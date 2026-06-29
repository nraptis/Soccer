#include "TwistExpander_PingPong_Arx.hpp"
#include "TwistFunctional.hpp"
#include "TwistMix32.hpp"
#include "TwistMix64.hpp"

#include <cstdint>

void TwistExpander_PingPong_Arx::KDF_A_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x814F371780637B89ULL + 0xAF4BC2369F2DBA17ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xCE49D7D02BF5D381ULL + 0x8531902F5827D206ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xE20300CB12C6B82DULL + 0xC53DD94022071557ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xDB8FEDD528D4C65DULL + 0x8D3D3F0CF451482FULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xA957A4BFBDF0561DULL + 0xA428E54E919A1219ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x985CF353E877B49FULL + 0xE576C4F72852B369ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xFDAD70F5B948F1E9ULL + 0xFD7CF89ED5EC9CC3ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xA188B6042F7AF291ULL + 0xE739543D4DAD12DDULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xD07CA391F54670B3ULL + 0x99432067222EDFE4ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x87A2ADFB15988741ULL + 0xABC6ACFE728C79F5ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x8D3CF5AEAD1C3C4DULL + 0x9049152041726297ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xF31AA2829FC1E289ULL + 0xE184AD7A4A12B6C1ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xAB61BBE07DEF77FBULL + 0x9B6CD78DDB09D9E9ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xCCB3DE67AB381345ULL + 0xFD42C0F9E7722320ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xF7DE75A3A63AA1A3ULL + 0xE0488EBD66B0C69DULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xD2BBD2470A1FD6B9ULL + 0x8A12CE2B7499E77DULL);
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
            aIngress = RotL64(mSource[((aIndex + 3668U)) & S_BLOCK1], 23U) ^ RotL64(pSnow[((aIndex + 4472U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = RotL64(pSnow[((S_BLOCK1 - aIndex + 1332U)) & S_BLOCK1], 35U) ^ RotL64(mSource[((aIndex + 3620U)) & S_BLOCK1], 10U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCarry, 51U)) + (RotL64(aCross, 22U) ^ RotL64(aIngress, 37U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterE = (aWandererF + RotL64(aIngress, 23U)) + 12775735908960052604U;
            aOrbiterI = ((aWandererG + RotL64(aScatter, 13U)) + RotL64(aCarry, 19U)) + 11791373812080296887U;
            aOrbiterJ = ((aWandererA + RotL64(aPrevious, 5U)) + RotL64(aCarry, 51U)) + 5537362877706057303U;
            aOrbiterK = (aWandererB + RotL64(aCross, 47U)) + 2023912048504189380U;
            aOrbiterC = (aWandererK + RotL64(aPrevious, 30U)) + 17668828109963766893U;
            aOrbiterF = (((aWandererJ + RotL64(aCross, 57U)) + RotL64(aCarry, 47U)) + 558908629933941224U) + aOrbiterAssignSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterD = ((aWandererE + RotL64(aScatter, 51U)) + 1479633119685446888U) + aNonceWordA;
            aOrbiterH = ((aWandererH + RotL64(aIngress, 37U)) + 15460320397843364063U) + aOrbiterAssignSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = (aWandererD + RotL64(aCross, 44U)) + 10059749397555469054U;
            aOrbiterG = ((aWandererC + RotL64(aPrevious, 19U)) + 9987633811929693924U) + aNonceWordC;
            aOrbiterA = (aWandererI + RotL64(aIngress, 11U)) + 10087337844580228269U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 4446204415503364254U) + aOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 15106063243302192717U) ^ aOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13273756657334709803U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 9430197906134676162U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 1226048679997253363U;
            aOrbiterC = RotL64((aOrbiterC * 14247538885252664127U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 10611580584157624739U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 3137391249289641509U;
            aOrbiterD = RotL64((aOrbiterD * 5462682413239873181U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 9327201928815412810U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 7890659377013147073U;
            aOrbiterI = RotL64((aOrbiterI * 13827717178378062047U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 10675114832750356941U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 8804440385852327267U;
            aOrbiterH = RotL64((aOrbiterH * 8520671775587260601U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 12871947817782057116U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 11015991745792051390U) ^ aNonceWordK;
            aOrbiterK = RotL64((aOrbiterK * 17152451500505815031U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 6320437975845673731U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 702457937087191287U) ^ aNonceWordM;
            aOrbiterB = RotL64((aOrbiterB * 17491257114676739589U), 39U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 16629064896250312921U) + aOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 6054107387816339103U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6983767878966747219U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 13274874838094190290U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 12211422735294360321U;
            aOrbiterE = RotL64((aOrbiterE * 5113738196151089817U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 15338616110718583619U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 1475787183754511373U;
            aOrbiterA = RotL64((aOrbiterA * 10904607643785840003U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 15486810401396777742U) + aNonceWordP;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 12775735908960052604U;
            aOrbiterG = RotL64((aOrbiterG * 7478156942468930207U), 51U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterJ, 30U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 3U));
            aIngress = aIngress + (RotL64(aOrbiterF, 27U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 5U));
            aIngress = aIngress + (RotL64(aOrbiterE, 53U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterD, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aCross, 23U) + RotL64(aOrbiterE, 21U)) + aOrbiterK);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterC, 43U)) + aOrbiterI) + aNonceWordD);
            aWandererB = aWandererB + (((RotL64(aPrevious, 28U) + RotL64(aOrbiterC, 51U)) + aOrbiterD) + aWandererUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 53U) + aOrbiterG) + RotL64(aOrbiterI, 30U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 3U) + aOrbiterF) + RotL64(aOrbiterH, 3U)) + RotL64(aCarry, 53U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 11U) + RotL64(aOrbiterE, 37U)) + aOrbiterI) + aNonceWordF);
            aWandererF = aWandererF + ((RotL64(aCross, 37U) + aOrbiterG) + RotL64(aOrbiterH, 27U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 26U) + aOrbiterA) + RotL64(aOrbiterG, 5U));
            aWandererD = aWandererD + (((RotL64(aIngress, 5U) + aOrbiterB) + RotL64(aOrbiterF, 46U)) + RotL64(aCarry, 43U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 21U) + RotL64(aOrbiterD, 19U)) + aOrbiterE) + aWandererUpdateSaltA[((aIndex + 17U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aCross, 43U) + aOrbiterJ) + RotL64(aOrbiterA, 53U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 48U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererD, 5U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererJ, 21U) ^ aWandererH);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 19U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 50U));
            aCarry = aCarry + RotL64(aWandererA, 23U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 7412U)) & S_BLOCK1], 5U) ^ RotL64(pSnow[((aIndex + 8439U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 10063U)) & S_BLOCK1], 50U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 6115U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aIngress, 41U) + RotL64(aCross, 53U)) + (RotL64(aCarry, 3U) ^ RotL64(aPrevious, 20U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterD = (aWandererH + RotL64(aPrevious, 47U)) + 12426357877879529292U;
            aOrbiterH = (aWandererJ + RotL64(aIngress, 29U)) + 12604900366173639176U;
            aOrbiterA = ((aWandererC + RotL64(aCross, 19U)) + RotL64(aCarry, 47U)) + 13511119007338929401U;
            aOrbiterK = (aWandererB + RotL64(aScatter, 53U)) + 9878720081166788060U;
            aOrbiterI = ((aWandererK + RotL64(aCross, 3U)) + 15463195409806395076U) + aNonceWordB;
            aOrbiterE = (aWandererF + RotL64(aIngress, 44U)) + 6407922778852833423U;
            aOrbiterF = (aWandererG + RotL64(aScatter, 41U)) + 7690427254160734016U;
            aOrbiterJ = ((aWandererI + RotL64(aPrevious, 21U)) + RotL64(aCarry, 11U)) + 18030974031722143619U;
            aOrbiterB = ((((aWandererD + RotL64(aIngress, 27U)) + RotL64(aCarry, 57U)) + 17983938038322737041U) + aOrbiterAssignSaltD[((aIndex + 28U)) & S_SALT1]) + aNonceWordC;
            aOrbiterG = ((aWandererA + RotL64(aCross, 39U)) + 16605512170117753884U) + aOrbiterAssignSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = ((aWandererE + RotL64(aScatter, 60U)) + 681802273302348322U) + aNonceWordI;
            //
            aOrbiterD = (((aOrbiterD + aOrbiterH) + 15550312921312083819U) + aOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1]) + aNonceWordE;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 17824154101711884508U;
            aOrbiterA = RotL64((aOrbiterA * 7358612830654795357U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 1939207786756735430U) + aOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 3132864634777826569U) ^ aNonceWordL;
            aOrbiterH = RotL64((aOrbiterH * 13606281919426730325U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 12822929773923954849U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 16576106045887115660U;
            aOrbiterK = RotL64((aOrbiterK * 16370914370769903051U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 2398825881649235260U) + aNonceWordJ;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 13700821892926092479U;
            aOrbiterB = RotL64((aOrbiterB * 10830623703416956043U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 2439833784883391606U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 15870638514107637833U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 3797380922767479287U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 9165457123134229670U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 8736642509192659417U;
            aOrbiterE = RotL64((aOrbiterE * 16219277537523484065U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 9232719746484835693U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 7826680628853322541U;
            aOrbiterC = RotL64((aOrbiterC * 12578050118133526187U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 14323652326982518782U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 2254524512851399313U;
            aOrbiterJ = RotL64((aOrbiterJ * 4119339547645451149U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 14459632243829356472U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 8591197056749497716U;
            aOrbiterF = RotL64((aOrbiterF * 13053836520694721881U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 17220196418897000411U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 7186579019945992185U;
            aOrbiterD = RotL64((aOrbiterD * 12406048515179065691U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 7554005180895698880U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 12426357877879529292U;
            aOrbiterI = RotL64((aOrbiterI * 5090046967147694465U), 29U);
            //
            aIngress = RotL64(aOrbiterA, 43U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 13U));
            aIngress = aIngress + (RotL64(aOrbiterB, 41U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 29U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 37U));
            aIngress = aIngress + RotL64(aOrbiterE, 48U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aScatter, 39U) + RotL64(aOrbiterI, 23U)) + aOrbiterH);
            aWandererI = aWandererI ^ ((((RotL64(aIngress, 3U) + RotL64(aOrbiterG, 47U)) + aOrbiterC) + aNonceWordA) + aWandererUpdateSaltE[((aIndex + 11U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aPrevious, 27U) + RotL64(aOrbiterI, 57U)) + aOrbiterB);
            aWandererE = aWandererE ^ (((RotL64(aCross, 11U) + aOrbiterA) + RotL64(aOrbiterE, 6U)) + aNonceWordM);
            aWandererD = aWandererD + ((RotL64(aPrevious, 53U) + aOrbiterG) + RotL64(aOrbiterF, 19U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 44U) + aOrbiterH) + RotL64(aOrbiterF, 39U));
            aWandererA = aWandererA + (((RotL64(aCross, 21U) + aOrbiterG) + RotL64(aOrbiterJ, 21U)) + aNonceWordO);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterK, 3U)) + aOrbiterC);
            aWandererK = aWandererK + (((RotL64(aCross, 23U) + RotL64(aOrbiterE, 60U)) + aOrbiterJ) + RotL64(aCarry, 21U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 60U) + RotL64(aOrbiterD, 51U)) + aOrbiterG);
            aWandererB = aWandererB + ((((RotL64(aScatter, 13U) + RotL64(aOrbiterI, 43U)) + aOrbiterG) + RotL64(aCarry, 57U)) + aWandererUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 20U));
            aCarry = aCarry + (RotL64(aWandererJ, 41U) ^ aWandererH);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 57U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 53U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 34U));
            aCarry = aCarry + RotL64(aWandererE, 13U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = RotL64(aFireLaneB[((aIndex + 11143U)) & S_BLOCK1], 39U) ^ RotL64(mSource[((aIndex + 13245U)) & S_BLOCK1], 6U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 14253U)) & S_BLOCK1], 13U) ^ RotL64(pSnow[((aIndex + 15577U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aPrevious, 27U)) + (RotL64(aIngress, 43U) + RotL64(aCarry, 56U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterE = ((aWandererF + RotL64(aIngress, 3U)) + 13333509828310369865U) + aNonceWordP;
            aOrbiterG = (aWandererD + RotL64(aCross, 6U)) + 7645352517103840797U;
            aOrbiterF = (aWandererA + RotL64(aPrevious, 57U)) + 5310766306660062655U;
            aOrbiterA = (((aWandererB + RotL64(aScatter, 19U)) + RotL64(aCarry, 27U)) + 5165635069832352932U) + aOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = (aWandererC + RotL64(aCross, 43U)) + 15684141764734281849U;
            aOrbiterC = ((aWandererI + RotL64(aScatter, 11U)) + 3327963374225061738U) + aNonceWordF;
            aOrbiterI = ((aWandererJ + RotL64(aIngress, 39U)) + 8625811794878848871U) + aNonceWordG;
            aOrbiterJ = ((aWandererG + RotL64(aPrevious, 47U)) + RotL64(aCarry, 51U)) + 7598657468430485291U;
            aOrbiterK = (aWandererH + RotL64(aIngress, 23U)) + 2881171216276746485U;
            aOrbiterD = (((aWandererK + RotL64(aCross, 51U)) + RotL64(aCarry, 3U)) + 10237691227222918101U) + aOrbiterAssignSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterH = ((aWandererE + RotL64(aPrevious, 34U)) + 6419254255884834497U) + aNonceWordM;
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 4238455444646479956U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 14936613353493061492U) ^ aOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3544216916806292273U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 15324699725208372627U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 9506640480601832011U) ^ aNonceWordC;
            aOrbiterB = RotL64((aOrbiterB * 12819564111348390227U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 3709149613660215641U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 1724290199312754307U) ^ aOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12597580418257897965U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 13191172833570139194U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 3686087945377837886U;
            aOrbiterC = RotL64((aOrbiterC * 10883609557429936283U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 10418330386245397022U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 5383531313632347245U) ^ aOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2987755379396160073U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 7414716553072652212U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 11301761123966206201U;
            aOrbiterD = RotL64((aOrbiterD * 1546727321088592187U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 8570229732236388847U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 8773754460060264773U;
            aOrbiterH = RotL64((aOrbiterH * 3251360788932563495U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 13636929800504199371U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 5486599841558573720U;
            aOrbiterJ = RotL64((aOrbiterJ * 2867914211589815153U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 13277541451512422776U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 10409779509190185921U;
            aOrbiterE = RotL64((aOrbiterE * 1926650154570961573U), 39U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 7268295836403414306U) + aNonceWordD;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 13815969853235433830U;
            aOrbiterK = RotL64((aOrbiterK * 11603750346752441535U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 9353249174240162324U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 13333509828310369865U;
            aOrbiterG = RotL64((aOrbiterG * 10381405217943841655U), 5U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterG, 19U);
            aIngress = aIngress + (RotL64(aOrbiterB, 53U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterJ, 10U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterF, 13U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 35U));
            aIngress = aIngress + RotL64(aOrbiterA, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aPrevious, 35U) + aOrbiterB) + RotL64(aOrbiterJ, 41U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 43U) + aOrbiterF) + RotL64(aOrbiterE, 37U));
            aWandererD = aWandererD + (((RotL64(aCross, 37U) + RotL64(aOrbiterG, 5U)) + aOrbiterK) + aNonceWordB);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 51U) + aOrbiterI) + RotL64(aOrbiterH, 47U));
            aWandererG = aWandererG + ((((RotL64(aPrevious, 47U) + RotL64(aOrbiterF, 35U)) + aOrbiterJ) + RotL64(aCarry, 23U)) + aNonceWordK);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterH, 19U)) + aOrbiterC);
            aWandererH = aWandererH + (((RotL64(aIngress, 60U) + RotL64(aOrbiterH, 44U)) + aOrbiterD) + RotL64(aCarry, 57U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 21U) + RotL64(aOrbiterI, 3U)) + aOrbiterJ) + aWandererUpdateSaltD[((aIndex + 10U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aIngress, 3U) + RotL64(aOrbiterB, 13U)) + aOrbiterK) + aNonceWordA);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 23U) + aOrbiterH) + RotL64(aOrbiterA, 27U)) + aWandererUpdateSaltC[((aIndex + 21U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aScatter, 14U) + RotL64(aOrbiterD, 22U)) + aOrbiterK) + aNonceWordO);
            //
            aCarry = aCarry + (RotL64(aWandererB, 53U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererA, 18U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererK, 5U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererI, 3U) ^ aWandererC);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 43U));
            aCarry = aCarry + RotL64(aWandererJ, 46U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 21061U)) & S_BLOCK1], 54U) ^ RotL64(pSnow[((aIndex + 18919U)) & S_BLOCK1], 41U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 21451U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(mSource[((S_BLOCK1 - aIndex + 16407U)) & S_BLOCK1], 42U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 21252U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aPrevious, 11U) ^ RotL64(aCarry, 41U)) ^ (RotL64(aCross, 28U) + RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterK = (aWandererG + RotL64(aPrevious, 11U)) + 3612110001869385068U;
            aOrbiterI = (aWandererA + RotL64(aIngress, 5U)) + 16340824141280225936U;
            aOrbiterJ = ((((aWandererH + RotL64(aScatter, 44U)) + RotL64(aCarry, 13U)) + 15222338965130765231U) + aOrbiterAssignSaltE[(((31U - aIndex) + 22U)) & S_SALT1]) + aNonceWordE;
            aOrbiterC = (((aWandererK + RotL64(aCross, 57U)) + RotL64(aCarry, 29U)) + 6649270508107155041U) + aNonceWordA;
            aOrbiterD = ((aWandererC + RotL64(aScatter, 19U)) + 768217258655426384U) + aOrbiterAssignSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterH = (aWandererB + RotL64(aIngress, 37U)) + 4481855259658861851U;
            aOrbiterG = (aWandererJ + RotL64(aPrevious, 39U)) + 18318041934562434016U;
            aOrbiterB = (aWandererF + RotL64(aCross, 34U)) + 4212457153804401807U;
            aOrbiterE = ((aWandererI + RotL64(aPrevious, 41U)) + RotL64(aCarry, 53U)) + 16143621095636987628U;
            aOrbiterF = (aWandererE + RotL64(aCross, 27U)) + 2095664232866642086U;
            aOrbiterA = (aWandererD + RotL64(aIngress, 23U)) + 4339527736737366572U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 13679353177869884790U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 11582168502846418236U;
            aOrbiterJ = RotL64((aOrbiterJ * 135539430034462861U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 10451330452898542191U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 12951448817640617841U;
            aOrbiterH = RotL64((aOrbiterH * 4141870904192742091U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 15389161934419370747U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 4754886272708253014U;
            aOrbiterC = RotL64((aOrbiterC * 16638243718191281597U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 11746389873929280688U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 12042680172517298768U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 3814780289755857543U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 2648103752465009244U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 451594673632597973U;
            aOrbiterI = RotL64((aOrbiterI * 8496763663271072425U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 5696534794094099710U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 14609435045257077395U;
            aOrbiterG = RotL64((aOrbiterG * 14658408563237468407U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 11599395126850950133U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 12699598504604446664U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 14313494063098111823U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 9398465148537154745U) + aNonceWordN;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 12139736860648011256U;
            aOrbiterA = RotL64((aOrbiterA * 15257503229375247987U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 5390816291244486383U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 2797988892316486895U;
            aOrbiterK = RotL64((aOrbiterK * 14668138881285892065U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 18356290434261054712U) + aNonceWordH;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 16582824574485822826U) ^ aNonceWordC;
            aOrbiterB = RotL64((aOrbiterB * 7207935384746719969U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 9858803484150150915U) + aOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 3612110001869385068U;
            aOrbiterF = RotL64((aOrbiterF * 2862887443435821143U), 41U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterA, 39U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 27U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 6U));
            aIngress = aIngress + (RotL64(aOrbiterD, 11U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 21U));
            aIngress = aIngress + RotL64(aOrbiterI, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aScatter, 51U) + RotL64(aOrbiterI, 5U)) + aOrbiterA);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterG, 11U)) + aOrbiterE);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 57U) + RotL64(aOrbiterC, 34U)) + aOrbiterK) + aNonceWordG) + aWandererUpdateSaltA[((aIndex + 3U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 44U) + aOrbiterD) + RotL64(aOrbiterF, 41U)) + aWandererUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterK, 19U)) + aOrbiterD) + aNonceWordI);
            aWandererF = aWandererF ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterH, 3U)) + aOrbiterJ);
            aWandererA = aWandererA + ((((RotL64(aScatter, 47U) + RotL64(aOrbiterA, 37U)) + aOrbiterK) + RotL64(aCarry, 47U)) + aNonceWordK);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 37U) + aOrbiterE) + RotL64(aOrbiterH, 21U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterF, 46U)) + aOrbiterH) + RotL64(aCarry, 19U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 60U) + RotL64(aOrbiterG, 13U)) + aOrbiterF);
            aWandererC = aWandererC + ((RotL64(aIngress, 11U) + aOrbiterA) + RotL64(aOrbiterB, 53U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 35U) ^ aWandererA);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 43U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 46U));
            aCarry = aCarry + (RotL64(aWandererK, 3U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererH, 5U);
            aCarry = aCarry + RotL64(aIngress, 60U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 23534U)) & S_BLOCK1], 39U) ^ RotL64(mSource[((aIndex + 21891U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(pSnow[((aIndex + 24804U)) & S_BLOCK1], 53U) ^ RotL64(aFireLaneA[((aIndex + 25499U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 25716U)) & S_BLOCK1], 41U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 25407U)) & S_BLOCK1], 6U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aIngress, 36U) + RotL64(aCarry, 3U)) ^ (RotL64(aPrevious, 51U) + RotL64(aCross, 19U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterF = (aWandererE + RotL64(aCross, 26U)) + 13583136155674166402U;
            aOrbiterI = (((aWandererJ + RotL64(aScatter, 5U)) + 12830472187484919497U) + aOrbiterAssignSaltD[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordK;
            aOrbiterA = (aWandererD + RotL64(aPrevious, 39U)) + 18081197909484522509U;
            aOrbiterH = ((aWandererF + RotL64(aIngress, 11U)) + RotL64(aCarry, 53U)) + 8680634051297891550U;
            aOrbiterB = (aWandererG + RotL64(aScatter, 19U)) + 13939998767458656823U;
            aOrbiterK = (aWandererB + RotL64(aCross, 3U)) + 1795730579103692594U;
            aOrbiterC = (((aWandererC + RotL64(aPrevious, 35U)) + RotL64(aCarry, 37U)) + 17369751719734069999U) + aNonceWordD;
            aOrbiterJ = (aWandererH + RotL64(aIngress, 43U)) + 224769585901248068U;
            aOrbiterD = ((aWandererA + RotL64(aScatter, 41U)) + RotL64(aCarry, 43U)) + 4133547085925268180U;
            aOrbiterE = ((aWandererI + RotL64(aPrevious, 29U)) + 7022512056309567391U) + aNonceWordF;
            aOrbiterG = ((aWandererK + RotL64(aIngress, 54U)) + 10319484359046945495U) + aOrbiterAssignSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 10483878349412282069U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 6481381149199985736U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 9701719367082506253U), 39U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 13721077228796934509U) + aNonceWordP;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 9704818014314175007U;
            aOrbiterB = RotL64((aOrbiterB * 760445624027740287U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 6253040047758584339U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 16890211690273641226U;
            aOrbiterI = RotL64((aOrbiterI * 5622534399866057841U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 6216227831265032436U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 2023609047004658739U) ^ aNonceWordO;
            aOrbiterJ = RotL64((aOrbiterJ * 3252332895698310147U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 9201669637050388263U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 5106927540934338576U) ^ aNonceWordN;
            aOrbiterK = RotL64((aOrbiterK * 6368134569042291431U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 10080368957861445998U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 10784789383436485808U;
            aOrbiterH = RotL64((aOrbiterH * 3794918350254445939U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 15426339824951793026U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 17637144549368340331U;
            aOrbiterD = RotL64((aOrbiterD * 10971293914614704441U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 9941300382181962134U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 8118046374121322097U;
            aOrbiterF = RotL64((aOrbiterF * 8481945819050983127U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 5138086185042567633U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 7279942739248982986U) ^ aNonceWordJ;
            aOrbiterG = RotL64((aOrbiterG * 12911998308338410917U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 12135610639038562853U) + aOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 12945353426409788798U;
            aOrbiterC = RotL64((aOrbiterC * 7434977715954413699U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 7534876598022096222U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 13583136155674166402U) ^ aOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 8194058098043157015U), 53U);
            //
            aIngress = RotL64(aOrbiterG, 21U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 50U));
            aIngress = aIngress + (RotL64(aOrbiterA, 43U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 29U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 19U));
            aIngress = aIngress + RotL64(aOrbiterH, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aIngress, 37U) + RotL64(aOrbiterB, 13U)) + aOrbiterD) + RotL64(aCarry, 13U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterF, 29U)) + aOrbiterH);
            aWandererG = aWandererG + ((RotL64(aCross, 10U) + aOrbiterK) + RotL64(aOrbiterF, 21U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterD, 6U)) + aOrbiterK);
            aWandererK = aWandererK + (((RotL64(aIngress, 27U) + RotL64(aOrbiterK, 57U)) + aOrbiterI) + aWandererUpdateSaltF[((aIndex + 19U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterA, 39U)) + aOrbiterC) + aNonceWordB);
            aWandererH = aWandererH + ((RotL64(aScatter, 3U) + RotL64(aOrbiterB, 3U)) + aOrbiterJ);
            aWandererI = aWandererI ^ (((RotL64(aCross, 21U) + RotL64(aOrbiterA, 52U)) + aOrbiterD) + aWandererUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 41U) + aOrbiterE) + RotL64(aOrbiterF, 19U)) + aNonceWordE);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 56U) + RotL64(aOrbiterG, 43U)) + aOrbiterH);
            aWandererA = aWandererA + (((RotL64(aCross, 43U) + RotL64(aOrbiterD, 47U)) + aOrbiterJ) + RotL64(aCarry, 37U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 13U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 40U));
            aCarry = aCarry + (RotL64(aWandererF, 19U) ^ aWandererA);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 5U));
            aCarry = aCarry + (RotL64(aWandererH, 35U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererD, 47U);
            aCarry = aCarry + RotL64(aIngress, 24U);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 32508U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneA[((aIndex + 30736U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 32348U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29273U)) & S_BLOCK1], 19U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 30084U)) & S_BLOCK1], 3U));
            aCross ^= (RotL64(pSnow[((S_BLOCK1 - aIndex + 29368U)) & S_BLOCK1], 39U) ^ RotL64(aFireLaneB[((aIndex + 27793U)) & S_BLOCK1], 54U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aIngress, 11U) ^ RotL64(aCarry, 24U)) ^ (RotL64(aCross, 51U) + RotL64(aPrevious, 39U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterF = (aWandererE + RotL64(aPrevious, 3U)) + 17081642665820489793U;
            aOrbiterK = (aWandererA + RotL64(aIngress, 41U)) + 14468854040067229623U;
            aOrbiterC = ((aWandererD + RotL64(aCross, 18U)) + 2249450222593057429U) + aOrbiterAssignSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = (aWandererG + RotL64(aScatter, 21U)) + 14964389079511378664U;
            aOrbiterI = ((aWandererF + RotL64(aPrevious, 27U)) + RotL64(aCarry, 47U)) + 17003491054252360650U;
            aOrbiterE = ((aWandererJ + RotL64(aScatter, 57U)) + 12710882240582032588U) + aNonceWordM;
            aOrbiterJ = (((aWandererC + RotL64(aCross, 35U)) + RotL64(aCarry, 53U)) + 9887078182156755359U) + aNonceWordP;
            aOrbiterG = ((((aWandererI + RotL64(aIngress, 29U)) + RotL64(aCarry, 13U)) + 7665284531810584704U) + aOrbiterAssignSaltA[(((31U - aIndex) + 4U)) & S_SALT1]) + aNonceWordC;
            aOrbiterD = (aWandererH + RotL64(aScatter, 13U)) + 7304284015511876717U;
            aOrbiterH = (aWandererK + RotL64(aPrevious, 60U)) + 5517927023543751734U;
            aOrbiterA = (aWandererB + RotL64(aCross, 39U)) + 17704756310857362759U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 11347400363019508578U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 11696395232760991243U;
            aOrbiterC = RotL64((aOrbiterC * 9725231749679442003U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 10875780291242873583U) + aNonceWordA;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 7808740614343437672U;
            aOrbiterF = RotL64((aOrbiterF * 8889516201913716283U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 3145390996141902032U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 16080636485642732615U) ^ aNonceWordJ;
            aOrbiterK = RotL64((aOrbiterK * 7445756373012217305U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 3929263288176983844U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 18210228766683996806U) ^ aOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 13178080076505449091U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 13948962323541421431U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 3037683309790156893U) ^ aNonceWordL;
            aOrbiterJ = RotL64((aOrbiterJ * 13406672352222636739U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 17827265198532699474U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 7270895262023504864U) ^ aNonceWordE;
            aOrbiterD = RotL64((aOrbiterD * 13467417362477308167U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 6431243064980879185U) + aOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 6680205390976259885U;
            aOrbiterB = RotL64((aOrbiterB * 10421386694108590789U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 15910655919164357152U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 8046213498216027383U;
            aOrbiterI = RotL64((aOrbiterI * 18061867495824063553U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 2521111689480478597U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 13892876610454681741U;
            aOrbiterH = RotL64((aOrbiterH * 17776392934374483875U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 16009217514890880809U) + aOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 1221573458193626679U;
            aOrbiterE = RotL64((aOrbiterE * 73477765605619369U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 9275704218554025797U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 17081642665820489793U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5613316790159527375U), 11U);
            //
            aIngress = RotL64(aOrbiterJ, 3U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 11U));
            aIngress = aIngress + (RotL64(aOrbiterI, 57U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterG, 48U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 41U));
            aIngress = aIngress + RotL64(aOrbiterK, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 12U) + aOrbiterF) + RotL64(aOrbiterC, 47U));
            aWandererA = aWandererA + (((RotL64(aCross, 41U) + RotL64(aOrbiterC, 43U)) + aOrbiterE) + aNonceWordG);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 43U) + aOrbiterF) + RotL64(aOrbiterG, 23U));
            aWandererC = aWandererC + ((RotL64(aIngress, 47U) + aOrbiterJ) + RotL64(aOrbiterB, 53U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 34U) + aOrbiterA) + RotL64(aOrbiterJ, 35U));
            aWandererD = aWandererD + (((RotL64(aIngress, 19U) + aOrbiterG) + RotL64(aOrbiterD, 60U)) + RotL64(aCarry, 35U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 37U) + aOrbiterC) + RotL64(aOrbiterA, 13U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 39U) + aOrbiterH) + RotL64(aOrbiterJ, 21U)) + RotL64(aCarry, 47U));
            aWandererB = aWandererB ^ ((((RotL64(aIngress, 53U) + RotL64(aOrbiterG, 3U)) + aOrbiterH) + aNonceWordD) + aWandererUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 57U) + aOrbiterG) + RotL64(aOrbiterI, 39U)) + aWandererUpdateSaltD[((aIndex + 14U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 51U) + aOrbiterK) + RotL64(aOrbiterG, 26U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 6U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererK, 27U) ^ aWandererD);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 51U));
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererE, 3U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererJ, 38U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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

void TwistExpander_PingPong_Arx::KDF_A_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xF58D11BD363036C9ULL + 0xFE7940114E7EE18CULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xA529DD760A9A7D0BULL + 0x822FC8E922F6F1F0ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xD0B26E30CB3A43E9ULL + 0xC04A4896379E02EBULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xFBE036C463988737ULL + 0xCE9AEC4571B6863DULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xBF0C73A338C93F71ULL + 0xBCF98DFEEEBDB6C3ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x8BC96F49545CF645ULL + 0xFD83A76FC15EC012ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xD11D4C7DFC8F2B0FULL + 0xDCD28092086A701EULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xC6C5F3CDBF4F6559ULL + 0xDC7BECC516ADBA3EULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xE8791DD0497E87F3ULL + 0xF6DFF8A251B16C98ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xF4DC0B107D10466DULL + 0xDF517142AACB6C82ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xADAE31A26A38A017ULL + 0xC6FE2E9A51E49B6AULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x96695D6549E1F7DDULL + 0x8A80E612BA260267ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x99AAF017BCF811C5ULL + 0xBC62C551540F416DULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xE4CFCF8C303DE67BULL + 0xAF6DE390D6132844ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xEF3FC58DB3F308CFULL + 0x87A2FB27400312DFULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xFB79C4D983932175ULL + 0xE99FFA90191EE91DULL);
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
            aIngress = RotL64(aExpandLaneA[((aIndex + 1983U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneB[((aIndex + 4980U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 3057U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneD[((aIndex + 3333U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCarry, 60U) + RotL64(aIngress, 13U)) + (RotL64(aPrevious, 29U) ^ RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterB = ((aWandererC + RotL64(aIngress, 30U)) + RotL64(aCarry, 37U)) + 7632760812370906911U;
            aOrbiterG = (aWandererH + RotL64(aCross, 43U)) + 6007174525479723089U;
            aOrbiterA = ((aWandererJ + RotL64(aPrevious, 57U)) + RotL64(aCarry, 3U)) + 3362829642521821048U;
            aOrbiterE = (aWandererB + RotL64(aScatter, 47U)) + 18009548556107978286U;
            aOrbiterH = (aWandererK + RotL64(aIngress, 53U)) + 17880909432272697327U;
            aOrbiterJ = (((aWandererA + RotL64(aPrevious, 11U)) + 15961567935420752568U) + aOrbiterAssignSaltF[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordO;
            aOrbiterK = ((aWandererG + RotL64(aScatter, 3U)) + RotL64(aCarry, 51U)) + 10136559064656837921U;
            aOrbiterC = (aWandererE + RotL64(aCross, 23U)) + 17622019364405410277U;
            aOrbiterI = (((aWandererF + RotL64(aPrevious, 18U)) + 6927494824421416306U) + aOrbiterAssignSaltD[(((31U - aIndex) + 14U)) & S_SALT1]) + aNonceWordG;
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 7125170407794874847U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 12342273503071032250U;
            aOrbiterA = RotL64((aOrbiterA * 867417849555857179U), 39U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterE) + 14997696377476124836U) + aOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1]) + aNonceWordK;
            aOrbiterH = (((aOrbiterH ^ aOrbiterG) ^ 14874498694181230698U) ^ aOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterH = RotL64((aOrbiterH * 4026127545746010937U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 2549397729130885686U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 4217995818662767955U;
            aOrbiterJ = RotL64((aOrbiterJ * 5525525344485251063U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 4706089044415442525U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 17983900172670031015U) ^ aNonceWordL;
            aOrbiterC = RotL64((aOrbiterC * 541552737180932879U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 1904937798143929988U) + aNonceWordC;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 10620877287033139483U;
            aOrbiterB = RotL64((aOrbiterB * 16711012562024287213U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 15681091173163181525U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 2655543246639000084U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 16686375598149755947U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 2647895110857289213U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 5581609212017175954U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 15330263616699031311U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 13609076329627787987U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 6244266279516622070U;
            aOrbiterG = RotL64((aOrbiterG * 12488345779236971095U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 5289624364508923581U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 16351476803965903112U;
            aOrbiterK = RotL64((aOrbiterK * 9012522724650442597U), 35U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterG, 34U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 23U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 13U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 5U));
            aIngress = aIngress + RotL64(aOrbiterA, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aCross, 20U) + aOrbiterE) + RotL64(aOrbiterB, 28U)) + aNonceWordA);
            aWandererB = aWandererB + ((RotL64(aIngress, 27U) + RotL64(aOrbiterB, 3U)) + aOrbiterH);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 3U) + RotL64(aOrbiterE, 47U)) + aOrbiterK) + aNonceWordB);
            aWandererH = aWandererH + ((RotL64(aPrevious, 47U) + RotL64(aOrbiterC, 57U)) + aOrbiterB);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterC, 11U)) + aOrbiterA);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 51U) + aOrbiterG) + RotL64(aOrbiterK, 43U)) + RotL64(aCarry, 27U)) + aWandererUpdateSaltE[((aIndex + 4U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((((RotL64(aCross, 42U) + aOrbiterJ) + RotL64(aOrbiterA, 51U)) + aNonceWordF) + aWandererUpdateSaltF[((aIndex + 15U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aIngress, 37U) + aOrbiterG) + RotL64(aOrbiterB, 34U)) + RotL64(aCarry, 35U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterG, 39U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 37U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererC, 50U) ^ aWandererE);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 43U));
            aCarry = aCarry + (RotL64(aWandererF, 5U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererA, 27U);
            aCarry = aCarry + RotL64(aIngress, 20U);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 7691U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneB[((aIndex + 8280U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 6853U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 8080U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 10209U)) & S_BLOCK1], 34U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aIngress, 27U)) + (RotL64(aCarry, 56U) ^ RotL64(aPrevious, 39U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterD = ((aWandererI + RotL64(aPrevious, 18U)) + 6521330037475130256U) + aNonceWordE;
            aOrbiterF = ((aWandererB + RotL64(aScatter, 47U)) + 12611880456055428940U) + aOrbiterAssignSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterI = ((aWandererK + RotL64(aCross, 57U)) + RotL64(aCarry, 35U)) + 12061611078130934708U;
            aOrbiterC = ((aWandererE + RotL64(aIngress, 43U)) + RotL64(aCarry, 5U)) + 1558112410801116984U;
            aOrbiterH = ((aWandererF + RotL64(aPrevious, 51U)) + RotL64(aCarry, 27U)) + 10509115227850160786U;
            aOrbiterJ = (((aWandererG + RotL64(aIngress, 35U)) + 4045915960688792066U) + aOrbiterAssignSaltE[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordP;
            aOrbiterB = (aWandererA + RotL64(aScatter, 10U)) + 1196541286513243082U;
            aOrbiterK = (aWandererC + RotL64(aCross, 23U)) + 15564991032722373702U;
            aOrbiterA = (aWandererH + RotL64(aPrevious, 39U)) + 4897765238703641798U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 12327429514907752733U) + aNonceWordG;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 6189189797708711636U;
            aOrbiterI = RotL64((aOrbiterI * 9017615866338877651U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 6374267075282018852U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 1888758503831341439U) ^ aOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 74387714918264257U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 14956857689299491800U) + aNonceWordB;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 14879361107223331957U) ^ aOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 9166712966729591953U), 5U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 16086885494838105042U) + aNonceWordC;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 8069724185844303923U) ^ aOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8878470736758734353U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 10854345917959911439U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 7078313614360332089U;
            aOrbiterB = RotL64((aOrbiterB * 9864025732292844871U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 15083669236062255011U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 594879695916679116U;
            aOrbiterJ = RotL64((aOrbiterJ * 9852515479152735283U), 37U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 6721466068234534523U) + aOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 475816724162626782U;
            aOrbiterA = RotL64((aOrbiterA * 4799725182757588407U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 4341655358154605899U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 15477254302340298586U;
            aOrbiterC = RotL64((aOrbiterC * 13961520225881974201U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 10179091913200895775U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 6310490897546909571U;
            aOrbiterH = RotL64((aOrbiterH * 15080621088825477613U), 41U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterI, 19U);
            aIngress = aIngress + (RotL64(aOrbiterD, 57U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 50U));
            aIngress = aIngress + (RotL64(aOrbiterB, 13U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterC, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aScatter, 46U) + aOrbiterH) + RotL64(aOrbiterK, 56U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterA, 27U)) + aOrbiterI) + aWandererUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 19U) + aOrbiterF) + RotL64(aOrbiterK, 23U));
            aWandererE = aWandererE + ((((RotL64(aIngress, 51U) + RotL64(aOrbiterI, 47U)) + aOrbiterD) + RotL64(aCarry, 41U)) + aNonceWordO);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterJ, 13U)) + aOrbiterB);
            aWandererC = aWandererC + (((RotL64(aScatter, 57U) + aOrbiterF) + RotL64(aOrbiterC, 3U)) + RotL64(aCarry, 19U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 3U) + aOrbiterJ) + RotL64(aOrbiterA, 60U)) + aWandererUpdateSaltC[((aIndex + 17U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aIngress, 27U) + aOrbiterA) + RotL64(aOrbiterC, 51U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 34U) + RotL64(aOrbiterI, 19U)) + aOrbiterK) + aNonceWordM);
            //
            aCarry = aCarry + (RotL64(aWandererH, 50U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererG, 53U) ^ aWandererC);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 23U));
            aCarry = aCarry + (RotL64(aWandererF, 35U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererK, 6U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 14279U)) & S_BLOCK1], 26U) ^ RotL64(aExpandLaneD[((aIndex + 11912U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aExpandLaneC[((aIndex + 15381U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 14188U)) & S_BLOCK1], 39U) ^ RotL64(aFireLaneC[((aIndex + 12003U)) & S_BLOCK1], 52U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCarry, 27U) + RotL64(aPrevious, 43U)) + (RotL64(aIngress, 58U) ^ RotL64(aCross, 11U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterJ = (((aWandererJ + RotL64(aIngress, 43U)) + 9133751643283278896U) + aOrbiterAssignSaltB[((aIndex + 9U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterD = (((aWandererE + RotL64(aCross, 47U)) + RotL64(aCarry, 37U)) + 8971581804375380408U) + aNonceWordN;
            aOrbiterG = ((aWandererB + RotL64(aScatter, 34U)) + RotL64(aCarry, 51U)) + 12559650383714566592U;
            aOrbiterC = (aWandererI + RotL64(aPrevious, 11U)) + 15753206088872859163U;
            aOrbiterI = ((aWandererF + RotL64(aCross, 5U)) + 7640756270450762350U) + aOrbiterAssignSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = (aWandererC + RotL64(aScatter, 53U)) + 7340073357551376125U;
            aOrbiterA = ((aWandererK + RotL64(aPrevious, 57U)) + 5270256573644196046U) + aNonceWordA;
            aOrbiterE = ((aWandererH + RotL64(aIngress, 27U)) + RotL64(aCarry, 3U)) + 3567367996479995928U;
            aOrbiterB = (aWandererG + RotL64(aCross, 20U)) + 11939634537492733738U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 7051817732424527120U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 1730487669951837941U;
            aOrbiterG = RotL64((aOrbiterG * 15191634337956285841U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 18009252467909454817U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 2361024272031696442U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 15215151562500226027U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 15902755877642960397U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 12243517544704116184U;
            aOrbiterA = RotL64((aOrbiterA * 2576071074148141447U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 16846181962302186187U) + aNonceWordF;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 636121425116506681U;
            aOrbiterC = RotL64((aOrbiterC * 17075030673338779993U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 6887385655828217318U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 3705834550934775862U) ^ aNonceWordL;
            aOrbiterB = RotL64((aOrbiterB * 11275428284929594435U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 11165142437077969438U) + aOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 6426659930331618269U) ^ aNonceWordO;
            aOrbiterF = RotL64((aOrbiterF * 17170640810530893705U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 12629082390899315789U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 4277510580069574724U;
            aOrbiterE = RotL64((aOrbiterE * 9829125163412708305U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 13814834144170469978U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 3698381854100295826U;
            aOrbiterD = RotL64((aOrbiterD * 5126359230872258015U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 11623170635983579937U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 7247413650388803796U;
            aOrbiterJ = RotL64((aOrbiterJ * 3403219499465560059U), 57U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterJ, 57U);
            aIngress = aIngress + (RotL64(aOrbiterA, 23U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 29U));
            aIngress = aIngress + (RotL64(aOrbiterC, 3U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterG, 46U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((((RotL64(aIngress, 5U) + RotL64(aOrbiterC, 11U)) + aOrbiterI) + aNonceWordE) + aWandererUpdateSaltB[((aIndex + 21U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aScatter, 37U) + RotL64(aOrbiterI, 43U)) + aOrbiterA);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 12U) + aOrbiterI) + RotL64(aOrbiterF, 3U)) + aNonceWordP);
            aWandererC = aWandererC + (((RotL64(aCross, 21U) + aOrbiterI) + RotL64(aOrbiterG, 57U)) + aNonceWordG);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 47U) + aOrbiterD) + RotL64(aOrbiterJ, 34U));
            aWandererI = aWandererI + ((((RotL64(aCross, 29U) + aOrbiterE) + RotL64(aOrbiterB, 51U)) + RotL64(aCarry, 39U)) + aNonceWordD);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterE, 39U)) + aOrbiterI);
            aWandererG = aWandererG + (((RotL64(aScatter, 58U) + aOrbiterJ) + RotL64(aOrbiterF, 23U)) + RotL64(aCarry, 29U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 51U) + RotL64(aOrbiterG, 18U)) + aOrbiterD) + aWandererUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 6U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 57U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 43U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 35U));
            aCarry = aCarry + RotL64(aWandererJ, 27U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 21444U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneC[((aIndex + 20959U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 19079U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 17871U)) & S_BLOCK1], 39U) ^ RotL64(aFireLaneD[((aIndex + 17771U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCross, 11U) ^ RotL64(aPrevious, 23U)) ^ (RotL64(aIngress, 56U) + RotL64(aCarry, 43U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterH = (((aWandererB + RotL64(aPrevious, 39U)) + RotL64(aCarry, 57U)) + 8975885703279267062U) + aOrbiterAssignSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = (aWandererK + RotL64(aCross, 23U)) + 8664844915562660637U;
            aOrbiterK = (((aWandererE + RotL64(aIngress, 35U)) + RotL64(aCarry, 11U)) + 12281774799736296726U) + aNonceWordL;
            aOrbiterA = ((aWandererD + RotL64(aScatter, 44U)) + 15347461352311329726U) + aNonceWordG;
            aOrbiterG = (aWandererC + RotL64(aCross, 13U)) + 12967500561828907834U;
            aOrbiterF = (aWandererJ + RotL64(aScatter, 57U)) + 5002833859280402726U;
            aOrbiterJ = ((aWandererF + RotL64(aPrevious, 3U)) + 11908257536954668983U) + aOrbiterAssignSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = (aWandererH + RotL64(aIngress, 50U)) + 17017174811949227162U;
            aOrbiterD = ((aWandererI + RotL64(aCross, 27U)) + RotL64(aCarry, 37U)) + 16851323125613931180U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 13469326957728686706U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 5228638551056105241U;
            aOrbiterK = RotL64((aOrbiterK * 13369947664646167255U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 11945166198089308564U) + aOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 16268645041872996022U;
            aOrbiterG = RotL64((aOrbiterG * 5391448793718370911U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 14781204627695095701U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 5365325354838101092U) ^ aNonceWordJ;
            aOrbiterJ = RotL64((aOrbiterJ * 8017284997946310807U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 563147416025715953U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 14660867395395625851U;
            aOrbiterA = RotL64((aOrbiterA * 4769458126865307103U), 21U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 3168989056355712105U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 16179131669773665579U) ^ aOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5641461617066671723U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 4160220074225527179U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 8597134686962559111U) ^ aNonceWordN;
            aOrbiterI = RotL64((aOrbiterI * 639572585431474015U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 16811551552456811661U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 5827323970423386301U;
            aOrbiterD = RotL64((aOrbiterD * 9328247349730652021U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 15583234353262170227U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 2950816254621717748U;
            aOrbiterF = RotL64((aOrbiterF * 1102417597476170143U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 4426165025104306337U) + aNonceWordK;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 11871220132164971152U;
            aOrbiterE = RotL64((aOrbiterE * 2366168050042802207U), 13U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterA, 26U);
            aIngress = aIngress + (RotL64(aOrbiterD, 57U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterH, 47U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 51U));
            aIngress = aIngress + RotL64(aOrbiterK, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aScatter, 24U) + RotL64(aOrbiterE, 19U)) + aOrbiterA) + aNonceWordD);
            aWandererC = aWandererC ^ ((RotL64(aCross, 57U) + aOrbiterA) + RotL64(aOrbiterI, 60U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 35U) + aOrbiterH) + RotL64(aOrbiterG, 5U)) + aWandererUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 39U) + aOrbiterJ) + RotL64(aOrbiterA, 37U));
            aWandererJ = aWandererJ + ((RotL64(aCross, 29U) + aOrbiterG) + RotL64(aOrbiterI, 41U));
            aWandererE = aWandererE ^ ((((RotL64(aPrevious, 50U) + aOrbiterA) + RotL64(aOrbiterK, 23U)) + aNonceWordE) + aWandererUpdateSaltE[((aIndex + 25U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 43U) + aOrbiterD) + RotL64(aOrbiterF, 51U)) + RotL64(aCarry, 35U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 19U) + aOrbiterJ) + RotL64(aOrbiterG, 47U));
            aWandererB = aWandererB + ((((RotL64(aPrevious, 11U) + aOrbiterF) + RotL64(aOrbiterJ, 56U)) + RotL64(aCarry, 5U)) + aNonceWordO);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 14U));
            aCarry = aCarry + (RotL64(aWandererD, 53U) ^ aWandererI);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 29U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 19U));
            aCarry = aCarry + RotL64(aWandererE, 57U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = RotL64(aOperationLaneB[((aIndex + 25418U)) & S_BLOCK1], 51U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 27064U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 26117U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneA[((aIndex + 27184U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aIngress, 14U) + RotL64(aCross, 57U)) ^ (RotL64(aPrevious, 29U) + RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterG = ((aWandererJ + RotL64(aScatter, 41U)) + RotL64(aCarry, 35U)) + 12692813903177772178U;
            aOrbiterH = (((aWandererK + RotL64(aIngress, 57U)) + RotL64(aCarry, 13U)) + 7112496446691277899U) + aNonceWordJ;
            aOrbiterC = (aWandererH + RotL64(aPrevious, 18U)) + 2112247138290568813U;
            aOrbiterJ = (aWandererG + RotL64(aCross, 47U)) + 3699421080882855947U;
            aOrbiterI = (aWandererD + RotL64(aPrevious, 23U)) + 13761832028354380922U;
            aOrbiterA = (((aWandererB + RotL64(aCross, 11U)) + RotL64(aCarry, 53U)) + 9243822514887600214U) + aNonceWordO;
            aOrbiterK = (aWandererI + RotL64(aScatter, 35U)) + 6863833516853046129U;
            aOrbiterE = ((aWandererE + RotL64(aIngress, 52U)) + 8863897995943098018U) + aOrbiterAssignSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = ((aWandererF + RotL64(aPrevious, 3U)) + 13346785686701467520U) + aOrbiterAssignSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 15309543066305531619U) + aOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 17515530938817919111U;
            aOrbiterC = RotL64((aOrbiterC * 16625193986319048245U), 39U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 760493237816424254U) + aNonceWordP;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 7282586354117620860U;
            aOrbiterI = RotL64((aOrbiterI * 2327153408185290635U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 4129706068526969105U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 7020175432730888755U;
            aOrbiterK = RotL64((aOrbiterK * 10095158356907592239U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 9102258982216515596U) + aOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 10822031305361453690U;
            aOrbiterJ = RotL64((aOrbiterJ * 2036205056490578491U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 12571477440964330246U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 8436347026653095199U;
            aOrbiterG = RotL64((aOrbiterG * 17930734781213681573U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 14214789872073941940U) + aNonceWordF;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 12915911919403385001U) ^ aNonceWordA;
            aOrbiterB = RotL64((aOrbiterB * 13161681603528031511U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 15443240166233851298U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 7311369180113240915U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 13339195007946889423U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 12976516224995960015U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 7823308381434556721U) ^ aNonceWordI;
            aOrbiterH = RotL64((aOrbiterH * 502385172763861451U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 4829417661664149137U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 16306394751966719700U;
            aOrbiterA = RotL64((aOrbiterA * 5294376579588592157U), 3U);
            //
            aIngress = RotL64(aOrbiterH, 40U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterG, 57U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterJ, 53U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterE, 29U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterC, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 18U) + aOrbiterE) + RotL64(aOrbiterK, 60U)) + aNonceWordK);
            aWandererI = aWandererI + (((RotL64(aIngress, 51U) + aOrbiterI) + RotL64(aOrbiterC, 19U)) + RotL64(aCarry, 5U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterC, 41U)) + aOrbiterK);
            aWandererF = aWandererF + ((RotL64(aCross, 35U) + aOrbiterA) + RotL64(aOrbiterC, 11U));
            aWandererH = aWandererH ^ ((((RotL64(aPrevious, 47U) + RotL64(aOrbiterG, 46U)) + aOrbiterJ) + aNonceWordG) + aWandererUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aScatter, 41U) + RotL64(aOrbiterB, 29U)) + aOrbiterE) + RotL64(aCarry, 27U)) + aWandererUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 27U) + aOrbiterB) + RotL64(aOrbiterK, 35U));
            aWandererK = aWandererK + ((RotL64(aIngress, 60U) + aOrbiterG) + RotL64(aOrbiterC, 51U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 23U) + aOrbiterH) + RotL64(aOrbiterE, 3U)) + aNonceWordH);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 35U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererK, 50U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererD, 27U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererE, 13U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererG, 53U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = RotL64(aOperationLaneC[((aIndex + 29655U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 30487U)) & S_BLOCK1], 46U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28419U)) & S_BLOCK1], 44U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29293U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCross, 54U) + RotL64(aIngress, 23U)) ^ (RotL64(aCarry, 5U) + RotL64(aPrevious, 37U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterI = ((aWandererC + RotL64(aScatter, 38U)) + 12380376990224645149U) + aNonceWordO;
            aOrbiterG = (aWandererH + RotL64(aPrevious, 29U)) + 18296928500297384014U;
            aOrbiterJ = (aWandererD + RotL64(aCross, 11U)) + 3550626816361145100U;
            aOrbiterE = ((aWandererK + RotL64(aIngress, 19U)) + RotL64(aCarry, 51U)) + 2667792936946706027U;
            aOrbiterK = (((aWandererB + RotL64(aScatter, 4U)) + RotL64(aCarry, 11U)) + 12020969779370926953U) + aOrbiterAssignSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = ((aWandererJ + RotL64(aIngress, 47U)) + 737340727886903447U) + aOrbiterAssignSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterH = ((aWandererG + RotL64(aPrevious, 57U)) + 1681797651799760502U) + aNonceWordK;
            aOrbiterB = ((aWandererE + RotL64(aCross, 51U)) + 2956186342689489064U) + aNonceWordA;
            aOrbiterA = (((aWandererA + RotL64(aPrevious, 43U)) + RotL64(aCarry, 27U)) + 1876852870402977177U) + aNonceWordM;
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 6433205819353555071U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 9065076854974222998U;
            aOrbiterJ = RotL64((aOrbiterJ * 5459675878087242021U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 3254410578766789992U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 2005081975473815576U;
            aOrbiterK = RotL64((aOrbiterK * 9947701153722014085U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 15992999234834560419U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 3458344156815120948U;
            aOrbiterH = RotL64((aOrbiterH * 1668460113964608051U), 37U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 17069783053664877727U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 1260234710193913099U) ^ aOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4561226779897414381U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 3825186451876061335U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 2905344294992827535U;
            aOrbiterA = RotL64((aOrbiterA * 2469896090698580795U), 51U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterA) + 18141402347899180617U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordB;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 8760129857609925066U;
            aOrbiterI = RotL64((aOrbiterI * 2507999156108123047U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 594052473780678210U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 13216719212966128379U) ^ aNonceWordH;
            aOrbiterC = RotL64((aOrbiterC * 10691355329696722303U), 23U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 10029948739466316169U) + aOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 11912428807431992996U) ^ aNonceWordF;
            aOrbiterB = RotL64((aOrbiterB * 85016510811938307U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 8735634019801417287U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 12785916159063273545U;
            aOrbiterG = RotL64((aOrbiterG * 1161917531260663357U), 43U);
            //
            aIngress = RotL64(aOrbiterB, 27U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 23U));
            aIngress = aIngress + (RotL64(aOrbiterA, 41U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 10U));
            aIngress = aIngress + RotL64(aOrbiterH, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aScatter, 51U) + RotL64(aOrbiterE, 23U)) + aOrbiterK) + RotL64(aCarry, 27U));
            aWandererH = aWandererH ^ ((((RotL64(aPrevious, 58U) + aOrbiterB) + RotL64(aOrbiterK, 57U)) + aNonceWordP) + aWandererUpdateSaltB[((aIndex + 5U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aIngress, 41U) + aOrbiterE) + RotL64(aOrbiterI, 46U)) + RotL64(aCarry, 53U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterC, 53U)) + aOrbiterA) + aWandererUpdateSaltD[((aIndex + 23U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aScatter, 19U) + RotL64(aOrbiterH, 5U)) + aOrbiterB);
            aWandererA = aWandererA ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterI, 27U)) + aOrbiterK) + aNonceWordJ);
            aWandererC = aWandererC + (((RotL64(aIngress, 23U) + aOrbiterH) + RotL64(aOrbiterJ, 13U)) + aNonceWordE);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterG, 19U)) + aOrbiterA) + aNonceWordL);
            aWandererG = aWandererG + ((RotL64(aIngress, 34U) + aOrbiterI) + RotL64(aOrbiterA, 36U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 57U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 51U));
            aCarry = aCarry + RotL64(aWandererH, 6U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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

void TwistExpander_PingPong_Arx::KDF_A_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x8B7E891C8A398DA1ULL + 0xE74C356D30388164ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xB34F9E295B51AB5FULL + 0x9CD0071B2A29770AULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x87B289D1652336B5ULL + 0xB1682B970C58FD43ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xF3005BFB9772CED1ULL + 0x8450DFB2C34CBBD8ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xE2D3AB9EE770E88FULL + 0xDA5A15FF973ECCB1ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xF4C6FE30D50CEC6FULL + 0xBB2949022B32D65BULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x828D274A76A9802BULL + 0xA8DAA1DF073F7A37ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xD48C0626D5ACB5ABULL + 0xC573EE3E19A8FA23ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xB4B95A22C725FCADULL + 0xBF86C520FD52E6FDULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x91937296EA7866F7ULL + 0x9526650886915EC5ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x897B7EAF43A003A7ULL + 0x883F40B87D6EDAD9ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xEEAAF817AB4778CDULL + 0xC71006BA0869B216ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xADC33F266CA9243BULL + 0x8CC83CEF5D1876EFULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xDD147189AAD236FBULL + 0xD4AD9684974B7D1EULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xDEEF7133805E5549ULL + 0xAEF7BAB6E8B296D8ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0x9D75B14702B2FAFFULL + 0xE428907594F637A6ULL);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 1898U)) & S_BLOCK1], 30U) ^ RotL64(aOperationLaneB[((aIndex + 7964U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 7207U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 1436U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 4588U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 7815U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCarry, 19U) + RotL64(aPrevious, 5U)) ^ (RotL64(aIngress, 54U) + RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterI = ((((aWandererB + RotL64(aScatter, 29U)) + RotL64(aCarry, 53U)) + 18302975933754610273U) + aOrbiterAssignSaltF[((aIndex + 14U)) & S_SALT1]) + aNonceWordP;
            aOrbiterC = ((aWandererG + RotL64(aPrevious, 56U)) + RotL64(aCarry, 21U)) + 16736972646771456082U;
            aOrbiterA = (((aWandererD + RotL64(aCross, 3U)) + 17389406266488137442U) + aOrbiterAssignSaltD[((aIndex + 7U)) & S_SALT1]) + aNonceWordC;
            aOrbiterF = ((aWandererJ + RotL64(aIngress, 13U)) + RotL64(aCarry, 3U)) + 5252511566486165539U;
            aOrbiterH = (aWandererE + RotL64(aCross, 37U)) + 5730715427422747640U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 6412695646456045825U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 9539701605708994494U) ^ aOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 6511935168278632407U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 18355107116412945722U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 11735742491750132942U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 18129835093627763685U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 12363819388562658842U) + aNonceWordL;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 5861430292304371543U;
            aOrbiterF = RotL64((aOrbiterF * 12989055611235382695U), 27U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterF) + 15027487084595017708U) + aOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1]) + aNonceWordI;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 7012850020745791926U;
            aOrbiterI = RotL64((aOrbiterI * 15952928839355613939U), 19U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterA) + 11904871669287886120U) + aOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1]) + aNonceWordG;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 11199760114477343208U;
            aOrbiterH = RotL64((aOrbiterH * 7156374911847525867U), 11U);
            //
            aIngress = RotL64(aOrbiterA, 3U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterI, 53U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterC, 18U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aPrevious, 57U) + RotL64(aOrbiterA, 57U)) + aOrbiterI) + aNonceWordH) + aWandererUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterH, 39U)) + aOrbiterI);
            aWandererD = aWandererD + ((((RotL64(aCross, 39U) + RotL64(aOrbiterC, 47U)) + aOrbiterF) + RotL64(aCarry, 51U)) + aNonceWordN);
            aWandererB = aWandererB ^ ((((RotL64(aIngress, 13U) + aOrbiterC) + RotL64(aOrbiterH, 10U)) + aNonceWordJ) + aWandererUpdateSaltE[((aIndex + 21U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 24U) + aOrbiterA) + RotL64(aOrbiterH, 27U)) + RotL64(aCarry, 37U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 46U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererJ, 57U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererB, 35U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 11564U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneC[((aIndex + 16108U)) & S_BLOCK1], 53U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 10483U)) & S_BLOCK1], 35U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 9153U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 12142U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 16171U)) & S_BLOCK1], 30U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 12655U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aIngress, 56U) + RotL64(aCarry, 43U)) ^ (RotL64(aPrevious, 5U) + RotL64(aCross, 19U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterI = (((aWandererC + RotL64(aIngress, 3U)) + RotL64(aCarry, 21U)) + 7896237440058555694U) + aNonceWordB;
            aOrbiterE = ((aWandererD + RotL64(aPrevious, 27U)) + 11870529476037558635U) + aOrbiterAssignSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterG = (((aWandererH + RotL64(aScatter, 58U)) + RotL64(aCarry, 5U)) + 9158983227801569448U) + aNonceWordP;
            aOrbiterA = (aWandererJ + RotL64(aCross, 37U)) + 4710172270996950329U;
            aOrbiterF = ((((aWandererF + RotL64(aPrevious, 19U)) + RotL64(aCarry, 41U)) + 14634482800356647630U) + aOrbiterAssignSaltA[((aIndex + 19U)) & S_SALT1]) + aNonceWordK;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 8822207952170610891U) + aNonceWordD;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 13755891414028982553U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 5173750624716006485U), 21U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterG) + 4555293067488040719U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1]) + aNonceWordE;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 2816805148093762081U) ^ aNonceWordL;
            aOrbiterI = RotL64((aOrbiterI * 16838149138341713943U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 2122631477965135190U) + aNonceWordC;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 4592922416380416071U;
            aOrbiterF = RotL64((aOrbiterF * 11644507904538573165U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 7102471666524164715U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 17274623547879474204U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5443572270546181789U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 938587316977094680U) + aOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 18258015823797023523U;
            aOrbiterE = RotL64((aOrbiterE * 6068819567674605919U), 41U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterE, 13U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 26U));
            aIngress = aIngress + RotL64(aOrbiterG, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aIngress, 37U) + aOrbiterE) + RotL64(aOrbiterI, 21U)) + RotL64(aCarry, 23U)) + aNonceWordI);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 29U) + aOrbiterF) + RotL64(aOrbiterG, 30U)) + aNonceWordO);
            aWandererC = aWandererC + (((RotL64(aPrevious, 6U) + aOrbiterG) + RotL64(aOrbiterA, 11U)) + aWandererUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 57U) + aOrbiterF) + RotL64(aOrbiterA, 57U)) + aWandererUpdateSaltF[((aIndex + 4U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterI, 43U)) + aOrbiterF) + RotL64(aCarry, 11U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererJ, 21U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererC, 13U);
            aCarry = aCarry + RotL64(aIngress, 48U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 22514U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneA[((aIndex + 17751U)) & S_BLOCK1], 37U));
            aIngress ^= (RotL64(aOperationLaneB[((aIndex + 23163U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 18989U)) & S_BLOCK1], 24U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16662U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 18376U)) & S_BLOCK1], 20U));
            aCross ^= RotL64(aExpandLaneB[((aIndex + 19160U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCarry, 57U) + RotL64(aPrevious, 24U)) ^ (RotL64(aIngress, 11U) ^ RotL64(aCross, 43U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterF = (((aWandererA + RotL64(aIngress, 43U)) + 5171470532667965920U) + aOrbiterAssignSaltE[((aIndex + 21U)) & S_SALT1]) + aNonceWordA;
            aOrbiterK = ((aWandererE + RotL64(aPrevious, 34U)) + RotL64(aCarry, 3U)) + 750549462358682403U;
            aOrbiterH = ((aWandererD + RotL64(aCross, 13U)) + 3325689257577120525U) + aOrbiterAssignSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterE = (((aWandererH + RotL64(aScatter, 21U)) + RotL64(aCarry, 41U)) + 18031575461559790826U) + aNonceWordJ;
            aOrbiterC = (((aWandererB + RotL64(aIngress, 53U)) + RotL64(aCarry, 19U)) + 13874739537012288677U) + aNonceWordO;
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 4250029868785016865U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 8211158803112611161U;
            aOrbiterH = RotL64((aOrbiterH * 9205801383408193959U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 1083939790236786027U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 3446525462376962464U;
            aOrbiterE = RotL64((aOrbiterE * 13603702473750888213U), 37U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 6973817815000417325U) + aOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 15230876489676945543U) ^ aOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 7737039082964537651U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 9359727659738755880U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 8775170107816327654U) ^ aNonceWordG;
            aOrbiterF = RotL64((aOrbiterF * 6910680458261008653U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 11958941755525038545U) + aNonceWordM;
            aOrbiterC = (((aOrbiterC ^ aOrbiterH) ^ 16966819714283167348U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterC = RotL64((aOrbiterC * 16363457661846050749U), 21U);
            //
            aIngress = RotL64(aOrbiterH, 23U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 13U));
            aIngress = aIngress + RotL64(aOrbiterK, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aScatter, 39U) + aOrbiterF) + RotL64(aOrbiterK, 56U)) + aNonceWordN);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 60U) + RotL64(aOrbiterH, 39U)) + aOrbiterE) + RotL64(aCarry, 37U)) + aWandererUpdateSaltA[((aIndex + 7U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((((RotL64(aIngress, 47U) + aOrbiterE) + RotL64(aOrbiterC, 13U)) + aNonceWordK) + aWandererUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 5U) + RotL64(aOrbiterF, 29U)) + aOrbiterE) + RotL64(aCarry, 21U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 21U) + aOrbiterK) + RotL64(aOrbiterE, 21U)) + aNonceWordH);
            //
            aCarry = aCarry + (RotL64(aWandererE, 12U) ^ aWandererD);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 53U));
            aCarry = aCarry + RotL64(aWandererB, 29U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 31609U)) & S_BLOCK1], 46U) ^ RotL64(aWorkLaneA[((aIndex + 28561U)) & S_BLOCK1], 27U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 25097U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneC[((aIndex + 26966U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 29433U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 30802U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 29118U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCarry, 23U) ^ RotL64(aIngress, 57U)) + (RotL64(aPrevious, 43U) ^ RotL64(aCross, 6U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterG = ((aWandererJ + RotL64(aCross, 28U)) + 13333509828310369865U) + aNonceWordP;
            aOrbiterJ = ((aWandererH + RotL64(aPrevious, 5U)) + 7645352517103840797U) + aNonceWordA;
            aOrbiterA = ((((aWandererK + RotL64(aScatter, 47U)) + RotL64(aCarry, 21U)) + 5310766306660062655U) + aOrbiterAssignSaltF[((aIndex + 6U)) & S_SALT1]) + aNonceWordO;
            aOrbiterF = ((aWandererF + RotL64(aIngress, 13U)) + RotL64(aCarry, 37U)) + 5165635069832352932U;
            aOrbiterB = ((((aWandererD + RotL64(aPrevious, 39U)) + RotL64(aCarry, 51U)) + 15684141764734281849U) + aOrbiterAssignSaltD[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordL;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 3327963374225061738U) + aOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 8625811794878848871U;
            aOrbiterA = RotL64((aOrbiterA * 16327750494894125333U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 7598657468430485291U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterJ) ^ 2881171216276746485U) ^ aOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterF = RotL64((aOrbiterF * 3331350584102843605U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 10237691227222918101U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterA) ^ 6419254255884834497U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterB = RotL64((aOrbiterB * 3816625473642865305U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 4238455444646479956U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 14936613353493061492U;
            aOrbiterJ = RotL64((aOrbiterJ * 3544216916806292273U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 15324699725208372627U) + aNonceWordM;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 9506640480601832011U) ^ aOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12819564111348390227U), 27U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterF, 41U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 28U));
            aIngress = aIngress + RotL64(aOrbiterG, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aCross, 3U) + RotL64(aOrbiterB, 27U)) + aOrbiterF) + aNonceWordH);
            aWandererF = aWandererF ^ ((((RotL64(aIngress, 47U) + RotL64(aOrbiterF, 3U)) + aOrbiterA) + aNonceWordC) + aWandererUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 12U) + RotL64(aOrbiterJ, 48U)) + aOrbiterG) + RotL64(aCarry, 19U));
            aWandererH = aWandererH ^ ((((RotL64(aScatter, 39U) + aOrbiterA) + RotL64(aOrbiterJ, 37U)) + aNonceWordE) + aWandererUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 23U) + RotL64(aOrbiterF, 57U)) + aOrbiterG) + RotL64(aCarry, 43U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 4U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererD, 35U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererH, 57U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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

void TwistExpander_PingPong_Arx::KDF_A_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xAD9DE2BF8A32D123ULL + 0x8533AF8945F90383ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xB03F0DD797EB9F1FULL + 0xE72FB45C83E7A408ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xE1C67D63C3877AF5ULL + 0xA9282A3E197006EEULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xCDA82EA36B3FE371ULL + 0xF7F70085B232EDD6ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xE40A993FD95C82F7ULL + 0xF6624A03047766B6ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xCAEA777778E2DDF7ULL + 0xD71E5902F4C2C4A6ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x8B59D9E0A846206DULL + 0x977F915241EA946BULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xBE3F1849892A75FBULL + 0xC2AC0C3F5BFCF653ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xAAF3EFE95E93A075ULL + 0xD74F72E2889CC837ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xE2BC8AF5D867D7BDULL + 0x8E2BD05CA1344D5DULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xCF531A568EC51E09ULL + 0xEF3E5C059446A143ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xBB1B6C9319CE5AAFULL + 0xCB9A498D2A478BE3ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xCC5307D97CC21361ULL + 0x84505C70FE76B2F4ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xAA7C63684817D935ULL + 0xECFA8787A83E1A56ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xDB40060038F806E3ULL + 0xE2038F72F49164D0ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xEB6DDED1D02142B9ULL + 0xBEF95A42C0E4548EULL);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 7600U)) & S_BLOCK1], 28U) ^ RotL64(aExpandLaneB[((aIndex + 3869U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 1171U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 2011U)) & S_BLOCK1], 50U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 1567U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 5258U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aPrevious, 4U) ^ RotL64(aCarry, 23U)) + (RotL64(aCross, 39U) ^ RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterD = ((aWandererH + RotL64(aCross, 51U)) + 7948891781097675369U) + aNonceWordI;
            aOrbiterI = (((aWandererG + RotL64(aScatter, 60U)) + 13928362874228230226U) + aOrbiterAssignSaltD[((aIndex + 16U)) & S_SALT1]) + aNonceWordD;
            aOrbiterG = (((aWandererJ + RotL64(aIngress, 23U)) + RotL64(aCarry, 41U)) + 10776180542602258926U) + aNonceWordM;
            aOrbiterH = (((aWandererK + RotL64(aPrevious, 11U)) + RotL64(aCarry, 53U)) + 5735115172149470447U) + aNonceWordN;
            aOrbiterC = (aWandererE + RotL64(aCross, 29U)) + 5353591822981766987U;
            aOrbiterK = ((aWandererC + RotL64(aIngress, 41U)) + 562301708107268570U) + aOrbiterAssignSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterJ = ((aWandererA + RotL64(aScatter, 5U)) + RotL64(aCarry, 3U)) + 10467810247578364868U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 14541630141152308564U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 2350076897065139429U;
            aOrbiterG = RotL64((aOrbiterG * 12222554362482034393U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 17519109078651162228U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 6061035173339902910U;
            aOrbiterC = RotL64((aOrbiterC * 10021905773432907835U), 53U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 15654836633731000065U) + aOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 13723521735153718904U;
            aOrbiterK = RotL64((aOrbiterK * 14459516479283070563U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 2849680038315532197U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 17336102435576647923U;
            aOrbiterI = RotL64((aOrbiterI * 10984689101753586739U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 7671010488872356142U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 11485114338165600777U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 4162584865462407791U), 41U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 8759060657343458985U) + aNonceWordB;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 11009137869375286581U;
            aOrbiterH = RotL64((aOrbiterH * 8741417343929809115U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 15792999392743144135U) + aOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterC) ^ 6180808423175992479U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterJ = RotL64((aOrbiterJ * 13681230339693676907U), 47U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterK, 27U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 13U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterD, 19U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterI, 34U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aCross, 19U) + aOrbiterJ) + RotL64(aOrbiterH, 27U)) + aWandererUpdateSaltB[((aIndex + 14U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterI, 60U)) + aOrbiterH);
            aWandererA = aWandererA + (((RotL64(aScatter, 39U) + aOrbiterK) + RotL64(aOrbiterI, 3U)) + aNonceWordO);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 13U) + RotL64(aOrbiterK, 37U)) + aOrbiterG) + aNonceWordK);
            aWandererJ = aWandererJ + (((RotL64(aCross, 3U) + aOrbiterD) + RotL64(aOrbiterC, 13U)) + RotL64(aCarry, 39U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 27U) + aOrbiterD) + RotL64(aOrbiterI, 43U)) + aWandererUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 48U) + aOrbiterG) + RotL64(aOrbiterD, 19U)) + RotL64(aCarry, 53U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 57U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 11U));
            aCarry = aCarry + (RotL64(aWandererC, 51U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererK, 44U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 9441U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneC[((aIndex + 14947U)) & S_BLOCK1], 46U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 12192U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 13912U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 10204U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 9152U)) & S_BLOCK1], 56U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 12090U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aPrevious, 23U) ^ RotL64(aCarry, 51U)) ^ (RotL64(aCross, 36U) + RotL64(aIngress, 3U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterE = (((aWandererB + RotL64(aCross, 29U)) + RotL64(aCarry, 57U)) + 7960325128608297381U) + aNonceWordP;
            aOrbiterG = (aWandererD + RotL64(aIngress, 53U)) + 12773836012104052042U;
            aOrbiterJ = (((aWandererF + RotL64(aPrevious, 11U)) + RotL64(aCarry, 29U)) + 3173972621347773016U) + aNonceWordE;
            aOrbiterI = ((aWandererJ + RotL64(aScatter, 37U)) + 3708401356314308171U) + aNonceWordM;
            aOrbiterH = ((aWandererC + RotL64(aIngress, 23U)) + 950774285720019449U) + aOrbiterAssignSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterD = ((((aWandererE + RotL64(aScatter, 5U)) + RotL64(aCarry, 5U)) + 4170092315705438265U) + aOrbiterAssignSaltE[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordC;
            aOrbiterA = (aWandererG + RotL64(aCross, 44U)) + 17000449130864980747U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 8793910540062893860U) + aNonceWordN;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 520277969543516469U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4150613128885828229U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 12762214857389827271U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 2932451184340207695U) ^ aOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7513337346940091655U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 11062179998786293839U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 7919119215271524178U) ^ aNonceWordA;
            aOrbiterD = RotL64((aOrbiterD * 9053677007180081359U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 1774988449597115155U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 3799792889466518953U) ^ aOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 17512791286490623455U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 1815062051307896589U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 15260373951371654483U;
            aOrbiterA = RotL64((aOrbiterA * 2208604434669491625U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 12867546628945676853U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 7772820973895846946U;
            aOrbiterG = RotL64((aOrbiterG * 7581704643538761985U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 14213957831821966834U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 16561105721170419454U) ^ aOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2540533987337175367U), 37U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterJ, 57U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 5U));
            aIngress = aIngress + (RotL64(aOrbiterG, 19U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterI, 30U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aScatter, 37U) + aOrbiterG) + RotL64(aOrbiterH, 11U));
            aWandererF = aWandererF + (((RotL64(aCross, 57U) + RotL64(aOrbiterA, 47U)) + aOrbiterJ) + aNonceWordG);
            aWandererD = aWandererD ^ ((((RotL64(aPrevious, 23U) + RotL64(aOrbiterD, 29U)) + aOrbiterE) + aNonceWordK) + aWandererUpdateSaltD[((aIndex + 5U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((((RotL64(aIngress, 3U) + RotL64(aOrbiterG, 21U)) + aOrbiterE) + RotL64(aCarry, 57U)) + aNonceWordH) + aWandererUpdateSaltF[((aIndex + 7U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 13U) + aOrbiterG) + RotL64(aOrbiterI, 60U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 44U) + RotL64(aOrbiterI, 53U)) + aOrbiterJ) + RotL64(aCarry, 19U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterA, 5U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererD, 35U) ^ aWandererE);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 21U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 46U));
            aCarry = aCarry + RotL64(aWandererF, 51U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 16942U)) & S_BLOCK1], 46U) ^ RotL64(aExpandLaneA[((aIndex + 24218U)) & S_BLOCK1], 19U));
            aIngress ^= (RotL64(aExpandLaneB[((aIndex + 20384U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneA[((aIndex + 22694U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21827U)) & S_BLOCK1], 6U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 23835U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 22245U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aIngress, 21U)) + (RotL64(aPrevious, 37U) ^ RotL64(aCross, 50U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterK = (((aWandererH + RotL64(aScatter, 3U)) + RotL64(aCarry, 29U)) + 826930775230515406U) + aNonceWordJ;
            aOrbiterB = ((aWandererK + RotL64(aIngress, 47U)) + RotL64(aCarry, 13U)) + 5137814617363250861U;
            aOrbiterD = ((aWandererG + RotL64(aPrevious, 35U)) + 14761561947426681616U) + aOrbiterAssignSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterG = ((aWandererC + RotL64(aCross, 41U)) + 12773023438753662590U) + aNonceWordP;
            aOrbiterE = ((aWandererI + RotL64(aPrevious, 29U)) + RotL64(aCarry, 57U)) + 7331345852207096322U;
            aOrbiterH = ((aWandererE + RotL64(aCross, 12U)) + 3899381212671247460U) + aNonceWordL;
            aOrbiterC = (((aWandererA + RotL64(aIngress, 19U)) + 10072004147620068599U) + aOrbiterAssignSaltA[((aIndex + 16U)) & S_SALT1]) + aNonceWordM;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 3424585039401897560U) + aOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 8246760141625966321U;
            aOrbiterD = RotL64((aOrbiterD * 11478879365443736383U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 3655992860610853290U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 11154618022505863898U;
            aOrbiterH = RotL64((aOrbiterH * 4791494171286145231U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 15629361991059709973U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 10842068502278489664U;
            aOrbiterB = RotL64((aOrbiterB * 17223002513104960799U), 27U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterC) + 5571312349016336686U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordF;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 589313823745748879U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 1356685926549786027U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 13633457935771935260U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterB) ^ 12684602052812183096U) ^ aOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterG = RotL64((aOrbiterG * 4689206269919806711U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 5711307583717354204U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 7181854170553728211U;
            aOrbiterC = RotL64((aOrbiterC * 9835601115561325911U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 1884620014396115821U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 1471516373272364262U;
            aOrbiterE = RotL64((aOrbiterE * 5126319375714848029U), 3U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterC, 53U);
            aIngress = aIngress + (RotL64(aOrbiterD, 60U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 39U));
            aIngress = aIngress + RotL64(aOrbiterH, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aIngress, 13U) + RotL64(aOrbiterE, 57U)) + aOrbiterH) + aNonceWordK);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterB, 50U)) + aOrbiterK);
            aWandererG = aWandererG + ((RotL64(aPrevious, 57U) + aOrbiterK) + RotL64(aOrbiterD, 35U));
            aWandererC = aWandererC ^ ((((RotL64(aCross, 51U) + aOrbiterH) + RotL64(aOrbiterG, 21U)) + aNonceWordD) + aWandererUpdateSaltA[((aIndex + 18U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 6U) + aOrbiterD) + RotL64(aOrbiterG, 3U)) + RotL64(aCarry, 11U)) + aNonceWordG);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 35U) + aOrbiterC) + RotL64(aOrbiterE, 13U)) + aWandererUpdateSaltE[((aIndex + 20U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 43U) + RotL64(aOrbiterE, 43U)) + aOrbiterD) + RotL64(aCarry, 37U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 57U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererA, 11U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererK, 48U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererG, 27U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 26874U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneA[((aIndex + 29207U)) & S_BLOCK1], 40U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 31459U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 32321U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 31294U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 26851U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 29468U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aIngress, 3U) + RotL64(aCarry, 24U)) ^ (RotL64(aPrevious, 39U) ^ RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterB = ((aWandererB + RotL64(aCross, 35U)) + RotL64(aCarry, 21U)) + 13278949403988203974U;
            aOrbiterA = (((aWandererD + RotL64(aScatter, 5U)) + RotL64(aCarry, 35U)) + 9213599924054673756U) + aNonceWordE;
            aOrbiterF = (((aWandererI + RotL64(aPrevious, 12U)) + RotL64(aCarry, 5U)) + 1255746482932381798U) + aNonceWordG;
            aOrbiterC = ((aWandererE + RotL64(aIngress, 41U)) + 11575321997144516122U) + aOrbiterAssignSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = (aWandererK + RotL64(aCross, 51U)) + 15881587525529432437U;
            aOrbiterE = ((aWandererG + RotL64(aPrevious, 27U)) + 9846195809864862707U) + aNonceWordJ;
            aOrbiterH = ((aWandererJ + RotL64(aIngress, 57U)) + 12319815691858217670U) + aOrbiterAssignSaltC[((aIndex + 3U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 16322617427294439587U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 16332130810525887437U) ^ aNonceWordK;
            aOrbiterF = RotL64((aOrbiterF * 7588076439690559343U), 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 4920951156015336794U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 16767126455124552329U;
            aOrbiterC = RotL64((aOrbiterC * 4440352337076842603U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 12553595911087945223U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 1437522202135436142U;
            aOrbiterH = RotL64((aOrbiterH * 2001992794165550905U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 12313100454852227143U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 2761983020631055729U) ^ aOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 3874839760378039509U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 17635303588421554367U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 788212489507463763U) ^ aOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 17896475584538528059U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 5192552894670654434U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 6784748488807738811U;
            aOrbiterK = RotL64((aOrbiterK * 8077237651953896479U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 16113417046719114943U) + aNonceWordP;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 1096874945215225916U;
            aOrbiterE = RotL64((aOrbiterE * 17308604412622879833U), 35U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterF, 47U);
            aIngress = aIngress + (RotL64(aOrbiterH, 28U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterE, 5U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterB, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aPrevious, 37U) + aOrbiterC) + RotL64(aOrbiterK, 29U)) + aNonceWordO);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterH, 51U)) + aOrbiterB);
            aWandererB = aWandererB + ((RotL64(aIngress, 51U) + RotL64(aOrbiterF, 60U)) + aOrbiterA);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 12U) + aOrbiterH) + RotL64(aOrbiterE, 23U));
            aWandererE = aWandererE + ((((RotL64(aIngress, 27U) + aOrbiterC) + RotL64(aOrbiterA, 3U)) + RotL64(aCarry, 47U)) + aNonceWordA);
            aWandererG = aWandererG ^ ((((RotL64(aScatter, 43U) + aOrbiterB) + RotL64(aOrbiterC, 13U)) + aNonceWordC) + aWandererUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererI = aWandererI + (((((RotL64(aCross, 21U) + aOrbiterE) + RotL64(aOrbiterB, 35U)) + RotL64(aCarry, 5U)) + aNonceWordB) + aWandererUpdateSaltB[((aIndex + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 37U) ^ aWandererE);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 60U));
            aCarry = aCarry + (RotL64(aWandererK, 51U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererJ, 41U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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

void TwistExpander_PingPong_Arx::KDF_B_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xAD322F8E30BBAA89ULL + 0xB4B9E983055B473DULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xE158549C87AE94BFULL + 0xC4C4A9B7BD02B640ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xB678A806121E52D7ULL + 0xA9E3A47300D4F5CFULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x958CF4AB31C76DAFULL + 0xEA6449602C755D0DULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x936680DCFFAB36E3ULL + 0xE88F0972CE3CF24CULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xD2BA0AAB9709CF65ULL + 0xAA33780EC930EE39ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xE1AFA1B03563A9D7ULL + 0xE0984BD2510820F1ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xB84B086CCDE20C3FULL + 0x86A6911ADDCB6A9EULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xA222717B2AFB9B25ULL + 0xF97355A024FBDADEULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xDCB65D852E13C44BULL + 0xC09CFCF1A4F35DE3ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xDAC98FE9B9C2732FULL + 0x81AF616088AF8913ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xF6AAD02FC8962DBBULL + 0xCD4CC7DDEFE65A4AULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xF52895DB688AA165ULL + 0xC18F2FAAF70AE210ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xF287834D9F7514FDULL + 0xFC0EA47040A7F536ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xA2BE8387EF534267ULL + 0xF4BAA7D7C644642DULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xECF586C4A8B94E01ULL + 0x8D74F0E7E020FCDEULL);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 2128U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneB[((aIndex + 5390U)) & S_BLOCK1], 38U));
            aIngress ^= RotL64(aOperationLaneA[((aIndex + 1680U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 487U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 3967U)) & S_BLOCK1], 42U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aPrevious, 57U) + RotL64(aCross, 37U)) ^ (RotL64(aIngress, 24U) ^ RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterG = (aWandererI + RotL64(aCross, 13U)) + 14157904117287696136U;
            aOrbiterK = ((((aWandererH + RotL64(aScatter, 53U)) + RotL64(aCarry, 47U)) + 7369512677371640676U) + aOrbiterAssignSaltD[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordE;
            aOrbiterH = ((aWandererC + RotL64(aPrevious, 5U)) + RotL64(aCarry, 27U)) + 8411250745902073798U;
            aOrbiterA = ((aWandererD + RotL64(aIngress, 43U)) + RotL64(aCarry, 13U)) + 5002041814539710275U;
            aOrbiterC = (aWandererA + RotL64(aCross, 36U)) + 9538041410816283124U;
            aOrbiterD = (((aWandererB + RotL64(aIngress, 27U)) + 5210700103927513061U) + aOrbiterAssignSaltB[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordM;
            aOrbiterE = (aWandererK + RotL64(aPrevious, 21U)) + 7600709399101287982U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 2366369466696580499U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 5544575244203019109U) ^ aOrbiterUpdateSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 16231219246786333057U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 8710073749110329779U) + aNonceWordI;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 15998211310115361630U;
            aOrbiterK = RotL64((aOrbiterK * 15275657696897688955U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 15354357553877376422U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 10657523549259276169U) ^ aNonceWordJ;
            aOrbiterE = RotL64((aOrbiterE * 13695239532898311073U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 10405750198355464768U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 3465819693133515142U) ^ aOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 14678343718277562799U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 16724189641701408630U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 3484340153620198872U) ^ aNonceWordA;
            aOrbiterD = RotL64((aOrbiterD * 17247547677520703125U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 7420442404884871126U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 11138445997256757636U) ^ aOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11167543379937571127U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 1428191560884663125U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 16950093140800653985U) ^ aOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4423012306984814805U), 51U);
            //
            aIngress = RotL64(aOrbiterK, 51U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterH, 37U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterA, 27U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterD, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aIngress, 27U) + aOrbiterD) + RotL64(aOrbiterC, 47U)) + aNonceWordD);
            aWandererH = aWandererH + ((RotL64(aScatter, 39U) + RotL64(aOrbiterD, 60U)) + aOrbiterG);
            aWandererI = aWandererI ^ ((((RotL64(aPrevious, 5U) + RotL64(aOrbiterK, 13U)) + aOrbiterG) + aNonceWordN) + aWandererUpdateSaltC[((aIndex + 13U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 53U) + aOrbiterE) + RotL64(aOrbiterG, 27U)) + RotL64(aCarry, 11U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 21U) + aOrbiterH) + RotL64(aOrbiterE, 21U)) + aNonceWordH);
            aWandererD = aWandererD + ((((RotL64(aIngress, 11U) + aOrbiterA) + RotL64(aOrbiterD, 53U)) + RotL64(aCarry, 47U)) + aWandererUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aCross, 60U) + RotL64(aOrbiterK, 35U)) + aOrbiterD) + aNonceWordK);
            //
            aCarry = aCarry + (RotL64(aWandererH, 29U) ^ aWandererD);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 5U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 34U));
            aCarry = aCarry + RotL64(aWandererB, 13U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aFireLaneA[((aIndex + 7471U)) & S_BLOCK1], 56U) ^ RotL64(aWorkLaneC[((aIndex + 9035U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 9417U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 7056U)) & S_BLOCK1], 28U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 9903U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 8301U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aPrevious, 58U) + RotL64(aCross, 29U)) ^ (RotL64(aCarry, 41U) + RotL64(aIngress, 13U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterG = ((aWandererK + RotL64(aScatter, 47U)) + RotL64(aCarry, 47U)) + 10038936806177516123U;
            aOrbiterC = ((aWandererG + RotL64(aCross, 39U)) + 1773168435195292638U) + aOrbiterAssignSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterF = (aWandererH + RotL64(aPrevious, 57U)) + 10655711161526628072U;
            aOrbiterE = ((((aWandererA + RotL64(aIngress, 21U)) + RotL64(aCarry, 35U)) + 14422295664639740437U) + aOrbiterAssignSaltF[(((31U - aIndex) + 28U)) & S_SALT1]) + aNonceWordA;
            aOrbiterI = (aWandererD + RotL64(aScatter, 11U)) + 4125228715513159576U;
            aOrbiterD = ((aWandererC + RotL64(aCross, 30U)) + RotL64(aCarry, 13U)) + 3670449653158650845U;
            aOrbiterA = ((aWandererJ + RotL64(aIngress, 3U)) + 17553727567180813057U) + aNonceWordI;
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 5111401772713882743U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 7688573124662314413U;
            aOrbiterF = RotL64((aOrbiterF * 10846442063022821393U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 9438375825507814395U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 14177477039902118886U;
            aOrbiterI = RotL64((aOrbiterI * 6467406626985022537U), 5U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterF) + 16329942595859623928U) + aOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1]) + aNonceWordB;
            aOrbiterA = (((aOrbiterA ^ aOrbiterD) ^ 3990536794006836672U) ^ aOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterA = RotL64((aOrbiterA * 579024714339065373U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 5072881436583180756U) + aNonceWordJ;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 16789727877867289997U;
            aOrbiterG = RotL64((aOrbiterG * 8766246302636197905U), 43U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterD) + 17313956922306689438U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordO;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 11530878396329822041U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 11356860047841383129U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 3612616532321160196U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 4172189825359187763U;
            aOrbiterD = RotL64((aOrbiterD * 12938945495299393177U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 8677279703778052804U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 1912172980909479362U;
            aOrbiterC = RotL64((aOrbiterC * 10053289257955474143U), 29U);
            //
            aIngress = RotL64(aOrbiterI, 43U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 29U));
            aIngress = aIngress + (RotL64(aOrbiterC, 57U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterG, 4U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aScatter, 5U) + RotL64(aOrbiterD, 27U)) + aOrbiterA);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterI, 21U)) + aOrbiterF);
            aWandererG = aWandererG + ((RotL64(aCross, 19U) + aOrbiterI) + RotL64(aOrbiterG, 37U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 51U) + aOrbiterE) + RotL64(aOrbiterG, 13U));
            aWandererJ = aWandererJ + ((((RotL64(aCross, 13U) + RotL64(aOrbiterE, 60U)) + aOrbiterF) + RotL64(aCarry, 5U)) + aWandererUpdateSaltE[((aIndex + 21U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 41U) + RotL64(aOrbiterI, 53U)) + aOrbiterD) + aNonceWordP);
            aWandererC = aWandererC + (((((RotL64(aIngress, 28U) + aOrbiterC) + RotL64(aOrbiterE, 43U)) + RotL64(aCarry, 53U)) + aNonceWordL) + aWandererUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 6U));
            aCarry = aCarry + (RotL64(aWandererH, 51U) ^ aWandererK);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 13U));
            aCarry = aCarry + RotL64(aWandererG, 43U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 13129U)) & S_BLOCK1], 48U) ^ RotL64(aWorkLaneD[((aIndex + 11257U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 13198U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 12167U)) & S_BLOCK1], 40U) ^ RotL64(aFireLaneA[((aIndex + 14754U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aIngress, 27U) + RotL64(aCarry, 43U)) ^ (RotL64(aCross, 6U) + RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterB = (aWandererB + RotL64(aPrevious, 19U)) + 13174219512651137892U;
            aOrbiterJ = ((aWandererH + RotL64(aScatter, 11U)) + RotL64(aCarry, 3U)) + 2715455762789269341U;
            aOrbiterF = ((aWandererG + RotL64(aIngress, 41U)) + 1338018183235594313U) + aNonceWordB;
            aOrbiterA = ((aWandererJ + RotL64(aCross, 29U)) + 16566866551729552930U) + aNonceWordH;
            aOrbiterD = ((aWandererE + RotL64(aScatter, 60U)) + 6901845297307236726U) + aOrbiterAssignSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterI = (((aWandererD + RotL64(aCross, 35U)) + RotL64(aCarry, 29U)) + 2476078302049201718U) + aNonceWordI;
            aOrbiterK = ((((aWandererC + RotL64(aPrevious, 47U)) + RotL64(aCarry, 47U)) + 15531109473927052260U) + aOrbiterAssignSaltE[((aIndex + 3U)) & S_SALT1]) + aNonceWordG;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 4087849380858572351U) + aNonceWordN;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 5167830630098599644U;
            aOrbiterF = RotL64((aOrbiterF * 1982835131228146099U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 7275995452428627217U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 14794340370010024117U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8779497557416568379U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 8509217403041662849U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 2321522025240806996U) ^ aNonceWordE;
            aOrbiterD = RotL64((aOrbiterD * 113568101672878697U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 5676672952755594051U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 2304681269233504384U) ^ aNonceWordK;
            aOrbiterK = RotL64((aOrbiterK * 15731441084605554497U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 8383399721062437300U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 13181984036942227666U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 1648761328771932069U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 13602604532551684210U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterK) ^ 12725687663616352843U) ^ aOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterB = RotL64((aOrbiterB * 4684699861686199753U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 5831790822416009806U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 4535048543735457407U;
            aOrbiterA = RotL64((aOrbiterA * 12076777878870257053U), 37U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterF, 27U);
            aIngress = aIngress + (RotL64(aOrbiterD, 37U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 43U));
            aIngress = aIngress + RotL64(aOrbiterA, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterF, 21U)) + aOrbiterB) + aNonceWordD);
            aWandererD = aWandererD + (((RotL64(aScatter, 50U) + RotL64(aOrbiterI, 10U)) + aOrbiterK) + RotL64(aCarry, 19U));
            aWandererB = aWandererB ^ ((((RotL64(aIngress, 27U) + aOrbiterA) + RotL64(aOrbiterB, 47U)) + aNonceWordO) + aWandererUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 57U) + aOrbiterB) + RotL64(aOrbiterK, 29U)) + aNonceWordJ);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 19U) + RotL64(aOrbiterF, 53U)) + aOrbiterD) + aWandererUpdateSaltA[((aIndex + 11U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aIngress, 41U) + aOrbiterJ) + RotL64(aOrbiterF, 35U)) + RotL64(aCarry, 5U)) + aNonceWordP);
            aWandererH = aWandererH ^ ((RotL64(aCross, 13U) + aOrbiterF) + RotL64(aOrbiterA, 41U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 14U) ^ aWandererD);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 41U));
            aCarry = aCarry + (RotL64(aWandererC, 3U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererG, 19U);
            aCarry = aCarry + RotL64(aIngress, 60U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 19274U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneC[((aIndex + 18938U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aOperationLaneD[((aIndex + 20539U)) & S_BLOCK1], 60U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordA));
            //
            aCross = RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 21645U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneD[((aIndex + 21093U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCross, 53U) + RotL64(aPrevious, 21U)) ^ (RotL64(aCarry, 34U) ^ RotL64(aIngress, 3U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterC = ((((aWandererK + RotL64(aPrevious, 13U)) + RotL64(aCarry, 57U)) + 15316464782468770057U) + aOrbiterAssignSaltD[((aIndex + 21U)) & S_SALT1]) + aNonceWordH;
            aOrbiterJ = ((aWandererA + RotL64(aIngress, 30U)) + 6642872057476351588U) + aOrbiterAssignSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = ((aWandererD + RotL64(aScatter, 57U)) + RotL64(aCarry, 23U)) + 660732654689529192U;
            aOrbiterH = (((aWandererB + RotL64(aCross, 51U)) + RotL64(aCarry, 5U)) + 7235418086884000655U) + aNonceWordC;
            aOrbiterB = ((aWandererH + RotL64(aPrevious, 3U)) + 14784518476694580493U) + aNonceWordD;
            aOrbiterI = ((aWandererJ + RotL64(aCross, 19U)) + 12222433977933449375U) + aNonceWordB;
            aOrbiterG = (aWandererC + RotL64(aIngress, 39U)) + 8573001207708329927U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 16035256260815013172U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 15767726974121910203U;
            aOrbiterF = RotL64((aOrbiterF * 719060452537759331U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 17712217935322939971U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 13488963456923357159U) ^ aNonceWordP;
            aOrbiterI = RotL64((aOrbiterI * 16785285630840310405U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 10222949131965611079U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 1495561412321657209U;
            aOrbiterB = RotL64((aOrbiterB * 9706305581868526265U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 16156530750584361434U) + aOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 7773792489045606309U;
            aOrbiterH = RotL64((aOrbiterH * 10730624207715601393U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 11544578291333360613U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 3665587867634242865U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4840528190844842595U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 15248434984650998090U) + aNonceWordF;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 15487979645426567581U;
            aOrbiterC = RotL64((aOrbiterC * 10868107809356766183U), 47U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterI) + 6972347795052712690U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordL;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 16074994810010431338U;
            aOrbiterG = RotL64((aOrbiterG * 1262655238856775853U), 3U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterI, 35U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 3U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 11U));
            aIngress = aIngress + RotL64(aOrbiterC, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterH, 51U)) + aOrbiterB) + aNonceWordN);
            aWandererC = aWandererC + ((((RotL64(aCross, 60U) + RotL64(aOrbiterC, 27U)) + aOrbiterF) + RotL64(aCarry, 23U)) + aWandererUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterH, 43U)) + aOrbiterF);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 35U) + aOrbiterJ) + RotL64(aOrbiterF, 35U)) + RotL64(aCarry, 47U)) + aNonceWordO);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterG, 12U)) + aOrbiterI);
            aWandererH = aWandererH + ((((RotL64(aScatter, 5U) + aOrbiterH) + RotL64(aOrbiterI, 3U)) + aNonceWordM) + aWandererUpdateSaltC[((aIndex + 3U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aCross, 53U) + RotL64(aOrbiterI, 21U)) + aOrbiterC) + aNonceWordE);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 14U));
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererJ, 39U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererD, 47U);
            aCarry = aCarry + RotL64(aIngress, 10U);
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
            aIngress = RotL64(aExpandLaneB[((aIndex + 21991U)) & S_BLOCK1], 40U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 24126U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 22604U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneA[((aIndex + 26905U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCross, 38U) + RotL64(aIngress, 51U)) ^ (RotL64(aCarry, 19U) + RotL64(aPrevious, 3U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterF = ((aWandererK + RotL64(aScatter, 5U)) + 13296600294247799698U) + aNonceWordI;
            aOrbiterE = (aWandererC + RotL64(aPrevious, 57U)) + 5818503518080877515U;
            aOrbiterJ = (((aWandererE + RotL64(aCross, 40U)) + RotL64(aCarry, 53U)) + 6735784238734173597U) + aOrbiterAssignSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = ((aWandererF + RotL64(aIngress, 51U)) + 7368398209488856201U) + aNonceWordA;
            aOrbiterA = (aWandererB + RotL64(aCross, 21U)) + 961734029066455638U;
            aOrbiterD = (((aWandererH + RotL64(aIngress, 13U)) + RotL64(aCarry, 19U)) + 797011946660892011U) + aOrbiterAssignSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterI = (((aWandererJ + RotL64(aPrevious, 27U)) + RotL64(aCarry, 3U)) + 12841876018396622350U) + aNonceWordJ;
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 16213253970483895623U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterF) ^ 15186950557113470375U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterJ = RotL64((aOrbiterJ * 4647470430467908107U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 5117930310827477341U) + aOrbiterUpdateSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterA = (((aOrbiterA ^ aOrbiterJ) ^ 12265429373166094162U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterA = RotL64((aOrbiterA * 1522823535151532249U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 13920531346698601568U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 14695405206998211456U;
            aOrbiterD = RotL64((aOrbiterD * 13950964363414164279U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 7851960904825938443U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 9501511171732550190U) ^ aNonceWordH;
            aOrbiterI = RotL64((aOrbiterI * 5614164120361489613U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 5663365182245722077U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 9607860124321315555U;
            aOrbiterK = RotL64((aOrbiterK * 3461820361914280601U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 18171052650586819280U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 3442698321538580861U;
            aOrbiterE = RotL64((aOrbiterE * 6317525514963824829U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 1491052813469258970U) + aNonceWordF;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 3956599824067616133U) ^ aOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2928600779267623085U), 3U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterA, 39U);
            aIngress = aIngress + (RotL64(aOrbiterD, 13U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 29U));
            aIngress = aIngress + RotL64(aOrbiterF, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aScatter, 48U) + RotL64(aOrbiterK, 57U)) + aOrbiterJ);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 57U) + aOrbiterJ) + RotL64(aOrbiterD, 5U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 29U) + aOrbiterE) + RotL64(aOrbiterI, 51U)) + RotL64(aCarry, 41U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterF, 43U)) + aOrbiterI);
            aWandererK = aWandererK + (((((RotL64(aIngress, 23U) + aOrbiterD) + RotL64(aOrbiterA, 23U)) + RotL64(aCarry, 23U)) + aNonceWordK) + aWandererUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aCross, 11U) + aOrbiterE) + RotL64(aOrbiterF, 12U)) + aNonceWordC);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 41U) + RotL64(aOrbiterK, 37U)) + aOrbiterI) + aWandererUpdateSaltD[((aIndex + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 24U));
            aCarry = aCarry + (RotL64(aWandererF, 13U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererJ, 43U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 28797U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneA[((aIndex + 32738U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29847U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((aIndex + 30958U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aPrevious, 23U) ^ RotL64(aCross, 51U)) + (RotL64(aCarry, 4U) ^ RotL64(aIngress, 37U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterF = ((aWandererA + RotL64(aIngress, 22U)) + 16922357079016918108U) + aOrbiterAssignSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = ((((aWandererB + RotL64(aPrevious, 47U)) + RotL64(aCarry, 57U)) + 11771749797137599131U) + aOrbiterAssignSaltE[((aIndex + 28U)) & S_SALT1]) + aNonceWordH;
            aOrbiterD = (((aWandererF + RotL64(aScatter, 5U)) + RotL64(aCarry, 5U)) + 4635668433708036077U) + aNonceWordM;
            aOrbiterA = (aWandererC + RotL64(aCross, 29U)) + 15827952719230577008U;
            aOrbiterK = (aWandererK + RotL64(aScatter, 39U)) + 1495675306110023086U;
            aOrbiterB = ((aWandererI + RotL64(aIngress, 53U)) + RotL64(aCarry, 29U)) + 7294835466949728365U;
            aOrbiterC = (aWandererH + RotL64(aPrevious, 11U)) + 179122461212041978U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 545981421632236251U) + aOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 15338259639814630535U;
            aOrbiterD = RotL64((aOrbiterD * 14895421566334357871U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 12924313840290895215U) + aNonceWordG;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 17846785921286020610U) ^ aNonceWordL;
            aOrbiterK = RotL64((aOrbiterK * 18309347016029917133U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 5721472794107057875U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 16359630793856870319U) ^ aNonceWordO;
            aOrbiterC = RotL64((aOrbiterC * 14186771515526698907U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 10614102110239037308U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 16421992251278236531U;
            aOrbiterA = RotL64((aOrbiterA * 2561232904676068089U), 53U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 8668149834861244963U) + aNonceWordB;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 12699331834360948734U;
            aOrbiterF = RotL64((aOrbiterF * 2249360824172616357U), 41U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 4470693178142950471U) + aOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 526000656022724741U;
            aOrbiterB = RotL64((aOrbiterB * 16688501462334673493U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 6880246132270094141U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 7126466778855297013U;
            aOrbiterG = RotL64((aOrbiterG * 5692237926830293205U), 3U);
            //
            aIngress = RotL64(aOrbiterK, 53U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 13U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 5U));
            aIngress = aIngress + RotL64(aOrbiterG, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aIngress, 48U) + RotL64(aOrbiterD, 41U)) + aOrbiterC) + RotL64(aCarry, 51U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterG, 57U)) + aOrbiterK);
            aWandererH = aWandererH + (((RotL64(aCross, 11U) + RotL64(aOrbiterB, 47U)) + aOrbiterD) + RotL64(aCarry, 3U));
            aWandererI = aWandererI ^ ((((RotL64(aPrevious, 41U) + RotL64(aOrbiterK, 11U)) + aOrbiterF) + aNonceWordK) + aWandererUpdateSaltF[((aIndex + 17U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 21U) + aOrbiterA) + RotL64(aOrbiterD, 30U)) + aNonceWordF);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 27U) + aOrbiterK) + RotL64(aOrbiterB, 3U)) + aWandererUpdateSaltA[((aIndex + 5U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aIngress, 35U) + RotL64(aOrbiterA, 23U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererA, 47U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererC, 18U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererF, 3U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererB, 51U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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

void TwistExpander_PingPong_Arx::KDF_B_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xFDA91C647A1607E7ULL + 0xF9507602FE35314FULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xB2BCC8CA1212388DULL + 0x85BD1C1429811ED4ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x8CB57B07E2898925ULL + 0xBB9D3ECBEAE29368ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xFEFD0DA61173C19FULL + 0x8FB9DD7111DB1142ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x9595498C2D07F025ULL + 0x8B94904225D147CAULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xA0BDAFB7424CDC9BULL + 0xC137DFE44157D4B3ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xD2A4B77BC3E8F3D3ULL + 0x84E536D7C005996DULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x965BCBB541956D61ULL + 0x9B526C379AB5ECE1ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xF667415BC238031BULL + 0xE9D6B261A112B3F5ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xBCE3E0CA664BCFABULL + 0x975A23DD04F293B6ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xC6EF98437DAB936BULL + 0xC6FE85928C37A5DAULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xB9121756B80BE425ULL + 0xEE0332B0EA3C1B0DULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xCC12ED451D71A36FULL + 0x9A64B214C9F21C2BULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x90903241786A81B5ULL + 0xDFFCB4CDFC5D687FULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xA49E96B6001D2FE1ULL + 0xE81EFC544780A87CULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xB2F94E6C40DF2C87ULL + 0xEB2E496AC1C40369ULL);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 5284U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneB[((aIndex + 5961U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 5937U)) & S_BLOCK1], 20U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4251U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 1157U)) & S_BLOCK1], 60U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 8064U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 35U)) + (RotL64(aIngress, 50U) ^ RotL64(aCross, 21U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterA = (aWandererH + RotL64(aScatter, 11U)) + 10404808878585437255U;
            aOrbiterG = (aWandererK + RotL64(aPrevious, 43U)) + 10587858736301591439U;
            aOrbiterK = (((aWandererE + RotL64(aCross, 18U)) + RotL64(aCarry, 5U)) + 1430530909801644435U) + aNonceWordD;
            aOrbiterF = ((aWandererG + RotL64(aIngress, 5U)) + RotL64(aCarry, 11U)) + 9090938022430118902U;
            aOrbiterE = (aWandererB + RotL64(aCross, 41U)) + 12936604311751121235U;
            aOrbiterI = (aWandererI + RotL64(aIngress, 13U)) + 1000583006020232032U;
            aOrbiterJ = ((aWandererJ + RotL64(aScatter, 53U)) + 12352532088997042232U) + aOrbiterAssignSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterC = ((aWandererA + RotL64(aPrevious, 23U)) + 16723410947058502564U) + aNonceWordM;
            aOrbiterH = (aWandererD + RotL64(aScatter, 29U)) + 16614089235313154270U;
            aOrbiterD = ((aWandererC + RotL64(aIngress, 37U)) + 4245553025593349277U) + aNonceWordE;
            aOrbiterB = (((aWandererF + RotL64(aPrevious, 46U)) + RotL64(aCarry, 27U)) + 3353146318549477494U) + aOrbiterAssignSaltF[((aIndex + 27U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 5935727336135635196U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 10312187090293319667U;
            aOrbiterK = RotL64((aOrbiterK * 1395964500396711899U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 12192843181244744484U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 2542570124502586365U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 17222847847573534963U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 3315472769469002444U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 17512858811783071174U;
            aOrbiterE = RotL64((aOrbiterE * 9070400454074283765U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 16633218007427888082U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 2502077714838858460U;
            aOrbiterH = RotL64((aOrbiterH * 970762420815997725U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 14792910273226469214U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterD) ^ 15739513291150783151U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterJ = RotL64((aOrbiterJ * 11896279674116906915U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 2192903544350345992U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 844428341223009295U;
            aOrbiterC = RotL64((aOrbiterC * 4768368713974002539U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 2998511458298901402U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 7790789639864783373U;
            aOrbiterB = RotL64((aOrbiterB * 9173097618440495497U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 4540735375055164995U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 13700342877362633034U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 14730797752841670505U), 39U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 16966725424259324323U) + aNonceWordK;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 5945539295893015935U;
            aOrbiterF = RotL64((aOrbiterF * 12226268057062268981U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 12560355243513521281U) + aNonceWordF;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 2104086086480258265U;
            aOrbiterI = RotL64((aOrbiterI * 17989755118752755577U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 4476697099257280568U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 10404808878585437255U;
            aOrbiterA = RotL64((aOrbiterA * 6245415417832089357U), 35U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterH, 30U);
            aIngress = aIngress + (RotL64(aOrbiterG, 11U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterJ, 27U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 37U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 13U));
            aIngress = aIngress + RotL64(aOrbiterC, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aScatter, 39U) + RotL64(aOrbiterK, 19U)) + aOrbiterB) + RotL64(aCarry, 19U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 11U) + aOrbiterE) + RotL64(aOrbiterD, 56U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 37U) + aOrbiterD) + RotL64(aOrbiterG, 37U)) + RotL64(aCarry, 29U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 6U) + aOrbiterC) + RotL64(aOrbiterK, 23U));
            aWandererC = aWandererC + ((((RotL64(aPrevious, 51U) + aOrbiterA) + RotL64(aOrbiterB, 35U)) + aNonceWordL) + aWandererUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterF, 13U)) + aOrbiterE);
            aWandererI = aWandererI + (((RotL64(aCross, 47U) + aOrbiterD) + RotL64(aOrbiterI, 11U)) + aNonceWordJ);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 60U) + aOrbiterF) + RotL64(aOrbiterH, 41U)) + aWandererUpdateSaltA[((aIndex + 19U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aPrevious, 29U) + RotL64(aOrbiterC, 6U)) + aOrbiterI);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterC, 47U)) + aOrbiterJ);
            aWandererF = aWandererF + ((RotL64(aCross, 57U) + aOrbiterA) + RotL64(aOrbiterH, 21U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 11U));
            aCarry = aCarry + (RotL64(aWandererC, 60U) ^ aWandererA);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 53U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 13U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 23U));
            aCarry = aCarry + RotL64(aWandererD, 29U);
            aCarry = aCarry + RotL64(aIngress, 6U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 11659U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneC[((aIndex + 8865U)) & S_BLOCK1], 51U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 8870U)) & S_BLOCK1], 35U) ^ RotL64(aFireLaneC[((aIndex + 12359U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 15221U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 16125U)) & S_BLOCK1], 4U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 11479U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aPrevious, 41U) + RotL64(aCarry, 11U)) ^ (RotL64(aCross, 23U) + RotL64(aIngress, 60U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterI = (((aWandererC + RotL64(aScatter, 44U)) + RotL64(aCarry, 19U)) + 7075016829833562104U) + aOrbiterAssignSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = ((aWandererD + RotL64(aCross, 41U)) + 8783765886115517036U) + aNonceWordE;
            aOrbiterJ = ((aWandererH + RotL64(aPrevious, 51U)) + 2996723892384565829U) + aNonceWordD;
            aOrbiterD = ((aWandererA + RotL64(aIngress, 13U)) + 9494134707342189476U) + aOrbiterAssignSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterB = (aWandererI + RotL64(aPrevious, 35U)) + 5052642981395679904U;
            aOrbiterK = (aWandererJ + RotL64(aCross, 19U)) + 8766787055127962238U;
            aOrbiterH = ((aWandererE + RotL64(aScatter, 58U)) + 4467211954388738079U) + aNonceWordI;
            aOrbiterA = ((aWandererB + RotL64(aIngress, 47U)) + RotL64(aCarry, 57U)) + 8030255604633658608U;
            aOrbiterE = (aWandererG + RotL64(aCross, 3U)) + 16962408063455702251U;
            aOrbiterC = ((aWandererK + RotL64(aIngress, 27U)) + 3768222186567699076U) + aNonceWordF;
            aOrbiterF = ((aWandererF + RotL64(aPrevious, 53U)) + RotL64(aCarry, 23U)) + 14930990410207899871U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 14179761938395502502U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 1879084742719898108U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 16783034788172670121U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 5535012408925981515U) + aNonceWordJ;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 12792553516710295939U;
            aOrbiterG = RotL64((aOrbiterG * 8577530993755159329U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 8979253163346099252U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 5559189896063990740U) ^ aOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8832485423727331621U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 13937564337299044079U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 2393376759689394948U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 2352815657830413941U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 12647519563697356479U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 10946871249960389549U;
            aOrbiterI = RotL64((aOrbiterI * 6272580371881237173U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 13376798695582123147U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 10958115913599631271U;
            aOrbiterC = RotL64((aOrbiterC * 18233981473003345217U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 4283914227806672773U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 910842005516235816U) ^ aNonceWordB;
            aOrbiterB = RotL64((aOrbiterB * 6722229871617873429U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 1509644316619370324U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 165987596716078174U;
            aOrbiterK = RotL64((aOrbiterK * 13600064054240185123U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 12491315345199091186U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 5982431705686495125U;
            aOrbiterF = RotL64((aOrbiterF * 2547243804779022665U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 231183123382412440U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 2872632389683254396U;
            aOrbiterD = RotL64((aOrbiterD * 1972278820468847241U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 15259314110008210315U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 7075016829833562104U) ^ aNonceWordC;
            aOrbiterA = RotL64((aOrbiterA * 8350093877370898869U), 37U);
            //
            aIngress = RotL64(aOrbiterH, 3U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 38U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 19U));
            aIngress = aIngress + (RotL64(aOrbiterK, 29U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 13U));
            aIngress = aIngress + RotL64(aOrbiterJ, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterE, 47U)) + aOrbiterF) + RotL64(aCarry, 27U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 53U) + aOrbiterJ) + RotL64(aOrbiterD, 53U));
            aWandererF = aWandererF + (((RotL64(aScatter, 11U) + RotL64(aOrbiterC, 13U)) + aOrbiterD) + RotL64(aCarry, 47U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterK, 37U)) + aOrbiterA);
            aWandererE = aWandererE + ((RotL64(aPrevious, 3U) + RotL64(aOrbiterD, 19U)) + aOrbiterH);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 48U) + aOrbiterH) + RotL64(aOrbiterB, 24U)) + aWandererUpdateSaltE[((aIndex + 22U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aCross, 37U) + aOrbiterG) + RotL64(aOrbiterI, 27U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 23U) + aOrbiterI) + RotL64(aOrbiterH, 21U));
            aWandererK = aWandererK + (((RotL64(aScatter, 43U) + RotL64(aOrbiterI, 5U)) + aOrbiterD) + aNonceWordA);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 26U) + aOrbiterK) + RotL64(aOrbiterJ, 56U)) + aWandererUpdateSaltC[((aIndex + 18U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aCross, 39U) + RotL64(aOrbiterF, 41U)) + aOrbiterH) + aNonceWordH);
            //
            aCarry = aCarry + (RotL64(aWandererB, 53U) ^ aWandererI);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 21U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 12U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 5U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 51U));
            aCarry = aCarry + RotL64(aWandererG, 23U);
            aCarry = aCarry + RotL64(aIngress, 18U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 16468U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneA[((aIndex + 21330U)) & S_BLOCK1], 53U));
            aIngress ^= (RotL64(aExpandLaneB[((aIndex + 18140U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22872U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 24046U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 21908U)) & S_BLOCK1], 52U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 20544U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aPrevious, 19U) ^ RotL64(aCarry, 35U)) + (RotL64(aCross, 5U) ^ RotL64(aIngress, 48U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterE = (aWandererE + RotL64(aScatter, 3U)) + 14249093584376402677U;
            aOrbiterJ = (aWandererH + RotL64(aCross, 58U)) + 8756965951816492264U;
            aOrbiterC = (aWandererD + RotL64(aIngress, 29U)) + 11221139480258176330U;
            aOrbiterI = ((aWandererK + RotL64(aPrevious, 19U)) + 17218894445564194851U) + aNonceWordB;
            aOrbiterK = (aWandererB + RotL64(aCross, 27U)) + 8064642692524949490U;
            aOrbiterB = (((aWandererJ + RotL64(aPrevious, 23U)) + RotL64(aCarry, 29U)) + 5822093203710704646U) + aNonceWordL;
            aOrbiterH = ((aWandererA + RotL64(aIngress, 39U)) + 3217799620158102238U) + aOrbiterAssignSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = (((aWandererC + RotL64(aScatter, 13U)) + RotL64(aCarry, 11U)) + 2613757677892120843U) + aOrbiterAssignSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = ((aWandererI + RotL64(aIngress, 53U)) + RotL64(aCarry, 23U)) + 13647481499551657237U;
            aOrbiterF = (aWandererF + RotL64(aCross, 5U)) + 3545714196663685016U;
            aOrbiterA = ((aWandererG + RotL64(aPrevious, 56U)) + 9735422670576621521U) + aNonceWordN;
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 3911046580637583767U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 9315984027042049203U;
            aOrbiterC = RotL64((aOrbiterC * 12568550776487242469U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 8926367674641729058U) + aNonceWordC;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 11035347490524961446U;
            aOrbiterK = RotL64((aOrbiterK * 10948288997163592463U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 10748158733051120339U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 2467801787989056455U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 12621934274702358977U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 9244415080474351390U) + aNonceWordD;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 8517784887959492079U;
            aOrbiterG = RotL64((aOrbiterG * 17022899813765884147U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 8409307332803038455U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 11043806021873232950U;
            aOrbiterF = RotL64((aOrbiterF * 8294888329708842989U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 17512395828450251457U) + aOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterF) ^ 16849067939795823992U) ^ aOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterJ = RotL64((aOrbiterJ * 9361991804481514337U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 17541946638063238056U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 11430501673960586718U;
            aOrbiterB = RotL64((aOrbiterB * 15074409630605450091U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 78307505705383302U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 4834528975263832983U;
            aOrbiterH = RotL64((aOrbiterH * 17245673681686752861U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 9647985402149698269U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 6610247710757518931U;
            aOrbiterI = RotL64((aOrbiterI * 8672486173272686859U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 2706696306041774372U) + aNonceWordP;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 9519896513600816252U;
            aOrbiterE = RotL64((aOrbiterE * 7468605169665549731U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 14647351223431646222U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 14249093584376402677U;
            aOrbiterA = RotL64((aOrbiterA * 8296105266618697281U), 27U);
            //
            aIngress = RotL64(aOrbiterK, 50U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 53U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 57U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 13U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 42U));
            aIngress = aIngress + RotL64(aOrbiterC, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aScatter, 35U) + aOrbiterI) + RotL64(aOrbiterB, 13U));
            aWandererF = aWandererF + (((RotL64(aIngress, 41U) + aOrbiterD) + RotL64(aOrbiterJ, 18U)) + aNonceWordF);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 54U) + RotL64(aOrbiterG, 35U)) + aOrbiterJ);
            aWandererC = aWandererC + ((((RotL64(aCross, 21U) + RotL64(aOrbiterJ, 37U)) + aOrbiterI) + RotL64(aCarry, 3U)) + aWandererUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterA, 51U)) + aOrbiterK);
            aWandererG = aWandererG + (((RotL64(aScatter, 51U) + aOrbiterJ) + RotL64(aOrbiterA, 57U)) + RotL64(aCarry, 29U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 5U) + aOrbiterE) + RotL64(aOrbiterD, 43U));
            aWandererD = aWandererD + ((RotL64(aCross, 47U) + RotL64(aOrbiterJ, 21U)) + aOrbiterH);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 37U) + aOrbiterE) + RotL64(aOrbiterC, 46U));
            aWandererH = aWandererH + (((RotL64(aIngress, 12U) + aOrbiterG) + RotL64(aOrbiterF, 53U)) + aNonceWordE);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 39U) + RotL64(aOrbiterB, 41U)) + aOrbiterK) + aWandererUpdateSaltD[((aIndex + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 53U) ^ aWandererJ);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 20U));
            aCarry = aCarry + (RotL64(aWandererG, 27U) ^ aWandererK);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 23U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 47U));
            aCarry = aCarry + RotL64(aWandererF, 13U);
            aCarry = aCarry + RotL64(aIngress, 44U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 30749U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneA[((aIndex + 31955U)) & S_BLOCK1], 13U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 27433U)) & S_BLOCK1], 22U) ^ RotL64(aWorkLaneC[((aIndex + 27829U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 32550U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 25869U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aWorkLaneD[((aIndex + 32125U)) & S_BLOCK1], 22U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCross, 57U) + RotL64(aPrevious, 20U)) ^ (RotL64(aCarry, 35U) ^ RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterG = ((aWandererC + RotL64(aIngress, 29U)) + 5088525177670191619U) + aNonceWordD;
            aOrbiterB = (aWandererK + RotL64(aCross, 39U)) + 9966456257813932112U;
            aOrbiterK = (aWandererD + RotL64(aPrevious, 41U)) + 7707646574027146307U;
            aOrbiterH = ((aWandererH + RotL64(aScatter, 11U)) + 75480203757681173U) + aOrbiterAssignSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterC = (aWandererJ + RotL64(aPrevious, 47U)) + 384659134071835163U;
            aOrbiterJ = (aWandererA + RotL64(aScatter, 18U)) + 3158769775373307778U;
            aOrbiterA = ((aWandererE + RotL64(aIngress, 5U)) + RotL64(aCarry, 41U)) + 17360830943513941272U;
            aOrbiterE = (((aWandererB + RotL64(aCross, 51U)) + RotL64(aCarry, 23U)) + 5317278822721604586U) + aOrbiterAssignSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = (aWandererF + RotL64(aIngress, 53U)) + 1371427105215954781U;
            aOrbiterD = (aWandererI + RotL64(aScatter, 57U)) + 3162710551223553423U;
            aOrbiterF = (((aWandererG + RotL64(aPrevious, 22U)) + RotL64(aCarry, 57U)) + 5332921933853550756U) + aNonceWordM;
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 10572462410297815854U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 10234389605554817892U;
            aOrbiterK = RotL64((aOrbiterK * 2130374833440291193U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 13421365517991380605U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 10186643614984034083U;
            aOrbiterJ = RotL64((aOrbiterJ * 8554471709467808453U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 4742438973260817120U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 6081590345899008846U;
            aOrbiterG = RotL64((aOrbiterG * 7069396301823124931U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 15360092808493795340U) + aNonceWordI;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 12186413069553132646U) ^ aNonceWordB;
            aOrbiterI = RotL64((aOrbiterI * 3815981440611914267U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 16756221656224451552U) + aNonceWordN;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 12232880965861373143U;
            aOrbiterC = RotL64((aOrbiterC * 14196910735715726471U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 10090954323470840557U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 15615770271463853537U;
            aOrbiterD = RotL64((aOrbiterD * 13544181592829027283U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 556029032505658411U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 13311879111583579039U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3924744868168749003U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 8646360871497847336U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 2064833941982069154U;
            aOrbiterB = RotL64((aOrbiterB * 10016546852137913163U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 1701847261278886621U) + aOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 9654208200019718374U;
            aOrbiterE = RotL64((aOrbiterE * 4398089490129603677U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 14276143262844412074U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 10738184916176200661U;
            aOrbiterH = RotL64((aOrbiterH * 8940267914440361883U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 2966052720680305600U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 5088525177670191619U;
            aOrbiterF = RotL64((aOrbiterF * 11621585388684456139U), 43U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterI, 37U);
            aIngress = aIngress + (RotL64(aOrbiterK, 13U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 19U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 6U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 39U));
            aIngress = aIngress + RotL64(aOrbiterH, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aPrevious, 3U) + aOrbiterJ) + RotL64(aOrbiterH, 50U)) + RotL64(aCarry, 43U)) + aWandererUpdateSaltB[((aIndex + 15U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aCross, 51U) + RotL64(aOrbiterE, 29U)) + aOrbiterK) + aNonceWordA);
            aWandererK = aWandererK + (((RotL64(aIngress, 21U) + aOrbiterB) + RotL64(aOrbiterJ, 37U)) + aNonceWordK);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterA, 21U)) + aOrbiterG);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 43U) + RotL64(aOrbiterC, 39U)) + aOrbiterD) + aNonceWordF) + aWandererUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 35U) + aOrbiterF) + RotL64(aOrbiterK, 27U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 60U) + RotL64(aOrbiterE, 52U)) + aOrbiterH) + RotL64(aCarry, 39U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterE, 57U)) + aOrbiterF);
            aWandererD = aWandererD + ((RotL64(aPrevious, 29U) + RotL64(aOrbiterI, 35U)) + aOrbiterG);
            aWandererI = aWandererI ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterI, 41U)) + aOrbiterE);
            aWandererA = aWandererA + ((RotL64(aScatter, 46U) + RotL64(aOrbiterE, 11U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 21U));
            aCarry = aCarry + (RotL64(aWandererC, 54U) ^ aWandererE);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 23U));
            aCarry = aCarry + (RotL64(aWandererA, 27U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererG, 13U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererH, 57U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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

void TwistExpander_PingPong_Arx::KDF_B_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x985479327A9900D7ULL + 0xFECA6B8188F457E5ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xAF1EADF2EC97EC4DULL + 0xC07B821A78A3BC4DULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x8F9748EC07DE4165ULL + 0xED6AB2363311F452ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xF3F3807E8264B335ULL + 0xBC1C6540C2D9405AULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xCCE2D8FBA65E0229ULL + 0xB1476C4779721938ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xE47204C458C0650BULL + 0xC5E2D6D0A2F7A9CEULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x8BD253B06F3EF643ULL + 0x873B57F2136EA73DULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xFB7D69C8B7EF9811ULL + 0xA7DF13FB61B0ACDBULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xDA26EBBC12A86A11ULL + 0x8C01CAD0DD697178ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xAA8D6A594270D781ULL + 0xCF831B6A66738A69ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xCA796EA5D242B867ULL + 0xC89526712239E98BULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xD470F5719E928393ULL + 0xAC1F32D6C86535A1ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xA8B84C81D48ED17DULL + 0x8237CEF6249E2DF1ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xADF48CCE13E47025ULL + 0xA430B9C71814B072ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x9067A418FDDB4DDBULL + 0x8605322E5DB88E3FULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xB909351A659C5FD3ULL + 0x8AD9BC2B1EB22F05ULL);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 7882U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneB[((aIndex + 2704U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 7017U)) & S_BLOCK1], 10U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 262U)) & S_BLOCK1], 50U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 2618U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 4204U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aPrevious, 27U) ^ RotL64(aCross, 39U)) + (RotL64(aCarry, 52U) + RotL64(aIngress, 13U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterA = (aWandererJ + RotL64(aCross, 43U)) + 10336802574069791273U;
            aOrbiterD = ((((aWandererI + RotL64(aIngress, 3U)) + RotL64(aCarry, 13U)) + 169025388197058936U) + aOrbiterAssignSaltD[((aIndex + 22U)) & S_SALT1]) + aNonceWordI;
            aOrbiterE = (((aWandererD + RotL64(aScatter, 52U)) + 6541354188379168846U) + aOrbiterAssignSaltF[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordN;
            aOrbiterC = (aWandererE + RotL64(aPrevious, 47U)) + 16223920526599306104U;
            aOrbiterJ = (aWandererH + RotL64(aIngress, 13U)) + 12756613707692514808U;
            aOrbiterF = ((aWandererG + RotL64(aScatter, 19U)) + RotL64(aCarry, 43U)) + 5082475548176484035U;
            aOrbiterI = (aWandererA + RotL64(aPrevious, 38U)) + 4907435526952698526U;
            aOrbiterK = ((aWandererF + RotL64(aCross, 29U)) + RotL64(aCarry, 21U)) + 14236627073831834337U;
            aOrbiterG = ((aWandererC + RotL64(aPrevious, 23U)) + 11502511046130497584U) + aNonceWordF;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 3679044835550219497U) + aNonceWordM;
            aOrbiterE = (((aOrbiterE ^ aOrbiterA) ^ 11254838916686736746U) ^ aOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterE = RotL64((aOrbiterE * 8631695922983532915U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 10582608424233200966U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 10449735026385340313U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 7363770199734997411U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 4628253464169957835U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 17664454668473204465U;
            aOrbiterI = RotL64((aOrbiterI * 4234720298731378527U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 3798386391743884889U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 1379331161819246587U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13086160171095077295U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 9816600392407327227U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 16781971616348376878U;
            aOrbiterG = RotL64((aOrbiterG * 12503867584828289879U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 4807797577690520554U) + aNonceWordC;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 2492057261148595922U;
            aOrbiterK = RotL64((aOrbiterK * 9453302540675483005U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 7909676419643119585U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 256053568910383007U;
            aOrbiterA = RotL64((aOrbiterA * 11965085163352053161U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 16179914439220412472U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 3968867762761955845U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7473632378251893139U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 7474832923901283742U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 4736994731050735779U;
            aOrbiterC = RotL64((aOrbiterC * 9839654409121414047U), 41U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterC, 60U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 57U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 3U));
            aIngress = aIngress + (RotL64(aOrbiterF, 19U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterD, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aPrevious, 27U) + aOrbiterE) + RotL64(aOrbiterC, 44U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 19U) + aOrbiterG) + RotL64(aOrbiterJ, 53U)) + aNonceWordG);
            aWandererJ = aWandererJ + (((RotL64(aCross, 48U) + RotL64(aOrbiterD, 13U)) + aOrbiterE) + RotL64(aCarry, 57U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 13U) + aOrbiterC) + RotL64(aOrbiterI, 5U));
            aWandererH = aWandererH + ((RotL64(aScatter, 53U) + aOrbiterJ) + RotL64(aOrbiterE, 27U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 23U) + aOrbiterK) + RotL64(aOrbiterC, 48U)) + aNonceWordK);
            aWandererI = aWandererI + (((RotL64(aCross, 44U) + RotL64(aOrbiterE, 19U)) + aOrbiterA) + aWandererUpdateSaltC[((aIndex + 15U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((((RotL64(aPrevious, 37U) + RotL64(aOrbiterD, 57U)) + aOrbiterA) + aNonceWordO) + aWandererUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aScatter, 5U) + aOrbiterF) + RotL64(aOrbiterJ, 39U)) + RotL64(aCarry, 5U)) + aNonceWordH);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 53U));
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererH, 6U) ^ aWandererA);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 47U));
            aCarry = aCarry + RotL64(aWandererC, 23U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 12351U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneC[((aIndex + 8931U)) & S_BLOCK1], 43U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 14553U)) & S_BLOCK1], 35U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 8623U)) & S_BLOCK1], 24U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 9843U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 15827U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 10518U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCross, 43U) + RotL64(aPrevious, 56U)) + (RotL64(aCarry, 21U) ^ RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterG = (aWandererK + RotL64(aCross, 53U)) + 6733949564325516029U;
            aOrbiterK = (aWandererI + RotL64(aIngress, 14U)) + 7304098437143918796U;
            aOrbiterB = (((aWandererC + RotL64(aScatter, 35U)) + RotL64(aCarry, 21U)) + 3923949518391777800U) + aNonceWordO;
            aOrbiterE = ((aWandererF + RotL64(aPrevious, 57U)) + RotL64(aCarry, 13U)) + 14243591003388927124U;
            aOrbiterC = ((aWandererH + RotL64(aCross, 19U)) + RotL64(aCarry, 47U)) + 18329498724605410406U;
            aOrbiterF = (aWandererJ + RotL64(aPrevious, 3U)) + 13118172167747037249U;
            aOrbiterA = ((aWandererG + RotL64(aScatter, 48U)) + 5272025143849174212U) + aOrbiterAssignSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = ((aWandererA + RotL64(aIngress, 41U)) + 16075917179214318424U) + aOrbiterAssignSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterI = ((aWandererB + RotL64(aScatter, 27U)) + 15263590648674658399U) + aNonceWordG;
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 13730046728289525921U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 7703141464499623408U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5886009900621521987U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 1382279753822135359U) + aNonceWordI;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 2973369221699098292U;
            aOrbiterF = RotL64((aOrbiterF * 7440242040663550631U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 11578274119583013219U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 3419411247737896674U) ^ aNonceWordF;
            aOrbiterJ = RotL64((aOrbiterJ * 17814942652262802991U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 2582783513078999303U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 3959762790273529677U;
            aOrbiterG = RotL64((aOrbiterG * 383974377372162751U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 465795011576934604U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 17880826624185821135U;
            aOrbiterK = RotL64((aOrbiterK * 4445949147592860913U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 10819659185349413173U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterJ) ^ 17298208553586835030U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterC = RotL64((aOrbiterC * 1965860510614222093U), 27U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 12585880006661489402U) + aOrbiterUpdateSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 16650193903267408586U;
            aOrbiterA = RotL64((aOrbiterA * 5781132589396936615U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 885882046325991589U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 869560078374809974U) ^ aOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 13440973563438747181U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 11871305571797951851U) + aNonceWordP;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 12137095015607196226U;
            aOrbiterI = RotL64((aOrbiterI * 7618152256560808581U), 37U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterJ, 53U);
            aIngress = aIngress + (RotL64(aOrbiterA, 47U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterK, 57U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterC, 41U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterG, 30U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aIngress, 3U) + aOrbiterB) + RotL64(aOrbiterE, 47U));
            aWandererF = aWandererF + ((((RotL64(aPrevious, 51U) + RotL64(aOrbiterI, 19U)) + aOrbiterC) + RotL64(aCarry, 23U)) + aNonceWordD);
            aWandererB = aWandererB ^ (((RotL64(aCross, 41U) + aOrbiterK) + RotL64(aOrbiterA, 24U)) + aWandererUpdateSaltA[((aIndex + 15U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 14U) + aOrbiterE) + RotL64(aOrbiterG, 35U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 19U) + aOrbiterF) + RotL64(aOrbiterJ, 13U));
            aWandererC = aWandererC + (((RotL64(aCross, 37U) + RotL64(aOrbiterA, 51U)) + aOrbiterF) + aNonceWordJ);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 27U) + aOrbiterJ) + RotL64(aOrbiterK, 29U)) + aWandererUpdateSaltE[((aIndex + 20U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aScatter, 58U) + RotL64(aOrbiterA, 60U)) + aOrbiterG) + RotL64(aCarry, 53U)) + aNonceWordH);
            aWandererA = aWandererA ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterC, 3U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 42U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 27U));
            aCarry = aCarry + (RotL64(aWandererI, 39U) ^ aWandererC);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 19U));
            aCarry = aCarry + RotL64(aWandererA, 53U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 22512U)) & S_BLOCK1], 12U) ^ RotL64(aOperationLaneA[((aIndex + 18284U)) & S_BLOCK1], 53U));
            aIngress ^= (RotL64(aOperationLaneB[((aIndex + 18443U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((aIndex + 22654U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 23085U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 24238U)) & S_BLOCK1], 58U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 17712U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aIngress, 40U) + RotL64(aCarry, 53U)) ^ (RotL64(aPrevious, 23U) + RotL64(aCross, 11U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterF = (aWandererA + RotL64(aIngress, 3U)) + 16160838483846078448U;
            aOrbiterI = (((aWandererG + RotL64(aScatter, 21U)) + RotL64(aCarry, 3U)) + 15404960896190227946U) + aNonceWordO;
            aOrbiterB = (((aWandererK + RotL64(aPrevious, 48U)) + 16904160594024977199U) + aOrbiterAssignSaltA[((aIndex + 5U)) & S_SALT1]) + aNonceWordH;
            aOrbiterG = ((aWandererI + RotL64(aCross, 53U)) + RotL64(aCarry, 35U)) + 17790460246821031802U;
            aOrbiterC = ((aWandererD + RotL64(aIngress, 35U)) + RotL64(aCarry, 13U)) + 16395168254086971959U;
            aOrbiterD = (aWandererB + RotL64(aPrevious, 57U)) + 7484373204039901786U;
            aOrbiterJ = ((aWandererE + RotL64(aScatter, 27U)) + 18026814691322913510U) + aNonceWordL;
            aOrbiterA = ((aWandererH + RotL64(aCross, 42U)) + 15244817793136966450U) + aOrbiterAssignSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = (aWandererJ + RotL64(aScatter, 11U)) + 5795491730356335666U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 3163873518027801504U) + aNonceWordE;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 2690791759507349172U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 16677948635136515083U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 17898067251167087906U) + aOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 8028010015006604239U;
            aOrbiterC = RotL64((aOrbiterC * 5601629670521300241U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 7304739457289910555U) + aNonceWordF;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 6476837815096530043U) ^ aOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 16380545138701113267U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 14242499233467960602U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 17305645693017634630U;
            aOrbiterA = RotL64((aOrbiterA * 14442976693206929569U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 9772864059444171908U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 7897200728282156408U;
            aOrbiterF = RotL64((aOrbiterF * 816306719390807411U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 4890999319172950996U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 8165132649356094963U;
            aOrbiterI = RotL64((aOrbiterI * 17297706071263690189U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 9342923520083533265U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 7213639583505088067U;
            aOrbiterD = RotL64((aOrbiterD * 1349251979649428909U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 4079475132684197272U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 3350998022472827283U) ^ aNonceWordP;
            aOrbiterH = RotL64((aOrbiterH * 948841791460066265U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 2479140576609216238U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 7703147534931674972U;
            aOrbiterG = RotL64((aOrbiterG * 11419116495223970801U), 5U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterA, 21U);
            aIngress = aIngress + (RotL64(aOrbiterI, 53U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterG, 18U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 13U));
            aIngress = aIngress + RotL64(aOrbiterD, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 56U) + aOrbiterI) + RotL64(aOrbiterD, 19U));
            aWandererA = aWandererA + (((((RotL64(aCross, 27U) + RotL64(aOrbiterJ, 27U)) + aOrbiterF) + RotL64(aCarry, 21U)) + aNonceWordK) + aWandererUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 3U) + aOrbiterH) + RotL64(aOrbiterC, 35U)) + aNonceWordD);
            aWandererE = aWandererE + (((RotL64(aScatter, 47U) + aOrbiterD) + RotL64(aOrbiterJ, 58U)) + RotL64(aCarry, 11U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 23U) + RotL64(aOrbiterB, 13U)) + aOrbiterF) + aWandererUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 19U) + RotL64(aOrbiterD, 43U)) + aOrbiterA) + aNonceWordI);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 35U) + aOrbiterA) + RotL64(aOrbiterH, 5U));
            aWandererK = aWandererK + ((RotL64(aScatter, 14U) + aOrbiterJ) + RotL64(aOrbiterB, 39U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterG, 48U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererI, 43U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererH, 13U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererB, 3U) ^ aWandererE);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 47U));
            aCarry = aCarry + RotL64(aWandererD, 20U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 32446U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneA[((aIndex + 30212U)) & S_BLOCK1], 29U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 27597U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 32133U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 26196U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 27396U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 25586U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aPrevious, 27U) ^ RotL64(aCross, 13U)) + (RotL64(aIngress, 56U) + RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterG = ((aWandererG + RotL64(aIngress, 5U)) + 964165145848253292U) + aOrbiterAssignSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterE = ((((aWandererK + RotL64(aScatter, 43U)) + RotL64(aCarry, 19U)) + 10645976767204934746U) + aOrbiterAssignSaltD[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordM;
            aOrbiterD = ((aWandererI + RotL64(aPrevious, 29U)) + RotL64(aCarry, 29U)) + 8241612229349212650U;
            aOrbiterA = (aWandererC + RotL64(aCross, 11U)) + 4159196033256913347U;
            aOrbiterI = (aWandererA + RotL64(aIngress, 24U)) + 7194795864620233507U;
            aOrbiterB = (aWandererH + RotL64(aScatter, 47U)) + 7638928444536778384U;
            aOrbiterF = (aWandererF + RotL64(aCross, 57U)) + 11819105916503968109U;
            aOrbiterK = ((aWandererB + RotL64(aPrevious, 51U)) + 18052213302858186237U) + aNonceWordP;
            aOrbiterH = ((aWandererD + RotL64(aCross, 18U)) + RotL64(aCarry, 43U)) + 8663575313970041570U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 16644136720439299786U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 16930316530442679864U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2650922074098320859U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 16251107616988250593U) + aOrbiterUpdateSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 7171986193609401665U;
            aOrbiterG = RotL64((aOrbiterG * 3543709971414550087U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 17885046834432626644U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 7757069274715713557U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15766885299397923879U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 2212805322061155615U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 6368539134638838822U;
            aOrbiterA = RotL64((aOrbiterA * 13383744883433594259U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 5264326094252925613U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 6126345334815012938U;
            aOrbiterK = RotL64((aOrbiterK * 17180934809764905307U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 13826731214018407061U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 6621261811613643620U) ^ aNonceWordJ;
            aOrbiterH = RotL64((aOrbiterH * 2823596473596114171U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 5964406317285863781U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 2167324450276308078U;
            aOrbiterF = RotL64((aOrbiterF * 1098346374733634905U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 16740710162977859724U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 8236083581048717923U;
            aOrbiterB = RotL64((aOrbiterB * 4364887787000704039U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 13967473987446124012U) + aOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 5136051802217149813U) ^ aNonceWordN;
            aOrbiterI = RotL64((aOrbiterI * 13997246005108872883U), 5U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterF, 37U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 60U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 5U));
            aIngress = aIngress + (RotL64(aOrbiterI, 11U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterD, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aCross, 19U) + aOrbiterF) + RotL64(aOrbiterE, 19U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 13U) + aOrbiterB) + RotL64(aOrbiterH, 11U)) + aNonceWordK);
            aWandererC = aWandererC + (((RotL64(aIngress, 35U) + RotL64(aOrbiterG, 23U)) + aOrbiterB) + RotL64(aCarry, 51U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterA, 43U)) + aOrbiterF) + aWandererUpdateSaltF[((aIndex + 22U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aCross, 6U) + RotL64(aOrbiterA, 38U)) + aOrbiterD) + RotL64(aCarry, 35U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 53U) + aOrbiterG) + RotL64(aOrbiterI, 51U));
            aWandererG = aWandererG + ((RotL64(aPrevious, 57U) + aOrbiterF) + RotL64(aOrbiterI, 29U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 23U) + aOrbiterF) + RotL64(aOrbiterK, 3U)) + aWandererUpdateSaltC[((aIndex + 14U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 48U) + aOrbiterD) + RotL64(aOrbiterE, 60U)) + aNonceWordA);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 5U));
            aCarry = aCarry + (RotL64(aWandererA, 11U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererK, 43U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererH, 39U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererB, 60U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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

void TwistExpander_PingPong_Arx::KDF_B_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xD42FAC5F621D0F8BULL + 0xCD7B56630F1A179FULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xE404845D65D35773ULL + 0x963A3093A337061FULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xE2D2359474AA6AABULL + 0xEAEE09844F8C4CC4ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xD6CB34F5B9AFE491ULL + 0xD33DD2E3D73E0354ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xB445361A956FFAA3ULL + 0xD6CCEF25E68EFF69ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xD7905A5F9AB00F65ULL + 0xB4F6A686B864FEDBULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x843497EFA2319AA1ULL + 0xB3755655774F6984ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xE13C9E1C53E5403BULL + 0xE8DC92F848E259BEULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xAAF8B9357B0D3B0DULL + 0xFE0B951B1B01EFEEULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0x98FFE77C9DFA3EB9ULL + 0x9311AF5E180B7E11ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xD15C651DFACB2795ULL + 0x9A786CC386C40B50ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xEB0097329D6F5285ULL + 0xA270596B52070FCAULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x9458E9C8A8146C33ULL + 0xA02273EC47AC83D5ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xE7DA97EA4EF23039ULL + 0xFA740F71CB71F56AULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x91460B864DBC638DULL + 0xEBD99980E26D1344ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xB2D8BEE324FFC12BULL + 0xD174CD7B502DF2EEULL);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 2954U)) & S_BLOCK1], 20U) ^ RotL64(aWorkLaneB[((aIndex + 4369U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 860U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 5929U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 4829U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 806U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aIngress, 57U) ^ RotL64(aCarry, 28U)) + (RotL64(aPrevious, 5U) + RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterK = ((((aWandererG + RotL64(aIngress, 51U)) + RotL64(aCarry, 35U)) + 3255291173184001106U) + aOrbiterAssignSaltE[((aIndex + 7U)) & S_SALT1]) + aNonceWordO;
            aOrbiterA = ((aWandererF + RotL64(aCross, 44U)) + RotL64(aCarry, 21U)) + 15308468160116255528U;
            aOrbiterE = (aWandererD + RotL64(aPrevious, 3U)) + 18186972408589866656U;
            aOrbiterC = (aWandererH + RotL64(aScatter, 27U)) + 4439324265978331914U;
            aOrbiterF = (aWandererI + RotL64(aIngress, 11U)) + 13099263173016322486U;
            aOrbiterI = (aWandererC + RotL64(aPrevious, 57U)) + 7041561081767500660U;
            aOrbiterJ = ((((aWandererE + RotL64(aScatter, 35U)) + RotL64(aCarry, 51U)) + 6196422612687812971U) + aOrbiterAssignSaltA[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordF;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 7664260932541281413U) + aNonceWordI;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 17802347823020441056U) ^ aOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 2220679459017369255U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 4253107484061190446U) + aOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 13799496534030645312U;
            aOrbiterF = RotL64((aOrbiterF * 9167675060053848207U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 14252892847595951926U) + aNonceWordD;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 5663527578664291422U;
            aOrbiterI = RotL64((aOrbiterI * 18314294235895182465U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 11148755959699137661U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterF) ^ 17036900929333594592U) ^ aOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterA = RotL64((aOrbiterA * 16041243617369003291U), 37U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 2403828181385259549U) + aOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 17813580350434928194U;
            aOrbiterK = RotL64((aOrbiterK * 13666780980793857831U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 5623611126885414523U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 7293224381174846969U;
            aOrbiterC = RotL64((aOrbiterC * 7032561584670788117U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 10602620906929686163U) + aNonceWordP;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 18015916257203385982U;
            aOrbiterJ = RotL64((aOrbiterJ * 10684090189688871993U), 43U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterK, 54U);
            aIngress = aIngress + (RotL64(aOrbiterF, 11U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterE, 35U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterA, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aScatter, 41U) + RotL64(aOrbiterI, 57U)) + aOrbiterJ);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 3U) + aOrbiterJ) + RotL64(aOrbiterK, 13U)) + aWandererUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 57U) + RotL64(aOrbiterA, 37U)) + aOrbiterC) + aNonceWordA);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 28U) + aOrbiterE) + RotL64(aOrbiterI, 51U)) + aNonceWordE);
            aWandererE = aWandererE + (((RotL64(aScatter, 51U) + RotL64(aOrbiterK, 4U)) + aOrbiterF) + RotL64(aCarry, 21U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterF, 27U)) + aOrbiterI);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 35U) + RotL64(aOrbiterK, 19U)) + aOrbiterC) + RotL64(aCarry, 53U)) + aWandererUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 34U) ^ aWandererD);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 11U));
            aCarry = aCarry + (RotL64(aWandererG, 43U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererI, 57U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 12268U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneC[((aIndex + 15350U)) & S_BLOCK1], 38U));
            aIngress ^= (RotL64(aWorkLaneD[((aIndex + 10717U)) & S_BLOCK1], 19U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 15748U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 11067U)) & S_BLOCK1], 50U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 9118U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 12819U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 21U)) + (RotL64(aIngress, 48U) + RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterA = ((aWandererA + RotL64(aCross, 12U)) + 3236820517816085022U) + aNonceWordC;
            aOrbiterB = ((aWandererD + RotL64(aPrevious, 53U)) + RotL64(aCarry, 13U)) + 741288875914097926U;
            aOrbiterJ = (((aWandererJ + RotL64(aIngress, 35U)) + RotL64(aCarry, 29U)) + 8417246926007729580U) + aNonceWordM;
            aOrbiterC = ((((aWandererH + RotL64(aScatter, 41U)) + RotL64(aCarry, 47U)) + 9715717805774537170U) + aOrbiterAssignSaltC[((aIndex + 5U)) & S_SALT1]) + aNonceWordG;
            aOrbiterE = ((aWandererG + RotL64(aPrevious, 21U)) + 14360243844821619482U) + aOrbiterAssignSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterD = (aWandererE + RotL64(aScatter, 5U)) + 10760908100206775334U;
            aOrbiterF = (aWandererB + RotL64(aCross, 29U)) + 3434641779946167811U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 7885568822756234567U) + aOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 3041563437672051294U;
            aOrbiterJ = RotL64((aOrbiterJ * 11440300917533482297U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 15761355327564963516U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 1158633562785937421U) ^ aOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 15511324886867188235U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 9338581575871970653U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 9172038894262857354U;
            aOrbiterA = RotL64((aOrbiterA * 3110871165285625807U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 14653924713599790081U) + aNonceWordB;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 3854497592598563309U) ^ aNonceWordI;
            aOrbiterE = RotL64((aOrbiterE * 11737111068815795303U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 16286980180327600557U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 5092583772591249756U;
            aOrbiterC = RotL64((aOrbiterC * 13955105624639442903U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 4288397994175567333U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 15584236478994873104U) ^ aOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 1860480595862755379U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 5557463939827483792U) + aNonceWordE;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 2659814275753280856U;
            aOrbiterD = RotL64((aOrbiterD * 17702430405693184643U), 27U);
            //
            aIngress = RotL64(aOrbiterJ, 60U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterA, 19U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 37U));
            aIngress = aIngress + RotL64(aOrbiterF, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((((RotL64(aCross, 19U) + aOrbiterE) + RotL64(aOrbiterC, 29U)) + aNonceWordJ) + aWandererUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 35U) + aOrbiterD) + RotL64(aOrbiterB, 22U)) + RotL64(aCarry, 29U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 27U) + aOrbiterA) + RotL64(aOrbiterE, 47U)) + aNonceWordF);
            aWandererD = aWandererD + (((RotL64(aPrevious, 13U) + aOrbiterF) + RotL64(aOrbiterB, 11U)) + aWandererUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aCross, 5U) + RotL64(aOrbiterF, 39U)) + aOrbiterC) + aNonceWordP);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 58U) + aOrbiterJ) + RotL64(aOrbiterF, 57U)) + RotL64(aCarry, 51U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 47U) + aOrbiterC) + RotL64(aOrbiterB, 5U)) + aNonceWordK);
            //
            aCarry = aCarry + (RotL64(aWandererH, 23U) ^ aWandererJ);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 40U));
            aCarry = aCarry + (RotL64(aWandererE, 57U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererA, 47U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 17748U)) & S_BLOCK1], 42U) ^ RotL64(aWorkLaneA[((aIndex + 22857U)) & S_BLOCK1], 29U));
            aIngress ^= (RotL64(aWorkLaneB[((aIndex + 20787U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 22825U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 18044U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 16444U)) & S_BLOCK1], 53U));
            aCross ^= RotL64(aOperationLaneB[((aIndex + 20832U)) & S_BLOCK1], 18U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCarry, 19U) + RotL64(aPrevious, 53U)) + (RotL64(aCross, 6U) ^ RotL64(aIngress, 37U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterG = ((aWandererC + RotL64(aScatter, 21U)) + 2915859148137000694U) + aNonceWordL;
            aOrbiterE = ((aWandererI + RotL64(aPrevious, 29U)) + 210680583721444425U) + aOrbiterAssignSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterB = ((((aWandererG + RotL64(aIngress, 46U)) + RotL64(aCarry, 57U)) + 6668118118775650387U) + aOrbiterAssignSaltF[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordP;
            aOrbiterD = ((aWandererA + RotL64(aCross, 37U)) + 15794200818099010989U) + aNonceWordC;
            aOrbiterJ = ((aWandererH + RotL64(aScatter, 57U)) + RotL64(aCarry, 5U)) + 6565076707062828369U;
            aOrbiterA = ((aWandererK + RotL64(aCross, 3U)) + RotL64(aCarry, 43U)) + 16323164497808856719U;
            aOrbiterF = ((aWandererJ + RotL64(aIngress, 13U)) + 7965435318816716560U) + aNonceWordF;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 7390281030573369017U) + aOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 2269738866911824875U;
            aOrbiterB = RotL64((aOrbiterB * 1198697877998135567U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 9664014216039993873U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 18284857398028357633U) ^ aOrbiterUpdateSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8402008251343393737U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 367667619795303009U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 7935945060956274197U) ^ aNonceWordM;
            aOrbiterJ = RotL64((aOrbiterJ * 5481786693511955209U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 16683666162337789540U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 10655658270998102390U;
            aOrbiterF = RotL64((aOrbiterF * 15231596813382239841U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 8307037916581540297U) + aNonceWordA;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 3247742749860703524U) ^ aNonceWordD;
            aOrbiterA = RotL64((aOrbiterA * 15052136713218656641U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 10446792483683818139U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 16374602929344972364U;
            aOrbiterG = RotL64((aOrbiterG * 12599903932725787599U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 2411334498322777183U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 1093701164116833765U;
            aOrbiterE = RotL64((aOrbiterE * 13129220206835381729U), 19U);
            //
            aIngress = RotL64(aOrbiterB, 37U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 29U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 47U));
            aIngress = aIngress + RotL64(aOrbiterE, 60U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterB, 11U)) + aOrbiterG);
            aWandererA = aWandererA + ((((RotL64(aIngress, 29U) + aOrbiterA) + RotL64(aOrbiterD, 57U)) + RotL64(aCarry, 21U)) + aNonceWordE);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 43U) + RotL64(aOrbiterJ, 41U)) + aOrbiterF) + aWandererUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aScatter, 20U) + aOrbiterE) + RotL64(aOrbiterG, 29U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 5U) + aOrbiterJ) + RotL64(aOrbiterB, 50U)) + aNonceWordO);
            aWandererG = aWandererG + ((((RotL64(aScatter, 35U) + RotL64(aOrbiterA, 5U)) + aOrbiterB) + RotL64(aCarry, 37U)) + aWandererUpdateSaltA[((aIndex + 14U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 53U) + aOrbiterE) + RotL64(aOrbiterF, 21U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 11U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 27U));
            aCarry = aCarry + (RotL64(aWandererC, 35U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererH, 40U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 32017U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneA[((aIndex + 30951U)) & S_BLOCK1], 35U));
            aIngress ^= (RotL64(aWorkLaneD[((aIndex + 26378U)) & S_BLOCK1], 54U) ^ RotL64(aOperationLaneC[((aIndex + 30027U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 24675U)) & S_BLOCK1], 12U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 29096U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 25232U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCarry, 3U) ^ RotL64(aIngress, 26U)) + (RotL64(aPrevious, 41U) ^ RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterF = ((((aWandererE + RotL64(aIngress, 47U)) + RotL64(aCarry, 39U)) + 15813325389431304548U) + aOrbiterAssignSaltA[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordB;
            aOrbiterH = ((aWandererC + RotL64(aCross, 5U)) + RotL64(aCarry, 21U)) + 2223874171125403602U;
            aOrbiterD = ((aWandererI + RotL64(aPrevious, 27U)) + 5510483568496824130U) + aOrbiterAssignSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterK = (((aWandererA + RotL64(aScatter, 13U)) + RotL64(aCarry, 53U)) + 15474152493495661876U) + aNonceWordM;
            aOrbiterE = ((aWandererF + RotL64(aCross, 60U)) + 16846339705130829195U) + aNonceWordI;
            aOrbiterI = ((aWandererD + RotL64(aScatter, 21U)) + 1289670576865739669U) + aNonceWordG;
            aOrbiterG = (aWandererB + RotL64(aIngress, 41U)) + 18017354919647006944U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 8539685539928984921U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 3333721400836704048U;
            aOrbiterD = RotL64((aOrbiterD * 3745286323481400085U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 2261560416623815491U) + aNonceWordH;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 4377786131746816567U;
            aOrbiterF = RotL64((aOrbiterF * 9164777834392621157U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 18047393176583722719U) + aOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 8184724021940434631U) ^ aNonceWordA;
            aOrbiterE = RotL64((aOrbiterE * 9800116157750921119U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 10469895939183324807U) + aNonceWordK;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 14543391765109879223U) ^ aOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4817987697437667225U), 13U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterG) + 5757225781746158178U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordN;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 3539000495894022869U) ^ aOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 1032298408884695925U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 11288971092707065923U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 2761384065186568294U;
            aOrbiterK = RotL64((aOrbiterK * 3323838837427471051U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 7120580145300417101U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 6977246291769372866U;
            aOrbiterG = RotL64((aOrbiterG * 15170353875184253779U), 37U);
            //
            aIngress = RotL64(aOrbiterD, 44U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterI, 19U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterE, 57U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterG, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 5U) + aOrbiterE) + RotL64(aOrbiterG, 35U)) + aNonceWordO);
            aWandererI = aWandererI + (((RotL64(aCross, 39U) + aOrbiterD) + RotL64(aOrbiterI, 29U)) + RotL64(aCarry, 11U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 23U) + aOrbiterG) + RotL64(aOrbiterK, 57U)) + aNonceWordF);
            aWandererC = aWandererC + ((RotL64(aIngress, 11U) + aOrbiterH) + RotL64(aOrbiterG, 21U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterK, 41U)) + aOrbiterE) + aWandererUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 46U) + aOrbiterF) + RotL64(aOrbiterD, 47U)) + RotL64(aCarry, 53U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterH, 10U)) + aOrbiterF) + aWandererUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 43U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererF, 23U) ^ aWandererA);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 3U));
            aCarry = aCarry + RotL64(aWandererE, 58U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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

void TwistExpander_PingPong_Arx::Seed_A(TwistWorkSpace *pWorkSpace,
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
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltD;
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
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltD;
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
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltF;
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
    [[maybe_unused]] std::uint64_t *aPhaseHWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltC;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x8B6814F57B03A139ULL + 0xC9488338B5A4B1AAULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xD0EF6D5FCE5D6BB7ULL + 0xFC90C47F114437BBULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x8D94ED4629A131EDULL + 0x872DFA9D4EEF64FCULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xC8BECB80B0B74D1FULL + 0xD29617E56679F420ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xA81C6207348129C9ULL + 0xB62ACD2256BE3E1EULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xEF4E9ED0965FB893ULL + 0xAAA990441DD1C180ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xD72F50B0B159280DULL + 0x858F8CC28D107F41ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xF73DA6EA879EBB2FULL + 0xC2BA68172248F95BULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0x8E78CE76C2497461ULL + 0xF74D82905F796BAAULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x887B1A490D3C942BULL + 0xAE9B7D132DE99B16ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0x8D392D600E557F31ULL + 0xC2D83648F68B5A29ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xF17F99366C0B6075ULL + 0xB8F12087C42172E3ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xCB2B1AF51DE32081ULL + 0xCC058176093F7FD3ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xC4D3B69EA6771309ULL + 0xE4F35F3FB141FE2EULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xA75C50B633B69269ULL + 0x92F26FDC3CE89A70ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xB66A396725658885ULL + 0xFBE11743BDAD9C93ULL);
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
            aIngress = RotL64(aKeyRowReadA[((aIndex + 902U)) & W_KEY1], 28U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 1684U)) & W_KEY1], 53U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 651U)) & W_KEY1], 5U) ^ RotL64(mSource[((aIndex + 1520U)) & S_BLOCK1], 26U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aPrevious, 18U) ^ RotL64(aCarry, 53U)) + (RotL64(aCross, 3U) + RotL64(aIngress, 37U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterA = (((aWandererG + RotL64(aIngress, 19U)) + RotL64(aCarry, 27U)) + 15813325389431304548U) + aPhaseEOrbiterAssignSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = (((aWandererA + RotL64(aPrevious, 42U)) + RotL64(aCarry, 3U)) + 2223874171125403602U) + aNonceWordL;
            aOrbiterI = (((aWandererB + RotL64(aCross, 51U)) + RotL64(aCarry, 51U)) + 5510483568496824130U) + aPhaseEOrbiterAssignSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterK = (aWandererJ + RotL64(aScatter, 57U)) + 15474152493495661876U;
            aOrbiterD = (aWandererC + RotL64(aPrevious, 13U)) + 16846339705130829195U;
            aOrbiterB = ((aWandererI + RotL64(aCross, 3U)) + 1289670576865739669U) + aNonceWordH;
            aOrbiterF = ((aWandererK + RotL64(aIngress, 27U)) + 18017354919647006944U) + aNonceWordB;
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 8539685539928984921U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 3333721400836704048U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 3745286323481400085U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 2261560416623815491U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 4377786131746816567U;
            aOrbiterA = RotL64((aOrbiterA * 9164777834392621157U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 18047393176583722719U) + aNonceWordN;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 8184724021940434631U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 9800116157750921119U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 10469895939183324807U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 14543391765109879223U;
            aOrbiterD = RotL64((aOrbiterD * 4817987697437667225U), 3U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterI) + 5757225781746158178U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1]) + aNonceWordP;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 3539000495894022869U;
            aOrbiterK = RotL64((aOrbiterK * 1032298408884695925U), 13U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterF) + 11288971092707065923U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordA;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 2761384065186568294U;
            aOrbiterH = RotL64((aOrbiterH * 3323838837427471051U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 7120580145300417101U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 6977246291769372866U;
            aOrbiterB = RotL64((aOrbiterB * 15170353875184253779U), 41U);
            //
            aIngress = RotL64(aOrbiterF, 21U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 11U));
            aIngress = aIngress + (RotL64(aOrbiterB, 27U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterA, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterI, 57U)) + aOrbiterB);
            aWandererG = aWandererG + ((((RotL64(aCross, 27U) + aOrbiterI) + RotL64(aOrbiterD, 28U)) + RotL64(aCarry, 5U)) + aNonceWordE);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterB, 11U)) + aOrbiterA) + aNonceWordO);
            aWandererI = aWandererI + ((((RotL64(aScatter, 19U) + RotL64(aOrbiterD, 19U)) + aOrbiterA) + RotL64(aCarry, 37U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 13U) + aOrbiterK) + RotL64(aOrbiterH, 3U)) + aNonceWordM);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 35U) + aOrbiterF) + RotL64(aOrbiterK, 39U)) + aNonceWordJ);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 50U) + RotL64(aOrbiterB, 47U)) + aOrbiterF) + aPhaseEWandererUpdateSaltA[((aIndex + 24U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 3U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererB, 58U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererJ, 27U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererI, 11U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 4209U)) & S_BLOCK1], 3U) ^ RotL64(aKeyRowReadA[((aIndex + 3355U)) & W_KEY1], 23U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 5033U)) & W_KEY1], 11U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 3863U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aIngress, 51U) + RotL64(aCarry, 37U)) ^ (RotL64(aCross, 19U) + RotL64(aPrevious, 6U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterC = ((aWandererF + RotL64(aCross, 20U)) + 3621877681473089725U) + aNonceWordP;
            aOrbiterF = ((aWandererD + RotL64(aPrevious, 35U)) + RotL64(aCarry, 57U)) + 4451752751536414717U;
            aOrbiterA = ((aWandererG + RotL64(aIngress, 41U)) + 11371625415377772117U) + aNonceWordJ;
            aOrbiterH = ((((aWandererA + RotL64(aScatter, 27U)) + RotL64(aCarry, 41U)) + 6046792758881150619U) + aPhaseEOrbiterAssignSaltD[((aIndex + 6U)) & S_SALT1]) + aNonceWordO;
            aOrbiterD = (aWandererJ + RotL64(aIngress, 47U)) + 8213166120394461682U;
            aOrbiterK = ((aWandererH + RotL64(aCross, 11U)) + RotL64(aCarry, 23U)) + 4343156661140422645U;
            aOrbiterE = ((aWandererI + RotL64(aScatter, 3U)) + 11105271483234947905U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 348904609985341372U) + aNonceWordA;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 12924652822526858767U;
            aOrbiterA = RotL64((aOrbiterA * 2801892489296408735U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 7461211697358520287U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 16551553555297890558U;
            aOrbiterD = RotL64((aOrbiterD * 16432952324635746293U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 11908056404140782995U) + aNonceWordE;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 9147367258259948715U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 10777628928376261667U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 8876461054692728610U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 10546855952702525404U;
            aOrbiterF = RotL64((aOrbiterF * 10071104785895309677U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 4748636139110443794U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 783046909529525098U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8969157702460927215U), 37U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 16683965945838696665U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 12385412690177109575U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 10795062772707143187U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 8210546822184469023U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 13146493623236979963U;
            aOrbiterE = RotL64((aOrbiterE * 13199947810161148155U), 53U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterE, 5U);
            aIngress = aIngress + (RotL64(aOrbiterA, 48U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 29U));
            aIngress = aIngress + RotL64(aOrbiterC, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterE, 5U)) + aOrbiterD);
            aWandererD = aWandererD + ((((RotL64(aScatter, 35U) + RotL64(aOrbiterH, 53U)) + aOrbiterF) + RotL64(aCarry, 37U)) + aNonceWordK);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 57U) + RotL64(aOrbiterK, 37U)) + aOrbiterH) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 41U) + RotL64(aOrbiterC, 13U)) + aOrbiterD) + RotL64(aCarry, 13U)) + aNonceWordD);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 19U) + RotL64(aOrbiterD, 29U)) + aOrbiterA) + aPhaseEWandererUpdateSaltE[((aIndex + 12U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aIngress, 28U) + RotL64(aOrbiterA, 23U)) + aOrbiterC);
            aWandererH = aWandererH ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterE, 44U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererG, 3U) ^ aWandererF);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 29U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 52U));
            aCarry = aCarry + RotL64(aWandererD, 57U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = RotL64(aFireLaneB[((aIndex + 6320U)) & S_BLOCK1], 43U) ^ RotL64(aKeyRowReadB[((aIndex + 7059U)) & W_KEY1], 27U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 7483U)) & W_KEY1], 5U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 7132U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 6475U)) & S_BLOCK1], 50U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aIngress, 53U) ^ RotL64(aCarry, 5U)) + (RotL64(aPrevious, 19U) ^ RotL64(aCross, 40U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterF = (((aWandererH + RotL64(aPrevious, 41U)) + RotL64(aCarry, 27U)) + 16462052553719977502U) + aPhaseEOrbiterAssignSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = (aWandererK + RotL64(aIngress, 29U)) + 12337064059566619581U;
            aOrbiterJ = ((aWandererD + RotL64(aScatter, 47U)) + 15801005007094515447U) + aNonceWordN;
            aOrbiterA = ((aWandererA + RotL64(aCross, 13U)) + RotL64(aCarry, 41U)) + 8228706742665081656U;
            aOrbiterK = (((aWandererC + RotL64(aPrevious, 19U)) + 11006723027845190869U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordA;
            aOrbiterH = (((aWandererE + RotL64(aScatter, 53U)) + RotL64(aCarry, 5U)) + 18173765337829177450U) + aNonceWordF;
            aOrbiterD = ((aWandererF + RotL64(aIngress, 6U)) + 530215083653542558U) + aNonceWordC;
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 6608611827035564511U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 2246051826221626809U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 6333352641495253539U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 5228575308895381421U) + aNonceWordG;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 10999213210689606857U;
            aOrbiterA = RotL64((aOrbiterA * 5467601259546342925U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 3773371037240485696U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 8887985779436152504U;
            aOrbiterI = RotL64((aOrbiterI * 698713082830739677U), 53U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 11150566414723818350U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 8336366151003049546U;
            aOrbiterK = RotL64((aOrbiterK * 9033771197242493699U), 3U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterH) + 13233968794237090787U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordK;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 8172558473508478819U;
            aOrbiterD = RotL64((aOrbiterD * 17837070423649268435U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 133564480283347997U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 15104810248883567064U;
            aOrbiterH = RotL64((aOrbiterH * 706802420642303533U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 9138629520201127075U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterD) ^ 13993086066341664080U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterF = RotL64((aOrbiterF * 4875046427147105077U), 37U);
            //
            aIngress = RotL64(aOrbiterH, 19U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterI, 60U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 41U));
            aIngress = aIngress + RotL64(aOrbiterK, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterH, 27U)) + aOrbiterI);
            aWandererF = aWandererF + ((((RotL64(aIngress, 57U) + RotL64(aOrbiterF, 42U)) + aOrbiterJ) + RotL64(aCarry, 37U)) + aNonceWordJ);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterF, 13U)) + aOrbiterD);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 35U) + aOrbiterI) + RotL64(aOrbiterA, 57U)) + RotL64(aCarry, 3U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterH, 19U)) + aOrbiterK);
            aWandererE = aWandererE + ((RotL64(aCross, 47U) + RotL64(aOrbiterI, 35U)) + aOrbiterF);
            aWandererD = aWandererD ^ ((((RotL64(aIngress, 10U) + RotL64(aOrbiterA, 5U)) + aOrbiterH) + aNonceWordB) + aPhaseEWandererUpdateSaltF[((aIndex + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 60U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 47U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 51U));
            aCarry = aCarry + RotL64(aWandererF, 23U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 9372U)) & S_BLOCK1], 51U) ^ RotL64(aKeyRowReadB[((aIndex + 9087U)) & W_KEY1], 14U));
            aIngress ^= (RotL64(mSource[((aIndex + 8881U)) & S_BLOCK1], 5U) ^ RotL64(aFireLaneA[((aIndex + 8444U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 8926U)) & W_KEY1], 3U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 8609U)) & S_BLOCK1], 56U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCarry, 41U) ^ RotL64(aIngress, 57U)) + (RotL64(aPrevious, 11U) ^ RotL64(aCross, 26U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterH = ((aWandererA + RotL64(aCross, 51U)) + RotL64(aCarry, 39U)) + 4384716820085860551U;
            aOrbiterA = (((aWandererE + RotL64(aPrevious, 21U)) + 9715780315942116888U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordA;
            aOrbiterB = ((aWandererG + RotL64(aIngress, 43U)) + 15963520052789178632U) + aPhaseFOrbiterAssignSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterF = ((aWandererB + RotL64(aScatter, 3U)) + RotL64(aCarry, 5U)) + 14346700690686392938U;
            aOrbiterG = ((aWandererK + RotL64(aPrevious, 10U)) + 6005518012489966643U) + aNonceWordF;
            aOrbiterD = (((aWandererD + RotL64(aIngress, 37U)) + RotL64(aCarry, 21U)) + 2506732930310252119U) + aNonceWordP;
            aOrbiterC = ((aWandererJ + RotL64(aCross, 29U)) + 16782163084851775826U) + aNonceWordE;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 823673076571076303U) + aNonceWordK;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 1634084509064077736U;
            aOrbiterB = RotL64((aOrbiterB * 1128407326773234517U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 1288134975466877686U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 2998220403162908444U) ^ aNonceWordL;
            aOrbiterH = RotL64((aOrbiterH * 4321412662318298283U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 220430672180734911U) + aNonceWordD;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 10223923547068528867U;
            aOrbiterA = RotL64((aOrbiterA * 12577370238343872139U), 3U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterD) + 11696469696177647608U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 6545430420379636963U;
            aOrbiterC = RotL64((aOrbiterC * 8387163146257553773U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 79691451831797107U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 8971444023498649419U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7148919880477390009U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 5624403902454498793U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 9468064161002030997U;
            aOrbiterF = RotL64((aOrbiterF * 8243560528100864595U), 39U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 4619361544913629805U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 12682446273369750704U;
            aOrbiterD = RotL64((aOrbiterD * 10879074713156075641U), 29U);
            //
            aIngress = RotL64(aOrbiterG, 43U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 58U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 5U));
            aIngress = aIngress + RotL64(aOrbiterH, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 12U) + RotL64(aOrbiterA, 35U)) + aOrbiterD);
            aWandererE = aWandererE + (((RotL64(aCross, 51U) + aOrbiterB) + RotL64(aOrbiterH, 10U)) + aNonceWordH);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 23U) + aOrbiterH) + RotL64(aOrbiterA, 41U)) + aPhaseFWandererUpdateSaltD[((aIndex + 28U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aScatter, 57U) + aOrbiterC) + RotL64(aOrbiterB, 3U)) + RotL64(aCarry, 5U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 37U) + aOrbiterG) + RotL64(aOrbiterC, 29U)) + aNonceWordN);
            aWandererA = aWandererA + (((RotL64(aCross, 29U) + aOrbiterC) + RotL64(aOrbiterF, 57U)) + RotL64(aCarry, 51U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 43U) + aOrbiterG) + RotL64(aOrbiterH, 23U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 6U));
            aCarry = aCarry + (RotL64(aWandererK, 23U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererB, 35U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererA, 11U);
            aCarry = aCarry + RotL64(aIngress, 56U);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 11347U)) & S_BLOCK1], 11U) ^ RotL64(aKeyRowReadA[((aIndex + 12288U)) & W_KEY1], 3U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 11356U)) & W_KEY1], 53U) ^ RotL64(mSource[((aIndex + 13238U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 11125U)) & S_BLOCK1], 40U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 12411U)) & S_BLOCK1], 36U) ^ RotL64(aFireLaneC[((aIndex + 11172U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aIngress, 24U) ^ RotL64(aCross, 37U)) + (RotL64(aCarry, 53U) + RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterA = ((aWandererD + RotL64(aCross, 57U)) + RotL64(aCarry, 23U)) + 6024062041314952357U;
            aOrbiterC = (((aWandererA + RotL64(aScatter, 43U)) + 18340757093658015585U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordH;
            aOrbiterK = ((aWandererB + RotL64(aIngress, 19U)) + RotL64(aCarry, 57U)) + 11911120493880346751U;
            aOrbiterB = ((((aWandererF + RotL64(aPrevious, 5U)) + RotL64(aCarry, 43U)) + 17428074353884654439U) + aPhaseFOrbiterAssignSaltF[((aIndex + 19U)) & S_SALT1]) + aNonceWordK;
            aOrbiterE = (aWandererK + RotL64(aScatter, 13U)) + 12790849760814795936U;
            aOrbiterI = (aWandererE + RotL64(aCross, 34U)) + 12633397052172117800U;
            aOrbiterH = ((aWandererI + RotL64(aPrevious, 51U)) + 11946150433665237945U) + aNonceWordF;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 16842157900909419285U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 14186235783224155962U;
            aOrbiterK = RotL64((aOrbiterK * 10521157787073684417U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 13284904542579767591U) + aNonceWordC;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 11609181965078844357U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5455780554452453513U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 9628562297095374984U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 7850281529011259759U) ^ aNonceWordN;
            aOrbiterI = RotL64((aOrbiterI * 17611485102925470357U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 257458718073794527U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 10693404545773519306U;
            aOrbiterA = RotL64((aOrbiterA * 14821443722828498323U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 3430519236533871460U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 6183054506953198055U;
            aOrbiterH = RotL64((aOrbiterH * 6121082743789970911U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 2905610989884221654U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterK) ^ 4472163910775333862U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterB = RotL64((aOrbiterB * 7770678426310856745U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 16870142883133769663U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 1403692060594816451U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9740854430251597879U), 51U);
            //
            aIngress = RotL64(aOrbiterC, 40U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterA, 5U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterI, 13U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterH, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aIngress, 57U) + aOrbiterK) + RotL64(aOrbiterA, 13U));
            aWandererB = aWandererB + (((RotL64(aScatter, 13U) + RotL64(aOrbiterC, 60U)) + aOrbiterH) + aNonceWordL);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 41U) + RotL64(aOrbiterA, 53U)) + aOrbiterH) + aNonceWordO);
            aWandererD = aWandererD + ((((RotL64(aCross, 51U) + RotL64(aOrbiterE, 19U)) + aOrbiterB) + RotL64(aCarry, 29U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 35U) + RotL64(aOrbiterH, 5U)) + aOrbiterB) + aPhaseFWandererUpdateSaltB[((aIndex + 25U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 27U) + RotL64(aOrbiterA, 47U)) + aOrbiterC) + RotL64(aCarry, 57U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 6U) + RotL64(aOrbiterH, 41U)) + aOrbiterI) + aNonceWordB);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 11U));
            aCarry = aCarry + (RotL64(aWandererA, 56U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererF, 3U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererB, 43U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 14218U)) & S_BLOCK1], 35U) ^ RotL64(aFireLaneC[((aIndex + 15672U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 13780U)) & W_KEY1], 27U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 13930U)) & W_KEY1], 19U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 15052U)) & S_BLOCK1], 60U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 14214U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 14591U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aIngress, 24U) ^ RotL64(aCarry, 5U)) + (RotL64(aPrevious, 41U) + RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterA = ((aWandererF + RotL64(aScatter, 13U)) + 1898718075389870739U) + aPhaseFOrbiterAssignSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterI = (((aWandererK + RotL64(aIngress, 27U)) + RotL64(aCarry, 3U)) + 5631794889237247403U) + aNonceWordN;
            aOrbiterK = ((aWandererE + RotL64(aCross, 34U)) + RotL64(aCarry, 27U)) + 18219714659484524607U;
            aOrbiterD = ((((aWandererG + RotL64(aPrevious, 5U)) + RotL64(aCarry, 43U)) + 15419581386225732921U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordM;
            aOrbiterF = (aWandererC + RotL64(aCross, 53U)) + 9125575431710198210U;
            aOrbiterG = ((aWandererA + RotL64(aScatter, 47U)) + 12205871520544965505U) + aNonceWordC;
            aOrbiterB = (aWandererI + RotL64(aPrevious, 21U)) + 7617534300497343422U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 18017579105368135814U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 10693882161946020042U) ^ aNonceWordK;
            aOrbiterK = RotL64((aOrbiterK * 2326507900303932855U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 11669615701700895306U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 11045110212889232165U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5965171269273719849U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 18019107802806469913U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterG) ^ 12315940560472528716U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 28U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterD = RotL64((aOrbiterD * 4505122470351404065U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 4899009736070044310U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 17412253404253730364U) ^ aNonceWordD;
            aOrbiterI = RotL64((aOrbiterI * 10791901166391946485U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 4826286251927854181U) + aNonceWordO;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 4523455921321845084U;
            aOrbiterF = RotL64((aOrbiterF * 14534103906736598099U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 4132514462154182215U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 7164745605985109269U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 14107325508977225261U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 6297434295807635654U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 8813887638672996646U;
            aOrbiterG = RotL64((aOrbiterG * 17495632530773158201U), 5U);
            //
            aIngress = RotL64(aOrbiterB, 3U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterD, 41U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterK, 47U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterA, 10U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterG, 57U)) + aOrbiterD) + aNonceWordL);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 57U) + aOrbiterF) + RotL64(aOrbiterK, 48U)) + RotL64(aCarry, 13U)) + aPhaseFWandererUpdateSaltF[((aIndex + 9U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 29U) + aOrbiterA) + RotL64(aOrbiterK, 23U)) + aNonceWordJ);
            aWandererA = aWandererA + ((((RotL64(aIngress, 18U) + aOrbiterA) + RotL64(aOrbiterI, 35U)) + RotL64(aCarry, 53U)) + aNonceWordF);
            aWandererC = aWandererC ^ ((RotL64(aCross, 35U) + aOrbiterG) + RotL64(aOrbiterB, 11U));
            aWandererK = aWandererK + ((((RotL64(aPrevious, 3U) + aOrbiterG) + RotL64(aOrbiterF, 3U)) + aNonceWordH) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterB, 29U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 60U));
            aCarry = aCarry + (RotL64(aWandererA, 13U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererC, 41U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererE, 29U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 16984U)) & S_BLOCK1], 27U) ^ RotL64(aKeyRowReadA[((aIndex + 18257U)) & W_KEY1], 41U));
            aIngress ^= (RotL64(mSource[((aIndex + 18504U)) & S_BLOCK1], 4U) ^ RotL64(aFireLaneA[((aIndex + 18042U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 18319U)) & W_KEY1], 3U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 17840U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18641U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aIngress, 41U) + RotL64(aCross, 29U)) + (RotL64(aPrevious, 14U) ^ RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterC = ((aWandererH + RotL64(aScatter, 19U)) + 7632760812370906911U) + aNonceWordO;
            aOrbiterI = (aWandererF + RotL64(aIngress, 13U)) + 6007174525479723089U;
            aOrbiterE = ((aWandererA + RotL64(aPrevious, 41U)) + 3362829642521821048U) + aPhaseGOrbiterAssignSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterD = (((aWandererI + RotL64(aCross, 58U)) + RotL64(aCarry, 19U)) + 18009548556107978286U) + aNonceWordD;
            aOrbiterG = (((aWandererK + RotL64(aPrevious, 29U)) + RotL64(aCarry, 35U)) + 17880909432272697327U) + aNonceWordF;
            aOrbiterF = ((aWandererB + RotL64(aIngress, 51U)) + 15961567935420752568U) + aPhaseGOrbiterAssignSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterK = ((aWandererD + RotL64(aScatter, 3U)) + RotL64(aCarry, 53U)) + 10136559064656837921U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 17622019364405410277U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 6927494824421416306U;
            aOrbiterE = RotL64((aOrbiterE * 2686290883767829973U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 7125170407794874847U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 12342273503071032250U) ^ aPhaseGOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 867417849555857179U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 14997696377476124836U) + aNonceWordL;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 14874498694181230698U;
            aOrbiterC = RotL64((aOrbiterC * 4026127545746010937U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 2549397729130885686U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 4217995818662767955U) ^ aNonceWordE;
            aOrbiterG = RotL64((aOrbiterG * 5525525344485251063U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 4706089044415442525U) + aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 17983900172670031015U;
            aOrbiterF = RotL64((aOrbiterF * 541552737180932879U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 1904937798143929988U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 10620877287033139483U;
            aOrbiterK = RotL64((aOrbiterK * 16711012562024287213U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 15681091173163181525U) + aNonceWordB;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 2655543246639000084U) ^ aPhaseGOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 16686375598149755947U), 35U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterG, 39U);
            aIngress = aIngress + (RotL64(aOrbiterF, 57U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 19U));
            aIngress = aIngress + RotL64(aOrbiterC, 48U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aIngress, 5U) + RotL64(aOrbiterI, 37U)) + aOrbiterK) + RotL64(aCarry, 35U)) + aNonceWordJ);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 47U) + aOrbiterD) + RotL64(aOrbiterI, 30U)) + aNonceWordI);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 57U) + aOrbiterF) + RotL64(aOrbiterI, 3U)) + RotL64(aCarry, 5U)) + aNonceWordM);
            aWandererK = aWandererK ^ (((RotL64(aCross, 37U) + aOrbiterC) + RotL64(aOrbiterF, 13U)) + aPhaseGWandererUpdateSaltE[((aIndex + 9U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aIngress, 11U) + aOrbiterE) + RotL64(aOrbiterK, 43U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 30U) + aOrbiterE) + RotL64(aOrbiterC, 53U)) + aPhaseGWandererUpdateSaltB[((aIndex + 16U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aPrevious, 21U) + aOrbiterK) + RotL64(aOrbiterG, 21U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 54U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererI, 27U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererF, 13U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererK, 35U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 21277U)) & S_BLOCK1], 13U) ^ RotL64(mSource[((aIndex + 20277U)) & S_BLOCK1], 23U));
            aIngress ^= (RotL64(aWorkLaneA[((aIndex + 20233U)) & S_BLOCK1], 5U) ^ RotL64(aFireLaneA[((aIndex + 19268U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 20910U)) & W_KEY1], 29U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 20794U)) & W_KEY1], 21U));
            aCross ^= (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 20952U)) & S_BLOCK1], 51U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 19453U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aPrevious, 23U) + RotL64(aCarry, 47U)) ^ (RotL64(aIngress, 4U) + RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterH = ((aWandererE + RotL64(aCross, 57U)) + 11210042748013785976U) + aNonceWordA;
            aOrbiterG = ((aWandererG + RotL64(aPrevious, 27U)) + RotL64(aCarry, 19U)) + 4584747303233477454U;
            aOrbiterJ = (((aWandererD + RotL64(aScatter, 21U)) + RotL64(aCarry, 51U)) + 8878765929792969517U) + aNonceWordH;
            aOrbiterC = ((aWandererB + RotL64(aIngress, 41U)) + 2172232330280041122U) + aPhaseGOrbiterAssignSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterB = ((aWandererC + RotL64(aPrevious, 3U)) + 8378937026022264016U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterD = (aWandererF + RotL64(aIngress, 14U)) + 8683007464695824208U;
            aOrbiterF = ((aWandererK + RotL64(aCross, 47U)) + RotL64(aCarry, 3U)) + 9564352997357118134U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 11713878436769887528U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 8052917623074021077U) ^ aPhaseGOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 7450115139081623477U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 7720597162792145185U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 2602847785328475621U;
            aOrbiterB = RotL64((aOrbiterB * 14065077077207224525U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 17813669222300509724U) + aNonceWordN;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 8724263063156573013U;
            aOrbiterC = RotL64((aOrbiterC * 3632927017737834359U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 6882429835961613492U) + aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 13213313479525717359U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2411431247725974895U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 2401526093648669573U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 3616448566579979749U;
            aOrbiterH = RotL64((aOrbiterH * 13323155103752121393U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 18268262471839710401U) + aNonceWordE;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 5116424918948694752U;
            aOrbiterD = RotL64((aOrbiterD * 7641143782996332069U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 11405305689555640431U) + aNonceWordC;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 12427591396711015574U;
            aOrbiterF = RotL64((aOrbiterF * 8112834135715541223U), 13U);
            //
            aIngress = RotL64(aOrbiterB, 35U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 27U));
            aIngress = aIngress + (RotL64(aOrbiterG, 47U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterJ, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterB, 21U)) + aOrbiterD);
            aWandererK = aWandererK + ((((RotL64(aScatter, 23U) + aOrbiterJ) + RotL64(aOrbiterD, 13U)) + RotL64(aCarry, 41U)) + aNonceWordP);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 30U) + RotL64(aOrbiterC, 60U)) + aOrbiterJ) + aPhaseGWandererUpdateSaltB[((aIndex + 21U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aCross, 43U) + RotL64(aOrbiterF, 43U)) + aOrbiterC) + RotL64(aCarry, 53U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 37U) + aOrbiterJ) + RotL64(aOrbiterH, 29U)) + aPhaseGWandererUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 51U) + aOrbiterB) + RotL64(aOrbiterJ, 3U)) + aNonceWordF);
            aWandererC = aWandererC ^ (((RotL64(aCross, 5U) + RotL64(aOrbiterC, 51U)) + aOrbiterG) + aNonceWordO);
            //
            aCarry = aCarry + (RotL64(aWandererC, 3U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererE, 24U) ^ aWandererG);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 39U));
            aCarry = aCarry + RotL64(aWandererB, 35U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aWorkLaneD[((aIndex + 21850U)) & S_BLOCK1], 5U) ^ RotL64(aKeyRowReadA[((aIndex + 24271U)) & W_KEY1], 47U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 23697U)) & W_KEY1], 35U) ^ RotL64(aWorkLaneC[((aIndex + 24016U)) & S_BLOCK1], 60U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 21851U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23674U)) & S_BLOCK1], 29U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 23107U)) & S_BLOCK1], 43U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 23023U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aIngress, 40U) ^ RotL64(aCross, 11U)) + (RotL64(aPrevious, 57U) + RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterC = (((aWandererB + RotL64(aIngress, 30U)) + 5041131702736607991U) + aPhaseGOrbiterAssignSaltA[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordF;
            aOrbiterF = (((aWandererK + RotL64(aCross, 39U)) + RotL64(aCarry, 47U)) + 9295010428212681446U) + aNonceWordG;
            aOrbiterB = ((aWandererD + RotL64(aScatter, 3U)) + 6235875895358766017U) + aNonceWordA;
            aOrbiterE = (((aWandererJ + RotL64(aPrevious, 47U)) + RotL64(aCarry, 27U)) + 2622227802531866918U) + aPhaseGOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = ((aWandererF + RotL64(aIngress, 13U)) + 3888894734834524972U) + aNonceWordJ;
            aOrbiterI = (aWandererH + RotL64(aCross, 57U)) + 241682012014701753U;
            aOrbiterD = ((aWandererG + RotL64(aScatter, 21U)) + RotL64(aCarry, 13U)) + 15758000422451568079U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 2061944548396976912U) + aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 8177144990755754531U;
            aOrbiterB = RotL64((aOrbiterB * 12702392689484397947U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 554978075608818497U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 250408260560714933U;
            aOrbiterI = RotL64((aOrbiterI * 1295379390497107727U), 57U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterB) + 8700027645880997552U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1]) + aNonceWordM;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 10026130047465480902U) ^ aNonceWordB;
            aOrbiterD = RotL64((aOrbiterD * 12417270861933696623U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 9785843014096326696U) + aPhaseGOrbiterUpdateSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 9998582683258411251U) ^ aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7197956237569462269U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 13817734599383455151U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 6647207154174092691U;
            aOrbiterF = RotL64((aOrbiterF * 1578528131687283531U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 4957715980509035719U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 4994885315786213197U) ^ aNonceWordN;
            aOrbiterJ = RotL64((aOrbiterJ * 5676683798126497011U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 5072908311783966503U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 5535039946192891515U;
            aOrbiterC = RotL64((aOrbiterC * 2989412783482309753U), 37U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterC, 23U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 13U));
            aIngress = aIngress + (RotL64(aOrbiterI, 53U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterE, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aCross, 53U) + RotL64(aOrbiterB, 50U)) + aOrbiterC) + aPhaseGWandererUpdateSaltD[((aIndex + 9U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aIngress, 21U) + RotL64(aOrbiterF, 3U)) + aOrbiterC) + aNonceWordH) + aPhaseGWandererUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 39U) + RotL64(aOrbiterF, 35U)) + aOrbiterB) + aNonceWordO);
            aWandererB = aWandererB + (((RotL64(aPrevious, 60U) + RotL64(aOrbiterD, 43U)) + aOrbiterE) + RotL64(aCarry, 57U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 3U) + aOrbiterI) + RotL64(aOrbiterJ, 11U)) + aNonceWordI);
            aWandererG = aWandererG + (((RotL64(aCross, 47U) + RotL64(aOrbiterE, 57U)) + aOrbiterJ) + RotL64(aCarry, 39U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 11U) + aOrbiterE) + RotL64(aOrbiterI, 27U)) + aNonceWordL);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 14U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 51U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 19U));
            aCarry = aCarry + RotL64(aWandererK, 5U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 27238U)) & S_BLOCK1], 42U) ^ RotL64(aKeyRowReadA[((aIndex + 26291U)) & W_KEY1], 57U));
            aIngress ^= (RotL64(aWorkLaneD[((aIndex + 25102U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneB[((aIndex + 26215U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 25795U)) & W_KEY1], 29U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 24603U)) & S_BLOCK1], 19U));
            aCross ^= (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 27131U)) & S_BLOCK1], 42U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 25167U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aIngress, 21U) + RotL64(aCross, 6U)) ^ (RotL64(aCarry, 37U) + RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterE = (aWandererB + RotL64(aIngress, 43U)) + 10881271196314989997U;
            aOrbiterG = ((aWandererF + RotL64(aScatter, 34U)) + 6406461249988567558U) + aPhaseHOrbiterAssignSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = ((aWandererJ + RotL64(aCross, 27U)) + 17255067918280095959U) + aNonceWordA;
            aOrbiterK = ((aWandererI + RotL64(aPrevious, 57U)) + RotL64(aCarry, 3U)) + 16690850682497718411U;
            aOrbiterJ = ((((aWandererG + RotL64(aCross, 11U)) + RotL64(aCarry, 39U)) + 5576201059361086866U) + aPhaseHOrbiterAssignSaltC[((aIndex + 10U)) & S_SALT1]) + aNonceWordD;
            aOrbiterC = (aWandererE + RotL64(aPrevious, 3U)) + 11991259685693687554U;
            aOrbiterD = ((aWandererK + RotL64(aIngress, 51U)) + RotL64(aCarry, 21U)) + 14652535244217836909U;
            //
            aOrbiterE = (((aOrbiterE + aOrbiterG) + 1701789037170782122U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1]) + aNonceWordL;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 953429054903473833U;
            aOrbiterA = RotL64((aOrbiterA * 13482379459700651427U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 12064513610469714211U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 7993881398822002424U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 11572884842788918377U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 14421313768013320050U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 11112386845630998889U;
            aOrbiterC = RotL64((aOrbiterC * 11771526352030371669U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 17069630896535699015U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 3308240081138623373U;
            aOrbiterK = RotL64((aOrbiterK * 10449509484417835159U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 17615529807112933619U) + aNonceWordJ;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 11782807146851563541U) ^ aNonceWordI;
            aOrbiterJ = RotL64((aOrbiterJ * 12992075832343669221U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 14401645829607611983U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 6736397344219993532U;
            aOrbiterG = RotL64((aOrbiterG * 1667287547938175641U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 6446974060524700550U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 7840991992443308254U) ^ aNonceWordP;
            aOrbiterD = RotL64((aOrbiterD * 6891023544882740107U), 23U);
            //
            aIngress = RotL64(aOrbiterK, 51U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 13U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 20U));
            aIngress = aIngress + RotL64(aOrbiterA, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((((RotL64(aCross, 43U) + aOrbiterC) + RotL64(aOrbiterG, 23U)) + aNonceWordC) + aPhaseHWandererUpdateSaltA[((aIndex + 23U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 27U) + aOrbiterG) + RotL64(aOrbiterA, 47U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterK, 41U)) + aOrbiterE);
            aWandererI = aWandererI + (((RotL64(aScatter, 5U) + aOrbiterC) + RotL64(aOrbiterA, 13U)) + RotL64(aCarry, 41U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 37U) + aOrbiterD) + RotL64(aOrbiterK, 54U)) + aNonceWordM);
            aWandererK = aWandererK + (((((RotL64(aIngress, 21U) + RotL64(aOrbiterE, 35U)) + aOrbiterG) + RotL64(aCarry, 29U)) + aNonceWordB) + aPhaseHWandererUpdateSaltF[((aIndex + 11U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aCross, 52U) + RotL64(aOrbiterG, 29U)) + aOrbiterJ) + aNonceWordN);
            //
            aCarry = aCarry + (RotL64(aWandererK, 36U) ^ aWandererJ);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 19U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 13U));
            aCarry = aCarry + RotL64(aWandererG, 47U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 29290U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneD[((aIndex + 27808U)) & S_BLOCK1], 13U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 27923U)) & W_KEY1], 58U) ^ RotL64(aWorkLaneC[((aIndex + 29145U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 28281U)) & W_KEY1], 27U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 29054U)) & S_BLOCK1], 57U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29186U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((aIndex + 28052U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCross, 21U) + RotL64(aPrevious, 51U)) + (RotL64(aCarry, 4U) ^ RotL64(aIngress, 35U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterG = ((((aWandererE + RotL64(aScatter, 53U)) + RotL64(aCarry, 23U)) + 12690502671561165478U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordD;
            aOrbiterE = (((aWandererI + RotL64(aIngress, 27U)) + RotL64(aCarry, 11U)) + 17519943923428102801U) + aNonceWordM;
            aOrbiterC = (aWandererJ + RotL64(aCross, 46U)) + 10705515807975331385U;
            aOrbiterI = (aWandererG + RotL64(aPrevious, 11U)) + 16586447272278538179U;
            aOrbiterF = ((aWandererA + RotL64(aIngress, 37U)) + 8006560996840971798U) + aNonceWordG;
            aOrbiterB = (aWandererH + RotL64(aPrevious, 21U)) + 12928600185788857701U;
            aOrbiterD = (((aWandererD + RotL64(aCross, 5U)) + RotL64(aCarry, 57U)) + 14240723153798267172U) + aPhaseHOrbiterAssignSaltC[((aIndex + 6U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 8636219177994872072U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 7586790235186467512U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 15052686382507614169U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 1103807034179512424U) + aNonceWordA;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 7547526530239498693U;
            aOrbiterF = RotL64((aOrbiterF * 3360295583636013509U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 8380239679344786397U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 5690809173787433519U;
            aOrbiterE = RotL64((aOrbiterE * 5354724308093372953U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 8390902801141804609U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 3507306189192059486U) ^ aNonceWordH;
            aOrbiterG = RotL64((aOrbiterG * 18336280496510253103U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 6190745292098482871U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 8065418693975056902U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 6414621418430102589U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 12111755051718111803U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 7605877769709909297U;
            aOrbiterI = RotL64((aOrbiterI * 17525248694315944599U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 5969794501112646237U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 5127559299360591476U;
            aOrbiterB = RotL64((aOrbiterB * 4521563633438853069U), 57U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterF, 21U);
            aIngress = aIngress + (RotL64(aOrbiterC, 13U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterB, 57U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterD, 44U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aScatter, 41U) + aOrbiterC) + RotL64(aOrbiterB, 21U)) + aNonceWordB);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 60U) + aOrbiterC) + RotL64(aOrbiterI, 5U)) + RotL64(aCarry, 27U)) + aNonceWordC);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterB, 13U)) + aOrbiterF) + aPhaseHWandererUpdateSaltA[((aIndex + 9U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aIngress, 51U) + RotL64(aOrbiterG, 60U)) + aOrbiterI) + aPhaseHWandererUpdateSaltF[((aIndex + 3U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 21U) + aOrbiterD) + RotL64(aOrbiterE, 41U));
            aWandererI = aWandererI + ((((RotL64(aPrevious, 35U) + aOrbiterG) + RotL64(aOrbiterE, 29U)) + RotL64(aCarry, 51U)) + aNonceWordJ);
            aWandererG = aWandererG ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterD, 51U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererG, 58U) ^ aWandererJ);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 27U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 53U));
            aCarry = aCarry + RotL64(aWandererH, 19U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 31807U)) & S_BLOCK1], 37U) ^ RotL64(aKeyRowReadA[((aIndex + 31975U)) & W_KEY1], 57U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 32642U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30277U)) & S_BLOCK1], 4U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30159U)) & S_BLOCK1], 41U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 31289U)) & W_KEY1], 27U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aPrevious, 39U) ^ RotL64(aCarry, 26U)) + (RotL64(aIngress, 51U) ^ RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterA = (((aWandererG + RotL64(aScatter, 47U)) + RotL64(aCarry, 19U)) + 11698283336767769359U) + aNonceWordJ;
            aOrbiterD = ((aWandererE + RotL64(aPrevious, 3U)) + RotL64(aCarry, 35U)) + 13297826354831483872U;
            aOrbiterJ = (((aWandererJ + RotL64(aCross, 23U)) + RotL64(aCarry, 5U)) + 15254999058287530795U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = ((aWandererH + RotL64(aIngress, 38U)) + 17474166585085346567U) + aNonceWordH;
            aOrbiterK = ((aWandererA + RotL64(aScatter, 11U)) + 15684783498452840289U) + aNonceWordO;
            aOrbiterF = ((aWandererC + RotL64(aCross, 53U)) + 5061229733465216486U) + aNonceWordA;
            aOrbiterE = ((aWandererK + RotL64(aIngress, 29U)) + 15370981279168377944U) + aPhaseHOrbiterAssignSaltF[((aIndex + 5U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 17966672773619554092U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 14685092893994491068U;
            aOrbiterJ = RotL64((aOrbiterJ * 1627758964162892429U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 12798804186209406389U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 2848444181474221574U) ^ aNonceWordC;
            aOrbiterK = RotL64((aOrbiterK * 13730480364920876877U), 37U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterF) + 8551142075919636146U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordI;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 8833198159158950723U;
            aOrbiterA = RotL64((aOrbiterA * 7650289040764974737U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 7351473160893666232U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 14204899612487622222U;
            aOrbiterF = RotL64((aOrbiterF * 6317485031956448029U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 7008985178526543258U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 13576796403863120356U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 13745839827679114077U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 5769784656937900699U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 14075925808204936705U) ^ aNonceWordG;
            aOrbiterI = RotL64((aOrbiterI * 5844894088757604713U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 17818667502858010896U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 16016922065572683130U;
            aOrbiterD = RotL64((aOrbiterD * 7525645833898085373U), 11U);
            //
            aIngress = RotL64(aOrbiterA, 19U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 5U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 57U));
            aIngress = aIngress + RotL64(aOrbiterI, 42U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aIngress, 3U) + RotL64(aOrbiterI, 43U)) + aOrbiterF) + RotL64(aCarry, 19U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 43U) + aOrbiterA) + RotL64(aOrbiterI, 5U));
            aWandererE = aWandererE + ((((RotL64(aPrevious, 53U) + RotL64(aOrbiterA, 51U)) + aOrbiterD) + RotL64(aCarry, 39U)) + aNonceWordN);
            aWandererH = aWandererH ^ (((RotL64(aCross, 37U) + aOrbiterJ) + RotL64(aOrbiterI, 13U)) + aPhaseHWandererUpdateSaltC[((aIndex + 4U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aScatter, 28U) + aOrbiterD) + RotL64(aOrbiterF, 20U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 21U) + RotL64(aOrbiterK, 57U)) + aOrbiterI) + aPhaseHWandererUpdateSaltA[((aIndex + 26U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterE, 27U)) + aOrbiterA) + aNonceWordF);
            //
            aCarry = aCarry + (RotL64(aWandererE, 53U) ^ aWandererG);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 24U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 13U));
            aCarry = aCarry + RotL64(aWandererC, 35U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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

void TwistExpander_PingPong_Arx::Seed_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xAFE9E474C1E3CC83ULL + 0xE4FBCBCAD4F5A33FULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x82BABEC042F73999ULL + 0x9224BE6AD79C9AA3ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x9ABBDB7B2D55D60DULL + 0xBFEC5E8B964C7AC7ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x8122ACE94ED8C267ULL + 0xA148EBE0A14D27ECULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xA8342ADD53F5689DULL + 0xDCBB1419DF4E9692ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xA33825D76A176FB7ULL + 0xF4FAEF334515773EULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xF4088A9D2014E2CFULL + 0xE11D7BC22DC17F74ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xE2C028313783EA27ULL + 0xC5AA0722E9E64F9AULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xFF419B2088779CA9ULL + 0x843C1C7E1BF45A66ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0x86EDAA44EE039713ULL + 0xC6E7930AEB6ED309ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0x933EA670F591E5FDULL + 0xD46B025350BC41BBULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xB12E195353258335ULL + 0x8E3698F4FB8CE544ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x8CA43ACE0444B6D7ULL + 0xB1DDA62834E297B2ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0x80EBAABC4981EBF1ULL + 0xE6DB854BC446F35CULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xC9085ADFB87CB3B9ULL + 0xF9C152E9FE74F30EULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xC11C98487EECFF17ULL + 0xACACE5120585540DULL);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 4035U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneB[((aIndex + 2177U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 2304U)) & S_BLOCK1], 48U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 1916U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 47U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 368U)) & S_BLOCK1], 12U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aPrevious, 41U) + RotL64(aCross, 53U)) + (RotL64(aIngress, 3U) ^ RotL64(aCarry, 28U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterB = ((((aWandererC + RotL64(aScatter, 19U)) + RotL64(aCarry, 19U)) + 11700815697312060726U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordC;
            aOrbiterA = ((aWandererE + RotL64(aIngress, 41U)) + 11808423452327465441U) + aNonceWordG;
            aOrbiterG = ((aWandererF + RotL64(aCross, 4U)) + 8670503858631730886U) + aNonceWordH;
            aOrbiterK = (((aWandererJ + RotL64(aPrevious, 51U)) + RotL64(aCarry, 53U)) + 2400061067991988544U) + aPhaseAOrbiterAssignSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterI = (((aWandererI + RotL64(aCross, 29U)) + RotL64(aCarry, 41U)) + 16163118178366229686U) + aNonceWordL;
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 3280178595904941068U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 3298683600817047727U;
            aOrbiterG = RotL64((aOrbiterG * 9865649058799255343U), 19U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterB) + 16321624053445183574U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 6730229877611375225U;
            aOrbiterA = RotL64((aOrbiterA * 2022290495153519279U), 5U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterG) + 10162830636713641322U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1]) + aNonceWordF;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 15646771327759599256U;
            aOrbiterI = RotL64((aOrbiterI * 15333053762177144775U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 14841751262270544102U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 9545541117228834895U;
            aOrbiterK = RotL64((aOrbiterK * 11529769874752969377U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 14676615635857599982U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 1231768638470558855U;
            aOrbiterB = RotL64((aOrbiterB * 2716808508509014677U), 27U);
            //
            aIngress = RotL64(aOrbiterK, 4U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 35U));
            aIngress = aIngress + RotL64(aOrbiterG, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aCross, 11U) + RotL64(aOrbiterI, 53U)) + aOrbiterG) + RotL64(aCarry, 41U)) + aPhaseAWandererUpdateSaltA[((aIndex + 27U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((((RotL64(aIngress, 3U) + aOrbiterA) + RotL64(aOrbiterK, 3U)) + aNonceWordN) + aPhaseAWandererUpdateSaltF[((aIndex + 17U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 41U) + RotL64(aOrbiterB, 11U)) + aOrbiterG) + aNonceWordA);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 56U) + RotL64(aOrbiterA, 43U)) + aOrbiterI) + aNonceWordM);
            aWandererC = aWandererC + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterK, 26U)) + aOrbiterG) + RotL64(aCarry, 13U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 18U) ^ aWandererF);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 57U));
            aCarry = aCarry + RotL64(aWandererJ, 29U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 9865U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneC[((aIndex + 5800U)) & S_BLOCK1], 5U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 10582U)) & S_BLOCK1], 18U) ^ RotL64(aFireLaneC[((aIndex + 8350U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 9544U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 7688U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 9466U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aPrevious, 51U) + RotL64(aCarry, 39U)) ^ (RotL64(aIngress, 5U) ^ RotL64(aCross, 26U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterD = ((aWandererA + RotL64(aPrevious, 30U)) + 15036852811491820366U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterA = ((aWandererE + RotL64(aCross, 53U)) + RotL64(aCarry, 21U)) + 305637140752898475U;
            aOrbiterB = ((aWandererB + RotL64(aIngress, 43U)) + RotL64(aCarry, 53U)) + 11948631574496129610U;
            aOrbiterK = (((aWandererJ + RotL64(aScatter, 19U)) + RotL64(aCarry, 3U)) + 5321623592482991426U) + aNonceWordD;
            aOrbiterF = (((aWandererF + RotL64(aIngress, 5U)) + 4075270159062690728U) + aPhaseAOrbiterAssignSaltE[((aIndex + 18U)) & S_SALT1]) + aNonceWordO;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 15111580500356908928U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = (((aOrbiterB ^ aOrbiterD) ^ 7244150695504160363U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterB = RotL64((aOrbiterB * 2445733898697939969U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 5131563519577488862U) + aNonceWordM;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 5881954992088651371U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2424421828597294607U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 12780935808751507998U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 12599159643925470226U;
            aOrbiterA = RotL64((aOrbiterA * 17690046932587062701U), 37U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 9466589929741834066U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 6093158735705189789U;
            aOrbiterD = RotL64((aOrbiterD * 7453778295800853653U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 17461243886150519249U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 15456408913739900718U;
            aOrbiterK = RotL64((aOrbiterK * 16093292401746174671U), 3U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterB, 19U);
            aIngress = aIngress + (RotL64(aOrbiterF, 29U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterK, 56U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 56U) + RotL64(aOrbiterD, 47U)) + aOrbiterA) + RotL64(aCarry, 29U)) + aNonceWordG);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 27U) + RotL64(aOrbiterF, 57U)) + aOrbiterD) + aNonceWordP);
            aWandererE = aWandererE + (((RotL64(aCross, 3U) + RotL64(aOrbiterK, 3U)) + aOrbiterA) + aPhaseAWandererUpdateSaltB[((aIndex + 11U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 43U) + aOrbiterF) + RotL64(aOrbiterB, 13U)) + aNonceWordE);
            aWandererF = aWandererF + (((((RotL64(aCross, 11U) + aOrbiterD) + RotL64(aOrbiterK, 38U)) + RotL64(aCarry, 53U)) + aNonceWordC) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 51U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 13U));
            aCarry = aCarry + RotL64(aWandererB, 43U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 15403U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneA[((aIndex + 11825U)) & S_BLOCK1], 28U));
            aIngress ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 15487U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 15987U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 12631U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCross, 24U) + RotL64(aPrevious, 57U)) + (RotL64(aIngress, 11U) ^ RotL64(aCarry, 43U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterA = (((aWandererE + RotL64(aIngress, 23U)) + RotL64(aCarry, 41U)) + 9435962834163239322U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = (((aWandererI + RotL64(aScatter, 35U)) + RotL64(aCarry, 11U)) + 10524704356081318973U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterG = ((aWandererH + RotL64(aCross, 12U)) + 7403401305665208680U) + aNonceWordL;
            aOrbiterE = ((aWandererC + RotL64(aPrevious, 3U)) + RotL64(aCarry, 53U)) + 7525414805023556493U;
            aOrbiterF = ((aWandererA + RotL64(aIngress, 53U)) + 1116686470029070951U) + aNonceWordM;
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 13257612299137802420U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 9181543003986598283U;
            aOrbiterG = RotL64((aOrbiterG * 18162011316880411235U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 9739384852307501107U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 11308402900229016057U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12690186771773188967U), 53U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 14935167593705272337U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 7171824007631943535U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4839974427616194289U), 37U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 8068411284829563567U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 12350207458513447578U) ^ aNonceWordJ;
            aOrbiterE = RotL64((aOrbiterE * 813973258659041895U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 17039236343991574134U) + aNonceWordD;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 18291683592714999632U;
            aOrbiterC = RotL64((aOrbiterC * 7771718817924840713U), 3U);
            //
            aIngress = RotL64(aOrbiterC, 57U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 13U));
            aIngress = aIngress + RotL64(aOrbiterF, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterF, 37U)) + aOrbiterA) + aNonceWordK);
            aWandererH = aWandererH + ((((RotL64(aIngress, 53U) + RotL64(aOrbiterA, 21U)) + aOrbiterC) + RotL64(aCarry, 51U)) + aPhaseAWandererUpdateSaltE[((aIndex + 17U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterC, 10U)) + aOrbiterG);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 44U) + aOrbiterG) + RotL64(aOrbiterF, 29U)) + RotL64(aCarry, 23U)) + aNonceWordP);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 11U) + RotL64(aOrbiterE, 51U)) + aOrbiterF) + aPhaseAWandererUpdateSaltD[((aIndex + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 3U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererC, 53U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererI, 21U);
            aCarry = aCarry + RotL64(aIngress, 40U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 16782U)) & S_BLOCK1], 3U) ^ RotL64(aInvestLaneA[((aIndex + 20812U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 17194U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 21004U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneD[((aIndex + 16669U)) & S_BLOCK1], 6U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aPrevious, 13U) + RotL64(aCarry, 42U)) ^ (RotL64(aIngress, 29U) ^ RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterB = (((aWandererC + RotL64(aScatter, 3U)) + RotL64(aCarry, 53U)) + 3621877681473089725U) + aNonceWordG;
            aOrbiterC = (((aWandererJ + RotL64(aIngress, 21U)) + 4451752751536414717U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordC;
            aOrbiterJ = (((aWandererF + RotL64(aPrevious, 52U)) + RotL64(aCarry, 23U)) + 11371625415377772117U) + aNonceWordH;
            aOrbiterG = (((aWandererG + RotL64(aCross, 35U)) + RotL64(aCarry, 35U)) + 6046792758881150619U) + aNonceWordK;
            aOrbiterD = ((aWandererK + RotL64(aScatter, 13U)) + 8213166120394461682U) + aPhaseAOrbiterAssignSaltA[((aIndex + 8U)) & S_SALT1];
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 4343156661140422645U) + aNonceWordE;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 11105271483234947905U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 853531080115819287U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 348904609985341372U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 12924652822526858767U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2801892489296408735U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 7461211697358520287U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 16551553555297890558U;
            aOrbiterG = RotL64((aOrbiterG * 16432952324635746293U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 11908056404140782995U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 9147367258259948715U) ^ aNonceWordA;
            aOrbiterD = RotL64((aOrbiterD * 10777628928376261667U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 8876461054692728610U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 10546855952702525404U;
            aOrbiterC = RotL64((aOrbiterC * 10071104785895309677U), 51U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterB, 29U);
            aIngress = aIngress + (RotL64(aOrbiterC, 41U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterJ, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aCross, 21U) + aOrbiterG) + RotL64(aOrbiterJ, 27U)) + RotL64(aCarry, 11U)) + aNonceWordB);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 44U) + RotL64(aOrbiterD, 38U)) + aOrbiterB);
            aWandererF = aWandererF + (((((RotL64(aScatter, 29U) + RotL64(aOrbiterC, 13U)) + aOrbiterB) + RotL64(aCarry, 35U)) + aNonceWordO) + aPhaseAWandererUpdateSaltA[((aIndex + 25U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 13U) + aOrbiterD) + RotL64(aOrbiterG, 51U)) + aNonceWordJ);
            aWandererG = aWandererG + (((RotL64(aCross, 3U) + aOrbiterJ) + RotL64(aOrbiterD, 3U)) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 29U));
            aCarry = aCarry + (RotL64(aWandererF, 53U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererC, 20U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 25876U)) & S_BLOCK1], 21U) ^ RotL64(aInvestLaneB[((aIndex + 26793U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 22537U)) & S_BLOCK1], 34U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 25348U)) & S_BLOCK1], 43U) ^ RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 23499U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aPrevious, 21U) + RotL64(aCross, 34U)) + (RotL64(aCarry, 57U) ^ RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterB = (((aWandererD + RotL64(aCross, 29U)) + RotL64(aCarry, 5U)) + 12262991801139086177U) + aPhaseAOrbiterAssignSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = (((aWandererH + RotL64(aScatter, 10U)) + RotL64(aCarry, 41U)) + 7963038771924890197U) + aNonceWordK;
            aOrbiterI = ((aWandererC + RotL64(aIngress, 37U)) + 15540520327933568896U) + aNonceWordP;
            aOrbiterH = (((aWandererA + RotL64(aPrevious, 53U)) + RotL64(aCarry, 53U)) + 8745565892055020722U) + aNonceWordG;
            aOrbiterE = (((aWandererF + RotL64(aIngress, 21U)) + 16619329199683755286U) + aPhaseAOrbiterAssignSaltF[((aIndex + 7U)) & S_SALT1]) + aNonceWordO;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 10865705026433867260U) + aNonceWordC;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 2743368697984518059U;
            aOrbiterI = RotL64((aOrbiterI * 2989232417816919375U), 57U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterH) + 5556006271515473135U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordE;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 5355833281353498588U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4190140212757841511U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 8313616108963479829U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 16657121016801866434U;
            aOrbiterH = RotL64((aOrbiterH * 331533349428472477U), 19U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterB) + 16532226425013000833U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordF;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 5800465874932467232U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5966395771690704577U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 17882948163883121328U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 15029375310296563175U;
            aOrbiterB = RotL64((aOrbiterB * 17021415832288477713U), 43U);
            //
            aIngress = RotL64(aOrbiterI, 51U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 29U));
            aIngress = aIngress + RotL64(aOrbiterC, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 39U) + aOrbiterE) + RotL64(aOrbiterI, 35U)) + aNonceWordH);
            aWandererH = aWandererH + (((((RotL64(aScatter, 51U) + aOrbiterH) + RotL64(aOrbiterI, 13U)) + RotL64(aCarry, 41U)) + aNonceWordI) + aPhaseAWandererUpdateSaltC[((aIndex + 14U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 27U) + RotL64(aOrbiterB, 47U)) + aOrbiterH) + aNonceWordN);
            aWandererC = aWandererC + ((((RotL64(aCross, 19U) + RotL64(aOrbiterC, 56U)) + aOrbiterE) + RotL64(aCarry, 21U)) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 6U) + aOrbiterH) + RotL64(aOrbiterE, 27U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 43U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 53U));
            aCarry = aCarry + RotL64(aWandererD, 6U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 29624U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneA[((aIndex + 27554U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 32380U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 32190U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneB[((aIndex + 28937U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCarry, 36U) ^ RotL64(aIngress, 5U)) + (RotL64(aPrevious, 19U) ^ RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterE = (((aWandererF + RotL64(aCross, 19U)) + RotL64(aCarry, 11U)) + 8101351470141807662U) + aPhaseAOrbiterAssignSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterF = ((aWandererG + RotL64(aIngress, 27U)) + RotL64(aCarry, 41U)) + 6965474099521076705U;
            aOrbiterK = ((aWandererI + RotL64(aScatter, 56U)) + 6803828268885684784U) + aNonceWordP;
            aOrbiterB = (((aWandererJ + RotL64(aPrevious, 47U)) + RotL64(aCarry, 27U)) + 13454235922950972488U) + aNonceWordA;
            aOrbiterG = ((aWandererB + RotL64(aScatter, 39U)) + 11678091885751244777U) + aPhaseAOrbiterAssignSaltD[((aIndex + 3U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 5307134544628507141U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 4873703518950429353U) ^ aNonceWordB;
            aOrbiterK = RotL64((aOrbiterK * 2680442582958424915U), 5U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 8542156221858586039U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 3993726182905296513U;
            aOrbiterF = RotL64((aOrbiterF * 11331376012938127609U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 12113047622035464386U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 1944244448665721151U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7010050836758762003U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 12914188029425467576U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterK) ^ 2486762763475327024U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 10U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterB = RotL64((aOrbiterB * 12319769994433811617U), 21U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 14580191602982245481U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 12093414832400135066U;
            aOrbiterE = RotL64((aOrbiterE * 12720286833215690663U), 13U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterK, 41U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 54U));
            aIngress = aIngress + RotL64(aOrbiterG, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aScatter, 29U) + aOrbiterB) + RotL64(aOrbiterF, 13U)) + RotL64(aCarry, 27U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 11U) + aOrbiterG) + RotL64(aOrbiterF, 53U)) + aNonceWordN);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 37U) + aOrbiterE) + RotL64(aOrbiterK, 5U)) + aNonceWordI) + aPhaseAWandererUpdateSaltE[((aIndex + 25U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterG, 40U)) + aOrbiterE) + aPhaseAWandererUpdateSaltD[((aIndex + 15U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 54U) + RotL64(aOrbiterE, 29U)) + aOrbiterB) + RotL64(aCarry, 41U)) + aNonceWordO);
            //
            aCarry = aCarry + (RotL64(aWandererG, 57U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererI, 13U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererJ, 29U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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

void TwistExpander_PingPong_Arx::Seed_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xA7D4B928435E0A71ULL + 0xA055E57FB766DF67ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xCC83EA8D13EF8DC9ULL + 0x8DE38D17FC590357ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xE53D8DC329F62239ULL + 0x9CBC45FAE3D53D19ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x9F646D6E6796B347ULL + 0xFE7BD2EB3529EFC7ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xA28EA650FF8236CFULL + 0xA18206D559740FF7ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xDF6778C1637185B7ULL + 0x83DAC29E1321B865ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xC15C47FA75DD2421ULL + 0xB3962C97D55597E3ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xAD865B7C28919A39ULL + 0xF685B9EF1F5D5BDFULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xFA475980B2AEC5DFULL + 0xFA0D460B8E436DDDULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xF8826191AAC1139BULL + 0x82314EA23DD07B08ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x8E2355FB9D157AB5ULL + 0x96CB93805DE75805ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xC8757F52C672AE61ULL + 0xC3C6DB3C947A50D5ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xA8093309D65D0435ULL + 0xA89A0718602FD3BDULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xC97EF576D32816BFULL + 0xB5B05E301FFD8901ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xE0D12E75761290B1ULL + 0xA02A25DF556496D0ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0x864D472BAE6C2D71ULL + 0xFF71B61D875BD994ULL);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 5408U)) & S_BLOCK1], 40U) ^ RotL64(aOperationLaneB[((aIndex + 2217U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 481U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 1127U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 3638U)) & S_BLOCK1], 58U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 6519U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCross, 37U) + RotL64(aPrevious, 21U)) ^ (RotL64(aCarry, 53U) ^ RotL64(aIngress, 6U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterH = (aWandererK + RotL64(aScatter, 5U)) + 2330952702412094686U;
            aOrbiterI = (aWandererD + RotL64(aPrevious, 42U)) + 7820188225935060799U;
            aOrbiterK = (((aWandererJ + RotL64(aCross, 11U)) + RotL64(aCarry, 3U)) + 9347644591709839145U) + aNonceWordK;
            aOrbiterC = (((aWandererI + RotL64(aIngress, 29U)) + RotL64(aCarry, 13U)) + 2288624878446846870U) + aNonceWordJ;
            aOrbiterE = ((aWandererF + RotL64(aCross, 47U)) + 9358977729492824128U) + aNonceWordH;
            aOrbiterA = (((aWandererH + RotL64(aPrevious, 34U)) + 1858511275052455039U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordG;
            aOrbiterG = ((aWandererB + RotL64(aIngress, 19U)) + 13715478509322292552U) + aPhaseBOrbiterAssignSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = ((aWandererE + RotL64(aScatter, 53U)) + RotL64(aCarry, 29U)) + 16413396625604260455U;
            aOrbiterD = (aWandererG + RotL64(aIngress, 23U)) + 17714322215518432705U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 16188315436202861122U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 5564445841368207813U) ^ aNonceWordP;
            aOrbiterK = RotL64((aOrbiterK * 14125834616162835983U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 13717068949900594673U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 14143659432287313765U;
            aOrbiterH = RotL64((aOrbiterH * 17281441046722262917U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 5729546141908425670U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 4297827922736712074U;
            aOrbiterI = RotL64((aOrbiterI * 13631630436759768885U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 829520109395163673U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 11547160328525174295U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4759690159673049775U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 2907177944512117206U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 11100346409065275671U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 17927994356809011637U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 1344592529249949068U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 6470438516791143572U) ^ aNonceWordD;
            aOrbiterC = RotL64((aOrbiterC * 13339390828725370475U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 5217751823741520847U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 5371275223586938039U;
            aOrbiterD = RotL64((aOrbiterD * 12318403075523724125U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 14218103150268532919U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 1367628876596800571U) ^ aNonceWordI;
            aOrbiterE = RotL64((aOrbiterE * 13777531272321533137U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 2372041991018455610U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 9870744274890595581U;
            aOrbiterA = RotL64((aOrbiterA * 12093443117747395585U), 23U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterD, 47U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 57U));
            aIngress = aIngress + (RotL64(aOrbiterE, 40U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 3U));
            aIngress = aIngress + RotL64(aOrbiterC, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((((RotL64(aIngress, 47U) + aOrbiterA) + RotL64(aOrbiterE, 43U)) + aNonceWordN) + aPhaseBWandererUpdateSaltE[((aIndex + 13U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aCross, 14U) + aOrbiterI) + RotL64(aOrbiterD, 11U)) + RotL64(aCarry, 23U)) + aNonceWordL);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 37U) + aOrbiterG) + RotL64(aOrbiterE, 35U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 53U) + aOrbiterK) + RotL64(aOrbiterB, 4U)) + aNonceWordF);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterA, 19U)) + aOrbiterC);
            aWandererF = aWandererF + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterB, 39U)) + aOrbiterD) + RotL64(aCarry, 39U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterC, 23U)) + aOrbiterK) + aNonceWordM);
            aWandererD = aWandererD + ((RotL64(aCross, 29U) + RotL64(aOrbiterH, 29U)) + aOrbiterK);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 22U) + RotL64(aOrbiterH, 54U)) + aOrbiterI) + aPhaseBWandererUpdateSaltC[((aIndex + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 54U));
            aCarry = aCarry + (RotL64(aWandererG, 29U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererE, 11U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererK, 57U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 12433U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneC[((aIndex + 14602U)) & S_BLOCK1], 11U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 14721U)) & S_BLOCK1], 21U) ^ RotL64(aFireLaneC[((aIndex + 8668U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 8370U)) & S_BLOCK1], 28U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 16377U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 14556U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCarry, 28U) ^ RotL64(aPrevious, 43U)) ^ (RotL64(aCross, 11U) + RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterC = ((((aWandererD + RotL64(aIngress, 57U)) + RotL64(aCarry, 39U)) + 17936518874386450467U) + aPhaseBOrbiterAssignSaltF[((aIndex + 7U)) & S_SALT1]) + aNonceWordN;
            aOrbiterI = ((aWandererB + RotL64(aPrevious, 22U)) + RotL64(aCarry, 3U)) + 13722737841589910344U;
            aOrbiterB = (((aWandererF + RotL64(aCross, 51U)) + RotL64(aCarry, 47U)) + 11774969167948715796U) + aNonceWordP;
            aOrbiterF = ((aWandererH + RotL64(aScatter, 3U)) + 3640101505680493777U) + aPhaseBOrbiterAssignSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = (aWandererC + RotL64(aCross, 27U)) + 1369495382725650822U;
            aOrbiterE = (aWandererK + RotL64(aPrevious, 47U)) + 11827310354654653345U;
            aOrbiterA = (aWandererI + RotL64(aIngress, 13U)) + 186037671377175394U;
            aOrbiterK = (aWandererG + RotL64(aScatter, 41U)) + 11428829344234627340U;
            aOrbiterH = (aWandererE + RotL64(aPrevious, 34U)) + 2275016369870029068U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 15471646673734798328U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 12172082573115640145U;
            aOrbiterB = RotL64((aOrbiterB * 9629417882787847753U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 6626736341348283154U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 12220614992483863623U;
            aOrbiterI = RotL64((aOrbiterI * 8137086205714097487U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 13157102324253760215U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 4143587482368093601U;
            aOrbiterA = RotL64((aOrbiterA * 5060677690991506895U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 11007575246013796426U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 11721585930088637162U) ^ aNonceWordH;
            aOrbiterK = RotL64((aOrbiterK * 15009627907125738519U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 5720789204450196217U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterI) ^ 3094696226821431648U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterH = RotL64((aOrbiterH * 4412033981712165541U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 14675830108100986773U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 9444071495289719645U;
            aOrbiterE = RotL64((aOrbiterE * 10983136361953366557U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 5106753847015199956U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 7585421898593510010U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 140996914192351011U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 11746948407655524690U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 16336323220286344483U;
            aOrbiterF = RotL64((aOrbiterF * 6590417628835864497U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 8030445186765781136U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 276034088015165891U;
            aOrbiterD = RotL64((aOrbiterD * 7626025612710225099U), 39U);
            //
            aIngress = RotL64(aOrbiterI, 57U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterB, 18U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 5U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 43U));
            aIngress = aIngress + RotL64(aOrbiterA, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aCross, 51U) + aOrbiterH) + RotL64(aOrbiterD, 13U));
            aWandererI = aWandererI + (((RotL64(aIngress, 13U) + aOrbiterB) + RotL64(aOrbiterK, 19U)) + aNonceWordL);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 44U) + aOrbiterD) + RotL64(aOrbiterB, 3U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 23U) + aOrbiterH) + RotL64(aOrbiterE, 58U)) + RotL64(aCarry, 35U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 29U) + RotL64(aOrbiterI, 43U)) + aOrbiterC) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 37U) + aOrbiterK) + RotL64(aOrbiterD, 47U)) + RotL64(aCarry, 43U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 18U) + RotL64(aOrbiterK, 37U)) + aOrbiterI);
            aWandererK = aWandererK + (((RotL64(aScatter, 57U) + aOrbiterB) + RotL64(aOrbiterF, 24U)) + aPhaseBWandererUpdateSaltA[((aIndex + 25U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 3U) + aOrbiterA) + RotL64(aOrbiterI, 53U)) + aNonceWordB);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 5U));
            aCarry = aCarry + (RotL64(aWandererK, 50U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererB, 23U) ^ aWandererD);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 29U));
            aCarry = aCarry + RotL64(aWandererI, 47U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 21368U)) & S_BLOCK1], 40U) ^ RotL64(aOperationLaneA[((aIndex + 17139U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aOperationLaneB[((aIndex + 17201U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneA[((aIndex + 19716U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24111U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 20469U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 18735U)) & S_BLOCK1], 14U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCross, 20U) ^ RotL64(aPrevious, 39U)) ^ (RotL64(aIngress, 53U) + RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterK = (aWandererF + RotL64(aIngress, 58U)) + 2225397913940961213U;
            aOrbiterB = ((aWandererH + RotL64(aCross, 35U)) + 8342544893601343643U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = (((aWandererA + RotL64(aPrevious, 13U)) + RotL64(aCarry, 19U)) + 162922186381417187U) + aNonceWordM;
            aOrbiterF = ((aWandererE + RotL64(aScatter, 5U)) + 11660218373710972210U) + aNonceWordE;
            aOrbiterH = ((aWandererI + RotL64(aCross, 47U)) + RotL64(aCarry, 11U)) + 14909034764605802354U;
            aOrbiterJ = (((aWandererB + RotL64(aIngress, 41U)) + RotL64(aCarry, 27U)) + 16776955237009701511U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterC = (aWandererJ + RotL64(aScatter, 27U)) + 5834487809188925253U;
            aOrbiterE = (aWandererC + RotL64(aPrevious, 20U)) + 1498492772767040320U;
            aOrbiterI = ((aWandererK + RotL64(aIngress, 51U)) + 4161765458781579617U) + aNonceWordD;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 10511923076962447765U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 8575954471692620021U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 12526744988828982731U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 6536325446331340573U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 1790628986900286346U;
            aOrbiterJ = RotL64((aOrbiterJ * 5262997114200816715U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 2623814807619278590U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 11676970995834706612U;
            aOrbiterB = RotL64((aOrbiterB * 10057461115132434901U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 13836786354224256591U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 6293096163612129260U;
            aOrbiterF = RotL64((aOrbiterF * 8977954126326217153U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 4271144764978661248U) + aNonceWordO;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 15938494256992560202U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 10004841288382726739U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 11038155227307702976U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 12408749795071243930U;
            aOrbiterE = RotL64((aOrbiterE * 5527720475032868855U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 1673665849053496882U) + aNonceWordA;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 12866353361497103629U;
            aOrbiterC = RotL64((aOrbiterC * 6041125499398924871U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 10673935802381580966U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 8946776538955520352U;
            aOrbiterK = RotL64((aOrbiterK * 12293084177712710021U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 16294935203370452805U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 4697759331563852212U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 14407806317275373043U), 47U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterK, 39U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 50U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterI, 43U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterD, 23U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterH, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aPrevious, 3U) + aOrbiterJ) + RotL64(aOrbiterB, 37U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 35U) + RotL64(aOrbiterF, 23U)) + aOrbiterD) + aNonceWordI);
            aWandererE = aWandererE + ((RotL64(aScatter, 39U) + RotL64(aOrbiterJ, 27U)) + aOrbiterH);
            aWandererH = aWandererH ^ ((((RotL64(aCross, 58U) + RotL64(aOrbiterC, 56U)) + aOrbiterB) + aNonceWordN) + aPhaseBWandererUpdateSaltF[((aIndex + 20U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aIngress, 21U) + RotL64(aOrbiterB, 41U)) + aOrbiterE) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 53U) + aOrbiterK) + RotL64(aOrbiterC, 5U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterK, 47U)) + aOrbiterI) + RotL64(aCarry, 47U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 28U) + aOrbiterC) + RotL64(aOrbiterJ, 19U));
            aWandererC = aWandererC + (((RotL64(aScatter, 47U) + aOrbiterD) + RotL64(aOrbiterK, 52U)) + RotL64(aCarry, 21U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 29U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 41U));
            aCarry = aCarry + (RotL64(aWandererH, 60U) ^ aWandererF);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 53U));
            aCarry = aCarry + RotL64(aWandererA, 11U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 28324U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneA[((aIndex + 25404U)) & S_BLOCK1], 51U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 26909U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 31688U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 29582U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31762U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aExpandLaneD[((aIndex + 30045U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCarry, 3U) ^ RotL64(aIngress, 53U)) ^ (RotL64(aPrevious, 20U) + RotL64(aCross, 37U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterJ = (((aWandererG + RotL64(aScatter, 23U)) + RotL64(aCarry, 3U)) + 1364174714924216027U) + aPhaseBOrbiterAssignSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = (aWandererA + RotL64(aIngress, 42U)) + 13561796874229506613U;
            aOrbiterA = (aWandererI + RotL64(aPrevious, 37U)) + 11845572344206238305U;
            aOrbiterE = (((aWandererD + RotL64(aCross, 5U)) + RotL64(aCarry, 43U)) + 15762708240326773763U) + aPhaseBOrbiterAssignSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = (aWandererB + RotL64(aPrevious, 19U)) + 1157119665207900473U;
            aOrbiterK = (aWandererJ + RotL64(aScatter, 29U)) + 6823546624372055260U;
            aOrbiterC = (aWandererC + RotL64(aIngress, 47U)) + 14465564210523945121U;
            aOrbiterG = ((aWandererE + RotL64(aCross, 12U)) + 10667464548080807531U) + aNonceWordN;
            aOrbiterI = (((aWandererH + RotL64(aPrevious, 57U)) + RotL64(aCarry, 27U)) + 13445737493224316575U) + aNonceWordG;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 3009837893785957665U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterJ) ^ 2886920524111083752U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterA = RotL64((aOrbiterA * 15308180928967762543U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 10886177449328249656U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 15067759884678100433U;
            aOrbiterK = RotL64((aOrbiterK * 5724566815989860041U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 18307930462682331536U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 8791864377579255801U;
            aOrbiterE = RotL64((aOrbiterE * 9265158882471421767U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 805797468642992351U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 5743305867058244964U;
            aOrbiterF = RotL64((aOrbiterF * 16263000753351131717U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 17102025528234481273U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 1841579177327486899U;
            aOrbiterC = RotL64((aOrbiterC * 3841603385577825265U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 2189493507896508972U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 18209567010094914374U;
            aOrbiterI = RotL64((aOrbiterI * 3737080408976852351U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 6697069234216868330U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 927471474577415372U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10680760991009199309U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 13155854301197725408U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 1014625081915435892U;
            aOrbiterB = RotL64((aOrbiterB * 11592754232949990435U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 12697209921410914931U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterB) ^ 11555096613655648647U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterG = RotL64((aOrbiterG * 4598821388864997089U), 13U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterG, 43U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 47U));
            aIngress = aIngress + (RotL64(aOrbiterK, 5U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 24U));
            aIngress = aIngress + RotL64(aOrbiterI, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aIngress, 14U) + RotL64(aOrbiterA, 52U)) + aOrbiterC);
            aWandererG = aWandererG + ((((RotL64(aCross, 21U) + RotL64(aOrbiterK, 11U)) + aOrbiterE) + aNonceWordA) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterF, 5U)) + aOrbiterC);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 47U) + aOrbiterC) + RotL64(aOrbiterE, 29U)) + RotL64(aCarry, 39U)) + aNonceWordI);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 27U) + aOrbiterG) + RotL64(aOrbiterJ, 21U)) + aNonceWordP);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 43U) + RotL64(aOrbiterB, 46U)) + aOrbiterC);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterI, 41U)) + aOrbiterA);
            aWandererE = aWandererE + ((((RotL64(aCross, 60U) + aOrbiterE) + RotL64(aOrbiterB, 35U)) + RotL64(aCarry, 5U)) + aPhaseBWandererUpdateSaltC[((aIndex + 13U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 39U) + aOrbiterK) + RotL64(aOrbiterG, 57U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 52U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererG, 35U) ^ aWandererH);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 57U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 19U));
            aCarry = aCarry + RotL64(aWandererD, 12U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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

void TwistExpander_PingPong_Arx::Seed_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xEDDFAAAFD895C72FULL + 0x9D2001C59E049354ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xFFC853C690EBB215ULL + 0xCFCB6549C538F224ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x97EB5608B1211101ULL + 0x82DD65CA2E571256ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x9FBCE65544EA45C9ULL + 0xD3C41046718390F9ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xF6CEA309B0FD6EE1ULL + 0xE762FA31DC2D5EC2ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xB21D36870535F447ULL + 0xF46EC9E426BEE6E7ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x8838B040EAAD9F55ULL + 0xB4EA0910A458E343ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xA241E454952F9899ULL + 0x98893BB8A1951F4CULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xB87800FE54DEE2CDULL + 0xE16061D72ED65AFFULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xC4E74A15277C4CB9ULL + 0xF658FD4150A1FA98ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x8E682D0B82462173ULL + 0x9D6CDB2A2392C3D2ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xD96B0E98CF6B9703ULL + 0xF0D9EE4C89F51C2CULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xE14E2C3FD544BD4FULL + 0xF94DC1C3025BB318ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xBDE6BBE2FF35E7B5ULL + 0xA022D1A7AC6466D0ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x99B92FC2CA1E205BULL + 0xBBBAF88FA1C59280ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xE437BC0722B54857ULL + 0xB10589D2A00B170AULL);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 3365U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneB[((aIndex + 1802U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 3049U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 3834U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 5167U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 4287U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCarry, 56U) ^ RotL64(aIngress, 21U)) ^ (RotL64(aCross, 5U) + RotL64(aPrevious, 43U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterK = ((aWandererH + RotL64(aScatter, 11U)) + RotL64(aCarry, 19U)) + 4752759164691497960U;
            aOrbiterC = ((aWandererD + RotL64(aIngress, 19U)) + 12088872623537639782U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterJ = ((aWandererG + RotL64(aPrevious, 53U)) + 3734943577379734227U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterG = (aWandererK + RotL64(aCross, 3U)) + 8854778183012444234U;
            aOrbiterA = ((aWandererB + RotL64(aPrevious, 40U)) + 16948373492893967275U) + aNonceWordM;
            aOrbiterE = ((aWandererF + RotL64(aCross, 27U)) + RotL64(aCarry, 53U)) + 7962415690046184385U;
            aOrbiterH = (((aWandererC + RotL64(aIngress, 47U)) + RotL64(aCarry, 41U)) + 1872682375669714454U) + aNonceWordH;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 7776801806943853566U) + aNonceWordD;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 16665439117257230732U;
            aOrbiterJ = RotL64((aOrbiterJ * 6866375628213114965U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 11088186766134265676U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 10850237991780969350U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7547414856143095121U), 21U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterE) + 6464817712131305812U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordN;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 244557182884209844U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2394270354887582889U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 13261563971157415841U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 2323811103717827362U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11483723582415081925U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 12338803568475493422U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 2811342930111104982U;
            aOrbiterK = RotL64((aOrbiterK * 5020981755203607757U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 5554497011738996057U) + aNonceWordI;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 12712169745460598698U;
            aOrbiterG = RotL64((aOrbiterG * 1985586486150377769U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 17415058661427002973U) + aNonceWordF;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 9430421222715343818U;
            aOrbiterE = RotL64((aOrbiterE * 10321140659099470811U), 43U);
            //
            aIngress = RotL64(aOrbiterK, 3U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterE, 23U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterA, 50U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterG, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aIngress, 29U) + aOrbiterE) + RotL64(aOrbiterK, 29U)) + aNonceWordC);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterE, 43U)) + aOrbiterG) + aNonceWordE);
            aWandererB = aWandererB + ((((RotL64(aScatter, 53U) + aOrbiterG) + RotL64(aOrbiterC, 51U)) + aNonceWordO) + aPhaseDWandererUpdateSaltF[((aIndex + 23U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aCross, 41U) + RotL64(aOrbiterJ, 12U)) + aOrbiterA) + aNonceWordG);
            aWandererD = aWandererD + ((((RotL64(aIngress, 47U) + aOrbiterH) + RotL64(aOrbiterA, 37U)) + RotL64(aCarry, 53U)) + aPhaseDWandererUpdateSaltB[((aIndex + 28U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterA, 3U)) + aOrbiterG);
            aWandererK = aWandererK + (((RotL64(aCross, 12U) + RotL64(aOrbiterJ, 57U)) + aOrbiterK) + RotL64(aCarry, 13U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 5U));
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererC, 53U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererF, 30U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 10475U)) & S_BLOCK1], 28U) ^ RotL64(aExpandLaneC[((aIndex + 8949U)) & S_BLOCK1], 19U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 10329U)) & S_BLOCK1], 57U) ^ RotL64(aFireLaneC[((aIndex + 9142U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 8316U)) & S_BLOCK1], 30U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 8534U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 8214U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aPrevious, 57U) ^ RotL64(aCarry, 44U)) + (RotL64(aIngress, 23U) + RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterC = ((aWandererK + RotL64(aScatter, 39U)) + 12809562813316740345U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = (((aWandererJ + RotL64(aPrevious, 53U)) + RotL64(aCarry, 27U)) + 17084212535326321199U) + aNonceWordM;
            aOrbiterE = ((aWandererB + RotL64(aIngress, 13U)) + 16074921689983846769U) + aNonceWordD;
            aOrbiterG = (((aWandererA + RotL64(aCross, 47U)) + RotL64(aCarry, 3U)) + 14027986153007120145U) + aNonceWordJ;
            aOrbiterH = ((aWandererF + RotL64(aScatter, 60U)) + RotL64(aCarry, 41U)) + 7633455951809250227U;
            aOrbiterI = (((aWandererG + RotL64(aCross, 3U)) + 340989348513370174U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordB;
            aOrbiterK = (aWandererC + RotL64(aIngress, 23U)) + 5307820377645020116U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 5605285015771527274U) + aNonceWordI;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 5293500434746182790U;
            aOrbiterE = RotL64((aOrbiterE * 17674669610895537063U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 7263156475892261811U) + aNonceWordN;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 10672879570907433005U;
            aOrbiterB = RotL64((aOrbiterB * 2506338667179450741U), 53U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 16659226780900986107U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 9774892622769850665U) ^ aNonceWordK;
            aOrbiterI = RotL64((aOrbiterI * 7487477727543183211U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 10728057184108279042U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 5032485856947407217U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 16651577903809154285U), 21U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 14642241075374862345U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 8386481273395203518U;
            aOrbiterG = RotL64((aOrbiterG * 11649977733867003445U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 2874153265304098104U) + aNonceWordH;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 11519900149177261000U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2010158758971864505U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 8885690878540115768U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 4482143389870987714U;
            aOrbiterH = RotL64((aOrbiterH * 7105332459437434281U), 41U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterG, 4U);
            aIngress = aIngress + (RotL64(aOrbiterC, 27U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 35U));
            aIngress = aIngress + RotL64(aOrbiterB, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aIngress, 35U) + RotL64(aOrbiterK, 36U)) + aOrbiterE) + aNonceWordL);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 27U) + aOrbiterH) + RotL64(aOrbiterE, 57U)) + aPhaseDWandererUpdateSaltE[((aIndex + 23U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aScatter, 50U) + aOrbiterC) + RotL64(aOrbiterB, 3U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterB, 11U)) + aOrbiterI);
            aWandererB = aWandererB + ((((RotL64(aIngress, 43U) + aOrbiterG) + RotL64(aOrbiterI, 27U)) + RotL64(aCarry, 11U)) + aNonceWordE);
            aWandererF = aWandererF ^ (((RotL64(aCross, 11U) + aOrbiterI) + RotL64(aOrbiterH, 43U)) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 57U) + RotL64(aOrbiterG, 51U)) + aOrbiterH) + RotL64(aCarry, 39U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 41U) ^ aWandererB);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 37U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 53U));
            aCarry = aCarry + RotL64(aWandererK, 30U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 12359U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneA[((aIndex + 12752U)) & S_BLOCK1], 36U));
            aIngress ^= RotL64(aOperationLaneA[((aIndex + 15019U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 14599U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneC[((aIndex + 12270U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCross, 18U) + RotL64(aPrevious, 39U)) ^ (RotL64(aCarry, 5U) ^ RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterA = ((aWandererI + RotL64(aPrevious, 23U)) + 3339283916456813609U) + aNonceWordP;
            aOrbiterI = ((aWandererK + RotL64(aCross, 37U)) + 11339086426180649584U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterB = ((aWandererH + RotL64(aScatter, 57U)) + RotL64(aCarry, 3U)) + 16819191669329316585U;
            aOrbiterC = (aWandererF + RotL64(aIngress, 51U)) + 8361916937762630725U;
            aOrbiterJ = ((aWandererD + RotL64(aPrevious, 14U)) + 18031328374429899857U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterE = (((aWandererA + RotL64(aIngress, 43U)) + RotL64(aCarry, 41U)) + 18261756894092897276U) + aNonceWordH;
            aOrbiterG = (((aWandererJ + RotL64(aCross, 29U)) + RotL64(aCarry, 23U)) + 4250319792907645666U) + aNonceWordM;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 1492411503643460886U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 17369549067879344180U) ^ aNonceWordI;
            aOrbiterB = RotL64((aOrbiterB * 2947354306696216579U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 7301713524358676722U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 2985193736033012535U;
            aOrbiterA = RotL64((aOrbiterA * 7473297294949338265U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 14086975808140927408U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 10390516547834639800U;
            aOrbiterE = RotL64((aOrbiterE * 11441293212275890819U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 18205555540941493267U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 16967799565443938873U;
            aOrbiterI = RotL64((aOrbiterI * 3009081009044782443U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 9209505304067579944U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterG = (((aOrbiterG ^ aOrbiterB) ^ 3522631966146762306U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterG = RotL64((aOrbiterG * 3441982898533162599U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 8811497120829041188U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 14707301680850257294U;
            aOrbiterJ = RotL64((aOrbiterJ * 11383709499376464085U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 10080595991787801029U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterE) ^ 6822892187784299166U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterC = RotL64((aOrbiterC * 7417016898027778287U), 5U);
            //
            aIngress = RotL64(aOrbiterG, 21U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterI, 58U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 47U));
            aIngress = aIngress + RotL64(aOrbiterE, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aIngress, 19U) + RotL64(aOrbiterI, 29U)) + aOrbiterB) + aNonceWordD);
            aWandererF = aWandererF + (((((RotL64(aPrevious, 57U) + aOrbiterI) + RotL64(aOrbiterJ, 35U)) + RotL64(aCarry, 29U)) + aNonceWordE) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 3U) + aOrbiterC) + RotL64(aOrbiterE, 18U)) + aNonceWordL);
            aWandererJ = aWandererJ + (((((RotL64(aCross, 27U) + RotL64(aOrbiterC, 11U)) + aOrbiterJ) + RotL64(aCarry, 41U)) + aNonceWordK) + aPhaseDWandererUpdateSaltC[((aIndex + 18U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 42U) + RotL64(aOrbiterA, 51U)) + aOrbiterJ);
            aWandererA = aWandererA + ((RotL64(aCross, 13U) + aOrbiterA) + RotL64(aOrbiterC, 3U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterC, 41U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 35U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 3U));
            aCarry = aCarry + (RotL64(aWandererH, 50U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererK, 29U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 19996U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneA[((aIndex + 18102U)) & S_BLOCK1], 26U));
            aIngress ^= RotL64(aOperationLaneB[((aIndex + 18917U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 19812U)) & S_BLOCK1], 30U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 19767U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCross, 11U) ^ RotL64(aIngress, 56U)) ^ (RotL64(aPrevious, 27U) + RotL64(aCarry, 43U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterF = (aWandererA + RotL64(aCross, 37U)) + 3105313968748067810U;
            aOrbiterA = ((aWandererD + RotL64(aPrevious, 29U)) + RotL64(aCarry, 43U)) + 9977249451119627064U;
            aOrbiterD = ((aWandererG + RotL64(aScatter, 13U)) + RotL64(aCarry, 21U)) + 17941392803495349366U;
            aOrbiterJ = ((((aWandererB + RotL64(aIngress, 23U)) + RotL64(aCarry, 57U)) + 4279533326705471133U) + aPhaseDOrbiterAssignSaltB[((aIndex + 29U)) & S_SALT1]) + aNonceWordA;
            aOrbiterE = (((aWandererF + RotL64(aPrevious, 3U)) + 13983828966811580039U) + aPhaseDOrbiterAssignSaltC[((aIndex + 19U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterB = ((aWandererI + RotL64(aCross, 51U)) + 3983490984234810378U) + aNonceWordI;
            aOrbiterI = ((aWandererK + RotL64(aScatter, 60U)) + 308786542215259956U) + aNonceWordM;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 8443607695364427037U) + aNonceWordH;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 14939626441464340668U;
            aOrbiterD = RotL64((aOrbiterD * 16793255020331774983U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 9350693577306121110U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 1717071159396961752U;
            aOrbiterE = RotL64((aOrbiterE * 11062480662625054525U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 15911765265202100610U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 14898546272333182767U;
            aOrbiterI = RotL64((aOrbiterI * 2674900543810733067U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 3560903518513465868U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 5367062725726860234U;
            aOrbiterA = RotL64((aOrbiterA * 8521908836601319553U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 15233321480618877327U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 9288449812290126074U;
            aOrbiterB = RotL64((aOrbiterB * 6815298520404038519U), 5U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterD) + 5504840529511585676U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1]) + aNonceWordD;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterA) ^ 6825598386801620046U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterJ = RotL64((aOrbiterJ * 11666542445846250077U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 6433024450721339470U) + aNonceWordG;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 97934156644929458U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8630530773006923215U), 21U);
            //
            aIngress = RotL64(aOrbiterJ, 35U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 5U));
            aIngress = aIngress + (RotL64(aOrbiterI, 19U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterA, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aPrevious, 19U) + aOrbiterA) + RotL64(aOrbiterJ, 29U)) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 26U) + RotL64(aOrbiterE, 35U)) + aOrbiterJ) + aNonceWordF);
            aWandererB = aWandererB + ((((RotL64(aCross, 37U) + RotL64(aOrbiterI, 3U)) + aOrbiterB) + RotL64(aCarry, 13U)) + aNonceWordC);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 3U) + aOrbiterD) + RotL64(aOrbiterA, 51U));
            aWandererI = aWandererI + (((((RotL64(aIngress, 53U) + RotL64(aOrbiterA, 19U)) + aOrbiterI) + RotL64(aCarry, 47U)) + aNonceWordE) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 47U) + RotL64(aOrbiterE, 42U)) + aOrbiterB) + aNonceWordP);
            aWandererA = aWandererA + ((RotL64(aCross, 11U) + RotL64(aOrbiterI, 13U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererD, 35U) ^ aWandererA);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 47U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 21U));
            aCarry = aCarry + RotL64(aWandererB, 52U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 23948U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneB[((aIndex + 22589U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 25825U)) & S_BLOCK1], 38U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 26559U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneA[((aIndex + 26313U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aPrevious, 44U) ^ RotL64(aCross, 5U)) + (RotL64(aCarry, 57U) + RotL64(aIngress, 27U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterA = (((aWandererE + RotL64(aCross, 35U)) + RotL64(aCarry, 37U)) + 3917730204724097072U) + aNonceWordP;
            aOrbiterE = (((aWandererC + RotL64(aIngress, 12U)) + RotL64(aCarry, 23U)) + 1874642340716212824U) + aNonceWordB;
            aOrbiterB = ((aWandererH + RotL64(aPrevious, 27U)) + 6900165757434854160U) + aPhaseDOrbiterAssignSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = ((aWandererJ + RotL64(aScatter, 41U)) + 12750946097023807161U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterD = (aWandererI + RotL64(aPrevious, 47U)) + 6563216048479513594U;
            aOrbiterG = (aWandererA + RotL64(aIngress, 21U)) + 14960240191349450795U;
            aOrbiterC = ((aWandererK + RotL64(aScatter, 3U)) + RotL64(aCarry, 51U)) + 16306180275951788289U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 6502066618271045547U) + aNonceWordK;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 6219852857850888738U;
            aOrbiterB = RotL64((aOrbiterB * 10892297250334325283U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 2272931312452845850U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 3028929882263199463U) ^ aNonceWordO;
            aOrbiterD = RotL64((aOrbiterD * 11005324285856805069U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 6067393030073568112U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 10094809900437037258U;
            aOrbiterI = RotL64((aOrbiterI * 18095564940730322769U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 5962414178157074575U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 15755563045799129417U;
            aOrbiterC = RotL64((aOrbiterC * 3692603590609922031U), 47U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterD) + 6321455513889880590U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1]) + aNonceWordM;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 1197435601998121700U;
            aOrbiterA = RotL64((aOrbiterA * 17693996266260557625U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 12496949381666299968U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 6357070235648527030U;
            aOrbiterG = RotL64((aOrbiterG * 2931486644220862433U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 8423760160877540210U) + aNonceWordE;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 8090246492554850768U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 2949407491181921633U), 21U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterE, 13U);
            aIngress = aIngress + (RotL64(aOrbiterA, 27U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterB, 54U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterC, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aIngress, 13U) + RotL64(aOrbiterD, 19U)) + aOrbiterG) + aNonceWordJ);
            aWandererE = aWandererE + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterG, 5U)) + aOrbiterI) + aNonceWordI);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 57U) + aOrbiterD) + RotL64(aOrbiterC, 50U));
            aWandererK = aWandererK + ((((RotL64(aScatter, 3U) + RotL64(aOrbiterB, 57U)) + aOrbiterD) + RotL64(aCarry, 53U)) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 46U) + RotL64(aOrbiterB, 13U)) + aOrbiterA) + aNonceWordN);
            aWandererI = aWandererI + (((((RotL64(aCross, 29U) + RotL64(aOrbiterI, 35U)) + aOrbiterD) + RotL64(aCarry, 29U)) + aNonceWordD) + aPhaseDWandererUpdateSaltE[((aIndex + 28U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 21U) + aOrbiterE) + RotL64(aOrbiterA, 41U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 19U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererK, 47U) ^ aWandererC);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 30U));
            aCarry = aCarry + RotL64(aWandererJ, 13U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aInvestLaneC[((aIndex + 27513U)) & S_BLOCK1], 40U) ^ RotL64(aInvestLaneA[((aIndex + 29165U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aOperationLaneD[((aIndex + 30650U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 29335U)) & S_BLOCK1], 24U) ^ RotL64(aExpandLaneB[((aIndex + 32412U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aIngress, 23U) + RotL64(aCarry, 38U)) ^ (RotL64(aPrevious, 51U) ^ RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterJ = (aWandererG + RotL64(aPrevious, 43U)) + 15920462086654025436U;
            aOrbiterI = ((aWandererF + RotL64(aCross, 3U)) + 487844076858004017U) + aPhaseDOrbiterAssignSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = ((aWandererK + RotL64(aIngress, 21U)) + 14502883786442630566U) + aNonceWordC;
            aOrbiterE = (((aWandererC + RotL64(aScatter, 35U)) + RotL64(aCarry, 51U)) + 3787107318658233674U) + aNonceWordD;
            aOrbiterK = ((((aWandererA + RotL64(aCross, 28U)) + RotL64(aCarry, 3U)) + 12548777544693755491U) + aPhaseDOrbiterAssignSaltF[((aIndex + 5U)) & S_SALT1]) + aNonceWordE;
            aOrbiterG = (((aWandererI + RotL64(aPrevious, 53U)) + RotL64(aCarry, 21U)) + 4907309444075181683U) + aNonceWordA;
            aOrbiterB = (aWandererH + RotL64(aIngress, 11U)) + 18342396700266492072U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 13503051997624242670U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 17845742460521374571U;
            aOrbiterF = RotL64((aOrbiterF * 1366356786138085155U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 8640887211877858169U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 5273913123709097537U) ^ aNonceWordI;
            aOrbiterK = RotL64((aOrbiterK * 1661149444148461791U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 17756844173695563883U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 6713055830729302951U;
            aOrbiterG = RotL64((aOrbiterG * 2832836748513174311U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 5106468334224035972U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 10228769728713526172U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 9760310686414358435U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 7687649520668883142U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 7757480627354711605U;
            aOrbiterE = RotL64((aOrbiterE * 7222553727737349209U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 10876291698508634557U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 8149278085586014186U;
            aOrbiterI = RotL64((aOrbiterI * 8577133863470695381U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 15592893988925610485U) + aNonceWordK;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 8639028256640537165U;
            aOrbiterB = RotL64((aOrbiterB * 1880655276432963955U), 57U);
            //
            aIngress = RotL64(aOrbiterE, 21U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterI, 50U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 13U));
            aIngress = aIngress + RotL64(aOrbiterG, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aIngress, 27U) + RotL64(aOrbiterB, 42U)) + aOrbiterG);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 21U) + aOrbiterF) + RotL64(aOrbiterE, 19U)) + aNonceWordN);
            aWandererI = aWandererI + (((RotL64(aScatter, 11U) + RotL64(aOrbiterK, 11U)) + aOrbiterG) + aPhaseDWandererUpdateSaltC[((aIndex + 20U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterF, 29U)) + aOrbiterI) + aPhaseDWandererUpdateSaltA[((aIndex + 28U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aIngress, 43U) + RotL64(aOrbiterB, 53U)) + aOrbiterK) + RotL64(aCarry, 57U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 35U) + aOrbiterJ) + RotL64(aOrbiterF, 35U)) + aNonceWordO);
            aWandererG = aWandererG + (((RotL64(aPrevious, 56U) + aOrbiterB) + RotL64(aOrbiterI, 5U)) + RotL64(aCarry, 13U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 20U) ^ aWandererI);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 57U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 27U));
            aCarry = aCarry + RotL64(aWandererC, 5U);
            aCarry = aCarry + RotL64(aIngress, 52U);
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

void TwistExpander_PingPong_Arx::Seed_E(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xE75095FAFE463CE7ULL + 0x9762E399F36FEE33ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x9442635A38469355ULL + 0xE5D71A1D3FCEEB78ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xA227BBE4037EB8EBULL + 0xD338D43A77D9974AULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xE8ABCDE187B20A15ULL + 0xE2C16B2AC98729A0ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xF890F07ABF935F93ULL + 0x9AB470F261833BF1ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xF051527D3986CE91ULL + 0x9BCFEE718FECEEF1ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xAC3A09F5183EB961ULL + 0xFD472229395FDFC1ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xEAEE1A0902008563ULL + 0xCA580D496ABA8EA8ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xBAAD1CC76E9E8C5DULL + 0x87184C43007F992DULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xB0F17F155D950CF5ULL + 0xBB285BCFF02C4B39ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xBF4BC6B3D6450D01ULL + 0xD4A96786787E98B5ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xD46B5A2B5CED0619ULL + 0xB8A93154ADF5FCF3ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xE618DF99E41794F9ULL + 0xBF41A64282B31E7CULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xA01C09D724B0A26FULL + 0xB57AAA3796A9D1C1ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xD2DED87756C1BF85ULL + 0xB37F2C0FF0F07CA5ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0x911A123655C80B3DULL + 0x803FA597BF42973CULL);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 3804U)) & S_BLOCK1], 11U) ^ RotL64(aInvestLaneB[((aIndex + 5136U)) & S_BLOCK1], 56U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 3803U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 4502U)) & S_BLOCK1], 39U) ^ RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 4760U)) & S_BLOCK1], 22U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 3778U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCarry, 6U) + RotL64(aIngress, 27U)) + (RotL64(aPrevious, 41U) ^ RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterI = ((aWandererI + RotL64(aPrevious, 39U)) + 5576732410244514238U) + aNonceWordP;
            aOrbiterC = (aWandererE + RotL64(aCross, 56U)) + 2833808925935929629U;
            aOrbiterJ = (aWandererK + RotL64(aIngress, 3U)) + 3670188682914544792U;
            aOrbiterB = ((aWandererB + RotL64(aScatter, 29U)) + RotL64(aCarry, 35U)) + 15759072378887814995U;
            aOrbiterG = (((aWandererH + RotL64(aCross, 23U)) + 13934007231137439994U) + aPhaseEOrbiterAssignSaltC[((aIndex + 19U)) & S_SALT1]) + aNonceWordC;
            aOrbiterK = ((aWandererJ + RotL64(aIngress, 42U)) + RotL64(aCarry, 53U)) + 11022225696007690512U;
            aOrbiterF = (aWandererD + RotL64(aPrevious, 53U)) + 16989177104453635790U;
            aOrbiterA = (aWandererA + RotL64(aScatter, 35U)) + 9256930045263527091U;
            aOrbiterH = ((aWandererG + RotL64(aCross, 37U)) + RotL64(aCarry, 3U)) + 17788596104417068290U;
            aOrbiterD = ((aWandererC + RotL64(aScatter, 27U)) + 17044369456673337625U) + aPhaseEOrbiterAssignSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterE = (aWandererF + RotL64(aIngress, 51U)) + 1310908395523250343U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 12067065689034065422U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 15130844248737512262U) ^ aNonceWordE;
            aOrbiterJ = RotL64((aOrbiterJ * 9409499577465934107U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 14532689204495587494U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 8198147292120244178U;
            aOrbiterK = RotL64((aOrbiterK * 1418356389507740991U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 5485494458627163347U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 10830008207150307611U;
            aOrbiterC = RotL64((aOrbiterC * 6526039534042499457U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 17770065502486618029U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 6397859353395335459U;
            aOrbiterG = RotL64((aOrbiterG * 14286997752368893825U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 5128700697381508319U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 7103394110057060499U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5053680689949149633U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 16024401282261796979U) + aNonceWordO;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 12818445221897253410U;
            aOrbiterD = RotL64((aOrbiterD * 11450004517784155405U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 13386978409145916350U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 16740821954556699503U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 5376430209628515105U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 313978038530994953U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 1355733685461795345U;
            aOrbiterE = RotL64((aOrbiterE * 15955927322082619735U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 12590581077253956064U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 2298195367575496005U) ^ aNonceWordA;
            aOrbiterB = RotL64((aOrbiterB * 17512801361187006363U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 11847450675712272468U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 5914296379577670282U) ^ aNonceWordD;
            aOrbiterI = RotL64((aOrbiterI * 14574813500616811367U), 23U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 16901317262621287065U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 5576732410244514238U;
            aOrbiterA = RotL64((aOrbiterA * 4514943876091531567U), 57U);
            //
            aIngress = RotL64(aOrbiterI, 26U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 23U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 35U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 5U));
            aIngress = aIngress + (RotL64(aOrbiterD, 19U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterF, 54U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 60U) + RotL64(aOrbiterC, 19U)) + aOrbiterG);
            aWandererD = aWandererD + ((RotL64(aCross, 41U) + RotL64(aOrbiterJ, 58U)) + aOrbiterH);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterG, 5U)) + aOrbiterI);
            aWandererK = aWandererK + (((RotL64(aScatter, 21U) + aOrbiterE) + RotL64(aOrbiterK, 23U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 37U) + aOrbiterH) + RotL64(aOrbiterF, 39U));
            aWandererC = aWandererC + ((RotL64(aIngress, 57U) + RotL64(aOrbiterC, 43U)) + aOrbiterD);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 53U) + aOrbiterA) + RotL64(aOrbiterK, 41U)) + aNonceWordB);
            aWandererF = aWandererF + (((RotL64(aPrevious, 12U) + RotL64(aOrbiterK, 26U)) + aOrbiterF) + RotL64(aCarry, 13U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterE, 29U)) + aOrbiterI);
            aWandererG = aWandererG + ((((RotL64(aIngress, 51U) + RotL64(aOrbiterI, 11U)) + aOrbiterJ) + RotL64(aCarry, 53U)) + aNonceWordG);
            aWandererJ = aWandererJ ^ ((((RotL64(aPrevious, 39U) + RotL64(aOrbiterB, 3U)) + aOrbiterF) + aNonceWordI) + aPhaseEWandererUpdateSaltF[((aIndex + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 10U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererH, 13U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererD, 57U) ^ aWandererA);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 51U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 27U));
            aCarry = aCarry + RotL64(aWandererJ, 19U);
            aCarry = aCarry + RotL64(aIngress, 48U);
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
            aIngress = (RotL64(aSnowLaneA[((aIndex + 7322U)) & S_BLOCK1], 3U) ^ RotL64(aInvestLaneC[((aIndex + 6419U)) & S_BLOCK1], 57U));
            aIngress ^= (RotL64(aInvestLaneD[((aIndex + 10879U)) & S_BLOCK1], 40U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 7421U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 5917U)) & S_BLOCK1], 43U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 8828U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 6232U)) & S_BLOCK1], 34U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCross, 29U) + RotL64(aPrevious, 13U)) ^ (RotL64(aIngress, 58U) + RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterH = (((aWandererJ + RotL64(aIngress, 19U)) + RotL64(aCarry, 51U)) + 4773124477323378268U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = (aWandererH + RotL64(aPrevious, 27U)) + 16848723289435796005U;
            aOrbiterJ = (aWandererA + RotL64(aScatter, 29U)) + 13846642134917107058U;
            aOrbiterI = ((aWandererI + RotL64(aCross, 23U)) + 6472057872482789939U) + aNonceWordE;
            aOrbiterB = (((aWandererF + RotL64(aPrevious, 60U)) + RotL64(aCarry, 23U)) + 2747019500690707226U) + aNonceWordP;
            aOrbiterG = ((aWandererE + RotL64(aCross, 41U)) + RotL64(aCarry, 27U)) + 9003965289739733880U;
            aOrbiterA = (aWandererG + RotL64(aScatter, 5U)) + 3013390651936257377U;
            aOrbiterC = ((aWandererB + RotL64(aIngress, 57U)) + 3331004709895625067U) + aNonceWordB;
            aOrbiterD = (((aWandererD + RotL64(aPrevious, 46U)) + 15355010435553517129U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordL;
            aOrbiterK = (aWandererK + RotL64(aScatter, 39U)) + 7709870658004280052U;
            aOrbiterE = (aWandererC + RotL64(aCross, 35U)) + 13568728443963926564U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 12409548853419307131U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 969183352023661537U;
            aOrbiterJ = RotL64((aOrbiterJ * 5549220554838837145U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 15370309834426476775U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 3896803894396631184U) ^ aNonceWordH;
            aOrbiterB = RotL64((aOrbiterB * 11018830202891911603U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 10848873633291935766U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 12885336509190543440U;
            aOrbiterC = RotL64((aOrbiterC * 1487357252619221365U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 8252290890093788010U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 9201553615601641350U;
            aOrbiterG = RotL64((aOrbiterG * 420321130559162915U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 14014209645503188472U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 4015071464301844550U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 17444195018239904971U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 16173085647514027347U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 16916627014974363360U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7699587344277490953U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 1591680303404522110U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 16499606051269327916U) ^ aNonceWordO;
            aOrbiterF = RotL64((aOrbiterF * 814405848002794813U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 6932673635509444619U) + aNonceWordD;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 8745681160108707944U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 14565255558668084787U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 10387263947888920455U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 2553335462317280031U;
            aOrbiterE = RotL64((aOrbiterE * 7253573275397985211U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 17449861295444216249U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterB) ^ 15716408844914738774U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterH = RotL64((aOrbiterH * 10132631423215542589U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 16974370193820578179U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 4773124477323378268U;
            aOrbiterA = RotL64((aOrbiterA * 8982190762960590543U), 39U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterH, 51U);
            aIngress = aIngress + (RotL64(aOrbiterA, 42U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterK, 5U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 53U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 35U));
            aIngress = aIngress + RotL64(aOrbiterF, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 57U) + aOrbiterH) + RotL64(aOrbiterG, 23U));
            aWandererE = aWandererE + (((RotL64(aScatter, 23U) + aOrbiterK) + RotL64(aOrbiterE, 27U)) + aNonceWordC);
            aWandererF = aWandererF ^ ((RotL64(aCross, 48U) + RotL64(aOrbiterD, 47U)) + aOrbiterF);
            aWandererI = aWandererI + (((RotL64(aIngress, 5U) + RotL64(aOrbiterK, 50U)) + aOrbiterI) + RotL64(aCarry, 47U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 39U) + aOrbiterE) + RotL64(aOrbiterG, 35U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 19U) + RotL64(aOrbiterA, 37U)) + aOrbiterB);
            aWandererC = aWandererC ^ ((RotL64(aCross, 13U) + aOrbiterI) + RotL64(aOrbiterA, 43U));
            aWandererA = aWandererA + (((RotL64(aIngress, 29U) + aOrbiterJ) + RotL64(aOrbiterC, 3U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterK, 13U)) + aOrbiterC);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 51U) + aOrbiterD) + RotL64(aOrbiterJ, 30U)) + RotL64(aCarry, 53U)) + aNonceWordG);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 10U) + RotL64(aOrbiterJ, 5U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 37U));
            aCarry = aCarry + (RotL64(aWandererD, 23U) ^ aWandererE);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 60U));
            aCarry = aCarry + (RotL64(aWandererH, 51U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererJ, 5U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererC, 35U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = (RotL64(aSnowLaneB[((aIndex + 13788U)) & S_BLOCK1], 3U) ^ RotL64(aInvestLaneA[((aIndex + 11684U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 14228U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 12217U)) & S_BLOCK1], 37U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 15301U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aIngress, 37U) ^ RotL64(aCarry, 57U)) ^ (RotL64(aPrevious, 22U) + RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterK = ((aWandererH + RotL64(aCross, 46U)) + 15188686795415908074U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterB = (aWandererE + RotL64(aScatter, 57U)) + 17310049041983079779U;
            aOrbiterF = (aWandererI + RotL64(aIngress, 41U)) + 8246925977992441471U;
            aOrbiterG = (aWandererC + RotL64(aPrevious, 19U)) + 8644260919918112781U;
            aOrbiterD = ((aWandererD + RotL64(aIngress, 13U)) + 13401663736874819483U) + aNonceWordO;
            aOrbiterH = ((aWandererK + RotL64(aCross, 43U)) + 7940358935238314973U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = ((aWandererJ + RotL64(aScatter, 29U)) + RotL64(aCarry, 57U)) + 13278990328548007839U;
            aOrbiterA = ((aWandererB + RotL64(aPrevious, 37U)) + 11346868298353840706U) + aNonceWordP;
            aOrbiterC = ((aWandererF + RotL64(aIngress, 27U)) + RotL64(aCarry, 35U)) + 2374077904806833579U;
            aOrbiterE = ((aWandererA + RotL64(aCross, 60U)) + RotL64(aCarry, 39U)) + 6978903378645019166U;
            aOrbiterI = ((aWandererG + RotL64(aPrevious, 21U)) + 11951633297870965212U) + aNonceWordH;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 17398460995357409673U) + aNonceWordN;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 1215437945597836770U;
            aOrbiterF = RotL64((aOrbiterF * 9322970054123481621U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 1878751468043972239U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 5343002808239712390U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 11878640995447558811U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 9884918450053276861U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 15894599082080422550U) ^ aNonceWordM;
            aOrbiterA = RotL64((aOrbiterA * 8359936745539546131U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 13917339232771145459U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 18101134009493720683U;
            aOrbiterC = RotL64((aOrbiterC * 15835859435306756387U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 3830086372356903769U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 15894394599564584010U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 9513921913446609263U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 5127590955274245812U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 9410946933309720054U;
            aOrbiterI = RotL64((aOrbiterI * 14507476989423060561U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 15544384157294987085U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 998801294460434123U;
            aOrbiterJ = RotL64((aOrbiterJ * 5946968142746472745U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 16442095194965452163U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 14294936349037516932U;
            aOrbiterK = RotL64((aOrbiterK * 14655345374740882581U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 16680659892463349201U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 10921918150041635666U;
            aOrbiterB = RotL64((aOrbiterB * 2908474941036821745U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 15350264522133299871U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 16413848767507968239U;
            aOrbiterD = RotL64((aOrbiterD * 10226942289998651355U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 11963105565077056299U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 15188686795415908074U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 13002484121826831091U), 37U);
            //
            aIngress = RotL64(aOrbiterG, 5U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 52U));
            aIngress = aIngress + (RotL64(aOrbiterH, 3U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 23U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 27U));
            aIngress = aIngress + RotL64(aOrbiterB, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aIngress, 13U) + aOrbiterH) + RotL64(aOrbiterC, 3U)) + RotL64(aCarry, 27U)) + aNonceWordJ);
            aWandererB = aWandererB ^ ((RotL64(aCross, 22U) + aOrbiterC) + RotL64(aOrbiterB, 57U));
            aWandererH = aWandererH + ((((RotL64(aScatter, 3U) + aOrbiterE) + RotL64(aOrbiterF, 46U)) + aNonceWordA) + aPhaseEWandererUpdateSaltB[((aIndex + 29U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 43U) + RotL64(aOrbiterA, 19U)) + aOrbiterI) + aNonceWordF);
            aWandererF = aWandererF + ((RotL64(aScatter, 19U) + RotL64(aOrbiterF, 37U)) + aOrbiterK);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterJ, 5U)) + aOrbiterK);
            aWandererC = aWandererC + (((RotL64(aPrevious, 27U) + aOrbiterC) + RotL64(aOrbiterK, 27U)) + RotL64(aCarry, 53U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 57U) + aOrbiterG) + RotL64(aOrbiterB, 39U));
            aWandererG = aWandererG + ((RotL64(aPrevious, 60U) + RotL64(aOrbiterA, 53U)) + aOrbiterK);
            aWandererD = aWandererD ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterE, 60U)) + aOrbiterH);
            aWandererI = aWandererI + (((RotL64(aIngress, 41U) + RotL64(aOrbiterD, 51U)) + aOrbiterC) + aPhaseEWandererUpdateSaltD[((aIndex + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 14U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererE, 23U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererB, 29U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererJ, 57U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererD, 27U);
            aCarry = aCarry + RotL64(aIngress, 10U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 16926U)) & S_BLOCK1], 50U) ^ RotL64(aSnowLaneA[((aIndex + 17277U)) & S_BLOCK1], 41U));
            aIngress ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 18254U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 17964U)) & S_BLOCK1], 11U) ^ RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 18336U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCarry, 29U) + RotL64(aPrevious, 56U)) ^ (RotL64(aCross, 11U) ^ RotL64(aIngress, 43U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterH = ((aWandererJ + RotL64(aCross, 3U)) + 2571116506511057880U) + aNonceWordL;
            aOrbiterK = ((aWandererH + RotL64(aScatter, 10U)) + 13112435411509707292U) + aNonceWordJ;
            aOrbiterJ = (aWandererC + RotL64(aIngress, 57U)) + 10403251762787357256U;
            aOrbiterB = (aWandererE + RotL64(aPrevious, 53U)) + 8461951095541400405U;
            aOrbiterI = (((aWandererF + RotL64(aIngress, 39U)) + RotL64(aCarry, 43U)) + 9890793478557463815U) + aPhaseEOrbiterAssignSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = ((aWandererA + RotL64(aScatter, 23U)) + RotL64(aCarry, 51U)) + 3030229465991783707U;
            aOrbiterD = (aWandererK + RotL64(aCross, 43U)) + 7273848154043719247U;
            aOrbiterG = (((aWandererB + RotL64(aPrevious, 21U)) + RotL64(aCarry, 47U)) + 10681774862516028276U) + aPhaseEOrbiterAssignSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterA = (aWandererG + RotL64(aScatter, 35U)) + 7105082755586853104U;
            aOrbiterE = (aWandererD + RotL64(aCross, 26U)) + 6588579345319551129U;
            aOrbiterF = ((aWandererI + RotL64(aIngress, 19U)) + 14616333550242386092U) + aNonceWordF;
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 15439666290229654921U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 3360304356760164799U;
            aOrbiterJ = RotL64((aOrbiterJ * 5164191920584106237U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 14438730801970761889U) + aNonceWordC;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 14515616787452085729U;
            aOrbiterI = RotL64((aOrbiterI * 2041601927968559821U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 4167853822635132419U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 8950982233003320239U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 887144270884244907U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 12391327853728029953U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 7100871010552394421U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 16552349374101955967U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 15381697462381887944U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 6801677551341079401U;
            aOrbiterA = RotL64((aOrbiterA * 13325954438427340703U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 947011315719204867U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 6356920162398333481U;
            aOrbiterC = RotL64((aOrbiterC * 5566721941682667419U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 8910262020598577378U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 8778455415977526457U) ^ aNonceWordE;
            aOrbiterF = RotL64((aOrbiterF * 4092470497616637283U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 5585696961453127223U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 9670655481681494412U;
            aOrbiterH = RotL64((aOrbiterH * 7863197168965036383U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 10713004007087085729U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 4036355047492922339U;
            aOrbiterE = RotL64((aOrbiterE * 6923922258047667173U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 14580156873863533497U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 7049502932205025182U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 8665428649262370727U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 12707521269341941677U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 2571116506511057880U;
            aOrbiterG = RotL64((aOrbiterG * 2388236789245943699U), 19U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterB, 5U);
            aIngress = aIngress + (RotL64(aOrbiterD, 46U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterK, 21U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 39U));
            aIngress = aIngress + (RotL64(aOrbiterF, 37U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterC, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aIngress, 10U) + aOrbiterK) + RotL64(aOrbiterE, 27U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterD, 53U)) + aOrbiterJ);
            aWandererB = aWandererB + ((((RotL64(aCross, 57U) + aOrbiterF) + RotL64(aOrbiterB, 35U)) + RotL64(aCarry, 5U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 43U) + aOrbiterI) + RotL64(aOrbiterC, 47U)) + aNonceWordP);
            aWandererC = aWandererC + ((RotL64(aScatter, 50U) + RotL64(aOrbiterG, 11U)) + aOrbiterB);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 23U) + aOrbiterG) + RotL64(aOrbiterI, 19U)) + aNonceWordD);
            aWandererE = aWandererE + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterC, 50U)) + aOrbiterJ) + RotL64(aCarry, 11U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 53U) + RotL64(aOrbiterF, 3U)) + aOrbiterA) + aNonceWordG);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 21U) + aOrbiterG) + RotL64(aOrbiterH, 37U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 5U) + aOrbiterB) + RotL64(aOrbiterK, 13U)) + aPhaseEWandererUpdateSaltA[((aIndex + 23U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aPrevious, 3U) + aOrbiterK) + RotL64(aOrbiterF, 30U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 14U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererH, 11U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererD, 21U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererC, 23U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererA, 37U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererI, 41U);
            aCarry = aCarry + RotL64(aIngress, 50U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 23614U)) & S_BLOCK1], 19U) ^ RotL64(aSnowLaneB[((aIndex + 22914U)) & S_BLOCK1], 4U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 22329U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 25216U)) & S_BLOCK1], 19U) ^ RotL64(aSnowLaneA[((aIndex + 23609U)) & S_BLOCK1], 36U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aIngress, 39U) + RotL64(aCarry, 13U)) + (RotL64(aPrevious, 26U) ^ RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterF = (((aWandererB + RotL64(aPrevious, 19U)) + RotL64(aCarry, 27U)) + 826930775230515406U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = (aWandererE + RotL64(aIngress, 11U)) + 5137814617363250861U;
            aOrbiterD = ((aWandererA + RotL64(aScatter, 43U)) + 14761561947426681616U) + aNonceWordO;
            aOrbiterE = (aWandererD + RotL64(aCross, 24U)) + 12773023438753662590U;
            aOrbiterA = (aWandererC + RotL64(aScatter, 27U)) + 7331345852207096322U;
            aOrbiterK = (aWandererF + RotL64(aPrevious, 57U)) + 3899381212671247460U;
            aOrbiterG = ((aWandererK + RotL64(aIngress, 41U)) + 10072004147620068599U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterJ = ((aWandererG + RotL64(aCross, 5U)) + RotL64(aCarry, 53U)) + 3424585039401897560U;
            aOrbiterI = (((aWandererH + RotL64(aScatter, 51U)) + RotL64(aCarry, 3U)) + 8246760141625966321U) + aNonceWordI;
            aOrbiterB = (aWandererJ + RotL64(aPrevious, 53U)) + 3655992860610853290U;
            aOrbiterC = (aWandererI + RotL64(aIngress, 34U)) + 11154618022505863898U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 15629361991059709973U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 10842068502278489664U;
            aOrbiterD = RotL64((aOrbiterD * 17223002513104960799U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 5571312349016336686U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 589313823745748879U;
            aOrbiterK = RotL64((aOrbiterK * 1356685926549786027U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 13633457935771935260U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 12684602052812183096U) ^ aNonceWordG;
            aOrbiterA = RotL64((aOrbiterA * 4689206269919806711U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 5711307583717354204U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 7181854170553728211U) ^ aNonceWordA;
            aOrbiterI = RotL64((aOrbiterI * 9835601115561325911U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 1884620014396115821U) + aNonceWordE;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 1471516373272364262U;
            aOrbiterJ = RotL64((aOrbiterJ * 5126319375714848029U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 742739371092077733U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 8075893317715227838U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 11208274111743259795U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 8179547722249281263U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 15305282712174742323U;
            aOrbiterE = RotL64((aOrbiterE * 7951986906055462929U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 1430543231751281079U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 14585341768267283387U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 313213844964269133U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 8123889986027932297U) + aNonceWordF;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 2081696191347150910U;
            aOrbiterF = RotL64((aOrbiterF * 4869653441012615053U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 10166788886199265936U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 15927074835525735601U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 6747650218540675523U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 6997764816848988590U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 826930775230515406U;
            aOrbiterH = RotL64((aOrbiterH * 9943232461538279601U), 35U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterF, 53U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 37U));
            aIngress = aIngress + (RotL64(aOrbiterG, 47U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 5U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 44U));
            aIngress = aIngress + RotL64(aOrbiterI, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aScatter, 29U) + aOrbiterD) + RotL64(aOrbiterK, 50U)) + aPhaseEWandererUpdateSaltC[((aIndex + 20U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 21U) + aOrbiterD) + RotL64(aOrbiterB, 39U)) + aNonceWordJ);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 39U) + aOrbiterF) + RotL64(aOrbiterG, 27U));
            aWandererB = aWandererB + ((RotL64(aIngress, 51U) + RotL64(aOrbiterJ, 37U)) + aOrbiterG);
            aWandererE = aWandererE ^ (((RotL64(aCross, 14U) + aOrbiterJ) + RotL64(aOrbiterK, 18U)) + aNonceWordM);
            aWandererG = aWandererG + ((RotL64(aPrevious, 41U) + RotL64(aOrbiterI, 11U)) + aOrbiterE);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterJ, 41U)) + aOrbiterH);
            aWandererD = aWandererD + ((((RotL64(aScatter, 53U) + RotL64(aOrbiterG, 13U)) + aOrbiterC) + RotL64(aCarry, 23U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 34U) + aOrbiterI) + RotL64(aOrbiterJ, 5U));
            aWandererC = aWandererC + (((RotL64(aIngress, 57U) + aOrbiterB) + RotL64(aOrbiterA, 29U)) + RotL64(aCarry, 51U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterH, 23U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererF, 6U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererI, 3U) ^ aWandererC);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 51U));
            aCarry = aCarry + (RotL64(aWandererJ, 27U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererE, 39U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererA, 35U);
            aCarry = aCarry + RotL64(aIngress, 44U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 32493U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneA[((aIndex + 29822U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 31219U)) & S_BLOCK1], 56U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 30129U)) & S_BLOCK1], 10U) ^ RotL64(aInvestLaneB[((aIndex + 31374U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCarry, 21U) ^ RotL64(aIngress, 40U)) + (RotL64(aCross, 5U) ^ RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterK = (aWandererA + RotL64(aIngress, 30U)) + 7948891781097675369U;
            aOrbiterE = (aWandererI + RotL64(aCross, 13U)) + 13928362874228230226U;
            aOrbiterC = ((aWandererK + RotL64(aScatter, 57U)) + 10776180542602258926U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterB = (aWandererD + RotL64(aPrevious, 53U)) + 5735115172149470447U;
            aOrbiterA = ((aWandererB + RotL64(aCross, 40U)) + RotL64(aCarry, 13U)) + 5353591822981766987U;
            aOrbiterH = (aWandererE + RotL64(aPrevious, 43U)) + 562301708107268570U;
            aOrbiterJ = (((aWandererG + RotL64(aScatter, 27U)) + RotL64(aCarry, 53U)) + 10467810247578364868U) + aPhaseEOrbiterAssignSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = ((aWandererJ + RotL64(aIngress, 51U)) + 14541630141152308564U) + aNonceWordO;
            aOrbiterF = (aWandererF + RotL64(aCross, 19U)) + 2350076897065139429U;
            aOrbiterI = ((aWandererC + RotL64(aPrevious, 23U)) + 17519109078651162228U) + aNonceWordE;
            aOrbiterG = ((aWandererH + RotL64(aIngress, 21U)) + RotL64(aCarry, 57U)) + 6061035173339902910U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 15654836633731000065U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 13723521735153718904U;
            aOrbiterC = RotL64((aOrbiterC * 14459516479283070563U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 2849680038315532197U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 17336102435576647923U;
            aOrbiterA = RotL64((aOrbiterA * 10984689101753586739U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 7671010488872356142U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 11485114338165600777U;
            aOrbiterH = RotL64((aOrbiterH * 4162584865462407791U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 8759060657343458985U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 11009137869375286581U;
            aOrbiterJ = RotL64((aOrbiterJ * 8741417343929809115U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 15792999392743144135U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 6180808423175992479U;
            aOrbiterD = RotL64((aOrbiterD * 13681230339693676907U), 35U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterD) + 361487389591183005U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordF;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 15292753806514404853U) ^ aNonceWordL;
            aOrbiterF = RotL64((aOrbiterF * 17478232597253311153U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 14929153438443362045U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 7904556383593914086U;
            aOrbiterE = RotL64((aOrbiterE * 2484130486635511403U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 3793180909904286848U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 10391957637467171320U;
            aOrbiterG = RotL64((aOrbiterG * 505484041943467117U), 21U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 11648765065563798353U) + aNonceWordA;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 17601185776537566611U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4753179291885740011U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 2907499704986356444U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 17048858067202291241U;
            aOrbiterK = RotL64((aOrbiterK * 2607549567999666889U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 4340465159886930775U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 7948891781097675369U;
            aOrbiterI = RotL64((aOrbiterI * 12913104720552907335U), 3U);
            //
            aIngress = RotL64(aOrbiterB, 19U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 50U));
            aIngress = aIngress + (RotL64(aOrbiterG, 57U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterE, 27U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 37U));
            aIngress = aIngress + RotL64(aOrbiterC, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterD, 23U)) + aOrbiterB);
            aWandererH = aWandererH + ((RotL64(aScatter, 30U) + aOrbiterF) + RotL64(aOrbiterG, 30U));
            aWandererB = aWandererB ^ ((((RotL64(aIngress, 23U) + aOrbiterH) + RotL64(aOrbiterE, 13U)) + aNonceWordJ) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 3U) + RotL64(aOrbiterE, 35U)) + aOrbiterA);
            aWandererD = aWandererD ^ ((RotL64(aCross, 21U) + aOrbiterG) + RotL64(aOrbiterC, 27U));
            aWandererK = aWandererK + ((((RotL64(aScatter, 41U) + RotL64(aOrbiterK, 21U)) + aOrbiterI) + RotL64(aCarry, 51U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterE, 5U)) + aOrbiterK);
            aWandererF = aWandererF + (((RotL64(aIngress, 51U) + RotL64(aOrbiterK, 39U)) + aOrbiterD) + RotL64(aCarry, 21U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterB, 10U)) + aOrbiterA) + aNonceWordI);
            aWandererE = aWandererE + (((RotL64(aIngress, 56U) + RotL64(aOrbiterE, 43U)) + aOrbiterJ) + aNonceWordP);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 43U) + aOrbiterJ) + RotL64(aOrbiterC, 51U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 26U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 57U));
            aCarry = aCarry + (RotL64(aWandererA, 29U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererD, 35U) ^ aWandererB);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 46U));
            aCarry = aCarry + RotL64(aWandererC, 5U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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

void TwistExpander_PingPong_Arx::Seed_F(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x8DC5C2B6D16806FFULL + 0xED7ED2A95B1F6F29ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x84FD212B7F760A13ULL + 0xCDE68461F97F294DULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xC00919FD2DA0FE53ULL + 0xB4FF262BF61A8713ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x9B084F0FF69D5603ULL + 0xEF0E0DA7E8466315ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xB0E52895056E4541ULL + 0xFED7480DF6D6C82EULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xFE2D9E67600A6CA1ULL + 0xF15A7DFF332F096EULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xA0DE862ABDAD2A91ULL + 0xB7FF46DC70DD031BULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xA91435C69130D2EDULL + 0xDB67773A74D125F5ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xD7D6527591354B97ULL + 0xEE0A1B98A9594D48ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x8990B3609178015BULL + 0x8E5D718F84442D5BULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xDA8C31AC5F3C831FULL + 0xDF7E7BEAF1AAB3D3ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xCFD9A569C8F2C0D7ULL + 0xD8B063FF6747F18AULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xAF7ABC9EEDF7739DULL + 0xF85C373EFAC20F2DULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xD70A63D1499B4567ULL + 0xAA06F23FB365C833ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xED0ADD4BCEAE78BBULL + 0xF48E0BFC9E0CDC29ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xADC08704E6A0D205ULL + 0x9CA2105067952D47ULL);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 4130U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneB[((aIndex + 647U)) & S_BLOCK1], 41U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 508U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 2567U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 2165U)) & S_BLOCK1], 56U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 4117U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aPrevious, 37U) ^ RotL64(aCross, 56U)) + (RotL64(aCarry, 11U) + RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterI = (((aWandererI + RotL64(aScatter, 39U)) + RotL64(aCarry, 3U)) + 3917730204724097072U) + aNonceWordG;
            aOrbiterH = (((aWandererH + RotL64(aPrevious, 35U)) + RotL64(aCarry, 19U)) + 1874642340716212824U) + aNonceWordE;
            aOrbiterJ = ((aWandererA + RotL64(aCross, 19U)) + RotL64(aCarry, 37U)) + 6900165757434854160U;
            aOrbiterF = (((aWandererG + RotL64(aIngress, 23U)) + 12750946097023807161U) + aPhaseFOrbiterAssignSaltF[((aIndex + 4U)) & S_SALT1]) + aNonceWordC;
            aOrbiterD = (aWandererF + RotL64(aCross, 56U)) + 6563216048479513594U;
            aOrbiterB = (aWandererE + RotL64(aPrevious, 51U)) + 14960240191349450795U;
            aOrbiterK = (((aWandererJ + RotL64(aScatter, 47U)) + 16306180275951788289U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordP;
            aOrbiterC = (aWandererC + RotL64(aIngress, 43U)) + 6502066618271045547U;
            aOrbiterE = (aWandererB + RotL64(aScatter, 28U)) + 6219852857850888738U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 2272931312452845850U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 3028929882263199463U) ^ aNonceWordF;
            aOrbiterJ = RotL64((aOrbiterJ * 11005324285856805069U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 6067393030073568112U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 10094809900437037258U;
            aOrbiterD = RotL64((aOrbiterD * 18095564940730322769U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 5962414178157074575U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 15755563045799129417U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 3692603590609922031U), 23U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterD) + 6321455513889880590U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1]) + aNonceWordA;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 1197435601998121700U;
            aOrbiterI = RotL64((aOrbiterI * 17693996266260557625U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 12496949381666299968U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 6357070235648527030U;
            aOrbiterF = RotL64((aOrbiterF * 2931486644220862433U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 8423760160877540210U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 8090246492554850768U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2949407491181921633U), 47U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterE) + 11436635942985063755U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordM;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 17086363141014359856U;
            aOrbiterB = RotL64((aOrbiterB * 10504127577318206801U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 10734017887545474935U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 375515325165740779U) ^ aNonceWordK;
            aOrbiterK = RotL64((aOrbiterK * 9980486695448151709U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 5217148491945389821U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 14696058217023530058U;
            aOrbiterE = RotL64((aOrbiterE * 11026674782236654799U), 27U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterB, 44U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 23U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterC, 39U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterK, 5U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterH, 56U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterK, 23U)) + aOrbiterH);
            aWandererF = aWandererF + (((RotL64(aCross, 27U) + aOrbiterK) + RotL64(aOrbiterB, 11U)) + aNonceWordL);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterI, 5U)) + aOrbiterD);
            aWandererB = aWandererB + ((((RotL64(aIngress, 12U) + RotL64(aOrbiterH, 52U)) + aOrbiterI) + RotL64(aCarry, 53U)) + aPhaseFWandererUpdateSaltA[((aIndex + 3U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterC, 19U)) + aOrbiterH);
            aWandererI = aWandererI + (((RotL64(aCross, 51U) + RotL64(aOrbiterE, 37U)) + aOrbiterK) + RotL64(aCarry, 13U));
            aWandererH = aWandererH ^ ((((RotL64(aIngress, 37U) + RotL64(aOrbiterF, 47U)) + aOrbiterD) + aNonceWordH) + aPhaseFWandererUpdateSaltB[((aIndex + 8U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aPrevious, 56U) + aOrbiterE) + RotL64(aOrbiterJ, 56U)) + aNonceWordJ);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 21U) + aOrbiterH) + RotL64(aOrbiterF, 43U)) + aNonceWordI);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 6U));
            aCarry = aCarry + (RotL64(aWandererE, 27U) ^ aWandererH);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 13U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 53U));
            aCarry = aCarry + RotL64(aWandererA, 39U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = (RotL64(aSnowLaneA[((aIndex + 8164U)) & S_BLOCK1], 10U) ^ RotL64(aOperationLaneC[((aIndex + 5897U)) & S_BLOCK1], 21U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 7967U)) & S_BLOCK1], 53U) ^ RotL64(aFireLaneC[((aIndex + 6778U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 9538U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 8874U)) & S_BLOCK1], 41U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 9140U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aPrevious, 36U)) ^ (RotL64(aCross, 21U) ^ RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterK = ((aWandererG + RotL64(aPrevious, 48U)) + 8767379393098711499U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = (aWandererH + RotL64(aScatter, 39U)) + 7168159491580816433U;
            aOrbiterC = (((aWandererJ + RotL64(aCross, 29U)) + RotL64(aCarry, 5U)) + 9879279829061883406U) + aNonceWordD;
            aOrbiterA = (aWandererB + RotL64(aIngress, 35U)) + 10537167136053399303U;
            aOrbiterE = (((aWandererA + RotL64(aPrevious, 57U)) + RotL64(aCarry, 37U)) + 2839070018069188936U) + aNonceWordK;
            aOrbiterG = (aWandererK + RotL64(aScatter, 43U)) + 13844278063968429732U;
            aOrbiterB = (((aWandererC + RotL64(aIngress, 19U)) + RotL64(aCarry, 21U)) + 11278946626186474646U) + aNonceWordC;
            aOrbiterJ = (aWandererF + RotL64(aCross, 24U)) + 11798425216660557799U;
            aOrbiterF = ((aWandererE + RotL64(aScatter, 53U)) + 7618446090703335192U) + aPhaseFOrbiterAssignSaltD[((aIndex + 21U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 695423597006983660U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 14344728202803488813U;
            aOrbiterC = RotL64((aOrbiterC * 5168825904902285909U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 11656100506575697086U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 10384358779985773937U;
            aOrbiterK = RotL64((aOrbiterK * 247494692039140973U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 17585001605131977341U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 9964478171465522911U;
            aOrbiterA = RotL64((aOrbiterA * 13484044854790175315U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 2710943171829692624U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 17809072853457153057U;
            aOrbiterJ = RotL64((aOrbiterJ * 16341884203303271365U), 23U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterJ) + 12814092033910687774U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1]) + aNonceWordB;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 1743186323268668740U;
            aOrbiterH = RotL64((aOrbiterH * 11150822630624332557U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 10750472346626754704U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 15925901217078035356U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 9276504171291801637U), 11U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterB) + 2569102106359362359U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1]) + aNonceWordI;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 8868261301410769739U;
            aOrbiterE = RotL64((aOrbiterE * 3662495603133918101U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 2143691008373582476U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 10606616796243205921U;
            aOrbiterB = RotL64((aOrbiterB * 15794414817813485643U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 16258070651850746855U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 11720192793689633315U;
            aOrbiterG = RotL64((aOrbiterG * 14475623219460678021U), 53U);
            //
            aIngress = RotL64(aOrbiterE, 11U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 6U));
            aIngress = aIngress + (RotL64(aOrbiterG, 35U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterJ, 47U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterH, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aCross, 10U) + RotL64(aOrbiterH, 3U)) + aOrbiterK);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterE, 12U)) + aOrbiterC);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 23U) + aOrbiterH) + RotL64(aOrbiterB, 47U)) + aNonceWordP);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 27U) + aOrbiterF) + RotL64(aOrbiterE, 41U));
            aWandererE = aWandererE + (((RotL64(aCross, 58U) + aOrbiterJ) + RotL64(aOrbiterF, 37U)) + aNonceWordN);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 51U) + RotL64(aOrbiterE, 19U)) + aOrbiterJ) + aNonceWordE);
            aWandererA = aWandererA + ((((RotL64(aIngress, 35U) + aOrbiterK) + RotL64(aOrbiterA, 24U)) + RotL64(aCarry, 29U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterE, 57U)) + aOrbiterG);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 41U) + RotL64(aOrbiterH, 29U)) + aOrbiterE) + RotL64(aCarry, 13U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 54U) ^ aWandererH);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 57U));
            aCarry = aCarry + (RotL64(aWandererJ, 3U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererA, 13U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererK, 27U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = (RotL64(aSnowLaneB[((aIndex + 10943U)) & S_BLOCK1], 28U) ^ RotL64(aOperationLaneA[((aIndex + 14587U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aInvestLaneA[((aIndex + 13672U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 14912U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneC[((aIndex + 14070U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aPrevious, 11U) + RotL64(aCross, 43U)) + (RotL64(aIngress, 60U) ^ RotL64(aCarry, 29U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterJ = (aWandererK + RotL64(aCross, 42U)) + 12311607308490066301U;
            aOrbiterG = ((aWandererC + RotL64(aScatter, 23U)) + RotL64(aCarry, 41U)) + 13100864684740679846U;
            aOrbiterB = (((aWandererA + RotL64(aPrevious, 19U)) + RotL64(aCarry, 51U)) + 13697304189274329704U) + aNonceWordA;
            aOrbiterF = ((aWandererJ + RotL64(aIngress, 5U)) + 9047976902871216732U) + aPhaseFOrbiterAssignSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterD = (aWandererD + RotL64(aCross, 27U)) + 2147897579538537888U;
            aOrbiterH = ((aWandererF + RotL64(aPrevious, 51U)) + 2072444829390996142U) + aPhaseFOrbiterAssignSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = (aWandererI + RotL64(aScatter, 46U)) + 2129307836981020908U;
            aOrbiterA = (aWandererH + RotL64(aIngress, 37U)) + 10663145333751112064U;
            aOrbiterE = (((aWandererB + RotL64(aCross, 57U)) + RotL64(aCarry, 19U)) + 15019844390503785459U) + aNonceWordG;
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterG) + 5460865577557928142U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordM;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 15806522559993224197U;
            aOrbiterB = RotL64((aOrbiterB * 8722932687972240099U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 6361113778657833389U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 8306013884615042570U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8234258702656728667U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 4038420580499706912U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 11908091484457158973U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 3964111175645156719U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 11133912466611921250U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 2469227904206936928U;
            aOrbiterF = RotL64((aOrbiterF * 2704438771198001599U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 13234017916788297295U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 9061117693840451988U;
            aOrbiterG = RotL64((aOrbiterG * 3637440416741459419U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 12013423690843812324U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 14371779015144617412U;
            aOrbiterJ = RotL64((aOrbiterJ * 3359568073302062667U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 10044883414565441442U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 14334898081890462218U) ^ aNonceWordN;
            aOrbiterK = RotL64((aOrbiterK * 4878939077928220019U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 13788962593988366125U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 8377887372059713516U;
            aOrbiterA = RotL64((aOrbiterA * 1925913354197206851U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 4584439257847749371U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterH) ^ 13335592911357756498U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterE = RotL64((aOrbiterE * 6515028218115896375U), 47U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterH, 57U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 27U));
            aIngress = aIngress + (RotL64(aOrbiterA, 51U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 20U));
            aIngress = aIngress + RotL64(aOrbiterK, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 35U) + aOrbiterH) + RotL64(aOrbiterK, 35U));
            aWandererF = aWandererF + ((RotL64(aCross, 52U) + aOrbiterD) + RotL64(aOrbiterF, 44U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterB, 53U)) + aOrbiterD);
            aWandererI = aWandererI + (((RotL64(aScatter, 39U) + aOrbiterK) + RotL64(aOrbiterF, 11U)) + RotL64(aCarry, 21U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 43U) + aOrbiterA) + RotL64(aOrbiterD, 21U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 4U) + RotL64(aOrbiterF, 26U)) + aOrbiterA) + RotL64(aCarry, 29U)) + aPhaseFWandererUpdateSaltC[((aIndex + 13U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 27U) + RotL64(aOrbiterJ, 57U)) + aOrbiterD) + aNonceWordF);
            aWandererK = aWandererK + ((RotL64(aScatter, 13U) + aOrbiterG) + RotL64(aOrbiterD, 5U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 57U) + aOrbiterH) + RotL64(aOrbiterE, 39U)) + aNonceWordJ);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 46U));
            aCarry = aCarry + (RotL64(aWandererJ, 39U) ^ aWandererI);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 43U));
            aCarry = aCarry + (RotL64(aWandererK, 53U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererF, 13U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 19853U)) & S_BLOCK1], 30U) ^ RotL64(aSnowLaneA[((aIndex + 19749U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aInvestLaneB[((aIndex + 20148U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 20339U)) & S_BLOCK1], 14U) ^ RotL64(aOperationLaneD[((aIndex + 21454U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aPrevious, 27U) + RotL64(aCarry, 6U)) ^ (RotL64(aCross, 57U) ^ RotL64(aIngress, 41U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterD = (aWandererE + RotL64(aScatter, 5U)) + 16183871922837164759U;
            aOrbiterI = (aWandererH + RotL64(aPrevious, 11U)) + 7002058258090219055U;
            aOrbiterK = (((aWandererF + RotL64(aIngress, 40U)) + RotL64(aCarry, 47U)) + 5650868611888303705U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = (((aWandererI + RotL64(aCross, 27U)) + RotL64(aCarry, 3U)) + 11899839660943876690U) + aPhaseFOrbiterAssignSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = (aWandererG + RotL64(aPrevious, 53U)) + 15349649504488111111U;
            aOrbiterH = ((aWandererC + RotL64(aScatter, 47U)) + RotL64(aCarry, 21U)) + 14060149569086744970U;
            aOrbiterJ = ((aWandererA + RotL64(aIngress, 35U)) + 12920917574225030112U) + aNonceWordK;
            aOrbiterF = ((aWandererD + RotL64(aCross, 58U)) + 2831994965175330135U) + aNonceWordO;
            aOrbiterC = ((aWandererJ + RotL64(aIngress, 19U)) + 18312543585028439192U) + aNonceWordF;
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 11657562205118394239U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 10850792819281246052U) ^ aNonceWordG;
            aOrbiterK = RotL64((aOrbiterK * 10663100544207879337U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 17810371216216125323U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 7963413941144223128U;
            aOrbiterH = RotL64((aOrbiterH * 534217972450595401U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 5498715358793875584U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 9256727548911651373U;
            aOrbiterF = RotL64((aOrbiterF * 10498848323914000989U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 17246360111302191699U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 18309978718113983369U) ^ aNonceWordP;
            aOrbiterJ = RotL64((aOrbiterJ * 18267472694666221077U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 3100998994319502921U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 8129301860291235970U) ^ aNonceWordE;
            aOrbiterA = RotL64((aOrbiterA * 17847033539279176187U), 57U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterB) + 1889641029473279114U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 24U)) & S_SALT1]) + aNonceWordB;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 16538494307002917945U;
            aOrbiterC = RotL64((aOrbiterC * 8081488217920885783U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 5432230549146849322U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 2634437941396090817U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7612999214758935211U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 16940172599174185058U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 13151669140593952203U;
            aOrbiterD = RotL64((aOrbiterD * 16225319638131723487U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 3995064294869931681U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 913081077665768816U;
            aOrbiterB = RotL64((aOrbiterB * 9299514648768060453U), 23U);
            //
            aIngress = RotL64(aOrbiterF, 6U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 13U));
            aIngress = aIngress + (RotL64(aOrbiterC, 43U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 35U));
            aIngress = aIngress + RotL64(aOrbiterI, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aScatter, 30U) + RotL64(aOrbiterH, 18U)) + aOrbiterA) + aNonceWordD);
            aWandererC = aWandererC ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterD, 5U)) + aOrbiterK);
            aWandererA = aWandererA + (((RotL64(aIngress, 57U) + aOrbiterK) + RotL64(aOrbiterB, 35U)) + RotL64(aCarry, 35U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 37U) + RotL64(aOrbiterI, 29U)) + aOrbiterD) + aNonceWordN);
            aWandererI = aWandererI + ((RotL64(aIngress, 3U) + RotL64(aOrbiterJ, 57U)) + aOrbiterH);
            aWandererH = aWandererH ^ (((RotL64(aCross, 41U) + RotL64(aOrbiterF, 13U)) + aOrbiterK) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aPrevious, 26U) + aOrbiterD) + RotL64(aOrbiterJ, 23U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 19U) + aOrbiterB) + RotL64(aOrbiterC, 47U));
            aWandererD = aWandererD + ((((RotL64(aPrevious, 51U) + aOrbiterI) + RotL64(aOrbiterJ, 52U)) + RotL64(aCarry, 21U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 51U));
            aCarry = aCarry + (RotL64(aWandererI, 4U) ^ aWandererE);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 39U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + RotL64(aWandererA, 35U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 26316U)) & S_BLOCK1], 5U) ^ RotL64(aSnowLaneB[((aIndex + 25351U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 23349U)) & S_BLOCK1], 24U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 25211U)) & S_BLOCK1], 56U) ^ RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 24640U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCarry, 44U) ^ RotL64(aIngress, 11U)) ^ (RotL64(aPrevious, 23U) + RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterC = (((aWandererD + RotL64(aCross, 58U)) + RotL64(aCarry, 39U)) + 15045917390223766480U) + aNonceWordH;
            aOrbiterE = ((aWandererB + RotL64(aPrevious, 23U)) + 10763054007033668758U) + aPhaseFOrbiterAssignSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterF = (aWandererJ + RotL64(aIngress, 11U)) + 13190170142593666607U;
            aOrbiterI = (aWandererK + RotL64(aScatter, 53U)) + 9657025731441167065U;
            aOrbiterJ = (aWandererA + RotL64(aPrevious, 34U)) + 11433367178975954211U;
            aOrbiterK = ((aWandererE + RotL64(aIngress, 29U)) + 17904920143996810366U) + aNonceWordD;
            aOrbiterA = (aWandererF + RotL64(aCross, 47U)) + 3244383020512113283U;
            aOrbiterH = ((aWandererI + RotL64(aScatter, 19U)) + RotL64(aCarry, 19U)) + 6538815775171139091U;
            aOrbiterB = (((aWandererH + RotL64(aPrevious, 3U)) + RotL64(aCarry, 11U)) + 7195368312757976343U) + aPhaseFOrbiterAssignSaltE[((aIndex + 27U)) & S_SALT1];
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 18134430713910279374U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 6571776588427107976U;
            aOrbiterF = RotL64((aOrbiterF * 11916502085252589161U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 11830778129647517758U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 9793702760907767365U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4096246227968677179U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 2287235876793192036U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 8951959188326141794U;
            aOrbiterA = RotL64((aOrbiterA * 9968356718110753845U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 7583061790273240157U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 3571364625022806085U) ^ aNonceWordG;
            aOrbiterH = RotL64((aOrbiterH * 6238360922735480669U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 13869345563551689212U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 277480328952975002U;
            aOrbiterB = RotL64((aOrbiterB * 1057564597096163085U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 4983735092494677578U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 9490022869381030928U) ^ aNonceWordB;
            aOrbiterC = RotL64((aOrbiterC * 12926352917961703123U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 7928039573014765566U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 6504190875809407084U;
            aOrbiterK = RotL64((aOrbiterK * 14648214826494826711U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 2787985600176307413U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 16308785053443116826U;
            aOrbiterE = RotL64((aOrbiterE * 17867565986311256691U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 12788128335006767824U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 1187040019537798339U) ^ aNonceWordL;
            aOrbiterI = RotL64((aOrbiterI * 10834905007658184183U), 47U);
            //
            aIngress = RotL64(aOrbiterJ, 43U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterK, 5U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterB, 48U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterE, 13U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterF, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aCross, 5U) + aOrbiterH) + RotL64(aOrbiterA, 14U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 20U) + RotL64(aOrbiterB, 23U)) + aOrbiterH) + aNonceWordI);
            aWandererF = aWandererF + (((RotL64(aPrevious, 27U) + RotL64(aOrbiterF, 35U)) + aOrbiterC) + aNonceWordM);
            aWandererI = aWandererI ^ ((((RotL64(aScatter, 57U) + aOrbiterC) + RotL64(aOrbiterI, 27U)) + aNonceWordC) + aPhaseFWandererUpdateSaltE[((aIndex + 22U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aCross, 53U) + RotL64(aOrbiterH, 39U)) + aOrbiterC) + RotL64(aCarry, 27U)) + aNonceWordN);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 36U) + aOrbiterK) + RotL64(aOrbiterJ, 47U));
            aWandererD = aWandererD + ((RotL64(aScatter, 41U) + RotL64(aOrbiterF, 43U)) + aOrbiterI);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterA, 19U)) + aOrbiterE);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 13U) + aOrbiterJ) + RotL64(aOrbiterA, 54U)) + RotL64(aCarry, 19U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 51U) ^ aWandererB);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 43U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 60U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 35U));
            aCarry = aCarry + RotL64(aWandererA, 3U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 30453U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneA[((aIndex + 30810U)) & S_BLOCK1], 46U));
            aIngress ^= RotL64(aInvestLaneD[((aIndex + 30714U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordA));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27820U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneB[((aIndex + 27566U)) & S_BLOCK1], 58U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCarry, 27U) ^ RotL64(aPrevious, 60U)) + (RotL64(aIngress, 11U) ^ RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterA = (((aWandererJ + RotL64(aPrevious, 35U)) + RotL64(aCarry, 5U)) + 6733949564325516029U) + aNonceWordB;
            aOrbiterG = ((aWandererA + RotL64(aCross, 14U)) + 7304098437143918796U) + aNonceWordD;
            aOrbiterF = ((aWandererK + RotL64(aScatter, 27U)) + 3923949518391777800U) + aNonceWordM;
            aOrbiterB = (aWandererF + RotL64(aIngress, 57U)) + 14243591003388927124U;
            aOrbiterD = ((aWandererI + RotL64(aScatter, 39U)) + RotL64(aCarry, 27U)) + 18329498724605410406U;
            aOrbiterK = (aWandererG + RotL64(aPrevious, 51U)) + 13118172167747037249U;
            aOrbiterI = (aWandererC + RotL64(aCross, 19U)) + 5272025143849174212U;
            aOrbiterJ = (((aWandererB + RotL64(aIngress, 47U)) + RotL64(aCarry, 19U)) + 16075917179214318424U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = ((aWandererE + RotL64(aCross, 10U)) + 15263590648674658399U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 13730046728289525921U) + aNonceWordK;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 7703141464499623408U) ^ aNonceWordE;
            aOrbiterF = RotL64((aOrbiterF * 5886009900621521987U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 1382279753822135359U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 2973369221699098292U) ^ aNonceWordF;
            aOrbiterD = RotL64((aOrbiterD * 7440242040663550631U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 11578274119583013219U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 3419411247737896674U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 17814942652262802991U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 2582783513078999303U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 3959762790273529677U;
            aOrbiterJ = RotL64((aOrbiterJ * 383974377372162751U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 465795011576934604U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 17880826624185821135U;
            aOrbiterB = RotL64((aOrbiterB * 4445949147592860913U), 39U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterA) + 10819659185349413173U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordG;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 17298208553586835030U;
            aOrbiterC = RotL64((aOrbiterC * 1965860510614222093U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 12585880006661489402U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 16650193903267408586U;
            aOrbiterK = RotL64((aOrbiterK * 5781132589396936615U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 885882046325991589U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 869560078374809974U;
            aOrbiterA = RotL64((aOrbiterA * 13440973563438747181U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 11871305571797951851U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 12137095015607196226U;
            aOrbiterI = RotL64((aOrbiterI * 7618152256560808581U), 23U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterJ, 23U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 60U));
            aIngress = aIngress + (RotL64(aOrbiterD, 19U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 47U));
            aIngress = aIngress + RotL64(aOrbiterG, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 39U) + RotL64(aOrbiterA, 13U)) + aOrbiterK) + aPhaseFWandererUpdateSaltC[((aIndex + 5U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aIngress, 27U) + RotL64(aOrbiterC, 29U)) + aOrbiterI) + aNonceWordH);
            aWandererE = aWandererE ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterG, 4U)) + aOrbiterF);
            aWandererB = aWandererB + (((((RotL64(aScatter, 58U) + aOrbiterA) + RotL64(aOrbiterI, 23U)) + RotL64(aCarry, 13U)) + aNonceWordN) + aPhaseFWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterF, 47U)) + aOrbiterI);
            aWandererF = aWandererF + (((RotL64(aCross, 21U) + RotL64(aOrbiterD, 35U)) + aOrbiterB) + RotL64(aCarry, 57U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 43U) + aOrbiterK) + RotL64(aOrbiterB, 41U));
            aWandererA = aWandererA + ((RotL64(aScatter, 54U) + RotL64(aOrbiterG, 57U)) + aOrbiterJ);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 35U) + aOrbiterB) + RotL64(aOrbiterF, 52U)) + aNonceWordP);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 44U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 53U));
            aCarry = aCarry + (RotL64(aWandererC, 13U) ^ aWandererJ);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 57U));
            aCarry = aCarry + RotL64(aWandererI, 3U);
            aCarry = aCarry + RotL64(aIngress, 48U);
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

void TwistExpander_PingPong_Arx::Seed_G(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xBDAC8D67544C9575ULL + 0xB2FF90C14C3D3A6AULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xCDDF1FFF567544A7ULL + 0x894218C957B7373FULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xAA671EF597743ADDULL + 0x834EE6D3C67AD68EULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xA6F76B31EBF07A71ULL + 0xEBE714466E660715ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xA3E63D38BE675D91ULL + 0xE742DC9F6E10B0D1ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xBA77587AB4E739B5ULL + 0xD461F79A78E83C1BULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xAE7B7D6F2C028B6FULL + 0xBA099F4BBACE5971ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x815C8822BD34E335ULL + 0xB600BFB25F3866F2ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x9D82A41634AC2B69ULL + 0x837E811B992E67F5ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xF779C9EFCD9AEB7FULL + 0x92C5009F830D6679ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xF838C4E513D5C383ULL + 0xF50C067A516617DBULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xC1851AADDA228FA7ULL + 0xBD0165E17F1DE1B1ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xAD814A3B30181F3FULL + 0x862CFD869DC64369ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xC6DDCC674A03495BULL + 0xF55F784FDD772F21ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xA7AEC84037B6B2D5ULL + 0x842377462BA9A2B7ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0x9B13E8B567221111ULL + 0xBA15E11AC3B0FC1BULL);
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
            aIngress = (RotL64(aSnowLaneA[((aIndex + 4002U)) & S_BLOCK1], 43U) ^ RotL64(aSnowLaneB[((aIndex + 1883U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 961U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 2063U)) & S_BLOCK1], 22U) ^ RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 5359U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 5342U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCross, 22U) ^ RotL64(aIngress, 35U)) + (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterH = (((aWandererB + RotL64(aIngress, 41U)) + RotL64(aCarry, 27U)) + 5480870806135400132U) + aNonceWordB;
            aOrbiterK = ((aWandererJ + RotL64(aPrevious, 26U)) + 8034874599430768743U) + aNonceWordM;
            aOrbiterJ = (((aWandererE + RotL64(aCross, 13U)) + RotL64(aCarry, 39U)) + 4006919843736863767U) + aPhaseHOrbiterAssignSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterD = ((aWandererK + RotL64(aScatter, 53U)) + 2988069748674633718U) + aNonceWordE;
            aOrbiterI = (aWandererF + RotL64(aCross, 19U)) + 12347295651973135786U;
            aOrbiterA = ((aWandererI + RotL64(aIngress, 35U)) + 14152683894431568192U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = (((aWandererC + RotL64(aPrevious, 3U)) + RotL64(aCarry, 51U)) + 15765143815254196598U) + aNonceWordO;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 10473067082331244233U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 1089466925383677249U;
            aOrbiterJ = RotL64((aOrbiterJ * 17334888609179149753U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 13215039929873682230U) + aNonceWordK;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 3957997712247961479U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7631186240013784703U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 10023907397941685546U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 14593012591254614353U;
            aOrbiterK = RotL64((aOrbiterK * 17111300092082154687U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 13353797968154036726U) + aNonceWordD;
            aOrbiterA = (((aOrbiterA ^ aOrbiterF) ^ 9259966668512102858U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterA = RotL64((aOrbiterA * 8326732574268308221U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 10757861831070349321U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 10530223113483866178U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11269177745265396583U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 7554320926405521865U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 6978052067277966996U;
            aOrbiterD = RotL64((aOrbiterD * 18020134738536217801U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 1053695861967171420U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 15980734683539854451U) ^ aNonceWordH;
            aOrbiterI = RotL64((aOrbiterI * 3208466640010555357U), 57U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterH, 29U);
            aIngress = aIngress + (RotL64(aOrbiterI, 43U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 3U));
            aIngress = aIngress + RotL64(aOrbiterD, 14U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 5U) + aOrbiterK) + RotL64(aOrbiterF, 13U)) + aNonceWordN);
            aWandererK = aWandererK + ((((RotL64(aIngress, 11U) + aOrbiterH) + RotL64(aOrbiterD, 27U)) + RotL64(aCarry, 53U)) + aNonceWordJ);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 43U) + aOrbiterD) + RotL64(aOrbiterI, 21U));
            aWandererI = aWandererI + ((((RotL64(aCross, 27U) + aOrbiterJ) + RotL64(aOrbiterH, 38U)) + RotL64(aCarry, 19U)) + aPhaseHWandererUpdateSaltD[((aIndex + 19U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterK, 53U)) + aOrbiterD);
            aWandererE = aWandererE + ((RotL64(aCross, 19U) + aOrbiterI) + RotL64(aOrbiterK, 47U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 34U) + aOrbiterA) + RotL64(aOrbiterI, 3U)) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 18U));
            aCarry = aCarry + (RotL64(aWandererC, 51U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererF, 3U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererB, 41U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 8556U)) & S_BLOCK1], 13U) ^ RotL64(aSnowLaneC[((aIndex + 8854U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aSnowLaneD[((aIndex + 6009U)) & S_BLOCK1], 35U) ^ RotL64(aFireLaneC[((aIndex + 8097U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 5876U)) & S_BLOCK1], 20U) ^ RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 8112U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 7198U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aPrevious, 11U) ^ RotL64(aCarry, 43U)) + (RotL64(aCross, 57U) ^ RotL64(aIngress, 24U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterF = (((aWandererC + RotL64(aCross, 37U)) + RotL64(aCarry, 51U)) + 11700815697312060726U) + aNonceWordL;
            aOrbiterK = (aWandererB + RotL64(aIngress, 51U)) + 11808423452327465441U;
            aOrbiterD = ((aWandererK + RotL64(aPrevious, 60U)) + RotL64(aCarry, 21U)) + 8670503858631730886U;
            aOrbiterG = (((aWandererJ + RotL64(aScatter, 27U)) + 2400061067991988544U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordI;
            aOrbiterC = ((aWandererD + RotL64(aCross, 5U)) + 16163118178366229686U) + aNonceWordM;
            aOrbiterA = ((aWandererH + RotL64(aScatter, 21U)) + 3280178595904941068U) + aNonceWordO;
            aOrbiterH = (((aWandererF + RotL64(aIngress, 43U)) + RotL64(aCarry, 3U)) + 3298683600817047727U) + aPhaseHOrbiterAssignSaltD[((aIndex + 11U)) & S_SALT1];
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 16321624053445183574U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterD = (((aOrbiterD ^ aOrbiterF) ^ 6730229877611375225U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterD = RotL64((aOrbiterD * 2022290495153519279U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 10162830636713641322U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 15646771327759599256U;
            aOrbiterC = RotL64((aOrbiterC * 15333053762177144775U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 14841751262270544102U) + aNonceWordN;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 9545541117228834895U;
            aOrbiterH = RotL64((aOrbiterH * 11529769874752969377U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 14676615635857599982U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 1231768638470558855U;
            aOrbiterG = RotL64((aOrbiterG * 2716808508509014677U), 53U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 1945905595345404833U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 1406171421638586846U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 4577864352425476233U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 1970292335806697198U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 12309719390375013297U;
            aOrbiterK = RotL64((aOrbiterK * 16540660957923687327U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 5352135521358954576U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 15465675376193501658U;
            aOrbiterF = RotL64((aOrbiterF * 16385761112921041387U), 35U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterH, 57U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 3U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 21U));
            aIngress = aIngress + RotL64(aOrbiterF, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aCross, 21U) + aOrbiterC) + RotL64(aOrbiterG, 5U)) + RotL64(aCarry, 29U)) + aNonceWordJ);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 41U) + aOrbiterC) + RotL64(aOrbiterF, 60U));
            aWandererJ = aWandererJ + ((RotL64(aScatter, 35U) + RotL64(aOrbiterD, 53U)) + aOrbiterF);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterK, 41U)) + aOrbiterA) + aNonceWordA);
            aWandererF = aWandererF + (((RotL64(aScatter, 47U) + RotL64(aOrbiterH, 11U)) + aOrbiterC) + aPhaseHWandererUpdateSaltF[((aIndex + 24U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 28U) + aOrbiterD) + RotL64(aOrbiterC, 47U)) + aNonceWordH);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 53U) + RotL64(aOrbiterA, 29U)) + aOrbiterD) + RotL64(aCarry, 3U)) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 41U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 12U));
            aCarry = aCarry + (RotL64(aWandererJ, 57U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererH, 47U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 15203U)) & S_BLOCK1], 37U) ^ RotL64(aSnowLaneA[((aIndex + 12077U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aOperationLaneA[((aIndex + 16218U)) & S_BLOCK1], 4U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 11830U)) & S_BLOCK1], 46U) ^ RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 14068U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCross, 57U) + RotL64(aIngress, 29U)) + (RotL64(aPrevious, 43U) ^ RotL64(aCarry, 6U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterA = ((aWandererG + RotL64(aScatter, 37U)) + RotL64(aCarry, 57U)) + 4384716820085860551U;
            aOrbiterJ = (((aWandererD + RotL64(aIngress, 29U)) + 9715780315942116888U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordH;
            aOrbiterE = (aWandererJ + RotL64(aPrevious, 23U)) + 15963520052789178632U;
            aOrbiterK = ((aWandererF + RotL64(aCross, 11U)) + RotL64(aCarry, 39U)) + 14346700690686392938U;
            aOrbiterH = (aWandererC + RotL64(aPrevious, 4U)) + 6005518012489966643U;
            aOrbiterI = ((aWandererE + RotL64(aIngress, 43U)) + RotL64(aCarry, 11U)) + 2506732930310252119U;
            aOrbiterC = (((aWandererA + RotL64(aCross, 57U)) + 16782163084851775826U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 14U)) & S_SALT1]) + aNonceWordM;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 823673076571076303U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 1634084509064077736U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 1128407326773234517U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 1288134975466877686U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 2998220403162908444U;
            aOrbiterK = RotL64((aOrbiterK * 4321412662318298283U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 220430672180734911U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 10223923547068528867U) ^ aNonceWordJ;
            aOrbiterC = RotL64((aOrbiterC * 12577370238343872139U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 11696469696177647608U) + aNonceWordC;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 6545430420379636963U;
            aOrbiterA = RotL64((aOrbiterA * 8387163146257553773U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 79691451831797107U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 8971444023498649419U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7148919880477390009U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 5624403902454498793U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 9468064161002030997U;
            aOrbiterH = RotL64((aOrbiterH * 8243560528100864595U), 27U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 4619361544913629805U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 12682446273369750704U) ^ aNonceWordG;
            aOrbiterJ = RotL64((aOrbiterJ * 10879074713156075641U), 51U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterA, 47U);
            aIngress = aIngress + (RotL64(aOrbiterE, 37U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterH, 60U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterI, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 54U) + RotL64(aOrbiterK, 35U)) + aOrbiterI);
            aWandererC = aWandererC + (((RotL64(aIngress, 41U) + RotL64(aOrbiterK, 41U)) + aOrbiterJ) + aNonceWordN);
            aWandererA = aWandererA ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterA, 11U)) + aOrbiterI);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 35U) + RotL64(aOrbiterC, 58U)) + aOrbiterI) + RotL64(aCarry, 23U)) + aNonceWordL);
            aWandererD = aWandererD ^ (((RotL64(aCross, 29U) + aOrbiterH) + RotL64(aOrbiterK, 5U)) + aPhaseHWandererUpdateSaltE[((aIndex + 8U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 47U) + RotL64(aOrbiterE, 47U)) + aOrbiterA) + RotL64(aCarry, 11U)) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 19U) + aOrbiterH) + RotL64(aOrbiterC, 23U)) + aNonceWordI);
            //
            aCarry = aCarry + (RotL64(aWandererF, 3U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererE, 47U) ^ aWandererA);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 35U));
            aCarry = aCarry + RotL64(aWandererD, 12U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 21278U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneA[((aIndex + 21496U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aOperationLaneB[((aIndex + 17185U)) & S_BLOCK1], 54U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 19416U)) & S_BLOCK1], 12U) ^ RotL64(aSnowLaneD[((aIndex + 17725U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCarry, 23U) + RotL64(aPrevious, 10U)) ^ (RotL64(aCross, 35U) ^ RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterJ = ((((aWandererK + RotL64(aPrevious, 3U)) + RotL64(aCarry, 41U)) + 2672739400294801233U) + aPhaseHOrbiterAssignSaltF[((aIndex + 5U)) & S_SALT1]) + aNonceWordC;
            aOrbiterF = (((aWandererG + RotL64(aCross, 27U)) + RotL64(aCarry, 11U)) + 8475624545015101850U) + aNonceWordF;
            aOrbiterC = ((aWandererH + RotL64(aScatter, 11U)) + 1252755112289831257U) + aNonceWordE;
            aOrbiterG = (((aWandererF + RotL64(aIngress, 37U)) + RotL64(aCarry, 57U)) + 7938039507649183387U) + aNonceWordO;
            aOrbiterI = (aWandererA + RotL64(aScatter, 19U)) + 8167413146948861022U;
            aOrbiterH = (aWandererB + RotL64(aCross, 60U)) + 17712313989694374353U;
            aOrbiterK = ((aWandererJ + RotL64(aPrevious, 53U)) + 7637042279892596975U) + aPhaseHOrbiterAssignSaltC[((aIndex + 9U)) & S_SALT1];
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 15770412950033467341U) + aNonceWordH;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 3951812021898608685U;
            aOrbiterC = RotL64((aOrbiterC * 6623127125223204737U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 8656983621098246507U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 17943342344730687317U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 16495519451034883813U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 3087677463651608668U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 16493240011924342788U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 16898479041530771871U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 7750923317452683057U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 2185924841611106546U;
            aOrbiterK = RotL64((aOrbiterK * 708072658250726381U), 5U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterK) + 14676868738946722416U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1]) + aNonceWordD;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 6849098251696302393U;
            aOrbiterH = RotL64((aOrbiterH * 2599806275837778069U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 17817755047153606419U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 9900465270314068757U;
            aOrbiterG = RotL64((aOrbiterG * 9267925873983176685U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 11380000891112113701U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 15930503831156546113U;
            aOrbiterJ = RotL64((aOrbiterJ * 14450535035065393845U), 27U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterF, 39U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 13U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 60U));
            aIngress = aIngress + RotL64(aOrbiterG, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aPrevious, 47U) + RotL64(aOrbiterI, 35U)) + aOrbiterH) + RotL64(aCarry, 5U)) + aNonceWordN);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 11U) + RotL64(aOrbiterK, 13U)) + aOrbiterG) + aPhaseHWandererUpdateSaltD[((aIndex + 4U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 53U) + aOrbiterF) + RotL64(aOrbiterH, 29U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 29U) + aOrbiterG) + RotL64(aOrbiterF, 21U));
            aWandererF = aWandererF + (((((RotL64(aIngress, 5U) + aOrbiterJ) + RotL64(aOrbiterC, 42U)) + RotL64(aCarry, 21U)) + aNonceWordG) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 22U) + RotL64(aOrbiterG, 51U)) + aOrbiterI) + aNonceWordJ);
            aWandererA = aWandererA + ((RotL64(aPrevious, 39U) + aOrbiterG) + RotL64(aOrbiterC, 3U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 42U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 35U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 23U));
            aCarry = aCarry + RotL64(aWandererK, 19U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 24017U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneB[((aIndex + 23812U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 26905U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 26433U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneA[((aIndex + 24460U)) & S_BLOCK1], 44U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aIngress, 35U) ^ RotL64(aCross, 4U)) ^ (RotL64(aCarry, 19U) + RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterB = ((aWandererC + RotL64(aCross, 53U)) + RotL64(aCarry, 43U)) + 17225673071833726819U;
            aOrbiterD = (aWandererH + RotL64(aPrevious, 47U)) + 10301458382103627331U;
            aOrbiterK = ((((aWandererJ + RotL64(aScatter, 3U)) + RotL64(aCarry, 57U)) + 3960233050857362414U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordP;
            aOrbiterI = (((aWandererG + RotL64(aIngress, 11U)) + RotL64(aCarry, 19U)) + 17768665685046605837U) + aNonceWordF;
            aOrbiterA = ((aWandererK + RotL64(aCross, 28U)) + 14471018461213959767U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = (aWandererA + RotL64(aPrevious, 41U)) + 10730597892721340453U;
            aOrbiterG = (aWandererE + RotL64(aIngress, 35U)) + 14863394003122760542U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 9948587274816688296U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 3573569431435100993U) ^ aNonceWordD;
            aOrbiterK = RotL64((aOrbiterK * 2303922230056523077U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 8153670675740450590U) + aNonceWordI;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 16438856577722561424U;
            aOrbiterA = RotL64((aOrbiterA * 4689247488336908827U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 15765587867581925041U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 1082039522061775213U;
            aOrbiterI = RotL64((aOrbiterI * 17023740047246402641U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 4202521649260798876U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 15877659681260461141U;
            aOrbiterB = RotL64((aOrbiterB * 11369910758551088173U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 2551560426129646123U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 3005102326163906320U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 4241583192662435107U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 1675501058857208089U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 12774812270956702043U;
            aOrbiterD = RotL64((aOrbiterD * 5488437008504905105U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 1044886020922563597U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterA) ^ 4857445127457225171U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterE = RotL64((aOrbiterE * 13223560654459705259U), 35U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterI, 19U);
            aIngress = aIngress + (RotL64(aOrbiterD, 44U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterG, 27U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterK, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 43U) + RotL64(aOrbiterA, 27U)) + aOrbiterK) + RotL64(aCarry, 13U)) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 5U) + RotL64(aOrbiterK, 13U)) + aOrbiterE) + aNonceWordH);
            aWandererH = aWandererH + (((RotL64(aScatter, 11U) + RotL64(aOrbiterD, 51U)) + aOrbiterE) + aNonceWordE);
            aWandererA = aWandererA ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterB, 35U)) + aOrbiterD);
            aWandererC = aWandererC + ((((RotL64(aIngress, 57U) + aOrbiterK) + RotL64(aOrbiterI, 5U)) + aNonceWordG) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 37U) + RotL64(aOrbiterB, 58U)) + aOrbiterA) + aNonceWordB);
            aWandererG = aWandererG + (((RotL64(aCross, 18U) + RotL64(aOrbiterG, 43U)) + aOrbiterI) + RotL64(aCarry, 29U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 3U));
            aCarry = aCarry + (RotL64(aWandererH, 53U) ^ aWandererJ);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 38U));
            aCarry = aCarry + RotL64(aWandererG, 47U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 28704U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneA[((aIndex + 31589U)) & S_BLOCK1], 50U));
            aIngress ^= RotL64(aOperationLaneD[((aIndex + 31887U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29820U)) & S_BLOCK1], 51U) ^ RotL64(aSnowLaneB[((aIndex + 31904U)) & S_BLOCK1], 42U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCarry, 53U) + RotL64(aIngress, 41U)) ^ (RotL64(aPrevious, 5U) ^ RotL64(aCross, 26U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterI = ((aWandererA + RotL64(aCross, 57U)) + 13687218104610230596U) + aNonceWordG;
            aOrbiterJ = ((aWandererK + RotL64(aIngress, 29U)) + RotL64(aCarry, 57U)) + 6841550124960692709U;
            aOrbiterF = (((aWandererI + RotL64(aPrevious, 23U)) + 17418968668458764131U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordC;
            aOrbiterK = ((aWandererG + RotL64(aScatter, 14U)) + 8303537912696948204U) + aNonceWordE;
            aOrbiterH = (aWandererC + RotL64(aIngress, 37U)) + 12376614417285936537U;
            aOrbiterE = ((aWandererF + RotL64(aScatter, 3U)) + RotL64(aCarry, 29U)) + 14215749063579232654U;
            aOrbiterD = (((aWandererH + RotL64(aPrevious, 47U)) + RotL64(aCarry, 5U)) + 4111736931433665347U) + aPhaseHOrbiterAssignSaltE[((aIndex + 4U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 11250375934571631522U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 5367367837773331275U) ^ aNonceWordP;
            aOrbiterF = RotL64((aOrbiterF * 7262723007545807179U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 15514089192382674434U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 1475991716685034960U;
            aOrbiterH = RotL64((aOrbiterH * 17720681295551650891U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 5531622777788629748U) + aNonceWordF;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 8363822215908303335U;
            aOrbiterE = RotL64((aOrbiterE * 17850203366840994883U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 3741256932685720414U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 11634667238062155772U;
            aOrbiterI = RotL64((aOrbiterI * 15925089729784547403U), 43U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 18180546911210417155U) + aNonceWordA;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 5123234656838556335U) ^ aNonceWordI;
            aOrbiterJ = RotL64((aOrbiterJ * 15362857462853398025U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 11215734271189250284U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 16863747802158398092U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 1828035970246160023U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 9859050606636646323U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 9331300036643654675U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2502263410556166281U), 29U);
            //
            aIngress = RotL64(aOrbiterI, 21U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 3U));
            aIngress = aIngress + (RotL64(aOrbiterE, 29U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterH, 46U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 57U) + aOrbiterH) + RotL64(aOrbiterD, 3U));
            aWandererK = aWandererK + (((RotL64(aIngress, 42U) + RotL64(aOrbiterH, 21U)) + aOrbiterI) + aNonceWordB);
            aWandererC = aWandererC ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterI, 29U)) + aOrbiterF) + aPhaseHWandererUpdateSaltE[((aIndex + 9U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aScatter, 35U) + aOrbiterD) + RotL64(aOrbiterF, 51U)) + RotL64(aCarry, 19U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 19U) + aOrbiterH) + RotL64(aOrbiterK, 40U)) + aNonceWordO);
            aWandererA = aWandererA + (((RotL64(aIngress, 51U) + aOrbiterJ) + RotL64(aOrbiterE, 57U)) + RotL64(aCarry, 3U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 13U) + aOrbiterJ) + RotL64(aOrbiterD, 13U)) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 51U) ^ aWandererA);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 41U));
            aCarry = aCarry + (RotL64(aWandererG, 18U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererC, 57U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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

void TwistExpander_PingPong_Arx::Twist_A(TwistWorkSpace *pWorkSpace,
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
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltB;
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
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltF;
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
            aIngress = RotL64(aKeyRowReadA[((aIndex + 471U)) & W_KEY1], 56U) ^ RotL64(aKeyRowReadB[((aIndex + 2136U)) & W_KEY1], 29U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 1127U)) & W_KEY1], 37U) ^ RotL64(mSource[((aIndex + 2620U)) & S_BLOCK1], 20U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 4U) ^ RotL64(aCarry, 37U)) ^ (RotL64(aIngress, 19U) + RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterA = ((aWandererA + RotL64(aScatter, 13U)) + RotL64(aCarry, 51U)) + 14499676118633326000U;
            aOrbiterE = ((aWandererI + RotL64(aCross, 36U)) + RotL64(aCarry, 19U)) + 17191273593018552288U;
            aOrbiterC = (aWandererJ + RotL64(aIngress, 23U)) + 4085176294948097737U;
            aOrbiterD = ((aWandererG + RotL64(aPrevious, 41U)) + RotL64(aCarry, 29U)) + 11112671474158908186U;
            aOrbiterJ = (aWandererB + RotL64(aScatter, 19U)) + 8745787969012266485U;
            aOrbiterB = ((aWandererC + RotL64(aIngress, 47U)) + 18074049663777707948U) + aPhaseAOrbiterAssignSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterI = (aWandererH + RotL64(aPrevious, 53U)) + 2543758649719164688U;
            aOrbiterG = (aWandererF + RotL64(aCross, 57U)) + 4659584749412700523U;
            aOrbiterF = ((aWandererK + RotL64(aPrevious, 6U)) + 974639159259871273U) + aPhaseAOrbiterAssignSaltD[((aIndex + 26U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 9211220687971081987U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 8567024626862182714U;
            aOrbiterC = RotL64((aOrbiterC * 7755874089832496393U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 5803002132294840900U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 11968489432878148467U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4501441062617123165U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 9470807228394903442U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 1692347973120388469U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 17433393164156231575U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 16510815732690193145U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 755159406833096510U;
            aOrbiterG = RotL64((aOrbiterG * 14091736464659561165U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 1518824876475937620U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 701225390867330446U;
            aOrbiterB = RotL64((aOrbiterB * 12264618860580199927U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 8425976693733003889U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 7182176375442410367U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8860605703761731859U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 4546566785167467924U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 2593340999038753749U;
            aOrbiterF = RotL64((aOrbiterF * 10152461487764567563U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 9756331608356622299U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 5511625814747641978U;
            aOrbiterA = RotL64((aOrbiterA * 4806076157539829529U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 8694400787420160733U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 12648969491371382682U;
            aOrbiterE = RotL64((aOrbiterE * 5346585704222643759U), 39U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterG, 23U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 14U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 57U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 19U));
            aIngress = aIngress + RotL64(aOrbiterB, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aIngress, 58U) + aOrbiterB) + RotL64(aOrbiterE, 39U)) + RotL64(aCarry, 47U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 19U) + aOrbiterF) + RotL64(aOrbiterB, 22U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 39U) + aOrbiterD) + RotL64(aOrbiterJ, 57U)) + RotL64(aCarry, 19U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterB, 35U)) + aOrbiterD);
            aWandererA = aWandererA + ((RotL64(aIngress, 43U) + RotL64(aOrbiterG, 3U)) + aOrbiterB);
            aWandererI = aWandererI ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterA, 27U)) + aOrbiterI);
            aWandererF = aWandererF + ((RotL64(aScatter, 29U) + RotL64(aOrbiterI, 53U)) + aOrbiterJ);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 12U) + RotL64(aOrbiterE, 44U)) + aOrbiterI) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 3U) + aOrbiterA) + RotL64(aOrbiterC, 11U)) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererF);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 34U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 51U));
            aCarry = aCarry + (RotL64(aWandererA, 39U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererC, 47U);
            aCarry = aCarry + RotL64(aIngress, 60U);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 2847U)) & S_BLOCK1], 53U) ^ RotL64(aKeyRowReadA[((aIndex + 3514U)) & W_KEY1], 10U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 4614U)) & W_KEY1], 11U) ^ RotL64(mSource[((aIndex + 4401U)) & S_BLOCK1], 24U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 53U) + RotL64(aIngress, 4U)) ^ (RotL64(aPrevious, 41U) ^ RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterJ = (aWandererE + RotL64(aCross, 21U)) + 12632404972795375757U;
            aOrbiterI = ((aWandererH + RotL64(aScatter, 47U)) + 5351879979055988456U) + aPhaseAOrbiterAssignSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = (aWandererJ + RotL64(aIngress, 43U)) + 3597737727467443413U;
            aOrbiterB = (aWandererB + RotL64(aPrevious, 27U)) + 2830846754917852318U;
            aOrbiterC = (aWandererF + RotL64(aScatter, 56U)) + 17311925960294518018U;
            aOrbiterG = (((aWandererG + RotL64(aPrevious, 13U)) + RotL64(aCarry, 3U)) + 2083584640523695383U) + aPhaseAOrbiterAssignSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = ((aWandererC + RotL64(aIngress, 3U)) + RotL64(aCarry, 41U)) + 15049343611387010158U;
            aOrbiterD = ((aWandererK + RotL64(aCross, 51U)) + RotL64(aCarry, 57U)) + 6443050378205811147U;
            aOrbiterA = (aWandererI + RotL64(aScatter, 60U)) + 6021965178697344070U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 5080289878758029976U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 576927745306972983U;
            aOrbiterF = RotL64((aOrbiterF * 16008958833683246115U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 4728489691382690859U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 6184355840165758855U;
            aOrbiterG = RotL64((aOrbiterG * 1515043910404156423U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 11220539885798595450U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 11091438724966718214U;
            aOrbiterH = RotL64((aOrbiterH * 8225347114759391961U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 17184210490020062419U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 2150997767099116408U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8058553821648892499U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 7021953562676903717U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 17159676348343312834U;
            aOrbiterA = RotL64((aOrbiterA * 13877284519668483549U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 10367891770525239784U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 11922478487264201233U;
            aOrbiterI = RotL64((aOrbiterI * 9195137452661956029U), 27U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 17815162358981720634U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 9582631251085100284U;
            aOrbiterJ = RotL64((aOrbiterJ * 11838992994130850483U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 872593750259572264U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 17832330100262167302U;
            aOrbiterB = RotL64((aOrbiterB * 1114416841510028467U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 16601139856969287418U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 14931287111691324985U;
            aOrbiterC = RotL64((aOrbiterC * 16757174577841001179U), 23U);
            //
            aIngress = RotL64(aOrbiterJ, 34U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 37U));
            aIngress = aIngress + (RotL64(aOrbiterF, 41U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterA, 13U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterD, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterF, 34U)) + aOrbiterH);
            aWandererG = aWandererG + ((RotL64(aCross, 60U) + RotL64(aOrbiterA, 3U)) + aOrbiterG);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 19U) + RotL64(aOrbiterB, 27U)) + aOrbiterJ) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 35U) + RotL64(aOrbiterF, 47U)) + aOrbiterD) + RotL64(aCarry, 3U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterG, 19U)) + aOrbiterB);
            aWandererK = aWandererK + ((RotL64(aCross, 30U) + RotL64(aOrbiterD, 13U)) + aOrbiterA);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterC, 38U)) + aOrbiterI);
            aWandererI = aWandererI + ((((RotL64(aIngress, 47U) + aOrbiterI) + RotL64(aOrbiterD, 57U)) + RotL64(aCarry, 19U)) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterD, 51U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererE, 42U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererJ, 57U) ^ aWandererI);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 47U));
            aCarry = aCarry + (RotL64(aWandererK, 39U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererG, 36U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = RotL64(aFireLaneB[((aIndex + 7791U)) & S_BLOCK1], 35U) ^ RotL64(aKeyRowReadB[((aIndex + 7719U)) & W_KEY1], 10U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 7594U)) & W_KEY1], 47U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 6802U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 5471U)) & S_BLOCK1], 58U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 43U) + RotL64(aCross, 5U)) + (RotL64(aIngress, 57U) ^ RotL64(aCarry, 20U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterF = (aWandererC + RotL64(aIngress, 27U)) + 10915618884692072446U;
            aOrbiterJ = ((aWandererK + RotL64(aPrevious, 41U)) + 12634922308499254909U) + aPhaseAOrbiterAssignSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = ((aWandererB + RotL64(aCross, 12U)) + 6533934734564499389U) + aPhaseAOrbiterAssignSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = (aWandererF + RotL64(aScatter, 3U)) + 6744203303756105181U;
            aOrbiterA = ((aWandererE + RotL64(aCross, 47U)) + RotL64(aCarry, 19U)) + 13086782386652045658U;
            aOrbiterB = ((aWandererJ + RotL64(aScatter, 19U)) + RotL64(aCarry, 35U)) + 5693840533331397822U;
            aOrbiterH = ((aWandererG + RotL64(aPrevious, 51U)) + RotL64(aCarry, 57U)) + 1803663542535024611U;
            aOrbiterI = (aWandererH + RotL64(aIngress, 36U)) + 3597219300593287708U;
            aOrbiterD = (aWandererA + RotL64(aCross, 57U)) + 1429753448204448904U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 17229017825587322715U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 1137574712801062932U;
            aOrbiterK = RotL64((aOrbiterK * 3645832160939819415U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 2401991077004083378U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 1332473247826139292U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 15029831858261506447U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 11730946340796899885U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 15319163439700390962U;
            aOrbiterH = RotL64((aOrbiterH * 1349242001887975499U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 4744141870145159917U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 6067132201862688684U;
            aOrbiterF = RotL64((aOrbiterF * 6046100687757836027U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 14991509179286371800U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 4342608825699398682U;
            aOrbiterI = RotL64((aOrbiterI * 10240526103933275875U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 3727521409410742075U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 3302027219498304367U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 12153634588200479559U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 6039539483340398858U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 2902581519976937051U;
            aOrbiterE = RotL64((aOrbiterE * 2057584328877854239U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 12332784713738947242U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 13761272577223712786U;
            aOrbiterB = RotL64((aOrbiterB * 14930145045480030821U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 2947946397617043735U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 11107014023853644521U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 15030903626191481831U), 11U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterA, 57U);
            aIngress = aIngress + (RotL64(aOrbiterK, 60U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterJ, 43U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterE, 19U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterF, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aScatter, 35U) + aOrbiterE) + RotL64(aOrbiterF, 39U)) + aPhaseAWandererUpdateSaltE[((aIndex + 13U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aIngress, 48U) + aOrbiterF) + RotL64(aOrbiterK, 52U)) + RotL64(aCarry, 27U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterA, 57U)) + aOrbiterE);
            aWandererC = aWandererC + (((RotL64(aCross, 3U) + aOrbiterJ) + RotL64(aOrbiterK, 29U)) + RotL64(aCarry, 19U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 39U) + aOrbiterH) + RotL64(aOrbiterI, 13U));
            aWandererH = aWandererH + ((RotL64(aPrevious, 57U) + aOrbiterH) + RotL64(aOrbiterJ, 47U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 26U) + RotL64(aOrbiterB, 35U)) + aOrbiterA);
            aWandererA = aWandererA + (((RotL64(aCross, 13U) + aOrbiterB) + RotL64(aOrbiterD, 5U)) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterI, 22U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 4U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererB, 39U) ^ aWandererE);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 35U));
            aCarry = aCarry + (RotL64(aWandererF, 27U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererH, 53U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 9834U)) & S_BLOCK1], 43U) ^ RotL64(aKeyRowReadB[((aIndex + 10681U)) & W_KEY1], 13U));
            aIngress ^= (RotL64(mSource[((aIndex + 9023U)) & S_BLOCK1], 22U) ^ RotL64(aFireLaneA[((aIndex + 8658U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 10162U)) & W_KEY1], 29U) ^ RotL64(aFireLaneB[((aIndex + 9210U)) & S_BLOCK1], 14U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 37U) ^ RotL64(aPrevious, 5U)) + (RotL64(aCarry, 51U) + RotL64(aIngress, 20U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterC = (aWandererA + RotL64(aCross, 13U)) + 5960680319644404115U;
            aOrbiterA = (aWandererF + RotL64(aScatter, 23U)) + 16050752633567034185U;
            aOrbiterE = (((aWandererJ + RotL64(aPrevious, 29U)) + RotL64(aCarry, 21U)) + 8447503223226854741U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = ((aWandererH + RotL64(aIngress, 34U)) + RotL64(aCarry, 41U)) + 14176813813397917591U;
            aOrbiterH = (aWandererB + RotL64(aPrevious, 19U)) + 10534915376130006644U;
            aOrbiterK = (aWandererE + RotL64(aCross, 51U)) + 6866224454375302514U;
            aOrbiterI = (((aWandererG + RotL64(aScatter, 43U)) + RotL64(aCarry, 53U)) + 16506374165041008396U) + aPhaseBOrbiterAssignSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = (aWandererK + RotL64(aIngress, 6U)) + 7167814023968794098U;
            aOrbiterG = (aWandererC + RotL64(aCross, 57U)) + 13870852197416596664U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 18064038854848993105U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 9869630811507771691U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 13723164383800461387U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 863613100452759380U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 16597969741225436529U;
            aOrbiterH = RotL64((aOrbiterH * 2680793528887208903U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 6575347108051310653U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 17062262265485019063U;
            aOrbiterI = RotL64((aOrbiterI * 7601045488473620019U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 7193399224636409133U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 14146747818810433849U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5273185769989530041U), 39U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 9441449106442431427U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 4303295336545399503U;
            aOrbiterA = RotL64((aOrbiterA * 8829695296836242587U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 12604760768543193458U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 15779327512379787715U;
            aOrbiterD = RotL64((aOrbiterD * 14000905201441272597U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 15553000781122708728U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 17162740616060079717U;
            aOrbiterJ = RotL64((aOrbiterJ * 9458662233556750239U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 1032374679817715156U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 16413393156165548232U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 549659738811935015U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 14056855000013992045U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 7399202019042538829U;
            aOrbiterC = RotL64((aOrbiterC * 6103508549612077695U), 57U);
            //
            aIngress = RotL64(aOrbiterH, 5U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterE, 51U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 44U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 27U));
            aIngress = aIngress + RotL64(aOrbiterK, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aCross, 18U) + aOrbiterD) + RotL64(aOrbiterH, 19U)) + aPhaseBWandererUpdateSaltE[((aIndex + 28U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 27U) + aOrbiterJ) + RotL64(aOrbiterE, 51U));
            aWandererK = aWandererK + (((RotL64(aIngress, 23U) + aOrbiterG) + RotL64(aOrbiterE, 39U)) + RotL64(aCarry, 35U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 51U) + aOrbiterD) + RotL64(aOrbiterE, 56U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 47U) + aOrbiterA) + RotL64(aOrbiterI, 47U)) + RotL64(aCarry, 21U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 57U) + aOrbiterK) + RotL64(aOrbiterD, 11U));
            aWandererG = aWandererG + ((RotL64(aCross, 14U) + RotL64(aOrbiterD, 27U)) + aOrbiterG);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 3U) + aOrbiterC) + RotL64(aOrbiterE, 43U)) + aPhaseBWandererUpdateSaltA[((aIndex + 16U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aCross, 41U) + RotL64(aOrbiterI, 60U)) + aOrbiterH);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 53U));
            aCarry = aCarry + (RotL64(aWandererA, 35U) ^ aWandererJ);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 57U));
            aCarry = aCarry + (RotL64(aWandererE, 26U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererC, 5U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 10992U)) & S_BLOCK1], 47U) ^ RotL64(aKeyRowReadA[((aIndex + 11417U)) & W_KEY1], 29U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 12843U)) & W_KEY1], 58U) ^ RotL64(mSource[((aIndex + 13388U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 13052U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 12385U)) & S_BLOCK1], 26U) ^ RotL64(aFireLaneC[((aIndex + 12932U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 4U) ^ RotL64(aIngress, 51U)) ^ (RotL64(aPrevious, 35U) + RotL64(aCross, 21U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterB = (aWandererB + RotL64(aPrevious, 6U)) + 12849591986267890852U;
            aOrbiterE = (aWandererJ + RotL64(aScatter, 57U)) + 8232614804696815750U;
            aOrbiterJ = ((aWandererK + RotL64(aIngress, 47U)) + RotL64(aCarry, 13U)) + 12141567259210877281U;
            aOrbiterI = (aWandererA + RotL64(aCross, 53U)) + 2928641981037885644U;
            aOrbiterF = (aWandererC + RotL64(aIngress, 19U)) + 980733350554783938U;
            aOrbiterA = (aWandererF + RotL64(aScatter, 23U)) + 2683985177993350746U;
            aOrbiterD = ((aWandererE + RotL64(aPrevious, 43U)) + RotL64(aCarry, 43U)) + 14532148403815527355U;
            aOrbiterK = (((aWandererH + RotL64(aCross, 11U)) + RotL64(aCarry, 21U)) + 7736296629433884203U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterC = ((aWandererD + RotL64(aPrevious, 28U)) + 10428437770166310549U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 18327174144859461029U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 6810436935194432002U;
            aOrbiterJ = RotL64((aOrbiterJ * 2715987179577753597U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 12606153309690753435U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 17123256945895150555U;
            aOrbiterF = RotL64((aOrbiterF * 13469111258504672565U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 9057777759026189541U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 16478485918911194442U;
            aOrbiterD = RotL64((aOrbiterD * 11054247078884894131U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 18064460487552100483U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 11477276762421684083U;
            aOrbiterC = RotL64((aOrbiterC * 3886501230380184395U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 18318375441973295081U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 13849305985380030986U;
            aOrbiterA = RotL64((aOrbiterA * 12962140243967824959U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 10240409420338313641U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 18360586077779529086U;
            aOrbiterI = RotL64((aOrbiterI * 18196875422391501927U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 16801797158622424257U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 4950305991208513887U;
            aOrbiterE = RotL64((aOrbiterE * 4437082499761416951U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 15790878572843321918U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 9808781805065559728U;
            aOrbiterB = RotL64((aOrbiterB * 9394280083159162953U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 11974996650410830731U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 4955004489435232515U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13301966529515483085U), 13U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterB, 42U);
            aIngress = aIngress + (RotL64(aOrbiterC, 3U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 21U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 51U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterI, 46U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 53U) + aOrbiterB) + RotL64(aOrbiterE, 44U));
            aWandererH = aWandererH + ((RotL64(aScatter, 26U) + aOrbiterD) + RotL64(aOrbiterB, 19U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterA, 35U)) + aOrbiterK) + aPhaseBWandererUpdateSaltC[((aIndex + 9U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aIngress, 19U) + RotL64(aOrbiterD, 57U)) + aOrbiterI);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterK, 39U)) + aOrbiterC);
            aWandererB = aWandererB + (((RotL64(aScatter, 30U) + aOrbiterC) + RotL64(aOrbiterF, 23U)) + RotL64(aCarry, 29U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 35U) + aOrbiterF) + RotL64(aOrbiterD, 3U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterI, 52U)) + aOrbiterF) + RotL64(aCarry, 13U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 13U) + RotL64(aOrbiterB, 27U)) + aOrbiterJ) + aPhaseBWandererUpdateSaltD[((aIndex + 6U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 44U) ^ aWandererF);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 11U));
            aCarry = aCarry + (RotL64(aWandererH, 5U) ^ aWandererA);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 19U));
            aCarry = aCarry + RotL64(aWandererK, 58U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 16233U)) & S_BLOCK1], 44U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 14448U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 15735U)) & W_KEY1], 6U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 13928U)) & W_KEY1], 47U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 13893U)) & S_BLOCK1], 57U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 13929U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 14376U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 51U) ^ RotL64(aPrevious, 19U)) ^ (RotL64(aCarry, 39U) + RotL64(aIngress, 4U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterF = (aWandererG + RotL64(aScatter, 27U)) + 3255291173184001106U;
            aOrbiterE = (((aWandererF + RotL64(aCross, 34U)) + RotL64(aCarry, 39U)) + 15308468160116255528U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterB = (aWandererB + RotL64(aIngress, 47U)) + 18186972408589866656U;
            aOrbiterC = ((aWandererE + RotL64(aPrevious, 13U)) + RotL64(aCarry, 19U)) + 4439324265978331914U;
            aOrbiterA = (((aWandererK + RotL64(aScatter, 3U)) + RotL64(aCarry, 11U)) + 13099263173016322486U) + aPhaseBOrbiterAssignSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = (aWandererH + RotL64(aPrevious, 43U)) + 7041561081767500660U;
            aOrbiterD = (aWandererC + RotL64(aCross, 58U)) + 6196422612687812971U;
            aOrbiterH = (aWandererJ + RotL64(aIngress, 19U)) + 7664260932541281413U;
            aOrbiterI = (aWandererI + RotL64(aPrevious, 51U)) + 17802347823020441056U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 4253107484061190446U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 13799496534030645312U;
            aOrbiterB = RotL64((aOrbiterB * 9167675060053848207U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 14252892847595951926U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 5663527578664291422U;
            aOrbiterJ = RotL64((aOrbiterJ * 18314294235895182465U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 11148755959699137661U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 17036900929333594592U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 16041243617369003291U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 2403828181385259549U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 17813580350434928194U;
            aOrbiterI = RotL64((aOrbiterI * 13666780980793857831U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 5623611126885414523U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 7293224381174846969U;
            aOrbiterH = RotL64((aOrbiterH * 7032561584670788117U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 10602620906929686163U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 18015916257203385982U;
            aOrbiterA = RotL64((aOrbiterA * 10684090189688871993U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 13592915735376305773U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 13995866908043417505U;
            aOrbiterF = RotL64((aOrbiterF * 3802175869395887331U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 8200465989447697618U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 9866671660800629464U;
            aOrbiterE = RotL64((aOrbiterE * 2138851839905326265U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 11557528777230608777U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 131060617338185060U;
            aOrbiterD = RotL64((aOrbiterD * 11068705423012265209U), 35U);
            //
            aIngress = RotL64(aOrbiterA, 27U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterC, 40U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 23U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 3U));
            aIngress = aIngress + RotL64(aOrbiterH, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aCross, 23U) + aOrbiterI) + RotL64(aOrbiterE, 12U));
            aWandererE = aWandererE + ((((RotL64(aScatter, 14U) + aOrbiterB) + RotL64(aOrbiterD, 29U)) + RotL64(aCarry, 11U)) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 19U) + aOrbiterJ) + RotL64(aOrbiterI, 3U));
            aWandererK = aWandererK + ((RotL64(aIngress, 3U) + RotL64(aOrbiterC, 47U)) + aOrbiterI);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 57U) + aOrbiterA) + RotL64(aOrbiterB, 35U));
            aWandererC = aWandererC + ((RotL64(aScatter, 35U) + RotL64(aOrbiterH, 39U)) + aOrbiterJ);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterI, 21U)) + aOrbiterB);
            aWandererH = aWandererH + (((RotL64(aIngress, 53U) + RotL64(aOrbiterD, 52U)) + aOrbiterI) + RotL64(aCarry, 21U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 44U) + RotL64(aOrbiterJ, 43U)) + aOrbiterF) + aPhaseBWandererUpdateSaltF[((aIndex + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 27U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererK, 53U) ^ aWandererG);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 23U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 20U));
            aCarry = aCarry + RotL64(aWandererE, 39U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 16479U)) & S_BLOCK1], 58U) ^ RotL64(aKeyRowReadA[((aIndex + 18263U)) & W_KEY1], 23U));
            aIngress ^= (RotL64(mSource[((aIndex + 18337U)) & S_BLOCK1], 5U) ^ RotL64(aFireLaneA[((aIndex + 17405U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 16529U)) & W_KEY1], 43U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 17889U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18622U)) & S_BLOCK1], 28U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 56U) + RotL64(aIngress, 43U)) ^ (RotL64(aCross, 27U) + RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterC = ((aWandererF + RotL64(aIngress, 47U)) + RotL64(aCarry, 3U)) + 11698283336767769359U;
            aOrbiterI = (aWandererH + RotL64(aScatter, 19U)) + 13297826354831483872U;
            aOrbiterB = (aWandererI + RotL64(aCross, 38U)) + 15254999058287530795U;
            aOrbiterA = ((aWandererD + RotL64(aPrevious, 11U)) + RotL64(aCarry, 19U)) + 17474166585085346567U;
            aOrbiterE = ((aWandererK + RotL64(aIngress, 5U)) + 15684783498452840289U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = ((aWandererJ + RotL64(aPrevious, 43U)) + 5061229733465216486U) + aPhaseCOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = (aWandererE + RotL64(aScatter, 57U)) + 15370981279168377944U;
            aOrbiterH = (aWandererG + RotL64(aCross, 52U)) + 17966672773619554092U;
            aOrbiterJ = ((aWandererB + RotL64(aScatter, 23U)) + RotL64(aCarry, 47U)) + 14685092893994491068U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 12798804186209406389U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 2848444181474221574U) ^ aPhaseCOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 13730480364920876877U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 8551142075919636146U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 8833198159158950723U;
            aOrbiterE = RotL64((aOrbiterE * 7650289040764974737U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 7351473160893666232U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 14204899612487622222U;
            aOrbiterF = RotL64((aOrbiterF * 6317485031956448029U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 7008985178526543258U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 13576796403863120356U;
            aOrbiterH = RotL64((aOrbiterH * 13745839827679114077U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 5769784656937900699U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 14075925808204936705U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 5844894088757604713U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 17818667502858010896U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 16016922065572683130U;
            aOrbiterK = RotL64((aOrbiterK * 7525645833898085373U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 1582458237855075977U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 10830440354527138227U;
            aOrbiterA = RotL64((aOrbiterA * 10499386926982228251U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 10653964151654643772U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 11218475491129483859U;
            aOrbiterC = RotL64((aOrbiterC * 3338108067044357141U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 9863649760189649255U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 13790281439048354358U) ^ aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 4682098083538482849U), 3U);
            //
            aIngress = RotL64(aOrbiterB, 14U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterI, 21U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 3U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 53U));
            aIngress = aIngress + RotL64(aOrbiterJ, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aIngress, 28U) + aOrbiterJ) + RotL64(aOrbiterA, 47U)) + RotL64(aCarry, 39U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterF, 51U)) + aOrbiterB);
            aWandererH = aWandererH + ((RotL64(aPrevious, 35U) + RotL64(aOrbiterA, 6U)) + aOrbiterE);
            aWandererG = aWandererG ^ ((RotL64(aCross, 19U) + aOrbiterC) + RotL64(aOrbiterH, 35U));
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 53U) + aOrbiterF) + RotL64(aOrbiterE, 57U)) + RotL64(aCarry, 19U)) + aPhaseCWandererUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 41U) + aOrbiterB) + RotL64(aOrbiterC, 13U));
            aWandererK = aWandererK + ((RotL64(aIngress, 6U) + RotL64(aOrbiterI, 29U)) + aOrbiterA);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 23U) + aOrbiterJ) + RotL64(aOrbiterH, 19U)) + aPhaseCWandererUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aIngress, 13U) + RotL64(aOrbiterK, 40U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 35U));
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererJ);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 39U));
            aCarry = aCarry + (RotL64(aWandererE, 47U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererG, 14U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 21205U)) & S_BLOCK1], 3U) ^ RotL64(mSource[((aIndex + 21197U)) & S_BLOCK1], 24U));
            aIngress ^= (RotL64(aWorkLaneA[((aIndex + 19835U)) & S_BLOCK1], 39U) ^ RotL64(aFireLaneA[((aIndex + 20537U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 21061U)) & W_KEY1], 39U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 21669U)) & W_KEY1], 60U));
            aCross ^= (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 20432U)) & S_BLOCK1], 47U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 19533U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aPrevious, 54U)) ^ (RotL64(aCarry, 21U) + RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterE = (((aWandererE + RotL64(aPrevious, 43U)) + RotL64(aCarry, 41U)) + 6654158889644956636U) + aPhaseCOrbiterAssignSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterI = (aWandererJ + RotL64(aScatter, 20U)) + 9045779659363991870U;
            aOrbiterJ = ((aWandererB + RotL64(aIngress, 29U)) + RotL64(aCarry, 5U)) + 3888897662136993491U;
            aOrbiterA = (aWandererI + RotL64(aCross, 53U)) + 6882016842864459345U;
            aOrbiterK = ((aWandererK + RotL64(aIngress, 57U)) + 15601891715956172291U) + aPhaseCOrbiterAssignSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = ((aWandererD + RotL64(aCross, 11U)) + RotL64(aCarry, 13U)) + 5176811598629335350U;
            aOrbiterB = (aWandererA + RotL64(aScatter, 36U)) + 12519945150889074325U;
            aOrbiterD = (aWandererF + RotL64(aPrevious, 47U)) + 4552583214397603278U;
            aOrbiterC = (aWandererC + RotL64(aIngress, 3U)) + 14225482701804864688U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 5485298070606280363U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 11237713257388094289U;
            aOrbiterJ = RotL64((aOrbiterJ * 11032429223099413011U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 14340345895626142788U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 16275167270553643347U;
            aOrbiterK = RotL64((aOrbiterK * 7308578867128951199U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 14041860597556520250U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 1436068974197066343U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 3938460345031496843U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 11483155566419547004U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 4608508534724289325U;
            aOrbiterD = RotL64((aOrbiterD * 13461385011638899485U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 2389196334288832895U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 4062682330273866602U) ^ aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8787682133271101901U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 5655656046585592034U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 7977947821249746880U;
            aOrbiterH = RotL64((aOrbiterH * 10082104644185964787U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 11653718118543974168U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 5456429682072377614U;
            aOrbiterB = RotL64((aOrbiterB * 12504180638665296649U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 12457179652004203574U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 445821754230182952U) ^ aPhaseCOrbiterUpdateSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 16043092621697786393U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 12429505513284703263U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 12480745784412363537U;
            aOrbiterE = RotL64((aOrbiterE * 643617210585287593U), 35U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterB, 57U);
            aIngress = aIngress + (RotL64(aOrbiterI, 42U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterD, 29U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterE, 5U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterJ, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aScatter, 48U) + aOrbiterJ) + RotL64(aOrbiterE, 39U));
            aWandererD = aWandererD + (((RotL64(aIngress, 19U) + RotL64(aOrbiterI, 24U)) + aOrbiterA) + aPhaseCWandererUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 43U) + aOrbiterD) + RotL64(aOrbiterI, 43U));
            aWandererF = aWandererF + ((((RotL64(aCross, 53U) + aOrbiterE) + RotL64(aOrbiterI, 51U)) + RotL64(aCarry, 3U)) + aPhaseCWandererUpdateSaltC[((aIndex + 20U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 23U) + aOrbiterH) + RotL64(aOrbiterE, 19U));
            aWandererA = aWandererA + ((RotL64(aIngress, 13U) + aOrbiterC) + RotL64(aOrbiterK, 47U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterJ, 11U)) + aOrbiterB);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 27U) + aOrbiterK) + RotL64(aOrbiterD, 57U)) + RotL64(aCarry, 41U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 60U) + aOrbiterD) + RotL64(aOrbiterE, 4U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 40U) ^ aWandererI);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 13U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 51U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 47U));
            aCarry = aCarry + RotL64(aWandererE, 19U);
            aCarry = aCarry + RotL64(aIngress, 6U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneD[((aIndex + 22004U)) & S_BLOCK1], 4U) ^ RotL64(aKeyRowReadA[((aIndex + 22506U)) & W_KEY1], 43U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 24017U)) & W_KEY1], 13U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 23438U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 22573U)) & S_BLOCK1], 28U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22375U)) & S_BLOCK1], 37U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 23263U)) & S_BLOCK1], 13U) ^ RotL64(aFireLaneD[((aIndex + 23697U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 14U) ^ RotL64(aPrevious, 57U)) ^ (RotL64(aCarry, 27U) + RotL64(aIngress, 41U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterE = ((aWandererD + RotL64(aScatter, 51U)) + 1888427424966603593U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterG = (aWandererB + RotL64(aIngress, 20U)) + 5436761445660415091U;
            aOrbiterJ = (aWandererA + RotL64(aPrevious, 27U)) + 17322876217962143270U;
            aOrbiterB = ((aWandererJ + RotL64(aCross, 35U)) + RotL64(aCarry, 29U)) + 9728299982740564979U;
            aOrbiterC = (aWandererH + RotL64(aIngress, 41U)) + 301720335271716921U;
            aOrbiterA = ((aWandererC + RotL64(aScatter, 5U)) + RotL64(aCarry, 3U)) + 8069685428854814396U;
            aOrbiterH = ((aWandererF + RotL64(aCross, 47U)) + 1973715500949100991U) + aPhaseCOrbiterAssignSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterF = (aWandererE + RotL64(aPrevious, 57U)) + 87666408799854155U;
            aOrbiterK = ((aWandererK + RotL64(aIngress, 10U)) + RotL64(aCarry, 51U)) + 12195436904339035245U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 4578742069143400295U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 7828776048774876484U;
            aOrbiterJ = RotL64((aOrbiterJ * 4047964518501081039U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 17203146364542781833U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 16913369550858890466U;
            aOrbiterC = RotL64((aOrbiterC * 13534417587921978507U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 9632761514552265402U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 9106637671877341286U) ^ aPhaseCOrbiterUpdateSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9073709119482640391U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 15423680889126750876U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 6087310684583331882U) ^ aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 8964465129744898619U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 5420955876411796789U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 14166807419730848032U;
            aOrbiterF = RotL64((aOrbiterF * 442659738632823751U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 8118312450347026824U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 4253043584558403086U;
            aOrbiterK = RotL64((aOrbiterK * 5651748455190536467U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 8810774678371762700U) + aPhaseCOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 12218479555589447835U) ^ aPhaseCOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11026364205248516355U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 11389930523582876358U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 16334420553471379915U;
            aOrbiterE = RotL64((aOrbiterE * 13830132212033904777U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 18201289372553710279U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 7196540389657785361U;
            aOrbiterG = RotL64((aOrbiterG * 13058135202554889791U), 21U);
            //
            aIngress = RotL64(aOrbiterE, 51U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 12U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 47U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 41U));
            aIngress = aIngress + RotL64(aOrbiterH, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterJ, 48U)) + aOrbiterB);
            aWandererK = aWandererK + (((RotL64(aIngress, 47U) + RotL64(aOrbiterB, 35U)) + aOrbiterH) + RotL64(aCarry, 53U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 18U) + aOrbiterC) + RotL64(aOrbiterK, 43U));
            aWandererD = aWandererD + (((RotL64(aScatter, 57U) + aOrbiterF) + RotL64(aOrbiterE, 29U)) + RotL64(aCarry, 37U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 27U) + aOrbiterA) + RotL64(aOrbiterC, 5U));
            aWandererA = aWandererA + ((RotL64(aPrevious, 11U) + RotL64(aOrbiterK, 23U)) + aOrbiterG);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 23U) + RotL64(aOrbiterA, 57U)) + aOrbiterH) + aPhaseCWandererUpdateSaltD[((aIndex + 23U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 43U) + RotL64(aOrbiterF, 19U)) + aOrbiterG) + aPhaseCWandererUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 52U) + aOrbiterH) + RotL64(aOrbiterK, 14U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 37U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 57U));
            aCarry = aCarry + (RotL64(aWandererJ, 44U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererC, 41U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererA, 29U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 24892U)) & S_BLOCK1], 5U) ^ RotL64(aKeyRowReadA[((aIndex + 26868U)) & W_KEY1], 36U));
            aIngress ^= (RotL64(aWorkLaneD[((aIndex + 25993U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneB[((aIndex + 25506U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 26152U)) & W_KEY1], 27U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 26622U)) & S_BLOCK1], 14U));
            aCross ^= (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 26916U)) & S_BLOCK1], 51U) ^ RotL64(aFireLaneD[((aIndex + 26413U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 35U) ^ RotL64(aIngress, 10U)) + (RotL64(aCross, 23U) + RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterF = ((aWandererH + RotL64(aIngress, 14U)) + 18319689184146942855U) + aPhaseDOrbiterAssignSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterH = ((aWandererE + RotL64(aCross, 35U)) + 8041304130090501019U) + aPhaseDOrbiterAssignSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = (aWandererD + RotL64(aPrevious, 41U)) + 11347064191990897738U;
            aOrbiterJ = ((aWandererC + RotL64(aScatter, 27U)) + RotL64(aCarry, 13U)) + 15242243470024447468U;
            aOrbiterC = (aWandererA + RotL64(aIngress, 47U)) + 10619749107163611105U;
            aOrbiterE = (aWandererK + RotL64(aCross, 53U)) + 14795614276221947128U;
            aOrbiterA = ((aWandererG + RotL64(aPrevious, 60U)) + RotL64(aCarry, 23U)) + 1578095288886372393U;
            aOrbiterB = (aWandererB + RotL64(aScatter, 3U)) + 13593906305770501684U;
            aOrbiterG = ((aWandererI + RotL64(aCross, 21U)) + RotL64(aCarry, 51U)) + 8919815528334599172U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 17425548324720065145U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 11125018338392347335U;
            aOrbiterD = RotL64((aOrbiterD * 4377887040461528587U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 3779189180734244399U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 10958224663276134041U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 6206963519509783781U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 4317305352561612995U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 4891139433808505355U;
            aOrbiterA = RotL64((aOrbiterA * 11507024985663120317U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 5166074784835930965U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 10080890270621589202U;
            aOrbiterB = RotL64((aOrbiterB * 13170894418184288695U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 4501071771615514619U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 6486573807774431753U;
            aOrbiterJ = RotL64((aOrbiterJ * 324029625116648669U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 15714881857668975753U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 3506619392820235900U;
            aOrbiterC = RotL64((aOrbiterC * 5707033870161224499U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 5295711072762443783U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 11192836530396570648U;
            aOrbiterG = RotL64((aOrbiterG * 4361810118382207039U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 7993389678399774574U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 12551394763541226695U;
            aOrbiterF = RotL64((aOrbiterF * 11903486656172026403U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 11553674370322129668U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 4459881583199320245U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 2805857426321555685U), 47U);
            //
            aIngress = RotL64(aOrbiterE, 21U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 13U));
            aIngress = aIngress + (RotL64(aOrbiterB, 48U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 35U));
            aIngress = aIngress + RotL64(aOrbiterH, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 4U) + aOrbiterF) + RotL64(aOrbiterB, 5U)) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aIngress, 47U) + RotL64(aOrbiterE, 47U)) + aOrbiterH) + RotL64(aCarry, 13U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterF, 11U)) + aOrbiterD);
            aWandererI = aWandererI + (((RotL64(aCross, 27U) + aOrbiterJ) + RotL64(aOrbiterB, 34U)) + RotL64(aCarry, 51U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterJ, 27U)) + aOrbiterG);
            aWandererA = aWandererA + (((RotL64(aCross, 39U) + aOrbiterC) + RotL64(aOrbiterF, 51U)) + aPhaseDWandererUpdateSaltB[((aIndex + 20U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterH, 39U)) + aOrbiterC);
            aWandererE = aWandererE + ((RotL64(aPrevious, 21U) + RotL64(aOrbiterG, 57U)) + aOrbiterF);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 58U) + aOrbiterA) + RotL64(aOrbiterH, 20U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 57U));
            aCarry = aCarry + (RotL64(aWandererH, 41U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererE, 12U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererI, 37U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererK, 23U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 28949U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneD[((aIndex + 28513U)) & S_BLOCK1], 47U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 28611U)) & W_KEY1], 24U) ^ RotL64(aWorkLaneC[((aIndex + 29262U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 28400U)) & W_KEY1], 37U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 29506U)) & S_BLOCK1], 13U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 28652U)) & S_BLOCK1], 24U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 29716U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 41U) ^ RotL64(aCarry, 54U)) + (RotL64(aCross, 5U) + RotL64(aPrevious, 29U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterE = (aWandererH + RotL64(aScatter, 10U)) + 10726035965553989335U;
            aOrbiterH = (aWandererE + RotL64(aIngress, 47U)) + 967354339530195662U;
            aOrbiterJ = (aWandererB + RotL64(aPrevious, 41U)) + 10834593005478605624U;
            aOrbiterI = (((aWandererI + RotL64(aCross, 37U)) + RotL64(aCarry, 5U)) + 1012888282838656933U) + aPhaseDOrbiterAssignSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = (aWandererF + RotL64(aPrevious, 3U)) + 15283530351725183253U;
            aOrbiterC = (aWandererK + RotL64(aIngress, 57U)) + 11724495956731703750U;
            aOrbiterK = ((aWandererJ + RotL64(aCross, 19U)) + 4288330117317505776U) + aPhaseDOrbiterAssignSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = ((aWandererD + RotL64(aScatter, 28U)) + RotL64(aCarry, 39U)) + 10894778070022873473U;
            aOrbiterF = ((aWandererA + RotL64(aPrevious, 23U)) + RotL64(aCarry, 47U)) + 15563886747621617467U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 11182488628562891937U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 10420140066310588580U;
            aOrbiterJ = RotL64((aOrbiterJ * 13898299782819948719U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 11775138062167543111U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 16545391898578161683U;
            aOrbiterG = RotL64((aOrbiterG * 14588306527161321535U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 1550144656312299266U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 14903504853138279883U;
            aOrbiterE = RotL64((aOrbiterE * 8003033561266164387U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 309935535526750396U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 13991265868040011411U;
            aOrbiterI = RotL64((aOrbiterI * 2887531132228588441U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 1755976294857114222U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 2259275858478396846U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7416165760067878161U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 4838175912944552936U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 12307900457200936013U;
            aOrbiterK = RotL64((aOrbiterK * 14719363144850838805U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 18025411832912225805U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 981375022769564523U;
            aOrbiterF = RotL64((aOrbiterF * 15869361544011831483U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 3174014054982742562U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 8119692378748963609U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 3072354179707448489U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 14502863160788675807U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 1207582534593709516U;
            aOrbiterB = RotL64((aOrbiterB * 3045412087535529357U), 13U);
            //
            aIngress = RotL64(aOrbiterJ, 5U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterK, 10U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterI, 35U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 53U));
            aIngress = aIngress + RotL64(aOrbiterE, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aPrevious, 24U) + aOrbiterC) + RotL64(aOrbiterK, 56U)) + RotL64(aCarry, 19U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 13U) + aOrbiterI) + RotL64(aOrbiterH, 39U)) + aPhaseDWandererUpdateSaltC[((aIndex + 4U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 37U) + RotL64(aOrbiterI, 51U)) + aOrbiterB) + RotL64(aCarry, 27U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 53U) + RotL64(aOrbiterK, 35U)) + aOrbiterE) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aCross, 29U) + RotL64(aOrbiterB, 23U)) + aOrbiterC);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 57U) + aOrbiterC) + RotL64(aOrbiterF, 27U));
            aWandererA = aWandererA + ((RotL64(aIngress, 48U) + aOrbiterG) + RotL64(aOrbiterJ, 5U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 41U) + aOrbiterH) + RotL64(aOrbiterF, 44U));
            aWandererH = aWandererH + ((RotL64(aIngress, 19U) + aOrbiterG) + RotL64(aOrbiterK, 13U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 47U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 37U));
            aCarry = aCarry + (RotL64(aWandererF, 21U) ^ aWandererE);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 60U));
            aCarry = aCarry + RotL64(aWandererK, 43U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 31435U)) & S_BLOCK1], 48U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 31083U)) & W_KEY1], 35U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 30629U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31876U)) & S_BLOCK1], 60U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32482U)) & S_BLOCK1], 43U) ^ RotL64(aKeyRowReadB[((aIndex + 30234U)) & W_KEY1], 5U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aPrevious, 28U)) + (RotL64(aIngress, 57U) ^ RotL64(aCarry, 43U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterB = (aWandererI + RotL64(aIngress, 43U)) + 12206125048349568300U;
            aOrbiterA = ((aWandererF + RotL64(aScatter, 58U)) + RotL64(aCarry, 43U)) + 5843520589343188818U;
            aOrbiterI = ((aWandererA + RotL64(aCross, 19U)) + RotL64(aCarry, 5U)) + 12195046124287121687U;
            aOrbiterH = (aWandererE + RotL64(aPrevious, 11U)) + 16769779119214020640U;
            aOrbiterD = ((aWandererD + RotL64(aScatter, 29U)) + 5257603646260695833U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = ((aWandererJ + RotL64(aIngress, 39U)) + 8523523946234886745U) + aPhaseDOrbiterAssignSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = (aWandererG + RotL64(aCross, 53U)) + 7316024684200084096U;
            aOrbiterC = ((aWandererB + RotL64(aPrevious, 24U)) + RotL64(aCarry, 13U)) + 11996978575084115207U;
            aOrbiterG = (aWandererC + RotL64(aIngress, 35U)) + 15491711479085513628U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 6036648530996821484U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 926323222234121863U;
            aOrbiterI = RotL64((aOrbiterI * 6639661141258803779U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 2700323841295743492U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 5852273765810284935U;
            aOrbiterB = RotL64((aOrbiterB * 16665696735016345215U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 11697397483133538067U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 17777142964957007194U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 6338967222543284999U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 10892176201151170298U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 11759700374509499684U;
            aOrbiterE = RotL64((aOrbiterE * 14247697264744736081U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 11343756773329590643U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 15785048929757652350U;
            aOrbiterH = RotL64((aOrbiterH * 17208103574389502597U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 7508839228498497238U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 13088508510402094665U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 15730279447009669103U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 16259236641717377699U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 11228995722951003980U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4870092259515181323U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 13775851561528617086U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 3023564646900497080U;
            aOrbiterC = RotL64((aOrbiterC * 9936548213275464131U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 154952467284609583U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 14239675888632174461U;
            aOrbiterD = RotL64((aOrbiterD * 1370550680736926425U), 53U);
            //
            aIngress = RotL64(aOrbiterD, 21U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterE, 35U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 14U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 27U));
            aIngress = aIngress + RotL64(aOrbiterK, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aScatter, 5U) + RotL64(aOrbiterG, 36U)) + aOrbiterB) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aCross, 21U) + aOrbiterE) + RotL64(aOrbiterB, 53U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 13U) + aOrbiterC) + RotL64(aOrbiterD, 27U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 26U) + aOrbiterK) + RotL64(aOrbiterA, 23U)) + RotL64(aCarry, 5U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterH, 3U)) + aOrbiterC) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aScatter, 47U) + RotL64(aOrbiterE, 46U)) + aOrbiterI);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterH, 11U)) + aOrbiterE);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 43U) + aOrbiterG) + RotL64(aOrbiterH, 57U)) + RotL64(aCarry, 53U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 30U) + RotL64(aOrbiterE, 19U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererI, 43U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererE, 60U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererB, 19U) ^ aWandererJ);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 29U));
            aCarry = aCarry + RotL64(aWandererG, 47U);
            aCarry = aCarry + RotL64(aIngress, 50U);
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

void TwistExpander_PingPong_Arx::Twist_B(TwistWorkSpace *pWorkSpace,
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 6940U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneB[((aIndex + 1103U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 1309U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 7401U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 7266U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 2710U)) & S_BLOCK1], 24U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 37U) ^ RotL64(aIngress, 22U)) + (RotL64(aPrevious, 57U) ^ RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterC = (aWandererE + RotL64(aPrevious, 11U)) + 1888427424966603593U;
            aOrbiterB = ((aWandererC + RotL64(aCross, 19U)) + RotL64(aCarry, 53U)) + 5436761445660415091U;
            aOrbiterF = ((aWandererA + RotL64(aScatter, 3U)) + 17322876217962143270U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterD = (aWandererJ + RotL64(aIngress, 29U)) + 9728299982740564979U;
            aOrbiterH = ((aWandererH + RotL64(aScatter, 47U)) + RotL64(aCarry, 35U)) + 301720335271716921U;
            aOrbiterG = (((aWandererG + RotL64(aPrevious, 39U)) + RotL64(aCarry, 23U)) + 8069685428854814396U) + aPhaseEOrbiterAssignSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterJ = (aWandererI + RotL64(aCross, 60U)) + 1973715500949100991U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 87666408799854155U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 12195436904339035245U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 15427739165893738105U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 4578742069143400295U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 7828776048774876484U;
            aOrbiterH = RotL64((aOrbiterH * 4047964518501081039U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 17203146364542781833U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 16913369550858890466U;
            aOrbiterC = RotL64((aOrbiterC * 13534417587921978507U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 9632761514552265402U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 9106637671877341286U;
            aOrbiterJ = RotL64((aOrbiterJ * 9073709119482640391U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 15423680889126750876U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 6087310684583331882U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8964465129744898619U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 5420955876411796789U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 14166807419730848032U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 442659738632823751U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 8118312450347026824U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 4253043584558403086U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5651748455190536467U), 29U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterH, 56U);
            aIngress = aIngress + (RotL64(aOrbiterB, 41U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 19U));
            aIngress = aIngress + RotL64(aOrbiterJ, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aScatter, 47U) + RotL64(aOrbiterJ, 29U)) + aOrbiterF);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 11U) + aOrbiterG) + RotL64(aOrbiterH, 3U));
            aWandererJ = aWandererJ + ((((RotL64(aCross, 21U) + aOrbiterJ) + RotL64(aOrbiterD, 19U)) + RotL64(aCarry, 57U)) + aPhaseEWandererUpdateSaltF[((aIndex + 19U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterH, 51U)) + aOrbiterB);
            aWandererH = aWandererH + (((RotL64(aScatter, 53U) + RotL64(aOrbiterB, 35U)) + aOrbiterG) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterD, 13U)) + aOrbiterC);
            aWandererC = aWandererC + (((RotL64(aIngress, 4U) + RotL64(aOrbiterF, 60U)) + aOrbiterC) + RotL64(aCarry, 29U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 57U));
            aCarry = aCarry + (RotL64(aWandererH, 12U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererJ, 35U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 9693U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneC[((aIndex + 12057U)) & S_BLOCK1], 53U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 14721U)) & S_BLOCK1], 29U) ^ RotL64(aFireLaneC[((aIndex + 13945U)) & S_BLOCK1], 38U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 9726U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 12977U)) & S_BLOCK1], 56U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 11528U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 11U) + RotL64(aCarry, 39U)) ^ (RotL64(aIngress, 26U) ^ RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterF = (((aWandererA + RotL64(aPrevious, 47U)) + RotL64(aCarry, 23U)) + 13350544654542863236U) + aPhaseEOrbiterAssignSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterA = ((aWandererB + RotL64(aScatter, 57U)) + RotL64(aCarry, 57U)) + 12364346790125404372U;
            aOrbiterE = (aWandererG + RotL64(aCross, 27U)) + 9738750172849512764U;
            aOrbiterK = ((aWandererK + RotL64(aIngress, 3U)) + 3781373837635491421U) + aPhaseEOrbiterAssignSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterC = (aWandererH + RotL64(aCross, 41U)) + 16635020317512702337U;
            aOrbiterI = (aWandererE + RotL64(aScatter, 35U)) + 5383653921676231276U;
            aOrbiterD = ((aWandererD + RotL64(aIngress, 18U)) + RotL64(aCarry, 35U)) + 10181959815492056493U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 10005510924273927017U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 9524687662265740565U;
            aOrbiterE = RotL64((aOrbiterE * 13687380438646756931U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 4259138552009771014U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 8973051213213726023U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12625091476068190979U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 17602611840127337490U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 8218984546932905269U;
            aOrbiterD = RotL64((aOrbiterD * 17504305273683304231U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 18102186122213487888U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 2629927500298092976U;
            aOrbiterF = RotL64((aOrbiterF * 6983280164448292723U), 39U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 2491581597835795234U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 9506602492971620955U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 9559829640915637163U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 13422942713680612924U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 15037354693234876601U;
            aOrbiterC = RotL64((aOrbiterC * 12692376075738621447U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 12896066842192894694U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 2202952306291905855U;
            aOrbiterK = RotL64((aOrbiterK * 6779368532763429997U), 57U);
            //
            aIngress = RotL64(aOrbiterK, 57U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterE, 13U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterF, 5U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterC, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterK, 5U)) + aOrbiterC);
            aWandererA = aWandererA + ((((RotL64(aIngress, 50U) + RotL64(aOrbiterE, 36U)) + aOrbiterI) + RotL64(aCarry, 29U)) + aPhaseEWandererUpdateSaltD[((aIndex + 16U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 11U) + aOrbiterD) + RotL64(aOrbiterA, 51U));
            aWandererD = aWandererD + (((RotL64(aCross, 57U) + RotL64(aOrbiterC, 11U)) + aOrbiterF) + RotL64(aCarry, 53U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 37U) + aOrbiterF) + RotL64(aOrbiterA, 21U));
            aWandererB = aWandererB + ((RotL64(aScatter, 43U) + aOrbiterK) + RotL64(aOrbiterI, 43U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 21U) + RotL64(aOrbiterA, 27U)) + aOrbiterI) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 50U));
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererD);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 23U));
            aCarry = aCarry + RotL64(aWandererE, 5U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 22893U)) & S_BLOCK1], 34U) ^ RotL64(aExpandLaneA[((aIndex + 22017U)) & S_BLOCK1], 21U));
            aIngress ^= (RotL64(aExpandLaneB[((aIndex + 17078U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneA[((aIndex + 22868U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 17114U)) & S_BLOCK1], 18U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 19662U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 24144U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 39U) ^ RotL64(aCross, 21U)) + (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 52U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterB = ((aWandererF + RotL64(aIngress, 53U)) + 7790166497945719700U) + aPhaseEOrbiterAssignSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = (aWandererI + RotL64(aScatter, 5U)) + 7136208896846119188U;
            aOrbiterE = (aWandererG + RotL64(aCross, 41U)) + 12123156943355100886U;
            aOrbiterI = (aWandererH + RotL64(aPrevious, 24U)) + 5095546037880875199U;
            aOrbiterA = ((aWandererB + RotL64(aCross, 47U)) + RotL64(aCarry, 37U)) + 17642705393916765992U;
            aOrbiterG = (((aWandererA + RotL64(aIngress, 11U)) + RotL64(aCarry, 51U)) + 9918479837334416990U) + aPhaseEOrbiterAssignSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = ((aWandererC + RotL64(aPrevious, 35U)) + RotL64(aCarry, 13U)) + 4890009823843176466U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 17652590786213674124U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 870002527644696135U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 915408393979165539U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 12545429703552643682U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 5310272867406182581U;
            aOrbiterG = RotL64((aOrbiterG * 10420003334833925011U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 3264719049050179440U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 1967241238180278937U;
            aOrbiterA = RotL64((aOrbiterA * 13004319774269457957U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 773883832927040736U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 12766817190261232485U;
            aOrbiterB = RotL64((aOrbiterB * 7448864556802318431U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 260069382395598265U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 15462103891287350123U;
            aOrbiterH = RotL64((aOrbiterH * 5029268763635635753U), 37U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 4072032867513289827U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 17153061419083897076U;
            aOrbiterI = RotL64((aOrbiterI * 11934532169271718913U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 6207264270332656966U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 18048064697837314947U;
            aOrbiterC = RotL64((aOrbiterC * 13632594619404208489U), 27U);
            //
            aIngress = RotL64(aOrbiterH, 47U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 54U));
            aIngress = aIngress + (RotL64(aOrbiterG, 35U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterE, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aCross, 44U) + RotL64(aOrbiterE, 53U)) + aOrbiterB);
            aWandererH = aWandererH + ((((RotL64(aIngress, 13U) + RotL64(aOrbiterB, 14U)) + aOrbiterC) + RotL64(aCarry, 43U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 5U) + aOrbiterB) + RotL64(aOrbiterH, 21U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterG, 35U)) + aOrbiterB) + RotL64(aCarry, 57U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 27U) + RotL64(aOrbiterI, 29U)) + aOrbiterG) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aIngress, 21U) + RotL64(aOrbiterG, 3U)) + aOrbiterC);
            aWandererC = aWandererC ^ ((RotL64(aCross, 37U) + aOrbiterI) + RotL64(aOrbiterA, 41U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 42U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererC, 11U) ^ aWandererF);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 19U));
            aCarry = aCarry + RotL64(aWandererG, 29U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 26787U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneA[((aIndex + 27700U)) & S_BLOCK1], 57U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 25861U)) & S_BLOCK1], 42U) ^ RotL64(aWorkLaneC[((aIndex + 28999U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 27139U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 26713U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aWorkLaneD[((aIndex + 26628U)) & S_BLOCK1], 42U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 37U) + RotL64(aCarry, 18U)) + (RotL64(aPrevious, 57U) ^ RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterJ = (((aWandererA + RotL64(aIngress, 57U)) + RotL64(aCarry, 13U)) + 16451272412693907816U) + aPhaseEOrbiterAssignSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterG = (aWandererF + RotL64(aScatter, 48U)) + 10099485419723255462U;
            aOrbiterD = ((aWandererJ + RotL64(aCross, 19U)) + RotL64(aCarry, 53U)) + 17668900099534923192U;
            aOrbiterC = ((aWandererE + RotL64(aPrevious, 5U)) + RotL64(aCarry, 39U)) + 5497093724143181753U;
            aOrbiterK = (aWandererG + RotL64(aScatter, 29U)) + 10354044773550071706U;
            aOrbiterH = (aWandererI + RotL64(aCross, 11U)) + 12728258851198019099U;
            aOrbiterF = ((aWandererB + RotL64(aPrevious, 37U)) + 4144050505314242618U) + aPhaseEOrbiterAssignSaltD[((aIndex + 18U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 14133805325480076530U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 308863673210602899U;
            aOrbiterD = RotL64((aOrbiterD * 2672613556981540433U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 11741180130160569753U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 12926863156769180448U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 9726030996091054939U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 211920854786494259U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 13234608842479411078U;
            aOrbiterH = RotL64((aOrbiterH * 2556747209733759467U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 9164711974854618892U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 6667377062281954219U;
            aOrbiterG = RotL64((aOrbiterG * 2603737166987437649U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 4559040002406721850U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 1749875480850675109U;
            aOrbiterF = RotL64((aOrbiterF * 15822640067349481089U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 9555365165561936366U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 18289733999504213574U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 14156217554673229429U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 8727162691639622461U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 291406782452963706U;
            aOrbiterC = RotL64((aOrbiterC * 8413500075082350243U), 29U);
            //
            aIngress = RotL64(aOrbiterG, 11U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterF, 41U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterJ, 29U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterH, 58U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aIngress, 35U) + aOrbiterJ) + RotL64(aOrbiterK, 35U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 4U) + aOrbiterH) + RotL64(aOrbiterG, 11U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 13U) + aOrbiterJ) + RotL64(aOrbiterD, 20U)) + aPhaseEWandererUpdateSaltB[((aIndex + 5U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 57U) + RotL64(aOrbiterH, 5U)) + aOrbiterF) + RotL64(aCarry, 39U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 23U) + aOrbiterD) + RotL64(aOrbiterF, 27U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterG, 57U)) + aOrbiterD) + RotL64(aCarry, 27U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterJ, 51U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 44U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 19U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 5U));
            aCarry = aCarry + RotL64(aWandererA, 11U);
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

void TwistExpander_PingPong_Arx::Twist_C(TwistWorkSpace *pWorkSpace,
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 4286U)) & S_BLOCK1], 58U) ^ RotL64(aOperationLaneB[((aIndex + 765U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 4598U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 1989U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 3430U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 6069U)) & S_BLOCK1], 12U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 41U) + RotL64(aCarry, 56U)) + (RotL64(aPrevious, 5U) ^ RotL64(aCross, 27U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterI = ((aWandererA + RotL64(aCross, 3U)) + 12535417189990029950U) + aPhaseFOrbiterAssignSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterE = (aWandererK + RotL64(aIngress, 43U)) + 6204401443676390273U;
            aOrbiterB = (aWandererD + RotL64(aPrevious, 39U)) + 869613505613154672U;
            aOrbiterF = ((aWandererE + RotL64(aScatter, 5U)) + RotL64(aCarry, 19U)) + 15053590879563855802U;
            aOrbiterC = (((aWandererI + RotL64(aCross, 52U)) + RotL64(aCarry, 51U)) + 13338989605204591428U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = (aWandererH + RotL64(aIngress, 47U)) + 18306470022403825392U;
            aOrbiterG = ((aWandererJ + RotL64(aPrevious, 29U)) + RotL64(aCarry, 43U)) + 1150696349434090218U;
            aOrbiterK = (aWandererC + RotL64(aScatter, 11U)) + 13549541786420596437U;
            aOrbiterH = (aWandererG + RotL64(aIngress, 23U)) + 14302878430259588461U;
            aOrbiterD = (aWandererB + RotL64(aScatter, 54U)) + 4660437084477165225U;
            aOrbiterJ = (aWandererF + RotL64(aPrevious, 27U)) + 1653628537860912069U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 5594199757006711631U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 11008472193138708891U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 13645764762027798301U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 3668516817279364310U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 128159531749679984U;
            aOrbiterC = RotL64((aOrbiterC * 4523246859249826987U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 6378674346113979108U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 11438762460659123362U;
            aOrbiterG = RotL64((aOrbiterG * 2733309638158283953U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 10624263004446482910U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 12546839706919241411U;
            aOrbiterK = RotL64((aOrbiterK * 11468326687628079347U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 8466639576503293921U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 5828694979857951504U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7835487310289634515U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 16496305151014092976U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 589464613876410567U;
            aOrbiterF = RotL64((aOrbiterF * 13190816610718051897U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 4168532743415647825U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 15944887793736489375U;
            aOrbiterD = RotL64((aOrbiterD * 17273403561158196717U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 11642456814106259483U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 1609897693632334867U;
            aOrbiterE = RotL64((aOrbiterE * 12912773555616819941U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 14950238412766325479U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 11862438528287402255U;
            aOrbiterH = RotL64((aOrbiterH * 7635864312080265695U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 5900629306795222263U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 3221591991392500536U;
            aOrbiterJ = RotL64((aOrbiterJ * 7188525011266868855U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 16938699391746264010U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 12535417189990029950U;
            aOrbiterI = RotL64((aOrbiterI * 18212319484142613215U), 19U);
            //
            aIngress = RotL64(aOrbiterA, 43U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 41U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 35U));
            aIngress = aIngress + (RotL64(aOrbiterK, 19U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 57U));
            aIngress = aIngress + RotL64(aOrbiterI, 54U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aPrevious, 41U) + RotL64(aOrbiterH, 47U)) + aOrbiterC) + RotL64(aCarry, 21U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterB, 5U)) + aOrbiterG);
            aWandererD = aWandererD + ((((RotL64(aScatter, 24U) + RotL64(aOrbiterB, 54U)) + aOrbiterA) + RotL64(aCarry, 37U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 11U) + aOrbiterE) + RotL64(aOrbiterH, 39U));
            aWandererA = aWandererA + ((RotL64(aScatter, 51U) + RotL64(aOrbiterG, 13U)) + aOrbiterC);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 29U) + aOrbiterD) + RotL64(aOrbiterI, 29U));
            aWandererG = aWandererG + ((RotL64(aPrevious, 5U) + RotL64(aOrbiterB, 60U)) + aOrbiterI);
            aWandererB = aWandererB ^ ((RotL64(aCross, 46U) + aOrbiterJ) + RotL64(aOrbiterK, 11U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterA, 35U)) + aOrbiterJ) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 19U) + aOrbiterF) + RotL64(aOrbiterA, 57U));
            aWandererE = aWandererE + ((RotL64(aScatter, 43U) + RotL64(aOrbiterB, 21U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 37U));
            aCarry = aCarry + (RotL64(aWandererD, 19U) ^ aWandererH);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 60U));
            aCarry = aCarry + (RotL64(aWandererG, 35U) ^ aWandererI);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 27U));
            aCarry = aCarry + RotL64(aWandererC, 11U);
            aCarry = aCarry + RotL64(aIngress, 50U);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 11130U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneC[((aIndex + 13574U)) & S_BLOCK1], 11U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 10812U)) & S_BLOCK1], 37U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 10382U)) & S_BLOCK1], 60U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 12678U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 13667U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 14873U)) & S_BLOCK1], 50U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 23U) ^ RotL64(aCross, 35U)) + (RotL64(aCarry, 3U) + RotL64(aPrevious, 52U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterA = (aWandererD + RotL64(aIngress, 11U)) + 898812731947995389U;
            aOrbiterE = ((aWandererI + RotL64(aPrevious, 43U)) + RotL64(aCarry, 19U)) + 8677347622525527167U;
            aOrbiterG = (((aWandererE + RotL64(aCross, 19U)) + RotL64(aCarry, 27U)) + 770321564027567654U) + aPhaseFOrbiterAssignSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterC = (aWandererA + RotL64(aScatter, 56U)) + 11020474858081526395U;
            aOrbiterF = (aWandererJ + RotL64(aCross, 27U)) + 17289793580414993470U;
            aOrbiterD = (aWandererF + RotL64(aScatter, 39U)) + 10111912559295118444U;
            aOrbiterK = (aWandererB + RotL64(aIngress, 5U)) + 8083622125544542011U;
            aOrbiterB = (aWandererH + RotL64(aPrevious, 47U)) + 7149858558922988240U;
            aOrbiterI = ((aWandererK + RotL64(aScatter, 52U)) + 5919683821379905699U) + aPhaseFOrbiterAssignSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterJ = (aWandererC + RotL64(aPrevious, 13U)) + 6860902846079238714U;
            aOrbiterH = ((aWandererG + RotL64(aIngress, 3U)) + RotL64(aCarry, 53U)) + 15083517836867542075U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 14852868368708376381U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 9860233289028878323U;
            aOrbiterG = RotL64((aOrbiterG * 13418143547952204667U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 772406119079116272U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 7971141501337627589U;
            aOrbiterF = RotL64((aOrbiterF * 10168120622976358617U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 8478568022896691911U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 4027604850785607101U;
            aOrbiterK = RotL64((aOrbiterK * 4826627523578901467U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 17199331557841535430U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 7515957656979776361U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5468950152869656599U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 17138249294921502391U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 16236812863923234668U;
            aOrbiterD = RotL64((aOrbiterD * 2925542836624164807U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 16941524155859123682U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 11240343728857342866U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7281012444214294659U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 15163914964139858328U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 6673576554415729652U;
            aOrbiterI = RotL64((aOrbiterI * 1558880328574736975U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 5399050402101642989U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 11806006719060024615U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 15782156615926092159U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 9812148913932011655U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 4737919734590584193U;
            aOrbiterE = RotL64((aOrbiterE * 2739737604370936959U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 3415477403346468057U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 5922725868927615919U;
            aOrbiterC = RotL64((aOrbiterC * 12390148483052777871U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 17435294951520465659U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 898812731947995389U;
            aOrbiterH = RotL64((aOrbiterH * 17248379279729365007U), 35U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterE, 43U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 3U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 18U));
            aIngress = aIngress + (RotL64(aOrbiterA, 51U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterI, 23U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterH, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aIngress, 23U) + aOrbiterK) + RotL64(aOrbiterI, 50U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 47U) + aOrbiterA) + RotL64(aOrbiterB, 19U));
            aWandererK = aWandererK + ((RotL64(aScatter, 28U) + aOrbiterE) + RotL64(aOrbiterI, 13U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 35U) + RotL64(aOrbiterG, 11U)) + aOrbiterC) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 43U) + RotL64(aOrbiterF, 35U)) + aOrbiterJ) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterB, 41U)) + aOrbiterH);
            aWandererJ = aWandererJ + (((RotL64(aCross, 39U) + aOrbiterE) + RotL64(aOrbiterA, 29U)) + RotL64(aCarry, 19U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 50U) + RotL64(aOrbiterA, 23U)) + aOrbiterJ);
            aWandererH = aWandererH + (((RotL64(aScatter, 3U) + aOrbiterC) + RotL64(aOrbiterK, 57U)) + RotL64(aCarry, 35U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterG, 60U)) + aOrbiterF);
            aWandererI = aWandererI + ((RotL64(aPrevious, 53U) + RotL64(aOrbiterK, 43U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + (RotL64(aWandererE, 42U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererH, 29U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererF, 3U) ^ aWandererI);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 19U));
            aCarry = aCarry + RotL64(aWandererK, 5U);
            aCarry = aCarry + RotL64(aIngress, 38U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 19711U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneA[((aIndex + 24339U)) & S_BLOCK1], 30U));
            aIngress ^= (RotL64(aOperationLaneB[((aIndex + 24308U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneA[((aIndex + 19617U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22610U)) & S_BLOCK1], 22U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 21455U)) & S_BLOCK1], 41U));
            aCross ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 24422U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 22U) ^ RotL64(aPrevious, 39U)) + (RotL64(aIngress, 53U) ^ RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterD = (aWandererI + RotL64(aPrevious, 3U)) + 17912271996338180948U;
            aOrbiterB = (aWandererE + RotL64(aCross, 13U)) + 13259276608841847058U;
            aOrbiterI = ((aWandererK + RotL64(aIngress, 47U)) + 16225936008657276089U) + aPhaseFOrbiterAssignSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = (aWandererA + RotL64(aScatter, 21U)) + 2243058962151834071U;
            aOrbiterJ = ((aWandererH + RotL64(aIngress, 26U)) + RotL64(aCarry, 35U)) + 10637439274127347861U;
            aOrbiterK = (aWandererD + RotL64(aPrevious, 35U)) + 15312219216405992627U;
            aOrbiterC = (aWandererB + RotL64(aScatter, 19U)) + 2393933972129878613U;
            aOrbiterF = (aWandererG + RotL64(aCross, 51U)) + 4327069337247976513U;
            aOrbiterE = ((aWandererF + RotL64(aScatter, 11U)) + RotL64(aCarry, 57U)) + 8307656353434167837U;
            aOrbiterH = (aWandererJ + RotL64(aCross, 43U)) + 17299145556933889336U;
            aOrbiterG = (((aWandererC + RotL64(aPrevious, 24U)) + RotL64(aCarry, 3U)) + 14458100581172798164U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 6410095654927998067U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 6168964796264687686U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 16218071040190475953U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 3667999465041020730U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 16021552859323602007U;
            aOrbiterJ = RotL64((aOrbiterJ * 6427266472526362663U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 12941668202330045095U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 4222032891850449934U;
            aOrbiterK = RotL64((aOrbiterK * 17292856787431308097U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 1346342592002730785U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 16860611785008118820U;
            aOrbiterE = RotL64((aOrbiterE * 384963420804756607U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 3193572711804730241U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 5866881282680588589U;
            aOrbiterB = RotL64((aOrbiterB * 9226331800853634597U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 17180332731328479126U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 10222097519535882241U;
            aOrbiterH = RotL64((aOrbiterH * 9422887302872778795U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 8863502179821584859U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 14872318155712512999U;
            aOrbiterG = RotL64((aOrbiterG * 11830641277356873233U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 16478790641892781150U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 8414944141232294781U;
            aOrbiterC = RotL64((aOrbiterC * 17443775794621154023U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 13204056527590476037U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 15084952142545813228U;
            aOrbiterA = RotL64((aOrbiterA * 17183888602469193015U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 13051035678904490854U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 17565188004293304987U;
            aOrbiterF = RotL64((aOrbiterF * 12785271107667631897U), 27U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 814245676602237400U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 17912271996338180948U;
            aOrbiterD = RotL64((aOrbiterD * 14557769257469623169U), 29U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterH, 51U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 53U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 12U));
            aIngress = aIngress + (RotL64(aOrbiterB, 57U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 3U));
            aIngress = aIngress + RotL64(aOrbiterI, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aCross, 3U) + aOrbiterD) + RotL64(aOrbiterH, 14U)) + aPhaseFWandererUpdateSaltD[((aIndex + 13U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 47U) + aOrbiterH) + RotL64(aOrbiterE, 37U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 37U) + RotL64(aOrbiterI, 29U)) + aOrbiterD);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 51U) + aOrbiterJ) + RotL64(aOrbiterD, 11U));
            aWandererE = aWandererE + (((RotL64(aCross, 29U) + aOrbiterH) + RotL64(aOrbiterJ, 3U)) + RotL64(aCarry, 51U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 34U) + RotL64(aOrbiterK, 22U)) + aOrbiterC);
            aWandererH = aWandererH + (((RotL64(aIngress, 19U) + aOrbiterA) + RotL64(aOrbiterH, 19U)) + RotL64(aCarry, 5U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterB, 41U)) + aOrbiterG);
            aWandererK = aWandererK + ((RotL64(aCross, 53U) + aOrbiterK) + RotL64(aOrbiterB, 51U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 40U) + aOrbiterK) + RotL64(aOrbiterD, 27U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterF, 39U)) + aOrbiterI) + aPhaseFWandererUpdateSaltB[((aIndex + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 58U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 29U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 3U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 13U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 35U));
            aCarry = aCarry + RotL64(aWandererA, 60U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 28544U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneA[((aIndex + 32507U)) & S_BLOCK1], 40U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 31820U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 25522U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 29340U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 26219U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 32264U)) & S_BLOCK1], 36U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 53U) + RotL64(aCross, 36U)) ^ (RotL64(aPrevious, 21U) + RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterB = ((aWandererJ + RotL64(aIngress, 60U)) + 13333509828310369865U) + aPhaseFOrbiterAssignSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = (aWandererE + RotL64(aPrevious, 23U)) + 7645352517103840797U;
            aOrbiterA = (aWandererB + RotL64(aScatter, 19U)) + 5310766306660062655U;
            aOrbiterI = (aWandererF + RotL64(aCross, 47U)) + 5165635069832352932U;
            aOrbiterF = (aWandererA + RotL64(aIngress, 43U)) + 15684141764734281849U;
            aOrbiterC = (aWandererD + RotL64(aPrevious, 3U)) + 3327963374225061738U;
            aOrbiterH = (aWandererI + RotL64(aScatter, 13U)) + 8625811794878848871U;
            aOrbiterJ = ((aWandererK + RotL64(aCross, 41U)) + RotL64(aCarry, 35U)) + 7598657468430485291U;
            aOrbiterD = ((aWandererH + RotL64(aIngress, 36U)) + RotL64(aCarry, 21U)) + 2881171216276746485U;
            aOrbiterG = (aWandererC + RotL64(aScatter, 53U)) + 10237691227222918101U;
            aOrbiterE = (((aWandererG + RotL64(aPrevious, 5U)) + RotL64(aCarry, 3U)) + 6419254255884834497U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 4238455444646479956U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 14936613353493061492U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3544216916806292273U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 15324699725208372627U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 9506640480601832011U;
            aOrbiterB = RotL64((aOrbiterB * 12819564111348390227U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 3709149613660215641U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 1724290199312754307U;
            aOrbiterK = RotL64((aOrbiterK * 12597580418257897965U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 13191172833570139194U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 3686087945377837886U;
            aOrbiterJ = RotL64((aOrbiterJ * 10883609557429936283U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 10418330386245397022U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 5383531313632347245U;
            aOrbiterH = RotL64((aOrbiterH * 2987755379396160073U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 7414716553072652212U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 11301761123966206201U;
            aOrbiterC = RotL64((aOrbiterC * 1546727321088592187U), 41U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 8570229732236388847U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 8773754460060264773U;
            aOrbiterD = RotL64((aOrbiterD * 3251360788932563495U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 13636929800504199371U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 5486599841558573720U;
            aOrbiterF = RotL64((aOrbiterF * 2867914211589815153U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 13277541451512422776U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 10409779509190185921U;
            aOrbiterI = RotL64((aOrbiterI * 1926650154570961573U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 7268295836403414306U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 13815969853235433830U;
            aOrbiterE = RotL64((aOrbiterE * 11603750346752441535U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 9353249174240162324U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 13333509828310369865U;
            aOrbiterG = RotL64((aOrbiterG * 10381405217943841655U), 19U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterJ, 21U);
            aIngress = aIngress + (RotL64(aOrbiterC, 29U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterK, 11U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 26U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 57U));
            aIngress = aIngress + RotL64(aOrbiterD, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aScatter, 57U) + aOrbiterK) + RotL64(aOrbiterJ, 57U));
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 43U) + RotL64(aOrbiterB, 51U)) + aOrbiterD);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterI, 6U)) + aOrbiterA);
            aWandererK = aWandererK + ((RotL64(aCross, 50U) + RotL64(aOrbiterC, 11U)) + aOrbiterH);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterH, 41U)) + aOrbiterD);
            aWandererD = aWandererD + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterC, 29U)) + aOrbiterA) + RotL64(aCarry, 11U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 23U) + aOrbiterG) + RotL64(aOrbiterD, 46U));
            aWandererG = aWandererG + ((((RotL64(aIngress, 39U) + RotL64(aOrbiterI, 39U)) + aOrbiterD) + RotL64(aCarry, 37U)) + aPhaseFWandererUpdateSaltC[((aIndex + 7U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 41U) + aOrbiterC) + RotL64(aOrbiterF, 13U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 28U) + aOrbiterE) + RotL64(aOrbiterK, 53U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterB, 35U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 57U));
            aCarry = aCarry + (RotL64(aWandererE, 38U) ^ aWandererF);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 43U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 29U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 51U));
            aCarry = aCarry + RotL64(aWandererK, 24U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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

void TwistExpander_PingPong_Arx::GROW_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterK = 0;

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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 6054U)) & S_BLOCK1], 20U) ^ RotL64(aWorkLaneB[((aIndex + 3728U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 5885U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 3230U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 3285U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aWorkLaneD[((aIndex + 3982U)) & S_BLOCK1], 22U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 39U) + RotL64(aPrevious, 3U)) ^ (RotL64(aIngress, 21U) ^ RotL64(aCross, 52U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterE = (aWandererC + RotL64(aPrevious, 47U)) + 4848316479321533394U;
            aOrbiterB = ((aWandererE + RotL64(aScatter, 38U)) + RotL64(aCarry, 37U)) + 6919360256662636195U;
            aOrbiterH = (((aWandererI + RotL64(aCross, 3U)) + RotL64(aCarry, 5U)) + 9897013582181108544U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = (((aWandererA + RotL64(aIngress, 57U)) + RotL64(aCarry, 57U)) + 7319353809896158678U) + aPhaseGOrbiterAssignSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterA = (aWandererB + RotL64(aPrevious, 19U)) + 2848175435514849859U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 6967780718720437934U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 10143884766603388136U) ^ aPhaseGOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 17346772745745835895U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 8675965006150972051U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 16350117755560994281U) ^ aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 15072308930382994425U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 17976597517118423760U) + aPhaseGOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 1399631141355370237U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 16537788276543236833U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 3590613762034716792U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 5134624314245932157U;
            aOrbiterE = RotL64((aOrbiterE * 13077589037975283371U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 10082236952942943654U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 4015535035905433450U;
            aOrbiterK = RotL64((aOrbiterK * 4961808568701908559U), 35U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterK, 53U);
            aIngress = aIngress + (RotL64(aOrbiterH, 29U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterE, 42U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterH, 39U)) + aOrbiterB);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 37U) + aOrbiterE) + RotL64(aOrbiterH, 58U)) + RotL64(aCarry, 53U)) + aPhaseGWandererUpdateSaltD[((aIndex + 20U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 52U) + aOrbiterB) + RotL64(aOrbiterA, 23U)) + aPhaseGWandererUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aIngress, 3U) + aOrbiterB) + RotL64(aOrbiterK, 5U)) + RotL64(aCarry, 39U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterH, 13U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererC, 13U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererI, 46U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 10743U)) & S_BLOCK1], 26U) ^ RotL64(aWorkLaneB[((aIndex + 15925U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 8702U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 15106U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 9769U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 13406U)) & S_BLOCK1], 56U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 42U) + RotL64(aPrevious, 57U)) + (RotL64(aIngress, 5U) ^ RotL64(aCross, 29U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterB = (((aWandererK + RotL64(aScatter, 37U)) + RotL64(aCarry, 13U)) + 11998579547770778580U) + aPhaseGOrbiterAssignSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = ((aWandererD + RotL64(aIngress, 13U)) + RotL64(aCarry, 51U)) + 8409465187298704610U;
            aOrbiterC = (aWandererF + RotL64(aPrevious, 4U)) + 3470222286110333500U;
            aOrbiterE = ((aWandererC + RotL64(aCross, 29U)) + RotL64(aCarry, 39U)) + 5704486785203069994U;
            aOrbiterI = ((aWandererG + RotL64(aIngress, 53U)) + 10334944660253279633U) + aPhaseGOrbiterAssignSaltE[((aIndex + 24U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 7626852700722567477U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 14631310754943209743U) ^ aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 1958866541508493967U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 807160297237854120U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 5624154783624196107U;
            aOrbiterB = RotL64((aOrbiterB * 2404066593958052159U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 4971444394698940423U) + aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 6340057638461027062U) ^ aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12027586111086798629U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 9003019862787819481U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 13632057463595873033U) ^ aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 12575202147280216765U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 12766104026871797746U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 4062118445824915939U;
            aOrbiterE = RotL64((aOrbiterE * 13130770039048080701U), 29U);
            //
            aIngress = RotL64(aOrbiterB, 3U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 34U));
            aIngress = aIngress + RotL64(aOrbiterC, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aCross, 11U) + aOrbiterD) + RotL64(aOrbiterE, 57U)) + RotL64(aCarry, 23U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 52U) + aOrbiterD) + RotL64(aOrbiterI, 5U)) + aPhaseGWandererUpdateSaltB[((aIndex + 26U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aIngress, 23U) + aOrbiterC) + RotL64(aOrbiterE, 27U)) + RotL64(aCarry, 3U)) + aPhaseGWandererUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterI, 19U)) + aOrbiterB);
            aWandererF = aWandererF + ((RotL64(aScatter, 35U) + aOrbiterI) + RotL64(aOrbiterC, 38U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 23U) ^ aWandererK);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 60U));
            aCarry = aCarry + RotL64(aWandererF, 5U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 17266U)) & S_BLOCK1], 54U) ^ RotL64(aExpandLaneA[((aIndex + 22237U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aWorkLaneD[((aIndex + 20274U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 24522U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 21186U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 22399U)) & S_BLOCK1], 20U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 57U) ^ RotL64(aPrevious, 38U)) ^ (RotL64(aCarry, 21U) + RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterK = ((aWandererE + RotL64(aCross, 52U)) + RotL64(aCarry, 53U)) + 15188686795415908074U;
            aOrbiterH = (((aWandererC + RotL64(aScatter, 3U)) + RotL64(aCarry, 13U)) + 17310049041983079779U) + aPhaseGOrbiterAssignSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterE = (aWandererA + RotL64(aIngress, 35U)) + 8246925977992441471U;
            aOrbiterD = (((aWandererF + RotL64(aPrevious, 43U)) + RotL64(aCarry, 41U)) + 8644260919918112781U) + aPhaseGOrbiterAssignSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterA = (aWandererH + RotL64(aIngress, 23U)) + 13401663736874819483U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 7940358935238314973U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 13278990328548007839U;
            aOrbiterE = RotL64((aOrbiterE * 285726811877787411U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 11346868298353840706U) + aPhaseGOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 2374077904806833579U;
            aOrbiterD = RotL64((aOrbiterD * 1765686942154321425U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 6978903378645019166U) + aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 11951633297870965212U) ^ aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 12778236598654492185U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 17398460995357409673U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 1215437945597836770U;
            aOrbiterK = RotL64((aOrbiterK * 9322970054123481621U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 1878751468043972239U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 5343002808239712390U;
            aOrbiterA = RotL64((aOrbiterA * 11878640995447558811U), 43U);
            //
            aIngress = RotL64(aOrbiterE, 13U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 3U));
            aIngress = aIngress + RotL64(aOrbiterK, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aScatter, 19U) + aOrbiterH) + RotL64(aOrbiterD, 19U)) + RotL64(aCarry, 53U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterE, 51U)) + aOrbiterD);
            aWandererH = aWandererH + ((((RotL64(aCross, 3U) + RotL64(aOrbiterA, 11U)) + aOrbiterK) + RotL64(aCarry, 39U)) + aPhaseGWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 46U) + RotL64(aOrbiterD, 60U)) + aOrbiterA) + aPhaseGWandererUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aScatter, 35U) + aOrbiterK) + RotL64(aOrbiterH, 35U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 13U) ^ aWandererF);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 21U));
            aCarry = aCarry + RotL64(aWandererE, 37U);
            aCarry = aCarry + RotL64(aIngress, 46U);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 25112U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneB[((aIndex + 25166U)) & S_BLOCK1], 28U));
            aIngress ^= RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 28068U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30551U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32212U)) & S_BLOCK1], 52U));
            aCross ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 30505U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 41U) + RotL64(aCarry, 13U)) ^ (RotL64(aPrevious, 60U) ^ RotL64(aCross, 29U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterC = ((aWandererD + RotL64(aScatter, 5U)) + 8685374557928800912U) + aPhaseGOrbiterAssignSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterI = (((aWandererE + RotL64(aCross, 13U)) + RotL64(aCarry, 41U)) + 3482312691892161229U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = ((aWandererA + RotL64(aPrevious, 48U)) + RotL64(aCarry, 5U)) + 6948130297389161165U;
            aOrbiterD = ((aWandererJ + RotL64(aIngress, 27U)) + RotL64(aCarry, 57U)) + 5506385663788942690U;
            aOrbiterK = (aWandererG + RotL64(aCross, 35U)) + 17859982009307397161U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 9178488809207094043U) + aPhaseGOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 1835479501226057169U;
            aOrbiterE = RotL64((aOrbiterE * 5671861318767342087U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 5368101733632614939U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 9050459666576835422U;
            aOrbiterI = RotL64((aOrbiterI * 10351719549990259551U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 9042186993119635078U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 17528342580198295025U) ^ aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 14316671546614386775U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 6495418332558436882U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 8834495762667327342U;
            aOrbiterC = RotL64((aOrbiterC * 10783141541937645995U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 4364314196965690905U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 6357485231062120459U) ^ aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 289429584586504995U), 37U);
            //
            aIngress = RotL64(aOrbiterE, 43U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterI, 57U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterK, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aScatter, 43U) + RotL64(aOrbiterK, 46U)) + aOrbiterC);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 56U) + aOrbiterE) + RotL64(aOrbiterK, 5U));
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 21U) + RotL64(aOrbiterI, 57U)) + aOrbiterE) + RotL64(aCarry, 29U)) + aPhaseGWandererUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterK, 13U)) + aOrbiterD);
            aWandererG = aWandererG + ((((RotL64(aScatter, 13U) + aOrbiterC) + RotL64(aOrbiterD, 37U)) + RotL64(aCarry, 51U)) + aPhaseGWandererUpdateSaltD[((aIndex + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 3U) ^ aWandererA);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 47U));
            aCarry = aCarry + RotL64(aWandererE, 58U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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

void TwistExpander_PingPong_Arx::GROW_B(TwistWorkSpace *pWorkSpace,
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 8155U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneB[((aIndex + 6231U)) & S_BLOCK1], 52U));
            aIngress ^= RotL64(aExpandLaneC[((aIndex + 4920U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 5194U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4656U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aExpandLaneD[((aIndex + 5947U)) & S_BLOCK1], 60U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 57U) ^ RotL64(aPrevious, 22U)) + (RotL64(aCarry, 41U) + RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterK = ((aWandererF + RotL64(aIngress, 41U)) + 6521330037475130256U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = ((aWandererC + RotL64(aCross, 3U)) + RotL64(aCarry, 39U)) + 12611880456055428940U;
            aOrbiterD = (((aWandererD + RotL64(aPrevious, 18U)) + RotL64(aCarry, 19U)) + 12061611078130934708U) + aPhaseHOrbiterAssignSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterF = (aWandererA + RotL64(aScatter, 29U)) + 1558112410801116984U;
            aOrbiterJ = ((aWandererH + RotL64(aIngress, 53U)) + RotL64(aCarry, 51U)) + 10509115227850160786U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 4045915960688792066U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 1196541286513243082U;
            aOrbiterD = RotL64((aOrbiterD * 5454309408259753479U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 15564991032722373702U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 4897765238703641798U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 9693901276712946763U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 12327429514907752733U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 6189189797708711636U;
            aOrbiterC = RotL64((aOrbiterC * 9017615866338877651U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 6374267075282018852U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 1888758503831341439U;
            aOrbiterF = RotL64((aOrbiterF * 74387714918264257U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 14956857689299491800U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 14879361107223331957U;
            aOrbiterK = RotL64((aOrbiterK * 9166712966729591953U), 41U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterK, 21U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 35U));
            aIngress = aIngress + RotL64(aOrbiterF, 60U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterC, 39U)) + aOrbiterJ);
            aWandererF = aWandererF + ((((RotL64(aCross, 29U) + aOrbiterJ) + RotL64(aOrbiterD, 4U)) + RotL64(aCarry, 41U)) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 47U) + aOrbiterF) + RotL64(aOrbiterC, 13U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 56U) + RotL64(aOrbiterK, 57U)) + aOrbiterJ) + RotL64(aCarry, 53U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 39U) + aOrbiterJ) + RotL64(aOrbiterF, 21U)) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 37U) ^ aWandererF);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 47U));
            aCarry = aCarry + RotL64(aWandererD, 24U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 14610U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneB[((aIndex + 11879U)) & S_BLOCK1], 12U));
            aIngress ^= RotL64(aExpandLaneC[((aIndex + 15445U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 15553U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 15627U)) & S_BLOCK1], 4U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 15158U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 13U) + RotL64(aCross, 27U)) ^ (RotL64(aCarry, 39U) ^ RotL64(aPrevious, 56U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterD = ((aWandererG + RotL64(aCross, 21U)) + RotL64(aCarry, 11U)) + 7948891781097675369U;
            aOrbiterE = ((aWandererA + RotL64(aScatter, 11U)) + 13928362874228230226U) + aPhaseHOrbiterAssignSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterJ = (aWandererC + RotL64(aPrevious, 29U)) + 10776180542602258926U;
            aOrbiterC = (((aWandererK + RotL64(aIngress, 3U)) + RotL64(aCarry, 27U)) + 5735115172149470447U) + aPhaseHOrbiterAssignSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = ((aWandererE + RotL64(aScatter, 52U)) + RotL64(aCarry, 57U)) + 5353591822981766987U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 562301708107268570U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 10467810247578364868U;
            aOrbiterJ = RotL64((aOrbiterJ * 10449089554007059823U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 14541630141152308564U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 2350076897065139429U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 12222554362482034393U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 17519109078651162228U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 6061035173339902910U;
            aOrbiterD = RotL64((aOrbiterD * 10021905773432907835U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 15654836633731000065U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 13723521735153718904U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14459516479283070563U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 2849680038315532197U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 17336102435576647923U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 10984689101753586739U), 35U);
            //
            aIngress = RotL64(aOrbiterD, 43U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterH, 19U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterE, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aPrevious, 29U) + aOrbiterH) + RotL64(aOrbiterJ, 39U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 60U) + RotL64(aOrbiterH, 11U)) + aOrbiterC) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 5U) + RotL64(aOrbiterE, 47U)) + aOrbiterC) + RotL64(aCarry, 11U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 51U) + aOrbiterH) + RotL64(aOrbiterD, 56U)) + aPhaseHWandererUpdateSaltE[((aIndex + 3U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aIngress, 37U) + aOrbiterE) + RotL64(aOrbiterD, 19U)) + RotL64(aCarry, 41U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 5U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 56U));
            aCarry = aCarry + RotL64(aWandererA, 21U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 19123U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneA[((aIndex + 20912U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aExpandLaneD[((aIndex + 17100U)) & S_BLOCK1], 52U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23383U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 18332U)) & S_BLOCK1], 14U));
            aCross ^= RotL64(aExpandLaneC[((aIndex + 18572U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 43U) + RotL64(aCarry, 13U)) ^ (RotL64(aIngress, 57U) + RotL64(aCross, 26U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterF = ((aWandererC + RotL64(aScatter, 35U)) + RotL64(aCarry, 35U)) + 1708250618750199233U;
            aOrbiterK = ((aWandererJ + RotL64(aCross, 43U)) + 12009147777553691142U) + aPhaseHOrbiterAssignSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = (((aWandererA + RotL64(aIngress, 5U)) + RotL64(aCarry, 53U)) + 8393982703399156592U) + aPhaseHOrbiterAssignSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterH = ((aWandererH + RotL64(aPrevious, 13U)) + RotL64(aCarry, 21U)) + 3247327098356831221U;
            aOrbiterJ = (aWandererB + RotL64(aCross, 60U)) + 3403590155376353737U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 18197244558104735044U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 3096253642040701606U;
            aOrbiterG = RotL64((aOrbiterG * 6656168712438620783U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 8012692688785412179U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 17531946907545680745U;
            aOrbiterK = RotL64((aOrbiterK * 16510602981731506381U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 17687695944270225817U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 16147773866007628769U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 16926442582711557877U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 18244641303026196497U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 8839160526348897457U;
            aOrbiterH = RotL64((aOrbiterH * 14268021129087663397U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 10599266240854068246U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 2056723540756216155U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13311591601230386375U), 3U);
            //
            aIngress = RotL64(aOrbiterK, 47U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 35U));
            aIngress = aIngress + RotL64(aOrbiterF, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aPrevious, 29U) + aOrbiterG) + RotL64(aOrbiterK, 37U)) + RotL64(aCarry, 35U)) + aPhaseHWandererUpdateSaltC[((aIndex + 27U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterF, 3U)) + aOrbiterK);
            aWandererH = aWandererH + ((RotL64(aIngress, 57U) + RotL64(aOrbiterG, 11U)) + aOrbiterJ);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 47U) + aOrbiterF) + RotL64(aOrbiterH, 27U));
            aWandererC = aWandererC + ((((RotL64(aIngress, 12U) + aOrbiterJ) + RotL64(aOrbiterH, 46U)) + RotL64(aCarry, 51U)) + aPhaseHWandererUpdateSaltF[((aIndex + 4U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 58U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 23U));
            aCarry = aCarry + RotL64(aWandererC, 11U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 26417U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneB[((aIndex + 27088U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aWorkLaneA[((aIndex + 25329U)) & S_BLOCK1], 52U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 25717U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 28035U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aWorkLaneC[((aIndex + 27446U)) & S_BLOCK1], 12U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 54U) + RotL64(aIngress, 11U)) ^ (RotL64(aPrevious, 23U) + RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterH = ((aWandererE + RotL64(aPrevious, 37U)) + RotL64(aCarry, 57U)) + 10805654776556844351U;
            aOrbiterF = ((aWandererB + RotL64(aIngress, 57U)) + RotL64(aCarry, 41U)) + 582794182442795335U;
            aOrbiterB = (((aWandererF + RotL64(aCross, 3U)) + RotL64(aCarry, 5U)) + 2858343650974681068U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterK = (aWandererI + RotL64(aScatter, 14U)) + 8189584049022064284U;
            aOrbiterA = ((aWandererA + RotL64(aCross, 29U)) + 1565100751996962893U) + aPhaseHOrbiterAssignSaltF[((aIndex + 14U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 8062028016947611891U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 8280504280578451745U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5212851648135050483U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 11326869194491655350U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 1671695656567777163U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7511554500524257921U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 2349843105293943452U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 13015545152052004254U;
            aOrbiterA = RotL64((aOrbiterA * 1316662811685429983U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 16703354404749291869U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 8713231044374305801U;
            aOrbiterH = RotL64((aOrbiterH * 9242480982197688625U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 11118401674497783533U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 14857556493734710364U;
            aOrbiterK = RotL64((aOrbiterK * 3452566050389715195U), 43U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterB, 41U);
            aIngress = aIngress + (RotL64(aOrbiterH, 30U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterK, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aCross, 37U) + RotL64(aOrbiterF, 39U)) + aOrbiterK) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aIngress, 3U) + aOrbiterB) + RotL64(aOrbiterA, 5U)) + RotL64(aCarry, 3U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterK, 53U)) + aOrbiterH);
            aWandererI = aWandererI + ((((RotL64(aScatter, 27U) + RotL64(aOrbiterF, 13U)) + aOrbiterB) + RotL64(aCarry, 23U)) + aPhaseHWandererUpdateSaltB[((aIndex + 21U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 46U) + RotL64(aOrbiterH, 22U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 30U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 43U));
            aCarry = aCarry + RotL64(aWandererA, 57U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
