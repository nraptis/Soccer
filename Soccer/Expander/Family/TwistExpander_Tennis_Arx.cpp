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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xD3EA5B423856CD0BULL + 0xE7414C382E30B698ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x895C24B28B1EEB11ULL + 0xEB1507779B1AED37ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xC4BD7FCA988751FFULL + 0xC8DC0E104774F211ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xFA2AB409FA51DB97ULL + 0xA467E303BF4C74C1ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xB404B527F4D69FABULL + 0x92CF3E21B566C4A7ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x80500EF5E956C057ULL + 0xE1271A78A8BA5225ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xF18D39EAB0E88697ULL + 0xAC40C356D21C81BDULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x8E7060975E686F4FULL + 0xE993E2BE1EC366F0ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x91EBFE69505F9C41ULL + 0xDAFD77E530AD4121ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x90C4AE2021CAA293ULL + 0xB6E8F983645F1A96ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0x944EFAA47DB31915ULL + 0xD36F36E62AA46071ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0x989650A2DA08DC67ULL + 0x997E95E72DB3485CULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xF1CA1F9C272D5487ULL + 0x975C520BD708343EULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xDED091163068EF11ULL + 0xC38B12193BACD815ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xE0D0EEF1A16C5F5FULL + 0xED652E3979B3D8FEULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xCE00ACA90B8B3965ULL + 0xBBF162E8810F8228ULL);
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
            aIngress = RotL64(mSource[((aIndex + 3955U)) & S_BLOCK1], 3U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 3629U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(pSnow[((S_BLOCK1 - aIndex + 690U)) & S_BLOCK1], 43U) ^ RotL64(mSource[((aIndex + 4691U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCross, 3U) ^ RotL64(aIngress, 35U)) ^ (RotL64(aCarry, 21U) + RotL64(aPrevious, 48U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterK = ((aWandererD + RotL64(aPrevious, 42U)) + 5697928251815176134U) + aOrbiterAssignSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = (aWandererJ + RotL64(aScatter, 23U)) + 337587740689259575U;
            aOrbiterG = ((aWandererF + RotL64(aCross, 3U)) + RotL64(aCarry, 51U)) + 4927686903263973950U;
            aOrbiterI = (aWandererK + RotL64(aIngress, 35U)) + 3742409032569801033U;
            aOrbiterE = (aWandererA + RotL64(aScatter, 37U)) + 1608092659172197650U;
            aOrbiterC = (aWandererC + RotL64(aCross, 57U)) + 15848744267145717509U;
            aOrbiterF = ((aWandererH + RotL64(aPrevious, 13U)) + 15300174177963339253U) + aNonceWordC;
            aOrbiterD = ((aWandererI + RotL64(aIngress, 18U)) + RotL64(aCarry, 43U)) + 14162868453323648628U;
            aOrbiterA = (((aWandererE + RotL64(aPrevious, 39U)) + RotL64(aCarry, 35U)) + 12020167069983729869U) + aOrbiterAssignSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterH = (aWandererB + RotL64(aCross, 51U)) + 16259538291658723956U;
            aOrbiterJ = ((aWandererG + RotL64(aScatter, 27U)) + 8516686212464112245U) + aNonceWordO;
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 3722184575520553132U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 5663609293306386784U) ^ aNonceWordL;
            aOrbiterG = RotL64((aOrbiterG * 14364218128780764749U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 15265344442454471986U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 3050323350098829515U;
            aOrbiterK = RotL64((aOrbiterK * 5890624677162388135U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 1093356813820599238U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 15167726103772238440U;
            aOrbiterD = RotL64((aOrbiterD * 5719466863561311069U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 15170797965325981472U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 17826286701992981628U;
            aOrbiterH = RotL64((aOrbiterH * 11186808881726573677U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 14710892030473425181U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterJ) ^ 397194787697553904U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterI = RotL64((aOrbiterI * 14368930300818752833U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 1273724124862533034U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 13018397560392545616U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4644812473262395329U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 9638716186445643730U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 7255587739807843785U) ^ aNonceWordM;
            aOrbiterB = RotL64((aOrbiterB * 6055682981584011189U), 21U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 9272350563697399628U) + aOrbiterUpdateSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 1040729335295009339U) ^ aOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 17825687660830291443U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 12128124729613601747U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 2285238815562202219U;
            aOrbiterF = RotL64((aOrbiterF * 15398840993074390573U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 6339113298619163493U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 5911895708485037040U;
            aOrbiterA = RotL64((aOrbiterA * 3271006139923200439U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 7601399508218901328U) + aNonceWordD;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 5697928251815176134U;
            aOrbiterJ = RotL64((aOrbiterJ * 8184257916861355735U), 53U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterG, 58U);
            aIngress = aIngress + (RotL64(aOrbiterD, 3U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 5U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 27U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 37U));
            aIngress = aIngress + RotL64(aOrbiterB, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aIngress, 11U) + aOrbiterJ) + RotL64(aOrbiterK, 27U));
            aWandererD = aWandererD + ((((RotL64(aPrevious, 51U) + aOrbiterH) + RotL64(aOrbiterC, 23U)) + RotL64(aCarry, 57U)) + aWandererUpdateSaltD[((aIndex + 27U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 26U) + RotL64(aOrbiterD, 30U)) + aOrbiterH);
            aWandererC = aWandererC + (((RotL64(aScatter, 23U) + RotL64(aOrbiterA, 43U)) + aOrbiterG) + aNonceWordB);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 41U) + aOrbiterJ) + RotL64(aOrbiterG, 35U));
            aWandererK = aWandererK + (((RotL64(aIngress, 53U) + aOrbiterB) + RotL64(aOrbiterE, 57U)) + aNonceWordF);
            aWandererH = aWandererH ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterK, 13U)) + aOrbiterG);
            aWandererB = aWandererB + (((RotL64(aScatter, 21U) + RotL64(aOrbiterI, 51U)) + aOrbiterE) + aNonceWordN);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 37U) + aOrbiterG) + RotL64(aOrbiterF, 21U));
            aWandererE = aWandererE + (((RotL64(aScatter, 47U) + aOrbiterA) + RotL64(aOrbiterI, 3U)) + RotL64(aCarry, 37U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 6U) + aOrbiterJ) + RotL64(aOrbiterH, 54U)) + aWandererUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 53U));
            aCarry = aCarry + (RotL64(aWandererB, 60U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererE, 11U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererJ, 3U) ^ aWandererI);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 37U));
            aCarry = aCarry + RotL64(aWandererA, 26U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 8099U)) & S_BLOCK1], 21U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 6360U)) & S_BLOCK1], 10U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 7637U)) & S_BLOCK1], 3U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 10251U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aPrevious, 53U) + RotL64(aCross, 37U)) + (RotL64(aIngress, 18U) ^ RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterA = ((aWandererH + RotL64(aIngress, 34U)) + 4179952823252098240U) + aOrbiterAssignSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = (((aWandererF + RotL64(aCross, 23U)) + 3745613452332101749U) + aOrbiterAssignSaltA[((aIndex + 17U)) & S_SALT1]) + aNonceWordH;
            aOrbiterD = (aWandererJ + RotL64(aPrevious, 39U)) + 2955689793395307176U;
            aOrbiterI = ((aWandererA + RotL64(aScatter, 13U)) + 5639060180251322019U) + aNonceWordC;
            aOrbiterF = ((aWandererK + RotL64(aIngress, 36U)) + RotL64(aCarry, 13U)) + 7901969163853586463U;
            aOrbiterB = (aWandererE + RotL64(aPrevious, 57U)) + 2242166787816318119U;
            aOrbiterC = (aWandererB + RotL64(aScatter, 3U)) + 5239936443960750064U;
            aOrbiterG = ((aWandererD + RotL64(aCross, 41U)) + RotL64(aCarry, 39U)) + 13939136954732185558U;
            aOrbiterE = (aWandererG + RotL64(aPrevious, 53U)) + 17058884136712717463U;
            aOrbiterK = (aWandererI + RotL64(aCross, 21U)) + 18148618660054585941U;
            aOrbiterH = ((aWandererC + RotL64(aScatter, 51U)) + RotL64(aCarry, 23U)) + 7022023484530327814U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 7722084537340095637U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 11764151879690934182U;
            aOrbiterD = RotL64((aOrbiterD * 12264384877711365655U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 16412785901758144708U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 9666718667728274824U;
            aOrbiterF = RotL64((aOrbiterF * 10865799822751771795U), 23U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 4307127540152109364U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 2457646804702647606U;
            aOrbiterG = RotL64((aOrbiterG * 6340030928007058595U), 37U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterE) + 3179394870088602208U) + aOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1]) + aNonceWordF;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 504977947273774249U) ^ aOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 16190282058883481551U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 16182729401018310837U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 7110817020445860609U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 13371352088428584087U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 12960656706837391973U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 7103806893724395904U;
            aOrbiterE = RotL64((aOrbiterE * 14365984439655979791U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 1248300178080633527U) + aNonceWordP;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 7195473175424961337U) ^ aNonceWordJ;
            aOrbiterJ = RotL64((aOrbiterJ * 4633558992739305045U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 13007951568242991449U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 10296811247653636372U;
            aOrbiterC = RotL64((aOrbiterC * 16469682651380549395U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 13922797949001028335U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 16773545425463040155U;
            aOrbiterI = RotL64((aOrbiterI * 10639282630227832397U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 2888887140296117803U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 10279517418046269817U;
            aOrbiterB = RotL64((aOrbiterB * 8600355360339461535U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 17303373436784809093U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 4179952823252098240U) ^ aNonceWordI;
            aOrbiterA = RotL64((aOrbiterA * 3675754609699406437U), 27U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterA, 19U);
            aIngress = aIngress + (RotL64(aOrbiterD, 53U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterB, 51U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 57U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 60U));
            aIngress = aIngress + RotL64(aOrbiterJ, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 5U) + aOrbiterE) + RotL64(aOrbiterJ, 27U)) + aWandererUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 29U) + aOrbiterF) + RotL64(aOrbiterI, 30U)) + RotL64(aCarry, 57U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 27U) + aOrbiterC) + RotL64(aOrbiterG, 57U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 42U) + RotL64(aOrbiterH, 41U)) + aOrbiterI) + aWandererUpdateSaltE[((aIndex + 15U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterI, 11U)) + aOrbiterK);
            aWandererH = aWandererH + (((RotL64(aCross, 51U) + aOrbiterE) + RotL64(aOrbiterC, 39U)) + RotL64(aCarry, 37U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterD, 47U)) + aOrbiterI) + aNonceWordB);
            aWandererE = aWandererE + ((RotL64(aIngress, 37U) + aOrbiterH) + RotL64(aOrbiterK, 23U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 44U) + RotL64(aOrbiterC, 35U)) + aOrbiterJ) + aNonceWordA);
            aWandererA = aWandererA + ((RotL64(aCross, 13U) + aOrbiterB) + RotL64(aOrbiterC, 60U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 21U) + aOrbiterK) + RotL64(aOrbiterA, 43U)) + aNonceWordK);
            //
            aCarry = aCarry + (RotL64(aWandererK, 51U) ^ aWandererB);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 12U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 41U));
            aCarry = aCarry + (RotL64(aWandererC, 5U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererF, 29U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererA, 53U);
            aCarry = aCarry + RotL64(aIngress, 44U);
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
            aIngress = RotL64(aWorkLaneB[((aIndex + 11387U)) & S_BLOCK1], 51U) ^ RotL64(mSource[((aIndex + 11248U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordA));
            //
            aCross = RotL64(pSnow[((S_BLOCK1 - aIndex + 14992U)) & S_BLOCK1], 42U) ^ RotL64(aWorkLaneA[((aIndex + 11389U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCarry, 11U) ^ RotL64(aIngress, 50U)) ^ (RotL64(aPrevious, 23U) + RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterJ = (aWandererH + RotL64(aPrevious, 58U)) + 701291026547470433U;
            aOrbiterB = ((aWandererA + RotL64(aCross, 19U)) + RotL64(aCarry, 13U)) + 17283292650462111643U;
            aOrbiterI = (aWandererI + RotL64(aScatter, 41U)) + 9969124091931303406U;
            aOrbiterH = (aWandererK + RotL64(aIngress, 3U)) + 889176772718046988U;
            aOrbiterK = (aWandererE + RotL64(aScatter, 43U)) + 6054541844643748084U;
            aOrbiterG = (((aWandererD + RotL64(aIngress, 35U)) + RotL64(aCarry, 57U)) + 14703226235143028132U) + aOrbiterAssignSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterF = ((aWandererC + RotL64(aPrevious, 54U)) + 7977975878522921062U) + aNonceWordL;
            aOrbiterA = (aWandererJ + RotL64(aCross, 47U)) + 16894322614172266274U;
            aOrbiterE = (((aWandererF + RotL64(aPrevious, 27U)) + RotL64(aCarry, 27U)) + 12160451749345900570U) + aOrbiterAssignSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterC = ((aWandererB + RotL64(aIngress, 39U)) + 10870847008043897470U) + aNonceWordJ;
            aOrbiterD = (aWandererG + RotL64(aScatter, 21U)) + 8159920947172520247U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 2440099120969517932U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 2428396147731468007U;
            aOrbiterI = RotL64((aOrbiterI * 9363073341539598441U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 2213226274394673479U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 7079731443427765333U;
            aOrbiterK = RotL64((aOrbiterK * 16918930776877030559U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 958896789550478970U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 10788682955708075458U) ^ aOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 913321215613559729U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 2003386579317564870U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 8419686358774204999U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 6547052526438697621U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 6989167615157578904U) + aOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 17636634003643824148U;
            aOrbiterC = RotL64((aOrbiterC * 11038576417283732937U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 13824962118933907859U) + aOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 9543912892587859646U;
            aOrbiterA = RotL64((aOrbiterA * 14736710162285997415U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 15729878041027706114U) + aNonceWordD;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 9542137475454825463U) ^ aNonceWordM;
            aOrbiterH = RotL64((aOrbiterH * 11420547128115090491U), 39U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 5327302277575009955U) + aNonceWordK;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 2707383132257428583U;
            aOrbiterD = RotL64((aOrbiterD * 6120763309390182129U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 9008601903853562620U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 11050463189491777908U;
            aOrbiterG = RotL64((aOrbiterG * 9178386878636430553U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 14683684132116778056U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 5390271065690907120U;
            aOrbiterB = RotL64((aOrbiterB * 17903005409098232619U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 5183407290520277451U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 701291026547470433U;
            aOrbiterF = RotL64((aOrbiterF * 16329261100139524239U), 57U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterH, 3U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 23U));
            aIngress = aIngress + (RotL64(aOrbiterA, 11U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 51U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 58U));
            aIngress = aIngress + RotL64(aOrbiterK, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterJ, 3U)) + aOrbiterD);
            aWandererD = aWandererD + ((RotL64(aCross, 47U) + aOrbiterI) + RotL64(aOrbiterD, 43U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 23U) + RotL64(aOrbiterH, 19U)) + aOrbiterI) + aNonceWordF);
            aWandererK = aWandererK + (((RotL64(aPrevious, 58U) + aOrbiterF) + RotL64(aOrbiterB, 29U)) + RotL64(aCarry, 19U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 53U) + aOrbiterJ) + RotL64(aOrbiterA, 14U));
            aWandererG = aWandererG + (((RotL64(aCross, 19U) + RotL64(aOrbiterF, 39U)) + aOrbiterD) + aWandererUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 21U) + aOrbiterI) + RotL64(aOrbiterK, 5U)) + aNonceWordC);
            aWandererF = aWandererF + (((RotL64(aPrevious, 5U) + aOrbiterH) + RotL64(aOrbiterB, 41U)) + aNonceWordI);
            aWandererE = aWandererE ^ (((RotL64(aCross, 10U) + RotL64(aOrbiterE, 26U)) + aOrbiterG) + aWandererUpdateSaltF[((aIndex + 5U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aIngress, 37U) + RotL64(aOrbiterE, 11U)) + aOrbiterA) + RotL64(aCarry, 3U)) + aNonceWordH);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 27U) + aOrbiterC) + RotL64(aOrbiterJ, 23U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 24U) ^ aWandererK);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 51U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 43U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 3U));
            aCarry = aCarry + (RotL64(aWandererH, 29U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererE, 53U);
            aCarry = aCarry + RotL64(aIngress, 56U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 17880U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneA[((aIndex + 20673U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 20730U)) & S_BLOCK1], 57U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 18790U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 18219U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aIngress, 57U) ^ RotL64(aCarry, 44U)) + (RotL64(aPrevious, 21U) ^ RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterK = ((aWandererD + RotL64(aScatter, 21U)) + 11039986441331892533U) + aNonceWordO;
            aOrbiterJ = (((aWandererI + RotL64(aPrevious, 46U)) + RotL64(aCarry, 13U)) + 6256024955965426119U) + aOrbiterAssignSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterF = ((aWandererA + RotL64(aCross, 29U)) + RotL64(aCarry, 43U)) + 9857443189988995666U;
            aOrbiterH = (aWandererK + RotL64(aIngress, 57U)) + 11900944813380998208U;
            aOrbiterE = (aWandererG + RotL64(aPrevious, 3U)) + 8422577734978875541U;
            aOrbiterI = ((aWandererH + RotL64(aCross, 51U)) + 3100835100713928724U) + aOrbiterAssignSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterB = (aWandererJ + RotL64(aScatter, 43U)) + 11871553509810206993U;
            aOrbiterG = (aWandererE + RotL64(aIngress, 39U)) + 17614749493763417027U;
            aOrbiterC = (aWandererC + RotL64(aScatter, 41U)) + 3638372131856199916U;
            aOrbiterA = ((aWandererB + RotL64(aIngress, 5U)) + RotL64(aCarry, 3U)) + 6582275259281025770U;
            aOrbiterD = ((aWandererF + RotL64(aPrevious, 34U)) + 17016882418498941958U) + aNonceWordL;
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 1747214688658984715U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 9356088987044015278U) ^ aNonceWordM;
            aOrbiterF = RotL64((aOrbiterF * 16221733545319753695U), 53U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 4056238112133473456U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 16013150119949532998U;
            aOrbiterK = RotL64((aOrbiterK * 12913648646318115315U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 16076621211111834889U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 9940824359571581765U;
            aOrbiterB = RotL64((aOrbiterB * 11624767861336495331U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 15624084004784515753U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 7630989544834680335U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12261063237156822067U), 3U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterA) + 18003586430673313786U) + aOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1]) + aNonceWordK;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 1654118743290334161U) ^ aNonceWordE;
            aOrbiterJ = RotL64((aOrbiterJ * 1153250137357176071U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 3254189676528343910U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 15629083361573065165U) ^ aNonceWordJ;
            aOrbiterA = RotL64((aOrbiterA * 17024833368570949107U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 10056859810555674806U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 15976683222786846254U;
            aOrbiterI = RotL64((aOrbiterI * 2801754232182942635U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 11872378594829637933U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 7633773773528713489U) ^ aOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 8218288492011593353U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 16305188578382203720U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 13293036594949754170U;
            aOrbiterH = RotL64((aOrbiterH * 1300645662609848183U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 15185013801659166674U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 11562899709899198100U;
            aOrbiterG = RotL64((aOrbiterG * 9115495024409604629U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 1525205566739385260U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 11039986441331892533U;
            aOrbiterD = RotL64((aOrbiterD * 9802284050237622047U), 19U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterH, 51U);
            aIngress = aIngress + (RotL64(aOrbiterA, 57U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 27U));
            aIngress = aIngress + (RotL64(aOrbiterK, 35U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterC, 11U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterJ, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aPrevious, 41U) + RotL64(aOrbiterI, 43U)) + aOrbiterH) + RotL64(aCarry, 57U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterK, 35U)) + aOrbiterC);
            aWandererH = aWandererH + (((RotL64(aScatter, 5U) + aOrbiterD) + RotL64(aOrbiterA, 48U)) + aNonceWordH);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 56U) + aOrbiterE) + RotL64(aOrbiterA, 39U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 37U) + aOrbiterG) + RotL64(aOrbiterB, 27U)) + aWandererUpdateSaltD[((aIndex + 6U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aCross, 53U) + RotL64(aOrbiterA, 23U)) + aOrbiterG) + aNonceWordN);
            aWandererK = aWandererK + ((RotL64(aIngress, 13U) + aOrbiterH) + RotL64(aOrbiterC, 58U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterF, 19U)) + aOrbiterA);
            aWandererA = aWandererA + ((((RotL64(aIngress, 39U) + RotL64(aOrbiterK, 3U)) + aOrbiterB) + RotL64(aCarry, 21U)) + aWandererUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aCross, 18U) + aOrbiterE) + RotL64(aOrbiterF, 29U)) + aNonceWordG);
            aWandererB = aWandererB + ((RotL64(aScatter, 43U) + aOrbiterJ) + RotL64(aOrbiterD, 11U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 38U));
            aCarry = aCarry + (RotL64(aWandererK, 43U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererA, 35U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererC, 57U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererH, 50U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererD, 19U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 22002U)) & S_BLOCK1], 37U) ^ RotL64(mSource[((aIndex + 25019U)) & S_BLOCK1], 27U));
            aIngress ^= (RotL64(pSnow[((aIndex + 26163U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24114U)) & S_BLOCK1], 50U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 22345U)) & S_BLOCK1], 52U) ^ RotL64(aWorkLaneB[((aIndex + 22255U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aIngress, 39U) ^ RotL64(aCross, 27U)) + (RotL64(aPrevious, 11U) ^ RotL64(aCarry, 58U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterG = (aWandererG + RotL64(aIngress, 19U)) + 380024772508948442U;
            aOrbiterH = (aWandererC + RotL64(aCross, 6U)) + 7649029098162567210U;
            aOrbiterA = (((aWandererJ + RotL64(aPrevious, 11U)) + RotL64(aCarry, 3U)) + 5329304598870421851U) + aOrbiterAssignSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = ((((aWandererI + RotL64(aScatter, 39U)) + RotL64(aCarry, 39U)) + 12306118665045151326U) + aOrbiterAssignSaltA[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordI;
            aOrbiterC = ((aWandererK + RotL64(aIngress, 23U)) + 960751560457324256U) + aNonceWordD;
            aOrbiterK = (aWandererE + RotL64(aScatter, 54U)) + 3244070254386191876U;
            aOrbiterD = (aWandererH + RotL64(aCross, 35U)) + 15733408571609521746U;
            aOrbiterB = (aWandererF + RotL64(aPrevious, 51U)) + 17623448932647018544U;
            aOrbiterE = (aWandererD + RotL64(aScatter, 29U)) + 8787759896149035829U;
            aOrbiterI = ((aWandererB + RotL64(aIngress, 27U)) + RotL64(aCarry, 35U)) + 14741681792348288162U;
            aOrbiterJ = (aWandererA + RotL64(aPrevious, 57U)) + 8801731213568307302U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 9872248187499779222U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 15407371518644528235U;
            aOrbiterA = RotL64((aOrbiterA * 1245102406469471673U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 4242060317152943062U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 9942784962409917541U;
            aOrbiterK = RotL64((aOrbiterK * 888649755587764533U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 7296348796484458631U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 15061417216070157797U;
            aOrbiterB = RotL64((aOrbiterB * 10349554676953256231U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 3233185810644297433U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 9241229457641024287U) ^ aOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2728237515724597517U), 37U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 8464051359381554575U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 3307872165699029375U;
            aOrbiterI = RotL64((aOrbiterI * 4859663401033023433U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 5482617843966711997U) + aNonceWordL;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 4442149210462943872U;
            aOrbiterG = RotL64((aOrbiterG * 8979352218576515647U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 10591636597580147381U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 14925122230279312217U;
            aOrbiterE = RotL64((aOrbiterE * 15038171961638724013U), 53U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 9772367878232735350U) + aNonceWordO;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 15800661165607190092U;
            aOrbiterF = RotL64((aOrbiterF * 10493976952980533589U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 1571665862499272194U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 3162847040693387901U) ^ aOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2747235335326991399U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 4868791925868749848U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 13134549226315884613U;
            aOrbiterJ = RotL64((aOrbiterJ * 3551955270718495869U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 7830447320021657240U) + aNonceWordH;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 380024772508948442U;
            aOrbiterD = RotL64((aOrbiterD * 5143324968958616357U), 41U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterA, 21U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 57U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 60U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 23U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 3U));
            aIngress = aIngress + RotL64(aOrbiterI, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aScatter, 26U) + RotL64(aOrbiterD, 47U)) + aOrbiterK);
            aWandererH = aWandererH ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterF, 53U)) + aOrbiterG);
            aWandererA = aWandererA + ((RotL64(aPrevious, 51U) + RotL64(aOrbiterD, 43U)) + aOrbiterC);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 11U) + aOrbiterE) + RotL64(aOrbiterI, 3U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterE, 6U)) + aOrbiterJ) + aNonceWordB);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterH, 27U)) + aOrbiterJ);
            aWandererB = aWandererB + (((RotL64(aCross, 47U) + aOrbiterG) + RotL64(aOrbiterI, 41U)) + RotL64(aCarry, 21U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 54U) + aOrbiterC) + RotL64(aOrbiterE, 19U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 5U) + RotL64(aOrbiterA, 11U)) + aOrbiterB) + aNonceWordN);
            aWandererC = aWandererC ^ ((((RotL64(aIngress, 13U) + RotL64(aOrbiterD, 51U)) + aOrbiterH) + aNonceWordM) + aWandererUpdateSaltB[((aIndex + 10U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 19U) + RotL64(aOrbiterK, 30U)) + aOrbiterA) + RotL64(aCarry, 35U)) + aWandererUpdateSaltE[((aIndex + 14U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 11U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 23U));
            aCarry = aCarry + (RotL64(aWandererE, 50U) ^ aWandererI);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 41U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 35U));
            aCarry = aCarry + RotL64(aWandererD, 53U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 28750U)) & S_BLOCK1], 13U) ^ RotL64(pSnow[((aIndex + 32068U)) & S_BLOCK1], 56U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 30757U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 31807U)) & S_BLOCK1], 30U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 32541U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 31326U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aPrevious, 29U) ^ RotL64(aCarry, 53U)) + (RotL64(aIngress, 6U) ^ RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterH = (aWandererE + RotL64(aCross, 35U)) + 9133751643283278896U;
            aOrbiterE = (((aWandererH + RotL64(aIngress, 29U)) + 8971581804375380408U) + aOrbiterAssignSaltC[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordB;
            aOrbiterK = ((aWandererJ + RotL64(aScatter, 50U)) + RotL64(aCarry, 39U)) + 12559650383714566592U;
            aOrbiterJ = (aWandererF + RotL64(aPrevious, 41U)) + 15753206088872859163U;
            aOrbiterD = (aWandererG + RotL64(aScatter, 13U)) + 7640756270450762350U;
            aOrbiterF = ((aWandererA + RotL64(aPrevious, 53U)) + RotL64(aCarry, 23U)) + 7340073357551376125U;
            aOrbiterI = (aWandererI + RotL64(aCross, 27U)) + 5270256573644196046U;
            aOrbiterA = (aWandererD + RotL64(aIngress, 5U)) + 3567367996479995928U;
            aOrbiterB = ((aWandererC + RotL64(aCross, 22U)) + 11939634537492733738U) + aOrbiterAssignSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = ((aWandererK + RotL64(aIngress, 39U)) + RotL64(aCarry, 57U)) + 7051817732424527120U;
            aOrbiterC = ((aWandererB + RotL64(aScatter, 37U)) + 1730487669951837941U) + aNonceWordP;
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 18009252467909454817U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 2361024272031696442U;
            aOrbiterK = RotL64((aOrbiterK * 15215151562500226027U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 15902755877642960397U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 12243517544704116184U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2576071074148141447U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 16846181962302186187U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 636121425116506681U;
            aOrbiterA = RotL64((aOrbiterA * 17075030673338779993U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 6887385655828217318U) + aOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 3705834550934775862U;
            aOrbiterJ = RotL64((aOrbiterJ * 11275428284929594435U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 11165142437077969438U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 6426659930331618269U) ^ aOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 17170640810530893705U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 12629082390899315789U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 4277510580069574724U;
            aOrbiterG = RotL64((aOrbiterG * 9829125163412708305U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 13814834144170469978U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 3698381854100295826U;
            aOrbiterI = RotL64((aOrbiterI * 5126359230872258015U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 11623170635983579937U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 7247413650388803796U;
            aOrbiterH = RotL64((aOrbiterH * 3403219499465560059U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 3129755194359521145U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 4081016725582134919U;
            aOrbiterB = RotL64((aOrbiterB * 11564414998539605389U), 37U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 15878346077922215753U) + aOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 2974440187796944059U) ^ aNonceWordC;
            aOrbiterC = RotL64((aOrbiterC * 783253926537018373U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 3922344163443096356U) + aNonceWordA;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 9133751643283278896U;
            aOrbiterD = RotL64((aOrbiterD * 16887991698415418429U), 23U);
            //
            aIngress = RotL64(aOrbiterD, 21U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterH, 29U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 43U));
            aIngress = aIngress + (RotL64(aOrbiterA, 35U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterC, 37U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterE, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aIngress, 3U) + aOrbiterI) + RotL64(aOrbiterA, 27U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 47U) + aOrbiterK) + RotL64(aOrbiterC, 6U));
            aWandererC = aWandererC + (((RotL64(aScatter, 43U) + RotL64(aOrbiterG, 51U)) + aOrbiterJ) + RotL64(aCarry, 13U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 40U) + aOrbiterD) + RotL64(aOrbiterI, 21U));
            aWandererB = aWandererB + ((((RotL64(aIngress, 29U) + RotL64(aOrbiterA, 53U)) + aOrbiterG) + RotL64(aCarry, 47U)) + aNonceWordM);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 35U) + aOrbiterF) + RotL64(aOrbiterE, 47U));
            aWandererD = aWandererD + ((((RotL64(aCross, 11U) + RotL64(aOrbiterK, 57U)) + aOrbiterH) + aNonceWordK) + aWandererUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterI, 11U)) + aOrbiterK);
            aWandererG = aWandererG + (((RotL64(aIngress, 5U) + aOrbiterK) + RotL64(aOrbiterJ, 14U)) + aWandererUpdateSaltF[((aIndex + 5U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 24U) + RotL64(aOrbiterB, 19U)) + aOrbiterC);
            aWandererF = aWandererF + ((RotL64(aCross, 27U) + aOrbiterF) + RotL64(aOrbiterC, 39U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 11U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 48U));
            aCarry = aCarry + (RotL64(aWandererJ, 57U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererG, 51U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererH, 5U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererE, 29U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xCA0FBB90CA13D523ULL + 0xD3026BE8C4A5D692ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x90E780284E69607DULL + 0xEC154275416C8E1FULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xC6DFA7D031061F7FULL + 0xAC6C0FD0A1EE8989ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xC6F1D247195E67E3ULL + 0xA045FC3B28A2CD3CULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xA647AB12C52750B9ULL + 0xBE987711DED08F21ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xE910A88CF85CE8A7ULL + 0x93CDCA1F2CE09542ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xACF42CEAE2E843FDULL + 0x86D280B0BDEA77CCULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xEC3CFCD13740F44BULL + 0xB36F31AC89378335ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xD09CA3D568DD2827ULL + 0xAD098265180E1041ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xF8F15408B279C52FULL + 0xECC49F468C8E86F9ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0x9040EAA500F542D3ULL + 0x87E631C9452ABADEULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xAB76B0DF057D12CBULL + 0x967628C05CC8A66EULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xA76AB8E8B5A93FB9ULL + 0x91C4ABDE262F28F3ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xF6449EF8F5B45D2FULL + 0xD1920550DBA07837ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xEDEF013B68D0163BULL + 0xBAE4333DEF67E852ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xB92F32124FA36FC5ULL + 0x8069EF2581891E8EULL);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 7774U)) & S_BLOCK1], 19U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 2127U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 7785U)) & S_BLOCK1], 41U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 6525U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aPrevious, 57U) ^ RotL64(aCross, 42U)) ^ (RotL64(aCarry, 5U) + RotL64(aIngress, 29U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterG = (aWandererH + RotL64(aIngress, 53U)) + 14179205183062705133U;
            aOrbiterJ = (aWandererK + RotL64(aScatter, 19U)) + 210032324058740920U;
            aOrbiterE = ((aWandererI + RotL64(aPrevious, 57U)) + 7387115089142500152U) + aOrbiterAssignSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterD = ((aWandererJ + RotL64(aCross, 24U)) + RotL64(aCarry, 37U)) + 17583362781238061430U;
            aOrbiterB = ((aWandererD + RotL64(aScatter, 13U)) + RotL64(aCarry, 53U)) + 4991442849150005943U;
            aOrbiterC = (((aWandererB + RotL64(aIngress, 41U)) + RotL64(aCarry, 5U)) + 2891376254689854555U) + aOrbiterAssignSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = (aWandererE + RotL64(aCross, 29U)) + 10523274382407446239U;
            aOrbiterI = ((aWandererA + RotL64(aPrevious, 37U)) + 3861893764676218667U) + aNonceWordJ;
            aOrbiterF = ((aWandererG + RotL64(aCross, 6U)) + 3366674459852093746U) + aNonceWordB;
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 5898492634386601145U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 7047353571244768721U;
            aOrbiterE = RotL64((aOrbiterE * 2257518291062508467U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 14374108805453186316U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 8763667021501226510U;
            aOrbiterB = RotL64((aOrbiterB * 7694695426430267863U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 18261523829316379575U) + aOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 650477532238860965U) ^ aNonceWordM;
            aOrbiterH = RotL64((aOrbiterH * 8291758490821819851U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 2162326554604894042U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 5776546692501825278U;
            aOrbiterC = RotL64((aOrbiterC * 14911545784585246537U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 3501863793638415049U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 14853789267425352958U;
            aOrbiterI = RotL64((aOrbiterI * 10590325397179928739U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 15399673014671329743U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 12253428583438990426U;
            aOrbiterJ = RotL64((aOrbiterJ * 12052855472196447849U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 13202953937621953839U) + aNonceWordN;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 7547616636832698398U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 9533399972562428073U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 15709801946594868318U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 12458677982746610971U;
            aOrbiterF = RotL64((aOrbiterF * 6662570874316418993U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 6957370791367530127U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 10511379961344950861U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 15551333099264031337U), 57U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterB, 58U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 39U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 19U));
            aIngress = aIngress + (RotL64(aOrbiterC, 3U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterH, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aIngress, 14U) + RotL64(aOrbiterC, 19U)) + aOrbiterI);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 35U) + aOrbiterF) + RotL64(aOrbiterB, 23U)) + aWandererUpdateSaltC[((aIndex + 25U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aScatter, 3U) + RotL64(aOrbiterF, 14U)) + aOrbiterE);
            aWandererH = aWandererH ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterG, 47U)) + aOrbiterD);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 39U) + aOrbiterF) + RotL64(aOrbiterC, 5U)) + RotL64(aCarry, 39U)) + aNonceWordO);
            aWandererK = aWandererK ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterD, 41U)) + aOrbiterF);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 47U) + aOrbiterD) + RotL64(aOrbiterH, 60U)) + RotL64(aCarry, 53U)) + aNonceWordG);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 56U) + RotL64(aOrbiterI, 53U)) + aOrbiterJ);
            aWandererI = aWandererI + (((RotL64(aPrevious, 23U) + RotL64(aOrbiterD, 37U)) + aOrbiterC) + aWandererUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 39U) ^ aWandererA);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 43U));
            aCarry = aCarry + (RotL64(aWandererG, 26U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererE, 47U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererD, 11U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 14273U)) & S_BLOCK1], 36U) ^ RotL64(aFireLaneB[((aIndex + 9159U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 8650U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 11333U)) & S_BLOCK1], 51U) ^ RotL64(aFireLaneD[((aIndex + 10011U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCarry, 36U) + RotL64(aIngress, 3U)) ^ (RotL64(aPrevious, 23U) + RotL64(aCross, 51U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterA = ((aWandererI + RotL64(aIngress, 19U)) + RotL64(aCarry, 13U)) + 3550722402315312207U;
            aOrbiterG = ((aWandererK + RotL64(aCross, 23U)) + RotL64(aCarry, 23U)) + 16724184551669522754U;
            aOrbiterF = (((aWandererG + RotL64(aScatter, 37U)) + RotL64(aCarry, 39U)) + 981751330116773021U) + aNonceWordH;
            aOrbiterB = ((aWandererE + RotL64(aPrevious, 12U)) + 7891159229704944868U) + aNonceWordE;
            aOrbiterE = ((aWandererH + RotL64(aIngress, 29U)) + 13618396711464799841U) + aOrbiterAssignSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterK = ((aWandererB + RotL64(aScatter, 3U)) + 5969291018449003648U) + aNonceWordD;
            aOrbiterD = (aWandererA + RotL64(aCross, 51U)) + 14595540413313640042U;
            aOrbiterH = (((aWandererJ + RotL64(aPrevious, 46U)) + 3287990436916111762U) + aOrbiterAssignSaltB[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordL;
            aOrbiterJ = (aWandererF + RotL64(aIngress, 41U)) + 12534369400200483704U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 2277312067930392274U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 10026320559261334353U) ^ aNonceWordC;
            aOrbiterF = RotL64((aOrbiterF * 11020464940995912637U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 11258082063135659551U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 1445958517675746990U;
            aOrbiterE = RotL64((aOrbiterE * 10062265337488757971U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 1011298251290970844U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 6487834862470043744U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 15477913837027179675U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 9966279022928268335U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 10285993486057704393U;
            aOrbiterD = RotL64((aOrbiterD * 15965714363201157535U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 16005362468813966136U) + aNonceWordB;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 223843444699390781U) ^ aOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 665392038954573081U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 18178876294968532775U) + aNonceWordO;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 12490136112181806806U) ^ aOrbiterUpdateSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 16380841616662993709U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 8775696166557913635U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 16464340319444310842U;
            aOrbiterG = RotL64((aOrbiterG * 18111632334728200721U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 6296039992673546227U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 7152939277656436037U;
            aOrbiterB = RotL64((aOrbiterB * 15183918431501487319U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 14066791413416223271U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 5026743227399908016U;
            aOrbiterA = RotL64((aOrbiterA * 5891343232759075675U), 43U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterD, 44U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 51U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 27U));
            aIngress = aIngress + (RotL64(aOrbiterF, 3U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterK, 38U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((((RotL64(aPrevious, 5U) + aOrbiterD) + RotL64(aOrbiterH, 5U)) + aNonceWordK) + aWandererUpdateSaltB[((aIndex + 15U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aCross, 51U) + RotL64(aOrbiterE, 43U)) + aOrbiterG) + RotL64(aCarry, 47U)) + aWandererUpdateSaltA[((aIndex + 13U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterD, 18U)) + aOrbiterJ);
            aWandererH = aWandererH + ((RotL64(aIngress, 27U) + aOrbiterD) + RotL64(aOrbiterK, 11U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 58U) + aOrbiterJ) + RotL64(aOrbiterF, 47U)) + aNonceWordF);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 39U) + aOrbiterF) + RotL64(aOrbiterB, 53U)) + RotL64(aCarry, 21U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterE, 29U)) + aOrbiterH);
            aWandererI = aWandererI + ((RotL64(aScatter, 23U) + aOrbiterG) + RotL64(aOrbiterA, 22U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 12U) + RotL64(aOrbiterH, 57U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + (RotL64(aWandererG, 14U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererF, 23U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererK, 39U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererH, 19U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 21324U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneD[((aIndex + 23954U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 21729U)) & S_BLOCK1], 56U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 20444U)) & S_BLOCK1], 53U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 18375U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aFireLaneC[((aIndex + 21720U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCross, 35U) + RotL64(aIngress, 60U)) ^ (RotL64(aPrevious, 11U) + RotL64(aCarry, 47U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterH = (aWandererH + RotL64(aScatter, 6U)) + 12122689833405846292U;
            aOrbiterK = (((aWandererC + RotL64(aCross, 47U)) + RotL64(aCarry, 5U)) + 9640400270962766788U) + aNonceWordC;
            aOrbiterD = (aWandererD + RotL64(aPrevious, 41U)) + 9141937998266739071U;
            aOrbiterI = ((aWandererE + RotL64(aIngress, 13U)) + RotL64(aCarry, 51U)) + 12899395770434090537U;
            aOrbiterF = (aWandererB + RotL64(aScatter, 57U)) + 13457918115408031842U;
            aOrbiterJ = ((aWandererF + RotL64(aCross, 19U)) + 15134784483576000943U) + aOrbiterAssignSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterG = ((aWandererK + RotL64(aIngress, 37U)) + 12540961268790055438U) + aNonceWordB;
            aOrbiterB = ((((aWandererG + RotL64(aPrevious, 29U)) + RotL64(aCarry, 13U)) + 6306886773092764230U) + aOrbiterAssignSaltA[((aIndex + 12U)) & S_SALT1]) + aNonceWordE;
            aOrbiterE = (aWandererI + RotL64(aScatter, 24U)) + 13573343491337243121U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 8545588657348974413U) + aNonceWordD;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 10891410570357275120U;
            aOrbiterD = RotL64((aOrbiterD * 5399310978367842841U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 2877137119767060151U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 9178097682386595144U) ^ aNonceWordF;
            aOrbiterJ = RotL64((aOrbiterJ * 3524486002084427513U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 15528007881855616978U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 11368419529245281435U;
            aOrbiterB = RotL64((aOrbiterB * 12433207037378339309U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 5932738914934356645U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 5551842263864055419U;
            aOrbiterG = RotL64((aOrbiterG * 16093776759971522681U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 3824433359595690603U) + aOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 17184628855571662441U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 691208053136187317U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 8724462245014132623U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 7481349499528092352U) ^ aOrbiterUpdateSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8212182934509617583U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 6908362960248294718U) + aNonceWordL;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 5354057969992655314U;
            aOrbiterE = RotL64((aOrbiterE * 16586084885820679343U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 11138301629323903147U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 14164180536320940750U;
            aOrbiterH = RotL64((aOrbiterH * 9099767681053390287U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 709942920176922902U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 17128241237359414945U;
            aOrbiterI = RotL64((aOrbiterI * 14063385518459963529U), 27U);
            //
            aIngress = RotL64(aOrbiterI, 47U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 5U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 27U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 57U));
            aIngress = aIngress + RotL64(aOrbiterK, 60U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aScatter, 11U) + aOrbiterH) + RotL64(aOrbiterD, 52U));
            aWandererF = aWandererF + ((RotL64(aCross, 39U) + RotL64(aOrbiterI, 19U)) + aOrbiterF);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 20U) + RotL64(aOrbiterD, 3U)) + aOrbiterK) + aNonceWordM);
            aWandererB = aWandererB + ((((RotL64(aIngress, 27U) + aOrbiterB) + RotL64(aOrbiterI, 11U)) + RotL64(aCarry, 3U)) + aWandererUpdateSaltE[((aIndex + 21U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 57U) + aOrbiterJ) + RotL64(aOrbiterF, 43U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterH, 47U)) + aOrbiterG) + RotL64(aCarry, 35U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterE, 34U)) + aOrbiterD) + aNonceWordA);
            aWandererH = aWandererH + (((RotL64(aIngress, 48U) + RotL64(aOrbiterE, 29U)) + aOrbiterF) + aWandererUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterD, 23U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 11U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 41U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 34U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 21U));
            aCarry = aCarry + RotL64(aWandererC, 53U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 26156U)) & S_BLOCK1], 23U) ^ RotL64(aFireLaneC[((aIndex + 27707U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aOperationLaneA[((aIndex + 28847U)) & S_BLOCK1], 58U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 26786U)) & S_BLOCK1], 19U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 30546U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 31144U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aPrevious, 47U) ^ RotL64(aCross, 35U)) + (RotL64(aIngress, 60U) ^ RotL64(aCarry, 21U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterA = (((aWandererI + RotL64(aIngress, 43U)) + 12131317914288566437U) + aOrbiterAssignSaltD[((aIndex + 19U)) & S_SALT1]) + aNonceWordM;
            aOrbiterD = ((aWandererJ + RotL64(aPrevious, 53U)) + RotL64(aCarry, 57U)) + 5672805657999385496U;
            aOrbiterH = (aWandererH + RotL64(aScatter, 13U)) + 3581710244233124197U;
            aOrbiterB = ((aWandererE + RotL64(aCross, 4U)) + 15251296040538489436U) + aOrbiterAssignSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = ((aWandererA + RotL64(aIngress, 39U)) + 11295008604679904153U) + aNonceWordN;
            aOrbiterI = (((aWandererD + RotL64(aCross, 47U)) + RotL64(aCarry, 11U)) + 2230897493419504490U) + aNonceWordB;
            aOrbiterE = ((aWandererC + RotL64(aScatter, 27U)) + RotL64(aCarry, 23U)) + 7109600123297458999U;
            aOrbiterG = (aWandererF + RotL64(aPrevious, 19U)) + 13119156643107683803U;
            aOrbiterJ = (aWandererG + RotL64(aIngress, 34U)) + 14755160867807355250U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 16829363373287496832U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 16981122946707720883U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5394974422201576627U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 8806000776958603317U) + aNonceWordH;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 16810923047720876014U;
            aOrbiterA = RotL64((aOrbiterA * 17872735050219539145U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 8129657889554436328U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 8653100378491974463U) ^ aOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 11395283153912468661U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 17048985838727432415U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 10892675550889823573U;
            aOrbiterK = RotL64((aOrbiterK * 976298937314081913U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 15960158965421254346U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 12290011578634850001U;
            aOrbiterJ = RotL64((aOrbiterJ * 9280475585104357745U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 16265047040311479093U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 10312956912303656248U;
            aOrbiterB = RotL64((aOrbiterB * 3012584393253845131U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 16706890352221352779U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 10630955894218491929U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12675937483456206355U), 57U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterB) + 4009352551041162434U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordK;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 3043810773683888556U;
            aOrbiterI = RotL64((aOrbiterI * 4328135390387997315U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 1398071019814944785U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 16689766557488135301U;
            aOrbiterD = RotL64((aOrbiterD * 8403881916549404871U), 11U);
            //
            aIngress = RotL64(aOrbiterH, 47U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 11U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 40U));
            aIngress = aIngress + (RotL64(aOrbiterG, 27U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterA, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aScatter, 56U) + aOrbiterG) + RotL64(aOrbiterK, 5U)) + RotL64(aCarry, 11U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterB, 43U)) + aOrbiterI);
            aWandererH = aWandererH + (((RotL64(aCross, 3U) + aOrbiterJ) + RotL64(aOrbiterE, 50U)) + RotL64(aCarry, 53U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 11U) + RotL64(aOrbiterA, 35U)) + aOrbiterD) + aWandererUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aPrevious, 35U) + RotL64(aOrbiterG, 39U)) + aOrbiterJ);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 19U) + aOrbiterK) + RotL64(aOrbiterI, 13U)) + aNonceWordE);
            aWandererF = aWandererF + (((RotL64(aScatter, 27U) + RotL64(aOrbiterK, 23U)) + aOrbiterB) + aWandererUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aCross, 47U) + aOrbiterD) + RotL64(aOrbiterG, 30U)) + aNonceWordL);
            aWandererG = aWandererG + ((RotL64(aPrevious, 52U) + aOrbiterB) + RotL64(aOrbiterH, 19U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 58U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererJ, 5U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererE, 19U) ^ aWandererI);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 29U));
            aCarry = aCarry + RotL64(aWandererF, 39U);
            aCarry = aCarry + RotL64(aIngress, 10U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xFF7F0A82B3FF7CA3ULL + 0xCF547D3B44883386ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x95D4E7012210699DULL + 0xA779F31E3B27D16BULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xD37AFDAA03EC3DB7ULL + 0xC313BD30980CBB2CULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xDE9A81FCB2C26B3BULL + 0xDC908F702D36CB9CULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x974880F7465CA41FULL + 0xF485C19B52475ED0ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x97BCF3C357FEB237ULL + 0xC3BDF5BEFA6665EFULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x89881A6E2089C62FULL + 0x9340FADBA1C54002ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x8D7AD0A1D9186981ULL + 0xFB8F23FBFDDEA656ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x8C81FE0DA2787597ULL + 0x9B709207AB98D847ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xDA29971B249FC487ULL + 0x8A82B8F61A24F107ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xD634806F6D09FAC5ULL + 0xC8803B0BC8D3EBDEULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xD137056AE630F855ULL + 0xED47B448B9B810C9ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0x815AD6E74C62CAB9ULL + 0xEF9A30439EA9A3F0ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xD1E3B475C65057D5ULL + 0xB78E6D0139775E3CULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xB8A9926BCE9C74F9ULL + 0xF284D60AEBD7EE6AULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xD1A48A3A93C926FBULL + 0xA8B381FA4029AF65ULL);
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
        // read from: aOperationLaneA, aOperationLaneB, aFireLaneA, aOperationLaneC, aOperationLaneD, aWorkLaneA, aFireLaneC, aWorkLaneB, aFireLaneD, aWorkLaneC, aFireLaneB
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 5498U)) & S_BLOCK1], 10U) ^ RotL64(aOperationLaneB[((aIndex + 331U)) & S_BLOCK1], 41U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 2982U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 6111U)) & S_BLOCK1], 48U) ^ RotL64(aOperationLaneD[((aIndex + 5066U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aIngress, 36U) ^ RotL64(aCarry, 53U)) + (RotL64(aCross, 23U) + RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterJ = ((aWandererI + RotL64(aPrevious, 41U)) + 9855743441035905047U) + aNonceWordJ;
            aOrbiterC = (((aWandererK + RotL64(aScatter, 57U)) + RotL64(aCarry, 57U)) + 8426286937143990276U) + aNonceWordF;
            aOrbiterH = (((aWandererE + RotL64(aCross, 3U)) + RotL64(aCarry, 43U)) + 7146752367170267002U) + aOrbiterAssignSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterK = (aWandererH + RotL64(aIngress, 12U)) + 12947210066678101726U;
            aOrbiterB = ((((aWandererJ + RotL64(aPrevious, 21U)) + RotL64(aCarry, 27U)) + 15902163559925328965U) + aOrbiterAssignSaltB[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordD;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 8506649889346449469U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 8226286036430263052U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7264199281303956141U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 2703047093452420216U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 6769351326360139560U) ^ aNonceWordO;
            aOrbiterB = RotL64((aOrbiterB * 5318104980014706265U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 9857025533281333281U) + aOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 238297452132277585U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 12974709749856065985U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 7203572312072908931U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 12497027346166575632U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 1703586436725662307U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 473851890609048879U) + aNonceWordE;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 1664484956453886047U) ^ aNonceWordG;
            aOrbiterC = RotL64((aOrbiterC * 8566500756326590209U), 57U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterJ, 14U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 43U));
            aIngress = aIngress + RotL64(aOrbiterB, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((((RotL64(aIngress, 3U) + RotL64(aOrbiterK, 35U)) + aOrbiterC) + aNonceWordC) + aWandererUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 29U) + RotL64(aOrbiterB, 52U)) + aOrbiterH) + RotL64(aCarry, 39U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 39U) + RotL64(aOrbiterJ, 3U)) + aOrbiterH) + aNonceWordA);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 21U) + RotL64(aOrbiterB, 11U)) + aOrbiterC) + RotL64(aCarry, 11U)) + aNonceWordN);
            aWandererI = aWandererI ^ ((((RotL64(aIngress, 12U) + aOrbiterJ) + RotL64(aOrbiterB, 19U)) + aNonceWordB) + aWandererUpdateSaltF[((aIndex + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 60U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 5U));
            aCarry = aCarry + RotL64(aWandererH, 29U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 8928U)) & S_BLOCK1], 6U) ^ RotL64(aOperationLaneC[((aIndex + 16287U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 13426U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 14132U)) & S_BLOCK1], 42U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 12939U)) & S_BLOCK1], 53U));
            aCross ^= RotL64(aOperationLaneB[((aIndex + 11208U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aIngress, 35U) ^ RotL64(aCross, 47U)) + (RotL64(aCarry, 21U) + RotL64(aPrevious, 60U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterA = (((aWandererB + RotL64(aPrevious, 27U)) + RotL64(aCarry, 41U)) + 826930775230515406U) + aNonceWordC;
            aOrbiterD = (((aWandererE + RotL64(aIngress, 19U)) + RotL64(aCarry, 11U)) + 5137814617363250861U) + aNonceWordA;
            aOrbiterF = ((aWandererA + RotL64(aCross, 40U)) + 14761561947426681616U) + aOrbiterAssignSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = ((aWandererI + RotL64(aScatter, 11U)) + RotL64(aCarry, 57U)) + 12773023438753662590U;
            aOrbiterE = (((aWandererJ + RotL64(aIngress, 57U)) + 7331345852207096322U) + aOrbiterAssignSaltF[((aIndex + 23U)) & S_SALT1]) + aNonceWordN;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 3899381212671247460U) + aOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 10072004147620068599U) ^ aNonceWordL;
            aOrbiterF = RotL64((aOrbiterF * 5663583566047763435U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 3424585039401897560U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterD) ^ 8246760141625966321U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterE = RotL64((aOrbiterE * 11478879365443736383U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 3655992860610853290U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 11154618022505863898U;
            aOrbiterD = RotL64((aOrbiterD * 4791494171286145231U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 15629361991059709973U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 10842068502278489664U) ^ aOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 17223002513104960799U), 37U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterF) + 5571312349016336686U) + aOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 589313823745748879U) ^ aNonceWordK;
            aOrbiterA = RotL64((aOrbiterA * 1356685926549786027U), 57U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterI, 57U);
            aIngress = aIngress + (RotL64(aOrbiterD, 47U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterE, 22U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 51U) + aOrbiterA) + RotL64(aOrbiterD, 3U)) + RotL64(aCarry, 41U)) + aNonceWordO);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 5U) + aOrbiterE) + RotL64(aOrbiterA, 35U));
            aWandererA = aWandererA + ((((RotL64(aIngress, 27U) + aOrbiterI) + RotL64(aOrbiterF, 51U)) + RotL64(aCarry, 53U)) + aNonceWordP);
            aWandererE = aWandererE ^ ((((RotL64(aCross, 36U) + aOrbiterE) + RotL64(aOrbiterF, 43U)) + aNonceWordM) + aWandererUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aIngress, 13U) + aOrbiterA) + RotL64(aOrbiterF, 18U)) + aNonceWordE) + aWandererUpdateSaltD[((aIndex + 10U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 47U) ^ aWandererA);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 57U));
            aCarry = aCarry + RotL64(aWandererI, 11U);
            aCarry = aCarry + RotL64(aIngress, 28U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 18544U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneD[((aIndex + 21371U)) & S_BLOCK1], 38U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 19401U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21988U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 16454U)) & S_BLOCK1], 20U));
            aCross ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 17966U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aIngress, 11U) ^ RotL64(aCarry, 41U)) ^ (RotL64(aPrevious, 23U) + RotL64(aCross, 54U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterA = (aWandererB + RotL64(aIngress, 3U)) + 10038936806177516123U;
            aOrbiterG = (((aWandererH + RotL64(aPrevious, 23U)) + RotL64(aCarry, 47U)) + 1773168435195292638U) + aOrbiterAssignSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterD = ((((aWandererC + RotL64(aScatter, 47U)) + RotL64(aCarry, 11U)) + 10655711161526628072U) + aOrbiterAssignSaltA[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordK;
            aOrbiterB = (((aWandererK + RotL64(aCross, 35U)) + RotL64(aCarry, 27U)) + 14422295664639740437U) + aNonceWordB;
            aOrbiterH = ((aWandererE + RotL64(aIngress, 56U)) + 4125228715513159576U) + aNonceWordO;
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 3670449653158650845U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 17553727567180813057U) ^ aOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 11814335762020146785U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 5111401772713882743U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 7688573124662314413U;
            aOrbiterB = RotL64((aOrbiterB * 10846442063022821393U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 9438375825507814395U) + aNonceWordE;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 14177477039902118886U) ^ aOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 6467406626985022537U), 3U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterH) + 16329942595859623928U) + aOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1]) + aNonceWordG;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 3990536794006836672U;
            aOrbiterA = RotL64((aOrbiterA * 579024714339065373U), 47U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterA) + 5072881436583180756U) + aOrbiterUpdateSaltC[((aIndex + 16U)) & S_SALT1]) + aNonceWordP;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 16789727877867289997U;
            aOrbiterG = RotL64((aOrbiterG * 8766246302636197905U), 21U);
            //
            aIngress = RotL64(aOrbiterH, 19U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterB, 29U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterA, 52U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aCross, 54U) + aOrbiterH) + RotL64(aOrbiterD, 21U)) + RotL64(aCarry, 27U)) + aWandererUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 19U) + RotL64(aOrbiterB, 35U)) + aOrbiterD) + aNonceWordA);
            aWandererC = aWandererC + ((((RotL64(aScatter, 35U) + RotL64(aOrbiterG, 57U)) + aOrbiterD) + RotL64(aCarry, 39U)) + aNonceWordF);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 43U) + aOrbiterA) + RotL64(aOrbiterG, 48U)) + aWandererUpdateSaltB[((aIndex + 7U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aScatter, 27U) + RotL64(aOrbiterA, 13U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererH, 37U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererE, 27U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererC, 47U);
            aCarry = aCarry + RotL64(aIngress, 14U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // kdf_a_loop_c loop 4
        // ingress from: aWorkLaneC, aWorkLaneA, aFireLaneB
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aFireLaneB forward/backward random
        // cross from: aWorkLaneB, aOperationLaneC, aOperationLaneD, aOperationLaneA
        // cross directions: aWorkLaneB backward forced, aOperationLaneC backward forced, aOperationLaneD backward forced, aOperationLaneA backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 31304U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneA[((aIndex + 30047U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 30964U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 29425U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 27062U)) & S_BLOCK1], 19U));
            aCross ^= (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 30057U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneA[((aIndex + 29034U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCarry, 57U) ^ RotL64(aIngress, 41U)) + (RotL64(aPrevious, 5U) + RotL64(aCross, 18U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterG = (aWandererK + RotL64(aScatter, 47U)) + 5697928251815176134U;
            aOrbiterJ = (((aWandererJ + RotL64(aCross, 24U)) + 337587740689259575U) + aOrbiterAssignSaltD[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordA;
            aOrbiterB = (((aWandererE + RotL64(aIngress, 3U)) + RotL64(aCarry, 43U)) + 4927686903263973950U) + aNonceWordI;
            aOrbiterI = ((((aWandererH + RotL64(aPrevious, 13U)) + RotL64(aCarry, 57U)) + 3742409032569801033U) + aOrbiterAssignSaltB[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordL;
            aOrbiterD = (((aWandererF + RotL64(aScatter, 37U)) + RotL64(aCarry, 21U)) + 1608092659172197650U) + aNonceWordJ;
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 15848744267145717509U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 15300174177963339253U) ^ aOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5771922862677667319U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 14162868453323648628U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterJ) ^ 12020167069983729869U) ^ aOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterI = RotL64((aOrbiterI * 2071080217680099017U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 16259538291658723956U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 8516686212464112245U) ^ aOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 4731296903548893627U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 3722184575520553132U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterB) ^ 5663609293306386784U) ^ aOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterD = RotL64((aOrbiterD * 14364218128780764749U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 15265344442454471986U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 3050323350098829515U;
            aOrbiterJ = RotL64((aOrbiterJ * 5890624677162388135U), 5U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterI, 19U);
            aIngress = aIngress + (RotL64(aOrbiterD, 57U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterB, 4U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterJ, 50U)) + aOrbiterB);
            aWandererK = aWandererK + (((RotL64(aIngress, 40U) + aOrbiterB) + RotL64(aOrbiterI, 19U)) + RotL64(aCarry, 47U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 27U) + RotL64(aOrbiterD, 3U)) + aOrbiterG) + aWandererUpdateSaltF[((aIndex + 15U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aScatter, 3U) + RotL64(aOrbiterD, 37U)) + aOrbiterI) + RotL64(aCarry, 35U)) + aNonceWordM);
            aWandererJ = aWandererJ ^ ((((RotL64(aCross, 53U) + aOrbiterI) + RotL64(aOrbiterJ, 27U)) + aNonceWordP) + aWandererUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 56U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + RotL64(aWandererK, 39U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterE = 0;
    std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
    std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xF7DF4E7CC43BC4E7ULL + 0xAF018B32A701D9DFULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xF7D96FA86F6E9FFBULL + 0xAD5C49CFF35FC0C4ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xADF07F5916557337ULL + 0xC83422C7E87E8D12ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x9ED157523BBE158BULL + 0xEEB0A2F7C6C34C1BULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x83EAE39ABCBB0BFBULL + 0xD749FEC84766668FULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xDAFA6E9CC74029C7ULL + 0xE0FDB97583457358ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x9D3BCF68F2CF4E0DULL + 0xABF8C93C38B49929ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xB55AC86AAD4DFEABULL + 0xEB63D0B0CAC4D0FFULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x875503CC839AE285ULL + 0xCBEC32C57099FE0CULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xB4A752A080052BD5ULL + 0xF0BCB4521FE2D7AFULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xAF4C81598B01CA29ULL + 0xB63ED8F4EDC0AF64ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xE7119423368CDF6DULL + 0xB2991211AC3F70D8ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xD4B36AA2BDF36D27ULL + 0xF9EF719AD3CF6DB9ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x99388AB93B4BA7DDULL + 0xE31AB56CAFB7D77FULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x93E4F4366AF97A65ULL + 0x8B2F3C2621B51D3BULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xD1C365B9D4186205ULL + 0x86F564BF85DC0FB1ULL);
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
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneD, aExpandLaneC, aExpandLaneD, aOperationLaneD, aWorkLaneA, aOperationLaneB, aFireLaneA, aWorkLaneB, aFireLaneC, aFireLaneB, aWorkLaneC, aOperationLaneC, aOperationLaneA
        // write to: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // kdf_a_loop_d loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aFireLaneD
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aFireLaneD forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD, aOperationLaneD
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward forced, aOperationLaneD backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 7033U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneB[((aIndex + 4798U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 6622U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4771U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 1032U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 4380U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aPrevious, 54U)) + (RotL64(aCarry, 19U) + RotL64(aIngress, 37U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterG = (((aWandererH + RotL64(aScatter, 39U)) + RotL64(aCarry, 53U)) + 18191288703716505885U) + aOrbiterAssignSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = ((aWandererI + RotL64(aPrevious, 47U)) + 9824014524910417136U) + aOrbiterAssignSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = ((aWandererA + RotL64(aIngress, 6U)) + RotL64(aCarry, 3U)) + 11953012029254917548U;
            aOrbiterH = ((aWandererK + RotL64(aCross, 29U)) + 6297568011027199089U) + aNonceWordL;
            aOrbiterI = ((aWandererC + RotL64(aScatter, 23U)) + 2576999400457367975U) + aNonceWordG;
            aOrbiterF = ((aWandererB + RotL64(aIngress, 13U)) + 13176139160575558254U) + aNonceWordC;
            aOrbiterA = (((aWandererG + RotL64(aCross, 57U)) + RotL64(aCarry, 41U)) + 9978408174563621810U) + aNonceWordI;
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 16765834875061607142U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 16534507305459121344U;
            aOrbiterE = RotL64((aOrbiterE * 8943988574248229067U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 3114710944346151807U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 10240517868726718592U;
            aOrbiterI = RotL64((aOrbiterI * 4645691562915606463U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 10721450637990777883U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 16689590768796583952U) ^ aNonceWordO;
            aOrbiterJ = RotL64((aOrbiterJ * 3046344179729901637U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 2427422768928450209U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 13495584061816457831U;
            aOrbiterF = RotL64((aOrbiterF * 6670984773768885119U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 7058636403765106682U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterJ) ^ 9897341853944713767U) ^ aOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterH = RotL64((aOrbiterH * 14286816859999869231U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 17749559755733386064U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 12515645083926326659U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 6582878478865838245U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 2625692458813609962U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 10596240255026143019U;
            aOrbiterG = RotL64((aOrbiterG * 11605800195771080135U), 5U);
            //
            aIngress = RotL64(aOrbiterG, 5U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterH, 41U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 47U));
            aIngress = aIngress + RotL64(aOrbiterF, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterG, 57U)) + aOrbiterE);
            aWandererC = aWandererC + ((((RotL64(aScatter, 47U) + aOrbiterA) + RotL64(aOrbiterJ, 22U)) + RotL64(aCarry, 13U)) + aNonceWordH);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 41U) + RotL64(aOrbiterA, 11U)) + aOrbiterF) + aNonceWordF);
            aWandererK = aWandererK + (((RotL64(aIngress, 27U) + aOrbiterH) + RotL64(aOrbiterF, 29U)) + aWandererUpdateSaltB[((aIndex + 11U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterF, 51U)) + aOrbiterE) + aNonceWordE);
            aWandererI = aWandererI + (((RotL64(aIngress, 34U) + RotL64(aOrbiterG, 5U)) + aOrbiterJ) + RotL64(aCarry, 57U));
            aWandererB = aWandererB ^ ((((RotL64(aCross, 11U) + aOrbiterA) + RotL64(aOrbiterI, 41U)) + aNonceWordM) + aWandererUpdateSaltE[((aIndex + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 35U));
            aCarry = aCarry + (RotL64(aWandererB, 23U) ^ aWandererI);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 60U));
            aCarry = aCarry + RotL64(aWandererH, 43U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 2
        // ingress from: aWorkLaneA, aExpandLaneC, aOperationLaneB
        // ingress directions: aWorkLaneA forward forced, aExpandLaneC forward forced, aOperationLaneB forward/backward random
        // cross from: aExpandLaneA, aExpandLaneD, aFireLaneA
        // cross directions: aExpandLaneA backward forced, aExpandLaneD backward forced, aFireLaneA backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 8528U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneC[((aIndex + 13086U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aOperationLaneB[((aIndex + 8708U)) & S_BLOCK1], 60U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 12881U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 15403U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 12183U)) & S_BLOCK1], 36U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCarry, 40U)) ^ (RotL64(aPrevious, 23U) + RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterH = (((aWandererB + RotL64(aIngress, 19U)) + 16424657151168221875U) + aOrbiterAssignSaltC[((aIndex + 27U)) & S_SALT1]) + aNonceWordK;
            aOrbiterC = (aWandererJ + RotL64(aPrevious, 27U)) + 17150123681886380361U;
            aOrbiterE = ((aWandererG + RotL64(aScatter, 60U)) + RotL64(aCarry, 39U)) + 16041993588694572757U;
            aOrbiterI = (aWandererC + RotL64(aCross, 11U)) + 9871185846434828537U;
            aOrbiterB = (((aWandererI + RotL64(aIngress, 53U)) + RotL64(aCarry, 53U)) + 11227236398354430757U) + aOrbiterAssignSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterF = (((aWandererH + RotL64(aPrevious, 43U)) + RotL64(aCarry, 19U)) + 5399325217402192631U) + aNonceWordN;
            aOrbiterA = ((aWandererK + RotL64(aCross, 5U)) + 9248828789282890454U) + aNonceWordD;
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 9041370494203701062U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 14944424084524970764U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 10283363059424655079U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 5481938174456671041U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 14783648629543752715U) ^ aOrbiterUpdateSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 7260164783191886395U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 12355573914530445723U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterF) ^ 9863991559011968318U) ^ aOrbiterUpdateSaltF[((aIndex + 12U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterC = RotL64((aOrbiterC * 8495251211794343179U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 16149688605937250965U) + aNonceWordM;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 106041828692026825U;
            aOrbiterI = RotL64((aOrbiterI * 12199934305374582599U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 8076098639554567792U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 11155119311895580013U) ^ aNonceWordF;
            aOrbiterA = RotL64((aOrbiterA * 1495180896564818647U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 6847612160595917702U) + aNonceWordA;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 16094377920388017367U;
            aOrbiterH = RotL64((aOrbiterH * 4875801863643206333U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 13584719866672696684U) + aOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 13446209321646234607U;
            aOrbiterF = RotL64((aOrbiterF * 9945349065094781529U), 11U);
            //
            aIngress = RotL64(aOrbiterF, 44U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 5U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 51U));
            aIngress = aIngress + RotL64(aOrbiterH, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 47U) + aOrbiterF) + RotL64(aOrbiterB, 21U));
            aWandererJ = aWandererJ + (((((RotL64(aScatter, 41U) + RotL64(aOrbiterA, 43U)) + aOrbiterE) + RotL64(aCarry, 29U)) + aNonceWordI) + aWandererUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aCross, 35U) + aOrbiterB) + RotL64(aOrbiterC, 13U)) + aNonceWordL);
            aWandererG = aWandererG + ((((RotL64(aIngress, 53U) + RotL64(aOrbiterF, 27U)) + aOrbiterI) + RotL64(aCarry, 51U)) + aNonceWordH);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterH, 3U)) + aOrbiterC);
            aWandererK = aWandererK + ((RotL64(aCross, 4U) + RotL64(aOrbiterH, 52U)) + aOrbiterI);
            aWandererI = aWandererI ^ ((((RotL64(aPrevious, 19U) + aOrbiterC) + RotL64(aOrbiterA, 37U)) + aNonceWordP) + aWandererUpdateSaltD[((aIndex + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 4U));
            aCarry = aCarry + (RotL64(aWandererB, 13U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererC, 57U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererG, 29U);
            aCarry = aCarry + RotL64(aIngress, 34U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 3
        // ingress from: aWorkLaneB, aExpandLaneD, aFireLaneC
        // ingress directions: aWorkLaneB forward forced, aExpandLaneD forward forced, aFireLaneC forward/backward random
        // cross from: aWorkLaneA, aExpandLaneB, aFireLaneB
        // cross directions: aWorkLaneA backward forced, aExpandLaneB backward forced, aFireLaneB backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 20164U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneD[((aIndex + 23547U)) & S_BLOCK1], 40U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 19620U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16814U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 19353U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 22324U)) & S_BLOCK1], 60U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aIngress, 41U) + RotL64(aCarry, 11U)) ^ (RotL64(aPrevious, 24U) ^ RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterB = ((aWandererK + RotL64(aCross, 5U)) + RotL64(aCarry, 43U)) + 9446153639709651566U;
            aOrbiterA = (aWandererH + RotL64(aScatter, 60U)) + 10550762260670758167U;
            aOrbiterC = (((aWandererB + RotL64(aPrevious, 39U)) + RotL64(aCarry, 5U)) + 7062634922142578383U) + aOrbiterAssignSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterG = ((aWandererG + RotL64(aIngress, 51U)) + 9178499097812764515U) + aNonceWordF;
            aOrbiterE = ((((aWandererJ + RotL64(aScatter, 23U)) + RotL64(aCarry, 23U)) + 6887103379773525538U) + aOrbiterAssignSaltF[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordH;
            aOrbiterF = (aWandererE + RotL64(aIngress, 11U)) + 6239750312052010257U;
            aOrbiterH = (aWandererF + RotL64(aPrevious, 29U)) + 17645022614523287959U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 3639618183259408272U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 3131737117548745095U;
            aOrbiterC = RotL64((aOrbiterC * 6585057380704940395U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 7253994382396406554U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 15217993711938379561U;
            aOrbiterG = RotL64((aOrbiterG * 17853313384747259923U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 12594152227603630033U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 11250170200489647869U) ^ aNonceWordD;
            aOrbiterH = RotL64((aOrbiterH * 546800378327864723U), 51U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterE) + 12936942656624279424U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1]) + aNonceWordM;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 10990736056052106149U;
            aOrbiterF = RotL64((aOrbiterF * 7123916809953459187U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 12787293075893090465U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 17154990205620778151U;
            aOrbiterA = RotL64((aOrbiterA * 10031369940028159521U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 1270827262969060301U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 17337623431665013136U;
            aOrbiterB = RotL64((aOrbiterB * 1517262088236356107U), 41U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 830330490987911853U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 6828309232554560547U;
            aOrbiterE = RotL64((aOrbiterE * 9742464176986145819U), 3U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterE, 11U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 3U));
            aIngress = aIngress + (RotL64(aOrbiterH, 19U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterA, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterB, 27U)) + aOrbiterA);
            aWandererH = aWandererH + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterG, 5U)) + aOrbiterC) + RotL64(aCarry, 3U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 13U) + RotL64(aOrbiterE, 60U)) + aOrbiterH) + aNonceWordA);
            aWandererK = aWandererK + ((((RotL64(aScatter, 53U) + RotL64(aOrbiterG, 21U)) + aOrbiterE) + RotL64(aCarry, 37U)) + aNonceWordP);
            aWandererG = aWandererG ^ ((((RotL64(aIngress, 27U) + RotL64(aOrbiterE, 43U)) + aOrbiterC) + aNonceWordJ) + aWandererUpdateSaltC[((aIndex + 19U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 3U) + RotL64(aOrbiterB, 37U)) + aOrbiterH) + aWandererUpdateSaltF[((aIndex + 24U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 60U) + aOrbiterF) + RotL64(aOrbiterA, 11U)) + aNonceWordN);
            //
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererK, 40U) ^ aWandererF);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 13U));
            aCarry = aCarry + RotL64(aWandererG, 19U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 4
        // ingress from: aWorkLaneC, aWorkLaneA, aOperationLaneC
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aOperationLaneC forward/backward random
        // cross from: aWorkLaneB, aExpandLaneC, aOperationLaneA
        // cross directions: aWorkLaneB backward forced, aExpandLaneC backward forced, aOperationLaneA backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 26882U)) & S_BLOCK1], 48U) ^ RotL64(aWorkLaneA[((aIndex + 26115U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aOperationLaneC[((aIndex + 31209U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 31393U)) & S_BLOCK1], 38U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 25635U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aOperationLaneA[((aIndex + 25834U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCross, 54U)) ^ (RotL64(aPrevious, 41U) + RotL64(aCarry, 27U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterH = (((aWandererG + RotL64(aIngress, 29U)) + 2974056819475622600U) + aOrbiterAssignSaltE[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordK;
            aOrbiterE = (((aWandererA + RotL64(aPrevious, 3U)) + RotL64(aCarry, 29U)) + 7345051759236356098U) + aNonceWordL;
            aOrbiterB = (aWandererE + RotL64(aScatter, 51U)) + 12738468816846628882U;
            aOrbiterJ = ((aWandererD + RotL64(aCross, 35U)) + RotL64(aCarry, 57U)) + 7694520596043297922U;
            aOrbiterC = (((aWandererI + RotL64(aIngress, 43U)) + RotL64(aCarry, 43U)) + 5530753590015084774U) + aNonceWordH;
            aOrbiterK = (aWandererC + RotL64(aCross, 13U)) + 3776309161718383105U;
            aOrbiterG = (((aWandererB + RotL64(aScatter, 22U)) + 784780304358106404U) + aOrbiterAssignSaltB[((aIndex + 14U)) & S_SALT1]) + aNonceWordJ;
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 8999942326995036509U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 5194986506064092779U) ^ aOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 15070787038006135963U), 11U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterH) + 7920040007459652762U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordG;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 11311997270710107937U;
            aOrbiterE = RotL64((aOrbiterE * 6227571709361790209U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 5365231114813547251U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 8630110234623825263U) ^ aOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2735881715888325759U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 2358235238039571072U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 18059414891616491807U;
            aOrbiterH = RotL64((aOrbiterH * 17150786106857185467U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 14526050556461782864U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 6937282036603272474U;
            aOrbiterG = RotL64((aOrbiterG * 14954512365270028029U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 10105832250694931310U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 3884223553012098137U) ^ aNonceWordM;
            aOrbiterJ = RotL64((aOrbiterJ * 16340956813003906195U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 10385284339549648087U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 1257633893341505930U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2669950791270500977U), 53U);
            //
            aIngress = RotL64(aOrbiterG, 41U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 21U));
            aIngress = aIngress + (RotL64(aOrbiterH, 29U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterJ, 58U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aIngress, 21U) + aOrbiterB) + RotL64(aOrbiterG, 51U)) + aWandererUpdateSaltB[((aIndex + 23U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aCross, 3U) + RotL64(aOrbiterB, 44U)) + aOrbiterC) + RotL64(aCarry, 51U)) + aNonceWordE);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterB, 57U)) + aOrbiterJ);
            aWandererI = aWandererI + ((RotL64(aPrevious, 54U) + RotL64(aOrbiterK, 21U)) + aOrbiterC);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 47U) + aOrbiterK) + RotL64(aOrbiterJ, 3U)) + aNonceWordN);
            aWandererA = aWandererA + (((RotL64(aScatter, 13U) + aOrbiterH) + RotL64(aOrbiterK, 13U)) + RotL64(aCarry, 5U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 41U) + RotL64(aOrbiterB, 37U)) + aOrbiterE) + aWandererUpdateSaltE[((aIndex + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 11U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 21U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 57U));
            aCarry = aCarry + RotL64(aWandererB, 40U);
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
    [[maybe_unused]] std::uint8_t *aFireLaneC = pWorkSpace->mFireLaneC;
    [[maybe_unused]] std::uint8_t *aFireLaneD = pWorkSpace->mFireLaneD;
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xC284F3A89B7552FDULL + 0xEE18E919289A0D79ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xC857939B7BFDCE6DULL + 0x930CA41BA5BCD967ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xD17F1FF2020BDDB7ULL + 0xD5A11088F8C53666ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x9B0476C8A63019C7ULL + 0xEC43007631D2D6F4ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xB39399D6D8966597ULL + 0xE70FF77215D92136ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xDDF0485B2AFBB18BULL + 0xD10A631557B4B8FFULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xF80953F22C1B9E4BULL + 0xCDE993B2DF56DD8FULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xA29EC82618CED381ULL + 0xFE30288EDA344A9BULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xF97E1B27B9734AD7ULL + 0xF1DAB8A814577D42ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xFD2F350F6912F43DULL + 0x80E8E307CC9F0F15ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x8CE33DDEA9972281ULL + 0x825D8B828D953B1EULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xD7CB26D60223D3BBULL + 0x9034A4E8101D92D1ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xB555B66636A1C9A3ULL + 0xC7DD1D4C849DCD64ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0x8A13BCD8D169B885ULL + 0xA65EC216E27F6457ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xDBD34660A48FCFBDULL + 0xF04161B83901FDC8ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0x8B81975D3C866EC1ULL + 0xBD815A92C489B8D0ULL);
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
        // read from: aWorkLaneA, aWorkLaneB, aOperationLaneA, aWorkLaneC, aWorkLaneD, aOperationLaneB, aExpandLaneA, aFireLaneB, aOperationLaneD, aExpandLaneB, aFireLaneD, aFireLaneC, aExpandLaneC, aFireLaneA, aOperationLaneC
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_a loop 1
        // ingress from: aWorkLaneA, aWorkLaneB, aOperationLaneA
        // ingress directions: aWorkLaneA forward forced, aWorkLaneB forward forced, aOperationLaneA forward/backward random
        // cross from: aWorkLaneC, aWorkLaneD, aOperationLaneB
        // cross directions: aWorkLaneC backward forced, aWorkLaneD backward forced, aOperationLaneB backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 1135U)) & S_BLOCK1], 24U) ^ RotL64(aWorkLaneB[((aIndex + 8023U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 4794U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 5947U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 6184U)) & S_BLOCK1], 34U));
            aCross ^= RotL64(aOperationLaneB[((aIndex + 4400U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aIngress, 57U) ^ RotL64(aCarry, 27U)) ^ (RotL64(aPrevious, 41U) + RotL64(aCross, 6U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterA = ((aWandererI + RotL64(aIngress, 3U)) + RotL64(aCarry, 11U)) + 11039986441331892533U;
            aOrbiterE = (aWandererB + RotL64(aCross, 19U)) + 6256024955965426119U;
            aOrbiterD = (aWandererJ + RotL64(aPrevious, 43U)) + 9857443189988995666U;
            aOrbiterK = (((aWandererC + RotL64(aScatter, 53U)) + RotL64(aCarry, 51U)) + 11900944813380998208U) + aNonceWordM;
            aOrbiterF = ((aWandererD + RotL64(aIngress, 13U)) + 8422577734978875541U) + aOrbiterAssignSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = (aWandererA + RotL64(aScatter, 29U)) + 3100835100713928724U;
            aOrbiterJ = ((((aWandererK + RotL64(aPrevious, 36U)) + RotL64(aCarry, 27U)) + 11871553509810206993U) + aOrbiterAssignSaltD[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordK;
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 17614749493763417027U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 3638372131856199916U;
            aOrbiterD = RotL64((aOrbiterD * 480683274898147025U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 6582275259281025770U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 17016882418498941958U) ^ aOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4269869255230867823U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 1747214688658984715U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 9356088987044015278U) ^ aNonceWordE;
            aOrbiterI = RotL64((aOrbiterI * 16221733545319753695U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 4056238112133473456U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterJ) ^ 16013150119949532998U) ^ aOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterK = RotL64((aOrbiterK * 12913648646318115315U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 16076621211111834889U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 9940824359571581765U;
            aOrbiterE = RotL64((aOrbiterE * 11624767861336495331U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 15624084004784515753U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 7630989544834680335U;
            aOrbiterJ = RotL64((aOrbiterJ * 12261063237156822067U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 18003586430673313786U) + aOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 1654118743290334161U) ^ aNonceWordL;
            aOrbiterA = RotL64((aOrbiterA * 1153250137357176071U), 39U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterI, 37U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 23U));
            aIngress = aIngress + (RotL64(aOrbiterE, 3U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterK, 30U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterD, 57U)) + aOrbiterF) + aNonceWordC);
            aWandererI = aWandererI + (((RotL64(aIngress, 51U) + aOrbiterF) + RotL64(aOrbiterA, 23U)) + aNonceWordP);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 27U) + aOrbiterA) + RotL64(aOrbiterD, 13U)) + aWandererUpdateSaltF[((aIndex + 22U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aScatter, 4U) + aOrbiterK) + RotL64(aOrbiterI, 40U)) + RotL64(aCarry, 39U)) + aWandererUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 43U) + aOrbiterD) + RotL64(aOrbiterJ, 29U)) + aNonceWordI);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 21U) + aOrbiterK) + RotL64(aOrbiterA, 5U)) + RotL64(aCarry, 3U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 11U) + aOrbiterE) + RotL64(aOrbiterI, 47U)) + aNonceWordG);
            //
            aCarry = aCarry + (RotL64(aWandererD, 29U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererB, 44U) ^ aWandererI);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + RotL64(aWandererK, 35U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 2
        // ingress from: aExpandLaneA, aWorkLaneC, aFireLaneB
        // ingress directions: aExpandLaneA forward forced, aWorkLaneC forward forced, aFireLaneB forward/backward random
        // cross from: aWorkLaneA, aWorkLaneD, aOperationLaneD
        // cross directions: aWorkLaneA backward forced, aWorkLaneD backward forced, aOperationLaneD backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 9279U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneC[((aIndex + 8757U)) & S_BLOCK1], 50U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 13824U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 15211U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 8297U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aOperationLaneD[((aIndex + 13599U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCarry, 23U) + RotL64(aIngress, 57U)) ^ (RotL64(aCross, 38U) ^ RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterF = (((aWandererK + RotL64(aCross, 44U)) + RotL64(aCarry, 39U)) + 11700815697312060726U) + aNonceWordD;
            aOrbiterE = (((aWandererA + RotL64(aIngress, 3U)) + RotL64(aCarry, 27U)) + 11808423452327465441U) + aNonceWordJ;
            aOrbiterJ = (aWandererH + RotL64(aScatter, 29U)) + 8670503858631730886U;
            aOrbiterB = (aWandererF + RotL64(aPrevious, 37U)) + 2400061067991988544U;
            aOrbiterG = ((aWandererE + RotL64(aIngress, 57U)) + 16163118178366229686U) + aOrbiterAssignSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterH = (((aWandererD + RotL64(aCross, 51U)) + 3280178595904941068U) + aOrbiterAssignSaltB[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordF;
            aOrbiterK = (((aWandererC + RotL64(aPrevious, 13U)) + RotL64(aCarry, 57U)) + 3298683600817047727U) + aNonceWordC;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 16321624053445183574U) + aNonceWordN;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 6730229877611375225U;
            aOrbiterJ = RotL64((aOrbiterJ * 2022290495153519279U), 27U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterJ) + 10162830636713641322U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordO;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 15646771327759599256U;
            aOrbiterG = RotL64((aOrbiterG * 15333053762177144775U), 39U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 14841751262270544102U) + aNonceWordA;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 9545541117228834895U) ^ aOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 11529769874752969377U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 14676615635857599982U) + aNonceWordH;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 1231768638470558855U;
            aOrbiterK = RotL64((aOrbiterK * 2716808508509014677U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 1945905595345404833U) + aOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 1406171421638586846U;
            aOrbiterF = RotL64((aOrbiterF * 4577864352425476233U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 1970292335806697198U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 12309719390375013297U;
            aOrbiterB = RotL64((aOrbiterB * 16540660957923687327U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 5352135521358954576U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 15465675376193501658U) ^ aOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 16385761112921041387U), 11U);
            //
            aIngress = RotL64(aOrbiterH, 41U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 29U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 19U));
            aIngress = aIngress + RotL64(aOrbiterE, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aPrevious, 3U) + aOrbiterB) + RotL64(aOrbiterG, 21U)) + aWandererUpdateSaltC[((aIndex + 23U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterK, 56U)) + aOrbiterB);
            aWandererK = aWandererK + ((((RotL64(aIngress, 48U) + RotL64(aOrbiterG, 27U)) + aOrbiterH) + RotL64(aCarry, 23U)) + aNonceWordI);
            aWandererC = aWandererC ^ ((((RotL64(aScatter, 57U) + aOrbiterK) + RotL64(aOrbiterF, 13U)) + aNonceWordL) + aWandererUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aIngress, 41U) + aOrbiterB) + RotL64(aOrbiterJ, 5U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 19U) + aOrbiterJ) + RotL64(aOrbiterF, 43U)) + aNonceWordP);
            aWandererA = aWandererA + ((((RotL64(aCross, 13U) + aOrbiterE) + RotL64(aOrbiterB, 35U)) + RotL64(aCarry, 39U)) + aNonceWordE);
            //
            aCarry = aCarry + (RotL64(aWandererD, 41U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererF, 3U) ^ aWandererA);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 53U));
            aCarry = aCarry + RotL64(aWandererK, 26U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 3
        // ingress from: aExpandLaneB, aWorkLaneD, aFireLaneD
        // ingress directions: aExpandLaneB forward forced, aWorkLaneD forward forced, aFireLaneD forward/backward random
        // cross from: aExpandLaneA, aWorkLaneB, aFireLaneC
        // cross directions: aExpandLaneA backward forced, aWorkLaneB backward forced, aFireLaneC backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 22064U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneD[((aIndex + 19461U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 23119U)) & S_BLOCK1], 40U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 20345U)) & S_BLOCK1], 14U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 17146U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 17669U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aPrevious, 13U) + RotL64(aCross, 47U)) ^ (RotL64(aCarry, 60U) + RotL64(aIngress, 35U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterA = (((aWandererJ + RotL64(aIngress, 57U)) + RotL64(aCarry, 27U)) + 12980104182836602177U) + aNonceWordE;
            aOrbiterG = (((aWandererK + RotL64(aPrevious, 30U)) + 3172622203188863995U) + aOrbiterAssignSaltF[((aIndex + 25U)) & S_SALT1]) + aNonceWordA;
            aOrbiterE = (aWandererI + RotL64(aScatter, 51U)) + 1170974132219980203U;
            aOrbiterK = (((aWandererD + RotL64(aCross, 43U)) + 6035201940965047490U) + aOrbiterAssignSaltA[(((31U - aIndex) + 8U)) & S_SALT1]) + aNonceWordL;
            aOrbiterH = ((aWandererB + RotL64(aPrevious, 19U)) + RotL64(aCarry, 39U)) + 18033907118424996722U;
            aOrbiterB = (aWandererH + RotL64(aIngress, 5U)) + 14604813424800580304U;
            aOrbiterF = (((aWandererG + RotL64(aScatter, 13U)) + RotL64(aCarry, 53U)) + 13720232492851066035U) + aNonceWordD;
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 3902659710585257448U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 8331560652661619868U) ^ aOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 11418103770615560205U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 4485014147538689794U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 168202636924512424U) ^ aNonceWordF;
            aOrbiterK = RotL64((aOrbiterK * 13711020666131492091U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 16227825670092707848U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 4792781933944671365U;
            aOrbiterG = RotL64((aOrbiterG * 15859849676231455283U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 12636865372722601282U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 18198291399585556632U) ^ aNonceWordC;
            aOrbiterA = RotL64((aOrbiterA * 18155803890313399795U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 3650053185419807206U) + aNonceWordM;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 5897288963905408776U;
            aOrbiterB = RotL64((aOrbiterB * 3706949366974086151U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 9922308113622901726U) + aOrbiterUpdateSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 13352279749091561510U;
            aOrbiterF = RotL64((aOrbiterF * 4025213180483632557U), 19U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterB) + 14969461950939646117U) + aOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1]) + aNonceWordB;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 10231661776135056651U;
            aOrbiterH = RotL64((aOrbiterH * 11284575051455238501U), 35U);
            //
            aIngress = RotL64(aOrbiterA, 13U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterE, 41U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 51U));
            aIngress = aIngress + RotL64(aOrbiterB, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aIngress, 20U) + aOrbiterB) + RotL64(aOrbiterA, 41U)) + aNonceWordN);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterG, 29U)) + aOrbiterH);
            aWandererK = aWandererK + ((RotL64(aCross, 11U) + RotL64(aOrbiterB, 5U)) + aOrbiterK);
            aWandererJ = aWandererJ ^ ((((RotL64(aPrevious, 5U) + RotL64(aOrbiterK, 23U)) + aOrbiterG) + aNonceWordK) + aWandererUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aIngress, 35U) + aOrbiterB) + RotL64(aOrbiterF, 57U)) + RotL64(aCarry, 23U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 51U) + RotL64(aOrbiterE, 50U)) + aOrbiterK) + aWandererUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 57U) + RotL64(aOrbiterH, 35U)) + aOrbiterF) + RotL64(aCarry, 3U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 42U));
            aCarry = aCarry + (RotL64(aWandererH, 57U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererI, 19U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererD, 51U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aFireLaneA
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aFireLaneA forward/backward random
        // cross from: aExpandLaneB, aWorkLaneC, aOperationLaneC
        // cross directions: aExpandLaneB backward forced, aWorkLaneC backward forced, aOperationLaneC backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 24615U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneA[((aIndex + 26429U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 32442U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30904U)) & S_BLOCK1], 6U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 30423U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 27734U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aPrevious, 21U) ^ RotL64(aCarry, 5U)) ^ (RotL64(aIngress, 50U) + RotL64(aCross, 37U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterD = (aWandererA + RotL64(aScatter, 39U)) + 12380376990224645149U;
            aOrbiterA = (aWandererG + RotL64(aIngress, 13U)) + 18296928500297384014U;
            aOrbiterB = ((aWandererC + RotL64(aCross, 46U)) + 3550626816361145100U) + aNonceWordD;
            aOrbiterC = (((aWandererD + RotL64(aPrevious, 3U)) + RotL64(aCarry, 35U)) + 2667792936946706027U) + aNonceWordK;
            aOrbiterI = (aWandererE + RotL64(aCross, 57U)) + 12020969779370926953U;
            aOrbiterF = ((((aWandererB + RotL64(aScatter, 27U)) + RotL64(aCarry, 47U)) + 737340727886903447U) + aOrbiterAssignSaltE[((aIndex + 12U)) & S_SALT1]) + aNonceWordB;
            aOrbiterJ = (((aWandererJ + RotL64(aIngress, 21U)) + RotL64(aCarry, 21U)) + 1681797651799760502U) + aOrbiterAssignSaltD[((aIndex + 7U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 2956186342689489064U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 1876852870402977177U;
            aOrbiterB = RotL64((aOrbiterB * 8875540081346621757U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 6433205819353555071U) + aOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 9065076854974222998U) ^ aOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 5459675878087242021U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 3254410578766789992U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 2005081975473815576U;
            aOrbiterI = RotL64((aOrbiterI * 9947701153722014085U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 15992999234834560419U) + aNonceWordN;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 3458344156815120948U;
            aOrbiterD = RotL64((aOrbiterD * 1668460113964608051U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 17069783053664877727U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 1260234710193913099U;
            aOrbiterC = RotL64((aOrbiterC * 4561226779897414381U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 3825186451876061335U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 2905344294992827535U) ^ aNonceWordC;
            aOrbiterJ = RotL64((aOrbiterJ * 2469896090698580795U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 18141402347899180617U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 8760129857609925066U;
            aOrbiterA = RotL64((aOrbiterA * 2507999156108123047U), 13U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterF, 29U);
            aIngress = aIngress + (RotL64(aOrbiterA, 47U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterD, 35U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterJ, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aScatter, 27U) + aOrbiterB) + RotL64(aOrbiterI, 53U));
            aWandererD = aWandererD + (((RotL64(aCross, 3U) + aOrbiterF) + RotL64(aOrbiterC, 3U)) + RotL64(aCarry, 29U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterA, 29U)) + aOrbiterJ);
            aWandererC = aWandererC + ((((RotL64(aIngress, 14U) + RotL64(aOrbiterJ, 39U)) + aOrbiterD) + RotL64(aCarry, 11U)) + aWandererUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aCross, 53U) + RotL64(aOrbiterJ, 60U)) + aOrbiterF) + aNonceWordP);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 21U) + aOrbiterB) + RotL64(aOrbiterC, 19U)) + aNonceWordM) + aWandererUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 35U) + RotL64(aOrbiterF, 47U)) + aOrbiterD) + aNonceWordO);
            //
            aCarry = aCarry + (RotL64(aWandererA, 18U) ^ aWandererE);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 39U));
            aCarry = aCarry + (RotL64(aWandererD, 29U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererJ, 51U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xB0573C17FC51CF07ULL + 0xB24EF266789D9830ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x9F6C6FC7AD283A05ULL + 0x9F4D46A6FFE4AF1FULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xA23E0DC610552ED5ULL + 0xA7B9E13B7ABB5C19ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xAA8ECD076896425BULL + 0xABF71092E64676D0ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xA47F4FFFF0C5E4C5ULL + 0xA60E9024F4D4A112ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x99B07E9AD183CB71ULL + 0xC61D2E4EE752DB14ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xB75182063302EA15ULL + 0xA801DB03207B7157ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xB07417DA15FC8BD9ULL + 0xE944F79718CAF8E8ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x87AD9F242ECF6D53ULL + 0xB51401A85B3EA16FULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xA5881AB5B7C2A509ULL + 0xCE0B1B3B64E197E0ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xEE0A67BD7012717FULL + 0xE4964CA03A9A093AULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xC4FE62A0CA051DF3ULL + 0xF3CAAA98A13A40B0ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x9FBEEFACC735EA15ULL + 0xAC15D2ABC8530A97ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x87B807E67CD26787ULL + 0xA4D9684B8BD4D7CFULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xCFB0B15F3AF00321ULL + 0x936C8E8CC1BF472AULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xBBD8F1FCAC370E5DULL + 0xFB3B06AFB1705FDCULL);
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
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneA, aExpandLaneC, aExpandLaneD, aFireLaneD, aOperationLaneA, aWorkLaneC, aFireLaneB, aOperationLaneB, aFireLaneC, aWorkLaneD, aOperationLaneC, aWorkLaneA, aWorkLaneB
        // write to: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD
    
        // kdf_b_loop_b loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aFireLaneA
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aFireLaneA forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD, aFireLaneD
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward forced, aFireLaneD backward/forward random
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 3460U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneB[((aIndex + 4956U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 7818U)) & S_BLOCK1], 28U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4080U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 946U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 8069U)) & S_BLOCK1], 18U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCarry, 41U) + RotL64(aIngress, 26U)) ^ (RotL64(aPrevious, 13U) ^ RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterH = ((aWandererC + RotL64(aPrevious, 19U)) + 2177539223979303669U) + aNonceWordP;
            aOrbiterF = ((aWandererA + RotL64(aCross, 39U)) + RotL64(aCarry, 13U)) + 3962004686551521471U;
            aOrbiterD = ((aWandererJ + RotL64(aIngress, 29U)) + 8457602312617147662U) + aNonceWordO;
            aOrbiterJ = (((aWandererB + RotL64(aScatter, 10U)) + RotL64(aCarry, 3U)) + 18011802451816510632U) + aNonceWordD;
            aOrbiterG = ((aWandererG + RotL64(aCross, 47U)) + 9046101759168876832U) + aOrbiterAssignSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = (aWandererH + RotL64(aScatter, 3U)) + 11135620637431969597U;
            aOrbiterC = ((aWandererE + RotL64(aPrevious, 13U)) + RotL64(aCarry, 47U)) + 15913029940697999701U;
            aOrbiterB = (aWandererI + RotL64(aIngress, 51U)) + 16304193109948135982U;
            aOrbiterA = (aWandererD + RotL64(aScatter, 53U)) + 13208892298820080981U;
            aOrbiterK = (aWandererF + RotL64(aIngress, 36U)) + 4182377898949419225U;
            aOrbiterE = (((aWandererK + RotL64(aPrevious, 21U)) + 13970137023071326151U) + aOrbiterAssignSaltC[((aIndex + 14U)) & S_SALT1]) + aNonceWordN;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 8402396284835248583U) + aNonceWordH;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 8859190834060657829U;
            aOrbiterD = RotL64((aOrbiterD * 13552418608113716117U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 9760005337757990392U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 14108277760135744897U;
            aOrbiterG = RotL64((aOrbiterG * 4474681104256093885U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 12226316121949012350U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 3456392186754113960U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8704729827929941215U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 5004087958637038973U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 7176881295123125567U;
            aOrbiterI = RotL64((aOrbiterI * 15272157962928021009U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 10889800478505074438U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 13728832441482547824U) ^ aNonceWordG;
            aOrbiterB = RotL64((aOrbiterB * 17588477761978646139U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 17345665880706866772U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 301139993853297566U) ^ aNonceWordL;
            aOrbiterA = RotL64((aOrbiterA * 5812445396758354505U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 2061389844760610160U) + aOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 13631862266139238355U;
            aOrbiterH = RotL64((aOrbiterH * 143613352104722701U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 10767186080827509622U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 4893486019456886013U;
            aOrbiterF = RotL64((aOrbiterF * 5194746459545610901U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 11264795916303477037U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 16013652139405432608U;
            aOrbiterJ = RotL64((aOrbiterJ * 14924257021089920495U), 21U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 5209743554932653849U) + aOrbiterUpdateSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 13160179712987277456U;
            aOrbiterK = RotL64((aOrbiterK * 5003755912040281427U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 12440615920191945386U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 2177539223979303669U;
            aOrbiterE = RotL64((aOrbiterE * 3565122523239344029U), 47U);
            //
            aIngress = RotL64(aOrbiterA, 29U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterK, 11U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterJ, 5U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 60U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 37U));
            aIngress = aIngress + RotL64(aOrbiterF, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aIngress, 57U) + aOrbiterA) + RotL64(aOrbiterG, 13U));
            aWandererC = aWandererC + ((((RotL64(aPrevious, 13U) + aOrbiterI) + RotL64(aOrbiterE, 23U)) + aNonceWordK) + aWandererUpdateSaltF[((aIndex + 15U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 3U) + RotL64(aOrbiterB, 57U)) + aOrbiterI) + aNonceWordJ);
            aWandererJ = aWandererJ + (((RotL64(aCross, 44U) + aOrbiterK) + RotL64(aOrbiterF, 40U)) + RotL64(aCarry, 23U));
            aWandererB = aWandererB ^ ((((RotL64(aScatter, 27U) + RotL64(aOrbiterI, 47U)) + aOrbiterK) + aNonceWordC) + aWandererUpdateSaltD[((aIndex + 27U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aIngress, 37U) + aOrbiterC) + RotL64(aOrbiterE, 27U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 11U) + aOrbiterH) + RotL64(aOrbiterB, 19U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 29U) + aOrbiterJ) + RotL64(aOrbiterA, 38U)) + RotL64(aCarry, 53U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 5U) + RotL64(aOrbiterH, 53U)) + aOrbiterD) + aNonceWordI);
            aWandererF = aWandererF + ((RotL64(aPrevious, 41U) + aOrbiterI) + RotL64(aOrbiterD, 51U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 20U) + RotL64(aOrbiterG, 11U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 13U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 26U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 35U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 43U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 19U));
            aCarry = aCarry + RotL64(aWandererC, 54U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 2
        // ingress from: aOperationLaneA, aExpandLaneC, aWorkLaneC
        // ingress directions: aOperationLaneA forward forced, aExpandLaneC forward forced, aWorkLaneC forward/backward random
        // cross from: aExpandLaneA, aExpandLaneD, aFireLaneB
        // cross directions: aExpandLaneA backward forced, aExpandLaneD backward forced, aFireLaneB backward/forward random
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 11647U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneC[((aIndex + 9390U)) & S_BLOCK1], 38U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 13313U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 9574U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 15203U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 14812U)) & S_BLOCK1], 44U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCross, 51U) ^ RotL64(aIngress, 27U)) + (RotL64(aPrevious, 39U) ^ RotL64(aCarry, 10U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterD = ((aWandererJ + RotL64(aScatter, 43U)) + RotL64(aCarry, 5U)) + 6521330037475130256U;
            aOrbiterA = (((aWandererH + RotL64(aIngress, 19U)) + RotL64(aCarry, 21U)) + 12611880456055428940U) + aNonceWordD;
            aOrbiterE = ((aWandererF + RotL64(aPrevious, 27U)) + 12061611078130934708U) + aOrbiterAssignSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterF = ((aWandererD + RotL64(aCross, 56U)) + 1558112410801116984U) + aOrbiterAssignSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterI = ((aWandererB + RotL64(aIngress, 47U)) + 10509115227850160786U) + aNonceWordM;
            aOrbiterB = (aWandererI + RotL64(aScatter, 13U)) + 4045915960688792066U;
            aOrbiterK = (aWandererE + RotL64(aCross, 3U)) + 1196541286513243082U;
            aOrbiterH = (aWandererK + RotL64(aPrevious, 53U)) + 15564991032722373702U;
            aOrbiterG = ((aWandererA + RotL64(aCross, 37U)) + RotL64(aCarry, 43U)) + 4897765238703641798U;
            aOrbiterC = ((aWandererC + RotL64(aScatter, 60U)) + 12327429514907752733U) + aNonceWordE;
            aOrbiterJ = (aWandererG + RotL64(aPrevious, 39U)) + 6189189797708711636U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 6374267075282018852U) + aNonceWordH;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 1888758503831341439U) ^ aNonceWordC;
            aOrbiterE = RotL64((aOrbiterE * 74387714918264257U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 14956857689299491800U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterF) ^ 14879361107223331957U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterA = RotL64((aOrbiterA * 9166712966729591953U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 16086885494838105042U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 8069724185844303923U;
            aOrbiterF = RotL64((aOrbiterF * 8878470736758734353U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 10854345917959911439U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 7078313614360332089U;
            aOrbiterG = RotL64((aOrbiterG * 9864025732292844871U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 15083669236062255011U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 594879695916679116U;
            aOrbiterJ = RotL64((aOrbiterJ * 9852515479152735283U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 6721466068234534523U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 475816724162626782U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4799725182757588407U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 4341655358154605899U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 15477254302340298586U;
            aOrbiterC = RotL64((aOrbiterC * 13961520225881974201U), 5U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 10179091913200895775U) + aOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 6310490897546909571U) ^ aOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 15080621088825477613U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 13462682513035460711U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 16739138858084100385U;
            aOrbiterD = RotL64((aOrbiterD * 16386371811268298031U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 13608837667062268989U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 12902415667552110103U;
            aOrbiterK = RotL64((aOrbiterK * 16398790854093048017U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 16596211634603915761U) + aNonceWordO;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 6521330037475130256U;
            aOrbiterB = RotL64((aOrbiterB * 631958426544321145U), 51U);
            //
            aIngress = RotL64(aOrbiterE, 43U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 47U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 36U));
            aIngress = aIngress + (RotL64(aOrbiterF, 13U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 53U));
            aIngress = aIngress + RotL64(aOrbiterI, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aIngress, 53U) + aOrbiterD) + RotL64(aOrbiterJ, 47U)) + RotL64(aCarry, 27U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 39U) + RotL64(aOrbiterK, 51U)) + aOrbiterA) + aNonceWordN);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 51U) + aOrbiterA) + RotL64(aOrbiterF, 36U)) + aNonceWordB) + aWandererUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterB, 39U)) + aOrbiterI);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 42U) + RotL64(aOrbiterC, 29U)) + aOrbiterH);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 21U) + aOrbiterJ) + RotL64(aOrbiterI, 3U)) + aWandererUpdateSaltC[((aIndex + 14U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aCross, 19U) + aOrbiterB) + RotL64(aOrbiterA, 23U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterE, 58U)) + aOrbiterG);
            aWandererI = aWandererI + (((RotL64(aPrevious, 29U) + aOrbiterF) + RotL64(aOrbiterG, 53U)) + RotL64(aCarry, 51U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 47U) + aOrbiterB) + RotL64(aOrbiterH, 27U)) + aNonceWordJ);
            aWandererC = aWandererC + (((RotL64(aIngress, 14U) + aOrbiterD) + RotL64(aOrbiterB, 41U)) + aNonceWordP);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 37U));
            aCarry = aCarry + (RotL64(aWandererH, 56U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererI, 19U) ^ aWandererC);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 35U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 51U));
            aCarry = aCarry + RotL64(aWandererD, 53U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aOperationLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 3
        // ingress from: aOperationLaneB, aExpandLaneD, aFireLaneC
        // ingress directions: aOperationLaneB forward forced, aExpandLaneD forward forced, aFireLaneC forward/backward random
        // cross from: aOperationLaneA, aExpandLaneB, aWorkLaneD
        // cross directions: aOperationLaneA backward forced, aExpandLaneB backward forced, aWorkLaneD backward/forward random
        // write to: aOperationLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneB[((aIndex + 20356U)) & S_BLOCK1], 54U) ^ RotL64(aExpandLaneD[((aIndex + 17743U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 22486U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 22861U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 21152U)) & S_BLOCK1], 41U));
            aCross ^= RotL64(aWorkLaneD[((aIndex + 18244U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCross, 57U)) ^ (RotL64(aCarry, 39U) + RotL64(aPrevious, 18U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterB = ((aWandererG + RotL64(aScatter, 37U)) + 17074147006464019918U) + aOrbiterAssignSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterD = (aWandererI + RotL64(aIngress, 41U)) + 10559516626129419928U;
            aOrbiterC = (((aWandererH + RotL64(aCross, 19U)) + RotL64(aCarry, 27U)) + 13280363679503946221U) + aNonceWordM;
            aOrbiterE = ((aWandererA + RotL64(aPrevious, 58U)) + 17657115422132457413U) + aNonceWordH;
            aOrbiterJ = (((aWandererB + RotL64(aScatter, 51U)) + RotL64(aCarry, 19U)) + 13325837013304973008U) + aNonceWordP;
            aOrbiterH = ((aWandererD + RotL64(aIngress, 3U)) + RotL64(aCarry, 23U)) + 3059707750486106037U;
            aOrbiterI = ((aWandererC + RotL64(aPrevious, 27U)) + 4529045702503050852U) + aNonceWordL;
            aOrbiterG = (aWandererK + RotL64(aCross, 60U)) + 10726578475550904292U;
            aOrbiterK = (aWandererJ + RotL64(aIngress, 47U)) + 14832537837996659885U;
            aOrbiterF = (aWandererF + RotL64(aScatter, 11U)) + 220094417441809246U;
            aOrbiterA = ((aWandererE + RotL64(aPrevious, 53U)) + 15343130035105342194U) + aOrbiterAssignSaltD[((aIndex + 15U)) & S_SALT1];
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 16592263353426409884U) + aOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 15649290906447931918U) ^ aNonceWordO;
            aOrbiterC = RotL64((aOrbiterC * 8405875177836650731U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 11437410545843708269U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 5859769136073011444U;
            aOrbiterH = RotL64((aOrbiterH * 1065016088086441107U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 15188064100307340341U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 4367466521843260049U;
            aOrbiterG = RotL64((aOrbiterG * 15916715854192820923U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 8482617283860566845U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 2585745804937342972U) ^ aNonceWordB;
            aOrbiterK = RotL64((aOrbiterK * 8267269625632139809U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 1687641344403425541U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 13667916445979421400U;
            aOrbiterE = RotL64((aOrbiterE * 8191322670355590027U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 7684258716388029228U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 14764266202380443369U;
            aOrbiterI = RotL64((aOrbiterI * 1746254773647650741U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 12685190466981675661U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 9958374400222383893U) ^ aOrbiterUpdateSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 12696606920219838929U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 1352584794098160330U) + aOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 16057453941015251708U;
            aOrbiterF = RotL64((aOrbiterF * 6051546505117202495U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 5642244742563733299U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 2946279435712646692U) ^ aNonceWordD;
            aOrbiterD = RotL64((aOrbiterD * 3711867103848631343U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 17305358424001395035U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 1831722001182742673U;
            aOrbiterA = RotL64((aOrbiterA * 13867284970939557547U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 12354430852596737299U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterK) ^ 17074147006464019918U) ^ aOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterB = RotL64((aOrbiterB * 17316050599218057961U), 51U);
            //
            aIngress = RotL64(aOrbiterI, 5U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterE, 3U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 12U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 21U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 27U));
            aIngress = aIngress + RotL64(aOrbiterF, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 6U) + RotL64(aOrbiterA, 24U)) + aOrbiterJ) + aNonceWordE);
            aWandererK = aWandererK + (((RotL64(aCross, 41U) + aOrbiterD) + RotL64(aOrbiterE, 27U)) + RotL64(aCarry, 29U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 19U) + aOrbiterI) + RotL64(aOrbiterH, 21U));
            aWandererJ = aWandererJ + ((RotL64(aScatter, 37U) + RotL64(aOrbiterD, 3U)) + aOrbiterH);
            aWandererD = aWandererD ^ (((RotL64(aCross, 43U) + RotL64(aOrbiterK, 41U)) + aOrbiterD) + aNonceWordK);
            aWandererA = aWandererA + (((RotL64(aIngress, 24U) + aOrbiterF) + RotL64(aOrbiterJ, 29U)) + RotL64(aCarry, 5U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 47U) + aOrbiterG) + RotL64(aOrbiterF, 56U));
            aWandererH = aWandererH + ((RotL64(aScatter, 39U) + aOrbiterK) + RotL64(aOrbiterC, 11U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 57U) + RotL64(aOrbiterK, 47U)) + aOrbiterG) + aNonceWordN);
            aWandererE = aWandererE + (((RotL64(aCross, 29U) + RotL64(aOrbiterB, 43U)) + aOrbiterI) + aWandererUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((((RotL64(aIngress, 53U) + aOrbiterJ) + RotL64(aOrbiterG, 35U)) + aNonceWordC) + aWandererUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 57U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererI, 23U) ^ aWandererC);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 27U));
            aCarry = aCarry + (RotL64(aWandererJ, 52U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererF, 13U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererK, 11U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aOperationLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 4
        // ingress from: aOperationLaneC, aOperationLaneA, aWorkLaneA
        // ingress directions: aOperationLaneC forward forced, aOperationLaneA forward forced, aWorkLaneA forward/backward random
        // cross from: aOperationLaneB, aExpandLaneC, aWorkLaneB
        // cross directions: aOperationLaneB backward forced, aExpandLaneC backward forced, aWorkLaneB backward/forward random
        // write to: aOperationLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneC[((aIndex + 24960U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneA[((aIndex + 30323U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aWorkLaneA[((aIndex + 28154U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 26918U)) & S_BLOCK1], 22U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 29772U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 28875U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCross, 39U) + RotL64(aPrevious, 19U)) + (RotL64(aCarry, 4U) ^ RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterB = (aWandererH + RotL64(aScatter, 5U)) + 14823268998003220191U;
            aOrbiterG = (aWandererJ + RotL64(aCross, 53U)) + 15295237288788213847U;
            aOrbiterK = ((aWandererC + RotL64(aPrevious, 19U)) + 16434853402001133899U) + aOrbiterAssignSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = (aWandererI + RotL64(aIngress, 39U)) + 7555911304407871631U;
            aOrbiterJ = ((aWandererA + RotL64(aScatter, 36U)) + 14977248264994834620U) + aNonceWordE;
            aOrbiterF = ((aWandererD + RotL64(aCross, 47U)) + RotL64(aCarry, 53U)) + 9707764144919392380U;
            aOrbiterH = (((aWandererB + RotL64(aIngress, 51U)) + RotL64(aCarry, 29U)) + 1277304385464681529U) + aNonceWordC;
            aOrbiterD = ((aWandererG + RotL64(aPrevious, 3U)) + 3089786220465849395U) + aNonceWordB;
            aOrbiterE = ((aWandererE + RotL64(aIngress, 21U)) + 3700503853358695085U) + aOrbiterAssignSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = ((aWandererK + RotL64(aScatter, 57U)) + RotL64(aCarry, 21U)) + 3240054112993517371U;
            aOrbiterA = ((aWandererF + RotL64(aCross, 10U)) + 16897532076915366859U) + aNonceWordA;
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 18167359289798364307U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 8870819278575769863U;
            aOrbiterK = RotL64((aOrbiterK * 9334066154398059075U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 15363069206212330251U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 14858164441499725158U;
            aOrbiterJ = RotL64((aOrbiterJ * 14931933411393847915U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 5357144808788707522U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 2910681277417754860U) ^ aNonceWordF;
            aOrbiterB = RotL64((aOrbiterB * 13170868582159347059U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 9824408699018165151U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 368370224788793300U;
            aOrbiterG = RotL64((aOrbiterG * 14358982366258729959U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 7095398304588825115U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 11418879758164313554U;
            aOrbiterI = RotL64((aOrbiterI * 5983520332639771791U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 2171599720681913272U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 17593730219647495033U;
            aOrbiterF = RotL64((aOrbiterF * 12926053208918563087U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 17755947635188715523U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 14565740605227022106U) ^ aOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 15866418354612945335U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 14538017880915584414U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterK) ^ 6174566474851449123U) ^ aOrbiterUpdateSaltA[((aIndex + 28U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterC = RotL64((aOrbiterC * 179569008593475683U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 3806438394748643441U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 13737114463856719285U) ^ aNonceWordN;
            aOrbiterA = RotL64((aOrbiterA * 13439346068497710151U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 3698379331577470045U) + aNonceWordM;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 1097081284062708554U;
            aOrbiterD = RotL64((aOrbiterD * 3498627643013255777U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 215117138867597766U) + aOrbiterUpdateSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 14823268998003220191U;
            aOrbiterE = RotL64((aOrbiterE * 12131828437975771377U), 51U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterJ, 19U);
            aIngress = aIngress + (RotL64(aOrbiterH, 47U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 37U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 43U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 23U));
            aIngress = aIngress + RotL64(aOrbiterG, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aCross, 19U) + aOrbiterH) + RotL64(aOrbiterE, 51U)) + RotL64(aCarry, 41U)) + aNonceWordP);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterI, 27U)) + aOrbiterG);
            aWandererC = aWandererC + ((RotL64(aIngress, 60U) + RotL64(aOrbiterJ, 34U)) + aOrbiterG);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterK, 29U)) + aOrbiterD);
            aWandererK = aWandererK + ((RotL64(aPrevious, 13U) + RotL64(aOrbiterE, 41U)) + aOrbiterF);
            aWandererB = aWandererB ^ ((((RotL64(aIngress, 37U) + aOrbiterH) + RotL64(aOrbiterD, 23U)) + aNonceWordD) + aWandererUpdateSaltD[((aIndex + 10U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 11U) + aOrbiterI) + RotL64(aOrbiterC, 57U)) + aNonceWordO);
            aWandererH = aWandererH ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterA, 3U)) + aOrbiterF);
            aWandererA = aWandererA + (((RotL64(aIngress, 39U) + aOrbiterB) + RotL64(aOrbiterJ, 11U)) + RotL64(aCarry, 35U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 28U) + aOrbiterI) + RotL64(aOrbiterA, 46U)) + aWandererUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aScatter, 57U) + aOrbiterB) + RotL64(aOrbiterG, 43U)) + aNonceWordK);
            //
            aCarry = aCarry + (RotL64(aWandererG, 21U) ^ aWandererD);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 56U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 53U));
            aCarry = aCarry + (RotL64(aWandererC, 39U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererE, 35U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererH, 28U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xC75B1F23EDB11BCDULL + 0xA6A726BFEF227D3BULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x81C0E5A16E762FADULL + 0xDD02E78A5FBEAF61ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xC4F6C9255B8C15A9ULL + 0x8DC05EEF63D6D8F3ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xD20C981A38752481ULL + 0x836F2AEAA021ECDAULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x9AAF0B98ADDA136DULL + 0xA8387BEECBC77661ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xD7FCC4909F96D69DULL + 0xFCC88C6C5F8344CEULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xF2D4DE1F6C2AFE9DULL + 0xC039EEA075A1D215ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x9622597693DD402BULL + 0xCB5D1B80DE5BC454ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xE5BEA025AC6D9E0FULL + 0xFCCA8F96A778AE5AULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xD042EFE01F70F675ULL + 0x9AB7D7015E5A9C3DULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xB34ADED8D17AE7B9ULL + 0xC63E7E11D47ABF6DULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xDFEE051907A0EA7DULL + 0xCBF8AF40268F518DULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x9DDC7AF08C1D400BULL + 0x8F1052B783B4EE15ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xB12F6385100AB537ULL + 0x8E8514C1E622CFE3ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xC14A99C6489A403DULL + 0xA48CF835F7789395ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0x8F8143173B3BB259ULL + 0xE5C7C792FC37F21FULL);
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
        // read from: aOperationLaneA, aOperationLaneB, aFireLaneA, aOperationLaneC, aOperationLaneD, aWorkLaneB, aExpandLaneA, aFireLaneC, aWorkLaneD, aExpandLaneB, aWorkLaneA, aFireLaneD, aExpandLaneC, aFireLaneB, aWorkLaneC
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_c loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aFireLaneA
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aFireLaneA forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aWorkLaneB
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aWorkLaneB backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 2588U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneB[((aIndex + 6145U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 1554U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 2657U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 7190U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 2232U)) & S_BLOCK1], 58U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCarry, 23U) + RotL64(aPrevious, 37U)) ^ (RotL64(aCross, 11U) ^ RotL64(aIngress, 58U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterE = ((aWandererG + RotL64(aCross, 60U)) + 8866844335448071821U) + aNonceWordA;
            aOrbiterC = ((aWandererF + RotL64(aPrevious, 19U)) + 15159698739856430085U) + aNonceWordL;
            aOrbiterK = (((aWandererA + RotL64(aScatter, 43U)) + RotL64(aCarry, 47U)) + 9582805772989594633U) + aOrbiterAssignSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = (aWandererC + RotL64(aIngress, 39U)) + 1438538239931588373U;
            aOrbiterF = ((aWandererK + RotL64(aPrevious, 29U)) + 10862044156620436139U) + aOrbiterAssignSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterI = ((aWandererH + RotL64(aCross, 23U)) + RotL64(aCarry, 37U)) + 13682173320058164615U;
            aOrbiterJ = (aWandererJ + RotL64(aIngress, 11U)) + 8351013291045977592U;
            aOrbiterA = (aWandererI + RotL64(aScatter, 4U)) + 15777857431516633916U;
            aOrbiterG = ((aWandererE + RotL64(aIngress, 51U)) + RotL64(aCarry, 3U)) + 16178966745333885377U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 9031889187993001617U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 6308472367425865347U;
            aOrbiterK = RotL64((aOrbiterK * 17118710301967158153U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 642109145903321046U) + aOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 9186268569255318035U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10714674348507516749U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 6091345356803675860U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 13218507921880873749U;
            aOrbiterJ = RotL64((aOrbiterJ * 15415157927185637717U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 4266652275234474616U) + aOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 4391422098164506195U;
            aOrbiterA = RotL64((aOrbiterA * 17634679403195085867U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 5160682323243635577U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 10351728852161347404U;
            aOrbiterC = RotL64((aOrbiterC * 11105410036471745951U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 3950932176454814023U) + aNonceWordB;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 9536466386833427441U;
            aOrbiterB = RotL64((aOrbiterB * 18064984243491293435U), 27U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 9927425919978776529U) + aNonceWordH;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 6819384090527481081U) ^ aNonceWordN;
            aOrbiterI = RotL64((aOrbiterI * 18032965969184368561U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 1646274931424218507U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 16166524473976135097U;
            aOrbiterE = RotL64((aOrbiterE * 11672192658072663849U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 11252501968059485262U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 16847854447987609067U;
            aOrbiterG = RotL64((aOrbiterG * 6326299154627028295U), 47U);
            //
            aIngress = RotL64(aOrbiterC, 29U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterA, 19U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 22U));
            aIngress = aIngress + (RotL64(aOrbiterB, 57U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterF, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterA, 30U)) + aOrbiterJ);
            aWandererG = aWandererG + (((RotL64(aIngress, 39U) + RotL64(aOrbiterI, 23U)) + aOrbiterF) + RotL64(aCarry, 27U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 46U) + aOrbiterJ) + RotL64(aOrbiterG, 57U)) + aWandererUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 21U) + aOrbiterK) + RotL64(aOrbiterB, 13U)) + RotL64(aCarry, 43U)) + aNonceWordO);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 35U) + aOrbiterJ) + RotL64(aOrbiterI, 53U));
            aWandererH = aWandererH + (((RotL64(aCross, 13U) + aOrbiterC) + RotL64(aOrbiterF, 39U)) + aNonceWordC);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 29U) + aOrbiterA) + RotL64(aOrbiterE, 46U));
            aWandererK = aWandererK + ((((RotL64(aScatter, 57U) + RotL64(aOrbiterI, 5U)) + aOrbiterK) + aNonceWordP) + aWandererUpdateSaltC[((aIndex + 25U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 50U) + RotL64(aOrbiterC, 19U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 35U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 13U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 47U));
            aCarry = aCarry + (RotL64(aWandererA, 38U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererH, 51U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 2
        // ingress from: aExpandLaneA, aOperationLaneC, aFireLaneC
        // ingress directions: aExpandLaneA forward forced, aOperationLaneC forward forced, aFireLaneC forward/backward random
        // cross from: aOperationLaneA, aOperationLaneD, aWorkLaneD
        // cross directions: aOperationLaneA backward forced, aOperationLaneD backward forced, aWorkLaneD backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 13426U)) & S_BLOCK1], 18U) ^ RotL64(aOperationLaneC[((aIndex + 12807U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 16252U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 16311U)) & S_BLOCK1], 10U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 14410U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aWorkLaneD[((aIndex + 9636U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCross, 27U) ^ RotL64(aPrevious, 39U)) ^ (RotL64(aCarry, 6U) + RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterA = (((aWandererC + RotL64(aCross, 52U)) + RotL64(aCarry, 11U)) + 9435962834163239322U) + aNonceWordH;
            aOrbiterC = (aWandererH + RotL64(aIngress, 39U)) + 10524704356081318973U;
            aOrbiterE = ((aWandererA + RotL64(aScatter, 57U)) + 7403401305665208680U) + aOrbiterAssignSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = (aWandererG + RotL64(aPrevious, 47U)) + 7525414805023556493U;
            aOrbiterH = ((aWandererD + RotL64(aCross, 3U)) + 1116686470029070951U) + aNonceWordN;
            aOrbiterJ = ((aWandererJ + RotL64(aScatter, 21U)) + RotL64(aCarry, 57U)) + 13257612299137802420U;
            aOrbiterK = ((((aWandererK + RotL64(aIngress, 11U)) + RotL64(aCarry, 37U)) + 9181543003986598283U) + aOrbiterAssignSaltC[((aIndex + 29U)) & S_SALT1]) + aNonceWordM;
            aOrbiterI = (aWandererF + RotL64(aPrevious, 30U)) + 9739384852307501107U;
            aOrbiterG = ((aWandererB + RotL64(aScatter, 43U)) + 11308402900229016057U) + aNonceWordP;
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 14935167593705272337U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 7171824007631943535U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4839974427616194289U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 8068411284829563567U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 12350207458513447578U;
            aOrbiterH = RotL64((aOrbiterH * 813973258659041895U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 17039236343991574134U) + aOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 18291683592714999632U;
            aOrbiterK = RotL64((aOrbiterK * 7771718817924840713U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 6239616841884430968U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 10604527977569876774U;
            aOrbiterJ = RotL64((aOrbiterJ * 6972820410084939637U), 47U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterK) + 1707724300671717658U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordC;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 3802268808625297647U) ^ aNonceWordG;
            aOrbiterC = RotL64((aOrbiterC * 11296811630387191563U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 9423064323799920219U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 242153923313096551U;
            aOrbiterI = RotL64((aOrbiterI * 12117679073775630197U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 945801070951928277U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 13094814302414492064U) ^ aNonceWordA;
            aOrbiterF = RotL64((aOrbiterF * 14638176479878969775U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 7572219725951040117U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 16494986983782503428U;
            aOrbiterG = RotL64((aOrbiterG * 2739189408707408171U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 10949497978229234856U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 11219643352002119905U) ^ aNonceWordF;
            aOrbiterA = RotL64((aOrbiterA * 16900635614259262873U), 19U);
            //
            aIngress = RotL64(aOrbiterK, 29U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterC, 34U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 51U));
            aIngress = aIngress + (RotL64(aOrbiterG, 47U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterI, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aCross, 37U) + aOrbiterF) + RotL64(aOrbiterH, 22U)) + aNonceWordI) + aWandererUpdateSaltB[((aIndex + 4U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 19U) + RotL64(aOrbiterG, 29U)) + aOrbiterA) + aNonceWordO);
            aWandererK = aWandererK + ((((RotL64(aScatter, 24U) + aOrbiterI) + RotL64(aOrbiterG, 5U)) + RotL64(aCarry, 11U)) + aWandererUpdateSaltF[((aIndex + 18U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 43U) + aOrbiterE) + RotL64(aOrbiterJ, 11U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterC, 35U)) + aOrbiterA) + RotL64(aCarry, 19U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 13U) + aOrbiterH) + RotL64(aOrbiterJ, 56U));
            aWandererC = aWandererC + ((RotL64(aScatter, 50U) + aOrbiterK) + RotL64(aOrbiterA, 39U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterF, 51U)) + aOrbiterA);
            aWandererG = aWandererG + ((RotL64(aScatter, 57U) + RotL64(aOrbiterJ, 47U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererG, 21U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererC, 51U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererJ, 29U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererA, 43U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererK, 14U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 3
        // ingress from: aExpandLaneB, aOperationLaneD, aWorkLaneA
        // ingress directions: aExpandLaneB forward forced, aOperationLaneD forward forced, aWorkLaneA forward/backward random
        // cross from: aExpandLaneA, aOperationLaneB, aFireLaneD
        // cross directions: aExpandLaneA backward forced, aOperationLaneB backward forced, aFireLaneD backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 17091U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneD[((aIndex + 16749U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16960U)) & S_BLOCK1], 40U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 21714U)) & S_BLOCK1], 44U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 22122U)) & S_BLOCK1], 53U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 17725U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCarry, 41U) ^ RotL64(aIngress, 23U)) + (RotL64(aPrevious, 54U) ^ RotL64(aCross, 11U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterB = ((aWandererC + RotL64(aCross, 5U)) + 17019646486641172469U) + aNonceWordP;
            aOrbiterJ = (aWandererB + RotL64(aIngress, 46U)) + 12276141179299971572U;
            aOrbiterF = (((aWandererD + RotL64(aScatter, 19U)) + RotL64(aCarry, 35U)) + 3617241694029841555U) + aOrbiterAssignSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterG = (((aWandererG + RotL64(aPrevious, 53U)) + RotL64(aCarry, 27U)) + 6967963401259371737U) + aNonceWordC;
            aOrbiterA = (aWandererF + RotL64(aScatter, 11U)) + 6340709284279891017U;
            aOrbiterD = ((aWandererK + RotL64(aCross, 35U)) + 456065368903896482U) + aOrbiterAssignSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = (((aWandererE + RotL64(aIngress, 24U)) + RotL64(aCarry, 51U)) + 17686765719908116203U) + aNonceWordM;
            aOrbiterH = (aWandererA + RotL64(aPrevious, 29U)) + 1322045955429785736U;
            aOrbiterK = (aWandererH + RotL64(aIngress, 41U)) + 5163772703302372887U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 13268431135020363252U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 6538789950366849332U;
            aOrbiterF = RotL64((aOrbiterF * 5352960308459065837U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 10390344544314544893U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 5087084271300584267U) ^ aNonceWordN;
            aOrbiterD = RotL64((aOrbiterD * 15149302947570776165U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 13423071121590981727U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 18324443012024134729U) ^ aOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 15814349432207734533U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 4129091815978464507U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 17024797553831962245U;
            aOrbiterG = RotL64((aOrbiterG * 3137753479364378175U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 6501545108779991661U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 11930037791867597447U) ^ aOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4904739567549702851U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 4667298703308315851U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 6315980380900062127U;
            aOrbiterK = RotL64((aOrbiterK * 12080555704907924637U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 12732382340390769888U) + aNonceWordB;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 7792095326183864547U;
            aOrbiterH = RotL64((aOrbiterH * 12645556660611824631U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 17428384983571405782U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterK) ^ 3193205313177048443U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterB = RotL64((aOrbiterB * 14488006565106259731U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 2813743367131107264U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 2742138679703780981U;
            aOrbiterA = RotL64((aOrbiterA * 18356569025783532225U), 29U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterG, 50U);
            aIngress = aIngress + (RotL64(aOrbiterA, 23U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 13U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 47U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterC, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aIngress, 19U) + RotL64(aOrbiterK, 34U)) + aOrbiterD) + RotL64(aCarry, 39U)) + aNonceWordH);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 23U) + aOrbiterC) + RotL64(aOrbiterB, 11U)) + aNonceWordE);
            aWandererE = aWandererE + (((RotL64(aPrevious, 34U) + aOrbiterF) + RotL64(aOrbiterA, 47U)) + aWandererUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 13U) + aOrbiterH) + RotL64(aOrbiterC, 43U));
            aWandererF = aWandererF + (((RotL64(aScatter, 5U) + aOrbiterJ) + RotL64(aOrbiterG, 23U)) + RotL64(aCarry, 21U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 27U) + RotL64(aOrbiterH, 27U)) + aOrbiterD) + aWandererUpdateSaltE[((aIndex + 26U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aPrevious, 54U) + aOrbiterA) + RotL64(aOrbiterC, 60U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterH, 53U)) + aOrbiterJ);
            aWandererK = aWandererK + ((RotL64(aCross, 47U) + aOrbiterJ) + RotL64(aOrbiterB, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 35U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererD, 3U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererB, 51U) ^ aWandererE);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 23U));
            aCarry = aCarry + RotL64(aWandererG, 27U);
            aCarry = aCarry + RotL64(aIngress, 56U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aFireLaneB
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aFireLaneB forward/backward random
        // cross from: aExpandLaneB, aOperationLaneC, aWorkLaneC
        // cross directions: aExpandLaneB backward forced, aOperationLaneC backward forced, aWorkLaneC backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 26692U)) & S_BLOCK1], 28U) ^ RotL64(aExpandLaneA[((aIndex + 30702U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 32049U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 26625U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 24611U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aWorkLaneC[((aIndex + 32334U)) & S_BLOCK1], 54U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCarry, 39U) + RotL64(aPrevious, 5U)) ^ (RotL64(aCross, 54U) ^ RotL64(aIngress, 27U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterE = (aWandererC + RotL64(aScatter, 43U)) + 6733949564325516029U;
            aOrbiterF = (((aWandererH + RotL64(aPrevious, 3U)) + RotL64(aCarry, 11U)) + 7304098437143918796U) + aNonceWordO;
            aOrbiterG = ((aWandererB + RotL64(aCross, 26U)) + 3923949518391777800U) + aOrbiterAssignSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterC = ((aWandererJ + RotL64(aIngress, 47U)) + 14243591003388927124U) + aOrbiterAssignSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterK = ((aWandererI + RotL64(aCross, 39U)) + 18329498724605410406U) + aNonceWordN;
            aOrbiterB = ((aWandererG + RotL64(aPrevious, 11U)) + 13118172167747037249U) + aNonceWordK;
            aOrbiterD = ((aWandererD + RotL64(aIngress, 35U)) + RotL64(aCarry, 27U)) + 5272025143849174212U;
            aOrbiterA = ((aWandererK + RotL64(aScatter, 20U)) + RotL64(aCarry, 41U)) + 16075917179214318424U;
            aOrbiterJ = ((aWandererA + RotL64(aPrevious, 51U)) + 15263590648674658399U) + aNonceWordB;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 13730046728289525921U) + aNonceWordI;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 7703141464499623408U;
            aOrbiterG = RotL64((aOrbiterG * 5886009900621521987U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 1382279753822135359U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 2973369221699098292U;
            aOrbiterE = RotL64((aOrbiterE * 7440242040663550631U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 11578274119583013219U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 3419411247737896674U;
            aOrbiterD = RotL64((aOrbiterD * 17814942652262802991U), 53U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterA) + 2582783513078999303U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1]) + aNonceWordL;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 3959762790273529677U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 383974377372162751U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 465795011576934604U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 17880826624185821135U;
            aOrbiterK = RotL64((aOrbiterK * 4445949147592860913U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 10819659185349413173U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 17298208553586835030U;
            aOrbiterC = RotL64((aOrbiterC * 1965860510614222093U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 12585880006661489402U) + aOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 16650193903267408586U) ^ aNonceWordP;
            aOrbiterF = RotL64((aOrbiterF * 5781132589396936615U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 885882046325991589U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 869560078374809974U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 13440973563438747181U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 11871305571797951851U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 12137095015607196226U;
            aOrbiterA = RotL64((aOrbiterA * 7618152256560808581U), 41U);
            //
            aIngress = RotL64(aOrbiterG, 11U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 19U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 22U));
            aIngress = aIngress + (RotL64(aOrbiterK, 43U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterD, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aScatter, 19U) + aOrbiterE) + RotL64(aOrbiterG, 14U));
            aWandererB = aWandererB + (((RotL64(aIngress, 47U) + RotL64(aOrbiterA, 5U)) + aOrbiterF) + aNonceWordD);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 40U) + aOrbiterD) + RotL64(aOrbiterF, 35U)) + aNonceWordM);
            aWandererG = aWandererG + ((((RotL64(aCross, 35U) + aOrbiterA) + RotL64(aOrbiterE, 53U)) + RotL64(aCarry, 37U)) + aWandererUpdateSaltC[((aIndex + 29U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 27U) + aOrbiterK) + RotL64(aOrbiterJ, 39U));
            aWandererA = aWandererA + (((RotL64(aIngress, 51U) + RotL64(aOrbiterC, 27U)) + aOrbiterB) + aNonceWordE);
            aWandererH = aWandererH ^ ((RotL64(aCross, 3U) + aOrbiterA) + RotL64(aOrbiterJ, 44U));
            aWandererC = aWandererC + ((((RotL64(aPrevious, 56U) + RotL64(aOrbiterB, 57U)) + aOrbiterJ) + RotL64(aCarry, 27U)) + aNonceWordH);
            aWandererK = aWandererK ^ (((RotL64(aCross, 23U) + RotL64(aOrbiterG, 23U)) + aOrbiterA) + aWandererUpdateSaltA[((aIndex + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 53U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 27U));
            aCarry = aCarry + (RotL64(aWandererH, 38U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererB, 47U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererC, 41U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xB030A7277B0A7A81ULL + 0xAA55658839C2D116ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xE331ED59B2CAF1F3ULL + 0xDD797BD01CCE42CCULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x89BB99DFD2F7D717ULL + 0x9F0BDC4FB3C82DCEULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xAA6AB22AA2AB08B7ULL + 0xA8F303817212DD4DULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xA73EDFBE01F7143BULL + 0xEEDF73CB7D18AA98ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x90FECA9E564C7B7DULL + 0xB057351EA345BEA8ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xBC02B570D18DE057ULL + 0x97E4B41CBAFB4E3BULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xC697B3C93807DA8BULL + 0xE6BFB1923CFE936DULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0x9939AD6A9C921EF3ULL + 0xCB1F735D80A14745ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xDD6435E8F6D8E01DULL + 0xCC576A76B7204FD4ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xAB43D0275F1E8BF3ULL + 0xF1C2890E660C51CCULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x91F062ED8537BB39ULL + 0xF16F1DC0B5DE9375ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xC463CE95A240BDD5ULL + 0xFF10200235D4CEE2ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0x8881F2D6AC3E475FULL + 0xF3C099975131E438ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x8B1C7581EE0339A9ULL + 0xBC592DE5D1D10B8DULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xB810CAC54B4AF005ULL + 0x9D9D823D0B3697BFULL);
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
        // read from: aWorkLaneA, aWorkLaneB, aFireLaneD, aWorkLaneC, aWorkLaneD, aOperationLaneA, aExpandLaneA, aFireLaneC, aOperationLaneB, aExpandLaneB, aOperationLaneD, aFireLaneA, aExpandLaneC, aOperationLaneC, aFireLaneB
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_d loop 1
        // ingress from: aWorkLaneA, aWorkLaneB, aFireLaneD
        // ingress directions: aWorkLaneA forward forced, aWorkLaneB forward forced, aFireLaneD forward/backward random
        // cross from: aWorkLaneC, aWorkLaneD, aOperationLaneA
        // cross directions: aWorkLaneC backward forced, aWorkLaneD backward forced, aOperationLaneA backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 1886U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneB[((aIndex + 4154U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 1526U)) & S_BLOCK1], 4U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 6066U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 5938U)) & S_BLOCK1], 54U));
            aCross ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 233U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCarry, 56U) ^ RotL64(aIngress, 43U)) + (RotL64(aCross, 19U) ^ RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterE = (((aWandererD + RotL64(aPrevious, 5U)) + RotL64(aCarry, 11U)) + 15045917390223766480U) + aOrbiterAssignSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = ((aWandererI + RotL64(aCross, 35U)) + 10763054007033668758U) + aNonceWordK;
            aOrbiterD = (((aWandererJ + RotL64(aScatter, 11U)) + RotL64(aCarry, 43U)) + 13190170142593666607U) + aNonceWordI;
            aOrbiterB = (aWandererH + RotL64(aIngress, 41U)) + 9657025731441167065U;
            aOrbiterI = ((aWandererK + RotL64(aCross, 29U)) + RotL64(aCarry, 27U)) + 11433367178975954211U;
            aOrbiterG = ((aWandererB + RotL64(aScatter, 21U)) + 17904920143996810366U) + aNonceWordB;
            aOrbiterC = ((aWandererA + RotL64(aIngress, 54U)) + 3244383020512113283U) + aOrbiterAssignSaltA[((aIndex + 21U)) & S_SALT1];
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 6538815775171139091U) + aOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 7195368312757976343U;
            aOrbiterD = RotL64((aOrbiterD * 10515679176134176565U), 3U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterB) + 18134430713910279374U) + aOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1]) + aNonceWordG;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 6571776588427107976U;
            aOrbiterI = RotL64((aOrbiterI * 11916502085252589161U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 11830778129647517758U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 9793702760907767365U) ^ aNonceWordF;
            aOrbiterF = RotL64((aOrbiterF * 4096246227968677179U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 2287235876793192036U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 8951959188326141794U) ^ aOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 9968356718110753845U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 7583061790273240157U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 3571364625022806085U;
            aOrbiterC = RotL64((aOrbiterC * 6238360922735480669U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 13869345563551689212U) + aOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 277480328952975002U;
            aOrbiterG = RotL64((aOrbiterG * 1057564597096163085U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 4983735092494677578U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 9490022869381030928U;
            aOrbiterB = RotL64((aOrbiterB * 12926352917961703123U), 43U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterG, 51U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 57U));
            aIngress = aIngress + (RotL64(aOrbiterE, 35U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterC, 18U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aIngress, 27U) + aOrbiterD) + RotL64(aOrbiterI, 41U)) + aNonceWordL);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterC, 47U)) + aOrbiterE);
            aWandererB = aWandererB + ((((RotL64(aCross, 57U) + aOrbiterC) + RotL64(aOrbiterD, 6U)) + RotL64(aCarry, 5U)) + aNonceWordM);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 43U) + aOrbiterB) + RotL64(aOrbiterG, 13U));
            aWandererA = aWandererA + ((((RotL64(aIngress, 34U) + aOrbiterI) + RotL64(aOrbiterG, 23U)) + RotL64(aCarry, 19U)) + aNonceWordH);
            aWandererD = aWandererD ^ ((((RotL64(aScatter, 51U) + RotL64(aOrbiterF, 29U)) + aOrbiterC) + aNonceWordN) + aWandererUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterG, 57U)) + aOrbiterD) + aWandererUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 26U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 37U));
            aCarry = aCarry + RotL64(aWandererH, 11U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 2
        // ingress from: aExpandLaneA, aWorkLaneC, aFireLaneC
        // ingress directions: aExpandLaneA forward forced, aWorkLaneC forward forced, aFireLaneC forward/backward random
        // cross from: aWorkLaneA, aWorkLaneD, aOperationLaneB
        // cross directions: aWorkLaneA backward forced, aWorkLaneD backward forced, aOperationLaneB backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 13858U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneC[((aIndex + 13263U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 10115U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 14250U)) & S_BLOCK1], 24U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 14677U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 15401U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aPrevious, 57U) ^ RotL64(aCarry, 27U)) ^ (RotL64(aCross, 5U) + RotL64(aIngress, 40U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterJ = (aWandererD + RotL64(aCross, 21U)) + 6068543441070417854U;
            aOrbiterF = (((aWandererA + RotL64(aPrevious, 57U)) + RotL64(aCarry, 5U)) + 2995980468193441856U) + aOrbiterAssignSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = (aWandererF + RotL64(aIngress, 5U)) + 18020277482171594003U;
            aOrbiterI = (((aWandererG + RotL64(aScatter, 14U)) + RotL64(aCarry, 57U)) + 4293807434721230702U) + aNonceWordL;
            aOrbiterK = ((aWandererK + RotL64(aIngress, 43U)) + 7980599111583893156U) + aNonceWordG;
            aOrbiterC = (aWandererE + RotL64(aPrevious, 37U)) + 8593141111851052016U;
            aOrbiterD = ((((aWandererC + RotL64(aCross, 27U)) + RotL64(aCarry, 27U)) + 5903487523900084325U) + aOrbiterAssignSaltC[((aIndex + 15U)) & S_SALT1]) + aNonceWordM;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 15112035513447930209U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 9854037263057006439U) ^ aOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 396276470208637283U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 16759760289688823193U) + aNonceWordI;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 12622628933030601390U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2151912984825538321U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 1264668857268123425U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 16302812053619101593U;
            aOrbiterI = RotL64((aOrbiterI * 18291400055836111547U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 16087995784896123610U) + aNonceWordE;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 7970269262800468363U;
            aOrbiterC = RotL64((aOrbiterC * 14924752223305807461U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 5331477046030959632U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 16534913204255550893U;
            aOrbiterD = RotL64((aOrbiterD * 1013433634373673565U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 11042821902537871209U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterD) ^ 8069677512345031660U) ^ aOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterF = RotL64((aOrbiterF * 13622218526054132397U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 5737130058129936372U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 1076627182956662997U;
            aOrbiterJ = RotL64((aOrbiterJ * 14342191224014199929U), 13U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterG, 11U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 29U));
            aIngress = aIngress + (RotL64(aOrbiterC, 53U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterJ, 4U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterI, 35U)) + aOrbiterD);
            aWandererA = aWandererA + (((RotL64(aIngress, 27U) + aOrbiterK) + RotL64(aOrbiterI, 53U)) + aWandererUpdateSaltD[((aIndex + 29U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 21U) + aOrbiterF) + RotL64(aOrbiterC, 47U)) + aNonceWordC);
            aWandererD = aWandererD + (((((RotL64(aPrevious, 51U) + aOrbiterI) + RotL64(aOrbiterG, 11U)) + RotL64(aCarry, 3U)) + aNonceWordP) + aWandererUpdateSaltB[((aIndex + 21U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 57U) + aOrbiterF) + RotL64(aOrbiterD, 28U));
            aWandererF = aWandererF + (((RotL64(aCross, 40U) + aOrbiterC) + RotL64(aOrbiterJ, 21U)) + RotL64(aCarry, 51U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterC, 41U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 40U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 23U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 35U));
            aCarry = aCarry + RotL64(aWandererD, 51U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 19298U)) & S_BLOCK1], 42U) ^ RotL64(aWorkLaneD[((aIndex + 16987U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 20477U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 17631U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 23471U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 18369U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aPrevious, 21U) ^ RotL64(aCarry, 37U)) + (RotL64(aCross, 53U) + RotL64(aIngress, 6U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterF = (((aWandererI + RotL64(aCross, 60U)) + RotL64(aCarry, 5U)) + 12380376990224645149U) + aOrbiterAssignSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = ((aWandererK + RotL64(aScatter, 5U)) + RotL64(aCarry, 27U)) + 18296928500297384014U;
            aOrbiterE = (((aWandererJ + RotL64(aPrevious, 47U)) + RotL64(aCarry, 39U)) + 3550626816361145100U) + aOrbiterAssignSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = ((aWandererE + RotL64(aIngress, 13U)) + 2667792936946706027U) + aNonceWordP;
            aOrbiterC = (aWandererF + RotL64(aCross, 19U)) + 12020969779370926953U;
            aOrbiterA = ((aWandererA + RotL64(aIngress, 41U)) + 737340727886903447U) + aNonceWordK;
            aOrbiterJ = ((aWandererH + RotL64(aScatter, 35U)) + 1681797651799760502U) + aNonceWordF;
            //
            aOrbiterF = (((aOrbiterF + aOrbiterI) + 2956186342689489064U) + aOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1]) + aNonceWordD;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 1876852870402977177U) ^ aOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 8875540081346621757U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 6433205819353555071U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 9065076854974222998U;
            aOrbiterA = RotL64((aOrbiterA * 5459675878087242021U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 3254410578766789992U) + aNonceWordO;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 2005081975473815576U;
            aOrbiterI = RotL64((aOrbiterI * 9947701153722014085U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 15992999234834560419U) + aOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 3458344156815120948U;
            aOrbiterF = RotL64((aOrbiterF * 1668460113964608051U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 17069783053664877727U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterE) ^ 1260234710193913099U) ^ aOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterC = RotL64((aOrbiterC * 4561226779897414381U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 3825186451876061335U) + aNonceWordJ;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 2905344294992827535U;
            aOrbiterJ = RotL64((aOrbiterJ * 2469896090698580795U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 18141402347899180617U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 8760129857609925066U;
            aOrbiterB = RotL64((aOrbiterB * 2507999156108123047U), 35U);
            //
            aIngress = RotL64(aOrbiterA, 37U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 53U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 11U));
            aIngress = aIngress + RotL64(aOrbiterI, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aCross, 37U) + aOrbiterI) + RotL64(aOrbiterJ, 47U)) + aNonceWordE);
            aWandererA = aWandererA + (((RotL64(aIngress, 46U) + aOrbiterC) + RotL64(aOrbiterJ, 28U)) + aWandererUpdateSaltF[((aIndex + 24U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterF, 3U)) + aOrbiterJ);
            aWandererF = aWandererF + (((RotL64(aPrevious, 19U) + aOrbiterI) + RotL64(aOrbiterF, 11U)) + RotL64(aCarry, 41U));
            aWandererJ = aWandererJ ^ ((((RotL64(aCross, 57U) + aOrbiterI) + RotL64(aOrbiterB, 57U)) + aNonceWordL) + aWandererUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aIngress, 11U) + RotL64(aOrbiterE, 41U)) + aOrbiterC) + RotL64(aCarry, 21U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 5U) + aOrbiterC) + RotL64(aOrbiterA, 21U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 41U) ^ aWandererE);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 30U));
            aCarry = aCarry + (RotL64(aWandererI, 57U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererH, 3U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aOperationLaneC
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aOperationLaneC forward/backward random
        // cross from: aExpandLaneB, aWorkLaneC, aFireLaneB
        // cross directions: aExpandLaneB backward forced, aWorkLaneC backward forced, aFireLaneB backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 24698U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneA[((aIndex + 30735U)) & S_BLOCK1], 48U));
            aIngress ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 29943U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31263U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 28348U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 28063U)) & S_BLOCK1], 46U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCarry, 57U) + RotL64(aIngress, 41U)) + (RotL64(aPrevious, 5U) ^ RotL64(aCross, 20U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterJ = ((aWandererE + RotL64(aPrevious, 57U)) + 439898681482066326U) + aOrbiterAssignSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterI = ((aWandererC + RotL64(aCross, 27U)) + 17362083676671776094U) + aNonceWordE;
            aOrbiterA = (aWandererK + RotL64(aScatter, 37U)) + 6418499837265155024U;
            aOrbiterH = ((aWandererJ + RotL64(aIngress, 18U)) + RotL64(aCarry, 29U)) + 17262244253027454972U;
            aOrbiterD = (((aWandererA + RotL64(aCross, 3U)) + RotL64(aCarry, 11U)) + 2382066162993139503U) + aNonceWordA;
            aOrbiterB = (((aWandererD + RotL64(aScatter, 43U)) + RotL64(aCarry, 53U)) + 14345808395587174135U) + aNonceWordF;
            aOrbiterG = (((aWandererG + RotL64(aIngress, 11U)) + 7534743166385552851U) + aOrbiterAssignSaltD[((aIndex + 28U)) & S_SALT1]) + aNonceWordP;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 16994453324688523966U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 7079553728544045092U;
            aOrbiterA = RotL64((aOrbiterA * 10104892188895367489U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 3562822704508440641U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 13990892681975857821U;
            aOrbiterI = RotL64((aOrbiterI * 8352929306654078795U), 21U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 1796728922368577238U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 6605161260520067178U) ^ aOrbiterUpdateSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8147537646591674091U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 13994083795942328918U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 6144523182899107711U;
            aOrbiterG = RotL64((aOrbiterG * 4153879991344611283U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 12247462325297436642U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 1065809332002012789U) ^ aNonceWordG;
            aOrbiterJ = RotL64((aOrbiterJ * 5496601177032953251U), 27U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterG) + 10147919864511540753U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordN;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 17138553441127273354U;
            aOrbiterH = RotL64((aOrbiterH * 5773875596275267871U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 2653924016109573974U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 6254416952351699582U;
            aOrbiterB = RotL64((aOrbiterB * 12756861659704947257U), 5U);
            //
            aIngress = RotL64(aOrbiterB, 13U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 47U));
            aIngress = aIngress + (RotL64(aOrbiterA, 34U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterH, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aPrevious, 14U) + RotL64(aOrbiterJ, 5U)) + aOrbiterI) + RotL64(aCarry, 5U)) + aNonceWordB);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 43U) + aOrbiterH) + RotL64(aOrbiterI, 11U));
            aWandererA = aWandererA + ((((RotL64(aScatter, 29U) + aOrbiterG) + RotL64(aOrbiterJ, 19U)) + RotL64(aCarry, 51U)) + aWandererUpdateSaltC[((aIndex + 23U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 37U) + aOrbiterH) + RotL64(aOrbiterB, 60U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterD, 47U)) + aOrbiterB) + aWandererUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aCross, 57U) + aOrbiterI) + RotL64(aOrbiterA, 29U)) + aNonceWordK);
            aWandererC = aWandererC + (((RotL64(aIngress, 21U) + aOrbiterI) + RotL64(aOrbiterD, 37U)) + aNonceWordH);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 52U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 29U));
            aCarry = aCarry + (RotL64(aWandererD, 3U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererG, 39U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltD;
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
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseHWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltB;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x8D51806E717E2C59ULL + 0xB9E4822E087B2487ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xB2AD27C7D6E7422BULL + 0x83E804931F704A06ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x8BEEA096FBA03B51ULL + 0xA5438F37A341EA0DULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x964AE3591811CD63ULL + 0xD65FADCEF9C3E054ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x900AE3AC26C0DFE5ULL + 0x8705D010626672AAULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xA6D10F46ADD8CFF9ULL + 0x9731741D23D2578DULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xABF1CA5E5204CB5FULL + 0xAF513E531587BA48ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xD61A5FE8196A00AFULL + 0x86A3514BD491D406ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xD400DD24DDB1F0B1ULL + 0x927613DCB2F0EC15ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0x8C580440EAA438F9ULL + 0xD9702CFB6735F728ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xDFEA0B2FBA15130BULL + 0xED57A948BA20C343ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xAD891738E2E1B5DBULL + 0x910A43B81C0F5F26ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xF26267A53064293FULL + 0xFFB9319595E966D1ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xA873A74645D56855ULL + 0xC2EA6318D35DC7D5ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x926A419D3EB33D35ULL + 0xC542D9000F6B9FB1ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xC4727C3B2E531A6DULL + 0xF71C156A79587F3CULL);
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
            aIngress = RotL64(aKeyRowReadA[((aIndex + 508U)) & W_KEY1], 20U) ^ RotL64(aKeyRowReadB[((aIndex + 1024U)) & W_KEY1], 57U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 673U)) & W_KEY1], 47U) ^ RotL64(mSource[((aIndex + 1700U)) & S_BLOCK1], 22U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aPrevious, 27U)) + (RotL64(aCarry, 56U) ^ RotL64(aIngress, 41U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterB = (((aWandererI + RotL64(aScatter, 19U)) + RotL64(aCarry, 23U)) + 11410829607777684449U) + aNonceWordC;
            aOrbiterJ = ((aWandererB + RotL64(aIngress, 29U)) + RotL64(aCarry, 5U)) + 7502698839700975347U;
            aOrbiterE = ((aWandererD + RotL64(aCross, 39U)) + 13267685058252106173U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterA = ((aWandererC + RotL64(aPrevious, 53U)) + 238242706996630625U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterF = (aWandererE + RotL64(aScatter, 47U)) + 8184695499511454281U;
            aOrbiterC = ((aWandererK + RotL64(aPrevious, 11U)) + 12767823220461985403U) + aNonceWordM;
            aOrbiterD = (((aWandererJ + RotL64(aCross, 4U)) + RotL64(aCarry, 35U)) + 12293198423143850330U) + aNonceWordA;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 11149495229952495939U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 7556992689338382800U;
            aOrbiterE = RotL64((aOrbiterE * 18232398462716803063U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 3431338808774134649U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 16863099140844995099U) ^ aNonceWordD;
            aOrbiterJ = RotL64((aOrbiterJ * 752376661101787919U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 17872458049880677604U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 16760153457252546974U;
            aOrbiterA = RotL64((aOrbiterA * 11225037229069712805U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 3115544493537438408U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 4359882942759752958U) ^ aNonceWordK;
            aOrbiterB = RotL64((aOrbiterB * 561477566995575801U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 13387113067202396536U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 12955690074544490161U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 12449941770827974511U), 21U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterE) + 15614054443728226807U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1]) + aNonceWordI;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 1939441328066616114U) ^ aNonceWordJ;
            aOrbiterD = RotL64((aOrbiterD * 4484917074808974359U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 4599016263007782537U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 9962305629016158048U;
            aOrbiterC = RotL64((aOrbiterC * 1496184427500037279U), 27U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterA, 3U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 48U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 13U));
            aIngress = aIngress + RotL64(aOrbiterJ, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aIngress, 23U) + RotL64(aOrbiterJ, 35U)) + aOrbiterC);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 47U) + aOrbiterD) + RotL64(aOrbiterF, 41U));
            aWandererD = aWandererD + ((((RotL64(aCross, 54U) + aOrbiterD) + RotL64(aOrbiterB, 13U)) + RotL64(aCarry, 51U)) + aPhaseEWandererUpdateSaltA[((aIndex + 16U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((((RotL64(aPrevious, 29U) + aOrbiterC) + RotL64(aOrbiterB, 27U)) + aNonceWordH) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aIngress, 41U) + aOrbiterA) + RotL64(aOrbiterE, 21U)) + RotL64(aCarry, 13U)) + aNonceWordG);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 13U) + aOrbiterB) + RotL64(aOrbiterE, 53U));
            aWandererC = aWandererC + (((RotL64(aCross, 35U) + aOrbiterA) + RotL64(aOrbiterD, 6U)) + aNonceWordB);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 42U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 57U));
            aCarry = aCarry + (RotL64(aWandererK, 3U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererJ, 23U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 4807U)) & S_BLOCK1], 19U) ^ RotL64(aKeyRowReadA[((aIndex + 3002U)) & W_KEY1], 46U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 3108U)) & W_KEY1], 12U) ^ RotL64(mSource[((aIndex + 4292U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aIngress, 37U) + RotL64(aCarry, 54U)) + (RotL64(aCross, 19U) ^ RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterJ = ((aWandererJ + RotL64(aScatter, 53U)) + RotL64(aCarry, 57U)) + 2571116506511057880U;
            aOrbiterK = ((aWandererF + RotL64(aPrevious, 11U)) + 13112435411509707292U) + aNonceWordE;
            aOrbiterD = ((aWandererB + RotL64(aCross, 5U)) + 10403251762787357256U) + aPhaseEOrbiterAssignSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = ((aWandererD + RotL64(aIngress, 47U)) + RotL64(aCarry, 35U)) + 8461951095541400405U;
            aOrbiterF = (((aWandererK + RotL64(aPrevious, 40U)) + RotL64(aCarry, 5U)) + 9890793478557463815U) + aNonceWordK;
            aOrbiterE = (aWandererH + RotL64(aCross, 21U)) + 3030229465991783707U;
            aOrbiterB = ((aWandererG + RotL64(aScatter, 29U)) + 7273848154043719247U) + aPhaseEOrbiterAssignSaltC[((aIndex + 21U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 10681774862516028276U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 7105082755586853104U;
            aOrbiterD = RotL64((aOrbiterD * 12217705329504230357U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 6588579345319551129U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 14616333550242386092U;
            aOrbiterF = RotL64((aOrbiterF * 2934574715879306337U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 15439666290229654921U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 3360304356760164799U;
            aOrbiterE = RotL64((aOrbiterE * 5164191920584106237U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 14438730801970761889U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 14515616787452085729U;
            aOrbiterB = RotL64((aOrbiterB * 2041601927968559821U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 4167853822635132419U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 8950982233003320239U;
            aOrbiterJ = RotL64((aOrbiterJ * 887144270884244907U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 12391327853728029953U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterE) ^ 7100871010552394421U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterI = RotL64((aOrbiterI * 16552349374101955967U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 15381697462381887944U) + aNonceWordP;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 6801677551341079401U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13325954438427340703U), 3U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterK, 6U);
            aIngress = aIngress + (RotL64(aOrbiterB, 19U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterJ, 35U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterD, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterE, 14U)) + aOrbiterB);
            aWandererD = aWandererD + ((((RotL64(aCross, 11U) + aOrbiterI) + RotL64(aOrbiterK, 53U)) + RotL64(aCarry, 27U)) + aPhaseEWandererUpdateSaltE[((aIndex + 11U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 26U) + aOrbiterD) + RotL64(aOrbiterI, 37U)) + aNonceWordM);
            aWandererF = aWandererF + ((((RotL64(aIngress, 51U) + RotL64(aOrbiterF, 5U)) + aOrbiterJ) + RotL64(aCarry, 47U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 37U) + aOrbiterK) + RotL64(aOrbiterJ, 47U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterE, 27U)) + aOrbiterJ) + aNonceWordG);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 5U) + RotL64(aOrbiterD, 21U)) + aOrbiterE) + aNonceWordF);
            //
            aCarry = aCarry + (RotL64(aWandererD, 29U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererB, 56U) ^ aWandererK);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 35U));
            aCarry = aCarry + RotL64(aWandererG, 39U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = RotL64(aWorkLaneB[((aIndex + 8148U)) & S_BLOCK1], 3U) ^ RotL64(aKeyRowReadB[((aIndex + 7299U)) & W_KEY1], 35U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 7055U)) & W_KEY1], 23U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 7480U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 7074U)) & S_BLOCK1], 60U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aPrevious, 27U) + RotL64(aCarry, 39U)) + (RotL64(aIngress, 10U) ^ RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterA = (((aWandererC + RotL64(aScatter, 57U)) + RotL64(aCarry, 11U)) + 11700815697312060726U) + aPhaseEOrbiterAssignSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterE = ((aWandererA + RotL64(aIngress, 47U)) + RotL64(aCarry, 51U)) + 11808423452327465441U;
            aOrbiterH = (aWandererH + RotL64(aPrevious, 21U)) + 8670503858631730886U;
            aOrbiterG = ((aWandererJ + RotL64(aCross, 3U)) + 2400061067991988544U) + aNonceWordO;
            aOrbiterK = (aWandererB + RotL64(aIngress, 13U)) + 16163118178366229686U;
            aOrbiterC = (aWandererE + RotL64(aPrevious, 34U)) + 3280178595904941068U;
            aOrbiterJ = ((((aWandererD + RotL64(aCross, 27U)) + RotL64(aCarry, 27U)) + 3298683600817047727U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 10U)) & S_SALT1]) + aNonceWordF;
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 16321624053445183574U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 6730229877611375225U;
            aOrbiterH = RotL64((aOrbiterH * 2022290495153519279U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 10162830636713641322U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 15646771327759599256U;
            aOrbiterC = RotL64((aOrbiterC * 15333053762177144775U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 14841751262270544102U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 9545541117228834895U;
            aOrbiterK = RotL64((aOrbiterK * 11529769874752969377U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 14676615635857599982U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 1231768638470558855U) ^ aNonceWordA;
            aOrbiterA = RotL64((aOrbiterA * 2716808508509014677U), 53U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterA) + 1945905595345404833U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordD;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 1406171421638586846U;
            aOrbiterE = RotL64((aOrbiterE * 4577864352425476233U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 1970292335806697198U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 12309719390375013297U;
            aOrbiterJ = RotL64((aOrbiterJ * 16540660957923687327U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 5352135521358954576U) + aNonceWordB;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 15465675376193501658U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 16385761112921041387U), 3U);
            //
            aIngress = RotL64(aOrbiterG, 3U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 47U));
            aIngress = aIngress + (RotL64(aOrbiterE, 21U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterJ, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aScatter, 53U) + aOrbiterA) + RotL64(aOrbiterC, 26U));
            aWandererD = aWandererD + ((((RotL64(aIngress, 43U) + RotL64(aOrbiterC, 35U)) + aOrbiterK) + RotL64(aCarry, 19U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 12U) + RotL64(aOrbiterG, 51U)) + aOrbiterK);
            aWandererB = aWandererB + (((((RotL64(aCross, 21U) + RotL64(aOrbiterH, 3U)) + aOrbiterE) + RotL64(aCarry, 53U)) + aNonceWordK) + aPhaseEWandererUpdateSaltC[((aIndex + 13U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 35U) + aOrbiterC) + RotL64(aOrbiterJ, 19U)) + aNonceWordI);
            aWandererE = aWandererE + ((RotL64(aIngress, 5U) + RotL64(aOrbiterG, 57U)) + aOrbiterE);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterH, 13U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererH, 3U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererB, 39U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererJ, 12U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererC, 47U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 9375U)) & S_BLOCK1], 21U) ^ RotL64(aKeyRowReadB[((aIndex + 10843U)) & W_KEY1], 35U));
            aIngress ^= (RotL64(mSource[((aIndex + 10372U)) & S_BLOCK1], 4U) ^ RotL64(aWorkLaneA[((aIndex + 9032U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 8576U)) & W_KEY1], 21U) ^ RotL64(aWorkLaneB[((aIndex + 8198U)) & S_BLOCK1], 50U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aIngress, 27U) ^ RotL64(aCross, 60U)) + (RotL64(aPrevious, 39U) ^ RotL64(aCarry, 11U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterK = (aWandererA + RotL64(aIngress, 23U)) + 6342299552323486695U;
            aOrbiterH = (((aWandererB + RotL64(aCross, 46U)) + RotL64(aCarry, 5U)) + 12692748514781367538U) + aNonceWordN;
            aOrbiterG = ((((aWandererC + RotL64(aScatter, 29U)) + RotL64(aCarry, 53U)) + 8202639945493229155U) + aPhaseFOrbiterAssignSaltC[((aIndex + 17U)) & S_SALT1]) + aNonceWordD;
            aOrbiterJ = (((aWandererD + RotL64(aPrevious, 3U)) + RotL64(aCarry, 41U)) + 4439975701793231639U) + aNonceWordE;
            aOrbiterE = (aWandererK + RotL64(aIngress, 11U)) + 16774235182859553759U;
            aOrbiterF = ((aWandererJ + RotL64(aPrevious, 37U)) + 8764155413335405667U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterD = ((aWandererH + RotL64(aCross, 53U)) + 7167848811974967685U) + aNonceWordI;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 16768278912125334220U) + aNonceWordG;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 9090838954826296201U;
            aOrbiterG = RotL64((aOrbiterG * 5459329624017272077U), 41U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 7644075729758006298U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterF = (((aOrbiterF ^ aOrbiterJ) ^ 17326182797908071215U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterF = RotL64((aOrbiterF * 2408330168749256075U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 16158809721888137555U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 8029938783858263694U;
            aOrbiterK = RotL64((aOrbiterK * 12628072435324195483U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 8716553521415553404U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 7012599977009208840U;
            aOrbiterJ = RotL64((aOrbiterJ * 8775355876188948851U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 13250558696578541499U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 13705957059101025396U;
            aOrbiterD = RotL64((aOrbiterD * 16889495686487056367U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 2796775206291902461U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 13741676263512390669U;
            aOrbiterE = RotL64((aOrbiterE * 10455782033465595947U), 21U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterK) + 1691908360612389252U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1]) + aNonceWordH;
            aOrbiterH = (((aOrbiterH ^ aOrbiterD) ^ 4114939415206031540U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 16U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterH = RotL64((aOrbiterH * 2797401802892718297U), 35U);
            //
            aIngress = RotL64(aOrbiterG, 57U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterE, 27U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterH, 51U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterJ, 6U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aCross, 3U) + RotL64(aOrbiterD, 51U)) + aOrbiterH);
            aWandererJ = aWandererJ ^ ((((RotL64(aPrevious, 29U) + RotL64(aOrbiterG, 35U)) + aOrbiterJ) + aNonceWordM) + aPhaseFWandererUpdateSaltF[((aIndex + 9U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aIngress, 39U) + aOrbiterE) + RotL64(aOrbiterF, 13U)) + RotL64(aCarry, 51U));
            aWandererA = aWandererA ^ ((((RotL64(aScatter, 18U) + RotL64(aOrbiterK, 3U)) + aOrbiterF) + aNonceWordC) + aPhaseFWandererUpdateSaltA[((aIndex + 4U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aCross, 57U) + aOrbiterH) + RotL64(aOrbiterJ, 23U)) + RotL64(aCarry, 39U)) + aNonceWordJ);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterG, 57U)) + aOrbiterE);
            aWandererB = aWandererB + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterH, 42U)) + aOrbiterG) + aNonceWordB);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 5U));
            aCarry = aCarry + (RotL64(aWandererK, 47U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererA, 30U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererD, 57U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneD[((aIndex + 12262U)) & S_BLOCK1], 3U) ^ RotL64(aKeyRowReadA[((aIndex + 12449U)) & W_KEY1], 39U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 12304U)) & W_KEY1], 13U) ^ RotL64(mSource[((aIndex + 12617U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aWorkLaneB[((aIndex + 11150U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordA));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 12604U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneC[((aIndex + 13170U)) & S_BLOCK1], 38U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aIngress, 23U) ^ RotL64(aCarry, 5U)) ^ (RotL64(aCross, 35U) + RotL64(aPrevious, 52U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterG = ((aWandererD + RotL64(aIngress, 5U)) + 2974056819475622600U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = (((aWandererI + RotL64(aScatter, 11U)) + RotL64(aCarry, 21U)) + 7345051759236356098U) + aNonceWordE;
            aOrbiterD = ((aWandererF + RotL64(aPrevious, 37U)) + RotL64(aCarry, 35U)) + 12738468816846628882U;
            aOrbiterB = ((aWandererB + RotL64(aCross, 19U)) + RotL64(aCarry, 57U)) + 7694520596043297922U;
            aOrbiterE = (((aWandererC + RotL64(aIngress, 29U)) + 5530753590015084774U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordF;
            aOrbiterC = (aWandererA + RotL64(aScatter, 60U)) + 3776309161718383105U;
            aOrbiterA = (aWandererH + RotL64(aPrevious, 51U)) + 784780304358106404U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 8999942326995036509U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 5194986506064092779U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 15070787038006135963U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 7920040007459652762U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 11311997270710107937U) ^ aNonceWordH;
            aOrbiterE = RotL64((aOrbiterE * 6227571709361790209U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 5365231114813547251U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 8630110234623825263U) ^ aNonceWordO;
            aOrbiterA = RotL64((aOrbiterA * 2735881715888325759U), 37U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 2358235238039571072U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 18059414891616491807U;
            aOrbiterB = RotL64((aOrbiterB * 17150786106857185467U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 14526050556461782864U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 6937282036603272474U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14954512365270028029U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 10105832250694931310U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 3884223553012098137U;
            aOrbiterK = RotL64((aOrbiterK * 16340956813003906195U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 10385284339549648087U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 1257633893341505930U;
            aOrbiterG = RotL64((aOrbiterG * 2669950791270500977U), 51U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterC, 5U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 34U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 19U));
            aIngress = aIngress + RotL64(aOrbiterD, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aCross, 35U) + aOrbiterA) + RotL64(aOrbiterC, 4U)) + aNonceWordN);
            aWandererC = aWandererC + (((RotL64(aScatter, 57U) + aOrbiterC) + RotL64(aOrbiterD, 13U)) + aNonceWordD);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterB, 29U)) + aOrbiterA);
            aWandererH = aWandererH + ((((RotL64(aIngress, 20U) + aOrbiterE) + RotL64(aOrbiterG, 47U)) + RotL64(aCarry, 13U)) + aPhaseFWandererUpdateSaltD[((aIndex + 24U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 51U) + aOrbiterA) + RotL64(aOrbiterK, 19U));
            aWandererD = aWandererD + ((((RotL64(aCross, 43U) + aOrbiterA) + RotL64(aOrbiterE, 39U)) + RotL64(aCarry, 41U)) + aNonceWordC);
            aWandererA = aWandererA ^ ((((RotL64(aPrevious, 29U) + RotL64(aOrbiterG, 57U)) + aOrbiterK) + aNonceWordL) + aPhaseFWandererUpdateSaltC[((aIndex + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 53U));
            aCarry = aCarry + (RotL64(aWandererC, 30U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererI, 11U);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 14449U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 14628U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 16337U)) & W_KEY1], 41U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 14251U)) & W_KEY1], 11U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 14478U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 14707U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 13933U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCarry, 13U) + RotL64(aPrevious, 27U)) ^ (RotL64(aIngress, 39U) + RotL64(aCross, 56U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterC = (aWandererJ + RotL64(aCross, 43U)) + 16451272412693907816U;
            aOrbiterG = (aWandererD + RotL64(aScatter, 3U)) + 10099485419723255462U;
            aOrbiterH = (((aWandererA + RotL64(aPrevious, 13U)) + 17668900099534923192U) + aPhaseFOrbiterAssignSaltC[((aIndex + 19U)) & S_SALT1]) + aNonceWordL;
            aOrbiterB = ((aWandererG + RotL64(aIngress, 56U)) + 5497093724143181753U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterK = (((aWandererK + RotL64(aScatter, 35U)) + RotL64(aCarry, 53U)) + 10354044773550071706U) + aNonceWordI;
            aOrbiterE = (((aWandererE + RotL64(aPrevious, 29U)) + RotL64(aCarry, 5U)) + 12728258851198019099U) + aNonceWordD;
            aOrbiterJ = ((aWandererH + RotL64(aIngress, 23U)) + RotL64(aCarry, 29U)) + 4144050505314242618U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 14133805325480076530U) + aNonceWordC;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 308863673210602899U) ^ aNonceWordJ;
            aOrbiterH = RotL64((aOrbiterH * 2672613556981540433U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 11741180130160569753U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 12926863156769180448U;
            aOrbiterC = RotL64((aOrbiterC * 9726030996091054939U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 211920854786494259U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterH) ^ 13234608842479411078U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterK = RotL64((aOrbiterK * 2556747209733759467U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 9164711974854618892U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 6667377062281954219U;
            aOrbiterB = RotL64((aOrbiterB * 2603737166987437649U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 4559040002406721850U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 1749875480850675109U;
            aOrbiterG = RotL64((aOrbiterG * 15822640067349481089U), 53U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterC) + 9555365165561936366U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1]) + aNonceWordM;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 18289733999504213574U;
            aOrbiterJ = RotL64((aOrbiterJ * 14156217554673229429U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 8727162691639622461U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 291406782452963706U;
            aOrbiterE = RotL64((aOrbiterE * 8413500075082350243U), 41U);
            //
            aIngress = RotL64(aOrbiterG, 21U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 47U));
            aIngress = aIngress + (RotL64(aOrbiterE, 3U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterK, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterB, 41U)) + aOrbiterG) + aNonceWordH);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 35U) + aOrbiterH) + RotL64(aOrbiterC, 48U)) + aPhaseFWandererUpdateSaltC[((aIndex + 7U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 57U) + RotL64(aOrbiterJ, 3U)) + aOrbiterH) + RotL64(aCarry, 19U)) + aNonceWordO);
            aWandererE = aWandererE ^ ((RotL64(aCross, 19U) + aOrbiterH) + RotL64(aOrbiterK, 11U));
            aWandererH = aWandererH + (((RotL64(aIngress, 13U) + RotL64(aOrbiterG, 57U)) + aOrbiterK) + RotL64(aCarry, 5U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 50U) + RotL64(aOrbiterJ, 35U)) + aOrbiterK) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 3U) + RotL64(aOrbiterE, 23U)) + aOrbiterC) + aNonceWordE);
            //
            aCarry = aCarry + (RotL64(aWandererK, 6U) ^ aWandererH);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 19U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 23U));
            aCarry = aCarry + RotL64(aWandererA, 13U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 16751U)) & S_BLOCK1], 3U) ^ RotL64(aKeyRowReadA[((aIndex + 18201U)) & W_KEY1], 13U));
            aIngress ^= (RotL64(mSource[((aIndex + 19099U)) & S_BLOCK1], 44U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16584U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 18547U)) & W_KEY1], 6U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 17064U)) & S_BLOCK1], 53U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 17832U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCarry, 21U)) + (RotL64(aIngress, 52U) ^ RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterD = ((aWandererE + RotL64(aPrevious, 10U)) + RotL64(aCarry, 27U)) + 7790166497945719700U;
            aOrbiterK = (((aWandererK + RotL64(aScatter, 43U)) + RotL64(aCarry, 53U)) + 7136208896846119188U) + aNonceWordC;
            aOrbiterB = ((aWandererH + RotL64(aIngress, 3U)) + 12123156943355100886U) + aNonceWordH;
            aOrbiterJ = ((((aWandererG + RotL64(aCross, 27U)) + RotL64(aCarry, 5U)) + 5095546037880875199U) + aPhaseGOrbiterAssignSaltB[((aIndex + 21U)) & S_SALT1]) + aNonceWordL;
            aOrbiterE = ((aWandererJ + RotL64(aScatter, 21U)) + 17642705393916765992U) + aNonceWordP;
            aOrbiterI = ((aWandererD + RotL64(aCross, 35U)) + 9918479837334416990U) + aPhaseGOrbiterAssignSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterA = (aWandererF + RotL64(aIngress, 51U)) + 4890009823843176466U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 17652590786213674124U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 870002527644696135U;
            aOrbiterB = RotL64((aOrbiterB * 915408393979165539U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 12545429703552643682U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 5310272867406182581U;
            aOrbiterE = RotL64((aOrbiterE * 10420003334833925011U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 3264719049050179440U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 1967241238180278937U) ^ aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 13004319774269457957U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 773883832927040736U) + aPhaseGOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 12766817190261232485U) ^ aNonceWordB;
            aOrbiterI = RotL64((aOrbiterI * 7448864556802318431U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 260069382395598265U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 15462103891287350123U;
            aOrbiterA = RotL64((aOrbiterA * 5029268763635635753U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 4072032867513289827U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 17153061419083897076U) ^ aNonceWordN;
            aOrbiterK = RotL64((aOrbiterK * 11934532169271718913U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 6207264270332656966U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 18048064697837314947U) ^ aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13632594619404208489U), 29U);
            //
            aIngress = RotL64(aOrbiterA, 37U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterE, 43U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterB, 29U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterJ, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aIngress, 4U) + RotL64(aOrbiterA, 37U)) + aOrbiterJ);
            aWandererH = aWandererH + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterI, 19U)) + aOrbiterD) + RotL64(aCarry, 27U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 51U) + aOrbiterD) + RotL64(aOrbiterK, 3U));
            aWandererE = aWandererE + ((((RotL64(aCross, 13U) + RotL64(aOrbiterJ, 57U)) + aOrbiterK) + RotL64(aCarry, 13U)) + aNonceWordG);
            aWandererG = aWandererG ^ ((((RotL64(aPrevious, 29U) + aOrbiterE) + RotL64(aOrbiterB, 43U)) + aNonceWordD) + aPhaseGWandererUpdateSaltD[((aIndex + 13U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aCross, 35U) + RotL64(aOrbiterJ, 12U)) + aOrbiterD);
            aWandererJ = aWandererJ ^ ((((RotL64(aScatter, 21U) + RotL64(aOrbiterK, 27U)) + aOrbiterE) + aNonceWordK) + aPhaseGWandererUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 6U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererJ, 23U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererF, 13U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererG, 51U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 21799U)) & S_BLOCK1], 21U) ^ RotL64(mSource[((aIndex + 21477U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aFireLaneA[((aIndex + 19531U)) & S_BLOCK1], 48U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19560U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 20665U)) & W_KEY1], 39U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 20425U)) & W_KEY1], 28U));
            aCross ^= (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 20852U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneB[((aIndex + 21636U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCross, 41U) + RotL64(aPrevious, 5U)) + (RotL64(aIngress, 19U) ^ RotL64(aCarry, 56U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterJ = ((aWandererK + RotL64(aPrevious, 13U)) + RotL64(aCarry, 35U)) + 6973892330986118220U;
            aOrbiterC = (((aWandererE + RotL64(aCross, 5U)) + RotL64(aCarry, 3U)) + 9886813896272094864U) + aPhaseGOrbiterAssignSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = (((aWandererJ + RotL64(aScatter, 26U)) + RotL64(aCarry, 51U)) + 10996306582517553173U) + aNonceWordB;
            aOrbiterH = (((aWandererH + RotL64(aIngress, 53U)) + 8490648283899856223U) + aPhaseGOrbiterAssignSaltE[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordF;
            aOrbiterF = (aWandererA + RotL64(aCross, 47U)) + 105141713530704655U;
            aOrbiterD = ((aWandererC + RotL64(aScatter, 41U)) + 3114337422810562588U) + aNonceWordJ;
            aOrbiterB = ((aWandererG + RotL64(aIngress, 35U)) + 980857684690886131U) + aNonceWordH;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 6562042345807072665U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 15665371138706353619U;
            aOrbiterI = RotL64((aOrbiterI * 8086237578564620623U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 18113013571374375028U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 17405346422601997299U) ^ aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11162604605443005253U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 5130876096426182506U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 1813821672299154629U) ^ aNonceWordI;
            aOrbiterD = RotL64((aOrbiterD * 15478100342425611875U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 15793814882743306728U) + aPhaseGOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 13925299440495476399U;
            aOrbiterC = RotL64((aOrbiterC * 12049601510660117401U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 9924458846049579438U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 7810034662781768090U) ^ aPhaseGOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10310594595026622513U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 12812586478656872854U) + aNonceWordA;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 5709576448057435237U;
            aOrbiterH = RotL64((aOrbiterH * 9101555233909853025U), 41U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 7839807649914541516U) + aNonceWordN;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 4717944526755429647U;
            aOrbiterJ = RotL64((aOrbiterJ * 8515229146471335721U), 3U);
            //
            aIngress = RotL64(aOrbiterD, 27U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 21U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 3U));
            aIngress = aIngress + RotL64(aOrbiterH, 34U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aCross, 35U) + aOrbiterC) + RotL64(aOrbiterD, 57U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterF, 5U)) + aOrbiterI);
            aWandererC = aWandererC + (((((RotL64(aPrevious, 22U) + RotL64(aOrbiterH, 43U)) + aOrbiterI) + RotL64(aCarry, 5U)) + aNonceWordL) + aPhaseGWandererUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 47U) + aOrbiterJ) + RotL64(aOrbiterD, 13U)) + aNonceWordO);
            aWandererK = aWandererK + (((RotL64(aCross, 29U) + aOrbiterF) + RotL64(aOrbiterC, 36U)) + RotL64(aCarry, 35U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 13U) + RotL64(aOrbiterC, 27U)) + aOrbiterH) + aNonceWordD);
            aWandererA = aWandererA + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterH, 51U)) + aOrbiterB) + aPhaseGWandererUpdateSaltD[((aIndex + 28U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 10U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererG, 23U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererA, 43U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererK, 51U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 23948U)) & S_BLOCK1], 43U) ^ RotL64(aKeyRowReadA[((aIndex + 24065U)) & W_KEY1], 51U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 23631U)) & W_KEY1], 11U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 22613U)) & S_BLOCK1], 60U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 23324U)) & S_BLOCK1], 13U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 22253U)) & S_BLOCK1], 3U));
            aCross ^= (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 22381U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 23134U)) & S_BLOCK1], 22U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aPrevious, 27U) ^ RotL64(aCarry, 11U)) + (RotL64(aIngress, 56U) ^ RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterJ = (aWandererJ + RotL64(aIngress, 53U)) + 11480359716598965890U;
            aOrbiterK = (((aWandererB + RotL64(aScatter, 47U)) + RotL64(aCarry, 23U)) + 15431182525482873419U) + aPhaseGOrbiterAssignSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterF = (((aWandererA + RotL64(aCross, 14U)) + RotL64(aCarry, 41U)) + 11360504974812776707U) + aNonceWordM;
            aOrbiterC = ((aWandererI + RotL64(aPrevious, 29U)) + 9292576416573382769U) + aNonceWordB;
            aOrbiterI = (((aWandererE + RotL64(aScatter, 23U)) + 1549257414531028975U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordP;
            aOrbiterA = (((aWandererC + RotL64(aPrevious, 41U)) + RotL64(aCarry, 3U)) + 5347769463033129317U) + aNonceWordO;
            aOrbiterG = (aWandererD + RotL64(aCross, 35U)) + 17019199177478377234U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 16558106007323125094U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 3976182233825939422U;
            aOrbiterF = RotL64((aOrbiterF * 4392162052317572289U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 2889047161195954395U) + aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 2241831345026962605U) ^ aNonceWordK;
            aOrbiterA = RotL64((aOrbiterA * 5757458560979927857U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 12850802412140579294U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 13541744735436450160U;
            aOrbiterC = RotL64((aOrbiterC * 906089290000537439U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 2085863085516538212U) + aNonceWordD;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 2969034221711544086U;
            aOrbiterG = RotL64((aOrbiterG * 7768528124408400403U), 41U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 6482666944512391472U) + aNonceWordE;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 16969153556875844613U) ^ aPhaseGOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 9483462388353216219U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 5161314086757363678U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 7150282484670673211U) ^ aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8522427002337918663U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 5465304381272305847U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterA) ^ 2344610773390354017U) ^ aPhaseGOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterJ = RotL64((aOrbiterJ * 17010258514288089191U), 53U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterG, 37U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 24U));
            aIngress = aIngress + (RotL64(aOrbiterI, 13U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterA, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 23U) + aOrbiterF) + RotL64(aOrbiterC, 35U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 58U) + aOrbiterI) + RotL64(aOrbiterG, 29U)) + RotL64(aCarry, 13U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 51U) + aOrbiterJ) + RotL64(aOrbiterA, 58U)) + aNonceWordH);
            aWandererB = aWandererB + (((RotL64(aIngress, 43U) + aOrbiterA) + RotL64(aOrbiterC, 41U)) + aNonceWordC);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 11U) + aOrbiterK) + RotL64(aOrbiterJ, 11U)) + aPhaseGWandererUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aIngress, 3U) + aOrbiterG) + RotL64(aOrbiterK, 3U)) + RotL64(aCarry, 35U)) + aPhaseGWandererUpdateSaltE[((aIndex + 14U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 29U) + aOrbiterA) + RotL64(aOrbiterG, 47U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 6U) ^ aWandererA);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 29U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 37U));
            aCarry = aCarry + RotL64(aWandererJ, 53U);
            aCarry = aCarry + RotL64(aIngress, 10U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 26860U)) & S_BLOCK1], 57U) ^ RotL64(aKeyRowReadA[((aIndex + 26976U)) & W_KEY1], 41U));
            aIngress ^= (RotL64(aFireLaneD[((aIndex + 27285U)) & S_BLOCK1], 27U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 26802U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 25657U)) & W_KEY1], 30U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 27097U)) & S_BLOCK1], 53U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 25002U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 27121U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCross, 10U) + RotL64(aPrevious, 57U)) ^ (RotL64(aCarry, 23U) + RotL64(aIngress, 43U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterC = (aWandererB + RotL64(aScatter, 57U)) + 9220392006207660113U;
            aOrbiterH = (aWandererC + RotL64(aPrevious, 35U)) + 11305018553489132882U;
            aOrbiterD = ((((aWandererA + RotL64(aCross, 47U)) + RotL64(aCarry, 37U)) + 5860373868073513684U) + aPhaseHOrbiterAssignSaltC[((aIndex + 14U)) & S_SALT1]) + aNonceWordF;
            aOrbiterF = (((aWandererE + RotL64(aIngress, 28U)) + RotL64(aCarry, 19U)) + 12319586170883987589U) + aPhaseHOrbiterAssignSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = (aWandererH + RotL64(aCross, 19U)) + 14072333614354649021U;
            aOrbiterJ = ((aWandererG + RotL64(aScatter, 3U)) + 9332158529453194608U) + aNonceWordC;
            aOrbiterI = ((aWandererD + RotL64(aPrevious, 41U)) + RotL64(aCarry, 5U)) + 3860569321145958686U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 8119005668901240093U) + aNonceWordM;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 13918259792880333239U;
            aOrbiterD = RotL64((aOrbiterD * 5441062406822088853U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 6938856216758228704U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 3960905839118710604U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 16203746868670689793U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 6043879193734253929U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 15691425268831319195U;
            aOrbiterE = RotL64((aOrbiterE * 7189195135654636271U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 14912209933584715274U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 16180183395910618923U;
            aOrbiterF = RotL64((aOrbiterF * 3942858974766467849U), 35U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterC) + 4966642362507707776U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordL;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 6962226782462822861U) ^ aNonceWordO;
            aOrbiterH = RotL64((aOrbiterH * 3647802407741095419U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 12409120845092026295U) + aNonceWordD;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 2302946450253872465U;
            aOrbiterJ = RotL64((aOrbiterJ * 7099576330777297911U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 16118304388937163838U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 15968419034359049422U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11736207775827080165U), 5U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterD, 3U);
            aIngress = aIngress + (RotL64(aOrbiterF, 13U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterE, 35U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterJ, 20U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 43U) + aOrbiterC) + RotL64(aOrbiterH, 51U));
            aWandererC = aWandererC + (((RotL64(aIngress, 51U) + aOrbiterJ) + RotL64(aOrbiterD, 42U)) + RotL64(aCarry, 21U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 6U) + aOrbiterC) + RotL64(aOrbiterE, 11U)) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aScatter, 13U) + RotL64(aOrbiterJ, 27U)) + aOrbiterF);
            aWandererB = aWandererB ^ ((((RotL64(aCross, 29U) + aOrbiterJ) + RotL64(aOrbiterI, 57U)) + aNonceWordJ) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 35U) + RotL64(aOrbiterE, 5U)) + aOrbiterH) + RotL64(aCarry, 3U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 23U) + RotL64(aOrbiterJ, 19U)) + aOrbiterE) + aNonceWordA);
            //
            aCarry = aCarry + (RotL64(aWandererD, 51U) ^ aWandererE);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 58U));
            aCarry = aCarry + (RotL64(aWandererC, 41U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererH, 11U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 29363U)) & S_BLOCK1], 60U) ^ RotL64(aFireLaneD[((aIndex + 29930U)) & S_BLOCK1], 29U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 29764U)) & W_KEY1], 51U) ^ RotL64(aFireLaneC[((aIndex + 28388U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 30033U)) & W_KEY1], 3U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 28017U)) & S_BLOCK1], 26U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27752U)) & S_BLOCK1], 35U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 29071U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aIngress, 23U) + RotL64(aCarry, 37U)) ^ (RotL64(aPrevious, 51U) ^ RotL64(aCross, 10U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterI = (aWandererG + RotL64(aCross, 57U)) + 5721224134332887360U;
            aOrbiterD = ((aWandererE + RotL64(aPrevious, 3U)) + RotL64(aCarry, 11U)) + 6892749729775049095U;
            aOrbiterC = (((aWandererB + RotL64(aScatter, 35U)) + 3884839462099556836U) + aPhaseHOrbiterAssignSaltE[((aIndex + 28U)) & S_SALT1]) + aNonceWordC;
            aOrbiterJ = ((aWandererD + RotL64(aIngress, 29U)) + 4365431706830216193U) + aNonceWordP;
            aOrbiterG = (((aWandererH + RotL64(aCross, 20U)) + RotL64(aCarry, 53U)) + 15501528746571578773U) + aPhaseHOrbiterAssignSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = (aWandererF + RotL64(aPrevious, 41U)) + 4505911326320650606U;
            aOrbiterK = ((aWandererJ + RotL64(aIngress, 13U)) + RotL64(aCarry, 29U)) + 1865129050927879580U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 2011737665969640369U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 611672935827062688U;
            aOrbiterC = RotL64((aOrbiterC * 12873671551304596619U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 663547038310431047U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 5468932264754299556U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 11968657455484578525U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 17920294117231191705U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 486058453837528110U;
            aOrbiterI = RotL64((aOrbiterI * 8851102552244026737U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 2789178451938129313U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 420772587981211184U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 17402987842294006667U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 16196774774442181825U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 16264169656793713547U;
            aOrbiterA = RotL64((aOrbiterA * 6900221986041638783U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 10207659833859860796U) + aNonceWordB;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 8593749091183323678U) ^ aNonceWordI;
            aOrbiterK = RotL64((aOrbiterK * 10696776033512404927U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 7224922076047787384U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 15366267474865172373U) ^ aNonceWordA;
            aOrbiterJ = RotL64((aOrbiterJ * 10134187073321814217U), 41U);
            //
            aIngress = RotL64(aOrbiterG, 51U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterJ, 57U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 21U));
            aIngress = aIngress + RotL64(aOrbiterD, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aScatter, 29U) + aOrbiterJ) + RotL64(aOrbiterC, 53U)) + aNonceWordK);
            aWandererF = aWandererF ^ ((((RotL64(aCross, 21U) + aOrbiterI) + RotL64(aOrbiterD, 11U)) + aNonceWordF) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aIngress, 35U) + aOrbiterJ) + RotL64(aOrbiterK, 27U)) + RotL64(aCarry, 57U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 14U) + RotL64(aOrbiterA, 41U)) + aOrbiterD);
            aWandererG = aWandererG + ((((RotL64(aScatter, 41U) + RotL64(aOrbiterK, 47U)) + aOrbiterI) + RotL64(aCarry, 27U)) + aPhaseHWandererUpdateSaltE[((aIndex + 3U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 57U) + RotL64(aOrbiterI, 35U)) + aOrbiterG) + aNonceWordG);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 51U) + aOrbiterI) + RotL64(aOrbiterC, 4U)) + aNonceWordL);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 35U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 3U));
            aCarry = aCarry + (RotL64(aWandererE, 18U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererG, 41U);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 30470U)) & S_BLOCK1], 13U) ^ RotL64(aKeyRowReadA[((aIndex + 31325U)) & W_KEY1], 37U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 32001U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30504U)) & S_BLOCK1], 41U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31335U)) & S_BLOCK1], 5U) ^ RotL64(aKeyRowReadB[((aIndex + 32537U)) & W_KEY1], 14U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCarry, 23U) ^ RotL64(aPrevious, 4U)) + (RotL64(aCross, 51U) ^ RotL64(aIngress, 37U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterK = (aWandererG + RotL64(aPrevious, 35U)) + 5568146815535263910U;
            aOrbiterJ = (((aWandererC + RotL64(aCross, 4U)) + RotL64(aCarry, 5U)) + 7736084960873834666U) + aNonceWordF;
            aOrbiterC = (aWandererI + RotL64(aIngress, 41U)) + 1336413621817562093U;
            aOrbiterG = ((((aWandererB + RotL64(aScatter, 21U)) + RotL64(aCarry, 19U)) + 5218462026934984692U) + aPhaseHOrbiterAssignSaltD[((aIndex + 28U)) & S_SALT1]) + aNonceWordC;
            aOrbiterE = ((aWandererE + RotL64(aIngress, 51U)) + 7048890985969555935U) + aNonceWordP;
            aOrbiterF = ((((aWandererK + RotL64(aPrevious, 27U)) + RotL64(aCarry, 51U)) + 13415955213864702118U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 14U)) & S_SALT1]) + aNonceWordB;
            aOrbiterA = (aWandererH + RotL64(aCross, 57U)) + 5657023257021528548U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 14338310943137497116U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 12305161641833950473U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 11949964304435964395U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 14514226578370459131U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 12692904083266024340U;
            aOrbiterE = RotL64((aOrbiterE * 14800805065279908839U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 11012959130001327964U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 7106471380403489078U;
            aOrbiterJ = RotL64((aOrbiterJ * 515626559384817223U), 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 3718101961355280891U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 13364192077222322664U;
            aOrbiterG = RotL64((aOrbiterG * 1411328915372590283U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 6720867800318913440U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 14497243926965866546U) ^ aNonceWordH;
            aOrbiterA = RotL64((aOrbiterA * 13595058589060114653U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 5789056168233262435U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 14438482587495779937U) ^ aNonceWordG;
            aOrbiterF = RotL64((aOrbiterF * 10593535547917767263U), 53U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 313917798940179945U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 15241845511889502917U;
            aOrbiterK = RotL64((aOrbiterK * 16483477103771326107U), 47U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterE, 11U);
            aIngress = aIngress + (RotL64(aOrbiterA, 19U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterF, 35U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterJ, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aIngress, 35U) + RotL64(aOrbiterG, 11U)) + aOrbiterA) + aPhaseHWandererUpdateSaltF[((aIndex + 11U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aPrevious, 29U) + aOrbiterK) + RotL64(aOrbiterE, 27U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterK, 41U)) + aOrbiterG) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aScatter, 41U) + aOrbiterJ) + RotL64(aOrbiterE, 34U)) + RotL64(aCarry, 11U)) + aNonceWordI);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 12U) + RotL64(aOrbiterJ, 5U)) + aOrbiterG) + aNonceWordM);
            aWandererC = aWandererC + ((((RotL64(aIngress, 21U) + RotL64(aOrbiterA, 53U)) + aOrbiterF) + RotL64(aCarry, 57U)) + aNonceWordE);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 51U) + RotL64(aOrbiterE, 47U)) + aOrbiterC) + aNonceWordJ);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 50U));
            aCarry = aCarry + (RotL64(aWandererG, 13U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererB, 19U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererK, 57U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x885279D82E8FDF5BULL + 0xD80DD872034AAECDULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xBF15E5981E77A4A3ULL + 0xE2430770D9D99724ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xCD694A74EA0565E7ULL + 0xE74358B9BCD486DCULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xC160FDDDFF553B17ULL + 0xC8FF3A216C030A0AULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xC63E236D8C21DEF9ULL + 0xA40DB4FE3304583CULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xE9CF7C5568CF13F9ULL + 0xAEAC91AF2CAB1FA7ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xA8C4209A9120BE5BULL + 0xD5A357DF69B12CC7ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xD5F8F521D59F144DULL + 0xE824103A7D69352CULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xAE55C8DFDAFB1F11ULL + 0xB9E327C41F9C5E98ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xE75F8241EE49268FULL + 0xF59D83447E618942ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x93DD6B7E336B2EA3ULL + 0xBF4324761122AC6FULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x804FD92A78FE56C3ULL + 0x8E1935904A2389A9ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xCFEB249DA8F100CFULL + 0x9414B0A8208EE0BFULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0x9D12CBCCCB82FF17ULL + 0xA81BCF87E9A0C661ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xF8E44D50F5AE8B6DULL + 0xA7E702DE79700F35ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0x8FCC792DEE0CD04DULL + 0xD767F3AD08415166ULL);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 1622U)) & S_BLOCK1], 28U) ^ RotL64(aExpandLaneB[((aIndex + 2481U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 480U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 3674U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 1863U)) & S_BLOCK1], 54U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCarry, 26U) + RotL64(aIngress, 39U)) ^ (RotL64(aCross, 57U) ^ RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterC = ((aWandererG + RotL64(aIngress, 38U)) + RotL64(aCarry, 43U)) + 16651241552253078315U;
            aOrbiterA = (((aWandererA + RotL64(aPrevious, 11U)) + 4558144676982478003U) + aPhaseAOrbiterAssignSaltA[((aIndex + 5U)) & S_SALT1]) + aNonceWordB;
            aOrbiterH = ((((aWandererK + RotL64(aScatter, 3U)) + RotL64(aCarry, 29U)) + 8814884320080367550U) + aPhaseAOrbiterAssignSaltB[((aIndex + 23U)) & S_SALT1]) + aNonceWordG;
            aOrbiterE = ((aWandererC + RotL64(aCross, 29U)) + RotL64(aCarry, 3U)) + 16011579668555672117U;
            aOrbiterD = ((aWandererD + RotL64(aPrevious, 57U)) + 4738918668759862438U) + aNonceWordE;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 12526083125540985108U) + aNonceWordH;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 8048723561746000552U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 11914807994597963481U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 1082218464034639039U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 8432043246965946816U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 7801965585991025451U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 9982080524048636852U) + aNonceWordJ;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 6720069955755215919U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 1025046364205332059U), 13U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterC) + 1019035028070247757U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1]) + aNonceWordD;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 7360619079463870467U;
            aOrbiterA = RotL64((aOrbiterA * 6623074813047915863U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 10893918488381348474U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 1390297670907738019U) ^ aNonceWordF;
            aOrbiterE = RotL64((aOrbiterE * 11909657437658597735U), 35U);
            //
            aIngress = RotL64(aOrbiterD, 29U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterE, 51U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterH, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aScatter, 51U) + RotL64(aOrbiterA, 57U)) + aOrbiterD) + aNonceWordK) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 43U) + aOrbiterD) + RotL64(aOrbiterH, 39U));
            aWandererC = aWandererC + ((((RotL64(aPrevious, 3U) + aOrbiterE) + RotL64(aOrbiterD, 27U)) + RotL64(aCarry, 47U)) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 30U) + RotL64(aOrbiterH, 47U)) + aOrbiterC) + aNonceWordL);
            aWandererG = aWandererG + (((RotL64(aScatter, 21U) + aOrbiterE) + RotL64(aOrbiterA, 4U)) + RotL64(aCarry, 13U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 37U));
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererC, 3U);
            aCarry = aCarry + RotL64(aIngress, 14U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 10513U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneC[((aIndex + 5704U)) & S_BLOCK1], 36U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 6711U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 6400U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 6930U)) & S_BLOCK1], 24U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aPrevious, 54U)) + (RotL64(aCross, 39U) ^ RotL64(aIngress, 19U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterK = ((aWandererF + RotL64(aCross, 56U)) + RotL64(aCarry, 23U)) + 9914837590440975587U;
            aOrbiterG = (((aWandererK + RotL64(aScatter, 47U)) + RotL64(aCarry, 11U)) + 6706125076401958051U) + aNonceWordN;
            aOrbiterI = ((aWandererJ + RotL64(aIngress, 29U)) + 16570817772679258409U) + aPhaseAOrbiterAssignSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = ((((aWandererD + RotL64(aPrevious, 21U)) + RotL64(aCarry, 53U)) + 6843705658115186948U) + aPhaseAOrbiterAssignSaltE[((aIndex + 23U)) & S_SALT1]) + aNonceWordB;
            aOrbiterH = ((aWandererE + RotL64(aIngress, 37U)) + 16099930446791572351U) + aNonceWordO;
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 5420550009556030459U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 5729549069420177477U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7842192631021712569U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 15590601126188675834U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 13044027390998620029U) ^ aNonceWordF;
            aOrbiterK = RotL64((aOrbiterK * 16845199115313444123U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 11068338135659636772U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 6584988841809544332U;
            aOrbiterG = RotL64((aOrbiterG * 1683336180438945439U), 3U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterJ) + 8516813219883915404U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1]) + aNonceWordG;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 10647314042912492785U;
            aOrbiterH = RotL64((aOrbiterH * 15559481057047148785U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 201691689889605304U) + aNonceWordJ;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 15512161798401184003U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 11473219183982564709U), 41U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterJ, 13U);
            aIngress = aIngress + (RotL64(aOrbiterK, 26U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterG, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aPrevious, 21U) + aOrbiterG) + RotL64(aOrbiterJ, 35U)) + RotL64(aCarry, 57U)) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 37U) + aOrbiterG) + RotL64(aOrbiterK, 14U)) + aNonceWordM);
            aWandererF = aWandererF + ((((RotL64(aCross, 13U) + RotL64(aOrbiterK, 3U)) + aOrbiterH) + RotL64(aCarry, 23U)) + aNonceWordI);
            aWandererJ = aWandererJ ^ ((((RotL64(aIngress, 5U) + aOrbiterI) + RotL64(aOrbiterH, 57U)) + aNonceWordA) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 48U) + RotL64(aOrbiterJ, 27U)) + aOrbiterI) + aNonceWordD);
            //
            aCarry = aCarry + (RotL64(aWandererD, 11U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererE, 47U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererK, 3U);
            aCarry = aCarry + RotL64(aIngress, 26U);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 15867U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneD[((aIndex + 13790U)) & S_BLOCK1], 10U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 12030U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 14247U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 15353U)) & S_BLOCK1], 48U));
            aCross ^= RotL64(aExpandLaneA[((aIndex + 16134U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCross, 51U) + RotL64(aIngress, 5U)) ^ (RotL64(aPrevious, 20U) ^ RotL64(aCarry, 35U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterB = ((((aWandererD + RotL64(aPrevious, 19U)) + RotL64(aCarry, 13U)) + 1952750591494698524U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterE = ((aWandererI + RotL64(aScatter, 5U)) + RotL64(aCarry, 51U)) + 4488270851303332830U;
            aOrbiterG = (((aWandererH + RotL64(aIngress, 60U)) + RotL64(aCarry, 35U)) + 2738763375328927635U) + aNonceWordC;
            aOrbiterF = ((aWandererJ + RotL64(aCross, 51U)) + 6728843649480454340U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterH = ((aWandererK + RotL64(aIngress, 41U)) + 10490717875258865358U) + aNonceWordA;
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 1429288737812910205U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 2761375016998907636U;
            aOrbiterG = RotL64((aOrbiterG * 16589197409983023283U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 1088988605204499835U) + aNonceWordG;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 6829840407300289709U) ^ aNonceWordI;
            aOrbiterE = RotL64((aOrbiterE * 13101432880030791787U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 9267240337867690471U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 8120113021183975703U;
            aOrbiterB = RotL64((aOrbiterB * 14296504593187173107U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 1340980511302566784U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterG) ^ 11874452169979878835U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterF = RotL64((aOrbiterF * 8638486178860092537U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 1872314794140971426U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 6013952618696225751U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7994863587373565715U), 53U);
            //
            aIngress = RotL64(aOrbiterB, 13U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 35U));
            aIngress = aIngress + RotL64(aOrbiterE, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 13U) + aOrbiterB) + RotL64(aOrbiterE, 50U)) + aNonceWordB);
            aWandererD = aWandererD + ((((RotL64(aIngress, 41U) + RotL64(aOrbiterF, 19U)) + aOrbiterB) + RotL64(aCarry, 41U)) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterG, 27U)) + aOrbiterE) + aNonceWordE);
            aWandererH = aWandererH + ((((RotL64(aCross, 50U) + aOrbiterH) + RotL64(aOrbiterB, 3U)) + RotL64(aCarry, 29U)) + aPhaseAWandererUpdateSaltB[((aIndex + 11U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 21U) + RotL64(aOrbiterH, 39U)) + aOrbiterG) + aNonceWordL);
            //
            aCarry = aCarry + (RotL64(aWandererI, 53U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererH, 11U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererJ, 34U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 21802U)) & S_BLOCK1], 50U) ^ RotL64(aInvestLaneA[((aIndex + 19221U)) & S_BLOCK1], 41U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 20009U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 21791U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 16440U)) & S_BLOCK1], 44U));
            aCross ^= RotL64(aExpandLaneC[((aIndex + 20205U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCarry, 39U) ^ RotL64(aPrevious, 27U)) + (RotL64(aIngress, 52U) + RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterD = (((aWandererF + RotL64(aScatter, 29U)) + 7960325128608297381U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordE;
            aOrbiterC = (aWandererG + RotL64(aPrevious, 3U)) + 12773836012104052042U;
            aOrbiterF = (((aWandererJ + RotL64(aIngress, 39U)) + RotL64(aCarry, 27U)) + 3173972621347773016U) + aPhaseAOrbiterAssignSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterJ = ((aWandererE + RotL64(aCross, 52U)) + RotL64(aCarry, 57U)) + 3708401356314308171U;
            aOrbiterH = (((aWandererD + RotL64(aScatter, 11U)) + RotL64(aCarry, 39U)) + 950774285720019449U) + aNonceWordH;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 4170092315705438265U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 17000449130864980747U) ^ aNonceWordI;
            aOrbiterF = RotL64((aOrbiterF * 7710635557693533263U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 8793910540062893860U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 520277969543516469U;
            aOrbiterJ = RotL64((aOrbiterJ * 4150613128885828229U), 47U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterD) + 12762214857389827271U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1]) + aNonceWordD;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 2932451184340207695U) ^ aNonceWordF;
            aOrbiterC = RotL64((aOrbiterC * 7513337346940091655U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 11062179998786293839U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 7919119215271524178U;
            aOrbiterD = RotL64((aOrbiterD * 9053677007180081359U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 1774988449597115155U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 3799792889466518953U;
            aOrbiterH = RotL64((aOrbiterH * 17512791286490623455U), 39U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterH, 29U);
            aIngress = aIngress + (RotL64(aOrbiterD, 51U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterJ, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aIngress, 29U) + RotL64(aOrbiterJ, 27U)) + aOrbiterF) + aNonceWordJ);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 39U) + aOrbiterC) + RotL64(aOrbiterF, 5U)) + RotL64(aCarry, 13U)) + aPhaseAWandererUpdateSaltD[((aIndex + 28U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((((RotL64(aCross, 19U) + aOrbiterC) + RotL64(aOrbiterD, 48U)) + aNonceWordM) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 5U) + aOrbiterC) + RotL64(aOrbiterH, 57U)) + RotL64(aCarry, 39U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 48U) + aOrbiterJ) + RotL64(aOrbiterC, 39U)) + aNonceWordK);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 23U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 51U));
            aCarry = aCarry + RotL64(aWandererG, 43U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 25343U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneA[((aIndex + 25661U)) & S_BLOCK1], 18U));
            aIngress ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 24935U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 25205U)) & S_BLOCK1], 35U) ^ RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 26990U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aInvestLaneB[((aIndex + 22590U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aPrevious, 23U) + RotL64(aCross, 40U)) ^ (RotL64(aIngress, 3U) ^ RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterD = ((aWandererK + RotL64(aIngress, 13U)) + 4259993311776766595U) + aPhaseAOrbiterAssignSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterC = ((aWandererB + RotL64(aCross, 21U)) + 2857813330021126753U) + aNonceWordP;
            aOrbiterF = (((aWandererD + RotL64(aScatter, 3U)) + RotL64(aCarry, 5U)) + 1345396841329442896U) + aNonceWordK;
            aOrbiterG = (((aWandererG + RotL64(aPrevious, 39U)) + RotL64(aCarry, 57U)) + 320992148982301024U) + aNonceWordM;
            aOrbiterH = (((aWandererC + RotL64(aIngress, 50U)) + RotL64(aCarry, 39U)) + 5619109532065293074U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 10380157329426706345U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 12449831150625409695U;
            aOrbiterF = RotL64((aOrbiterF * 3354095240459774437U), 37U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterG) + 7847096607042268396U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordN;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 11707184096803214678U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 1959476948106553973U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 9893643746186827088U) + aNonceWordE;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 333687403830908774U;
            aOrbiterC = RotL64((aOrbiterC * 17911256836121454271U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 13837360705077441580U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 4367119682175710689U) ^ aNonceWordD;
            aOrbiterG = RotL64((aOrbiterG * 10295744669174603401U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 1193493435041306784U) + aNonceWordL;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 15062951612027370606U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2509383510565136549U), 47U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterG, 18U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 41U));
            aIngress = aIngress + RotL64(aOrbiterF, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aScatter, 21U) + aOrbiterG) + RotL64(aOrbiterC, 3U)) + RotL64(aCarry, 37U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterD, 38U)) + aOrbiterH);
            aWandererK = aWandererK + ((((RotL64(aIngress, 29U) + aOrbiterG) + RotL64(aOrbiterF, 53U)) + RotL64(aCarry, 11U)) + aPhaseAWandererUpdateSaltE[((aIndex + 19U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((((RotL64(aPrevious, 51U) + aOrbiterC) + RotL64(aOrbiterD, 19U)) + aNonceWordJ) + aPhaseAWandererUpdateSaltA[((aIndex + 15U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aScatter, 6U) + RotL64(aOrbiterF, 29U)) + aOrbiterC) + aNonceWordA);
            //
            aCarry = aCarry + (RotL64(aWandererG, 47U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererD, 37U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererB, 56U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 27483U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneA[((aIndex + 31887U)) & S_BLOCK1], 30U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 31517U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 27502U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 28426U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aInvestLaneB[((aIndex + 32390U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCross, 37U)) ^ (RotL64(aIngress, 19U) + RotL64(aCarry, 54U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterG = ((((aWandererF + RotL64(aPrevious, 57U)) + RotL64(aCarry, 39U)) + 898812731947995389U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordG;
            aOrbiterB = ((aWandererA + RotL64(aCross, 47U)) + 8677347622525527167U) + aNonceWordN;
            aOrbiterD = ((aWandererD + RotL64(aScatter, 5U)) + 770321564027567654U) + aNonceWordI;
            aOrbiterJ = ((aWandererJ + RotL64(aIngress, 14U)) + RotL64(aCarry, 53U)) + 11020474858081526395U;
            aOrbiterK = ((((aWandererK + RotL64(aScatter, 35U)) + RotL64(aCarry, 13U)) + 17289793580414993470U) + aPhaseAOrbiterAssignSaltC[((aIndex + 7U)) & S_SALT1]) + aNonceWordL;
            //
            aOrbiterG = (((aOrbiterG + aOrbiterB) + 10111912559295118444U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordB;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 8083622125544542011U) ^ aNonceWordD;
            aOrbiterD = RotL64((aOrbiterD * 3610772128071340341U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 7149858558922988240U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 5919683821379905699U;
            aOrbiterJ = RotL64((aOrbiterJ * 16705119888884231567U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 6860902846079238714U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 15083517836867542075U;
            aOrbiterB = RotL64((aOrbiterB * 4686657139237578325U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 14852868368708376381U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 9860233289028878323U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13418143547952204667U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 772406119079116272U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterJ) ^ 7971141501337627589U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterG = RotL64((aOrbiterG * 10168120622976358617U), 41U);
            //
            aIngress = RotL64(aOrbiterK, 57U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 47U));
            aIngress = aIngress + RotL64(aOrbiterJ, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((((RotL64(aPrevious, 11U) + aOrbiterG) + RotL64(aOrbiterK, 19U)) + aNonceWordF) + aPhaseAWandererUpdateSaltF[((aIndex + 22U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aCross, 53U) + aOrbiterK) + RotL64(aOrbiterB, 4U)) + RotL64(aCarry, 23U)) + aNonceWordA);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 28U) + RotL64(aOrbiterJ, 51U)) + aOrbiterB) + aNonceWordH);
            aWandererF = aWandererF + ((((RotL64(aIngress, 19U) + aOrbiterG) + RotL64(aOrbiterJ, 43U)) + RotL64(aCarry, 57U)) + aNonceWordE);
            aWandererD = aWandererD ^ (((RotL64(aCross, 41U) + aOrbiterK) + RotL64(aOrbiterD, 27U)) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 35U) ^ aWandererF);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 53U));
            aCarry = aCarry + RotL64(aWandererA, 26U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x892873F1C29EB895ULL + 0xA6B0D3ABB1F2F0CCULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x99565DA5EF18E165ULL + 0x9679F869E82C813EULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xFFBC81CAC398A6C3ULL + 0xC08E2E4A6927BDD5ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xF5626EA42682C9F3ULL + 0xE7449406108B3453ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xA4163C5CD5C54A4DULL + 0xC4F041C446791F8DULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xAFF6E2B5F56ECE51ULL + 0xA5405786481F0EF9ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xCEAA2BDB92D16A27ULL + 0xFC0C698C8B7833CCULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xA0B6402982A249A3ULL + 0xF5435714C250919FULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xEB4B6BCCD1A09A75ULL + 0xB0C09B8723866099ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xADD96EE874865E07ULL + 0x8D0ED9B77C40147EULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xB3DCD16E565B7BB7ULL + 0xC31614F2B0FD1A59ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xDB0E70EB51B9F101ULL + 0x942B0D95E4741E69ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x9644C1CA19774E33ULL + 0xAE7E65FDB2263F51ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xD90637949FFE63E1ULL + 0xA2149CA04BD22BFEULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x9652E38749934A7BULL + 0xD7FAD589ABF240EAULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xC1346A09E7DB6A89ULL + 0xCA6FC2694D88FC7AULL);
    // GSeedRunSeed_C seed_loop_b (start)
    {
        // GSeedRunSeed_C seed_loop_b lane group
        // read from: aOperationLaneA, aOperationLaneB, aExpandLaneC, aOperationLaneC, aOperationLaneD, aExpandLaneA, aInvestLaneC, aFireLaneB, aExpandLaneD, aInvestLaneD, aFireLaneD, aWorkLaneA, aFireLaneC, aWorkLaneB, aFireLaneA, aWorkLaneC, aExpandLaneB
        // write to: aInvestLaneC, aInvestLaneD, aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // seed_loop_b loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aExpandLaneC
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aExpandLaneC forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aExpandLaneA
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aExpandLaneA backward/forward random
        // write to: aInvestLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 622U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneB[((aIndex + 1174U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 1752U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 3865U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 1996U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aExpandLaneA[((aIndex + 3217U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aPrevious, 57U) + RotL64(aCarry, 5U)) + (RotL64(aCross, 39U) ^ RotL64(aIngress, 20U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterC = ((aWandererH + RotL64(aPrevious, 51U)) + 5480870806135400132U) + aNonceWordA;
            aOrbiterH = ((aWandererI + RotL64(aIngress, 43U)) + 8034874599430768743U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = (((aWandererC + RotL64(aCross, 26U)) + RotL64(aCarry, 13U)) + 4006919843736863767U) + aNonceWordL;
            aOrbiterF = (aWandererJ + RotL64(aScatter, 47U)) + 2988069748674633718U;
            aOrbiterJ = ((aWandererG + RotL64(aPrevious, 57U)) + RotL64(aCarry, 21U)) + 12347295651973135786U;
            aOrbiterD = ((aWandererE + RotL64(aIngress, 39U)) + RotL64(aCarry, 41U)) + 14152683894431568192U;
            aOrbiterG = (aWandererD + RotL64(aScatter, 13U)) + 15765143815254196598U;
            aOrbiterB = ((aWandererK + RotL64(aCross, 35U)) + 10473067082331244233U) + aNonceWordM;
            aOrbiterK = ((aWandererA + RotL64(aPrevious, 6U)) + 1089466925383677249U) + aPhaseBOrbiterAssignSaltB[((aIndex + 16U)) & S_SALT1];
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 13215039929873682230U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 3957997712247961479U) ^ aNonceWordE;
            aOrbiterI = RotL64((aOrbiterI * 7631186240013784703U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 10023907397941685546U) + aNonceWordO;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 14593012591254614353U;
            aOrbiterH = RotL64((aOrbiterH * 17111300092082154687U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 13353797968154036726U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 9259966668512102858U) ^ aNonceWordD;
            aOrbiterG = RotL64((aOrbiterG * 8326732574268308221U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 10757861831070349321U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 10530223113483866178U;
            aOrbiterF = RotL64((aOrbiterF * 11269177745265396583U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 7554320926405521865U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 6978052067277966996U;
            aOrbiterD = RotL64((aOrbiterD * 18020134738536217801U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 1053695861967171420U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 15980734683539854451U;
            aOrbiterB = RotL64((aOrbiterB * 3208466640010555357U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 17041258393808061556U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 12846551858751995530U;
            aOrbiterC = RotL64((aOrbiterC * 9303891433380993639U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 14617434286683320666U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 3999309956180741302U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 15037707937050015205U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 13452627760403094126U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 2633241575260427158U;
            aOrbiterJ = RotL64((aOrbiterJ * 2638570213290747581U), 51U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterK, 21U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 11U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterG, 60U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterI, 51U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterF, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aPrevious, 29U) + RotL64(aOrbiterC, 37U)) + aOrbiterD);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 13U) + aOrbiterG) + RotL64(aOrbiterD, 30U)) + aPhaseBWandererUpdateSaltC[((aIndex + 24U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aCross, 3U) + RotL64(aOrbiterC, 13U)) + aOrbiterJ) + RotL64(aCarry, 43U)) + aPhaseBWandererUpdateSaltB[((aIndex + 25U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 18U) + aOrbiterI) + RotL64(aOrbiterD, 41U));
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 53U) + RotL64(aOrbiterC, 47U)) + aOrbiterB) + RotL64(aCarry, 13U)) + aNonceWordP);
            aWandererD = aWandererD ^ ((RotL64(aCross, 47U) + aOrbiterG) + RotL64(aOrbiterF, 51U));
            aWandererI = aWandererI + ((RotL64(aScatter, 35U) + aOrbiterH) + RotL64(aOrbiterK, 57U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 24U) + RotL64(aOrbiterC, 20U)) + aOrbiterI) + aNonceWordK);
            aWandererC = aWandererC + ((RotL64(aCross, 57U) + aOrbiterH) + RotL64(aOrbiterD, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 10U) ^ aWandererI);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 57U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 51U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 35U));
            aCarry = aCarry + RotL64(aWandererA, 47U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aInvestLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_b loop 2
        // ingress from: aInvestLaneC, aOperationLaneC, aOperationLaneD, aFireLaneB
        // ingress directions: aInvestLaneC forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aFireLaneB forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aExpandLaneD
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aExpandLaneD backward/forward random
        // write to: aInvestLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneC[((aIndex + 8549U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneC[((aIndex + 9176U)) & S_BLOCK1], 41U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 8312U)) & S_BLOCK1], 29U) ^ RotL64(aFireLaneB[((aIndex + 8425U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 5823U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 6286U)) & S_BLOCK1], 53U));
            aCross ^= RotL64(aExpandLaneD[((aIndex + 6877U)) & S_BLOCK1], 38U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aPrevious, 53U) + RotL64(aCarry, 21U)) ^ (RotL64(aIngress, 35U) + RotL64(aCross, 4U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterF = (aWandererC + RotL64(aPrevious, 34U)) + 4752759164691497960U;
            aOrbiterH = (aWandererG + RotL64(aScatter, 29U)) + 12088872623537639782U;
            aOrbiterE = ((aWandererE + RotL64(aCross, 11U)) + RotL64(aCarry, 39U)) + 3734943577379734227U;
            aOrbiterA = ((((aWandererH + RotL64(aIngress, 51U)) + RotL64(aCarry, 57U)) + 8854778183012444234U) + aPhaseBOrbiterAssignSaltD[((aIndex + 19U)) & S_SALT1]) + aNonceWordP;
            aOrbiterG = (((aWandererK + RotL64(aPrevious, 57U)) + RotL64(aCarry, 11U)) + 16948373492893967275U) + aNonceWordF;
            aOrbiterB = (aWandererI + RotL64(aScatter, 19U)) + 7962415690046184385U;
            aOrbiterK = (aWandererJ + RotL64(aCross, 23U)) + 1872682375669714454U;
            aOrbiterD = ((aWandererA + RotL64(aIngress, 47U)) + 7776801806943853566U) + aPhaseBOrbiterAssignSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = (aWandererD + RotL64(aScatter, 6U)) + 16665439117257230732U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 11088186766134265676U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 10850237991780969350U) ^ aNonceWordO;
            aOrbiterE = RotL64((aOrbiterE * 7547414856143095121U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 6464817712131305812U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 244557182884209844U;
            aOrbiterB = RotL64((aOrbiterB * 2394270354887582889U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 13261563971157415841U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 2323811103717827362U;
            aOrbiterF = RotL64((aOrbiterF * 11483723582415081925U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 12338803568475493422U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 2811342930111104982U) ^ aNonceWordM;
            aOrbiterA = RotL64((aOrbiterA * 5020981755203607757U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 5554497011738996057U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 12712169745460598698U;
            aOrbiterG = RotL64((aOrbiterG * 1985586486150377769U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 17415058661427002973U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 9430421222715343818U;
            aOrbiterD = RotL64((aOrbiterD * 10321140659099470811U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 3926618548181233180U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 6172453297026957838U;
            aOrbiterH = RotL64((aOrbiterH * 1161551082037835233U), 13U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterE) + 8633288765997226004U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 24U)) & S_SALT1]) + aNonceWordN;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 17270881130844274342U;
            aOrbiterK = RotL64((aOrbiterK * 8888559940161770791U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 12232950994807835262U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 15352600312956742750U;
            aOrbiterJ = RotL64((aOrbiterJ * 6140396356904933003U), 35U);
            //
            aIngress = RotL64(aOrbiterJ, 47U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 53U));
            aIngress = aIngress + (RotL64(aOrbiterG, 35U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 60U));
            aIngress = aIngress + RotL64(aOrbiterD, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aScatter, 26U) + RotL64(aOrbiterD, 29U)) + aOrbiterE) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aIngress, 3U) + aOrbiterH) + RotL64(aOrbiterF, 20U)) + RotL64(aCarry, 35U)) + aNonceWordA);
            aWandererC = aWandererC ^ ((((RotL64(aPrevious, 13U) + aOrbiterJ) + RotL64(aOrbiterD, 47U)) + aNonceWordD) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 57U) + aOrbiterJ) + RotL64(aOrbiterB, 53U)) + aNonceWordH);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 43U) + aOrbiterE) + RotL64(aOrbiterB, 11U)) + aNonceWordB);
            aWandererG = aWandererG + (((RotL64(aScatter, 53U) + RotL64(aOrbiterG, 57U)) + aOrbiterJ) + RotL64(aCarry, 5U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 36U) + aOrbiterA) + RotL64(aOrbiterG, 24U));
            aWandererI = aWandererI + ((RotL64(aCross, 47U) + RotL64(aOrbiterH, 5U)) + aOrbiterD);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 21U) + aOrbiterG) + RotL64(aOrbiterK, 37U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 27U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererK, 24U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererE, 39U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererJ, 43U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererI, 35U);
            aCarry = aCarry + RotL64(aIngress, 12U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aInvestLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_b loop 3
        // ingress from: aInvestLaneD, aOperationLaneA, aFireLaneD
        // ingress directions: aInvestLaneD forward forced, aOperationLaneA forward forced, aFireLaneD forward/backward random
        // cross from: aInvestLaneC, aOperationLaneC
        // cross directions: aInvestLaneC backward forced, aOperationLaneC backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneD[((aIndex + 14897U)) & S_BLOCK1], 58U) ^ RotL64(aOperationLaneA[((aIndex + 13050U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 14475U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 14277U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 14214U)) & S_BLOCK1], 20U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aPrevious, 11U) + RotL64(aCarry, 52U)) + (RotL64(aIngress, 23U) ^ RotL64(aCross, 37U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterC = ((aWandererB + RotL64(aScatter, 27U)) + 13442819395490639310U) + aNonceWordP;
            aOrbiterJ = (((aWandererC + RotL64(aCross, 19U)) + RotL64(aCarry, 5U)) + 8187292523194120936U) + aNonceWordE;
            aOrbiterD = (aWandererF + RotL64(aIngress, 36U)) + 11469697159823131388U;
            aOrbiterG = ((aWandererH + RotL64(aPrevious, 13U)) + 13414083692375929653U) + aPhaseBOrbiterAssignSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = (aWandererJ + RotL64(aScatter, 3U)) + 11404010733687907517U;
            aOrbiterH = (aWandererE + RotL64(aIngress, 53U)) + 6783212827186218247U;
            aOrbiterE = ((aWandererI + RotL64(aPrevious, 48U)) + RotL64(aCarry, 37U)) + 8561131439340372614U;
            aOrbiterA = (aWandererG + RotL64(aCross, 57U)) + 6252609642004429113U;
            aOrbiterB = (((aWandererD + RotL64(aScatter, 43U)) + RotL64(aCarry, 29U)) + 12804867444200448952U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 2739648749603690781U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 14808861217017399752U;
            aOrbiterD = RotL64((aOrbiterD * 373911885694012101U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 17588866502571268888U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 5882260142735642980U;
            aOrbiterF = RotL64((aOrbiterF * 7688252946143263869U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 15493099088132862949U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 5175647411532429582U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 15226544495598541883U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 14279707376173642767U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterA) ^ 6826363572161275158U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterG = RotL64((aOrbiterG * 5263708315440161809U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 13267185753040999992U) + aNonceWordF;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 9980987858092888720U;
            aOrbiterH = RotL64((aOrbiterH * 13210290848800728635U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 3582972937645514549U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 10140409019562890804U;
            aOrbiterJ = RotL64((aOrbiterJ * 6944490201647678479U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 6160444117287330557U) + aNonceWordJ;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 16344602960561293113U;
            aOrbiterB = RotL64((aOrbiterB * 2319964919335633293U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 3497141036108337171U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 91269118352540308U;
            aOrbiterA = RotL64((aOrbiterA * 5160060720189045505U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 12739932748793144857U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 12820180915064791197U;
            aOrbiterE = RotL64((aOrbiterE * 5843849637411948699U), 57U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterD, 14U);
            aIngress = aIngress + (RotL64(aOrbiterA, 43U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 11U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 23U));
            aIngress = aIngress + RotL64(aOrbiterJ, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aIngress, 29U) + aOrbiterA) + RotL64(aOrbiterG, 38U)) + aNonceWordC);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 22U) + aOrbiterF) + RotL64(aOrbiterJ, 57U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 47U) + RotL64(aOrbiterD, 19U)) + aOrbiterA);
            aWandererH = aWandererH ^ ((((RotL64(aCross, 5U) + RotL64(aOrbiterB, 11U)) + aOrbiterH) + aNonceWordN) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aIngress, 53U) + RotL64(aOrbiterH, 51U)) + aOrbiterJ);
            aWandererE = aWandererE ^ ((((RotL64(aPrevious, 60U) + RotL64(aOrbiterC, 42U)) + aOrbiterD) + aNonceWordK) + aPhaseBWandererUpdateSaltE[((aIndex + 23U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 43U) + RotL64(aOrbiterG, 23U)) + aOrbiterB) + RotL64(aCarry, 19U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterB, 5U)) + aOrbiterJ);
            aWandererI = aWandererI + (((RotL64(aIngress, 11U) + RotL64(aOrbiterE, 47U)) + aOrbiterC) + RotL64(aCarry, 43U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 35U));
            aCarry = aCarry + (RotL64(aWandererG, 29U) ^ aWandererE);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 20U));
            aCarry = aCarry + (RotL64(aWandererH, 13U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererB, 5U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_b loop 4
        // ingress from: aWorkLaneA, aInvestLaneC, aFireLaneC
        // ingress directions: aWorkLaneA forward forced, aInvestLaneC forward forced, aFireLaneC forward/backward random
        // cross from: aInvestLaneD, aOperationLaneD
        // cross directions: aInvestLaneD backward forced, aOperationLaneD backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 18223U)) & S_BLOCK1], 56U) ^ RotL64(aInvestLaneC[((aIndex + 21451U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 21527U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordE));
            //
            aCross = RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 19494U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 17725U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aPrevious, 40U)) + (RotL64(aIngress, 23U) + RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterK = ((aWandererG + RotL64(aCross, 12U)) + 6973892330986118220U) + aNonceWordB;
            aOrbiterG = ((aWandererC + RotL64(aIngress, 39U)) + RotL64(aCarry, 41U)) + 9886813896272094864U;
            aOrbiterF = (aWandererB + RotL64(aPrevious, 23U)) + 10996306582517553173U;
            aOrbiterI = (aWandererD + RotL64(aScatter, 57U)) + 8490648283899856223U;
            aOrbiterA = ((aWandererA + RotL64(aCross, 35U)) + 105141713530704655U) + aNonceWordJ;
            aOrbiterC = ((((aWandererK + RotL64(aPrevious, 46U)) + RotL64(aCarry, 51U)) + 3114337422810562588U) + aPhaseBOrbiterAssignSaltB[((aIndex + 12U)) & S_SALT1]) + aNonceWordC;
            aOrbiterE = (((aWandererH + RotL64(aIngress, 53U)) + 980857684690886131U) + aPhaseBOrbiterAssignSaltA[((aIndex + 19U)) & S_SALT1]) + aNonceWordL;
            aOrbiterH = (aWandererE + RotL64(aScatter, 27U)) + 6562042345807072665U;
            aOrbiterB = ((aWandererF + RotL64(aCross, 5U)) + RotL64(aCarry, 19U)) + 15665371138706353619U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 18113013571374375028U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 17405346422601997299U) ^ aNonceWordG;
            aOrbiterF = RotL64((aOrbiterF * 11162604605443005253U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 5130876096426182506U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 1813821672299154629U;
            aOrbiterG = RotL64((aOrbiterG * 15478100342425611875U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 15793814882743306728U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 13925299440495476399U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12049601510660117401U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 9924458846049579438U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterA) ^ 7810034662781768090U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterH = RotL64((aOrbiterH * 10310594595026622513U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 12812586478656872854U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 5709576448057435237U;
            aOrbiterE = RotL64((aOrbiterE * 9101555233909853025U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 7839807649914541516U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 4717944526755429647U;
            aOrbiterA = RotL64((aOrbiterA * 8515229146471335721U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 3933911971504256022U) + aNonceWordD;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 4814079680865379831U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 15100740696230557391U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 18352577312212175569U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 9670612998448920742U;
            aOrbiterB = RotL64((aOrbiterB * 5743579439303300553U), 23U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 72737302703035726U) + aNonceWordA;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 10032869372369626210U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 7449905669249993731U), 27U);
            //
            aIngress = RotL64(aOrbiterB, 13U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 4U));
            aIngress = aIngress + (RotL64(aOrbiterE, 23U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterF, 47U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterA, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((((RotL64(aIngress, 29U) + aOrbiterH) + RotL64(aOrbiterK, 10U)) + aNonceWordP) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 3U) + RotL64(aOrbiterB, 3U)) + aOrbiterA) + RotL64(aCarry, 29U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 41U) + aOrbiterE) + RotL64(aOrbiterH, 29U));
            aWandererA = aWandererA + ((((RotL64(aPrevious, 46U) + aOrbiterI) + RotL64(aOrbiterC, 47U)) + RotL64(aCarry, 39U)) + aNonceWordH);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 11U) + aOrbiterH) + RotL64(aOrbiterF, 43U)) + aPhaseBWandererUpdateSaltB[((aIndex + 21U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aCross, 19U) + RotL64(aOrbiterE, 23U)) + aOrbiterF);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterK, 34U)) + aOrbiterG);
            aWandererK = aWandererK + ((RotL64(aScatter, 53U) + RotL64(aOrbiterG, 19U)) + aOrbiterA);
            aWandererG = aWandererG ^ (((RotL64(aCross, 60U) + RotL64(aOrbiterB, 57U)) + aOrbiterI) + aNonceWordK);
            //
            aCarry = aCarry + (RotL64(aWandererE, 5U) ^ aWandererC);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 35U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 43U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 13U));
            aCarry = aCarry + RotL64(aWandererK, 18U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_b loop 5
        // ingress from: aWorkLaneB, aInvestLaneD, aFireLaneA
        // ingress directions: aWorkLaneB forward forced, aInvestLaneD forward forced, aFireLaneA forward/backward random
        // cross from: aWorkLaneA, aInvestLaneC
        // cross directions: aWorkLaneA backward forced, aInvestLaneC backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 23438U)) & S_BLOCK1], 3U) ^ RotL64(aInvestLaneD[((aIndex + 25485U)) & S_BLOCK1], 56U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 24211U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23130U)) & S_BLOCK1], 60U) ^ RotL64(aInvestLaneC[((aIndex + 26743U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCarry, 34U)) + (RotL64(aPrevious, 21U) ^ RotL64(aCross, 47U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterB = (aWandererE + RotL64(aIngress, 12U)) + 12669015908335980355U;
            aOrbiterD = ((aWandererK + RotL64(aPrevious, 53U)) + RotL64(aCarry, 35U)) + 5438715179868613192U;
            aOrbiterJ = ((aWandererJ + RotL64(aScatter, 19U)) + 13172104448184536460U) + aPhaseBOrbiterAssignSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterC = ((aWandererB + RotL64(aCross, 37U)) + 13421421503244744803U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = (aWandererD + RotL64(aScatter, 29U)) + 13327113302994856582U;
            aOrbiterG = (aWandererA + RotL64(aCross, 5U)) + 4671768205922454413U;
            aOrbiterH = ((aWandererG + RotL64(aPrevious, 57U)) + 5355759962838579929U) + aNonceWordC;
            aOrbiterK = ((aWandererI + RotL64(aIngress, 47U)) + RotL64(aCarry, 21U)) + 6691720614265406851U;
            aOrbiterI = (((aWandererF + RotL64(aCross, 42U)) + RotL64(aCarry, 43U)) + 7063906424700911378U) + aNonceWordI;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 17328616394166672263U) + aNonceWordK;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 1542940602574207068U) ^ aNonceWordO;
            aOrbiterJ = RotL64((aOrbiterJ * 8981679306319627975U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 7203866278803132454U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 993485696233139264U;
            aOrbiterF = RotL64((aOrbiterF * 11609009908810366447U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 15659679028507488331U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 18321361454094675842U) ^ aNonceWordJ;
            aOrbiterC = RotL64((aOrbiterC * 3966860765622641843U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 9633319822696783352U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 3496559332232402963U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7772060229838162977U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 1918349708324205526U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 7701088402761359134U;
            aOrbiterH = RotL64((aOrbiterH * 9649485438465644795U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 6006824348814439686U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 18088375375347012557U;
            aOrbiterB = RotL64((aOrbiterB * 12801082943086128385U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 12816533373478543584U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 17951880253818836433U;
            aOrbiterK = RotL64((aOrbiterK * 8935839101517220201U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 11311632024372748238U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 9891349164779752351U;
            aOrbiterI = RotL64((aOrbiterI * 11405973752233193209U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 711130292000437038U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 17818800917771709681U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 10567029732245868263U), 41U);
            //
            aIngress = RotL64(aOrbiterD, 53U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterB, 47U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 34U));
            aIngress = aIngress + (RotL64(aOrbiterK, 37U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterG, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterC, 50U)) + aOrbiterH);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 5U) + RotL64(aOrbiterF, 35U)) + aOrbiterG) + RotL64(aCarry, 23U)) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 60U) + RotL64(aOrbiterB, 19U)) + aOrbiterI);
            aWandererI = aWandererI + ((((RotL64(aCross, 43U) + RotL64(aOrbiterI, 11U)) + aOrbiterD) + RotL64(aCarry, 43U)) + aNonceWordE);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterJ, 23U)) + aOrbiterH);
            aWandererA = aWandererA + ((RotL64(aScatter, 27U) + RotL64(aOrbiterJ, 57U)) + aOrbiterK);
            aWandererE = aWandererE ^ (((RotL64(aCross, 13U) + aOrbiterF) + RotL64(aOrbiterI, 28U)) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aIngress, 39U) + RotL64(aOrbiterG, 5U)) + aOrbiterI) + aNonceWordA);
            aWandererK = aWandererK ^ ((RotL64(aCross, 48U) + aOrbiterB) + RotL64(aOrbiterC, 41U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 41U) ^ aWandererG);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 27U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 35U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 47U));
            aCarry = aCarry + RotL64(aWandererK, 14U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_b loop 6
        // ingress from: aWorkLaneC, aWorkLaneA, aExpandLaneB
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aExpandLaneB forward/backward random
        // cross from: aWorkLaneB, aOperationLaneB
        // cross directions: aWorkLaneB backward forced, aOperationLaneB backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 28235U)) & S_BLOCK1], 4U) ^ RotL64(aWorkLaneA[((aIndex + 28573U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28209U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 30059U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 30489U)) & S_BLOCK1], 44U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCarry, 27U) ^ RotL64(aPrevious, 39U)) + (RotL64(aIngress, 56U) ^ RotL64(aCross, 13U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterJ = ((aWandererC + RotL64(aCross, 29U)) + 5568146815535263910U) + aNonceWordN;
            aOrbiterG = ((((aWandererE + RotL64(aScatter, 35U)) + RotL64(aCarry, 53U)) + 7736084960873834666U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordF;
            aOrbiterA = ((aWandererH + RotL64(aIngress, 39U)) + 1336413621817562093U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterH = ((aWandererD + RotL64(aPrevious, 10U)) + RotL64(aCarry, 5U)) + 5218462026934984692U;
            aOrbiterK = (aWandererJ + RotL64(aCross, 53U)) + 7048890985969555935U;
            aOrbiterB = ((aWandererG + RotL64(aIngress, 43U)) + RotL64(aCarry, 21U)) + 13415955213864702118U;
            aOrbiterC = ((aWandererK + RotL64(aScatter, 5U)) + 5657023257021528548U) + aNonceWordO;
            aOrbiterI = (aWandererB + RotL64(aPrevious, 47U)) + 14338310943137497116U;
            aOrbiterE = (aWandererI + RotL64(aCross, 24U)) + 12305161641833950473U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 14514226578370459131U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 12692904083266024340U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 14800805065279908839U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 11012959130001327964U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 7106471380403489078U;
            aOrbiterK = RotL64((aOrbiterK * 515626559384817223U), 39U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 3718101961355280891U) + aNonceWordJ;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 13364192077222322664U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 1411328915372590283U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 6720867800318913440U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 14497243926965866546U;
            aOrbiterC = RotL64((aOrbiterC * 13595058589060114653U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 5789056168233262435U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 14438482587495779937U;
            aOrbiterI = RotL64((aOrbiterI * 10593535547917767263U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 313917798940179945U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 15241845511889502917U;
            aOrbiterE = RotL64((aOrbiterE * 16483477103771326107U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 3591957424821693032U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 1559050939014453558U) ^ aNonceWordC;
            aOrbiterG = RotL64((aOrbiterG * 17933346117866604725U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 15340590914441451383U) + aNonceWordI;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 5538037287390050110U;
            aOrbiterJ = RotL64((aOrbiterJ * 4082576643144951473U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 4151270491894969214U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 263593701314144898U;
            aOrbiterH = RotL64((aOrbiterH * 10372046955804512457U), 43U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterC, 35U);
            aIngress = aIngress + (RotL64(aOrbiterI, 24U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterH, 57U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterK, 5U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterE, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aCross, 42U) + aOrbiterA) + RotL64(aOrbiterK, 3U)) + aNonceWordH);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterG, 23U)) + aOrbiterH);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 3U) + aOrbiterI) + RotL64(aOrbiterC, 53U)) + aNonceWordP);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 57U) + aOrbiterI) + RotL64(aOrbiterA, 11U));
            aWandererK = aWandererK + (((RotL64(aScatter, 19U) + aOrbiterI) + RotL64(aOrbiterE, 58U)) + RotL64(aCarry, 47U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterA, 39U)) + aOrbiterJ);
            aWandererD = aWandererD + ((((RotL64(aCross, 47U) + RotL64(aOrbiterK, 35U)) + aOrbiterH) + RotL64(aCarry, 27U)) + aPhaseBWandererUpdateSaltF[((aIndex + 7U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 10U) + aOrbiterB) + RotL64(aOrbiterA, 43U)) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aPrevious, 53U) + RotL64(aOrbiterI, 30U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererK, 22U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererD, 41U) ^ aWandererC);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 51U));
            aCarry = aCarry + (RotL64(aWandererB, 29U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererJ, 19U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x957C50E3DA839ABDULL + 0xFE190B38781E93ACULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xB06747674F404259ULL + 0x8CD29495FE6B3E1BULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xB3EA8DDE2C80D63DULL + 0xB6915F4AB73BAD8EULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xF83F4DE30F5A4ADDULL + 0x939F508842519ED0ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x983905080C46F55FULL + 0xA7C27326C1E3C466ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xC3E120B859C896F9ULL + 0xD1A520383D7678CBULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x81C6DD2C347B019DULL + 0xBD5DA7CCB19D9FA8ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xA2C9CC398C7D917FULL + 0x9F87BF6B4ECEC220ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xCC24CB3D8DF82185ULL + 0xA59A980D2D6BF82BULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xE173FBCD31DBF0A7ULL + 0x884F13E584CF7735ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xEC11BDA9F9E9D505ULL + 0xFA8FD35D4EC799E3ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0x940D70A153A15EB7ULL + 0xF96169FEB68E6C01ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xC030070CC54931F7ULL + 0x96DBDD0993AF3D79ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xC5742AAF2B0E4C17ULL + 0xF9A218E1AAEDE8CCULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x80FD997DCCCB5747ULL + 0xD02B185C94504785ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xF042115B7316232DULL + 0xE655427F70545FAAULL);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 3681U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneB[((aIndex + 3211U)) & S_BLOCK1], 4U));
            aIngress ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 1195U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 2249U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 3483U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 1514U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCarry, 29U) ^ RotL64(aIngress, 54U)) ^ (RotL64(aCross, 3U) + RotL64(aPrevious, 41U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterH = ((aWandererG + RotL64(aIngress, 50U)) + 4204560462077827182U) + aNonceWordB;
            aOrbiterJ = ((aWandererJ + RotL64(aScatter, 43U)) + 6572370199668594039U) + aNonceWordF;
            aOrbiterE = ((aWandererD + RotL64(aPrevious, 13U)) + RotL64(aCarry, 19U)) + 15958999876732622825U;
            aOrbiterK = (((aWandererI + RotL64(aCross, 3U)) + RotL64(aCarry, 39U)) + 9969349486879280377U) + aNonceWordD;
            aOrbiterD = (((aWandererB + RotL64(aIngress, 23U)) + RotL64(aCarry, 57U)) + 15450238998293956181U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = ((aWandererE + RotL64(aCross, 37U)) + 9128619863683138259U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = (aWandererH + RotL64(aScatter, 57U)) + 5691270563628979565U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 5901029710568933106U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 10442738941988588834U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7386621444831603817U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 3508116020325721993U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 13221917083569767259U;
            aOrbiterD = RotL64((aOrbiterD * 6845108555710135357U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 11627915460377128176U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 17858261365514253433U;
            aOrbiterJ = RotL64((aOrbiterJ * 7535577636975884641U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 4294837988806295989U) + aNonceWordN;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 11242915481585070249U;
            aOrbiterA = RotL64((aOrbiterA * 17540688242763829319U), 37U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 13030663829236027109U) + aNonceWordA;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 7451948220723185149U;
            aOrbiterK = RotL64((aOrbiterK * 5191778587712222029U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 5575508866505031037U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 5161096033789876794U) ^ aNonceWordG;
            aOrbiterH = RotL64((aOrbiterH * 16843827915802461797U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 3980482740649505122U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 11188906150207270241U;
            aOrbiterB = RotL64((aOrbiterB * 408550837615188413U), 13U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterA, 29U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 37U));
            aIngress = aIngress + (RotL64(aOrbiterK, 11U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterE, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aCross, 29U) + RotL64(aOrbiterE, 3U)) + aOrbiterA) + RotL64(aCarry, 29U)) + aPhaseDWandererUpdateSaltC[((aIndex + 14U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 47U) + aOrbiterH) + RotL64(aOrbiterA, 11U)) + aPhaseDWandererUpdateSaltE[((aIndex + 19U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aScatter, 19U) + aOrbiterA) + RotL64(aOrbiterJ, 51U)) + aNonceWordO);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 41U) + aOrbiterD) + RotL64(aOrbiterK, 58U));
            aWandererB = aWandererB + ((RotL64(aPrevious, 10U) + aOrbiterJ) + RotL64(aOrbiterK, 43U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 35U) + aOrbiterA) + RotL64(aOrbiterK, 37U)) + aNonceWordJ);
            aWandererD = aWandererD + ((((RotL64(aScatter, 57U) + aOrbiterB) + RotL64(aOrbiterD, 29U)) + RotL64(aCarry, 5U)) + aNonceWordM);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 41U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererH, 60U) ^ aWandererD);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 5U));
            aCarry = aCarry + RotL64(aWandererG, 23U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aSnowLaneA[((aIndex + 9773U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneC[((aIndex + 7963U)) & S_BLOCK1], 18U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 6765U)) & S_BLOCK1], 57U) ^ RotL64(aInvestLaneC[((aIndex + 7324U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 8773U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 9332U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 10653U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aPrevious, 6U) + RotL64(aCross, 57U)) + (RotL64(aIngress, 23U) ^ RotL64(aCarry, 35U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterB = ((aWandererH + RotL64(aIngress, 39U)) + 16200278595895089008U) + aPhaseDOrbiterAssignSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = (((aWandererG + RotL64(aCross, 26U)) + RotL64(aCarry, 57U)) + 1029614154810465897U) + aNonceWordL;
            aOrbiterK = (aWandererB + RotL64(aScatter, 53U)) + 7129562468705441295U;
            aOrbiterA = ((aWandererK + RotL64(aPrevious, 19U)) + 14388903902433951274U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterG = ((aWandererD + RotL64(aIngress, 13U)) + RotL64(aCarry, 19U)) + 1013568949315967455U;
            aOrbiterC = ((aWandererI + RotL64(aScatter, 3U)) + RotL64(aCarry, 39U)) + 3128823373497815651U;
            aOrbiterE = ((aWandererA + RotL64(aPrevious, 47U)) + 14525694606889470589U) + aNonceWordP;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 14443983602196782887U) + aNonceWordB;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 12244220415328641190U) ^ aNonceWordC;
            aOrbiterK = RotL64((aOrbiterK * 15052949098014803181U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 10477159225338766614U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 2842870123078131566U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 11522265477555954071U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 8621138818955849917U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 5038396344400303181U;
            aOrbiterA = RotL64((aOrbiterA * 14636756322207385447U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 2768613802894372496U) + aNonceWordG;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 2027754864051410015U;
            aOrbiterJ = RotL64((aOrbiterJ * 2461322540050569287U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 2848088309172056399U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 15017458513904884651U;
            aOrbiterE = RotL64((aOrbiterE * 9926904679902843055U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 9079797279596336139U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 15424866642305110811U;
            aOrbiterB = RotL64((aOrbiterB * 12912331089970158845U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 13751764050290602740U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 7694557131324740282U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14980807690491467023U), 37U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterJ, 37U);
            aIngress = aIngress + (RotL64(aOrbiterA, 53U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterC, 43U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterK, 22U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 41U) + RotL64(aOrbiterE, 43U)) + aOrbiterA) + aNonceWordE);
            aWandererB = aWandererB + ((RotL64(aIngress, 19U) + aOrbiterG) + RotL64(aOrbiterA, 13U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterB, 37U)) + aOrbiterK);
            aWandererA = aWandererA + ((((RotL64(aCross, 11U) + aOrbiterC) + RotL64(aOrbiterB, 22U)) + RotL64(aCarry, 53U)) + aNonceWordF);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 28U) + RotL64(aOrbiterB, 29U)) + aOrbiterJ);
            aWandererI = aWandererI + (((((RotL64(aIngress, 5U) + RotL64(aOrbiterE, 57U)) + aOrbiterG) + RotL64(aCarry, 21U)) + aNonceWordI) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 35U) + aOrbiterA) + RotL64(aOrbiterB, 3U)) + aPhaseDWandererUpdateSaltD[((aIndex + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 29U) ^ aWandererA);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 18U));
            aCarry = aCarry + (RotL64(aWandererK, 23U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererD, 13U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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
            aIngress = (RotL64(aSnowLaneB[((aIndex + 13323U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneA[((aIndex + 11345U)) & S_BLOCK1], 22U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 11779U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 11809U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 13830U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCarry, 57U) + RotL64(aIngress, 23U)) + (RotL64(aCross, 5U) ^ RotL64(aPrevious, 40U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterC = (((aWandererK + RotL64(aIngress, 56U)) + RotL64(aCarry, 27U)) + 16160838483846078448U) + aPhaseDOrbiterAssignSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterD = ((((aWandererF + RotL64(aCross, 47U)) + RotL64(aCarry, 41U)) + 15404960896190227946U) + aPhaseDOrbiterAssignSaltE[((aIndex + 22U)) & S_SALT1]) + aNonceWordK;
            aOrbiterH = (aWandererE + RotL64(aScatter, 41U)) + 16904160594024977199U;
            aOrbiterJ = (aWandererI + RotL64(aPrevious, 11U)) + 17790460246821031802U;
            aOrbiterI = (aWandererA + RotL64(aScatter, 19U)) + 16395168254086971959U;
            aOrbiterE = (aWandererG + RotL64(aIngress, 35U)) + 7484373204039901786U;
            aOrbiterK = (((aWandererB + RotL64(aPrevious, 27U)) + RotL64(aCarry, 53U)) + 18026814691322913510U) + aNonceWordJ;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 15244817793136966450U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 5795491730356335666U;
            aOrbiterH = RotL64((aOrbiterH * 13253529465289332171U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 3163873518027801504U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterJ) ^ 2690791759507349172U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterE = RotL64((aOrbiterE * 16677948635136515083U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 17898067251167087906U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 8028010015006604239U) ^ aNonceWordE;
            aOrbiterD = RotL64((aOrbiterD * 5601629670521300241U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 7304739457289910555U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 6476837815096530043U;
            aOrbiterK = RotL64((aOrbiterK * 16380545138701113267U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 14242499233467960602U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 17305645693017634630U;
            aOrbiterJ = RotL64((aOrbiterJ * 14442976693206929569U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 9772864059444171908U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 7897200728282156408U) ^ aNonceWordA;
            aOrbiterC = RotL64((aOrbiterC * 816306719390807411U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 4890999319172950996U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 8165132649356094963U;
            aOrbiterI = RotL64((aOrbiterI * 17297706071263690189U), 51U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterH, 29U);
            aIngress = aIngress + (RotL64(aOrbiterI, 47U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 5U));
            aIngress = aIngress + RotL64(aOrbiterD, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterE, 35U)) + aOrbiterC) + aNonceWordI);
            aWandererK = aWandererK + (((RotL64(aIngress, 23U) + aOrbiterC) + RotL64(aOrbiterD, 19U)) + RotL64(aCarry, 51U));
            aWandererI = aWandererI ^ ((((RotL64(aPrevious, 37U) + aOrbiterI) + RotL64(aOrbiterE, 60U)) + aNonceWordN) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 50U) + RotL64(aOrbiterK, 41U)) + aOrbiterI) + RotL64(aCarry, 39U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 5U) + RotL64(aOrbiterE, 13U)) + aOrbiterJ) + aNonceWordP);
            aWandererF = aWandererF + (((RotL64(aScatter, 11U) + RotL64(aOrbiterC, 3U)) + aOrbiterH) + aNonceWordM);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 43U) + aOrbiterK) + RotL64(aOrbiterD, 53U)) + aPhaseDWandererUpdateSaltF[((aIndex + 6U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 40U) ^ aWandererF);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 29U));
            aCarry = aCarry + (RotL64(aWandererK, 23U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererG, 51U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 20329U)) & S_BLOCK1], 13U) ^ RotL64(aSnowLaneA[((aIndex + 19575U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 20363U)) & S_BLOCK1], 58U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 18237U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 18435U)) & S_BLOCK1], 4U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCross, 37U) ^ RotL64(aPrevious, 54U)) ^ (RotL64(aIngress, 3U) + RotL64(aCarry, 21U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterI = (((aWandererB + RotL64(aPrevious, 19U)) + RotL64(aCarry, 3U)) + 6069475454765660321U) + aNonceWordF;
            aOrbiterA = (aWandererI + RotL64(aCross, 29U)) + 11483704742497268068U;
            aOrbiterK = (((aWandererJ + RotL64(aScatter, 51U)) + 11055697447388986418U) + aPhaseDOrbiterAssignSaltA[((aIndex + 19U)) & S_SALT1]) + aNonceWordK;
            aOrbiterG = ((aWandererG + RotL64(aIngress, 6U)) + RotL64(aCarry, 53U)) + 10897095046039997004U;
            aOrbiterB = ((aWandererK + RotL64(aPrevious, 43U)) + 4731637118230457840U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = (((aWandererA + RotL64(aCross, 37U)) + RotL64(aCarry, 41U)) + 13855839187084986751U) + aNonceWordD;
            aOrbiterD = (aWandererD + RotL64(aIngress, 13U)) + 5328208115460188239U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 12479538544291412985U) + aNonceWordB;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 10740165998792608231U) ^ aNonceWordP;
            aOrbiterK = RotL64((aOrbiterK * 14046827922294477379U), 37U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 6492798157284955373U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 13056825957483891921U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 14882112110627751751U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 2068184064919194657U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 5656302738780746294U;
            aOrbiterB = RotL64((aOrbiterB * 16493021179127646345U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 11193756120230763294U) + aNonceWordI;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 17306750816837208999U) ^ aNonceWordA;
            aOrbiterE = RotL64((aOrbiterE * 7949360041241439741U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 12952818800389361804U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 15380412293642628312U;
            aOrbiterD = RotL64((aOrbiterD * 2914662289178925547U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 7706090204767242996U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 14598802276412649570U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 4821408736292041399U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 17819762117328075515U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 6481384240915075101U;
            aOrbiterI = RotL64((aOrbiterI * 4836701121865783029U), 53U);
            //
            aIngress = RotL64(aOrbiterA, 53U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 41U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 11U));
            aIngress = aIngress + RotL64(aOrbiterK, 34U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aCross, 5U) + aOrbiterE) + RotL64(aOrbiterI, 35U)) + aPhaseDWandererUpdateSaltE[((aIndex + 7U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aIngress, 13U) + RotL64(aOrbiterG, 11U)) + aOrbiterA);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterD, 56U)) + aOrbiterI) + aNonceWordC);
            aWandererI = aWandererI + (((RotL64(aPrevious, 41U) + aOrbiterE) + RotL64(aOrbiterD, 3U)) + RotL64(aCarry, 35U));
            aWandererJ = aWandererJ ^ ((((RotL64(aIngress, 22U) + aOrbiterA) + RotL64(aOrbiterI, 41U)) + aNonceWordL) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aCross, 29U) + RotL64(aOrbiterD, 29U)) + aOrbiterB) + RotL64(aCarry, 51U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterK, 19U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererG, 53U) ^ aWandererK);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 48U));
            aCarry = aCarry + (RotL64(aWandererI, 5U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererJ, 11U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 24769U)) & S_BLOCK1], 5U) ^ RotL64(aSnowLaneB[((aIndex + 26814U)) & S_BLOCK1], 28U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 23440U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 25401U)) & S_BLOCK1], 21U) ^ RotL64(aSnowLaneA[((aIndex + 24880U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aIngress, 27U) + RotL64(aCross, 39U)) ^ (RotL64(aCarry, 53U) + RotL64(aPrevious, 6U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterG = (((aWandererB + RotL64(aCross, 22U)) + RotL64(aCarry, 5U)) + 14686411261024919129U) + aNonceWordG;
            aOrbiterE = ((aWandererH + RotL64(aScatter, 57U)) + 7514582233957632005U) + aNonceWordA;
            aOrbiterD = (((aWandererD + RotL64(aPrevious, 13U)) + RotL64(aCarry, 19U)) + 6520710480103365552U) + aPhaseDOrbiterAssignSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterH = ((aWandererE + RotL64(aIngress, 43U)) + RotL64(aCarry, 47U)) + 1983621978676188036U;
            aOrbiterI = (((aWandererJ + RotL64(aCross, 35U)) + 9003524602590749672U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 8U)) & S_SALT1]) + aNonceWordP;
            aOrbiterB = (aWandererG + RotL64(aScatter, 3U)) + 6428568234045228995U;
            aOrbiterA = ((aWandererI + RotL64(aIngress, 51U)) + 8656552687136446989U) + aNonceWordN;
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 16916248288415922490U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 9740237548002535784U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 7970729853948983849U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 907561000814618339U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 4751108900841197631U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4545395964730641957U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 167774899400732287U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 11907484918310854962U;
            aOrbiterG = RotL64((aOrbiterG * 7213139491146402985U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 14910318613649863924U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 14882888155751455276U;
            aOrbiterB = RotL64((aOrbiterB * 11394136445442060201U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 16175942562693781908U) + aNonceWordI;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 11022373758481651102U;
            aOrbiterH = RotL64((aOrbiterH * 6836331461393816027U), 21U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 12548405399045031548U) + aNonceWordM;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 10850926364556828443U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 16231561687709867431U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 13391684887911141790U) + aNonceWordL;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 14648937281264822988U) ^ aNonceWordF;
            aOrbiterI = RotL64((aOrbiterI * 6533299316940026059U), 3U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterH, 11U);
            aIngress = aIngress + (RotL64(aOrbiterI, 3U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 47U));
            aIngress = aIngress + RotL64(aOrbiterD, 34U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 13U) + aOrbiterA) + RotL64(aOrbiterD, 5U));
            aWandererH = aWandererH + ((((RotL64(aCross, 19U) + RotL64(aOrbiterD, 27U)) + aOrbiterI) + RotL64(aCarry, 57U)) + aNonceWordK);
            aWandererJ = aWandererJ ^ ((((RotL64(aScatter, 35U) + aOrbiterI) + RotL64(aOrbiterG, 51U)) + aNonceWordH) + aPhaseDWandererUpdateSaltD[((aIndex + 17U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aIngress, 4U) + RotL64(aOrbiterD, 43U)) + aOrbiterB) + RotL64(aCarry, 29U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 27U) + aOrbiterE) + RotL64(aOrbiterB, 11U));
            aWandererE = aWandererE + (((RotL64(aIngress, 51U) + RotL64(aOrbiterG, 37U)) + aOrbiterB) + aNonceWordD);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 41U) + RotL64(aOrbiterE, 18U)) + aOrbiterH) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 35U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererH, 14U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererB, 43U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererJ, 29U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aInvestLaneC[((aIndex + 27897U)) & S_BLOCK1], 5U) ^ RotL64(aInvestLaneA[((aIndex + 27368U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 32216U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 31400U)) & S_BLOCK1], 44U) ^ RotL64(aExpandLaneB[((aIndex + 27455U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aIngress, 24U) + RotL64(aCarry, 51U)) ^ (RotL64(aCross, 5U) ^ RotL64(aPrevious, 39U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterK = ((aWandererA + RotL64(aIngress, 3U)) + 15652862298542575895U) + aNonceWordK;
            aOrbiterI = ((aWandererC + RotL64(aScatter, 41U)) + RotL64(aCarry, 3U)) + 16925323928418184554U;
            aOrbiterE = (((aWandererD + RotL64(aPrevious, 29U)) + RotL64(aCarry, 23U)) + 4413861484961668394U) + aNonceWordO;
            aOrbiterG = (aWandererH + RotL64(aCross, 21U)) + 2215946422098155969U;
            aOrbiterJ = (((aWandererI + RotL64(aIngress, 35U)) + RotL64(aCarry, 51U)) + 14975185533513111110U) + aNonceWordJ;
            aOrbiterB = ((aWandererE + RotL64(aPrevious, 53U)) + 9711613814905834552U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterF = ((aWandererJ + RotL64(aCross, 60U)) + 13154957291850149471U) + aPhaseDOrbiterAssignSaltB[((aIndex + 10U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 5058313016418534840U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 15011423472941211620U;
            aOrbiterE = RotL64((aOrbiterE * 6125316151731105673U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 2030053257469580168U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 150530795186791193U) ^ aNonceWordM;
            aOrbiterJ = RotL64((aOrbiterJ * 11106050063717096073U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 10878237472104183427U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 11724672539469573109U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 16158741837357985395U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 9589700906445846956U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 1367381624958248949U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8459515089081211977U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 12003215666757518106U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 11232479330848006729U;
            aOrbiterI = RotL64((aOrbiterI * 10993290955464593033U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 13013910456628561621U) + aNonceWordH;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 6092509838924105265U;
            aOrbiterB = RotL64((aOrbiterB * 805601154718006061U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 11999225836250312801U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 14421271973875748413U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 9529010940887430157U), 39U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterF, 57U);
            aIngress = aIngress + (RotL64(aOrbiterB, 5U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 23U));
            aIngress = aIngress + RotL64(aOrbiterJ, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 5U) + aOrbiterJ) + RotL64(aOrbiterB, 35U));
            aWandererC = aWandererC + (((RotL64(aIngress, 14U) + RotL64(aOrbiterF, 11U)) + aOrbiterJ) + RotL64(aCarry, 29U));
            aWandererI = aWandererI ^ ((((RotL64(aScatter, 41U) + aOrbiterE) + RotL64(aOrbiterK, 57U)) + aNonceWordD) + aPhaseDWandererUpdateSaltB[((aIndex + 13U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 53U) + aOrbiterI) + RotL64(aOrbiterJ, 4U)) + RotL64(aCarry, 11U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 35U) + aOrbiterI) + RotL64(aOrbiterK, 51U));
            aWandererE = aWandererE + (((RotL64(aIngress, 47U) + RotL64(aOrbiterI, 29U)) + aOrbiterF) + aNonceWordP);
            aWandererD = aWandererD ^ (((RotL64(aCross, 29U) + aOrbiterG) + RotL64(aOrbiterK, 21U)) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 12U) ^ aWandererE);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 43U));
            aCarry = aCarry + (RotL64(aWandererI, 19U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererC, 27U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xCE378E127D5BDB85ULL + 0xF5FFB3CA8B8C853EULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xB78D9846572A40DBULL + 0x93CDD1C8056B13CDULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x980C4CE370456EA7ULL + 0xDC0FB32853B1237EULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xBAD32F49ECC23F51ULL + 0xB7C46D408385F957ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x81C64D3035500D5FULL + 0x9321000A338224CEULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xEB1B1D1D25100953ULL + 0xF55E080B9A846C3DULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xA49A77B642EFC6F7ULL + 0x9BC7F064326C95D7ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x80D98ABFF0406FA3ULL + 0xEE7F552BD0C4DD29ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xB1DBA8FCEC6D0735ULL + 0xEE4C9D0D2B5DF05DULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0x8F22DE95CE70A8AFULL + 0xE5FAC47A10224708ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xDAC3B3C0227CCEEDULL + 0xBECF8DD66CA599A3ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xCEBA0856690D7FDBULL + 0xA25C5111E92F74D9ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xCF0120323361F829ULL + 0x8D515D88B6E2DB84ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xD003BE36F2FD6273ULL + 0xB3F53122134704FEULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xC4F45AF4E61AF96BULL + 0x9ED3813843B3AE75ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0x94813A4B92F80F03ULL + 0x95581579882EDCADULL);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 2203U)) & S_BLOCK1], 27U) ^ RotL64(aInvestLaneB[((aIndex + 2728U)) & S_BLOCK1], 58U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 1023U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 3026U)) & S_BLOCK1], 6U) ^ RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 3764U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 3477U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCarry, 41U) ^ RotL64(aPrevious, 29U)) ^ (RotL64(aIngress, 60U) + RotL64(aCross, 11U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterF = (aWandererJ + RotL64(aCross, 23U)) + 9855743441035905047U;
            aOrbiterB = ((aWandererA + RotL64(aScatter, 21U)) + 8426286937143990276U) + aPhaseEOrbiterAssignSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = (aWandererI + RotL64(aPrevious, 11U)) + 7146752367170267002U;
            aOrbiterH = (aWandererD + RotL64(aIngress, 27U)) + 12947210066678101726U;
            aOrbiterJ = (aWandererK + RotL64(aCross, 30U)) + 15902163559925328965U;
            aOrbiterE = (aWandererF + RotL64(aPrevious, 35U)) + 8506649889346449469U;
            aOrbiterG = ((aWandererE + RotL64(aScatter, 41U)) + RotL64(aCarry, 43U)) + 8226286036430263052U;
            aOrbiterC = (((aWandererH + RotL64(aIngress, 43U)) + RotL64(aCarry, 5U)) + 2703047093452420216U) + aNonceWordL;
            aOrbiterK = ((aWandererC + RotL64(aCross, 37U)) + RotL64(aCarry, 57U)) + 6769351326360139560U;
            aOrbiterI = ((aWandererG + RotL64(aScatter, 6U)) + 9857025533281333281U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = ((aWandererB + RotL64(aPrevious, 39U)) + 238297452132277585U) + aNonceWordA;
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 7203572312072908931U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 12497027346166575632U;
            aOrbiterD = RotL64((aOrbiterD * 1703586436725662307U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 473851890609048879U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 1664484956453886047U;
            aOrbiterJ = RotL64((aOrbiterJ * 8566500756326590209U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 4635095143004754116U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 17695676150967345793U;
            aOrbiterC = RotL64((aOrbiterC * 5780416541584439301U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 15628965269863402796U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 9190117464399730235U;
            aOrbiterH = RotL64((aOrbiterH * 5586437438425999715U), 37U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 17835918238346011086U) + aNonceWordP;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 4398005402429282682U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 14828737209913317463U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 10902589938246551273U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 15124274429081385923U;
            aOrbiterB = RotL64((aOrbiterB * 13524180348258805367U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 8747233520702236018U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 5445611443463112371U;
            aOrbiterA = RotL64((aOrbiterA * 10294109295823410447U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 16296005217836151910U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 6468336224317602364U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7369779919748367133U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 3827976387089403774U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 7773383658122100111U;
            aOrbiterG = RotL64((aOrbiterG * 9784711300597525161U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 18273794621528918389U) + aNonceWordC;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 8401424792700263455U;
            aOrbiterI = RotL64((aOrbiterI * 13003420427441089595U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 11402828934846813949U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 9855743441035905047U;
            aOrbiterE = RotL64((aOrbiterE * 7339549576423555273U), 23U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterF, 21U);
            aIngress = aIngress + (RotL64(aOrbiterG, 39U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterK, 3U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterJ, 14U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 57U));
            aIngress = aIngress + RotL64(aOrbiterA, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aScatter, 42U) + aOrbiterE) + RotL64(aOrbiterF, 37U));
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 51U) + aOrbiterG) + RotL64(aOrbiterB, 57U)) + RotL64(aCarry, 23U)) + aPhaseEWandererUpdateSaltD[((aIndex + 13U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 21U) + aOrbiterH) + RotL64(aOrbiterF, 30U)) + aNonceWordO);
            aWandererE = aWandererE + ((RotL64(aCross, 27U) + RotL64(aOrbiterD, 5U)) + aOrbiterH);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 11U) + aOrbiterI) + RotL64(aOrbiterF, 51U));
            aWandererB = aWandererB + ((RotL64(aCross, 3U) + aOrbiterJ) + RotL64(aOrbiterE, 41U));
            aWandererK = aWandererK ^ ((((RotL64(aScatter, 13U) + aOrbiterK) + RotL64(aOrbiterB, 43U)) + aNonceWordI) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aIngress, 39U) + RotL64(aOrbiterC, 35U)) + aOrbiterI);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 35U) + aOrbiterG) + RotL64(aOrbiterA, 54U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterD, 39U)) + aOrbiterC) + RotL64(aCarry, 13U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 18U) + RotL64(aOrbiterK, 47U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererK, 28U) ^ aWandererA);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 53U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 23U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 37U));
            aCarry = aCarry + (RotL64(aWandererE, 11U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererB, 30U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = (RotL64(aFireLaneA[((aIndex + 10394U)) & S_BLOCK1], 5U) ^ RotL64(aInvestLaneC[((aIndex + 5906U)) & S_BLOCK1], 29U));
            aIngress ^= (RotL64(aInvestLaneD[((aIndex + 8673U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 7775U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 6220U)) & S_BLOCK1], 53U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 8791U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 9649U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aIngress, 26U) ^ RotL64(aCarry, 39U)) + (RotL64(aCross, 57U) + RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterH = ((aWandererI + RotL64(aPrevious, 3U)) + 13481227414590594621U) + aNonceWordM;
            aOrbiterJ = (aWandererA + RotL64(aCross, 21U)) + 17425964381118918026U;
            aOrbiterC = (aWandererJ + RotL64(aIngress, 60U)) + 4792004356135956581U;
            aOrbiterB = (((aWandererD + RotL64(aScatter, 11U)) + RotL64(aCarry, 47U)) + 11926849936000639098U) + aPhaseEOrbiterAssignSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterG = ((aWandererC + RotL64(aPrevious, 53U)) + RotL64(aCarry, 13U)) + 990697329347742142U;
            aOrbiterE = (aWandererG + RotL64(aIngress, 35U)) + 9307721505373076588U;
            aOrbiterA = ((aWandererE + RotL64(aScatter, 5U)) + 17605732738841908719U) + aNonceWordO;
            aOrbiterD = ((aWandererK + RotL64(aCross, 50U)) + RotL64(aCarry, 5U)) + 13110764518634187439U;
            aOrbiterK = ((aWandererB + RotL64(aScatter, 39U)) + 17970109897810645911U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterF = ((aWandererF + RotL64(aIngress, 37U)) + 10273133817644703654U) + aNonceWordF;
            aOrbiterI = ((aWandererH + RotL64(aPrevious, 19U)) + 11239046688920468137U) + aNonceWordB;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 8355821483275763145U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 15522151127786049345U;
            aOrbiterC = RotL64((aOrbiterC * 4844278537850520413U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 5381663179722418112U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 9551368011768104906U;
            aOrbiterG = RotL64((aOrbiterG * 14202470972121732997U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 16264476585232221270U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 7721417776432288282U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10267770327791051869U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 339418090653475277U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 3247926250495935511U;
            aOrbiterD = RotL64((aOrbiterD * 16824669543765729097U), 37U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterC) + 3390560045236418590U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 3894024951542543635U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 10599637790900418767U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 3878539166189668154U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 5617705593218220843U) ^ aNonceWordL;
            aOrbiterB = RotL64((aOrbiterB * 82771190372750823U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 12320861089148474544U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 14943790251625519550U;
            aOrbiterJ = RotL64((aOrbiterJ * 13758322022902008313U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 18119213517612562775U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 1413193144229486646U) ^ aNonceWordG;
            aOrbiterE = RotL64((aOrbiterE * 14562375280658115687U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 14810150213456844196U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 8468712395797520201U;
            aOrbiterI = RotL64((aOrbiterI * 8167911669632436949U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 13501570100536254566U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 15409772061478100850U;
            aOrbiterH = RotL64((aOrbiterH * 955182899606655851U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 8621805947309982779U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 13481227414590594621U) ^ aNonceWordI;
            aOrbiterF = RotL64((aOrbiterF * 9591362493722704105U), 11U);
            //
            aIngress = RotL64(aOrbiterJ, 5U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterD, 60U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterA, 35U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterI, 53U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterB, 51U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterK, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterJ, 57U)) + aOrbiterB);
            aWandererA = aWandererA + (((((RotL64(aPrevious, 12U) + aOrbiterC) + RotL64(aOrbiterD, 19U)) + RotL64(aCarry, 39U)) + aNonceWordN) + aPhaseEWandererUpdateSaltB[((aIndex + 25U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 3U) + aOrbiterB) + RotL64(aOrbiterE, 60U));
            aWandererC = aWandererC + (((RotL64(aIngress, 19U) + aOrbiterA) + RotL64(aOrbiterF, 21U)) + aNonceWordP);
            aWandererE = aWandererE ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterA, 43U)) + aOrbiterK);
            aWandererB = aWandererB + ((RotL64(aScatter, 53U) + RotL64(aOrbiterE, 47U)) + aOrbiterI);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 57U) + aOrbiterD) + RotL64(aOrbiterA, 11U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 21U) + aOrbiterG) + RotL64(aOrbiterD, 53U)) + aNonceWordA);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 43U) + aOrbiterH) + RotL64(aOrbiterI, 5U));
            aWandererH = aWandererH + (((RotL64(aScatter, 51U) + RotL64(aOrbiterH, 40U)) + aOrbiterE) + RotL64(aCarry, 53U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 48U) + RotL64(aOrbiterH, 23U)) + aOrbiterC) + aPhaseEWandererUpdateSaltE[((aIndex + 14U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 27U) ^ aWandererE);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 12U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 19U));
            aCarry = aCarry + (RotL64(aWandererG, 3U) ^ aWandererJ);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 23U));
            aCarry = aCarry + RotL64(aWandererI, 35U);
            aCarry = aCarry + RotL64(aIngress, 60U);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 13801U)) & S_BLOCK1], 19U) ^ RotL64(aInvestLaneA[((aIndex + 11042U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 16337U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 15244U)) & S_BLOCK1], 43U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 13006U)) & S_BLOCK1], 34U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCross, 19U) + RotL64(aIngress, 35U)) + (RotL64(aPrevious, 3U) ^ RotL64(aCarry, 54U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterF = (((aWandererK + RotL64(aPrevious, 35U)) + RotL64(aCarry, 47U)) + 7960325128608297381U) + aNonceWordN;
            aOrbiterJ = (((aWandererE + RotL64(aCross, 39U)) + RotL64(aCarry, 37U)) + 12773836012104052042U) + aNonceWordF;
            aOrbiterC = (aWandererF + RotL64(aIngress, 23U)) + 3173972621347773016U;
            aOrbiterB = (aWandererH + RotL64(aScatter, 5U)) + 3708401356314308171U;
            aOrbiterI = ((aWandererC + RotL64(aPrevious, 56U)) + 950774285720019449U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterA = (aWandererI + RotL64(aScatter, 3U)) + 4170092315705438265U;
            aOrbiterH = (aWandererA + RotL64(aIngress, 13U)) + 17000449130864980747U;
            aOrbiterD = (aWandererD + RotL64(aCross, 21U)) + 8793910540062893860U;
            aOrbiterG = (((aWandererB + RotL64(aScatter, 29U)) + RotL64(aCarry, 57U)) + 520277969543516469U) + aNonceWordK;
            aOrbiterK = (aWandererG + RotL64(aCross, 50U)) + 12762214857389827271U;
            aOrbiterE = (((aWandererJ + RotL64(aPrevious, 27U)) + 2932451184340207695U) + aPhaseEOrbiterAssignSaltF[((aIndex + 4U)) & S_SALT1]) + aNonceWordB;
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 11062179998786293839U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 7919119215271524178U) ^ aNonceWordM;
            aOrbiterC = RotL64((aOrbiterC * 9053677007180081359U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 1774988449597115155U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 3799792889466518953U;
            aOrbiterF = RotL64((aOrbiterF * 17512791286490623455U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 1815062051307896589U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 15260373951371654483U;
            aOrbiterI = RotL64((aOrbiterI * 2208604434669491625U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 12867546628945676853U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 7772820973895846946U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7581704643538761985U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 14213957831821966834U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 16561105721170419454U;
            aOrbiterK = RotL64((aOrbiterK * 2540533987337175367U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 16556502948339949526U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 9706742922075498974U;
            aOrbiterD = RotL64((aOrbiterD * 8527361328901355457U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 13455756934917486016U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 9107769876332723454U;
            aOrbiterB = RotL64((aOrbiterB * 1722386100852683783U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 15793099079168487016U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 7968278803691283365U) ^ aNonceWordD;
            aOrbiterJ = RotL64((aOrbiterJ * 11644765391940099387U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 15068302421261745111U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 11373111908765197862U;
            aOrbiterA = RotL64((aOrbiterA * 17756438368103196771U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 6362100123286229887U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 528778333872160609U;
            aOrbiterE = RotL64((aOrbiterE * 17377710146983314215U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 6116442644744391285U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 7960325128608297381U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 17826511435509927061U), 39U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterB, 51U);
            aIngress = aIngress + (RotL64(aOrbiterC, 5U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterG, 20U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterK, 3U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterH, 23U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterI, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 41U) + RotL64(aOrbiterA, 54U)) + aOrbiterI) + RotL64(aCarry, 53U)) + aNonceWordA);
            aWandererE = aWandererE ^ ((RotL64(aCross, 10U) + RotL64(aOrbiterD, 51U)) + aOrbiterJ);
            aWandererB = aWandererB + ((((RotL64(aIngress, 21U) + aOrbiterE) + RotL64(aOrbiterF, 37U)) + RotL64(aCarry, 47U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 53U) + RotL64(aOrbiterI, 13U)) + aOrbiterC) + aNonceWordO);
            aWandererA = aWandererA + ((RotL64(aIngress, 39U) + RotL64(aOrbiterA, 39U)) + aOrbiterH);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 27U) + aOrbiterB) + RotL64(aOrbiterK, 43U)) + aNonceWordP);
            aWandererI = aWandererI + (((RotL64(aPrevious, 37U) + RotL64(aOrbiterD, 56U)) + aOrbiterI) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 13U) + aOrbiterG) + RotL64(aOrbiterH, 11U));
            aWandererH = aWandererH + ((RotL64(aIngress, 29U) + RotL64(aOrbiterH, 47U)) + aOrbiterK);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 5U) + aOrbiterJ) + RotL64(aOrbiterB, 3U));
            aWandererK = aWandererK + ((RotL64(aPrevious, 50U) + RotL64(aOrbiterE, 29U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 43U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 50U));
            aCarry = aCarry + (RotL64(aWandererH, 37U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererE, 23U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererK, 41U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererG, 35U);
            aCarry = aCarry + RotL64(aIngress, 48U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 16774U)) & S_BLOCK1], 51U) ^ RotL64(aFireLaneA[((aIndex + 21239U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 19676U)) & S_BLOCK1], 22U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordE));
            //
            aCross = RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 16419U)) & S_BLOCK1], 43U) ^ RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 21078U)) & S_BLOCK1], 52U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aPrevious, 43U) + RotL64(aCarry, 29U)) + (RotL64(aCross, 56U) ^ RotL64(aIngress, 13U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterH = (aWandererA + RotL64(aCross, 43U)) + 3339283916456813609U;
            aOrbiterF = (((aWandererK + RotL64(aIngress, 48U)) + RotL64(aCarry, 13U)) + 11339086426180649584U) + aNonceWordF;
            aOrbiterG = (aWandererD + RotL64(aPrevious, 3U)) + 16819191669329316585U;
            aOrbiterD = ((aWandererJ + RotL64(aScatter, 53U)) + 8361916937762630725U) + aNonceWordM;
            aOrbiterA = (((aWandererF + RotL64(aPrevious, 37U)) + RotL64(aCarry, 27U)) + 18031328374429899857U) + aPhaseEOrbiterAssignSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = (aWandererB + RotL64(aScatter, 60U)) + 18261756894092897276U;
            aOrbiterE = (aWandererC + RotL64(aIngress, 13U)) + 4250319792907645666U;
            aOrbiterB = (((aWandererH + RotL64(aCross, 21U)) + RotL64(aCarry, 5U)) + 1492411503643460886U) + aNonceWordN;
            aOrbiterK = (aWandererG + RotL64(aPrevious, 27U)) + 17369549067879344180U;
            aOrbiterI = ((aWandererE + RotL64(aScatter, 29U)) + 7301713524358676722U) + aPhaseEOrbiterAssignSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = ((aWandererI + RotL64(aCross, 41U)) + 2985193736033012535U) + aNonceWordK;
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 14086975808140927408U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 10390516547834639800U;
            aOrbiterG = RotL64((aOrbiterG * 11441293212275890819U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 18205555540941493267U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 16967799565443938873U;
            aOrbiterA = RotL64((aOrbiterA * 3009081009044782443U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 9209505304067579944U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 3522631966146762306U;
            aOrbiterJ = RotL64((aOrbiterJ * 3441982898533162599U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 8811497120829041188U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 14707301680850257294U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 11383709499376464085U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 10080595991787801029U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 6822892187784299166U;
            aOrbiterE = RotL64((aOrbiterE * 7417016898027778287U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 1981637172055758689U) + aNonceWordA;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 16463077485583119324U) ^ aNonceWordJ;
            aOrbiterH = RotL64((aOrbiterH * 2876782050665869121U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 8383837717361569465U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 2788511294985017326U;
            aOrbiterC = RotL64((aOrbiterC * 2809163242875130677U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 3529607472855930041U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 8850940802020173766U;
            aOrbiterF = RotL64((aOrbiterF * 7821450253655655943U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 7469160295100147267U) + aNonceWordL;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 16973986572163482061U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 15660743778376905023U), 37U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 12371372942863279718U) + aNonceWordB;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 12098525148034303633U;
            aOrbiterD = RotL64((aOrbiterD * 11234127652230231751U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 5138683482859889480U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 3339283916456813609U;
            aOrbiterI = RotL64((aOrbiterI * 10975353228235695455U), 23U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterE, 53U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 11U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 29U));
            aIngress = aIngress + (RotL64(aOrbiterD, 21U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterA, 14U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterI, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterF, 29U)) + aOrbiterE) + aNonceWordP);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 57U) + aOrbiterE) + RotL64(aOrbiterJ, 5U)) + aNonceWordI);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 11U) + aOrbiterE) + RotL64(aOrbiterH, 21U)) + aNonceWordD);
            aWandererF = aWandererF + (((RotL64(aIngress, 51U) + aOrbiterC) + RotL64(aOrbiterF, 3U)) + aPhaseEWandererUpdateSaltD[((aIndex + 14U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 54U) + RotL64(aOrbiterE, 43U)) + aOrbiterD);
            aWandererI = aWandererI + (((RotL64(aCross, 23U) + aOrbiterI) + RotL64(aOrbiterA, 60U)) + RotL64(aCarry, 37U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterF, 51U)) + aOrbiterJ);
            aWandererK = aWandererK + (((RotL64(aScatter, 35U) + RotL64(aOrbiterC, 35U)) + aOrbiterA) + RotL64(aCarry, 3U));
            aWandererB = aWandererB ^ ((((RotL64(aPrevious, 41U) + aOrbiterB) + RotL64(aOrbiterD, 39U)) + aNonceWordO) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aCross, 6U) + RotL64(aOrbiterK, 26U)) + aOrbiterA);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 29U) + aOrbiterB) + RotL64(aOrbiterG, 47U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 3U));
            aCarry = aCarry + (RotL64(aWandererK, 30U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererI, 27U) ^ aWandererE);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 39U));
            aCarry = aCarry + (RotL64(aWandererF, 21U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererD, 52U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 26102U)) & S_BLOCK1], 36U) ^ RotL64(aFireLaneB[((aIndex + 22404U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 24386U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 25985U)) & S_BLOCK1], 41U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 25944U)) & S_BLOCK1], 58U));
            aCross ^= RotL64(aInvestLaneA[((aIndex + 25343U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCarry, 58U) + RotL64(aPrevious, 39U)) ^ (RotL64(aIngress, 13U) + RotL64(aCross, 27U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterC = ((aWandererG + RotL64(aPrevious, 43U)) + 12131317914288566437U) + aNonceWordI;
            aOrbiterB = (aWandererE + RotL64(aScatter, 47U)) + 5672805657999385496U;
            aOrbiterA = (aWandererA + RotL64(aIngress, 39U)) + 3581710244233124197U;
            aOrbiterH = (aWandererI + RotL64(aCross, 53U)) + 15251296040538489436U;
            aOrbiterD = (((aWandererF + RotL64(aPrevious, 12U)) + RotL64(aCarry, 57U)) + 11295008604679904153U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterE = ((((aWandererK + RotL64(aScatter, 57U)) + RotL64(aCarry, 43U)) + 2230897493419504490U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordO;
            aOrbiterJ = (aWandererB + RotL64(aIngress, 19U)) + 7109600123297458999U;
            aOrbiterF = (aWandererC + RotL64(aCross, 3U)) + 13119156643107683803U;
            aOrbiterK = (((aWandererH + RotL64(aIngress, 23U)) + RotL64(aCarry, 13U)) + 14755160867807355250U) + aNonceWordE;
            aOrbiterI = ((aWandererD + RotL64(aCross, 34U)) + 16829363373287496832U) + aNonceWordH;
            aOrbiterG = (aWandererJ + RotL64(aScatter, 5U)) + 16981122946707720883U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 8806000776958603317U) + aNonceWordP;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 16810923047720876014U;
            aOrbiterA = RotL64((aOrbiterA * 17872735050219539145U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 8129657889554436328U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 8653100378491974463U;
            aOrbiterC = RotL64((aOrbiterC * 11395283153912468661U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 17048985838727432415U) + aNonceWordL;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 10892675550889823573U;
            aOrbiterJ = RotL64((aOrbiterJ * 976298937314081913U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 15960158965421254346U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 12290011578634850001U;
            aOrbiterH = RotL64((aOrbiterH * 9280475585104357745U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 16265047040311479093U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 10312956912303656248U;
            aOrbiterK = RotL64((aOrbiterK * 3012584393253845131U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 16706890352221352779U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 10630955894218491929U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 12675937483456206355U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 4009352551041162434U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 3043810773683888556U;
            aOrbiterI = RotL64((aOrbiterI * 4328135390387997315U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 1398071019814944785U) + aNonceWordK;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 16689766557488135301U;
            aOrbiterB = RotL64((aOrbiterB * 8403881916549404871U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 15934647144489136524U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 13521276033614992223U;
            aOrbiterG = RotL64((aOrbiterG * 18003640895553609933U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 4281211055727414100U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 11848150507497406421U;
            aOrbiterF = RotL64((aOrbiterF * 1107789990317433481U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 12022829841608199449U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterD = (((aOrbiterD ^ aOrbiterK) ^ 12131317914288566437U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterD = RotL64((aOrbiterD * 13275753083882829973U), 19U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterG, 10U);
            aIngress = aIngress + (RotL64(aOrbiterA, 47U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterI, 43U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 37U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 57U));
            aIngress = aIngress + RotL64(aOrbiterK, 18U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aIngress, 57U) + aOrbiterA) + RotL64(aOrbiterH, 21U)) + aNonceWordA);
            aWandererF = aWandererF + (((RotL64(aCross, 6U) + RotL64(aOrbiterB, 23U)) + aOrbiterH) + RotL64(aCarry, 37U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 41U) + RotL64(aOrbiterI, 41U)) + aOrbiterJ) + aPhaseEWandererUpdateSaltB[((aIndex + 23U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 37U) + aOrbiterJ) + RotL64(aOrbiterC, 27U)) + RotL64(aCarry, 51U)) + aPhaseEWandererUpdateSaltE[((aIndex + 12U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterB, 60U)) + aOrbiterC);
            aWandererK = aWandererK + ((RotL64(aScatter, 43U) + RotL64(aOrbiterD, 35U)) + aOrbiterK);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterJ, 37U)) + aOrbiterF);
            aWandererG = aWandererG + ((RotL64(aPrevious, 19U) + RotL64(aOrbiterB, 57U)) + aOrbiterF);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 39U) + aOrbiterE) + RotL64(aOrbiterH, 47U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 27U) + RotL64(aOrbiterK, 39U)) + aOrbiterI) + aNonceWordG);
            aWandererA = aWandererA ^ ((RotL64(aCross, 48U) + aOrbiterG) + RotL64(aOrbiterA, 14U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 47U) ^ aWandererK);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 26U));
            aCarry = aCarry + (RotL64(aWandererG, 23U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererF, 53U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererD, 37U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererB, 39U);
            aCarry = aCarry + RotL64(aIngress, 6U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 31768U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneA[((aIndex + 28841U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 30245U)) & S_BLOCK1], 60U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordA));
            //
            aCross = RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 29694U)) & S_BLOCK1], 4U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 28173U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aIngress, 3U) + RotL64(aCross, 34U)) + (RotL64(aCarry, 53U) ^ RotL64(aPrevious, 21U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterD = (aWandererB + RotL64(aIngress, 29U)) + 13583136155674166402U;
            aOrbiterK = ((aWandererK + RotL64(aPrevious, 12U)) + RotL64(aCarry, 39U)) + 12830472187484919497U;
            aOrbiterC = (aWandererG + RotL64(aCross, 5U)) + 18081197909484522509U;
            aOrbiterG = (aWandererA + RotL64(aScatter, 47U)) + 8680634051297891550U;
            aOrbiterH = ((aWandererJ + RotL64(aIngress, 43U)) + 13939998767458656823U) + aNonceWordB;
            aOrbiterI = (aWandererC + RotL64(aPrevious, 21U)) + 1795730579103692594U;
            aOrbiterF = ((aWandererI + RotL64(aScatter, 51U)) + RotL64(aCarry, 19U)) + 17369751719734069999U;
            aOrbiterJ = ((aWandererD + RotL64(aCross, 34U)) + 224769585901248068U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterE = (((aWandererF + RotL64(aScatter, 39U)) + 4133547085925268180U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 14U)) & S_SALT1]) + aNonceWordF;
            aOrbiterB = (aWandererH + RotL64(aIngress, 19U)) + 7022512056309567391U;
            aOrbiterA = (((aWandererE + RotL64(aCross, 23U)) + RotL64(aCarry, 43U)) + 10319484359046945495U) + aNonceWordH;
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 10483878349412282069U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 6481381149199985736U;
            aOrbiterC = RotL64((aOrbiterC * 9701719367082506253U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 13721077228796934509U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 9704818014314175007U;
            aOrbiterH = RotL64((aOrbiterH * 760445624027740287U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 6253040047758584339U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 16890211690273641226U;
            aOrbiterF = RotL64((aOrbiterF * 5622534399866057841U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 6216227831265032436U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterJ) ^ 2023609047004658739U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterE = RotL64((aOrbiterE * 3252332895698310147U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 9201669637050388263U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 5106927540934338576U;
            aOrbiterK = RotL64((aOrbiterK * 6368134569042291431U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 10080368957861445998U) + aNonceWordC;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 10784789383436485808U;
            aOrbiterJ = RotL64((aOrbiterJ * 3794918350254445939U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 15426339824951793026U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 17637144549368340331U;
            aOrbiterA = RotL64((aOrbiterA * 10971293914614704441U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 9941300382181962134U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 8118046374121322097U;
            aOrbiterB = RotL64((aOrbiterB * 8481945819050983127U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 5138086185042567633U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 7279942739248982986U;
            aOrbiterG = RotL64((aOrbiterG * 12911998308338410917U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 12135610639038562853U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 12945353426409788798U;
            aOrbiterD = RotL64((aOrbiterD * 7434977715954413699U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 7534876598022096222U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 13583136155674166402U;
            aOrbiterI = RotL64((aOrbiterI * 8194058098043157015U), 47U);
            //
            aIngress = RotL64(aOrbiterK, 29U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterG, 3U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterD, 41U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 57U));
            aIngress = aIngress + (RotL64(aOrbiterF, 39U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterA, 52U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 43U) + aOrbiterA) + RotL64(aOrbiterC, 58U));
            aWandererK = aWandererK + ((RotL64(aPrevious, 19U) + RotL64(aOrbiterC, 3U)) + aOrbiterI);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 29U) + aOrbiterG) + RotL64(aOrbiterD, 43U));
            aWandererA = aWandererA + (((RotL64(aIngress, 51U) + aOrbiterB) + RotL64(aOrbiterC, 51U)) + RotL64(aCarry, 47U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 23U) + RotL64(aOrbiterK, 53U)) + aOrbiterF) + aNonceWordE);
            aWandererE = aWandererE + (((RotL64(aIngress, 57U) + RotL64(aOrbiterJ, 21U)) + aOrbiterE) + aPhaseEWandererUpdateSaltF[((aIndex + 19U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 36U) + RotL64(aOrbiterF, 47U)) + aOrbiterG) + aPhaseEWandererUpdateSaltA[((aIndex + 3U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterH, 13U)) + aOrbiterI) + RotL64(aCarry, 41U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 11U) + aOrbiterJ) + RotL64(aOrbiterB, 18U));
            aWandererH = aWandererH + (((RotL64(aCross, 47U) + RotL64(aOrbiterC, 23U)) + aOrbiterJ) + aNonceWordN);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 6U) + RotL64(aOrbiterB, 35U)) + aOrbiterG) + aNonceWordG);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 35U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererH, 19U) ^ aWandererC);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 26U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 53U));
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererB, 51U);
            aCarry = aCarry + RotL64(aIngress, 28U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xC6CE91B994F8F7C7ULL + 0xEF2C9C08CB7040F0ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x9C64CC8606DE5C4FULL + 0xBBE82D7D7F9E0840ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xCE1ECB39725C4457ULL + 0xA29B3F1EC6FE2F57ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xE7E04FF61C7DDC51ULL + 0xFD59785335DDCCC4ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x8A36EF15D8CED951ULL + 0xC17C178CBAB868F3ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xD16DBD74FD95E07FULL + 0x932E1904C3B8A2B0ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xB27D3170BCF4505BULL + 0xEDB3BB816473C2C9ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xBD42D6851E655D19ULL + 0xE452FADEFD08D996ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x9E38E3C9CA39BC3BULL + 0xE6FF492FDAF6F4C8ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xCE8863C87A0A8C19ULL + 0x9AFD1D28245F5A3DULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xD33AE4227B5580D1ULL + 0xF1CBBD293BA7A971ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xF874EA81AF66D919ULL + 0xC2DEAAA0422998B8ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xAC999FF95C1DB117ULL + 0xD1A2116C4F29A76AULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xABE634E237BC6053ULL + 0xA6276C4B524D7CE1ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xFD141C26A7017875ULL + 0xE1ABC8E09E4A149EULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0x9529BFCBE581AFDBULL + 0xBBC6F7182BE847FBULL);
    // GSeedRunSeed_F seed_loop_f (start)
    {
        // GSeedRunSeed_F seed_loop_f lane group
        // read from: aOperationLaneA, aOperationLaneB, aInvestLaneB, aOperationLaneC, aOperationLaneD, aSnowLaneA, aSnowLaneC, aInvestLaneC, aInvestLaneD, aSnowLaneD, aWorkLaneD, aExpandLaneA, aInvestLaneA, aExpandLaneB, aSnowLaneB, aExpandLaneC, aWorkLaneC
        // write to: aSnowLaneC, aSnowLaneD, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // seed_loop_f loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aInvestLaneB
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aInvestLaneB forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aSnowLaneA
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aSnowLaneA backward/forward random
        // write to: aSnowLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 1079U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneB[((aIndex + 5127U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aInvestLaneB[((aIndex + 1028U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 2450U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 2214U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aSnowLaneA[((aIndex + 1092U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aPrevious, 37U) ^ RotL64(aCross, 4U)) ^ (RotL64(aIngress, 51U) + RotL64(aCarry, 21U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterB = (aWandererH + RotL64(aPrevious, 27U)) + 10881271196314989997U;
            aOrbiterK = (((aWandererK + RotL64(aCross, 58U)) + RotL64(aCarry, 53U)) + 6406461249988567558U) + aNonceWordB;
            aOrbiterE = (aWandererF + RotL64(aIngress, 5U)) + 17255067918280095959U;
            aOrbiterC = (aWandererD + RotL64(aScatter, 23U)) + 16690850682497718411U;
            aOrbiterG = ((((aWandererC + RotL64(aIngress, 47U)) + RotL64(aCarry, 23U)) + 5576201059361086866U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordN;
            aOrbiterA = ((aWandererE + RotL64(aPrevious, 38U)) + 11991259685693687554U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = ((aWandererA + RotL64(aScatter, 19U)) + RotL64(aCarry, 39U)) + 14652535244217836909U;
            aOrbiterJ = (aWandererI + RotL64(aCross, 13U)) + 1701789037170782122U;
            aOrbiterH = (aWandererB + RotL64(aPrevious, 51U)) + 953429054903473833U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 12064513610469714211U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 7993881398822002424U;
            aOrbiterE = RotL64((aOrbiterE * 11572884842788918377U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 14421313768013320050U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 11112386845630998889U;
            aOrbiterA = RotL64((aOrbiterA * 11771526352030371669U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 17069630896535699015U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 3308240081138623373U;
            aOrbiterG = RotL64((aOrbiterG * 10449509484417835159U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 17615529807112933619U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 11782807146851563541U;
            aOrbiterI = RotL64((aOrbiterI * 12992075832343669221U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 14401645829607611983U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 6736397344219993532U;
            aOrbiterB = RotL64((aOrbiterB * 1667287547938175641U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 6446974060524700550U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterE) ^ 7840991992443308254U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterC = RotL64((aOrbiterC * 6891023544882740107U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 10362169906019794305U) + aNonceWordC;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 4503700997923168911U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 15066164494038852559U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 13492041134973259041U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 14337899277551397976U;
            aOrbiterK = RotL64((aOrbiterK * 5966740718899290915U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 13693100781608180748U) + aNonceWordF;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 16177545026405910052U;
            aOrbiterJ = RotL64((aOrbiterJ * 6019231448444020563U), 57U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterA, 30U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 35U));
            aIngress = aIngress + (RotL64(aOrbiterG, 13U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterC, 19U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterJ, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aCross, 51U) + aOrbiterA) + RotL64(aOrbiterB, 46U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 14U) + RotL64(aOrbiterK, 11U)) + aOrbiterH) + RotL64(aCarry, 13U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 19U) + aOrbiterJ) + RotL64(aOrbiterC, 19U)) + aPhaseFWandererUpdateSaltE[((aIndex + 29U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aIngress, 29U) + RotL64(aOrbiterG, 3U)) + aOrbiterJ) + aNonceWordK);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 47U) + aOrbiterG) + RotL64(aOrbiterC, 29U)) + aNonceWordE);
            aWandererK = aWandererK + ((RotL64(aScatter, 43U) + aOrbiterG) + RotL64(aOrbiterE, 51U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 24U) + RotL64(aOrbiterC, 58U)) + aOrbiterK);
            aWandererF = aWandererF + (((RotL64(aIngress, 57U) + aOrbiterG) + RotL64(aOrbiterB, 37U)) + RotL64(aCarry, 37U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 35U) + aOrbiterI) + RotL64(aOrbiterG, 23U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 23U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererH, 51U) ^ aWandererE);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 47U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 36U));
            aCarry = aCarry + RotL64(aWandererF, 39U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aSnowLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_f loop 2
        // ingress from: aSnowLaneC, aOperationLaneC, aOperationLaneD, aInvestLaneC
        // ingress directions: aSnowLaneC forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aInvestLaneC forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aInvestLaneD
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aInvestLaneD backward/forward random
        // write to: aSnowLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneC[((aIndex + 10823U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneC[((aIndex + 10056U)) & S_BLOCK1], 43U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 7094U)) & S_BLOCK1], 11U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 7175U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 10419U)) & S_BLOCK1], 54U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 10515U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aInvestLaneD[((aIndex + 7836U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aPrevious, 6U) ^ RotL64(aCross, 41U)) + (RotL64(aIngress, 21U) + RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterD = ((aWandererB + RotL64(aPrevious, 39U)) + 898812731947995389U) + aNonceWordH;
            aOrbiterJ = (aWandererD + RotL64(aCross, 13U)) + 8677347622525527167U;
            aOrbiterC = ((aWandererG + RotL64(aIngress, 48U)) + RotL64(aCarry, 5U)) + 770321564027567654U;
            aOrbiterF = (aWandererA + RotL64(aScatter, 3U)) + 11020474858081526395U;
            aOrbiterK = ((((aWandererC + RotL64(aPrevious, 19U)) + RotL64(aCarry, 39U)) + 17289793580414993470U) + aPhaseFOrbiterAssignSaltA[((aIndex + 11U)) & S_SALT1]) + aNonceWordL;
            aOrbiterG = ((aWandererF + RotL64(aCross, 29U)) + 10111912559295118444U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = (((aWandererJ + RotL64(aScatter, 43U)) + RotL64(aCarry, 47U)) + 8083622125544542011U) + aNonceWordG;
            aOrbiterI = (aWandererE + RotL64(aIngress, 35U)) + 7149858558922988240U;
            aOrbiterH = (aWandererH + RotL64(aPrevious, 24U)) + 5919683821379905699U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 6860902846079238714U) + aNonceWordB;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 15083517836867542075U;
            aOrbiterC = RotL64((aOrbiterC * 4686657139237578325U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 14852868368708376381U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 9860233289028878323U;
            aOrbiterG = RotL64((aOrbiterG * 13418143547952204667U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 772406119079116272U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 7971141501337627589U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10168120622976358617U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 8478568022896691911U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 4027604850785607101U;
            aOrbiterF = RotL64((aOrbiterF * 4826627523578901467U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 17199331557841535430U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 7515957656979776361U) ^ aNonceWordM;
            aOrbiterJ = RotL64((aOrbiterJ * 5468950152869656599U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 17138249294921502391U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 16236812863923234668U;
            aOrbiterI = RotL64((aOrbiterI * 2925542836624164807U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 16941524155859123682U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 11240343728857342866U;
            aOrbiterD = RotL64((aOrbiterD * 7281012444214294659U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 15163914964139858328U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 6673576554415729652U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 1558880328574736975U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 5399050402101642989U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 11806006719060024615U;
            aOrbiterK = RotL64((aOrbiterK * 15782156615926092159U), 57U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterG, 13U);
            aIngress = aIngress + (RotL64(aOrbiterK, 39U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 60U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 43U));
            aIngress = aIngress + RotL64(aOrbiterH, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aIngress, 13U) + RotL64(aOrbiterC, 41U)) + aOrbiterA) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 26U) + RotL64(aOrbiterG, 60U)) + aOrbiterC) + RotL64(aCarry, 3U)) + aNonceWordN);
            aWandererA = aWandererA ^ (((RotL64(aCross, 51U) + aOrbiterK) + RotL64(aOrbiterA, 13U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 35U) + aOrbiterA) + RotL64(aOrbiterH, 21U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 43U) + aOrbiterD) + RotL64(aOrbiterH, 5U));
            aWandererD = aWandererD + ((((RotL64(aScatter, 57U) + RotL64(aOrbiterA, 35U)) + aOrbiterI) + RotL64(aCarry, 41U)) + aNonceWordJ);
            aWandererH = aWandererH ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterI, 51U)) + aOrbiterG);
            aWandererF = aWandererF + (((RotL64(aIngress, 22U) + RotL64(aOrbiterC, 47U)) + aOrbiterF) + aNonceWordO);
            aWandererE = aWandererE ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterA, 28U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 35U));
            aCarry = aCarry + (RotL64(aWandererJ, 29U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererC, 39U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererH, 3U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererG, 51U);
            aCarry = aCarry + RotL64(aIngress, 58U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aSnowLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_f loop 3
        // ingress from: aSnowLaneD, aOperationLaneA, aWorkLaneD
        // ingress directions: aSnowLaneD forward forced, aOperationLaneA forward forced, aWorkLaneD forward/backward random
        // cross from: aSnowLaneC, aOperationLaneC
        // cross directions: aSnowLaneC backward forced, aOperationLaneC backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneD[((aIndex + 14083U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneA[((aIndex + 14674U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aWorkLaneD[((aIndex + 12956U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 16050U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 13300U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCarry, 37U) + RotL64(aPrevious, 3U)) ^ (RotL64(aCross, 53U) + RotL64(aIngress, 18U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterA = (aWandererA + RotL64(aIngress, 30U)) + 2101601659597850213U;
            aOrbiterB = ((aWandererE + RotL64(aScatter, 43U)) + 2759794072560720121U) + aNonceWordK;
            aOrbiterF = ((aWandererK + RotL64(aPrevious, 23U)) + 9443562552411269339U) + aPhaseFOrbiterAssignSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterK = (((aWandererJ + RotL64(aCross, 57U)) + RotL64(aCarry, 57U)) + 10801360546699857975U) + aNonceWordG;
            aOrbiterH = ((aWandererI + RotL64(aScatter, 39U)) + RotL64(aCarry, 19U)) + 8020716394829332019U;
            aOrbiterC = (((aWandererH + RotL64(aPrevious, 47U)) + RotL64(aCarry, 39U)) + 1021894212367773801U) + aNonceWordM;
            aOrbiterJ = ((aWandererC + RotL64(aIngress, 34U)) + 13346855534622490176U) + aPhaseFOrbiterAssignSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterE = (aWandererB + RotL64(aCross, 53U)) + 16359309548462953836U;
            aOrbiterI = ((aWandererD + RotL64(aScatter, 19U)) + 12642446944680783519U) + aNonceWordB;
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 8197424982767553380U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 14346334610901859094U;
            aOrbiterF = RotL64((aOrbiterF * 16982899923227935679U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 14171304260534233539U) + aNonceWordC;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 334531601308283605U;
            aOrbiterC = RotL64((aOrbiterC * 5012968232749075075U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 10707856298471572695U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 18364775750091914766U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 15735143943129143265U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 8531394793118363836U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 15352876929406908882U;
            aOrbiterA = RotL64((aOrbiterA * 475199047053777179U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 567682016232278157U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 2068146551757663119U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 1557877740957797555U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 7776122587613256525U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 16430938890724272256U;
            aOrbiterB = RotL64((aOrbiterB * 4540270493783593257U), 11U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterE) + 11912000645055436094U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1]) + aNonceWordF;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 16800749242578741498U;
            aOrbiterH = RotL64((aOrbiterH * 17804584625034241737U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 5909199180260499150U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 5751089915336865588U;
            aOrbiterI = RotL64((aOrbiterI * 15376689503142397927U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 3478216857728853008U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 18007567146937338241U) ^ aNonceWordO;
            aOrbiterE = RotL64((aOrbiterE * 6620498877303917855U), 29U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterI, 19U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 13U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 57U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 6U));
            aIngress = aIngress + RotL64(aOrbiterF, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aPrevious, 51U) + RotL64(aOrbiterC, 23U)) + aOrbiterH) + RotL64(aCarry, 13U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 39U) + RotL64(aOrbiterI, 18U)) + aOrbiterJ) + aNonceWordN);
            aWandererD = aWandererD + ((RotL64(aCross, 60U) + aOrbiterK) + RotL64(aOrbiterJ, 27U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterE, 57U)) + aOrbiterA) + aNonceWordP);
            aWandererH = aWandererH + (((RotL64(aCross, 19U) + RotL64(aOrbiterK, 47U)) + aOrbiterF) + RotL64(aCarry, 35U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 11U) + aOrbiterA) + RotL64(aOrbiterH, 41U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 30U) + RotL64(aOrbiterC, 53U)) + aOrbiterI);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 23U) + aOrbiterE) + RotL64(aOrbiterJ, 36U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 5U) + aOrbiterB) + RotL64(aOrbiterA, 5U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 44U) ^ aWandererI);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 23U));
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererJ);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + RotL64(aWandererA, 20U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_f loop 4
        // ingress from: aExpandLaneA, aSnowLaneC, aInvestLaneA
        // ingress directions: aExpandLaneA forward forced, aSnowLaneC forward forced, aInvestLaneA forward/backward random
        // cross from: aSnowLaneD, aOperationLaneD
        // cross directions: aSnowLaneD backward forced, aOperationLaneD backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 20646U)) & S_BLOCK1], 58U) ^ RotL64(aSnowLaneC[((aIndex + 17666U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aInvestLaneA[((aIndex + 18332U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 17264U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 19527U)) & S_BLOCK1], 20U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCross, 29U)) ^ (RotL64(aPrevious, 56U) + RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterB = ((aWandererB + RotL64(aIngress, 19U)) + 18144572925667544139U) + aPhaseFOrbiterAssignSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterG = (aWandererI + RotL64(aCross, 52U)) + 5659758077574059728U;
            aOrbiterD = ((aWandererJ + RotL64(aScatter, 11U)) + 6343330616999166392U) + aNonceWordG;
            aOrbiterC = (aWandererE + RotL64(aPrevious, 41U)) + 17754639838410839447U;
            aOrbiterF = ((((aWandererF + RotL64(aIngress, 37U)) + RotL64(aCarry, 53U)) + 9451843819849581729U) + aPhaseFOrbiterAssignSaltD[((aIndex + 3U)) & S_SALT1]) + aNonceWordE;
            aOrbiterH = ((aWandererD + RotL64(aCross, 57U)) + RotL64(aCarry, 21U)) + 7957854457197462212U;
            aOrbiterI = (aWandererC + RotL64(aScatter, 23U)) + 1461994799722205010U;
            aOrbiterK = ((aWandererA + RotL64(aPrevious, 28U)) + RotL64(aCarry, 37U)) + 18002214276252170177U;
            aOrbiterA = ((aWandererH + RotL64(aIngress, 3U)) + 14689869073147027164U) + aNonceWordI;
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 3978104368003440293U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 8512135845221335386U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 10506667163729414667U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 1477533446382953439U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 2166717790929947990U;
            aOrbiterF = RotL64((aOrbiterF * 6538884492418324461U), 37U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 8082437060686606995U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 4363687722464700362U;
            aOrbiterI = RotL64((aOrbiterI * 7199165810993478887U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 15782763348014924206U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 8572509150015960728U) ^ aNonceWordB;
            aOrbiterC = RotL64((aOrbiterC * 3340528604891897779U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 12248271773316742521U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 9602078627638561949U;
            aOrbiterG = RotL64((aOrbiterG * 1860631869877427405U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 17244849374768558859U) + aNonceWordL;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 1030743048280579012U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10858949914285817051U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 17722342363541914280U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 15667504059789880034U;
            aOrbiterH = RotL64((aOrbiterH * 15872269872168533709U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 12645332941998550794U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 9938135244509986497U;
            aOrbiterK = RotL64((aOrbiterK * 16548185968987392957U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 4024609904162105979U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterF) ^ 6732064218696157303U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterB = RotL64((aOrbiterB * 3815409766145891393U), 57U);
            //
            aIngress = RotL64(aOrbiterA, 35U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterG, 10U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 47U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 43U));
            aIngress = aIngress + RotL64(aOrbiterD, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 51U) + aOrbiterB) + RotL64(aOrbiterI, 27U)) + RotL64(aCarry, 23U)) + aNonceWordP);
            aWandererD = aWandererD ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterC, 3U)) + aOrbiterF);
            aWandererI = aWandererI + (((RotL64(aScatter, 36U) + aOrbiterD) + RotL64(aOrbiterK, 34U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterF, 51U)) + aOrbiterB);
            aWandererA = aWandererA + (((RotL64(aCross, 47U) + RotL64(aOrbiterC, 43U)) + aOrbiterK) + aNonceWordH);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 23U) + aOrbiterI) + RotL64(aOrbiterC, 47U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterA, 57U)) + aOrbiterG) + aNonceWordK);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 56U) + RotL64(aOrbiterA, 19U)) + aOrbiterF) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 43U) + aOrbiterD) + RotL64(aOrbiterH, 14U)) + RotL64(aCarry, 51U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 57U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererI, 26U) ^ aWandererD);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 3U));
            aCarry = aCarry + (RotL64(aWandererJ, 29U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererB, 47U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_f loop 5
        // ingress from: aExpandLaneB, aSnowLaneD, aSnowLaneB
        // ingress directions: aExpandLaneB forward forced, aSnowLaneD forward forced, aSnowLaneB forward/backward random
        // cross from: aExpandLaneA, aSnowLaneC
        // cross directions: aExpandLaneA backward forced, aSnowLaneC backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 22433U)) & S_BLOCK1], 43U) ^ RotL64(aSnowLaneD[((aIndex + 25817U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aSnowLaneB[((aIndex + 26270U)) & S_BLOCK1], 30U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 24418U)) & S_BLOCK1], 40U) ^ RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 23547U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCarry, 3U) + RotL64(aIngress, 52U)) ^ (RotL64(aPrevious, 39U) ^ RotL64(aCross, 19U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterB = ((aWandererH + RotL64(aPrevious, 51U)) + 16922357079016918108U) + aNonceWordL;
            aOrbiterA = (aWandererB + RotL64(aScatter, 60U)) + 11771749797137599131U;
            aOrbiterF = ((aWandererC + RotL64(aIngress, 11U)) + RotL64(aCarry, 51U)) + 4635668433708036077U;
            aOrbiterD = ((aWandererF + RotL64(aCross, 39U)) + 15827952719230577008U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterE = (aWandererK + RotL64(aIngress, 5U)) + 1495675306110023086U;
            aOrbiterH = ((((aWandererE + RotL64(aScatter, 21U)) + RotL64(aCarry, 13U)) + 7294835466949728365U) + aPhaseFOrbiterAssignSaltA[((aIndex + 8U)) & S_SALT1]) + aNonceWordM;
            aOrbiterI = ((aWandererJ + RotL64(aCross, 34U)) + RotL64(aCarry, 23U)) + 179122461212041978U;
            aOrbiterG = ((aWandererA + RotL64(aPrevious, 47U)) + 545981421632236251U) + aNonceWordE;
            aOrbiterC = ((aWandererD + RotL64(aCross, 29U)) + 15338259639814630535U) + aNonceWordJ;
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 12924313840290895215U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 17846785921286020610U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 18309347016029917133U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 5721472794107057875U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 16359630793856870319U;
            aOrbiterE = RotL64((aOrbiterE * 14186771515526698907U), 39U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 10614102110239037308U) + aNonceWordG;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 16421992251278236531U;
            aOrbiterI = RotL64((aOrbiterI * 2561232904676068089U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 8668149834861244963U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 12699331834360948734U;
            aOrbiterB = RotL64((aOrbiterB * 2249360824172616357U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 4470693178142950471U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 526000656022724741U;
            aOrbiterC = RotL64((aOrbiterC * 16688501462334673493U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 6880246132270094141U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 7126466778855297013U;
            aOrbiterG = RotL64((aOrbiterG * 5692237926830293205U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 6436404501390442054U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 1213633065612242699U) ^ aNonceWordN;
            aOrbiterH = RotL64((aOrbiterH * 17604454985534439259U), 43U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterC) + 8186529105901185854U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1]) + aNonceWordB;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 10607460957358250935U;
            aOrbiterD = RotL64((aOrbiterD * 17172191011625677861U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 9743278964993305169U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 14007577681873418075U;
            aOrbiterA = RotL64((aOrbiterA * 4231122580398039133U), 35U);
            //
            aIngress = RotL64(aOrbiterD, 3U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterI, 23U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterF, 19U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 53U));
            aIngress = aIngress + RotL64(aOrbiterA, 36U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 41U) + RotL64(aOrbiterI, 14U)) + aOrbiterC) + aNonceWordC);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 14U) + RotL64(aOrbiterG, 5U)) + aOrbiterF);
            aWandererF = aWandererF + ((RotL64(aCross, 35U) + aOrbiterE) + RotL64(aOrbiterB, 29U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 3U) + aOrbiterC) + RotL64(aOrbiterE, 43U)) + aPhaseFWandererUpdateSaltA[((aIndex + 6U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 51U) + aOrbiterH) + RotL64(aOrbiterC, 21U)) + RotL64(aCarry, 19U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterA, 57U)) + aOrbiterB);
            aWandererD = aWandererD + ((((RotL64(aCross, 29U) + aOrbiterC) + RotL64(aOrbiterG, 48U)) + RotL64(aCarry, 5U)) + aNonceWordD);
            aWandererB = aWandererB ^ ((((RotL64(aScatter, 23U) + aOrbiterF) + RotL64(aOrbiterD, 37U)) + aNonceWordK) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aIngress, 10U) + aOrbiterH) + RotL64(aOrbiterI, 53U)) + aNonceWordO);
            //
            aCarry = aCarry + (RotL64(aWandererH, 35U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererE, 47U) ^ aWandererA);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 57U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 43U));
            aCarry = aCarry + RotL64(aWandererJ, 54U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_f loop 6
        // ingress from: aExpandLaneC, aExpandLaneA, aWorkLaneC
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aWorkLaneC forward/backward random
        // cross from: aExpandLaneB, aOperationLaneB
        // cross directions: aExpandLaneB backward forced, aOperationLaneB backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 31178U)) & S_BLOCK1], 30U) ^ RotL64(aExpandLaneA[((aIndex + 31213U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 31213U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27769U)) & S_BLOCK1], 24U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28590U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCross, 21U) ^ RotL64(aIngress, 36U)) ^ (RotL64(aCarry, 53U) + RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterA = (((aWandererE + RotL64(aCross, 48U)) + RotL64(aCarry, 3U)) + 14823268998003220191U) + aNonceWordN;
            aOrbiterD = ((aWandererD + RotL64(aScatter, 53U)) + 15295237288788213847U) + aPhaseFOrbiterAssignSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterF = (aWandererA + RotL64(aIngress, 23U)) + 16434853402001133899U;
            aOrbiterG = (aWandererG + RotL64(aPrevious, 3U)) + 7555911304407871631U;
            aOrbiterH = (((aWandererI + RotL64(aCross, 39U)) + 14977248264994834620U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordK;
            aOrbiterE = ((aWandererC + RotL64(aScatter, 60U)) + 9707764144919392380U) + aNonceWordF;
            aOrbiterC = (aWandererB + RotL64(aIngress, 35U)) + 1277304385464681529U;
            aOrbiterK = ((aWandererF + RotL64(aPrevious, 29U)) + RotL64(aCarry, 51U)) + 3089786220465849395U;
            aOrbiterI = (((aWandererJ + RotL64(aIngress, 13U)) + RotL64(aCarry, 35U)) + 3700503853358695085U) + aNonceWordH;
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 3240054112993517371U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 16897532076915366859U;
            aOrbiterF = RotL64((aOrbiterF * 4120874717534309035U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 18167359289798364307U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 8870819278575769863U;
            aOrbiterA = RotL64((aOrbiterA * 9334066154398059075U), 21U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 15363069206212330251U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 14858164441499725158U) ^ aNonceWordP;
            aOrbiterC = RotL64((aOrbiterC * 14931933411393847915U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 5357144808788707522U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 2910681277417754860U) ^ aNonceWordD;
            aOrbiterE = RotL64((aOrbiterE * 13170868582159347059U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 9824408699018165151U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 368370224788793300U) ^ aNonceWordG;
            aOrbiterI = RotL64((aOrbiterI * 14358982366258729959U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 7095398304588825115U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 11418879758164313554U;
            aOrbiterG = RotL64((aOrbiterG * 5983520332639771791U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 2171599720681913272U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 17593730219647495033U;
            aOrbiterD = RotL64((aOrbiterD * 12926053208918563087U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 17755947635188715523U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 14565740605227022106U;
            aOrbiterK = RotL64((aOrbiterK * 15866418354612945335U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 14538017880915584414U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 6174566474851449123U;
            aOrbiterH = RotL64((aOrbiterH * 179569008593475683U), 35U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterD, 35U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 60U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 51U));
            aIngress = aIngress + (RotL64(aOrbiterG, 3U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterF, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aCross, 3U) + RotL64(aOrbiterK, 20U)) + aOrbiterH) + RotL64(aCarry, 35U)) + aPhaseFWandererUpdateSaltF[((aIndex + 14U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterF, 57U)) + aOrbiterH);
            aWandererE = aWandererE + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterE, 3U)) + aOrbiterD) + aNonceWordL);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 10U) + aOrbiterC) + RotL64(aOrbiterA, 27U));
            aWandererG = aWandererG + (((RotL64(aCross, 47U) + aOrbiterG) + RotL64(aOrbiterI, 41U)) + aNonceWordJ);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 57U) + RotL64(aOrbiterF, 52U)) + aOrbiterI) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aIngress, 35U) + aOrbiterK) + RotL64(aOrbiterA, 11U)) + RotL64(aCarry, 51U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 53U) + aOrbiterD) + RotL64(aOrbiterF, 37U)) + aNonceWordI);
            aWandererD = aWandererD + (((RotL64(aPrevious, 18U) + aOrbiterE) + RotL64(aOrbiterK, 47U)) + aNonceWordC);
            //
            aCarry = aCarry + (RotL64(aWandererC, 12U) ^ aWandererB);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 3U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 47U));
            aCarry = aCarry + (RotL64(aWandererJ, 43U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererA, 23U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xF7E9A6DC59A5C58FULL + 0xB221810E8E90BC09ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x8AAA0C76945FA1A1ULL + 0xBF84A96CEDB399A9ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x96F63B6F36191C63ULL + 0xA0BA6126DA525913ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xCEF9F7D6ED9DA1E9ULL + 0xF1E5BB1795A967C6ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xF3BF17EE3DBD9743ULL + 0xDFE72EFBE0A1543EULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xBBA0D8ACFD882311ULL + 0xE5E0C1C539F217E5ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x939772FA4EFD3097ULL + 0x8C7F9B05475ECE79ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xF4B888A0B54C3D5FULL + 0xAF1142F5C47236A1ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xAD97B035AC20BED1ULL + 0xAA0BD35FB1CBF510ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xE36E273E1BF83E13ULL + 0xA17016DA6247B2C2ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xA70D34FCA9448B59ULL + 0xE769561B46DAC5E1ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xF19AB44D7E930207ULL + 0xBEACEB637D9DE482ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xDE7EB9ECAE2A6029ULL + 0x8DAC04D396B158CDULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xCB47E28D77B3FC33ULL + 0xC3E2871B84765301ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x83B513A605FF6BABULL + 0xB87FA183EAEEC3BBULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0x925385B4B5E228A3ULL + 0xE90ABBB95611A2EAULL);
    // GSeedRunSeed_G seed_loop_h (start)
    {
        // GSeedRunSeed_G seed_loop_h lane group
        // read from: aSnowLaneA, aSnowLaneB, aFireLaneC, aSnowLaneC, aSnowLaneD, aInvestLaneC, aWorkLaneA, aFireLaneD, aFireLaneA, aWorkLaneB, aInvestLaneD, aExpandLaneA, aInvestLaneB, aExpandLaneB, aInvestLaneA, aExpandLaneC, aFireLaneB
        // write to: aWorkLaneA, aWorkLaneB, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // seed_loop_h loop 1
        // ingress from: aSnowLaneA, aSnowLaneB, aFireLaneC
        // ingress directions: aSnowLaneA forward forced, aSnowLaneB forward forced, aFireLaneC forward/backward random
        // cross from: aSnowLaneC, aSnowLaneD, aInvestLaneC
        // cross directions: aSnowLaneC backward forced, aSnowLaneD backward forced, aInvestLaneC backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneA[((aIndex + 4295U)) & S_BLOCK1], 52U) ^ RotL64(aSnowLaneB[((aIndex + 1596U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 921U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 1328U)) & S_BLOCK1], 47U) ^ RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 1583U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aInvestLaneC[((aIndex + 2581U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aPrevious, 39U) ^ RotL64(aCross, 5U)) + (RotL64(aCarry, 18U) + RotL64(aIngress, 51U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterH = ((aWandererJ + RotL64(aPrevious, 58U)) + 9446153639709651566U) + aNonceWordC;
            aOrbiterD = ((((aWandererG + RotL64(aCross, 3U)) + RotL64(aCarry, 57U)) + 10550762260670758167U) + aPhaseHOrbiterAssignSaltD[((aIndex + 3U)) & S_SALT1]) + aNonceWordN;
            aOrbiterE = ((aWandererI + RotL64(aScatter, 13U)) + RotL64(aCarry, 21U)) + 7062634922142578383U;
            aOrbiterB = (aWandererC + RotL64(aIngress, 41U)) + 9178499097812764515U;
            aOrbiterF = ((aWandererB + RotL64(aScatter, 35U)) + 6887103379773525538U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterG = (((aWandererE + RotL64(aIngress, 47U)) + RotL64(aCarry, 37U)) + 6239750312052010257U) + aNonceWordH;
            aOrbiterJ = (aWandererD + RotL64(aPrevious, 23U)) + 17645022614523287959U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 3639618183259408272U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterH) ^ 3131737117548745095U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterE = RotL64((aOrbiterE * 6585057380704940395U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 7253994382396406554U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 15217993711938379561U) ^ aNonceWordI;
            aOrbiterF = RotL64((aOrbiterF * 17853313384747259923U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 12594152227603630033U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 11250170200489647869U;
            aOrbiterD = RotL64((aOrbiterD * 546800378327864723U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 12936942656624279424U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 10990736056052106149U) ^ aNonceWordG;
            aOrbiterG = RotL64((aOrbiterG * 7123916809953459187U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 12787293075893090465U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 17154990205620778151U;
            aOrbiterB = RotL64((aOrbiterB * 10031369940028159521U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 1270827262969060301U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 17337623431665013136U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 1517262088236356107U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 830330490987911853U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 6828309232554560547U) ^ aNonceWordE;
            aOrbiterJ = RotL64((aOrbiterJ * 9742464176986145819U), 27U);
            //
            aIngress = RotL64(aOrbiterF, 29U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 50U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 19U));
            aIngress = aIngress + RotL64(aOrbiterD, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aScatter, 3U) + aOrbiterE) + RotL64(aOrbiterF, 37U)) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererB = aWandererB + (((((RotL64(aPrevious, 29U) + aOrbiterJ) + RotL64(aOrbiterG, 5U)) + RotL64(aCarry, 41U)) + aNonceWordA) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterD, 51U)) + aOrbiterJ);
            aWandererE = aWandererE + (((RotL64(aIngress, 57U) + aOrbiterG) + RotL64(aOrbiterF, 23U)) + RotL64(aCarry, 13U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterE, 58U)) + aOrbiterG);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 10U) + RotL64(aOrbiterH, 13U)) + aOrbiterB);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 21U) + RotL64(aOrbiterD, 43U)) + aOrbiterH) + aNonceWordF);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 38U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 51U));
            aCarry = aCarry + (RotL64(aWandererB, 19U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererC, 13U);
            aCarry = aCarry + RotL64(aIngress, 28U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_h loop 2
        // ingress from: aWorkLaneA, aSnowLaneC, aSnowLaneD, aFireLaneD
        // ingress directions: aWorkLaneA forward forced, aSnowLaneC forward forced, aSnowLaneD forward forced, aFireLaneD forward/backward random
        // cross from: aSnowLaneA, aSnowLaneB, aFireLaneA
        // cross directions: aSnowLaneA backward forced, aSnowLaneB backward forced, aFireLaneA backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 6627U)) & S_BLOCK1], 35U) ^ RotL64(aSnowLaneC[((aIndex + 8418U)) & S_BLOCK1], 56U));
            aIngress ^= (RotL64(aSnowLaneD[((aIndex + 10767U)) & S_BLOCK1], 43U) ^ RotL64(aFireLaneD[((aIndex + 9102U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 10300U)) & S_BLOCK1], 21U) ^ RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 8054U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 9034U)) & S_BLOCK1], 58U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aPrevious, 36U) ^ RotL64(aCross, 53U)) ^ (RotL64(aIngress, 3U) + RotL64(aCarry, 19U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterA = (((aWandererF + RotL64(aScatter, 41U)) + RotL64(aCarry, 57U)) + 6521330037475130256U) + aNonceWordO;
            aOrbiterG = (((aWandererJ + RotL64(aIngress, 19U)) + RotL64(aCarry, 39U)) + 12611880456055428940U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = ((aWandererH + RotL64(aCross, 47U)) + 12061611078130934708U) + aPhaseHOrbiterAssignSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterJ = (aWandererE + RotL64(aPrevious, 34U)) + 1558112410801116984U;
            aOrbiterC = ((aWandererI + RotL64(aIngress, 3U)) + 10509115227850160786U) + aNonceWordM;
            aOrbiterH = ((aWandererA + RotL64(aPrevious, 11U)) + 4045915960688792066U) + aNonceWordH;
            aOrbiterF = (((aWandererK + RotL64(aCross, 57U)) + RotL64(aCarry, 27U)) + 1196541286513243082U) + aNonceWordA;
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 15564991032722373702U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 4897765238703641798U) ^ aNonceWordL;
            aOrbiterI = RotL64((aOrbiterI * 9693901276712946763U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 12327429514907752733U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 6189189797708711636U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9017615866338877651U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 6374267075282018852U) + aNonceWordB;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 1888758503831341439U;
            aOrbiterH = RotL64((aOrbiterH * 74387714918264257U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 14956857689299491800U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 14879361107223331957U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 9166712966729591953U), 37U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterF) + 16086885494838105042U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordP;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 8069724185844303923U;
            aOrbiterG = RotL64((aOrbiterG * 8878470736758734353U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 10854345917959911439U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 7078313614360332089U) ^ aNonceWordE;
            aOrbiterA = RotL64((aOrbiterA * 9864025732292844871U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 15083669236062255011U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 594879695916679116U;
            aOrbiterF = RotL64((aOrbiterF * 9852515479152735283U), 13U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterI, 28U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 5U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 37U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterH, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 3U) + aOrbiterA) + RotL64(aOrbiterC, 19U)) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererF = aWandererF + (((((RotL64(aCross, 27U) + aOrbiterF) + RotL64(aOrbiterA, 3U)) + RotL64(aCarry, 11U)) + aNonceWordF) + aPhaseHWandererUpdateSaltE[((aIndex + 14U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterA, 60U)) + aOrbiterI) + aNonceWordJ);
            aWandererE = aWandererE + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterC, 41U)) + aOrbiterH) + RotL64(aCarry, 41U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 51U) + RotL64(aOrbiterI, 27U)) + aOrbiterJ) + aNonceWordD);
            aWandererH = aWandererH + ((RotL64(aScatter, 41U) + aOrbiterG) + RotL64(aOrbiterH, 13U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 14U) + aOrbiterJ) + RotL64(aOrbiterH, 53U)) + aNonceWordN);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 24U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererF, 29U) ^ aWandererK);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 57U));
            aCarry = aCarry + RotL64(aWandererH, 3U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 14944U)) & S_BLOCK1], 47U) ^ RotL64(aSnowLaneA[((aIndex + 11962U)) & S_BLOCK1], 18U));
            aIngress ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 11328U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordD));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 13754U)) & S_BLOCK1], 43U) ^ RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 14680U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCross, 41U) + RotL64(aPrevious, 53U)) ^ (RotL64(aIngress, 5U) ^ RotL64(aCarry, 18U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterB = (aWandererB + RotL64(aCross, 39U)) + 16200278595895089008U;
            aOrbiterJ = (((aWandererC + RotL64(aScatter, 27U)) + 1029614154810465897U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 10U)) & S_SALT1]) + aNonceWordF;
            aOrbiterE = ((aWandererJ + RotL64(aIngress, 46U)) + RotL64(aCarry, 53U)) + 7129562468705441295U;
            aOrbiterA = (((aWandererH + RotL64(aPrevious, 19U)) + RotL64(aCarry, 3U)) + 14388903902433951274U) + aNonceWordE;
            aOrbiterD = (aWandererK + RotL64(aIngress, 5U)) + 1013568949315967455U;
            aOrbiterI = (((aWandererD + RotL64(aScatter, 13U)) + RotL64(aCarry, 41U)) + 3128823373497815651U) + aNonceWordM;
            aOrbiterF = (((aWandererE + RotL64(aCross, 53U)) + 14525694606889470589U) + aPhaseHOrbiterAssignSaltF[((aIndex + 15U)) & S_SALT1]) + aNonceWordH;
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 14443983602196782887U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 12244220415328641190U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15052949098014803181U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 10477159225338766614U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 2842870123078131566U;
            aOrbiterJ = RotL64((aOrbiterJ * 11522265477555954071U), 27U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterE) + 8621138818955849917U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordB;
            aOrbiterD = (((aOrbiterD ^ aOrbiterJ) ^ 5038396344400303181U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterD = RotL64((aOrbiterD * 14636756322207385447U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 2768613802894372496U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 2027754864051410015U;
            aOrbiterF = RotL64((aOrbiterF * 2461322540050569287U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 2848088309172056399U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 15017458513904884651U;
            aOrbiterB = RotL64((aOrbiterB * 9926904679902843055U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 9079797279596336139U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 15424866642305110811U;
            aOrbiterA = RotL64((aOrbiterA * 12912331089970158845U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 13751764050290602740U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 7694557131324740282U;
            aOrbiterI = RotL64((aOrbiterI * 14980807690491467023U), 47U);
            //
            aIngress = RotL64(aOrbiterB, 35U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 47U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 58U));
            aIngress = aIngress + RotL64(aOrbiterF, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aIngress, 21U) + RotL64(aOrbiterJ, 27U)) + aOrbiterB) + aNonceWordG);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 13U) + RotL64(aOrbiterA, 47U)) + aOrbiterI) + RotL64(aCarry, 35U)) + aNonceWordI);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 28U) + RotL64(aOrbiterE, 21U)) + aOrbiterD);
            aWandererJ = aWandererJ + (((RotL64(aCross, 3U) + RotL64(aOrbiterJ, 41U)) + aOrbiterD) + aNonceWordK);
            aWandererC = aWandererC ^ ((((RotL64(aScatter, 35U) + RotL64(aOrbiterE, 13U)) + aOrbiterJ) + aNonceWordO) + aPhaseHWandererUpdateSaltF[((aIndex + 11U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aCross, 57U) + aOrbiterF) + RotL64(aOrbiterA, 6U)) + RotL64(aCarry, 47U)) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterF, 35U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererH, 24U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererJ);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 3U));
            aCarry = aCarry + RotL64(aWandererE, 41U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_h loop 4
        // ingress from: aExpandLaneA, aWorkLaneA, aInvestLaneB
        // ingress directions: aExpandLaneA forward forced, aWorkLaneA forward forced, aInvestLaneB forward/backward random
        // cross from: aWorkLaneB, aSnowLaneD
        // cross directions: aWorkLaneB backward forced, aSnowLaneD backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 19604U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneA[((aIndex + 20784U)) & S_BLOCK1], 48U));
            aIngress ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 16695U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 17377U)) & S_BLOCK1], 19U) ^ RotL64(aSnowLaneD[((aIndex + 17040U)) & S_BLOCK1], 52U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aIngress, 11U) + RotL64(aCarry, 40U)) + (RotL64(aPrevious, 23U) ^ RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterJ = (((aWandererH + RotL64(aPrevious, 60U)) + RotL64(aCarry, 19U)) + 17668251151213543491U) + aNonceWordH;
            aOrbiterK = (aWandererE + RotL64(aCross, 53U)) + 16101602509895104517U;
            aOrbiterF = (aWandererF + RotL64(aScatter, 23U)) + 9083915270773304935U;
            aOrbiterE = (((aWandererC + RotL64(aIngress, 13U)) + RotL64(aCarry, 57U)) + 12810720730318214811U) + aPhaseHOrbiterAssignSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = (((aWandererB + RotL64(aScatter, 43U)) + RotL64(aCarry, 43U)) + 18113428002071925621U) + aPhaseHOrbiterAssignSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = ((aWandererD + RotL64(aIngress, 35U)) + 1582208899354109878U) + aNonceWordL;
            aOrbiterB = ((aWandererA + RotL64(aCross, 3U)) + 4180688104819188154U) + aNonceWordD;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 8954598189262820611U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 15360094153175355879U;
            aOrbiterF = RotL64((aOrbiterF * 8177798855402983685U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 8383954114668216260U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 15626783326234049197U) ^ aNonceWordJ;
            aOrbiterG = RotL64((aOrbiterG * 15058420415480073793U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 10609978564404958066U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 17656516608997517984U;
            aOrbiterK = RotL64((aOrbiterK * 4590620354119899777U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 760077259110786536U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 3597338735888033063U;
            aOrbiterJ = RotL64((aOrbiterJ * 6548831472863517621U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 4431777844935985157U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 10710423172154671296U;
            aOrbiterE = RotL64((aOrbiterE * 16267496318491473315U), 5U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterF) + 10240882795242085185U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordF;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 7826053487019825891U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 15053729937684375907U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 9418883403715727353U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 11507423614799075545U;
            aOrbiterI = RotL64((aOrbiterI * 16189463984557044693U), 23U);
            //
            aIngress = RotL64(aOrbiterB, 35U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 43U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 18U));
            aIngress = aIngress + RotL64(aOrbiterI, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aScatter, 37U) + aOrbiterK) + RotL64(aOrbiterB, 60U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 5U) + aOrbiterE) + RotL64(aOrbiterI, 19U));
            aWandererE = aWandererE + ((((RotL64(aPrevious, 29U) + aOrbiterJ) + RotL64(aOrbiterG, 11U)) + aNonceWordN) + aPhaseHWandererUpdateSaltA[((aIndex + 5U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 11U) + aOrbiterE) + RotL64(aOrbiterG, 37U)) + aNonceWordP);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 23U) + RotL64(aOrbiterF, 27U)) + aOrbiterK) + RotL64(aCarry, 39U)) + aNonceWordI);
            aWandererA = aWandererA ^ (((RotL64(aCross, 43U) + aOrbiterF) + RotL64(aOrbiterJ, 47U)) + aPhaseHWandererUpdateSaltB[((aIndex + 12U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aScatter, 58U) + aOrbiterB) + RotL64(aOrbiterF, 5U)) + RotL64(aCarry, 21U)) + aNonceWordA);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 47U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 29U));
            aCarry = aCarry + (RotL64(aWandererH, 56U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererB, 3U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_h loop 5
        // ingress from: aExpandLaneB, aWorkLaneB, aInvestLaneA
        // ingress directions: aExpandLaneB forward forced, aWorkLaneB forward forced, aInvestLaneA forward/backward random
        // cross from: aExpandLaneA, aWorkLaneA
        // cross directions: aExpandLaneA backward forced, aWorkLaneA backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 26381U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneB[((aIndex + 22301U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 24779U)) & S_BLOCK1], 48U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 23172U)) & S_BLOCK1], 12U) ^ RotL64(aWorkLaneA[((aIndex + 25172U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aIngress, 18U)) ^ (RotL64(aCarry, 53U) ^ RotL64(aPrevious, 41U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterG = ((aWandererH + RotL64(aPrevious, 21U)) + 2571116506511057880U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = ((aWandererJ + RotL64(aCross, 3U)) + 13112435411509707292U) + aPhaseHOrbiterAssignSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = (aWandererI + RotL64(aIngress, 27U)) + 10403251762787357256U;
            aOrbiterE = ((aWandererC + RotL64(aScatter, 37U)) + RotL64(aCarry, 21U)) + 8461951095541400405U;
            aOrbiterC = ((aWandererK + RotL64(aIngress, 43U)) + RotL64(aCarry, 41U)) + 9890793478557463815U;
            aOrbiterB = ((aWandererD + RotL64(aScatter, 60U)) + 3030229465991783707U) + aNonceWordI;
            aOrbiterK = (((aWandererE + RotL64(aCross, 51U)) + RotL64(aCarry, 57U)) + 7273848154043719247U) + aNonceWordE;
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 10681774862516028276U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 7105082755586853104U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 12217705329504230357U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 6588579345319551129U) + aNonceWordH;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 14616333550242386092U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2934574715879306337U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 15439666290229654921U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 3360304356760164799U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5164191920584106237U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 14438730801970761889U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 14515616787452085729U) ^ aNonceWordF;
            aOrbiterK = RotL64((aOrbiterK * 2041601927968559821U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 4167853822635132419U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 8950982233003320239U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 887144270884244907U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 12391327853728029953U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 7100871010552394421U;
            aOrbiterG = RotL64((aOrbiterG * 16552349374101955967U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 15381697462381887944U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 6801677551341079401U) ^ aNonceWordJ;
            aOrbiterB = RotL64((aOrbiterB * 13325954438427340703U), 57U);
            //
            aIngress = RotL64(aOrbiterD, 58U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterF, 5U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterG, 23U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterB, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aScatter, 13U) + aOrbiterB) + RotL64(aOrbiterG, 29U)) + aNonceWordP);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 47U) + aOrbiterE) + RotL64(aOrbiterC, 43U)) + RotL64(aCarry, 43U)) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 53U) + aOrbiterK) + RotL64(aOrbiterD, 13U)) + aNonceWordD);
            aWandererD = aWandererD + (((RotL64(aCross, 5U) + aOrbiterC) + RotL64(aOrbiterD, 35U)) + aPhaseHWandererUpdateSaltC[((aIndex + 7U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 28U) + aOrbiterC) + RotL64(aOrbiterF, 20U)) + aNonceWordG);
            aWandererC = aWandererC + (((RotL64(aScatter, 21U) + aOrbiterF) + RotL64(aOrbiterB, 5U)) + RotL64(aCarry, 29U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 35U) + aOrbiterD) + RotL64(aOrbiterG, 53U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 53U));
            aCarry = aCarry + (RotL64(aWandererK, 41U) ^ aWandererC);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 34U));
            aCarry = aCarry + RotL64(aWandererE, 19U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_h loop 6
        // ingress from: aExpandLaneC, aExpandLaneA, aFireLaneB
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aFireLaneB forward/backward random
        // cross from: aExpandLaneB, aSnowLaneB
        // cross directions: aExpandLaneB backward forced, aSnowLaneB backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 31700U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneA[((aIndex + 29943U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 27545U)) & S_BLOCK1], 46U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31498U)) & S_BLOCK1], 3U) ^ RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 30628U)) & S_BLOCK1], 44U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aIngress, 39U) + RotL64(aCross, 54U)) + (RotL64(aPrevious, 27U) ^ RotL64(aCarry, 13U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterE = ((aWandererI + RotL64(aIngress, 43U)) + RotL64(aCarry, 3U)) + 13350544654542863236U;
            aOrbiterI = ((aWandererH + RotL64(aCross, 19U)) + RotL64(aCarry, 51U)) + 12364346790125404372U;
            aOrbiterK = ((aWandererD + RotL64(aPrevious, 5U)) + RotL64(aCarry, 37U)) + 9738750172849512764U;
            aOrbiterJ = ((aWandererE + RotL64(aScatter, 37U)) + 3781373837635491421U) + aNonceWordJ;
            aOrbiterA = ((aWandererG + RotL64(aIngress, 57U)) + 16635020317512702337U) + aPhaseHOrbiterAssignSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = (((aWandererF + RotL64(aCross, 28U)) + 5383653921676231276U) + aPhaseHOrbiterAssignSaltE[((aIndex + 26U)) & S_SALT1]) + aNonceWordF;
            aOrbiterH = (aWandererB + RotL64(aPrevious, 11U)) + 10181959815492056493U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 10005510924273927017U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 9524687662265740565U;
            aOrbiterK = RotL64((aOrbiterK * 13687380438646756931U), 35U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterJ) + 4259138552009771014U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1]) + aNonceWordL;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 8973051213213726023U;
            aOrbiterA = RotL64((aOrbiterA * 12625091476068190979U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 17602611840127337490U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 8218984546932905269U;
            aOrbiterE = RotL64((aOrbiterE * 17504305273683304231U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 18102186122213487888U) + aNonceWordB;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 2629927500298092976U;
            aOrbiterG = RotL64((aOrbiterG * 6983280164448292723U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 2491581597835795234U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 9506602492971620955U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9559829640915637163U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 13422942713680612924U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 15037354693234876601U;
            aOrbiterJ = RotL64((aOrbiterJ * 12692376075738621447U), 41U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterH) + 12896066842192894694U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordO;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 2202952306291905855U;
            aOrbiterI = RotL64((aOrbiterI * 6779368532763429997U), 3U);
            //
            aIngress = RotL64(aOrbiterA, 60U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterK, 41U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterH, 19U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterJ, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aPrevious, 19U) + RotL64(aOrbiterH, 13U)) + aOrbiterJ);
            aWandererB = aWandererB ^ (((RotL64(aCross, 58U) + RotL64(aOrbiterE, 21U)) + aOrbiterJ) + aPhaseHWandererUpdateSaltD[((aIndex + 25U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 35U) + aOrbiterK) + RotL64(aOrbiterH, 29U)) + RotL64(aCarry, 57U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 29U) + RotL64(aOrbiterA, 35U)) + aOrbiterG) + aNonceWordP);
            aWandererI = aWandererI + (((RotL64(aPrevious, 51U) + aOrbiterA) + RotL64(aOrbiterK, 41U)) + RotL64(aCarry, 13U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 5U) + RotL64(aOrbiterE, 54U)) + aOrbiterI) + aNonceWordK);
            aWandererD = aWandererD + ((((RotL64(aCross, 41U) + RotL64(aOrbiterI, 5U)) + aOrbiterG) + aNonceWordE) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 57U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererG, 21U) ^ aWandererH);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 36U));
            aCarry = aCarry + RotL64(aWandererI, 47U);
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
    [[maybe_unused]] std::uint8_t *aFireLaneA = pWorkSpace->mFireLaneA;
    [[maybe_unused]] std::uint8_t *aFireLaneB = pWorkSpace->mFireLaneB;
    [[maybe_unused]] std::uint8_t *aFireLaneC = pWorkSpace->mFireLaneC;
    [[maybe_unused]] std::uint8_t *aFireLaneD = pWorkSpace->mFireLaneD;
    [[maybe_unused]] std::uint8_t *aInvestLaneA = pWorkSpace->mInvestLaneA;
    [[maybe_unused]] std::uint8_t *aInvestLaneB = pWorkSpace->mInvestLaneB;
    [[maybe_unused]] std::uint8_t *aKeyRowReadA = &(pWorkSpace->mKeyBoxA[H_KEY - 1][0]);
    [[maybe_unused]] std::uint8_t *aKeyRowReadB = &(pWorkSpace->mKeyBoxB[H_KEY - 1][0]);
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltB;
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
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltF;
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
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC;
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
            aIngress = RotL64(aKeyRowReadA[((aIndex + 1209U)) & W_KEY1], 41U) ^ RotL64(aKeyRowReadB[((aIndex + 213U)) & W_KEY1], 58U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 1704U)) & W_KEY1], 43U) ^ RotL64(mSource[((aIndex + 490U)) & S_BLOCK1], 18U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 11U) + RotL64(aPrevious, 60U)) + (RotL64(aIngress, 43U) ^ RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterG = (((aWandererE + RotL64(aPrevious, 13U)) + RotL64(aCarry, 19U)) + 6469584119078165548U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = (aWandererG + RotL64(aIngress, 57U)) + 14329756366517987910U;
            aOrbiterJ = (aWandererJ + RotL64(aScatter, 22U)) + 12890831797059772123U;
            aOrbiterF = ((aWandererF + RotL64(aCross, 35U)) + RotL64(aCarry, 41U)) + 3164503807500018990U;
            aOrbiterE = (aWandererH + RotL64(aIngress, 29U)) + 177531431387646836U;
            aOrbiterB = (aWandererA + RotL64(aCross, 51U)) + 3167421392893561015U;
            aOrbiterH = (aWandererD + RotL64(aScatter, 41U)) + 2813174781844753460U;
            aOrbiterI = ((aWandererB + RotL64(aPrevious, 6U)) + 10953270419153249857U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = ((aWandererC + RotL64(aIngress, 47U)) + RotL64(aCarry, 3U)) + 16911518309710356951U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 6616750447844893150U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 10276741398025985982U;
            aOrbiterJ = RotL64((aOrbiterJ * 6824712685896987133U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 6206043608461213208U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 12021552904553405793U;
            aOrbiterB = RotL64((aOrbiterB * 10023362889960174909U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 15283586234744144846U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 5923238786775948571U;
            aOrbiterH = RotL64((aOrbiterH * 8200882393521882651U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 11044014510971660078U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 9351141024085076044U;
            aOrbiterE = RotL64((aOrbiterE * 13316079344614432317U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 17703395981862992420U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 10154548848376027087U;
            aOrbiterC = RotL64((aOrbiterC * 12324478347590509035U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 8836420852291617425U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 10193385413543886344U;
            aOrbiterF = RotL64((aOrbiterF * 824935982418585449U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 8248580084535685190U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 3910083671888152974U;
            aOrbiterI = RotL64((aOrbiterI * 17825311776715895927U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 12350341628569930642U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 2565977481575002842U;
            aOrbiterG = RotL64((aOrbiterG * 18233446879833776677U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 9271041067874027417U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 14289254596554201861U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 7985522692852251413U), 19U);
            //
            aIngress = RotL64(aOrbiterJ, 23U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterB, 50U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 27U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 41U));
            aIngress = aIngress + RotL64(aOrbiterF, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 48U) + RotL64(aOrbiterF, 19U)) + aOrbiterH);
            aWandererB = aWandererB + ((RotL64(aScatter, 3U) + RotL64(aOrbiterF, 60U)) + aOrbiterC);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterE, 47U)) + aOrbiterF);
            aWandererE = aWandererE + ((RotL64(aCross, 57U) + RotL64(aOrbiterI, 39U)) + aOrbiterD);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterD, 11U)) + aOrbiterF);
            aWandererC = aWandererC + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterJ, 35U)) + aOrbiterF) + RotL64(aCarry, 57U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 53U) + aOrbiterJ) + RotL64(aOrbiterE, 23U)) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aScatter, 13U) + aOrbiterG) + RotL64(aOrbiterC, 3U)) + RotL64(aCarry, 11U)) + aPhaseAWandererUpdateSaltB[((aIndex + 4U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 44U) + aOrbiterB) + RotL64(aOrbiterJ, 54U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 46U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererA, 5U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererD, 51U) ^ aWandererG);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 35U));
            aCarry = aCarry + RotL64(aWandererE, 57U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 4692U)) & S_BLOCK1], 38U) ^ RotL64(aKeyRowReadA[((aIndex + 3205U)) & W_KEY1], 27U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 2913U)) & W_KEY1], 28U) ^ RotL64(mSource[((aIndex + 5306U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 11U) + RotL64(aCross, 37U)) ^ (RotL64(aCarry, 50U) ^ RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterB = (aWandererJ + RotL64(aScatter, 27U)) + 13442819395490639310U;
            aOrbiterC = ((aWandererD + RotL64(aCross, 53U)) + 8187292523194120936U) + aPhaseAOrbiterAssignSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterH = (aWandererI + RotL64(aIngress, 42U)) + 11469697159823131388U;
            aOrbiterG = ((aWandererC + RotL64(aPrevious, 23U)) + RotL64(aCarry, 57U)) + 13414083692375929653U;
            aOrbiterA = ((aWandererB + RotL64(aIngress, 37U)) + RotL64(aCarry, 11U)) + 11404010733687907517U;
            aOrbiterD = (aWandererH + RotL64(aCross, 47U)) + 6783212827186218247U;
            aOrbiterJ = (((aWandererA + RotL64(aScatter, 10U)) + RotL64(aCarry, 3U)) + 8561131439340372614U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterI = (aWandererF + RotL64(aPrevious, 3U)) + 6252609642004429113U;
            aOrbiterE = (aWandererE + RotL64(aScatter, 57U)) + 12804867444200448952U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 2739648749603690781U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 14808861217017399752U;
            aOrbiterH = RotL64((aOrbiterH * 373911885694012101U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 17588866502571268888U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 5882260142735642980U;
            aOrbiterD = RotL64((aOrbiterD * 7688252946143263869U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 15493099088132862949U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 5175647411532429582U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 15226544495598541883U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 14279707376173642767U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 6826363572161275158U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 5263708315440161809U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 13267185753040999992U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 9980987858092888720U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13210290848800728635U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 3582972937645514549U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 10140409019562890804U;
            aOrbiterG = RotL64((aOrbiterG * 6944490201647678479U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 6160444117287330557U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 16344602960561293113U;
            aOrbiterE = RotL64((aOrbiterE * 2319964919335633293U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 3497141036108337171U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 91269118352540308U;
            aOrbiterA = RotL64((aOrbiterA * 5160060720189045505U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 12739932748793144857U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 12820180915064791197U;
            aOrbiterB = RotL64((aOrbiterB * 5843849637411948699U), 39U);
            //
            aIngress = RotL64(aOrbiterA, 57U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 26U));
            aIngress = aIngress + (RotL64(aOrbiterC, 39U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterE, 21U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterI, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aPrevious, 18U) + aOrbiterC) + RotL64(aOrbiterJ, 12U)) + RotL64(aCarry, 41U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterH, 43U)) + aOrbiterD);
            aWandererE = aWandererE + (((RotL64(aScatter, 47U) + aOrbiterJ) + RotL64(aOrbiterB, 51U)) + RotL64(aCarry, 13U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterH, 39U)) + aOrbiterA);
            aWandererD = aWandererD + ((RotL64(aPrevious, 4U) + RotL64(aOrbiterH, 57U)) + aOrbiterG);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 27U) + aOrbiterG) + RotL64(aOrbiterD, 35U));
            aWandererH = aWandererH + (((RotL64(aCross, 53U) + RotL64(aOrbiterE, 6U)) + aOrbiterD) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 43U) + aOrbiterB) + RotL64(aOrbiterI, 29U)) + aPhaseAWandererUpdateSaltA[((aIndex + 9U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aCross, 39U) + aOrbiterC) + RotL64(aOrbiterG, 19U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 43U));
            aCarry = aCarry + (RotL64(aWandererF, 5U) ^ aWandererB);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 50U));
            aCarry = aCarry + (RotL64(aWandererA, 11U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererE, 35U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = RotL64(aWorkLaneB[((aIndex + 5825U)) & S_BLOCK1], 11U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 7098U)) & W_KEY1], 50U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 7027U)) & W_KEY1], 20U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 5612U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 6572U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 41U) + RotL64(aCross, 5U)) ^ (RotL64(aIngress, 27U) ^ RotL64(aCarry, 56U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterB = (aWandererK + RotL64(aScatter, 10U)) + 1952750591494698524U;
            aOrbiterJ = ((aWandererJ + RotL64(aPrevious, 37U)) + RotL64(aCarry, 47U)) + 4488270851303332830U;
            aOrbiterH = (((aWandererD + RotL64(aCross, 57U)) + RotL64(aCarry, 37U)) + 2738763375328927635U) + aPhaseAOrbiterAssignSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterD = (((aWandererH + RotL64(aIngress, 41U)) + RotL64(aCarry, 21U)) + 6728843649480454340U) + aPhaseAOrbiterAssignSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = (aWandererI + RotL64(aCross, 47U)) + 10490717875258865358U;
            aOrbiterG = (aWandererG + RotL64(aScatter, 3U)) + 1429288737812910205U;
            aOrbiterC = (aWandererB + RotL64(aPrevious, 19U)) + 2761375016998907636U;
            aOrbiterF = (aWandererE + RotL64(aIngress, 26U)) + 1088988605204499835U;
            aOrbiterI = (aWandererA + RotL64(aCross, 53U)) + 6829840407300289709U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 9267240337867690471U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 8120113021183975703U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 14296504593187173107U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 1340980511302566784U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 11874452169979878835U;
            aOrbiterA = RotL64((aOrbiterA * 8638486178860092537U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 1872314794140971426U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 6013952618696225751U;
            aOrbiterC = RotL64((aOrbiterC * 7994863587373565715U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 3644011378086236002U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 8501867691997891731U;
            aOrbiterB = RotL64((aOrbiterB * 7115282675461711509U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 2493546555198066143U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 5179240189571799179U;
            aOrbiterF = RotL64((aOrbiterF * 1267579130962756135U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 11273348247858394197U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 4577476419423118925U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8427261005061162673U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 6201955123046621919U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 3930651302557530185U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 1563512534463027965U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 7571426325227856019U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 11098508505512361002U;
            aOrbiterD = RotL64((aOrbiterD * 9229352429618815089U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 6154830144380484305U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 4282054616147137364U;
            aOrbiterG = RotL64((aOrbiterG * 14984813139796280171U), 43U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterJ, 13U);
            aIngress = aIngress + (RotL64(aOrbiterI, 23U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 29U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 18U));
            aIngress = aIngress + RotL64(aOrbiterA, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aScatter, 37U) + aOrbiterC) + RotL64(aOrbiterI, 47U));
            aWandererE = aWandererE + (((RotL64(aIngress, 5U) + aOrbiterA) + RotL64(aOrbiterB, 11U)) + RotL64(aCarry, 43U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 26U) + RotL64(aOrbiterB, 43U)) + aOrbiterF);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 57U) + aOrbiterF) + RotL64(aOrbiterC, 6U)) + RotL64(aCarry, 19U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 41U) + aOrbiterI) + RotL64(aOrbiterA, 53U)) + aPhaseAWandererUpdateSaltE[((aIndex + 23U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aCross, 47U) + aOrbiterB) + RotL64(aOrbiterD, 39U)) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 53U) + aOrbiterJ) + RotL64(aOrbiterG, 23U));
            aWandererK = aWandererK + ((RotL64(aPrevious, 18U) + aOrbiterH) + RotL64(aOrbiterG, 29U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 13U) + aOrbiterJ) + RotL64(aOrbiterI, 60U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 37U));
            aCarry = aCarry + (RotL64(aWandererK, 43U) ^ aWandererE);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 5U));
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererA, 14U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 10482U)) & S_BLOCK1], 5U) ^ RotL64(aKeyRowReadB[((aIndex + 8669U)) & W_KEY1], 24U));
            aIngress ^= (RotL64(mSource[((aIndex + 9991U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneA[((aIndex + 10409U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 10513U)) & W_KEY1], 52U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 10486U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 41U) ^ RotL64(aIngress, 57U)) ^ (RotL64(aCross, 23U) + RotL64(aPrevious, 6U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterG = ((aWandererE + RotL64(aPrevious, 23U)) + 4622023259121087483U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterD = ((aWandererJ + RotL64(aIngress, 60U)) + RotL64(aCarry, 51U)) + 10253505250223501352U;
            aOrbiterB = ((aWandererB + RotL64(aCross, 39U)) + RotL64(aCarry, 5U)) + 17133877904420462669U;
            aOrbiterC = (aWandererD + RotL64(aScatter, 13U)) + 6162827793741796700U;
            aOrbiterK = (aWandererF + RotL64(aPrevious, 47U)) + 9610986424765907615U;
            aOrbiterA = (aWandererC + RotL64(aScatter, 35U)) + 11210747154264753754U;
            aOrbiterE = (aWandererG + RotL64(aCross, 18U)) + 16554205219580654546U;
            aOrbiterF = ((aWandererI + RotL64(aIngress, 3U)) + 10352576357413766388U) + aPhaseBOrbiterAssignSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterJ = ((aWandererA + RotL64(aPrevious, 43U)) + RotL64(aCarry, 23U)) + 3651845783283479752U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 18145542190463500476U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 5415609566767162857U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 6474184559323816389U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 2033734872464201570U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 3507213117125813345U;
            aOrbiterG = RotL64((aOrbiterG * 5453058336688881113U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 8716253393049851856U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 695984869565941856U;
            aOrbiterE = RotL64((aOrbiterE * 8377921610764044735U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 7661578828878284931U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 906654265099155956U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8117625377607536949U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 6050049984731254612U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 17882717590338190821U;
            aOrbiterJ = RotL64((aOrbiterJ * 10807367411402733215U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 4996521991532815957U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 4246460672800604436U;
            aOrbiterC = RotL64((aOrbiterC * 12047466401960824903U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 8700148116452518842U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 10039050281847466206U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11884791271239660157U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 4513844680425845372U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 3037563127442815153U;
            aOrbiterD = RotL64((aOrbiterD * 18363509277992292407U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 1005237931570968724U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 1373258132025712065U;
            aOrbiterF = RotL64((aOrbiterF * 10458020799382532395U), 29U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterE, 50U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 47U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 39U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 27U));
            aIngress = aIngress + RotL64(aOrbiterB, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 14U) + RotL64(aOrbiterG, 54U)) + aOrbiterJ);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 27U) + aOrbiterB) + RotL64(aOrbiterA, 39U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterD, 35U)) + aOrbiterE);
            aWandererF = aWandererF + (((RotL64(aIngress, 23U) + RotL64(aOrbiterD, 5U)) + aOrbiterG) + aPhaseBWandererUpdateSaltB[((aIndex + 7U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aCross, 18U) + RotL64(aOrbiterJ, 21U)) + aOrbiterA) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterJ, 26U)) + aOrbiterF) + RotL64(aCarry, 39U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 5U) + aOrbiterE) + RotL64(aOrbiterC, 47U));
            aWandererE = aWandererE + (((RotL64(aScatter, 57U) + aOrbiterK) + RotL64(aOrbiterC, 43U)) + RotL64(aCarry, 53U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 37U) + aOrbiterB) + RotL64(aOrbiterG, 11U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 36U));
            aCarry = aCarry + (RotL64(aWandererI, 19U) ^ aWandererG);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 53U));
            aCarry = aCarry + (RotL64(aWandererB, 43U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererE, 29U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 11635U)) & S_BLOCK1], 11U) ^ RotL64(aKeyRowReadA[((aIndex + 13432U)) & W_KEY1], 38U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 11501U)) & W_KEY1], 57U) ^ RotL64(mSource[((aIndex + 12739U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aWorkLaneB[((aIndex + 11424U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 13512U)) & S_BLOCK1], 42U) ^ RotL64(aInvestLaneA[((aIndex + 12477U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 28U) + RotL64(aIngress, 57U)) ^ (RotL64(aCarry, 43U) + RotL64(aPrevious, 13U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterH = (aWandererB + RotL64(aPrevious, 39U)) + 15904465836916519864U;
            aOrbiterK = (((aWandererI + RotL64(aScatter, 51U)) + RotL64(aCarry, 21U)) + 17725629806317789307U) + aPhaseBOrbiterAssignSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = (aWandererF + RotL64(aIngress, 27U)) + 13794170125914914828U;
            aOrbiterF = (aWandererH + RotL64(aCross, 34U)) + 2149055907476874332U;
            aOrbiterJ = (((aWandererG + RotL64(aIngress, 57U)) + RotL64(aCarry, 3U)) + 5342047776745074649U) + aPhaseBOrbiterAssignSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterI = ((aWandererK + RotL64(aPrevious, 11U)) + RotL64(aCarry, 11U)) + 8268148484060546838U;
            aOrbiterG = (aWandererD + RotL64(aScatter, 43U)) + 10821151364028563719U;
            aOrbiterC = (aWandererE + RotL64(aCross, 21U)) + 4294213820894407378U;
            aOrbiterB = (aWandererC + RotL64(aScatter, 4U)) + 10884726101307943090U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 16432210042202444824U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 15196602644336228055U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 12680438355124070237U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 14117787670220328165U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 219833877949480215U;
            aOrbiterH = RotL64((aOrbiterH * 10736293047771972173U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 3326396981881473962U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 14918513066311426279U;
            aOrbiterF = RotL64((aOrbiterF * 14269763278564574663U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 11795234681370163206U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 3068267285352664813U;
            aOrbiterK = RotL64((aOrbiterK * 15746255933920904619U), 37U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 245233356957999496U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 709926406353796673U;
            aOrbiterJ = RotL64((aOrbiterJ * 13627039596842073595U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 5378105439430271038U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 10114555061122044430U;
            aOrbiterB = RotL64((aOrbiterB * 5351295043424885549U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 13233010815716769713U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 8231291294833548389U;
            aOrbiterG = RotL64((aOrbiterG * 10840516135212753869U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 7160760224172419829U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 14767926435411546785U;
            aOrbiterC = RotL64((aOrbiterC * 1643485739468851073U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 4464245330038080103U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 15778166658285494712U;
            aOrbiterI = RotL64((aOrbiterI * 13980891936095282989U), 11U);
            //
            aIngress = RotL64(aOrbiterE, 10U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 35U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 51U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 47U));
            aIngress = aIngress + RotL64(aOrbiterB, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 19U) + aOrbiterC) + RotL64(aOrbiterF, 47U)) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aIngress, 34U) + RotL64(aOrbiterJ, 24U)) + aOrbiterF) + RotL64(aCarry, 47U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 3U) + aOrbiterE) + RotL64(aOrbiterG, 11U));
            aWandererD = aWandererD + ((RotL64(aCross, 29U) + RotL64(aOrbiterF, 35U)) + aOrbiterH);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 51U) + aOrbiterB) + RotL64(aOrbiterK, 39U));
            aWandererH = aWandererH + ((RotL64(aCross, 41U) + RotL64(aOrbiterI, 4U)) + aOrbiterK);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 47U) + aOrbiterJ) + RotL64(aOrbiterG, 53U));
            aWandererK = aWandererK + ((((RotL64(aScatter, 58U) + RotL64(aOrbiterF, 43U)) + aOrbiterI) + RotL64(aCarry, 57U)) + aPhaseBWandererUpdateSaltF[((aIndex + 4U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterK, 29U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 43U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 48U));
            aCarry = aCarry + (RotL64(aWandererK, 5U) ^ aWandererH);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 39U));
            aCarry = aCarry + RotL64(aWandererI, 13U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 14561U)) & S_BLOCK1], 47U) ^ RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 15844U)) & S_BLOCK1], 6U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 15357U)) & W_KEY1], 39U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 15553U)) & W_KEY1], 48U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 14000U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 15333U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 14460U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 27U) + RotL64(aPrevious, 14U)) ^ (RotL64(aCross, 39U) + RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterA = ((aWandererH + RotL64(aIngress, 21U)) + RotL64(aCarry, 27U)) + 5721224134332887360U;
            aOrbiterC = ((aWandererG + RotL64(aPrevious, 34U)) + 6892749729775049095U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterJ = ((aWandererA + RotL64(aScatter, 43U)) + 3884839462099556836U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterE = (aWandererI + RotL64(aCross, 5U)) + 4365431706830216193U;
            aOrbiterH = (aWandererJ + RotL64(aPrevious, 57U)) + 15501528746571578773U;
            aOrbiterB = (aWandererF + RotL64(aCross, 11U)) + 4505911326320650606U;
            aOrbiterD = ((aWandererB + RotL64(aScatter, 53U)) + RotL64(aCarry, 51U)) + 1865129050927879580U;
            aOrbiterF = (aWandererD + RotL64(aIngress, 38U)) + 2011737665969640369U;
            aOrbiterG = ((aWandererK + RotL64(aPrevious, 29U)) + RotL64(aCarry, 39U)) + 611672935827062688U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 663547038310431047U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 5468932264754299556U;
            aOrbiterJ = RotL64((aOrbiterJ * 11968657455484578525U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 17920294117231191705U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 486058453837528110U;
            aOrbiterB = RotL64((aOrbiterB * 8851102552244026737U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 2789178451938129313U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 420772587981211184U;
            aOrbiterA = RotL64((aOrbiterA * 17402987842294006667U), 27U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 16196774774442181825U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 16264169656793713547U;
            aOrbiterD = RotL64((aOrbiterD * 6900221986041638783U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 10207659833859860796U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 8593749091183323678U;
            aOrbiterG = RotL64((aOrbiterG * 10696776033512404927U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 7224922076047787384U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 15366267474865172373U;
            aOrbiterC = RotL64((aOrbiterC * 10134187073321814217U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 4235342515820080294U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 5239480080426950612U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 12077621553561927079U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 10891752830598395582U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 7797358829694471108U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7621206775460997431U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 3755715857903753416U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 3172069024987421726U;
            aOrbiterH = RotL64((aOrbiterH * 16048490837178650865U), 13U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterB, 11U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 24U));
            aIngress = aIngress + (RotL64(aOrbiterE, 43U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 35U));
            aIngress = aIngress + RotL64(aOrbiterF, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterC, 29U)) + aOrbiterE) + RotL64(aCarry, 27U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterA, 34U)) + aOrbiterD);
            aWandererK = aWandererK + (((RotL64(aScatter, 56U) + RotL64(aOrbiterJ, 23U)) + aOrbiterH) + aPhaseBWandererUpdateSaltA[((aIndex + 13U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterH, 3U)) + aOrbiterG);
            aWandererF = aWandererF + ((RotL64(aCross, 23U) + RotL64(aOrbiterD, 53U)) + aOrbiterJ);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterG, 13U)) + aOrbiterC);
            aWandererH = aWandererH + (((RotL64(aIngress, 35U) + aOrbiterF) + RotL64(aOrbiterJ, 46U)) + RotL64(aCarry, 35U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 6U) + RotL64(aOrbiterH, 57U)) + aOrbiterF) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aCross, 39U) + aOrbiterD) + RotL64(aOrbiterB, 39U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 29U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 35U));
            aCarry = aCarry + (RotL64(aWandererH, 22U) ^ aWandererF);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 43U));
            aCarry = aCarry + RotL64(aWandererK, 57U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 17319U)) & S_BLOCK1], 43U) ^ RotL64(aKeyRowReadA[((aIndex + 18688U)) & W_KEY1], 51U));
            aIngress ^= (RotL64(mSource[((aIndex + 18699U)) & S_BLOCK1], 34U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16438U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 17844U)) & W_KEY1], 38U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 16961U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 18981U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 13U) ^ RotL64(aCross, 57U)) ^ (RotL64(aCarry, 41U) + RotL64(aPrevious, 28U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterA = (aWandererC + RotL64(aPrevious, 23U)) + 16462052553719977502U;
            aOrbiterJ = (aWandererF + RotL64(aScatter, 53U)) + 12337064059566619581U;
            aOrbiterH = ((aWandererJ + RotL64(aCross, 47U)) + 15801005007094515447U) + aPhaseCOrbiterAssignSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = (aWandererB + RotL64(aIngress, 37U)) + 8228706742665081656U;
            aOrbiterB = ((aWandererA + RotL64(aPrevious, 14U)) + RotL64(aCarry, 57U)) + 11006723027845190869U;
            aOrbiterI = (aWandererG + RotL64(aIngress, 5U)) + 18173765337829177450U;
            aOrbiterG = ((aWandererE + RotL64(aCross, 57U)) + RotL64(aCarry, 3U)) + 530215083653542558U;
            aOrbiterF = (((aWandererD + RotL64(aScatter, 41U)) + RotL64(aCarry, 43U)) + 6608611827035564511U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = (aWandererI + RotL64(aCross, 18U)) + 2246051826221626809U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 5228575308895381421U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 10999213210689606857U;
            aOrbiterH = RotL64((aOrbiterH * 5467601259546342925U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 3773371037240485696U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 8887985779436152504U;
            aOrbiterJ = RotL64((aOrbiterJ * 698713082830739677U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 11150566414723818350U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 8336366151003049546U;
            aOrbiterF = RotL64((aOrbiterF * 9033771197242493699U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 13233968794237090787U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 8172558473508478819U;
            aOrbiterB = RotL64((aOrbiterB * 17837070423649268435U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 133564480283347997U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 15104810248883567064U) ^ aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 706802420642303533U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 9138629520201127075U) + aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 13993086066341664080U;
            aOrbiterK = RotL64((aOrbiterK * 4875046427147105077U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 6547273508580516932U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 9838727018769865759U;
            aOrbiterA = RotL64((aOrbiterA * 11395273371936839815U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 11685694999526122626U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 8945983172566303116U;
            aOrbiterG = RotL64((aOrbiterG * 17791527981004597623U), 39U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 17606249889617356327U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 9296903152000480008U;
            aOrbiterE = RotL64((aOrbiterE * 18066622289408024413U), 57U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterG, 47U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 27U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 44U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterF, 57U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterA, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aScatter, 60U) + aOrbiterH) + RotL64(aOrbiterA, 23U));
            aWandererE = aWandererE + (((RotL64(aCross, 43U) + aOrbiterK) + RotL64(aOrbiterF, 39U)) + aPhaseCWandererUpdateSaltF[((aIndex + 15U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 13U) + aOrbiterG) + RotL64(aOrbiterF, 57U));
            aWandererI = aWandererI + ((((RotL64(aIngress, 51U) + RotL64(aOrbiterI, 18U)) + aOrbiterA) + RotL64(aCarry, 39U)) + aPhaseCWandererUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 5U) + aOrbiterE) + RotL64(aOrbiterB, 35U));
            aWandererA = aWandererA + ((RotL64(aIngress, 39U) + aOrbiterG) + RotL64(aOrbiterH, 13U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 30U) + RotL64(aOrbiterG, 27U)) + aOrbiterE);
            aWandererF = aWandererF + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterI, 48U)) + aOrbiterG) + RotL64(aCarry, 29U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 47U) + aOrbiterF) + RotL64(aOrbiterJ, 43U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 6U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 35U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 27U));
            aCarry = aCarry + (RotL64(aWandererD, 11U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererA, 23U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 21165U)) & S_BLOCK1], 38U) ^ RotL64(mSource[((aIndex + 19509U)) & S_BLOCK1], 47U));
            aIngress ^= (RotL64(aFireLaneA[((aIndex + 20265U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19804U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 19896U)) & W_KEY1], 35U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 21313U)) & W_KEY1], 57U));
            aCross ^= (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 19753U)) & S_BLOCK1], 26U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 21597U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 53U) + RotL64(aIngress, 27U)) ^ (RotL64(aCross, 3U) ^ RotL64(aPrevious, 40U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterC = (aWandererG + RotL64(aScatter, 56U)) + 6973892330986118220U;
            aOrbiterD = ((aWandererK + RotL64(aPrevious, 35U)) + RotL64(aCarry, 21U)) + 9886813896272094864U;
            aOrbiterG = (aWandererH + RotL64(aCross, 27U)) + 10996306582517553173U;
            aOrbiterH = (((aWandererA + RotL64(aIngress, 19U)) + RotL64(aCarry, 5U)) + 8490648283899856223U) + aPhaseCOrbiterAssignSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterF = (aWandererD + RotL64(aScatter, 39U)) + 105141713530704655U;
            aOrbiterB = (aWandererJ + RotL64(aPrevious, 43U)) + 3114337422810562588U;
            aOrbiterK = ((aWandererF + RotL64(aCross, 60U)) + RotL64(aCarry, 35U)) + 980857684690886131U;
            aOrbiterI = ((aWandererC + RotL64(aIngress, 47U)) + 6562042345807072665U) + aPhaseCOrbiterAssignSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = (aWandererB + RotL64(aScatter, 3U)) + 15665371138706353619U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 18113013571374375028U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 17405346422601997299U;
            aOrbiterG = RotL64((aOrbiterG * 11162604605443005253U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 5130876096426182506U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 1813821672299154629U;
            aOrbiterC = RotL64((aOrbiterC * 15478100342425611875U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 15793814882743306728U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 13925299440495476399U;
            aOrbiterH = RotL64((aOrbiterH * 12049601510660117401U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 9924458846049579438U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 7810034662781768090U;
            aOrbiterD = RotL64((aOrbiterD * 10310594595026622513U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 12812586478656872854U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 5709576448057435237U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 9101555233909853025U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 7839807649914541516U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 4717944526755429647U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 8515229146471335721U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 3933911971504256022U) + aPhaseCOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 4814079680865379831U;
            aOrbiterF = RotL64((aOrbiterF * 15100740696230557391U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 18352577312212175569U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 9670612998448920742U) ^ aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5743579439303300553U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 72737302703035726U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 10032869372369626210U;
            aOrbiterK = RotL64((aOrbiterK * 7449905669249993731U), 47U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterK, 27U);
            aIngress = aIngress + (RotL64(aOrbiterD, 5U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 13U));
            aIngress = aIngress + (RotL64(aOrbiterB, 43U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterE, 30U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 60U) + RotL64(aOrbiterB, 23U)) + aOrbiterI);
            aWandererA = aWandererA + ((((RotL64(aScatter, 23U) + RotL64(aOrbiterG, 5U)) + aOrbiterE) + RotL64(aCarry, 11U)) + aPhaseCWandererUpdateSaltB[((aIndex + 26U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 19U) + aOrbiterD) + RotL64(aOrbiterC, 39U)) + aPhaseCWandererUpdateSaltA[((aIndex + 5U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aCross, 35U) + aOrbiterH) + RotL64(aOrbiterF, 28U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterK, 43U)) + aOrbiterE);
            aWandererF = aWandererF + (((RotL64(aIngress, 43U) + RotL64(aOrbiterE, 57U)) + aOrbiterC) + RotL64(aCarry, 29U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 12U) + aOrbiterC) + RotL64(aOrbiterH, 13U));
            aWandererD = aWandererD + ((RotL64(aCross, 47U) + aOrbiterE) + RotL64(aOrbiterI, 35U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 5U) + aOrbiterC) + RotL64(aOrbiterI, 18U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 48U));
            aCarry = aCarry + (RotL64(aWandererG, 19U) ^ aWandererB);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 23U));
            aCarry = aCarry + (RotL64(aWandererH, 5U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererF, 43U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 23160U)) & S_BLOCK1], 56U) ^ RotL64(aKeyRowReadA[((aIndex + 24344U)) & W_KEY1], 13U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 23405U)) & W_KEY1], 3U) ^ RotL64(aFireLaneC[((aIndex + 22807U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 22097U)) & S_BLOCK1], 47U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 21861U)) & S_BLOCK1], 35U));
            aCross ^= (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 23838U)) & S_BLOCK1], 4U) ^ RotL64(aInvestLaneB[((aIndex + 23196U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 41U) ^ RotL64(aIngress, 13U)) ^ (RotL64(aCarry, 54U) + RotL64(aPrevious, 27U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterK = (aWandererD + RotL64(aScatter, 5U)) + 13714409587461539863U;
            aOrbiterJ = (aWandererB + RotL64(aPrevious, 29U)) + 14101156723903265839U;
            aOrbiterH = ((aWandererH + RotL64(aCross, 13U)) + 7063754562895369001U) + aPhaseCOrbiterAssignSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterD = (aWandererF + RotL64(aIngress, 58U)) + 12320578575245519386U;
            aOrbiterA = (aWandererG + RotL64(aPrevious, 19U)) + 11744826789631008424U;
            aOrbiterE = ((aWandererE + RotL64(aCross, 47U)) + RotL64(aCarry, 39U)) + 8744816505096675597U;
            aOrbiterF = (((aWandererJ + RotL64(aScatter, 43U)) + RotL64(aCarry, 13U)) + 10405435520084528645U) + aPhaseCOrbiterAssignSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = (aWandererA + RotL64(aIngress, 52U)) + 1463157688070683543U;
            aOrbiterG = ((aWandererI + RotL64(aPrevious, 35U)) + RotL64(aCarry, 53U)) + 12379603577919617703U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 1343439118031348146U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 16118850268070235540U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 11184386483735388257U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 14116264435819277136U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 5251698273012432109U;
            aOrbiterK = RotL64((aOrbiterK * 1495818611622063967U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 14806408656041403829U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 11569345414052398227U;
            aOrbiterF = RotL64((aOrbiterF * 9913158908301414861U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 17063874769147888574U) + aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 9927420478679581917U;
            aOrbiterE = RotL64((aOrbiterE * 9042782809534196563U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 2550285599827162167U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 17801534123304996448U;
            aOrbiterD = RotL64((aOrbiterD * 2160836889363614721U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 6456685241021762041U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 17064208177372969289U;
            aOrbiterA = RotL64((aOrbiterA * 13726627607233302493U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 18279938244131982650U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 8211002229712129419U;
            aOrbiterG = RotL64((aOrbiterG * 12931373380977640645U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 12795832560781931767U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 286378504074349650U;
            aOrbiterC = RotL64((aOrbiterC * 85453101173293509U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 5835304250436889513U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 12704972686724379659U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 1198789639656336053U), 27U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterE, 51U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 24U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 47U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 29U));
            aIngress = aIngress + RotL64(aOrbiterD, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 24U) + RotL64(aOrbiterF, 18U)) + aOrbiterG) + aPhaseCWandererUpdateSaltD[((aIndex + 3U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aIngress, 53U) + aOrbiterJ) + RotL64(aOrbiterA, 23U)) + RotL64(aCarry, 13U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 29U) + aOrbiterD) + RotL64(aOrbiterK, 3U));
            aWandererB = aWandererB + (((RotL64(aCross, 19U) + RotL64(aOrbiterE, 35U)) + aOrbiterF) + aPhaseCWandererUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 48U) + aOrbiterG) + RotL64(aOrbiterC, 51U));
            aWandererE = aWandererE + ((RotL64(aIngress, 13U) + RotL64(aOrbiterA, 46U)) + aOrbiterK);
            aWandererF = aWandererF ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterA, 27U)) + aOrbiterH);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 39U) + RotL64(aOrbiterC, 13U)) + aOrbiterH) + RotL64(aCarry, 35U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterG, 41U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 21U) ^ aWandererF);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 50U));
            aCarry = aCarry + (RotL64(aWandererG, 53U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererI, 29U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererA, 5U);
            aCarry = aCarry + RotL64(aIngress, 26U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 25967U)) & S_BLOCK1], 11U) ^ RotL64(aKeyRowReadA[((aIndex + 27274U)) & W_KEY1], 23U));
            aIngress ^= (RotL64(aFireLaneD[((aIndex + 26840U)) & S_BLOCK1], 47U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 27133U)) & S_BLOCK1], 38U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 24926U)) & W_KEY1], 58U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 26034U)) & S_BLOCK1], 21U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 25283U)) & S_BLOCK1], 5U) ^ RotL64(aInvestLaneB[((aIndex + 25866U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 29U) + RotL64(aIngress, 13U)) + (RotL64(aCross, 42U) ^ RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterK = ((aWandererG + RotL64(aIngress, 58U)) + 9041099828460168106U) + aPhaseDOrbiterAssignSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = (aWandererK + RotL64(aCross, 35U)) + 12883711604096848454U;
            aOrbiterC = ((aWandererF + RotL64(aPrevious, 19U)) + RotL64(aCarry, 3U)) + 17420968786226443079U;
            aOrbiterG = ((aWandererD + RotL64(aScatter, 13U)) + 3448213891716125104U) + aPhaseDOrbiterAssignSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = (aWandererC + RotL64(aIngress, 27U)) + 11866455977445336560U;
            aOrbiterD = ((aWandererB + RotL64(aScatter, 23U)) + RotL64(aCarry, 23U)) + 4119356835384495905U;
            aOrbiterJ = (aWandererE + RotL64(aCross, 54U)) + 2186212599698637068U;
            aOrbiterB = (aWandererA + RotL64(aPrevious, 47U)) + 6506144898969301620U;
            aOrbiterA = ((aWandererH + RotL64(aCross, 3U)) + RotL64(aCarry, 51U)) + 12556800923644051626U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 4075551535185182945U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 17877694808492008749U;
            aOrbiterC = RotL64((aOrbiterC * 901315308379887473U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 5553428900598223316U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 14362304852277160675U;
            aOrbiterH = RotL64((aOrbiterH * 11415103199856419303U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 9174200302876075831U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 16110739511917638547U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 7004356839428657949U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 10189881974519849402U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 2128076632642616677U;
            aOrbiterG = RotL64((aOrbiterG * 8860453653433114929U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 18133523799074400083U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 9916472958834153766U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3454601168808001733U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 10274457562795569227U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 14134814273275356425U;
            aOrbiterB = RotL64((aOrbiterB * 15912501063665343159U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 6394306369514735480U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 4825761192736485643U;
            aOrbiterK = RotL64((aOrbiterK * 12534544147331805643U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 5672807934779206275U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 3881953574159390421U;
            aOrbiterD = RotL64((aOrbiterD * 7448770570912161095U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 12012232712634303203U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 14176392925893052596U;
            aOrbiterF = RotL64((aOrbiterF * 11288668529893084583U), 11U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterB, 47U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 50U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 3U));
            aIngress = aIngress + (RotL64(aOrbiterG, 57U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterD, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterD, 39U)) + aOrbiterJ);
            aWandererC = aWandererC + ((RotL64(aIngress, 13U) + RotL64(aOrbiterC, 19U)) + aOrbiterG);
            aWandererK = aWandererK ^ ((RotL64(aCross, 26U) + aOrbiterK) + RotL64(aOrbiterG, 52U));
            aWandererG = aWandererG + (((RotL64(aScatter, 3U) + RotL64(aOrbiterB, 11U)) + aOrbiterF) + RotL64(aCarry, 47U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterA, 35U)) + aOrbiterB);
            aWandererB = aWandererB + (((RotL64(aScatter, 43U) + aOrbiterK) + RotL64(aOrbiterD, 47U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aCross, 51U) + aOrbiterH) + RotL64(aOrbiterB, 30U)) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 60U) + aOrbiterC) + RotL64(aOrbiterK, 5U)) + RotL64(aCarry, 57U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterF, 43U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 19U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 56U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 5U));
            aCarry = aCarry + (RotL64(aWandererA, 29U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererF, 39U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 28493U)) & S_BLOCK1], 37U) ^ RotL64(aFireLaneD[((aIndex + 29875U)) & S_BLOCK1], 11U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 28837U)) & W_KEY1], 27U) ^ RotL64(aFireLaneC[((aIndex + 28555U)) & S_BLOCK1], 52U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 27718U)) & W_KEY1], 34U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 29065U)) & S_BLOCK1], 11U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27479U)) & S_BLOCK1], 21U) ^ RotL64(aFireLaneB[((aIndex + 27342U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 53U) + RotL64(aCross, 41U)) ^ (RotL64(aIngress, 3U) + RotL64(aCarry, 26U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterG = ((aWandererC + RotL64(aPrevious, 11U)) + 10812151398716051703U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterF = ((aWandererI + RotL64(aCross, 60U)) + RotL64(aCarry, 39U)) + 18202551453336003710U;
            aOrbiterH = (aWandererD + RotL64(aScatter, 19U)) + 9434410809101973752U;
            aOrbiterK = (aWandererF + RotL64(aIngress, 23U)) + 12955829998028534045U;
            aOrbiterA = (aWandererH + RotL64(aScatter, 47U)) + 12271740641929640181U;
            aOrbiterE = (aWandererA + RotL64(aPrevious, 52U)) + 14009351527014534752U;
            aOrbiterI = ((aWandererB + RotL64(aCross, 3U)) + 4316296955679133450U) + aPhaseDOrbiterAssignSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterD = ((aWandererK + RotL64(aIngress, 35U)) + RotL64(aCarry, 47U)) + 16473324966997442872U;
            aOrbiterJ = ((aWandererJ + RotL64(aPrevious, 39U)) + RotL64(aCarry, 21U)) + 15735123324965019802U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 17656375090484080236U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 16066325053456055298U;
            aOrbiterH = RotL64((aOrbiterH * 17912970706985130327U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 12908968778503516903U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 12761433987676836197U;
            aOrbiterA = RotL64((aOrbiterA * 1023329467480907925U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 12737513138040664509U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 14535795767570998392U;
            aOrbiterI = RotL64((aOrbiterI * 15560519667062222269U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 14370908061811284364U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 7001358781208669795U;
            aOrbiterD = RotL64((aOrbiterD * 11641248025734015835U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 7298578161120090849U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 10498302152357484629U;
            aOrbiterG = RotL64((aOrbiterG * 13144110412179037175U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 11447343228638006767U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 18284143620422655675U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 572862190073605651U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 5918253208127360199U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 3910541329178205943U;
            aOrbiterE = RotL64((aOrbiterE * 4550654545328228103U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 10357053096941367910U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 5610891501128498748U;
            aOrbiterJ = RotL64((aOrbiterJ * 8676370811772047449U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 9049881176058575811U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 6307599924966452216U;
            aOrbiterK = RotL64((aOrbiterK * 5551444450572055895U), 21U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterJ, 56U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 35U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 47U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 39U));
            aIngress = aIngress + RotL64(aOrbiterG, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterD, 29U)) + aOrbiterA);
            aWandererF = aWandererF + (((RotL64(aPrevious, 53U) + aOrbiterJ) + RotL64(aOrbiterK, 19U)) + RotL64(aCarry, 5U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 60U) + RotL64(aOrbiterG, 3U)) + aOrbiterF);
            aWandererC = aWandererC + (((RotL64(aCross, 27U) + RotL64(aOrbiterG, 42U)) + aOrbiterE) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 23U) + aOrbiterJ) + RotL64(aOrbiterD, 13U)) + aPhaseDWandererUpdateSaltA[((aIndex + 11U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aIngress, 39U) + RotL64(aOrbiterJ, 35U)) + aOrbiterI) + RotL64(aCarry, 57U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 12U) + RotL64(aOrbiterE, 23U)) + aOrbiterA);
            aWandererK = aWandererK + ((RotL64(aCross, 3U) + RotL64(aOrbiterG, 56U)) + aOrbiterH);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterH, 51U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererB, 3U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererI, 53U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererA, 14U) ^ aWandererK);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 39U));
            aCarry = aCarry + RotL64(aWandererH, 29U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 32371U)) & S_BLOCK1], 12U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 30528U)) & W_KEY1], 27U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 30292U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31056U)) & S_BLOCK1], 47U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32028U)) & S_BLOCK1], 36U) ^ RotL64(aKeyRowReadB[((aIndex + 30900U)) & W_KEY1], 3U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 51U) ^ RotL64(aIngress, 27U)) + (RotL64(aCross, 12U) ^ RotL64(aPrevious, 39U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterC = (((aWandererG + RotL64(aIngress, 52U)) + RotL64(aCarry, 43U)) + 9630214189402543339U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterD = ((aWandererE + RotL64(aScatter, 3U)) + 4072576573737526819U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = (aWandererH + RotL64(aCross, 47U)) + 15994787452709618869U;
            aOrbiterA = ((aWandererC + RotL64(aPrevious, 37U)) + RotL64(aCarry, 51U)) + 6403240137132259482U;
            aOrbiterB = ((aWandererJ + RotL64(aScatter, 29U)) + RotL64(aCarry, 5U)) + 10229266900170507720U;
            aOrbiterH = (aWandererA + RotL64(aPrevious, 23U)) + 5025294577989748989U;
            aOrbiterE = (aWandererD + RotL64(aIngress, 56U)) + 16696461238217956883U;
            aOrbiterK = (aWandererK + RotL64(aCross, 13U)) + 9878318855341719119U;
            aOrbiterJ = (aWandererF + RotL64(aScatter, 43U)) + 16086635438116177346U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 12295437783084203730U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 7681150419912842402U;
            aOrbiterI = RotL64((aOrbiterI * 7289497379725191451U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 2639104034287637448U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 12298170009332243573U;
            aOrbiterH = RotL64((aOrbiterH * 9397919591171238575U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 3485932317267669626U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 16569551670038752475U;
            aOrbiterD = RotL64((aOrbiterD * 8139802826402217631U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 4448490103784103954U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 14510534073046885941U;
            aOrbiterJ = RotL64((aOrbiterJ * 7777192047386438305U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 4286195398675733451U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 15790355933840266463U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 13342257823027075501U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 6362891510370156055U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 15121822034579983174U;
            aOrbiterC = RotL64((aOrbiterC * 7268045994574844937U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 13817341015719915628U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 14113474087906143783U;
            aOrbiterK = RotL64((aOrbiterK * 12838910141533126059U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 9988301252236121106U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 11287477288382171758U;
            aOrbiterE = RotL64((aOrbiterE * 4979297247881426383U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 9491727010910328644U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 7961202721830514030U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 16300364540313620767U), 37U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterC, 6U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 35U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 47U));
            aIngress = aIngress + (RotL64(aOrbiterI, 43U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterK, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 43U) + aOrbiterK) + RotL64(aOrbiterH, 53U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 19U) + aOrbiterI) + RotL64(aOrbiterB, 36U)) + aPhaseDWandererUpdateSaltA[((aIndex + 11U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 51U) + aOrbiterI) + RotL64(aOrbiterD, 41U));
            aWandererF = aWandererF + (((RotL64(aScatter, 60U) + aOrbiterJ) + RotL64(aOrbiterC, 13U)) + RotL64(aCarry, 19U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 27U) + aOrbiterK) + RotL64(aOrbiterE, 21U));
            aWandererE = aWandererE + (((RotL64(aScatter, 11U) + aOrbiterD) + RotL64(aOrbiterA, 47U)) + aPhaseDWandererUpdateSaltF[((aIndex + 13U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterK, 30U)) + aOrbiterB);
            aWandererH = aWandererH + (((RotL64(aCross, 3U) + aOrbiterJ) + RotL64(aOrbiterI, 5U)) + RotL64(aCarry, 11U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 34U) + RotL64(aOrbiterH, 57U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 23U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 41U));
            aCarry = aCarry + (RotL64(aWandererE, 20U) ^ aWandererG);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 11U));
            aCarry = aCarry + RotL64(aWandererC, 51U);
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
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneD, aExpandLaneC, aExpandLaneD, aInvestLaneC, aFireLaneA, aInvestLaneD, aFireLaneC, aOperationLaneA, aFireLaneB, aOperationLaneB, aOperationLaneC
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 1467U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneB[((aIndex + 2687U)) & S_BLOCK1], 46U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 4255U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 1347U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 4975U)) & S_BLOCK1], 18U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 35U) + RotL64(aIngress, 57U)) ^ (RotL64(aPrevious, 23U) ^ RotL64(aCross, 6U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterG = (aWandererA + RotL64(aIngress, 29U)) + 8604208734152026945U;
            aOrbiterK = (aWandererG + RotL64(aScatter, 21U)) + 1374329953253889829U;
            aOrbiterA = (((aWandererB + RotL64(aCross, 43U)) + RotL64(aCarry, 21U)) + 5779278910548228339U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = ((aWandererD + RotL64(aPrevious, 5U)) + RotL64(aCarry, 37U)) + 17670451230882805140U;
            aOrbiterE = ((aWandererH + RotL64(aCross, 11U)) + 8193848740764866860U) + aPhaseEOrbiterAssignSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterH = (aWandererE + RotL64(aScatter, 52U)) + 15801168428145650104U;
            aOrbiterJ = ((aWandererF + RotL64(aIngress, 37U)) + RotL64(aCarry, 53U)) + 2584718176087499066U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 14950366247822737997U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 9779293225265670135U;
            aOrbiterA = RotL64((aOrbiterA * 11625969538497982117U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 8688968319288372383U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 13665723186950342601U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 292035540396910837U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 9395428688359973510U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 2152719218018108418U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 15271961483518392671U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 1350324137411377992U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 8729317951386057921U;
            aOrbiterB = RotL64((aOrbiterB * 6008790836417785083U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 6317310451893678411U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 10175620379041384281U;
            aOrbiterG = RotL64((aOrbiterG * 14079679617394330781U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 1203082119358827708U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 523869107818193101U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4629501113595689157U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 4028324959540432983U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 15447631947468213912U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 6037306615787729185U), 27U);
            //
            aIngress = RotL64(aOrbiterA, 41U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterG, 51U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterJ, 35U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterH, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aPrevious, 39U) + RotL64(aOrbiterG, 41U)) + aOrbiterE) + aPhaseEWandererUpdateSaltD[((aIndex + 7U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 47U) + aOrbiterK) + RotL64(aOrbiterH, 57U));
            aWandererB = aWandererB + ((((RotL64(aIngress, 19U) + RotL64(aOrbiterB, 3U)) + aOrbiterH) + RotL64(aCarry, 13U)) + aPhaseEWandererUpdateSaltC[((aIndex + 11U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterH, 51U)) + aOrbiterE);
            aWandererD = aWandererD + (((RotL64(aPrevious, 54U) + aOrbiterH) + RotL64(aOrbiterA, 11U)) + RotL64(aCarry, 35U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 27U) + aOrbiterJ) + RotL64(aOrbiterG, 27U));
            aWandererF = aWandererF + ((RotL64(aIngress, 13U) + aOrbiterH) + RotL64(aOrbiterG, 18U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 34U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererF, 39U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererH, 23U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererA, 43U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aInvestLaneC[((aIndex + 10765U)) & S_BLOCK1], 18U) ^ RotL64(aExpandLaneC[((aIndex + 10333U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 10200U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 6012U)) & S_BLOCK1], 46U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 8274U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 11U) + RotL64(aPrevious, 27U)) ^ (RotL64(aCarry, 39U) ^ RotL64(aIngress, 60U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterF = (aWandererJ + RotL64(aIngress, 28U)) + 18302975933754610273U;
            aOrbiterJ = ((aWandererK + RotL64(aCross, 47U)) + RotL64(aCarry, 5U)) + 16736972646771456082U;
            aOrbiterD = (aWandererH + RotL64(aPrevious, 57U)) + 17389406266488137442U;
            aOrbiterB = ((aWandererB + RotL64(aScatter, 35U)) + RotL64(aCarry, 21U)) + 5252511566486165539U;
            aOrbiterC = (aWandererC + RotL64(aCross, 5U)) + 5730715427422747640U;
            aOrbiterG = (((aWandererI + RotL64(aIngress, 11U)) + RotL64(aCarry, 47U)) + 6412695646456045825U) + aPhaseEOrbiterAssignSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = ((aWandererF + RotL64(aScatter, 21U)) + 9539701605708994494U) + aPhaseEOrbiterAssignSaltC[((aIndex + 24U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 18355107116412945722U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 11735742491750132942U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 18129835093627763685U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 12363819388562658842U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 5861430292304371543U;
            aOrbiterC = RotL64((aOrbiterC * 12989055611235382695U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 15027487084595017708U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 7012850020745791926U;
            aOrbiterJ = RotL64((aOrbiterJ * 15952928839355613939U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 11904871669287886120U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 11199760114477343208U;
            aOrbiterB = RotL64((aOrbiterB * 7156374911847525867U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 3856004502263742700U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 3705931243173921893U;
            aOrbiterF = RotL64((aOrbiterF * 10334871178498711485U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 12305785390539209389U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 18057980996551978823U;
            aOrbiterG = RotL64((aOrbiterG * 4850564181113470859U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 3229431819292153014U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 2994716629242460094U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 1029427328395257917U), 57U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterC, 57U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 20U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 5U));
            aIngress = aIngress + RotL64(aOrbiterG, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterC, 23U)) + aOrbiterF) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 3U) + aOrbiterC) + RotL64(aOrbiterA, 35U));
            aWandererI = aWandererI + ((((RotL64(aCross, 35U) + aOrbiterF) + RotL64(aOrbiterJ, 5U)) + RotL64(aCarry, 51U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 23U) + aOrbiterA) + RotL64(aOrbiterG, 51U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterB, 12U)) + aOrbiterD) + RotL64(aCarry, 5U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 10U) + RotL64(aOrbiterJ, 29U)) + aOrbiterB);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 47U) + aOrbiterJ) + RotL64(aOrbiterA, 57U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 39U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererH, 52U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererK, 35U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererJ, 47U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aInvestLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_b loop 3
        // ingress from: aInvestLaneD, aExpandLaneD, aFireLaneC
        // ingress directions: aInvestLaneD forward forced, aExpandLaneD forward forced, aFireLaneC forward/backward random
        // cross from: aInvestLaneC, aExpandLaneB, aExpandLaneA
        // cross directions: aInvestLaneC backward forced, aExpandLaneB backward forced, aExpandLaneA backward/forward random
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneD[((aIndex + 15664U)) & S_BLOCK1], 26U) ^ RotL64(aExpandLaneD[((aIndex + 13102U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 12389U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 11739U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 12080U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 14641U)) & S_BLOCK1], 12U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 3U) ^ RotL64(aCarry, 40U)) ^ (RotL64(aCross, 21U) + RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterE = ((aWandererA + RotL64(aCross, 3U)) + RotL64(aCarry, 39U)) + 4970414922752555648U;
            aOrbiterK = (((aWandererE + RotL64(aIngress, 11U)) + RotL64(aCarry, 23U)) + 9462756592787669327U) + aPhaseEOrbiterAssignSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = (aWandererC + RotL64(aScatter, 37U)) + 3948790686662213095U;
            aOrbiterF = ((aWandererB + RotL64(aPrevious, 43U)) + RotL64(aCarry, 5U)) + 14542857212241578311U;
            aOrbiterA = (aWandererK + RotL64(aIngress, 19U)) + 3387479009827029547U;
            aOrbiterI = (aWandererG + RotL64(aCross, 53U)) + 1411421370057797877U;
            aOrbiterG = ((aWandererH + RotL64(aScatter, 28U)) + 16894451466895681236U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 12727136462290223542U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 4625389198191960525U;
            aOrbiterC = RotL64((aOrbiterC * 5726474430977810191U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 3471881403786164913U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 6433115856048534831U;
            aOrbiterI = RotL64((aOrbiterI * 9363233870194144053U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 9825592965466157982U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 1553125767261293088U;
            aOrbiterK = RotL64((aOrbiterK * 411535191177308781U), 27U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 9951616357109647617U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 11231080382787286889U;
            aOrbiterA = RotL64((aOrbiterA * 14024961994986659187U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 13419663264017317947U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 4835055642466215566U;
            aOrbiterF = RotL64((aOrbiterF * 17898065852351759171U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 14558747666410946768U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 13120938960926874504U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 5681766019285559739U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 11910501376797343986U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 15074100100781785300U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 228976960937473851U), 39U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterC, 11U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 58U));
            aIngress = aIngress + (RotL64(aOrbiterI, 23U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterG, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aPrevious, 23U) + aOrbiterC) + RotL64(aOrbiterE, 51U)) + RotL64(aCarry, 43U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterE, 13U)) + aOrbiterI) + aPhaseEWandererUpdateSaltA[((aIndex + 3U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aIngress, 51U) + aOrbiterK) + RotL64(aOrbiterE, 3U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 43U) + aOrbiterF) + RotL64(aOrbiterA, 28U));
            aWandererG = aWandererG + (((RotL64(aIngress, 12U) + aOrbiterG) + RotL64(aOrbiterA, 19U)) + RotL64(aCarry, 23U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 37U) + aOrbiterI) + RotL64(aOrbiterA, 43U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aScatter, 29U) + aOrbiterK) + RotL64(aOrbiterF, 35U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 36U) ^ aWandererH);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 27U));
            aCarry = aCarry + (RotL64(aWandererE, 43U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererB, 47U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 16720U)) & S_BLOCK1], 12U) ^ RotL64(aInvestLaneC[((aIndex + 21805U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 20504U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 19067U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 19158U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 17778U)) & S_BLOCK1], 60U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 53U) ^ RotL64(aCarry, 35U)) ^ (RotL64(aCross, 3U) + RotL64(aPrevious, 18U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = (aWandererK + RotL64(aCross, 11U)) + 13915875634607599122U;
            aOrbiterG = (aWandererE + RotL64(aScatter, 57U)) + 1695770381382411673U;
            aOrbiterF = ((aWandererG + RotL64(aPrevious, 5U)) + RotL64(aCarry, 35U)) + 3709105579778295511U;
            aOrbiterK = (aWandererC + RotL64(aIngress, 39U)) + 7673376335333251804U;
            aOrbiterB = ((aWandererB + RotL64(aCross, 30U)) + 8814147709738503518U) + aPhaseEOrbiterAssignSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = ((aWandererI + RotL64(aIngress, 19U)) + RotL64(aCarry, 19U)) + 13451412605350381172U;
            aOrbiterH = (((aWandererD + RotL64(aScatter, 47U)) + RotL64(aCarry, 3U)) + 6447870234069609538U) + aPhaseEOrbiterAssignSaltD[((aIndex + 15U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 13419487997946496825U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 5478309847615220345U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 12953043149543448765U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 3635184969215610049U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 12527903812035294828U;
            aOrbiterG = RotL64((aOrbiterG * 12540800512035534967U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 1684685110885338814U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 12860354576326835090U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 12743745087733307255U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 9081823570147481835U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 14369321778210049109U;
            aOrbiterD = RotL64((aOrbiterD * 17865953349448767035U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 11518132079084873250U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 11893535026126957389U;
            aOrbiterB = RotL64((aOrbiterB * 15751374986135615095U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 7084079180579206226U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 2999676609847603277U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 14602698397511266403U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 17683445810614029153U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 11576460512964896969U;
            aOrbiterA = RotL64((aOrbiterA * 5243651036457051155U), 29U);
            //
            aIngress = RotL64(aOrbiterA, 35U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterG, 13U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterB, 58U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterH, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aCross, 47U) + aOrbiterD) + RotL64(aOrbiterG, 29U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterK, 6U)) + aOrbiterD) + RotL64(aCarry, 47U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 41U) + aOrbiterK) + RotL64(aOrbiterG, 43U));
            aWandererI = aWandererI + ((RotL64(aIngress, 54U) + aOrbiterH) + RotL64(aOrbiterF, 19U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 19U) + aOrbiterK) + RotL64(aOrbiterA, 57U));
            aWandererK = aWandererK + (((RotL64(aCross, 3U) + aOrbiterD) + RotL64(aOrbiterB, 51U)) + RotL64(aCarry, 35U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 27U) + RotL64(aOrbiterH, 37U)) + aOrbiterB) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 43U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererE, 27U) ^ aWandererI);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 36U));
            aCarry = aCarry + RotL64(aWandererB, 5U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 22108U)) & S_BLOCK1], 36U) ^ RotL64(aOperationLaneA[((aIndex + 25035U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 26868U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 23656U)) & S_BLOCK1], 53U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 22901U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aInvestLaneD[((aIndex + 25801U)) & S_BLOCK1], 14U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 3U) ^ RotL64(aCarry, 50U)) + (RotL64(aIngress, 19U) + RotL64(aCross, 37U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterB = ((aWandererE + RotL64(aPrevious, 60U)) + 15036852811491820366U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterJ = ((aWandererH + RotL64(aIngress, 3U)) + 305637140752898475U) + aPhaseEOrbiterAssignSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = (aWandererI + RotL64(aScatter, 39U)) + 11948631574496129610U;
            aOrbiterH = ((aWandererJ + RotL64(aCross, 11U)) + RotL64(aCarry, 53U)) + 5321623592482991426U;
            aOrbiterD = ((aWandererG + RotL64(aIngress, 51U)) + RotL64(aCarry, 29U)) + 4075270159062690728U;
            aOrbiterA = (aWandererK + RotL64(aCross, 29U)) + 15111580500356908928U;
            aOrbiterC = ((aWandererA + RotL64(aScatter, 21U)) + RotL64(aCarry, 5U)) + 7244150695504160363U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 5131563519577488862U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 5881954992088651371U;
            aOrbiterE = RotL64((aOrbiterE * 2424421828597294607U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 12780935808751507998U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 12599159643925470226U;
            aOrbiterD = RotL64((aOrbiterD * 17690046932587062701U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 9466589929741834066U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 6093158735705189789U;
            aOrbiterJ = RotL64((aOrbiterJ * 7453778295800853653U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 17461243886150519249U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 15456408913739900718U;
            aOrbiterB = RotL64((aOrbiterB * 16093292401746174671U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 11260643903290392780U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 7870342756041882616U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2431528656086173419U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 134484990005888936U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 10626896209992890407U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12034131076645285597U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 14031164129515132292U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 1771835705730244212U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 186981668443596623U), 19U);
            //
            aIngress = RotL64(aOrbiterE, 14U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterD, 5U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 53U));
            aIngress = aIngress + RotL64(aOrbiterA, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aCross, 29U) + aOrbiterE) + RotL64(aOrbiterB, 5U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 53U) + aOrbiterJ) + RotL64(aOrbiterD, 48U)) + RotL64(aCarry, 29U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 60U) + aOrbiterH) + RotL64(aOrbiterC, 35U));
            aWandererA = aWandererA + (((RotL64(aScatter, 47U) + aOrbiterH) + RotL64(aOrbiterD, 57U)) + aPhaseEWandererUpdateSaltE[((aIndex + 24U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 35U) + aOrbiterB) + RotL64(aOrbiterC, 29U));
            aWandererH = aWandererH + (((RotL64(aScatter, 21U) + aOrbiterB) + RotL64(aOrbiterD, 41U)) + RotL64(aCarry, 53U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterH, 19U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 4U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererH, 47U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererA, 27U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererG, 35U);
            aCarry = aCarry + RotL64(aIngress, 52U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 31362U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneA[((aIndex + 29280U)) & S_BLOCK1], 10U));
            aIngress ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30546U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 30403U)) & S_BLOCK1], 30U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 28665U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aInvestLaneD[((aIndex + 27584U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 24U) + RotL64(aPrevious, 41U)) ^ (RotL64(aCross, 3U) ^ RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterA = (aWandererC + RotL64(aScatter, 37U)) + 13053031069776604052U;
            aOrbiterC = (((aWandererA + RotL64(aPrevious, 21U)) + RotL64(aCarry, 13U)) + 1331396630251085122U) + aPhaseEOrbiterAssignSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterI = ((aWandererG + RotL64(aCross, 52U)) + RotL64(aCarry, 39U)) + 15879286043343942393U;
            aOrbiterB = (aWandererE + RotL64(aIngress, 27U)) + 13590365633321406830U;
            aOrbiterE = (aWandererD + RotL64(aCross, 3U)) + 14569235423040242618U;
            aOrbiterF = ((aWandererB + RotL64(aIngress, 43U)) + 11397370636618371560U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = ((aWandererH + RotL64(aScatter, 11U)) + RotL64(aCarry, 57U)) + 3455933494593971847U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 1307153376443784593U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 10688618762584786871U;
            aOrbiterI = RotL64((aOrbiterI * 9503823896874842411U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 17746248451153600096U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 8512568600755410158U;
            aOrbiterC = RotL64((aOrbiterC * 16648320170768234063U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 8950230550112591092U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 17790968369472845496U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5104988920132008913U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 12583323865381967534U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 11243927099685293887U;
            aOrbiterF = RotL64((aOrbiterF * 12867003042486433971U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 9690268715525781389U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 7466066217365074653U;
            aOrbiterB = RotL64((aOrbiterB * 17565696765505320889U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 3673528673209875118U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 14079103852360952255U;
            aOrbiterA = RotL64((aOrbiterA * 17449228863409999629U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 6747836856132250630U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 5027692924422297153U;
            aOrbiterE = RotL64((aOrbiterE * 2492421273167124437U), 35U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterH, 20U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 51U));
            aIngress = aIngress + (RotL64(aOrbiterC, 13U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterE, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aCross, 53U) + aOrbiterI) + RotL64(aOrbiterH, 20U)) + aPhaseEWandererUpdateSaltA[((aIndex + 5U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterC, 11U)) + aOrbiterB) + RotL64(aCarry, 53U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 6U) + RotL64(aOrbiterA, 51U)) + aOrbiterF);
            aWandererH = aWandererH + (((RotL64(aIngress, 13U) + RotL64(aOrbiterH, 41U)) + aOrbiterA) + RotL64(aCarry, 37U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterC, 5U)) + aOrbiterA);
            aWandererG = aWandererG + (((RotL64(aPrevious, 41U) + RotL64(aOrbiterB, 29U)) + aOrbiterE) + aPhaseEWandererUpdateSaltB[((aIndex + 21U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterC, 57U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 57U));
            aCarry = aCarry + (RotL64(aWandererH, 28U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererG, 39U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererD, 13U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
        // read from: aOperationLaneA, aOperationLaneB, aExpandLaneC, aOperationLaneC, aOperationLaneD, aExpandLaneB, aSnowLaneA, aExpandLaneA, aInvestLaneC, aSnowLaneB, aExpandLaneD, aWorkLaneA, aInvestLaneA, aWorkLaneB, aInvestLaneD, aWorkLaneC, aInvestLaneB
        // write to: aSnowLaneA, aSnowLaneB, aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // twist_loop_c loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aExpandLaneC
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aExpandLaneC forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aExpandLaneB
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aExpandLaneB backward/forward random
        // write to: aSnowLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 922U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneB[((aIndex + 1666U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aExpandLaneC[((aIndex + 5358U)) & S_BLOCK1], 48U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 1383U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 2032U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aExpandLaneB[((aIndex + 3983U)) & S_BLOCK1], 24U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 18U) + RotL64(aCross, 53U)) + (RotL64(aCarry, 35U) ^ RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterD = (aWandererI + RotL64(aIngress, 39U)) + 13278949403988203974U;
            aOrbiterF = ((aWandererA + RotL64(aPrevious, 53U)) + RotL64(aCarry, 19U)) + 9213599924054673756U;
            aOrbiterK = ((aWandererB + RotL64(aCross, 51U)) + RotL64(aCarry, 27U)) + 1255746482932381798U;
            aOrbiterH = (aWandererF + RotL64(aScatter, 21U)) + 11575321997144516122U;
            aOrbiterG = (aWandererD + RotL64(aCross, 23U)) + 15881587525529432437U;
            aOrbiterI = (aWandererG + RotL64(aPrevious, 26U)) + 9846195809864862707U;
            aOrbiterA = ((aWandererK + RotL64(aScatter, 19U)) + 12319815691858217670U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = ((aWandererJ + RotL64(aIngress, 13U)) + 16322617427294439587U) + aPhaseFOrbiterAssignSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterC = (aWandererC + RotL64(aScatter, 35U)) + 16332130810525887437U;
            aOrbiterB = ((aWandererE + RotL64(aIngress, 43U)) + RotL64(aCarry, 35U)) + 4920951156015336794U;
            aOrbiterE = (aWandererH + RotL64(aPrevious, 10U)) + 16767126455124552329U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 12553595911087945223U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 1437522202135436142U;
            aOrbiterK = RotL64((aOrbiterK * 2001992794165550905U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 12313100454852227143U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 2761983020631055729U;
            aOrbiterI = RotL64((aOrbiterI * 3874839760378039509U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 17635303588421554367U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 788212489507463763U;
            aOrbiterJ = RotL64((aOrbiterJ * 17896475584538528059U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 5192552894670654434U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 6784748488807738811U;
            aOrbiterC = RotL64((aOrbiterC * 8077237651953896479U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 16113417046719114943U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 1096874945215225916U;
            aOrbiterG = RotL64((aOrbiterG * 17308604412622879833U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 7610274704570171595U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 10466070212284342550U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 6449728258497920613U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 6777845928873855221U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 5251515022021984126U;
            aOrbiterH = RotL64((aOrbiterH * 9018277343404261611U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 13849343158824111498U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 7977711210181714021U;
            aOrbiterF = RotL64((aOrbiterF * 4182053966171053577U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 6494539818728106982U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 11314590450226080781U;
            aOrbiterB = RotL64((aOrbiterB * 12455979257225599157U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 552687702594328012U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 14961304171192292246U;
            aOrbiterA = RotL64((aOrbiterA * 846375892915484717U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 9771874402848476494U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 13278949403988203974U;
            aOrbiterE = RotL64((aOrbiterE * 2119203863777871233U), 47U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterD, 41U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 35U));
            aIngress = aIngress + (RotL64(aOrbiterA, 51U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterK, 11U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 24U));
            aIngress = aIngress + RotL64(aOrbiterI, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 19U) + aOrbiterD) + RotL64(aOrbiterC, 35U));
            aWandererE = aWandererE + ((RotL64(aIngress, 5U) + aOrbiterA) + RotL64(aOrbiterK, 23U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterE, 57U)) + aOrbiterI);
            aWandererK = aWandererK + (((RotL64(aCross, 10U) + RotL64(aOrbiterF, 37U)) + aOrbiterA) + aPhaseFWandererUpdateSaltA[((aIndex + 19U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 3U) + aOrbiterI) + RotL64(aOrbiterD, 52U));
            aWandererI = aWandererI + ((RotL64(aCross, 37U) + RotL64(aOrbiterI, 29U)) + aOrbiterK);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterH, 3U)) + aOrbiterB);
            aWandererH = aWandererH + (((RotL64(aIngress, 47U) + RotL64(aOrbiterE, 41U)) + aOrbiterH) + RotL64(aCarry, 57U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 27U) + aOrbiterG) + RotL64(aOrbiterD, 11U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 43U) + aOrbiterJ) + RotL64(aOrbiterE, 47U)) + RotL64(aCarry, 35U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 24U) + aOrbiterC) + RotL64(aOrbiterJ, 6U)) + aPhaseFWandererUpdateSaltC[((aIndex + 12U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 35U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererA, 19U) ^ aWandererH);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 41U));
            aCarry = aCarry + (RotL64(aWandererJ, 58U) ^ aWandererK);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 39U));
            aCarry = aCarry + RotL64(aWandererB, 23U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aSnowLaneA[((aIndex + 10889U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneC[((aIndex + 6392U)) & S_BLOCK1], 48U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 8396U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneA[((aIndex + 5510U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 10761U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 8543U)) & S_BLOCK1], 54U));
            aCross ^= RotL64(aInvestLaneC[((aIndex + 5592U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 51U) ^ RotL64(aPrevious, 3U)) ^ (RotL64(aIngress, 39U) + RotL64(aCross, 22U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterE = ((aWandererJ + RotL64(aCross, 57U)) + RotL64(aCarry, 3U)) + 17019646486641172469U;
            aOrbiterK = ((aWandererH + RotL64(aPrevious, 39U)) + 12276141179299971572U) + aPhaseFOrbiterAssignSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterD = (aWandererB + RotL64(aScatter, 47U)) + 3617241694029841555U;
            aOrbiterH = (aWandererF + RotL64(aIngress, 37U)) + 6967963401259371737U;
            aOrbiterA = (aWandererG + RotL64(aPrevious, 22U)) + 6340709284279891017U;
            aOrbiterI = (aWandererI + RotL64(aScatter, 41U)) + 456065368903896482U;
            aOrbiterG = (aWandererA + RotL64(aCross, 19U)) + 17686765719908116203U;
            aOrbiterF = (aWandererD + RotL64(aIngress, 3U)) + 1322045955429785736U;
            aOrbiterC = (aWandererE + RotL64(aCross, 51U)) + 5163772703302372887U;
            aOrbiterJ = ((aWandererC + RotL64(aPrevious, 44U)) + RotL64(aCarry, 47U)) + 13268431135020363252U;
            aOrbiterB = (((aWandererK + RotL64(aScatter, 35U)) + RotL64(aCarry, 13U)) + 6538789950366849332U) + aPhaseFOrbiterAssignSaltF[((aIndex + 18U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 10390344544314544893U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 5087084271300584267U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 15149302947570776165U), 37U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 13423071121590981727U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 18324443012024134729U;
            aOrbiterI = RotL64((aOrbiterI * 15814349432207734533U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 4129091815978464507U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 17024797553831962245U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 3137753479364378175U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 6501545108779991661U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 11930037791867597447U;
            aOrbiterK = RotL64((aOrbiterK * 4904739567549702851U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 4667298703308315851U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 6315980380900062127U;
            aOrbiterH = RotL64((aOrbiterH * 12080555704907924637U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 12732382340390769888U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 7792095326183864547U;
            aOrbiterB = RotL64((aOrbiterB * 12645556660611824631U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 17428384983571405782U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 3193205313177048443U;
            aOrbiterF = RotL64((aOrbiterF * 14488006565106259731U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 2813743367131107264U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 2742138679703780981U;
            aOrbiterG = RotL64((aOrbiterG * 18356569025783532225U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 6270291142961043031U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 3490174937775044998U;
            aOrbiterJ = RotL64((aOrbiterJ * 13879285210885619613U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 13182535825771438942U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 13047228760732694484U;
            aOrbiterC = RotL64((aOrbiterC * 10365428317468779549U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 17926326514553542739U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 17019646486641172469U;
            aOrbiterA = RotL64((aOrbiterA * 13978838314848228053U), 51U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterI, 39U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 5U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterK, 52U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterA, 11U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterC, 47U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterF, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aIngress, 21U) + aOrbiterI) + RotL64(aOrbiterB, 5U)) + aPhaseFWandererUpdateSaltE[((aIndex + 25U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aPrevious, 39U) + RotL64(aOrbiterK, 53U)) + aOrbiterB);
            aWandererD = aWandererD ^ ((RotL64(aCross, 37U) + aOrbiterF) + RotL64(aOrbiterJ, 57U));
            aWandererK = aWandererK + ((RotL64(aScatter, 57U) + aOrbiterD) + RotL64(aOrbiterE, 35U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 4U) + RotL64(aOrbiterC, 18U)) + aOrbiterA);
            aWandererC = aWandererC + ((RotL64(aScatter, 43U) + aOrbiterC) + RotL64(aOrbiterK, 11U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterC, 43U)) + aOrbiterH);
            aWandererF = aWandererF + (((RotL64(aIngress, 13U) + RotL64(aOrbiterG, 47U)) + aOrbiterJ) + RotL64(aCarry, 47U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 6U) + aOrbiterJ) + RotL64(aOrbiterI, 28U));
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 11U) + aOrbiterD) + RotL64(aOrbiterH, 51U)) + RotL64(aCarry, 53U)) + aPhaseFWandererUpdateSaltF[((aIndex + 3U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterD, 23U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererG, 41U) ^ aWandererC);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 4U));
            aCarry = aCarry + (RotL64(aWandererF, 21U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererI, 57U) ^ aWandererK);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 39U));
            aCarry = aCarry + RotL64(aWandererE, 52U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aSnowLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_c loop 3
        // ingress from: aSnowLaneB, aOperationLaneA, aExpandLaneD
        // ingress directions: aSnowLaneB forward forced, aOperationLaneA forward forced, aExpandLaneD forward/backward random
        // cross from: aSnowLaneA, aOperationLaneC
        // cross directions: aSnowLaneA backward forced, aOperationLaneC backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneB[((aIndex + 11091U)) & S_BLOCK1], 28U) ^ RotL64(aOperationLaneA[((aIndex + 13597U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 11633U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 15067U)) & S_BLOCK1], 18U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 12716U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 3U) ^ RotL64(aIngress, 18U)) + (RotL64(aPrevious, 41U) + RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterG = (aWandererE + RotL64(aIngress, 21U)) + 15904465836916519864U;
            aOrbiterI = ((aWandererD + RotL64(aCross, 39U)) + RotL64(aCarry, 29U)) + 17725629806317789307U;
            aOrbiterA = ((aWandererH + RotL64(aScatter, 3U)) + 13794170125914914828U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = ((aWandererG + RotL64(aPrevious, 46U)) + 2149055907476874332U) + aPhaseFOrbiterAssignSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = (aWandererF + RotL64(aScatter, 13U)) + 5342047776745074649U;
            aOrbiterE = (aWandererI + RotL64(aCross, 11U)) + 8268148484060546838U;
            aOrbiterJ = (aWandererJ + RotL64(aIngress, 19U)) + 10821151364028563719U;
            aOrbiterD = ((aWandererK + RotL64(aPrevious, 51U)) + RotL64(aCarry, 3U)) + 4294213820894407378U;
            aOrbiterB = (aWandererC + RotL64(aIngress, 43U)) + 10884726101307943090U;
            aOrbiterK = (aWandererB + RotL64(aPrevious, 54U)) + 16432210042202444824U;
            aOrbiterH = ((aWandererA + RotL64(aScatter, 29U)) + RotL64(aCarry, 37U)) + 15196602644336228055U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 14117787670220328165U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 219833877949480215U;
            aOrbiterA = RotL64((aOrbiterA * 10736293047771972173U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 3326396981881473962U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 14918513066311426279U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14269763278564574663U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 11795234681370163206U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 3068267285352664813U;
            aOrbiterF = RotL64((aOrbiterF * 15746255933920904619U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 245233356957999496U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 709926406353796673U;
            aOrbiterD = RotL64((aOrbiterD * 13627039596842073595U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 5378105439430271038U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 10114555061122044430U;
            aOrbiterB = RotL64((aOrbiterB * 5351295043424885549U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 13233010815716769713U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 8231291294833548389U;
            aOrbiterH = RotL64((aOrbiterH * 10840516135212753869U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 7160760224172419829U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 14767926435411546785U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 1643485739468851073U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 4464245330038080103U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 15778166658285494712U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 13980891936095282989U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 2426340576450960905U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 6030631392508241438U;
            aOrbiterI = RotL64((aOrbiterI * 13921288910299408423U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 15990180955119402476U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 8707879851984546959U;
            aOrbiterJ = RotL64((aOrbiterJ * 13794027045755532979U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 11665969506971636052U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 15904465836916519864U;
            aOrbiterK = RotL64((aOrbiterK * 17042355185093585101U), 47U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterF, 21U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 37U));
            aIngress = aIngress + (RotL64(aOrbiterB, 41U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 56U));
            aIngress = aIngress + (RotL64(aOrbiterI, 27U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterK, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aCross, 11U) + aOrbiterK) + RotL64(aOrbiterF, 39U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aIngress, 4U) + aOrbiterA) + RotL64(aOrbiterK, 51U)) + RotL64(aCarry, 29U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterJ, 4U)) + aOrbiterB);
            aWandererA = aWandererA + ((RotL64(aPrevious, 35U) + RotL64(aOrbiterK, 19U)) + aOrbiterJ);
            aWandererF = aWandererF ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterD, 57U)) + aOrbiterG);
            aWandererB = aWandererB + ((RotL64(aIngress, 53U) + RotL64(aOrbiterG, 23U)) + aOrbiterF);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterE, 41U)) + aOrbiterH);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 23U) + RotL64(aOrbiterI, 11U)) + aOrbiterC);
            aWandererC = aWandererC ^ ((RotL64(aCross, 30U) + RotL64(aOrbiterB, 21U)) + aOrbiterE);
            aWandererI = aWandererI + (((RotL64(aScatter, 19U) + RotL64(aOrbiterB, 47U)) + aOrbiterC) + RotL64(aCarry, 3U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 13U) + aOrbiterI) + RotL64(aOrbiterJ, 60U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 29U));
            aCarry = aCarry + (RotL64(aWandererE, 60U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererA, 23U) ^ aWandererB);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 53U));
            aCarry = aCarry + (RotL64(aWandererK, 35U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererJ, 21U);
            aCarry = aCarry + RotL64(aIngress, 18U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_c loop 4
        // ingress from: aWorkLaneA, aSnowLaneA, aInvestLaneA
        // ingress directions: aWorkLaneA forward forced, aSnowLaneA forward forced, aInvestLaneA forward/backward random
        // cross from: aSnowLaneB, aOperationLaneD
        // cross directions: aSnowLaneB backward forced, aOperationLaneD backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 19017U)) & S_BLOCK1], 43U) ^ RotL64(aSnowLaneA[((aIndex + 17595U)) & S_BLOCK1], 26U));
            aIngress ^= RotL64(aInvestLaneA[((aIndex + 17547U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 21641U)) & S_BLOCK1], 18U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 16805U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 34U) ^ RotL64(aPrevious, 3U)) ^ (RotL64(aCarry, 21U) + RotL64(aIngress, 47U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterE = ((aWandererF + RotL64(aScatter, 35U)) + RotL64(aCarry, 27U)) + 12615321415808640429U;
            aOrbiterJ = (aWandererD + RotL64(aPrevious, 3U)) + 15712784676459931207U;
            aOrbiterF = (aWandererG + RotL64(aIngress, 13U)) + 11013335427004930046U;
            aOrbiterC = ((aWandererB + RotL64(aCross, 46U)) + RotL64(aCarry, 11U)) + 8298733856304768806U;
            aOrbiterG = ((aWandererJ + RotL64(aIngress, 23U)) + RotL64(aCarry, 3U)) + 6207732959150824216U;
            aOrbiterB = ((aWandererE + RotL64(aPrevious, 11U)) + 9769864876127544038U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = (aWandererH + RotL64(aScatter, 39U)) + 10782181918651152563U;
            aOrbiterK = ((aWandererC + RotL64(aCross, 27U)) + 5790454015845620939U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterD = (aWandererA + RotL64(aPrevious, 54U)) + 15606578025386733803U;
            aOrbiterI = (aWandererK + RotL64(aIngress, 43U)) + 5522352539991175304U;
            aOrbiterA = (aWandererI + RotL64(aScatter, 19U)) + 5993355818572869649U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 10864534396947622047U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 12090053126235913528U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7250801471645972261U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 14191181677234981396U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 2258570108233924592U;
            aOrbiterB = RotL64((aOrbiterB * 8307541155393855209U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 8448114811381534603U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 2702389315763499817U;
            aOrbiterE = RotL64((aOrbiterE * 6710443836432274393U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 17202184076718780200U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 150549910056015002U;
            aOrbiterI = RotL64((aOrbiterI * 195034681254956335U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 4910512055808124967U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 4783477997418403079U;
            aOrbiterG = RotL64((aOrbiterG * 861977492146512865U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 13842899106208709771U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 7930112618036681468U;
            aOrbiterC = RotL64((aOrbiterC * 8609551859830858419U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 8790107242863198659U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 6882768826643279144U;
            aOrbiterD = RotL64((aOrbiterD * 13745521454063360763U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 12136498871759890015U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 8120456314755584336U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 1830725195528043575U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 14425711740351183016U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 15907406009196323049U;
            aOrbiterH = RotL64((aOrbiterH * 8599371693260686839U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 4878521420367891861U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 1184672056055028939U;
            aOrbiterA = RotL64((aOrbiterA * 5963961755367831967U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 10126736568567000180U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 12615321415808640429U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 11663715449073755137U), 29U);
            //
            aIngress = RotL64(aOrbiterG, 29U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 19U));
            aIngress = aIngress + (RotL64(aOrbiterC, 11U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 47U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 26U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterK, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aPrevious, 13U) + aOrbiterH) + RotL64(aOrbiterE, 43U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 37U) + RotL64(aOrbiterI, 34U)) + aOrbiterB) + aPhaseFWandererUpdateSaltA[((aIndex + 3U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aCross, 27U) + aOrbiterI) + RotL64(aOrbiterD, 3U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 56U) + RotL64(aOrbiterI, 51U)) + aOrbiterG);
            aWandererF = aWandererF + (((RotL64(aCross, 5U) + aOrbiterE) + RotL64(aOrbiterD, 47U)) + RotL64(aCarry, 47U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 39U) + aOrbiterK) + RotL64(aOrbiterG, 57U));
            aWandererC = aWandererC + ((((RotL64(aPrevious, 11U) + RotL64(aOrbiterF, 39U)) + aOrbiterK) + RotL64(aCarry, 23U)) + aPhaseFWandererUpdateSaltC[((aIndex + 15U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 58U) + aOrbiterE) + RotL64(aOrbiterC, 37U));
            aWandererG = aWandererG + ((RotL64(aCross, 43U) + RotL64(aOrbiterJ, 41U)) + aOrbiterF);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 47U) + aOrbiterE) + RotL64(aOrbiterJ, 54U));
            aWandererJ = aWandererJ + ((RotL64(aScatter, 51U) + RotL64(aOrbiterA, 29U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 19U));
            aCarry = aCarry + (RotL64(aWandererK, 21U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererD, 29U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererC, 34U) ^ aWandererG);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 51U));
            aCarry = aCarry + RotL64(aWandererH, 47U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_c loop 5
        // ingress from: aWorkLaneB, aSnowLaneB, aInvestLaneD
        // ingress directions: aWorkLaneB forward forced, aSnowLaneB forward forced, aInvestLaneD forward/backward random
        // cross from: aWorkLaneA, aSnowLaneA
        // cross directions: aWorkLaneA backward forced, aSnowLaneA backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 23456U)) & S_BLOCK1], 12U) ^ RotL64(aSnowLaneB[((aIndex + 25739U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aInvestLaneD[((aIndex + 23391U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 25870U)) & S_BLOCK1], 27U) ^ RotL64(aSnowLaneA[((aIndex + 24149U)) & S_BLOCK1], 50U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 57U) + RotL64(aIngress, 43U)) + (RotL64(aCarry, 24U) ^ RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterJ = (aWandererA + RotL64(aScatter, 39U)) + 18255347001097480328U;
            aOrbiterB = (aWandererB + RotL64(aPrevious, 21U)) + 13679246790311505735U;
            aOrbiterG = (aWandererF + RotL64(aIngress, 37U)) + 10565839529765027116U;
            aOrbiterF = (aWandererH + RotL64(aCross, 4U)) + 14327172566224769901U;
            aOrbiterK = (((aWandererC + RotL64(aPrevious, 51U)) + RotL64(aCarry, 11U)) + 16239024612038195174U) + aPhaseFOrbiterAssignSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = ((aWandererG + RotL64(aScatter, 35U)) + 13800012174212131890U) + aPhaseFOrbiterAssignSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterA = (aWandererE + RotL64(aIngress, 53U)) + 13900288860157577583U;
            aOrbiterD = ((aWandererJ + RotL64(aCross, 30U)) + RotL64(aCarry, 21U)) + 4144386119777112740U;
            aOrbiterI = (aWandererK + RotL64(aPrevious, 47U)) + 3154558262670631372U;
            aOrbiterE = (aWandererD + RotL64(aScatter, 27U)) + 7456728543137614001U;
            aOrbiterH = ((aWandererI + RotL64(aIngress, 57U)) + RotL64(aCarry, 47U)) + 11709519851158935384U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 15607438907832240304U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 9276575329661725624U;
            aOrbiterG = RotL64((aOrbiterG * 8879744070762412745U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 6459435969129449226U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 6442382118416542275U;
            aOrbiterK = RotL64((aOrbiterK * 2921027306686588233U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 12117432107282150865U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 6831279293184793243U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2435360641135249073U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 9520022957804572889U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 8322178689474588679U;
            aOrbiterI = RotL64((aOrbiterI * 1627707191467537115U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 4162401591586869316U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 8994015844714895961U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 15421910378057951895U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 10038095909727959633U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 17756404450592957616U;
            aOrbiterH = RotL64((aOrbiterH * 14255952184627347295U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 3379089265413427719U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 11341713098678108441U;
            aOrbiterB = RotL64((aOrbiterB * 2500587373161411961U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 4030296130743454165U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 6332387792111212064U;
            aOrbiterE = RotL64((aOrbiterE * 16490982218150897861U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 14893209417387662133U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 9265457389326311687U;
            aOrbiterJ = RotL64((aOrbiterJ * 9778404505547862689U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 13496086915199406901U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 14576555328710787951U;
            aOrbiterA = RotL64((aOrbiterA * 13155395071667672943U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 11482324648071976743U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 18255347001097480328U;
            aOrbiterC = RotL64((aOrbiterC * 10918514878283385643U), 53U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterC, 54U);
            aIngress = aIngress + (RotL64(aOrbiterG, 23U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 39U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 13U));
            aIngress = aIngress + (RotL64(aOrbiterE, 19U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterF, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aIngress, 35U) + RotL64(aOrbiterB, 23U)) + aOrbiterC) + RotL64(aCarry, 51U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 51U) + aOrbiterB) + RotL64(aOrbiterI, 35U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aScatter, 29U) + RotL64(aOrbiterK, 43U)) + aOrbiterJ);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 56U) + aOrbiterK) + RotL64(aOrbiterA, 41U));
            aWandererF = aWandererF + ((RotL64(aScatter, 37U) + aOrbiterJ) + RotL64(aOrbiterE, 58U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 27U) + RotL64(aOrbiterC, 37U)) + aOrbiterG) + aPhaseFWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aCross, 23U) + aOrbiterD) + RotL64(aOrbiterF, 39U)) + RotL64(aCarry, 35U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterK, 21U)) + aOrbiterD);
            aWandererE = aWandererE + ((RotL64(aIngress, 47U) + RotL64(aOrbiterI, 26U)) + aOrbiterJ);
            aWandererD = aWandererD ^ ((RotL64(aCross, 10U) + aOrbiterH) + RotL64(aOrbiterK, 19U));
            aWandererC = aWandererC + ((RotL64(aScatter, 41U) + RotL64(aOrbiterE, 5U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererD, 56U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererJ, 23U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererI, 41U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererA, 3U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererB, 5U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererF, 29U);
            aCarry = aCarry + RotL64(aIngress, 10U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // twist_loop_c loop 6
        // ingress from: aWorkLaneC, aWorkLaneA, aInvestLaneB
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aInvestLaneB forward/backward random
        // cross from: aWorkLaneB, aOperationLaneB
        // cross directions: aWorkLaneB backward forced, aOperationLaneB backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 31924U)) & S_BLOCK1], 26U) ^ RotL64(aWorkLaneA[((aIndex + 29374U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aInvestLaneB[((aIndex + 31344U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 32124U)) & S_BLOCK1], 6U) ^ RotL64(aOperationLaneB[((aIndex + 27884U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 19U) + RotL64(aPrevious, 43U)) + (RotL64(aCarry, 5U) ^ RotL64(aIngress, 56U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterF = (aWandererE + RotL64(aPrevious, 47U)) + 2558105147674438050U;
            aOrbiterK = (aWandererF + RotL64(aScatter, 37U)) + 15856662514774702561U;
            aOrbiterI = (aWandererB + RotL64(aCross, 57U)) + 13346869226246584582U;
            aOrbiterE = (((aWandererG + RotL64(aIngress, 6U)) + RotL64(aCarry, 21U)) + 7632111846116243973U) + aPhaseFOrbiterAssignSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = (aWandererA + RotL64(aPrevious, 41U)) + 2102101361626976279U;
            aOrbiterJ = (aWandererK + RotL64(aCross, 35U)) + 5605968705067851563U;
            aOrbiterH = (aWandererI + RotL64(aScatter, 3U)) + 6842483186584326681U;
            aOrbiterA = (aWandererD + RotL64(aIngress, 53U)) + 5559797213819425064U;
            aOrbiterG = ((aWandererH + RotL64(aCross, 39U)) + RotL64(aCarry, 27U)) + 12422313931331576759U;
            aOrbiterD = ((aWandererC + RotL64(aPrevious, 10U)) + 2751024420047872601U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterB = ((aWandererJ + RotL64(aScatter, 29U)) + RotL64(aCarry, 5U)) + 11031320239359798610U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 14366375309473793217U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 11971479429768505316U;
            aOrbiterI = RotL64((aOrbiterI * 10063001532313098203U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 3947595951884469542U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 17882767922372770896U;
            aOrbiterK = RotL64((aOrbiterK * 3361906348965810211U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 513871456983509223U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 5951677013597794294U;
            aOrbiterH = RotL64((aOrbiterH * 8508629569649935293U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 437626309049021931U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 466674061172005705U;
            aOrbiterC = RotL64((aOrbiterC * 1310502572084891157U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 12362602809233133718U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 10525852878882195702U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 17755022180514914325U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 17927000184308583095U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 566723721423470052U;
            aOrbiterJ = RotL64((aOrbiterJ * 17710534355278632573U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 9504585484034413577U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 4614306037721859929U;
            aOrbiterD = RotL64((aOrbiterD * 170807293799483539U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 1463218357720031588U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 4036696102163560633U;
            aOrbiterB = RotL64((aOrbiterB * 15389914226155130065U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 9907678911300898726U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 11804311892289601322U;
            aOrbiterA = RotL64((aOrbiterA * 13986106774841242253U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 6514645538508331396U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 17246364354815744899U;
            aOrbiterE = RotL64((aOrbiterE * 12800661037742526999U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 6725706155285333764U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 2558105147674438050U;
            aOrbiterG = RotL64((aOrbiterG * 6752457079901154727U), 11U);
            //
            aIngress = RotL64(aOrbiterH, 47U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 53U));
            aIngress = aIngress + (RotL64(aOrbiterG, 19U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterC, 51U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterA, 3U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterK, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aIngress, 13U) + RotL64(aOrbiterH, 60U)) + aOrbiterK) + RotL64(aCarry, 39U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 42U) + RotL64(aOrbiterA, 37U)) + aOrbiterC);
            aWandererB = aWandererB + ((RotL64(aScatter, 19U) + aOrbiterG) + RotL64(aOrbiterB, 13U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 53U) + aOrbiterJ) + RotL64(aOrbiterB, 11U));
            aWandererK = aWandererK + ((RotL64(aIngress, 3U) + aOrbiterH) + RotL64(aOrbiterI, 29U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterD, 46U)) + aOrbiterF);
            aWandererJ = aWandererJ + ((RotL64(aCross, 30U) + aOrbiterI) + RotL64(aOrbiterF, 41U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 47U) + aOrbiterJ) + RotL64(aOrbiterF, 23U));
            aWandererE = aWandererE + ((((RotL64(aCross, 37U) + aOrbiterC) + RotL64(aOrbiterJ, 35U)) + RotL64(aCarry, 23U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterE, 21U)) + aOrbiterG);
            aWandererD = aWandererD + ((RotL64(aScatter, 23U) + RotL64(aOrbiterJ, 19U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 22U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 43U));
            aCarry = aCarry + (RotL64(aWandererG, 37U) ^ aWandererE);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 11U));
            aCarry = aCarry + (RotL64(aWandererC, 41U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererK, 54U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 6243U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneB[((aIndex + 2026U)) & S_BLOCK1], 6U));
            aIngress ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 4993U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 4006U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 5952U)) & S_BLOCK1], 40U));
            aCross ^= RotL64(aWorkLaneD[((aIndex + 1675U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 57U) + RotL64(aIngress, 41U)) ^ (RotL64(aCarry, 28U) + RotL64(aPrevious, 13U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterI = ((aWandererC + RotL64(aIngress, 53U)) + RotL64(aCarry, 37U)) + 1557680213571812384U;
            aOrbiterJ = (aWandererH + RotL64(aScatter, 14U)) + 7387349725778021121U;
            aOrbiterK = ((aWandererI + RotL64(aPrevious, 29U)) + RotL64(aCarry, 23U)) + 15379264067601586976U;
            aOrbiterB = (((aWandererE + RotL64(aCross, 3U)) + RotL64(aCarry, 11U)) + 3730195724576043708U) + aPhaseGOrbiterAssignSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = ((aWandererB + RotL64(aScatter, 39U)) + 9637070085323827066U) + aPhaseGOrbiterAssignSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 1170865717363676184U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 2750833653175252030U;
            aOrbiterK = RotL64((aOrbiterK * 1937822982381882775U), 5U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 15118992811225568305U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 4974092922102988451U;
            aOrbiterI = RotL64((aOrbiterI * 10575977398702460975U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 10625719096296719514U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 855167122475471865U) ^ aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 7441090331293158773U), 39U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 11322911068958340262U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 4334591909425429835U;
            aOrbiterJ = RotL64((aOrbiterJ * 10059025861172038183U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 14263701737208936392U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 678723206735649084U;
            aOrbiterE = RotL64((aOrbiterE * 10823239851733632227U), 29U);
            //
            aIngress = RotL64(aOrbiterJ, 24U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 57U));
            aIngress = aIngress + RotL64(aOrbiterK, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aIngress, 3U) + aOrbiterB) + RotL64(aOrbiterI, 56U)) + aPhaseGWandererUpdateSaltD[((aIndex + 13U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 24U) + aOrbiterK) + RotL64(aOrbiterI, 3U));
            aWandererC = aWandererC + (((RotL64(aCross, 35U) + RotL64(aOrbiterE, 39U)) + aOrbiterI) + RotL64(aCarry, 57U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 47U) + aOrbiterK) + RotL64(aOrbiterE, 21U));
            aWandererH = aWandererH + ((((RotL64(aPrevious, 13U) + RotL64(aOrbiterJ, 11U)) + aOrbiterB) + RotL64(aCarry, 21U)) + aPhaseGWandererUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 35U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererB, 6U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 11256U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneB[((aIndex + 10567U)) & S_BLOCK1], 58U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 15416U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 12697U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 15801U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 13353U)) & S_BLOCK1], 14U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 11U) ^ RotL64(aIngress, 40U)) ^ (RotL64(aPrevious, 23U) + RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterB = ((aWandererA + RotL64(aPrevious, 47U)) + RotL64(aCarry, 3U)) + 9774364261626083532U;
            aOrbiterI = ((aWandererE + RotL64(aIngress, 3U)) + 18059001521926116420U) + aPhaseGOrbiterAssignSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = ((aWandererJ + RotL64(aScatter, 39U)) + RotL64(aCarry, 53U)) + 10615626210406381148U;
            aOrbiterA = ((aWandererF + RotL64(aCross, 56U)) + 10536484278007898620U) + aPhaseGOrbiterAssignSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterF = ((aWandererD + RotL64(aIngress, 27U)) + RotL64(aCarry, 27U)) + 13320663045139972700U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 17127001787268166583U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 16742574590844166551U) ^ aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 17828964140627204983U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 8347719720758228053U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 13502468705946051986U;
            aOrbiterB = RotL64((aOrbiterB * 13822952083584784695U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 3512687886188904904U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 495660316165795934U;
            aOrbiterI = RotL64((aOrbiterI * 6724596801190194913U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 5092722552034477356U) + aPhaseGOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 15641128019608284015U) ^ aPhaseGOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3621036395703527059U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 15421873776811085458U) + aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 17978775513204574125U;
            aOrbiterF = RotL64((aOrbiterF * 18359600395119440183U), 57U);
            //
            aIngress = RotL64(aOrbiterA, 35U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 21U));
            aIngress = aIngress + RotL64(aOrbiterF, 58U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterA, 35U)) + aOrbiterD) + aPhaseGWandererUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 13U) + RotL64(aOrbiterB, 3U)) + aOrbiterI) + RotL64(aCarry, 35U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 27U) + aOrbiterI) + RotL64(aOrbiterA, 53U));
            aWandererA = aWandererA + ((((RotL64(aPrevious, 3U) + aOrbiterD) + RotL64(aOrbiterF, 43U)) + RotL64(aCarry, 3U)) + aPhaseGWandererUpdateSaltC[((aIndex + 20U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 40U) + aOrbiterB) + RotL64(aOrbiterF, 24U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 21U));
            aCarry = aCarry + (RotL64(aWandererE, 13U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererD, 43U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 19407U)) & S_BLOCK1], 22U) ^ RotL64(aExpandLaneA[((aIndex + 17851U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aWorkLaneD[((aIndex + 22349U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 23571U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 20571U)) & S_BLOCK1], 6U));
            aCross ^= RotL64(aWorkLaneC[((aIndex + 17130U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 23U) ^ RotL64(aCarry, 35U)) ^ (RotL64(aPrevious, 11U) + RotL64(aCross, 58U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterH = (aWandererF + RotL64(aScatter, 11U)) + 9654059367478508868U;
            aOrbiterC = (((aWandererI + RotL64(aPrevious, 51U)) + RotL64(aCarry, 39U)) + 6473006635864677427U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterE = (aWandererJ + RotL64(aCross, 23U)) + 6944184481315853243U;
            aOrbiterJ = ((aWandererG + RotL64(aIngress, 35U)) + RotL64(aCarry, 19U)) + 4061496421939102306U;
            aOrbiterI = (((aWandererB + RotL64(aCross, 60U)) + RotL64(aCarry, 51U)) + 15791809275719085463U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 14050798802646323055U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 12072905924741758266U) ^ aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4757104346636738119U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 17639076509231343896U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 12195388285571234715U;
            aOrbiterC = RotL64((aOrbiterC * 4317060502521195769U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 4325404419499496529U) + aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 5910567888204238382U;
            aOrbiterI = RotL64((aOrbiterI * 11503787177122206937U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 13092940059929942699U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 13381962590820308761U) ^ aPhaseGOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 6345904465930943295U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 15622862439323440527U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 14027151901132249793U;
            aOrbiterJ = RotL64((aOrbiterJ * 2273573821630510087U), 29U);
            //
            aIngress = RotL64(aOrbiterC, 57U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterH, 19U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterE, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterJ, 39U)) + aOrbiterI);
            aWandererB = aWandererB + ((((RotL64(aIngress, 11U) + RotL64(aOrbiterC, 13U)) + aOrbiterE) + RotL64(aCarry, 11U)) + aPhaseGWandererUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 56U) + aOrbiterJ) + RotL64(aOrbiterH, 29U));
            aWandererG = aWandererG + ((((RotL64(aPrevious, 35U) + RotL64(aOrbiterI, 21U)) + aOrbiterE) + RotL64(aCarry, 41U)) + aPhaseGWandererUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterH, 4U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 3U));
            aCarry = aCarry + (RotL64(aWandererJ, 35U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererB, 27U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 30979U)) & S_BLOCK1], 60U) ^ RotL64(aExpandLaneB[((aIndex + 26205U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aExpandLaneA[((aIndex + 28958U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 26099U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27328U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aExpandLaneC[((aIndex + 24935U)) & S_BLOCK1], 44U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCross, 22U)) + (RotL64(aCarry, 41U) ^ RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterD = ((aWandererJ + RotL64(aPrevious, 41U)) + RotL64(aCarry, 41U)) + 4751694786009671052U;
            aOrbiterH = ((aWandererB + RotL64(aScatter, 3U)) + RotL64(aCarry, 27U)) + 16362725160370844224U;
            aOrbiterG = ((aWandererI + RotL64(aCross, 28U)) + 6360885380915941057U) + aPhaseGOrbiterAssignSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterK = (aWandererC + RotL64(aIngress, 11U)) + 5154536007972297036U;
            aOrbiterB = (((aWandererG + RotL64(aCross, 51U)) + RotL64(aCarry, 5U)) + 9362540581874808253U) + aPhaseGOrbiterAssignSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 13902493871525612934U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 10208452885367546542U;
            aOrbiterG = RotL64((aOrbiterG * 12067703239567933105U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 3117030377279160998U) + aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 17286247690414027870U;
            aOrbiterD = RotL64((aOrbiterD * 4896931759653832095U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 3930314320040949141U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 7289525252391668404U;
            aOrbiterK = RotL64((aOrbiterK * 15452162299105112187U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 3434167955466809185U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 17852573095128575663U;
            aOrbiterH = RotL64((aOrbiterH * 1485660158767033425U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 6137259687928853253U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 13992510605237574698U) ^ aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 15346263295995333395U), 27U);
            //
            aIngress = RotL64(aOrbiterG, 24U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 47U));
            aIngress = aIngress + RotL64(aOrbiterH, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 23U) + aOrbiterB) + RotL64(aOrbiterD, 5U));
            aWandererG = aWandererG + (((RotL64(aIngress, 11U) + aOrbiterG) + RotL64(aOrbiterH, 21U)) + RotL64(aCarry, 5U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 50U) + aOrbiterH) + RotL64(aOrbiterK, 29U)) + aPhaseGWandererUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 41U) + RotL64(aOrbiterK, 56U)) + aOrbiterB) + RotL64(aCarry, 19U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 3U) + aOrbiterG) + RotL64(aOrbiterK, 47U)) + aPhaseGWandererUpdateSaltD[((aIndex + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 56U));
            aCarry = aCarry + (RotL64(aWandererC, 39U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererG, 21U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterD = 0; std::uint64_t aOrbiterE = 0;
    std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0;

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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 117U)) & S_BLOCK1], 54U) ^ RotL64(aExpandLaneB[((aIndex + 2844U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4335U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 3689U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 5674U)) & S_BLOCK1], 56U));
            aCross ^= RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 1228U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 23U) ^ RotL64(aCross, 57U)) + (RotL64(aCarry, 10U) + RotL64(aIngress, 35U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterJ = ((aWandererA + RotL64(aScatter, 3U)) + RotL64(aCarry, 53U)) + 3917730204724097072U;
            aOrbiterD = (((aWandererC + RotL64(aPrevious, 47U)) + RotL64(aCarry, 3U)) + 1874642340716212824U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterI = ((aWandererD + RotL64(aIngress, 18U)) + 6900165757434854160U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = (aWandererK + RotL64(aCross, 27U)) + 12750946097023807161U;
            aOrbiterE = ((aWandererJ + RotL64(aIngress, 39U)) + RotL64(aCarry, 21U)) + 6563216048479513594U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 14960240191349450795U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 16306180275951788289U;
            aOrbiterI = RotL64((aOrbiterI * 12077366095522790283U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 6502066618271045547U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 6219852857850888738U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10892297250334325283U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 2272931312452845850U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 3028929882263199463U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 11005324285856805069U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 6067393030073568112U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 10094809900437037258U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 18095564940730322769U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 5962414178157074575U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 15755563045799129417U;
            aOrbiterE = RotL64((aOrbiterE * 3692603590609922031U), 41U);
            //
            aIngress = RotL64(aOrbiterJ, 39U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 51U));
            aIngress = aIngress + RotL64(aOrbiterD, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aIngress, 47U) + aOrbiterI) + RotL64(aOrbiterE, 47U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 57U) + aOrbiterA) + RotL64(aOrbiterJ, 38U)) + RotL64(aCarry, 37U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 13U) + aOrbiterA) + RotL64(aOrbiterD, 29U)) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aScatter, 35U) + aOrbiterI) + RotL64(aOrbiterA, 21U)) + RotL64(aCarry, 5U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 22U) + RotL64(aOrbiterI, 13U)) + aOrbiterJ) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 19U));
            aCarry = aCarry + (RotL64(aWandererK, 3U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererA, 37U);
            aCarry = aCarry + RotL64(aIngress, 50U);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 11365U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneB[((aIndex + 15797U)) & S_BLOCK1], 42U));
            aIngress ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 12842U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 8353U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 13172U)) & S_BLOCK1], 54U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 14879U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 53U) + RotL64(aCarry, 19U)) + (RotL64(aCross, 4U) ^ RotL64(aIngress, 35U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterG = ((aWandererA + RotL64(aIngress, 57U)) + RotL64(aCarry, 3U)) + 1364174714924216027U;
            aOrbiterB = ((aWandererB + RotL64(aPrevious, 14U)) + 13561796874229506613U) + aPhaseHOrbiterAssignSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterD = (((aWandererK + RotL64(aScatter, 3U)) + RotL64(aCarry, 21U)) + 11845572344206238305U) + aPhaseHOrbiterAssignSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterA = (aWandererI + RotL64(aCross, 41U)) + 15762708240326773763U;
            aOrbiterI = ((aWandererE + RotL64(aPrevious, 29U)) + RotL64(aCarry, 39U)) + 1157119665207900473U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 6823546624372055260U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 14465564210523945121U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 10957323253786161255U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 10667464548080807531U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 13445737493224316575U;
            aOrbiterI = RotL64((aOrbiterI * 12137295000900795711U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 3009837893785957665U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 2886920524111083752U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 15308180928967762543U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 10886177449328249656U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 15067759884678100433U;
            aOrbiterB = RotL64((aOrbiterB * 5724566815989860041U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 18307930462682331536U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 8791864377579255801U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 9265158882471421767U), 57U);
            //
            aIngress = RotL64(aOrbiterB, 29U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterG, 3U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterD, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterG, 27U)) + aOrbiterA);
            aWandererB = aWandererB + (((RotL64(aCross, 43U) + RotL64(aOrbiterI, 3U)) + aOrbiterG) + RotL64(aCarry, 27U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 21U) + aOrbiterG) + RotL64(aOrbiterB, 18U)) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 13U) + aOrbiterA) + RotL64(aOrbiterD, 51U)) + RotL64(aCarry, 51U)) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 54U) + RotL64(aOrbiterI, 35U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererI, 21U) ^ aWandererE);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 47U));
            aCarry = aCarry + RotL64(aWandererB, 60U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 19778U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneA[((aIndex + 18791U)) & S_BLOCK1], 56U));
            aIngress ^= RotL64(aExpandLaneD[((aIndex + 22527U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18849U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 22486U)) & S_BLOCK1], 40U));
            aCross ^= RotL64(aExpandLaneC[((aIndex + 22613U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 35U) ^ RotL64(aCarry, 6U)) ^ (RotL64(aIngress, 21U) + RotL64(aCross, 51U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterH = (((aWandererB + RotL64(aCross, 19U)) + RotL64(aCarry, 39U)) + 15904465836916519864U) + aPhaseHOrbiterAssignSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterA = (aWandererJ + RotL64(aScatter, 47U)) + 17725629806317789307U;
            aOrbiterE = ((aWandererI + RotL64(aIngress, 36U)) + RotL64(aCarry, 23U)) + 13794170125914914828U;
            aOrbiterB = ((aWandererH + RotL64(aPrevious, 11U)) + RotL64(aCarry, 5U)) + 2149055907476874332U;
            aOrbiterG = ((aWandererD + RotL64(aScatter, 57U)) + 5342047776745074649U) + aPhaseHOrbiterAssignSaltA[((aIndex + 25U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 8268148484060546838U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 10821151364028563719U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 13626634259250509711U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 4294213820894407378U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 10884726101307943090U;
            aOrbiterB = RotL64((aOrbiterB * 1116128870387229159U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 16432210042202444824U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 15196602644336228055U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 12680438355124070237U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 14117787670220328165U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 219833877949480215U;
            aOrbiterG = RotL64((aOrbiterG * 10736293047771972173U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 3326396981881473962U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 14918513066311426279U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 14269763278564574663U), 11U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterE, 51U);
            aIngress = aIngress + (RotL64(aOrbiterG, 29U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterH, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aIngress, 35U) + aOrbiterG) + RotL64(aOrbiterH, 13U)) + RotL64(aCarry, 19U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 18U) + RotL64(aOrbiterE, 39U)) + aOrbiterA);
            aWandererH = aWandererH + (((RotL64(aCross, 43U) + RotL64(aOrbiterH, 3U)) + aOrbiterA) + aPhaseHWandererUpdateSaltC[((aIndex + 17U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterE, 29U)) + aOrbiterB);
            aWandererB = aWandererB + ((((RotL64(aCross, 5U) + RotL64(aOrbiterB, 58U)) + aOrbiterH) + RotL64(aCarry, 43U)) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 40U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 27U));
            aCarry = aCarry + RotL64(aWandererI, 3U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 30370U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneB[((aIndex + 31021U)) & S_BLOCK1], 34U));
            aIngress ^= RotL64(aWorkLaneA[((aIndex + 28923U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 32368U)) & S_BLOCK1], 6U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 25797U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aWorkLaneC[((aIndex + 28680U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 19U) ^ RotL64(aCarry, 37U)) + (RotL64(aCross, 52U) ^ RotL64(aPrevious, 3U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterE = ((aWandererK + RotL64(aCross, 37U)) + RotL64(aCarry, 11U)) + 6467297102954816305U;
            aOrbiterD = (aWandererE + RotL64(aPrevious, 23U)) + 7921154109831114952U;
            aOrbiterJ = (((aWandererB + RotL64(aIngress, 14U)) + RotL64(aCarry, 23U)) + 5701131763215638919U) + aPhaseHOrbiterAssignSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterH = (((aWandererF + RotL64(aScatter, 47U)) + RotL64(aCarry, 35U)) + 10022999076719002684U) + aPhaseHOrbiterAssignSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterA = (aWandererH + RotL64(aCross, 3U)) + 4367135243038982316U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 14445846824810383592U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 7683697954545773253U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4832124801510084629U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 17517006750428030899U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 2052484792684025476U;
            aOrbiterA = RotL64((aOrbiterA * 12463117571122469643U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 6279463052085808926U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 679280153651813684U;
            aOrbiterD = RotL64((aOrbiterD * 3047031560593583881U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 2939516520188460569U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 1960616434964712325U;
            aOrbiterH = RotL64((aOrbiterH * 15145998415466343039U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 12273819390719947361U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 5685033154709449397U;
            aOrbiterE = RotL64((aOrbiterE * 9845666295874714959U), 13U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterD, 57U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 27U));
            aIngress = aIngress + RotL64(aOrbiterJ, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aPrevious, 42U) + aOrbiterD) + RotL64(aOrbiterE, 57U)) + RotL64(aCarry, 13U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 53U) + RotL64(aOrbiterH, 4U)) + aOrbiterJ) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aIngress, 27U) + RotL64(aOrbiterJ, 37U)) + aOrbiterE);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 11U) + aOrbiterH) + RotL64(aOrbiterA, 27U));
            aWandererK = aWandererK + ((((RotL64(aIngress, 3U) + RotL64(aOrbiterA, 13U)) + aOrbiterE) + RotL64(aCarry, 47U)) + aPhaseHWandererUpdateSaltB[((aIndex + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 47U) ^ aWandererF);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 56U));
            aCarry = aCarry + RotL64(aWandererB, 19U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
