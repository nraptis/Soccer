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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xADFA53423EF10E1BULL + 0x914BC8E7B30E9BAFULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x8EDE2EE2A8183F65ULL + 0xB14A8A0DBDBF1190ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xD24514F94B1F5933ULL + 0xA9EC3AB3870A787DULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xDC07F048001568BFULL + 0xBBC16DCDA49F11B5ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xEF762F126E981FCBULL + 0xAF185F1C9DA9DBF1ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xE3E57F4A8B306CCBULL + 0xC0F2C37AAF4F33B7ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xE16AEB0A38E256A3ULL + 0xEBB40E383444BE98ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xF602B29D510924FFULL + 0xA0E1D75ED29E210DULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xC496F85955E40C0DULL + 0xDDC334F17D11FC6EULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xFDD33158678AC3DFULL + 0xEF49D0978651FABBULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xD3F2CD35D62F7369ULL + 0xF2ED2446C6870236ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xAA34B5C89119A301ULL + 0xA5459B1AEBB074E6ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xDFCC15C4FEB6A26FULL + 0xD28BC7C084D604FCULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xBC092023FC4F0E53ULL + 0xE5C564577E244511ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xE7733FD03BD2D167ULL + 0x8C59D99DA6B71956ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xAFABDD55FCD59EA3ULL + 0xFC2AEAB1772ECE8CULL);
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 2801U)) & S_BLOCK1], 14U) ^ RotL64(pSnow[((aIndex + 3179U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(mSource[((S_BLOCK1 - aIndex + 4624U)) & S_BLOCK1], 23U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 2111U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCarry, 51U)) ^ (RotL64(aIngress, 36U) ^ RotL64(aCross, 19U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = (((aWandererF + RotL64(aCross, 19U)) + RotL64(aCarry, 43U)) + 13880995121909552664U) + aNonceWordK;
            aOrbiterK = (aWandererJ + RotL64(aIngress, 53U)) + 14534942818069300546U;
            aOrbiterG = (aWandererD + RotL64(aPrevious, 29U)) + 17745973100886007133U;
            aOrbiterA = (aWandererB + RotL64(aScatter, 39U)) + 2249805580771946872U;
            aOrbiterE = ((aWandererG + RotL64(aPrevious, 44U)) + 4460116116396439410U) + aNonceWordM;
            aOrbiterJ = ((aWandererE + RotL64(aScatter, 41U)) + 3378683994078106878U) + aOrbiterAssignSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = ((aWandererC + RotL64(aIngress, 23U)) + RotL64(aCarry, 5U)) + 3992996501048809123U;
            aOrbiterF = (aWandererH + RotL64(aCross, 13U)) + 12057768808864451929U;
            aOrbiterD = (((aWandererA + RotL64(aPrevious, 57U)) + RotL64(aCarry, 19U)) + 4115362079047921130U) + aOrbiterAssignSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterH = (aWandererK + RotL64(aIngress, 21U)) + 15297384955502206698U;
            aOrbiterI = ((aWandererI + RotL64(aScatter, 34U)) + 17623548383481905636U) + aNonceWordH;
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 3559213898000162417U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 12311605719074507335U;
            aOrbiterG = RotL64((aOrbiterG * 3982199462062847697U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 14807313864347885885U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 11222085523291581822U;
            aOrbiterJ = RotL64((aOrbiterJ * 12580941911587215653U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 916681229436292462U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterC) ^ 2441350114032314686U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterB = RotL64((aOrbiterB * 7336079498999018067U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 7361470539894653271U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 12153585147213579808U;
            aOrbiterA = RotL64((aOrbiterA * 3040327545467672961U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 13566300726101613579U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 14875254144748509128U;
            aOrbiterC = RotL64((aOrbiterC * 13699179902908972403U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 9268158535644002904U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterK) ^ 14144295981814993491U) ^ aOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterD = RotL64((aOrbiterD * 12739937231684038161U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 13861225650900541642U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 12620513474052058164U;
            aOrbiterI = RotL64((aOrbiterI * 18141974182442267181U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 14163773386433257965U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 5725700029399455855U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 10446930901088908809U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 16644838246877860102U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 6611825438224873117U;
            aOrbiterE = RotL64((aOrbiterE * 5336239588054125897U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 9408958265247071226U) + aOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 16980073477599191801U;
            aOrbiterF = RotL64((aOrbiterF * 7985839560318985205U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 6513029242607881518U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 13880995121909552664U;
            aOrbiterH = RotL64((aOrbiterH * 17463079726765044639U), 35U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterK, 37U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 48U));
            aIngress = aIngress + (RotL64(aOrbiterF, 57U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterE, 39U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterD, 19U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterA, 6U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aScatter, 23U) + RotL64(aOrbiterE, 21U)) + aOrbiterH);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterC, 19U)) + aOrbiterH);
            aWandererH = aWandererH + (((RotL64(aIngress, 21U) + RotL64(aOrbiterB, 35U)) + aOrbiterH) + aNonceWordJ);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 50U) + RotL64(aOrbiterA, 41U)) + aOrbiterF) + aNonceWordN);
            aWandererK = aWandererK + (((RotL64(aIngress, 3U) + aOrbiterH) + RotL64(aOrbiterA, 27U)) + RotL64(aCarry, 11U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterG, 11U)) + aOrbiterJ) + aWandererUpdateSaltC[((aIndex + 19U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aScatter, 53U) + aOrbiterB) + RotL64(aOrbiterI, 60U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 19U) + aOrbiterD) + RotL64(aOrbiterA, 29U));
            aWandererD = aWandererD + (((RotL64(aIngress, 43U) + RotL64(aOrbiterK, 5U)) + aOrbiterD) + aWandererUpdateSaltF[((aIndex + 5U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 26U) + aOrbiterI) + RotL64(aOrbiterD, 51U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 35U) + aOrbiterG) + RotL64(aOrbiterC, 58U)) + RotL64(aCarry, 19U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 54U));
            aCarry = aCarry + (RotL64(aWandererI, 41U) ^ aWandererG);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 13U));
            aCarry = aCarry + (RotL64(aWandererE, 37U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererH, 51U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererB, 39U);
            aCarry = aCarry + RotL64(aIngress, 48U);
            aCarry = aCarry ^ aNonceWordM;
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 9780U)) & S_BLOCK1], 54U) ^ RotL64(mSource[((aIndex + 10523U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(pSnow[((S_BLOCK1 - aIndex + 5920U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneA[((aIndex + 10131U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 41U) ^ RotL64(aCross, 4U)) ^ (RotL64(aCarry, 19U) + RotL64(aIngress, 53U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = ((aWandererA + RotL64(aScatter, 35U)) + 15036852811491820366U) + aNonceWordP;
            aOrbiterA = (aWandererI + RotL64(aIngress, 27U)) + 305637140752898475U;
            aOrbiterG = ((aWandererE + RotL64(aCross, 13U)) + 11948631574496129610U) + aOrbiterAssignSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterK = (aWandererH + RotL64(aPrevious, 20U)) + 5321623592482991426U;
            aOrbiterE = (aWandererG + RotL64(aCross, 3U)) + 4075270159062690728U;
            aOrbiterF = ((aWandererB + RotL64(aIngress, 29U)) + RotL64(aCarry, 3U)) + 15111580500356908928U;
            aOrbiterJ = ((aWandererF + RotL64(aPrevious, 11U)) + 7244150695504160363U) + aNonceWordJ;
            aOrbiterD = ((aWandererD + RotL64(aScatter, 23U)) + RotL64(aCarry, 19U)) + 5131563519577488862U;
            aOrbiterB = (aWandererJ + RotL64(aCross, 51U)) + 5881954992088651371U;
            aOrbiterI = ((aWandererC + RotL64(aPrevious, 46U)) + RotL64(aCarry, 29U)) + 12780935808751507998U;
            aOrbiterC = (((aWandererK + RotL64(aIngress, 39U)) + 12599159643925470226U) + aOrbiterAssignSaltD[((aIndex + 28U)) & S_SALT1]) + aNonceWordC;
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 9466589929741834066U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 6093158735705189789U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7453778295800853653U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 17461243886150519249U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 15456408913739900718U;
            aOrbiterA = RotL64((aOrbiterA * 16093292401746174671U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 11260643903290392780U) + aNonceWordF;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 7870342756041882616U;
            aOrbiterE = RotL64((aOrbiterE * 2431528656086173419U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 134484990005888936U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 10626896209992890407U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 12034131076645285597U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 14031164129515132292U) + aNonceWordB;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 1771835705730244212U;
            aOrbiterB = RotL64((aOrbiterB * 186981668443596623U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 16395472745067254664U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 1455944290845294254U;
            aOrbiterH = RotL64((aOrbiterH * 6757824754363319079U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 17866422769075350837U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 10226884082632410805U;
            aOrbiterK = RotL64((aOrbiterK * 206035536985843815U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 14474587247775371703U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 8501763445324525303U;
            aOrbiterF = RotL64((aOrbiterF * 5298694643596784007U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 222650368553738561U) + aNonceWordL;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 3901452368735982094U;
            aOrbiterD = RotL64((aOrbiterD * 18347115513126660483U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 3063093906728331146U) + aOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 9026710562384443411U;
            aOrbiterI = RotL64((aOrbiterI * 8411243802199203035U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 11282041925238364080U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 15036852811491820366U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 18185121326941087841U), 27U);
            //
            aIngress = RotL64(aOrbiterI, 19U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterB, 5U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 48U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 11U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 27U));
            aIngress = aIngress + RotL64(aOrbiterD, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aScatter, 12U) + RotL64(aOrbiterD, 41U)) + aOrbiterH);
            aWandererH = aWandererH + (((RotL64(aPrevious, 47U) + aOrbiterF) + RotL64(aOrbiterE, 54U)) + aNonceWordK);
            aWandererC = aWandererC ^ (((RotL64(aCross, 53U) + aOrbiterA) + RotL64(aOrbiterG, 57U)) + aWandererUpdateSaltE[((aIndex + 9U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aIngress, 39U) + RotL64(aOrbiterC, 35U)) + aOrbiterF);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterI, 23U)) + aOrbiterB);
            aWandererA = aWandererA + (((RotL64(aScatter, 23U) + aOrbiterK) + RotL64(aOrbiterG, 38U)) + RotL64(aCarry, 13U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 21U) + RotL64(aOrbiterI, 51U)) + aOrbiterJ) + aWandererUpdateSaltB[((aIndex + 17U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aIngress, 3U) + RotL64(aOrbiterC, 43U)) + aOrbiterJ);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 19U) + aOrbiterI) + RotL64(aOrbiterE, 29U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 6U) + aOrbiterH) + RotL64(aOrbiterK, 5U)) + RotL64(aCarry, 29U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 51U) + aOrbiterD) + RotL64(aOrbiterA, 27U)) + aNonceWordH);
            //
            aCarry = aCarry + (RotL64(aWandererA, 23U) ^ aWandererG);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 52U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 11U));
            aCarry = aCarry + (RotL64(aWandererH, 43U) ^ aWandererE);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 47U));
            aCarry = aCarry + RotL64(aWandererB, 29U);
            aCarry = aCarry + RotL64(aIngress, 50U);
            aCarry = aCarry ^ (aNonceWordA ^ aNonceWordD);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 11316U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 11809U)) & S_BLOCK1], 10U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(mSource[((S_BLOCK1 - aIndex + 16268U)) & S_BLOCK1], 51U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 11404U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 50U) + RotL64(aPrevious, 21U)) + (RotL64(aCross, 3U) ^ RotL64(aIngress, 35U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = ((aWandererB + RotL64(aIngress, 23U)) + 1557680213571812384U) + aOrbiterAssignSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterK = ((aWandererE + RotL64(aCross, 10U)) + 7387349725778021121U) + aNonceWordO;
            aOrbiterJ = (aWandererC + RotL64(aScatter, 43U)) + 15379264067601586976U;
            aOrbiterF = ((aWandererK + RotL64(aPrevious, 35U)) + 3730195724576043708U) + aNonceWordP;
            aOrbiterD = (aWandererF + RotL64(aIngress, 39U)) + 9637070085323827066U;
            aOrbiterC = (aWandererJ + RotL64(aCross, 41U)) + 1170865717363676184U;
            aOrbiterB = ((aWandererI + RotL64(aPrevious, 54U)) + RotL64(aCarry, 13U)) + 2750833653175252030U;
            aOrbiterH = (((aWandererA + RotL64(aScatter, 27U)) + RotL64(aCarry, 37U)) + 15118992811225568305U) + aOrbiterAssignSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = (aWandererG + RotL64(aCross, 47U)) + 4974092922102988451U;
            aOrbiterI = ((aWandererH + RotL64(aIngress, 29U)) + RotL64(aCarry, 27U)) + 10625719096296719514U;
            aOrbiterE = (aWandererD + RotL64(aScatter, 21U)) + 855167122475471865U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 11322911068958340262U) + aOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 4334591909425429835U;
            aOrbiterJ = RotL64((aOrbiterJ * 10059025861172038183U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 14263701737208936392U) + aOrbiterUpdateSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 678723206735649084U;
            aOrbiterC = RotL64((aOrbiterC * 10823239851733632227U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 15652053114252065230U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 1705225940224061401U;
            aOrbiterK = RotL64((aOrbiterK * 3626023093533713579U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 6826394665732900206U) + aOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 11902946775066981141U;
            aOrbiterD = RotL64((aOrbiterD * 18300629262162694137U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 9802212958998591310U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 14001358545610206524U;
            aOrbiterH = RotL64((aOrbiterH * 13172645840788327099U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 4299184726135884309U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 7288757011999872416U;
            aOrbiterI = RotL64((aOrbiterI * 16806027820468277393U), 37U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 233801262480580205U) + aOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 14208660347238680268U;
            aOrbiterG = RotL64((aOrbiterG * 6299693448313154603U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 9217797359740446104U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 18165073197136050838U) ^ aNonceWordC;
            aOrbiterF = RotL64((aOrbiterF * 11677479094709512887U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 9101905235436427482U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 2884224555227870272U;
            aOrbiterB = RotL64((aOrbiterB * 12085235281782370391U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 13118509728421714433U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 1385390888603164704U;
            aOrbiterA = RotL64((aOrbiterA * 6927424835779289199U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 9621084561183039538U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 1557680213571812384U;
            aOrbiterE = RotL64((aOrbiterE * 3202327770291862207U), 3U);
            //
            aIngress = RotL64(aOrbiterK, 51U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterB, 24U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 29U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 39U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 11U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterD, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aIngress, 28U) + aOrbiterC) + RotL64(aOrbiterJ, 19U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterE, 3U)) + aOrbiterA);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 47U) + aOrbiterH) + RotL64(aOrbiterF, 37U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterB, 47U)) + aOrbiterJ);
            aWandererI = aWandererI + ((RotL64(aPrevious, 38U) + aOrbiterE) + RotL64(aOrbiterD, 22U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterE, 41U)) + aOrbiterK);
            aWandererK = aWandererK + (((RotL64(aScatter, 35U) + RotL64(aOrbiterK, 35U)) + aOrbiterB) + aWandererUpdateSaltD[((aIndex + 7U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterG, 57U)) + aOrbiterC);
            aWandererH = aWandererH + (((RotL64(aScatter, 51U) + RotL64(aOrbiterA, 53U)) + aOrbiterI) + RotL64(aCarry, 23U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterH, 12U)) + aOrbiterJ) + aNonceWordN);
            aWandererF = aWandererF + ((((RotL64(aCross, 5U) + aOrbiterB) + RotL64(aOrbiterA, 51U)) + RotL64(aCarry, 51U)) + aWandererUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 14U) ^ aWandererA);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 29U));
            aCarry = aCarry + (RotL64(aWandererK, 35U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererC, 37U) ^ aWandererH);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 51U));
            aCarry = aCarry + RotL64(aWandererI, 11U);
            aCarry = aCarry + RotL64(aIngress, 18U);
            aCarry = aCarry ^ aNonceWordB;
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 21443U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 21060U)) & S_BLOCK1], 38U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16611U)) & S_BLOCK1], 53U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 21410U)) & S_BLOCK1], 20U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 57U) + RotL64(aIngress, 43U)) + (RotL64(aCarry, 23U) ^ RotL64(aPrevious, 6U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = ((aWandererB + RotL64(aIngress, 5U)) + 479672811032092393U) + aNonceWordH;
            aOrbiterC = ((aWandererF + RotL64(aPrevious, 57U)) + 18061121631394564425U) + aOrbiterAssignSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterJ = ((aWandererG + RotL64(aCross, 60U)) + 14237400452740566065U) + aOrbiterAssignSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterF = (aWandererK + RotL64(aScatter, 53U)) + 6723123812257706134U;
            aOrbiterE = (aWandererA + RotL64(aIngress, 11U)) + 4247997188026499248U;
            aOrbiterD = (aWandererD + RotL64(aPrevious, 23U)) + 1939107415066134869U;
            aOrbiterG = ((aWandererI + RotL64(aScatter, 3U)) + RotL64(aCarry, 41U)) + 3912640123546395979U;
            aOrbiterK = (aWandererE + RotL64(aCross, 37U)) + 8295478436553964298U;
            aOrbiterA = ((aWandererH + RotL64(aIngress, 34U)) + RotL64(aCarry, 51U)) + 3218960600711526885U;
            aOrbiterI = (aWandererJ + RotL64(aScatter, 21U)) + 5874096203353388890U;
            aOrbiterB = ((aWandererC + RotL64(aPrevious, 13U)) + RotL64(aCarry, 35U)) + 10294536533673023358U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 11268561953904130747U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 16693201256788898423U;
            aOrbiterJ = RotL64((aOrbiterJ * 16291987237693567209U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 7550969634681894654U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 9501647424602245869U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 11265865222096866605U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 8881869255994319423U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 16770136406906800016U;
            aOrbiterD = RotL64((aOrbiterD * 1782039587385512923U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 16185384746435761363U) + aNonceWordP;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 13841034186650721627U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12000155593277035447U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 15229062695864608309U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 3576122704615303733U;
            aOrbiterK = RotL64((aOrbiterK * 2433987493885779279U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 13898167174453181224U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 12878032061609524049U;
            aOrbiterA = RotL64((aOrbiterA * 18104665741338251495U), 41U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 12719156051299028649U) + aOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 8640980843376950769U;
            aOrbiterI = RotL64((aOrbiterI * 10242616778390983333U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 12133332160916004365U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterK) ^ 8743563985229104484U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterB = RotL64((aOrbiterB * 4575129690615054691U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 7362223873479167793U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 4230720394788635807U;
            aOrbiterH = RotL64((aOrbiterH * 3658720603716856293U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 5095842824285329272U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 7483469517256234638U;
            aOrbiterC = RotL64((aOrbiterC * 9782114499878763883U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 17426017004856399653U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 479672811032092393U;
            aOrbiterF = RotL64((aOrbiterF * 14921028515589317919U), 53U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterD, 3U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 13U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterB, 28U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 19U));
            aIngress = aIngress + (RotL64(aOrbiterA, 37U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterG, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aScatter, 27U) + aOrbiterE) + RotL64(aOrbiterK, 5U));
            aWandererG = aWandererG + ((RotL64(aCross, 29U) + RotL64(aOrbiterE, 30U)) + aOrbiterI);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 60U) + aOrbiterA) + RotL64(aOrbiterI, 57U)) + aWandererUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aIngress, 43U) + RotL64(aOrbiterB, 35U)) + aOrbiterD) + RotL64(aCarry, 37U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterD, 41U)) + aOrbiterG);
            aWandererC = aWandererC + (((RotL64(aPrevious, 35U) + aOrbiterE) + RotL64(aOrbiterC, 19U)) + aNonceWordE);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 39U) + RotL64(aOrbiterJ, 54U)) + aOrbiterE) + aWandererUpdateSaltF[((aIndex + 23U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 41U) + aOrbiterA) + RotL64(aOrbiterD, 43U)) + RotL64(aCarry, 57U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterF, 11U)) + aOrbiterC);
            aWandererA = aWandererA + ((RotL64(aCross, 57U) + RotL64(aOrbiterH, 51U)) + aOrbiterK);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 50U) + RotL64(aOrbiterF, 39U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 60U));
            aCarry = aCarry + (RotL64(aWandererC, 43U) ^ aWandererD);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 41U));
            aCarry = aCarry + (RotL64(aWandererE, 47U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererG, 6U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererH, 57U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = aCarry ^ (aNonceWordB ^ aNonceWordK);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 26865U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneA[((aIndex + 24125U)) & S_BLOCK1], 60U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26705U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneA[((aIndex + 24629U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 39U) + RotL64(aPrevious, 52U)) + (RotL64(aCarry, 19U) ^ RotL64(aIngress, 5U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = ((aWandererJ + RotL64(aCross, 37U)) + 9023059520606551446U) + aOrbiterAssignSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterC = (aWandererH + RotL64(aIngress, 57U)) + 662441755115638133U;
            aOrbiterI = (aWandererK + RotL64(aPrevious, 24U)) + 16957253361196144712U;
            aOrbiterJ = (((aWandererA + RotL64(aScatter, 13U)) + RotL64(aCarry, 13U)) + 7840955025765308605U) + aNonceWordF;
            aOrbiterD = (aWandererD + RotL64(aIngress, 35U)) + 346855809270395799U;
            aOrbiterB = (aWandererI + RotL64(aPrevious, 3U)) + 16099139781586668343U;
            aOrbiterF = (aWandererC + RotL64(aScatter, 21U)) + 3706457327118322098U;
            aOrbiterG = (((aWandererF + RotL64(aCross, 11U)) + 12166825885547622870U) + aOrbiterAssignSaltD[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordA;
            aOrbiterK = ((aWandererE + RotL64(aIngress, 39U)) + RotL64(aCarry, 41U)) + 7792658665720344200U;
            aOrbiterH = ((aWandererB + RotL64(aCross, 19U)) + RotL64(aCarry, 19U)) + 7128477606152986326U;
            aOrbiterA = (aWandererG + RotL64(aPrevious, 48U)) + 11116533962780290084U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 10443889548568288532U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 4402387036946561017U;
            aOrbiterI = RotL64((aOrbiterI * 9032964741841833277U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 13002706161178447654U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 13929727277530310708U;
            aOrbiterB = RotL64((aOrbiterB * 7005639090871200285U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 10949073760696935106U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 15405923432006783533U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 17989565878445202495U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 18096057968822208905U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 3032155040484574973U) ^ aNonceWordH;
            aOrbiterH = RotL64((aOrbiterH * 448597307502544605U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 17462076466907467134U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 15471015427013701406U;
            aOrbiterE = RotL64((aOrbiterE * 6113474000571976139U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 3549031751266594344U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 14243218483842508113U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 9041601306479302047U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 5803147589312920032U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 5549470512227427855U;
            aOrbiterF = RotL64((aOrbiterF * 12592362489263862879U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 10076661824293832189U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 3196799148974716550U;
            aOrbiterK = RotL64((aOrbiterK * 8183276968961467775U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 5245559903456662243U) + aNonceWordM;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 5907555542861339984U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10224549416454347583U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 12670710096595941569U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 655047039452620836U;
            aOrbiterC = RotL64((aOrbiterC * 9717552134857988153U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 2654837870443908572U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 9023059520606551446U;
            aOrbiterD = RotL64((aOrbiterD * 170905364378771841U), 21U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterG, 51U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 11U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 37U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 57U));
            aIngress = aIngress + (RotL64(aOrbiterF, 21U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterD, 14U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aCross, 35U) + RotL64(aOrbiterF, 29U)) + aOrbiterG) + RotL64(aCarry, 5U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 57U) + aOrbiterI) + RotL64(aOrbiterK, 37U));
            aWandererE = aWandererE + ((RotL64(aIngress, 60U) + RotL64(aOrbiterB, 43U)) + aOrbiterC);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 53U) + aOrbiterB) + RotL64(aOrbiterF, 34U)) + aNonceWordL);
            aWandererG = aWandererG + (((RotL64(aCross, 21U) + RotL64(aOrbiterF, 27U)) + aOrbiterJ) + aNonceWordC);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 3U) + aOrbiterH) + RotL64(aOrbiterD, 21U)) + aWandererUpdateSaltE[((aIndex + 21U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aScatter, 5U) + aOrbiterI) + RotL64(aOrbiterA, 11U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterK, 58U)) + aOrbiterD);
            aWandererH = aWandererH + (((RotL64(aScatter, 26U) + RotL64(aOrbiterF, 13U)) + aOrbiterI) + RotL64(aCarry, 21U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterE, 53U)) + aOrbiterA);
            aWandererC = aWandererC + (((RotL64(aIngress, 23U) + RotL64(aOrbiterK, 3U)) + aOrbiterB) + aWandererUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 28U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 51U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 37U));
            aCarry = aCarry + (RotL64(aWandererE, 21U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererD, 5U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererJ, 42U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ aNonceWordB;
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 32292U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31438U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 32485U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27371U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 29U) + RotL64(aIngress, 41U)) + (RotL64(aCross, 4U) ^ RotL64(aPrevious, 53U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = ((aWandererK + RotL64(aIngress, 20U)) + 11698283336767769359U) + aOrbiterAssignSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterC = (aWandererJ + RotL64(aPrevious, 5U)) + 13297826354831483872U;
            aOrbiterH = (((aWandererH + RotL64(aScatter, 39U)) + RotL64(aCarry, 3U)) + 15254999058287530795U) + aNonceWordA;
            aOrbiterD = (aWandererF + RotL64(aCross, 53U)) + 17474166585085346567U;
            aOrbiterA = ((aWandererE + RotL64(aScatter, 41U)) + 15684783498452840289U) + aNonceWordG;
            aOrbiterB = ((aWandererB + RotL64(aCross, 37U)) + 5061229733465216486U) + aOrbiterAssignSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = (aWandererA + RotL64(aIngress, 60U)) + 15370981279168377944U;
            aOrbiterI = ((aWandererG + RotL64(aPrevious, 29U)) + 17966672773619554092U) + aNonceWordD;
            aOrbiterK = ((aWandererC + RotL64(aCross, 13U)) + RotL64(aCarry, 57U)) + 14685092893994491068U;
            aOrbiterG = (aWandererD + RotL64(aScatter, 23U)) + 12798804186209406389U;
            aOrbiterJ = ((aWandererI + RotL64(aIngress, 47U)) + RotL64(aCarry, 23U)) + 2848444181474221574U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 8551142075919636146U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 8833198159158950723U;
            aOrbiterH = RotL64((aOrbiterH * 7650289040764974737U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 7351473160893666232U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 14204899612487622222U;
            aOrbiterA = RotL64((aOrbiterA * 6317485031956448029U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 7008985178526543258U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 13576796403863120356U;
            aOrbiterB = RotL64((aOrbiterB * 13745839827679114077U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 5769784656937900699U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 14075925808204936705U;
            aOrbiterF = RotL64((aOrbiterF * 5844894088757604713U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 17818667502858010896U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 16016922065572683130U;
            aOrbiterI = RotL64((aOrbiterI * 7525645833898085373U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 1582458237855075977U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 10830440354527138227U;
            aOrbiterK = RotL64((aOrbiterK * 10499386926982228251U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 10653964151654643772U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 11218475491129483859U) ^ aOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 3338108067044357141U), 35U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterK) + 9863649760189649255U) + aOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1]) + aNonceWordK;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 13790281439048354358U;
            aOrbiterJ = RotL64((aOrbiterJ * 4682098083538482849U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 14846954923718136337U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 522207783972623813U;
            aOrbiterE = RotL64((aOrbiterE * 14299798934454852811U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 426829715716262697U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 7482977730216354509U;
            aOrbiterC = RotL64((aOrbiterC * 6317437989422015173U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 10736099808538972990U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 11698283336767769359U;
            aOrbiterD = RotL64((aOrbiterD * 17230175904095995929U), 13U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterF, 37U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 48U));
            aIngress = aIngress + (RotL64(aOrbiterA, 51U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterE, 41U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 5U));
            aIngress = aIngress + RotL64(aOrbiterI, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 29U) + aOrbiterD) + RotL64(aOrbiterJ, 53U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 40U) + RotL64(aOrbiterB, 47U)) + aOrbiterJ) + aWandererUpdateSaltD[((aIndex + 15U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 3U) + aOrbiterB) + RotL64(aOrbiterG, 51U)) + aNonceWordN);
            aWandererI = aWandererI ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterI, 41U)) + aOrbiterC);
            aWandererA = aWandererA + (((RotL64(aIngress, 21U) + RotL64(aOrbiterJ, 3U)) + aOrbiterF) + RotL64(aCarry, 3U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 5U) + aOrbiterC) + RotL64(aOrbiterK, 26U));
            aWandererD = aWandererD + (((RotL64(aCross, 51U) + aOrbiterH) + RotL64(aOrbiterI, 29U)) + RotL64(aCarry, 51U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 18U) + aOrbiterF) + RotL64(aOrbiterB, 43U));
            aWandererE = aWandererE + ((RotL64(aPrevious, 37U) + aOrbiterH) + RotL64(aOrbiterF, 39U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterE, 34U)) + aOrbiterB) + aNonceWordE);
            aWandererK = aWandererK + ((((RotL64(aScatter, 53U) + aOrbiterA) + RotL64(aOrbiterB, 5U)) + aNonceWordL) + aWandererUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 29U));
            aCarry = aCarry + (RotL64(aWandererF, 44U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererG, 3U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererC, 41U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererJ, 39U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererK, 13U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ aNonceWordI;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x8CF34B5DB678F191ULL + 0x917BAB371D07CBFBULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xA29B018D7B5B9453ULL + 0x81014A73BB4CF50FULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xA9273EEC042C2687ULL + 0x992E046BE3CD2CE0ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xF1C5860DD568F2B1ULL + 0x8CBBBCCD2B590A1FULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xAFDBE45B4F4221FBULL + 0x8F0FEAB25D7B6398ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xAD62B0325FFD0539ULL + 0xC1573C8ED148B61DULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xBBCAD0AFD8F296EBULL + 0xD4C8592226269D6DULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xA21BB9DD98A89F07ULL + 0x94001A9DDE1F6BDBULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x92D5109F0E3B65FDULL + 0xC0B69ED502BB1CC8ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xF3762E8D8A1D42F7ULL + 0xD6E6530159842AFEULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xD462F880DA572495ULL + 0x9FF5D7446E5C55D5ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xBDAB4F57D27DC93DULL + 0xB3A20D52DB6A04F4ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xED7762526F011FD9ULL + 0xD4EAF464BFFB0F8EULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xDA6F56786F24128DULL + 0xB093852245EF46ECULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x9925D06D614100CDULL + 0xA5D2433D30678494ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xBAF6788EFD183015ULL + 0x99AA4236F8C0038DULL);
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 4283U)) & S_BLOCK1], 18U) ^ RotL64(aExpandLaneC[((aIndex + 1584U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 2496U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 2733U)) & S_BLOCK1], 46U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 27U) ^ RotL64(aIngress, 41U)) + (RotL64(aPrevious, 54U) ^ RotL64(aCross, 5U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = (aWandererA + RotL64(aIngress, 3U)) + 2672739400294801233U;
            aOrbiterG = ((aWandererE + RotL64(aPrevious, 37U)) + RotL64(aCarry, 11U)) + 8475624545015101850U;
            aOrbiterK = ((aWandererG + RotL64(aScatter, 29U)) + 1252755112289831257U) + aNonceWordD;
            aOrbiterH = ((aWandererK + RotL64(aCross, 60U)) + 7938039507649183387U) + aOrbiterAssignSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterF = ((aWandererI + RotL64(aPrevious, 43U)) + 8167413146948861022U) + aOrbiterAssignSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = ((aWandererB + RotL64(aCross, 53U)) + RotL64(aCarry, 27U)) + 17712313989694374353U;
            aOrbiterA = (aWandererF + RotL64(aIngress, 47U)) + 7637042279892596975U;
            aOrbiterD = (((aWandererD + RotL64(aScatter, 23U)) + RotL64(aCarry, 51U)) + 15770412950033467341U) + aNonceWordA;
            aOrbiterJ = ((aWandererC + RotL64(aIngress, 18U)) + 3951812021898608685U) + aNonceWordN;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 8656983621098246507U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 17943342344730687317U;
            aOrbiterK = RotL64((aOrbiterK * 16495519451034883813U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 3087677463651608668U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 16493240011924342788U;
            aOrbiterE = RotL64((aOrbiterE * 16898479041530771871U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 7750923317452683057U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 2185924841611106546U) ^ aOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 708072658250726381U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 14676868738946722416U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 6849098251696302393U;
            aOrbiterJ = RotL64((aOrbiterJ * 2599806275837778069U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 17817755047153606419U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 9900465270314068757U) ^ aNonceWordP;
            aOrbiterB = RotL64((aOrbiterB * 9267925873983176685U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 11380000891112113701U) + aOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 15930503831156546113U;
            aOrbiterH = RotL64((aOrbiterH * 14450535035065393845U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 5439183530402949780U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 3731802052051181843U) ^ aOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7739775058947333169U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 14432344583247783600U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 16192098795467501636U;
            aOrbiterG = RotL64((aOrbiterG * 6285466374319549047U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 1523272672673940290U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 7462092373525113574U;
            aOrbiterF = RotL64((aOrbiterF * 15067751170235540679U), 21U);
            //
            aIngress = RotL64(aOrbiterG, 47U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 19U));
            aIngress = aIngress + (RotL64(aOrbiterB, 43U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 36U));
            aIngress = aIngress + RotL64(aOrbiterJ, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aPrevious, 43U) + RotL64(aOrbiterG, 58U)) + aOrbiterJ);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 56U) + RotL64(aOrbiterJ, 5U)) + aOrbiterH);
            aWandererF = aWandererF + ((((RotL64(aIngress, 51U) + aOrbiterE) + RotL64(aOrbiterK, 23U)) + aNonceWordB) + aWandererUpdateSaltD[((aIndex + 3U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterF, 43U)) + aOrbiterG);
            aWandererB = aWandererB + ((RotL64(aIngress, 29U) + aOrbiterB) + RotL64(aOrbiterE, 39U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterF, 47U)) + aOrbiterD);
            aWandererC = aWandererC + (((RotL64(aCross, 13U) + RotL64(aOrbiterK, 11U)) + aOrbiterH) + RotL64(aCarry, 41U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 4U) + RotL64(aOrbiterJ, 27U)) + aOrbiterB);
            aWandererA = aWandererA + (((((RotL64(aIngress, 35U) + aOrbiterJ) + RotL64(aOrbiterA, 52U)) + RotL64(aCarry, 21U)) + aNonceWordG) + aWandererUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 51U) ^ aWandererF);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 47U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 23U));
            aCarry = aCarry + (RotL64(aWandererD, 30U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererG, 5U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ (aNonceWordF ^ aNonceWordB);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 10371U)) & S_BLOCK1], 18U) ^ RotL64(aExpandLaneD[((aIndex + 10924U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 14639U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 14235U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 51U) + RotL64(aIngress, 36U)) ^ (RotL64(aCross, 5U) ^ RotL64(aPrevious, 21U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = ((aWandererK + RotL64(aCross, 46U)) + 3199575576585871314U) + aNonceWordH;
            aOrbiterD = ((aWandererD + RotL64(aPrevious, 11U)) + RotL64(aCarry, 47U)) + 2533378188975571824U;
            aOrbiterI = (aWandererA + RotL64(aIngress, 19U)) + 6819782112558312658U;
            aOrbiterH = (((aWandererB + RotL64(aScatter, 57U)) + RotL64(aCarry, 29U)) + 12690060987724798497U) + aNonceWordA;
            aOrbiterE = ((aWandererG + RotL64(aPrevious, 4U)) + 7088375139715629606U) + aOrbiterAssignSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterC = ((aWandererJ + RotL64(aCross, 35U)) + 17785618677423695666U) + aNonceWordK;
            aOrbiterF = ((aWandererI + RotL64(aIngress, 53U)) + RotL64(aCarry, 13U)) + 1714999280296491277U;
            aOrbiterK = (aWandererH + RotL64(aScatter, 27U)) + 17611338506932491624U;
            aOrbiterA = ((aWandererC + RotL64(aIngress, 23U)) + 6475727359297421201U) + aOrbiterAssignSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 2347744591204119530U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 2739317903351401068U;
            aOrbiterI = RotL64((aOrbiterI * 15435029315209475631U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 8663535261373274338U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 8205245127823536479U) ^ aNonceWordM;
            aOrbiterE = RotL64((aOrbiterE * 13857005110466856439U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 8916510616749754516U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 3944805940148512932U;
            aOrbiterF = RotL64((aOrbiterF * 18082271583211389701U), 37U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterF) + 14094751253118853302U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordG;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 14094299829196076311U) ^ aOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 6370012560657108493U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 3940673811518673802U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 3015106523254484839U;
            aOrbiterA = RotL64((aOrbiterA * 9655401190755573379U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 15404103131982599922U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 1828655763233900875U;
            aOrbiterG = RotL64((aOrbiterG * 13024358077740310049U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 1236981890899916502U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 18208975564570342697U) ^ aOrbiterUpdateSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4577109989465876801U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 17882273895471449661U) + aNonceWordD;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 16196010765612713713U;
            aOrbiterC = RotL64((aOrbiterC * 15624856645134182005U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 14639250100311162559U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 9139027997336903273U;
            aOrbiterD = RotL64((aOrbiterD * 1853126389565574293U), 13U);
            //
            aIngress = RotL64(aOrbiterH, 4U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 19U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 13U));
            aIngress = aIngress + (RotL64(aOrbiterI, 47U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterK, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aScatter, 19U) + RotL64(aOrbiterI, 13U)) + aOrbiterH) + RotL64(aCarry, 39U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 52U) + RotL64(aOrbiterE, 27U)) + aOrbiterD);
            aWandererB = aWandererB + (((RotL64(aIngress, 13U) + aOrbiterF) + RotL64(aOrbiterI, 60U)) + RotL64(aCarry, 3U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterF, 47U)) + aOrbiterD) + aNonceWordI);
            aWandererH = aWandererH + ((RotL64(aCross, 57U) + aOrbiterA) + RotL64(aOrbiterD, 3U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 29U) + aOrbiterK) + RotL64(aOrbiterG, 37U));
            aWandererI = aWandererI + ((RotL64(aScatter, 39U) + RotL64(aOrbiterG, 54U)) + aOrbiterF);
            aWandererD = aWandererD ^ ((((RotL64(aIngress, 23U) + RotL64(aOrbiterC, 43U)) + aOrbiterA) + aNonceWordP) + aWandererUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 44U) + aOrbiterH) + RotL64(aOrbiterA, 19U)) + aWandererUpdateSaltA[((aIndex + 4U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 30U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererA, 21U) ^ aWandererC);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 39U));
            aCarry = aCarry + (RotL64(aWandererJ, 35U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererH, 53U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ (aNonceWordK ^ aNonceWordC);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 19110U)) & S_BLOCK1], 60U) ^ RotL64(aOperationLaneA[((aIndex + 18828U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 22692U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 23045U)) & S_BLOCK1], 38U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 12U) + RotL64(aCross, 57U)) ^ (RotL64(aPrevious, 27U) + RotL64(aCarry, 43U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = (aWandererE + RotL64(aScatter, 19U)) + 8402620908307642697U;
            aOrbiterA = ((aWandererG + RotL64(aIngress, 51U)) + 11347672014525086047U) + aNonceWordK;
            aOrbiterH = (aWandererB + RotL64(aCross, 57U)) + 2816462912503401876U;
            aOrbiterI = ((aWandererI + RotL64(aPrevious, 12U)) + 6940159795470696093U) + aOrbiterAssignSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterF = ((aWandererD + RotL64(aIngress, 43U)) + RotL64(aCarry, 11U)) + 9134692490095883851U;
            aOrbiterE = (aWandererK + RotL64(aPrevious, 29U)) + 4999455497008026526U;
            aOrbiterC = ((aWandererH + RotL64(aCross, 47U)) + 5992451460350651332U) + aNonceWordM;
            aOrbiterB = (((aWandererC + RotL64(aScatter, 6U)) + RotL64(aCarry, 27U)) + 3417087346651371924U) + aOrbiterAssignSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterG = ((aWandererJ + RotL64(aCross, 37U)) + RotL64(aCarry, 41U)) + 3612773820086198270U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 463398077083428570U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 11249391303705089012U;
            aOrbiterH = RotL64((aOrbiterH * 7106735772303292983U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 17027535139825739501U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 568131384979596481U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 5683451044852895957U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 4793712537158004047U) + aOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 10415170179135963622U;
            aOrbiterI = RotL64((aOrbiterI * 13729564030210361415U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 2391473979460065630U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 4240058362680064261U;
            aOrbiterA = RotL64((aOrbiterA * 12375884373396400889U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 9963957011090031698U) + aNonceWordN;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 3325305624067445525U;
            aOrbiterF = RotL64((aOrbiterF * 3128542681461806309U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 2094945647665114693U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 10703615640774042674U;
            aOrbiterE = RotL64((aOrbiterE * 12641986098450423751U), 23U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 3768738815518590289U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 15021301790376706827U;
            aOrbiterC = RotL64((aOrbiterC * 14445850924223550339U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 10571246886181608316U) + aOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 5130325144599151793U;
            aOrbiterB = RotL64((aOrbiterB * 3185251943547657467U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 8617523421720966373U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 16574597770835250074U;
            aOrbiterG = RotL64((aOrbiterG * 1759209403428937799U), 27U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterI, 58U);
            aIngress = aIngress + (RotL64(aOrbiterD, 23U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 37U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 47U));
            aIngress = aIngress + RotL64(aOrbiterA, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aScatter, 5U) + aOrbiterF) + RotL64(aOrbiterB, 19U)) + RotL64(aCarry, 23U));
            aWandererC = aWandererC ^ ((((RotL64(aPrevious, 29U) + RotL64(aOrbiterI, 58U)) + aOrbiterF) + aNonceWordC) + aWandererUpdateSaltF[((aIndex + 14U)) & S_SALT1]);
            aWandererK = aWandererK + (((((RotL64(aCross, 18U) + RotL64(aOrbiterE, 43U)) + aOrbiterA) + RotL64(aCarry, 5U)) + aNonceWordA) + aWandererUpdateSaltE[((aIndex + 25U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterD, 11U)) + aOrbiterH);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 13U) + aOrbiterG) + RotL64(aOrbiterC, 53U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 53U) + aOrbiterH) + RotL64(aOrbiterI, 47U));
            aWandererH = aWandererH + ((RotL64(aCross, 58U) + RotL64(aOrbiterG, 34U)) + aOrbiterE);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 43U) + aOrbiterH) + RotL64(aOrbiterG, 29U));
            aWandererG = aWandererG + ((RotL64(aPrevious, 39U) + aOrbiterI) + RotL64(aOrbiterE, 5U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 14U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 23U));
            aCarry = aCarry + (RotL64(aWandererD, 5U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererB, 19U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererJ, 27U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ (aNonceWordK ^ aNonceWordC);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 32409U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneB[((aIndex + 27911U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 26038U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneD[((aIndex + 29684U)) & S_BLOCK1], 4U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 19U) ^ RotL64(aCross, 39U)) + (RotL64(aCarry, 52U) + RotL64(aIngress, 5U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = ((aWandererH + RotL64(aIngress, 53U)) + 10805654776556844351U) + aNonceWordD;
            aOrbiterI = (aWandererD + RotL64(aPrevious, 18U)) + 582794182442795335U;
            aOrbiterD = (aWandererA + RotL64(aScatter, 29U)) + 2858343650974681068U;
            aOrbiterH = ((aWandererG + RotL64(aCross, 43U)) + 8189584049022064284U) + aOrbiterAssignSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = (((aWandererI + RotL64(aScatter, 39U)) + RotL64(aCarry, 35U)) + 1565100751996962893U) + aOrbiterAssignSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterF = (((aWandererJ + RotL64(aCross, 23U)) + RotL64(aCarry, 47U)) + 8062028016947611891U) + aNonceWordB;
            aOrbiterK = (((aWandererE + RotL64(aIngress, 47U)) + RotL64(aCarry, 11U)) + 8280504280578451745U) + aNonceWordP;
            aOrbiterB = (aWandererF + RotL64(aPrevious, 13U)) + 11326869194491655350U;
            aOrbiterA = (aWandererB + RotL64(aCross, 34U)) + 1671695656567777163U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 2349843105293943452U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 13015545152052004254U;
            aOrbiterD = RotL64((aOrbiterD * 1316662811685429983U), 39U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 16703354404749291869U) + aOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 8713231044374305801U;
            aOrbiterG = RotL64((aOrbiterG * 9242480982197688625U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 11118401674497783533U) + aNonceWordH;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 14857556493734710364U;
            aOrbiterK = RotL64((aOrbiterK * 3452566050389715195U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 12953419670951660965U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 12666121730825089017U;
            aOrbiterC = RotL64((aOrbiterC * 14049925256934142519U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 11075249639473053423U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 9374217688244187867U;
            aOrbiterH = RotL64((aOrbiterH * 5261156325627117877U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 17608340953291367867U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 13159437499327086340U;
            aOrbiterF = RotL64((aOrbiterF * 4882100944453534805U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 4304700511322366815U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 10172544755256706767U;
            aOrbiterB = RotL64((aOrbiterB * 4013006212154771797U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 17340067939877432472U) + aOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 14130447570008179105U;
            aOrbiterA = RotL64((aOrbiterA * 8178075071208718915U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 2652532710498072378U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 10384945384238518296U;
            aOrbiterI = RotL64((aOrbiterI * 17137694272394304045U), 11U);
            //
            aIngress = RotL64(aOrbiterC, 18U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterD, 23U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 39U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 11U));
            aIngress = aIngress + RotL64(aOrbiterK, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aScatter, 46U) + aOrbiterG) + RotL64(aOrbiterA, 20U)) + RotL64(aCarry, 43U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterC, 27U)) + aOrbiterB);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterI, 13U)) + aOrbiterK) + aNonceWordC);
            aWandererE = aWandererE ^ ((RotL64(aCross, 13U) + aOrbiterF) + RotL64(aOrbiterB, 39U));
            aWandererA = aWandererA + ((((RotL64(aPrevious, 21U) + aOrbiterD) + RotL64(aOrbiterF, 6U)) + RotL64(aCarry, 13U)) + aWandererUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 39U) + aOrbiterK) + RotL64(aOrbiterF, 35U));
            aWandererB = aWandererB + (((RotL64(aScatter, 60U) + aOrbiterH) + RotL64(aOrbiterD, 57U)) + aWandererUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 35U) + RotL64(aOrbiterG, 51U)) + aOrbiterD) + aNonceWordO);
            aWandererG = aWandererG + ((RotL64(aCross, 53U) + aOrbiterG) + RotL64(aOrbiterF, 47U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 11U));
            aCarry = aCarry + (RotL64(aWandererF, 3U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererB, 30U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererE, 43U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererI, 27U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ aNonceWordF;
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

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xE96692B4E09A2FDDULL + 0xCAB5506DC12D68E6ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xFBB2F37C16954B91ULL + 0xF814A8BF5576D7EFULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xB765C68500A2AC95ULL + 0x8F2D32854738C2D9ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xD0CADBF7A4862137ULL + 0x98D0B5732C408267ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xB663359952668DD7ULL + 0xFC632EF66AD17813ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xDE797F7494545795ULL + 0xBE09FE1C2BEA051EULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xAE1261A5BE9BE669ULL + 0xCB9CA58FC382F557ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xE93062C5FEA81A0FULL + 0xC21226BD371911F3ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xA91E006F873BEEA7ULL + 0xA93C4FCEF59C071DULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0x8DCF75D7C1EED5B9ULL + 0xDE58641887587521ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xFCCA9CF2327D1413ULL + 0x8AE84DE6DC3FAD1CULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xA8C28C68F7681E23ULL + 0xA656C3DD733D0187ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xFFB24EE7FDF2E6A1ULL + 0xA261CC359D7E426CULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0x8CFCB72ADF6EB1DFULL + 0x939B3B4535555B9AULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xB71C5E088B8977BFULL + 0xFAC33C766DE0BBCCULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xEC0AD41295AA4447ULL + 0xDFF7D2C5E86CF2E4ULL);
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 5409U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 4840U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 6128U)) & S_BLOCK1], 44U) ^ RotL64(aOperationLaneA[((aIndex + 723U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 11U) ^ RotL64(aPrevious, 50U)) + (RotL64(aCarry, 23U) + RotL64(aIngress, 35U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = ((aWandererK + RotL64(aCross, 57U)) + 16183871922837164759U) + aOrbiterAssignSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterH = (((aWandererF + RotL64(aIngress, 21U)) + RotL64(aCarry, 53U)) + 7002058258090219055U) + aOrbiterAssignSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterG = ((aWandererH + RotL64(aPrevious, 47U)) + 5650868611888303705U) + aNonceWordC;
            aOrbiterD = ((aWandererG + RotL64(aScatter, 5U)) + RotL64(aCarry, 11U)) + 11899839660943876690U;
            aOrbiterA = ((aWandererB + RotL64(aPrevious, 36U)) + RotL64(aCarry, 29U)) + 15349649504488111111U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 14060149569086744970U) + aNonceWordD;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 12920917574225030112U;
            aOrbiterG = RotL64((aOrbiterG * 6552626684290469367U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 2831994965175330135U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 18312543585028439192U) ^ aOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 11618182708195744321U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 11657562205118394239U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 10850792819281246052U;
            aOrbiterD = RotL64((aOrbiterD * 10663100544207879337U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 17810371216216125323U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 7963413941144223128U) ^ aNonceWordM;
            aOrbiterH = RotL64((aOrbiterH * 534217972450595401U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 5498715358793875584U) + aOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 9256727548911651373U;
            aOrbiterA = RotL64((aOrbiterA * 10498848323914000989U), 3U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterG, 60U);
            aIngress = aIngress + (RotL64(aOrbiterD, 35U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterA, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((((RotL64(aIngress, 39U) + aOrbiterG) + RotL64(aOrbiterE, 39U)) + RotL64(aCarry, 43U)) + aNonceWordO) + aWandererUpdateSaltF[((aIndex + 29U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aCross, 24U) + aOrbiterH) + RotL64(aOrbiterA, 27U)) + aNonceWordH);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 13U) + aOrbiterG) + RotL64(aOrbiterA, 19U)) + RotL64(aCarry, 19U)) + aWandererUpdateSaltC[((aIndex + 12U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 5U) + aOrbiterA) + RotL64(aOrbiterE, 50U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterH, 3U)) + aOrbiterD) + aNonceWordN);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 14U));
            aCarry = aCarry + (RotL64(aWandererB, 27U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererF, 39U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ (aNonceWordO ^ aNonceWordI);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 15398U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneD[((aIndex + 10134U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 9347U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneB[((aIndex + 13439U)) & S_BLOCK1], 6U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 35U) ^ RotL64(aCross, 5U)) + (RotL64(aCarry, 23U) + RotL64(aIngress, 50U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = ((aWandererF + RotL64(aIngress, 35U)) + RotL64(aCarry, 11U)) + 2786079456995203065U;
            aOrbiterI = (aWandererK + RotL64(aCross, 43U)) + 7237256119153857253U;
            aOrbiterG = ((((aWandererA + RotL64(aScatter, 60U)) + RotL64(aCarry, 57U)) + 9310834010563647604U) + aOrbiterAssignSaltC[((aIndex + 22U)) & S_SALT1]) + aNonceWordI;
            aOrbiterD = ((aWandererD + RotL64(aPrevious, 21U)) + RotL64(aCarry, 43U)) + 17361734905706517877U;
            aOrbiterH = ((aWandererB + RotL64(aCross, 51U)) + 15837111231884647451U) + aOrbiterAssignSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 18065431964418026445U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 3029123922999952652U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 16309219658285890145U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 5166926595573507837U) + aNonceWordD;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 1918425684273807598U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 16616641579714896719U), 53U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterG) + 4724551751012661440U) + aOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1]) + aNonceWordO;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 1818014487579644390U;
            aOrbiterC = RotL64((aOrbiterC * 14904092108647864911U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 6670090372241084216U) + aOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 8485757110007268693U;
            aOrbiterI = RotL64((aOrbiterI * 11876760095108618363U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 4928130251509514742U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 2528788422725346792U;
            aOrbiterD = RotL64((aOrbiterD * 1855982047967756661U), 27U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterH, 27U);
            aIngress = aIngress + (RotL64(aOrbiterD, 60U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterG, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aScatter, 51U) + RotL64(aOrbiterD, 5U)) + aOrbiterI) + aNonceWordM);
            aWandererK = aWandererK + (((((RotL64(aPrevious, 37U) + aOrbiterC) + RotL64(aOrbiterH, 13U)) + RotL64(aCarry, 57U)) + aNonceWordJ) + aWandererUpdateSaltA[((aIndex + 7U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((((RotL64(aIngress, 4U) + RotL64(aOrbiterG, 29U)) + aOrbiterH) + aNonceWordF) + aWandererUpdateSaltD[((aIndex + 27U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 27U) + RotL64(aOrbiterC, 52U)) + aOrbiterI) + RotL64(aCarry, 39U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 19U) + aOrbiterG) + RotL64(aOrbiterD, 41U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 38U));
            aCarry = aCarry + (RotL64(aWandererK, 29U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererF, 21U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ aNonceWordJ;
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 20525U)) & S_BLOCK1], 28U) ^ RotL64(aWorkLaneA[((aIndex + 18535U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 20816U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 17146U)) & S_BLOCK1], 6U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 30U) + RotL64(aCarry, 57U)) ^ (RotL64(aCross, 43U) ^ RotL64(aPrevious, 13U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = (aWandererG + RotL64(aPrevious, 14U)) + 17668251151213543491U;
            aOrbiterI = (((aWandererK + RotL64(aCross, 23U)) + RotL64(aCarry, 57U)) + 16101602509895104517U) + aNonceWordB;
            aOrbiterA = (((aWandererI + RotL64(aScatter, 47U)) + RotL64(aCarry, 43U)) + 9083915270773304935U) + aOrbiterAssignSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterC = (((aWandererD + RotL64(aIngress, 37U)) + 12810720730318214811U) + aOrbiterAssignSaltB[((aIndex + 11U)) & S_SALT1]) + aNonceWordG;
            aOrbiterD = (((aWandererC + RotL64(aPrevious, 5U)) + RotL64(aCarry, 13U)) + 18113428002071925621U) + aNonceWordM;
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 1582208899354109878U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 4180688104819188154U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3391785441902730815U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 8954598189262820611U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 15360094153175355879U) ^ aNonceWordC;
            aOrbiterI = RotL64((aOrbiterI * 8177798855402983685U), 53U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterC) + 8383954114668216260U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordD;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 15626783326234049197U;
            aOrbiterF = RotL64((aOrbiterF * 15058420415480073793U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 10609978564404958066U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 17656516608997517984U;
            aOrbiterC = RotL64((aOrbiterC * 4590620354119899777U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 760077259110786536U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 3597338735888033063U;
            aOrbiterD = RotL64((aOrbiterD * 6548831472863517621U), 29U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterD, 13U);
            aIngress = aIngress + (RotL64(aOrbiterA, 3U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterI, 24U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((((RotL64(aCross, 13U) + RotL64(aOrbiterI, 13U)) + aOrbiterA) + RotL64(aCarry, 21U)) + aNonceWordN) + aWandererUpdateSaltB[((aIndex + 3U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterA, 47U)) + aOrbiterC);
            aWandererG = aWandererG + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterC, 3U)) + aOrbiterF) + RotL64(aCarry, 35U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 5U) + RotL64(aOrbiterI, 56U)) + aOrbiterF) + aWandererUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aIngress, 58U) + RotL64(aOrbiterA, 27U)) + aOrbiterD) + aNonceWordK);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 19U));
            aCarry = aCarry + (RotL64(aWandererG, 27U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererD, 60U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = aCarry ^ aNonceWordJ;
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 25838U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneB[((aIndex + 26544U)) & S_BLOCK1], 20U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 30674U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 27993U)) & S_BLOCK1], 44U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 60U) + RotL64(aCarry, 13U)) + (RotL64(aPrevious, 27U) ^ RotL64(aCross, 47U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = (((aWandererF + RotL64(aPrevious, 41U)) + RotL64(aCarry, 35U)) + 5131645209694953015U) + aNonceWordE;
            aOrbiterJ = ((aWandererC + RotL64(aScatter, 54U)) + 12070391048835379854U) + aNonceWordI;
            aOrbiterG = ((aWandererG + RotL64(aCross, 29U)) + RotL64(aCarry, 5U)) + 2604295836242338724U;
            aOrbiterB = (((aWandererB + RotL64(aIngress, 21U)) + 14042039029284001596U) + aOrbiterAssignSaltE[((aIndex + 19U)) & S_SALT1]) + aNonceWordF;
            aOrbiterC = (((aWandererH + RotL64(aScatter, 11U)) + RotL64(aCarry, 57U)) + 8914654543854559327U) + aOrbiterAssignSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 2185619407969359869U) + aNonceWordC;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 5187406295103352574U) ^ aNonceWordH;
            aOrbiterG = RotL64((aOrbiterG * 10497064008152537837U), 53U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 8022832481290871217U) + aOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 8783061916740573472U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 3309891377744201773U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 10711028365596196301U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterJ) ^ 13387065038269133571U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterB = RotL64((aOrbiterB * 12444578026365205255U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 11187001318931801582U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 14191473173276034019U;
            aOrbiterJ = RotL64((aOrbiterJ * 2491253922434756431U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 16207761776716426435U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 9677408414452078760U;
            aOrbiterC = RotL64((aOrbiterC * 5487303383095129949U), 19U);
            //
            aIngress = RotL64(aOrbiterJ, 21U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterG, 57U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterC, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aIngress, 43U) + aOrbiterI) + RotL64(aOrbiterC, 47U)) + aWandererUpdateSaltF[((aIndex + 10U)) & S_SALT1]);
            aWandererB = aWandererB + (((((RotL64(aScatter, 20U) + aOrbiterB) + RotL64(aOrbiterG, 28U)) + RotL64(aCarry, 53U)) + aNonceWordJ) + aWandererUpdateSaltC[((aIndex + 20U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 29U) + aOrbiterC) + RotL64(aOrbiterB, 57U)) + aNonceWordB);
            aWandererF = aWandererF + (((RotL64(aCross, 57U) + RotL64(aOrbiterB, 19U)) + aOrbiterI) + RotL64(aCarry, 39U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 11U) + aOrbiterG) + RotL64(aOrbiterJ, 3U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 57U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 3U));
            aCarry = aCarry + RotL64(aWandererC, 43U);
            aCarry = aCarry + RotL64(aIngress, 14U);
            aCarry = aCarry ^ (aNonceWordB ^ aNonceWordA);
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

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xCCF26501E3DA8F83ULL + 0xF6809D34A852E37DULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xC06CE209B7906F81ULL + 0xB36A2F6DC8186F51ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x8123FEC645252533ULL + 0xBEA65D7CA3324083ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xB15CF4721276D3DBULL + 0xB969A9396F39EC3BULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xD25075F55EF79433ULL + 0x88FAAFB6A72B349EULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xE448EEF1B6E23003ULL + 0xD8418D06141C8769ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x9674540B7829E3C1ULL + 0x9DC438CB8DCA9D8AULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x873B7569E6B87F31ULL + 0xBB70E05C6DA0AF8EULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xAFE80130EF7C4BABULL + 0xC596E7BBC505ED06ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0x81AD9E2BC081A863ULL + 0x96FEDDA75477C36AULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xC3CB7689BCCAD617ULL + 0xF20DE76EC9C617C4ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xFB2CA833B96AD0D5ULL + 0xFE4565DF0B8B615DULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xACB9682BA1E13109ULL + 0xAAD7120A4C2BD3F5ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x86C50F4D8FE6437DULL + 0x910449ACEFD70A99ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xF04E1B41CAAF4E45ULL + 0xA82AF7886BB40D87ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xA8645B9A0EC2B325ULL + 0xEA325A43600264BAULL);
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 2359U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 463U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 4110U)) & S_BLOCK1], 20U) ^ RotL64(aExpandLaneA[((aIndex + 7431U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 52U) + RotL64(aCarry, 5U)) + (RotL64(aIngress, 37U) ^ RotL64(aCross, 19U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (((aWandererA + RotL64(aPrevious, 43U)) + RotL64(aCarry, 41U)) + 12131317914288566437U) + aNonceWordE;
            aOrbiterC = ((aWandererE + RotL64(aCross, 37U)) + 5672805657999385496U) + aNonceWordI;
            aOrbiterK = (((aWandererK + RotL64(aScatter, 53U)) + 3581710244233124197U) + aOrbiterAssignSaltD[((aIndex + 4U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterB = (aWandererI + RotL64(aIngress, 23U)) + 15251296040538489436U;
            aOrbiterH = (aWandererG + RotL64(aScatter, 11U)) + 11295008604679904153U;
            aOrbiterF = (((aWandererC + RotL64(aCross, 3U)) + RotL64(aCarry, 11U)) + 2230897493419504490U) + aOrbiterAssignSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterE = ((aWandererJ + RotL64(aIngress, 60U)) + RotL64(aCarry, 27U)) + 7109600123297458999U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 13119156643107683803U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 14755160867807355250U) ^ aNonceWordL;
            aOrbiterK = RotL64((aOrbiterK * 10007087518844899239U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 16829363373287496832U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 16981122946707720883U;
            aOrbiterH = RotL64((aOrbiterH * 5394974422201576627U), 37U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 8806000776958603317U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 16810923047720876014U) ^ aNonceWordK;
            aOrbiterF = RotL64((aOrbiterF * 17872735050219539145U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 8129657889554436328U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 8653100378491974463U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 11395283153912468661U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 17048985838727432415U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 10892675550889823573U) ^ aNonceWordH;
            aOrbiterJ = RotL64((aOrbiterJ * 976298937314081913U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 15960158965421254346U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 12290011578634850001U;
            aOrbiterB = RotL64((aOrbiterB * 9280475585104357745U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 16265047040311479093U) + aOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 10312956912303656248U;
            aOrbiterC = RotL64((aOrbiterC * 3012584393253845131U), 29U);
            //
            aIngress = RotL64(aOrbiterK, 11U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 41U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 60U));
            aIngress = aIngress + RotL64(aOrbiterJ, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aIngress, 21U) + RotL64(aOrbiterC, 46U)) + aOrbiterE) + aWandererUpdateSaltE[((aIndex + 11U)) & S_SALT1]);
            aWandererG = aWandererG + (((((RotL64(aCross, 41U) + aOrbiterJ) + RotL64(aOrbiterC, 37U)) + RotL64(aCarry, 27U)) + aNonceWordO) + aWandererUpdateSaltD[((aIndex + 23U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterJ, 5U)) + aOrbiterF);
            aWandererI = aWandererI + ((RotL64(aScatter, 57U) + RotL64(aOrbiterF, 13U)) + aOrbiterC);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 5U) + aOrbiterE) + RotL64(aOrbiterB, 21U));
            aWandererA = aWandererA + (((RotL64(aScatter, 47U) + RotL64(aOrbiterE, 57U)) + aOrbiterH) + RotL64(aCarry, 47U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 28U) + RotL64(aOrbiterB, 27U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererA, 58U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererG, 35U) ^ aWandererJ);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 11U));
            aCarry = aCarry + RotL64(aWandererK, 23U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ aNonceWordM;
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 15769U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 10845U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 15114U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneB[((aIndex + 12187U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 23U) ^ RotL64(aCarry, 57U)) + (RotL64(aIngress, 6U) + RotL64(aCross, 39U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = (aWandererG + RotL64(aScatter, 53U)) + 14214886793361825363U;
            aOrbiterI = ((aWandererJ + RotL64(aIngress, 5U)) + 17267959031078766320U) + aOrbiterAssignSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = ((aWandererB + RotL64(aCross, 60U)) + RotL64(aCarry, 19U)) + 16436067429484887644U;
            aOrbiterD = (((aWandererI + RotL64(aPrevious, 39U)) + RotL64(aCarry, 35U)) + 9885951769332633820U) + aNonceWordH;
            aOrbiterB = (((aWandererD + RotL64(aScatter, 21U)) + RotL64(aCarry, 47U)) + 12971711341813893304U) + aOrbiterAssignSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = ((aWandererE + RotL64(aPrevious, 47U)) + 199970353398450154U) + aNonceWordO;
            aOrbiterH = (aWandererK + RotL64(aIngress, 29U)) + 1237341696444162094U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 7991128854417613360U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 14809029847149045833U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 5940857360838299105U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 2559509556915775947U) + aNonceWordN;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 14336829730147834160U;
            aOrbiterE = RotL64((aOrbiterE * 15103242520064900873U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 8853631886733610440U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 13346159398673246914U;
            aOrbiterD = RotL64((aOrbiterD * 13660497151446983393U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 12121095718571872976U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 16239781125815589804U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5157009090454962231U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 9051377033794324106U) + aOrbiterUpdateSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 13805815136723461780U) ^ aNonceWordG;
            aOrbiterB = RotL64((aOrbiterB * 571129481747181357U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 14849157800322754413U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 18116651528452542634U;
            aOrbiterJ = RotL64((aOrbiterJ * 3638480428016835537U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 4105057226952948599U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 5911714320560994391U;
            aOrbiterH = RotL64((aOrbiterH * 1796514171654961389U), 21U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterB, 51U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 44U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 11U));
            aIngress = aIngress + RotL64(aOrbiterJ, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aCross, 5U) + aOrbiterB) + RotL64(aOrbiterI, 53U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterH, 3U)) + aOrbiterE) + aWandererUpdateSaltF[((aIndex + 20U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 51U) + aOrbiterD) + RotL64(aOrbiterC, 35U)) + aWandererUpdateSaltA[((aIndex + 4U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aScatter, 44U) + RotL64(aOrbiterC, 43U)) + aOrbiterE) + RotL64(aCarry, 57U)) + aNonceWordA);
            aWandererB = aWandererB ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterI, 12U)) + aOrbiterE);
            aWandererG = aWandererG + (((RotL64(aPrevious, 27U) + aOrbiterH) + RotL64(aOrbiterC, 29U)) + RotL64(aCarry, 19U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterJ, 23U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererI, 41U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererB, 18U) ^ aWandererD);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 3U));
            aCarry = aCarry + RotL64(aWandererE, 47U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ (aNonceWordF ^ aNonceWordJ);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 16703U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneA[((aIndex + 24081U)) & S_BLOCK1], 36U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 17429U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 19977U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 10U) + RotL64(aPrevious, 27U)) ^ (RotL64(aCarry, 57U) ^ RotL64(aIngress, 39U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = ((aWandererD + RotL64(aCross, 19U)) + RotL64(aCarry, 5U)) + 12809562813316740345U;
            aOrbiterB = (((aWandererG + RotL64(aIngress, 57U)) + RotL64(aCarry, 41U)) + 17084212535326321199U) + aOrbiterAssignSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterI = ((aWandererK + RotL64(aPrevious, 40U)) + RotL64(aCarry, 23U)) + 16074921689983846769U;
            aOrbiterG = ((aWandererF + RotL64(aScatter, 47U)) + 14027986153007120145U) + aNonceWordM;
            aOrbiterE = (aWandererE + RotL64(aIngress, 13U)) + 7633455951809250227U;
            aOrbiterJ = (aWandererA + RotL64(aPrevious, 5U)) + 340989348513370174U;
            aOrbiterD = ((aWandererJ + RotL64(aCross, 27U)) + 5307820377645020116U) + aOrbiterAssignSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 5605285015771527274U) + aOrbiterUpdateSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 5293500434746182790U) ^ aOrbiterUpdateSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 17674669610895537063U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 7263156475892261811U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 10672879570907433005U) ^ aNonceWordD;
            aOrbiterB = RotL64((aOrbiterB * 2506338667179450741U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 16659226780900986107U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 9774892622769850665U;
            aOrbiterA = RotL64((aOrbiterA * 7487477727543183211U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 10728057184108279042U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 5032485856947407217U;
            aOrbiterG = RotL64((aOrbiterG * 16651577903809154285U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 14642241075374862345U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 8386481273395203518U) ^ aNonceWordH;
            aOrbiterE = RotL64((aOrbiterE * 11649977733867003445U), 37U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 2874153265304098104U) + aOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 11519900149177261000U;
            aOrbiterJ = RotL64((aOrbiterJ * 2010158758971864505U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 8885690878540115768U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 4482143389870987714U) ^ aNonceWordJ;
            aOrbiterD = RotL64((aOrbiterD * 7105332459437434281U), 47U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterG, 41U);
            aIngress = aIngress + (RotL64(aOrbiterD, 60U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterA, 27U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterE, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aIngress, 35U) + RotL64(aOrbiterE, 29U)) + aOrbiterJ) + RotL64(aCarry, 19U)) + aNonceWordF);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 51U) + RotL64(aOrbiterA, 60U)) + aOrbiterG) + aNonceWordB);
            aWandererF = aWandererF + ((((RotL64(aCross, 29U) + aOrbiterD) + RotL64(aOrbiterI, 21U)) + RotL64(aCarry, 3U)) + aNonceWordO);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 57U) + aOrbiterD) + RotL64(aOrbiterJ, 35U));
            aWandererJ = aWandererJ + ((RotL64(aCross, 41U) + RotL64(aOrbiterI, 3U)) + aOrbiterA);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 22U) + aOrbiterI) + RotL64(aOrbiterB, 43U)) + aWandererUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 3U) + aOrbiterG) + RotL64(aOrbiterJ, 13U)) + aWandererUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 35U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererJ, 23U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererF, 3U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererG, 10U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ aNonceWordO;
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 31501U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneB[((aIndex + 27012U)) & S_BLOCK1], 10U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 30490U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 29915U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCarry, 40U)) ^ (RotL64(aCross, 21U) ^ RotL64(aIngress, 57U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (((aWandererG + RotL64(aIngress, 14U)) + RotL64(aCarry, 57U)) + 13499155707765393469U) + aNonceWordL;
            aOrbiterB = ((aWandererC + RotL64(aScatter, 3U)) + 3740324981823726185U) + aNonceWordJ;
            aOrbiterG = ((aWandererJ + RotL64(aPrevious, 41U)) + RotL64(aCarry, 11U)) + 5470765363949735652U;
            aOrbiterI = (((aWandererB + RotL64(aCross, 35U)) + RotL64(aCarry, 27U)) + 3446436171274452326U) + aOrbiterAssignSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = (aWandererA + RotL64(aScatter, 27U)) + 1778929412631211933U;
            aOrbiterE = (((aWandererH + RotL64(aIngress, 57U)) + 14666308799855220954U) + aOrbiterAssignSaltE[(((31U - aIndex) + 28U)) & S_SALT1]) + aNonceWordK;
            aOrbiterH = (aWandererD + RotL64(aCross, 21U)) + 4548410236791175055U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 5829739767694190372U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 14319231414903675748U;
            aOrbiterG = RotL64((aOrbiterG * 4966501102515775601U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 1513851750246111405U) + aNonceWordB;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 1685620217748986019U;
            aOrbiterE = RotL64((aOrbiterE * 9286548037413609445U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 16284162182006054402U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 6271539598462003309U;
            aOrbiterB = RotL64((aOrbiterB * 13923286694131331137U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 12669312437565969473U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 11894755313393001665U) ^ aOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 12556759675372354075U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 6315983824634946566U) + aOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 17106616474222892782U) ^ aNonceWordN;
            aOrbiterJ = RotL64((aOrbiterJ * 167205520766791073U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 13350266700180455548U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 4608846311203767162U;
            aOrbiterI = RotL64((aOrbiterI * 2504857468837437365U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 14195866746143604365U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 7917977448256795054U) ^ aOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5927771378657284557U), 11U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterE, 13U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 29U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 57U));
            aIngress = aIngress + RotL64(aOrbiterB, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((((RotL64(aIngress, 13U) + aOrbiterF) + RotL64(aOrbiterI, 35U)) + aNonceWordM) + aWandererUpdateSaltD[((aIndex + 3U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aCross, 23U) + aOrbiterF) + RotL64(aOrbiterH, 51U)) + RotL64(aCarry, 35U)) + aWandererUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterE, 3U)) + aOrbiterF);
            aWandererB = aWandererB + ((((RotL64(aScatter, 29U) + aOrbiterB) + RotL64(aOrbiterG, 57U)) + RotL64(aCarry, 53U)) + aNonceWordP);
            aWandererC = aWandererC ^ (((RotL64(aCross, 54U) + aOrbiterG) + RotL64(aOrbiterJ, 19U)) + aNonceWordE);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 35U) + RotL64(aOrbiterE, 28U)) + aOrbiterJ);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 3U) + aOrbiterI) + RotL64(aOrbiterB, 41U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 50U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 5U));
            aCarry = aCarry + (RotL64(aWandererG, 35U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererA, 57U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ aNonceWordD;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xC863125EFA5618E5ULL + 0xAE58E5414F8B15E0ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xB2B835796D8A3E27ULL + 0x926DF07AF15AB8B4ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x82F4D895C1E0AF1FULL + 0x9E8D6F863C681B74ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xDE1610A118CAEBB7ULL + 0xC74D6071CC45F225ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xCFB8C37519BB5467ULL + 0xB35E4EE2C2A97576ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xE18AAD76DD90EAA3ULL + 0xCFB1F80256A978BEULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x85542CE7499C5E05ULL + 0xC6EF43AEB226E844ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xFB7F37678C6F9A41ULL + 0x9BDAF6A352C70EA7ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xD449B9BD1BC440EFULL + 0xFBD6CA6EF5DC5FE9ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0x938F047CC2A2F117ULL + 0xD105E60EF79C9132ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xBB2BF8A927C19B43ULL + 0xA9F968F61A6419C2ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xDC7F2AC07456E7AFULL + 0xEF7F2062BC11B819ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xA502811E61F4D0FBULL + 0x95BA9AE66EF5596BULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xC4CF939CDF857C1FULL + 0xA715DEB1BF10BDEEULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x97138AAE754F2C0FULL + 0xBF03E23100575ED1ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0x9F340A959C01A585ULL + 0x9879BB8C925040CDULL);
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 4099U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneC[((aIndex + 164U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 6420U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneA[((aIndex + 277U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 43U) ^ RotL64(aCarry, 12U)) + (RotL64(aCross, 27U) ^ RotL64(aPrevious, 57U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = ((aWandererJ + RotL64(aPrevious, 14U)) + 15910560457440369082U) + aNonceWordO;
            aOrbiterC = ((aWandererG + RotL64(aCross, 43U)) + 17953072986407436888U) + aOrbiterAssignSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = (aWandererB + RotL64(aScatter, 37U)) + 15446940721193538669U;
            aOrbiterA = (((aWandererE + RotL64(aIngress, 3U)) + RotL64(aCarry, 37U)) + 3020785262774422009U) + aNonceWordP;
            aOrbiterB = ((aWandererK + RotL64(aPrevious, 21U)) + 7001288645424994404U) + aNonceWordM;
            aOrbiterG = (((aWandererF + RotL64(aCross, 27U)) + RotL64(aCarry, 53U)) + 13385250665458462689U) + aOrbiterAssignSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterH = ((aWandererH + RotL64(aScatter, 51U)) + RotL64(aCarry, 5U)) + 4841895644623005949U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 13053476783239482065U) + aOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 641996979335975244U) ^ aOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 3697673197256549833U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 16211238020928688299U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 12715448751323279480U) ^ aNonceWordD;
            aOrbiterB = RotL64((aOrbiterB * 2116880429675303291U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 17784406727699995290U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 16626339815786580778U;
            aOrbiterG = RotL64((aOrbiterG * 13940754474750138041U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 9035070625716345139U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 6085848172494001945U) ^ aOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 10405728912339646693U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 1177103851507561053U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 2281901691017816407U;
            aOrbiterI = RotL64((aOrbiterI * 3142197009403602497U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 9040984343694325070U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 13334258224023902365U;
            aOrbiterA = RotL64((aOrbiterA * 4782523727707164869U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 1079824790138592518U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 14024082692012948652U;
            aOrbiterC = RotL64((aOrbiterC * 3219489374333737903U), 5U);
            //
            aIngress = RotL64(aOrbiterA, 5U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 21U));
            aIngress = aIngress + (RotL64(aOrbiterG, 13U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterI, 38U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aScatter, 29U) + aOrbiterH) + RotL64(aOrbiterA, 29U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterH, 19U)) + aOrbiterC);
            aWandererF = aWandererF + (((RotL64(aPrevious, 41U) + aOrbiterI) + RotL64(aOrbiterB, 3U)) + RotL64(aCarry, 39U));
            aWandererH = aWandererH ^ ((((RotL64(aIngress, 60U) + aOrbiterA) + RotL64(aOrbiterJ, 11U)) + aNonceWordC) + aWandererUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 19U) + aOrbiterI) + RotL64(aOrbiterJ, 50U)) + RotL64(aCarry, 13U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 11U) + aOrbiterJ) + RotL64(aOrbiterG, 43U));
            aWandererE = aWandererE + (((RotL64(aScatter, 35U) + RotL64(aOrbiterI, 37U)) + aOrbiterC) + aWandererUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 39U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 34U));
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererH, 53U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ (aNonceWordC ^ aNonceWordA);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 11537U)) & S_BLOCK1], 46U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 13994U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 14757U)) & S_BLOCK1], 52U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 12297U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 57U) + RotL64(aCross, 6U)) + (RotL64(aCarry, 29U) ^ RotL64(aPrevious, 43U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = ((aWandererA + RotL64(aIngress, 5U)) + 4848316479321533394U) + aNonceWordG;
            aOrbiterC = (((aWandererF + RotL64(aScatter, 60U)) + RotL64(aCarry, 53U)) + 6919360256662636195U) + aOrbiterAssignSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = ((aWandererG + RotL64(aCross, 27U)) + RotL64(aCarry, 37U)) + 9897013582181108544U;
            aOrbiterK = ((aWandererE + RotL64(aPrevious, 53U)) + 7319353809896158678U) + aOrbiterAssignSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = (aWandererB + RotL64(aCross, 47U)) + 2848175435514849859U;
            aOrbiterI = ((aWandererH + RotL64(aScatter, 19U)) + 6967780718720437934U) + aNonceWordI;
            aOrbiterE = ((aWandererI + RotL64(aPrevious, 41U)) + RotL64(aCarry, 21U)) + 10143884766603388136U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 8675965006150972051U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 16350117755560994281U;
            aOrbiterG = RotL64((aOrbiterG * 15072308930382994425U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 17976597517118423760U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 1399631141355370237U) ^ aNonceWordH;
            aOrbiterA = RotL64((aOrbiterA * 16537788276543236833U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 3590613762034716792U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 5134624314245932157U;
            aOrbiterK = RotL64((aOrbiterK * 13077589037975283371U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 10082236952942943654U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 4015535035905433450U;
            aOrbiterC = RotL64((aOrbiterC * 4961808568701908559U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 611474103801573800U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterI) ^ 5786708483794098001U) ^ aOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterB = RotL64((aOrbiterB * 7694007039340089267U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 5201943497363274455U) + aNonceWordE;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 9282160506938328489U) ^ aOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5368182164239021367U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 4932320527498940158U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 11576526341731392916U;
            aOrbiterE = RotL64((aOrbiterE * 1712051774729439363U), 11U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterB, 35U);
            aIngress = aIngress + (RotL64(aOrbiterK, 51U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 19U));
            aIngress = aIngress + RotL64(aOrbiterG, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aCross, 30U) + RotL64(aOrbiterE, 21U)) + aOrbiterG);
            aWandererH = aWandererH + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterC, 30U)) + aOrbiterB) + RotL64(aCarry, 19U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 5U) + aOrbiterG) + RotL64(aOrbiterI, 13U));
            aWandererE = aWandererE + ((((RotL64(aIngress, 43U) + RotL64(aOrbiterA, 57U)) + aOrbiterK) + RotL64(aCarry, 43U)) + aNonceWordL);
            aWandererB = aWandererB ^ (((RotL64(aCross, 11U) + aOrbiterC) + RotL64(aOrbiterK, 3U)) + aWandererUpdateSaltC[((aIndex + 17U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aIngress, 57U) + RotL64(aOrbiterC, 47U)) + aOrbiterA) + aWandererUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 51U) + RotL64(aOrbiterI, 41U)) + aOrbiterC) + aNonceWordP);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 57U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 30U));
            aCarry = aCarry + (RotL64(aWandererE, 19U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererB, 51U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = aCarry ^ (aNonceWordM ^ aNonceWordO);
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 20370U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 24314U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 19716U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 17979U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 27U) ^ RotL64(aCarry, 4U)) ^ (RotL64(aPrevious, 53U) + RotL64(aCross, 41U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = ((aWandererG + RotL64(aScatter, 57U)) + 3650233661228036955U) + aNonceWordJ;
            aOrbiterK = ((aWandererD + RotL64(aIngress, 13U)) + RotL64(aCarry, 35U)) + 11607036400067735729U;
            aOrbiterI = (((aWandererC + RotL64(aCross, 3U)) + RotL64(aCarry, 3U)) + 3899614406903883035U) + aOrbiterAssignSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = ((aWandererE + RotL64(aPrevious, 43U)) + 8159156925629965143U) + aNonceWordD;
            aOrbiterD = ((aWandererF + RotL64(aScatter, 19U)) + RotL64(aCarry, 53U)) + 7148903913967261270U;
            aOrbiterB = (aWandererK + RotL64(aIngress, 26U)) + 9161665622287517848U;
            aOrbiterE = (((aWandererH + RotL64(aPrevious, 37U)) + 2981535013474059469U) + aOrbiterAssignSaltB[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordE;
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 15812469008200319549U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 14687469489893270300U;
            aOrbiterI = RotL64((aOrbiterI * 14142363399696670451U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 6025209349511417063U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 12964750392311112676U;
            aOrbiterK = RotL64((aOrbiterK * 12955480283032701843U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 6572355895765394340U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 3542300121890027981U;
            aOrbiterA = RotL64((aOrbiterA * 11201491178181273935U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 6477175684045398359U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 1081388388827929314U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8752188637514143529U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 13754328481584620771U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 3684673342659575917U;
            aOrbiterD = RotL64((aOrbiterD * 6139923312873039143U), 35U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterE) + 6542045150319909445U) + aOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1]) + aNonceWordF;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 5352102692424060388U) ^ aOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 7385758355501860261U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 9110100774657340354U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 2813273684436269057U;
            aOrbiterE = RotL64((aOrbiterE * 10468759062594022273U), 13U);
            //
            aIngress = RotL64(aOrbiterI, 47U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterA, 18U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterK, 53U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterB, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aCross, 39U) + RotL64(aOrbiterI, 51U)) + aOrbiterA) + aWandererUpdateSaltF[((aIndex + 20U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 48U) + RotL64(aOrbiterK, 3U)) + aOrbiterE) + RotL64(aCarry, 39U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterE, 57U)) + aOrbiterB);
            aWandererF = aWandererF + (((RotL64(aScatter, 21U) + RotL64(aOrbiterE, 26U)) + aOrbiterD) + RotL64(aCarry, 53U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 13U) + RotL64(aOrbiterK, 37U)) + aOrbiterF) + aWandererUpdateSaltB[((aIndex + 11U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aIngress, 29U) + aOrbiterI) + RotL64(aOrbiterF, 43U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterF, 13U)) + aOrbiterA) + aNonceWordM);
            //
            aCarry = aCarry + (RotL64(aWandererC, 27U) ^ aWandererE);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 60U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 35U));
            aCarry = aCarry + RotL64(aWandererD, 51U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = aCarry ^ (aNonceWordF ^ aNonceWordP);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 30827U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneB[((aIndex + 24904U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 32467U)) & S_BLOCK1], 38U) ^ RotL64(aWorkLaneD[((aIndex + 30783U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 35U) + RotL64(aIngress, 11U)) ^ (RotL64(aPrevious, 23U) ^ RotL64(aCarry, 58U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = (((aWandererA + RotL64(aCross, 53U)) + 14249093584376402677U) + aOrbiterAssignSaltF[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordN;
            aOrbiterH = (((aWandererI + RotL64(aPrevious, 43U)) + RotL64(aCarry, 27U)) + 8756965951816492264U) + aNonceWordC;
            aOrbiterC = ((aWandererD + RotL64(aIngress, 27U)) + 11221139480258176330U) + aOrbiterAssignSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterJ = ((aWandererH + RotL64(aScatter, 21U)) + RotL64(aCarry, 57U)) + 17218894445564194851U;
            aOrbiterB = ((aWandererJ + RotL64(aCross, 34U)) + RotL64(aCarry, 13U)) + 8064642692524949490U;
            aOrbiterG = (aWandererC + RotL64(aIngress, 13U)) + 5822093203710704646U;
            aOrbiterE = ((aWandererF + RotL64(aScatter, 5U)) + 3217799620158102238U) + aNonceWordM;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 2613757677892120843U) + aOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 13647481499551657237U;
            aOrbiterC = RotL64((aOrbiterC * 5517563514031899891U), 41U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 3545714196663685016U) + aOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 9735422670576621521U;
            aOrbiterG = RotL64((aOrbiterG * 7276207208162697249U), 21U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 3911046580637583767U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 9315984027042049203U;
            aOrbiterH = RotL64((aOrbiterH * 12568550776487242469U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 8926367674641729058U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 11035347490524961446U) ^ aNonceWordD;
            aOrbiterB = RotL64((aOrbiterB * 10948288997163592463U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 10748158733051120339U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 2467801787989056455U;
            aOrbiterK = RotL64((aOrbiterK * 12621934274702358977U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 9244415080474351390U) + aOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 8517784887959492079U;
            aOrbiterJ = RotL64((aOrbiterJ * 17022899813765884147U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 8409307332803038455U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 11043806021873232950U) ^ aNonceWordI;
            aOrbiterE = RotL64((aOrbiterE * 8294888329708842989U), 13U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterG, 13U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 41U));
            aIngress = aIngress + (RotL64(aOrbiterE, 54U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterH, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aIngress, 3U) + aOrbiterH) + RotL64(aOrbiterC, 23U));
            aWandererD = aWandererD + ((RotL64(aPrevious, 57U) + RotL64(aOrbiterK, 11U)) + aOrbiterE);
            aWandererC = aWandererC ^ (((RotL64(aCross, 27U) + RotL64(aOrbiterG, 58U)) + aOrbiterE) + aNonceWordG);
            aWandererH = aWandererH + ((((RotL64(aScatter, 21U) + RotL64(aOrbiterJ, 39U)) + aOrbiterG) + RotL64(aCarry, 3U)) + aWandererUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aCross, 47U) + aOrbiterH) + RotL64(aOrbiterJ, 5U)) + aWandererUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 13U) + RotL64(aOrbiterC, 51U)) + aOrbiterB) + RotL64(aCarry, 43U)) + aNonceWordK);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 36U) + aOrbiterJ) + RotL64(aOrbiterC, 29U)) + aNonceWordB);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 19U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 3U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 44U));
            aCarry = aCarry + RotL64(aWandererD, 51U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ aNonceWordH;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xC69851CFEE611A25ULL + 0xB67314A491DE23F8ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xBE82C937C689BBA9ULL + 0xCB997E194B3F20A3ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xDC1B7FC2D75A2567ULL + 0x99AC35C486A355C6ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x99828D9FDDB2E92FULL + 0x8272C7739F033832ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xF64240A2B8404F13ULL + 0xD5CAC78308C7591EULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xAD395E2613527673ULL + 0xE0C0B608C0FBA51EULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xF3BE5A15C1AE3A21ULL + 0xC1C6694ADFB3D3C0ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xA4C955DD95B7EAEBULL + 0x9BB03BF9982FB921ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xDC65109008B24EF3ULL + 0x9D642556C1AA2F42ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xB28B97C5EFB6CCFBULL + 0xF0128DC940054845ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xF260BEF013EE43F9ULL + 0xC2447D06EE062D28ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xD0082157DE89D5AFULL + 0x9CA515F2012B5457ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xCFBE5684BF5AD84DULL + 0x86AE4BFBFD8C6D33ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xAF83290369D2E4BBULL + 0x8BBB62A6327C0A7EULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xB564F3B5E6E58501ULL + 0xD07B6CCFDB8363CAULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xA0B11EA2D4F80C99ULL + 0x8059B0BFBC3A65BBULL);
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 2153U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneC[((aIndex + 3450U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 7727U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneA[((aIndex + 2298U)) & S_BLOCK1], 52U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 21U) ^ RotL64(aCross, 5U)) ^ (RotL64(aPrevious, 47U) + RotL64(aCarry, 34U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = ((aWandererA + RotL64(aIngress, 56U)) + RotL64(aCarry, 51U)) + 4179952823252098240U;
            aOrbiterI = (aWandererE + RotL64(aCross, 37U)) + 3745613452332101749U;
            aOrbiterJ = ((aWandererJ + RotL64(aScatter, 39U)) + RotL64(aCarry, 23U)) + 2955689793395307176U;
            aOrbiterE = (aWandererK + RotL64(aPrevious, 53U)) + 5639060180251322019U;
            aOrbiterA = (aWandererI + RotL64(aScatter, 14U)) + 7901969163853586463U;
            aOrbiterK = (aWandererF + RotL64(aCross, 21U)) + 2242166787816318119U;
            aOrbiterH = ((aWandererD + RotL64(aPrevious, 41U)) + 5239936443960750064U) + aNonceWordO;
            aOrbiterD = ((aWandererG + RotL64(aIngress, 3U)) + 13939136954732185558U) + aOrbiterAssignSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = ((aWandererH + RotL64(aCross, 43U)) + RotL64(aCarry, 57U)) + 17058884136712717463U;
            aOrbiterF = (aWandererC + RotL64(aScatter, 29U)) + 18148618660054585941U;
            aOrbiterC = ((aWandererB + RotL64(aPrevious, 19U)) + 7022023484530327814U) + aOrbiterAssignSaltA[((aIndex + 28U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 7722084537340095637U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 11764151879690934182U;
            aOrbiterJ = RotL64((aOrbiterJ * 12264384877711365655U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 16412785901758144708U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 9666718667728274824U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 10865799822751771795U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 4307127540152109364U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 2457646804702647606U;
            aOrbiterB = RotL64((aOrbiterB * 6340030928007058595U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 3179394870088602208U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 504977947273774249U;
            aOrbiterE = RotL64((aOrbiterE * 16190282058883481551U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 16182729401018310837U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 7110817020445860609U;
            aOrbiterH = RotL64((aOrbiterH * 13371352088428584087U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 12960656706837391973U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 7103806893724395904U;
            aOrbiterG = RotL64((aOrbiterG * 14365984439655979791U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 1248300178080633527U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 7195473175424961337U;
            aOrbiterC = RotL64((aOrbiterC * 4633558992739305045U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 13007951568242991449U) + aOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 10296811247653636372U;
            aOrbiterI = RotL64((aOrbiterI * 16469682651380549395U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 13922797949001028335U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 16773545425463040155U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10639282630227832397U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 2888887140296117803U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 10279517418046269817U) ^ aNonceWordC;
            aOrbiterD = RotL64((aOrbiterD * 8600355360339461535U), 37U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 17303373436784809093U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 4179952823252098240U;
            aOrbiterF = RotL64((aOrbiterF * 3675754609699406437U), 21U);
            //
            aIngress = RotL64(aOrbiterI, 26U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterG, 51U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 29U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 19U));
            aIngress = aIngress + (RotL64(aOrbiterA, 39U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterD, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 54U) + RotL64(aOrbiterA, 51U)) + aOrbiterF);
            aWandererG = aWandererG + (((RotL64(aScatter, 27U) + RotL64(aOrbiterF, 27U)) + aOrbiterI) + RotL64(aCarry, 43U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 23U) + aOrbiterF) + RotL64(aOrbiterE, 48U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 21U) + aOrbiterK) + RotL64(aOrbiterA, 23U)) + aWandererUpdateSaltB[((aIndex + 25U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((((RotL64(aIngress, 13U) + RotL64(aOrbiterH, 35U)) + aOrbiterJ) + aNonceWordB) + aWandererUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aPrevious, 34U) + RotL64(aOrbiterI, 3U)) + aOrbiterD);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 37U) + aOrbiterA) + RotL64(aOrbiterG, 37U));
            aWandererH = aWandererH + ((RotL64(aCross, 51U) + RotL64(aOrbiterG, 41U)) + aOrbiterC);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 3U) + aOrbiterG) + RotL64(aOrbiterH, 39U));
            aWandererD = aWandererD + (((RotL64(aIngress, 39U) + RotL64(aOrbiterB, 54U)) + aOrbiterC) + RotL64(aCarry, 5U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterE, 11U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 56U));
            aCarry = aCarry + (RotL64(aWandererJ, 3U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererH, 35U) ^ aWandererA);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 39U));
            aCarry = aCarry + (RotL64(aWandererD, 41U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererK, 46U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ aNonceWordL;
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
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 13248U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 8782U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 12847U)) & S_BLOCK1], 54U) ^ RotL64(aExpandLaneB[((aIndex + 8462U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 39U) ^ RotL64(aCarry, 23U)) + (RotL64(aPrevious, 11U) ^ RotL64(aCross, 56U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = (((aWandererK + RotL64(aScatter, 37U)) + RotL64(aCarry, 21U)) + 13583136155674166402U) + aOrbiterAssignSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterH = (aWandererJ + RotL64(aCross, 23U)) + 12830472187484919497U;
            aOrbiterJ = (((aWandererI + RotL64(aIngress, 47U)) + RotL64(aCarry, 41U)) + 18081197909484522509U) + aNonceWordE;
            aOrbiterC = (aWandererC + RotL64(aPrevious, 58U)) + 8680634051297891550U;
            aOrbiterF = (aWandererB + RotL64(aIngress, 53U)) + 13939998767458656823U;
            aOrbiterB = (aWandererA + RotL64(aPrevious, 3U)) + 1795730579103692594U;
            aOrbiterG = ((aWandererE + RotL64(aScatter, 43U)) + 17369751719734069999U) + aOrbiterAssignSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterD = (aWandererG + RotL64(aCross, 60U)) + 224769585901248068U;
            aOrbiterA = (aWandererF + RotL64(aIngress, 21U)) + 4133547085925268180U;
            aOrbiterK = (aWandererD + RotL64(aScatter, 19U)) + 7022512056309567391U;
            aOrbiterE = ((aWandererH + RotL64(aCross, 29U)) + RotL64(aCarry, 53U)) + 10319484359046945495U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 10483878349412282069U) + aOrbiterUpdateSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 6481381149199985736U) ^ aNonceWordI;
            aOrbiterJ = RotL64((aOrbiterJ * 9701719367082506253U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 13721077228796934509U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 9704818014314175007U;
            aOrbiterH = RotL64((aOrbiterH * 760445624027740287U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 6253040047758584339U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 16890211690273641226U) ^ aOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 5622534399866057841U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 6216227831265032436U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 2023609047004658739U;
            aOrbiterG = RotL64((aOrbiterG * 3252332895698310147U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 9201669637050388263U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 5106927540934338576U;
            aOrbiterA = RotL64((aOrbiterA * 6368134569042291431U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 10080368957861445998U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterE) ^ 10784789383436485808U) ^ aOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterI = RotL64((aOrbiterI * 3794918350254445939U), 37U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 15426339824951793026U) + aNonceWordO;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 17637144549368340331U;
            aOrbiterC = RotL64((aOrbiterC * 10971293914614704441U), 21U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 9941300382181962134U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 8118046374121322097U;
            aOrbiterB = RotL64((aOrbiterB * 8481945819050983127U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 5138086185042567633U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 7279942739248982986U;
            aOrbiterD = RotL64((aOrbiterD * 12911998308338410917U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 12135610639038562853U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 12945353426409788798U;
            aOrbiterK = RotL64((aOrbiterK * 7434977715954413699U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 7534876598022096222U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 13583136155674166402U;
            aOrbiterE = RotL64((aOrbiterE * 8194058098043157015U), 35U);
            //
            aIngress = RotL64(aOrbiterF, 23U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 19U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 53U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 44U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 47U));
            aIngress = aIngress + RotL64(aOrbiterH, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aScatter, 54U) + RotL64(aOrbiterE, 46U)) + aOrbiterF) + aWandererUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterE, 57U)) + aOrbiterC);
            aWandererH = aWandererH + (((RotL64(aIngress, 29U) + aOrbiterK) + RotL64(aOrbiterF, 39U)) + RotL64(aCarry, 39U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 23U) + RotL64(aOrbiterJ, 23U)) + aOrbiterI) + aNonceWordF);
            aWandererI = aWandererI + ((RotL64(aScatter, 43U) + RotL64(aOrbiterB, 6U)) + aOrbiterK);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterI, 19U)) + aOrbiterA);
            aWandererC = aWandererC + ((((RotL64(aCross, 19U) + aOrbiterJ) + RotL64(aOrbiterG, 27U)) + RotL64(aCarry, 13U)) + aWandererUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 48U) + aOrbiterB) + RotL64(aOrbiterH, 21U));
            aWandererD = aWandererD + (((RotL64(aScatter, 35U) + aOrbiterI) + RotL64(aOrbiterD, 13U)) + aNonceWordL);
            aWandererF = aWandererF ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterE, 35U)) + aOrbiterB);
            aWandererA = aWandererA + ((RotL64(aIngress, 51U) + RotL64(aOrbiterI, 51U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 50U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 47U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 39U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 19U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 21U));
            aCarry = aCarry + RotL64(aWandererC, 11U);
            aCarry = aCarry + RotL64(aIngress, 44U);
            aCarry = aCarry ^ (aNonceWordG ^ aNonceWordI);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 20943U)) & S_BLOCK1], 46U) ^ RotL64(aOperationLaneA[((aIndex + 19969U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 22847U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneC[((aIndex + 23454U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 27U) + RotL64(aPrevious, 41U)) ^ (RotL64(aIngress, 54U) ^ RotL64(aCarry, 3U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = ((aWandererK + RotL64(aScatter, 46U)) + RotL64(aCarry, 27U)) + 11698283336767769359U;
            aOrbiterA = ((aWandererF + RotL64(aCross, 21U)) + RotL64(aCarry, 23U)) + 13297826354831483872U;
            aOrbiterK = (aWandererG + RotL64(aPrevious, 41U)) + 15254999058287530795U;
            aOrbiterE = ((aWandererI + RotL64(aIngress, 39U)) + 17474166585085346567U) + aNonceWordN;
            aOrbiterB = ((aWandererH + RotL64(aPrevious, 5U)) + 15684783498452840289U) + aNonceWordB;
            aOrbiterH = (aWandererD + RotL64(aCross, 29U)) + 5061229733465216486U;
            aOrbiterC = (aWandererC + RotL64(aIngress, 43U)) + 15370981279168377944U;
            aOrbiterF = ((aWandererA + RotL64(aScatter, 52U)) + 17966672773619554092U) + aNonceWordI;
            aOrbiterD = (((aWandererJ + RotL64(aIngress, 37U)) + RotL64(aCarry, 39U)) + 14685092893994491068U) + aOrbiterAssignSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = ((aWandererB + RotL64(aCross, 57U)) + 12798804186209406389U) + aOrbiterAssignSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterG = (aWandererE + RotL64(aPrevious, 11U)) + 2848444181474221574U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 8551142075919636146U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 8833198159158950723U;
            aOrbiterK = RotL64((aOrbiterK * 7650289040764974737U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 7351473160893666232U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 14204899612487622222U;
            aOrbiterH = RotL64((aOrbiterH * 6317485031956448029U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 7008985178526543258U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 13576796403863120356U;
            aOrbiterA = RotL64((aOrbiterA * 13745839827679114077U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 5769784656937900699U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 14075925808204936705U;
            aOrbiterB = RotL64((aOrbiterB * 5844894088757604713U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 17818667502858010896U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 16016922065572683130U) ^ aOrbiterUpdateSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7525645833898085373U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 1582458237855075977U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 10830440354527138227U) ^ aOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 10499386926982228251U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 10653964151654643772U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 11218475491129483859U;
            aOrbiterJ = RotL64((aOrbiterJ * 3338108067044357141U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 9863649760189649255U) + aNonceWordP;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 13790281439048354358U;
            aOrbiterE = RotL64((aOrbiterE * 4682098083538482849U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 14846954923718136337U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 522207783972623813U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14299798934454852811U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 426829715716262697U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 7482977730216354509U;
            aOrbiterD = RotL64((aOrbiterD * 6317437989422015173U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 10736099808538972990U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 11698283336767769359U;
            aOrbiterG = RotL64((aOrbiterG * 17230175904095995929U), 3U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterK, 13U);
            aIngress = aIngress + (RotL64(aOrbiterD, 57U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 35U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 50U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 43U));
            aIngress = aIngress + RotL64(aOrbiterI, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterC, 37U)) + aOrbiterF);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 56U) + RotL64(aOrbiterF, 11U)) + aOrbiterI);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 41U) + aOrbiterF) + RotL64(aOrbiterE, 43U));
            aWandererI = aWandererI + ((((RotL64(aScatter, 19U) + aOrbiterG) + RotL64(aOrbiterA, 48U)) + aNonceWordD) + aWandererUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((((RotL64(aCross, 21U) + aOrbiterK) + RotL64(aOrbiterB, 13U)) + aNonceWordE) + aWandererUpdateSaltC[((aIndex + 11U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aScatter, 35U) + aOrbiterC) + RotL64(aOrbiterH, 19U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 10U) + aOrbiterD) + RotL64(aOrbiterG, 5U)) + aNonceWordA);
            aWandererD = aWandererD + (((RotL64(aPrevious, 37U) + RotL64(aOrbiterA, 35U)) + aOrbiterJ) + RotL64(aCarry, 43U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterK, 54U)) + aOrbiterG);
            aWandererA = aWandererA + (((RotL64(aScatter, 47U) + RotL64(aOrbiterK, 27U)) + aOrbiterF) + RotL64(aCarry, 13U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 39U) + aOrbiterI) + RotL64(aOrbiterD, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 19U) ^ aWandererG);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 3U));
            aCarry = aCarry + (RotL64(aWandererE, 10U) ^ aWandererC);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 23U));
            aCarry = aCarry + (RotL64(aWandererD, 43U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererJ, 39U);
            aCarry = aCarry + RotL64(aIngress, 52U);
            aCarry = aCarry ^ aNonceWordA;
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 27826U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneB[((aIndex + 30720U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 28357U)) & S_BLOCK1], 60U) ^ RotL64(aExpandLaneD[((aIndex + 28741U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 3U) ^ RotL64(aIngress, 21U)) + (RotL64(aCarry, 47U) + RotL64(aPrevious, 34U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = ((aWandererI + RotL64(aCross, 35U)) + RotL64(aCarry, 47U)) + 3550722402315312207U;
            aOrbiterA = ((aWandererE + RotL64(aScatter, 19U)) + 16724184551669522754U) + aOrbiterAssignSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterI = (aWandererJ + RotL64(aPrevious, 30U)) + 981751330116773021U;
            aOrbiterC = (aWandererK + RotL64(aIngress, 5U)) + 7891159229704944868U;
            aOrbiterD = ((aWandererD + RotL64(aScatter, 43U)) + 13618396711464799841U) + aOrbiterAssignSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterK = ((aWandererA + RotL64(aIngress, 47U)) + RotL64(aCarry, 11U)) + 5969291018449003648U;
            aOrbiterB = ((aWandererC + RotL64(aCross, 56U)) + 14595540413313640042U) + aNonceWordN;
            aOrbiterF = ((aWandererG + RotL64(aPrevious, 27U)) + RotL64(aCarry, 27U)) + 3287990436916111762U;
            aOrbiterG = (aWandererF + RotL64(aScatter, 51U)) + 12534369400200483704U;
            aOrbiterJ = (aWandererB + RotL64(aCross, 13U)) + 2277312067930392274U;
            aOrbiterH = (aWandererH + RotL64(aIngress, 41U)) + 10026320559261334353U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 11258082063135659551U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 1445958517675746990U;
            aOrbiterI = RotL64((aOrbiterI * 10062265337488757971U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 1011298251290970844U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 6487834862470043744U;
            aOrbiterD = RotL64((aOrbiterD * 15477913837027179675U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 9966279022928268335U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 10285993486057704393U;
            aOrbiterK = RotL64((aOrbiterK * 15965714363201157535U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 16005362468813966136U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 223843444699390781U;
            aOrbiterB = RotL64((aOrbiterB * 665392038954573081U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 18178876294968532775U) + aNonceWordB;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 12490136112181806806U) ^ aOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 16380841616662993709U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 8775696166557913635U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 16464340319444310842U;
            aOrbiterG = RotL64((aOrbiterG * 18111632334728200721U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 6296039992673546227U) + aOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 7152939277656436037U;
            aOrbiterJ = RotL64((aOrbiterJ * 15183918431501487319U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 14066791413416223271U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 5026743227399908016U;
            aOrbiterH = RotL64((aOrbiterH * 5891343232759075675U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 12923870516588764609U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 2509970166609982397U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 10708677957633925007U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 15155802288437422950U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 15615656627428205711U;
            aOrbiterA = RotL64((aOrbiterA * 6199439196177598589U), 39U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 17233751123865498186U) + aOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 3550722402315312207U;
            aOrbiterC = RotL64((aOrbiterC * 2247546626523919155U), 51U);
            //
            aIngress = RotL64(aOrbiterF, 37U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 3U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 58U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 51U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 21U));
            aIngress = aIngress + RotL64(aOrbiterB, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 24U) + aOrbiterJ) + RotL64(aOrbiterD, 13U));
            aWandererA = aWandererA + (((RotL64(aScatter, 43U) + aOrbiterJ) + RotL64(aOrbiterH, 3U)) + RotL64(aCarry, 21U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 47U) + aOrbiterG) + RotL64(aOrbiterF, 46U));
            aWandererB = aWandererB + (((RotL64(aIngress, 57U) + RotL64(aOrbiterB, 23U)) + aOrbiterE) + RotL64(aCarry, 5U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterH, 29U)) + aOrbiterB);
            aWandererG = aWandererG + (((RotL64(aCross, 5U) + RotL64(aOrbiterF, 41U)) + aOrbiterA) + aWandererUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterH, 51U)) + aOrbiterF);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 3U) + aOrbiterK) + RotL64(aOrbiterA, 58U)) + aNonceWordE);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 11U) + RotL64(aOrbiterI, 39U)) + aOrbiterJ) + aWandererUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aPrevious, 30U) + RotL64(aOrbiterD, 37U)) + aOrbiterA);
            aWandererE = aWandererE ^ ((RotL64(aCross, 13U) + aOrbiterF) + RotL64(aOrbiterC, 11U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 5U) ^ aWandererK);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 47U));
            aCarry = aCarry + (RotL64(aWandererD, 39U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererA, 44U) ^ aWandererG);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 19U));
            aCarry = aCarry + RotL64(aWandererI, 27U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = aCarry ^ aNonceWordA;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xE293130B466905F5ULL + 0xBE14418B622391B1ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xA5A8D07EBFF80007ULL + 0xDD709A03E42F7B94ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x8C5E5621F8620EBDULL + 0x8880773B5C0E42D2ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xECF736AE0FE4F52DULL + 0xA2AC635C7B8DDFD6ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xA3F9C8CC2CE839C3ULL + 0xCDAE34C622E66028ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xB83ACAD2BA41ABBBULL + 0xAC1E29203256B4EAULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xD1D7F134E5C5629BULL + 0x80F813D84A364AE7ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xAFE0D33F93B8649BULL + 0xA727FA77A88183DAULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xB8A588F9EFCC9519ULL + 0x9F79738E924E46E5ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xF7220F1832989E6BULL + 0xE7D31AC6234A6367ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xF79933C0C98D75E7ULL + 0x9F36E6CF54A2E30EULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xFCCB1A1B96001965ULL + 0xE3625616A8755649ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0x8F3E9AAD95AD92A5ULL + 0xF2D0B497B8420CCEULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xF182FCB2DC4C1221ULL + 0xD3ED8BC041DD77F2ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x9CA4048CACC221D5ULL + 0xDF0FE9C1007F3619ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xA51DB2A3C5B1CB8BULL + 0x97B7A89F53BE4164ULL);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 4610U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneC[((aIndex + 4420U)) & S_BLOCK1], 10U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 1562U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneA[((aIndex + 431U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 41U) ^ RotL64(aIngress, 57U)) + (RotL64(aCarry, 27U) + RotL64(aPrevious, 10U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = ((aWandererH + RotL64(aIngress, 56U)) + 8793908991006073956U) + aOrbiterAssignSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = (aWandererE + RotL64(aScatter, 23U)) + 2932916283348441943U;
            aOrbiterC = (aWandererI + RotL64(aCross, 27U)) + 11069042087940968262U;
            aOrbiterK = ((aWandererG + RotL64(aPrevious, 5U)) + RotL64(aCarry, 3U)) + 14369628676782894441U;
            aOrbiterE = ((aWandererF + RotL64(aScatter, 51U)) + RotL64(aCarry, 57U)) + 8602903272780978282U;
            aOrbiterD = (((aWandererJ + RotL64(aCross, 43U)) + RotL64(aCarry, 11U)) + 3827036107178568820U) + aNonceWordE;
            aOrbiterH = (aWandererC + RotL64(aIngress, 60U)) + 8905245209036772489U;
            aOrbiterF = (((aWandererD + RotL64(aPrevious, 13U)) + 13331387530760017893U) + aOrbiterAssignSaltF[((aIndex + 7U)) & S_SALT1]) + aNonceWordI;
            aOrbiterG = (aWandererA + RotL64(aCross, 37U)) + 9880107580289737823U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 10199619040626900278U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 2466307560891374281U) ^ aNonceWordB;
            aOrbiterC = RotL64((aOrbiterC * 6295342978834217571U), 41U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterE) + 13973403407981259448U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordA;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 2851460278409385243U;
            aOrbiterD = RotL64((aOrbiterD * 11226902976321781743U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 10365453393815690776U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 2382382358987358791U;
            aOrbiterF = RotL64((aOrbiterF * 481563628980705781U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 5058198848163792422U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 10500434740387593487U;
            aOrbiterG = RotL64((aOrbiterG * 5946747708776079787U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 11289798395177667084U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 14327152153231286666U;
            aOrbiterA = RotL64((aOrbiterA * 18155778059595245561U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 8065137263811956313U) + aOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 3865153574847924816U;
            aOrbiterK = RotL64((aOrbiterK * 9495741102667755161U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 18102279969722473375U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 6306428427188742325U) ^ aNonceWordH;
            aOrbiterH = RotL64((aOrbiterH * 17826782872351406167U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 16953348204663693724U) + aOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 11950791817032898613U;
            aOrbiterJ = RotL64((aOrbiterJ * 1498946055469611133U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 11980823193543752994U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 17845490308799454871U;
            aOrbiterE = RotL64((aOrbiterE * 16385153013485463791U), 11U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterA, 3U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 51U));
            aIngress = aIngress + (RotL64(aOrbiterK, 35U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterD, 46U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterF, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aScatter, 56U) + aOrbiterH) + RotL64(aOrbiterK, 19U)) + aNonceWordJ);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 47U) + RotL64(aOrbiterG, 5U)) + aOrbiterK);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 43U) + aOrbiterD) + RotL64(aOrbiterA, 10U));
            aWandererC = aWandererC + (((RotL64(aCross, 27U) + RotL64(aOrbiterH, 39U)) + aOrbiterF) + aNonceWordK);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 52U) + aOrbiterJ) + RotL64(aOrbiterA, 47U)) + aNonceWordC);
            aWandererD = aWandererD + (((RotL64(aCross, 35U) + RotL64(aOrbiterH, 43U)) + aOrbiterA) + RotL64(aCarry, 47U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 11U) + RotL64(aOrbiterG, 34U)) + aOrbiterA) + aWandererUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aScatter, 23U) + aOrbiterE) + RotL64(aOrbiterA, 23U)) + RotL64(aCarry, 11U)) + aWandererUpdateSaltC[((aIndex + 28U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterE, 57U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererA, 57U) ^ aWandererD);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 26U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 5U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 47U));
            aCarry = aCarry + RotL64(aWandererJ, 23U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = aCarry ^ (aNonceWordO ^ aNonceWordD);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 7458U)) & S_BLOCK1], 10U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 8541U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 9611U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 6057U)) & S_BLOCK1], 28U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 36U) + RotL64(aCarry, 23U)) ^ (RotL64(aCross, 5U) ^ RotL64(aIngress, 57U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = ((aWandererD + RotL64(aScatter, 23U)) + 15910560457440369082U) + aNonceWordL;
            aOrbiterD = (aWandererF + RotL64(aCross, 46U)) + 17953072986407436888U;
            aOrbiterB = ((aWandererG + RotL64(aPrevious, 41U)) + 15446940721193538669U) + aNonceWordA;
            aOrbiterF = ((aWandererJ + RotL64(aIngress, 35U)) + 3020785262774422009U) + aOrbiterAssignSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterC = ((aWandererB + RotL64(aScatter, 51U)) + RotL64(aCarry, 23U)) + 7001288645424994404U;
            aOrbiterJ = ((aWandererE + RotL64(aCross, 19U)) + 13385250665458462689U) + aOrbiterAssignSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = ((aWandererA + RotL64(aPrevious, 4U)) + RotL64(aCarry, 57U)) + 4841895644623005949U;
            aOrbiterG = (((aWandererC + RotL64(aIngress, 29U)) + RotL64(aCarry, 39U)) + 13053476783239482065U) + aNonceWordG;
            aOrbiterA = (aWandererH + RotL64(aPrevious, 57U)) + 641996979335975244U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 16211238020928688299U) + aNonceWordK;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 12715448751323279480U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2116880429675303291U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 17784406727699995290U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 16626339815786580778U;
            aOrbiterC = RotL64((aOrbiterC * 13940754474750138041U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 9035070625716345139U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 6085848172494001945U;
            aOrbiterI = RotL64((aOrbiterI * 10405728912339646693U), 43U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 1177103851507561053U) + aNonceWordC;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 2281901691017816407U;
            aOrbiterG = RotL64((aOrbiterG * 3142197009403602497U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 9040984343694325070U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 13334258224023902365U) ^ aOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 4782523727707164869U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 1079824790138592518U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 14024082692012948652U;
            aOrbiterK = RotL64((aOrbiterK * 3219489374333737903U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 2966776524421278970U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 5510281854029308547U;
            aOrbiterF = RotL64((aOrbiterF * 9275402927591867297U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 7126632329316720048U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 1476827035602733472U;
            aOrbiterJ = RotL64((aOrbiterJ * 2217671289726794033U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 6470212302133184965U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 4172257438373147415U) ^ aOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 4449314239630366533U), 3U);
            //
            aIngress = RotL64(aOrbiterD, 6U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 3U));
            aIngress = aIngress + (RotL64(aOrbiterI, 29U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterK, 47U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterJ, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterF, 35U)) + aOrbiterG);
            aWandererG = aWandererG + (((RotL64(aPrevious, 35U) + aOrbiterA) + RotL64(aOrbiterJ, 13U)) + RotL64(aCarry, 5U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 47U) + aOrbiterD) + RotL64(aOrbiterA, 24U)) + aNonceWordN);
            aWandererC = aWandererC + ((RotL64(aCross, 60U) + RotL64(aOrbiterG, 57U)) + aOrbiterK);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterF, 5U)) + aOrbiterA);
            aWandererA = aWandererA + (((RotL64(aPrevious, 39U) + RotL64(aOrbiterK, 51U)) + aOrbiterC) + aNonceWordI);
            aWandererF = aWandererF ^ ((((RotL64(aCross, 43U) + aOrbiterA) + RotL64(aOrbiterI, 47U)) + aNonceWordJ) + aWandererUpdateSaltF[((aIndex + 10U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aIngress, 5U) + RotL64(aOrbiterK, 28U)) + aOrbiterD) + RotL64(aCarry, 37U)) + aWandererUpdateSaltB[((aIndex + 13U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 52U) + aOrbiterG) + RotL64(aOrbiterB, 19U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 57U));
            aCarry = aCarry + (RotL64(aWandererD, 26U) ^ aWandererA);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 23U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 47U));
            aCarry = aCarry + RotL64(aWandererJ, 5U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ aNonceWordK;
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 12651U)) & S_BLOCK1], 4U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 14494U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 13987U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneC[((aIndex + 14320U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 51U) + RotL64(aCross, 23U)) ^ (RotL64(aCarry, 11U) + RotL64(aIngress, 38U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = ((aWandererC + RotL64(aCross, 35U)) + RotL64(aCarry, 13U)) + 10812151398716051703U;
            aOrbiterH = (((aWandererH + RotL64(aScatter, 47U)) + RotL64(aCarry, 41U)) + 18202551453336003710U) + aOrbiterAssignSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = (aWandererA + RotL64(aPrevious, 51U)) + 9434410809101973752U;
            aOrbiterK = (aWandererD + RotL64(aIngress, 10U)) + 12955829998028534045U;
            aOrbiterB = (aWandererF + RotL64(aPrevious, 19U)) + 12271740641929640181U;
            aOrbiterF = (aWandererJ + RotL64(aScatter, 3U)) + 14009351527014534752U;
            aOrbiterJ = ((aWandererB + RotL64(aCross, 39U)) + 4316296955679133450U) + aNonceWordD;
            aOrbiterD = ((aWandererG + RotL64(aIngress, 43U)) + RotL64(aCarry, 53U)) + 16473324966997442872U;
            aOrbiterE = ((aWandererI + RotL64(aCross, 28U)) + 15735123324965019802U) + aOrbiterAssignSaltE[((aIndex + 19U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 17656375090484080236U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 16066325053456055298U;
            aOrbiterI = RotL64((aOrbiterI * 17912970706985130327U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 12908968778503516903U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 12761433987676836197U) ^ aOrbiterUpdateSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 1023329467480907925U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 12737513138040664509U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 14535795767570998392U) ^ aNonceWordG;
            aOrbiterK = RotL64((aOrbiterK * 15560519667062222269U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 14370908061811284364U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 7001358781208669795U;
            aOrbiterH = RotL64((aOrbiterH * 11641248025734015835U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 7298578161120090849U) + aNonceWordM;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 10498302152357484629U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 13144110412179037175U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 11447343228638006767U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 18284143620422655675U;
            aOrbiterF = RotL64((aOrbiterF * 572862190073605651U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 5918253208127360199U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 3910541329178205943U;
            aOrbiterJ = RotL64((aOrbiterJ * 4550654545328228103U), 39U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 10357053096941367910U) + aNonceWordE;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 5610891501128498748U;
            aOrbiterD = RotL64((aOrbiterD * 8676370811772047449U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 9049881176058575811U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 6307599924966452216U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5551444450572055895U), 51U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterJ, 47U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 5U));
            aIngress = aIngress + (RotL64(aOrbiterK, 53U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 30U));
            aIngress = aIngress + RotL64(aOrbiterA, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aCross, 3U) + RotL64(aOrbiterK, 18U)) + aOrbiterI) + aWandererUpdateSaltA[((aIndex + 16U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 29U) + aOrbiterD) + RotL64(aOrbiterF, 35U)) + aNonceWordL);
            aWandererC = aWandererC + (((RotL64(aIngress, 21U) + RotL64(aOrbiterD, 51U)) + aOrbiterE) + RotL64(aCarry, 37U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 10U) + aOrbiterE) + RotL64(aOrbiterI, 47U));
            aWandererF = aWandererF + (((RotL64(aIngress, 53U) + aOrbiterA) + RotL64(aOrbiterI, 11U)) + aWandererUpdateSaltD[((aIndex + 23U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 47U) + RotL64(aOrbiterB, 23U)) + aOrbiterF) + aNonceWordC);
            aWandererI = aWandererI + ((RotL64(aScatter, 57U) + RotL64(aOrbiterD, 43U)) + aOrbiterK);
            aWandererD = aWandererD ^ ((RotL64(aCross, 35U) + aOrbiterI) + RotL64(aOrbiterH, 27U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 40U) + aOrbiterJ) + RotL64(aOrbiterB, 58U)) + RotL64(aCarry, 13U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 34U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererC, 27U) ^ aWandererA);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 53U));
            aCarry = aCarry + (RotL64(aWandererD, 21U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererF, 5U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ aNonceWordL;
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 20740U)) & S_BLOCK1], 54U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 18167U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17537U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 19331U)) & S_BLOCK1], 24U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 23U) + RotL64(aPrevious, 37U)) ^ (RotL64(aIngress, 50U) ^ RotL64(aCross, 5U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = ((aWandererA + RotL64(aPrevious, 48U)) + 18319689184146942855U) + aNonceWordE;
            aOrbiterC = (((aWandererD + RotL64(aCross, 43U)) + RotL64(aCarry, 51U)) + 8041304130090501019U) + aNonceWordJ;
            aOrbiterK = (aWandererB + RotL64(aIngress, 29U)) + 11347064191990897738U;
            aOrbiterE = (((aWandererG + RotL64(aScatter, 23U)) + 15242243470024447468U) + aOrbiterAssignSaltB[((aIndex + 18U)) & S_SALT1]) + aNonceWordF;
            aOrbiterJ = (aWandererF + RotL64(aCross, 11U)) + 10619749107163611105U;
            aOrbiterF = (aWandererH + RotL64(aScatter, 53U)) + 14795614276221947128U;
            aOrbiterB = ((aWandererJ + RotL64(aPrevious, 4U)) + RotL64(aCarry, 23U)) + 1578095288886372393U;
            aOrbiterA = ((aWandererC + RotL64(aIngress, 39U)) + RotL64(aCarry, 5U)) + 13593906305770501684U;
            aOrbiterH = ((aWandererE + RotL64(aPrevious, 57U)) + 8919815528334599172U) + aOrbiterAssignSaltF[((aIndex + 6U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 17425548324720065145U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 11125018338392347335U) ^ aOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4377887040461528587U), 39U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 3779189180734244399U) + aOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 10958224663276134041U;
            aOrbiterJ = RotL64((aOrbiterJ * 6206963519509783781U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 4317305352561612995U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 4891139433808505355U;
            aOrbiterB = RotL64((aOrbiterB * 11507024985663120317U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 5166074784835930965U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 10080890270621589202U;
            aOrbiterD = RotL64((aOrbiterD * 13170894418184288695U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 4501071771615514619U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 6486573807774431753U;
            aOrbiterE = RotL64((aOrbiterE * 324029625116648669U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 15714881857668975753U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 3506619392820235900U) ^ aNonceWordH;
            aOrbiterF = RotL64((aOrbiterF * 5707033870161224499U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 5295711072762443783U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 11192836530396570648U;
            aOrbiterA = RotL64((aOrbiterA * 4361810118382207039U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 7993389678399774574U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 12551394763541226695U;
            aOrbiterH = RotL64((aOrbiterH * 11903486656172026403U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 11553674370322129668U) + aOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 4459881583199320245U;
            aOrbiterC = RotL64((aOrbiterC * 2805857426321555685U), 3U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterD, 6U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 11U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 19U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 35U));
            aIngress = aIngress + RotL64(aOrbiterE, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aIngress, 60U) + RotL64(aOrbiterB, 28U)) + aOrbiterD);
            aWandererH = aWandererH + ((RotL64(aPrevious, 43U) + aOrbiterF) + RotL64(aOrbiterK, 47U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 51U) + aOrbiterF) + RotL64(aOrbiterA, 35U)) + aWandererUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aCross, 5U) + RotL64(aOrbiterA, 53U)) + aOrbiterK);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 23U) + aOrbiterA) + RotL64(aOrbiterH, 19U)) + aWandererUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aScatter, 29U) + aOrbiterK) + RotL64(aOrbiterE, 39U)) + RotL64(aCarry, 51U)) + aNonceWordM);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterJ, 11U)) + aOrbiterK);
            aWandererA = aWandererA + (((RotL64(aCross, 38U) + RotL64(aOrbiterC, 43U)) + aOrbiterE) + RotL64(aCarry, 23U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterB, 58U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererC, 21U) ^ aWandererB);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 39U));
            aCarry = aCarry + (RotL64(aWandererD, 50U) ^ aWandererG);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 3U));
            aCarry = aCarry + RotL64(aWandererJ, 47U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ aNonceWordO;
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 21847U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneA[((aIndex + 22889U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27266U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22822U)) & S_BLOCK1], 44U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 51U) ^ RotL64(aCarry, 39U)) + (RotL64(aPrevious, 3U) ^ RotL64(aCross, 18U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (aWandererC + RotL64(aPrevious, 5U)) + 16200278595895089008U;
            aOrbiterK = ((aWandererF + RotL64(aIngress, 52U)) + RotL64(aCarry, 21U)) + 1029614154810465897U;
            aOrbiterH = (aWandererH + RotL64(aScatter, 19U)) + 7129562468705441295U;
            aOrbiterI = ((aWandererD + RotL64(aCross, 35U)) + RotL64(aCarry, 5U)) + 14388903902433951274U;
            aOrbiterE = (aWandererJ + RotL64(aPrevious, 23U)) + 1013568949315967455U;
            aOrbiterD = (aWandererI + RotL64(aCross, 43U)) + 3128823373497815651U;
            aOrbiterG = (((aWandererE + RotL64(aScatter, 14U)) + RotL64(aCarry, 47U)) + 14525694606889470589U) + aOrbiterAssignSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterC = ((aWandererB + RotL64(aIngress, 29U)) + 14443983602196782887U) + aNonceWordO;
            aOrbiterF = ((aWandererG + RotL64(aCross, 47U)) + 12244220415328641190U) + aOrbiterAssignSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 10477159225338766614U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 2842870123078131566U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 11522265477555954071U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 8621138818955849917U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 5038396344400303181U;
            aOrbiterD = RotL64((aOrbiterD * 14636756322207385447U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 2768613802894372496U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 2027754864051410015U) ^ aNonceWordN;
            aOrbiterC = RotL64((aOrbiterC * 2461322540050569287U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 2848088309172056399U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 15017458513904884651U;
            aOrbiterF = RotL64((aOrbiterF * 9926904679902843055U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 9079797279596336139U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 15424866642305110811U;
            aOrbiterJ = RotL64((aOrbiterJ * 12912331089970158845U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 13751764050290602740U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 7694557131324740282U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 14980807690491467023U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 3508673897305667669U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 3600868397311393233U;
            aOrbiterG = RotL64((aOrbiterG * 5165032044164139165U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 1222655844979128996U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 2257342337168905875U;
            aOrbiterK = RotL64((aOrbiterK * 6198995971182272119U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 6290990717563682725U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 15308494772443447109U) ^ aOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 1925593111157842325U), 43U);
            //
            aIngress = RotL64(aOrbiterJ, 41U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 21U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 37U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 26U));
            aIngress = aIngress + RotL64(aOrbiterD, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aScatter, 29U) + aOrbiterE) + RotL64(aOrbiterF, 14U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 24U) + aOrbiterJ) + RotL64(aOrbiterK, 21U)) + aWandererUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aIngress, 37U) + aOrbiterK) + RotL64(aOrbiterC, 3U)) + aNonceWordA);
            aWandererI = aWandererI ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterG, 57U)) + aOrbiterC) + aWandererUpdateSaltB[((aIndex + 17U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 43U) + aOrbiterI) + RotL64(aOrbiterE, 39U)) + RotL64(aCarry, 5U)) + aNonceWordD);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 47U) + aOrbiterK) + RotL64(aOrbiterD, 35U)) + aNonceWordB);
            aWandererB = aWandererB + ((RotL64(aCross, 6U) + RotL64(aOrbiterH, 53U)) + aOrbiterD);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterF, 43U)) + aOrbiterC);
            aWandererH = aWandererH + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterJ, 26U)) + aOrbiterD) + RotL64(aCarry, 41U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 20U));
            aCarry = aCarry + (RotL64(aWandererH, 57U) ^ aWandererG);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 43U));
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererJ, 37U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ (aNonceWordO ^ aNonceWordI);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 29507U)) & S_BLOCK1], 50U) ^ RotL64(aExpandLaneB[((aIndex + 28540U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29031U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneB[((aIndex + 30427U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 19U) ^ RotL64(aCarry, 53U)) + (RotL64(aCross, 4U) + RotL64(aPrevious, 37U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = (aWandererK + RotL64(aScatter, 43U)) + 16160838483846078448U;
            aOrbiterI = (((aWandererD + RotL64(aCross, 35U)) + 15404960896190227946U) + aOrbiterAssignSaltE[((aIndex + 3U)) & S_SALT1]) + aNonceWordC;
            aOrbiterJ = (((aWandererI + RotL64(aPrevious, 12U)) + 16904160594024977199U) + aOrbiterAssignSaltA[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordP;
            aOrbiterG = ((aWandererH + RotL64(aIngress, 47U)) + RotL64(aCarry, 39U)) + 17790460246821031802U;
            aOrbiterB = (aWandererG + RotL64(aCross, 51U)) + 16395168254086971959U;
            aOrbiterH = (aWandererA + RotL64(aScatter, 19U)) + 7484373204039901786U;
            aOrbiterK = (aWandererJ + RotL64(aIngress, 6U)) + 18026814691322913510U;
            aOrbiterE = ((aWandererE + RotL64(aPrevious, 23U)) + RotL64(aCarry, 11U)) + 15244817793136966450U;
            aOrbiterD = ((aWandererB + RotL64(aCross, 29U)) + RotL64(aCarry, 27U)) + 5795491730356335666U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 3163873518027801504U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 2690791759507349172U;
            aOrbiterJ = RotL64((aOrbiterJ * 16677948635136515083U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 17898067251167087906U) + aNonceWordI;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 8028010015006604239U) ^ aNonceWordE;
            aOrbiterB = RotL64((aOrbiterB * 5601629670521300241U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 7304739457289910555U) + aNonceWordB;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 6476837815096530043U) ^ aOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 16380545138701113267U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 14242499233467960602U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 17305645693017634630U;
            aOrbiterE = RotL64((aOrbiterE * 14442976693206929569U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 9772864059444171908U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 7897200728282156408U) ^ aOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 816306719390807411U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 4890999319172950996U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 8165132649356094963U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 17297706071263690189U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 9342923520083533265U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 7213639583505088067U;
            aOrbiterG = RotL64((aOrbiterG * 1349251979649428909U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 4079475132684197272U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 3350998022472827283U;
            aOrbiterH = RotL64((aOrbiterH * 948841791460066265U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 2479140576609216238U) + aOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 7703147534931674972U;
            aOrbiterI = RotL64((aOrbiterI * 11419116495223970801U), 37U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterK, 21U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 53U));
            aIngress = aIngress + (RotL64(aOrbiterH, 57U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 37U));
            aIngress = aIngress + RotL64(aOrbiterI, 24U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aScatter, 51U) + RotL64(aOrbiterE, 24U)) + aOrbiterI);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterF, 41U)) + aOrbiterJ);
            aWandererE = aWandererE + (((RotL64(aCross, 60U) + RotL64(aOrbiterK, 53U)) + aOrbiterD) + aWandererUpdateSaltA[((aIndex + 7U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 39U) + RotL64(aOrbiterG, 57U)) + aOrbiterE) + aNonceWordO);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 3U) + aOrbiterD) + RotL64(aOrbiterH, 11U)) + RotL64(aCarry, 3U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 11U) + aOrbiterJ) + RotL64(aOrbiterI, 19U));
            aWandererK = aWandererK + ((RotL64(aPrevious, 47U) + RotL64(aOrbiterG, 47U)) + aOrbiterH);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 23U) + aOrbiterF) + RotL64(aOrbiterI, 29U)) + aWandererUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aPrevious, 56U) + RotL64(aOrbiterH, 36U)) + aOrbiterB) + RotL64(aCarry, 35U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 30U) ^ aWandererG);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 13U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 39U));
            aCarry = aCarry + (RotL64(aWandererH, 53U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererE, 23U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ aNonceWordN;
            aCarry = TwistMix64::DiffuseA(aCarry);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x84988980BE515A77ULL + 0xFA6F4563454C50ECULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xECAEC4B989BE7093ULL + 0xEE5B528A132F3B20ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xAA7AA89AC9C28C37ULL + 0x8801AD77F3DAFCC7ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x96D55A158314EDE3ULL + 0xB4237A6B8576FEBFULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xBC73E8ABF97E2B0BULL + 0xBF84816E99487BE2ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xACFD044FC5C17627ULL + 0xCB2A70E987A2A4D8ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xA5CE3885842A2889ULL + 0xEAB768708FD547FEULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xBCA64464996D9F01ULL + 0xC7A9D2D02A1928E5ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xA45BAB8C47770CD1ULL + 0xC993DB2BE04F0675ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xAF55AB0C980C6211ULL + 0xA6BC5BC6A8F5DBECULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xCDDD9A8B5A857283ULL + 0x8F6A0EAF186EC5EFULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xB875E32E592FF11DULL + 0xE39673AEC7C1E772ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xAD14C4040D11F90BULL + 0xAA6F4A7CA2D7B74BULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xE1F9AC38798B582DULL + 0x9C920A636E3C62EEULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xC9761D61BAB61C0FULL + 0xC9CF6BEED2473135ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xEFCB43968593E601ULL + 0xE694893F8A4FB3EBULL);
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 4777U)) & S_BLOCK1], 37U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 747U)) & W_KEY1], 58U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 3109U)) & W_KEY1], 37U) ^ RotL64(mSource[((aIndex + 114U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCarry, 41U) ^ RotL64(aIngress, 5U)) + (RotL64(aCross, 53U) + RotL64(aPrevious, 22U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterD = ((aWandererH + RotL64(aCross, 3U)) + 4980738603982643969U) + aNonceWordO;
            aOrbiterF = ((aWandererG + RotL64(aIngress, 51U)) + 17660278413018470020U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = ((aWandererB + RotL64(aPrevious, 41U)) + 17598114429859543466U) + aNonceWordN;
            aOrbiterI = ((((aWandererI + RotL64(aScatter, 21U)) + RotL64(aCarry, 21U)) + 10993929335279994739U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordG;
            aOrbiterA = ((aWandererA + RotL64(aPrevious, 27U)) + RotL64(aCarry, 53U)) + 17967203122976322481U;
            aOrbiterE = ((aWandererF + RotL64(aIngress, 60U)) + RotL64(aCarry, 3U)) + 1872290205549034384U;
            aOrbiterB = (aWandererC + RotL64(aScatter, 13U)) + 16607778671782810797U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 4895226930754394376U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 14960359005982301383U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8546231310054433721U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 9921642352377700630U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 893281964367208693U;
            aOrbiterA = RotL64((aOrbiterA * 2345509157333444217U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 8232519988397858732U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 4433022122758913407U) ^ aNonceWordI;
            aOrbiterE = RotL64((aOrbiterE * 834240393225479419U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 12689609831247168353U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 404535388957472176U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 14534020545479806593U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 3349108201964013155U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 4386449511297371730U;
            aOrbiterD = RotL64((aOrbiterD * 9596273264321140229U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 14314587717949070586U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = (((aOrbiterI ^ aOrbiterE) ^ 10923886625271054985U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 4U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterI = RotL64((aOrbiterI * 7838969002623486809U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 17634909585329833520U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 2021301459918350372U) ^ aNonceWordF;
            aOrbiterF = RotL64((aOrbiterF * 1388242915918642741U), 23U);
            //
            aIngress = RotL64(aOrbiterC, 27U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterI, 3U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterE, 11U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterF, 60U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterE, 35U)) + aOrbiterD);
            aWandererG = aWandererG + ((((RotL64(aScatter, 3U) + RotL64(aOrbiterF, 11U)) + aOrbiterB) + RotL64(aCarry, 41U)) + aNonceWordE);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterE, 60U)) + aOrbiterC);
            aWandererB = aWandererB + ((((RotL64(aCross, 57U) + RotL64(aOrbiterB, 41U)) + aOrbiterC) + RotL64(aCarry, 11U)) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 21U) + aOrbiterA) + RotL64(aOrbiterB, 53U));
            aWandererI = aWandererI + (((RotL64(aScatter, 12U) + RotL64(aOrbiterD, 19U)) + aOrbiterC) + aNonceWordB);
            aWandererH = aWandererH ^ (((RotL64(aCross, 37U) + RotL64(aOrbiterB, 27U)) + aOrbiterI) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 47U));
            aCarry = aCarry + (RotL64(aWandererF, 29U) ^ aWandererA);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 4U));
            aCarry = aCarry + RotL64(aWandererI, 13U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ (aNonceWordG ^ aNonceWordL);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 9523U)) & S_BLOCK1], 21U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 8320U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 10438U)) & W_KEY1], 6U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 7195U)) & W_KEY1], 39U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 3U) + RotL64(aCross, 51U)) + (RotL64(aIngress, 39U) ^ RotL64(aCarry, 24U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterG = (((aWandererK + RotL64(aScatter, 29U)) + RotL64(aCarry, 51U)) + 6163290588946759209U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = ((aWandererC + RotL64(aCross, 3U)) + RotL64(aCarry, 21U)) + 7342672468560105447U;
            aOrbiterE = (aWandererG + RotL64(aIngress, 21U)) + 11574563167017282321U;
            aOrbiterJ = (((aWandererJ + RotL64(aPrevious, 57U)) + RotL64(aCarry, 39U)) + 2254820206194758964U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterD = (aWandererB + RotL64(aIngress, 39U)) + 1469783447473099498U;
            aOrbiterA = ((aWandererE + RotL64(aScatter, 46U)) + 14174828900676165088U) + aNonceWordG;
            aOrbiterC = ((aWandererF + RotL64(aPrevious, 11U)) + 16277954291890598132U) + aNonceWordO;
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 14845750668693136766U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 150099699692047766U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7644895634421086357U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 1200784917165131703U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 9469982764806754302U;
            aOrbiterG = RotL64((aOrbiterG * 17851969334511301943U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 10956702761701710182U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 7915506894975487807U;
            aOrbiterJ = RotL64((aOrbiterJ * 8874108311712727983U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 17335794183733623213U) + aNonceWordE;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 557028996286989506U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 3993359298602424281U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 1597385667771002414U) + aNonceWordB;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 4376417959915162639U;
            aOrbiterD = RotL64((aOrbiterD * 4626236858205178149U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 549770198518993876U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 756554555648070919U) ^ aNonceWordF;
            aOrbiterA = RotL64((aOrbiterA * 16272320259614325355U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 7298557532533152193U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 3336802611342112013U;
            aOrbiterC = RotL64((aOrbiterC * 14679103452120080499U), 51U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterJ, 58U);
            aIngress = aIngress + (RotL64(aOrbiterE, 51U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 3U));
            aIngress = aIngress + RotL64(aOrbiterB, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterB, 43U)) + aOrbiterJ);
            aWandererC = aWandererC + ((RotL64(aPrevious, 35U) + aOrbiterA) + RotL64(aOrbiterB, 60U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 23U) + aOrbiterC) + RotL64(aOrbiterD, 27U));
            aWandererB = aWandererB + (((RotL64(aCross, 47U) + aOrbiterG) + RotL64(aOrbiterB, 35U)) + RotL64(aCarry, 5U));
            aWandererF = aWandererF ^ ((((RotL64(aScatter, 57U) + RotL64(aOrbiterA, 19U)) + aOrbiterD) + aNonceWordM) + aPhaseAWandererUpdateSaltD[((aIndex + 4U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aIngress, 6U) + RotL64(aOrbiterA, 13U)) + aOrbiterC) + RotL64(aCarry, 27U)) + aPhaseAWandererUpdateSaltF[((aIndex + 23U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterJ, 3U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 27U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 58U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 35U));
            aCarry = aCarry + RotL64(aWandererG, 3U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ aNonceWordM;
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 11654U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 13560U)) & S_BLOCK1], 44U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 11669U)) & W_KEY1], 39U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 14736U)) & W_KEY1], 54U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCross, 29U) + RotL64(aIngress, 41U)) + (RotL64(aPrevious, 10U) ^ RotL64(aCarry, 57U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterC = (((aWandererJ + RotL64(aIngress, 51U)) + RotL64(aCarry, 23U)) + 6069475454765660321U) + aNonceWordO;
            aOrbiterJ = (((aWandererI + RotL64(aScatter, 4U)) + 11483704742497268068U) + aPhaseAOrbiterAssignSaltF[((aIndex + 28U)) & S_SALT1]) + aNonceWordD;
            aOrbiterG = ((aWandererK + RotL64(aPrevious, 23U)) + RotL64(aCarry, 53U)) + 11055697447388986418U;
            aOrbiterB = ((aWandererB + RotL64(aCross, 43U)) + 10897095046039997004U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterF = (aWandererE + RotL64(aPrevious, 29U)) + 4731637118230457840U;
            aOrbiterI = (aWandererD + RotL64(aScatter, 35U)) + 13855839187084986751U;
            aOrbiterD = (((aWandererH + RotL64(aCross, 57U)) + RotL64(aCarry, 35U)) + 5328208115460188239U) + aNonceWordB;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 12479538544291412985U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 10740165998792608231U;
            aOrbiterG = RotL64((aOrbiterG * 14046827922294477379U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 6492798157284955373U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 13056825957483891921U;
            aOrbiterJ = RotL64((aOrbiterJ * 14882112110627751751U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 2068184064919194657U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 5656302738780746294U;
            aOrbiterC = RotL64((aOrbiterC * 16493021179127646345U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 11193756120230763294U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterI) ^ 17306750816837208999U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterB = RotL64((aOrbiterB * 7949360041241439741U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 12952818800389361804U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 15380412293642628312U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2914662289178925547U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 7706090204767242996U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 14598802276412649570U;
            aOrbiterI = RotL64((aOrbiterI * 4821408736292041399U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 17819762117328075515U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 6481384240915075101U;
            aOrbiterD = RotL64((aOrbiterD * 4836701121865783029U), 3U);
            //
            aIngress = RotL64(aOrbiterD, 51U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterC, 5U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 35U));
            aIngress = aIngress + RotL64(aOrbiterG, 26U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aScatter, 11U) + aOrbiterI) + RotL64(aOrbiterD, 5U)) + RotL64(aCarry, 5U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterG, 29U)) + aOrbiterI);
            aWandererD = aWandererD + (((RotL64(aIngress, 19U) + aOrbiterG) + RotL64(aOrbiterJ, 53U)) + aNonceWordI);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterC, 37U)) + aOrbiterB);
            aWandererK = aWandererK + ((((RotL64(aCross, 57U) + aOrbiterD) + RotL64(aOrbiterG, 14U)) + RotL64(aCarry, 19U)) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 47U) + aOrbiterG) + RotL64(aOrbiterB, 47U)) + aNonceWordF);
            aWandererE = aWandererE + ((((RotL64(aIngress, 4U) + aOrbiterC) + RotL64(aOrbiterF, 23U)) + aNonceWordP) + aPhaseAWandererUpdateSaltC[((aIndex + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererD, 10U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererB, 53U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererJ, 41U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = aCarry ^ aNonceWordB;
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 19103U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 20079U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 20345U)) & S_BLOCK1], 51U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 16730U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 57U) ^ RotL64(aCross, 43U)) ^ (RotL64(aCarry, 12U) + RotL64(aIngress, 29U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterK = (aWandererA + RotL64(aIngress, 19U)) + 7948891781097675369U;
            aOrbiterF = (((aWandererF + RotL64(aCross, 13U)) + 13928362874228230226U) + aPhaseAOrbiterAssignSaltD[((aIndex + 26U)) & S_SALT1]) + aNonceWordK;
            aOrbiterG = ((aWandererE + RotL64(aPrevious, 30U)) + RotL64(aCarry, 13U)) + 10776180542602258926U;
            aOrbiterD = (((aWandererH + RotL64(aScatter, 57U)) + RotL64(aCarry, 51U)) + 5735115172149470447U) + aPhaseAOrbiterAssignSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = (aWandererJ + RotL64(aCross, 3U)) + 5353591822981766987U;
            aOrbiterB = (aWandererD + RotL64(aPrevious, 39U)) + 562301708107268570U;
            aOrbiterE = (((aWandererG + RotL64(aIngress, 47U)) + RotL64(aCarry, 35U)) + 10467810247578364868U) + aNonceWordN;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 14541630141152308564U) + aNonceWordP;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 2350076897065139429U;
            aOrbiterG = RotL64((aOrbiterG * 12222554362482034393U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 17519109078651162228U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 6061035173339902910U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10021905773432907835U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 15654836633731000065U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 13723521735153718904U;
            aOrbiterF = RotL64((aOrbiterF * 14459516479283070563U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 2849680038315532197U) + aNonceWordC;
            aOrbiterA = (((aOrbiterA ^ aOrbiterG) ^ 17336102435576647923U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterA = RotL64((aOrbiterA * 10984689101753586739U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 7671010488872356142U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 11485114338165600777U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4162584865462407791U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 8759060657343458985U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 11009137869375286581U;
            aOrbiterD = RotL64((aOrbiterD * 8741417343929809115U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 15792999392743144135U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 6180808423175992479U;
            aOrbiterE = RotL64((aOrbiterE * 13681230339693676907U), 35U);
            //
            aIngress = RotL64(aOrbiterF, 21U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 13U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 47U));
            aIngress = aIngress + RotL64(aOrbiterE, 4U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aIngress, 11U) + RotL64(aOrbiterB, 23U)) + aOrbiterD) + RotL64(aCarry, 51U)) + aNonceWordA);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterB, 57U)) + aOrbiterA);
            aWandererD = aWandererD + ((((RotL64(aCross, 23U) + aOrbiterE) + RotL64(aOrbiterB, 29U)) + RotL64(aCarry, 13U)) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterF, 37U)) + aOrbiterG);
            aWandererF = aWandererF + (((RotL64(aCross, 60U) + aOrbiterG) + RotL64(aOrbiterK, 43U)) + aPhaseAWandererUpdateSaltA[((aIndex + 28U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 3U) + aOrbiterE) + RotL64(aOrbiterK, 12U));
            aWandererH = aWandererH + ((RotL64(aIngress, 35U) + aOrbiterF) + RotL64(aOrbiterK, 5U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 47U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 53U));
            aCarry = aCarry + (RotL64(aWandererA, 43U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererH, 24U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ aNonceWordA;
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 25960U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneA[((aIndex + 24856U)) & S_BLOCK1], 42U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 24997U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneA[((aIndex + 24388U)) & S_BLOCK1], 50U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCarry, 37U) + RotL64(aIngress, 57U)) ^ (RotL64(aPrevious, 6U) ^ RotL64(aCross, 23U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterE = ((aWandererH + RotL64(aCross, 3U)) + 5568146815535263910U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = ((aWandererC + RotL64(aScatter, 50U)) + 7736084960873834666U) + aNonceWordP;
            aOrbiterJ = (((aWandererJ + RotL64(aIngress, 43U)) + 1336413621817562093U) + aPhaseAOrbiterAssignSaltE[((aIndex + 6U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterB = ((aWandererD + RotL64(aPrevious, 35U)) + RotL64(aCarry, 23U)) + 5218462026934984692U;
            aOrbiterC = ((aWandererA + RotL64(aScatter, 21U)) + RotL64(aCarry, 11U)) + 7048890985969555935U;
            aOrbiterF = ((aWandererB + RotL64(aCross, 29U)) + RotL64(aCarry, 53U)) + 13415955213864702118U;
            aOrbiterG = ((aWandererF + RotL64(aPrevious, 11U)) + 5657023257021528548U) + aNonceWordF;
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 14338310943137497116U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 12305161641833950473U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 11949964304435964395U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 14514226578370459131U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 12692904083266024340U) ^ aNonceWordG;
            aOrbiterE = RotL64((aOrbiterE * 14800805065279908839U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 11012959130001327964U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 7106471380403489078U) ^ aNonceWordB;
            aOrbiterB = RotL64((aOrbiterB * 515626559384817223U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 3718101961355280891U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 13364192077222322664U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 1411328915372590283U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 6720867800318913440U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 14497243926965866546U;
            aOrbiterC = RotL64((aOrbiterC * 13595058589060114653U), 53U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 5789056168233262435U) + aNonceWordD;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 14438482587495779937U;
            aOrbiterF = RotL64((aOrbiterF * 10593535547917767263U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 313917798940179945U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 15241845511889502917U;
            aOrbiterG = RotL64((aOrbiterG * 16483477103771326107U), 21U);
            //
            aIngress = RotL64(aOrbiterF, 19U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterE, 5U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 41U));
            aIngress = aIngress + RotL64(aOrbiterG, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aCross, 11U) + aOrbiterG) + RotL64(aOrbiterI, 27U)) + aPhaseAWandererUpdateSaltF[((aIndex + 8U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 41U) + RotL64(aOrbiterI, 37U)) + aOrbiterF) + RotL64(aCarry, 23U)) + aPhaseAWandererUpdateSaltD[((aIndex + 16U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterI, 19U)) + aOrbiterC) + aNonceWordK);
            aWandererA = aWandererA + ((RotL64(aScatter, 35U) + aOrbiterB) + RotL64(aOrbiterE, 12U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 56U) + RotL64(aOrbiterC, 57U)) + aOrbiterF) + aNonceWordE);
            aWandererF = aWandererF + (((RotL64(aScatter, 19U) + aOrbiterG) + RotL64(aOrbiterJ, 43U)) + RotL64(aCarry, 47U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterC, 3U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 60U));
            aCarry = aCarry + (RotL64(aWandererC, 35U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererA, 41U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererD, 11U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ aNonceWordN;
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 32714U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneB[((aIndex + 28226U)) & S_BLOCK1], 30U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30351U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneB[((aIndex + 30964U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 51U) ^ RotL64(aCross, 4U)) + (RotL64(aIngress, 39U) ^ RotL64(aCarry, 23U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterA = ((aWandererD + RotL64(aCross, 53U)) + 13296600294247799698U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterF = (aWandererF + RotL64(aScatter, 43U)) + 5818503518080877515U;
            aOrbiterC = ((aWandererA + RotL64(aPrevious, 3U)) + 6735784238734173597U) + aNonceWordK;
            aOrbiterE = (aWandererB + RotL64(aIngress, 21U)) + 7368398209488856201U;
            aOrbiterJ = ((((aWandererH + RotL64(aPrevious, 13U)) + RotL64(aCarry, 41U)) + 961734029066455638U) + aPhaseAOrbiterAssignSaltF[((aIndex + 21U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterK = (((aWandererG + RotL64(aIngress, 60U)) + RotL64(aCarry, 53U)) + 797011946660892011U) + aNonceWordB;
            aOrbiterH = ((aWandererI + RotL64(aCross, 27U)) + RotL64(aCarry, 23U)) + 12841876018396622350U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 16213253970483895623U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 15186950557113470375U;
            aOrbiterC = RotL64((aOrbiterC * 4647470430467908107U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 5117930310827477341U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 12265429373166094162U;
            aOrbiterJ = RotL64((aOrbiterJ * 1522823535151532249U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 13920531346698601568U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 14695405206998211456U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13950964363414164279U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 7851960904825938443U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 9501511171732550190U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5614164120361489613U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 5663365182245722077U) + aNonceWordL;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 9607860124321315555U) ^ aNonceWordM;
            aOrbiterA = RotL64((aOrbiterA * 3461820361914280601U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 18171052650586819280U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 3442698321538580861U;
            aOrbiterE = RotL64((aOrbiterE * 6317525514963824829U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 1491052813469258970U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 3956599824067616133U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2928600779267623085U), 41U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterH, 13U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 29U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 4U));
            aIngress = aIngress + RotL64(aOrbiterJ, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterE, 41U)) + aOrbiterK);
            aWandererH = aWandererH + (((RotL64(aScatter, 19U) + aOrbiterE) + RotL64(aOrbiterH, 29U)) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 3U) + aOrbiterJ) + RotL64(aOrbiterA, 21U));
            aWandererF = aWandererF + (((RotL64(aIngress, 13U) + aOrbiterC) + RotL64(aOrbiterE, 11U)) + RotL64(aCarry, 37U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 51U) + RotL64(aOrbiterK, 56U)) + aOrbiterC) + aPhaseAWandererUpdateSaltC[((aIndex + 22U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aCross, 60U) + RotL64(aOrbiterJ, 3U)) + aOrbiterF) + RotL64(aCarry, 19U)) + aNonceWordG);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 27U) + aOrbiterJ) + RotL64(aOrbiterH, 47U)) + aNonceWordO);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 23U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 37U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 14U));
            aCarry = aCarry + RotL64(aWandererI, 57U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = aCarry ^ (aNonceWordA ^ aNonceWordP);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x9B4E102D332CCBBBULL + 0xC78EF0731DF2C9C9ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xDC8F18F57381B06BULL + 0xBB34906BF0D9CEE8ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xEC0C2C267B822FDBULL + 0xB5BB217440058A1CULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xA066767DE23E0D71ULL + 0x98E573D8EEEA7D00ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xD481725B22AE74F7ULL + 0xC8AD7473C22682B4ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xDB1838D749052CB7ULL + 0xE0E845C7D1693DEBULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xB9B524317E93BF9BULL + 0xCC0027A1AC4940F0ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xE415EC563F235531ULL + 0xAECB065A191F2744ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xD77AF6A64440A03DULL + 0xAB3DB40C9A7C3D44ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xC3214E2B8D1FDB41ULL + 0x9A30EFB6B9341452ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xD24E2E96F339A7A1ULL + 0xD4F271916A4043D7ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xEAE1CE8D7B908557ULL + 0x95A0FE39FEB1E6E1ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xBA03385E1F2BEFF9ULL + 0x860DECB93466FEE2ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x855437C1879434B3ULL + 0xF0FF38A91863A8B1ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xFD537E084C80595DULL + 0xACF1DDA4FF4ACA3BULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xE736F76EFD93D5C9ULL + 0xD050C2C0E55F4F4CULL);
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 1662U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 2817U)) & S_BLOCK1], 60U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 951U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneA[((aIndex + 4284U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCross, 4U) ^ RotL64(aIngress, 47U)) ^ (RotL64(aPrevious, 35U) + RotL64(aCarry, 21U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterH = ((((aWandererJ + RotL64(aIngress, 23U)) + RotL64(aCarry, 51U)) + 6469584119078165548U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordD;
            aOrbiterK = ((aWandererI + RotL64(aPrevious, 3U)) + RotL64(aCarry, 37U)) + 14329756366517987910U;
            aOrbiterE = ((aWandererF + RotL64(aScatter, 56U)) + RotL64(aCarry, 3U)) + 12890831797059772123U;
            aOrbiterJ = (aWandererG + RotL64(aCross, 43U)) + 3164503807500018990U;
            aOrbiterD = ((aWandererC + RotL64(aIngress, 35U)) + 177531431387646836U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 3167421392893561015U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 2813174781844753460U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 9760688894575305115U), 35U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterD) + 10953270419153249857U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1]) + aNonceWordN;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 16911518309710356951U;
            aOrbiterH = RotL64((aOrbiterH * 13162785997686570445U), 53U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 6616750447844893150U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 10276741398025985982U;
            aOrbiterJ = RotL64((aOrbiterJ * 6824712685896987133U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 6206043608461213208U) + aNonceWordJ;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 12021552904553405793U;
            aOrbiterK = RotL64((aOrbiterK * 10023362889960174909U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 15283586234744144846U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterE) ^ 5923238786775948571U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterD = RotL64((aOrbiterD * 8200882393521882651U), 3U);
            //
            aIngress = RotL64(aOrbiterK, 3U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterH, 57U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterJ, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aScatter, 37U) + aOrbiterE) + RotL64(aOrbiterD, 37U)) + RotL64(aCarry, 51U)) + aNonceWordA);
            aWandererI = aWandererI ^ ((((RotL64(aIngress, 21U) + RotL64(aOrbiterK, 53U)) + aOrbiterD) + aNonceWordL) + aPhaseBWandererUpdateSaltB[((aIndex + 29U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 29U) + RotL64(aOrbiterH, 28U)) + aOrbiterE);
            aWandererF = aWandererF ^ ((RotL64(aCross, 11U) + aOrbiterH) + RotL64(aOrbiterD, 11U));
            aWandererC = aWandererC + ((((RotL64(aPrevious, 50U) + aOrbiterJ) + RotL64(aOrbiterK, 19U)) + RotL64(aCarry, 35U)) + aPhaseBWandererUpdateSaltD[((aIndex + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 58U));
            aCarry = aCarry + (RotL64(aWandererF, 11U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererC, 29U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ aNonceWordE;
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 5553U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneD[((aIndex + 10813U)) & S_BLOCK1], 24U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 6916U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 9576U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 13U) + RotL64(aCross, 60U)) + (RotL64(aPrevious, 41U) ^ RotL64(aCarry, 29U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterH = ((aWandererC + RotL64(aScatter, 39U)) + RotL64(aCarry, 41U)) + 12632404972795375757U;
            aOrbiterA = (((aWandererB + RotL64(aCross, 13U)) + 5351879979055988456U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordE;
            aOrbiterG = (aWandererK + RotL64(aIngress, 21U)) + 3597737727467443413U;
            aOrbiterK = ((aWandererE + RotL64(aPrevious, 30U)) + RotL64(aCarry, 23U)) + 2830846754917852318U;
            aOrbiterI = ((((aWandererI + RotL64(aIngress, 57U)) + RotL64(aCarry, 53U)) + 17311925960294518018U) + aPhaseBOrbiterAssignSaltB[((aIndex + 11U)) & S_SALT1]) + aNonceWordL;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 2083584640523695383U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 15049343611387010158U;
            aOrbiterG = RotL64((aOrbiterG * 5567816356477420399U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 6443050378205811147U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 6021965178697344070U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 6054064448935006741U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 5080289878758029976U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 576927745306972983U) ^ aNonceWordP;
            aOrbiterH = RotL64((aOrbiterH * 16008958833683246115U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 4728489691382690859U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 6184355840165758855U;
            aOrbiterA = RotL64((aOrbiterA * 1515043910404156423U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 11220539885798595450U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 11091438724966718214U) ^ aNonceWordN;
            aOrbiterK = RotL64((aOrbiterK * 8225347114759391961U), 21U);
            //
            aIngress = RotL64(aOrbiterG, 37U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 13U));
            aIngress = aIngress + RotL64(aOrbiterH, 60U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aScatter, 3U) + RotL64(aOrbiterK, 21U)) + aOrbiterG) + RotL64(aCarry, 11U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 12U) + RotL64(aOrbiterA, 29U)) + aOrbiterK) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aIngress, 21U) + RotL64(aOrbiterH, 39U)) + aOrbiterK);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 53U) + aOrbiterI) + RotL64(aOrbiterH, 10U)) + aNonceWordI);
            aWandererB = aWandererB + ((((RotL64(aIngress, 35U) + RotL64(aOrbiterA, 51U)) + aOrbiterH) + RotL64(aCarry, 39U)) + aPhaseBWandererUpdateSaltC[((aIndex + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 37U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 14U));
            aCarry = aCarry + RotL64(aWandererE, 47U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ aNonceWordF;
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 15719U)) & S_BLOCK1], 36U) ^ RotL64(aWorkLaneA[((aIndex + 15480U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 14890U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneC[((aIndex + 13708U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aIngress, 22U)) + (RotL64(aPrevious, 51U) ^ RotL64(aCross, 35U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterH = (aWandererH + RotL64(aPrevious, 10U)) + 12980104182836602177U;
            aOrbiterK = (((aWandererE + RotL64(aScatter, 37U)) + RotL64(aCarry, 35U)) + 3172622203188863995U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = ((aWandererD + RotL64(aIngress, 57U)) + 1170974132219980203U) + aPhaseBOrbiterAssignSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = ((aWandererC + RotL64(aCross, 47U)) + RotL64(aCarry, 5U)) + 6035201940965047490U;
            aOrbiterC = (((aWandererG + RotL64(aPrevious, 19U)) + RotL64(aCarry, 21U)) + 18033907118424996722U) + aNonceWordF;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 14604813424800580304U) + aNonceWordN;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 13720232492851066035U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8927246214721284759U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 3902659710585257448U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 8331560652661619868U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 11418103770615560205U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 4485014147538689794U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 168202636924512424U;
            aOrbiterH = RotL64((aOrbiterH * 13711020666131492091U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 16227825670092707848U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 4792781933944671365U;
            aOrbiterE = RotL64((aOrbiterE * 15859849676231455283U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 12636865372722601282U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 18198291399585556632U;
            aOrbiterC = RotL64((aOrbiterC * 18155803890313399795U), 47U);
            //
            aIngress = RotL64(aOrbiterK, 3U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterH, 29U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterJ, 52U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterJ, 23U)) + aOrbiterC);
            aWandererC = aWandererC + ((((RotL64(aIngress, 19U) + aOrbiterJ) + RotL64(aOrbiterE, 11U)) + RotL64(aCarry, 19U)) + aPhaseBWandererUpdateSaltE[((aIndex + 4U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterK, 57U)) + aOrbiterJ) + aNonceWordB);
            aWandererE = aWandererE + (((((RotL64(aCross, 42U) + RotL64(aOrbiterK, 46U)) + aOrbiterH) + RotL64(aCarry, 5U)) + aNonceWordI) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 27U) + RotL64(aOrbiterH, 37U)) + aOrbiterJ) + aNonceWordP);
            //
            aCarry = aCarry + (RotL64(aWandererD, 11U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererH, 35U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererE, 19U);
            aCarry = aCarry + RotL64(aIngress, 56U);
            aCarry = aCarry ^ (aNonceWordA ^ aNonceWordE);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 16743U)) & S_BLOCK1], 4U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 18275U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17323U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 20575U)) & S_BLOCK1], 34U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 40U) ^ RotL64(aIngress, 53U)) ^ (RotL64(aPrevious, 11U) + RotL64(aCross, 27U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterJ = (((aWandererK + RotL64(aScatter, 19U)) + RotL64(aCarry, 29U)) + 16651241552253078315U) + aPhaseBOrbiterAssignSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = (((aWandererC + RotL64(aPrevious, 56U)) + RotL64(aCarry, 57U)) + 4558144676982478003U) + aPhaseBOrbiterAssignSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = ((aWandererI + RotL64(aIngress, 3U)) + 8814884320080367550U) + aNonceWordK;
            aOrbiterG = (((aWandererJ + RotL64(aCross, 11U)) + RotL64(aCarry, 13U)) + 16011579668555672117U) + aNonceWordB;
            aOrbiterH = (aWandererH + RotL64(aIngress, 37U)) + 4738918668759862438U;
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterC) + 12526083125540985108U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordE;
            aOrbiterB = (((aOrbiterB ^ aOrbiterJ) ^ 8048723561746000552U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterB = RotL64((aOrbiterB * 11914807994597963481U), 53U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 1082218464034639039U) + aNonceWordN;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 8432043246965946816U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 7801965585991025451U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 9982080524048636852U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 6720069955755215919U;
            aOrbiterG = RotL64((aOrbiterG * 1025046364205332059U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 1019035028070247757U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 7360619079463870467U;
            aOrbiterC = RotL64((aOrbiterC * 6623074813047915863U), 5U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 10893918488381348474U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 1390297670907738019U;
            aOrbiterH = RotL64((aOrbiterH * 11909657437658597735U), 13U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterC, 29U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 5U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterH, 18U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aIngress, 48U) + aOrbiterG) + RotL64(aOrbiterJ, 19U)) + RotL64(aCarry, 29U)) + aPhaseBWandererUpdateSaltB[((aIndex + 11U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((((RotL64(aPrevious, 3U) + aOrbiterC) + RotL64(aOrbiterB, 29U)) + aNonceWordL) + aPhaseBWandererUpdateSaltD[((aIndex + 13U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aScatter, 27U) + RotL64(aOrbiterJ, 57U)) + aOrbiterC) + RotL64(aCarry, 43U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterG, 5U)) + aOrbiterH);
            aWandererK = aWandererK + ((RotL64(aScatter, 39U) + aOrbiterJ) + RotL64(aOrbiterH, 44U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 27U));
            aCarry = aCarry + (RotL64(aWandererI, 13U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererJ, 3U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ aNonceWordL;
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 24385U)) & S_BLOCK1], 38U) ^ RotL64(aOperationLaneA[((aIndex + 23883U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 25418U)) & S_BLOCK1], 24U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24077U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 23U) ^ RotL64(aCross, 37U)) ^ (RotL64(aIngress, 3U) + RotL64(aCarry, 50U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterF = (((aWandererA + RotL64(aCross, 19U)) + 8604208734152026945U) + aPhaseBOrbiterAssignSaltB[((aIndex + 9U)) & S_SALT1]) + aNonceWordO;
            aOrbiterJ = ((aWandererB + RotL64(aPrevious, 35U)) + 1374329953253889829U) + aNonceWordJ;
            aOrbiterB = ((aWandererG + RotL64(aScatter, 57U)) + RotL64(aCarry, 5U)) + 5779278910548228339U;
            aOrbiterI = (((aWandererC + RotL64(aIngress, 27U)) + RotL64(aCarry, 21U)) + 17670451230882805140U) + aPhaseBOrbiterAssignSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterH = ((aWandererE + RotL64(aCross, 48U)) + RotL64(aCarry, 43U)) + 8193848740764866860U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 15801168428145650104U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 2584718176087499066U;
            aOrbiterB = RotL64((aOrbiterB * 5687189872016780831U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 14950366247822737997U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterJ) ^ 9779293225265670135U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterH = RotL64((aOrbiterH * 11625969538497982117U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 8688968319288372383U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 13665723186950342601U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 292035540396910837U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 9395428688359973510U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 2152719218018108418U) ^ aNonceWordM;
            aOrbiterJ = RotL64((aOrbiterJ * 15271961483518392671U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 1350324137411377992U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 8729317951386057921U) ^ aNonceWordG;
            aOrbiterI = RotL64((aOrbiterI * 6008790836417785083U), 35U);
            //
            aIngress = RotL64(aOrbiterB, 3U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 13U));
            aIngress = aIngress + RotL64(aOrbiterI, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aIngress, 39U) + RotL64(aOrbiterI, 57U)) + aOrbiterB) + RotL64(aCarry, 53U)) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aCross, 19U) + aOrbiterH) + RotL64(aOrbiterF, 3U)) + aNonceWordN);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 47U) + aOrbiterH) + RotL64(aOrbiterJ, 13U)) + RotL64(aCarry, 35U)) + aNonceWordI);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 60U) + aOrbiterJ) + RotL64(aOrbiterI, 46U)) + aNonceWordC);
            aWandererC = aWandererC + (((RotL64(aIngress, 29U) + RotL64(aOrbiterH, 27U)) + aOrbiterB) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 52U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererA, 39U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererB, 3U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = aCarry ^ (aNonceWordB ^ aNonceWordA);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 27936U)) & S_BLOCK1], 4U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 32296U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 28821U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneB[((aIndex + 28970U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 54U) + RotL64(aPrevious, 3U)) ^ (RotL64(aCross, 39U) ^ RotL64(aIngress, 23U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterF = ((((aWandererA + RotL64(aIngress, 19U)) + RotL64(aCarry, 41U)) + 7896237440058555694U) + aPhaseBOrbiterAssignSaltF[((aIndex + 25U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterI = ((aWandererK + RotL64(aCross, 27U)) + 11870529476037558635U) + aNonceWordC;
            aOrbiterK = ((aWandererF + RotL64(aScatter, 39U)) + RotL64(aCarry, 53U)) + 9158983227801569448U;
            aOrbiterJ = (((aWandererJ + RotL64(aPrevious, 4U)) + RotL64(aCarry, 19U)) + 4710172270996950329U) + aNonceWordO;
            aOrbiterH = ((aWandererH + RotL64(aCross, 47U)) + 14634482800356647630U) + aPhaseBOrbiterAssignSaltA[((aIndex + 10U)) & S_SALT1];
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 8822207952170610891U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 13755891414028982553U;
            aOrbiterK = RotL64((aOrbiterK * 5173750624716006485U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 4555293067488040719U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 2816805148093762081U;
            aOrbiterI = RotL64((aOrbiterI * 16838149138341713943U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 2122631477965135190U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 4592922416380416071U) ^ aNonceWordA;
            aOrbiterF = RotL64((aOrbiterF * 11644507904538573165U), 23U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 7102471666524164715U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterK) ^ 17274623547879474204U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterJ = RotL64((aOrbiterJ * 5443572270546181789U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 938587316977094680U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 18258015823797023523U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 6068819567674605919U), 13U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterK, 43U);
            aIngress = aIngress + (RotL64(aOrbiterF, 6U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterH, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterJ, 24U)) + aOrbiterI) + aNonceWordE);
            aWandererA = aWandererA + ((((RotL64(aScatter, 21U) + RotL64(aOrbiterH, 51U)) + aOrbiterF) + RotL64(aCarry, 35U)) + aNonceWordG);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 57U) + aOrbiterJ) + RotL64(aOrbiterK, 11U)) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererF = aWandererF + (((((RotL64(aIngress, 46U) + aOrbiterK) + RotL64(aOrbiterF, 3U)) + RotL64(aCarry, 51U)) + aNonceWordM) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 37U) + aOrbiterJ) + RotL64(aOrbiterH, 35U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 29U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + RotL64(aWandererH, 19U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ aNonceWordL;
            aCarry = TwistMix64::DiffuseB(aCarry);
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
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0;

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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xF8978FE5DC6CB16DULL + 0xF24BB2D71CACCEF1ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x96D1B583595CB05FULL + 0xB577993A5598DD29ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xFC7524A1C44193E3ULL + 0x94561209115F8F1BULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xBE7550A29736D34BULL + 0xEE4C812288D14BC7ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xB2F44C54CF022427ULL + 0xCCB7C548190FBA83ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xD3EC98C5DEEF0AC5ULL + 0xE513827A9AD8DE01ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xE7FC0403D6EE7D85ULL + 0xC8E2A71909F2230DULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xD495E70C278E4EF1ULL + 0x84845014C2F68A89ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x9D73A25808DE1855ULL + 0x995C047351FDFF01ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xDAA865E43480995DULL + 0x9923B31195A367D0ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xD4289DD4BC80915FULL + 0xFF813FBEED0FC339ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xD57BD7E32CD5F2EBULL + 0xD0ECCF6B58D246D3ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xB382935AD65BE279ULL + 0xA5C9AF1E84B09287ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xB87F7FE6626487F9ULL + 0xDFC2E22A402C9D85ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x8F290E6FE583AB69ULL + 0xACC118D2C509C58DULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xF002BE7303F8A391ULL + 0x8DDBB568C67A2B77ULL);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 396U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneC[((aIndex + 5828U)) & S_BLOCK1], 24U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 1619U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneA[((aIndex + 2858U)) & S_BLOCK1], 28U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCross, 37U) ^ RotL64(aPrevious, 51U)) + (RotL64(aCarry, 4U) ^ RotL64(aIngress, 21U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterH = (((aWandererF + RotL64(aPrevious, 6U)) + RotL64(aCarry, 21U)) + 7893287783892523139U) + aPhaseCOrbiterAssignSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = (((aWandererJ + RotL64(aIngress, 13U)) + RotL64(aCarry, 37U)) + 10257331997383491153U) + aPhaseCOrbiterAssignSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterI = ((aWandererC + RotL64(aCross, 43U)) + RotL64(aCarry, 5U)) + 14562226733652231753U;
            aOrbiterC = (aWandererI + RotL64(aScatter, 39U)) + 14320342577110737851U;
            aOrbiterB = ((aWandererA + RotL64(aPrevious, 51U)) + 9816717579822880756U) + aNonceWordD;
            aOrbiterD = (aWandererH + RotL64(aIngress, 30U)) + 9558926960095881953U;
            aOrbiterF = ((aWandererE + RotL64(aCross, 19U)) + 9230371862654338324U) + aNonceWordA;
            aOrbiterJ = (aWandererB + RotL64(aScatter, 47U)) + 6414274291252913420U;
            aOrbiterE = (aWandererG + RotL64(aCross, 23U)) + 13868546184398350849U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 16940736952569949038U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 2866957764814864371U;
            aOrbiterI = RotL64((aOrbiterI * 3554702178644797003U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 7916721976073979724U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 1602444214978842275U;
            aOrbiterD = RotL64((aOrbiterD * 11072503711308122385U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 9529061385251008037U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterF) ^ 8402775110887376588U) ^ aPhaseCOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterJ = RotL64((aOrbiterJ * 13980225144628227381U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 15003592180290390713U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 14195681406520825751U) ^ aPhaseCOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 11455000833788877217U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 3263577002367714202U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 12019422062655581928U;
            aOrbiterH = RotL64((aOrbiterH * 5002313835338447799U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 8508638054582582917U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 6536618106353552880U;
            aOrbiterC = RotL64((aOrbiterC * 6233964121117511885U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 9654542989321430868U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 7019594782797863244U;
            aOrbiterF = RotL64((aOrbiterF * 1234877854354279981U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 8256061220727519919U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 9232754129467036130U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 17556001874302369781U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 5608829951337740378U) + aNonceWordN;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 12632120498473345701U) ^ aNonceWordF;
            aOrbiterB = RotL64((aOrbiterB * 6994794653605831925U), 19U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterH, 54U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 51U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 5U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 23U));
            aIngress = aIngress + RotL64(aOrbiterB, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 36U) + RotL64(aOrbiterF, 37U)) + aOrbiterC) + aNonceWordI);
            aWandererA = aWandererA + (((RotL64(aIngress, 13U) + RotL64(aOrbiterB, 46U)) + aOrbiterG) + aPhaseCWandererUpdateSaltE[((aIndex + 11U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 27U) + aOrbiterH) + RotL64(aOrbiterF, 21U)) + aPhaseCWandererUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aCross, 5U) + RotL64(aOrbiterH, 3U)) + aOrbiterJ) + RotL64(aCarry, 57U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 58U) + RotL64(aOrbiterD, 41U)) + aOrbiterG);
            aWandererI = aWandererI + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterC, 51U)) + aOrbiterJ) + RotL64(aCarry, 23U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 19U) + aOrbiterC) + RotL64(aOrbiterI, 11U));
            aWandererC = aWandererC + (((RotL64(aCross, 23U) + aOrbiterG) + RotL64(aOrbiterF, 27U)) + aNonceWordH);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 41U) + RotL64(aOrbiterE, 56U)) + aOrbiterG) + aNonceWordC);
            //
            aCarry = aCarry + (RotL64(aWandererE, 26U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererC, 39U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererG, 23U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererA, 43U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererJ, 53U);
            aCarry = aCarry + RotL64(aIngress, 6U);
            aCarry = aCarry ^ (aNonceWordB ^ aNonceWordD);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 10965U)) & S_BLOCK1], 38U) ^ RotL64(aOperationLaneD[((aIndex + 10798U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 16144U)) & S_BLOCK1], 58U) ^ RotL64(aOperationLaneB[((aIndex + 10993U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 29U) + RotL64(aCross, 43U)) + (RotL64(aPrevious, 13U) ^ RotL64(aCarry, 56U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterH = (aWandererK + RotL64(aIngress, 12U)) + 18302975933754610273U;
            aOrbiterC = (aWandererE + RotL64(aPrevious, 57U)) + 16736972646771456082U;
            aOrbiterJ = ((aWandererA + RotL64(aScatter, 37U)) + 17389406266488137442U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterG = ((aWandererG + RotL64(aCross, 43U)) + RotL64(aCarry, 5U)) + 5252511566486165539U;
            aOrbiterF = (((aWandererH + RotL64(aIngress, 4U)) + RotL64(aCarry, 29U)) + 5730715427422747640U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = (aWandererJ + RotL64(aScatter, 51U)) + 6412695646456045825U;
            aOrbiterI = (aWandererF + RotL64(aPrevious, 47U)) + 9539701605708994494U;
            aOrbiterB = (aWandererB + RotL64(aCross, 21U)) + 18355107116412945722U;
            aOrbiterE = (((aWandererI + RotL64(aScatter, 27U)) + RotL64(aCarry, 13U)) + 11735742491750132942U) + aNonceWordE;
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 12363819388562658842U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 5861430292304371543U;
            aOrbiterJ = RotL64((aOrbiterJ * 12989055611235382695U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 15027487084595017708U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 7012850020745791926U) ^ aNonceWordO;
            aOrbiterF = RotL64((aOrbiterF * 15952928839355613939U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 11904871669287886120U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 11199760114477343208U;
            aOrbiterI = RotL64((aOrbiterI * 7156374911847525867U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 3856004502263742700U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 3705931243173921893U;
            aOrbiterB = RotL64((aOrbiterB * 10334871178498711485U), 37U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 12305785390539209389U) + aPhaseCOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 18057980996551978823U;
            aOrbiterE = RotL64((aOrbiterE * 4850564181113470859U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 3229431819292153014U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 2994716629242460094U;
            aOrbiterH = RotL64((aOrbiterH * 1029427328395257917U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 9796307843453735512U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 2957260393651252432U;
            aOrbiterG = RotL64((aOrbiterG * 7261055869794739609U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 4060469664218866340U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 17462081697889685330U;
            aOrbiterD = RotL64((aOrbiterD * 7712009170974461225U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 13638660073917821172U) + aPhaseCOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 15202349592659062565U) ^ aPhaseCOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4514326257446024301U), 51U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterJ, 3U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 57U));
            aIngress = aIngress + (RotL64(aOrbiterD, 36U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 21U));
            aIngress = aIngress + RotL64(aOrbiterE, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterJ, 35U)) + aOrbiterE) + aPhaseCWandererUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 11U) + aOrbiterE) + RotL64(aOrbiterC, 43U)) + RotL64(aCarry, 41U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 60U) + RotL64(aOrbiterD, 11U)) + aOrbiterE);
            aWandererF = aWandererF + (((RotL64(aCross, 39U) + RotL64(aOrbiterD, 57U)) + aOrbiterI) + RotL64(aCarry, 3U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 3U) + aOrbiterI) + RotL64(aOrbiterG, 4U));
            aWandererG = aWandererG + (((RotL64(aIngress, 53U) + RotL64(aOrbiterF, 39U)) + aOrbiterD) + aPhaseCWandererUpdateSaltD[((aIndex + 29U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterG, 19U)) + aOrbiterF) + aNonceWordI);
            aWandererH = aWandererH + ((RotL64(aScatter, 23U) + RotL64(aOrbiterF, 27U)) + aOrbiterB);
            aWandererB = aWandererB ^ ((RotL64(aCross, 28U) + aOrbiterB) + RotL64(aOrbiterH, 50U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 23U) ^ aWandererJ);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 30U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 5U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 35U));
            aCarry = aCarry + RotL64(aWandererE, 27U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = aCarry ^ (aNonceWordL ^ aNonceWordJ);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 21080U)) & S_BLOCK1], 12U) ^ RotL64(aWorkLaneA[((aIndex + 24190U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 19277U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 16995U)) & S_BLOCK1], 28U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 57U) + RotL64(aCross, 6U)) ^ (RotL64(aCarry, 23U) + RotL64(aIngress, 37U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterF = ((((aWandererC + RotL64(aScatter, 12U)) + RotL64(aCarry, 53U)) + 12380376990224645149U) + aPhaseCOrbiterAssignSaltD[((aIndex + 10U)) & S_SALT1]) + aNonceWordI;
            aOrbiterC = ((aWandererA + RotL64(aPrevious, 39U)) + RotL64(aCarry, 29U)) + 18296928500297384014U;
            aOrbiterB = (aWandererF + RotL64(aIngress, 29U)) + 3550626816361145100U;
            aOrbiterJ = ((aWandererG + RotL64(aCross, 21U)) + RotL64(aCarry, 19U)) + 2667792936946706027U;
            aOrbiterH = (aWandererJ + RotL64(aIngress, 47U)) + 12020969779370926953U;
            aOrbiterE = ((aWandererB + RotL64(aScatter, 43U)) + 737340727886903447U) + aPhaseCOrbiterAssignSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterD = (aWandererK + RotL64(aCross, 58U)) + 1681797651799760502U;
            aOrbiterA = (aWandererI + RotL64(aPrevious, 53U)) + 2956186342689489064U;
            aOrbiterG = (aWandererD + RotL64(aScatter, 3U)) + 1876852870402977177U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 6433205819353555071U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 9065076854974222998U) ^ aNonceWordA;
            aOrbiterB = RotL64((aOrbiterB * 5459675878087242021U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 3254410578766789992U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 2005081975473815576U;
            aOrbiterF = RotL64((aOrbiterF * 9947701153722014085U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 15992999234834560419U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 3458344156815120948U;
            aOrbiterJ = RotL64((aOrbiterJ * 1668460113964608051U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 17069783053664877727U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 1260234710193913099U;
            aOrbiterC = RotL64((aOrbiterC * 4561226779897414381U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 3825186451876061335U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 2905344294992827535U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2469896090698580795U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 18141402347899180617U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 8760129857609925066U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 2507999156108123047U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 594052473780678210U) + aPhaseCOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 13216719212966128379U;
            aOrbiterD = RotL64((aOrbiterD * 10691355329696722303U), 39U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 10029948739466316169U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 11912428807431992996U;
            aOrbiterA = RotL64((aOrbiterA * 85016510811938307U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 8735634019801417287U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 12785916159063273545U;
            aOrbiterG = RotL64((aOrbiterG * 1161917531260663357U), 43U);
            //
            aIngress = RotL64(aOrbiterC, 41U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 12U));
            aIngress = aIngress + (RotL64(aOrbiterE, 53U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 19U));
            aIngress = aIngress + RotL64(aOrbiterG, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aPrevious, 53U) + RotL64(aOrbiterF, 57U)) + aOrbiterA) + RotL64(aCarry, 13U)) + aNonceWordK);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterC, 48U)) + aOrbiterE) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 39U) + aOrbiterD) + RotL64(aOrbiterG, 35U)) + RotL64(aCarry, 3U)) + aNonceWordG);
            aWandererD = aWandererD ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterD, 13U)) + aOrbiterH);
            aWandererB = aWandererB + (((RotL64(aScatter, 6U) + RotL64(aOrbiterF, 43U)) + aOrbiterC) + aNonceWordB);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterG, 5U)) + aOrbiterJ);
            aWandererI = aWandererI + (((RotL64(aIngress, 19U) + RotL64(aOrbiterJ, 53U)) + aOrbiterB) + aPhaseCWandererUpdateSaltC[((aIndex + 19U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 13U) + aOrbiterF) + RotL64(aOrbiterG, 24U));
            aWandererK = aWandererK + ((RotL64(aIngress, 30U) + RotL64(aOrbiterH, 29U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererB, 47U) ^ aWandererJ);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 53U));
            aCarry = aCarry + (RotL64(aWandererA, 11U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererC, 29U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererD, 34U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ aNonceWordN;
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 27256U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 29938U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 32002U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 31540U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 47U) + RotL64(aCross, 35U)) ^ (RotL64(aCarry, 60U) ^ RotL64(aPrevious, 13U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterB = (aWandererB + RotL64(aIngress, 57U)) + 13333509828310369865U;
            aOrbiterF = ((aWandererE + RotL64(aScatter, 53U)) + 7645352517103840797U) + aNonceWordB;
            aOrbiterA = ((aWandererK + RotL64(aPrevious, 28U)) + RotL64(aCarry, 27U)) + 5310766306660062655U;
            aOrbiterG = (aWandererI + RotL64(aCross, 41U)) + 5165635069832352932U;
            aOrbiterJ = ((aWandererH + RotL64(aScatter, 37U)) + 15684141764734281849U) + aPhaseCOrbiterAssignSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterC = ((aWandererC + RotL64(aPrevious, 11U)) + 3327963374225061738U) + aNonceWordA;
            aOrbiterD = (aWandererD + RotL64(aCross, 47U)) + 8625811794878848871U;
            aOrbiterE = (((aWandererF + RotL64(aIngress, 5U)) + RotL64(aCarry, 41U)) + 7598657468430485291U) + aPhaseCOrbiterAssignSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterH = ((aWandererG + RotL64(aCross, 18U)) + RotL64(aCarry, 53U)) + 2881171216276746485U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 10237691227222918101U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 6419254255884834497U) ^ aPhaseCOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3816625473642865305U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 4238455444646479956U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterG) ^ 14936613353493061492U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterJ = RotL64((aOrbiterJ * 3544216916806292273U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 15324699725208372627U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 9506640480601832011U) ^ aNonceWordH;
            aOrbiterD = RotL64((aOrbiterD * 12819564111348390227U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 3709149613660215641U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 1724290199312754307U;
            aOrbiterB = RotL64((aOrbiterB * 12597580418257897965U), 53U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 13191172833570139194U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 3686087945377837886U;
            aOrbiterG = RotL64((aOrbiterG * 10883609557429936283U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 10418330386245397022U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 5383531313632347245U) ^ aNonceWordC;
            aOrbiterC = RotL64((aOrbiterC * 2987755379396160073U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 7414716553072652212U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 11301761123966206201U;
            aOrbiterE = RotL64((aOrbiterE * 1546727321088592187U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 8570229732236388847U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 8773754460060264773U) ^ aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 3251360788932563495U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 13636929800504199371U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 5486599841558573720U;
            aOrbiterF = RotL64((aOrbiterF * 2867914211589815153U), 11U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterD, 39U);
            aIngress = aIngress + (RotL64(aOrbiterB, 22U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterG, 27U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterE, 43U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterC, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aScatter, 52U) + aOrbiterB) + RotL64(aOrbiterF, 14U));
            aWandererC = aWandererC + (((RotL64(aIngress, 5U) + aOrbiterA) + RotL64(aOrbiterE, 43U)) + RotL64(aCarry, 57U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 19U) + aOrbiterF) + RotL64(aOrbiterD, 39U));
            aWandererK = aWandererK + ((RotL64(aPrevious, 47U) + aOrbiterG) + RotL64(aOrbiterA, 19U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 23U) + RotL64(aOrbiterG, 57U)) + aOrbiterH) + aPhaseCWandererUpdateSaltE[((aIndex + 27U)) & S_SALT1]);
            aWandererH = aWandererH + (((((RotL64(aCross, 39U) + RotL64(aOrbiterJ, 3U)) + aOrbiterD) + RotL64(aCarry, 37U)) + aNonceWordI) + aPhaseCWandererUpdateSaltF[((aIndex + 18U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterC, 51U)) + aOrbiterE);
            aWandererD = aWandererD + ((RotL64(aPrevious, 14U) + aOrbiterB) + RotL64(aOrbiterH, 47U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterG, 24U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererK, 43U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererE, 23U) ^ aWandererD);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 6U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 39U));
            aCarry = aCarry + RotL64(aWandererB, 3U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = aCarry ^ aNonceWordN;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x8C0405C4A76FEDBBULL + 0xCAE3505324EB5742ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xABF2DD58840C0561ULL + 0xA979694BF5C44D4BULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xC81890C69A410EE3ULL + 0x876DA7F6999C9ECEULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xD7D2A6DA73FFDC83ULL + 0xDAD1E1674AD9C6F0ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x8CE8097ABCA5D777ULL + 0xBFDD3C41F61702F4ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xB96359F15AEA774FULL + 0xE54C1E0A3E6E4CDFULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xA2F1501FC126DAA3ULL + 0xD06D0D0F8E859943ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xD411B9A0C0D1251DULL + 0xE8E19896D47E8132ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xC8753CBF9032C7EBULL + 0xD724AD7D3892A77FULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0x834794D07F7C044FULL + 0xE8850F715C2429CFULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xEE5C3BBF54CB6F7FULL + 0xC58ED52AED671048ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xE6C1283D84E81D1DULL + 0xCCF3A266C92DD28BULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xFBA6E60F4F9FC2EDULL + 0x98CBD40620CEC95EULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xC2F8194DF251D109ULL + 0x9563D3377E436A6CULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xE78AEE76B8293EC7ULL + 0xF1A2968672959253ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xCBD0A5DC95C751DDULL + 0xAC3F792739C89FFDULL);
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 3768U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 5440U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 1861U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 161U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCross, 41U) ^ RotL64(aPrevious, 27U)) + (RotL64(aIngress, 10U) + RotL64(aCarry, 57U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterK = ((aWandererK + RotL64(aScatter, 23U)) + 4980738603982643969U) + aNonceWordK;
            aOrbiterD = (aWandererI + RotL64(aCross, 3U)) + 17660278413018470020U;
            aOrbiterJ = (aWandererJ + RotL64(aPrevious, 34U)) + 17598114429859543466U;
            aOrbiterG = (aWandererG + RotL64(aIngress, 41U)) + 10993929335279994739U;
            aOrbiterA = ((aWandererH + RotL64(aCross, 5U)) + 17967203122976322481U) + aPhaseDOrbiterAssignSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = ((aWandererC + RotL64(aIngress, 39U)) + RotL64(aCarry, 53U)) + 1872290205549034384U;
            aOrbiterH = (aWandererD + RotL64(aScatter, 27U)) + 16607778671782810797U;
            aOrbiterF = (aWandererF + RotL64(aPrevious, 13U)) + 4895226930754394376U;
            aOrbiterC = ((aWandererB + RotL64(aScatter, 53U)) + RotL64(aCarry, 5U)) + 14960359005982301383U;
            aOrbiterI = ((aWandererA + RotL64(aCross, 11U)) + 9921642352377700630U) + aPhaseDOrbiterAssignSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = (((aWandererE + RotL64(aPrevious, 44U)) + RotL64(aCarry, 43U)) + 893281964367208693U) + aNonceWordE;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 8232519988397858732U) + aNonceWordH;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 4433022122758913407U;
            aOrbiterJ = RotL64((aOrbiterJ * 834240393225479419U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 12689609831247168353U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 404535388957472176U;
            aOrbiterB = RotL64((aOrbiterB * 14534020545479806593U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 3349108201964013155U) + aNonceWordG;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 4386449511297371730U;
            aOrbiterK = RotL64((aOrbiterK * 9596273264321140229U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 14314587717949070586U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 10923886625271054985U;
            aOrbiterG = RotL64((aOrbiterG * 7838969002623486809U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 17634909585329833520U) + aNonceWordL;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 2021301459918350372U;
            aOrbiterH = RotL64((aOrbiterH * 1388242915918642741U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 5219599112498224367U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 10641339455385046206U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 1022283727595400719U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 5003342156562330058U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 10951027475628404336U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 17836928292555158461U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 13040991872592235460U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 11149099984302782267U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 4248667283139686251U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 2202253777854402763U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 16679038924474862612U;
            aOrbiterA = RotL64((aOrbiterA * 2624443661523083597U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 1959650241410955571U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 8415989510614674816U;
            aOrbiterF = RotL64((aOrbiterF * 16340289102832732519U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 2344501711730399821U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 4980738603982643969U;
            aOrbiterI = RotL64((aOrbiterI * 6419275275477478723U), 19U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterC, 13U);
            aIngress = aIngress + (RotL64(aOrbiterG, 20U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterD, 37U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 3U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 53U));
            aIngress = aIngress + RotL64(aOrbiterJ, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aPrevious, 37U) + RotL64(aOrbiterE, 47U)) + aOrbiterB) + aNonceWordI);
            aWandererE = aWandererE ^ ((RotL64(aCross, 18U) + aOrbiterI) + RotL64(aOrbiterK, 14U));
            aWandererC = aWandererC + ((RotL64(aScatter, 57U) + RotL64(aOrbiterB, 19U)) + aOrbiterA);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterE, 21U)) + aOrbiterH);
            aWandererK = aWandererK + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterK, 37U)) + aOrbiterC) + RotL64(aCarry, 27U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 23U) + aOrbiterD) + RotL64(aOrbiterK, 5U));
            aWandererJ = aWandererJ + ((RotL64(aScatter, 60U) + RotL64(aOrbiterH, 29U)) + aOrbiterJ);
            aWandererF = aWandererF ^ (((RotL64(aCross, 5U) + RotL64(aOrbiterD, 57U)) + aOrbiterE) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aScatter, 11U) + RotL64(aOrbiterC, 3U)) + aOrbiterE) + aNonceWordA) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 21U) + aOrbiterB) + RotL64(aOrbiterF, 60U)) + aNonceWordC);
            aWandererA = aWandererA + (((RotL64(aIngress, 53U) + RotL64(aOrbiterA, 43U)) + aOrbiterG) + RotL64(aCarry, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 48U) ^ aWandererA);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 57U));
            aCarry = aCarry + (RotL64(aWandererD, 53U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererG, 41U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererI, 22U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererB, 39U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ aNonceWordG;
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 9539U)) & S_BLOCK1], 34U) ^ RotL64(aExpandLaneD[((aIndex + 10407U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 8363U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 5861U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 53U) + RotL64(aCarry, 3U)) ^ (RotL64(aCross, 41U) ^ RotL64(aIngress, 26U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterH = (aWandererE + RotL64(aIngress, 35U)) + 1952750591494698524U;
            aOrbiterE = ((aWandererK + RotL64(aPrevious, 57U)) + RotL64(aCarry, 53U)) + 4488270851303332830U;
            aOrbiterF = (aWandererB + RotL64(aScatter, 21U)) + 2738763375328927635U;
            aOrbiterC = (aWandererD + RotL64(aCross, 37U)) + 6728843649480454340U;
            aOrbiterJ = (aWandererH + RotL64(aPrevious, 26U)) + 10490717875258865358U;
            aOrbiterI = (aWandererI + RotL64(aScatter, 13U)) + 1429288737812910205U;
            aOrbiterA = ((aWandererA + RotL64(aIngress, 29U)) + RotL64(aCarry, 39U)) + 2761375016998907636U;
            aOrbiterD = (((aWandererJ + RotL64(aCross, 19U)) + RotL64(aCarry, 47U)) + 1088988605204499835U) + aPhaseDOrbiterAssignSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterK = (aWandererC + RotL64(aIngress, 52U)) + 6829840407300289709U;
            aOrbiterB = ((aWandererF + RotL64(aCross, 41U)) + 9267240337867690471U) + aPhaseDOrbiterAssignSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = ((aWandererG + RotL64(aScatter, 39U)) + 8120113021183975703U) + aNonceWordC;
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 1340980511302566784U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 11874452169979878835U) ^ aNonceWordD;
            aOrbiterF = RotL64((aOrbiterF * 8638486178860092537U), 53U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 1872314794140971426U) + aNonceWordL;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 6013952618696225751U;
            aOrbiterE = RotL64((aOrbiterE * 7994863587373565715U), 39U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 3644011378086236002U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 8501867691997891731U;
            aOrbiterJ = RotL64((aOrbiterJ * 7115282675461711509U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 2493546555198066143U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 5179240189571799179U;
            aOrbiterA = RotL64((aOrbiterA * 1267579130962756135U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 11273348247858394197U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 4577476419423118925U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8427261005061162673U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 6201955123046621919U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 3930651302557530185U;
            aOrbiterH = RotL64((aOrbiterH * 1563512534463027965U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 7571426325227856019U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 11098508505512361002U) ^ aNonceWordP;
            aOrbiterC = RotL64((aOrbiterC * 9229352429618815089U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 6154830144380484305U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 4282054616147137364U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 14984813139796280171U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 14818120999774989697U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 12174471855744785761U;
            aOrbiterD = RotL64((aOrbiterD * 3061488029278974095U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 3117297607579915182U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 2979217539186455309U;
            aOrbiterB = RotL64((aOrbiterB * 12235308335184626143U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 824986728082249286U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 1952750591494698524U;
            aOrbiterG = RotL64((aOrbiterG * 10162288961171400541U), 13U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterC, 30U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 21U));
            aIngress = aIngress + (RotL64(aOrbiterE, 19U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 41U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 47U));
            aIngress = aIngress + RotL64(aOrbiterB, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 29U) + aOrbiterB) + RotL64(aOrbiterJ, 27U));
            aWandererD = aWandererD + (((RotL64(aIngress, 5U) + RotL64(aOrbiterE, 48U)) + aOrbiterH) + aNonceWordH);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 50U) + aOrbiterB) + RotL64(aOrbiterG, 21U)) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 39U) + aOrbiterK) + RotL64(aOrbiterH, 3U)) + RotL64(aCarry, 51U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 27U) + RotL64(aOrbiterG, 39U)) + aOrbiterA) + aPhaseDWandererUpdateSaltF[((aIndex + 25U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aIngress, 19U) + aOrbiterJ) + RotL64(aOrbiterE, 51U)) + RotL64(aCarry, 43U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterE, 23U)) + aOrbiterB);
            aWandererB = aWandererB + ((RotL64(aCross, 3U) + aOrbiterH) + RotL64(aOrbiterC, 6U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 12U) + aOrbiterG) + RotL64(aOrbiterF, 29U));
            aWandererK = aWandererK + (((RotL64(aIngress, 41U) + aOrbiterD) + RotL64(aOrbiterF, 41U)) + aNonceWordN);
            aWandererC = aWandererC ^ ((RotL64(aCross, 21U) + aOrbiterI) + RotL64(aOrbiterE, 11U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 39U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererB, 19U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererK, 28U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererF, 3U) ^ aWandererH);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 23U));
            aCarry = aCarry + RotL64(aWandererC, 51U);
            aCarry = aCarry + RotL64(aIngress, 44U);
            aCarry = aCarry ^ (aNonceWordA ^ aNonceWordC);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 11038U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneA[((aIndex + 15568U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 12414U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 13176U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 21U) ^ RotL64(aCross, 5U)) + (RotL64(aCarry, 36U) + RotL64(aIngress, 53U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterF = (((aWandererE + RotL64(aIngress, 5U)) + 4179952823252098240U) + aPhaseDOrbiterAssignSaltA[((aIndex + 4U)) & S_SALT1]) + aNonceWordL;
            aOrbiterJ = ((aWandererG + RotL64(aPrevious, 29U)) + RotL64(aCarry, 47U)) + 3745613452332101749U;
            aOrbiterB = (((aWandererI + RotL64(aScatter, 47U)) + RotL64(aCarry, 27U)) + 2955689793395307176U) + aNonceWordH;
            aOrbiterA = (aWandererJ + RotL64(aCross, 50U)) + 5639060180251322019U;
            aOrbiterI = (aWandererH + RotL64(aIngress, 27U)) + 7901969163853586463U;
            aOrbiterD = (((aWandererA + RotL64(aCross, 53U)) + RotL64(aCarry, 37U)) + 2242166787816318119U) + aNonceWordA;
            aOrbiterG = (aWandererF + RotL64(aScatter, 19U)) + 5239936443960750064U;
            aOrbiterE = (aWandererB + RotL64(aPrevious, 3U)) + 13939136954732185558U;
            aOrbiterH = (aWandererC + RotL64(aCross, 43U)) + 17058884136712717463U;
            aOrbiterK = (aWandererK + RotL64(aScatter, 41U)) + 18148618660054585941U;
            aOrbiterC = ((aWandererD + RotL64(aPrevious, 60U)) + 7022023484530327814U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 7722084537340095637U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 11764151879690934182U;
            aOrbiterB = RotL64((aOrbiterB * 12264384877711365655U), 37U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 16412785901758144708U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 9666718667728274824U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 10865799822751771795U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 4307127540152109364U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 2457646804702647606U;
            aOrbiterJ = RotL64((aOrbiterJ * 6340030928007058595U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 3179394870088602208U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 504977947273774249U;
            aOrbiterI = RotL64((aOrbiterI * 16190282058883481551U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 16182729401018310837U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 7110817020445860609U;
            aOrbiterE = RotL64((aOrbiterE * 13371352088428584087U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 12960656706837391973U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 7103806893724395904U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 14365984439655979791U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 1248300178080633527U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 7195473175424961337U;
            aOrbiterF = RotL64((aOrbiterF * 4633558992739305045U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 13007951568242991449U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 10296811247653636372U) ^ aNonceWordP;
            aOrbiterA = RotL64((aOrbiterA * 16469682651380549395U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 13922797949001028335U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 16773545425463040155U;
            aOrbiterG = RotL64((aOrbiterG * 10639282630227832397U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 2888887140296117803U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 10279517418046269817U;
            aOrbiterH = RotL64((aOrbiterH * 8600355360339461535U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 17303373436784809093U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 4179952823252098240U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 3675754609699406437U), 23U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterJ, 57U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 43U));
            aIngress = aIngress + (RotL64(aOrbiterF, 5U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 41U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 27U));
            aIngress = aIngress + RotL64(aOrbiterG, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterD, 53U)) + aOrbiterJ);
            aWandererA = aWandererA + ((RotL64(aScatter, 19U) + RotL64(aOrbiterI, 47U)) + aOrbiterJ);
            aWandererI = aWandererI ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterE, 35U)) + aOrbiterI) + aNonceWordN);
            aWandererF = aWandererF + ((RotL64(aIngress, 27U) + RotL64(aOrbiterF, 37U)) + aOrbiterA);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterC, 21U)) + aOrbiterI) + aPhaseDWandererUpdateSaltB[((aIndex + 11U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aScatter, 54U) + RotL64(aOrbiterF, 56U)) + aOrbiterH);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 21U) + aOrbiterB) + RotL64(aOrbiterK, 41U)) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 37U) + RotL64(aOrbiterB, 23U)) + aOrbiterI) + RotL64(aCarry, 43U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 47U) + aOrbiterC) + RotL64(aOrbiterG, 43U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterI, 29U)) + aOrbiterA) + RotL64(aCarry, 11U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 60U) + RotL64(aOrbiterF, 50U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 29U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 57U));
            aCarry = aCarry + (RotL64(aWandererE, 54U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererC, 11U) ^ aWandererD);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 43U));
            aCarry = aCarry + RotL64(aWandererB, 35U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = aCarry ^ (aNonceWordA ^ aNonceWordM);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 19979U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 21196U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 20622U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 20999U)) & S_BLOCK1], 56U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 13U) + RotL64(aIngress, 27U)) ^ (RotL64(aCross, 54U) ^ RotL64(aPrevious, 39U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterJ = ((aWandererJ + RotL64(aPrevious, 18U)) + 9446153639709651566U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterG = ((aWandererA + RotL64(aCross, 5U)) + RotL64(aCarry, 21U)) + 10550762260670758167U;
            aOrbiterI = ((aWandererE + RotL64(aIngress, 41U)) + RotL64(aCarry, 37U)) + 7062634922142578383U;
            aOrbiterE = (aWandererG + RotL64(aScatter, 51U)) + 9178499097812764515U;
            aOrbiterD = ((aWandererK + RotL64(aPrevious, 43U)) + 6887103379773525538U) + aNonceWordO;
            aOrbiterH = (aWandererI + RotL64(aIngress, 27U)) + 6239750312052010257U;
            aOrbiterB = (aWandererF + RotL64(aCross, 38U)) + 17645022614523287959U;
            aOrbiterA = (aWandererC + RotL64(aScatter, 57U)) + 3639618183259408272U;
            aOrbiterF = (((aWandererH + RotL64(aCross, 35U)) + 3131737117548745095U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 28U)) & S_SALT1]) + aNonceWordA;
            aOrbiterK = ((aWandererD + RotL64(aScatter, 29U)) + 7253994382396406554U) + aNonceWordN;
            aOrbiterC = ((aWandererB + RotL64(aPrevious, 53U)) + RotL64(aCarry, 13U)) + 15217993711938379561U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 12594152227603630033U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 11250170200489647869U) ^ aNonceWordK;
            aOrbiterI = RotL64((aOrbiterI * 546800378327864723U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 12936942656624279424U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 10990736056052106149U;
            aOrbiterD = RotL64((aOrbiterD * 7123916809953459187U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 12787293075893090465U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterE) ^ 17154990205620778151U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterH = RotL64((aOrbiterH * 10031369940028159521U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 1270827262969060301U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 17337623431665013136U;
            aOrbiterB = RotL64((aOrbiterB * 1517262088236356107U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 830330490987911853U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 6828309232554560547U;
            aOrbiterA = RotL64((aOrbiterA * 9742464176986145819U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 11470087853413986203U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 10470148870747884420U;
            aOrbiterF = RotL64((aOrbiterF * 6766079738799967443U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 18315536891901859637U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 12264670822285914271U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5841574505408674119U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 10931842095884524879U) + aNonceWordH;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 11134871340959676257U;
            aOrbiterC = RotL64((aOrbiterC * 11714837622285605745U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 11484168476761306078U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 5964766416973454097U;
            aOrbiterJ = RotL64((aOrbiterJ * 14721123403032510803U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 10646362765367117994U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 8994267196877016381U;
            aOrbiterG = RotL64((aOrbiterG * 17386417559346134797U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 16797547458402042464U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 9446153639709651566U;
            aOrbiterE = RotL64((aOrbiterE * 567585472220695323U), 21U);
            //
            aIngress = RotL64(aOrbiterF, 21U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 13U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 39U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 37U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 43U));
            aIngress = aIngress + RotL64(aOrbiterJ, 60U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aPrevious, 57U) + aOrbiterD) + RotL64(aOrbiterH, 34U)) + RotL64(aCarry, 51U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 35U) + aOrbiterB) + RotL64(aOrbiterK, 53U));
            aWandererI = aWandererI + ((RotL64(aIngress, 39U) + aOrbiterG) + RotL64(aOrbiterD, 27U));
            aWandererF = aWandererF ^ ((((RotL64(aScatter, 43U) + aOrbiterD) + RotL64(aOrbiterC, 43U)) + aNonceWordL) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aIngress, 37U) + aOrbiterB) + RotL64(aOrbiterG, 13U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 41U) + aOrbiterI) + RotL64(aOrbiterE, 51U));
            aWandererK = aWandererK + (((RotL64(aCross, 28U) + RotL64(aOrbiterA, 41U)) + aOrbiterJ) + RotL64(aCarry, 27U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterF, 29U)) + aOrbiterI);
            aWandererA = aWandererA + ((RotL64(aIngress, 53U) + RotL64(aOrbiterC, 23U)) + aOrbiterB);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 19U) + aOrbiterA) + RotL64(aOrbiterF, 56U));
            aWandererG = aWandererG + ((((RotL64(aCross, 14U) + RotL64(aOrbiterJ, 11U)) + aOrbiterG) + aNonceWordE) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 11U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererE, 56U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererD, 39U) ^ aWandererB);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 53U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 43U));
            aCarry = aCarry + RotL64(aWandererJ, 47U);
            aCarry = aCarry + RotL64(aIngress, 4U);
            aCarry = aCarry ^ aNonceWordJ;
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 27019U)) & S_BLOCK1], 26U) ^ RotL64(aWorkLaneA[((aIndex + 27098U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 24568U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 24828U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 53U) + RotL64(aCarry, 19U)) ^ (RotL64(aCross, 6U) + RotL64(aIngress, 35U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterH = ((aWandererI + RotL64(aScatter, 13U)) + 8793908991006073956U) + aNonceWordA;
            aOrbiterI = ((aWandererH + RotL64(aCross, 27U)) + RotL64(aCarry, 37U)) + 2932916283348441943U;
            aOrbiterK = (((aWandererJ + RotL64(aPrevious, 44U)) + RotL64(aCarry, 21U)) + 11069042087940968262U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = (aWandererG + RotL64(aIngress, 53U)) + 14369628676782894441U;
            aOrbiterJ = ((aWandererA + RotL64(aPrevious, 3U)) + 8602903272780978282U) + aPhaseDOrbiterAssignSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterB = (aWandererK + RotL64(aCross, 41U)) + 3827036107178568820U;
            aOrbiterG = (aWandererE + RotL64(aIngress, 29U)) + 8905245209036772489U;
            aOrbiterA = ((aWandererC + RotL64(aScatter, 19U)) + RotL64(aCarry, 51U)) + 13331387530760017893U;
            aOrbiterC = (aWandererF + RotL64(aIngress, 50U)) + 9880107580289737823U;
            aOrbiterD = (aWandererD + RotL64(aPrevious, 35U)) + 10199619040626900278U;
            aOrbiterE = (aWandererB + RotL64(aScatter, 37U)) + 2466307560891374281U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 13973403407981259448U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 2851460278409385243U;
            aOrbiterK = RotL64((aOrbiterK * 11226902976321781743U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 10365453393815690776U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 2382382358987358791U;
            aOrbiterB = RotL64((aOrbiterB * 481563628980705781U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 5058198848163792422U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 10500434740387593487U;
            aOrbiterA = RotL64((aOrbiterA * 5946747708776079787U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 11289798395177667084U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 14327152153231286666U;
            aOrbiterD = RotL64((aOrbiterD * 18155778059595245561U), 21U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 8065137263811956313U) + aNonceWordK;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 3865153574847924816U;
            aOrbiterH = RotL64((aOrbiterH * 9495741102667755161U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 18102279969722473375U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 6306428427188742325U) ^ aNonceWordC;
            aOrbiterF = RotL64((aOrbiterF * 17826782872351406167U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 16953348204663693724U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 11950791817032898613U;
            aOrbiterG = RotL64((aOrbiterG * 1498946055469611133U), 39U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 11980823193543752994U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 17845490308799454871U;
            aOrbiterC = RotL64((aOrbiterC * 16385153013485463791U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 5566398755702887071U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 10308378271388889968U;
            aOrbiterE = RotL64((aOrbiterE * 142732084484961281U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 6717846700455219260U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 8297225372883997017U;
            aOrbiterI = RotL64((aOrbiterI * 14102812043481327907U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 12249337046267666603U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 8793908991006073956U;
            aOrbiterJ = RotL64((aOrbiterJ * 5851229209188473467U), 47U);
            //
            aIngress = RotL64(aOrbiterI, 6U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 37U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 43U));
            aIngress = aIngress + (RotL64(aOrbiterH, 35U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 47U));
            aIngress = aIngress + RotL64(aOrbiterC, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aScatter, 43U) + RotL64(aOrbiterA, 35U)) + aOrbiterD) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 27U) + RotL64(aOrbiterF, 46U)) + aOrbiterK) + RotL64(aCarry, 11U)) + aNonceWordH);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 37U) + aOrbiterD) + RotL64(aOrbiterG, 41U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 11U) + aOrbiterH) + RotL64(aOrbiterE, 39U)) + aPhaseDWandererUpdateSaltC[((aIndex + 14U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 40U) + aOrbiterF) + RotL64(aOrbiterB, 23U));
            aWandererH = aWandererH + ((RotL64(aScatter, 57U) + RotL64(aOrbiterF, 37U)) + aOrbiterE);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterG, 10U)) + aOrbiterF);
            aWandererG = aWandererG + ((RotL64(aCross, 23U) + aOrbiterB) + RotL64(aOrbiterI, 19U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 3U) + aOrbiterI) + RotL64(aOrbiterF, 3U));
            aWandererF = aWandererF + (((RotL64(aIngress, 35U) + aOrbiterC) + RotL64(aOrbiterK, 57U)) + RotL64(aCarry, 23U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 14U) + RotL64(aOrbiterC, 27U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 18U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 51U));
            aCarry = aCarry + (RotL64(aWandererD, 57U) ^ aWandererE);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 5U));
            aCarry = aCarry + (RotL64(aWandererB, 60U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererA, 43U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = aCarry ^ (aNonceWordD ^ aNonceWordI);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 27907U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 32545U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 27376U)) & S_BLOCK1], 6U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 29836U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 21U) ^ RotL64(aIngress, 35U)) ^ (RotL64(aPrevious, 5U) + RotL64(aCross, 56U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterF = (((aWandererK + RotL64(aPrevious, 19U)) + RotL64(aCarry, 11U)) + 785861751704720606U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterH = ((aWandererB + RotL64(aScatter, 5U)) + RotL64(aCarry, 57U)) + 15968088718435606299U;
            aOrbiterA = (aWandererC + RotL64(aCross, 54U)) + 1393976526590347151U;
            aOrbiterK = (aWandererD + RotL64(aIngress, 27U)) + 17240750947292745884U;
            aOrbiterB = ((aWandererH + RotL64(aPrevious, 13U)) + 4921576136163183137U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = (aWandererA + RotL64(aIngress, 35U)) + 3334047873553153032U;
            aOrbiterC = ((aWandererE + RotL64(aCross, 51U)) + RotL64(aCarry, 27U)) + 15086509978458408698U;
            aOrbiterD = ((aWandererF + RotL64(aScatter, 11U)) + 892391205397581998U) + aNonceWordI;
            aOrbiterG = ((aWandererI + RotL64(aCross, 60U)) + 2965686403183767521U) + aNonceWordK;
            aOrbiterJ = (aWandererJ + RotL64(aScatter, 21U)) + 14632215393655706170U;
            aOrbiterE = (aWandererG + RotL64(aPrevious, 39U)) + 15740589515342377322U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 11131164813943086445U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 6988080581278900960U) ^ aNonceWordE;
            aOrbiterA = RotL64((aOrbiterA * 6412189142344044255U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 16021254613117657178U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 6183615599897921154U;
            aOrbiterB = RotL64((aOrbiterB * 9976411093264211033U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 12533992547026652747U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 3104325358982904219U;
            aOrbiterI = RotL64((aOrbiterI * 14977348108778147265U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 3878525937957474644U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 2120435259884368445U;
            aOrbiterC = RotL64((aOrbiterC * 15964718652193073177U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 14928658302694194856U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 9121310461310309348U;
            aOrbiterD = RotL64((aOrbiterD * 17304439784647477491U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 3715693239100476493U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 7336577492932262490U;
            aOrbiterG = RotL64((aOrbiterG * 11074754160002665253U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 2312452827448455675U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 4322756069651934618U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 6908893297397073539U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 4962079617577705818U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 5072727464750706525U;
            aOrbiterE = RotL64((aOrbiterE * 4947670001221089155U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 4553791875259778686U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 15823770920225774233U;
            aOrbiterF = RotL64((aOrbiterF * 409663191536830375U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 9468608484284459072U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 8658861660659699947U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2933359123761406353U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 14453429515273506170U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 785861751704720606U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 3544627380583668815U), 13U);
            //
            aIngress = RotL64(aOrbiterC, 37U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 60U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 43U));
            aIngress = aIngress + (RotL64(aOrbiterD, 29U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 5U));
            aIngress = aIngress + RotL64(aOrbiterA, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aIngress, 46U) + RotL64(aOrbiterI, 13U)) + aOrbiterE) + RotL64(aCarry, 5U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 19U) + aOrbiterC) + RotL64(aOrbiterG, 35U));
            aWandererB = aWandererB + ((((RotL64(aPrevious, 23U) + aOrbiterF) + RotL64(aOrbiterB, 51U)) + RotL64(aCarry, 53U)) + aPhaseDWandererUpdateSaltA[((aIndex + 12U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterE, 6U)) + aOrbiterC);
            aWandererG = aWandererG + ((RotL64(aIngress, 13U) + aOrbiterB) + RotL64(aOrbiterH, 39U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 35U) + aOrbiterD) + RotL64(aOrbiterF, 53U));
            aWandererE = aWandererE + ((RotL64(aCross, 58U) + aOrbiterJ) + RotL64(aOrbiterK, 47U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterE, 27U)) + aOrbiterA);
            aWandererK = aWandererK + ((((RotL64(aCross, 53U) + RotL64(aOrbiterA, 3U)) + aOrbiterB) + aNonceWordN) + aPhaseDWandererUpdateSaltB[((aIndex + 16U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 27U) + aOrbiterC) + RotL64(aOrbiterI, 21U));
            aWandererD = aWandererD + ((RotL64(aScatter, 3U) + RotL64(aOrbiterH, 60U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 5U));
            aCarry = aCarry + (RotL64(aWandererA, 60U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererF, 3U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererI, 11U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererJ, 35U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererH, 19U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ (aNonceWordD ^ aNonceWordO);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xAD87E666CA4DDB51ULL + 0xF866F143CE753BE6ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xDA2D459E86856EB3ULL + 0xCD6763D33337C763ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xBFB880DFAE723F85ULL + 0xF2E48726F502A671ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xB921AE522A7FD2BFULL + 0x927311081957DB49ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xAC122A402E860C51ULL + 0xA3D6134CFBE172E5ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xFB8E6BEA2B880991ULL + 0xC50FA545C543257AULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xBD61832CBBE94C73ULL + 0x9B891BE0FF9E7C18ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x9AF01395D1C48AD5ULL + 0xEDA697209DF7E6F0ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x9B862031DADA5F87ULL + 0xF09867147A3E113AULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xDDF60959C240B695ULL + 0xE648B1DF3A24AE0DULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xD9F51919008764D1ULL + 0xDB010FC2B0D9AE08ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xF2E4A72891B8CDE9ULL + 0xB95C155657D82A5AULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xF744E55F356915FFULL + 0xF56FF6F65FCDD090ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xC4B06DB6E79A1353ULL + 0x9A7881B771DA5748ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xEE1A59FE280CC091ULL + 0xF2F1F862721FCCD3ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0x8782358C1C289E29ULL + 0xE1A93CE944C15347ULL);
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 4225U)) & S_BLOCK1], 4U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 2589U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 2994U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 4795U)) & S_BLOCK1], 50U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 18U) ^ RotL64(aCarry, 51U)) + (RotL64(aPrevious, 3U) ^ RotL64(aCross, 39U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterG = ((aWandererJ + RotL64(aScatter, 47U)) + RotL64(aCarry, 5U)) + 11998579547770778580U;
            aOrbiterJ = ((aWandererA + RotL64(aCross, 24U)) + 8409465187298704610U) + aNonceWordM;
            aOrbiterI = ((aWandererF + RotL64(aIngress, 41U)) + 3470222286110333500U) + aNonceWordC;
            aOrbiterC = ((((aWandererB + RotL64(aPrevious, 21U)) + RotL64(aCarry, 57U)) + 5704486785203069994U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordB;
            aOrbiterA = (aWandererC + RotL64(aCross, 11U)) + 10334944660253279633U;
            aOrbiterH = ((aWandererH + RotL64(aIngress, 13U)) + RotL64(aCarry, 47U)) + 7626852700722567477U;
            aOrbiterK = ((aWandererE + RotL64(aScatter, 35U)) + 14631310754943209743U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterD = (aWandererD + RotL64(aPrevious, 30U)) + 807160297237854120U;
            aOrbiterF = (aWandererI + RotL64(aIngress, 39U)) + 5624154783624196107U;
            aOrbiterB = (aWandererG + RotL64(aPrevious, 19U)) + 4971444394698940423U;
            aOrbiterE = (aWandererK + RotL64(aScatter, 51U)) + 6340057638461027062U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 9003019862787819481U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterG) ^ 13632057463595873033U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterI = RotL64((aOrbiterI * 12575202147280216765U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 12766104026871797746U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 4062118445824915939U;
            aOrbiterH = RotL64((aOrbiterH * 13130770039048080701U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 5258212525426469978U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 9956946981015983939U;
            aOrbiterG = RotL64((aOrbiterG * 8106382657040497669U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 10837606223056473999U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 13292864885504191134U;
            aOrbiterC = RotL64((aOrbiterC * 4445739587553669471U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 166087925900318658U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 6786842221885441388U;
            aOrbiterK = RotL64((aOrbiterK * 4411147600413147773U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 16888086378070246404U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 5240855484445974002U;
            aOrbiterF = RotL64((aOrbiterF * 402652898573422271U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 6874866669211571608U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 732890824978127460U;
            aOrbiterE = RotL64((aOrbiterE * 3776365957702257453U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 5541380495707308058U) + aNonceWordE;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 17947326584411475765U;
            aOrbiterJ = RotL64((aOrbiterJ * 10920952349981652899U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 15060679340045767910U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 1675974028461383576U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 15127962310365242819U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 226889112033170368U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 4290719734244011388U;
            aOrbiterD = RotL64((aOrbiterD * 6453598182035414143U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 7712233480730639084U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 11998579547770778580U) ^ aNonceWordJ;
            aOrbiterB = RotL64((aOrbiterB * 11599893373156816375U), 5U);
            //
            aIngress = RotL64(aOrbiterI, 43U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterH, 57U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterG, 41U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 11U));
            aIngress = aIngress + (RotL64(aOrbiterE, 6U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterB, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aIngress, 51U) + RotL64(aOrbiterH, 22U)) + aOrbiterJ);
            aWandererB = aWandererB ^ ((RotL64(aCross, 53U) + aOrbiterE) + RotL64(aOrbiterF, 3U));
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 35U) + RotL64(aOrbiterK, 43U)) + aOrbiterI) + RotL64(aCarry, 51U)) + aNonceWordA);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 39U) + RotL64(aOrbiterH, 29U)) + aOrbiterC) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aScatter, 20U) + aOrbiterJ) + RotL64(aOrbiterD, 6U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterD, 27U)) + aOrbiterE);
            aWandererE = aWandererE + ((RotL64(aIngress, 11U) + RotL64(aOrbiterG, 37U)) + aOrbiterE);
            aWandererK = aWandererK ^ ((RotL64(aCross, 29U) + aOrbiterK) + RotL64(aOrbiterB, 47U));
            aWandererG = aWandererG + (((((RotL64(aPrevious, 22U) + aOrbiterK) + RotL64(aOrbiterF, 13U)) + RotL64(aCarry, 27U)) + aNonceWordN) + aPhaseEWandererUpdateSaltA[((aIndex + 9U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 13U) + aOrbiterC) + RotL64(aOrbiterB, 57U));
            aWandererF = aWandererF + ((RotL64(aScatter, 41U) + aOrbiterB) + RotL64(aOrbiterA, 51U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 35U) ^ aWandererD);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 58U));
            aCarry = aCarry + (RotL64(aWandererI, 37U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererF, 19U) ^ aWandererB);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 53U));
            aCarry = aCarry + RotL64(aWandererJ, 46U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = aCarry ^ aNonceWordM;
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 6037U)) & S_BLOCK1], 14U) ^ RotL64(aWorkLaneD[((aIndex + 6583U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 7211U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 7273U)) & S_BLOCK1], 12U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 37U) + RotL64(aPrevious, 51U)) ^ (RotL64(aIngress, 4U) + RotL64(aCross, 19U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterF = ((aWandererH + RotL64(aScatter, 41U)) + 2915859148137000694U) + aNonceWordB;
            aOrbiterG = (((aWandererF + RotL64(aIngress, 29U)) + RotL64(aCarry, 57U)) + 210680583721444425U) + aNonceWordG;
            aOrbiterE = ((aWandererI + RotL64(aCross, 19U)) + RotL64(aCarry, 13U)) + 6668118118775650387U;
            aOrbiterC = (aWandererC + RotL64(aPrevious, 27U)) + 15794200818099010989U;
            aOrbiterK = ((aWandererA + RotL64(aScatter, 36U)) + 6565076707062828369U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterD = ((aWandererK + RotL64(aPrevious, 39U)) + RotL64(aCarry, 43U)) + 16323164497808856719U;
            aOrbiterJ = (aWandererD + RotL64(aIngress, 21U)) + 7965435318816716560U;
            aOrbiterH = ((aWandererJ + RotL64(aCross, 13U)) + 7390281030573369017U) + aPhaseEOrbiterAssignSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = (aWandererG + RotL64(aScatter, 23U)) + 2269738866911824875U;
            aOrbiterB = ((aWandererB + RotL64(aIngress, 5U)) + 9664014216039993873U) + aNonceWordJ;
            aOrbiterA = (aWandererE + RotL64(aPrevious, 46U)) + 18284857398028357633U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 367667619795303009U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 7935945060956274197U;
            aOrbiterE = RotL64((aOrbiterE * 5481786693511955209U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 16683666162337789540U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 10655658270998102390U;
            aOrbiterG = RotL64((aOrbiterG * 15231596813382239841U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 8307037916581540297U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 3247742749860703524U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 15052136713218656641U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 10446792483683818139U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 16374602929344972364U;
            aOrbiterJ = RotL64((aOrbiterJ * 12599903932725787599U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 2411334498322777183U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 1093701164116833765U;
            aOrbiterI = RotL64((aOrbiterI * 13129220206835381729U), 57U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterC) + 17018480952982840635U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1]) + aNonceWordM;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 17348395690080029814U;
            aOrbiterF = RotL64((aOrbiterF * 6212591395713433257U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 16111252311283623152U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 12776492920397785951U;
            aOrbiterC = RotL64((aOrbiterC * 6136009241593081821U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 12214538600808144816U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 10043377462096783363U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 14639467375095185877U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 5101561512438055661U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 3683207847147603335U;
            aOrbiterH = RotL64((aOrbiterH * 14355438383379198639U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 14446947359104987749U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 7596096688268335354U;
            aOrbiterB = RotL64((aOrbiterB * 13522935803383107145U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 14015424109468938015U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 2915859148137000694U;
            aOrbiterA = RotL64((aOrbiterA * 3653144205211106817U), 5U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterK, 35U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 27U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 19U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 29U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 3U));
            aIngress = aIngress + RotL64(aOrbiterD, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 44U) + RotL64(aOrbiterK, 11U)) + aOrbiterC) + aNonceWordC);
            aWandererJ = aWandererJ + ((RotL64(aCross, 13U) + RotL64(aOrbiterI, 44U)) + aOrbiterD);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 41U) + aOrbiterI) + RotL64(aOrbiterE, 29U));
            aWandererH = aWandererH + ((RotL64(aScatter, 19U) + RotL64(aOrbiterF, 23U)) + aOrbiterK);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterD, 57U)) + aOrbiterA);
            aWandererD = aWandererD + ((((RotL64(aCross, 35U) + aOrbiterK) + RotL64(aOrbiterJ, 47U)) + RotL64(aCarry, 41U)) + aPhaseEWandererUpdateSaltB[((aIndex + 9U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 53U) + RotL64(aOrbiterB, 3U)) + aOrbiterG) + aNonceWordK);
            aWandererA = aWandererA + ((RotL64(aScatter, 29U) + RotL64(aOrbiterA, 21U)) + aOrbiterC);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterF, 50U)) + aOrbiterH) + aPhaseEWandererUpdateSaltC[((aIndex + 11U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aScatter, 47U) + RotL64(aOrbiterI, 39U)) + aOrbiterB) + RotL64(aCarry, 51U)) + aNonceWordD);
            aWandererG = aWandererG ^ ((RotL64(aCross, 50U) + aOrbiterK) + RotL64(aOrbiterH, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 60U) ^ aWandererE);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 57U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 5U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 51U));
            aCarry = aCarry + (RotL64(aWandererA, 19U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererF, 27U);
            aCarry = aCarry + RotL64(aIngress, 24U);
            aCarry = aCarry ^ aNonceWordN;
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 16363U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 11209U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 10979U)) & S_BLOCK1], 58U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 13901U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 53U) + RotL64(aCarry, 5U)) + (RotL64(aPrevious, 40U) ^ RotL64(aCross, 19U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterA = ((aWandererG + RotL64(aCross, 6U)) + 1866656689936219099U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterF = ((aWandererE + RotL64(aScatter, 27U)) + 2312314528139448289U) + aPhaseEOrbiterAssignSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = ((aWandererD + RotL64(aIngress, 37U)) + RotL64(aCarry, 27U)) + 3554037526469185237U;
            aOrbiterC = (aWandererK + RotL64(aPrevious, 41U)) + 405707755060974111U;
            aOrbiterB = (aWandererI + RotL64(aCross, 29U)) + 1862976326004007697U;
            aOrbiterE = (aWandererB + RotL64(aIngress, 47U)) + 12992483065443288263U;
            aOrbiterI = (aWandererJ + RotL64(aPrevious, 51U)) + 3793854946371595197U;
            aOrbiterK = (((aWandererC + RotL64(aScatter, 11U)) + RotL64(aCarry, 21U)) + 4244007978867369382U) + aNonceWordO;
            aOrbiterD = (aWandererH + RotL64(aPrevious, 3U)) + 10280867500312580308U;
            aOrbiterJ = (aWandererF + RotL64(aIngress, 34U)) + 472563452959164242U;
            aOrbiterG = ((aWandererA + RotL64(aCross, 39U)) + RotL64(aCarry, 43U)) + 12041770406895816553U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 6118634015704900486U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 13637107920449233307U) ^ aNonceWordN;
            aOrbiterH = RotL64((aOrbiterH * 17712028184714868053U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 16673735670669318830U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 8602681273646630496U;
            aOrbiterE = RotL64((aOrbiterE * 6995213887710749241U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 7683264695930369476U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 9146674871199188218U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7403427067419261981U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 3012935612827493084U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 1259789268731661945U;
            aOrbiterB = RotL64((aOrbiterB * 2372843620327050137U), 37U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 5623690455471160780U) + aNonceWordF;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 18355567776031865462U;
            aOrbiterK = RotL64((aOrbiterK * 9553862670107886679U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 7705134893833304792U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 4435192506444773834U) ^ aNonceWordI;
            aOrbiterJ = RotL64((aOrbiterJ * 5249651218395299501U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 6204683785806409075U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 17886971535016484255U;
            aOrbiterA = RotL64((aOrbiterA * 6047216474762933535U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 4430578901091376829U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 607557685798141547U;
            aOrbiterC = RotL64((aOrbiterC * 12342665567201483107U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 18258994761911545002U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 634391404805006992U;
            aOrbiterI = RotL64((aOrbiterI * 5761143438450180463U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 8528044138264666860U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 3867692060293315964U;
            aOrbiterD = RotL64((aOrbiterD * 8285164562893231087U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 8333438209201978886U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 1866656689936219099U;
            aOrbiterG = RotL64((aOrbiterG * 3935928308329865425U), 57U);
            //
            aIngress = RotL64(aOrbiterC, 21U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterB, 19U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 46U));
            aIngress = aIngress + (RotL64(aOrbiterA, 41U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterH, 37U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterD, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterE, 41U)) + aOrbiterH);
            aWandererC = aWandererC + ((RotL64(aScatter, 22U) + aOrbiterD) + RotL64(aOrbiterB, 46U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 3U) + aOrbiterA) + RotL64(aOrbiterD, 27U)) + aPhaseEWandererUpdateSaltD[((aIndex + 3U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aCross, 19U) + RotL64(aOrbiterI, 3U)) + aOrbiterH);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 37U) + RotL64(aOrbiterF, 21U)) + aOrbiterD) + aNonceWordH);
            aWandererE = aWandererE + (((RotL64(aIngress, 12U) + RotL64(aOrbiterK, 11U)) + aOrbiterH) + RotL64(aCarry, 27U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 39U) + aOrbiterH) + RotL64(aOrbiterB, 35U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 27U) + RotL64(aOrbiterA, 29U)) + aOrbiterJ) + RotL64(aCarry, 35U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterG, 51U)) + aOrbiterC);
            aWandererK = aWandererK + (((RotL64(aScatter, 43U) + aOrbiterC) + RotL64(aOrbiterB, 38U)) + aNonceWordM);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 5U) + aOrbiterG) + RotL64(aOrbiterJ, 43U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 3U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererI, 34U) ^ aWandererD);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 11U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 23U));
            aCarry = aCarry + (RotL64(aWandererH, 51U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererF, 37U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ (aNonceWordH ^ aNonceWordC);
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 19870U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneB[((aIndex + 16443U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 19366U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 17415U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCross, 57U)) ^ (RotL64(aCarry, 42U) ^ RotL64(aIngress, 19U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterB = ((aWandererD + RotL64(aPrevious, 18U)) + 8767379393098711499U) + aNonceWordH;
            aOrbiterD = (aWandererG + RotL64(aIngress, 11U)) + 7168159491580816433U;
            aOrbiterG = (aWandererC + RotL64(aCross, 39U)) + 9879279829061883406U;
            aOrbiterH = (aWandererH + RotL64(aScatter, 13U)) + 10537167136053399303U;
            aOrbiterI = (aWandererB + RotL64(aPrevious, 43U)) + 2839070018069188936U;
            aOrbiterC = (aWandererE + RotL64(aIngress, 37U)) + 13844278063968429732U;
            aOrbiterJ = ((aWandererA + RotL64(aCross, 57U)) + 11278946626186474646U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = ((aWandererJ + RotL64(aScatter, 50U)) + RotL64(aCarry, 3U)) + 11798425216660557799U;
            aOrbiterF = (((aWandererI + RotL64(aCross, 35U)) + RotL64(aCarry, 27U)) + 7618446090703335192U) + aNonceWordI;
            aOrbiterE = (aWandererF + RotL64(aScatter, 23U)) + 695423597006983660U;
            aOrbiterK = (((aWandererK + RotL64(aIngress, 5U)) + RotL64(aCarry, 35U)) + 14344728202803488813U) + aPhaseEOrbiterAssignSaltD[((aIndex + 9U)) & S_SALT1];
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 11656100506575697086U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 10384358779985773937U;
            aOrbiterG = RotL64((aOrbiterG * 247494692039140973U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 17585001605131977341U) + aNonceWordO;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 9964478171465522911U;
            aOrbiterI = RotL64((aOrbiterI * 13484044854790175315U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 2710943171829692624U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 17809072853457153057U;
            aOrbiterC = RotL64((aOrbiterC * 16341884203303271365U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 12814092033910687774U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 1743186323268668740U;
            aOrbiterJ = RotL64((aOrbiterJ * 11150822630624332557U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 10750472346626754704U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 15925901217078035356U;
            aOrbiterA = RotL64((aOrbiterA * 9276504171291801637U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 2569102106359362359U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 8868261301410769739U) ^ aNonceWordN;
            aOrbiterF = RotL64((aOrbiterF * 3662495603133918101U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 2143691008373582476U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 10606616796243205921U;
            aOrbiterE = RotL64((aOrbiterE * 15794414817813485643U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 16258070651850746855U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 11720192793689633315U;
            aOrbiterK = RotL64((aOrbiterK * 14475623219460678021U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 8230871037292355675U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 16898650748046368353U;
            aOrbiterB = RotL64((aOrbiterB * 7368697435476300255U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 9071122174426904737U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 4506737259011736474U;
            aOrbiterD = RotL64((aOrbiterD * 11903039808814842447U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 4545409671845718259U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 8767379393098711499U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 1210632171306946669U), 21U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterH, 39U);
            aIngress = aIngress + (RotL64(aOrbiterK, 47U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 35U));
            aIngress = aIngress + (RotL64(aOrbiterI, 21U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 14U));
            aIngress = aIngress + RotL64(aOrbiterC, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aScatter, 5U) + aOrbiterA) + RotL64(aOrbiterJ, 23U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterE, 47U)) + aOrbiterD);
            aWandererA = aWandererA + (((RotL64(aPrevious, 21U) + aOrbiterD) + RotL64(aOrbiterI, 51U)) + RotL64(aCarry, 47U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterI, 43U)) + aOrbiterC);
            aWandererJ = aWandererJ + ((RotL64(aCross, 57U) + aOrbiterF) + RotL64(aOrbiterI, 28U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 50U) + aOrbiterK) + RotL64(aOrbiterG, 11U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 23U) + aOrbiterA) + RotL64(aOrbiterB, 57U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 11U) + aOrbiterH) + RotL64(aOrbiterF, 53U)) + aNonceWordE);
            aWandererD = aWandererD + (((RotL64(aIngress, 13U) + RotL64(aOrbiterB, 60U)) + aOrbiterI) + RotL64(aCarry, 19U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 36U) + aOrbiterA) + RotL64(aOrbiterK, 39U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 27U) + aOrbiterB) + RotL64(aOrbiterD, 5U)) + aPhaseEWandererUpdateSaltA[((aIndex + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 53U));
            aCarry = aCarry + (RotL64(aWandererI, 3U) ^ aWandererB);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 28U));
            aCarry = aCarry + (RotL64(aWandererK, 39U) ^ aWandererD);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 41U));
            aCarry = aCarry + RotL64(aWandererF, 23U);
            aCarry = aCarry + RotL64(aIngress, 6U);
            aCarry = aCarry ^ aNonceWordB;
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 26086U)) & S_BLOCK1], 26U) ^ RotL64(aOperationLaneA[((aIndex + 24498U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 22513U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneA[((aIndex + 25790U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCross, 21U) ^ RotL64(aIngress, 53U)) + (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 36U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterI = ((aWandererJ + RotL64(aPrevious, 44U)) + RotL64(aCarry, 27U)) + 12980104182836602177U;
            aOrbiterF = (aWandererI + RotL64(aScatter, 3U)) + 3172622203188863995U;
            aOrbiterC = (aWandererE + RotL64(aIngress, 57U)) + 1170974132219980203U;
            aOrbiterA = ((aWandererC + RotL64(aCross, 13U)) + RotL64(aCarry, 53U)) + 6035201940965047490U;
            aOrbiterD = ((aWandererG + RotL64(aIngress, 6U)) + RotL64(aCarry, 21U)) + 18033907118424996722U;
            aOrbiterG = (aWandererB + RotL64(aScatter, 41U)) + 14604813424800580304U;
            aOrbiterB = ((aWandererA + RotL64(aCross, 39U)) + 13720232492851066035U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterH = (aWandererK + RotL64(aPrevious, 53U)) + 3902659710585257448U;
            aOrbiterE = ((aWandererD + RotL64(aIngress, 37U)) + 8331560652661619868U) + aNonceWordO;
            aOrbiterJ = (aWandererH + RotL64(aScatter, 23U)) + 4485014147538689794U;
            aOrbiterK = ((aWandererF + RotL64(aPrevious, 11U)) + 168202636924512424U) + aPhaseEOrbiterAssignSaltB[((aIndex + 21U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 16227825670092707848U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 4792781933944671365U;
            aOrbiterC = RotL64((aOrbiterC * 15859849676231455283U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 12636865372722601282U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 18198291399585556632U;
            aOrbiterG = RotL64((aOrbiterG * 18155803890313399795U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 3650053185419807206U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 5897288963905408776U;
            aOrbiterH = RotL64((aOrbiterH * 3706949366974086151U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 9922308113622901726U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 13352279749091561510U;
            aOrbiterJ = RotL64((aOrbiterJ * 4025213180483632557U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 14969461950939646117U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 10231661776135056651U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11284575051455238501U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 10621934544068320859U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 6029116920305246887U;
            aOrbiterA = RotL64((aOrbiterA * 6087523725059376905U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 12887482425168671195U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 8351351557123783853U) ^ aNonceWordP;
            aOrbiterB = RotL64((aOrbiterB * 3839381627914762245U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 5405938210926464973U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 385145802287899406U;
            aOrbiterE = RotL64((aOrbiterE * 8330751480464271445U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 7907749190875916461U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 5138733192253468642U;
            aOrbiterK = RotL64((aOrbiterK * 17028325976353263843U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 14382272868178763187U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 14354777100157531233U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7095764230272037767U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 4390647647193363824U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 12980104182836602177U;
            aOrbiterD = RotL64((aOrbiterD * 11124472075872147333U), 11U);
            //
            aIngress = RotL64(aOrbiterD, 56U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterF, 29U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 27U));
            aIngress = aIngress + (RotL64(aOrbiterC, 43U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterE, 11U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterG, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aIngress, 19U) + RotL64(aOrbiterF, 5U)) + aOrbiterA) + aNonceWordI);
            aWandererC = aWandererC + ((((RotL64(aScatter, 52U) + aOrbiterD) + RotL64(aOrbiterJ, 58U)) + aNonceWordJ) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterG, 43U)) + aOrbiterI);
            aWandererD = aWandererD + ((RotL64(aPrevious, 23U) + aOrbiterD) + RotL64(aOrbiterA, 13U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 41U) + aOrbiterC) + RotL64(aOrbiterG, 11U));
            aWandererE = aWandererE + (((RotL64(aCross, 13U) + aOrbiterI) + RotL64(aOrbiterK, 21U)) + RotL64(aCarry, 37U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 47U) + aOrbiterC) + RotL64(aOrbiterB, 50U));
            aWandererI = aWandererI + ((((RotL64(aPrevious, 43U) + RotL64(aOrbiterB, 39U)) + aOrbiterH) + RotL64(aCarry, 29U)) + aNonceWordB);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 50U) + aOrbiterB) + RotL64(aOrbiterE, 29U));
            aWandererH = aWandererH + (((RotL64(aScatter, 37U) + aOrbiterE) + RotL64(aOrbiterK, 35U)) + aPhaseEWandererUpdateSaltB[((aIndex + 14U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 21U) + aOrbiterA) + RotL64(aOrbiterK, 53U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 39U));
            aCarry = aCarry + (RotL64(aWandererJ, 51U) ^ aWandererI);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 41U));
            aCarry = aCarry + (RotL64(aWandererC, 58U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererH, 43U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererA, 23U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ (aNonceWordD ^ aNonceWordB);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 27544U)) & S_BLOCK1], 22U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28770U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 30320U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneB[((aIndex + 30151U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCross, 53U) + RotL64(aPrevious, 41U)) ^ (RotL64(aCarry, 22U) + RotL64(aIngress, 5U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterI = (aWandererC + RotL64(aIngress, 39U)) + 7948891781097675369U;
            aOrbiterD = ((aWandererH + RotL64(aCross, 57U)) + 13928362874228230226U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = (aWandererB + RotL64(aPrevious, 60U)) + 10776180542602258926U;
            aOrbiterJ = ((aWandererG + RotL64(aScatter, 29U)) + 5735115172149470447U) + aNonceWordC;
            aOrbiterA = ((aWandererF + RotL64(aCross, 53U)) + 5353591822981766987U) + aNonceWordK;
            aOrbiterK = ((aWandererA + RotL64(aScatter, 41U)) + 562301708107268570U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterF = ((aWandererI + RotL64(aPrevious, 5U)) + RotL64(aCarry, 47U)) + 10467810247578364868U;
            aOrbiterC = (((aWandererK + RotL64(aIngress, 51U)) + RotL64(aCarry, 35U)) + 14541630141152308564U) + aNonceWordF;
            aOrbiterB = (aWandererE + RotL64(aPrevious, 11U)) + 2350076897065139429U;
            aOrbiterE = (aWandererD + RotL64(aScatter, 3U)) + 17519109078651162228U;
            aOrbiterG = ((aWandererJ + RotL64(aCross, 26U)) + RotL64(aCarry, 53U)) + 6061035173339902910U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 15654836633731000065U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 13723521735153718904U;
            aOrbiterH = RotL64((aOrbiterH * 14459516479283070563U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 2849680038315532197U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 17336102435576647923U;
            aOrbiterA = RotL64((aOrbiterA * 10984689101753586739U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 7671010488872356142U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 11485114338165600777U;
            aOrbiterK = RotL64((aOrbiterK * 4162584865462407791U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 8759060657343458985U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 11009137869375286581U;
            aOrbiterF = RotL64((aOrbiterF * 8741417343929809115U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 15792999392743144135U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 6180808423175992479U;
            aOrbiterC = RotL64((aOrbiterC * 13681230339693676907U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 361487389591183005U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 15292753806514404853U;
            aOrbiterB = RotL64((aOrbiterB * 17478232597253311153U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 14929153438443362045U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 7904556383593914086U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 2484130486635511403U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 3793180909904286848U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 10391957637467171320U;
            aOrbiterG = RotL64((aOrbiterG * 505484041943467117U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 11648765065563798353U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 17601185776537566611U;
            aOrbiterI = RotL64((aOrbiterI * 4753179291885740011U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 2907499704986356444U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 17048858067202291241U) ^ aNonceWordI;
            aOrbiterD = RotL64((aOrbiterD * 2607549567999666889U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 4340465159886930775U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 7948891781097675369U;
            aOrbiterJ = RotL64((aOrbiterJ * 12913104720552907335U), 3U);
            //
            aIngress = RotL64(aOrbiterD, 37U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 52U));
            aIngress = aIngress + (RotL64(aOrbiterI, 47U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterF, 11U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterJ, 27U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterE, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aPrevious, 27U) + aOrbiterK) + RotL64(aOrbiterB, 39U));
            aWandererC = aWandererC ^ ((((RotL64(aCross, 51U) + aOrbiterH) + RotL64(aOrbiterI, 53U)) + aNonceWordL) + aPhaseEWandererUpdateSaltF[((aIndex + 9U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aIngress, 41U) + aOrbiterF) + RotL64(aOrbiterC, 51U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 29U) + aOrbiterC) + RotL64(aOrbiterH, 37U)) + aNonceWordB);
            aWandererE = aWandererE + (((((RotL64(aIngress, 4U) + RotL64(aOrbiterA, 48U)) + aOrbiterD) + RotL64(aCarry, 35U)) + aNonceWordO) + aPhaseEWandererUpdateSaltD[((aIndex + 20U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterI, 29U)) + aOrbiterA);
            aWandererB = aWandererB + ((RotL64(aPrevious, 19U) + aOrbiterF) + RotL64(aOrbiterB, 21U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 53U) + aOrbiterK) + RotL64(aOrbiterJ, 5U));
            aWandererI = aWandererI + (((RotL64(aCross, 39U) + aOrbiterG) + RotL64(aOrbiterC, 42U)) + RotL64(aCarry, 43U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 37U) + aOrbiterA) + RotL64(aOrbiterB, 11U));
            aWandererG = aWandererG + ((RotL64(aScatter, 56U) + aOrbiterD) + RotL64(aOrbiterE, 57U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 10U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererG, 41U) ^ aWandererH);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 19U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 43U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 36U));
            aCarry = aCarry + RotL64(aWandererK, 53U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xCA04CF3EF586D609ULL + 0xECC25C77D1F3C215ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x8EAE582C72EFFDB5ULL + 0xBA58FD857E0B016CULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xCFF1B1E0FCBEDFB1ULL + 0xDB2DF780E12AAF8DULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xE1BC27C1A602427BULL + 0xB50CCCC369DD1BF2ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xE4EDFF76922212E3ULL + 0xC1AFEDD90B5C3B11ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xABF8BB8E49254E01ULL + 0xCC4F67ED0D0FCF07ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xD7313D52B4B490E9ULL + 0x89DE6DF3E4BEBD73ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xE1334B416DAF5FE7ULL + 0x94FD26F29E10E002ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x8B002AB3D67331E3ULL + 0xE1AC1B8EA2C0CAD5ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xEFBAF075930A930BULL + 0xE1D8D4C3DE1F210DULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xC9D15E7A67EC03C9ULL + 0xCB72FF15807D4E93ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xB5313983409FCC37ULL + 0x954A752BC19096E8ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xDAE7D8EA8F95642FULL + 0xEF5C6FDC042C87CCULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xC174EA17080D4AB3ULL + 0xB1AEB4C1E6DB0686ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xF80CF48B05939B71ULL + 0x973BFF7E64845BB3ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xBE88CF7EA58CAD21ULL + 0xDF4DB74E0C73F4B8ULL);
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 362U)) & S_BLOCK1], 12U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 4198U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 4403U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 2909U)) & S_BLOCK1], 56U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 53U) + RotL64(aCross, 27U)) ^ (RotL64(aIngress, 5U) + RotL64(aCarry, 40U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterA = (aWandererI + RotL64(aScatter, 29U)) + 6381335981879993247U;
            aOrbiterC = ((aWandererD + RotL64(aCross, 27U)) + RotL64(aCarry, 11U)) + 15595429101600023172U;
            aOrbiterF = ((aWandererK + RotL64(aPrevious, 46U)) + 5449234297249826461U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = (aWandererF + RotL64(aIngress, 11U)) + 11213734849329731168U;
            aOrbiterG = ((aWandererG + RotL64(aPrevious, 41U)) + RotL64(aCarry, 53U)) + 16438473952464514248U;
            aOrbiterI = ((aWandererH + RotL64(aScatter, 39U)) + RotL64(aCarry, 39U)) + 7357872882115186976U;
            aOrbiterE = (aWandererC + RotL64(aIngress, 23U)) + 394402075160738643U;
            aOrbiterD = (((aWandererB + RotL64(aCross, 34U)) + 11112941985410283532U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 8U)) & S_SALT1]) + aNonceWordC;
            aOrbiterB = (aWandererE + RotL64(aScatter, 21U)) + 14955125011182736212U;
            aOrbiterK = (aWandererA + RotL64(aIngress, 3U)) + 14770727009821304070U;
            aOrbiterH = (aWandererJ + RotL64(aCross, 51U)) + 11286366598129204910U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 7358400908565425780U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 15635109923749114761U;
            aOrbiterF = RotL64((aOrbiterF * 12415152149408700329U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 13826842523738623579U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 1072811298828325231U;
            aOrbiterI = RotL64((aOrbiterI * 9662800288646215083U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 4017334196009350776U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 8812213572751410831U;
            aOrbiterA = RotL64((aOrbiterA * 12744171921566782795U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 6723457786170634403U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 9785583533999417673U;
            aOrbiterJ = RotL64((aOrbiterJ * 7776915427605471097U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 10265132640322153964U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 8435670887514808087U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 2706263045620662131U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 4303823386961718326U) + aNonceWordO;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 4214384238167491037U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 8490707334221154005U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 8740835037840799136U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 5988815405391206280U;
            aOrbiterH = RotL64((aOrbiterH * 17838555472135715929U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 15539461383052981747U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 3743772525784217714U;
            aOrbiterC = RotL64((aOrbiterC * 6352086797545969187U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 16283379107488103386U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 2677085736169305444U;
            aOrbiterG = RotL64((aOrbiterG * 5034373635279045467U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 16961352880910247821U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 7475807604144212417U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 5016987646810330727U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 10187131329357526073U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 6381335981879993247U;
            aOrbiterK = RotL64((aOrbiterK * 15277168748093112841U), 27U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterJ, 37U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 4U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 13U));
            aIngress = aIngress + (RotL64(aOrbiterG, 39U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterH, 53U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterF, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aIngress, 14U) + aOrbiterF) + RotL64(aOrbiterK, 39U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 37U) + RotL64(aOrbiterB, 27U)) + aOrbiterJ) + aPhaseFWandererUpdateSaltA[((aIndex + 25U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aCross, 43U) + RotL64(aOrbiterA, 21U)) + aOrbiterK) + RotL64(aCarry, 19U)) + aPhaseFWandererUpdateSaltF[((aIndex + 14U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 11U) + aOrbiterH) + RotL64(aOrbiterJ, 34U));
            aWandererI = aWandererI + ((RotL64(aIngress, 23U) + RotL64(aOrbiterC, 41U)) + aOrbiterB);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 52U) + RotL64(aOrbiterI, 51U)) + aOrbiterK);
            aWandererG = aWandererG + (((RotL64(aScatter, 29U) + aOrbiterJ) + RotL64(aOrbiterI, 23U)) + RotL64(aCarry, 41U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 41U) + aOrbiterC) + RotL64(aOrbiterI, 48U));
            aWandererH = aWandererH + ((RotL64(aPrevious, 39U) + aOrbiterG) + RotL64(aOrbiterD, 11U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 19U) + aOrbiterG) + RotL64(aOrbiterC, 37U)) + aNonceWordB);
            aWandererA = aWandererA + ((RotL64(aIngress, 35U) + RotL64(aOrbiterB, 29U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 13U));
            aCarry = aCarry + (RotL64(aWandererC, 21U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererF, 60U) ^ aWandererI);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 43U));
            aCarry = aCarry + (RotL64(aWandererK, 23U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererD, 47U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ aNonceWordF;
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 8644U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 6312U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 8607U)) & S_BLOCK1], 4U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 9121U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 28U) + RotL64(aCarry, 13U)) ^ (RotL64(aCross, 57U) ^ RotL64(aIngress, 43U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterF = ((aWandererK + RotL64(aPrevious, 19U)) + 18144572925667544139U) + aPhaseFOrbiterAssignSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterJ = (aWandererE + RotL64(aIngress, 23U)) + 5659758077574059728U;
            aOrbiterI = (aWandererH + RotL64(aScatter, 29U)) + 6343330616999166392U;
            aOrbiterB = ((aWandererB + RotL64(aCross, 11U)) + 17754639838410839447U) + aNonceWordJ;
            aOrbiterH = (aWandererF + RotL64(aScatter, 41U)) + 9451843819849581729U;
            aOrbiterC = ((aWandererC + RotL64(aPrevious, 60U)) + 7957854457197462212U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterA = ((aWandererA + RotL64(aIngress, 35U)) + RotL64(aCarry, 43U)) + 1461994799722205010U;
            aOrbiterE = ((aWandererG + RotL64(aCross, 5U)) + RotL64(aCarry, 53U)) + 18002214276252170177U;
            aOrbiterK = (aWandererI + RotL64(aIngress, 3U)) + 14689869073147027164U;
            aOrbiterD = ((aWandererJ + RotL64(aPrevious, 54U)) + RotL64(aCarry, 23U)) + 3978104368003440293U;
            aOrbiterG = (aWandererD + RotL64(aCross, 37U)) + 8512135845221335386U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 1477533446382953439U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 2166717790929947990U;
            aOrbiterI = RotL64((aOrbiterI * 6538884492418324461U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 8082437060686606995U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 4363687722464700362U;
            aOrbiterJ = RotL64((aOrbiterJ * 7199165810993478887U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 15782763348014924206U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 8572509150015960728U;
            aOrbiterH = RotL64((aOrbiterH * 3340528604891897779U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 12248271773316742521U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 9602078627638561949U;
            aOrbiterA = RotL64((aOrbiterA * 1860631869877427405U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 17244849374768558859U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 1030743048280579012U) ^ aNonceWordO;
            aOrbiterK = RotL64((aOrbiterK * 10858949914285817051U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 17722342363541914280U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 15667504059789880034U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 15872269872168533709U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 12645332941998550794U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 9938135244509986497U;
            aOrbiterB = RotL64((aOrbiterB * 16548185968987392957U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 4024609904162105979U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 6732064218696157303U;
            aOrbiterC = RotL64((aOrbiterC * 3815409766145891393U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 14314117137220703583U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 15244765904057473814U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4034571710808047959U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 17441241682018169245U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 11958974379114644873U;
            aOrbiterD = RotL64((aOrbiterD * 11315689206845170303U), 57U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterI) + 8310839846793796473U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordE;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 18144572925667544139U;
            aOrbiterG = RotL64((aOrbiterG * 11668203295511168011U), 37U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterA, 38U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 53U));
            aIngress = aIngress + (RotL64(aOrbiterE, 13U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterB, 43U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterD, 47U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterJ, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterJ, 10U)) + aOrbiterE) + aNonceWordH);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterJ, 23U)) + aOrbiterC);
            aWandererG = aWandererG + ((RotL64(aCross, 12U) + aOrbiterB) + RotL64(aOrbiterG, 39U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 41U) + aOrbiterJ) + RotL64(aOrbiterI, 41U));
            aWandererI = aWandererI + (((RotL64(aScatter, 53U) + aOrbiterA) + RotL64(aOrbiterE, 21U)) + RotL64(aCarry, 57U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterD, 3U)) + aOrbiterB);
            aWandererD = aWandererD + ((((RotL64(aCross, 39U) + RotL64(aOrbiterG, 48U)) + aOrbiterD) + RotL64(aCarry, 37U)) + aPhaseFWandererUpdateSaltD[((aIndex + 28U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 47U) + RotL64(aOrbiterK, 27U)) + aOrbiterE) + aNonceWordL);
            aWandererJ = aWandererJ + (((RotL64(aCross, 29U) + aOrbiterF) + RotL64(aOrbiterK, 29U)) + aNonceWordN);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 6U) + aOrbiterC) + RotL64(aOrbiterA, 43U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aPrevious, 51U) + aOrbiterF) + RotL64(aOrbiterH, 53U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 44U));
            aCarry = aCarry + (RotL64(aWandererE, 37U) ^ aWandererH);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 5U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 21U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 41U));
            aCarry = aCarry + RotL64(aWandererG, 39U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = aCarry ^ aNonceWordH;
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 14110U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 15521U)) & S_BLOCK1], 54U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 13530U)) & S_BLOCK1], 20U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 14358U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 18U) + RotL64(aCross, 37U)) + (RotL64(aCarry, 53U) ^ RotL64(aIngress, 5U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterB = ((aWandererA + RotL64(aScatter, 6U)) + 6318740973868639425U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = (aWandererB + RotL64(aIngress, 29U)) + 5487840061430920881U;
            aOrbiterI = (aWandererI + RotL64(aPrevious, 11U)) + 10258706763248072672U;
            aOrbiterF = (aWandererK + RotL64(aCross, 53U)) + 18356875269730338208U;
            aOrbiterD = (((aWandererH + RotL64(aPrevious, 43U)) + RotL64(aCarry, 27U)) + 12883160282903147010U) + aNonceWordK;
            aOrbiterE = ((aWandererF + RotL64(aIngress, 56U)) + RotL64(aCarry, 5U)) + 1010140474942697730U;
            aOrbiterA = (aWandererE + RotL64(aScatter, 23U)) + 17733939421700898293U;
            aOrbiterJ = ((aWandererG + RotL64(aCross, 21U)) + RotL64(aCarry, 47U)) + 13693055887924981201U;
            aOrbiterC = (aWandererC + RotL64(aIngress, 39U)) + 14574732452793385269U;
            aOrbiterK = (aWandererJ + RotL64(aScatter, 35U)) + 10832873941223609012U;
            aOrbiterH = ((aWandererD + RotL64(aPrevious, 13U)) + 8212600587135328040U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 5312744319781971178U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 6173741211706546923U;
            aOrbiterI = RotL64((aOrbiterI * 12854414066390848249U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 3693249147883790810U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 18365859989736602556U;
            aOrbiterE = RotL64((aOrbiterE * 3348463719324104997U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 10645056678337549771U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 1175668356822251045U;
            aOrbiterG = RotL64((aOrbiterG * 6579675292775345579U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 13556844570541823717U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 4790355739411849736U;
            aOrbiterD = RotL64((aOrbiterD * 4083544011788850307U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 14905575502272644116U) + aNonceWordD;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 17047244574558476634U;
            aOrbiterJ = RotL64((aOrbiterJ * 2356386971503880047U), 21U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 10161614295718414869U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = (((aOrbiterK ^ aOrbiterI) ^ 13413914082651612468U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterK = RotL64((aOrbiterK * 16224039093981079491U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 6072693130156927774U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 4333656233793103787U;
            aOrbiterB = RotL64((aOrbiterB * 9374745547133955709U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 17209776289202130250U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 11752001118070361543U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4416523594812872339U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 15367365111105608277U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 8650687767097460704U;
            aOrbiterA = RotL64((aOrbiterA * 11430451559660578667U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 18074648514448405693U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 10857586858462237581U;
            aOrbiterC = RotL64((aOrbiterC * 3722891011080095849U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 17219932344278345591U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 6318740973868639425U;
            aOrbiterH = RotL64((aOrbiterH * 8846295038878812229U), 51U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterJ, 41U);
            aIngress = aIngress + (RotL64(aOrbiterE, 21U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 47U));
            aIngress = aIngress + (RotL64(aOrbiterI, 3U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterG, 10U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterD, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aCross, 23U) + aOrbiterC) + RotL64(aOrbiterK, 13U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterH, 4U)) + aOrbiterF) + aNonceWordO);
            aWandererG = aWandererG + (((RotL64(aScatter, 21U) + aOrbiterD) + RotL64(aOrbiterC, 21U)) + RotL64(aCarry, 29U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 27U) + aOrbiterG) + RotL64(aOrbiterD, 11U));
            aWandererA = aWandererA + ((RotL64(aIngress, 52U) + aOrbiterB) + RotL64(aOrbiterF, 35U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 41U) + aOrbiterI) + RotL64(aOrbiterJ, 19U));
            aWandererF = aWandererF + ((((RotL64(aCross, 35U) + RotL64(aOrbiterF, 23U)) + aOrbiterI) + RotL64(aCarry, 19U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 3U) + aOrbiterB) + RotL64(aOrbiterG, 47U));
            aWandererJ = aWandererJ + ((RotL64(aCross, 14U) + RotL64(aOrbiterA, 37U)) + aOrbiterK);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 39U) + RotL64(aOrbiterI, 53U)) + aOrbiterE) + aPhaseFWandererUpdateSaltE[((aIndex + 29U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aIngress, 29U) + aOrbiterJ) + RotL64(aOrbiterE, 6U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 37U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 34U));
            aCarry = aCarry + (RotL64(aWandererG, 21U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererE, 27U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererI, 53U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererC, 47U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ aNonceWordO;
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 17801U)) & S_BLOCK1], 18U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 20485U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16841U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 19605U)) & S_BLOCK1], 14U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 53U) + RotL64(aCarry, 21U)) ^ (RotL64(aPrevious, 6U) ^ RotL64(aCross, 39U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterC = (aWandererC + RotL64(aIngress, 5U)) + 3339283916456813609U;
            aOrbiterI = (((aWandererB + RotL64(aScatter, 21U)) + RotL64(aCarry, 41U)) + 11339086426180649584U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterH = ((aWandererH + RotL64(aCross, 57U)) + 16819191669329316585U) + aNonceWordL;
            aOrbiterG = (aWandererK + RotL64(aPrevious, 53U)) + 8361916937762630725U;
            aOrbiterB = ((aWandererF + RotL64(aIngress, 19U)) + 18031328374429899857U) + aPhaseFOrbiterAssignSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = (aWandererI + RotL64(aScatter, 42U)) + 18261756894092897276U;
            aOrbiterJ = ((aWandererG + RotL64(aPrevious, 29U)) + 4250319792907645666U) + aNonceWordJ;
            aOrbiterA = ((aWandererJ + RotL64(aCross, 11U)) + RotL64(aCarry, 57U)) + 1492411503643460886U;
            aOrbiterD = ((aWandererD + RotL64(aPrevious, 23U)) + RotL64(aCarry, 37U)) + 17369549067879344180U;
            aOrbiterF = (aWandererE + RotL64(aCross, 40U)) + 7301713524358676722U;
            aOrbiterE = (aWandererA + RotL64(aIngress, 37U)) + 2985193736033012535U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 14086975808140927408U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 10390516547834639800U;
            aOrbiterH = RotL64((aOrbiterH * 11441293212275890819U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 18205555540941493267U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 16967799565443938873U;
            aOrbiterB = RotL64((aOrbiterB * 3009081009044782443U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 9209505304067579944U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 3522631966146762306U;
            aOrbiterK = RotL64((aOrbiterK * 3441982898533162599U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 8811497120829041188U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 14707301680850257294U;
            aOrbiterJ = RotL64((aOrbiterJ * 11383709499376464085U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 10080595991787801029U) + aNonceWordF;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 6822892187784299166U;
            aOrbiterA = RotL64((aOrbiterA * 7417016898027778287U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 1981637172055758689U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 16463077485583119324U;
            aOrbiterD = RotL64((aOrbiterD * 2876782050665869121U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 8383837717361569465U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 2788511294985017326U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2809163242875130677U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 3529607472855930041U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 8850940802020173766U;
            aOrbiterE = RotL64((aOrbiterE * 7821450253655655943U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 7469160295100147267U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 16973986572163482061U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 15660743778376905023U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 12371372942863279718U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 12098525148034303633U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11234127652230231751U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 5138683482859889480U) + aNonceWordN;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 3339283916456813609U) ^ aNonceWordK;
            aOrbiterG = RotL64((aOrbiterG * 10975353228235695455U), 37U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterK, 29U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 23U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 51U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterG, 5U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 26U));
            aIngress = aIngress + RotL64(aOrbiterI, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aPrevious, 19U) + RotL64(aOrbiterF, 57U)) + aOrbiterH) + RotL64(aCarry, 3U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 23U) + RotL64(aOrbiterJ, 23U)) + aOrbiterF) + aPhaseFWandererUpdateSaltF[((aIndex + 18U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 5U) + RotL64(aOrbiterE, 41U)) + aOrbiterK) + RotL64(aCarry, 35U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterE, 39U)) + aOrbiterG);
            aWandererE = aWandererE + ((RotL64(aIngress, 3U) + RotL64(aOrbiterG, 30U)) + aOrbiterF);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 38U) + RotL64(aOrbiterB, 47U)) + aOrbiterF);
            aWandererB = aWandererB + (((RotL64(aCross, 57U) + aOrbiterD) + RotL64(aOrbiterI, 43U)) + aNonceWordG);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterK, 19U)) + aOrbiterI);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 27U) + RotL64(aOrbiterC, 13U)) + aOrbiterJ);
            aWandererF = aWandererF ^ ((RotL64(aCross, 44U) + aOrbiterD) + RotL64(aOrbiterF, 3U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterA, 50U)) + aOrbiterJ) + aNonceWordE);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 52U));
            aCarry = aCarry + (RotL64(aWandererI, 29U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererA, 21U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererH, 5U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererJ, 54U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererK, 41U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ aNonceWordD;
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 24059U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 26067U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26474U)) & S_BLOCK1], 20U) ^ RotL64(aWorkLaneA[((aIndex + 22239U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 53U) + RotL64(aIngress, 38U)) ^ (RotL64(aCross, 23U) ^ RotL64(aPrevious, 5U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterA = (aWandererH + RotL64(aPrevious, 10U)) + 6361545377408870615U;
            aOrbiterC = (aWandererE + RotL64(aIngress, 21U)) + 2967245486744774933U;
            aOrbiterB = (aWandererI + RotL64(aScatter, 51U)) + 3836634268482850139U;
            aOrbiterE = ((aWandererB + RotL64(aCross, 13U)) + RotL64(aCarry, 41U)) + 7691642115360086297U;
            aOrbiterI = ((aWandererG + RotL64(aPrevious, 27U)) + RotL64(aCarry, 21U)) + 16479280384178279281U;
            aOrbiterJ = ((aWandererF + RotL64(aIngress, 5U)) + RotL64(aCarry, 51U)) + 2901468732552539249U;
            aOrbiterK = ((aWandererJ + RotL64(aCross, 41U)) + 2600353867755647475U) + aPhaseFOrbiterAssignSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = (aWandererD + RotL64(aScatter, 39U)) + 5666596904781510956U;
            aOrbiterD = (aWandererK + RotL64(aPrevious, 19U)) + 16108791609267427553U;
            aOrbiterF = ((aWandererA + RotL64(aScatter, 36U)) + 8389926875737312112U) + aNonceWordJ;
            aOrbiterH = ((aWandererC + RotL64(aCross, 57U)) + 1689501721163024426U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 11721701506949917719U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 3963842745030140473U;
            aOrbiterB = RotL64((aOrbiterB * 6692473494944919373U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 8510538243472109368U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 18281865214102080387U;
            aOrbiterJ = RotL64((aOrbiterJ * 1351546966368884609U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 2259725140963665123U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 11652011949557979650U;
            aOrbiterG = RotL64((aOrbiterG * 11260100762113295037U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 1116085424226174473U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 4725260319270802912U;
            aOrbiterF = RotL64((aOrbiterF * 4697109059565450269U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 7348945429843437036U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 1249234309180653260U;
            aOrbiterA = RotL64((aOrbiterA * 3136745255820405881U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 12463505532573389603U) + aNonceWordP;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 2304125977906510386U;
            aOrbiterE = RotL64((aOrbiterE * 9960816714791454421U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 2178037443783425551U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 11712110130079307683U) ^ aNonceWordD;
            aOrbiterK = RotL64((aOrbiterK * 9797864956200779505U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 10703510612147312252U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 18155460326242413483U;
            aOrbiterD = RotL64((aOrbiterD * 6903953708987478723U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 5753486645345036069U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 2314216774606770444U;
            aOrbiterH = RotL64((aOrbiterH * 14002639533287566667U), 41U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 9662599462788305323U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 3805101172359199209U;
            aOrbiterC = RotL64((aOrbiterC * 10669315962181581543U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 1073926575064224947U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 6361545377408870615U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 10685650563722188837U), 57U);
            //
            aIngress = RotL64(aOrbiterI, 39U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterF, 23U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 58U));
            aIngress = aIngress + (RotL64(aOrbiterB, 5U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 47U));
            aIngress = aIngress + RotL64(aOrbiterK, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aCross, 39U) + aOrbiterF) + RotL64(aOrbiterG, 43U));
            aWandererH = aWandererH + ((RotL64(aIngress, 19U) + aOrbiterA) + RotL64(aOrbiterE, 11U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 11U) + aOrbiterH) + RotL64(aOrbiterG, 5U));
            aWandererA = aWandererA + (((RotL64(aScatter, 30U) + RotL64(aOrbiterC, 30U)) + aOrbiterE) + RotL64(aCarry, 19U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterD, 3U)) + aOrbiterJ);
            aWandererD = aWandererD + ((RotL64(aIngress, 3U) + aOrbiterI) + RotL64(aOrbiterC, 23U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 43U) + RotL64(aOrbiterJ, 19U)) + aOrbiterE) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 5U) + aOrbiterE) + RotL64(aOrbiterH, 60U)) + aNonceWordB);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterB, 57U)) + aOrbiterD);
            aWandererJ = aWandererJ + (((RotL64(aCross, 21U) + RotL64(aOrbiterG, 53U)) + aOrbiterK) + RotL64(aCarry, 43U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 60U) + RotL64(aOrbiterB, 51U)) + aOrbiterE) + aPhaseFWandererUpdateSaltB[((aIndex + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 11U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 58U));
            aCarry = aCarry + (RotL64(aWandererG, 37U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererH, 35U) ^ aWandererK);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 53U));
            aCarry = aCarry + RotL64(aWandererF, 13U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ aNonceWordH;
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 31821U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneB[((aIndex + 29899U)) & S_BLOCK1], 6U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29376U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneB[((aIndex + 28261U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 37U) + RotL64(aIngress, 5U)) + (RotL64(aCross, 18U) ^ RotL64(aPrevious, 57U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterH = ((((aWandererC + RotL64(aIngress, 23U)) + RotL64(aCarry, 27U)) + 6521330037475130256U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordF;
            aOrbiterI = ((aWandererG + RotL64(aCross, 19U)) + RotL64(aCarry, 23U)) + 12611880456055428940U;
            aOrbiterD = (aWandererD + RotL64(aScatter, 47U)) + 12061611078130934708U;
            aOrbiterA = (aWandererA + RotL64(aPrevious, 34U)) + 1558112410801116984U;
            aOrbiterC = ((aWandererE + RotL64(aScatter, 5U)) + RotL64(aCarry, 5U)) + 10509115227850160786U;
            aOrbiterE = (aWandererI + RotL64(aPrevious, 11U)) + 4045915960688792066U;
            aOrbiterK = (aWandererJ + RotL64(aIngress, 37U)) + 1196541286513243082U;
            aOrbiterF = ((aWandererH + RotL64(aCross, 41U)) + 15564991032722373702U) + aPhaseFOrbiterAssignSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = (aWandererF + RotL64(aScatter, 56U)) + 4897765238703641798U;
            aOrbiterJ = (aWandererK + RotL64(aCross, 53U)) + 12327429514907752733U;
            aOrbiterG = (aWandererB + RotL64(aIngress, 27U)) + 6189189797708711636U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 6374267075282018852U) + aNonceWordM;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 1888758503831341439U) ^ aNonceWordD;
            aOrbiterD = RotL64((aOrbiterD * 74387714918264257U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 14956857689299491800U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 14879361107223331957U;
            aOrbiterC = RotL64((aOrbiterC * 9166712966729591953U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 16086885494838105042U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 8069724185844303923U;
            aOrbiterE = RotL64((aOrbiterE * 8878470736758734353U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 10854345917959911439U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 7078313614360332089U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 9864025732292844871U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 15083669236062255011U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 594879695916679116U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 9852515479152735283U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 6721466068234534523U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 475816724162626782U;
            aOrbiterB = RotL64((aOrbiterB * 4799725182757588407U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 4341655358154605899U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 15477254302340298586U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13961520225881974201U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 10179091913200895775U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 6310490897546909571U;
            aOrbiterG = RotL64((aOrbiterG * 15080621088825477613U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 13462682513035460711U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 16739138858084100385U;
            aOrbiterH = RotL64((aOrbiterH * 16386371811268298031U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 13608837667062268989U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 12902415667552110103U;
            aOrbiterI = RotL64((aOrbiterI * 16398790854093048017U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 16596211634603915761U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 6521330037475130256U;
            aOrbiterA = RotL64((aOrbiterA * 631958426544321145U), 11U);
            //
            aIngress = RotL64(aOrbiterF, 57U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 13U));
            aIngress = aIngress + (RotL64(aOrbiterB, 53U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 5U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 38U));
            aIngress = aIngress + RotL64(aOrbiterD, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aIngress, 3U) + RotL64(aOrbiterK, 57U)) + aOrbiterJ) + RotL64(aCarry, 5U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterG, 53U)) + aOrbiterK);
            aWandererB = aWandererB + ((RotL64(aScatter, 30U) + aOrbiterE) + RotL64(aOrbiterK, 44U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterD, 29U)) + aOrbiterB);
            aWandererI = aWandererI + (((RotL64(aScatter, 13U) + RotL64(aOrbiterI, 21U)) + aOrbiterA) + RotL64(aCarry, 53U));
            aWandererD = aWandererD ^ ((((RotL64(aCross, 37U) + aOrbiterF) + RotL64(aOrbiterD, 3U)) + aNonceWordJ) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aPrevious, 20U) + RotL64(aOrbiterG, 39U)) + aOrbiterA);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterJ, 12U)) + aOrbiterC);
            aWandererG = aWandererG + (((RotL64(aCross, 11U) + aOrbiterB) + RotL64(aOrbiterI, 5U)) + aNonceWordL);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 27U) + aOrbiterH) + RotL64(aOrbiterG, 19U)) + aNonceWordB);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 53U) + aOrbiterH) + RotL64(aOrbiterB, 35U)) + aPhaseFWandererUpdateSaltC[((aIndex + 26U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 24U) ^ aWandererH);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 37U));
            aCarry = aCarry + (RotL64(aWandererK, 35U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererD, 41U) ^ aWandererE);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 53U));
            aCarry = aCarry + RotL64(aWandererI, 39U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ (aNonceWordM ^ aNonceWordD);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xA7A8B01C5CAA61BDULL + 0x81C5DF97A450C196ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xE0C8457B7E6BEE43ULL + 0xB065BFF2EBCB76DFULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xBDE7B262A70CA133ULL + 0xB730AFD1D3583690ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x874339C2260C1751ULL + 0xBBB06102C3AFDAB6ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x9FE8684133AF805BULL + 0xF50CA2B20EDFC939ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x9E30763C999F5497ULL + 0xF78923E0A1A245ADULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xE99620727B786673ULL + 0xDF7CAEF43E90AF4AULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xACF9AAE15AAAFC4DULL + 0xC2EFAEBE8E291F4BULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xE7838DDC3EF7FB0DULL + 0xFA670EACAFED40ACULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xD045738C8536F301ULL + 0xC378131572C93E42ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xD84A962817EDB837ULL + 0xB7959B66AD8AB971ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0x923835C8ED44FABFULL + 0xD7D1466BD00550B4ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xF685618BD1ECF097ULL + 0x95731BF539F9C96CULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xBDAA3D6A1D8750D1ULL + 0xDD62A3EBEA7BC53AULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xFBF0A14B4FF6F09BULL + 0xE41EBC13FDE31E09ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xED2E4D8F67ADE567ULL + 0xAA72A72EE045EAFEULL);
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 2314U)) & S_BLOCK1], 56U) ^ RotL64(aWorkLaneC[((aIndex + 2678U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 1327U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneA[((aIndex + 434U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 40U) ^ RotL64(aIngress, 53U)) + (RotL64(aCross, 27U) + RotL64(aPrevious, 3U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterJ = ((aWandererD + RotL64(aIngress, 39U)) + RotL64(aCarry, 35U)) + 1898718075389870739U;
            aOrbiterC = ((aWandererH + RotL64(aPrevious, 51U)) + 5631794889237247403U) + aNonceWordB;
            aOrbiterD = (aWandererE + RotL64(aCross, 6U)) + 18219714659484524607U;
            aOrbiterG = (aWandererG + RotL64(aScatter, 53U)) + 15419581386225732921U;
            aOrbiterB = ((aWandererB + RotL64(aIngress, 35U)) + 9125575431710198210U) + aPhaseFOrbiterAssignSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterH = (aWandererA + RotL64(aCross, 27U)) + 12205871520544965505U;
            aOrbiterA = ((aWandererJ + RotL64(aPrevious, 11U)) + RotL64(aCarry, 21U)) + 7617534300497343422U;
            aOrbiterK = ((aWandererC + RotL64(aScatter, 43U)) + RotL64(aCarry, 27U)) + 18017579105368135814U;
            aOrbiterE = ((aWandererK + RotL64(aCross, 14U)) + 10693882161946020042U) + aPhaseFOrbiterAssignSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterI = (aWandererF + RotL64(aPrevious, 37U)) + 11669615701700895306U;
            aOrbiterF = (aWandererI + RotL64(aIngress, 57U)) + 11045110212889232165U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 18019107802806469913U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 12315940560472528716U;
            aOrbiterD = RotL64((aOrbiterD * 4505122470351404065U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 4899009736070044310U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 17412253404253730364U;
            aOrbiterH = RotL64((aOrbiterH * 10791901166391946485U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 4826286251927854181U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 4523455921321845084U;
            aOrbiterJ = RotL64((aOrbiterJ * 14534103906736598099U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 4132514462154182215U) + aNonceWordK;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 7164745605985109269U) ^ aNonceWordD;
            aOrbiterG = RotL64((aOrbiterG * 14107325508977225261U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 6297434295807635654U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 8813887638672996646U;
            aOrbiterA = RotL64((aOrbiterA * 17495632530773158201U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 11086381278955626084U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 5660733992573928887U;
            aOrbiterE = RotL64((aOrbiterE * 11248164458720777889U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 14851044686208609882U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 12707776386060264479U;
            aOrbiterF = RotL64((aOrbiterF * 4470919091467313071U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 11508023384209716657U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 11752973809740920034U;
            aOrbiterC = RotL64((aOrbiterC * 10212754472298834769U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 16746821150860017820U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 9659421716296641396U;
            aOrbiterB = RotL64((aOrbiterB * 7530071874978553673U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 3192309064305104593U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 11409078048681398061U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 14991409124701807765U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 315359495275427324U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 1898718075389870739U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 13126661894614781343U), 51U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterE, 3U);
            aIngress = aIngress + (RotL64(aOrbiterB, 51U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterD, 58U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterG, 35U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterI, 53U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterH, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aIngress, 46U) + aOrbiterE) + RotL64(aOrbiterI, 51U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterB, 27U)) + aOrbiterF) + aPhaseFWandererUpdateSaltE[((aIndex + 20U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterD, 35U)) + aOrbiterK) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aCross, 5U) + RotL64(aOrbiterF, 11U)) + aOrbiterC);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterJ, 3U)) + aOrbiterC);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 3U) + aOrbiterJ) + RotL64(aOrbiterF, 47U)) + RotL64(aCarry, 51U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterG, 24U)) + aOrbiterA);
            aWandererC = aWandererC + (((RotL64(aCross, 18U) + RotL64(aOrbiterI, 21U)) + aOrbiterG) + RotL64(aCarry, 47U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 35U) + aOrbiterD) + RotL64(aOrbiterE, 29U)) + aNonceWordE);
            aWandererH = aWandererH + ((RotL64(aPrevious, 23U) + RotL64(aOrbiterH, 19U)) + aOrbiterC);
            aWandererE = aWandererE ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterE, 56U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererC, 26U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererA, 53U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererI, 19U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererK, 51U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererD, 14U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererJ, 57U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ aNonceWordO;
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 8265U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 6161U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 6229U)) & S_BLOCK1], 36U) ^ RotL64(aWorkLaneB[((aIndex + 8568U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 53U) + RotL64(aIngress, 3U)) + (RotL64(aCarry, 20U) ^ RotL64(aPrevious, 39U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterE = ((aWandererD + RotL64(aPrevious, 5U)) + RotL64(aCarry, 29U)) + 3550722402315312207U;
            aOrbiterJ = (aWandererB + RotL64(aIngress, 47U)) + 16724184551669522754U;
            aOrbiterD = ((aWandererH + RotL64(aCross, 34U)) + 981751330116773021U) + aPhaseFOrbiterAssignSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterB = (aWandererA + RotL64(aScatter, 3U)) + 7891159229704944868U;
            aOrbiterA = ((aWandererF + RotL64(aCross, 51U)) + RotL64(aCarry, 41U)) + 13618396711464799841U;
            aOrbiterC = ((aWandererI + RotL64(aIngress, 43U)) + 5969291018449003648U) + aNonceWordE;
            aOrbiterI = (aWandererG + RotL64(aPrevious, 19U)) + 14595540413313640042U;
            aOrbiterH = ((aWandererK + RotL64(aScatter, 29U)) + RotL64(aCarry, 37U)) + 3287990436916111762U;
            aOrbiterK = ((aWandererJ + RotL64(aPrevious, 23U)) + 12534369400200483704U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = (aWandererC + RotL64(aCross, 38U)) + 2277312067930392274U;
            aOrbiterF = (aWandererE + RotL64(aScatter, 21U)) + 10026320559261334353U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 11258082063135659551U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 1445958517675746990U;
            aOrbiterD = RotL64((aOrbiterD * 10062265337488757971U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 1011298251290970844U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 6487834862470043744U;
            aOrbiterJ = RotL64((aOrbiterJ * 15477913837027179675U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 9966279022928268335U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 10285993486057704393U;
            aOrbiterA = RotL64((aOrbiterA * 15965714363201157535U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 16005362468813966136U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 223843444699390781U;
            aOrbiterI = RotL64((aOrbiterI * 665392038954573081U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 18178876294968532775U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 12490136112181806806U;
            aOrbiterK = RotL64((aOrbiterK * 16380841616662993709U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 8775696166557913635U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 16464340319444310842U) ^ aNonceWordC;
            aOrbiterE = RotL64((aOrbiterE * 18111632334728200721U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 6296039992673546227U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 7152939277656436037U;
            aOrbiterB = RotL64((aOrbiterB * 15183918431501487319U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 14066791413416223271U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 5026743227399908016U;
            aOrbiterC = RotL64((aOrbiterC * 5891343232759075675U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 12923870516588764609U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 2509970166609982397U;
            aOrbiterH = RotL64((aOrbiterH * 10708677957633925007U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 15155802288437422950U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 15615656627428205711U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 6199439196177598589U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 17233751123865498186U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 3550722402315312207U;
            aOrbiterF = RotL64((aOrbiterF * 2247546626523919155U), 3U);
            //
            aIngress = RotL64(aOrbiterH, 51U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterG, 5U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterB, 23U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 47U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 26U));
            aIngress = aIngress + RotL64(aOrbiterK, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterB, 60U)) + aOrbiterE);
            aWandererG = aWandererG + ((((RotL64(aScatter, 57U) + RotL64(aOrbiterJ, 23U)) + aOrbiterE) + RotL64(aCarry, 53U)) + aPhaseFWandererUpdateSaltA[((aIndex + 5U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 54U) + RotL64(aOrbiterG, 47U)) + aOrbiterK);
            aWandererH = aWandererH + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterI, 39U)) + aOrbiterH) + RotL64(aCarry, 5U));
            aWandererE = aWandererE ^ ((((RotL64(aIngress, 5U) + aOrbiterK) + RotL64(aOrbiterF, 51U)) + aNonceWordP) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aCross, 35U) + RotL64(aOrbiterA, 37U)) + aOrbiterJ);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 40U) + RotL64(aOrbiterE, 3U)) + aOrbiterD);
            aWandererA = aWandererA + (((RotL64(aPrevious, 47U) + aOrbiterH) + RotL64(aOrbiterK, 11U)) + aNonceWordB);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 43U) + aOrbiterJ) + RotL64(aOrbiterC, 54U));
            aWandererI = aWandererI + ((RotL64(aCross, 3U) + RotL64(aOrbiterI, 13U)) + aOrbiterC);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterJ, 57U)) + aOrbiterH);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 10U));
            aCarry = aCarry + (RotL64(aWandererK, 51U) ^ aWandererE);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 29U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 13U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 34U));
            aCarry = aCarry + RotL64(aWandererI, 3U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = aCarry ^ (aNonceWordF ^ aNonceWordP);
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 14349U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneA[((aIndex + 12167U)) & S_BLOCK1], 60U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 15130U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 11530U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 53U) ^ RotL64(aPrevious, 27U)) ^ (RotL64(aIngress, 14U) + RotL64(aCross, 39U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterD = (aWandererA + RotL64(aCross, 37U)) + 8367680518550579791U;
            aOrbiterK = (aWandererF + RotL64(aPrevious, 54U)) + 11491674725611181241U;
            aOrbiterF = ((aWandererE + RotL64(aIngress, 41U)) + RotL64(aCarry, 13U)) + 16673861720782164214U;
            aOrbiterC = (((aWandererH + RotL64(aScatter, 51U)) + RotL64(aCarry, 53U)) + 9786610124108350855U) + aPhaseFOrbiterAssignSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterG = ((aWandererI + RotL64(aCross, 11U)) + 5745080601557577637U) + aNonceWordF;
            aOrbiterB = ((aWandererG + RotL64(aPrevious, 5U)) + RotL64(aCarry, 29U)) + 1959402215131684684U;
            aOrbiterE = (aWandererK + RotL64(aIngress, 56U)) + 6121650036079196522U;
            aOrbiterI = (aWandererD + RotL64(aScatter, 27U)) + 12016309761037342392U;
            aOrbiterH = ((aWandererC + RotL64(aPrevious, 19U)) + 5986936646177049603U) + aNonceWordC;
            aOrbiterJ = (aWandererJ + RotL64(aCross, 35U)) + 1000367700904043468U;
            aOrbiterA = ((aWandererB + RotL64(aScatter, 13U)) + 17425288243569101032U) + aPhaseFOrbiterAssignSaltE[((aIndex + 19U)) & S_SALT1];
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 4856917474950325209U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 16312111093223166419U;
            aOrbiterF = RotL64((aOrbiterF * 11046477664487805241U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 456110002032422270U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 11393724374787795662U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 1176984359123668389U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 8378176867715697176U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 8086186452345234815U) ^ aNonceWordA;
            aOrbiterK = RotL64((aOrbiterK * 8450438271765985235U), 27U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 8470349167474173245U) + aNonceWordO;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 2528229938740192694U;
            aOrbiterG = RotL64((aOrbiterG * 8717790851266520943U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 13247168811545753141U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 8745293957516815264U;
            aOrbiterI = RotL64((aOrbiterI * 14270617180621072619U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 6165915500564961987U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 12015407798844173213U;
            aOrbiterJ = RotL64((aOrbiterJ * 3913451986559154153U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 545006684939922156U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 16366753936267185001U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 6495185976430013201U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 3097605623436091728U) + aNonceWordN;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 15950167830259022926U;
            aOrbiterC = RotL64((aOrbiterC * 4415538963984293323U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 8356327899232213426U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 10183421678251169945U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 9474380650337109299U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 16327340177970834683U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 7086901180933495535U;
            aOrbiterH = RotL64((aOrbiterH * 1276521829484494857U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 13421211370092080006U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 8367680518550579791U;
            aOrbiterA = RotL64((aOrbiterA * 12256662446176946163U), 43U);
            //
            aIngress = RotL64(aOrbiterC, 47U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterJ, 36U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterI, 11U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 29U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 53U));
            aIngress = aIngress + RotL64(aOrbiterH, 44U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterA, 47U)) + aOrbiterC) + aPhaseFWandererUpdateSaltC[((aIndex + 8U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aIngress, 39U) + aOrbiterG) + RotL64(aOrbiterK, 29U)) + aPhaseFWandererUpdateSaltF[((aIndex + 24U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 19U) + aOrbiterC) + RotL64(aOrbiterD, 60U));
            aWandererH = aWandererH + ((((RotL64(aCross, 58U) + aOrbiterH) + RotL64(aOrbiterJ, 35U)) + RotL64(aCarry, 57U)) + aNonceWordB);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterF, 13U)) + aOrbiterC);
            aWandererI = aWandererI + ((RotL64(aCross, 37U) + RotL64(aOrbiterI, 43U)) + aOrbiterG);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 11U) + aOrbiterH) + RotL64(aOrbiterE, 23U));
            aWandererJ = aWandererJ + ((RotL64(aIngress, 60U) + RotL64(aOrbiterB, 37U)) + aOrbiterK);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 13U) + aOrbiterA) + RotL64(aOrbiterG, 39U));
            aWandererA = aWandererA + (((RotL64(aIngress, 41U) + RotL64(aOrbiterE, 50U)) + aOrbiterJ) + RotL64(aCarry, 21U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 27U) + aOrbiterI) + RotL64(aOrbiterC, 19U)) + aNonceWordE);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 34U));
            aCarry = aCarry + (RotL64(aWandererH, 27U) ^ aWandererI);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 43U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 37U));
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererK, 12U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ aNonceWordG;
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 21567U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 20972U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 18552U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneD[((aIndex + 20406U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 11U) + RotL64(aPrevious, 43U)) ^ (RotL64(aCarry, 60U) + RotL64(aIngress, 27U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterJ = (aWandererJ + RotL64(aScatter, 34U)) + 13854738573712660276U;
            aOrbiterE = ((aWandererH + RotL64(aCross, 23U)) + RotL64(aCarry, 29U)) + 16835460633412286294U;
            aOrbiterC = (aWandererF + RotL64(aIngress, 3U)) + 6785859293758091931U;
            aOrbiterF = (aWandererI + RotL64(aPrevious, 11U)) + 126317283127992659U;
            aOrbiterA = (aWandererG + RotL64(aScatter, 43U)) + 7568963536291415413U;
            aOrbiterD = (aWandererE + RotL64(aCross, 5U)) + 12294016745653004819U;
            aOrbiterI = (aWandererA + RotL64(aPrevious, 37U)) + 18269588932920281147U;
            aOrbiterG = ((aWandererC + RotL64(aIngress, 27U)) + 5872406424994751026U) + aPhaseFOrbiterAssignSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterB = ((aWandererD + RotL64(aScatter, 39U)) + RotL64(aCarry, 51U)) + 7764434758831474129U;
            aOrbiterH = ((((aWandererK + RotL64(aIngress, 60U)) + RotL64(aCarry, 47U)) + 4804168969415573371U) + aPhaseFOrbiterAssignSaltD[((aIndex + 3U)) & S_SALT1]) + aNonceWordA;
            aOrbiterK = ((aWandererB + RotL64(aPrevious, 29U)) + 959601763507651280U) + aNonceWordE;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 9257644462479293048U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 14332699366894494579U;
            aOrbiterC = RotL64((aOrbiterC * 8829304078930625541U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 10487012596470786004U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 612729229562321440U;
            aOrbiterA = RotL64((aOrbiterA * 11380387280507726003U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 7845523921295625315U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 12742115479740024747U;
            aOrbiterD = RotL64((aOrbiterD * 15578543510683986421U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 10294667720904610944U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 14369711143154904567U;
            aOrbiterI = RotL64((aOrbiterI * 13753005602288309379U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 10918344717497681894U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 18136794828308636957U;
            aOrbiterG = RotL64((aOrbiterG * 17899418637978002409U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 14378638206724886404U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 7077588188450008059U;
            aOrbiterB = RotL64((aOrbiterB * 485375960462924335U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 8941870012851971932U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 15242087859620352399U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4963002810455992839U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 10395280254030875387U) + aNonceWordO;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 6826595516076975980U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 6198886240333178001U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 10407910809564430664U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 6368255889263255730U;
            aOrbiterJ = RotL64((aOrbiterJ * 3809496492809859731U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 6365669830464231626U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 596785214258266904U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 6338109335634389561U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 4807438574488830717U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 13854738573712660276U;
            aOrbiterF = RotL64((aOrbiterF * 6954368463489446551U), 37U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterE, 5U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 48U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 37U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterC, 11U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 27U));
            aIngress = aIngress + RotL64(aOrbiterA, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((((RotL64(aIngress, 37U) + aOrbiterB) + RotL64(aOrbiterJ, 29U)) + aNonceWordN) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 39U) + aOrbiterE) + RotL64(aOrbiterA, 39U)) + RotL64(aCarry, 3U));
            aWandererD = aWandererD ^ ((((RotL64(aCross, 29U) + RotL64(aOrbiterD, 5U)) + aOrbiterH) + aNonceWordG) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aPrevious, 5U) + RotL64(aOrbiterI, 60U)) + aOrbiterF);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 58U) + aOrbiterG) + RotL64(aOrbiterC, 3U));
            aWandererE = aWandererE + (((RotL64(aCross, 11U) + RotL64(aOrbiterF, 37U)) + aOrbiterH) + RotL64(aCarry, 53U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterJ, 11U)) + aOrbiterA);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 47U) + RotL64(aOrbiterB, 53U)) + aOrbiterC) + aNonceWordP);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 13U) + aOrbiterE) + RotL64(aOrbiterG, 41U));
            aWandererA = aWandererA + ((RotL64(aPrevious, 35U) + aOrbiterK) + RotL64(aOrbiterF, 26U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 20U) + RotL64(aOrbiterI, 35U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 57U));
            aCarry = aCarry + (RotL64(aWandererK, 60U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererG, 39U) ^ aWandererC);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 3U));
            aCarry = aCarry + (RotL64(aWandererH, 19U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererB, 46U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = aCarry ^ (aNonceWordF ^ aNonceWordJ);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 27012U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneA[((aIndex + 24775U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 23276U)) & S_BLOCK1], 28U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 26981U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 53U) + RotL64(aCross, 41U)) ^ (RotL64(aCarry, 10U) ^ RotL64(aIngress, 27U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterB = (aWandererF + RotL64(aPrevious, 50U)) + 3684295017013759987U;
            aOrbiterC = (aWandererH + RotL64(aIngress, 19U)) + 6740408842457292881U;
            aOrbiterA = (aWandererA + RotL64(aCross, 47U)) + 4563975890702399441U;
            aOrbiterF = (aWandererB + RotL64(aScatter, 39U)) + 797804144825287940U;
            aOrbiterE = (aWandererG + RotL64(aIngress, 41U)) + 2763779540450101303U;
            aOrbiterD = ((aWandererI + RotL64(aPrevious, 29U)) + RotL64(aCarry, 35U)) + 13211846164102089685U;
            aOrbiterG = (((aWandererD + RotL64(aScatter, 57U)) + RotL64(aCarry, 13U)) + 15214578447281401982U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = (aWandererC + RotL64(aCross, 53U)) + 13745208628754232427U;
            aOrbiterJ = ((aWandererE + RotL64(aIngress, 22U)) + RotL64(aCarry, 53U)) + 17358621225969190747U;
            aOrbiterK = (((aWandererK + RotL64(aScatter, 37U)) + 779739369960480023U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordG;
            aOrbiterH = ((aWandererJ + RotL64(aCross, 43U)) + 4370963533701407813U) + aNonceWordD;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 6061333005507739975U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 3589705340762734456U;
            aOrbiterA = RotL64((aOrbiterA * 16499293983611196967U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 10607697666369230567U) + aNonceWordE;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 9356757995305239271U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 10945513661439954731U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 10093033335903048138U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 11037328061699834100U;
            aOrbiterI = RotL64((aOrbiterI * 11189760551792389605U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 558431161176115540U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 17795680919453449358U;
            aOrbiterK = RotL64((aOrbiterK * 3910117359996283803U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 6096779391116214109U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 17594243286880690775U;
            aOrbiterB = RotL64((aOrbiterB * 12655610181937429915U), 21U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 15414704802398002423U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 18040588240488602196U;
            aOrbiterF = RotL64((aOrbiterF * 16344249573086571225U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 14636298592697156931U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 9677305688594936561U;
            aOrbiterG = RotL64((aOrbiterG * 8354776999961642997U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 16408025751875050713U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 10018342878801454965U;
            aOrbiterJ = RotL64((aOrbiterJ * 10349132962708124117U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 1841090936357114866U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 16142637455878447020U;
            aOrbiterH = RotL64((aOrbiterH * 10565394571714418033U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 4089676582910615502U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 8749600984499831109U;
            aOrbiterC = RotL64((aOrbiterC * 3421055105090316521U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 11408932421005107097U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 3684295017013759987U;
            aOrbiterE = RotL64((aOrbiterE * 7037953759624065417U), 43U);
            //
            aIngress = RotL64(aOrbiterF, 44U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterA, 27U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterH, 11U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 35U));
            aIngress = aIngress + (RotL64(aOrbiterI, 46U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterC, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterJ, 48U)) + aOrbiterH) + aNonceWordH);
            aWandererD = aWandererD + ((((RotL64(aCross, 51U) + aOrbiterA) + RotL64(aOrbiterF, 41U)) + RotL64(aCarry, 5U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 53U) + aOrbiterG) + RotL64(aOrbiterC, 53U));
            aWandererF = aWandererF + (((RotL64(aScatter, 60U) + RotL64(aOrbiterK, 37U)) + aOrbiterB) + RotL64(aCarry, 37U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 43U) + aOrbiterB) + RotL64(aOrbiterC, 43U));
            aWandererI = aWandererI + ((((RotL64(aScatter, 23U) + aOrbiterK) + RotL64(aOrbiterE, 3U)) + aNonceWordN) + aPhaseFWandererUpdateSaltD[((aIndex + 20U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 27U) + aOrbiterA) + RotL64(aOrbiterD, 6U));
            aWandererK = aWandererK + (((RotL64(aIngress, 35U) + RotL64(aOrbiterG, 11U)) + aOrbiterF) + aNonceWordA);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 10U) + RotL64(aOrbiterC, 29U)) + aOrbiterH);
            aWandererE = aWandererE + ((RotL64(aIngress, 3U) + RotL64(aOrbiterC, 27U)) + aOrbiterE);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 41U) + aOrbiterI) + RotL64(aOrbiterC, 23U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 21U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererJ, 39U) ^ aWandererE);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 12U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 37U));
            aCarry = aCarry + (RotL64(aWandererA, 41U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererC, 47U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ (aNonceWordJ ^ aNonceWordL);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 32495U)) & S_BLOCK1], 54U) ^ RotL64(aExpandLaneB[((aIndex + 32305U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30170U)) & S_BLOCK1], 52U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 27728U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 29U) ^ RotL64(aCarry, 11U)) + (RotL64(aCross, 41U) ^ RotL64(aIngress, 54U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterE = ((aWandererJ + RotL64(aScatter, 57U)) + RotL64(aCarry, 53U)) + 479672811032092393U;
            aOrbiterH = (aWandererK + RotL64(aPrevious, 21U)) + 18061121631394564425U;
            aOrbiterK = ((aWandererG + RotL64(aIngress, 46U)) + 14237400452740566065U) + aNonceWordB;
            aOrbiterI = ((aWandererB + RotL64(aCross, 43U)) + 6723123812257706134U) + aPhaseFOrbiterAssignSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = (aWandererI + RotL64(aScatter, 51U)) + 4247997188026499248U;
            aOrbiterF = (((aWandererA + RotL64(aPrevious, 41U)) + 1939107415066134869U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordI;
            aOrbiterJ = (aWandererD + RotL64(aCross, 11U)) + 3912640123546395979U;
            aOrbiterC = (aWandererC + RotL64(aIngress, 19U)) + 8295478436553964298U;
            aOrbiterA = ((aWandererE + RotL64(aScatter, 27U)) + 3218960600711526885U) + aNonceWordO;
            aOrbiterG = ((aWandererH + RotL64(aCross, 38U)) + RotL64(aCarry, 57U)) + 5874096203353388890U;
            aOrbiterD = ((aWandererF + RotL64(aIngress, 5U)) + RotL64(aCarry, 47U)) + 10294536533673023358U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 11268561953904130747U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 16693201256788898423U;
            aOrbiterK = RotL64((aOrbiterK * 16291987237693567209U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 7550969634681894654U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 9501647424602245869U;
            aOrbiterB = RotL64((aOrbiterB * 11265865222096866605U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 8881869255994319423U) + aNonceWordL;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 16770136406906800016U;
            aOrbiterF = RotL64((aOrbiterF * 1782039587385512923U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 16185384746435761363U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 13841034186650721627U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 12000155593277035447U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 15229062695864608309U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 3576122704615303733U;
            aOrbiterC = RotL64((aOrbiterC * 2433987493885779279U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 13898167174453181224U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 12878032061609524049U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 18104665741338251495U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 12719156051299028649U) + aNonceWordK;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 8640980843376950769U) ^ aNonceWordF;
            aOrbiterG = RotL64((aOrbiterG * 10242616778390983333U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 12133332160916004365U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 8743563985229104484U;
            aOrbiterD = RotL64((aOrbiterD * 4575129690615054691U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 7362223873479167793U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 4230720394788635807U;
            aOrbiterE = RotL64((aOrbiterE * 3658720603716856293U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 5095842824285329272U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 7483469517256234638U;
            aOrbiterH = RotL64((aOrbiterH * 9782114499878763883U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 17426017004856399653U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 479672811032092393U;
            aOrbiterI = RotL64((aOrbiterI * 14921028515589317919U), 39U);
            //
            aIngress = RotL64(aOrbiterJ, 53U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 23U));
            aIngress = aIngress + (RotL64(aOrbiterK, 11U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 18U));
            aIngress = aIngress + (RotL64(aOrbiterA, 3U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterE, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterJ, 10U)) + aOrbiterE);
            aWandererH = aWandererH + (((RotL64(aIngress, 23U) + aOrbiterI) + RotL64(aOrbiterC, 37U)) + aNonceWordP);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterJ, 19U)) + aOrbiterK);
            aWandererA = aWandererA + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterD, 39U)) + aOrbiterI) + aNonceWordM);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 28U) + RotL64(aOrbiterJ, 3U)) + aOrbiterA);
            aWandererG = aWandererG + (((RotL64(aPrevious, 13U) + aOrbiterK) + RotL64(aOrbiterI, 23U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterB, 51U)) + aOrbiterH);
            aWandererE = aWandererE + (((RotL64(aIngress, 3U) + RotL64(aOrbiterJ, 41U)) + aOrbiterI) + RotL64(aCarry, 19U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 26U) + RotL64(aOrbiterF, 13U)) + aOrbiterI) + aNonceWordH);
            aWandererJ = aWandererJ + (((RotL64(aCross, 37U) + aOrbiterB) + RotL64(aOrbiterG, 30U)) + RotL64(aCarry, 57U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 43U) + aOrbiterG) + RotL64(aOrbiterK, 43U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 14U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererI);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 3U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 5U));
            aCarry = aCarry + (RotL64(aWandererE, 46U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererD, 37U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = aCarry ^ (aNonceWordL ^ aNonceWordJ);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 713U)) & S_BLOCK1], 4U) ^ RotL64(aKeyRowReadA[((aIndex + 5560U)) & W_KEY1], 35U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 6182U)) & W_KEY1], 14U) ^ RotL64(mSource[((aIndex + 5006U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 53U) + RotL64(aIngress, 35U)) ^ (RotL64(aPrevious, 6U) + RotL64(aCarry, 19U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterH = (aWandererH + RotL64(aIngress, 60U)) + 15920462086654025436U;
            aOrbiterJ = ((aWandererA + RotL64(aCross, 29U)) + 487844076858004017U) + aPhaseCOrbiterAssignSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = (aWandererK + RotL64(aPrevious, 43U)) + 14502883786442630566U;
            aOrbiterI = (aWandererJ + RotL64(aScatter, 13U)) + 3787107318658233674U;
            aOrbiterF = (aWandererE + RotL64(aIngress, 35U)) + 12548777544693755491U;
            aOrbiterC = (((aWandererG + RotL64(aPrevious, 23U)) + RotL64(aCarry, 47U)) + 4907309444075181683U) + aPhaseCOrbiterAssignSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterK = ((aWandererB + RotL64(aCross, 47U)) + RotL64(aCarry, 23U)) + 18342396700266492072U;
            aOrbiterD = (aWandererD + RotL64(aScatter, 52U)) + 13503051997624242670U;
            aOrbiterA = ((aWandererF + RotL64(aIngress, 39U)) + RotL64(aCarry, 3U)) + 17845742460521374571U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 8640887211877858169U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 5273913123709097537U;
            aOrbiterB = RotL64((aOrbiterB * 1661149444148461791U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 17756844173695563883U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 6713055830729302951U;
            aOrbiterC = RotL64((aOrbiterC * 2832836748513174311U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 5106468334224035972U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 10228769728713526172U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9760310686414358435U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 7687649520668883142U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 7757480627354711605U) ^ aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7222553727737349209U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 10876291698508634557U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 8149278085586014186U;
            aOrbiterH = RotL64((aOrbiterH * 8577133863470695381U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 15592893988925610485U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 8639028256640537165U;
            aOrbiterI = RotL64((aOrbiterI * 1880655276432963955U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 475660347892196219U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 1903736092401853832U;
            aOrbiterK = RotL64((aOrbiterK * 8486318978769094799U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 12463250192809450953U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 7253918448601703982U;
            aOrbiterJ = RotL64((aOrbiterJ * 3821034106528009129U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 5171661020093804486U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 11627344933828324146U;
            aOrbiterF = RotL64((aOrbiterF * 5388047063152043277U), 41U);
            //
            aIngress = RotL64(aOrbiterB, 37U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 12U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 51U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 5U));
            aIngress = aIngress + RotL64(aOrbiterC, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 4U) + RotL64(aOrbiterB, 51U)) + aOrbiterI);
            aWandererK = aWandererK ^ ((RotL64(aCross, 53U) + aOrbiterC) + RotL64(aOrbiterD, 60U));
            aWandererA = aWandererA + ((((RotL64(aIngress, 35U) + RotL64(aOrbiterA, 41U)) + aOrbiterB) + RotL64(aCarry, 35U)) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterF, 27U)) + aOrbiterB);
            aWandererE = aWandererE + (((RotL64(aPrevious, 23U) + aOrbiterJ) + RotL64(aOrbiterD, 11U)) + RotL64(aCarry, 27U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 14U) + aOrbiterK) + RotL64(aOrbiterH, 19U));
            aWandererF = aWandererF + (((RotL64(aScatter, 27U) + aOrbiterC) + RotL64(aOrbiterK, 23U)) + aPhaseCWandererUpdateSaltD[((aIndex + 15U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterF, 6U)) + aOrbiterI);
            aWandererH = aWandererH + ((RotL64(aIngress, 19U) + RotL64(aOrbiterJ, 35U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererG, 29U) ^ aWandererE);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 47U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 11U));
            aCarry = aCarry + (RotL64(aWandererF, 3U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererH, 34U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 8748U)) & S_BLOCK1], 11U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 13473U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 14114U)) & W_KEY1], 52U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 9652U)) & W_KEY1], 23U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 29U) + RotL64(aCross, 5U)) ^ (RotL64(aPrevious, 57U) + RotL64(aCarry, 44U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterF = (aWandererI + RotL64(aCross, 3U)) + 16802219662864902427U;
            aOrbiterA = ((aWandererG + RotL64(aScatter, 43U)) + RotL64(aCarry, 29U)) + 14332033461409490629U;
            aOrbiterC = ((aWandererB + RotL64(aIngress, 30U)) + 8781794298640286845U) + aPhaseCOrbiterAssignSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = ((aWandererH + RotL64(aPrevious, 51U)) + 8459933908074937264U) + aPhaseCOrbiterAssignSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterJ = (aWandererF + RotL64(aIngress, 35U)) + 1883580287986004426U;
            aOrbiterH = ((aWandererD + RotL64(aCross, 39U)) + RotL64(aCarry, 43U)) + 17500258188004626118U;
            aOrbiterB = ((aWandererJ + RotL64(aPrevious, 13U)) + RotL64(aCarry, 13U)) + 7934811305150872870U;
            aOrbiterD = (aWandererE + RotL64(aScatter, 18U)) + 6380363892361098905U;
            aOrbiterI = (aWandererK + RotL64(aIngress, 23U)) + 12623079132626676910U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 10455208121949202703U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 8805532707916767629U) ^ aPhaseCOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 666082374369701881U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 9161544391400377699U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 3501434325829663268U;
            aOrbiterJ = RotL64((aOrbiterJ * 7933545151293799637U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 651783304096081996U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 441505031509930622U;
            aOrbiterB = RotL64((aOrbiterB * 8045355432310956143U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 1771159983581326424U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 15227946417377695989U;
            aOrbiterD = RotL64((aOrbiterD * 1563141188972797601U), 41U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 4153717524193279095U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 4404521756523902829U;
            aOrbiterI = RotL64((aOrbiterI * 1410342912973206203U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 6231945075461813285U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 3864780227164426690U;
            aOrbiterF = RotL64((aOrbiterF * 18031353247480673617U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 1509699687948576558U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 17316114302489411191U;
            aOrbiterK = RotL64((aOrbiterK * 15490661284980281585U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 2250572827340157410U) + aPhaseCOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 6403966113144372915U;
            aOrbiterH = RotL64((aOrbiterH * 726441947009132383U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 2329903609147403156U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 2486330017319455238U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 17427461345935191757U), 11U);
            //
            aIngress = RotL64(aOrbiterB, 57U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 48U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 41U));
            aIngress = aIngress + (RotL64(aOrbiterC, 11U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterK, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterB, 18U)) + aOrbiterI) + aPhaseCWandererUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aPrevious, 4U) + aOrbiterD) + RotL64(aOrbiterC, 53U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterA, 39U)) + aOrbiterJ);
            aWandererI = aWandererI + (((RotL64(aIngress, 47U) + RotL64(aOrbiterC, 35U)) + aOrbiterK) + RotL64(aCarry, 3U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 29U) + aOrbiterA) + RotL64(aOrbiterF, 47U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 23U) + aOrbiterI) + RotL64(aOrbiterH, 12U)) + aPhaseCWandererUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 35U) + aOrbiterD) + RotL64(aOrbiterF, 23U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterH, 29U)) + aOrbiterB) + RotL64(aCarry, 43U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 58U) + aOrbiterI) + RotL64(aOrbiterA, 57U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 5U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 10U));
            aCarry = aCarry + (RotL64(aWandererI, 39U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererF, 29U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererE, 35U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 20943U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 21951U)) & S_BLOCK1], 44U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 17775U)) & W_KEY1], 10U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 17273U)) & W_KEY1], 37U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 11U) ^ RotL64(aPrevious, 41U)) ^ (RotL64(aCross, 54U) + RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = (((aWandererH + RotL64(aCross, 47U)) + RotL64(aCarry, 11U)) + 1952750591494698524U) + aPhaseCOrbiterAssignSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterF = (aWandererB + RotL64(aPrevious, 19U)) + 4488270851303332830U;
            aOrbiterH = (aWandererA + RotL64(aScatter, 42U)) + 2738763375328927635U;
            aOrbiterB = ((aWandererF + RotL64(aIngress, 5U)) + 6728843649480454340U) + aPhaseCOrbiterAssignSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterC = (aWandererK + RotL64(aCross, 57U)) + 10490717875258865358U;
            aOrbiterG = ((aWandererJ + RotL64(aScatter, 37U)) + RotL64(aCarry, 23U)) + 1429288737812910205U;
            aOrbiterK = (aWandererD + RotL64(aIngress, 24U)) + 2761375016998907636U;
            aOrbiterJ = ((aWandererI + RotL64(aPrevious, 51U)) + RotL64(aCarry, 35U)) + 1088988605204499835U;
            aOrbiterE = (aWandererG + RotL64(aIngress, 29U)) + 6829840407300289709U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 9267240337867690471U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 8120113021183975703U;
            aOrbiterH = RotL64((aOrbiterH * 14296504593187173107U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 1340980511302566784U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 11874452169979878835U) ^ aPhaseCOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8638486178860092537U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 1872314794140971426U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 6013952618696225751U;
            aOrbiterB = RotL64((aOrbiterB * 7994863587373565715U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 3644011378086236002U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 8501867691997891731U;
            aOrbiterF = RotL64((aOrbiterF * 7115282675461711509U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 2493546555198066143U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 5179240189571799179U;
            aOrbiterC = RotL64((aOrbiterC * 1267579130962756135U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 11273348247858394197U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 4577476419423118925U;
            aOrbiterG = RotL64((aOrbiterG * 8427261005061162673U), 41U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 6201955123046621919U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 3930651302557530185U;
            aOrbiterK = RotL64((aOrbiterK * 1563512534463027965U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 7571426325227856019U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 11098508505512361002U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 9229352429618815089U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 6154830144380484305U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 4282054616147137364U;
            aOrbiterE = RotL64((aOrbiterE * 14984813139796280171U), 53U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterF, 27U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 35U));
            aIngress = aIngress + (RotL64(aOrbiterC, 57U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 12U));
            aIngress = aIngress + RotL64(aOrbiterJ, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aIngress, 34U) + aOrbiterK) + RotL64(aOrbiterG, 47U)) + RotL64(aCarry, 3U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterC, 23U)) + aOrbiterJ) + aPhaseCWandererUpdateSaltE[((aIndex + 16U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aScatter, 57U) + aOrbiterH) + RotL64(aOrbiterD, 60U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 23U) + aOrbiterH) + RotL64(aOrbiterK, 5U));
            aWandererB = aWandererB + (((RotL64(aScatter, 51U) + aOrbiterJ) + RotL64(aOrbiterH, 39U)) + RotL64(aCarry, 11U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 5U) + RotL64(aOrbiterJ, 13U)) + aOrbiterG) + aPhaseCWandererUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aCross, 13U) + RotL64(aOrbiterB, 43U)) + aOrbiterF);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 47U) + aOrbiterE) + RotL64(aOrbiterH, 52U));
            aWandererH = aWandererH + ((RotL64(aScatter, 18U) + aOrbiterC) + RotL64(aOrbiterF, 27U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 48U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererB, 35U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererA, 53U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererF, 3U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererJ, 44U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 25694U)) & S_BLOCK1], 10U) ^ RotL64(aExpandLaneB[((aIndex + 24615U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 25603U)) & S_BLOCK1], 4U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 28383U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 11U) + RotL64(aCross, 23U)) ^ (RotL64(aIngress, 40U) ^ RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterE = ((aWandererJ + RotL64(aIngress, 27U)) + RotL64(aCarry, 23U)) + 15036852811491820366U;
            aOrbiterC = (aWandererD + RotL64(aScatter, 60U)) + 305637140752898475U;
            aOrbiterJ = ((aWandererH + RotL64(aCross, 35U)) + RotL64(aCarry, 43U)) + 11948631574496129610U;
            aOrbiterA = ((aWandererE + RotL64(aPrevious, 51U)) + 5321623592482991426U) + aPhaseCOrbiterAssignSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterK = (aWandererB + RotL64(aIngress, 21U)) + 4075270159062690728U;
            aOrbiterF = ((aWandererG + RotL64(aScatter, 41U)) + RotL64(aCarry, 35U)) + 15111580500356908928U;
            aOrbiterI = (aWandererC + RotL64(aCross, 4U)) + 7244150695504160363U;
            aOrbiterG = (aWandererF + RotL64(aPrevious, 13U)) + 5131563519577488862U;
            aOrbiterD = ((aWandererI + RotL64(aCross, 47U)) + 5881954992088651371U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 12780935808751507998U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 12599159643925470226U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 17690046932587062701U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 9466589929741834066U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 6093158735705189789U;
            aOrbiterK = RotL64((aOrbiterK * 7453778295800853653U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 17461243886150519249U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 15456408913739900718U;
            aOrbiterI = RotL64((aOrbiterI * 16093292401746174671U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 11260643903290392780U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 7870342756041882616U;
            aOrbiterE = RotL64((aOrbiterE * 2431528656086173419U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 134484990005888936U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 10626896209992890407U;
            aOrbiterA = RotL64((aOrbiterA * 12034131076645285597U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 14031164129515132292U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 1771835705730244212U) ^ aPhaseCOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 186981668443596623U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 16395472745067254664U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 1455944290845294254U;
            aOrbiterG = RotL64((aOrbiterG * 6757824754363319079U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 17866422769075350837U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 10226884082632410805U;
            aOrbiterD = RotL64((aOrbiterD * 206035536985843815U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 14474587247775371703U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 8501763445324525303U;
            aOrbiterC = RotL64((aOrbiterC * 5298694643596784007U), 29U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterC, 19U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 6U));
            aIngress = aIngress + (RotL64(aOrbiterA, 35U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterJ, 13U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterK, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aIngress, 30U) + aOrbiterD) + RotL64(aOrbiterA, 57U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterE, 12U)) + aOrbiterG);
            aWandererI = aWandererI + (((RotL64(aScatter, 41U) + aOrbiterJ) + RotL64(aOrbiterF, 43U)) + RotL64(aCarry, 13U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterF, 39U)) + aOrbiterA);
            aWandererC = aWandererC + ((RotL64(aPrevious, 20U) + RotL64(aOrbiterD, 47U)) + aOrbiterI);
            aWandererG = aWandererG ^ ((RotL64(aCross, 3U) + aOrbiterC) + RotL64(aOrbiterA, 5U));
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 13U) + aOrbiterG) + RotL64(aOrbiterK, 53U)) + RotL64(aCarry, 35U)) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 53U) + RotL64(aOrbiterD, 24U)) + aOrbiterE) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aIngress, 57U) + RotL64(aOrbiterJ, 35U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 11U));
            aCarry = aCarry + (RotL64(aWandererI, 48U) ^ aWandererH);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 57U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 41U));
            aCarry = aCarry + RotL64(aWandererB, 37U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0; std::uint64_t aOrbiterE = 0;
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 4518U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneC[((aIndex + 2016U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 510U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 6704U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 11U) ^ RotL64(aPrevious, 52U)) ^ (RotL64(aCarry, 23U) + RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterA = (((aWandererI + RotL64(aIngress, 3U)) + RotL64(aCarry, 5U)) + 9914837590440975587U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = (aWandererB + RotL64(aCross, 19U)) + 6706125076401958051U;
            aOrbiterC = ((aWandererG + RotL64(aPrevious, 51U)) + RotL64(aCarry, 53U)) + 16570817772679258409U;
            aOrbiterF = ((aWandererE + RotL64(aScatter, 30U)) + RotL64(aCarry, 27U)) + 6843705658115186948U;
            aOrbiterG = ((aWandererH + RotL64(aPrevious, 39U)) + 16099930446791572351U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 5420550009556030459U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 5729549069420177477U;
            aOrbiterC = RotL64((aOrbiterC * 7842192631021712569U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 15590601126188675834U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 13044027390998620029U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 16845199115313444123U), 23U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 11068338135659636772U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 6584988841809544332U;
            aOrbiterF = RotL64((aOrbiterF * 1683336180438945439U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 8516813219883915404U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 10647314042912492785U;
            aOrbiterK = RotL64((aOrbiterK * 15559481057047148785U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 201691689889605304U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 15512161798401184003U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 11473219183982564709U), 35U);
            //
            aIngress = RotL64(aOrbiterA, 51U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 30U));
            aIngress = aIngress + RotL64(aOrbiterF, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aCross, 13U) + aOrbiterG) + RotL64(aOrbiterA, 26U)) + RotL64(aCarry, 5U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterA, 13U)) + aOrbiterF);
            aWandererB = aWandererB + ((((RotL64(aIngress, 48U) + aOrbiterF) + RotL64(aOrbiterK, 41U)) + RotL64(aCarry, 19U)) + aPhaseDWandererUpdateSaltE[((aIndex + 11U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterG, 57U)) + aOrbiterK);
            aWandererI = aWandererI + (((RotL64(aCross, 27U) + aOrbiterA) + RotL64(aOrbiterC, 3U)) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 11U));
            aCarry = aCarry + (RotL64(aWandererG, 26U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererB, 35U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 15554U)) & S_BLOCK1], 38U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 10724U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 14328U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneB[((aIndex + 15989U)) & S_BLOCK1], 4U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 39U) + RotL64(aPrevious, 3U)) ^ (RotL64(aIngress, 21U) + RotL64(aCarry, 52U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterI = (aWandererG + RotL64(aIngress, 35U)) + 479672811032092393U;
            aOrbiterJ = ((aWandererB + RotL64(aPrevious, 57U)) + RotL64(aCarry, 21U)) + 18061121631394564425U;
            aOrbiterE = ((aWandererD + RotL64(aCross, 43U)) + RotL64(aCarry, 39U)) + 14237400452740566065U;
            aOrbiterC = (((aWandererA + RotL64(aScatter, 24U)) + RotL64(aCarry, 5U)) + 6723123812257706134U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterD = ((aWandererH + RotL64(aCross, 3U)) + 4247997188026499248U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 1939107415066134869U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 3912640123546395979U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 9779626695085572877U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 8295478436553964298U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 3218960600711526885U;
            aOrbiterD = RotL64((aOrbiterD * 15443507655470278069U), 39U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 5874096203353388890U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 10294536533673023358U;
            aOrbiterI = RotL64((aOrbiterI * 15561710414949058923U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 11268561953904130747U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 16693201256788898423U;
            aOrbiterJ = RotL64((aOrbiterJ * 16291987237693567209U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 7550969634681894654U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 9501647424602245869U;
            aOrbiterC = RotL64((aOrbiterC * 11265865222096866605U), 13U);
            //
            aIngress = RotL64(aOrbiterJ, 51U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterI, 13U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterE, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aIngress, 57U) + aOrbiterC) + RotL64(aOrbiterE, 57U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 34U) + RotL64(aOrbiterE, 39U)) + aOrbiterD);
            aWandererB = aWandererB + ((((RotL64(aScatter, 3U) + RotL64(aOrbiterD, 23U)) + aOrbiterI) + RotL64(aCarry, 21U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 23U) + aOrbiterI) + RotL64(aOrbiterJ, 3U));
            aWandererG = aWandererG + ((((RotL64(aPrevious, 13U) + aOrbiterE) + RotL64(aOrbiterI, 48U)) + RotL64(aCarry, 39U)) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 29U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererA, 19U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererG, 37U);
            aCarry = aCarry + RotL64(aIngress, 60U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 22781U)) & S_BLOCK1], 30U) ^ RotL64(aOperationLaneA[((aIndex + 22952U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 18351U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneC[((aIndex + 22088U)) & S_BLOCK1], 30U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 43U) ^ RotL64(aIngress, 21U)) + (RotL64(aPrevious, 56U) ^ RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterK = ((aWandererD + RotL64(aIngress, 39U)) + RotL64(aCarry, 13U)) + 1087148170018530502U;
            aOrbiterH = (((aWandererG + RotL64(aPrevious, 30U)) + RotL64(aCarry, 51U)) + 15530846874509311414U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = ((aWandererB + RotL64(aCross, 51U)) + RotL64(aCarry, 39U)) + 16987358651515511212U;
            aOrbiterG = (aWandererJ + RotL64(aScatter, 3U)) + 12504143181007924259U;
            aOrbiterE = ((aWandererH + RotL64(aPrevious, 11U)) + 393322117322732418U) + aPhaseDOrbiterAssignSaltE[((aIndex + 14U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 14325937299241887166U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 9395262907017475742U;
            aOrbiterC = RotL64((aOrbiterC * 3442643798173589117U), 21U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 13658510441418344769U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 6410754322737005336U;
            aOrbiterH = RotL64((aOrbiterH * 6932217611373076391U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 9257290738538818434U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 7489828960857692286U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 16519674788777989043U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 4118778591214588387U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 16619215231168796563U;
            aOrbiterG = RotL64((aOrbiterG * 14876884956536265157U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 11326283811003573430U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 1865401866017614604U;
            aOrbiterE = RotL64((aOrbiterE * 8378326058282460073U), 5U);
            //
            aIngress = RotL64(aOrbiterK, 47U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 22U));
            aIngress = aIngress + RotL64(aOrbiterC, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aScatter, 35U) + RotL64(aOrbiterG, 3U)) + aOrbiterC) + RotL64(aCarry, 19U)) + aPhaseDWandererUpdateSaltD[((aIndex + 10U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 13U) + aOrbiterG) + RotL64(aOrbiterK, 12U));
            aWandererJ = aWandererJ + ((RotL64(aIngress, 23U) + aOrbiterH) + RotL64(aOrbiterK, 29U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 5U) + aOrbiterC) + RotL64(aOrbiterE, 51U)) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aCross, 60U) + RotL64(aOrbiterE, 21U)) + aOrbiterG) + RotL64(aCarry, 37U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 47U));
            aCarry = aCarry + (RotL64(aWandererD, 13U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererH, 58U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 32679U)) & S_BLOCK1], 52U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 30412U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 29685U)) & S_BLOCK1], 60U) ^ RotL64(aExpandLaneD[((aIndex + 28314U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 51U) ^ RotL64(aCarry, 5U)) ^ (RotL64(aCross, 19U) + RotL64(aIngress, 36U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterA = ((aWandererH + RotL64(aPrevious, 53U)) + RotL64(aCarry, 5U)) + 13333509828310369865U;
            aOrbiterK = (((aWandererB + RotL64(aIngress, 41U)) + RotL64(aCarry, 35U)) + 7645352517103840797U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterH = ((aWandererE + RotL64(aScatter, 27U)) + 5310766306660062655U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = ((aWandererK + RotL64(aCross, 14U)) + RotL64(aCarry, 47U)) + 5165635069832352932U;
            aOrbiterE = (aWandererG + RotL64(aPrevious, 3U)) + 15684141764734281849U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 3327963374225061738U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 8625811794878848871U;
            aOrbiterH = RotL64((aOrbiterH * 16327750494894125333U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 7598657468430485291U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 2881171216276746485U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3331350584102843605U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 10237691227222918101U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 6419254255884834497U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 3816625473642865305U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 4238455444646479956U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 14936613353493061492U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 3544216916806292273U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 15324699725208372627U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 9506640480601832011U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 12819564111348390227U), 27U);
            //
            aIngress = RotL64(aOrbiterE, 3U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 14U));
            aIngress = aIngress + RotL64(aOrbiterK, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aScatter, 19U) + RotL64(aOrbiterJ, 11U)) + aOrbiterE) + aPhaseDWandererUpdateSaltF[((aIndex + 23U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aPrevious, 37U) + aOrbiterK) + RotL64(aOrbiterA, 51U)) + RotL64(aCarry, 3U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 28U) + aOrbiterE) + RotL64(aOrbiterA, 39U));
            aWandererE = aWandererE + ((((RotL64(aCross, 57U) + aOrbiterJ) + RotL64(aOrbiterA, 29U)) + RotL64(aCarry, 43U)) + aPhaseDWandererUpdateSaltE[((aIndex + 21U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 47U) + aOrbiterJ) + RotL64(aOrbiterH, 20U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 37U) ^ aWandererB);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 29U));
            aCarry = aCarry + RotL64(aWandererG, 21U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 338U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 7026U)) & S_BLOCK1], 54U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 7813U)) & S_BLOCK1], 10U) ^ RotL64(aOperationLaneA[((aIndex + 6376U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 34U) + RotL64(aCross, 5U)) ^ (RotL64(aCarry, 53U) + RotL64(aPrevious, 19U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterK = ((aWandererG + RotL64(aCross, 47U)) + RotL64(aCarry, 27U)) + 12029393034357490020U;
            aOrbiterI = ((aWandererC + RotL64(aPrevious, 57U)) + 4526754731580694987U) + aPhaseEOrbiterAssignSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = (aWandererK + RotL64(aScatter, 13U)) + 17060419646421271853U;
            aOrbiterH = ((aWandererJ + RotL64(aIngress, 4U)) + RotL64(aCarry, 53U)) + 4128488893837059683U;
            aOrbiterA = ((aWandererB + RotL64(aPrevious, 41U)) + 12706894827547160110U) + aPhaseEOrbiterAssignSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = (aWandererA + RotL64(aIngress, 35U)) + 12506324593645825056U;
            aOrbiterE = ((aWandererH + RotL64(aScatter, 19U)) + RotL64(aCarry, 5U)) + 12581344490649250025U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 14357032418199130132U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 15341977701796331249U;
            aOrbiterG = RotL64((aOrbiterG * 6332369248718076031U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 7086602307544733241U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 12398300065276832486U;
            aOrbiterA = RotL64((aOrbiterA * 18157408831225635333U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 2499745046076601988U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 7249361592814001829U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 14597139848072319685U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 3254456186337366437U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 3472973415969046680U;
            aOrbiterE = RotL64((aOrbiterE * 14583566953969168353U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 7905718972111691591U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 15941413652144021522U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 3473779492962783565U), 53U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 10583964125960308762U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 13659925272340853715U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 16708294803316630743U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 9487054537489454887U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 13287757570441887517U;
            aOrbiterI = RotL64((aOrbiterI * 17351439045329892107U), 35U);
            //
            aIngress = RotL64(aOrbiterA, 19U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 27U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 60U));
            aIngress = aIngress + RotL64(aOrbiterG, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aIngress, 21U) + aOrbiterG) + RotL64(aOrbiterK, 37U)) + RotL64(aCarry, 35U)) + aPhaseEWandererUpdateSaltE[((aIndex + 13U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterB, 3U)) + aOrbiterK);
            aWandererB = aWandererB + ((RotL64(aCross, 3U) + aOrbiterK) + RotL64(aOrbiterA, 29U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterK, 11U)) + aOrbiterI);
            aWandererA = aWandererA + ((((RotL64(aCross, 13U) + aOrbiterA) + RotL64(aOrbiterE, 44U)) + RotL64(aCarry, 51U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 60U) + RotL64(aOrbiterA, 23U)) + aOrbiterH);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 35U) + aOrbiterI) + RotL64(aOrbiterB, 51U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 5U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 24U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 35U));
            aCarry = aCarry + RotL64(aWandererJ, 47U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 13751U)) & S_BLOCK1], 36U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 11049U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 9478U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 15207U)) & S_BLOCK1], 48U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 50U) + RotL64(aPrevious, 37U)) ^ (RotL64(aCross, 3U) + RotL64(aIngress, 19U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterI = (((aWandererB + RotL64(aIngress, 35U)) + RotL64(aCarry, 21U)) + 3550722402315312207U) + aPhaseEOrbiterAssignSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = ((aWandererI + RotL64(aScatter, 29U)) + RotL64(aCarry, 3U)) + 16724184551669522754U;
            aOrbiterG = ((aWandererE + RotL64(aCross, 60U)) + 981751330116773021U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = (aWandererF + RotL64(aPrevious, 5U)) + 7891159229704944868U;
            aOrbiterH = (aWandererC + RotL64(aCross, 51U)) + 13618396711464799841U;
            aOrbiterB = ((aWandererG + RotL64(aPrevious, 11U)) + RotL64(aCarry, 35U)) + 5969291018449003648U;
            aOrbiterE = (aWandererJ + RotL64(aIngress, 21U)) + 14595540413313640042U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 3287990436916111762U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 12534369400200483704U;
            aOrbiterG = RotL64((aOrbiterG * 2345945228434740707U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 2277312067930392274U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 10026320559261334353U;
            aOrbiterI = RotL64((aOrbiterI * 11020464940995912637U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 11258082063135659551U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 1445958517675746990U;
            aOrbiterF = RotL64((aOrbiterF * 10062265337488757971U), 41U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 1011298251290970844U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 6487834862470043744U;
            aOrbiterD = RotL64((aOrbiterD * 15477913837027179675U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 9966279022928268335U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 10285993486057704393U;
            aOrbiterH = RotL64((aOrbiterH * 15965714363201157535U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 16005362468813966136U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 223843444699390781U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 665392038954573081U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 18178876294968532775U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 12490136112181806806U;
            aOrbiterE = RotL64((aOrbiterE * 16380841616662993709U), 57U);
            //
            aIngress = RotL64(aOrbiterE, 11U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterH, 57U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 29U));
            aIngress = aIngress + RotL64(aOrbiterB, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aScatter, 29U) + aOrbiterI) + RotL64(aOrbiterB, 3U));
            aWandererF = aWandererF + (((RotL64(aCross, 60U) + RotL64(aOrbiterH, 27U)) + aOrbiterF) + RotL64(aCarry, 43U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 3U) + aOrbiterE) + RotL64(aOrbiterG, 51U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterB, 60U)) + aOrbiterG) + RotL64(aCarry, 57U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterE, 13U)) + aOrbiterB);
            aWandererB = aWandererB + (((RotL64(aCross, 19U) + aOrbiterD) + RotL64(aOrbiterI, 41U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 35U) + aOrbiterF) + RotL64(aOrbiterG, 35U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 43U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 58U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 47U));
            aCarry = aCarry + RotL64(aWandererJ, 3U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 21446U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneA[((aIndex + 22296U)) & S_BLOCK1], 14U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 19219U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 19425U)) & S_BLOCK1], 56U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aPrevious, 56U)) ^ (RotL64(aIngress, 19U) + RotL64(aCross, 37U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterK = (aWandererC + RotL64(aPrevious, 29U)) + 14157904117287696136U;
            aOrbiterF = (((aWandererJ + RotL64(aIngress, 37U)) + RotL64(aCarry, 51U)) + 7369512677371640676U) + aPhaseEOrbiterAssignSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterB = ((aWandererD + RotL64(aScatter, 60U)) + RotL64(aCarry, 23U)) + 8411250745902073798U;
            aOrbiterI = ((aWandererI + RotL64(aCross, 11U)) + 5002041814539710275U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterD = ((aWandererG + RotL64(aPrevious, 23U)) + RotL64(aCarry, 3U)) + 9538041410816283124U;
            aOrbiterG = (aWandererK + RotL64(aScatter, 51U)) + 5210700103927513061U;
            aOrbiterE = (aWandererE + RotL64(aIngress, 43U)) + 7600709399101287982U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 2366369466696580499U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 5544575244203019109U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 16231219246786333057U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 8710073749110329779U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 15998211310115361630U;
            aOrbiterF = RotL64((aOrbiterF * 15275657696897688955U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 15354357553877376422U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 10657523549259276169U;
            aOrbiterK = RotL64((aOrbiterK * 13695239532898311073U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 10405750198355464768U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 3465819693133515142U;
            aOrbiterI = RotL64((aOrbiterI * 14678343718277562799U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 16724189641701408630U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 3484340153620198872U;
            aOrbiterD = RotL64((aOrbiterD * 17247547677520703125U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 7420442404884871126U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 11138445997256757636U;
            aOrbiterG = RotL64((aOrbiterG * 11167543379937571127U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 1428191560884663125U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 16950093140800653985U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4423012306984814805U), 21U);
            //
            aIngress = RotL64(aOrbiterB, 21U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterG, 12U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 35U));
            aIngress = aIngress + RotL64(aOrbiterK, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aIngress, 41U) + aOrbiterI) + RotL64(aOrbiterG, 53U)) + aPhaseEWandererUpdateSaltA[((aIndex + 21U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aPrevious, 35U) + RotL64(aOrbiterF, 13U)) + aOrbiterK);
            aWandererE = aWandererE ^ ((RotL64(aCross, 19U) + aOrbiterG) + RotL64(aOrbiterD, 35U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 3U) + aOrbiterE) + RotL64(aOrbiterD, 60U)) + RotL64(aCarry, 5U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 10U) + RotL64(aOrbiterI, 27U)) + aOrbiterB);
            aWandererC = aWandererC + (((RotL64(aPrevious, 27U) + RotL64(aOrbiterF, 47U)) + aOrbiterE) + RotL64(aCarry, 51U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterB, 5U)) + aOrbiterG) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 52U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 57U));
            aCarry = aCarry + (RotL64(aWandererG, 41U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererD, 3U);
            aCarry = aCarry + RotL64(aIngress, 18U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 30241U)) & S_BLOCK1], 38U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27761U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 31574U)) & S_BLOCK1], 14U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 32725U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 21U) ^ RotL64(aCarry, 57U)) + (RotL64(aCross, 6U) + RotL64(aPrevious, 41U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterK = ((aWandererI + RotL64(aCross, 21U)) + RotL64(aCarry, 27U)) + 9107326720193244489U;
            aOrbiterE = ((aWandererK + RotL64(aScatter, 47U)) + 10868585484401664145U) + aPhaseEOrbiterAssignSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterC = ((aWandererF + RotL64(aIngress, 37U)) + RotL64(aCarry, 11U)) + 13637736741437846622U;
            aOrbiterH = (((aWandererG + RotL64(aPrevious, 11U)) + RotL64(aCarry, 43U)) + 6130725216183918844U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = (aWandererA + RotL64(aCross, 27U)) + 2063834478521338187U;
            aOrbiterI = (aWandererJ + RotL64(aPrevious, 5U)) + 8564870627911949158U;
            aOrbiterJ = (aWandererB + RotL64(aScatter, 54U)) + 6524015751064086390U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 9874937766875388236U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 14723718409522680894U;
            aOrbiterC = RotL64((aOrbiterC * 17379140128833323431U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 13767059954741528279U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 6387608251033722169U;
            aOrbiterI = RotL64((aOrbiterI * 6601902195707980693U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 5391425980008431000U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 11524218415655093779U;
            aOrbiterE = RotL64((aOrbiterE * 12508457981779189389U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 155510463350385905U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 10554591788433641311U;
            aOrbiterA = RotL64((aOrbiterA * 5412084824127934293U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 8662160162966241542U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 5092555636369853727U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 433807340167635499U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 7163345798448796101U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 695089002178413267U;
            aOrbiterH = RotL64((aOrbiterH * 17302689458565434475U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 5409173939213468972U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 15349690077393827541U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10984681254001609841U), 57U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterJ, 35U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 41U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 27U));
            aIngress = aIngress + RotL64(aOrbiterC, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aPrevious, 58U) + RotL64(aOrbiterE, 41U)) + aOrbiterC) + RotL64(aCarry, 57U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterK, 60U)) + aOrbiterE);
            aWandererB = aWandererB + ((RotL64(aScatter, 3U) + RotL64(aOrbiterA, 53U)) + aOrbiterH);
            aWandererK = aWandererK ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterI, 47U)) + aOrbiterA) + aPhaseEWandererUpdateSaltE[((aIndex + 8U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aScatter, 23U) + RotL64(aOrbiterJ, 11U)) + aOrbiterI) + RotL64(aCarry, 29U)) + aPhaseEWandererUpdateSaltF[((aIndex + 3U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 41U) + aOrbiterJ) + RotL64(aOrbiterK, 3U));
            aWandererG = aWandererG + ((RotL64(aIngress, 51U) + RotL64(aOrbiterC, 29U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererK, 6U) ^ aWandererB);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 13U));
            aCarry = aCarry + RotL64(aWandererA, 57U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 3680U)) & S_BLOCK1], 54U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 6539U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 1116U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneA[((aIndex + 2237U)) & S_BLOCK1], 40U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 43U) + RotL64(aIngress, 56U)) ^ (RotL64(aCross, 29U) + RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterH = (aWandererB + RotL64(aPrevious, 3U)) + 3339283916456813609U;
            aOrbiterI = (((aWandererA + RotL64(aIngress, 14U)) + RotL64(aCarry, 5U)) + 11339086426180649584U) + aPhaseFOrbiterAssignSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = ((aWandererF + RotL64(aCross, 39U)) + RotL64(aCarry, 19U)) + 16819191669329316585U;
            aOrbiterK = ((aWandererE + RotL64(aScatter, 57U)) + RotL64(aCarry, 47U)) + 8361916937762630725U;
            aOrbiterC = ((aWandererD + RotL64(aPrevious, 23U)) + 18031328374429899857U) + aPhaseFOrbiterAssignSaltB[((aIndex + 28U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 18261756894092897276U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 4250319792907645666U;
            aOrbiterF = RotL64((aOrbiterF * 7053489184750217963U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 1492411503643460886U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 17369549067879344180U;
            aOrbiterH = RotL64((aOrbiterH * 2947354306696216579U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 7301713524358676722U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 2985193736033012535U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 7473297294949338265U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 14086975808140927408U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 10390516547834639800U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11441293212275890819U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 18205555540941493267U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 16967799565443938873U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 3009081009044782443U), 19U);
            //
            aIngress = RotL64(aOrbiterC, 29U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 5U));
            aIngress = aIngress + RotL64(aOrbiterF, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aCross, 39U) + RotL64(aOrbiterF, 5U)) + aOrbiterH) + RotL64(aCarry, 51U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 14U) + RotL64(aOrbiterC, 39U)) + aOrbiterF) + aPhaseFWandererUpdateSaltC[((aIndex + 21U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aIngress, 3U) + aOrbiterK) + RotL64(aOrbiterI, 47U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 57U) + aOrbiterI) + RotL64(aOrbiterC, 14U));
            aWandererA = aWandererA + (((RotL64(aIngress, 23U) + aOrbiterC) + RotL64(aOrbiterH, 29U)) + RotL64(aCarry, 27U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 5U));
            aCarry = aCarry + (RotL64(aWandererE, 13U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererD, 57U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 10534U)) & S_BLOCK1], 10U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 8421U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 15208U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 10544U)) & S_BLOCK1], 48U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 19U) ^ RotL64(aPrevious, 34U)) ^ (RotL64(aIngress, 51U) + RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterB = (((aWandererG + RotL64(aCross, 48U)) + RotL64(aCarry, 21U)) + 2225397913940961213U) + aPhaseFOrbiterAssignSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterA = (aWandererE + RotL64(aPrevious, 57U)) + 8342544893601343643U;
            aOrbiterJ = (aWandererB + RotL64(aScatter, 3U)) + 162922186381417187U;
            aOrbiterH = (((aWandererH + RotL64(aIngress, 39U)) + RotL64(aCarry, 5U)) + 11660218373710972210U) + aPhaseFOrbiterAssignSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterD = ((aWandererD + RotL64(aPrevious, 11U)) + RotL64(aCarry, 37U)) + 14909034764605802354U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 16776955237009701511U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 5834487809188925253U;
            aOrbiterJ = RotL64((aOrbiterJ * 4458820879204327709U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 1498492772767040320U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 4161765458781579617U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 15535994410289065281U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 10511923076962447765U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 8575954471692620021U;
            aOrbiterB = RotL64((aOrbiterB * 12526744988828982731U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 6536325446331340573U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 1790628986900286346U;
            aOrbiterA = RotL64((aOrbiterA * 5262997114200816715U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 2623814807619278590U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 11676970995834706612U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 10057461115132434901U), 21U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterJ, 37U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 57U));
            aIngress = aIngress + RotL64(aOrbiterD, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aPrevious, 13U) + aOrbiterJ) + RotL64(aOrbiterH, 35U)) + RotL64(aCarry, 39U)) + aPhaseFWandererUpdateSaltF[((aIndex + 11U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 60U) + RotL64(aOrbiterA, 23U)) + aOrbiterH);
            aWandererH = aWandererH + ((RotL64(aIngress, 43U) + aOrbiterD) + RotL64(aOrbiterB, 47U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterA, 13U)) + aOrbiterB);
            aWandererG = aWandererG + ((((RotL64(aIngress, 51U) + aOrbiterJ) + RotL64(aOrbiterD, 4U)) + RotL64(aCarry, 27U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 5U) ^ aWandererH);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 38U));
            aCarry = aCarry + RotL64(aWandererE, 57U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 21657U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((aIndex + 22281U)) & S_BLOCK1], 22U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 17379U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 17248U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 53U) ^ RotL64(aCross, 21U)) ^ (RotL64(aPrevious, 3U) + RotL64(aCarry, 38U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterG = ((aWandererF + RotL64(aPrevious, 37U)) + RotL64(aCarry, 35U)) + 785861751704720606U;
            aOrbiterB = ((aWandererI + RotL64(aScatter, 47U)) + 15968088718435606299U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterI = ((aWandererD + RotL64(aIngress, 11U)) + 1393976526590347151U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = ((aWandererC + RotL64(aCross, 26U)) + RotL64(aCarry, 3U)) + 17240750947292745884U;
            aOrbiterH = ((aWandererK + RotL64(aScatter, 3U)) + RotL64(aCarry, 53U)) + 4921576136163183137U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 3334047873553153032U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 15086509978458408698U;
            aOrbiterI = RotL64((aOrbiterI * 2162818176367899893U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 892391205397581998U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 2965686403183767521U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 709160942482770225U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 14632215393655706170U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 15740589515342377322U;
            aOrbiterG = RotL64((aOrbiterG * 15677716942904794913U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 11131164813943086445U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 6988080581278900960U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6412189142344044255U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 16021254613117657178U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 6183615599897921154U;
            aOrbiterH = RotL64((aOrbiterH * 9976411093264211033U), 51U);
            //
            aIngress = RotL64(aOrbiterI, 47U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 3U));
            aIngress = aIngress + RotL64(aOrbiterB, 22U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aIngress, 58U) + aOrbiterB) + RotL64(aOrbiterI, 20U)) + aPhaseFWandererUpdateSaltB[((aIndex + 26U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 3U) + aOrbiterG) + RotL64(aOrbiterF, 43U)) + RotL64(aCarry, 11U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 21U) + aOrbiterF) + RotL64(aOrbiterI, 29U));
            aWandererK = aWandererK + ((((RotL64(aPrevious, 35U) + aOrbiterH) + RotL64(aOrbiterI, 3U)) + RotL64(aCarry, 27U)) + aPhaseFWandererUpdateSaltA[((aIndex + 4U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 11U) + aOrbiterF) + RotL64(aOrbiterH, 57U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 43U));
            aCarry = aCarry + (RotL64(aWandererI, 58U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererC, 19U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 31137U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27760U)) & S_BLOCK1], 10U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 27120U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneD[((aIndex + 32731U)) & S_BLOCK1], 24U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 54U) ^ RotL64(aPrevious, 13U)) ^ (RotL64(aCarry, 27U) + RotL64(aIngress, 41U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterC = (aWandererF + RotL64(aIngress, 21U)) + 17019646486641172469U;
            aOrbiterA = ((aWandererG + RotL64(aScatter, 29U)) + RotL64(aCarry, 41U)) + 12276141179299971572U;
            aOrbiterF = ((aWandererE + RotL64(aCross, 47U)) + 3617241694029841555U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = (((aWandererK + RotL64(aPrevious, 4U)) + RotL64(aCarry, 23U)) + 6967963401259371737U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = ((aWandererC + RotL64(aIngress, 37U)) + RotL64(aCarry, 53U)) + 6340709284279891017U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 456065368903896482U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 17686765719908116203U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4451942512173336609U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 1322045955429785736U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 5163772703302372887U;
            aOrbiterC = RotL64((aOrbiterC * 3193272189179082313U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 13268431135020363252U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 6538789950366849332U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5352960308459065837U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 10390344544314544893U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 5087084271300584267U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 15149302947570776165U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 13423071121590981727U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 18324443012024134729U;
            aOrbiterG = RotL64((aOrbiterG * 15814349432207734533U), 57U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterA, 42U);
            aIngress = aIngress + (RotL64(aOrbiterF, 13U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterC, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aIngress, 37U) + aOrbiterH) + RotL64(aOrbiterC, 19U));
            aWandererE = aWandererE + ((((RotL64(aCross, 3U) + aOrbiterC) + RotL64(aOrbiterG, 35U)) + RotL64(aCarry, 13U)) + aPhaseFWandererUpdateSaltC[((aIndex + 9U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterA, 27U)) + aOrbiterF);
            aWandererG = aWandererG + ((((RotL64(aScatter, 13U) + RotL64(aOrbiterH, 3U)) + aOrbiterG) + RotL64(aCarry, 35U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 22U) + aOrbiterF) + RotL64(aOrbiterH, 48U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 35U));
            aCarry = aCarry + (RotL64(aWandererK, 18U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererG, 27U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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

    std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0; std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0;
    std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0;
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 3428U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 2872U)) & S_BLOCK1], 34U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 1301U)) & S_BLOCK1], 6U) ^ RotL64(aWorkLaneD[((aIndex + 3061U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 57U) + RotL64(aPrevious, 19U)) ^ (RotL64(aIngress, 6U) + RotL64(aCross, 37U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterJ = (((aWandererD + RotL64(aIngress, 57U)) + RotL64(aCarry, 5U)) + 18180797995100240808U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterD = (aWandererH + RotL64(aCross, 43U)) + 6585906608223552885U;
            aOrbiterC = ((aWandererJ + RotL64(aPrevious, 35U)) + RotL64(aCarry, 57U)) + 14088708930575939855U;
            aOrbiterG = ((aWandererE + RotL64(aScatter, 5U)) + RotL64(aCarry, 19U)) + 468974153311516044U;
            aOrbiterK = ((aWandererG + RotL64(aIngress, 26U)) + 12481951025619894110U) + aPhaseGOrbiterAssignSaltE[((aIndex + 21U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 17227987923860711763U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 4373962756657477139U;
            aOrbiterC = RotL64((aOrbiterC * 6069068316234356267U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 2077576476565420951U) + aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 17435011300234663764U;
            aOrbiterJ = RotL64((aOrbiterJ * 8910133867294004711U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 4118039398293246896U) + aPhaseGOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 13724716599855216683U) ^ aPhaseGOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 17556333902751079677U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 12391461204689596339U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 9900605191533799627U) ^ aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 13553565332531046301U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 972946858824366125U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 17247681919694541215U;
            aOrbiterK = RotL64((aOrbiterK * 2974639094630445643U), 13U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterK, 3U);
            aIngress = aIngress + (RotL64(aOrbiterG, 29U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterD, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aScatter, 3U) + RotL64(aOrbiterK, 11U)) + aOrbiterC) + aPhaseGWandererUpdateSaltB[((aIndex + 6U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterG, 3U)) + aOrbiterD) + RotL64(aCarry, 37U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 39U) + RotL64(aOrbiterJ, 37U)) + aOrbiterC) + aPhaseGWandererUpdateSaltE[((aIndex + 4U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aIngress, 57U) + RotL64(aOrbiterD, 29U)) + aOrbiterK) + RotL64(aCarry, 53U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 30U) + RotL64(aOrbiterG, 52U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 27U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 11U));
            aCarry = aCarry + RotL64(aWandererJ, 19U);
            aCarry = aCarry + RotL64(aIngress, 60U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 8367U)) & S_BLOCK1], 22U) ^ RotL64(aWorkLaneC[((aIndex + 8973U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 8573U)) & S_BLOCK1], 48U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 9109U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 19U) + RotL64(aCross, 36U)) ^ (RotL64(aCarry, 3U) + RotL64(aIngress, 51U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterG = ((aWandererA + RotL64(aIngress, 41U)) + 6771552164800695068U) + aPhaseGOrbiterAssignSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterF = ((aWandererF + RotL64(aScatter, 19U)) + RotL64(aCarry, 35U)) + 12131763371571322040U;
            aOrbiterD = ((aWandererK + RotL64(aCross, 27U)) + RotL64(aCarry, 47U)) + 3326182381395522013U;
            aOrbiterJ = (((aWandererH + RotL64(aPrevious, 3U)) + RotL64(aCarry, 23U)) + 12288775097697156383U) + aPhaseGOrbiterAssignSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterI = (aWandererE + RotL64(aCross, 56U)) + 5195948373449796741U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 14404044002250137144U) + aPhaseGOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 11142382920035825426U;
            aOrbiterD = RotL64((aOrbiterD * 8134413822789107595U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 2967149520256475485U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 1470907369577818097U) ^ aPhaseGOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 9398653295177725883U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 9231668148004163910U) + aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 13078929163913892386U;
            aOrbiterG = RotL64((aOrbiterG * 7509829068700523627U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 9485274692075657877U) + aPhaseGOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 12216951187543631673U;
            aOrbiterF = RotL64((aOrbiterF * 6571066246507310805U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 6933334652581744234U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 17260276102423580920U;
            aOrbiterJ = RotL64((aOrbiterJ * 7796879893790990605U), 37U);
            //
            aIngress = RotL64(aOrbiterG, 13U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterI, 60U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterD, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aCross, 3U) + aOrbiterG) + RotL64(aOrbiterI, 46U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 57U) + aOrbiterD) + RotL64(aOrbiterJ, 11U)) + aPhaseGWandererUpdateSaltD[((aIndex + 4U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterJ, 37U)) + aOrbiterG) + RotL64(aCarry, 47U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 39U) + RotL64(aOrbiterF, 21U)) + aOrbiterJ) + aPhaseGWandererUpdateSaltC[((aIndex + 7U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aIngress, 48U) + aOrbiterG) + RotL64(aOrbiterF, 57U)) + RotL64(aCarry, 21U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 35U));
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererA, 3U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 22149U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 21557U)) & S_BLOCK1], 26U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 19348U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 19316U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 56U) + RotL64(aPrevious, 5U)) ^ (RotL64(aCarry, 43U) ^ RotL64(aIngress, 21U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterJ = ((aWandererB + RotL64(aCross, 51U)) + RotL64(aCarry, 27U)) + 13687218104610230596U;
            aOrbiterH = ((aWandererA + RotL64(aScatter, 13U)) + RotL64(aCarry, 41U)) + 6841550124960692709U;
            aOrbiterC = ((aWandererH + RotL64(aIngress, 5U)) + 17418968668458764131U) + aPhaseGOrbiterAssignSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = (aWandererE + RotL64(aPrevious, 28U)) + 8303537912696948204U;
            aOrbiterD = (((aWandererJ + RotL64(aIngress, 43U)) + RotL64(aCarry, 13U)) + 12376614417285936537U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 14215749063579232654U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 4111736931433665347U;
            aOrbiterC = RotL64((aOrbiterC * 8841288213954433049U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 11250375934571631522U) + aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 5367367837773331275U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7262723007545807179U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 15514089192382674434U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 1475991716685034960U;
            aOrbiterJ = RotL64((aOrbiterJ * 17720681295551650891U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 5531622777788629748U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 8363822215908303335U;
            aOrbiterI = RotL64((aOrbiterI * 17850203366840994883U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 3741256932685720414U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 11634667238062155772U;
            aOrbiterD = RotL64((aOrbiterD * 15925089729784547403U), 23U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterH, 3U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 41U));
            aIngress = aIngress + RotL64(aOrbiterC, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aIngress, 39U) + aOrbiterD) + RotL64(aOrbiterI, 35U)) + RotL64(aCarry, 53U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 48U) + RotL64(aOrbiterI, 12U)) + aOrbiterC);
            aWandererB = aWandererB + ((((RotL64(aCross, 19U) + aOrbiterI) + RotL64(aOrbiterJ, 21U)) + RotL64(aCarry, 41U)) + aPhaseGWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterH, 57U)) + aOrbiterC);
            aWandererJ = aWandererJ + (((RotL64(aCross, 27U) + RotL64(aOrbiterC, 3U)) + aOrbiterD) + aPhaseGWandererUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 37U) ^ aWandererB);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 54U));
            aCarry = aCarry + RotL64(aWandererE, 27U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 27348U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneA[((aIndex + 27069U)) & S_BLOCK1], 50U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28281U)) & S_BLOCK1], 22U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 31657U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 56U) ^ RotL64(aIngress, 27U)) + (RotL64(aCarry, 41U) + RotL64(aPrevious, 13U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = (((aWandererG + RotL64(aPrevious, 19U)) + RotL64(aCarry, 3U)) + 1393781663398437180U) + aPhaseGOrbiterAssignSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterJ = ((aWandererJ + RotL64(aCross, 56U)) + RotL64(aCarry, 23U)) + 17414594746688585273U;
            aOrbiterG = (aWandererA + RotL64(aScatter, 3U)) + 2823888497053071250U;
            aOrbiterC = (((aWandererE + RotL64(aIngress, 39U)) + RotL64(aCarry, 43U)) + 17032631958617884859U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = (aWandererK + RotL64(aScatter, 11U)) + 15222697630461125019U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 15737414920751551780U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 1357196111055783001U) ^ aPhaseGOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8225423829221938165U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 5315122321649251691U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 7893744655508595974U;
            aOrbiterD = RotL64((aOrbiterD * 17863000246694319149U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 16721939414324611738U) + aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 3444375866323610848U) ^ aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 10874157227815775661U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 1825716513674511632U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 15582066843912467318U;
            aOrbiterJ = RotL64((aOrbiterJ * 12765146555943757373U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 15673590949193923915U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 13887365046280406413U;
            aOrbiterE = RotL64((aOrbiterE * 3169061375011420121U), 19U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterD, 53U);
            aIngress = aIngress + (RotL64(aOrbiterE, 3U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterC, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 43U) + aOrbiterJ) + RotL64(aOrbiterG, 27U)) + RotL64(aCarry, 39U)) + aPhaseGWandererUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterE, 57U)) + aOrbiterC);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 29U) + RotL64(aOrbiterD, 19U)) + aOrbiterE) + RotL64(aCarry, 51U)) + aPhaseGWandererUpdateSaltB[((aIndex + 22U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 60U) + aOrbiterC) + RotL64(aOrbiterD, 36U));
            aWandererA = aWandererA + ((RotL64(aCross, 11U) + RotL64(aOrbiterJ, 5U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 13U));
            aCarry = aCarry + (RotL64(aWandererJ, 27U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererG, 57U);
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
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 2925U)) & S_BLOCK1], 36U) ^ RotL64(aExpandLaneB[((aIndex + 8004U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 1599U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 830U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 47U) + RotL64(aIngress, 29U)) ^ (RotL64(aPrevious, 60U) + RotL64(aCross, 11U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterH = ((aWandererF + RotL64(aPrevious, 13U)) + RotL64(aCarry, 23U)) + 18144572925667544139U;
            aOrbiterI = (aWandererI + RotL64(aIngress, 37U)) + 5659758077574059728U;
            aOrbiterB = (((aWandererA + RotL64(aCross, 23U)) + RotL64(aCarry, 11U)) + 6343330616999166392U) + aPhaseHOrbiterAssignSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterF = ((aWandererE + RotL64(aScatter, 47U)) + RotL64(aCarry, 47U)) + 17754639838410839447U;
            aOrbiterC = ((aWandererG + RotL64(aIngress, 58U)) + 9451843819849581729U) + aPhaseHOrbiterAssignSaltD[((aIndex + 14U)) & S_SALT1];
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 7957854457197462212U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 1461994799722205010U;
            aOrbiterB = RotL64((aOrbiterB * 13431080873536691809U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 18002214276252170177U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 14689869073147027164U;
            aOrbiterH = RotL64((aOrbiterH * 12242482963989582191U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 3978104368003440293U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 8512135845221335386U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10506667163729414667U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 1477533446382953439U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 2166717790929947990U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 6538884492418324461U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 8082437060686606995U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 4363687722464700362U;
            aOrbiterC = RotL64((aOrbiterC * 7199165810993478887U), 13U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterF, 40U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 3U));
            aIngress = aIngress + RotL64(aOrbiterI, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 21U) + RotL64(aOrbiterH, 46U)) + aOrbiterC) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 51U) + aOrbiterF) + RotL64(aOrbiterH, 11U)) + RotL64(aCarry, 57U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 60U) + RotL64(aOrbiterC, 19U)) + aOrbiterI);
            aWandererG = aWandererG + ((((RotL64(aCross, 11U) + RotL64(aOrbiterF, 57U)) + aOrbiterI) + RotL64(aCarry, 37U)) + aPhaseHWandererUpdateSaltD[((aIndex + 16U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterB, 37U)) + aOrbiterH);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 29U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 60U));
            aCarry = aCarry + RotL64(aWandererE, 43U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 9638U)) & S_BLOCK1], 26U) ^ RotL64(aExpandLaneC[((aIndex + 13173U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 8285U)) & S_BLOCK1], 56U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 11699U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 41U) + RotL64(aCarry, 11U)) + (RotL64(aCross, 29U) ^ RotL64(aPrevious, 56U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterG = (((aWandererH + RotL64(aIngress, 21U)) + RotL64(aCarry, 39U)) + 14214886793361825363U) + aPhaseHOrbiterAssignSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterD = ((aWandererG + RotL64(aCross, 56U)) + 17267959031078766320U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterF = ((aWandererK + RotL64(aScatter, 13U)) + RotL64(aCarry, 53U)) + 16436067429484887644U;
            aOrbiterC = ((aWandererA + RotL64(aPrevious, 37U)) + RotL64(aCarry, 3U)) + 9885951769332633820U;
            aOrbiterE = (aWandererJ + RotL64(aCross, 5U)) + 12971711341813893304U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 199970353398450154U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 1237341696444162094U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2850125642665515751U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 7991128854417613360U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 14809029847149045833U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5940857360838299105U), 53U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 2559509556915775947U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 14336829730147834160U;
            aOrbiterG = RotL64((aOrbiterG * 15103242520064900873U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 8853631886733610440U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 13346159398673246914U;
            aOrbiterD = RotL64((aOrbiterD * 13660497151446983393U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 12121095718571872976U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 16239781125815589804U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 5157009090454962231U), 23U);
            //
            aIngress = RotL64(aOrbiterF, 30U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 19U));
            aIngress = aIngress + RotL64(aOrbiterG, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterE, 5U)) + aOrbiterG) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 29U) + RotL64(aOrbiterG, 29U)) + aOrbiterD) + RotL64(aCarry, 13U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterC, 19U)) + aOrbiterD);
            aWandererK = aWandererK + (((RotL64(aPrevious, 3U) + aOrbiterF) + RotL64(aOrbiterC, 47U)) + RotL64(aCarry, 51U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 54U) + aOrbiterG) + RotL64(aOrbiterC, 56U)) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 13U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 53U));
            aCarry = aCarry + RotL64(aWandererJ, 35U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 20679U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 22264U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19807U)) & S_BLOCK1], 20U) ^ RotL64(aWorkLaneB[((aIndex + 21190U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 36U) ^ RotL64(aIngress, 11U)) ^ (RotL64(aCarry, 23U) + RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterH = (((aWandererF + RotL64(aIngress, 23U)) + RotL64(aCarry, 43U)) + 2617613537256538553U) + aPhaseHOrbiterAssignSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterJ = ((aWandererD + RotL64(aPrevious, 35U)) + 16642868916835132715U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterB = (aWandererC + RotL64(aScatter, 3U)) + 10860291124337073254U;
            aOrbiterI = ((aWandererH + RotL64(aCross, 12U)) + RotL64(aCarry, 29U)) + 6432511273906902472U;
            aOrbiterE = ((aWandererI + RotL64(aScatter, 57U)) + RotL64(aCarry, 57U)) + 7505375005848241910U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 11086616004678821329U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 3298830587569881951U;
            aOrbiterB = RotL64((aOrbiterB * 4304047944073454489U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 9775143140064220979U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 4147601326580823120U;
            aOrbiterJ = RotL64((aOrbiterJ * 13462244678782260871U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 12245920269898100415U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 8391940489176734499U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9119606167674098007U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 17876893379544668477U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 18301882058180370541U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 16680384667098921309U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 6869225862715140102U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 15404118372589259800U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5766851935950389915U), 5U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterJ, 52U);
            aIngress = aIngress + (RotL64(aOrbiterE, 41U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterB, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterI, 13U)) + aOrbiterH) + RotL64(aCarry, 53U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 51U) + aOrbiterJ) + RotL64(aOrbiterH, 56U));
            aWandererH = aWandererH + (((RotL64(aScatter, 22U) + aOrbiterB) + RotL64(aOrbiterE, 39U)) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterH, 47U)) + aOrbiterE);
            aWandererF = aWandererF + ((((RotL64(aScatter, 13U) + aOrbiterB) + RotL64(aOrbiterI, 5U)) + RotL64(aCarry, 5U)) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 60U));
            aCarry = aCarry + (RotL64(aWandererC, 39U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererH, 47U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 24943U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneA[((aIndex + 25165U)) & S_BLOCK1], 6U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 31592U)) & S_BLOCK1], 46U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 31270U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 51U)) ^ (RotL64(aCross, 22U) + RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterE = ((aWandererK + RotL64(aScatter, 13U)) + RotL64(aCarry, 51U)) + 11274974230580265396U;
            aOrbiterG = (aWandererJ + RotL64(aCross, 44U)) + 16658438747342741547U;
            aOrbiterA = ((aWandererI + RotL64(aPrevious, 53U)) + 16612986966106053844U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = ((aWandererE + RotL64(aIngress, 21U)) + RotL64(aCarry, 11U)) + 9329502236843231290U;
            aOrbiterD = (((aWandererD + RotL64(aCross, 5U)) + RotL64(aCarry, 23U)) + 14088261356708344656U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 13692608802007789581U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 6824473946645682398U;
            aOrbiterA = RotL64((aOrbiterA * 13619437545775237601U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 2072915876348570040U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 7420507753044460759U;
            aOrbiterE = RotL64((aOrbiterE * 13239288539564571257U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 4677557318688502593U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 15081678577055628459U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 16659305295251177155U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 7026792817486507482U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 14871665922943969918U;
            aOrbiterG = RotL64((aOrbiterG * 694073180313083145U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 6807734532159292872U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 17882797335141303280U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 15439872930381050291U), 3U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterB, 58U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 5U));
            aIngress = aIngress + RotL64(aOrbiterE, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 54U) + aOrbiterG) + RotL64(aOrbiterA, 19U)) + aPhaseHWandererUpdateSaltD[((aIndex + 3U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aIngress, 23U) + aOrbiterE) + RotL64(aOrbiterB, 27U)) + RotL64(aCarry, 39U)) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterE, 44U)) + aOrbiterG);
            aWandererD = aWandererD + (((RotL64(aScatter, 37U) + RotL64(aOrbiterD, 35U)) + aOrbiterE) + RotL64(aCarry, 11U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterD, 53U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 51U));
            aCarry = aCarry + (RotL64(aWandererI, 21U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererE, 39U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
