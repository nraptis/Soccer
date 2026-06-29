#include "TwistExpander_Hockey_Arx.hpp"
#include "TwistFunctional.hpp"
#include "TwistMix32.hpp"
#include "TwistMix64.hpp"

#include <cstdint>

void TwistExpander_Hockey_Arx::KDF_A_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x9CBF615C90F64619ULL + 0xEE2D418169D84DF6ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xE611554A88110E97ULL + 0xB779C1554960A846ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x9CEECF7FC0939F1FULL + 0xA3B4BF742DF10A59ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xD48D8ADC71B956EBULL + 0xBD814C2ECA9BA1D2ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xBF1B5E0BFDC79363ULL + 0xE8254F729D0F4B44ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x8C4570D2C22111F1ULL + 0xDE9A896EE59280F5ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xCA5D135E24D87143ULL + 0xCFBE46E2A944ECD2ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xFF96D5060D941A85ULL + 0xCFC63F472D93DA11ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xC76C98B2F3B26C5DULL + 0xCB49591CCF555CE6ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xE512921385954361ULL + 0x888C0544ADF18615ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xBA84E4AE4F66ABE1ULL + 0xF7BDB38F07035453ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xAA7094A23B482B39ULL + 0xCD00ED8B64AD27FFULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xC58DD9288E0F04C3ULL + 0xA4E8606C4D82C5FEULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x8400CF4AE719D465ULL + 0x8E67B880DDAB50D1ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x91E4496DBB3D3B79ULL + 0xA40889535FE84FD9ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0x853C2221ECBDAA5DULL + 0x859D1F22B39E657BULL);
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
            aIngress = RotL64(mSource[((aIndex + 3323U)) & S_BLOCK1], 10U) ^ RotL64(pSnow[((aIndex + 5321U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(pSnow[((S_BLOCK1 - aIndex + 5396U)) & S_BLOCK1], 34U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 4447U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCross, 6U) + RotL64(aIngress, 37U)) + (RotL64(aPrevious, 53U) ^ RotL64(aCarry, 19U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterI = (aWandererD + RotL64(aPrevious, 43U)) + 10038936806177516123U;
            aOrbiterB = (aWandererG + RotL64(aCross, 52U)) + 1773168435195292638U;
            aOrbiterE = ((aWandererA + RotL64(aScatter, 35U)) + 10655711161526628072U) + aOrbiterAssignSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterG = (aWandererJ + RotL64(aIngress, 13U)) + 14422295664639740437U;
            aOrbiterC = (aWandererE + RotL64(aScatter, 5U)) + 4125228715513159576U;
            aOrbiterF = ((aWandererH + RotL64(aIngress, 3U)) + RotL64(aCarry, 53U)) + 3670449653158650845U;
            aOrbiterA = ((aWandererK + RotL64(aCross, 39U)) + RotL64(aCarry, 3U)) + 17553727567180813057U;
            aOrbiterH = (((aWandererB + RotL64(aPrevious, 19U)) + RotL64(aCarry, 27U)) + 5111401772713882743U) + aNonceWordL;
            aOrbiterK = ((aWandererF + RotL64(aScatter, 11U)) + 7688573124662314413U) + aOrbiterAssignSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterJ = (aWandererI + RotL64(aIngress, 47U)) + 9438375825507814395U;
            aOrbiterD = ((aWandererC + RotL64(aCross, 54U)) + 14177477039902118886U) + aNonceWordO;
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 16329942595859623928U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 3990536794006836672U;
            aOrbiterE = RotL64((aOrbiterE * 579024714339065373U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 5072881436583180756U) + aNonceWordA;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 16789727877867289997U) ^ aNonceWordJ;
            aOrbiterC = RotL64((aOrbiterC * 8766246302636197905U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 17313956922306689438U) + aOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 11530878396329822041U;
            aOrbiterA = RotL64((aOrbiterA * 11356860047841383129U), 23U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterA) + 3612616532321160196U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordI;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 4172189825359187763U;
            aOrbiterH = RotL64((aOrbiterH * 12938945495299393177U), 41U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 8677279703778052804U) + aOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 1912172980909479362U;
            aOrbiterK = RotL64((aOrbiterK * 10053289257955474143U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 1460085850227494500U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 12116763868122868147U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 6076945628020280957U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 17571840610366424432U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 15581362592611080868U;
            aOrbiterB = RotL64((aOrbiterB * 1129054058044872003U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 14434700039977611666U) + aNonceWordB;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 4534294602623329152U;
            aOrbiterF = RotL64((aOrbiterF * 5860911553425182045U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 865998255725903702U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 16407778704555344108U;
            aOrbiterD = RotL64((aOrbiterD * 15571344643129797977U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 1948990288894429805U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 18218556219056835250U;
            aOrbiterG = RotL64((aOrbiterG * 16574160087642377293U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 1309229265173143398U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 10038936806177516123U;
            aOrbiterJ = RotL64((aOrbiterJ * 12954594462760207923U), 51U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterK, 18U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 29U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 21U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 13U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 53U));
            aIngress = aIngress + RotL64(aOrbiterI, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aIngress, 53U) + aOrbiterE) + RotL64(aOrbiterC, 13U)) + RotL64(aCarry, 27U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 30U) + aOrbiterH) + RotL64(aOrbiterE, 18U)) + aNonceWordN);
            aWandererC = aWandererC + (((((RotL64(aCross, 41U) + aOrbiterI) + RotL64(aOrbiterA, 51U)) + RotL64(aCarry, 39U)) + aNonceWordC) + aWandererUpdateSaltB[((aIndex + 29U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 51U) + RotL64(aOrbiterG, 37U)) + aOrbiterI) + aWandererUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aIngress, 39U) + aOrbiterJ) + RotL64(aOrbiterC, 23U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 27U) + aOrbiterB) + RotL64(aOrbiterJ, 3U));
            aWandererH = aWandererH + ((RotL64(aScatter, 57U) + RotL64(aOrbiterA, 11U)) + aOrbiterD);
            aWandererI = aWandererI ^ ((RotL64(aCross, 35U) + aOrbiterB) + RotL64(aOrbiterG, 39U));
            aWandererA = aWandererA + ((RotL64(aIngress, 37U) + aOrbiterH) + RotL64(aOrbiterK, 20U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 44U) + RotL64(aOrbiterH, 35U)) + aOrbiterF) + aNonceWordG);
            aWandererF = aWandererF + ((RotL64(aScatter, 5U) + aOrbiterE) + RotL64(aOrbiterJ, 47U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 39U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 50U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 3U));
            aCarry = aCarry + (RotL64(aWandererC, 13U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererI, 5U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererJ, 29U);
            aCarry = aCarry + RotL64(aIngress, 24U);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 9671U)) & S_BLOCK1], 19U) ^ RotL64(mSource[((aIndex + 8484U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 9116U)) & S_BLOCK1], 54U) ^ RotL64(pSnow[((aIndex + 6793U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCross, 23U) ^ RotL64(aIngress, 54U)) + (RotL64(aCarry, 41U) + RotL64(aPrevious, 3U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterE = (aWandererJ + RotL64(aPrevious, 47U)) + 12131317914288566437U;
            aOrbiterB = ((aWandererH + RotL64(aCross, 5U)) + RotL64(aCarry, 5U)) + 5672805657999385496U;
            aOrbiterD = ((((aWandererI + RotL64(aScatter, 27U)) + RotL64(aCarry, 47U)) + 3581710244233124197U) + aOrbiterAssignSaltF[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordI;
            aOrbiterK = (aWandererB + RotL64(aIngress, 38U)) + 15251296040538489436U;
            aOrbiterC = (aWandererK + RotL64(aCross, 57U)) + 11295008604679904153U;
            aOrbiterF = ((aWandererF + RotL64(aScatter, 21U)) + 2230897493419504490U) + aNonceWordP;
            aOrbiterG = ((aWandererA + RotL64(aPrevious, 19U)) + RotL64(aCarry, 43U)) + 7109600123297458999U;
            aOrbiterJ = (aWandererG + RotL64(aIngress, 3U)) + 13119156643107683803U;
            aOrbiterA = ((aWandererD + RotL64(aScatter, 44U)) + 14755160867807355250U) + aOrbiterAssignSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = (aWandererC + RotL64(aIngress, 41U)) + 16829363373287496832U;
            aOrbiterH = ((aWandererE + RotL64(aPrevious, 53U)) + 16981122946707720883U) + aNonceWordA;
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 8806000776958603317U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 16810923047720876014U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 17872735050219539145U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 8129657889554436328U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterK) ^ 8653100378491974463U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterC = RotL64((aOrbiterC * 11395283153912468661U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 17048985838727432415U) + aOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 10892675550889823573U;
            aOrbiterG = RotL64((aOrbiterG * 976298937314081913U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 15960158965421254346U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 12290011578634850001U;
            aOrbiterA = RotL64((aOrbiterA * 9280475585104357745U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 16265047040311479093U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 10312956912303656248U;
            aOrbiterH = RotL64((aOrbiterH * 3012584393253845131U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 16706890352221352779U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 10630955894218491929U) ^ aNonceWordF;
            aOrbiterK = RotL64((aOrbiterK * 12675937483456206355U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 4009352551041162434U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 3043810773683888556U;
            aOrbiterJ = RotL64((aOrbiterJ * 4328135390387997315U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 1398071019814944785U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 16689766557488135301U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8403881916549404871U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 15934647144489136524U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 13521276033614992223U;
            aOrbiterB = RotL64((aOrbiterB * 18003640895553609933U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 4281211055727414100U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 11848150507497406421U;
            aOrbiterI = RotL64((aOrbiterI * 1107789990317433481U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 12022829841608199449U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 12131317914288566437U) ^ aNonceWordD;
            aOrbiterE = RotL64((aOrbiterE * 13275753083882829973U), 41U);
            //
            aIngress = RotL64(aOrbiterI, 13U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 47U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 43U));
            aIngress = aIngress + (RotL64(aOrbiterA, 19U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterD, 53U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterE, 50U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 37U) + aOrbiterF) + RotL64(aOrbiterK, 3U)) + RotL64(aCarry, 57U));
            aWandererK = aWandererK ^ ((((RotL64(aCross, 53U) + RotL64(aOrbiterK, 13U)) + aOrbiterJ) + aNonceWordL) + aWandererUpdateSaltC[((aIndex + 6U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aScatter, 5U) + RotL64(aOrbiterH, 57U)) + aOrbiterJ);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 42U) + aOrbiterC) + RotL64(aOrbiterG, 10U));
            aWandererI = aWandererI + ((((RotL64(aScatter, 47U) + RotL64(aOrbiterF, 19U)) + aOrbiterD) + RotL64(aCarry, 51U)) + aNonceWordC);
            aWandererF = aWandererF ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterA, 43U)) + aOrbiterB);
            aWandererA = aWandererA + ((RotL64(aPrevious, 3U) + RotL64(aOrbiterK, 23U)) + aOrbiterC);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 51U) + RotL64(aOrbiterA, 29U)) + aOrbiterE) + aWandererUpdateSaltF[((aIndex + 7U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aPrevious, 35U) + aOrbiterJ) + RotL64(aOrbiterB, 46U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterI, 37U)) + aOrbiterH);
            aWandererE = aWandererE + ((RotL64(aCross, 26U) + RotL64(aOrbiterI, 35U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 27U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 23U));
            aCarry = aCarry + (RotL64(aWandererI, 54U) ^ aWandererD);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 51U));
            aCarry = aCarry + (RotL64(aWandererK, 41U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererG, 21U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = RotL64(aWorkLaneB[((aIndex + 13334U)) & S_BLOCK1], 13U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 14068U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(pSnow[((S_BLOCK1 - aIndex + 12563U)) & S_BLOCK1], 24U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 15283U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aPrevious, 60U) + RotL64(aCross, 27U)) ^ (RotL64(aCarry, 41U) ^ RotL64(aIngress, 13U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterG = ((((aWandererK + RotL64(aCross, 21U)) + RotL64(aCarry, 13U)) + 17470880031634374199U) + aOrbiterAssignSaltE[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordE;
            aOrbiterH = ((aWandererI + RotL64(aScatter, 27U)) + 757565846006937746U) + aNonceWordD;
            aOrbiterD = ((aWandererE + RotL64(aIngress, 24U)) + 9419282475801345674U) + aNonceWordA;
            aOrbiterJ = (((aWandererC + RotL64(aPrevious, 5U)) + RotL64(aCarry, 35U)) + 2014248014107898196U) + aOrbiterAssignSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = ((aWandererF + RotL64(aScatter, 13U)) + RotL64(aCarry, 47U)) + 15113928519446490441U;
            aOrbiterE = (aWandererB + RotL64(aCross, 35U)) + 7346126964886259935U;
            aOrbiterB = (aWandererG + RotL64(aPrevious, 29U)) + 5594123113093162359U;
            aOrbiterC = (aWandererA + RotL64(aIngress, 39U)) + 5659237263369402005U;
            aOrbiterK = (aWandererJ + RotL64(aCross, 3U)) + 11565709683423969703U;
            aOrbiterA = (aWandererD + RotL64(aScatter, 47U)) + 16782863743534856287U;
            aOrbiterI = (aWandererH + RotL64(aIngress, 50U)) + 13499100900072115907U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 11414447651044205242U) + aOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 7545993795121430538U;
            aOrbiterD = RotL64((aOrbiterD * 10758488381206257261U), 29U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterD) + 11778229237616454988U) + aOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1]) + aNonceWordK;
            aOrbiterF = (((aOrbiterF ^ aOrbiterJ) ^ 2544793391976514665U) ^ aOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterF = RotL64((aOrbiterF * 4021060413798523299U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 9972156716619459164U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 17651030383827445664U;
            aOrbiterG = RotL64((aOrbiterG * 6742914240706775487U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 17439147296849134543U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 10021926927948343656U) ^ aNonceWordH;
            aOrbiterK = RotL64((aOrbiterK * 18139540407315440909U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 9309867875882669289U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 14951424455944346337U;
            aOrbiterH = RotL64((aOrbiterH * 10569523948169951309U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 2166343974068770659U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 11386993629011562026U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 3091639433512536097U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 5747849744680120960U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 4019290369160113026U) ^ aNonceWordC;
            aOrbiterB = RotL64((aOrbiterB * 5567515306039646735U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 3820540009554769592U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 8210747198363020939U;
            aOrbiterJ = RotL64((aOrbiterJ * 16215133106542452509U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 3006494852696036003U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 2736305345451919450U;
            aOrbiterA = RotL64((aOrbiterA * 11993452696344358247U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 6148431711118275178U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 6986633012691940738U;
            aOrbiterI = RotL64((aOrbiterI * 15672039482523804893U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 7837859154831245165U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 17470880031634374199U;
            aOrbiterE = RotL64((aOrbiterE * 2153299273348512243U), 11U);
            //
            aIngress = RotL64(aOrbiterH, 37U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterB, 53U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 26U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 43U));
            aIngress = aIngress + (RotL64(aOrbiterK, 11U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterG, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aPrevious, 41U) + aOrbiterH) + RotL64(aOrbiterB, 30U)) + RotL64(aCarry, 43U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterE, 5U)) + aOrbiterF);
            aWandererG = aWandererG + ((RotL64(aScatter, 13U) + aOrbiterI) + RotL64(aOrbiterF, 11U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterA, 37U)) + aOrbiterH);
            aWandererH = aWandererH + ((((RotL64(aScatter, 27U) + aOrbiterB) + RotL64(aOrbiterK, 50U)) + RotL64(aCarry, 47U)) + aWandererUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((((RotL64(aCross, 24U) + aOrbiterD) + RotL64(aOrbiterE, 13U)) + aNonceWordJ) + aWandererUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aIngress, 43U) + aOrbiterG) + RotL64(aOrbiterC, 43U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterG, 27U)) + aOrbiterJ);
            aWandererE = aWandererE + ((RotL64(aCross, 29U) + RotL64(aOrbiterA, 47U)) + aOrbiterJ);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 56U) + RotL64(aOrbiterI, 41U)) + aOrbiterC);
            aWandererI = aWandererI + (((RotL64(aPrevious, 5U) + aOrbiterI) + RotL64(aOrbiterJ, 19U)) + aNonceWordM);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 44U));
            aCarry = aCarry + (RotL64(aWandererC, 21U) ^ aWandererG);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 23U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 51U));
            aCarry = aCarry + (RotL64(aWandererB, 3U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererH, 48U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 20779U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneA[((aIndex + 21658U)) & S_BLOCK1], 42U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 20261U)) & S_BLOCK1], 3U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 20933U)) & S_BLOCK1], 26U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 18681U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCarry, 21U) ^ RotL64(aIngress, 35U)) + (RotL64(aCross, 52U) ^ RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterH = ((aWandererG + RotL64(aPrevious, 24U)) + 15726877954695761686U) + aOrbiterAssignSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = ((((aWandererC + RotL64(aScatter, 13U)) + RotL64(aCarry, 13U)) + 14187652171881943587U) + aOrbiterAssignSaltC[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordG;
            aOrbiterB = (((aWandererD + RotL64(aCross, 5U)) + RotL64(aCarry, 41U)) + 8420423151313882782U) + aNonceWordK;
            aOrbiterK = (aWandererE + RotL64(aIngress, 21U)) + 14942322692433259283U;
            aOrbiterG = ((aWandererH + RotL64(aScatter, 19U)) + 7272331475919796255U) + aNonceWordA;
            aOrbiterJ = (aWandererI + RotL64(aCross, 40U)) + 154504365041805840U;
            aOrbiterI = ((aWandererB + RotL64(aPrevious, 43U)) + RotL64(aCarry, 5U)) + 17475491222554948786U;
            aOrbiterD = (aWandererA + RotL64(aIngress, 57U)) + 5759181483165339605U;
            aOrbiterF = ((aWandererF + RotL64(aPrevious, 3U)) + 5993060214499322845U) + aNonceWordM;
            aOrbiterA = (aWandererK + RotL64(aScatter, 53U)) + 10901786237875941844U;
            aOrbiterC = (aWandererJ + RotL64(aIngress, 35U)) + 17135786595614068473U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 5208202073886811165U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 6821452921018900631U;
            aOrbiterB = RotL64((aOrbiterB * 13119330055184115669U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 13348064837402206969U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 8967943922403445136U;
            aOrbiterJ = RotL64((aOrbiterJ * 300168481725373093U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 8130283784171430891U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 6351113882502502876U;
            aOrbiterK = RotL64((aOrbiterK * 15960622823993072903U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 6894708729226455769U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 12065058511247133944U) ^ aOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5432601727436935831U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 17138279326229372741U) + aNonceWordI;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 12987698199066890628U) ^ aOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12665716655177320977U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 13688833537574196675U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 4211971980434000618U;
            aOrbiterD = RotL64((aOrbiterD * 1374411763361518851U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 10376917117582537592U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 4807742522197923516U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 15257251453302090961U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 18038296468177121243U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 6879666349379745258U;
            aOrbiterF = RotL64((aOrbiterF * 15819475269715810555U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 5193656664432659624U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 680899397323387963U;
            aOrbiterA = RotL64((aOrbiterA * 9857476056194621321U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 1851929589073547860U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterC) ^ 13093101559415170218U) ^ aOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterE = RotL64((aOrbiterE * 13950928576652143737U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 13695333301427028607U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 15726877954695761686U;
            aOrbiterH = RotL64((aOrbiterH * 960063676226172027U), 43U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterE, 37U);
            aIngress = aIngress + (RotL64(aOrbiterC, 26U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterF, 43U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterH, 11U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 39U));
            aIngress = aIngress + RotL64(aOrbiterJ, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aIngress, 53U) + aOrbiterJ) + RotL64(aOrbiterA, 5U)) + RotL64(aCarry, 35U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 6U) + RotL64(aOrbiterJ, 13U)) + aOrbiterI) + aNonceWordH);
            aWandererK = aWandererK + (((RotL64(aCross, 27U) + RotL64(aOrbiterG, 18U)) + aOrbiterF) + RotL64(aCarry, 29U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 39U) + aOrbiterF) + RotL64(aOrbiterI, 37U)) + aNonceWordF);
            aWandererA = aWandererA + ((RotL64(aCross, 35U) + RotL64(aOrbiterE, 57U)) + aOrbiterH);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterC, 43U)) + aOrbiterF);
            aWandererF = aWandererF + (((RotL64(aIngress, 41U) + aOrbiterB) + RotL64(aOrbiterD, 53U)) + aNonceWordB);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 11U) + aOrbiterK) + RotL64(aOrbiterB, 11U)) + aWandererUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aCross, 29U) + aOrbiterE) + RotL64(aOrbiterI, 47U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 23U) + aOrbiterF) + RotL64(aOrbiterJ, 3U)) + aWandererUpdateSaltD[((aIndex + 12U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aIngress, 44U) + aOrbiterK) + RotL64(aOrbiterG, 24U)) + aNonceWordN);
            //
            aCarry = aCarry + (RotL64(aWandererG, 12U) ^ aWandererJ);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 5U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + (RotL64(aWandererH, 23U) ^ aWandererC);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 43U));
            aCarry = aCarry + RotL64(aWandererF, 39U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 23510U)) & S_BLOCK1], 53U) ^ RotL64(mSource[((aIndex + 26786U)) & S_BLOCK1], 12U));
            aIngress ^= (RotL64(pSnow[((aIndex + 23619U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 26867U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 24463U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneB[((aIndex + 26337U)) & S_BLOCK1], 10U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCarry, 43U) ^ RotL64(aPrevious, 28U)) + (RotL64(aIngress, 13U) + RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterB = ((aWandererB + RotL64(aIngress, 41U)) + 966899917801652720U) + aOrbiterAssignSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = ((aWandererC + RotL64(aPrevious, 56U)) + RotL64(aCarry, 43U)) + 10996327672320748649U;
            aOrbiterJ = ((aWandererG + RotL64(aScatter, 43U)) + 4188171566846621107U) + aOrbiterAssignSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = ((aWandererJ + RotL64(aCross, 37U)) + RotL64(aCarry, 23U)) + 5886209243097387959U;
            aOrbiterE = (aWandererK + RotL64(aIngress, 3U)) + 14940428957136728111U;
            aOrbiterA = (((aWandererD + RotL64(aScatter, 5U)) + RotL64(aCarry, 13U)) + 179187285531914832U) + aNonceWordJ;
            aOrbiterG = (aWandererF + RotL64(aPrevious, 60U)) + 6685351948936817752U;
            aOrbiterK = (aWandererI + RotL64(aCross, 11U)) + 1894506461704029700U;
            aOrbiterI = (aWandererA + RotL64(aScatter, 35U)) + 4182760368636977082U;
            aOrbiterF = ((aWandererH + RotL64(aIngress, 13U)) + 12523318028514940790U) + aNonceWordM;
            aOrbiterC = (aWandererE + RotL64(aCross, 51U)) + 5059306166973366892U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 5890872367917643851U) + aOrbiterUpdateSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 17747338389865221534U;
            aOrbiterJ = RotL64((aOrbiterJ * 5306740664798049267U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 13906227834259884100U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 7152105382899756368U) ^ aNonceWordE;
            aOrbiterB = RotL64((aOrbiterB * 6772157117358310485U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 17868101884759619240U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 11758843266314148347U;
            aOrbiterG = RotL64((aOrbiterG * 5919135169337501485U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 13950566197090324859U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 17278105609930477854U) ^ aNonceWordP;
            aOrbiterD = RotL64((aOrbiterD * 11431842718945107359U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 9556785965646738355U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 841298436857932987U;
            aOrbiterK = RotL64((aOrbiterK * 15077843186688841797U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 1951515285492133830U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 15775839819330588437U;
            aOrbiterF = RotL64((aOrbiterF * 7902654031401620995U), 41U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 5585458468816495436U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 17258586689032223623U;
            aOrbiterE = RotL64((aOrbiterE * 1652050227399194271U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 5254132659445988836U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 15440741734777060925U;
            aOrbiterI = RotL64((aOrbiterI * 17445581079035134067U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 16770361602586485631U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 14902616717976301965U;
            aOrbiterA = RotL64((aOrbiterA * 7757713071544143453U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 9521517757370835715U) + aOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 18241677917767801049U;
            aOrbiterH = RotL64((aOrbiterH * 16977396965907931057U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 14307634663160859644U) + aNonceWordO;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 966899917801652720U;
            aOrbiterC = RotL64((aOrbiterC * 17012361848398765251U), 53U);
            //
            aIngress = RotL64(aOrbiterF, 60U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterC, 11U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterD, 51U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 57U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 41U));
            aIngress = aIngress + RotL64(aOrbiterA, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 6U) + RotL64(aOrbiterE, 27U)) + aOrbiterA);
            aWandererD = aWandererD + ((((RotL64(aCross, 27U) + aOrbiterE) + RotL64(aOrbiterI, 57U)) + RotL64(aCarry, 11U)) + aNonceWordG);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterA, 48U)) + aOrbiterG);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 35U) + RotL64(aOrbiterB, 3U)) + aOrbiterK);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterK, 43U)) + aOrbiterJ);
            aWandererC = aWandererC + ((RotL64(aCross, 60U) + RotL64(aOrbiterD, 21U)) + aOrbiterC);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 13U) + RotL64(aOrbiterK, 41U)) + aOrbiterH) + aNonceWordK);
            aWandererI = aWandererI + (((RotL64(aScatter, 47U) + RotL64(aOrbiterC, 35U)) + aOrbiterB) + RotL64(aCarry, 39U));
            aWandererA = aWandererA ^ ((((RotL64(aPrevious, 53U) + RotL64(aOrbiterA, 23U)) + aOrbiterD) + aNonceWordC) + aWandererUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 57U) + RotL64(aOrbiterE, 29U)) + aOrbiterC) + aWandererUpdateSaltF[((aIndex + 13U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 37U) + RotL64(aOrbiterH, 52U)) + aOrbiterF) + aNonceWordA);
            //
            aCarry = aCarry + (RotL64(aWandererD, 60U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererH, 57U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererE, 35U) ^ aWandererG);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 27U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 19U));
            aCarry = aCarry + RotL64(aWandererF, 6U);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 32715U)) & S_BLOCK1], 35U) ^ RotL64(pSnow[((aIndex + 29177U)) & S_BLOCK1], 24U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 31425U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 30837U)) & S_BLOCK1], 4U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 31227U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 28912U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCross, 53U) + RotL64(aPrevious, 19U)) ^ (RotL64(aIngress, 41U) ^ RotL64(aCarry, 4U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterG = (aWandererH + RotL64(aCross, 27U)) + 15316464782468770057U;
            aOrbiterF = ((aWandererC + RotL64(aScatter, 11U)) + 6642872057476351588U) + aOrbiterAssignSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = ((aWandererI + RotL64(aIngress, 23U)) + RotL64(aCarry, 3U)) + 660732654689529192U;
            aOrbiterA = ((aWandererG + RotL64(aPrevious, 30U)) + 7235418086884000655U) + aNonceWordJ;
            aOrbiterH = (((aWandererE + RotL64(aScatter, 5U)) + RotL64(aCarry, 57U)) + 14784518476694580493U) + aOrbiterAssignSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterE = (aWandererJ + RotL64(aCross, 51U)) + 12222433977933449375U;
            aOrbiterB = (aWandererA + RotL64(aPrevious, 35U)) + 8573001207708329927U;
            aOrbiterC = (aWandererB + RotL64(aIngress, 47U)) + 16035256260815013172U;
            aOrbiterI = (aWandererK + RotL64(aScatter, 53U)) + 15767726974121910203U;
            aOrbiterK = ((aWandererD + RotL64(aPrevious, 14U)) + 17712217935322939971U) + aNonceWordH;
            aOrbiterD = (((aWandererF + RotL64(aCross, 39U)) + RotL64(aCarry, 11U)) + 13488963456923357159U) + aNonceWordN;
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 10222949131965611079U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 1495561412321657209U;
            aOrbiterJ = RotL64((aOrbiterJ * 9706305581868526265U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 16156530750584361434U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 7773792489045606309U) ^ aOrbiterUpdateSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 10730624207715601393U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 11544578291333360613U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 3665587867634242865U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 4840528190844842595U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 15248434984650998090U) + aNonceWordL;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 15487979645426567581U;
            aOrbiterI = RotL64((aOrbiterI * 10868107809356766183U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 6972347795052712690U) + aNonceWordM;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 16074994810010431338U;
            aOrbiterK = RotL64((aOrbiterK * 1262655238856775853U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 16851139687900415292U) + aNonceWordI;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 14630026837021552812U;
            aOrbiterC = RotL64((aOrbiterC * 9577900853521254603U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 14236330619137368169U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 17778707026111136216U;
            aOrbiterD = RotL64((aOrbiterD * 16239561893843454747U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 9390961969105999083U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 1174881758316573228U;
            aOrbiterH = RotL64((aOrbiterH * 6602061268277529311U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 3025148570039849574U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 2813499258480831171U;
            aOrbiterF = RotL64((aOrbiterF * 12272555492688861861U), 41U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterD) + 15397952138592662354U) + aOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1]) + aNonceWordA;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 10394648143430175275U;
            aOrbiterG = RotL64((aOrbiterG * 18195627209519212303U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 3043205345760158739U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 15316464782468770057U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 8162506622688910545U), 43U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterF, 40U);
            aIngress = aIngress + (RotL64(aOrbiterA, 43U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 37U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 27U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 11U));
            aIngress = aIngress + RotL64(aOrbiterJ, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aCross, 5U) + RotL64(aOrbiterH, 35U)) + aOrbiterG) + aNonceWordE);
            aWandererB = aWandererB + (((RotL64(aIngress, 41U) + aOrbiterE) + RotL64(aOrbiterI, 53U)) + RotL64(aCarry, 23U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 23U) + aOrbiterB) + RotL64(aOrbiterG, 13U)) + aWandererUpdateSaltE[((aIndex + 3U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 18U) + RotL64(aOrbiterA, 30U)) + aOrbiterF);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterK, 51U)) + aOrbiterC);
            aWandererH = aWandererH + (((RotL64(aCross, 39U) + RotL64(aOrbiterI, 41U)) + aOrbiterK) + aWandererUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 57U) + aOrbiterJ) + RotL64(aOrbiterH, 5U));
            aWandererF = aWandererF + ((RotL64(aScatter, 29U) + aOrbiterF) + RotL64(aOrbiterI, 21U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 46U) + RotL64(aOrbiterB, 39U)) + aOrbiterA);
            aWandererK = aWandererK + ((((RotL64(aScatter, 27U) + aOrbiterD) + RotL64(aOrbiterC, 3U)) + RotL64(aCarry, 11U)) + aNonceWordK);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterG, 48U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererD, 60U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererE, 47U) ^ aWandererK);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 41U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 23U));
            aCarry = aCarry + (RotL64(aWandererH, 56U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererF, 11U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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

void TwistExpander_Hockey_Arx::KDF_A_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xEEDDFCFC9146BE85ULL + 0xFED695462DB77A62ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xBB78CDB4F06C28BFULL + 0xB23EA6EEF288B47EULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xF01BC91966284ABDULL + 0xB9CD404F129ECCE0ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x960289A95FD8C673ULL + 0x9229DD546E87BA4CULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xF1D34AEF54E890C3ULL + 0xEBAC5EDB0257F956ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xE23DF73277F3F6A7ULL + 0xB099E169E2D36272ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xED7BC3DF011143BBULL + 0xF3914395046F1B07ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xEFFCC65ACB09BCE7ULL + 0x8ABB0D8557A403E7ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xE9CCA76B32733921ULL + 0xA107F0008A06D803ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xDC724371CB292F79ULL + 0x8142F2B0CE83D078ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xB4B1666DB5F5E009ULL + 0xEB15A978FA8BAC13ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0x9F3E48F881BCF77BULL + 0xC6452016E1078CCDULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xC1B0BFC3835B6197ULL + 0xBDDE986275781185ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xAC6C94FC0204019DULL + 0x960754107DB6C92FULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x8C9888835CB1A1D3ULL + 0x8FC14C2B1CC4567BULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0x8A7A4E340F477CE5ULL + 0x90F5921827E00906ULL);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 1190U)) & S_BLOCK1], 23U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 5000U)) & S_BLOCK1], 52U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 2874U)) & S_BLOCK1], 58U) ^ RotL64(aFireLaneD[((aIndex + 5333U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aPrevious, 21U) + RotL64(aCarry, 41U)) ^ (RotL64(aIngress, 54U) ^ RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterB = (aWandererD + RotL64(aCross, 5U)) + 18180797995100240808U;
            aOrbiterG = (aWandererA + RotL64(aIngress, 51U)) + 6585906608223552885U;
            aOrbiterE = ((aWandererB + RotL64(aScatter, 30U)) + 14088708930575939855U) + aOrbiterAssignSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = (((aWandererK + RotL64(aPrevious, 11U)) + RotL64(aCarry, 5U)) + 468974153311516044U) + aNonceWordO;
            aOrbiterH = (((aWandererH + RotL64(aIngress, 47U)) + RotL64(aCarry, 27U)) + 12481951025619894110U) + aOrbiterAssignSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = (aWandererC + RotL64(aPrevious, 35U)) + 17227987923860711763U;
            aOrbiterF = (((aWandererG + RotL64(aScatter, 41U)) + RotL64(aCarry, 51U)) + 4373962756657477139U) + aNonceWordD;
            aOrbiterK = (aWandererE + RotL64(aCross, 57U)) + 2077576476565420951U;
            aOrbiterD = (aWandererJ + RotL64(aScatter, 24U)) + 17435011300234663764U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 4118039398293246896U) + aOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 13724716599855216683U;
            aOrbiterE = RotL64((aOrbiterE * 17556333902751079677U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 12391461204689596339U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 9900605191533799627U;
            aOrbiterH = RotL64((aOrbiterH * 13553565332531046301U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 972946858824366125U) + aOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 17247681919694541215U;
            aOrbiterB = RotL64((aOrbiterB * 2974639094630445643U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 15442851427306771601U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 7303586227288294037U;
            aOrbiterG = RotL64((aOrbiterG * 15406402525021428799U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 12650358753454105119U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 1483710933373510492U) ^ aNonceWordM;
            aOrbiterD = RotL64((aOrbiterD * 6531763256577221891U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 18065810162229740788U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 11311677121338794007U;
            aOrbiterF = RotL64((aOrbiterF * 15116367961682119467U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 2355285311890287611U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = (((aOrbiterK ^ aOrbiterH) ^ 1287783821903407734U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterK = RotL64((aOrbiterK * 8054011680932255985U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 9282654686791135654U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 15488608017745542551U) ^ aNonceWordN;
            aOrbiterJ = RotL64((aOrbiterJ * 7858866274035085123U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 13296835576073421802U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 7127700236018338741U;
            aOrbiterA = RotL64((aOrbiterA * 11246173563106014149U), 53U);
            //
            aIngress = RotL64(aOrbiterH, 57U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 30U));
            aIngress = aIngress + (RotL64(aOrbiterG, 13U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 53U));
            aIngress = aIngress + RotL64(aOrbiterF, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aIngress, 29U) + RotL64(aOrbiterB, 47U)) + aOrbiterJ) + RotL64(aCarry, 39U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 38U) + aOrbiterG) + RotL64(aOrbiterF, 19U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterE, 5U)) + aOrbiterB) + aNonceWordA);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterD, 52U)) + aOrbiterA);
            aWandererE = aWandererE + ((((RotL64(aCross, 5U) + RotL64(aOrbiterA, 35U)) + aOrbiterJ) + RotL64(aCarry, 5U)) + aNonceWordL);
            aWandererA = aWandererA ^ ((((RotL64(aScatter, 23U) + RotL64(aOrbiterA, 57U)) + aOrbiterG) + aNonceWordP) + aWandererUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 53U) + aOrbiterA) + RotL64(aOrbiterK, 41U)) + aNonceWordE);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 19U) + RotL64(aOrbiterH, 10U)) + aOrbiterE) + aWandererUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aIngress, 42U) + RotL64(aOrbiterE, 23U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererG, 47U) ^ aWandererD);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 5U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 35U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 13U));
            aCarry = aCarry + RotL64(aWandererC, 56U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 12040U)) & S_BLOCK1], 29U) ^ RotL64(aFireLaneB[((aIndex + 11059U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 9662U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 9227U)) & S_BLOCK1], 5U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 14300U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aPrevious, 24U) ^ RotL64(aCarry, 11U)) + (RotL64(aIngress, 57U) ^ RotL64(aCross, 37U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterK = ((aWandererD + RotL64(aScatter, 30U)) + RotL64(aCarry, 27U)) + 9855743441035905047U;
            aOrbiterB = (((aWandererG + RotL64(aCross, 3U)) + RotL64(aCarry, 35U)) + 8426286937143990276U) + aNonceWordB;
            aOrbiterI = ((aWandererH + RotL64(aPrevious, 39U)) + RotL64(aCarry, 43U)) + 7146752367170267002U;
            aOrbiterJ = ((aWandererE + RotL64(aIngress, 47U)) + 12947210066678101726U) + aOrbiterAssignSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterE = (((aWandererF + RotL64(aPrevious, 56U)) + 15902163559925328965U) + aOrbiterAssignSaltF[((aIndex + 11U)) & S_SALT1]) + aNonceWordP;
            aOrbiterD = ((aWandererA + RotL64(aIngress, 51U)) + 8506649889346449469U) + aNonceWordK;
            aOrbiterC = (aWandererK + RotL64(aCross, 35U)) + 8226286036430263052U;
            aOrbiterF = (aWandererI + RotL64(aScatter, 23U)) + 2703047093452420216U;
            aOrbiterA = ((aWandererC + RotL64(aPrevious, 11U)) + 6769351326360139560U) + aNonceWordN;
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 9857025533281333281U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 238297452132277585U) ^ aNonceWordJ;
            aOrbiterI = RotL64((aOrbiterI * 12974709749856065985U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 7203572312072908931U) + aOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 12497027346166575632U;
            aOrbiterE = RotL64((aOrbiterE * 1703586436725662307U), 29U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterC) + 473851890609048879U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordD;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 1664484956453886047U;
            aOrbiterK = RotL64((aOrbiterK * 8566500756326590209U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 4635095143004754116U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 17695676150967345793U;
            aOrbiterJ = RotL64((aOrbiterJ * 5780416541584439301U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 15628965269863402796U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 9190117464399730235U;
            aOrbiterA = RotL64((aOrbiterA * 5586437438425999715U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 17835918238346011086U) + aOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 4398005402429282682U) ^ aNonceWordM;
            aOrbiterC = RotL64((aOrbiterC * 14828737209913317463U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 10902589938246551273U) + aOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 15124274429081385923U;
            aOrbiterF = RotL64((aOrbiterF * 13524180348258805367U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 8747233520702236018U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 5445611443463112371U;
            aOrbiterB = RotL64((aOrbiterB * 10294109295823410447U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 16296005217836151910U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 6468336224317602364U;
            aOrbiterD = RotL64((aOrbiterD * 7369779919748367133U), 23U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterI, 60U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 51U));
            aIngress = aIngress + (RotL64(aOrbiterA, 39U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterF, 43U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterK, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aPrevious, 11U) + aOrbiterI) + RotL64(aOrbiterJ, 48U)) + aNonceWordC);
            aWandererE = aWandererE ^ ((((RotL64(aScatter, 28U) + aOrbiterI) + RotL64(aOrbiterC, 39U)) + aNonceWordI) + aWandererUpdateSaltD[((aIndex + 17U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aIngress, 23U) + aOrbiterA) + RotL64(aOrbiterK, 5U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 47U) + aOrbiterE) + RotL64(aOrbiterK, 23U)) + aNonceWordL);
            aWandererK = aWandererK + ((((RotL64(aScatter, 53U) + RotL64(aOrbiterF, 57U)) + aOrbiterD) + RotL64(aCarry, 11U)) + aWandererUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterJ, 43U)) + aOrbiterK) + aNonceWordH);
            aWandererF = aWandererF + (((RotL64(aPrevious, 35U) + aOrbiterE) + RotL64(aOrbiterD, 27U)) + RotL64(aCarry, 41U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 60U) + aOrbiterF) + RotL64(aOrbiterA, 11U));
            aWandererH = aWandererH + ((RotL64(aPrevious, 39U) + aOrbiterE) + RotL64(aOrbiterB, 52U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 12U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererC, 35U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererK, 3U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererD, 28U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 17935U)) & S_BLOCK1], 35U) ^ RotL64(aFireLaneD[((aIndex + 19107U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 20288U)) & S_BLOCK1], 44U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 22150U)) & S_BLOCK1], 52U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 22581U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aFireLaneC[((aIndex + 24329U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aPrevious, 47U) ^ RotL64(aCross, 19U)) ^ (RotL64(aCarry, 60U) + RotL64(aIngress, 35U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterK = ((aWandererD + RotL64(aPrevious, 24U)) + 11177787645248006236U) + aNonceWordI;
            aOrbiterA = (((aWandererE + RotL64(aIngress, 47U)) + RotL64(aCarry, 51U)) + 3808340254579817169U) + aOrbiterAssignSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = ((aWandererB + RotL64(aCross, 57U)) + RotL64(aCarry, 39U)) + 828030667598518279U;
            aOrbiterI = ((aWandererA + RotL64(aScatter, 35U)) + RotL64(aCarry, 3U)) + 16177835921238398371U;
            aOrbiterE = (aWandererC + RotL64(aPrevious, 4U)) + 5518747735458708741U;
            aOrbiterJ = (aWandererK + RotL64(aScatter, 43U)) + 17346319082399995165U;
            aOrbiterB = (aWandererF + RotL64(aIngress, 13U)) + 6397156921893030937U;
            aOrbiterF = ((aWandererI + RotL64(aCross, 51U)) + 15559381654710713582U) + aNonceWordM;
            aOrbiterC = ((aWandererG + RotL64(aPrevious, 19U)) + 940404446491415088U) + aOrbiterAssignSaltD[((aIndex + 4U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 8047166032048732645U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 4688468645859470491U;
            aOrbiterD = RotL64((aOrbiterD * 14383536431614496369U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 3710878044770337260U) + aNonceWordB;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 116343189456629220U;
            aOrbiterA = RotL64((aOrbiterA * 5637725064169289339U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 883908030159391659U) + aNonceWordK;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 18058691521694880482U;
            aOrbiterB = RotL64((aOrbiterB * 3132200449123497619U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 17521015077103586117U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 3668332225435714918U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 12658899101297839881U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 12229480388278883300U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 16206524049491531816U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 11122340196620859805U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 5743265849441077466U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 2812293020719282236U;
            aOrbiterF = RotL64((aOrbiterF * 8903956475200417109U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 13718364781538837074U) + aNonceWordJ;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 861529717259766236U;
            aOrbiterC = RotL64((aOrbiterC * 17019744777211266685U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 4862687502126693872U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 7722024283321020761U;
            aOrbiterK = RotL64((aOrbiterK * 18086944039541060829U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 8205803118233399853U) + aOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 15130160926615050422U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 1454552751453996765U), 11U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterI, 23U);
            aIngress = aIngress + (RotL64(aOrbiterE, 57U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 40U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 3U));
            aIngress = aIngress + RotL64(aOrbiterF, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aScatter, 37U) + RotL64(aOrbiterD, 3U)) + aOrbiterA);
            aWandererE = aWandererE ^ ((((RotL64(aIngress, 11U) + aOrbiterA) + RotL64(aOrbiterI, 42U)) + aNonceWordH) + aWandererUpdateSaltC[((aIndex + 18U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aPrevious, 57U) + aOrbiterD) + RotL64(aOrbiterB, 11U)) + aNonceWordA);
            aWandererI = aWandererI ^ ((RotL64(aCross, 3U) + aOrbiterI) + RotL64(aOrbiterC, 19U));
            aWandererB = aWandererB + ((RotL64(aScatter, 20U) + RotL64(aOrbiterB, 51U)) + aOrbiterK);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterF, 37U)) + aOrbiterC);
            aWandererF = aWandererF + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterC, 29U)) + aOrbiterE) + RotL64(aCarry, 41U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 41U) + RotL64(aOrbiterK, 24U)) + aOrbiterF) + aWandererUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 24U) + RotL64(aOrbiterJ, 47U)) + aOrbiterB) + RotL64(aCarry, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 23U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererB, 18U) ^ aWandererK);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 39U));
            aCarry = aCarry + (RotL64(aWandererA, 11U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererD, 53U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 28959U)) & S_BLOCK1], 35U) ^ RotL64(aFireLaneC[((aIndex + 26409U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 27321U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 29152U)) & S_BLOCK1], 29U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 30395U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 32219U)) & S_BLOCK1], 48U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aPrevious, 13U) + RotL64(aCarry, 43U)) ^ (RotL64(aCross, 28U) ^ RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterB = (((aWandererD + RotL64(aPrevious, 23U)) + RotL64(aCarry, 51U)) + 12632404972795375757U) + aNonceWordP;
            aOrbiterA = (((aWandererI + RotL64(aIngress, 57U)) + RotL64(aCarry, 43U)) + 5351879979055988456U) + aOrbiterAssignSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterI = ((aWandererJ + RotL64(aCross, 4U)) + 3597737727467443413U) + aNonceWordM;
            aOrbiterG = (((aWandererA + RotL64(aScatter, 35U)) + RotL64(aCarry, 27U)) + 2830846754917852318U) + aOrbiterAssignSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = (aWandererH + RotL64(aPrevious, 11U)) + 17311925960294518018U;
            aOrbiterH = (aWandererE + RotL64(aCross, 39U)) + 2083584640523695383U;
            aOrbiterC = (aWandererG + RotL64(aIngress, 30U)) + 15049343611387010158U;
            aOrbiterF = (aWandererK + RotL64(aScatter, 43U)) + 6443050378205811147U;
            aOrbiterJ = (aWandererF + RotL64(aCross, 19U)) + 6021965178697344070U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 5080289878758029976U) + aNonceWordB;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 576927745306972983U;
            aOrbiterI = RotL64((aOrbiterI * 16008958833683246115U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 4728489691382690859U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 6184355840165758855U) ^ aNonceWordA;
            aOrbiterK = RotL64((aOrbiterK * 1515043910404156423U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 11220539885798595450U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 11091438724966718214U) ^ aOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8225347114759391961U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 17184210490020062419U) + aOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 2150997767099116408U;
            aOrbiterG = RotL64((aOrbiterG * 8058553821648892499U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 7021953562676903717U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 17159676348343312834U) ^ aNonceWordC;
            aOrbiterJ = RotL64((aOrbiterJ * 13877284519668483549U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 10367891770525239784U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 11922478487264201233U;
            aOrbiterA = RotL64((aOrbiterA * 9195137452661956029U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 17815162358981720634U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterF) ^ 9582631251085100284U) ^ aOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterH = RotL64((aOrbiterH * 11838992994130850483U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 872593750259572264U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 17832330100262167302U;
            aOrbiterF = RotL64((aOrbiterF * 1114416841510028467U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 16601139856969287418U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 14931287111691324985U;
            aOrbiterB = RotL64((aOrbiterB * 16757174577841001179U), 11U);
            //
            aIngress = RotL64(aOrbiterJ, 19U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 3U));
            aIngress = aIngress + (RotL64(aOrbiterA, 51U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 57U));
            aIngress = aIngress + RotL64(aOrbiterK, 10U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aIngress, 57U) + aOrbiterF) + RotL64(aOrbiterA, 19U)) + RotL64(aCarry, 41U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 12U) + RotL64(aOrbiterB, 53U)) + aOrbiterA);
            aWandererI = aWandererI + ((((RotL64(aCross, 27U) + aOrbiterI) + RotL64(aOrbiterG, 12U)) + RotL64(aCarry, 21U)) + aNonceWordH);
            aWandererG = aWandererG ^ ((((RotL64(aScatter, 39U) + aOrbiterI) + RotL64(aOrbiterF, 57U)) + aNonceWordD) + aWandererUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 47U) + aOrbiterA) + RotL64(aOrbiterG, 23U)) + aNonceWordE);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterK, 5U)) + aOrbiterG);
            aWandererA = aWandererA + (((RotL64(aPrevious, 22U) + aOrbiterJ) + RotL64(aOrbiterH, 35U)) + aWandererUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterH, 48U)) + aOrbiterI);
            aWandererK = aWandererK + ((RotL64(aIngress, 53U) + RotL64(aOrbiterH, 41U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 35U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererI, 54U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererD, 29U) ^ aWandererG);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 43U));
            aCarry = aCarry + RotL64(aWandererK, 39U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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

void TwistExpander_Hockey_Arx::KDF_A_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x829C5B61130D3429ULL + 0x9B491B3E1468D2BAULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x90298991DBA2D551ULL + 0xEEBC09993E927747ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xE5975EA1D2226F9FULL + 0xD4484F485FB6F417ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xE13A179F9115962DULL + 0xE01CE5788C62B5F2ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xF702BC77340A2A91ULL + 0x88F2069FF0776975ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xEB2DB82D787B537FULL + 0x8297E0060004E88CULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xC884F9F1A2FDE145ULL + 0xE2A66090929705C6ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xE1214DD1D49821BFULL + 0xB38AB6F500EA9651ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xE019D029D335ACB3ULL + 0xF8A56BDB7C4F96DFULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x808EC93945AC8CB3ULL + 0x832B423ECC4ADF1FULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x9EDB7B04F42BC12BULL + 0x8D76A1110AAFE1A5ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xFCC1CE6CA4E58197ULL + 0x971FCBB5D4DED79FULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xAD2695D39201B25FULL + 0xFB1B812F30A2A30AULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xEDC78507C11B0A79ULL + 0xF5017F1AB8C3A870ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xC6336CD0A9A54719ULL + 0xF59184360610B04EULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0x85691F9FD345BC9FULL + 0xF4118225B3BEFB5AULL);
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
        // read from: aOperationLaneA, aOperationLaneB, aFireLaneB, aOperationLaneC, aOperationLaneD, aWorkLaneA, aFireLaneA, aWorkLaneB, aFireLaneC, aWorkLaneC, aFireLaneD
        // write to: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // kdf_a_loop_c loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aFireLaneB
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aFireLaneB forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 2847U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneB[((aIndex + 1544U)) & S_BLOCK1], 52U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 1896U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 1482U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneD[((aIndex + 1725U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aIngress, 4U) ^ RotL64(aCarry, 53U)) + (RotL64(aPrevious, 41U) + RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterI = (((aWandererH + RotL64(aScatter, 47U)) + RotL64(aCarry, 39U)) + 9751314027302668907U) + aNonceWordN;
            aOrbiterE = (aWandererA + RotL64(aCross, 29U)) + 12175450995523107056U;
            aOrbiterG = ((((aWandererC + RotL64(aIngress, 3U)) + RotL64(aCarry, 53U)) + 17519694958730119552U) + aOrbiterAssignSaltB[((aIndex + 9U)) & S_SALT1]) + aNonceWordI;
            aOrbiterA = (((aWandererJ + RotL64(aPrevious, 19U)) + RotL64(aCarry, 19U)) + 9093525527925682263U) + aNonceWordA;
            aOrbiterC = (((aWandererG + RotL64(aScatter, 58U)) + 3713831321786810138U) + aOrbiterAssignSaltF[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordK;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 10108355209191835040U) + aOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 12956307447311314768U;
            aOrbiterG = RotL64((aOrbiterG * 9198936928658626667U), 13U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterI) + 1904298513945877359U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordG;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 4658049993308574460U;
            aOrbiterE = RotL64((aOrbiterE * 10482422152074338611U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 9826333658248851902U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 12058666914724365134U) ^ aNonceWordH;
            aOrbiterI = RotL64((aOrbiterI * 964233873188373939U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 2516574707110528099U) + aOrbiterUpdateSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 13335308331049750235U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5880227828760598587U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 8230749255538495304U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 16536559486797811486U;
            aOrbiterC = RotL64((aOrbiterC * 7097036838156464969U), 43U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterA, 5U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 29U));
            aIngress = aIngress + RotL64(aOrbiterC, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aScatter, 37U) + aOrbiterA) + RotL64(aOrbiterE, 57U)) + RotL64(aCarry, 51U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 60U) + RotL64(aOrbiterC, 37U)) + aOrbiterI) + aWandererUpdateSaltD[((aIndex + 5U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aIngress, 19U) + aOrbiterG) + RotL64(aOrbiterA, 13U)) + RotL64(aCarry, 5U)) + aNonceWordB);
            aWandererC = aWandererC ^ ((((RotL64(aCross, 29U) + aOrbiterE) + RotL64(aOrbiterI, 48U)) + aNonceWordE) + aWandererUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 5U) + RotL64(aOrbiterC, 5U)) + aOrbiterE) + aNonceWordL);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 3U));
            aCarry = aCarry + (RotL64(aWandererG, 29U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererH, 54U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // kdf_a_loop_c loop 2
        // ingress from: aWorkLaneA, aOperationLaneC, aFireLaneA
        // ingress directions: aWorkLaneA forward forced, aOperationLaneC forward forced, aFireLaneA forward/backward random
        // cross from: aOperationLaneA, aOperationLaneD, aOperationLaneB
        // cross directions: aOperationLaneA backward forced, aOperationLaneD backward forced, aOperationLaneB backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 12291U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneC[((aIndex + 13616U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 15119U)) & S_BLOCK1], 24U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 13115U)) & S_BLOCK1], 4U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 9010U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aOperationLaneB[((aIndex + 15415U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aIngress, 58U) ^ RotL64(aCarry, 41U)) + (RotL64(aCross, 13U) ^ RotL64(aPrevious, 29U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterC = ((aWandererK + RotL64(aPrevious, 35U)) + 77518479758428414U) + aOrbiterAssignSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = (((aWandererJ + RotL64(aScatter, 47U)) + RotL64(aCarry, 57U)) + 4832061802166300011U) + aNonceWordJ;
            aOrbiterE = (((aWandererG + RotL64(aCross, 23U)) + RotL64(aCarry, 11U)) + 11695291171006574112U) + aNonceWordI;
            aOrbiterF = ((((aWandererF + RotL64(aIngress, 3U)) + RotL64(aCarry, 43U)) + 7467412817843260094U) + aOrbiterAssignSaltE[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordP;
            aOrbiterI = ((aWandererD + RotL64(aCross, 58U)) + 17801484124471154757U) + aNonceWordB;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 5555455638503958639U) + aOrbiterUpdateSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 5669470540733721606U;
            aOrbiterE = RotL64((aOrbiterE * 17219613748084498879U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 3042388456327784163U) + aNonceWordA;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 2236734925228156691U;
            aOrbiterC = RotL64((aOrbiterC * 10076582424701705531U), 11U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterC) + 14459720401528685450U) + aOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1]) + aNonceWordM;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 4814967631216658856U;
            aOrbiterF = RotL64((aOrbiterF * 18288097536171386643U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 16950679344449075945U) + aNonceWordN;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 6262238639302011050U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9942659897425088183U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 3522256359074996724U) + aNonceWordL;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 12524717897707074242U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 6787771338063891989U), 43U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterF, 3U);
            aIngress = aIngress + (RotL64(aOrbiterB, 47U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterI, 30U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((((RotL64(aScatter, 3U) + RotL64(aOrbiterF, 41U)) + aOrbiterB) + aNonceWordE) + aWandererUpdateSaltE[((aIndex + 5U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aIngress, 11U) + RotL64(aOrbiterI, 27U)) + aOrbiterC) + RotL64(aCarry, 13U)) + aNonceWordC);
            aWandererD = aWandererD ^ ((RotL64(aCross, 47U) + aOrbiterI) + RotL64(aOrbiterE, 56U));
            aWandererK = aWandererK + ((((RotL64(aPrevious, 27U) + aOrbiterC) + RotL64(aOrbiterB, 3U)) + RotL64(aCarry, 43U)) + aNonceWordK);
            aWandererG = aWandererG ^ ((((RotL64(aScatter, 38U) + RotL64(aOrbiterF, 19U)) + aOrbiterE) + aNonceWordF) + aWandererUpdateSaltC[((aIndex + 8U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 5U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 51U));
            aCarry = aCarry + RotL64(aWandererF, 21U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 17176U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneD[((aIndex + 20815U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 18437U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18057U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 24048U)) & S_BLOCK1], 53U));
            aCross ^= RotL64(aOperationLaneC[((aIndex + 20511U)) & S_BLOCK1], 40U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aIngress, 21U) ^ RotL64(aCarry, 3U)) + (RotL64(aPrevious, 51U) + RotL64(aCross, 34U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterH = (((aWandererJ + RotL64(aCross, 4U)) + RotL64(aCarry, 3U)) + 5131645209694953015U) + aOrbiterAssignSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = (((aWandererF + RotL64(aIngress, 37U)) + 12070391048835379854U) + aOrbiterAssignSaltD[((aIndex + 11U)) & S_SALT1]) + aNonceWordL;
            aOrbiterB = (((aWandererD + RotL64(aPrevious, 47U)) + RotL64(aCarry, 51U)) + 2604295836242338724U) + aNonceWordN;
            aOrbiterK = (((aWandererA + RotL64(aScatter, 23U)) + RotL64(aCarry, 35U)) + 14042039029284001596U) + aNonceWordO;
            aOrbiterE = ((aWandererH + RotL64(aIngress, 13U)) + 8914654543854559327U) + aNonceWordP;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 2185619407969359869U) + aNonceWordE;
            aOrbiterB = (((aOrbiterB ^ aOrbiterH) ^ 5187406295103352574U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterB = RotL64((aOrbiterB * 10497064008152537837U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 8022832481290871217U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 8783061916740573472U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 3309891377744201773U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 10711028365596196301U) + aOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 13387065038269133571U) ^ aOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 12444578026365205255U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 11187001318931801582U) + aNonceWordJ;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 14191473173276034019U;
            aOrbiterK = RotL64((aOrbiterK * 2491253922434756431U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 16207761776716426435U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 9677408414452078760U;
            aOrbiterE = RotL64((aOrbiterE * 5487303383095129949U), 47U);
            //
            aIngress = RotL64(aOrbiterH, 36U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterE, 57U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterI, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aPrevious, 3U) + RotL64(aOrbiterK, 5U)) + aOrbiterH) + RotL64(aCarry, 47U)) + aNonceWordD);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 43U) + aOrbiterE) + RotL64(aOrbiterB, 29U));
            aWandererD = aWandererD + (((RotL64(aCross, 13U) + aOrbiterH) + RotL64(aOrbiterI, 53U)) + aWandererUpdateSaltB[((aIndex + 26U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 29U) + aOrbiterI) + RotL64(aOrbiterB, 42U)) + aWandererUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aIngress, 58U) + RotL64(aOrbiterK, 21U)) + aOrbiterE) + RotL64(aCarry, 19U)) + aNonceWordG);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 13U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 21U));
            aCarry = aCarry + RotL64(aWandererJ, 57U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 29096U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneA[((aIndex + 31215U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 30926U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26267U)) & S_BLOCK1], 52U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 30079U)) & S_BLOCK1], 11U));
            aCross ^= (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 31895U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 25303U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCross, 41U) + RotL64(aPrevious, 28U)) ^ (RotL64(aCarry, 13U) ^ RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterJ = ((aWandererC + RotL64(aIngress, 39U)) + RotL64(aCarry, 47U)) + 1142447269198373880U;
            aOrbiterD = (((aWandererD + RotL64(aScatter, 19U)) + RotL64(aCarry, 3U)) + 10581460640040336191U) + aNonceWordE;
            aOrbiterA = ((aWandererJ + RotL64(aPrevious, 29U)) + 14703062773878202900U) + aOrbiterAssignSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = ((aWandererE + RotL64(aCross, 4U)) + RotL64(aCarry, 19U)) + 15737525756286914746U;
            aOrbiterC = (((aWandererG + RotL64(aScatter, 51U)) + 16178774478273186999U) + aOrbiterAssignSaltF[((aIndex + 18U)) & S_SALT1]) + aNonceWordC;
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterD) + 2514897053906809160U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordF;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 13702496607592508464U;
            aOrbiterA = RotL64((aOrbiterA * 16540143680974064057U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 18030885275418337965U) + aNonceWordN;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 5241783876161655984U;
            aOrbiterI = RotL64((aOrbiterI * 10970981186787227937U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 2807052676283587925U) + aOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 8022804576763271327U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 11727096043219370577U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 15597099852232205860U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 1538435607932096400U) ^ aNonceWordK;
            aOrbiterC = RotL64((aOrbiterC * 7900752511710516981U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 11147868774413615365U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 9325213746830411568U;
            aOrbiterD = RotL64((aOrbiterD * 561819005818948769U), 23U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterD, 37U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 47U));
            aIngress = aIngress + RotL64(aOrbiterC, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((((RotL64(aPrevious, 19U) + RotL64(aOrbiterC, 29U)) + aOrbiterI) + aNonceWordJ) + aWandererUpdateSaltF[((aIndex + 27U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aCross, 53U) + RotL64(aOrbiterA, 21U)) + aOrbiterD) + RotL64(aCarry, 11U)) + aNonceWordI);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterA, 38U)) + aOrbiterC);
            aWandererE = aWandererE + (((((RotL64(aScatter, 5U) + RotL64(aOrbiterA, 3U)) + aOrbiterI) + RotL64(aCarry, 51U)) + aNonceWordH) + aWandererUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aCross, 28U) + RotL64(aOrbiterC, 53U)) + aOrbiterJ) + aNonceWordG);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 13U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 58U));
            aCarry = aCarry + RotL64(aWandererJ, 5U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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

void TwistExpander_Hockey_Arx::KDF_A_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xA21C88548572F4E3ULL + 0x811C5CF328EC56BBULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xE1BC20F07774C271ULL + 0xA53CC2CAC6C10B2AULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xC925F82A450BFACFULL + 0x8D6888ED4D82AD12ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x9634C96F7DDC63EFULL + 0x9DCFC5C12BE79D36ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x8C0F6B2292D67DBFULL + 0x992E0DB46504E5CCULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x8852E9A749C6AA0BULL + 0xBE120475843EC7ACULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xBFEF1D5B1F84F767ULL + 0xCB0CBEC0ACC94A8EULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x89A7BED7151CC3CBULL + 0xE3230CAB4F585749ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xD95D24557A57F3F3ULL + 0xD2E6D33895714544ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xA68E3FDC447BBBAFULL + 0xE27D88DAC760C827ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xB77A4609569B9B01ULL + 0xCA2644261AAB8EBAULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xDC1077DFBE93FABFULL + 0xFD60AC36F1AFC0C1ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xA632646C5594355BULL + 0xAE141EDE0E6B6FC3ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xD832499D83732641ULL + 0xE7B0ED9A920BBAF8ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xB2DE3A8B921E2127ULL + 0xA839D13B720E4A7FULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0x824AD224F97E0E0BULL + 0xE0C470A909E542DAULL);
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
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneC, aExpandLaneC, aExpandLaneD, aFireLaneD, aWorkLaneA, aOperationLaneD, aOperationLaneB, aWorkLaneB, aOperationLaneA, aFireLaneB, aWorkLaneC, aOperationLaneC, aFireLaneA
        // write to: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // kdf_a_loop_d loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aFireLaneC
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aFireLaneC forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD, aFireLaneD
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward forced, aFireLaneD backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 7655U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneB[((aIndex + 1463U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 3801U)) & S_BLOCK1], 54U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 7234U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 7302U)) & S_BLOCK1], 34U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 6712U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aIngress, 23U) ^ RotL64(aCarry, 51U)) + (RotL64(aPrevious, 5U) ^ RotL64(aCross, 38U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterG = (aWandererF + RotL64(aCross, 19U)) + 5171470532667965920U;
            aOrbiterH = ((aWandererD + RotL64(aIngress, 13U)) + RotL64(aCarry, 51U)) + 750549462358682403U;
            aOrbiterB = (((aWandererC + RotL64(aScatter, 58U)) + RotL64(aCarry, 29U)) + 3325689257577120525U) + aOrbiterAssignSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterA = (((aWandererH + RotL64(aPrevious, 5U)) + RotL64(aCarry, 11U)) + 18031575461559790826U) + aNonceWordL;
            aOrbiterC = ((aWandererG + RotL64(aScatter, 27U)) + 13874739537012288677U) + aNonceWordD;
            aOrbiterD = (((aWandererJ + RotL64(aIngress, 41U)) + 4250029868785016865U) + aOrbiterAssignSaltC[((aIndex + 25U)) & S_SALT1]) + aNonceWordI;
            aOrbiterI = ((aWandererB + RotL64(aCross, 35U)) + 8211158803112611161U) + aNonceWordF;
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 1083939790236786027U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 3446525462376962464U;
            aOrbiterB = RotL64((aOrbiterB * 13603702473750888213U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 6973817815000417325U) + aNonceWordN;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 15230876489676945543U;
            aOrbiterC = RotL64((aOrbiterC * 7737039082964537651U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 9359727659738755880U) + aNonceWordP;
            aOrbiterI = (((aOrbiterI ^ aOrbiterD) ^ 8775170107816327654U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterI = RotL64((aOrbiterI * 6910680458261008653U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 11958941755525038545U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 16966819714283167348U;
            aOrbiterD = RotL64((aOrbiterD * 16363457661846050749U), 21U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 14556087985619763243U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 17915047508377045221U) ^ aNonceWordE;
            aOrbiterG = RotL64((aOrbiterG * 6727635453185130109U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 8578745677485367222U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 7002181668717618866U) ^ aOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 12329703532414955235U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 3569939503066735457U) + aOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 2956247934282522184U;
            aOrbiterA = RotL64((aOrbiterA * 9946650822131152531U), 5U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterC, 43U);
            aIngress = aIngress + (RotL64(aOrbiterG, 29U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 11U));
            aIngress = aIngress + RotL64(aOrbiterB, 58U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterB, 3U)) + aOrbiterD);
            aWandererD = aWandererD + (((RotL64(aScatter, 27U) + RotL64(aOrbiterB, 41U)) + aOrbiterA) + RotL64(aCarry, 29U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 57U) + aOrbiterD) + RotL64(aOrbiterA, 47U));
            aWandererB = aWandererB + (((((RotL64(aCross, 21U) + aOrbiterG) + RotL64(aOrbiterI, 53U)) + RotL64(aCarry, 47U)) + aNonceWordB) + aWandererUpdateSaltB[((aIndex + 9U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 13U) + aOrbiterA) + RotL64(aOrbiterG, 19U)) + aNonceWordG);
            aWandererG = aWandererG + (((RotL64(aCross, 51U) + RotL64(aOrbiterB, 27U)) + aOrbiterC) + aWandererUpdateSaltC[((aIndex + 27U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 4U) + aOrbiterH) + RotL64(aOrbiterA, 60U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 29U) ^ aWandererH);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 44U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 3U));
            aCarry = aCarry + RotL64(aWandererG, 23U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 2
        // ingress from: aWorkLaneA, aExpandLaneC, aOperationLaneD
        // ingress directions: aWorkLaneA forward forced, aExpandLaneC forward forced, aOperationLaneD forward/backward random
        // cross from: aExpandLaneA, aExpandLaneD, aOperationLaneB
        // cross directions: aExpandLaneA backward forced, aExpandLaneD backward forced, aOperationLaneB backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 12510U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneC[((aIndex + 11867U)) & S_BLOCK1], 20U));
            aIngress ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 11208U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 15207U)) & S_BLOCK1], 12U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 9433U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aOperationLaneB[((aIndex + 12274U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCarry, 43U) ^ RotL64(aIngress, 60U)) ^ (RotL64(aPrevious, 29U) + RotL64(aCross, 13U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterA = (((aWandererJ + RotL64(aScatter, 29U)) + RotL64(aCarry, 23U)) + 6318740973868639425U) + aNonceWordJ;
            aOrbiterG = ((((aWandererG + RotL64(aPrevious, 53U)) + RotL64(aCarry, 3U)) + 5487840061430920881U) + aOrbiterAssignSaltE[((aIndex + 20U)) & S_SALT1]) + aNonceWordD;
            aOrbiterJ = ((aWandererE + RotL64(aIngress, 5U)) + 10258706763248072672U) + aNonceWordH;
            aOrbiterB = ((aWandererI + RotL64(aCross, 23U)) + 18356875269730338208U) + aOrbiterAssignSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterD = ((aWandererB + RotL64(aScatter, 13U)) + 12883160282903147010U) + aNonceWordN;
            aOrbiterC = (aWandererC + RotL64(aCross, 60U)) + 1010140474942697730U;
            aOrbiterK = ((aWandererK + RotL64(aIngress, 43U)) + RotL64(aCarry, 43U)) + 17733939421700898293U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 13693055887924981201U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 14574732452793385269U;
            aOrbiterJ = RotL64((aOrbiterJ * 9373765929885750185U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 10832873941223609012U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterB) ^ 8212600587135328040U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterD = RotL64((aOrbiterD * 5334613996794796145U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 5312744319781971178U) + aOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 6173741211706546923U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 12854414066390848249U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 3693249147883790810U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 18365859989736602556U;
            aOrbiterB = RotL64((aOrbiterB * 3348463719324104997U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 10645056678337549771U) + aNonceWordG;
            aOrbiterA = (((aOrbiterA ^ aOrbiterC) ^ 1175668356822251045U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterA = RotL64((aOrbiterA * 6579675292775345579U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 13556844570541823717U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 4790355739411849736U;
            aOrbiterC = RotL64((aOrbiterC * 4083544011788850307U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 14905575502272644116U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 17047244574558476634U;
            aOrbiterG = RotL64((aOrbiterG * 2356386971503880047U), 29U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterA, 13U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 35U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 50U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterC, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aCross, 35U) + aOrbiterK) + RotL64(aOrbiterJ, 21U)) + aWandererUpdateSaltD[((aIndex + 28U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aScatter, 13U) + aOrbiterD) + RotL64(aOrbiterG, 46U)) + RotL64(aCarry, 35U)) + aNonceWordC);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 60U) + aOrbiterJ) + RotL64(aOrbiterG, 29U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 3U) + RotL64(aOrbiterK, 53U)) + aOrbiterD) + aNonceWordL);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 43U) + RotL64(aOrbiterA, 37U)) + aOrbiterC) + aNonceWordK);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 29U) + RotL64(aOrbiterK, 11U)) + aOrbiterB) + RotL64(aCarry, 51U)) + aNonceWordI);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 53U) + RotL64(aOrbiterJ, 3U)) + aOrbiterC) + aWandererUpdateSaltA[((aIndex + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 48U));
            aCarry = aCarry + (RotL64(aWandererI, 35U) ^ aWandererC);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 53U));
            aCarry = aCarry + RotL64(aWandererG, 57U);
            aCarry = aCarry + RotL64(aIngress, 26U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 3
        // ingress from: aWorkLaneB, aExpandLaneD, aOperationLaneA
        // ingress directions: aWorkLaneB forward forced, aExpandLaneD forward forced, aOperationLaneA forward/backward random
        // cross from: aWorkLaneA, aExpandLaneB, aFireLaneB
        // cross directions: aWorkLaneA backward forced, aExpandLaneB backward forced, aFireLaneB backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 17603U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneD[((aIndex + 22666U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aOperationLaneA[((aIndex + 19693U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24537U)) & S_BLOCK1], 26U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 21010U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 20763U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCross, 53U) ^ RotL64(aPrevious, 24U)) + (RotL64(aCarry, 39U) ^ RotL64(aIngress, 3U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterE = (aWandererJ + RotL64(aPrevious, 27U)) + 4980738603982643969U;
            aOrbiterA = ((aWandererH + RotL64(aCross, 35U)) + 17660278413018470020U) + aNonceWordP;
            aOrbiterC = (((aWandererD + RotL64(aScatter, 5U)) + RotL64(aCarry, 29U)) + 17598114429859543466U) + aNonceWordI;
            aOrbiterJ = (((aWandererF + RotL64(aIngress, 21U)) + 10993929335279994739U) + aOrbiterAssignSaltF[((aIndex + 26U)) & S_SALT1]) + aNonceWordD;
            aOrbiterI = ((((aWandererI + RotL64(aCross, 53U)) + RotL64(aCarry, 51U)) + 17967203122976322481U) + aOrbiterAssignSaltA[((aIndex + 22U)) & S_SALT1]) + aNonceWordA;
            aOrbiterB = ((aWandererB + RotL64(aIngress, 13U)) + RotL64(aCarry, 11U)) + 1872290205549034384U;
            aOrbiterF = (aWandererE + RotL64(aScatter, 60U)) + 16607778671782810797U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 4895226930754394376U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 14960359005982301383U) ^ aOrbiterUpdateSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8546231310054433721U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 9921642352377700630U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 893281964367208693U) ^ aNonceWordC;
            aOrbiterJ = RotL64((aOrbiterJ * 2345509157333444217U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 8232519988397858732U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 4433022122758913407U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 834240393225479419U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 12689609831247168353U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 404535388957472176U;
            aOrbiterF = RotL64((aOrbiterF * 14534020545479806593U), 53U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 3349108201964013155U) + aNonceWordN;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 4386449511297371730U;
            aOrbiterA = RotL64((aOrbiterA * 9596273264321140229U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 14314587717949070586U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 10923886625271054985U) ^ aNonceWordL;
            aOrbiterB = RotL64((aOrbiterB * 7838969002623486809U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 17634909585329833520U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 2021301459918350372U;
            aOrbiterI = RotL64((aOrbiterI * 1388242915918642741U), 29U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterJ, 5U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 35U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 21U));
            aIngress = aIngress + RotL64(aOrbiterF, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aCross, 53U) + RotL64(aOrbiterF, 5U)) + aOrbiterI) + RotL64(aCarry, 13U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 46U) + RotL64(aOrbiterE, 57U)) + aOrbiterC);
            aWandererF = aWandererF + (((RotL64(aIngress, 3U) + aOrbiterF) + RotL64(aOrbiterB, 19U)) + aNonceWordB);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterJ, 46U)) + aOrbiterC);
            aWandererB = aWandererB + (((((RotL64(aIngress, 29U) + RotL64(aOrbiterJ, 13U)) + aOrbiterA) + RotL64(aCarry, 29U)) + aNonceWordH) + aWandererUpdateSaltF[((aIndex + 7U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aCross, 37U) + aOrbiterC) + RotL64(aOrbiterF, 39U)) + aWandererUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 21U) + aOrbiterA) + RotL64(aOrbiterI, 27U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 35U));
            aCarry = aCarry + (RotL64(aWandererJ, 30U) ^ aWandererH);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + RotL64(aWandererI, 19U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 4
        // ingress from: aWorkLaneC, aWorkLaneA, aOperationLaneC
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aOperationLaneC forward/backward random
        // cross from: aWorkLaneB, aExpandLaneC, aFireLaneA
        // cross directions: aWorkLaneB backward forced, aExpandLaneC backward forced, aFireLaneA backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 30906U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneA[((aIndex + 29696U)) & S_BLOCK1], 44U));
            aIngress ^= RotL64(aOperationLaneC[((aIndex + 29244U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 31647U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 25131U)) & S_BLOCK1], 54U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 26589U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCarry, 4U) ^ RotL64(aIngress, 23U)) ^ (RotL64(aCross, 35U) + RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterI = ((aWandererF + RotL64(aIngress, 43U)) + 3970829908171131502U) + aOrbiterAssignSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterH = (((aWandererG + RotL64(aCross, 37U)) + RotL64(aCarry, 41U)) + 7040283759419531991U) + aOrbiterAssignSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterJ = ((aWandererJ + RotL64(aPrevious, 29U)) + RotL64(aCarry, 29U)) + 11856292169397052901U;
            aOrbiterG = (((aWandererB + RotL64(aScatter, 14U)) + RotL64(aCarry, 5U)) + 819598588791819022U) + aNonceWordK;
            aOrbiterE = (aWandererA + RotL64(aPrevious, 21U)) + 2176451710970866848U;
            aOrbiterA = (aWandererK + RotL64(aScatter, 51U)) + 6454704928613390494U;
            aOrbiterD = ((aWandererE + RotL64(aCross, 57U)) + 11792122387218053841U) + aNonceWordE;
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 9254780213489752211U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 16591812589999846482U;
            aOrbiterJ = RotL64((aOrbiterJ * 5425771603523423167U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 1471246223935074832U) + aNonceWordM;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 1424843083106386453U;
            aOrbiterG = RotL64((aOrbiterG * 15020536982657410783U), 51U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterE) + 1856469958050891629U) + aOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1]) + aNonceWordC;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 6331743690452052712U;
            aOrbiterA = RotL64((aOrbiterA * 15327924647897459645U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 10351075711345476487U) + aNonceWordP;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 9518585245330480185U;
            aOrbiterE = RotL64((aOrbiterE * 3792179827396760391U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 17787514620244712033U) + aOrbiterUpdateSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 14182328067398162557U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 18107337388659070197U), 21U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 12798088948801072444U) + aNonceWordN;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 9563215159275202323U;
            aOrbiterD = RotL64((aOrbiterD * 7058145016617349141U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 9904919772580498232U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 16579777394992143043U) ^ aOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 10516761340320196661U), 41U);
            //
            aIngress = RotL64(aOrbiterH, 47U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 41U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 35U));
            aIngress = aIngress + RotL64(aOrbiterA, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aCross, 11U) + RotL64(aOrbiterA, 13U)) + aOrbiterE);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 35U) + aOrbiterD) + RotL64(aOrbiterA, 34U)) + aNonceWordO);
            aWandererA = aWandererA + ((((RotL64(aScatter, 47U) + RotL64(aOrbiterI, 51U)) + aOrbiterA) + RotL64(aCarry, 57U)) + aNonceWordL);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 53U) + aOrbiterI) + RotL64(aOrbiterH, 21U)) + aWandererUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 60U) + aOrbiterG) + RotL64(aOrbiterE, 57U)) + RotL64(aCarry, 11U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 41U) + RotL64(aOrbiterJ, 3U)) + aOrbiterI) + aWandererUpdateSaltB[((aIndex + 17U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aIngress, 21U) + aOrbiterD) + RotL64(aOrbiterI, 43U)) + aNonceWordB);
            //
            aCarry = aCarry + (RotL64(aWandererG, 11U) ^ aWandererA);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 42U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 57U));
            aCarry = aCarry + RotL64(aWandererJ, 27U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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

void TwistExpander_Hockey_Arx::KDF_B_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xEBD56690C2AFDC43ULL + 0x98FD3EE13685A008ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x9C4C6919928C5C9DULL + 0xA330B9B00D989557ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x822F6446CAFEC5A1ULL + 0x845F71BABA30B853ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xCBD54C5C868A2B27ULL + 0xC22EBB3314919703ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xE78F12A7CE01CE0DULL + 0x88E7A09B3D13905FULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x99606AAB1FF95A4DULL + 0xF1B10AD6712F1FF2ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xB7A5099C76A06385ULL + 0x9AF0B272E8D5CB3BULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x95C0018D3B3EE725ULL + 0xEB5B67325D45DED8ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xCA1085169A779EE3ULL + 0xF9D3E41206EC5E67ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xCE60D4424D7BBE5BULL + 0x8812816AF3D6068AULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xFFDFE03B14428109ULL + 0x86978EFC4A423461ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xED5612951C39D0A5ULL + 0xB10327756A2A204FULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xF352C929F73F30D1ULL + 0xEE68E1A7F319116DULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xC3D6DB64D245A6C9ULL + 0xC3B7AF2676A257A8ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x90D37C0F3C32F56FULL + 0xDDED73355D062D05ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xE380D57C8BB24C49ULL + 0xD16E8B6E3AA5A679ULL);
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
        // read from: aWorkLaneA, aWorkLaneB, aFireLaneC, aWorkLaneC, aWorkLaneD, aFireLaneD, aExpandLaneA, aFireLaneA, aOperationLaneD, aExpandLaneB, aOperationLaneA, aOperationLaneC, aExpandLaneC, aFireLaneB, aOperationLaneB
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_a loop 1
        // ingress from: aWorkLaneA, aWorkLaneB, aFireLaneC
        // ingress directions: aWorkLaneA forward forced, aWorkLaneB forward forced, aFireLaneC forward/backward random
        // cross from: aWorkLaneC, aWorkLaneD, aFireLaneD
        // cross directions: aWorkLaneC backward forced, aWorkLaneD backward forced, aFireLaneD backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 2055U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((aIndex + 4454U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 7256U)) & S_BLOCK1], 50U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 7881U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 2196U)) & S_BLOCK1], 60U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 7811U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCarry, 41U) ^ RotL64(aPrevious, 54U)) + (RotL64(aIngress, 27U) + RotL64(aCross, 13U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterF = (aWandererD + RotL64(aIngress, 11U)) + 3248574644570178787U;
            aOrbiterI = ((aWandererB + RotL64(aPrevious, 21U)) + 4506961512959200024U) + aNonceWordB;
            aOrbiterH = ((aWandererE + RotL64(aCross, 53U)) + RotL64(aCarry, 13U)) + 8423739774540738590U;
            aOrbiterD = (((aWandererJ + RotL64(aScatter, 35U)) + RotL64(aCarry, 39U)) + 6593975869641735337U) + aNonceWordO;
            aOrbiterE = ((aWandererI + RotL64(aCross, 3U)) + 16441716090557369103U) + aOrbiterAssignSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterA = (aWandererF + RotL64(aScatter, 41U)) + 7936601450453207914U;
            aOrbiterK = ((((aWandererH + RotL64(aIngress, 28U)) + RotL64(aCarry, 51U)) + 13333752583560167065U) + aOrbiterAssignSaltA[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordD;
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 8013703284795432973U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 2349852779887439236U;
            aOrbiterH = RotL64((aOrbiterH * 2422888500648100783U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 5318539364763284138U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 11450957608502944376U;
            aOrbiterE = RotL64((aOrbiterE * 1957880366707810635U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 9058992558327552687U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 632095686920230926U) ^ aNonceWordI;
            aOrbiterI = RotL64((aOrbiterI * 12460364388358520799U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 14734218428913777098U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 16344357661370784442U) ^ aOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 15049472842002138369U), 35U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterH) + 2981145363531184308U) + aOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1]) + aNonceWordK;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 14176472085175714494U;
            aOrbiterK = RotL64((aOrbiterK * 2584623327412130939U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 11198457590069700889U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 952584436750426828U;
            aOrbiterF = RotL64((aOrbiterF * 1165713888651280355U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 4311591763498985972U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 16194341833989936369U;
            aOrbiterA = RotL64((aOrbiterA * 9997934560195932575U), 51U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterA, 35U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 52U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 29U));
            aIngress = aIngress + RotL64(aOrbiterH, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aIngress, 27U) + RotL64(aOrbiterE, 23U)) + aOrbiterH);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 5U) + aOrbiterI) + RotL64(aOrbiterD, 11U));
            aWandererI = aWandererI + (((RotL64(aScatter, 20U) + RotL64(aOrbiterF, 57U)) + aOrbiterD) + aWandererUpdateSaltC[((aIndex + 22U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterE, 35U)) + aOrbiterK);
            aWandererH = aWandererH + (((((RotL64(aScatter, 51U) + aOrbiterH) + RotL64(aOrbiterF, 29U)) + RotL64(aCarry, 47U)) + aNonceWordH) + aWandererUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 57U) + aOrbiterA) + RotL64(aOrbiterH, 5U));
            aWandererF = aWandererF + ((((RotL64(aCross, 43U) + aOrbiterD) + RotL64(aOrbiterH, 50U)) + RotL64(aCarry, 21U)) + aNonceWordL);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 53U));
            aCarry = aCarry + (RotL64(aWandererB, 3U) ^ aWandererD);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + RotL64(aWandererF, 30U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 2
        // ingress from: aExpandLaneA, aWorkLaneC, aFireLaneA
        // ingress directions: aExpandLaneA forward forced, aWorkLaneC forward forced, aFireLaneA forward/backward random
        // cross from: aWorkLaneA, aWorkLaneD, aOperationLaneD
        // cross directions: aWorkLaneA backward forced, aWorkLaneD backward forced, aOperationLaneD backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 14350U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneC[((aIndex + 13729U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 14678U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 15791U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 16376U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 14323U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aIngress, 53U) + RotL64(aCross, 3U)) + (RotL64(aPrevious, 36U) ^ RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterC = (((aWandererI + RotL64(aPrevious, 43U)) + RotL64(aCarry, 47U)) + 14157904117287696136U) + aNonceWordN;
            aOrbiterG = ((aWandererJ + RotL64(aIngress, 29U)) + 7369512677371640676U) + aNonceWordG;
            aOrbiterB = (aWandererH + RotL64(aScatter, 21U)) + 8411250745902073798U;
            aOrbiterI = ((aWandererB + RotL64(aCross, 4U)) + 5002041814539710275U) + aNonceWordI;
            aOrbiterK = ((aWandererA + RotL64(aIngress, 11U)) + RotL64(aCarry, 23U)) + 9538041410816283124U;
            aOrbiterD = ((((aWandererC + RotL64(aScatter, 53U)) + RotL64(aCarry, 35U)) + 5210700103927513061U) + aOrbiterAssignSaltD[((aIndex + 8U)) & S_SALT1]) + aNonceWordP;
            aOrbiterE = ((aWandererK + RotL64(aCross, 37U)) + 7600709399101287982U) + aOrbiterAssignSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 2366369466696580499U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 5544575244203019109U) ^ aOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 16231219246786333057U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 8710073749110329779U) + aOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 15998211310115361630U;
            aOrbiterK = RotL64((aOrbiterK * 15275657696897688955U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 15354357553877376422U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 10657523549259276169U;
            aOrbiterD = RotL64((aOrbiterD * 13695239532898311073U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 10405750198355464768U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 3465819693133515142U;
            aOrbiterC = RotL64((aOrbiterC * 14678343718277562799U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 16724189641701408630U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 3484340153620198872U) ^ aNonceWordH;
            aOrbiterE = RotL64((aOrbiterE * 17247547677520703125U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 7420442404884871126U) + aNonceWordM;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 11138445997256757636U;
            aOrbiterG = RotL64((aOrbiterG * 11167543379937571127U), 37U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 1428191560884663125U) + aOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 16950093140800653985U;
            aOrbiterI = RotL64((aOrbiterI * 4423012306984814805U), 11U);
            //
            aIngress = RotL64(aOrbiterK, 47U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 57U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 12U));
            aIngress = aIngress + RotL64(aOrbiterB, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aScatter, 11U) + aOrbiterD) + RotL64(aOrbiterC, 19U)) + aWandererUpdateSaltB[((aIndex + 13U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aIngress, 60U) + RotL64(aOrbiterG, 48U)) + aOrbiterE) + RotL64(aCarry, 57U)) + aWandererUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterK, 41U)) + aOrbiterC);
            aWandererC = aWandererC + ((((RotL64(aCross, 29U) + aOrbiterB) + RotL64(aOrbiterI, 3U)) + RotL64(aCarry, 23U)) + aNonceWordB);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 35U) + aOrbiterG) + RotL64(aOrbiterI, 35U));
            aWandererH = aWandererH + ((RotL64(aPrevious, 3U) + aOrbiterI) + RotL64(aOrbiterD, 11U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterB, 29U)) + aOrbiterK) + aNonceWordF);
            //
            aCarry = aCarry + (RotL64(aWandererB, 44U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererC, 29U) ^ aWandererH);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 39U));
            aCarry = aCarry + RotL64(aWandererK, 11U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 3
        // ingress from: aExpandLaneB, aWorkLaneD, aOperationLaneA
        // ingress directions: aExpandLaneB forward forced, aWorkLaneD forward forced, aOperationLaneA forward/backward random
        // cross from: aExpandLaneA, aWorkLaneB, aOperationLaneC
        // cross directions: aExpandLaneA backward forced, aWorkLaneB backward forced, aOperationLaneC backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 17189U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneD[((aIndex + 20154U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 20385U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 17146U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 19474U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aOperationLaneC[((aIndex + 17491U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCross, 39U) ^ RotL64(aPrevious, 58U)) + (RotL64(aCarry, 27U) ^ RotL64(aIngress, 11U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterH = (aWandererD + RotL64(aIngress, 57U)) + 12583180859826261500U;
            aOrbiterE = ((aWandererI + RotL64(aCross, 14U)) + 9067093488553721468U) + aNonceWordB;
            aOrbiterK = (((aWandererK + RotL64(aScatter, 37U)) + 12173106198862881754U) + aOrbiterAssignSaltE[((aIndex + 8U)) & S_SALT1]) + aNonceWordI;
            aOrbiterG = ((aWandererH + RotL64(aPrevious, 29U)) + RotL64(aCarry, 47U)) + 11333491014394592654U;
            aOrbiterD = ((aWandererF + RotL64(aScatter, 3U)) + RotL64(aCarry, 11U)) + 3511883526940919554U;
            aOrbiterB = ((aWandererA + RotL64(aPrevious, 47U)) + 7416810692106273044U) + aNonceWordN;
            aOrbiterA = ((((aWandererC + RotL64(aCross, 23U)) + RotL64(aCarry, 35U)) + 8341174972619784110U) + aOrbiterAssignSaltC[((aIndex + 11U)) & S_SALT1]) + aNonceWordH;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 2220852854836962979U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 8090781422229383825U) ^ aNonceWordE;
            aOrbiterK = RotL64((aOrbiterK * 578293950675644397U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 2338801236599102223U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 12484514711848308104U;
            aOrbiterB = RotL64((aOrbiterB * 10364216764253366067U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 13684861340589131816U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 12796636819991873058U;
            aOrbiterH = RotL64((aOrbiterH * 5533508014234835669U), 35U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterH) + 7634198650894837690U) + aOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1]) + aNonceWordD;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 10240326122201201762U;
            aOrbiterE = RotL64((aOrbiterE * 8758703497719125901U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 4162814763739453934U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 2766504649149048469U) ^ aNonceWordJ;
            aOrbiterG = RotL64((aOrbiterG * 16731843453895178671U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 11051393030148769655U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterK) ^ 17687055068651386665U) ^ aOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterD = RotL64((aOrbiterD * 1042927176246229537U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 3353615315436983420U) + aOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 5971640796220306310U;
            aOrbiterA = RotL64((aOrbiterA * 15804313508835034807U), 57U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterG, 12U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 43U));
            aIngress = aIngress + (RotL64(aOrbiterH, 53U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterB, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterD, 13U)) + aOrbiterA);
            aWandererA = aWandererA + ((((RotL64(aScatter, 35U) + RotL64(aOrbiterE, 27U)) + aOrbiterK) + RotL64(aCarry, 3U)) + aWandererUpdateSaltA[((aIndex + 21U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterE, 3U)) + aOrbiterA);
            aWandererF = aWandererF + (((((RotL64(aIngress, 19U) + aOrbiterH) + RotL64(aOrbiterK, 58U)) + RotL64(aCarry, 29U)) + aNonceWordF) + aWandererUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterG, 47U)) + aOrbiterE) + aNonceWordP);
            aWandererD = aWandererD + ((RotL64(aIngress, 50U) + aOrbiterG) + RotL64(aOrbiterH, 39U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterB, 19U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 24U));
            aCarry = aCarry + (RotL64(aWandererD, 53U) ^ aWandererF);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 37U));
            aCarry = aCarry + RotL64(aWandererI, 5U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aFireLaneB
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aFireLaneB forward/backward random
        // cross from: aExpandLaneB, aWorkLaneC, aOperationLaneB
        // cross directions: aExpandLaneB backward forced, aWorkLaneC backward forced, aOperationLaneB backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 31404U)) & S_BLOCK1], 40U) ^ RotL64(aExpandLaneA[((aIndex + 30199U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 25364U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27538U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 24982U)) & S_BLOCK1], 54U));
            aCross ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31616U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aPrevious, 13U) + RotL64(aCross, 57U)) ^ (RotL64(aCarry, 28U) ^ RotL64(aIngress, 43U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterJ = (aWandererD + RotL64(aPrevious, 23U)) + 6361545377408870615U;
            aOrbiterA = ((aWandererE + RotL64(aCross, 11U)) + 2967245486744774933U) + aNonceWordL;
            aOrbiterC = (aWandererI + RotL64(aScatter, 3U)) + 3836634268482850139U;
            aOrbiterK = ((aWandererB + RotL64(aIngress, 57U)) + RotL64(aCarry, 47U)) + 7691642115360086297U;
            aOrbiterE = (((aWandererC + RotL64(aPrevious, 51U)) + 16479280384178279281U) + aOrbiterAssignSaltA[((aIndex + 15U)) & S_SALT1]) + aNonceWordE;
            aOrbiterB = (((aWandererG + RotL64(aScatter, 40U)) + RotL64(aCarry, 5U)) + 2901468732552539249U) + aNonceWordN;
            aOrbiterI = ((((aWandererF + RotL64(aCross, 29U)) + RotL64(aCarry, 29U)) + 2600353867755647475U) + aOrbiterAssignSaltF[((aIndex + 21U)) & S_SALT1]) + aNonceWordO;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 5666596904781510956U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterJ) ^ 16108791609267427553U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterC = RotL64((aOrbiterC * 8904649663479834199U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 8389926875737312112U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 1689501721163024426U;
            aOrbiterA = RotL64((aOrbiterA * 6517194895779049139U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 11721701506949917719U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 3963842745030140473U) ^ aOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 6692473494944919373U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 8510538243472109368U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 18281865214102080387U) ^ aNonceWordI;
            aOrbiterB = RotL64((aOrbiterB * 1351546966368884609U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 2259725140963665123U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 11652011949557979650U;
            aOrbiterI = RotL64((aOrbiterI * 11260100762113295037U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 1116085424226174473U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 4725260319270802912U;
            aOrbiterE = RotL64((aOrbiterE * 4697109059565450269U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 7348945429843437036U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 1249234309180653260U;
            aOrbiterJ = RotL64((aOrbiterJ * 3136745255820405881U), 57U);
            //
            aIngress = RotL64(aOrbiterJ, 51U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 57U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 23U));
            aIngress = aIngress + RotL64(aOrbiterE, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aScatter, 11U) + RotL64(aOrbiterA, 51U)) + aOrbiterJ) + aNonceWordA);
            aWandererD = aWandererD + (((RotL64(aIngress, 3U) + aOrbiterC) + RotL64(aOrbiterE, 57U)) + RotL64(aCarry, 3U));
            aWandererI = aWandererI ^ ((((RotL64(aPrevious, 41U) + RotL64(aOrbiterA, 34U)) + aOrbiterB) + aNonceWordG) + aWandererUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aCross, 51U) + aOrbiterB) + RotL64(aOrbiterI, 41U)) + RotL64(aCarry, 29U));
            aWandererF = aWandererF ^ ((((RotL64(aScatter, 34U) + RotL64(aOrbiterC, 11U)) + aOrbiterJ) + aNonceWordD) + aWandererUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aIngress, 57U) + RotL64(aOrbiterK, 19U)) + aOrbiterB);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 23U) + RotL64(aOrbiterE, 3U)) + aOrbiterI) + aNonceWordC);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 51U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 19U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 3U));
            aCarry = aCarry + RotL64(aWandererE, 46U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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

void TwistExpander_Hockey_Arx::KDF_B_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x85DB592A327B8AA3ULL + 0xEE3AAC67DE5CA75BULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xA17D7F081983BC79ULL + 0xA6AACCB950ED48BCULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xC28667807B6E27C1ULL + 0xBDE698C546F445A7ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xB091E6DFE72A9011ULL + 0x921ACA70B0FCEE93ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xA16BF4E99612F355ULL + 0xC913D1E79B6BAA21ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xDD28107530AF2E3BULL + 0xFAB193076C28D025ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xF6DA2B30B93EC9DFULL + 0xD4F223BABE520EF7ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xC51486C5F4567C87ULL + 0xF1DCB39EB3DA23D7ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xB476625657170557ULL + 0xE5F64948FDC756A4ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xF582C741F2AE6889ULL + 0xC642002ACD585DF5ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xBC8F23E38826DD2BULL + 0x8302026F8A81D567ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xE7E540957BE4EC9BULL + 0x898AAB36ABF8223CULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xF47619A83D1CE2E7ULL + 0xD03E8FF005AEAE66ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xAC8D845FF12C2A09ULL + 0xCDE0D97134F656C7ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xB74F9A4519F74161ULL + 0xA26D5B4DF78FAD17ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0x99BF1EFFF7EA915BULL + 0xAB3EFB93F8E9176AULL);
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
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneD, aExpandLaneC, aExpandLaneD, aWorkLaneA, aOperationLaneA, aWorkLaneC, aWorkLaneB, aOperationLaneB, aWorkLaneD, aFireLaneB, aOperationLaneC, aFireLaneA, aFireLaneC
        // write to: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD
    
        // kdf_b_loop_b loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aFireLaneD
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aFireLaneD forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD, aWorkLaneA
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward forced, aWorkLaneA backward/forward random
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 5283U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneB[((aIndex + 6131U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 6858U)) & S_BLOCK1], 6U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 2954U)) & S_BLOCK1], 60U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 3764U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 7854U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCarry, 6U) + RotL64(aPrevious, 39U)) ^ (RotL64(aCross, 23U) ^ RotL64(aIngress, 51U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterI = (aWandererG + RotL64(aIngress, 35U)) + 8793908991006073956U;
            aOrbiterK = (aWandererC + RotL64(aPrevious, 6U)) + 2932916283348441943U;
            aOrbiterC = (aWandererF + RotL64(aCross, 3U)) + 11069042087940968262U;
            aOrbiterF = (aWandererD + RotL64(aScatter, 21U)) + 14369628676782894441U;
            aOrbiterJ = (aWandererE + RotL64(aCross, 13U)) + 8602903272780978282U;
            aOrbiterE = (((aWandererK + RotL64(aIngress, 37U)) + RotL64(aCarry, 53U)) + 3827036107178568820U) + aNonceWordD;
            aOrbiterB = ((aWandererB + RotL64(aScatter, 28U)) + 8905245209036772489U) + aOrbiterAssignSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterA = ((aWandererA + RotL64(aPrevious, 39U)) + 13331387530760017893U) + aOrbiterAssignSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterD = (((aWandererJ + RotL64(aCross, 19U)) + RotL64(aCarry, 3U)) + 9880107580289737823U) + aNonceWordK;
            aOrbiterH = (aWandererH + RotL64(aScatter, 11U)) + 10199619040626900278U;
            aOrbiterG = ((aWandererI + RotL64(aPrevious, 51U)) + RotL64(aCarry, 37U)) + 2466307560891374281U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 13973403407981259448U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 2851460278409385243U;
            aOrbiterC = RotL64((aOrbiterC * 11226902976321781743U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 10365453393815690776U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 2382382358987358791U) ^ aNonceWordN;
            aOrbiterE = RotL64((aOrbiterE * 481563628980705781U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 5058198848163792422U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 10500434740387593487U;
            aOrbiterJ = RotL64((aOrbiterJ * 5946747708776079787U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 11289798395177667084U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 14327152153231286666U;
            aOrbiterK = RotL64((aOrbiterK * 18155778059595245561U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 8065137263811956313U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 3865153574847924816U;
            aOrbiterB = RotL64((aOrbiterB * 9495741102667755161U), 27U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 18102279969722473375U) + aOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 6306428427188742325U;
            aOrbiterD = RotL64((aOrbiterD * 17826782872351406167U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 16953348204663693724U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 11950791817032898613U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 1498946055469611133U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 11980823193543752994U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 17845490308799454871U) ^ aNonceWordF;
            aOrbiterA = RotL64((aOrbiterA * 16385153013485463791U), 41U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 5566398755702887071U) + aOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 10308378271388889968U) ^ aOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 142732084484961281U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 6717846700455219260U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 8297225372883997017U;
            aOrbiterH = RotL64((aOrbiterH * 14102812043481327907U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 12249337046267666603U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 8793908991006073956U;
            aOrbiterF = RotL64((aOrbiterF * 5851229209188473467U), 19U);
            //
            aIngress = RotL64(aOrbiterB, 53U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 21U));
            aIngress = aIngress + (RotL64(aOrbiterA, 19U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterH, 13U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterD, 43U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterJ, 60U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aIngress, 19U) + aOrbiterK) + RotL64(aOrbiterD, 30U)) + aNonceWordL);
            aWandererK = aWandererK + (((RotL64(aPrevious, 56U) + aOrbiterI) + RotL64(aOrbiterB, 41U)) + RotL64(aCarry, 47U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterB, 5U)) + aOrbiterG);
            aWandererD = aWandererD + (((RotL64(aCross, 35U) + aOrbiterC) + RotL64(aOrbiterB, 51U)) + RotL64(aCarry, 13U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterH, 11U)) + aOrbiterF);
            aWandererG = aWandererG + ((RotL64(aCross, 30U) + RotL64(aOrbiterH, 39U)) + aOrbiterE);
            aWandererA = aWandererA ^ ((((RotL64(aPrevious, 21U) + RotL64(aOrbiterF, 37U)) + aOrbiterI) + aNonceWordM) + aWandererUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aIngress, 23U) + aOrbiterB) + RotL64(aOrbiterK, 43U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterD, 19U)) + aOrbiterA);
            aWandererB = aWandererB + ((RotL64(aIngress, 27U) + RotL64(aOrbiterK, 48U)) + aOrbiterI);
            aWandererE = aWandererE ^ ((((RotL64(aScatter, 41U) + aOrbiterJ) + RotL64(aOrbiterK, 3U)) + aNonceWordG) + aWandererUpdateSaltE[((aIndex + 16U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 50U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererB, 13U) ^ aWandererE);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 39U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 54U));
            aCarry = aCarry + RotL64(aWandererH, 35U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 2
        // ingress from: aOperationLaneA, aExpandLaneC, aWorkLaneC
        // ingress directions: aOperationLaneA forward forced, aExpandLaneC forward forced, aWorkLaneC forward/backward random
        // cross from: aExpandLaneA, aExpandLaneD, aWorkLaneB
        // cross directions: aExpandLaneA backward forced, aExpandLaneD backward forced, aWorkLaneB backward/forward random
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 9091U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneC[((aIndex + 11145U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 12873U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 9592U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 10789U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 14257U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCross, 23U) ^ RotL64(aPrevious, 39U)) + (RotL64(aIngress, 56U) + RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterC = ((((aWandererG + RotL64(aCross, 41U)) + RotL64(aCarry, 43U)) + 6318740973868639425U) + aOrbiterAssignSaltA[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterD = (aWandererK + RotL64(aPrevious, 27U)) + 5487840061430920881U;
            aOrbiterA = (((aWandererH + RotL64(aIngress, 53U)) + RotL64(aCarry, 27U)) + 10258706763248072672U) + aOrbiterAssignSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = (aWandererE + RotL64(aScatter, 44U)) + 18356875269730338208U;
            aOrbiterG = ((aWandererA + RotL64(aPrevious, 57U)) + 12883160282903147010U) + aNonceWordK;
            aOrbiterH = ((aWandererI + RotL64(aIngress, 5U)) + 1010140474942697730U) + aNonceWordI;
            aOrbiterJ = ((aWandererC + RotL64(aScatter, 51U)) + 17733939421700898293U) + aNonceWordF;
            aOrbiterE = (aWandererB + RotL64(aCross, 39U)) + 13693055887924981201U;
            aOrbiterI = (aWandererF + RotL64(aPrevious, 37U)) + 14574732452793385269U;
            aOrbiterF = (aWandererD + RotL64(aCross, 48U)) + 10832873941223609012U;
            aOrbiterB = ((aWandererJ + RotL64(aScatter, 29U)) + RotL64(aCarry, 3U)) + 8212600587135328040U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 5312744319781971178U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 6173741211706546923U) ^ aNonceWordA;
            aOrbiterA = RotL64((aOrbiterA * 12854414066390848249U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 3693249147883790810U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 18365859989736602556U) ^ aOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 3348463719324104997U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 10645056678337549771U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 1175668356822251045U;
            aOrbiterE = RotL64((aOrbiterE * 6579675292775345579U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 13556844570541823717U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 4790355739411849736U;
            aOrbiterK = RotL64((aOrbiterK * 4083544011788850307U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 14905575502272644116U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 17047244574558476634U) ^ aOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2356386971503880047U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 10161614295718414869U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 13413914082651612468U;
            aOrbiterF = RotL64((aOrbiterF * 16224039093981079491U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 6072693130156927774U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 4333656233793103787U;
            aOrbiterD = RotL64((aOrbiterD * 9374745547133955709U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 17209776289202130250U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 11752001118070361543U;
            aOrbiterB = RotL64((aOrbiterB * 4416523594812872339U), 43U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterF) + 15367365111105608277U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordN;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 8650687767097460704U) ^ aNonceWordG;
            aOrbiterC = RotL64((aOrbiterC * 11430451559660578667U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 18074648514448405693U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 10857586858462237581U) ^ aNonceWordP;
            aOrbiterJ = RotL64((aOrbiterJ * 3722891011080095849U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 17219932344278345591U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 6318740973868639425U;
            aOrbiterG = RotL64((aOrbiterG * 8846295038878812229U), 35U);
            //
            aIngress = RotL64(aOrbiterD, 11U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterH, 41U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 27U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 57U));
            aIngress = aIngress + (RotL64(aOrbiterA, 14U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterI, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aCross, 27U) + RotL64(aOrbiterE, 47U)) + aOrbiterG) + aNonceWordB);
            aWandererG = aWandererG + (((RotL64(aIngress, 51U) + RotL64(aOrbiterB, 53U)) + aOrbiterG) + RotL64(aCarry, 53U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterD, 39U)) + aOrbiterC) + aNonceWordO);
            aWandererF = aWandererF + (((RotL64(aPrevious, 40U) + aOrbiterD) + RotL64(aOrbiterA, 37U)) + aWandererUpdateSaltC[((aIndex + 5U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((((RotL64(aCross, 13U) + aOrbiterH) + RotL64(aOrbiterJ, 57U)) + aNonceWordH) + aWandererUpdateSaltB[((aIndex + 19U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aPrevious, 29U) + aOrbiterH) + RotL64(aOrbiterG, 14U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterE, 43U)) + aOrbiterH);
            aWandererC = aWandererC + ((RotL64(aScatter, 23U) + RotL64(aOrbiterK, 19U)) + aOrbiterF);
            aWandererK = aWandererK ^ (((RotL64(aCross, 21U) + RotL64(aOrbiterG, 35U)) + aOrbiterA) + aNonceWordE);
            aWandererD = aWandererD + (((RotL64(aPrevious, 60U) + RotL64(aOrbiterJ, 21U)) + aOrbiterI) + RotL64(aCarry, 13U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterH, 28U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 34U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 23U));
            aCarry = aCarry + (RotL64(aWandererK, 43U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererI, 21U) ^ aWandererC);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 19U));
            aCarry = aCarry + RotL64(aWandererJ, 57U);
            aCarry = aCarry + RotL64(aIngress, 30U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aOperationLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 3
        // ingress from: aOperationLaneB, aExpandLaneD, aWorkLaneD
        // ingress directions: aOperationLaneB forward forced, aExpandLaneD forward forced, aWorkLaneD forward/backward random
        // cross from: aOperationLaneA, aExpandLaneB, aFireLaneB
        // cross directions: aOperationLaneA backward forced, aExpandLaneB backward forced, aFireLaneB backward/forward random
        // write to: aOperationLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneB[((aIndex + 19917U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneD[((aIndex + 22741U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aWorkLaneD[((aIndex + 19847U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 22084U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 20891U)) & S_BLOCK1], 54U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 23906U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aPrevious, 52U) ^ RotL64(aCarry, 39U)) ^ (RotL64(aIngress, 5U) + RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterG = (((aWandererB + RotL64(aPrevious, 5U)) + RotL64(aCarry, 13U)) + 14686411261024919129U) + aOrbiterAssignSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = (aWandererG + RotL64(aCross, 29U)) + 7514582233957632005U;
            aOrbiterB = ((aWandererE + RotL64(aIngress, 44U)) + 6520710480103365552U) + aNonceWordJ;
            aOrbiterC = (aWandererK + RotL64(aScatter, 37U)) + 1983621978676188036U;
            aOrbiterF = (aWandererC + RotL64(aCross, 47U)) + 9003524602590749672U;
            aOrbiterA = (aWandererI + RotL64(aIngress, 35U)) + 6428568234045228995U;
            aOrbiterJ = (aWandererH + RotL64(aScatter, 57U)) + 8656552687136446989U;
            aOrbiterH = ((aWandererF + RotL64(aPrevious, 50U)) + 16916248288415922490U) + aOrbiterAssignSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = (aWandererJ + RotL64(aIngress, 41U)) + 9740237548002535784U;
            aOrbiterD = (((aWandererD + RotL64(aScatter, 19U)) + RotL64(aCarry, 43U)) + 907561000814618339U) + aNonceWordK;
            aOrbiterE = ((aWandererA + RotL64(aCross, 27U)) + RotL64(aCarry, 37U)) + 4751108900841197631U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 167774899400732287U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 11907484918310854962U;
            aOrbiterB = RotL64((aOrbiterB * 7213139491146402985U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 14910318613649863924U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 14882888155751455276U;
            aOrbiterI = RotL64((aOrbiterI * 11394136445442060201U), 37U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 16175942562693781908U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 11022373758481651102U;
            aOrbiterC = RotL64((aOrbiterC * 6836331461393816027U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 12548405399045031548U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 10850926364556828443U;
            aOrbiterH = RotL64((aOrbiterH * 16231561687709867431U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 13391684887911141790U) + aOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 14648937281264822988U;
            aOrbiterD = RotL64((aOrbiterD * 6533299316940026059U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 8298658887198526821U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 13822977698661348891U) ^ aNonceWordM;
            aOrbiterA = RotL64((aOrbiterA * 17769262972278410937U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 7505646847564645719U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 3238749538197209166U) ^ aNonceWordD;
            aOrbiterK = RotL64((aOrbiterK * 15394286542600778567U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 15853506915123709257U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 8426329899401071248U) ^ aNonceWordP;
            aOrbiterE = RotL64((aOrbiterE * 1330397096577715113U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 14848635392815613098U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 3549927798350175044U;
            aOrbiterF = RotL64((aOrbiterF * 1899044682313056949U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 1798973117197750802U) + aOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 13056711228618953977U;
            aOrbiterG = RotL64((aOrbiterG * 9102877396419306689U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 1395893547965799281U) + aNonceWordO;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 14686411261024919129U;
            aOrbiterJ = RotL64((aOrbiterJ * 17075377081365066067U), 57U);
            //
            aIngress = RotL64(aOrbiterC, 5U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterH, 41U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 21U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 3U));
            aIngress = aIngress + (RotL64(aOrbiterB, 35U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterI, 54U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 39U) + aOrbiterF) + RotL64(aOrbiterA, 5U));
            aWandererE = aWandererE + ((RotL64(aScatter, 30U) + RotL64(aOrbiterD, 18U)) + aOrbiterF);
            aWandererH = aWandererH ^ (((RotL64(aCross, 23U) + aOrbiterB) + RotL64(aOrbiterC, 35U)) + aNonceWordG);
            aWandererG = aWandererG + ((RotL64(aIngress, 35U) + RotL64(aOrbiterG, 57U)) + aOrbiterI);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 27U) + aOrbiterE) + RotL64(aOrbiterJ, 23U));
            aWandererB = aWandererB + (((RotL64(aIngress, 58U) + aOrbiterJ) + RotL64(aOrbiterI, 29U)) + RotL64(aCarry, 29U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 13U) + aOrbiterK) + RotL64(aOrbiterF, 41U));
            aWandererI = aWandererI + ((((RotL64(aScatter, 5U) + aOrbiterI) + RotL64(aOrbiterD, 21U)) + RotL64(aCarry, 3U)) + aNonceWordI);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 37U) + aOrbiterJ) + RotL64(aOrbiterK, 51U)) + aWandererUpdateSaltA[((aIndex + 3U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aPrevious, 47U) + RotL64(aOrbiterH, 43U)) + aOrbiterC);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 51U) + RotL64(aOrbiterC, 10U)) + aOrbiterI) + aWandererUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererB);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 26U));
            aCarry = aCarry + (RotL64(aWandererC, 3U) ^ aWandererD);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 21U));
            aCarry = aCarry + (RotL64(aWandererG, 23U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererA, 5U);
            aCarry = aCarry + RotL64(aIngress, 28U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aOperationLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 4
        // ingress from: aOperationLaneC, aOperationLaneA, aFireLaneA
        // ingress directions: aOperationLaneC forward forced, aOperationLaneA forward forced, aFireLaneA forward/backward random
        // cross from: aOperationLaneB, aExpandLaneC, aFireLaneC
        // cross directions: aOperationLaneB backward forced, aExpandLaneC backward forced, aFireLaneC backward/forward random
        // write to: aOperationLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneC[((aIndex + 26074U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneA[((aIndex + 24652U)) & S_BLOCK1], 46U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 30797U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 26894U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 26564U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 25459U)) & S_BLOCK1], 42U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCarry, 23U) ^ RotL64(aIngress, 57U)) + (RotL64(aCross, 11U) + RotL64(aPrevious, 38U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterB = ((aWandererD + RotL64(aPrevious, 24U)) + 4179952823252098240U) + aNonceWordD;
            aOrbiterF = (aWandererE + RotL64(aIngress, 35U)) + 3745613452332101749U;
            aOrbiterJ = (aWandererJ + RotL64(aCross, 39U)) + 2955689793395307176U;
            aOrbiterD = ((aWandererC + RotL64(aScatter, 27U)) + RotL64(aCarry, 23U)) + 5639060180251322019U;
            aOrbiterK = (((aWandererA + RotL64(aPrevious, 21U)) + RotL64(aCarry, 35U)) + 7901969163853586463U) + aNonceWordB;
            aOrbiterG = ((aWandererG + RotL64(aCross, 3U)) + RotL64(aCarry, 43U)) + 2242166787816318119U;
            aOrbiterH = ((aWandererH + RotL64(aIngress, 37U)) + 5239936443960750064U) + aOrbiterAssignSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = ((aWandererI + RotL64(aScatter, 13U)) + 13939136954732185558U) + aOrbiterAssignSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterE = (aWandererF + RotL64(aCross, 11U)) + 17058884136712717463U;
            aOrbiterC = (aWandererK + RotL64(aScatter, 44U)) + 18148618660054585941U;
            aOrbiterA = (aWandererB + RotL64(aIngress, 47U)) + 7022023484530327814U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 7722084537340095637U) + aOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 11764151879690934182U;
            aOrbiterJ = RotL64((aOrbiterJ * 12264384877711365655U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 16412785901758144708U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 9666718667728274824U;
            aOrbiterG = RotL64((aOrbiterG * 10865799822751771795U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 4307127540152109364U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 2457646804702647606U;
            aOrbiterI = RotL64((aOrbiterI * 6340030928007058595U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 3179394870088602208U) + aNonceWordH;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 504977947273774249U;
            aOrbiterF = RotL64((aOrbiterF * 16190282058883481551U), 53U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 16182729401018310837U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 7110817020445860609U) ^ aNonceWordN;
            aOrbiterD = RotL64((aOrbiterD * 13371352088428584087U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 12960656706837391973U) + aNonceWordL;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 7103806893724395904U;
            aOrbiterH = RotL64((aOrbiterH * 14365984439655979791U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 1248300178080633527U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 7195473175424961337U;
            aOrbiterA = RotL64((aOrbiterA * 4633558992739305045U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 13007951568242991449U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 10296811247653636372U;
            aOrbiterE = RotL64((aOrbiterE * 16469682651380549395U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 13922797949001028335U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 16773545425463040155U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 10639282630227832397U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 2888887140296117803U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 10279517418046269817U;
            aOrbiterC = RotL64((aOrbiterC * 8600355360339461535U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 17303373436784809093U) + aNonceWordG;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 4179952823252098240U;
            aOrbiterB = RotL64((aOrbiterB * 3675754609699406437U), 23U);
            //
            aIngress = RotL64(aOrbiterK, 60U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 41U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 47U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterA, 29U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 21U));
            aIngress = aIngress + RotL64(aOrbiterE, 34U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aIngress, 23U) + RotL64(aOrbiterB, 43U)) + aOrbiterE);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 56U) + aOrbiterI) + RotL64(aOrbiterE, 51U));
            aWandererE = aWandererE + ((RotL64(aCross, 41U) + aOrbiterG) + RotL64(aOrbiterC, 39U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 19U) + aOrbiterI) + RotL64(aOrbiterF, 36U));
            aWandererK = aWandererK + ((RotL64(aScatter, 13U) + RotL64(aOrbiterD, 47U)) + aOrbiterA);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 28U) + RotL64(aOrbiterH, 5U)) + aOrbiterK) + aNonceWordF);
            aWandererD = aWandererD + (((RotL64(aCross, 5U) + aOrbiterE) + RotL64(aOrbiterD, 13U)) + aWandererUpdateSaltE[((aIndex + 24U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 51U) + RotL64(aOrbiterG, 57U)) + aOrbiterJ) + aNonceWordM);
            aWandererA = aWandererA + (((((RotL64(aCross, 21U) + aOrbiterF) + RotL64(aOrbiterK, 29U)) + RotL64(aCarry, 27U)) + aNonceWordO) + aWandererUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 35U) + aOrbiterK) + RotL64(aOrbiterB, 26U));
            aWandererB = aWandererB + ((((RotL64(aScatter, 39U) + aOrbiterE) + RotL64(aOrbiterC, 21U)) + RotL64(aCarry, 57U)) + aNonceWordE);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 35U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 30U));
            aCarry = aCarry + (RotL64(aWandererE, 51U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererJ, 23U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererH, 53U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererG, 60U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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

void TwistExpander_Hockey_Arx::KDF_B_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xB843369BBD65CC6DULL + 0xF75EF2EBE33434D4ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xBFBF9020FBCFA721ULL + 0xFBA3D7D0E5AD2074ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xC27E7C15AA6C083DULL + 0xC7B9D0B590B676FAULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xCEBD63B875AB3B2DULL + 0xA8D12411DF720AA7ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xCF369BD484A3B5F7ULL + 0xC859C6A4E7B6C0E0ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xEBC9EE81D012D003ULL + 0x997BD357DE6E8DE7ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xA818A1EEBE041B9DULL + 0xDCB0339ACFCF0E5CULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x9338CE22813E22EBULL + 0x89069364B3F9B7B9ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xBFC86E69D299C08FULL + 0xACD7EBA2B4E7942FULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x826D3ECA86834BADULL + 0x9BC8F1C05AE19C44ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xA82EE63BB0BFBE29ULL + 0x936CC2185BE412B7ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xDA3392899BF549CDULL + 0x92AD3E661F3DBB7CULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xA64A39C5C8570569ULL + 0xDEFC7114AAA50BF2ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xA4CF9A6E98E97A3BULL + 0xAD46EC96AD61FEE7ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x850A2E15EE89C599ULL + 0xEC86ED82A36C11EEULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xD7F509C20EAD9941ULL + 0xB8EDF43CD7CD3823ULL);
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
        // read from: aOperationLaneA, aOperationLaneB, aWorkLaneB, aOperationLaneC, aOperationLaneD, aFireLaneB, aExpandLaneA, aFireLaneD, aWorkLaneC, aExpandLaneB, aWorkLaneD, aFireLaneA, aExpandLaneC, aFireLaneC, aWorkLaneA
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_c loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aWorkLaneB
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aWorkLaneB forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aFireLaneB
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aFireLaneB backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 5255U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneB[((aIndex + 4694U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aWorkLaneB[((aIndex + 3235U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 4678U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 7773U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 1832U)) & S_BLOCK1], 40U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aIngress, 35U)) ^ (RotL64(aPrevious, 52U) ^ RotL64(aCross, 19U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterC = (aWandererF + RotL64(aScatter, 47U)) + 13650869943246163567U;
            aOrbiterJ = ((aWandererD + RotL64(aPrevious, 24U)) + 3435284932011770999U) + aNonceWordC;
            aOrbiterH = ((aWandererC + RotL64(aCross, 39U)) + RotL64(aCarry, 23U)) + 12388155658186776579U;
            aOrbiterK = (((aWandererG + RotL64(aIngress, 19U)) + RotL64(aCarry, 11U)) + 2374345913955712039U) + aNonceWordA;
            aOrbiterB = ((aWandererK + RotL64(aCross, 13U)) + 6095094526980292156U) + aOrbiterAssignSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterE = ((aWandererB + RotL64(aPrevious, 35U)) + 4965147025852444174U) + aOrbiterAssignSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterF = (((aWandererH + RotL64(aScatter, 29U)) + RotL64(aCarry, 37U)) + 3261881216269075298U) + aNonceWordB;
            aOrbiterA = (aWandererA + RotL64(aIngress, 6U)) + 4939780217097329222U;
            aOrbiterG = ((aWandererI + RotL64(aCross, 43U)) + 3019862009792676287U) + aNonceWordI;
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 901910626217143974U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 3647055146712366383U;
            aOrbiterH = RotL64((aOrbiterH * 1792602402476450009U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 7731765438957392967U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 13409819457393479741U;
            aOrbiterB = RotL64((aOrbiterB * 3345078200262410715U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 5415832109107794258U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 8876738832313114471U;
            aOrbiterE = RotL64((aOrbiterE * 1304277600444504135U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 17135570542519390359U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 2373193062766802082U) ^ aNonceWordE;
            aOrbiterK = RotL64((aOrbiterK * 4213691513185791519U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 16318403285501718552U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 8456043288604687045U;
            aOrbiterF = RotL64((aOrbiterF * 10556964529144571683U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 10572534930284516528U) + aOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 14616251186735204677U) ^ aNonceWordJ;
            aOrbiterG = RotL64((aOrbiterG * 2048651204265459805U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 2837006243817205610U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 5315917323622194254U;
            aOrbiterA = RotL64((aOrbiterA * 4080522050089666599U), 19U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterF) + 12084676282761185907U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1]) + aNonceWordL;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 7922080344175593788U) ^ aOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 7603522302708937379U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 17620847289789547792U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 12140386059533463650U;
            aOrbiterC = RotL64((aOrbiterC * 1443266480620969535U), 23U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterG, 43U);
            aIngress = aIngress + (RotL64(aOrbiterA, 30U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterH, 37U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterC, 47U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterF, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 56U) + RotL64(aOrbiterF, 40U)) + aOrbiterE) + aNonceWordN);
            aWandererC = aWandererC + (((RotL64(aScatter, 29U) + RotL64(aOrbiterB, 27U)) + aOrbiterA) + RotL64(aCarry, 41U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterC, 47U)) + aOrbiterK);
            aWandererK = aWandererK + (((RotL64(aIngress, 37U) + aOrbiterA) + RotL64(aOrbiterC, 13U)) + aNonceWordO);
            aWandererG = aWandererG ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterE, 36U)) + aOrbiterJ) + aWandererUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aScatter, 23U) + RotL64(aOrbiterH, 19U)) + aOrbiterK);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 13U) + aOrbiterG) + RotL64(aOrbiterJ, 23U)) + aNonceWordM);
            aWandererB = aWandererB + ((((RotL64(aIngress, 51U) + aOrbiterE) + RotL64(aOrbiterK, 53U)) + RotL64(aCarry, 21U)) + aNonceWordF);
            aWandererH = aWandererH ^ (((RotL64(aCross, 42U) + aOrbiterG) + RotL64(aOrbiterA, 3U)) + aWandererUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 30U));
            aCarry = aCarry + (RotL64(aWandererH, 35U) ^ aWandererD);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 19U));
            aCarry = aCarry + (RotL64(aWandererG, 47U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererC, 11U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 2
        // ingress from: aExpandLaneA, aOperationLaneC, aFireLaneD
        // ingress directions: aExpandLaneA forward forced, aOperationLaneC forward forced, aFireLaneD forward/backward random
        // cross from: aOperationLaneA, aOperationLaneD, aWorkLaneC
        // cross directions: aOperationLaneA backward forced, aOperationLaneD backward forced, aWorkLaneC backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 14119U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneC[((aIndex + 9747U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 10170U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 12163U)) & S_BLOCK1], 6U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 11673U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aWorkLaneC[((aIndex + 9402U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCarry, 27U) + RotL64(aPrevious, 5U)) ^ (RotL64(aCross, 41U) ^ RotL64(aIngress, 54U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterK = (aWandererJ + RotL64(aIngress, 56U)) + 6973892330986118220U;
            aOrbiterI = ((((aWandererI + RotL64(aPrevious, 41U)) + RotL64(aCarry, 29U)) + 9886813896272094864U) + aOrbiterAssignSaltE[((aIndex + 7U)) & S_SALT1]) + aNonceWordH;
            aOrbiterE = (aWandererF + RotL64(aScatter, 29U)) + 10996306582517553173U;
            aOrbiterF = ((aWandererH + RotL64(aCross, 37U)) + RotL64(aCarry, 53U)) + 8490648283899856223U;
            aOrbiterD = (aWandererB + RotL64(aPrevious, 51U)) + 105141713530704655U;
            aOrbiterG = (aWandererE + RotL64(aScatter, 5U)) + 3114337422810562588U;
            aOrbiterA = ((aWandererG + RotL64(aIngress, 12U)) + 980857684690886131U) + aNonceWordM;
            aOrbiterB = ((aWandererC + RotL64(aCross, 23U)) + 6562042345807072665U) + aNonceWordE;
            aOrbiterJ = ((((aWandererD + RotL64(aScatter, 19U)) + RotL64(aCarry, 41U)) + 15665371138706353619U) + aOrbiterAssignSaltD[((aIndex + 26U)) & S_SALT1]) + aNonceWordP;
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 18113013571374375028U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterK) ^ 17405346422601997299U) ^ aOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterE = RotL64((aOrbiterE * 11162604605443005253U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 5130876096426182506U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 1813821672299154629U;
            aOrbiterG = RotL64((aOrbiterG * 15478100342425611875U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 15793814882743306728U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 13925299440495476399U) ^ aNonceWordA;
            aOrbiterA = RotL64((aOrbiterA * 12049601510660117401U), 37U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterG) + 9924458846049579438U) + aOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1]) + aNonceWordD;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 7810034662781768090U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 10310594595026622513U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 12812586478656872854U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 5709576448057435237U;
            aOrbiterF = RotL64((aOrbiterF * 9101555233909853025U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 7839807649914541516U) + aOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 4717944526755429647U;
            aOrbiterB = RotL64((aOrbiterB * 8515229146471335721U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 3933911971504256022U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 4814079680865379831U) ^ aNonceWordF;
            aOrbiterK = RotL64((aOrbiterK * 15100740696230557391U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 18352577312212175569U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 9670612998448920742U;
            aOrbiterD = RotL64((aOrbiterD * 5743579439303300553U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 72737302703035726U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 10032869372369626210U;
            aOrbiterJ = RotL64((aOrbiterJ * 7449905669249993731U), 41U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterD, 41U);
            aIngress = aIngress + (RotL64(aOrbiterK, 58U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterJ, 23U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 35U));
            aIngress = aIngress + RotL64(aOrbiterE, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 30U) + aOrbiterB) + RotL64(aOrbiterE, 51U)) + aNonceWordN);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 3U) + RotL64(aOrbiterD, 56U)) + aOrbiterA) + RotL64(aCarry, 57U)) + aNonceWordC);
            aWandererI = aWandererI ^ (((RotL64(aCross, 43U) + aOrbiterG) + RotL64(aOrbiterF, 47U)) + aNonceWordG);
            aWandererG = aWandererG + ((((RotL64(aIngress, 39U) + aOrbiterA) + RotL64(aOrbiterI, 27U)) + RotL64(aCarry, 39U)) + aNonceWordL);
            aWandererB = aWandererB ^ ((RotL64(aCross, 14U) + aOrbiterJ) + RotL64(aOrbiterI, 11U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterD, 35U)) + aOrbiterE) + aWandererUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterA, 3U)) + aOrbiterK) + aWandererUpdateSaltB[((aIndex + 9U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aScatter, 19U) + aOrbiterK) + RotL64(aOrbiterF, 40U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 23U) + aOrbiterD) + RotL64(aOrbiterJ, 21U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 19U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererH, 37U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererE, 3U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererJ, 26U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 3
        // ingress from: aExpandLaneB, aOperationLaneD, aWorkLaneD
        // ingress directions: aExpandLaneB forward forced, aOperationLaneD forward forced, aWorkLaneD forward/backward random
        // cross from: aExpandLaneA, aOperationLaneB, aFireLaneA
        // cross directions: aExpandLaneA backward forced, aOperationLaneB backward forced, aFireLaneA backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 19357U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneD[((aIndex + 17263U)) & S_BLOCK1], 30U));
            aIngress ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 19240U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 24303U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 17412U)) & S_BLOCK1], 53U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 24446U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCarry, 26U)) + (RotL64(aPrevious, 41U) + RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterI = ((aWandererD + RotL64(aIngress, 12U)) + RotL64(aCarry, 3U)) + 1898718075389870739U;
            aOrbiterD = ((aWandererC + RotL64(aPrevious, 23U)) + RotL64(aCarry, 53U)) + 5631794889237247403U;
            aOrbiterG = (aWandererJ + RotL64(aScatter, 47U)) + 18219714659484524607U;
            aOrbiterF = ((aWandererB + RotL64(aCross, 43U)) + 15419581386225732921U) + aNonceWordG;
            aOrbiterC = (((aWandererE + RotL64(aScatter, 57U)) + RotL64(aCarry, 19U)) + 9125575431710198210U) + aOrbiterAssignSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = ((aWandererG + RotL64(aPrevious, 3U)) + 12205871520544965505U) + aNonceWordI;
            aOrbiterA = (((aWandererI + RotL64(aIngress, 37U)) + 7617534300497343422U) + aOrbiterAssignSaltF[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordA;
            aOrbiterE = (aWandererK + RotL64(aCross, 52U)) + 18017579105368135814U;
            aOrbiterH = ((aWandererF + RotL64(aScatter, 27U)) + 10693882161946020042U) + aNonceWordD;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 11669615701700895306U) + aNonceWordP;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 11045110212889232165U;
            aOrbiterG = RotL64((aOrbiterG * 5965171269273719849U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 18019107802806469913U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 12315940560472528716U;
            aOrbiterI = RotL64((aOrbiterI * 4505122470351404065U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 4899009736070044310U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 17412253404253730364U;
            aOrbiterC = RotL64((aOrbiterC * 10791901166391946485U), 39U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 4826286251927854181U) + aOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 4523455921321845084U) ^ aOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 14534103906736598099U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 4132514462154182215U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 7164745605985109269U) ^ aNonceWordJ;
            aOrbiterE = RotL64((aOrbiterE * 14107325508977225261U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 6297434295807635654U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 8813887638672996646U;
            aOrbiterB = RotL64((aOrbiterB * 17495632530773158201U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 11086381278955626084U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 5660733992573928887U;
            aOrbiterA = RotL64((aOrbiterA * 11248164458720777889U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 14851044686208609882U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 12707776386060264479U;
            aOrbiterF = RotL64((aOrbiterF * 4470919091467313071U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 11508023384209716657U) + aOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 11752973809740920034U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 10212754472298834769U), 43U);
            //
            aIngress = RotL64(aOrbiterD, 35U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 46U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 43U));
            aIngress = aIngress + (RotL64(aOrbiterB, 5U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterC, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aScatter, 57U) + RotL64(aOrbiterB, 29U)) + aOrbiterC) + RotL64(aCarry, 27U)) + aWandererUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterH, 11U)) + aOrbiterD);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 24U) + RotL64(aOrbiterD, 47U)) + aOrbiterI) + RotL64(aCarry, 57U)) + aNonceWordN);
            aWandererF = aWandererF ^ (((RotL64(aCross, 39U) + RotL64(aOrbiterE, 6U)) + aOrbiterB) + aNonceWordE);
            aWandererD = aWandererD + ((RotL64(aPrevious, 11U) + RotL64(aOrbiterI, 57U)) + aOrbiterH);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 19U) + aOrbiterG) + RotL64(aOrbiterE, 41U));
            aWandererK = aWandererK + (((RotL64(aScatter, 35U) + RotL64(aOrbiterH, 23U)) + aOrbiterE) + aWandererUpdateSaltE[((aIndex + 12U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 3U) + aOrbiterF) + RotL64(aOrbiterH, 51U));
            aWandererC = aWandererC + ((RotL64(aScatter, 30U) + aOrbiterA) + RotL64(aOrbiterB, 34U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 19U) ^ aWandererC);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 10U));
            aCarry = aCarry + (RotL64(aWandererG, 57U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererF, 29U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererJ, 37U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 30186U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneA[((aIndex + 32728U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 27637U)) & S_BLOCK1], 52U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 26205U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 30120U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 25752U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCross, 24U) + RotL64(aPrevious, 3U)) ^ (RotL64(aIngress, 51U) ^ RotL64(aCarry, 39U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterG = ((aWandererD + RotL64(aIngress, 27U)) + RotL64(aCarry, 27U)) + 17454559218352016650U;
            aOrbiterK = (aWandererJ + RotL64(aCross, 60U)) + 8005709669325164803U;
            aOrbiterE = (aWandererH + RotL64(aPrevious, 23U)) + 13393741948412816357U;
            aOrbiterB = ((aWandererI + RotL64(aScatter, 47U)) + 3665865624348875553U) + aOrbiterAssignSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterC = (((aWandererE + RotL64(aPrevious, 51U)) + RotL64(aCarry, 3U)) + 8334142570031883436U) + aNonceWordL;
            aOrbiterD = ((aWandererF + RotL64(aIngress, 43U)) + 17226066128706139657U) + aOrbiterAssignSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = ((aWandererG + RotL64(aCross, 19U)) + RotL64(aCarry, 19U)) + 3319093033121522613U;
            aOrbiterI = ((aWandererA + RotL64(aScatter, 38U)) + 6657535603401588798U) + aNonceWordM;
            aOrbiterH = (aWandererK + RotL64(aIngress, 3U)) + 5469746182326331147U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 17846791786050221418U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 15939541003714896288U) ^ aNonceWordA;
            aOrbiterE = RotL64((aOrbiterE * 1400351482213119809U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 12076763190461077406U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 3594038213596405284U) ^ aNonceWordD;
            aOrbiterC = RotL64((aOrbiterC * 10244002692575821495U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 8301291631324464622U) + aNonceWordN;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 8460406137668390582U;
            aOrbiterA = RotL64((aOrbiterA * 9117147929757711595U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 7612394867020871200U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 8525076134853103975U;
            aOrbiterD = RotL64((aOrbiterD * 5790440201072204659U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 11929899088215090379U) + aOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 7119509166360685726U;
            aOrbiterG = RotL64((aOrbiterG * 1662341427992528823U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 5081078459225240607U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 17149991983909906705U;
            aOrbiterH = RotL64((aOrbiterH * 950223374568067343U), 53U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterG) + 8817303295675241994U) + aOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1]) + aNonceWordB;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 7962039282652745113U;
            aOrbiterI = RotL64((aOrbiterI * 12773588587795522121U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 13596273086338032370U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 8186297702278180956U;
            aOrbiterK = RotL64((aOrbiterK * 6226504769888753861U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 1696277861691580263U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 17360461831507082959U;
            aOrbiterB = RotL64((aOrbiterB * 1651378456022210983U), 27U);
            //
            aIngress = RotL64(aOrbiterH, 50U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterB, 47U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterD, 11U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 39U));
            aIngress = aIngress + RotL64(aOrbiterK, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aScatter, 19U) + aOrbiterC) + RotL64(aOrbiterA, 57U));
            aWandererG = aWandererG + ((((RotL64(aPrevious, 42U) + aOrbiterG) + RotL64(aOrbiterH, 47U)) + aNonceWordC) + aWandererUpdateSaltD[((aIndex + 12U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 23U) + aOrbiterD) + RotL64(aOrbiterC, 28U));
            aWandererF = aWandererF + (((RotL64(aCross, 51U) + aOrbiterE) + RotL64(aOrbiterD, 23U)) + RotL64(aCarry, 39U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 3U) + aOrbiterI) + RotL64(aOrbiterD, 39U));
            aWandererK = aWandererK + ((((RotL64(aCross, 14U) + aOrbiterA) + RotL64(aOrbiterB, 5U)) + aNonceWordE) + aWandererUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 29U) + aOrbiterK) + RotL64(aOrbiterG, 52U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterK, 43U)) + aOrbiterE) + RotL64(aCarry, 19U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterE, 11U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 37U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 53U));
            aCarry = aCarry + (RotL64(aWandererD, 58U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererJ, 11U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererI, 19U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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

void TwistExpander_Hockey_Arx::KDF_B_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xE3AA71ED35C4F14DULL + 0xFB11A7082BD65162ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xDC7F23538C768463ULL + 0xBB4B6F2B2E0B1856ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x8432162C4501D85DULL + 0xB877C39D2853FA1BULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xF29FBC275DACCD27ULL + 0xD6E0E6CF5D5DECB7ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xC427E9C25C277CBDULL + 0xCB9ADB599B0942D1ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xDAC6185CBE182125ULL + 0xAB731AD6911D5711ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xF8A0F5406093BFD5ULL + 0xB6C2DAA407C694E6ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xB0943D86BDE22F75ULL + 0xC47340DAEC1A8395ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xD6A93D2388E05DA7ULL + 0xBE99FF7C2C93433CULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xEF9C5BD19062CB87ULL + 0x99514A4B2318EF44ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xC1D9B9111C0F7221ULL + 0xF13EB631D9C358AAULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xD0B3E6767D57DE8BULL + 0xA33EDB6A6413F281ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xFC80A66FFF73F8FBULL + 0x80789544EB082B42ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xEBBA475C94B253A5ULL + 0xB06AAFBA654740A8ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xBAEE1137DA7CC415ULL + 0xFF13E5113A896699ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0x97BBC68D4A846CADULL + 0xA35F16874809B968ULL);
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
        // read from: aWorkLaneA, aWorkLaneB, aOperationLaneB, aWorkLaneC, aWorkLaneD, aFireLaneD, aExpandLaneA, aFireLaneA, aOperationLaneD, aExpandLaneB, aFireLaneB, aFireLaneC, aExpandLaneC, aOperationLaneC, aOperationLaneA
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_d loop 1
        // ingress from: aWorkLaneA, aWorkLaneB, aOperationLaneB
        // ingress directions: aWorkLaneA forward forced, aWorkLaneB forward forced, aOperationLaneB forward/backward random
        // cross from: aWorkLaneC, aWorkLaneD, aFireLaneD
        // cross directions: aWorkLaneC backward forced, aWorkLaneD backward forced, aFireLaneD backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 7468U)) & S_BLOCK1], 56U) ^ RotL64(aWorkLaneB[((aIndex + 4203U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 3923U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 63U)) & S_BLOCK1], 6U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 8154U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 1334U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCross, 37U)) + (RotL64(aCarry, 22U) + RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterH = ((aWandererG + RotL64(aCross, 27U)) + 9471546960258473684U) + aNonceWordK;
            aOrbiterB = (((aWandererI + RotL64(aIngress, 21U)) + RotL64(aCarry, 41U)) + 18050235435948942244U) + aOrbiterAssignSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterI = ((aWandererK + RotL64(aScatter, 43U)) + 3005107102671544641U) + aNonceWordA;
            aOrbiterK = (aWandererH + RotL64(aPrevious, 35U)) + 17898396434573801850U;
            aOrbiterA = ((aWandererD + RotL64(aIngress, 11U)) + 15071602525497771648U) + aOrbiterAssignSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = ((aWandererF + RotL64(aScatter, 50U)) + RotL64(aCarry, 57U)) + 5780119462702672108U;
            aOrbiterC = (((aWandererA + RotL64(aPrevious, 3U)) + RotL64(aCarry, 13U)) + 13301326224151025687U) + aNonceWordC;
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 18129323022260575961U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 1199228670638790709U;
            aOrbiterI = RotL64((aOrbiterI * 1780426336211781025U), 19U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterK) + 1839199978088021020U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordP;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 4999517042246790165U;
            aOrbiterA = RotL64((aOrbiterA * 4585813675677234577U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 8788607633376516299U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 15143903839930468749U) ^ aNonceWordB;
            aOrbiterF = RotL64((aOrbiterF * 12735914889325422675U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 16674732686428431869U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 15908873150953195581U) ^ aOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 18049755517524334107U), 41U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 11204775359756474667U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = (((aOrbiterB ^ aOrbiterF) ^ 2525984309543939465U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterB = RotL64((aOrbiterB * 3988529812023791571U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 4566345170476825512U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 14876612901557406267U;
            aOrbiterH = RotL64((aOrbiterH * 9047956948845135339U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 14926290877038883931U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 12710203178186614846U;
            aOrbiterC = RotL64((aOrbiterC * 14841163494801662515U), 5U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterB, 29U);
            aIngress = aIngress + (RotL64(aOrbiterF, 35U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 57U));
            aIngress = aIngress + RotL64(aOrbiterH, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((((RotL64(aCross, 56U) + RotL64(aOrbiterK, 41U)) + aOrbiterA) + aNonceWordM) + aWandererUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterI, 27U)) + aOrbiterH) + RotL64(aCarry, 41U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 5U) + aOrbiterH) + RotL64(aOrbiterK, 20U)) + aWandererUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aIngress, 29U) + aOrbiterK) + RotL64(aOrbiterF, 35U)) + aNonceWordD);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 41U) + aOrbiterA) + RotL64(aOrbiterB, 13U));
            aWandererI = aWandererI + ((((RotL64(aCross, 47U) + aOrbiterC) + RotL64(aOrbiterA, 51U)) + RotL64(aCarry, 19U)) + aNonceWordL);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 21U) + aOrbiterF) + RotL64(aOrbiterC, 57U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 47U) ^ aWandererF);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 52U));
            aCarry = aCarry + (RotL64(aWandererA, 29U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererH, 11U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 2
        // ingress from: aExpandLaneA, aWorkLaneC, aFireLaneA
        // ingress directions: aExpandLaneA forward forced, aWorkLaneC forward forced, aFireLaneA forward/backward random
        // cross from: aWorkLaneA, aWorkLaneD, aOperationLaneD
        // cross directions: aWorkLaneA backward forced, aWorkLaneD backward forced, aOperationLaneD backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 13773U)) & S_BLOCK1], 28U) ^ RotL64(aWorkLaneC[((aIndex + 9467U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 10113U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 13456U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 16186U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aOperationLaneD[((aIndex + 8712U)) & S_BLOCK1], 60U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aPrevious, 29U) + RotL64(aCross, 11U)) ^ (RotL64(aCarry, 58U) + RotL64(aIngress, 41U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterE = ((aWandererG + RotL64(aCross, 5U)) + 17225673071833726819U) + aOrbiterAssignSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterD = (aWandererI + RotL64(aIngress, 23U)) + 10301458382103627331U;
            aOrbiterB = ((aWandererH + RotL64(aScatter, 29U)) + RotL64(aCarry, 53U)) + 3960233050857362414U;
            aOrbiterA = (((aWandererC + RotL64(aPrevious, 51U)) + RotL64(aCarry, 11U)) + 17768665685046605837U) + aNonceWordO;
            aOrbiterF = (aWandererB + RotL64(aScatter, 58U)) + 14471018461213959767U;
            aOrbiterI = ((aWandererF + RotL64(aIngress, 11U)) + RotL64(aCarry, 41U)) + 10730597892721340453U;
            aOrbiterJ = (((aWandererK + RotL64(aCross, 35U)) + 14863394003122760542U) + aOrbiterAssignSaltC[((aIndex + 12U)) & S_SALT1]) + aNonceWordD;
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 9948587274816688296U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterE) ^ 3573569431435100993U) ^ aOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterB = RotL64((aOrbiterB * 2303922230056523077U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 8153670675740450590U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 16438856577722561424U) ^ aNonceWordJ;
            aOrbiterD = RotL64((aOrbiterD * 4689247488336908827U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 15765587867581925041U) + aNonceWordC;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 1082039522061775213U;
            aOrbiterA = RotL64((aOrbiterA * 17023740047246402641U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 4202521649260798876U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 15877659681260461141U;
            aOrbiterE = RotL64((aOrbiterE * 11369910758551088173U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 2551560426129646123U) + aNonceWordB;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 3005102326163906320U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4241583192662435107U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 1675501058857208089U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 12774812270956702043U) ^ aOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5488437008504905105U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 1044886020922563597U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 4857445127457225171U;
            aOrbiterJ = RotL64((aOrbiterJ * 13223560654459705259U), 11U);
            //
            aIngress = RotL64(aOrbiterF, 11U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 19U));
            aIngress = aIngress + (RotL64(aOrbiterI, 27U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterJ, 38U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aScatter, 5U) + aOrbiterI) + RotL64(aOrbiterA, 40U)) + aWandererUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 28U) + aOrbiterI) + RotL64(aOrbiterB, 5U)) + aNonceWordL);
            aWandererG = aWandererG + ((((RotL64(aCross, 13U) + aOrbiterJ) + RotL64(aOrbiterD, 51U)) + aNonceWordN) + aWandererUpdateSaltA[((aIndex + 11U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterF, 11U)) + aOrbiterB) + aNonceWordK);
            aWandererB = aWandererB + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterB, 57U)) + aOrbiterJ) + RotL64(aCarry, 37U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 37U) + aOrbiterD) + RotL64(aOrbiterE, 19U));
            aWandererH = aWandererH + ((((RotL64(aCross, 57U) + aOrbiterD) + RotL64(aOrbiterI, 29U)) + RotL64(aCarry, 51U)) + aNonceWordG);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 43U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 30U));
            aCarry = aCarry + (RotL64(aWandererI, 23U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererG, 3U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 3
        // ingress from: aExpandLaneB, aWorkLaneD, aFireLaneB
        // ingress directions: aExpandLaneB forward forced, aWorkLaneD forward forced, aFireLaneB forward/backward random
        // cross from: aExpandLaneA, aWorkLaneB, aFireLaneC
        // cross directions: aExpandLaneA backward forced, aWorkLaneB backward forced, aFireLaneC backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 17491U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneD[((aIndex + 23644U)) & S_BLOCK1], 58U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 24371U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 23377U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 18186U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aFireLaneC[((aIndex + 23642U)) & S_BLOCK1], 14U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCross, 34U) ^ RotL64(aPrevious, 51U)) + (RotL64(aCarry, 5U) + RotL64(aIngress, 19U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterB = (aWandererB + RotL64(aIngress, 47U)) + 3236820517816085022U;
            aOrbiterG = (((aWandererA + RotL64(aCross, 23U)) + RotL64(aCarry, 3U)) + 741288875914097926U) + aNonceWordP;
            aOrbiterD = ((((aWandererH + RotL64(aScatter, 29U)) + RotL64(aCarry, 43U)) + 8417246926007729580U) + aOrbiterAssignSaltA[((aIndex + 21U)) & S_SALT1]) + aNonceWordI;
            aOrbiterA = (aWandererD + RotL64(aPrevious, 37U)) + 9715717805774537170U;
            aOrbiterC = (aWandererK + RotL64(aScatter, 56U)) + 14360243844821619482U;
            aOrbiterE = ((aWandererF + RotL64(aPrevious, 13U)) + RotL64(aCarry, 29U)) + 10760908100206775334U;
            aOrbiterJ = (((aWandererC + RotL64(aCross, 3U)) + 3434641779946167811U) + aOrbiterAssignSaltD[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordE;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 7885568822756234567U) + aNonceWordK;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 3041563437672051294U;
            aOrbiterD = RotL64((aOrbiterD * 11440300917533482297U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 15761355327564963516U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 1158633562785937421U) ^ aOrbiterUpdateSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15511324886867188235U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 9338581575871970653U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 9172038894262857354U) ^ aNonceWordC;
            aOrbiterA = RotL64((aOrbiterA * 3110871165285625807U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 14653924713599790081U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 3854497592598563309U;
            aOrbiterJ = RotL64((aOrbiterJ * 11737111068815795303U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 16286980180327600557U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 5092583772591249756U;
            aOrbiterG = RotL64((aOrbiterG * 13955105624639442903U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 4288397994175567333U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterJ) ^ 15584236478994873104U) ^ aOrbiterUpdateSaltB[((aIndex + 14U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterC = RotL64((aOrbiterC * 1860480595862755379U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 5557463939827483792U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 2659814275753280856U;
            aOrbiterB = RotL64((aOrbiterB * 17702430405693184643U), 57U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterD, 35U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 53U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 19U));
            aIngress = aIngress + RotL64(aOrbiterB, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aScatter, 58U) + RotL64(aOrbiterG, 58U)) + aOrbiterE);
            aWandererF = aWandererF ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterE, 27U)) + aOrbiterC);
            aWandererH = aWandererH + (((RotL64(aIngress, 27U) + RotL64(aOrbiterC, 47U)) + aOrbiterB) + aNonceWordD);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterA, 39U)) + aOrbiterJ);
            aWandererC = aWandererC + ((((RotL64(aIngress, 41U) + RotL64(aOrbiterD, 5U)) + aOrbiterA) + RotL64(aCarry, 21U)) + aWandererUpdateSaltC[((aIndex + 22U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 21U) + aOrbiterC) + RotL64(aOrbiterJ, 11U)) + aNonceWordB);
            aWandererK = aWandererK + (((((RotL64(aCross, 13U) + aOrbiterC) + RotL64(aOrbiterG, 21U)) + RotL64(aCarry, 3U)) + aNonceWordF) + aWandererUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 6U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 23U));
            aCarry = aCarry + (RotL64(aWandererD, 29U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererH, 57U);
            aCarry = aCarry + RotL64(aIngress, 48U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aOperationLaneC
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aOperationLaneC forward/backward random
        // cross from: aExpandLaneB, aWorkLaneC, aOperationLaneA
        // cross directions: aExpandLaneB backward forced, aWorkLaneC backward forced, aOperationLaneA backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 30268U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneA[((aIndex + 28456U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aOperationLaneC[((aIndex + 32538U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30166U)) & S_BLOCK1], 42U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 24784U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aOperationLaneA[((aIndex + 28187U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aPrevious, 23U) + RotL64(aCross, 11U)) + (RotL64(aCarry, 51U) ^ RotL64(aIngress, 38U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterD = (((aWandererK + RotL64(aPrevious, 47U)) + RotL64(aCarry, 13U)) + 1393781663398437180U) + aNonceWordF;
            aOrbiterE = ((aWandererF + RotL64(aCross, 37U)) + 17414594746688585273U) + aOrbiterAssignSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterJ = (((aWandererI + RotL64(aIngress, 21U)) + RotL64(aCarry, 43U)) + 2823888497053071250U) + aOrbiterAssignSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = (aWandererA + RotL64(aScatter, 29U)) + 17032631958617884859U;
            aOrbiterH = (aWandererG + RotL64(aPrevious, 11U)) + 15222697630461125019U;
            aOrbiterG = (((aWandererC + RotL64(aCross, 3U)) + RotL64(aCarry, 27U)) + 15737414920751551780U) + aNonceWordM;
            aOrbiterI = (aWandererE + RotL64(aScatter, 56U)) + 1357196111055783001U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 5315122321649251691U) + aOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 7893744655508595974U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 17863000246694319149U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 16721939414324611738U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = (((aOrbiterA ^ aOrbiterE) ^ 3444375866323610848U) ^ aOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterA = RotL64((aOrbiterA * 10874157227815775661U), 41U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 1825716513674511632U) + aNonceWordJ;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 15582066843912467318U;
            aOrbiterD = RotL64((aOrbiterD * 12765146555943757373U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 15673590949193923915U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 13887365046280406413U;
            aOrbiterH = RotL64((aOrbiterH * 3169061375011420121U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 12730414371734709356U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 4819112390640821927U;
            aOrbiterI = RotL64((aOrbiterI * 8782547948627685451U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 3089925954422937464U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 7180179304678622530U) ^ aNonceWordG;
            aOrbiterG = RotL64((aOrbiterG * 16118051565147747413U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 17030269962085008657U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 6675917351883004046U;
            aOrbiterE = RotL64((aOrbiterE * 14134335325316949687U), 11U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterA, 21U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 35U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 51U));
            aIngress = aIngress + RotL64(aOrbiterI, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 23U) + aOrbiterG) + RotL64(aOrbiterH, 21U)) + aNonceWordL);
            aWandererF = aWandererF + (((RotL64(aIngress, 51U) + RotL64(aOrbiterI, 58U)) + aOrbiterJ) + aWandererUpdateSaltE[((aIndex + 5U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterD, 35U)) + aOrbiterI);
            aWandererC = aWandererC + (((RotL64(aCross, 57U) + aOrbiterE) + RotL64(aOrbiterA, 51U)) + RotL64(aCarry, 51U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 4U) + RotL64(aOrbiterE, 41U)) + aOrbiterG) + aNonceWordE);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 35U) + aOrbiterI) + RotL64(aOrbiterA, 3U)) + RotL64(aCarry, 13U)) + aNonceWordC);
            aWandererI = aWandererI ^ (((RotL64(aCross, 41U) + aOrbiterE) + RotL64(aOrbiterJ, 29U)) + aWandererUpdateSaltD[((aIndex + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 26U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererF, 3U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererK, 37U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererA, 19U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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

void TwistExpander_Hockey_Arx::Seed_A(TwistWorkSpace *pWorkSpace,
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
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltE;
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
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA;
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
    [[maybe_unused]] std::uint64_t *aPhaseHWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseHWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltB;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xC02E443523636C21ULL + 0xA01208D9D2F4AC3BULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xFD64604790323EA9ULL + 0xF96A3E8EE2BC3E78ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xE98FD8B64A46F8E7ULL + 0xD54D5B67A9C1AE04ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x9DD2CD5449EDEC0FULL + 0xEBD406C7536D0695ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xB0BA73D043AF1337ULL + 0xE16CA4DCA4534957ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xA5908C65E663B685ULL + 0x9583BA498540671AULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xFB2153BC18496031ULL + 0xE6ED84A724597F69ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x9A75D2425A95082DULL + 0xEDF7203B3D3835A7ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xBE5A207F2E763DADULL + 0x93271E9ED9ED6EC1ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0x9742C3F5722112F1ULL + 0xA51F208A4817ACD2ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xD79225AF4DE01E3DULL + 0xC1A2194678FE4E29ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xB69C87563C33CD73ULL + 0xCFF56D9911C36FCEULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xDF645D93CF53BFDFULL + 0xBA7C5C746D68B838ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x8CD4C363C13B6541ULL + 0x8EA88256E813B3F1ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x8D64ADFD41018AC7ULL + 0xAE7AA4A477DBF40FULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xB2091DD6C23A9B51ULL + 0x9F1D87E662608A58ULL);
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
            aIngress = RotL64(aKeyRowReadA[((aIndex + 2028U)) & W_KEY1], 5U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 2420U)) & W_KEY1], 23U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 307U)) & W_KEY1], 53U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 1915U)) & S_BLOCK1], 24U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCarry, 41U) ^ RotL64(aIngress, 57U)) + (RotL64(aPrevious, 5U) + RotL64(aCross, 28U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterE = ((aWandererH + RotL64(aScatter, 21U)) + 966899917801652720U) + aNonceWordJ;
            aOrbiterF = ((aWandererD + RotL64(aPrevious, 43U)) + RotL64(aCarry, 21U)) + 10996327672320748649U;
            aOrbiterG = ((aWandererB + RotL64(aIngress, 34U)) + RotL64(aCarry, 35U)) + 4188171566846621107U;
            aOrbiterH = (((aWandererJ + RotL64(aCross, 27U)) + RotL64(aCarry, 5U)) + 5886209243097387959U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = ((aWandererA + RotL64(aIngress, 51U)) + 14940428957136728111U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = ((aWandererG + RotL64(aCross, 5U)) + 179187285531914832U) + aNonceWordH;
            aOrbiterJ = (aWandererK + RotL64(aScatter, 13U)) + 6685351948936817752U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 1894506461704029700U) + aNonceWordA;
            aOrbiterG = (((aOrbiterG ^ aOrbiterE) ^ 4182760368636977082U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterG = RotL64((aOrbiterG * 972988091869133921U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 12523318028514940790U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 5059306166973366892U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2857409765717296483U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 5890872367917643851U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 17747338389865221534U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 5306740664798049267U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 13906227834259884100U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 7152105382899756368U;
            aOrbiterE = RotL64((aOrbiterE * 6772157117358310485U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 17868101884759619240U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 11758843266314148347U;
            aOrbiterH = RotL64((aOrbiterH * 5919135169337501485U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 13950566197090324859U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 17278105609930477854U;
            aOrbiterJ = RotL64((aOrbiterJ * 11431842718945107359U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 9556785965646738355U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 841298436857932987U) ^ aNonceWordP;
            aOrbiterD = RotL64((aOrbiterD * 15077843186688841797U), 21U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterE, 19U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 30U));
            aIngress = aIngress + (RotL64(aOrbiterD, 11U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterJ, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aIngress, 39U) + RotL64(aOrbiterJ, 47U)) + aOrbiterF) + aNonceWordM);
            aWandererA = aWandererA + ((RotL64(aPrevious, 13U) + RotL64(aOrbiterD, 5U)) + aOrbiterJ);
            aWandererK = aWandererK ^ (((RotL64(aCross, 5U) + aOrbiterH) + RotL64(aOrbiterF, 11U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 60U) + RotL64(aOrbiterJ, 39U)) + aOrbiterG) + RotL64(aCarry, 39U)) + aNonceWordI);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 53U) + aOrbiterE) + RotL64(aOrbiterH, 53U));
            aWandererH = aWandererH + ((((RotL64(aIngress, 29U) + aOrbiterJ) + RotL64(aOrbiterH, 19U)) + RotL64(aCarry, 57U)) + aPhaseEWandererUpdateSaltA[((aIndex + 19U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterB, 30U)) + aOrbiterF) + aNonceWordN);
            //
            aCarry = aCarry + (RotL64(aWandererD, 36U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererB, 3U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererG, 21U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererH, 13U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 4761U)) & S_BLOCK1], 13U) ^ RotL64(aKeyRowReadA[((aIndex + 4537U)) & W_KEY1], 54U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 4626U)) & W_KEY1], 57U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 2782U)) & S_BLOCK1], 6U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCarry, 23U) ^ RotL64(aIngress, 51U)) + (RotL64(aCross, 6U) + RotL64(aPrevious, 39U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterD = (aWandererD + RotL64(aScatter, 11U)) + 5160910997561396461U;
            aOrbiterK = ((aWandererC + RotL64(aPrevious, 41U)) + RotL64(aCarry, 43U)) + 14920764751058512062U;
            aOrbiterC = (((aWandererB + RotL64(aIngress, 5U)) + 6080952401749660022U) + aPhaseEOrbiterAssignSaltC[((aIndex + 13U)) & S_SALT1]) + aNonceWordM;
            aOrbiterJ = ((aWandererK + RotL64(aCross, 21U)) + 17667234330526298627U) + aNonceWordJ;
            aOrbiterI = (((aWandererI + RotL64(aIngress, 60U)) + 760630072638686756U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordA;
            aOrbiterE = ((aWandererA + RotL64(aScatter, 47U)) + RotL64(aCarry, 3U)) + 3504157162816997476U;
            aOrbiterH = ((aWandererG + RotL64(aCross, 53U)) + RotL64(aCarry, 21U)) + 9489022223422585882U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 1149898536879968964U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterD) ^ 10492284328940025310U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterC = RotL64((aOrbiterC * 7893416766300156495U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 13213275606286399312U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 10557118912847180413U;
            aOrbiterI = RotL64((aOrbiterI * 10077877991284587845U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 15618980209023994776U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 5268600749854045564U) ^ aNonceWordB;
            aOrbiterK = RotL64((aOrbiterK * 3849660559223919613U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 8011552687609649990U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 3148133096349525066U;
            aOrbiterH = RotL64((aOrbiterH * 5245156554959620007U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 12032847944237867285U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 14999005703490824673U;
            aOrbiterE = RotL64((aOrbiterE * 6631584955208646049U), 41U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterH) + 5426735969392906710U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1]) + aNonceWordH;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 3593177531650386729U;
            aOrbiterJ = RotL64((aOrbiterJ * 12997284886192717043U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 1701444719333347373U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 15928731228196894960U) ^ aNonceWordD;
            aOrbiterD = RotL64((aOrbiterD * 1919318226904213433U), 19U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterJ, 51U);
            aIngress = aIngress + (RotL64(aOrbiterE, 29U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 5U));
            aIngress = aIngress + RotL64(aOrbiterI, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterH, 11U)) + aOrbiterI) + aNonceWordE);
            aWandererK = aWandererK + ((((RotL64(aCross, 29U) + aOrbiterC) + RotL64(aOrbiterH, 3U)) + RotL64(aCarry, 35U)) + aNonceWordP);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 19U) + aOrbiterC) + RotL64(aOrbiterJ, 27U)) + aPhaseEWandererUpdateSaltB[((aIndex + 25U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 38U) + RotL64(aOrbiterC, 43U)) + aOrbiterD) + RotL64(aCarry, 53U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 5U) + aOrbiterI) + RotL64(aOrbiterD, 53U)) + aNonceWordL);
            aWandererA = aWandererA + (((RotL64(aCross, 13U) + RotL64(aOrbiterH, 35U)) + aOrbiterE) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterD, 20U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 51U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 29U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 14U));
            aCarry = aCarry + RotL64(aWandererC, 47U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = RotL64(aWorkLaneB[((aIndex + 8160U)) & S_BLOCK1], 27U) ^ RotL64(aKeyRowReadB[((aIndex + 7376U)) & W_KEY1], 11U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 6488U)) & W_KEY1], 21U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 6027U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 7857U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCross, 35U) + RotL64(aPrevious, 60U)) + (RotL64(aIngress, 47U) ^ RotL64(aCarry, 19U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterK = (aWandererI + RotL64(aIngress, 37U)) + 9471546960258473684U;
            aOrbiterH = (aWandererK + RotL64(aPrevious, 43U)) + 18050235435948942244U;
            aOrbiterJ = (((aWandererD + RotL64(aCross, 23U)) + RotL64(aCarry, 41U)) + 3005107102671544641U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = ((aWandererF + RotL64(aScatter, 53U)) + 17898396434573801850U) + aNonceWordD;
            aOrbiterF = (((aWandererE + RotL64(aIngress, 11U)) + RotL64(aCarry, 23U)) + 15071602525497771648U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterE = (((aWandererG + RotL64(aScatter, 30U)) + RotL64(aCarry, 53U)) + 5780119462702672108U) + aNonceWordK;
            aOrbiterD = (aWandererJ + RotL64(aPrevious, 3U)) + 13301326224151025687U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 18129323022260575961U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 1199228670638790709U;
            aOrbiterJ = RotL64((aOrbiterJ * 1780426336211781025U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 1839199978088021020U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 4999517042246790165U;
            aOrbiterK = RotL64((aOrbiterK * 4585813675677234577U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 8788607633376516299U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 15143903839930468749U) ^ aNonceWordO;
            aOrbiterI = RotL64((aOrbiterI * 12735914889325422675U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 16674732686428431869U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 15908873150953195581U;
            aOrbiterE = RotL64((aOrbiterE * 18049755517524334107U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 11204775359756474667U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 2525984309543939465U;
            aOrbiterD = RotL64((aOrbiterD * 3988529812023791571U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 4566345170476825512U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 14876612901557406267U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9047956948845135339U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 14926290877038883931U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterD) ^ 12710203178186614846U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterF = RotL64((aOrbiterF * 14841163494801662515U), 11U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterH, 3U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 30U));
            aIngress = aIngress + (RotL64(aOrbiterK, 53U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterE, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aIngress, 53U) + RotL64(aOrbiterH, 5U)) + aOrbiterD) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterJ, 29U)) + aOrbiterK) + aNonceWordM);
            aWandererG = aWandererG + (((((RotL64(aCross, 27U) + RotL64(aOrbiterF, 35U)) + aOrbiterI) + RotL64(aCarry, 13U)) + aNonceWordG) + aPhaseEWandererUpdateSaltB[((aIndex + 5U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 60U) + RotL64(aOrbiterJ, 19U)) + aOrbiterE) + aNonceWordE);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 11U) + RotL64(aOrbiterD, 54U)) + aOrbiterF);
            aWandererF = aWandererF ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterE, 47U)) + aOrbiterH);
            aWandererI = aWandererI + (((RotL64(aIngress, 35U) + aOrbiterE) + RotL64(aOrbiterI, 41U)) + RotL64(aCarry, 57U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 26U));
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererJ, 41U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererK, 19U);
            aCarry = aCarry + RotL64(aIngress, 10U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 10336U)) & S_BLOCK1], 37U) ^ RotL64(aKeyRowReadB[((aIndex + 10386U)) & W_KEY1], 29U));
            aIngress ^= (RotL64(mSource[((aIndex + 9803U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 8847U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 10354U)) & W_KEY1], 18U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 10845U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aIngress, 6U) ^ RotL64(aCarry, 29U)) ^ (RotL64(aCross, 53U) + RotL64(aPrevious, 41U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterB = ((aWandererI + RotL64(aScatter, 21U)) + 8685374557928800912U) + aNonceWordA;
            aOrbiterD = (aWandererG + RotL64(aPrevious, 51U)) + 3482312691892161229U;
            aOrbiterG = ((aWandererH + RotL64(aCross, 29U)) + 6948130297389161165U) + aNonceWordP;
            aOrbiterC = ((aWandererK + RotL64(aIngress, 5U)) + RotL64(aCarry, 41U)) + 5506385663788942690U;
            aOrbiterE = (((aWandererJ + RotL64(aScatter, 43U)) + RotL64(aCarry, 5U)) + 17859982009307397161U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = (aWandererE + RotL64(aPrevious, 37U)) + 9178488809207094043U;
            aOrbiterH = ((((aWandererA + RotL64(aCross, 60U)) + RotL64(aCarry, 23U)) + 1835479501226057169U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordF;
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 5368101733632614939U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 9050459666576835422U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10351719549990259551U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 9042186993119635078U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 17528342580198295025U;
            aOrbiterJ = RotL64((aOrbiterJ * 14316671546614386775U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 6495418332558436882U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 8834495762667327342U;
            aOrbiterC = RotL64((aOrbiterC * 10783141541937645995U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 4364314196965690905U) + aNonceWordO;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 6357485231062120459U;
            aOrbiterD = RotL64((aOrbiterD * 289429584586504995U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 3321488322626415347U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 10817330671781848737U;
            aOrbiterB = RotL64((aOrbiterB * 15875919466358823335U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 17974092279281611763U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterH = (((aOrbiterH ^ aOrbiterE) ^ 2871472057292789157U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterH = RotL64((aOrbiterH * 16104199340711015181U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 15187929795092006849U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 13482063681546475923U) ^ aNonceWordD;
            aOrbiterE = RotL64((aOrbiterE * 14466266308157364963U), 5U);
            //
            aIngress = RotL64(aOrbiterG, 27U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 43U));
            aIngress = aIngress + (RotL64(aOrbiterE, 11U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterJ, 34U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((((RotL64(aPrevious, 44U) + aOrbiterB) + RotL64(aOrbiterJ, 5U)) + RotL64(aCarry, 57U)) + aNonceWordL) + aPhaseFWandererUpdateSaltA[((aIndex + 3U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 21U) + RotL64(aOrbiterC, 50U)) + aOrbiterG) + aNonceWordH);
            aWandererH = aWandererH + (((RotL64(aIngress, 29U) + RotL64(aOrbiterE, 29U)) + aOrbiterC) + RotL64(aCarry, 21U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 3U) + aOrbiterH) + RotL64(aOrbiterE, 43U)) + aPhaseFWandererUpdateSaltD[((aIndex + 4U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterD, 37U)) + aOrbiterG) + aNonceWordK);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 35U) + aOrbiterJ) + RotL64(aOrbiterE, 23U));
            aWandererA = aWandererA + (((RotL64(aCross, 11U) + aOrbiterJ) + RotL64(aOrbiterC, 57U)) + aNonceWordC);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 6U));
            aCarry = aCarry + (RotL64(aWandererI, 57U) ^ aWandererJ);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 13U));
            aCarry = aCarry + RotL64(aWandererG, 53U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = (RotL64(aWorkLaneD[((aIndex + 11202U)) & S_BLOCK1], 54U) ^ RotL64(aKeyRowReadA[((aIndex + 13602U)) & W_KEY1], 35U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 13245U)) & W_KEY1], 3U) ^ RotL64(mSource[((aIndex + 13570U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aWorkLaneB[((aIndex + 11624U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordE));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 12812U)) & S_BLOCK1], 48U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 11717U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCross, 52U) ^ RotL64(aPrevious, 23U)) + (RotL64(aCarry, 11U) + RotL64(aIngress, 35U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterF = (((aWandererF + RotL64(aIngress, 35U)) + RotL64(aCarry, 13U)) + 2672739400294801233U) + aNonceWordB;
            aOrbiterH = ((aWandererA + RotL64(aPrevious, 41U)) + RotL64(aCarry, 35U)) + 8475624545015101850U;
            aOrbiterI = (((aWandererJ + RotL64(aScatter, 11U)) + RotL64(aCarry, 51U)) + 1252755112289831257U) + aPhaseFOrbiterAssignSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = ((aWandererD + RotL64(aCross, 29U)) + 7938039507649183387U) + aNonceWordI;
            aOrbiterC = (aWandererH + RotL64(aPrevious, 53U)) + 8167413146948861022U;
            aOrbiterK = ((aWandererE + RotL64(aIngress, 22U)) + 17712313989694374353U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterJ = (aWandererI + RotL64(aCross, 3U)) + 7637042279892596975U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 15770412950033467341U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 3951812021898608685U;
            aOrbiterI = RotL64((aOrbiterI * 6623127125223204737U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 8656983621098246507U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 17943342344730687317U;
            aOrbiterC = RotL64((aOrbiterC * 16495519451034883813U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 3087677463651608668U) + aNonceWordJ;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 16493240011924342788U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 16898479041530771871U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 7750923317452683057U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterA) ^ 2185924841611106546U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterJ = RotL64((aOrbiterJ * 708072658250726381U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 14676868738946722416U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 6849098251696302393U) ^ aNonceWordP;
            aOrbiterF = RotL64((aOrbiterF * 2599806275837778069U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 17817755047153606419U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 9900465270314068757U) ^ aNonceWordD;
            aOrbiterH = RotL64((aOrbiterH * 9267925873983176685U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 11380000891112113701U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 15930503831156546113U;
            aOrbiterA = RotL64((aOrbiterA * 14450535035065393845U), 13U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterI, 23U);
            aIngress = aIngress + (RotL64(aOrbiterH, 51U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterK, 58U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterF, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((((RotL64(aIngress, 47U) + aOrbiterF) + RotL64(aOrbiterC, 21U)) + aNonceWordN) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aCross, 29U) + RotL64(aOrbiterF, 34U)) + aOrbiterK);
            aWandererD = aWandererD ^ ((((RotL64(aPrevious, 11U) + aOrbiterI) + RotL64(aOrbiterK, 51U)) + aNonceWordH) + aPhaseFWandererUpdateSaltF[((aIndex + 14U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 36U) + aOrbiterA) + RotL64(aOrbiterK, 11U)) + RotL64(aCarry, 37U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 53U) + aOrbiterA) + RotL64(aOrbiterJ, 5U)) + aNonceWordC);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 5U) + aOrbiterJ) + RotL64(aOrbiterH, 57U)) + RotL64(aCarry, 21U)) + aNonceWordF);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 23U) + aOrbiterI) + RotL64(aOrbiterA, 27U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 52U));
            aCarry = aCarry + (RotL64(aWandererF, 21U) ^ aWandererE);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 11U));
            aCarry = aCarry + RotL64(aWandererD, 39U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 15255U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneC[((aIndex + 15378U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 15791U)) & W_KEY1], 38U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 15919U)) & W_KEY1], 21U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 14503U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 13692U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 15048U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aPrevious, 20U)) + (RotL64(aCarry, 53U) ^ RotL64(aIngress, 35U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterF = (aWandererH + RotL64(aScatter, 51U)) + 10038936806177516123U;
            aOrbiterH = ((aWandererC + RotL64(aIngress, 35U)) + RotL64(aCarry, 23U)) + 1773168435195292638U;
            aOrbiterE = (((aWandererI + RotL64(aCross, 11U)) + RotL64(aCarry, 41U)) + 10655711161526628072U) + aNonceWordM;
            aOrbiterB = ((aWandererG + RotL64(aPrevious, 26U)) + 14422295664639740437U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = ((aWandererE + RotL64(aScatter, 43U)) + RotL64(aCarry, 11U)) + 4125228715513159576U;
            aOrbiterA = ((aWandererF + RotL64(aIngress, 19U)) + 3670449653158650845U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterK = ((aWandererB + RotL64(aPrevious, 57U)) + 17553727567180813057U) + aNonceWordH;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 5111401772713882743U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 7688573124662314413U;
            aOrbiterE = RotL64((aOrbiterE * 10846442063022821393U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 9438375825507814395U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 14177477039902118886U;
            aOrbiterJ = RotL64((aOrbiterJ * 6467406626985022537U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 16329942595859623928U) + aNonceWordI;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 3990536794006836672U;
            aOrbiterA = RotL64((aOrbiterA * 579024714339065373U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 5072881436583180756U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 16789727877867289997U) ^ aNonceWordN;
            aOrbiterK = RotL64((aOrbiterK * 8766246302636197905U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 17313956922306689438U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterA) ^ 11530878396329822041U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterB = RotL64((aOrbiterB * 11356860047841383129U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 3612616532321160196U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 4172189825359187763U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 12938945495299393177U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 8677279703778052804U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterK) ^ 1912172980909479362U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterH = RotL64((aOrbiterH * 10053289257955474143U), 27U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterJ, 13U);
            aIngress = aIngress + (RotL64(aOrbiterB, 51U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterK, 58U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterA, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterE, 35U)) + aOrbiterK) + aNonceWordD);
            aWandererH = aWandererH + ((((RotL64(aIngress, 19U) + RotL64(aOrbiterF, 41U)) + aOrbiterE) + RotL64(aCarry, 3U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 60U) + aOrbiterH) + RotL64(aOrbiterJ, 5U));
            aWandererE = aWandererE + (((((RotL64(aCross, 39U) + aOrbiterH) + RotL64(aOrbiterF, 29U)) + RotL64(aCarry, 27U)) + aNonceWordL) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterJ, 13U)) + aOrbiterE);
            aWandererF = aWandererF + (((RotL64(aScatter, 29U) + RotL64(aOrbiterF, 54U)) + aOrbiterA) + aNonceWordA);
            aWandererI = aWandererI ^ ((RotL64(aCross, 13U) + aOrbiterH) + RotL64(aOrbiterB, 47U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 12U));
            aCarry = aCarry + (RotL64(aWandererE, 35U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererH, 39U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererI, 53U);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 18538U)) & S_BLOCK1], 39U) ^ RotL64(aKeyRowReadA[((aIndex + 17191U)) & W_KEY1], 27U));
            aIngress ^= (RotL64(mSource[((aIndex + 18904U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18829U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 18440U)) & W_KEY1], 47U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 18445U)) & S_BLOCK1], 22U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 18005U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCarry, 27U) ^ RotL64(aPrevious, 10U)) + (RotL64(aIngress, 51U) ^ RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterF = (((aWandererH + RotL64(aPrevious, 58U)) + RotL64(aCarry, 47U)) + 14008824488073394623U) + aNonceWordO;
            aOrbiterG = (((aWandererF + RotL64(aCross, 5U)) + 13317978415866411468U) + aPhaseGOrbiterAssignSaltD[((aIndex + 24U)) & S_SALT1]) + aNonceWordE;
            aOrbiterH = ((aWandererG + RotL64(aScatter, 21U)) + 13209180141897453900U) + aPhaseGOrbiterAssignSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = ((aWandererB + RotL64(aIngress, 37U)) + RotL64(aCarry, 21U)) + 11870521586865233578U;
            aOrbiterB = (aWandererA + RotL64(aScatter, 29U)) + 8052156380448047385U;
            aOrbiterA = (((aWandererE + RotL64(aCross, 43U)) + RotL64(aCarry, 5U)) + 12158131176743680605U) + aNonceWordK;
            aOrbiterK = (aWandererD + RotL64(aIngress, 11U)) + 14674467487607719347U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 18055496790566231147U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 3838105585041578784U;
            aOrbiterH = RotL64((aOrbiterH * 1075709247574580091U), 29U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterE) + 2839568255183054418U) + aPhaseGOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1]) + aNonceWordM;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 11933612922864258179U;
            aOrbiterB = RotL64((aOrbiterB * 7571964469321160347U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 6289849094151630580U) + aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterG = (((aOrbiterG ^ aOrbiterA) ^ 2640344350528492271U) ^ aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterG = RotL64((aOrbiterG * 16197726750829369365U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 16306175266267657791U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 3339898380394883600U;
            aOrbiterK = RotL64((aOrbiterK * 7105436590182982373U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 15017076663742800002U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 8973064296077602496U;
            aOrbiterF = RotL64((aOrbiterF * 9309462227233615761U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 17580319233338139859U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 14063208878807603874U;
            aOrbiterE = RotL64((aOrbiterE * 16601475239075164585U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 13326130855721009942U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterH) ^ 12843186026737544416U) ^ aPhaseGOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterA = RotL64((aOrbiterA * 4975848122837321619U), 13U);
            //
            aIngress = RotL64(aOrbiterB, 35U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 11U));
            aIngress = aIngress + (RotL64(aOrbiterG, 47U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterH, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aScatter, 41U) + RotL64(aOrbiterH, 29U)) + aOrbiterB) + aNonceWordL);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterG, 22U)) + aOrbiterA);
            aWandererE = aWandererE + ((RotL64(aCross, 48U) + aOrbiterF) + RotL64(aOrbiterG, 13U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 35U) + aOrbiterH) + RotL64(aOrbiterK, 43U)) + aPhaseGWandererUpdateSaltC[((aIndex + 26U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aCross, 27U) + RotL64(aOrbiterB, 5U)) + aOrbiterF) + RotL64(aCarry, 51U)) + aNonceWordG);
            aWandererG = aWandererG ^ ((((RotL64(aIngress, 5U) + aOrbiterB) + RotL64(aOrbiterG, 57U)) + aNonceWordB) + aPhaseGWandererUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 11U) + RotL64(aOrbiterK, 35U)) + aOrbiterE) + RotL64(aCarry, 23U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 53U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 20U));
            aCarry = aCarry + (RotL64(aWandererB, 39U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererD, 29U);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 20544U)) & S_BLOCK1], 5U) ^ RotL64(mSource[((aIndex + 19431U)) & S_BLOCK1], 13U));
            aIngress ^= (RotL64(aFireLaneA[((aIndex + 20004U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19331U)) & S_BLOCK1], 24U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 20528U)) & W_KEY1], 18U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 21615U)) & W_KEY1], 3U));
            aCross ^= (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 21580U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneB[((aIndex + 20796U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aPrevious, 53U) + RotL64(aCarry, 21U)) ^ (RotL64(aCross, 36U) + RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterJ = (aWandererB + RotL64(aPrevious, 21U)) + 6318740973868639425U;
            aOrbiterG = (((aWandererG + RotL64(aIngress, 3U)) + 5487840061430920881U) + aPhaseGOrbiterAssignSaltA[((aIndex + 19U)) & S_SALT1]) + aNonceWordD;
            aOrbiterI = (((aWandererK + RotL64(aCross, 27U)) + RotL64(aCarry, 29U)) + 10258706763248072672U) + aNonceWordP;
            aOrbiterC = (((aWandererH + RotL64(aScatter, 41U)) + RotL64(aCarry, 3U)) + 18356875269730338208U) + aPhaseGOrbiterAssignSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterE = (aWandererE + RotL64(aIngress, 34U)) + 12883160282903147010U;
            aOrbiterB = ((aWandererD + RotL64(aPrevious, 47U)) + RotL64(aCarry, 43U)) + 1010140474942697730U;
            aOrbiterF = (aWandererI + RotL64(aCross, 11U)) + 17733939421700898293U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 13693055887924981201U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 14574732452793385269U;
            aOrbiterI = RotL64((aOrbiterI * 9373765929885750185U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 10832873941223609012U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 8212600587135328040U;
            aOrbiterJ = RotL64((aOrbiterJ * 5334613996794796145U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 5312744319781971178U) + aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 6173741211706546923U;
            aOrbiterF = RotL64((aOrbiterF * 12854414066390848249U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 3693249147883790810U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 18365859989736602556U;
            aOrbiterB = RotL64((aOrbiterB * 3348463719324104997U), 21U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 10645056678337549771U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 1175668356822251045U) ^ aNonceWordM;
            aOrbiterG = RotL64((aOrbiterG * 6579675292775345579U), 41U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 13556844570541823717U) + aPhaseGOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 4790355739411849736U;
            aOrbiterC = RotL64((aOrbiterC * 4083544011788850307U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 14905575502272644116U) + aNonceWordN;
            aOrbiterE = (((aOrbiterE ^ aOrbiterF) ^ 17047244574558476634U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterE = RotL64((aOrbiterE * 2356386971503880047U), 35U);
            //
            aIngress = RotL64(aOrbiterE, 47U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterI, 3U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterC, 19U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterJ, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aScatter, 11U) + aOrbiterI) + RotL64(aOrbiterF, 51U)) + aNonceWordF);
            aWandererD = aWandererD + ((((RotL64(aCross, 44U) + aOrbiterB) + RotL64(aOrbiterJ, 37U)) + RotL64(aCarry, 57U)) + aPhaseGWandererUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 35U) + aOrbiterI) + RotL64(aOrbiterG, 21U)) + aNonceWordO);
            aWandererB = aWandererB + (((RotL64(aPrevious, 29U) + aOrbiterJ) + RotL64(aOrbiterC, 43U)) + RotL64(aCarry, 35U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterB, 5U)) + aOrbiterE);
            aWandererG = aWandererG + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterG, 60U)) + aOrbiterF) + aNonceWordB);
            aWandererK = aWandererK ^ ((((RotL64(aScatter, 3U) + RotL64(aOrbiterB, 27U)) + aOrbiterF) + aNonceWordJ) + aPhaseGWandererUpdateSaltD[((aIndex + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 19U));
            aCarry = aCarry + (RotL64(aWandererE, 27U) ^ aWandererG);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 39U));
            aCarry = aCarry + RotL64(aWandererD, 60U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 23044U)) & S_BLOCK1], 5U) ^ RotL64(aKeyRowReadA[((aIndex + 23218U)) & W_KEY1], 46U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 24178U)) & W_KEY1], 57U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 23353U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 22534U)) & S_BLOCK1], 43U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 24039U)) & S_BLOCK1], 28U));
            aCross ^= (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 21995U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneD[((aIndex + 22433U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCross, 23U)) ^ (RotL64(aCarry, 35U) + RotL64(aPrevious, 54U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterH = (aWandererC + RotL64(aPrevious, 13U)) + 15549114274303128055U;
            aOrbiterE = (((aWandererK + RotL64(aScatter, 58U)) + RotL64(aCarry, 37U)) + 16466750056388063241U) + aPhaseGOrbiterAssignSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterC = (((aWandererH + RotL64(aIngress, 19U)) + RotL64(aCarry, 5U)) + 12209449840836787142U) + aPhaseGOrbiterAssignSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = (aWandererF + RotL64(aCross, 41U)) + 14551496099734294336U;
            aOrbiterI = ((aWandererJ + RotL64(aPrevious, 3U)) + RotL64(aCarry, 21U)) + 6266576428679808622U;
            aOrbiterK = ((aWandererD + RotL64(aCross, 51U)) + 16892841575635668152U) + aNonceWordA;
            aOrbiterF = ((aWandererI + RotL64(aScatter, 35U)) + 7375966221423362125U) + aNonceWordO;
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 11926105302821753530U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 16219253791550461124U;
            aOrbiterC = RotL64((aOrbiterC * 2117550758226173419U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 7299056065319248160U) + aPhaseGOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 15234001484933728439U) ^ aNonceWordP;
            aOrbiterK = RotL64((aOrbiterK * 8182244796017018911U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 6615802589932632120U) + aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 5481176858895819247U;
            aOrbiterI = RotL64((aOrbiterI * 3604590158551984877U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 17220507586542139380U) + aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 14137921473739415340U;
            aOrbiterH = RotL64((aOrbiterH * 10634645686035907603U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 16981960446540932787U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 10897565927079518588U;
            aOrbiterF = RotL64((aOrbiterF * 418843936329303571U), 47U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterH) + 2746889569299593263U) + aPhaseGOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1]) + aNonceWordN;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 4894117146736361379U) ^ aNonceWordD;
            aOrbiterE = RotL64((aOrbiterE * 2656750612042673191U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 18294823016957137777U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 86828501068883383U;
            aOrbiterA = RotL64((aOrbiterA * 11432686669235402365U), 37U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterI, 44U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 51U));
            aIngress = aIngress + (RotL64(aOrbiterA, 11U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterC, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 23U) + RotL64(aOrbiterH, 13U)) + aOrbiterC) + aNonceWordM);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 54U) + aOrbiterF) + RotL64(aOrbiterE, 3U));
            aWandererF = aWandererF + ((((RotL64(aScatter, 43U) + RotL64(aOrbiterA, 52U)) + aOrbiterF) + RotL64(aCarry, 3U)) + aPhaseGWandererUpdateSaltC[((aIndex + 26U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 35U) + aOrbiterI) + RotL64(aOrbiterH, 19U));
            aWandererK = aWandererK + (((RotL64(aIngress, 11U) + aOrbiterF) + RotL64(aOrbiterI, 27U)) + aNonceWordJ);
            aWandererI = aWandererI ^ ((((RotL64(aScatter, 29U) + RotL64(aOrbiterK, 43U)) + aOrbiterH) + aNonceWordL) + aPhaseGWandererUpdateSaltD[((aIndex + 17U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aCross, 5U) + RotL64(aOrbiterI, 35U)) + aOrbiterA) + RotL64(aCarry, 19U)) + aNonceWordI);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 4U));
            aCarry = aCarry + (RotL64(aWandererD, 51U) ^ aWandererF);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 13U));
            aCarry = aCarry + RotL64(aWandererC, 57U);
            aCarry = aCarry + RotL64(aIngress, 28U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 27174U)) & S_BLOCK1], 10U) ^ RotL64(aKeyRowReadA[((aIndex + 26338U)) & W_KEY1], 37U));
            aIngress ^= (RotL64(aFireLaneD[((aIndex + 26248U)) & S_BLOCK1], 29U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 26643U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 26316U)) & W_KEY1], 5U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 26340U)) & S_BLOCK1], 18U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 25799U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneD[((aIndex + 25080U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aPrevious, 51U) ^ RotL64(aCarry, 23U)) ^ (RotL64(aCross, 6U) + RotL64(aIngress, 37U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterK = (((aWandererG + RotL64(aScatter, 11U)) + RotL64(aCarry, 43U)) + 13296600294247799698U) + aNonceWordN;
            aOrbiterB = (((aWandererE + RotL64(aCross, 47U)) + 5818503518080877515U) + aPhaseHOrbiterAssignSaltA[((aIndex + 15U)) & S_SALT1]) + aNonceWordL;
            aOrbiterG = (((aWandererI + RotL64(aPrevious, 5U)) + RotL64(aCarry, 11U)) + 6735784238734173597U) + aNonceWordH;
            aOrbiterI = ((aWandererF + RotL64(aIngress, 41U)) + 7368398209488856201U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterC = (aWandererA + RotL64(aScatter, 29U)) + 961734029066455638U;
            aOrbiterH = ((aWandererK + RotL64(aIngress, 20U)) + RotL64(aCarry, 57U)) + 797011946660892011U;
            aOrbiterE = (aWandererJ + RotL64(aPrevious, 35U)) + 12841876018396622350U;
            //
            aOrbiterK = (((aOrbiterK + aOrbiterB) + 16213253970483895623U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordA;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 15186950557113470375U;
            aOrbiterG = RotL64((aOrbiterG * 4647470430467908107U), 21U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterC) + 5117930310827477341U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordE;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 12265429373166094162U;
            aOrbiterK = RotL64((aOrbiterK * 1522823535151532249U), 53U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 13920531346698601568U) + aNonceWordC;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 14695405206998211456U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 13950964363414164279U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 7851960904825938443U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 9501511171732550190U;
            aOrbiterE = RotL64((aOrbiterE * 5614164120361489613U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 5663365182245722077U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 9607860124321315555U;
            aOrbiterH = RotL64((aOrbiterH * 3461820361914280601U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 18171052650586819280U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 3442698321538580861U) ^ aNonceWordP;
            aOrbiterI = RotL64((aOrbiterI * 6317525514963824829U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 1491052813469258970U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 3956599824067616133U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2928600779267623085U), 47U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterC, 27U);
            aIngress = aIngress + (RotL64(aOrbiterH, 21U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterG, 5U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterB, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterH, 51U)) + aOrbiterB) + aPhaseHWandererUpdateSaltB[((aIndex + 27U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterK, 29U)) + aOrbiterE);
            aWandererA = aWandererA + (((RotL64(aScatter, 60U) + RotL64(aOrbiterC, 41U)) + aOrbiterI) + aNonceWordJ);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterH, 35U)) + aOrbiterG) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 43U) + RotL64(aOrbiterH, 58U)) + aOrbiterI) + RotL64(aCarry, 53U)) + aNonceWordF);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 53U) + RotL64(aOrbiterC, 11U)) + aOrbiterE) + aNonceWordD);
            aWandererK = aWandererK + ((((RotL64(aCross, 5U) + RotL64(aOrbiterI, 19U)) + aOrbiterK) + RotL64(aCarry, 35U)) + aNonceWordB);
            //
            aCarry = aCarry + (RotL64(aWandererF, 21U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererI, 48U) ^ aWandererJ);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 57U));
            aCarry = aCarry + RotL64(aWandererA, 29U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 29103U)) & S_BLOCK1], 56U) ^ RotL64(aFireLaneD[((aIndex + 29076U)) & S_BLOCK1], 29U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 27549U)) & W_KEY1], 13U) ^ RotL64(aFireLaneC[((aIndex + 29221U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 28766U)) & W_KEY1], 52U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 28741U)) & S_BLOCK1], 19U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29689U)) & S_BLOCK1], 11U) ^ RotL64(aFireLaneB[((aIndex + 27636U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aPrevious, 21U) ^ RotL64(aCarry, 35U)) + (RotL64(aIngress, 3U) ^ RotL64(aCross, 48U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterJ = ((aWandererD + RotL64(aPrevious, 47U)) + 380024772508948442U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterA = (((aWandererJ + RotL64(aCross, 23U)) + RotL64(aCarry, 35U)) + 7649029098162567210U) + aNonceWordC;
            aOrbiterE = (aWandererF + RotL64(aIngress, 29U)) + 5329304598870421851U;
            aOrbiterG = ((aWandererE + RotL64(aScatter, 35U)) + 12306118665045151326U) + aNonceWordN;
            aOrbiterD = ((aWandererI + RotL64(aPrevious, 4U)) + RotL64(aCarry, 47U)) + 960751560457324256U;
            aOrbiterC = ((aWandererB + RotL64(aIngress, 11U)) + RotL64(aCarry, 3U)) + 3244070254386191876U;
            aOrbiterK = ((aWandererC + RotL64(aCross, 53U)) + 15733408571609521746U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 17623448932647018544U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 8787759896149035829U;
            aOrbiterE = RotL64((aOrbiterE * 7092515868845497573U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 14741681792348288162U) + aNonceWordF;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 8801731213568307302U;
            aOrbiterD = RotL64((aOrbiterD * 12127126999570616489U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 9872248187499779222U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 15407371518644528235U;
            aOrbiterA = RotL64((aOrbiterA * 1245102406469471673U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 4242060317152943062U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 9942784962409917541U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 888649755587764533U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 7296348796484458631U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 15061417216070157797U) ^ aNonceWordJ;
            aOrbiterG = RotL64((aOrbiterG * 10349554676953256231U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 3233185810644297433U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 9241229457641024287U;
            aOrbiterK = RotL64((aOrbiterK * 2728237515724597517U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 8464051359381554575U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 3307872165699029375U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4859663401033023433U), 21U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterK, 11U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 27U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 41U));
            aIngress = aIngress + RotL64(aOrbiterE, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aScatter, 53U) + aOrbiterC) + RotL64(aOrbiterA, 5U)) + RotL64(aCarry, 3U)) + aNonceWordO);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 39U) + aOrbiterD) + RotL64(aOrbiterE, 35U));
            aWandererE = aWandererE + ((((RotL64(aCross, 29U) + RotL64(aOrbiterE, 41U)) + aOrbiterJ) + RotL64(aCarry, 47U)) + aPhaseHWandererUpdateSaltD[((aIndex + 13U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 60U) + RotL64(aOrbiterG, 29U)) + aOrbiterK) + aNonceWordE);
            aWandererF = aWandererF + ((RotL64(aCross, 11U) + RotL64(aOrbiterA, 23U)) + aOrbiterJ);
            aWandererI = aWandererI ^ ((((RotL64(aPrevious, 3U) + aOrbiterJ) + RotL64(aOrbiterK, 48U)) + aNonceWordI) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aIngress, 47U) + aOrbiterD) + RotL64(aOrbiterC, 57U)) + aNonceWordL);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 4U));
            aCarry = aCarry + (RotL64(aWandererI, 57U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererC, 29U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererE, 19U);
            aCarry = aCarry + RotL64(aIngress, 24U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 31502U)) & S_BLOCK1], 11U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 30131U)) & W_KEY1], 37U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 30871U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 32170U)) & S_BLOCK1], 41U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30134U)) & S_BLOCK1], 21U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 31720U)) & W_KEY1], 13U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCarry, 27U) ^ RotL64(aPrevious, 54U)) ^ (RotL64(aIngress, 13U) + RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterH = (aWandererB + RotL64(aCross, 11U)) + 12690502671561165478U;
            aOrbiterG = (((aWandererK + RotL64(aScatter, 5U)) + 17519943923428102801U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordE;
            aOrbiterJ = ((((aWandererJ + RotL64(aIngress, 57U)) + RotL64(aCarry, 47U)) + 10705515807975331385U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordM;
            aOrbiterA = (aWandererI + RotL64(aPrevious, 35U)) + 16586447272278538179U;
            aOrbiterD = (((aWandererF + RotL64(aScatter, 41U)) + RotL64(aCarry, 5U)) + 8006560996840971798U) + aNonceWordH;
            aOrbiterB = (aWandererC + RotL64(aPrevious, 50U)) + 12928600185788857701U;
            aOrbiterC = ((aWandererG + RotL64(aCross, 27U)) + RotL64(aCarry, 35U)) + 14240723153798267172U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 8636219177994872072U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 7586790235186467512U;
            aOrbiterJ = RotL64((aOrbiterJ * 15052686382507614169U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 1103807034179512424U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 7547526530239498693U;
            aOrbiterD = RotL64((aOrbiterD * 3360295583636013509U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 8380239679344786397U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 5690809173787433519U;
            aOrbiterG = RotL64((aOrbiterG * 5354724308093372953U), 53U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterC) + 8390902801141804609U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1]) + aNonceWordK;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 3507306189192059486U;
            aOrbiterA = RotL64((aOrbiterA * 18336280496510253103U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 6190745292098482871U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 8065418693975056902U) ^ aNonceWordG;
            aOrbiterC = RotL64((aOrbiterC * 6414621418430102589U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 12111755051718111803U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 7605877769709909297U;
            aOrbiterH = RotL64((aOrbiterH * 17525248694315944599U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 5969794501112646237U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 5127559299360591476U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4521563633438853069U), 27U);
            //
            aIngress = RotL64(aOrbiterJ, 51U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterD, 60U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 19U));
            aIngress = aIngress + RotL64(aOrbiterG, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((((RotL64(aIngress, 41U) + RotL64(aOrbiterJ, 5U)) + aOrbiterA) + aNonceWordL) + aPhaseHWandererUpdateSaltB[((aIndex + 13U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 11U) + aOrbiterG) + RotL64(aOrbiterA, 29U)) + RotL64(aCarry, 47U)) + aNonceWordD);
            aWandererG = aWandererG ^ (((RotL64(aCross, 3U) + aOrbiterC) + RotL64(aOrbiterB, 47U)) + aNonceWordB);
            aWandererF = aWandererF + (((RotL64(aScatter, 19U) + aOrbiterG) + RotL64(aOrbiterH, 35U)) + RotL64(aCarry, 29U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 47U) + aOrbiterB) + RotL64(aOrbiterD, 53U)) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 27U) + RotL64(aOrbiterJ, 11U)) + aOrbiterH) + aNonceWordA);
            aWandererC = aWandererC ^ ((RotL64(aCross, 56U) + RotL64(aOrbiterB, 60U)) + aOrbiterH);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 50U));
            aCarry = aCarry + (RotL64(aWandererF, 19U) ^ aWandererK);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 43U));
            aCarry = aCarry + RotL64(aWandererJ, 13U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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

void TwistExpander_Hockey_Arx::Seed_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xF3D0EC2D06A18221ULL + 0xEC2123CE3CEC2D43ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xDCDE09436BE2C957ULL + 0xBABD164A46AE2389ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x9251F583A20C793DULL + 0x843DBBF203872FE2ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xF8137895D2819421ULL + 0x996FCD01CF249622ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xF1AA57F4D130BDBFULL + 0xE55134DC75AF7D24ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xD5DE48D5546D66BFULL + 0xE1DBBEE804AC8D08ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xBA5070EDB4C10869ULL + 0x8319678DEF795682ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xE0642EBA9A165531ULL + 0xDD7E5C193429CB25ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xEDB01D11A8937C8BULL + 0xE662684CC8367733ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xF2011FDC0478DFF7ULL + 0xC089540FF1DAF866ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x85C783198151B1DFULL + 0xF533A46E6B6131F2ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0x8153ED5C8631817BULL + 0xF7700471E58508A0ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0x96652425698D4CB5ULL + 0xF9CA03BD66727A7FULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xF92BEC6A3B4AF66BULL + 0xC8AD8A08EBDF95DCULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xE78600B23E37F91BULL + 0xABC180C09E4D56D8ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0x84C64E2D68E483EFULL + 0x9C866E17F2108C49ULL);
    // GSeedRunSeed_B seed_loop_a (start)
    {
        // GSeedRunSeed_B seed_loop_a lane group
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneC, aExpandLaneC, aExpandLaneD, aInvestLaneA, aFireLaneA, aInvestLaneB, aFireLaneB, aOperationLaneA, aFireLaneD, aOperationLaneB, aOperationLaneC
        // write to: aInvestLaneA, aInvestLaneB, aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD
    
        // seed_loop_a loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aFireLaneC
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aFireLaneC forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward/forward random
        // write to: aInvestLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 3489U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneB[((aIndex + 5400U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 3391U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 782U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneD[((aIndex + 3942U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aIngress, 23U) ^ RotL64(aCarry, 3U)) ^ (RotL64(aCross, 39U) + RotL64(aPrevious, 54U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterC = ((aWandererJ + RotL64(aScatter, 57U)) + RotL64(aCarry, 39U)) + 2558105147674438050U;
            aOrbiterH = ((aWandererD + RotL64(aPrevious, 4U)) + 15856662514774702561U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = ((aWandererK + RotL64(aIngress, 13U)) + RotL64(aCarry, 27U)) + 13346869226246584582U;
            aOrbiterA = (((aWandererI + RotL64(aCross, 27U)) + RotL64(aCarry, 51U)) + 7632111846116243973U) + aNonceWordF;
            aOrbiterI = (((aWandererF + RotL64(aIngress, 41U)) + 2102101361626976279U) + aPhaseAOrbiterAssignSaltB[((aIndex + 28U)) & S_SALT1]) + aNonceWordC;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 5605968705067851563U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 6842483186584326681U;
            aOrbiterD = RotL64((aOrbiterD * 11344798544990575365U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 5559797213819425064U) + aNonceWordL;
            aOrbiterH = (((aOrbiterH ^ aOrbiterA) ^ 12422313931331576759U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterH = RotL64((aOrbiterH * 7399849122565913401U), 13U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterD) + 2751024420047872601U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordG;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 11031320239359798610U;
            aOrbiterI = RotL64((aOrbiterI * 8607639453141148025U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 14366375309473793217U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 11971479429768505316U;
            aOrbiterC = RotL64((aOrbiterC * 10063001532313098203U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 3947595951884469542U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 17882767922372770896U;
            aOrbiterA = RotL64((aOrbiterA * 3361906348965810211U), 41U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterC, 19U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 41U));
            aIngress = aIngress + RotL64(aOrbiterI, 30U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((((RotL64(aPrevious, 60U) + aOrbiterA) + RotL64(aOrbiterD, 53U)) + RotL64(aCarry, 11U)) + aNonceWordO) + aPhaseAWandererUpdateSaltF[((aIndex + 8U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterD, 41U)) + aOrbiterC) + aNonceWordD);
            aWandererI = aWandererI + ((RotL64(aScatter, 35U) + RotL64(aOrbiterA, 21U)) + aOrbiterC);
            aWandererD = aWandererD ^ (((RotL64(aCross, 21U) + RotL64(aOrbiterI, 4U)) + aOrbiterC) + aNonceWordB);
            aWandererJ = aWandererJ + (((((RotL64(aScatter, 13U) + RotL64(aOrbiterH, 29U)) + aOrbiterA) + RotL64(aCarry, 37U)) + aNonceWordJ) + aPhaseAWandererUpdateSaltC[((aIndex + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 23U) ^ aWandererI);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 57U));
            aCarry = aCarry + RotL64(aWandererF, 3U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aInvestLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_a loop 2
        // ingress from: aInvestLaneA, aExpandLaneC, aFireLaneA
        // ingress directions: aInvestLaneA forward forced, aExpandLaneC forward forced, aFireLaneA forward/backward random
        // cross from: aExpandLaneA, aExpandLaneD
        // cross directions: aExpandLaneA backward forced, aExpandLaneD backward/forward random
        // write to: aInvestLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneA[((aIndex + 9467U)) & S_BLOCK1], 20U) ^ RotL64(aExpandLaneC[((aIndex + 5776U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 7012U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 5931U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneD[((aIndex + 5982U)) & S_BLOCK1], 48U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aPrevious, 29U) + RotL64(aCross, 5U)) ^ (RotL64(aIngress, 42U) ^ RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterD = (((aWandererK + RotL64(aScatter, 13U)) + RotL64(aCarry, 29U)) + 15036852811491820366U) + aNonceWordF;
            aOrbiterH = (((aWandererG + RotL64(aPrevious, 5U)) + RotL64(aCarry, 51U)) + 305637140752898475U) + aPhaseAOrbiterAssignSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = ((((aWandererJ + RotL64(aCross, 37U)) + RotL64(aCarry, 11U)) + 11948631574496129610U) + aPhaseAOrbiterAssignSaltF[((aIndex + 17U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterF = (aWandererH + RotL64(aIngress, 28U)) + 5321623592482991426U;
            aOrbiterC = ((aWandererB + RotL64(aCross, 47U)) + 4075270159062690728U) + aNonceWordD;
            //
            aOrbiterD = (((aOrbiterD + aOrbiterH) + 15111580500356908928U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1]) + aNonceWordE;
            aOrbiterE = (((aOrbiterE ^ aOrbiterD) ^ 7244150695504160363U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterE = RotL64((aOrbiterE * 2445733898697939969U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 5131563519577488862U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 5881954992088651371U;
            aOrbiterC = RotL64((aOrbiterC * 2424421828597294607U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 12780935808751507998U) + aNonceWordH;
            aOrbiterH = (((aOrbiterH ^ aOrbiterE) ^ 12599159643925470226U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterH = RotL64((aOrbiterH * 17690046932587062701U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 9466589929741834066U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 6093158735705189789U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 7453778295800853653U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 17461243886150519249U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 15456408913739900718U;
            aOrbiterF = RotL64((aOrbiterF * 16093292401746174671U), 29U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterF, 47U);
            aIngress = aIngress + (RotL64(aOrbiterE, 37U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterH, 24U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 29U) + aOrbiterD) + RotL64(aOrbiterF, 21U)) + aNonceWordO);
            aWandererG = aWandererG + (((((RotL64(aIngress, 37U) + RotL64(aOrbiterD, 38U)) + aOrbiterH) + RotL64(aCarry, 13U)) + aNonceWordA) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterF, 3U)) + aOrbiterE) + aNonceWordP);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 11U) + aOrbiterE) + RotL64(aOrbiterH, 57U)) + RotL64(aCarry, 43U)) + aNonceWordN);
            aWandererH = aWandererH ^ (((RotL64(aCross, 50U) + aOrbiterE) + RotL64(aOrbiterC, 13U)) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 35U) ^ aWandererJ);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 23U));
            aCarry = aCarry + RotL64(aWandererH, 51U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 12026U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneD[((aIndex + 12970U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 15531U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 14786U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 13932U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aExpandLaneA[((aIndex + 11695U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aIngress, 19U) ^ RotL64(aCross, 35U)) ^ (RotL64(aCarry, 5U) + RotL64(aPrevious, 56U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterF = (((aWandererG + RotL64(aPrevious, 29U)) + RotL64(aCarry, 11U)) + 5295352595333316211U) + aNonceWordJ;
            aOrbiterE = ((((aWandererB + RotL64(aCross, 12U)) + RotL64(aCarry, 23U)) + 2341795367042042605U) + aPhaseAOrbiterAssignSaltE[((aIndex + 11U)) & S_SALT1]) + aNonceWordH;
            aOrbiterI = ((((aWandererF + RotL64(aIngress, 3U)) + RotL64(aCarry, 57U)) + 10122175780504033663U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordB;
            aOrbiterH = ((aWandererI + RotL64(aScatter, 21U)) + 10084612804696198554U) + aNonceWordO;
            aOrbiterG = (aWandererJ + RotL64(aCross, 51U)) + 16470424309851045971U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 656016130975227994U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 15313268829659834317U;
            aOrbiterI = RotL64((aOrbiterI * 3553315008401417123U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 3795220914993923394U) + aNonceWordC;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 14044442220988813825U) ^ aNonceWordA;
            aOrbiterE = RotL64((aOrbiterE * 3270650852546606835U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 3804224626734584802U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 7980006306010255693U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 13958505239726088561U), 53U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterI) + 13746830564584711549U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1]) + aNonceWordP;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 11852212099729274845U;
            aOrbiterG = RotL64((aOrbiterG * 2164880979318247855U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 9083223471018084847U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 13706723820703853346U;
            aOrbiterF = RotL64((aOrbiterF * 11361854103656219887U), 29U);
            //
            aIngress = RotL64(aOrbiterF, 57U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 14U));
            aIngress = aIngress + RotL64(aOrbiterH, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterE, 19U)) + aOrbiterF);
            aWandererG = aWandererG + (((((RotL64(aIngress, 37U) + aOrbiterH) + RotL64(aOrbiterF, 57U)) + RotL64(aCarry, 27U)) + aNonceWordK) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 29U) + aOrbiterI) + RotL64(aOrbiterG, 38U)) + aNonceWordF);
            aWandererF = aWandererF + ((((RotL64(aScatter, 50U) + aOrbiterI) + RotL64(aOrbiterF, 5U)) + RotL64(aCarry, 13U)) + aPhaseAWandererUpdateSaltD[((aIndex + 5U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 5U) + aOrbiterE) + RotL64(aOrbiterI, 27U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 27U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererB, 11U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererF, 39U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 21647U)) & S_BLOCK1], 21U) ^ RotL64(aInvestLaneA[((aIndex + 17123U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 19549U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 17382U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 21113U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 19696U)) & S_BLOCK1], 30U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 35U)) ^ (RotL64(aIngress, 23U) + RotL64(aCross, 48U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterK = ((aWandererG + RotL64(aCross, 21U)) + 8975885703279267062U) + aNonceWordI;
            aOrbiterJ = (((aWandererF + RotL64(aIngress, 5U)) + RotL64(aCarry, 13U)) + 8664844915562660637U) + aNonceWordH;
            aOrbiterF = (aWandererD + RotL64(aScatter, 60U)) + 12281774799736296726U;
            aOrbiterH = ((((aWandererE + RotL64(aPrevious, 47U)) + RotL64(aCarry, 57U)) + 15347461352311329726U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordN;
            aOrbiterG = ((((aWandererC + RotL64(aScatter, 29U)) + RotL64(aCarry, 41U)) + 12967500561828907834U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordD;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 5002833859280402726U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 11908257536954668983U) ^ aNonceWordM;
            aOrbiterF = RotL64((aOrbiterF * 4384790916151202785U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 17017174811949227162U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 16851323125613931180U) ^ aNonceWordA;
            aOrbiterH = RotL64((aOrbiterH * 12446990992858763577U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 13469326957728686706U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 5228638551056105241U;
            aOrbiterG = RotL64((aOrbiterG * 13369947664646167255U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 11945166198089308564U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 16268645041872996022U;
            aOrbiterK = RotL64((aOrbiterK * 5391448793718370911U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 14781204627695095701U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 5365325354838101092U) ^ aNonceWordL;
            aOrbiterJ = RotL64((aOrbiterJ * 8017284997946310807U), 39U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterJ, 37U);
            aIngress = aIngress + (RotL64(aOrbiterG, 27U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterH, 10U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((((RotL64(aPrevious, 34U) + aOrbiterF) + RotL64(aOrbiterH, 47U)) + aNonceWordC) + aPhaseAWandererUpdateSaltC[((aIndex + 3U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aIngress, 11U) + aOrbiterK) + RotL64(aOrbiterJ, 5U)) + RotL64(aCarry, 43U)) + aNonceWordO);
            aWandererE = aWandererE ^ ((((RotL64(aScatter, 57U) + aOrbiterK) + RotL64(aOrbiterG, 20U)) + aNonceWordK) + aPhaseAWandererUpdateSaltF[((aIndex + 14U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aCross, 19U) + aOrbiterJ) + RotL64(aOrbiterH, 57U)) + RotL64(aCarry, 21U)) + aNonceWordG);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 47U) + aOrbiterH) + RotL64(aOrbiterG, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 35U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererE, 11U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererD, 3U);
            aCarry = aCarry + RotL64(aIngress, 24U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 27160U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneA[((aIndex + 23565U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 22542U)) & S_BLOCK1], 10U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 22581U)) & S_BLOCK1], 58U) ^ RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 25786U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 27146U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aIngress, 39U) ^ RotL64(aCarry, 10U)) + (RotL64(aPrevious, 27U) ^ RotL64(aCross, 51U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterB = ((((aWandererK + RotL64(aCross, 23U)) + RotL64(aCarry, 43U)) + 3255291173184001106U) + aPhaseAOrbiterAssignSaltC[((aIndex + 16U)) & S_SALT1]) + aNonceWordL;
            aOrbiterH = ((aWandererH + RotL64(aScatter, 3U)) + 15308468160116255528U) + aNonceWordP;
            aOrbiterC = ((aWandererG + RotL64(aPrevious, 56U)) + RotL64(aCarry, 57U)) + 18186972408589866656U;
            aOrbiterD = (((aWandererE + RotL64(aIngress, 35U)) + RotL64(aCarry, 23U)) + 4439324265978331914U) + aNonceWordE;
            aOrbiterE = (((aWandererC + RotL64(aScatter, 13U)) + 13099263173016322486U) + aPhaseAOrbiterAssignSaltF[((aIndex + 15U)) & S_SALT1]) + aNonceWordG;
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 7041561081767500660U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 6196422612687812971U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 13359900204297781063U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 7664260932541281413U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 17802347823020441056U;
            aOrbiterE = RotL64((aOrbiterE * 2220679459017369255U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 4253107484061190446U) + aNonceWordC;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 13799496534030645312U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9167675060053848207U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 14252892847595951926U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 5663527578664291422U;
            aOrbiterD = RotL64((aOrbiterD * 18314294235895182465U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 11148755959699137661U) + aNonceWordA;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 17036900929333594592U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 16041243617369003291U), 43U);
            //
            aIngress = RotL64(aOrbiterE, 57U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 39U));
            aIngress = aIngress + RotL64(aOrbiterC, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aIngress, 46U) + aOrbiterH) + RotL64(aOrbiterE, 41U)) + aPhaseAWandererUpdateSaltA[((aIndex + 26U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 11U) + RotL64(aOrbiterB, 10U)) + aOrbiterE) + RotL64(aCarry, 5U));
            aWandererH = aWandererH ^ ((((RotL64(aPrevious, 35U) + RotL64(aOrbiterE, 29U)) + aOrbiterC) + aNonceWordH) + aPhaseAWandererUpdateSaltE[((aIndex + 5U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aScatter, 57U) + RotL64(aOrbiterH, 19U)) + aOrbiterB) + RotL64(aCarry, 27U)) + aNonceWordF);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 19U) + aOrbiterC) + RotL64(aOrbiterD, 51U)) + aNonceWordO);
            //
            aCarry = aCarry + (RotL64(aWandererK, 5U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererH, 21U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererC, 37U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 30804U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneA[((aIndex + 30832U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 28664U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28507U)) & S_BLOCK1], 48U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 27553U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aInvestLaneB[((aIndex + 27846U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCarry, 57U) + RotL64(aPrevious, 23U)) ^ (RotL64(aCross, 39U) + RotL64(aIngress, 10U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterG = (((aWandererC + RotL64(aCross, 39U)) + RotL64(aCarry, 19U)) + 16519040829220310189U) + aPhaseAOrbiterAssignSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterA = ((aWandererH + RotL64(aPrevious, 19U)) + RotL64(aCarry, 35U)) + 6888002778416941825U;
            aOrbiterJ = ((aWandererD + RotL64(aIngress, 27U)) + RotL64(aCarry, 57U)) + 1310832187746534025U;
            aOrbiterB = ((aWandererI + RotL64(aScatter, 56U)) + 5890888009051281674U) + aNonceWordO;
            aOrbiterI = (((aWandererA + RotL64(aIngress, 5U)) + 5143864838362464857U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordN;
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 15591534069452660003U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 1466867671765325096U;
            aOrbiterJ = RotL64((aOrbiterJ * 1277202105237572301U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 13931443680107902488U) + aNonceWordD;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 15400747367673245552U;
            aOrbiterG = RotL64((aOrbiterG * 7011651369456453127U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 2836975369734495759U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 2370720358274970117U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 4615571902817575375U), 27U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterG) + 3470677184188006133U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordC;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 7175584278499266723U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10067096593682482345U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 6095078817776863055U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 2176637999243513070U;
            aOrbiterB = RotL64((aOrbiterB * 12215701810843975501U), 53U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterA, 11U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 24U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterG, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aCross, 47U) + RotL64(aOrbiterG, 57U)) + aOrbiterA) + RotL64(aCarry, 23U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterI, 47U)) + aOrbiterA) + aPhaseAWandererUpdateSaltB[((aIndex + 8U)) & S_SALT1]);
            aWandererI = aWandererI + (((((RotL64(aScatter, 58U) + aOrbiterJ) + RotL64(aOrbiterI, 24U)) + RotL64(aCarry, 5U)) + aNonceWordI) + aPhaseAWandererUpdateSaltD[((aIndex + 10U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 13U) + aOrbiterG) + RotL64(aOrbiterJ, 37U)) + aNonceWordM);
            aWandererC = aWandererC + (((RotL64(aScatter, 21U) + RotL64(aOrbiterA, 5U)) + aOrbiterB) + aNonceWordF);
            //
            aCarry = aCarry + (RotL64(aWandererA, 5U) ^ aWandererH);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 60U));
            aCarry = aCarry + RotL64(aWandererC, 51U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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

void TwistExpander_Hockey_Arx::Seed_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xE920ADBF6795C267ULL + 0x863DC91348F32B6FULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xB8E4D458B819FFD1ULL + 0x86AA55F3A7622C89ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xB6D546E29825AF4FULL + 0xDBCEB760BE0A9175ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x9B6C5D979B7F0AA3ULL + 0xF6B7EE9C311DEFBCULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xF6B133C06A9377FFULL + 0xB22B195A78800F5EULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x8B256AE8A6EC7023ULL + 0xC1307CF6FDB1D0D4ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xC5025D7926FE3309ULL + 0xBF04A37744689550ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xE87C9F95CE6A3CD5ULL + 0xA2EC82762A395A2BULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xE95B278B03F040F7ULL + 0xDBA2D8ADFC3B21B7ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xA1A788768232C7CBULL + 0xF575D6149CF5BF84ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x917FF540053DCDBBULL + 0xD9EB4CFCD94B472CULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xFF8125D716F5ECA9ULL + 0xF06FD0FB8E971BFCULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0x9F8EDF0C165F729FULL + 0xCD2DDC28E58EE413ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xA575C6302D333997ULL + 0xD6237C15D98F5605ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xD597353C4B869881ULL + 0xBD66FB16C630C36FULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xDF216E65A261A157ULL + 0xFFCC6CE862504EDDULL);
    // GSeedRunSeed_C seed_loop_b (start)
    {
        // GSeedRunSeed_C seed_loop_b lane group
        // read from: aOperationLaneA, aOperationLaneB, aFireLaneD, aOperationLaneC, aOperationLaneD, aFireLaneA, aInvestLaneC, aFireLaneB, aExpandLaneA, aInvestLaneD, aExpandLaneD, aWorkLaneA, aFireLaneC, aWorkLaneB, aExpandLaneC, aWorkLaneC, aExpandLaneB
        // write to: aInvestLaneC, aInvestLaneD, aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // seed_loop_b loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aFireLaneD
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aFireLaneD forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aFireLaneA
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aFireLaneA backward/forward random
        // write to: aInvestLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 2775U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneB[((aIndex + 3179U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 5415U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 2237U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 4677U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 3301U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aIngress, 53U) + RotL64(aCross, 18U)) ^ (RotL64(aPrevious, 41U) ^ RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterA = ((aWandererG + RotL64(aCross, 34U)) + 5576732410244514238U) + aPhaseBOrbiterAssignSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = ((aWandererI + RotL64(aIngress, 19U)) + 2833808925935929629U) + aNonceWordF;
            aOrbiterB = (((aWandererB + RotL64(aPrevious, 51U)) + RotL64(aCarry, 53U)) + 3670188682914544792U) + aPhaseBOrbiterAssignSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = ((aWandererC + RotL64(aScatter, 5U)) + RotL64(aCarry, 39U)) + 15759072378887814995U;
            aOrbiterI = ((aWandererK + RotL64(aCross, 13U)) + RotL64(aCarry, 27U)) + 13934007231137439994U;
            aOrbiterF = ((aWandererF + RotL64(aIngress, 29U)) + 11022225696007690512U) + aNonceWordI;
            aOrbiterG = (aWandererD + RotL64(aScatter, 39U)) + 16989177104453635790U;
            aOrbiterK = (aWandererH + RotL64(aPrevious, 44U)) + 9256930045263527091U;
            aOrbiterC = (aWandererA + RotL64(aIngress, 23U)) + 17788596104417068290U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 17044369456673337625U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 1310908395523250343U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 16305084373037705921U), 19U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterB) + 12067065689034065422U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 20U)) & S_SALT1]) + aNonceWordE;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 15130844248737512262U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 9409499577465934107U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 14532689204495587494U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 8198147292120244178U;
            aOrbiterK = RotL64((aOrbiterK * 1418356389507740991U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 5485494458627163347U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 10830008207150307611U) ^ aNonceWordP;
            aOrbiterA = RotL64((aOrbiterA * 6526039534042499457U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 17770065502486618029U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 6397859353395335459U;
            aOrbiterC = RotL64((aOrbiterC * 14286997752368893825U), 37U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 5128700697381508319U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 7103394110057060499U;
            aOrbiterE = RotL64((aOrbiterE * 5053680689949149633U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 16024401282261796979U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 12818445221897253410U;
            aOrbiterG = RotL64((aOrbiterG * 11450004517784155405U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 13386978409145916350U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 16740821954556699503U;
            aOrbiterF = RotL64((aOrbiterF * 5376430209628515105U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 313978038530994953U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 1355733685461795345U;
            aOrbiterH = RotL64((aOrbiterH * 15955927322082619735U), 13U);
            //
            aIngress = RotL64(aOrbiterI, 44U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterK, 41U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 47U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 35U));
            aIngress = aIngress + RotL64(aOrbiterG, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aScatter, 41U) + RotL64(aOrbiterB, 14U)) + aOrbiterC);
            aWandererD = aWandererD ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterK, 53U)) + aOrbiterG) + aNonceWordO);
            aWandererB = aWandererB + ((((RotL64(aIngress, 50U) + aOrbiterI) + RotL64(aOrbiterB, 23U)) + RotL64(aCarry, 3U)) + aPhaseBWandererUpdateSaltF[((aIndex + 29U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 13U) + aOrbiterE) + RotL64(aOrbiterF, 37U)) + aNonceWordG);
            aWandererG = aWandererG + ((RotL64(aScatter, 3U) + RotL64(aOrbiterC, 60U)) + aOrbiterI);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 23U) + aOrbiterK) + RotL64(aOrbiterH, 29U));
            aWandererA = aWandererA + (((RotL64(aCross, 27U) + RotL64(aOrbiterC, 5U)) + aOrbiterA) + RotL64(aCarry, 35U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 54U) + aOrbiterH) + RotL64(aOrbiterA, 19U)) + aPhaseBWandererUpdateSaltA[((aIndex + 12U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aPrevious, 19U) + aOrbiterF) + RotL64(aOrbiterI, 47U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 34U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 57U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 29U));
            aCarry = aCarry + (RotL64(aWandererB, 53U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererD, 40U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aInvestLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_b loop 2
        // ingress from: aInvestLaneC, aOperationLaneC, aOperationLaneD, aFireLaneB
        // ingress directions: aInvestLaneC forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aFireLaneB forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aExpandLaneA
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aExpandLaneA backward/forward random
        // write to: aInvestLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneC[((aIndex + 9384U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneC[((aIndex + 9445U)) & S_BLOCK1], 54U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 8748U)) & S_BLOCK1], 35U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 7069U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 9316U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 6528U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aExpandLaneA[((aIndex + 9217U)) & S_BLOCK1], 40U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aPrevious, 39U) + RotL64(aCross, 27U)) + (RotL64(aCarry, 11U) ^ RotL64(aIngress, 54U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterF = (aWandererC + RotL64(aPrevious, 44U)) + 9435962834163239322U;
            aOrbiterJ = ((aWandererB + RotL64(aScatter, 23U)) + RotL64(aCarry, 37U)) + 10524704356081318973U;
            aOrbiterA = (((aWandererI + RotL64(aCross, 19U)) + RotL64(aCarry, 53U)) + 7403401305665208680U) + aNonceWordF;
            aOrbiterB = (aWandererH + RotL64(aIngress, 53U)) + 7525414805023556493U;
            aOrbiterI = ((aWandererK + RotL64(aScatter, 5U)) + 1116686470029070951U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = (((aWandererD + RotL64(aIngress, 27U)) + RotL64(aCarry, 5U)) + 13257612299137802420U) + aNonceWordL;
            aOrbiterE = (aWandererF + RotL64(aPrevious, 39U)) + 9181543003986598283U;
            aOrbiterD = ((aWandererG + RotL64(aCross, 35U)) + 9739384852307501107U) + aNonceWordK;
            aOrbiterK = ((aWandererE + RotL64(aScatter, 10U)) + 11308402900229016057U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 14935167593705272337U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 7171824007631943535U;
            aOrbiterA = RotL64((aOrbiterA * 4839974427616194289U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 8068411284829563567U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 12350207458513447578U;
            aOrbiterI = RotL64((aOrbiterI * 813973258659041895U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 17039236343991574134U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 18291683592714999632U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7771718817924840713U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 6239616841884430968U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 10604527977569876774U;
            aOrbiterD = RotL64((aOrbiterD * 6972820410084939637U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 1707724300671717658U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterB = (((aOrbiterB ^ aOrbiterD) ^ 3802268808625297647U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterB = RotL64((aOrbiterB * 11296811630387191563U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 9423064323799920219U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 242153923313096551U) ^ aNonceWordJ;
            aOrbiterK = RotL64((aOrbiterK * 12117679073775630197U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 945801070951928277U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 13094814302414492064U) ^ aNonceWordH;
            aOrbiterF = RotL64((aOrbiterF * 14638176479878969775U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 7572219725951040117U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 16494986983782503428U;
            aOrbiterE = RotL64((aOrbiterE * 2739189408707408171U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 10949497978229234856U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 11219643352002119905U;
            aOrbiterJ = RotL64((aOrbiterJ * 16900635614259262873U), 3U);
            //
            aIngress = RotL64(aOrbiterA, 18U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 27U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 11U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 23U));
            aIngress = aIngress + RotL64(aOrbiterE, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aCross, 26U) + aOrbiterF) + RotL64(aOrbiterJ, 53U)) + aNonceWordG);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 5U) + aOrbiterB) + RotL64(aOrbiterJ, 23U));
            aWandererH = aWandererH + (((RotL64(aScatter, 37U) + RotL64(aOrbiterF, 5U)) + aOrbiterE) + aNonceWordE);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 57U) + aOrbiterE) + RotL64(aOrbiterD, 47U)) + aNonceWordN);
            aWandererD = aWandererD + ((RotL64(aScatter, 10U) + RotL64(aOrbiterK, 10U)) + aOrbiterJ);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterJ, 41U)) + aOrbiterI);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 43U) + RotL64(aOrbiterK, 29U)) + aOrbiterA) + RotL64(aCarry, 19U)) + aPhaseBWandererUpdateSaltC[((aIndex + 11U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aCross, 51U) + aOrbiterD) + RotL64(aOrbiterH, 57U)) + aPhaseBWandererUpdateSaltE[((aIndex + 19U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 21U) + aOrbiterH) + RotL64(aOrbiterF, 36U)) + RotL64(aCarry, 37U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 47U));
            aCarry = aCarry + (RotL64(aWandererB, 29U) ^ aWandererG);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 6U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 11U));
            aCarry = aCarry + RotL64(aWandererF, 23U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aInvestLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_b loop 3
        // ingress from: aInvestLaneD, aOperationLaneA, aExpandLaneD
        // ingress directions: aInvestLaneD forward forced, aOperationLaneA forward forced, aExpandLaneD forward/backward random
        // cross from: aInvestLaneC, aOperationLaneC
        // cross directions: aInvestLaneC backward forced, aOperationLaneC backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneD[((aIndex + 15666U)) & S_BLOCK1], 60U) ^ RotL64(aOperationLaneA[((aIndex + 11951U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aExpandLaneD[((aIndex + 11716U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 15212U)) & S_BLOCK1], 18U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 12595U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aIngress, 43U) ^ RotL64(aCross, 58U)) + (RotL64(aPrevious, 13U) ^ RotL64(aCarry, 27U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterC = ((aWandererD + RotL64(aScatter, 58U)) + RotL64(aCarry, 47U)) + 9220392006207660113U;
            aOrbiterI = ((aWandererA + RotL64(aCross, 3U)) + 11305018553489132882U) + aPhaseBOrbiterAssignSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = (((aWandererB + RotL64(aIngress, 51U)) + 5860373868073513684U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordF;
            aOrbiterH = (aWandererF + RotL64(aPrevious, 43U)) + 12319586170883987589U;
            aOrbiterJ = (aWandererK + RotL64(aScatter, 11U)) + 14072333614354649021U;
            aOrbiterB = ((aWandererE + RotL64(aPrevious, 27U)) + 9332158529453194608U) + aNonceWordI;
            aOrbiterE = (aWandererC + RotL64(aCross, 18U)) + 3860569321145958686U;
            aOrbiterG = (((aWandererI + RotL64(aIngress, 37U)) + RotL64(aCarry, 23U)) + 8119005668901240093U) + aNonceWordD;
            aOrbiterF = (((aWandererH + RotL64(aCross, 23U)) + RotL64(aCarry, 37U)) + 13918259792880333239U) + aNonceWordB;
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 6938856216758228704U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 3960905839118710604U;
            aOrbiterK = RotL64((aOrbiterK * 16203746868670689793U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 6043879193734253929U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 15691425268831319195U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 7189195135654636271U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 14912209933584715274U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 16180183395910618923U;
            aOrbiterB = RotL64((aOrbiterB * 3942858974766467849U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 4966642362507707776U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 6962226782462822861U;
            aOrbiterI = RotL64((aOrbiterI * 3647802407741095419U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 12409120845092026295U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 2302946450253872465U;
            aOrbiterF = RotL64((aOrbiterF * 7099576330777297911U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 16118304388937163838U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 15968419034359049422U) ^ aNonceWordO;
            aOrbiterG = RotL64((aOrbiterG * 11736207775827080165U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 17098982091525008231U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 10298979200690822062U;
            aOrbiterE = RotL64((aOrbiterE * 12620028874653521945U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 552826643694256437U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 11786560990790695378U;
            aOrbiterC = RotL64((aOrbiterC * 11190309640069208311U), 57U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterB) + 13730399230389329793U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordC;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 17614226859252305432U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2640019643570222977U), 47U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterJ, 19U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 5U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 10U));
            aIngress = aIngress + (RotL64(aOrbiterE, 47U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterG, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aIngress, 10U) + RotL64(aOrbiterE, 37U)) + aOrbiterF);
            aWandererB = aWandererB + (((RotL64(aPrevious, 47U) + aOrbiterK) + RotL64(aOrbiterG, 42U)) + RotL64(aCarry, 35U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 57U) + aOrbiterI) + RotL64(aOrbiterE, 53U)) + aNonceWordN);
            aWandererH = aWandererH + ((RotL64(aCross, 51U) + RotL64(aOrbiterH, 47U)) + aOrbiterB);
            aWandererC = aWandererC ^ ((((RotL64(aPrevious, 30U) + RotL64(aOrbiterH, 19U)) + aOrbiterJ) + aNonceWordK) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 43U) + RotL64(aOrbiterK, 5U)) + aOrbiterJ) + RotL64(aCarry, 51U));
            aWandererD = aWandererD ^ ((((RotL64(aScatter, 35U) + aOrbiterK) + RotL64(aOrbiterC, 30U)) + aNonceWordG) + aPhaseBWandererUpdateSaltD[((aIndex + 16U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aIngress, 5U) + aOrbiterC) + RotL64(aOrbiterG, 23U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 39U) + aOrbiterJ) + RotL64(aOrbiterE, 13U)) + aNonceWordP);
            //
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererB);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 43U));
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererC);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 36U));
            aCarry = aCarry + RotL64(aWandererA, 5U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 17893U)) & S_BLOCK1], 43U) ^ RotL64(aInvestLaneC[((aIndex + 16534U)) & S_BLOCK1], 26U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 20660U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 19654U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneD[((aIndex + 19786U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCross, 4U) ^ RotL64(aIngress, 27U)) + (RotL64(aPrevious, 39U) ^ RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterK = ((aWandererI + RotL64(aCross, 21U)) + 6771552164800695068U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterD = (aWandererB + RotL64(aIngress, 35U)) + 12131763371571322040U;
            aOrbiterJ = (((aWandererJ + RotL64(aPrevious, 26U)) + RotL64(aCarry, 39U)) + 3326182381395522013U) + aNonceWordN;
            aOrbiterI = ((((aWandererF + RotL64(aScatter, 13U)) + RotL64(aCarry, 13U)) + 12288775097697156383U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordM;
            aOrbiterE = ((aWandererK + RotL64(aCross, 3U)) + 5195948373449796741U) + aNonceWordH;
            aOrbiterF = ((aWandererH + RotL64(aIngress, 39U)) + 14404044002250137144U) + aNonceWordB;
            aOrbiterG = (aWandererD + RotL64(aScatter, 51U)) + 11142382920035825426U;
            aOrbiterH = (aWandererG + RotL64(aPrevious, 44U)) + 2967149520256475485U;
            aOrbiterA = ((aWandererC + RotL64(aIngress, 57U)) + RotL64(aCarry, 29U)) + 1470907369577818097U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 9231668148004163910U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 13078929163913892386U;
            aOrbiterJ = RotL64((aOrbiterJ * 7509829068700523627U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 9485274692075657877U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 12216951187543631673U;
            aOrbiterF = RotL64((aOrbiterF * 6571066246507310805U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 6933334652581744234U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 17260276102423580920U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7796879893790990605U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 387767848169714392U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 8597538259308082638U;
            aOrbiterI = RotL64((aOrbiterI * 4888054690557707241U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 7996708724489146033U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 15357384191688149939U;
            aOrbiterG = RotL64((aOrbiterG * 9827691726832491373U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 17739222908739454637U) + aNonceWordE;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 1614322333281471170U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7063116837752240891U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 4531604274893197209U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 3453280714992341288U;
            aOrbiterE = RotL64((aOrbiterE * 8390029711127907805U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 116623650872661533U) + aNonceWordG;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 6565636510115095988U;
            aOrbiterD = RotL64((aOrbiterD * 9691897067492501177U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 10303258439817808058U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 10917642773040237611U;
            aOrbiterK = RotL64((aOrbiterK * 10232856828372963363U), 23U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterI, 3U);
            aIngress = aIngress + (RotL64(aOrbiterK, 22U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 35U));
            aIngress = aIngress + (RotL64(aOrbiterH, 27U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterF, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterK, 6U)) + aOrbiterH) + aNonceWordA);
            aWandererI = aWandererI + (((RotL64(aScatter, 30U) + aOrbiterA) + RotL64(aOrbiterI, 23U)) + aNonceWordD);
            aWandererK = aWandererK ^ ((((RotL64(aPrevious, 57U) + RotL64(aOrbiterK, 41U)) + aOrbiterA) + aNonceWordC) + aPhaseBWandererUpdateSaltF[((aIndex + 19U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aIngress, 47U) + aOrbiterJ) + RotL64(aOrbiterG, 53U)) + aNonceWordF);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 53U) + aOrbiterH) + RotL64(aOrbiterF, 36U));
            aWandererH = aWandererH + ((((RotL64(aIngress, 3U) + aOrbiterD) + RotL64(aOrbiterA, 29U)) + RotL64(aCarry, 23U)) + aPhaseBWandererUpdateSaltA[((aIndex + 6U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 20U) + aOrbiterJ) + RotL64(aOrbiterD, 47U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterK, 13U)) + aOrbiterE) + RotL64(aCarry, 53U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterD, 19U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 56U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 47U));
            aCarry = aCarry + (RotL64(aWandererC, 3U) ^ aWandererD);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 23U));
            aCarry = aCarry + RotL64(aWandererH, 37U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 21904U)) & S_BLOCK1], 53U) ^ RotL64(aInvestLaneD[((aIndex + 24007U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aExpandLaneC[((aIndex + 23185U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22052U)) & S_BLOCK1], 57U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 23635U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aPrevious, 40U) ^ RotL64(aCross, 57U)) + (RotL64(aIngress, 27U) + RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterC = ((aWandererD + RotL64(aCross, 35U)) + RotL64(aCarry, 51U)) + 6521330037475130256U;
            aOrbiterB = ((aWandererA + RotL64(aScatter, 56U)) + 12611880456055428940U) + aNonceWordI;
            aOrbiterE = ((aWandererJ + RotL64(aPrevious, 43U)) + 12061611078130934708U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = ((((aWandererH + RotL64(aIngress, 51U)) + RotL64(aCarry, 13U)) + 1558112410801116984U) + aPhaseBOrbiterAssignSaltD[((aIndex + 27U)) & S_SALT1]) + aNonceWordA;
            aOrbiterI = ((aWandererB + RotL64(aPrevious, 21U)) + RotL64(aCarry, 35U)) + 10509115227850160786U;
            aOrbiterF = (aWandererE + RotL64(aCross, 39U)) + 4045915960688792066U;
            aOrbiterJ = ((aWandererF + RotL64(aScatter, 5U)) + 1196541286513243082U) + aNonceWordC;
            aOrbiterH = (aWandererI + RotL64(aIngress, 26U)) + 15564991032722373702U;
            aOrbiterD = (aWandererG + RotL64(aCross, 47U)) + 4897765238703641798U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 12327429514907752733U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 6189189797708711636U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 9017615866338877651U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 6374267075282018852U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 1888758503831341439U) ^ aNonceWordM;
            aOrbiterF = RotL64((aOrbiterF * 74387714918264257U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 14956857689299491800U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 14879361107223331957U;
            aOrbiterH = RotL64((aOrbiterH * 9166712966729591953U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 16086885494838105042U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 8069724185844303923U;
            aOrbiterC = RotL64((aOrbiterC * 8878470736758734353U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 10854345917959911439U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 7078313614360332089U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 9864025732292844871U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 15083669236062255011U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 594879695916679116U;
            aOrbiterD = RotL64((aOrbiterD * 9852515479152735283U), 35U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterD) + 6721466068234534523U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1]) + aNonceWordL;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 475816724162626782U;
            aOrbiterA = RotL64((aOrbiterA * 4799725182757588407U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 4341655358154605899U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 15477254302340298586U;
            aOrbiterJ = RotL64((aOrbiterJ * 13961520225881974201U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 10179091913200895775U) + aNonceWordD;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 6310490897546909571U;
            aOrbiterB = RotL64((aOrbiterB * 15080621088825477613U), 23U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterH, 29U);
            aIngress = aIngress + (RotL64(aOrbiterC, 39U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 42U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 47U));
            aIngress = aIngress + RotL64(aOrbiterB, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aCross, 53U) + RotL64(aOrbiterB, 12U)) + aOrbiterI) + aPhaseBWandererUpdateSaltE[((aIndex + 9U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aIngress, 27U) + aOrbiterD) + RotL64(aOrbiterH, 41U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 60U) + aOrbiterH) + RotL64(aOrbiterF, 3U)) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterA, 57U)) + aOrbiterD) + RotL64(aCarry, 21U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterA, 27U)) + aOrbiterI);
            aWandererF = aWandererF + (((RotL64(aScatter, 19U) + aOrbiterJ) + RotL64(aOrbiterD, 23U)) + RotL64(aCarry, 51U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 40U) + RotL64(aOrbiterE, 47U)) + aOrbiterF);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 23U) + aOrbiterF) + RotL64(aOrbiterC, 34U)) + aNonceWordB);
            aWandererH = aWandererH ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterD, 53U)) + aOrbiterI) + aNonceWordN);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 36U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 23U));
            aCarry = aCarry + (RotL64(aWandererJ, 5U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererI, 19U);
            aCarry = aCarry + RotL64(aIngress, 26U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 32299U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneA[((aIndex + 27648U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31162U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 31635U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneB[((aIndex + 28670U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aIngress, 53U)) + (RotL64(aPrevious, 37U) ^ RotL64(aCross, 18U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterK = (aWandererJ + RotL64(aScatter, 5U)) + 5721224134332887360U;
            aOrbiterI = ((aWandererI + RotL64(aCross, 60U)) + RotL64(aCarry, 11U)) + 6892749729775049095U;
            aOrbiterB = (((aWandererA + RotL64(aPrevious, 39U)) + RotL64(aCarry, 51U)) + 3884839462099556836U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = (aWandererG + RotL64(aIngress, 51U)) + 4365431706830216193U;
            aOrbiterA = ((aWandererE + RotL64(aPrevious, 35U)) + 15501528746571578773U) + aNonceWordK;
            aOrbiterJ = (((aWandererK + RotL64(aIngress, 14U)) + 4505911326320650606U) + aPhaseBOrbiterAssignSaltA[((aIndex + 7U)) & S_SALT1]) + aNonceWordD;
            aOrbiterD = (aWandererC + RotL64(aCross, 47U)) + 1865129050927879580U;
            aOrbiterG = ((aWandererD + RotL64(aScatter, 43U)) + RotL64(aCarry, 35U)) + 2011737665969640369U;
            aOrbiterH = ((aWandererH + RotL64(aPrevious, 27U)) + 611672935827062688U) + aNonceWordC;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 663547038310431047U) + aNonceWordG;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 5468932264754299556U;
            aOrbiterB = RotL64((aOrbiterB * 11968657455484578525U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 17920294117231191705U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 486058453837528110U;
            aOrbiterJ = RotL64((aOrbiterJ * 8851102552244026737U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 2789178451938129313U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 420772587981211184U;
            aOrbiterE = RotL64((aOrbiterE * 17402987842294006667U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 16196774774442181825U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 16264169656793713547U;
            aOrbiterG = RotL64((aOrbiterG * 6900221986041638783U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 10207659833859860796U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 8593749091183323678U;
            aOrbiterK = RotL64((aOrbiterK * 10696776033512404927U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 7224922076047787384U) + aNonceWordA;
            aOrbiterD = (((aOrbiterD ^ aOrbiterJ) ^ 15366267474865172373U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterD = RotL64((aOrbiterD * 10134187073321814217U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 4235342515820080294U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 5239480080426950612U;
            aOrbiterA = RotL64((aOrbiterA * 12077621553561927079U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 10891752830598395582U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 7797358829694471108U;
            aOrbiterI = RotL64((aOrbiterI * 7621206775460997431U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 3755715857903753416U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 3172069024987421726U) ^ aNonceWordL;
            aOrbiterH = RotL64((aOrbiterH * 16048490837178650865U), 19U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterG, 53U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 41U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 37U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterD, 4U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterB, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aIngress, 10U) + aOrbiterA) + RotL64(aOrbiterJ, 35U));
            aWandererD = aWandererD + ((RotL64(aScatter, 53U) + aOrbiterA) + RotL64(aOrbiterG, 57U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 29U) + aOrbiterK) + RotL64(aOrbiterJ, 4U));
            aWandererK = aWandererK + ((RotL64(aPrevious, 23U) + RotL64(aOrbiterI, 51U)) + aOrbiterK);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 19U) + aOrbiterH) + RotL64(aOrbiterB, 43U)) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aCross, 35U) + RotL64(aOrbiterD, 23U)) + aOrbiterA) + RotL64(aCarry, 51U)) + aNonceWordM);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 58U) + aOrbiterE) + RotL64(aOrbiterB, 19U)) + aNonceWordH);
            aWandererG = aWandererG + (((((RotL64(aIngress, 47U) + aOrbiterI) + RotL64(aOrbiterB, 30U)) + RotL64(aCarry, 39U)) + aNonceWordF) + aPhaseBWandererUpdateSaltD[((aIndex + 12U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 3U) + aOrbiterI) + RotL64(aOrbiterH, 13U)) + aNonceWordI);
            //
            aCarry = aCarry + (RotL64(aWandererH, 23U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererE, 19U) ^ aWandererG);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 12U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 37U));
            aCarry = aCarry + RotL64(aWandererI, 27U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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

void TwistExpander_Hockey_Arx::Seed_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x9BBEC6BC8700B289ULL + 0xBC77273C8985C0A9ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xD85D17C42329979FULL + 0x86799AC2848D595DULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xC6C92680FC9B7535ULL + 0xD004596E15AEA6ECULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xE04DE06AB3E6627DULL + 0x8426713E479DCCD4ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xED054201C4DB382DULL + 0xE30D1FEAD15CDAC5ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x97EB491F84A7F01FULL + 0xC92FCBA11CF0A531ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xDBB2CFFA8620E17BULL + 0xBB7B495B3644D13BULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xE5E8C2999B2049E1ULL + 0x9C752B806D5DF860ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xC798DE5E9B50A31BULL + 0xA4328CCC6A200B74ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x8382212E40657531ULL + 0x89FF223C622AC615ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x8677A9333D68971FULL + 0xAC7F1F5DDB921B0BULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x93DEDA1BF9FF92F3ULL + 0x92062A1C0AABAEEBULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xF93C2917133F3EAFULL + 0xA03E85046C1406F0ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xC69F0F3A69B775B9ULL + 0xCB424197795C3B64ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xBB563A688FD5618BULL + 0x8930BC3A1A3DDAC4ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0x84D6C783396FA09FULL + 0x964BF02893D3FFB5ULL);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 254U)) & S_BLOCK1], 30U) ^ RotL64(aExpandLaneB[((aIndex + 1405U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 4793U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 2648U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 5005U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aInvestLaneB[((aIndex + 803U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aPrevious, 53U) ^ RotL64(aCarry, 21U)) + (RotL64(aIngress, 3U) ^ RotL64(aCross, 40U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterF = (aWandererA + RotL64(aScatter, 11U)) + 785861751704720606U;
            aOrbiterJ = (((aWandererD + RotL64(aIngress, 39U)) + RotL64(aCarry, 5U)) + 15968088718435606299U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterD = (((aWandererF + RotL64(aCross, 19U)) + RotL64(aCarry, 37U)) + 1393976526590347151U) + aPhaseDOrbiterAssignSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterH = ((aWandererB + RotL64(aPrevious, 58U)) + 17240750947292745884U) + aNonceWordA;
            aOrbiterI = ((aWandererH + RotL64(aScatter, 5U)) + RotL64(aCarry, 19U)) + 4921576136163183137U;
            aOrbiterA = (aWandererI + RotL64(aPrevious, 29U)) + 3334047873553153032U;
            aOrbiterK = ((aWandererJ + RotL64(aCross, 51U)) + 15086509978458408698U) + aNonceWordF;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 892391205397581998U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 2965686403183767521U;
            aOrbiterD = RotL64((aOrbiterD * 709160942482770225U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 14632215393655706170U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 15740589515342377322U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 15677716942904794913U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 11131164813943086445U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 6988080581278900960U;
            aOrbiterA = RotL64((aOrbiterA * 6412189142344044255U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 16021254613117657178U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 6183615599897921154U;
            aOrbiterK = RotL64((aOrbiterK * 9976411093264211033U), 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 12533992547026652747U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 3104325358982904219U) ^ aNonceWordO;
            aOrbiterJ = RotL64((aOrbiterJ * 14977348108778147265U), 11U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterA) + 3878525937957474644U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1]) + aNonceWordH;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 2120435259884368445U;
            aOrbiterF = RotL64((aOrbiterF * 15964718652193073177U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 14928658302694194856U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 9121310461310309348U;
            aOrbiterH = RotL64((aOrbiterH * 17304439784647477491U), 53U);
            //
            aIngress = RotL64(aOrbiterF, 29U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterD, 57U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterJ, 12U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterI, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterI, 35U)) + aOrbiterK);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 3U) + aOrbiterK) + RotL64(aOrbiterA, 41U)) + RotL64(aCarry, 23U)) + aNonceWordG);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 60U) + aOrbiterD) + RotL64(aOrbiterF, 56U)) + aNonceWordC);
            aWandererF = aWandererF + ((((RotL64(aIngress, 21U) + RotL64(aOrbiterF, 21U)) + aOrbiterI) + RotL64(aCarry, 37U)) + aNonceWordM);
            aWandererH = aWandererH ^ ((((RotL64(aScatter, 27U) + aOrbiterJ) + RotL64(aOrbiterH, 47U)) + aNonceWordE) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aPrevious, 51U) + RotL64(aOrbiterJ, 11U)) + aOrbiterA);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 11U) + aOrbiterK) + RotL64(aOrbiterH, 3U)) + aPhaseDWandererUpdateSaltF[((aIndex + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 3U) ^ aWandererJ);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 56U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 19U));
            aCarry = aCarry + RotL64(aWandererD, 39U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = (RotL64(aSnowLaneA[((aIndex + 6490U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneC[((aIndex + 5593U)) & S_BLOCK1], 54U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 8630U)) & S_BLOCK1], 43U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 5823U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 5791U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 8752U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aInvestLaneD[((aIndex + 8994U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aPrevious, 3U) + RotL64(aCarry, 52U)) ^ (RotL64(aCross, 35U) ^ RotL64(aIngress, 19U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterC = (aWandererJ + RotL64(aCross, 35U)) + 10805654776556844351U;
            aOrbiterG = (((aWandererI + RotL64(aScatter, 53U)) + RotL64(aCarry, 53U)) + 582794182442795335U) + aNonceWordP;
            aOrbiterI = ((aWandererK + RotL64(aIngress, 41U)) + 2858343650974681068U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterK = (((aWandererC + RotL64(aPrevious, 4U)) + RotL64(aCarry, 21U)) + 8189584049022064284U) + aNonceWordL;
            aOrbiterB = (((aWandererF + RotL64(aCross, 21U)) + RotL64(aCarry, 37U)) + 1565100751996962893U) + aNonceWordH;
            aOrbiterE = ((aWandererH + RotL64(aPrevious, 11U)) + 8062028016947611891U) + aNonceWordC;
            aOrbiterD = ((aWandererG + RotL64(aIngress, 29U)) + 8280504280578451745U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 11326869194491655350U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 1671695656567777163U) ^ aNonceWordG;
            aOrbiterI = RotL64((aOrbiterI * 7511554500524257921U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 2349843105293943452U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 13015545152052004254U) ^ aNonceWordB;
            aOrbiterB = RotL64((aOrbiterB * 1316662811685429983U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 16703354404749291869U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 8713231044374305801U;
            aOrbiterC = RotL64((aOrbiterC * 9242480982197688625U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 11118401674497783533U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 14857556493734710364U;
            aOrbiterK = RotL64((aOrbiterK * 3452566050389715195U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 12953419670951660965U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 12666121730825089017U;
            aOrbiterD = RotL64((aOrbiterD * 14049925256934142519U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 11075249639473053423U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 9374217688244187867U;
            aOrbiterE = RotL64((aOrbiterE * 5261156325627117877U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 17608340953291367867U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 13159437499327086340U;
            aOrbiterG = RotL64((aOrbiterG * 4882100944453534805U), 27U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterC, 13U);
            aIngress = aIngress + (RotL64(aOrbiterG, 47U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterK, 3U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterD, 20U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aPrevious, 44U) + aOrbiterC) + RotL64(aOrbiterG, 44U));
            aWandererC = aWandererC ^ ((((RotL64(aScatter, 35U) + RotL64(aOrbiterD, 11U)) + aOrbiterK) + aNonceWordN) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aIngress, 3U) + aOrbiterC) + RotL64(aOrbiterK, 19U)) + RotL64(aCarry, 35U)) + aNonceWordJ);
            aWandererF = aWandererF ^ (((RotL64(aCross, 29U) + aOrbiterD) + RotL64(aOrbiterG, 37U)) + aPhaseDWandererUpdateSaltA[((aIndex + 21U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aPrevious, 53U) + aOrbiterD) + RotL64(aOrbiterE, 51U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterI, 27U)) + aOrbiterD);
            aWandererJ = aWandererJ + (((RotL64(aCross, 13U) + aOrbiterB) + RotL64(aOrbiterI, 3U)) + RotL64(aCarry, 19U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 43U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererC, 12U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererH, 37U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererF, 5U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = (RotL64(aSnowLaneB[((aIndex + 11209U)) & S_BLOCK1], 38U) ^ RotL64(aExpandLaneA[((aIndex + 14366U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 11128U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 15364U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 10997U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aPrevious, 43U) ^ RotL64(aCross, 5U)) + (RotL64(aCarry, 57U) ^ RotL64(aIngress, 26U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterJ = (aWandererB + RotL64(aIngress, 11U)) + 15188686795415908074U;
            aOrbiterH = ((aWandererD + RotL64(aCross, 27U)) + 17310049041983079779U) + aPhaseDOrbiterAssignSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterC = (aWandererA + RotL64(aPrevious, 56U)) + 8246925977992441471U;
            aOrbiterI = (((aWandererC + RotL64(aScatter, 37U)) + RotL64(aCarry, 53U)) + 8644260919918112781U) + aNonceWordO;
            aOrbiterG = ((((aWandererF + RotL64(aPrevious, 3U)) + RotL64(aCarry, 41U)) + 13401663736874819483U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordH;
            aOrbiterD = ((aWandererH + RotL64(aIngress, 21U)) + RotL64(aCarry, 11U)) + 7940358935238314973U;
            aOrbiterK = (aWandererG + RotL64(aScatter, 43U)) + 13278990328548007839U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 11346868298353840706U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 2374077904806833579U;
            aOrbiterC = RotL64((aOrbiterC * 1765686942154321425U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 6978903378645019166U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 11951633297870965212U;
            aOrbiterH = RotL64((aOrbiterH * 12778236598654492185U), 53U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 17398460995357409673U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 1215437945597836770U;
            aOrbiterG = RotL64((aOrbiterG * 9322970054123481621U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 1878751468043972239U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 5343002808239712390U) ^ aNonceWordI;
            aOrbiterI = RotL64((aOrbiterI * 11878640995447558811U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 9884918450053276861U) + aNonceWordL;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 15894599082080422550U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8359936745539546131U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 13917339232771145459U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 18101134009493720683U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 15835859435306756387U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 3830086372356903769U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 15894394599564584010U) ^ aNonceWordD;
            aOrbiterJ = RotL64((aOrbiterJ * 9513921913446609263U), 3U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterJ, 43U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 51U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 4U));
            aIngress = aIngress + RotL64(aOrbiterC, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 21U) + aOrbiterK) + RotL64(aOrbiterJ, 41U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aCross, 51U) + RotL64(aOrbiterD, 29U)) + aOrbiterK) + RotL64(aCarry, 47U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterG, 53U)) + aOrbiterH) + aNonceWordF);
            aWandererC = aWandererC + ((RotL64(aScatter, 29U) + RotL64(aOrbiterJ, 35U)) + aOrbiterC);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 44U) + aOrbiterH) + RotL64(aOrbiterC, 6U));
            aWandererH = aWandererH + (((((RotL64(aScatter, 3U) + RotL64(aOrbiterH, 19U)) + aOrbiterI) + RotL64(aCarry, 5U)) + aNonceWordA) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 11U) + aOrbiterJ) + RotL64(aOrbiterG, 47U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 47U) ^ aWandererG);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 37U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 4U));
            aCarry = aCarry + RotL64(aWandererA, 13U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 19696U)) & S_BLOCK1], 42U) ^ RotL64(aSnowLaneA[((aIndex + 16483U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 21263U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 20183U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 20484U)) & S_BLOCK1], 54U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCarry, 39U) + RotL64(aPrevious, 19U)) ^ (RotL64(aIngress, 51U) ^ RotL64(aCross, 4U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterB = ((aWandererB + RotL64(aPrevious, 57U)) + RotL64(aCarry, 5U)) + 7632760812370906911U;
            aOrbiterJ = ((aWandererK + RotL64(aCross, 51U)) + 6007174525479723089U) + aNonceWordB;
            aOrbiterI = ((((aWandererD + RotL64(aScatter, 44U)) + RotL64(aCarry, 51U)) + 3362829642521821048U) + aPhaseDOrbiterAssignSaltE[((aIndex + 27U)) & S_SALT1]) + aNonceWordD;
            aOrbiterG = ((aWandererI + RotL64(aIngress, 11U)) + RotL64(aCarry, 19U)) + 18009548556107978286U;
            aOrbiterK = (((aWandererC + RotL64(aPrevious, 23U)) + 17880909432272697327U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordE;
            aOrbiterD = (aWandererG + RotL64(aCross, 29U)) + 15961567935420752568U;
            aOrbiterA = ((aWandererE + RotL64(aScatter, 37U)) + 10136559064656837921U) + aNonceWordH;
            //
            aOrbiterB = (((aOrbiterB + aOrbiterJ) + 17622019364405410277U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1]) + aNonceWordC;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 6927494824421416306U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2686290883767829973U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 7125170407794874847U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 12342273503071032250U;
            aOrbiterG = RotL64((aOrbiterG * 867417849555857179U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 14997696377476124836U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 14874498694181230698U;
            aOrbiterA = RotL64((aOrbiterA * 4026127545746010937U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 2549397729130885686U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterA) ^ 4217995818662767955U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterJ = RotL64((aOrbiterJ * 5525525344485251063U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 4706089044415442525U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 17983900172670031015U;
            aOrbiterD = RotL64((aOrbiterD * 541552737180932879U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 1904937798143929988U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 10620877287033139483U;
            aOrbiterB = RotL64((aOrbiterB * 16711012562024287213U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 15681091173163181525U) + aNonceWordF;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 2655543246639000084U;
            aOrbiterK = RotL64((aOrbiterK * 16686375598149755947U), 21U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterI, 57U);
            aIngress = aIngress + (RotL64(aOrbiterD, 37U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 3U));
            aIngress = aIngress + RotL64(aOrbiterK, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aScatter, 27U) + RotL64(aOrbiterD, 51U)) + aOrbiterK);
            aWandererK = aWandererK ^ ((((RotL64(aIngress, 51U) + RotL64(aOrbiterJ, 13U)) + aOrbiterD) + aNonceWordP) + aPhaseDWandererUpdateSaltF[((aIndex + 12U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 57U) + aOrbiterA) + RotL64(aOrbiterD, 57U)) + RotL64(aCarry, 39U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 20U) + aOrbiterB) + RotL64(aOrbiterJ, 42U)) + aNonceWordJ);
            aWandererC = aWandererC + ((RotL64(aCross, 43U) + RotL64(aOrbiterA, 23U)) + aOrbiterK);
            aWandererB = aWandererB ^ ((((RotL64(aScatter, 11U) + RotL64(aOrbiterD, 35U)) + aOrbiterG) + aNonceWordM) + aPhaseDWandererUpdateSaltC[((aIndex + 20U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aIngress, 35U) + aOrbiterI) + RotL64(aOrbiterK, 29U)) + RotL64(aCarry, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 43U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererC, 35U) ^ aWandererG);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 30U));
            aCarry = aCarry + RotL64(aWandererD, 57U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 25472U)) & S_BLOCK1], 35U) ^ RotL64(aSnowLaneB[((aIndex + 23196U)) & S_BLOCK1], 4U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 22119U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 27278U)) & S_BLOCK1], 3U) ^ RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 23222U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aIngress, 27U) + RotL64(aCross, 13U)) ^ (RotL64(aPrevious, 58U) ^ RotL64(aCarry, 43U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterJ = ((aWandererC + RotL64(aCross, 3U)) + RotL64(aCarry, 35U)) + 8367680518550579791U;
            aOrbiterK = (aWandererF + RotL64(aPrevious, 53U)) + 11491674725611181241U;
            aOrbiterF = ((aWandererG + RotL64(aScatter, 43U)) + 16673861720782164214U) + aNonceWordK;
            aOrbiterC = ((((aWandererH + RotL64(aIngress, 19U)) + RotL64(aCarry, 23U)) + 9786610124108350855U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordG;
            aOrbiterD = (((aWandererK + RotL64(aScatter, 11U)) + RotL64(aCarry, 3U)) + 5745080601557577637U) + aNonceWordI;
            aOrbiterA = ((aWandererB + RotL64(aCross, 60U)) + 1959402215131684684U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterE = (aWandererJ + RotL64(aIngress, 35U)) + 6121650036079196522U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 12016309761037342392U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 5986936646177049603U;
            aOrbiterF = RotL64((aOrbiterF * 3585650475703294895U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 1000367700904043468U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 17425288243569101032U;
            aOrbiterK = RotL64((aOrbiterK * 2174614006719048535U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 4856917474950325209U) + aNonceWordB;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 16312111093223166419U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 11046477664487805241U), 53U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterA) + 456110002032422270U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1]) + aNonceWordP;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 11393724374787795662U;
            aOrbiterE = RotL64((aOrbiterE * 1176984359123668389U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 8378176867715697176U) + aNonceWordC;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 8086186452345234815U;
            aOrbiterA = RotL64((aOrbiterA * 8450438271765985235U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 8470349167474173245U) + aNonceWordO;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 2528229938740192694U;
            aOrbiterJ = RotL64((aOrbiterJ * 8717790851266520943U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 13247168811545753141U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 8745293957516815264U;
            aOrbiterD = RotL64((aOrbiterD * 14270617180621072619U), 23U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterJ, 13U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 27U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 57U));
            aIngress = aIngress + RotL64(aOrbiterK, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aIngress, 43U) + aOrbiterE) + RotL64(aOrbiterJ, 51U));
            aWandererK = aWandererK + ((((RotL64(aScatter, 3U) + RotL64(aOrbiterC, 44U)) + aOrbiterE) + RotL64(aCarry, 3U)) + aNonceWordF);
            aWandererH = aWandererH ^ ((((RotL64(aCross, 27U) + RotL64(aOrbiterK, 37U)) + aOrbiterJ) + aNonceWordH) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererC = aWandererC + (((((RotL64(aPrevious, 21U) + RotL64(aOrbiterF, 27U)) + aOrbiterD) + RotL64(aCarry, 21U)) + aNonceWordA) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 52U) + RotL64(aOrbiterD, 11U)) + aOrbiterJ);
            aWandererF = aWandererF + ((RotL64(aCross, 11U) + aOrbiterC) + RotL64(aOrbiterA, 5U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterC, 21U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererH, 48U) ^ aWandererB);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 29U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 53U));
            aCarry = aCarry + RotL64(aWandererJ, 23U);
            aCarry = aCarry + RotL64(aIngress, 58U);
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
            aIngress = (RotL64(aInvestLaneC[((aIndex + 31361U)) & S_BLOCK1], 47U) ^ RotL64(aInvestLaneA[((aIndex + 28532U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 27306U)) & S_BLOCK1], 34U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordA));
            //
            aCross = RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 28290U)) & S_BLOCK1], 46U) ^ RotL64(aExpandLaneB[((aIndex + 27475U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCross, 19U) + RotL64(aPrevious, 35U)) + (RotL64(aCarry, 4U) ^ RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterA = (((aWandererE + RotL64(aScatter, 60U)) + 13650869943246163567U) + aPhaseDOrbiterAssignSaltF[((aIndex + 3U)) & S_SALT1]) + aNonceWordP;
            aOrbiterE = ((aWandererG + RotL64(aPrevious, 13U)) + 3435284932011770999U) + aNonceWordJ;
            aOrbiterC = ((aWandererK + RotL64(aCross, 19U)) + RotL64(aCarry, 51U)) + 12388155658186776579U;
            aOrbiterF = (aWandererA + RotL64(aIngress, 51U)) + 2374345913955712039U;
            aOrbiterG = (((aWandererH + RotL64(aPrevious, 39U)) + RotL64(aCarry, 29U)) + 6095094526980292156U) + aNonceWordM;
            aOrbiterH = (aWandererC + RotL64(aScatter, 3U)) + 4965147025852444174U;
            aOrbiterI = ((((aWandererB + RotL64(aIngress, 27U)) + RotL64(aCarry, 5U)) + 3261881216269075298U) + aPhaseDOrbiterAssignSaltA[((aIndex + 19U)) & S_SALT1]) + aNonceWordG;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 4939780217097329222U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 3019862009792676287U;
            aOrbiterC = RotL64((aOrbiterC * 2452316208025448747U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 901910626217143974U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 3647055146712366383U) ^ aNonceWordD;
            aOrbiterA = RotL64((aOrbiterA * 1792602402476450009U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 7731765438957392967U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 13409819457393479741U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 3345078200262410715U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 5415832109107794258U) + aNonceWordF;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 8876738832313114471U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 1304277600444504135U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 17135570542519390359U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 2373193062766802082U;
            aOrbiterI = RotL64((aOrbiterI * 4213691513185791519U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 16318403285501718552U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 8456043288604687045U;
            aOrbiterF = RotL64((aOrbiterF * 10556964529144571683U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 10572534930284516528U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 14616251186735204677U;
            aOrbiterH = RotL64((aOrbiterH * 2048651204265459805U), 53U);
            //
            aIngress = RotL64(aOrbiterG, 27U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 57U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 47U));
            aIngress = aIngress + RotL64(aOrbiterF, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aCross, 47U) + RotL64(aOrbiterA, 5U)) + aOrbiterC);
            aWandererC = aWandererC ^ ((((RotL64(aIngress, 14U) + aOrbiterA) + RotL64(aOrbiterH, 27U)) + aNonceWordK) + aPhaseDWandererUpdateSaltE[((aIndex + 17U)) & S_SALT1]);
            aWandererK = aWandererK + (((((RotL64(aPrevious, 29U) + RotL64(aOrbiterE, 11U)) + aOrbiterA) + RotL64(aCarry, 37U)) + aNonceWordO) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 41U) + aOrbiterI) + RotL64(aOrbiterF, 19U));
            aWandererA = aWandererA + (((RotL64(aCross, 35U) + aOrbiterG) + RotL64(aOrbiterI, 57U)) + RotL64(aCarry, 57U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 53U) + aOrbiterH) + RotL64(aOrbiterC, 41U)) + aNonceWordL);
            aWandererH = aWandererH + ((RotL64(aPrevious, 23U) + aOrbiterF) + RotL64(aOrbiterA, 50U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 53U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 19U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 23U));
            aCarry = aCarry + RotL64(aWandererA, 60U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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

void TwistExpander_Hockey_Arx::Seed_E(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xB3AEC2CE0BBDA737ULL + 0xA767BD628002D0B0ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x9CADBBEB5EFA5335ULL + 0xD7995E8BCEBFBF3DULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xCE8CEA47361DCD01ULL + 0x9994DF4A8F2982C5ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xBB07F5C0849849C3ULL + 0xF240C34626EE5C18ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x94943414B8E07EAFULL + 0x96A006C3EA523B98ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xE9F30EE9E1379BF3ULL + 0xBF7023AF33B85119ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xE956ED78AF6DE095ULL + 0xA2980F853EEFE21DULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xDC931CE2D2ED6D21ULL + 0xE1BA946D6F47FB29ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0x84A88477C0A0A48BULL + 0xB6ED9A8C37D04029ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xF59100DCD18D6CD9ULL + 0xA63983FAF63B1957ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x8F735FB32FB9796FULL + 0xE1DC4EBC18DFFCCAULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xEF2E5112C0D623F3ULL + 0x984F24AFA4142833ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xC69AF8B4F4006DBDULL + 0xE7F3E59BE4DDB56CULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xA2C118B4C545120BULL + 0xE434AE84926303E2ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xC3A76D19C1497CC7ULL + 0xA1CB4FE63DB8D73BULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xDC2E05A2B5CEDBDDULL + 0x936C6B2F35637E74ULL);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 2960U)) & S_BLOCK1], 60U) ^ RotL64(aInvestLaneB[((aIndex + 3727U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 4762U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 802U)) & S_BLOCK1], 51U) ^ RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 2632U)) & S_BLOCK1], 34U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 1042U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aPrevious, 11U) + RotL64(aCarry, 26U)) ^ (RotL64(aCross, 41U) + RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterG = ((aWandererI + RotL64(aCross, 19U)) + RotL64(aCarry, 23U)) + 12669015908335980355U;
            aOrbiterH = ((aWandererD + RotL64(aIngress, 52U)) + 5438715179868613192U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterC = ((aWandererJ + RotL64(aScatter, 37U)) + RotL64(aCarry, 11U)) + 13172104448184536460U;
            aOrbiterK = ((aWandererC + RotL64(aPrevious, 21U)) + 13421421503244744803U) + aNonceWordI;
            aOrbiterE = ((aWandererE + RotL64(aIngress, 41U)) + RotL64(aCarry, 51U)) + 13327113302994856582U;
            aOrbiterD = ((aWandererK + RotL64(aPrevious, 57U)) + 4671768205922454413U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = (aWandererB + RotL64(aCross, 29U)) + 5355759962838579929U;
            aOrbiterB = ((aWandererG + RotL64(aScatter, 47U)) + 6691720614265406851U) + aNonceWordD;
            aOrbiterI = ((aWandererH + RotL64(aCross, 26U)) + 7063906424700911378U) + aNonceWordH;
            aOrbiterA = (aWandererA + RotL64(aPrevious, 35U)) + 17328616394166672263U;
            aOrbiterF = (aWandererF + RotL64(aScatter, 39U)) + 1542940602574207068U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 7203866278803132454U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 993485696233139264U;
            aOrbiterC = RotL64((aOrbiterC * 11609009908810366447U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 15659679028507488331U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 18321361454094675842U;
            aOrbiterE = RotL64((aOrbiterE * 3966860765622641843U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 9633319822696783352U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 3496559332232402963U;
            aOrbiterH = RotL64((aOrbiterH * 7772060229838162977U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 1918349708324205526U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 7701088402761359134U;
            aOrbiterI = RotL64((aOrbiterI * 9649485438465644795U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 6006824348814439686U) + aNonceWordG;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 18088375375347012557U;
            aOrbiterK = RotL64((aOrbiterK * 12801082943086128385U), 53U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 12816533373478543584U) + aNonceWordE;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 17951880253818836433U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8935839101517220201U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 11311632024372748238U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 9891349164779752351U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 11405973752233193209U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 711130292000437038U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 17818800917771709681U;
            aOrbiterD = RotL64((aOrbiterD * 10567029732245868263U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 10188714200240109442U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 9745615081760948652U;
            aOrbiterF = RotL64((aOrbiterF * 9321909462220134035U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 6508703788527163965U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 7536038073603467381U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 12015514242701199813U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 2793951597846756844U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 12669015908335980355U) ^ aNonceWordL;
            aOrbiterB = RotL64((aOrbiterB * 7355285540199760689U), 23U);
            //
            aIngress = RotL64(aOrbiterF, 53U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterH, 19U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 29U));
            aIngress = aIngress + (RotL64(aOrbiterD, 5U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterK, 10U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterC, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aCross, 47U) + RotL64(aOrbiterK, 18U)) + aOrbiterB) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 27U) + RotL64(aOrbiterH, 37U)) + aOrbiterK) + aPhaseEWandererUpdateSaltA[((aIndex + 11U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aScatter, 13U) + aOrbiterI) + RotL64(aOrbiterA, 43U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 24U) + aOrbiterG) + RotL64(aOrbiterJ, 51U));
            aWandererF = aWandererF + (((RotL64(aCross, 19U) + aOrbiterA) + RotL64(aOrbiterE, 57U)) + RotL64(aCarry, 11U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 37U) + aOrbiterC) + RotL64(aOrbiterE, 47U)) + aNonceWordN);
            aWandererG = aWandererG + ((RotL64(aPrevious, 35U) + RotL64(aOrbiterG, 10U)) + aOrbiterD);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 53U) + aOrbiterH) + RotL64(aOrbiterF, 41U));
            aWandererC = aWandererC + (((RotL64(aScatter, 22U) + RotL64(aOrbiterI, 23U)) + aOrbiterC) + RotL64(aCarry, 41U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 51U) + aOrbiterJ) + RotL64(aOrbiterD, 53U)) + aNonceWordB);
            aWandererE = aWandererE + ((RotL64(aPrevious, 57U) + RotL64(aOrbiterF, 21U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererF, 43U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererC, 35U) ^ aWandererB);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 21U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 4U));
            aCarry = aCarry + (RotL64(aWandererJ, 51U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererI, 27U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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
            aIngress = (RotL64(aFireLaneA[((aIndex + 8189U)) & S_BLOCK1], 53U) ^ RotL64(aInvestLaneC[((aIndex + 10392U)) & S_BLOCK1], 10U));
            aIngress ^= (RotL64(aInvestLaneD[((aIndex + 5587U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneA[((aIndex + 6409U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 10150U)) & S_BLOCK1], 47U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 9944U)) & S_BLOCK1], 20U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 8406U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCross, 39U) ^ RotL64(aPrevious, 26U)) + (RotL64(aCarry, 3U) ^ RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterE = (aWandererF + RotL64(aPrevious, 53U)) + 13854738573712660276U;
            aOrbiterA = ((aWandererG + RotL64(aScatter, 23U)) + RotL64(aCarry, 39U)) + 16835460633412286294U;
            aOrbiterC = (aWandererC + RotL64(aIngress, 41U)) + 6785859293758091931U;
            aOrbiterJ = ((aWandererH + RotL64(aCross, 6U)) + 126317283127992659U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = (((aWandererE + RotL64(aPrevious, 47U)) + RotL64(aCarry, 21U)) + 7568963536291415413U) + aNonceWordC;
            aOrbiterF = ((aWandererI + RotL64(aCross, 27U)) + 12294016745653004819U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = (aWandererJ + RotL64(aScatter, 43U)) + 18269588932920281147U;
            aOrbiterK = ((aWandererK + RotL64(aIngress, 35U)) + RotL64(aCarry, 53U)) + 5872406424994751026U;
            aOrbiterI = (aWandererA + RotL64(aPrevious, 21U)) + 7764434758831474129U;
            aOrbiterD = ((aWandererD + RotL64(aIngress, 57U)) + 4804168969415573371U) + aNonceWordJ;
            aOrbiterG = (aWandererB + RotL64(aCross, 38U)) + 959601763507651280U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 9257644462479293048U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 14332699366894494579U) ^ aNonceWordF;
            aOrbiterC = RotL64((aOrbiterC * 8829304078930625541U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 10487012596470786004U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 612729229562321440U;
            aOrbiterH = RotL64((aOrbiterH * 11380387280507726003U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 7845523921295625315U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 12742115479740024747U;
            aOrbiterB = RotL64((aOrbiterB * 15578543510683986421U), 53U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 10294667720904610944U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 14369711143154904567U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13753005602288309379U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 10918344717497681894U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 18136794828308636957U) ^ aNonceWordM;
            aOrbiterK = RotL64((aOrbiterK * 17899418637978002409U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 14378638206724886404U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 7077588188450008059U;
            aOrbiterE = RotL64((aOrbiterE * 485375960462924335U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 8941870012851971932U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 15242087859620352399U;
            aOrbiterD = RotL64((aOrbiterD * 4963002810455992839U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 10395280254030875387U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 6826595516076975980U;
            aOrbiterJ = RotL64((aOrbiterJ * 6198886240333178001U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 10407910809564430664U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 6368255889263255730U;
            aOrbiterA = RotL64((aOrbiterA * 3809496492809859731U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 6365669830464231626U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 596785214258266904U;
            aOrbiterG = RotL64((aOrbiterG * 6338109335634389561U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 4807438574488830717U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 13854738573712660276U;
            aOrbiterI = RotL64((aOrbiterI * 6954368463489446551U), 3U);
            //
            aIngress = RotL64(aOrbiterC, 29U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterE, 26U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 19U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 57U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 5U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterG, 24U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 48U) + RotL64(aOrbiterB, 13U)) + aOrbiterC) + aNonceWordH);
            aWandererA = aWandererA + ((RotL64(aCross, 21U) + RotL64(aOrbiterJ, 57U)) + aOrbiterI);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterE, 29U)) + aOrbiterD);
            aWandererF = aWandererF + (((RotL64(aScatter, 41U) + aOrbiterG) + RotL64(aOrbiterK, 35U)) + RotL64(aCarry, 37U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 43U) + aOrbiterE) + RotL64(aOrbiterG, 48U));
            aWandererG = aWandererG + ((RotL64(aPrevious, 30U) + aOrbiterF) + RotL64(aOrbiterA, 19U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterC, 5U)) + aOrbiterF);
            aWandererD = aWandererD + (((RotL64(aIngress, 53U) + RotL64(aOrbiterH, 23U)) + aOrbiterI) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 37U) + aOrbiterE) + RotL64(aOrbiterI, 41U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 19U) + aOrbiterA) + RotL64(aOrbiterB, 21U)) + RotL64(aCarry, 41U));
            aWandererC = aWandererC ^ ((((RotL64(aScatter, 39U) + RotL64(aOrbiterG, 52U)) + aOrbiterJ) + aNonceWordK) + aPhaseEWandererUpdateSaltD[((aIndex + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 51U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 12U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 37U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 29U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 39U));
            aCarry = aCarry + RotL64(aWandererK, 6U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 15125U)) & S_BLOCK1], 57U) ^ RotL64(aInvestLaneA[((aIndex + 12821U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 14556U)) & S_BLOCK1], 28U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 13856U)) & S_BLOCK1], 53U) ^ RotL64(aInvestLaneC[((aIndex + 15158U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aIngress, 43U) + RotL64(aCarry, 29U)) + (RotL64(aCross, 56U) ^ RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterC = ((aWandererB + RotL64(aScatter, 41U)) + 6469584119078165548U) + aNonceWordE;
            aOrbiterA = (((aWandererF + RotL64(aCross, 5U)) + RotL64(aCarry, 57U)) + 14329756366517987910U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = (aWandererE + RotL64(aPrevious, 47U)) + 12890831797059772123U;
            aOrbiterB = ((aWandererC + RotL64(aIngress, 21U)) + 3164503807500018990U) + aNonceWordJ;
            aOrbiterE = (aWandererD + RotL64(aPrevious, 52U)) + 177531431387646836U;
            aOrbiterJ = (((aWandererH + RotL64(aCross, 11U)) + 3167421392893561015U) + aPhaseEOrbiterAssignSaltF[((aIndex + 7U)) & S_SALT1]) + aNonceWordN;
            aOrbiterH = (((aWandererA + RotL64(aScatter, 57U)) + RotL64(aCarry, 47U)) + 2813174781844753460U) + aNonceWordA;
            aOrbiterK = ((aWandererI + RotL64(aIngress, 13U)) + RotL64(aCarry, 3U)) + 10953270419153249857U;
            aOrbiterG = (aWandererJ + RotL64(aPrevious, 37U)) + 16911518309710356951U;
            aOrbiterD = (aWandererG + RotL64(aIngress, 54U)) + 6616750447844893150U;
            aOrbiterI = (aWandererK + RotL64(aScatter, 35U)) + 10276741398025985982U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 6206043608461213208U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 12021552904553405793U;
            aOrbiterF = RotL64((aOrbiterF * 10023362889960174909U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 15283586234744144846U) + aNonceWordM;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 5923238786775948571U;
            aOrbiterJ = RotL64((aOrbiterJ * 8200882393521882651U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 11044014510971660078U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 9351141024085076044U;
            aOrbiterE = RotL64((aOrbiterE * 13316079344614432317U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 17703395981862992420U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 10154548848376027087U;
            aOrbiterH = RotL64((aOrbiterH * 12324478347590509035U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 8836420852291617425U) + aNonceWordD;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 10193385413543886344U;
            aOrbiterG = RotL64((aOrbiterG * 824935982418585449U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 8248580084535685190U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 3910083671888152974U;
            aOrbiterB = RotL64((aOrbiterB * 17825311776715895927U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 12350341628569930642U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 2565977481575002842U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 18233446879833776677U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 9271041067874027417U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 14289254596554201861U) ^ aNonceWordG;
            aOrbiterK = RotL64((aOrbiterK * 7985522692852251413U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 5981802134118235214U) + aNonceWordH;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 14047813418129636856U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 15961435325216504877U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 11808443842149398212U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 11380858372643695792U;
            aOrbiterD = RotL64((aOrbiterD * 100198424024622179U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 10385375464069162356U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 6469584119078165548U;
            aOrbiterA = RotL64((aOrbiterA * 5263876933019848989U), 43U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterH, 53U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 14U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 39U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 5U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterG, 21U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterB, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aCross, 21U) + aOrbiterB) + RotL64(aOrbiterD, 43U)) + aPhaseEWandererUpdateSaltF[((aIndex + 11U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aIngress, 19U) + RotL64(aOrbiterG, 11U)) + aOrbiterA) + RotL64(aCarry, 13U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 5U) + RotL64(aOrbiterF, 29U)) + aOrbiterB) + aNonceWordC);
            aWandererE = aWandererE + ((RotL64(aPrevious, 47U) + RotL64(aOrbiterK, 54U)) + aOrbiterA);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 14U) + aOrbiterE) + RotL64(aOrbiterB, 27U));
            aWandererI = aWandererI + ((((RotL64(aPrevious, 29U) + aOrbiterB) + RotL64(aOrbiterG, 57U)) + aNonceWordO) + aPhaseEWandererUpdateSaltC[((aIndex + 10U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterK, 51U)) + aOrbiterC);
            aWandererD = aWandererD + (((RotL64(aCross, 3U) + aOrbiterI) + RotL64(aOrbiterJ, 21U)) + RotL64(aCarry, 53U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 23U) + RotL64(aOrbiterA, 19U)) + aOrbiterE) + aNonceWordI);
            aWandererJ = aWandererJ + ((RotL64(aCross, 39U) + aOrbiterH) + RotL64(aOrbiterI, 6U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 56U) + RotL64(aOrbiterI, 39U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 34U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 23U));
            aCarry = aCarry + (RotL64(aWandererB, 13U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererE, 5U) ^ aWandererH);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 27U));
            aCarry = aCarry + RotL64(aWandererC, 51U);
            aCarry = aCarry + RotL64(aIngress, 38U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 17049U)) & S_BLOCK1], 5U) ^ RotL64(aFireLaneA[((aIndex + 20184U)) & S_BLOCK1], 36U));
            aIngress ^= RotL64(aWorkLaneD[((aIndex + 21684U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 21347U)) & S_BLOCK1], 19U) ^ RotL64(aInvestLaneD[((aIndex + 18060U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCross, 39U) + RotL64(aPrevious, 11U)) + (RotL64(aCarry, 27U) ^ RotL64(aIngress, 60U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterG = ((aWandererD + RotL64(aIngress, 14U)) + RotL64(aCarry, 29U)) + 14823268998003220191U;
            aOrbiterA = ((aWandererK + RotL64(aScatter, 19U)) + 15295237288788213847U) + aNonceWordM;
            aOrbiterH = ((aWandererG + RotL64(aPrevious, 53U)) + 16434853402001133899U) + aPhaseEOrbiterAssignSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = (((aWandererI + RotL64(aCross, 43U)) + RotL64(aCarry, 21U)) + 7555911304407871631U) + aNonceWordE;
            aOrbiterF = (aWandererB + RotL64(aScatter, 57U)) + 14977248264994834620U;
            aOrbiterE = (aWandererF + RotL64(aCross, 37U)) + 9707764144919392380U;
            aOrbiterI = ((aWandererE + RotL64(aPrevious, 39U)) + RotL64(aCarry, 57U)) + 1277304385464681529U;
            aOrbiterK = (((aWandererA + RotL64(aIngress, 23U)) + 3089786220465849395U) + aPhaseEOrbiterAssignSaltB[((aIndex + 7U)) & S_SALT1]) + aNonceWordG;
            aOrbiterD = (aWandererH + RotL64(aPrevious, 21U)) + 3700503853358695085U;
            aOrbiterB = (aWandererJ + RotL64(aIngress, 5U)) + 3240054112993517371U;
            aOrbiterC = ((aWandererC + RotL64(aScatter, 48U)) + 16897532076915366859U) + aNonceWordK;
            //
            aOrbiterG = (((aOrbiterG + aOrbiterA) + 18167359289798364307U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1]) + aNonceWordO;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 8870819278575769863U;
            aOrbiterH = RotL64((aOrbiterH * 9334066154398059075U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 15363069206212330251U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 14858164441499725158U;
            aOrbiterG = RotL64((aOrbiterG * 14931933411393847915U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 5357144808788707522U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 2910681277417754860U) ^ aNonceWordF;
            aOrbiterJ = RotL64((aOrbiterJ * 13170868582159347059U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 9824408699018165151U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 368370224788793300U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 14358982366258729959U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 7095398304588825115U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 11418879758164313554U;
            aOrbiterF = RotL64((aOrbiterF * 5983520332639771791U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 2171599720681913272U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 17593730219647495033U;
            aOrbiterB = RotL64((aOrbiterB * 12926053208918563087U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 17755947635188715523U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 14565740605227022106U) ^ aNonceWordA;
            aOrbiterI = RotL64((aOrbiterI * 15866418354612945335U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 14538017880915584414U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 6174566474851449123U;
            aOrbiterA = RotL64((aOrbiterA * 179569008593475683U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 3806438394748643441U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 13737114463856719285U;
            aOrbiterC = RotL64((aOrbiterC * 13439346068497710151U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 3698379331577470045U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 1097081284062708554U;
            aOrbiterE = RotL64((aOrbiterE * 3498627643013255777U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 215117138867597766U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 14823268998003220191U;
            aOrbiterK = RotL64((aOrbiterK * 12131828437975771377U), 27U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterE, 39U);
            aIngress = aIngress + (RotL64(aOrbiterD, 60U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterK, 41U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterB, 53U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterJ, 11U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterC, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aIngress, 35U) + aOrbiterK) + RotL64(aOrbiterD, 3U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 39U) + aOrbiterK) + RotL64(aOrbiterG, 35U));
            aWandererH = aWandererH + (((RotL64(aScatter, 19U) + RotL64(aOrbiterI, 27U)) + aOrbiterF) + aNonceWordB);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 24U) + RotL64(aOrbiterF, 39U)) + aOrbiterJ);
            aWandererA = aWandererA + (((RotL64(aIngress, 47U) + aOrbiterI) + RotL64(aOrbiterA, 24U)) + aNonceWordI);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 51U) + aOrbiterJ) + RotL64(aOrbiterK, 53U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 41U) + aOrbiterA) + RotL64(aOrbiterC, 37U)) + RotL64(aCarry, 5U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterH, 5U)) + aOrbiterF);
            aWandererG = aWandererG + ((((RotL64(aIngress, 60U) + aOrbiterE) + RotL64(aOrbiterC, 57U)) + RotL64(aCarry, 29U)) + aNonceWordD);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterI, 48U)) + aOrbiterD);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 27U) + RotL64(aOrbiterE, 43U)) + aOrbiterB) + aNonceWordJ) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 23U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererH, 29U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererF, 56U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererD, 27U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererB, 13U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererK, 53U);
            aCarry = aCarry + RotL64(aIngress, 10U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 24370U)) & S_BLOCK1], 40U) ^ RotL64(aFireLaneB[((aIndex + 24395U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 26055U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 23294U)) & S_BLOCK1], 47U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 23450U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aInvestLaneA[((aIndex + 25793U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCross, 56U) + RotL64(aPrevious, 43U)) + (RotL64(aIngress, 27U) ^ RotL64(aCarry, 13U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterH = (aWandererC + RotL64(aCross, 35U)) + 7722279280863371124U;
            aOrbiterD = ((aWandererH + RotL64(aScatter, 56U)) + 11584220561732385598U) + aPhaseEOrbiterAssignSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = (aWandererJ + RotL64(aPrevious, 5U)) + 7834679350105534657U;
            aOrbiterG = ((aWandererF + RotL64(aIngress, 43U)) + 11347994382444180879U) + aNonceWordP;
            aOrbiterF = ((aWandererI + RotL64(aCross, 27U)) + RotL64(aCarry, 11U)) + 9449903188047063431U;
            aOrbiterI = (aWandererK + RotL64(aPrevious, 51U)) + 6516243976652795170U;
            aOrbiterC = ((aWandererG + RotL64(aScatter, 3U)) + 8420815253991184777U) + aNonceWordN;
            aOrbiterJ = (((aWandererA + RotL64(aIngress, 24U)) + RotL64(aCarry, 41U)) + 9081386852515170937U) + aPhaseEOrbiterAssignSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = ((aWandererE + RotL64(aScatter, 13U)) + RotL64(aCarry, 5U)) + 14375955191735286867U;
            aOrbiterE = ((aWandererB + RotL64(aPrevious, 11U)) + 880757589768436072U) + aNonceWordM;
            aOrbiterK = ((aWandererD + RotL64(aIngress, 39U)) + 3349856625725164229U) + aNonceWordD;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 7826309957607577207U) + aNonceWordE;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 8057435761214313635U;
            aOrbiterB = RotL64((aOrbiterB * 4718430712767038607U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 9565237500443303103U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 15893066735310588501U;
            aOrbiterI = RotL64((aOrbiterI * 8457633439171452397U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 3276844534476430842U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 6828644383891274120U;
            aOrbiterJ = RotL64((aOrbiterJ * 979580351653410157U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 2815676923011504251U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 5030251870850928417U;
            aOrbiterH = RotL64((aOrbiterH * 7075653570570819253U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 13464083008377887034U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 8994560761846897590U;
            aOrbiterC = RotL64((aOrbiterC * 9892839554658865143U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 8398813387154468736U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 8136429428340910892U;
            aOrbiterD = RotL64((aOrbiterD * 3348811490733577295U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 418587250696862341U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 4111667833838312094U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 860949442143849147U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 6075478294190926371U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 2208124955874142264U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 15741988616251072075U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 4726538724576443010U) + aNonceWordO;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 6524078248882840425U;
            aOrbiterF = RotL64((aOrbiterF * 9784875566721689069U), 51U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterB) + 14521003220464811621U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1]) + aNonceWordK;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 16916247868211621303U;
            aOrbiterA = RotL64((aOrbiterA * 1911638054294853877U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 18207293125461843123U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 7722279280863371124U;
            aOrbiterE = RotL64((aOrbiterE * 14303108475807941791U), 5U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterH, 27U);
            aIngress = aIngress + (RotL64(aOrbiterI, 21U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterE, 14U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterF, 39U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterG, 35U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterD, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aScatter, 51U) + aOrbiterI) + RotL64(aOrbiterB, 43U)) + aNonceWordC);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 3U) + aOrbiterH) + RotL64(aOrbiterD, 29U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 60U) + aOrbiterI) + RotL64(aOrbiterG, 19U));
            aWandererI = aWandererI + ((RotL64(aIngress, 11U) + RotL64(aOrbiterB, 27U)) + aOrbiterF);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 13U) + aOrbiterH) + RotL64(aOrbiterJ, 48U));
            aWandererK = aWandererK + ((RotL64(aCross, 53U) + RotL64(aOrbiterA, 23U)) + aOrbiterJ);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 35U) + aOrbiterC) + RotL64(aOrbiterG, 41U)) + aNonceWordB);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 27U) + aOrbiterB) + RotL64(aOrbiterG, 3U)) + RotL64(aCarry, 43U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aCross, 19U) + aOrbiterE) + RotL64(aOrbiterG, 38U)) + aNonceWordG);
            aWandererA = aWandererA + (((RotL64(aIngress, 38U) + RotL64(aOrbiterD, 51U)) + aOrbiterF) + RotL64(aCarry, 19U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 23U) + aOrbiterK) + RotL64(aOrbiterB, 11U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 11U) ^ aWandererH);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 46U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 19U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 43U));
            aCarry = aCarry + (RotL64(aWandererC, 39U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererD, 21U);
            aCarry = aCarry + RotL64(aIngress, 58U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 31039U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneA[((aIndex + 27821U)) & S_BLOCK1], 58U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 29940U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 29007U)) & S_BLOCK1], 5U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 32402U)) & S_BLOCK1], 18U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCross, 23U) ^ RotL64(aPrevious, 57U)) + (RotL64(aIngress, 5U) ^ RotL64(aCarry, 44U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterB = (((aWandererC + RotL64(aCross, 46U)) + RotL64(aCarry, 29U)) + 12535417189990029950U) + aNonceWordF;
            aOrbiterI = (aWandererH + RotL64(aScatter, 19U)) + 6204401443676390273U;
            aOrbiterC = (((aWandererE + RotL64(aIngress, 37U)) + RotL64(aCarry, 21U)) + 869613505613154672U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterK = ((aWandererI + RotL64(aPrevious, 57U)) + 15053590879563855802U) + aNonceWordD;
            aOrbiterA = ((aWandererG + RotL64(aIngress, 23U)) + 13338989605204591428U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = (aWandererA + RotL64(aCross, 34U)) + 18306470022403825392U;
            aOrbiterE = (aWandererB + RotL64(aPrevious, 29U)) + 1150696349434090218U;
            aOrbiterG = (aWandererJ + RotL64(aScatter, 5U)) + 13549541786420596437U;
            aOrbiterJ = (aWandererD + RotL64(aCross, 21U)) + 14302878430259588461U;
            aOrbiterH = (aWandererK + RotL64(aPrevious, 13U)) + 4660437084477165225U;
            aOrbiterD = ((aWandererF + RotL64(aScatter, 3U)) + RotL64(aCarry, 13U)) + 1653628537860912069U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 5594199757006711631U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 11008472193138708891U;
            aOrbiterC = RotL64((aOrbiterC * 13645764762027798301U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 3668516817279364310U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 128159531749679984U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4523246859249826987U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 6378674346113979108U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 11438762460659123362U;
            aOrbiterG = RotL64((aOrbiterG * 2733309638158283953U), 43U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterJ) + 10624263004446482910U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1]) + aNonceWordM;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 12546839706919241411U;
            aOrbiterK = RotL64((aOrbiterK * 11468326687628079347U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 8466639576503293921U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 5828694979857951504U) ^ aNonceWordG;
            aOrbiterJ = RotL64((aOrbiterJ * 7835487310289634515U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 16496305151014092976U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 589464613876410567U;
            aOrbiterB = RotL64((aOrbiterB * 13190816610718051897U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 4168532743415647825U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 15944887793736489375U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 17273403561158196717U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 11642456814106259483U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 1609897693632334867U;
            aOrbiterA = RotL64((aOrbiterA * 12912773555616819941U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 14950238412766325479U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 11862438528287402255U) ^ aNonceWordC;
            aOrbiterD = RotL64((aOrbiterD * 7635864312080265695U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 5900629306795222263U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 3221591991392500536U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7188525011266868855U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 16938699391746264010U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 12535417189990029950U;
            aOrbiterI = RotL64((aOrbiterI * 18212319484142613215U), 11U);
            //
            aIngress = RotL64(aOrbiterB, 39U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterJ, 43U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterF, 35U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterA, 37U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterE, 12U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterH, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aCross, 14U) + RotL64(aOrbiterB, 21U)) + aOrbiterK);
            aWandererC = aWandererC + ((RotL64(aPrevious, 21U) + RotL64(aOrbiterH, 47U)) + aOrbiterD);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 37U) + aOrbiterI) + RotL64(aOrbiterE, 13U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 39U) + aOrbiterD) + RotL64(aOrbiterB, 35U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 3U) + aOrbiterG) + RotL64(aOrbiterE, 6U));
            aWandererD = aWandererD + ((((RotL64(aScatter, 35U) + RotL64(aOrbiterJ, 27U)) + aOrbiterC) + RotL64(aCarry, 11U)) + aNonceWordE);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterD, 29U)) + aOrbiterA);
            aWandererH = aWandererH + ((RotL64(aCross, 5U) + RotL64(aOrbiterF, 19U)) + aOrbiterE);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 12U) + aOrbiterC) + RotL64(aOrbiterH, 3U));
            aWandererK = aWandererK + (((RotL64(aCross, 41U) + aOrbiterA) + RotL64(aOrbiterI, 39U)) + RotL64(aCarry, 47U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 47U) + RotL64(aOrbiterE, 52U)) + aOrbiterK) + aNonceWordI);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 46U));
            aCarry = aCarry + (RotL64(aWandererH, 53U) ^ aWandererK);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 29U));
            aCarry = aCarry + (RotL64(aWandererJ, 27U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererI, 5U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererC, 11U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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

void TwistExpander_Hockey_Arx::Seed_F(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xBDBEA523A64D921DULL + 0xB9345956E5DAB7E2ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xBA4F7678A6E4A0E9ULL + 0xDC61785177CEB1DEULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xE44013626996595BULL + 0x99A6068574D48A8FULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xCB9798E30DB22975ULL + 0x93D898A3EC52FB56ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x9CB009F85479B0DDULL + 0xCD2433967F2C1C68ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xABBB190D8FE6204FULL + 0xA9BA33F2E0A2CF62ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x972D1A4F274F08CFULL + 0xAE95560B52CCB268ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xFC9530E0875C538BULL + 0xE552FED02FE1B83DULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xA1FF348A88560531ULL + 0xE2A26372FD4C3205ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xB4FFA3A9D9E1CE39ULL + 0xD3DFE78B245DF255ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0x92DE5908A37EB747ULL + 0x80A5769DD9CEA84CULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xB5DC50622E672B27ULL + 0xD25496C0AE03F9EBULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xB9B941E852721C41ULL + 0xB27610EFA27CBAB9ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xEF2A4EA51CD6A9E3ULL + 0xB3A5E51C069435D6ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xF7E292CE99A6D8EBULL + 0xE91A78D9B3398BDDULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xC9331E2AC1FD5577ULL + 0x8BFAB94925EB981EULL);
    // GSeedRunSeed_F seed_loop_f (start)
    {
        // GSeedRunSeed_F seed_loop_f lane group
        // read from: aOperationLaneA, aOperationLaneB, aWorkLaneD, aOperationLaneC, aOperationLaneD, aInvestLaneD, aSnowLaneC, aInvestLaneA, aSnowLaneB, aSnowLaneD, aSnowLaneA, aExpandLaneA, aInvestLaneB, aExpandLaneB, aWorkLaneC, aExpandLaneC, aInvestLaneC
        // write to: aSnowLaneC, aSnowLaneD, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // seed_loop_f loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aWorkLaneD
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aWorkLaneD forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aInvestLaneD
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aInvestLaneD backward/forward random
        // write to: aSnowLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 4066U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneB[((aIndex + 2301U)) & S_BLOCK1], 20U));
            aIngress ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 1245U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 1535U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 82U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aInvestLaneD[((aIndex + 567U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aPrevious, 39U)) + (RotL64(aCarry, 21U) + RotL64(aIngress, 56U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterK = ((aWandererE + RotL64(aCross, 10U)) + RotL64(aCarry, 51U)) + 14179205183062705133U;
            aOrbiterI = ((aWandererD + RotL64(aPrevious, 57U)) + 210032324058740920U) + aNonceWordL;
            aOrbiterF = ((aWandererF + RotL64(aScatter, 43U)) + 7387115089142500152U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = (aWandererB + RotL64(aIngress, 53U)) + 17583362781238061430U;
            aOrbiterD = (aWandererJ + RotL64(aPrevious, 39U)) + 4991442849150005943U;
            aOrbiterJ = (((aWandererG + RotL64(aScatter, 23U)) + 2891376254689854555U) + aPhaseFOrbiterAssignSaltA[((aIndex + 10U)) & S_SALT1]) + aNonceWordN;
            aOrbiterH = (aWandererC + RotL64(aCross, 34U)) + 10523274382407446239U;
            aOrbiterE = ((aWandererI + RotL64(aIngress, 29U)) + RotL64(aCarry, 13U)) + 3861893764676218667U;
            aOrbiterA = ((aWandererH + RotL64(aScatter, 47U)) + RotL64(aCarry, 21U)) + 3366674459852093746U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 5898492634386601145U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 7047353571244768721U;
            aOrbiterF = RotL64((aOrbiterF * 2257518291062508467U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 14374108805453186316U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 8763667021501226510U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 7694695426430267863U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 18261523829316379575U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 650477532238860965U;
            aOrbiterH = RotL64((aOrbiterH * 8291758490821819851U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 2162326554604894042U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 5776546692501825278U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 14911545784585246537U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 3501863793638415049U) + aNonceWordA;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 14853789267425352958U;
            aOrbiterB = RotL64((aOrbiterB * 10590325397179928739U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 15399673014671329743U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 12253428583438990426U;
            aOrbiterA = RotL64((aOrbiterA * 12052855472196447849U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 13202953937621953839U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 7547616636832698398U;
            aOrbiterK = RotL64((aOrbiterK * 9533399972562428073U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 15709801946594868318U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterH) ^ 12458677982746610971U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterI = RotL64((aOrbiterI * 6662570874316418993U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 6957370791367530127U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 10511379961344950861U;
            aOrbiterE = RotL64((aOrbiterE * 15551333099264031337U), 27U);
            //
            aIngress = RotL64(aOrbiterE, 57U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 43U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 28U));
            aIngress = aIngress + (RotL64(aOrbiterK, 47U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterH, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aIngress, 46U) + aOrbiterI) + RotL64(aOrbiterB, 43U)) + RotL64(aCarry, 13U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterH, 4U)) + aOrbiterE);
            aWandererB = aWandererB + ((RotL64(aPrevious, 41U) + aOrbiterJ) + RotL64(aOrbiterI, 27U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 37U) + RotL64(aOrbiterI, 39U)) + aOrbiterD) + aNonceWordH);
            aWandererE = aWandererE + ((((RotL64(aIngress, 51U) + RotL64(aOrbiterK, 51U)) + aOrbiterE) + aNonceWordB) + aPhaseFWandererUpdateSaltC[((aIndex + 29U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 14U) + aOrbiterE) + RotL64(aOrbiterA, 58U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterF, 11U)) + aOrbiterI) + aNonceWordC);
            aWandererF = aWandererF ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterJ, 35U)) + aOrbiterA);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 5U) + RotL64(aOrbiterB, 21U)) + aOrbiterH) + RotL64(aCarry, 39U)) + aPhaseFWandererUpdateSaltE[((aIndex + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 13U) ^ aWandererD);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 26U));
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererG, 35U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererC, 19U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aSnowLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_f loop 2
        // ingress from: aSnowLaneC, aOperationLaneC, aOperationLaneD, aInvestLaneA
        // ingress directions: aSnowLaneC forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aInvestLaneA forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aSnowLaneB
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aSnowLaneB backward/forward random
        // write to: aSnowLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneC[((aIndex + 6372U)) & S_BLOCK1], 44U) ^ RotL64(aOperationLaneC[((aIndex + 6164U)) & S_BLOCK1], 53U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 10248U)) & S_BLOCK1], 11U) ^ RotL64(aInvestLaneA[((aIndex + 8722U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 7818U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 9988U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aSnowLaneB[((aIndex + 8972U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCarry, 27U) ^ RotL64(aIngress, 12U)) + (RotL64(aCross, 57U) ^ RotL64(aPrevious, 43U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterA = (aWandererD + RotL64(aCross, 23U)) + 12535417189990029950U;
            aOrbiterK = (aWandererH + RotL64(aIngress, 56U)) + 6204401443676390273U;
            aOrbiterI = ((aWandererI + RotL64(aScatter, 35U)) + RotL64(aCarry, 41U)) + 869613505613154672U;
            aOrbiterJ = ((aWandererC + RotL64(aPrevious, 3U)) + 15053590879563855802U) + aPhaseFOrbiterAssignSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = ((aWandererF + RotL64(aCross, 11U)) + RotL64(aCarry, 11U)) + 13338989605204591428U;
            aOrbiterG = (aWandererA + RotL64(aScatter, 19U)) + 18306470022403825392U;
            aOrbiterC = (((aWandererG + RotL64(aIngress, 39U)) + RotL64(aCarry, 27U)) + 1150696349434090218U) + aNonceWordO;
            aOrbiterH = (((aWandererJ + RotL64(aPrevious, 50U)) + 13549541786420596437U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordD;
            aOrbiterF = ((aWandererK + RotL64(aScatter, 43U)) + 14302878430259588461U) + aNonceWordJ;
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 4660437084477165225U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 1653628537860912069U;
            aOrbiterI = RotL64((aOrbiterI * 2624835201155303123U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 5594199757006711631U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 11008472193138708891U) ^ aNonceWordM;
            aOrbiterG = RotL64((aOrbiterG * 13645764762027798301U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 3668516817279364310U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 128159531749679984U;
            aOrbiterK = RotL64((aOrbiterK * 4523246859249826987U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 6378674346113979108U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 11438762460659123362U;
            aOrbiterH = RotL64((aOrbiterH * 2733309638158283953U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 10624263004446482910U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 12546839706919241411U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 11468326687628079347U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 8466639576503293921U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 5828694979857951504U) ^ aNonceWordN;
            aOrbiterD = RotL64((aOrbiterD * 7835487310289634515U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 16496305151014092976U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 589464613876410567U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13190816610718051897U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 4168532743415647825U) + aNonceWordK;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 15944887793736489375U;
            aOrbiterC = RotL64((aOrbiterC * 17273403561158196717U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 11642456814106259483U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = (((aOrbiterA ^ aOrbiterD) ^ 1609897693632334867U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterA = RotL64((aOrbiterA * 12912773555616819941U), 57U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterI, 48U);
            aIngress = aIngress + (RotL64(aOrbiterC, 3U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 53U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 13U));
            aIngress = aIngress + RotL64(aOrbiterK, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 11U) + aOrbiterD) + RotL64(aOrbiterK, 47U));
            aWandererI = aWandererI + (((RotL64(aScatter, 29U) + RotL64(aOrbiterC, 19U)) + aOrbiterD) + aNonceWordL);
            aWandererF = aWandererF ^ (((RotL64(aCross, 41U) + RotL64(aOrbiterG, 5U)) + aOrbiterJ) + aPhaseFWandererUpdateSaltD[((aIndex + 16U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aIngress, 23U) + RotL64(aOrbiterJ, 28U)) + aOrbiterF);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 58U) + RotL64(aOrbiterI, 51U)) + aOrbiterJ);
            aWandererH = aWandererH + ((((RotL64(aIngress, 53U) + RotL64(aOrbiterK, 57U)) + aOrbiterF) + RotL64(aCarry, 23U)) + aNonceWordC);
            aWandererA = aWandererA ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterH, 43U)) + aOrbiterF);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 37U) + RotL64(aOrbiterH, 23U)) + aOrbiterA) + RotL64(aCarry, 43U)) + aPhaseFWandererUpdateSaltB[((aIndex + 25U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 46U) + RotL64(aOrbiterI, 38U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererF, 56U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererA);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 39U));
            aCarry = aCarry + (RotL64(aWandererG, 5U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererH, 35U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aSnowLaneD[((aIndex + 16216U)) & S_BLOCK1], 14U) ^ RotL64(aOperationLaneA[((aIndex + 13386U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 12265U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 16140U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 13659U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCross, 28U) ^ RotL64(aPrevious, 11U)) + (RotL64(aIngress, 43U) ^ RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterD = ((aWandererA + RotL64(aPrevious, 39U)) + RotL64(aCarry, 3U)) + 11998579547770778580U;
            aOrbiterJ = ((aWandererJ + RotL64(aCross, 11U)) + 8409465187298704610U) + aNonceWordJ;
            aOrbiterF = ((aWandererF + RotL64(aScatter, 34U)) + 3470222286110333500U) + aNonceWordG;
            aOrbiterE = (aWandererK + RotL64(aIngress, 3U)) + 5704486785203069994U;
            aOrbiterC = (((aWandererG + RotL64(aCross, 53U)) + RotL64(aCarry, 23U)) + 10334944660253279633U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = (((aWandererC + RotL64(aScatter, 43U)) + RotL64(aCarry, 39U)) + 7626852700722567477U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = (aWandererB + RotL64(aIngress, 30U)) + 14631310754943209743U;
            aOrbiterB = (aWandererI + RotL64(aPrevious, 23U)) + 807160297237854120U;
            aOrbiterG = (aWandererH + RotL64(aIngress, 19U)) + 5624154783624196107U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 4971444394698940423U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 6340057638461027062U;
            aOrbiterF = RotL64((aOrbiterF * 12027586111086798629U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 9003019862787819481U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 13632057463595873033U;
            aOrbiterC = RotL64((aOrbiterC * 12575202147280216765U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 12766104026871797746U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 4062118445824915939U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13130770039048080701U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 5258212525426469978U) + aNonceWordP;
            aOrbiterE = (((aOrbiterE ^ aOrbiterJ) ^ 9956946981015983939U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterE = RotL64((aOrbiterE * 8106382657040497669U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 10837606223056473999U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 13292864885504191134U) ^ aNonceWordB;
            aOrbiterD = RotL64((aOrbiterD * 4445739587553669471U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 166087925900318658U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 6786842221885441388U;
            aOrbiterH = RotL64((aOrbiterH * 4411147600413147773U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 16888086378070246404U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 5240855484445974002U) ^ aNonceWordC;
            aOrbiterG = RotL64((aOrbiterG * 402652898573422271U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 6874866669211571608U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 732890824978127460U;
            aOrbiterB = RotL64((aOrbiterB * 3776365957702257453U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 5541380495707308058U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 17947326584411475765U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 10920952349981652899U), 43U);
            //
            aIngress = RotL64(aOrbiterH, 36U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterF, 47U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 5U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 39U));
            aIngress = aIngress + RotL64(aOrbiterJ, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterK, 29U)) + aOrbiterH);
            aWandererH = aWandererH + ((RotL64(aScatter, 3U) + aOrbiterG) + RotL64(aOrbiterF, 35U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 12U) + RotL64(aOrbiterJ, 3U)) + aOrbiterD);
            aWandererK = aWandererK + (((RotL64(aIngress, 47U) + aOrbiterJ) + RotL64(aOrbiterF, 52U)) + aPhaseFWandererUpdateSaltA[((aIndex + 11U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 23U) + RotL64(aOrbiterE, 23U)) + aOrbiterF) + aNonceWordI);
            aWandererC = aWandererC + ((((RotL64(aScatter, 43U) + aOrbiterD) + RotL64(aOrbiterC, 43U)) + RotL64(aCarry, 21U)) + aNonceWordK);
            aWandererA = aWandererA ^ (((RotL64(aCross, 58U) + aOrbiterB) + RotL64(aOrbiterF, 19U)) + aPhaseFWandererUpdateSaltF[((aIndex + 28U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 51U) + RotL64(aOrbiterC, 13U)) + aOrbiterB) + RotL64(aCarry, 53U)) + aNonceWordF);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 39U) + RotL64(aOrbiterH, 56U)) + aOrbiterC) + aNonceWordM);
            //
            aCarry = aCarry + (RotL64(aWandererH, 57U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererF, 35U) ^ aWandererC);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 54U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 43U));
            aCarry = aCarry + RotL64(aWandererG, 39U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_f loop 4
        // ingress from: aExpandLaneA, aSnowLaneC, aInvestLaneB
        // ingress directions: aExpandLaneA forward forced, aSnowLaneC forward forced, aInvestLaneB forward/backward random
        // cross from: aSnowLaneD, aOperationLaneD
        // cross directions: aSnowLaneD backward forced, aOperationLaneD backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 18972U)) & S_BLOCK1], 57U) ^ RotL64(aSnowLaneC[((aIndex + 20194U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 16780U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 16976U)) & S_BLOCK1], 42U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 20675U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCross, 29U) + RotL64(aPrevious, 44U)) ^ (RotL64(aIngress, 57U) + RotL64(aCarry, 13U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterE = (aWandererF + RotL64(aIngress, 57U)) + 16124889768301047791U;
            aOrbiterH = (((aWandererA + RotL64(aCross, 51U)) + 11912338587186717280U) + aPhaseFOrbiterAssignSaltA[((aIndex + 4U)) & S_SALT1]) + aNonceWordN;
            aOrbiterG = ((((aWandererE + RotL64(aScatter, 6U)) + RotL64(aCarry, 57U)) + 8594012868813114354U) + aPhaseFOrbiterAssignSaltC[((aIndex + 29U)) & S_SALT1]) + aNonceWordG;
            aOrbiterB = (aWandererH + RotL64(aPrevious, 35U)) + 18281043566156682815U;
            aOrbiterA = (aWandererC + RotL64(aIngress, 41U)) + 16853106130200942302U;
            aOrbiterC = (aWandererI + RotL64(aScatter, 47U)) + 2611212958619673086U;
            aOrbiterI = (((aWandererJ + RotL64(aPrevious, 13U)) + RotL64(aCarry, 43U)) + 18039472325066855180U) + aNonceWordF;
            aOrbiterD = ((aWandererG + RotL64(aCross, 28U)) + 14495785571345122046U) + aNonceWordC;
            aOrbiterJ = ((aWandererD + RotL64(aIngress, 21U)) + RotL64(aCarry, 21U)) + 4556063793412832418U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 14896419970271244358U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 880028529183500036U) ^ aNonceWordL;
            aOrbiterG = RotL64((aOrbiterG * 14228281807461251361U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 2379557167489415783U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 11854373946064529806U;
            aOrbiterE = RotL64((aOrbiterE * 150755294320438887U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 1487252775956449964U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 12777924204511625545U;
            aOrbiterH = RotL64((aOrbiterH * 1366019527386994789U), 13U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterI) + 15998631485222477969U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordH;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 8864212892296191613U;
            aOrbiterB = RotL64((aOrbiterB * 579242788050369815U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 17069347835763226743U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 7443008171694679791U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 748894368884566607U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 17334256152350782002U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 8986626119086556393U;
            aOrbiterI = RotL64((aOrbiterI * 2258172145924120235U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 8528180968228358674U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 12702290928064582589U;
            aOrbiterC = RotL64((aOrbiterC * 15673603224146737631U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 7742438100860023610U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 3729687240959702198U;
            aOrbiterD = RotL64((aOrbiterD * 3756794766163746783U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 426129097367382096U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 16782175452274911213U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 1041477289638333659U), 43U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterE, 43U);
            aIngress = aIngress + (RotL64(aOrbiterB, 53U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 18U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 47U));
            aIngress = aIngress + RotL64(aOrbiterG, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aScatter, 18U) + aOrbiterI) + RotL64(aOrbiterH, 5U)) + RotL64(aCarry, 27U)) + aPhaseFWandererUpdateSaltC[((aIndex + 5U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aCross, 37U) + RotL64(aOrbiterB, 21U)) + aOrbiterI) + aNonceWordI);
            aWandererE = aWandererE + (((RotL64(aPrevious, 23U) + RotL64(aOrbiterI, 26U)) + aOrbiterC) + RotL64(aCarry, 13U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 53U) + RotL64(aOrbiterI, 39U)) + aOrbiterG) + aNonceWordE);
            aWandererH = aWandererH + ((RotL64(aScatter, 43U) + aOrbiterG) + RotL64(aOrbiterE, 47U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 29U) + aOrbiterA) + RotL64(aOrbiterE, 43U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 47U) + RotL64(aOrbiterD, 30U)) + aOrbiterC) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterG, 53U)) + aOrbiterJ);
            aWandererF = aWandererF + (((RotL64(aCross, 14U) + RotL64(aOrbiterI, 57U)) + aOrbiterA) + aNonceWordO);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 3U));
            aCarry = aCarry + (RotL64(aWandererE, 54U) ^ aWandererH);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 57U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 35U));
            aCarry = aCarry + RotL64(aWandererJ, 13U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_f loop 5
        // ingress from: aExpandLaneB, aSnowLaneD, aWorkLaneC
        // ingress directions: aExpandLaneB forward forced, aSnowLaneD forward forced, aWorkLaneC forward/backward random
        // cross from: aExpandLaneA, aSnowLaneC
        // cross directions: aExpandLaneA backward forced, aSnowLaneC backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 27015U)) & S_BLOCK1], 23U) ^ RotL64(aSnowLaneD[((aIndex + 23211U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 22340U)) & S_BLOCK1], 60U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 26093U)) & S_BLOCK1], 35U) ^ RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 26451U)) & S_BLOCK1], 56U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aIngress, 37U) + RotL64(aCarry, 23U)) ^ (RotL64(aCross, 3U) ^ RotL64(aPrevious, 52U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterG = ((aWandererJ + RotL64(aScatter, 57U)) + RotL64(aCarry, 21U)) + 13278949403988203974U;
            aOrbiterC = ((aWandererK + RotL64(aPrevious, 42U)) + 9213599924054673756U) + aPhaseFOrbiterAssignSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterD = (aWandererF + RotL64(aIngress, 19U)) + 1255746482932381798U;
            aOrbiterI = ((aWandererA + RotL64(aCross, 29U)) + 11575321997144516122U) + aNonceWordF;
            aOrbiterB = (aWandererI + RotL64(aPrevious, 3U)) + 15881587525529432437U;
            aOrbiterF = ((aWandererC + RotL64(aCross, 11U)) + 9846195809864862707U) + aNonceWordO;
            aOrbiterH = (((aWandererE + RotL64(aIngress, 46U)) + RotL64(aCarry, 3U)) + 12319815691858217670U) + aNonceWordE;
            aOrbiterA = (aWandererG + RotL64(aScatter, 51U)) + 16322617427294439587U;
            aOrbiterE = ((((aWandererB + RotL64(aCross, 23U)) + RotL64(aCarry, 11U)) + 16332130810525887437U) + aPhaseFOrbiterAssignSaltE[((aIndex + 9U)) & S_SALT1]) + aNonceWordJ;
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 4920951156015336794U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 16767126455124552329U;
            aOrbiterD = RotL64((aOrbiterD * 4440352337076842603U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 12553595911087945223U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 1437522202135436142U;
            aOrbiterB = RotL64((aOrbiterB * 2001992794165550905U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 12313100454852227143U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 2761983020631055729U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3874839760378039509U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 17635303588421554367U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = (((aOrbiterG ^ aOrbiterH) ^ 788212489507463763U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterG = RotL64((aOrbiterG * 17896475584538528059U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 5192552894670654434U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 6784748488807738811U;
            aOrbiterI = RotL64((aOrbiterI * 8077237651953896479U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 16113417046719114943U) + aNonceWordL;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 1096874945215225916U;
            aOrbiterA = RotL64((aOrbiterA * 17308604412622879833U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 7610274704570171595U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 10466070212284342550U;
            aOrbiterE = RotL64((aOrbiterE * 6449728258497920613U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 6777845928873855221U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 5251515022021984126U;
            aOrbiterH = RotL64((aOrbiterH * 9018277343404261611U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 13849343158824111498U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 7977711210181714021U;
            aOrbiterC = RotL64((aOrbiterC * 4182053966171053577U), 23U);
            //
            aIngress = RotL64(aOrbiterC, 53U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterH, 24U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 47U));
            aIngress = aIngress + (RotL64(aOrbiterG, 39U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterI, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aIngress, 3U) + RotL64(aOrbiterG, 29U)) + aOrbiterD);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterF, 51U)) + aOrbiterB);
            aWandererA = aWandererA + ((((RotL64(aScatter, 14U) + RotL64(aOrbiterF, 18U)) + aOrbiterE) + aNonceWordA) + aPhaseFWandererUpdateSaltD[((aIndex + 25U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 39U) + aOrbiterI) + RotL64(aOrbiterG, 57U));
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 43U) + aOrbiterE) + RotL64(aOrbiterH, 47U)) + RotL64(aCarry, 47U)) + aNonceWordC);
            aWandererI = aWandererI ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterB, 37U)) + aOrbiterG);
            aWandererB = aWandererB + ((RotL64(aPrevious, 60U) + RotL64(aOrbiterC, 23U)) + aOrbiterH);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterC, 41U)) + aOrbiterA);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 19U) + aOrbiterC) + RotL64(aOrbiterI, 10U)) + RotL64(aCarry, 37U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 29U) ^ aWandererI);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 56U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 3U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 51U));
            aCarry = aCarry + RotL64(aWandererF, 35U);
            aCarry = aCarry + RotL64(aIngress, 60U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_f loop 6
        // ingress from: aExpandLaneC, aExpandLaneA, aInvestLaneC
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aInvestLaneC forward/backward random
        // cross from: aExpandLaneB, aOperationLaneB
        // cross directions: aExpandLaneB backward forced, aOperationLaneB backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 29094U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneA[((aIndex + 31471U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 30688U)) & S_BLOCK1], 6U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordD));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27549U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneB[((aIndex + 28391U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aPrevious, 20U) ^ RotL64(aCross, 3U)) ^ (RotL64(aIngress, 53U) + RotL64(aCarry, 35U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterK = (aWandererJ + RotL64(aCross, 5U)) + 16200278595895089008U;
            aOrbiterA = ((aWandererG + RotL64(aScatter, 11U)) + RotL64(aCarry, 29U)) + 1029614154810465897U;
            aOrbiterH = (aWandererI + RotL64(aPrevious, 23U)) + 7129562468705441295U;
            aOrbiterE = ((((aWandererC + RotL64(aIngress, 48U)) + RotL64(aCarry, 51U)) + 14388903902433951274U) + aPhaseFOrbiterAssignSaltF[((aIndex + 19U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterD = (aWandererB + RotL64(aPrevious, 27U)) + 1013568949315967455U;
            aOrbiterG = (((aWandererA + RotL64(aCross, 37U)) + RotL64(aCarry, 13U)) + 3128823373497815651U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = ((aWandererF + RotL64(aIngress, 41U)) + 14525694606889470589U) + aNonceWordK;
            aOrbiterI = ((aWandererK + RotL64(aScatter, 53U)) + 14443983602196782887U) + aNonceWordA;
            aOrbiterJ = (aWandererH + RotL64(aIngress, 60U)) + 12244220415328641190U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 10477159225338766614U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 2842870123078131566U) ^ aNonceWordP;
            aOrbiterH = RotL64((aOrbiterH * 11522265477555954071U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 8621138818955849917U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 5038396344400303181U;
            aOrbiterD = RotL64((aOrbiterD * 14636756322207385447U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 2768613802894372496U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 2027754864051410015U;
            aOrbiterC = RotL64((aOrbiterC * 2461322540050569287U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 2848088309172056399U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 15017458513904884651U;
            aOrbiterK = RotL64((aOrbiterK * 9926904679902843055U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 9079797279596336139U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 15424866642305110811U) ^ aNonceWordO;
            aOrbiterJ = RotL64((aOrbiterJ * 12912331089970158845U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 13751764050290602740U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 7694557131324740282U) ^ aNonceWordB;
            aOrbiterI = RotL64((aOrbiterI * 14980807690491467023U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 3508673897305667669U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = (((aOrbiterG ^ aOrbiterE) ^ 3600868397311393233U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterG = RotL64((aOrbiterG * 5165032044164139165U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 1222655844979128996U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 2257342337168905875U;
            aOrbiterE = RotL64((aOrbiterE * 6198995971182272119U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 6290990717563682725U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 15308494772443447109U;
            aOrbiterA = RotL64((aOrbiterA * 1925593111157842325U), 5U);
            //
            aIngress = RotL64(aOrbiterE, 54U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 13U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 27U));
            aIngress = aIngress + (RotL64(aOrbiterG, 41U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterC, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aPrevious, 53U) + RotL64(aOrbiterJ, 51U)) + aOrbiterC);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 19U) + aOrbiterK) + RotL64(aOrbiterA, 35U)) + aNonceWordH);
            aWandererB = aWandererB + ((RotL64(aScatter, 39U) + aOrbiterK) + RotL64(aOrbiterE, 4U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 23U) + aOrbiterI) + RotL64(aOrbiterD, 43U)) + aNonceWordC);
            aWandererH = aWandererH + ((((RotL64(aScatter, 46U) + RotL64(aOrbiterI, 39U)) + aOrbiterA) + RotL64(aCarry, 53U)) + aPhaseFWandererUpdateSaltF[((aIndex + 11U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 3U) + aOrbiterG) + RotL64(aOrbiterK, 57U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aCross, 29U) + aOrbiterA) + RotL64(aOrbiterJ, 23U)) + RotL64(aCarry, 39U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 35U) + RotL64(aOrbiterH, 28U)) + aOrbiterG) + aNonceWordE);
            aWandererK = aWandererK + (((RotL64(aPrevious, 60U) + aOrbiterE) + RotL64(aOrbiterA, 19U)) + aNonceWordG);
            //
            aCarry = aCarry + (RotL64(aWandererG, 57U) ^ aWandererC);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 39U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 44U));
            aCarry = aCarry + (RotL64(aWandererI, 35U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererF, 51U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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

void TwistExpander_Hockey_Arx::Seed_G(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xFF58088BF9770A23ULL + 0x84B4B86A4E7AE751ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x8387F950DBC136ADULL + 0xB6E7866412691882ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x925BBCD603C6256FULL + 0xA4AAED5C823AC959ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xA7CBC812F34422F5ULL + 0x80600DCE78E1B920ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x8B1C539ABF179277ULL + 0x9994043E586595B1ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xD86F703744E6E147ULL + 0x8C453805CAC86BA5ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xBCF0102C307E0D93ULL + 0xD8209CA80192DFA5ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xCD30C8922A50ADF9ULL + 0x904C3FD74060DA42ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xF6393C584D2F1ABFULL + 0xC974D3056C074C71ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x886BACA29C933D21ULL + 0xB6A923EF43B49D9CULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xA93E4F781A816459ULL + 0xC35617B024CCF672ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0x9983DA8BCF05D3C9ULL + 0xB40D4C463D944FA4ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x9F11DE4578265E01ULL + 0xC57FB087EFEBE8D1ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x81FA02807450FFABULL + 0x8B0EAAD6E23DDDDAULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xD6DAF544B1802BE7ULL + 0x921BDC0A21E3AFC3ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xC7868BCDB9F13F5DULL + 0x8B24EF8640B72FDFULL);
    // GSeedRunSeed_G seed_loop_h (start)
    {
        // GSeedRunSeed_G seed_loop_h lane group
        // read from: aSnowLaneA, aSnowLaneB, aFireLaneC, aSnowLaneC, aSnowLaneD, aFireLaneD, aWorkLaneA, aInvestLaneA, aFireLaneB, aWorkLaneB, aFireLaneA, aExpandLaneA, aInvestLaneD, aExpandLaneB, aInvestLaneB, aExpandLaneC, aInvestLaneC
        // write to: aWorkLaneA, aWorkLaneB, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // seed_loop_h loop 1
        // ingress from: aSnowLaneA, aSnowLaneB, aFireLaneC
        // ingress directions: aSnowLaneA forward forced, aSnowLaneB forward forced, aFireLaneC forward/backward random
        // cross from: aSnowLaneC, aSnowLaneD, aFireLaneD
        // cross directions: aSnowLaneC backward forced, aSnowLaneD backward forced, aFireLaneD backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneA[((aIndex + 4926U)) & S_BLOCK1], 21U) ^ RotL64(aSnowLaneB[((aIndex + 4757U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 2411U)) & S_BLOCK1], 6U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 3965U)) & S_BLOCK1], 21U) ^ RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 4880U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 4374U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aPrevious, 56U) + RotL64(aCarry, 41U)) + (RotL64(aIngress, 29U) ^ RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterG = (aWandererI + RotL64(aCross, 47U)) + 9855743441035905047U;
            aOrbiterJ = (((aWandererD + RotL64(aPrevious, 23U)) + RotL64(aCarry, 23U)) + 8426286937143990276U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterI = (((aWandererH + RotL64(aIngress, 53U)) + 7146752367170267002U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordE;
            aOrbiterD = (aWandererE + RotL64(aScatter, 41U)) + 12947210066678101726U;
            aOrbiterB = ((aWandererF + RotL64(aIngress, 35U)) + RotL64(aCarry, 39U)) + 15902163559925328965U;
            aOrbiterH = ((aWandererA + RotL64(aCross, 29U)) + 8506649889346449469U) + aNonceWordP;
            aOrbiterF = ((aWandererK + RotL64(aScatter, 4U)) + RotL64(aCarry, 53U)) + 8226286036430263052U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 2703047093452420216U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 6769351326360139560U;
            aOrbiterI = RotL64((aOrbiterI * 5318104980014706265U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 9857025533281333281U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 238297452132277585U;
            aOrbiterG = RotL64((aOrbiterG * 12974709749856065985U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 7203572312072908931U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 12497027346166575632U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 1703586436725662307U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 473851890609048879U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 1664484956453886047U;
            aOrbiterD = RotL64((aOrbiterD * 8566500756326590209U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 4635095143004754116U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 17695676150967345793U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 5780416541584439301U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 15628965269863402796U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterI) ^ 9190117464399730235U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 10U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterB = RotL64((aOrbiterB * 5586437438425999715U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 17835918238346011086U) + aNonceWordL;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 4398005402429282682U;
            aOrbiterF = RotL64((aOrbiterF * 14828737209913317463U), 51U);
            //
            aIngress = RotL64(aOrbiterD, 3U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 57U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 37U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterI, 22U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aScatter, 23U) + aOrbiterG) + RotL64(aOrbiterH, 11U)) + aNonceWordC);
            aWandererI = aWandererI + ((RotL64(aIngress, 47U) + RotL64(aOrbiterI, 47U)) + aOrbiterG);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 60U) + RotL64(aOrbiterB, 3U)) + aOrbiterF) + aNonceWordI);
            aWandererD = aWandererD + (((RotL64(aCross, 13U) + RotL64(aOrbiterJ, 29U)) + aOrbiterH) + RotL64(aCarry, 5U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 3U) + aOrbiterD) + RotL64(aOrbiterJ, 22U));
            aWandererF = aWandererF + (((((RotL64(aScatter, 37U) + RotL64(aOrbiterI, 39U)) + aOrbiterH) + RotL64(aCarry, 57U)) + aNonceWordG) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 53U) + RotL64(aOrbiterB, 57U)) + aOrbiterD) + aPhaseHWandererUpdateSaltB[((aIndex + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 35U));
            aCarry = aCarry + (RotL64(aWandererH, 41U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererE, 60U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_h loop 2
        // ingress from: aWorkLaneA, aSnowLaneC, aSnowLaneD, aInvestLaneA
        // ingress directions: aWorkLaneA forward forced, aSnowLaneC forward forced, aSnowLaneD forward forced, aInvestLaneA forward/backward random
        // cross from: aSnowLaneA, aSnowLaneB, aFireLaneB
        // cross directions: aSnowLaneA backward forced, aSnowLaneB backward forced, aFireLaneB backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 6726U)) & S_BLOCK1], 11U) ^ RotL64(aSnowLaneC[((aIndex + 10124U)) & S_BLOCK1], 30U));
            aIngress ^= (RotL64(aSnowLaneD[((aIndex + 6051U)) & S_BLOCK1], 3U) ^ RotL64(aInvestLaneA[((aIndex + 8436U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 5496U)) & S_BLOCK1], 11U) ^ RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 10347U)) & S_BLOCK1], 60U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 5590U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aIngress, 3U) ^ RotL64(aCarry, 53U)) ^ (RotL64(aCross, 38U) + RotL64(aPrevious, 21U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterJ = (aWandererF + RotL64(aScatter, 5U)) + 12426357877879529292U;
            aOrbiterH = ((((aWandererC + RotL64(aIngress, 57U)) + RotL64(aCarry, 37U)) + 12604900366173639176U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordN;
            aOrbiterG = ((aWandererE + RotL64(aCross, 29U)) + RotL64(aCarry, 3U)) + 13511119007338929401U;
            aOrbiterK = (aWandererB + RotL64(aPrevious, 19U)) + 9878720081166788060U;
            aOrbiterB = (((aWandererA + RotL64(aScatter, 11U)) + RotL64(aCarry, 51U)) + 15463195409806395076U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = ((aWandererJ + RotL64(aIngress, 46U)) + 6407922778852833423U) + aNonceWordP;
            aOrbiterF = (aWandererD + RotL64(aPrevious, 35U)) + 7690427254160734016U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 18030974031722143619U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 17983938038322737041U;
            aOrbiterG = RotL64((aOrbiterG * 12479365337221685413U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 16605512170117753884U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 681802273302348322U;
            aOrbiterH = RotL64((aOrbiterH * 14608920184802647123U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 15550312921312083819U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 17824154101711884508U) ^ aNonceWordJ;
            aOrbiterK = RotL64((aOrbiterK * 7358612830654795357U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 1939207786756735430U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 3132864634777826569U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 13606281919426730325U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 12822929773923954849U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 16576106045887115660U) ^ aNonceWordG;
            aOrbiterJ = RotL64((aOrbiterJ * 16370914370769903051U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 2398825881649235260U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterH) ^ 13700821892926092479U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterF = RotL64((aOrbiterF * 10830623703416956043U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 2439833784883391606U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 15870638514107637833U;
            aOrbiterB = RotL64((aOrbiterB * 3797380922767479287U), 35U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterF, 18U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 5U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 47U));
            aIngress = aIngress + RotL64(aOrbiterK, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 13U) + RotL64(aOrbiterB, 13U)) + aOrbiterG) + aNonceWordF);
            aWandererD = aWandererD + (((RotL64(aIngress, 53U) + aOrbiterK) + RotL64(aOrbiterH, 29U)) + RotL64(aCarry, 13U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 5U) + RotL64(aOrbiterB, 51U)) + aOrbiterC) + aNonceWordD);
            aWandererC = aWandererC + (((RotL64(aScatter, 47U) + RotL64(aOrbiterJ, 35U)) + aOrbiterB) + RotL64(aCarry, 41U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 35U) + aOrbiterF) + RotL64(aOrbiterC, 6U)) + aNonceWordA);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 22U) + aOrbiterH) + RotL64(aOrbiterF, 57U)) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((((RotL64(aPrevious, 41U) + RotL64(aOrbiterH, 19U)) + aOrbiterC) + aNonceWordL) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 30U) ^ aWandererA);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 43U));
            aCarry = aCarry + (RotL64(aWandererE, 35U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererD, 21U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_h loop 3
        // ingress from: aWorkLaneB, aSnowLaneA, aFireLaneA
        // ingress directions: aWorkLaneB forward forced, aSnowLaneA forward forced, aFireLaneA forward/backward random
        // cross from: aWorkLaneA, aSnowLaneC
        // cross directions: aWorkLaneA backward forced, aSnowLaneC backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 13292U)) & S_BLOCK1], 41U) ^ RotL64(aSnowLaneA[((aIndex + 13829U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 11335U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 15976U)) & S_BLOCK1], 48U) ^ RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 12924U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCross, 37U) ^ RotL64(aPrevious, 5U)) ^ (RotL64(aCarry, 54U) + RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterH = ((aWandererK + RotL64(aPrevious, 30U)) + 1457104756581596530U) + aNonceWordB;
            aOrbiterF = ((aWandererE + RotL64(aCross, 57U)) + 6127240317844622874U) + aNonceWordM;
            aOrbiterC = (aWandererB + RotL64(aScatter, 43U)) + 16492290056044189421U;
            aOrbiterK = ((aWandererF + RotL64(aIngress, 37U)) + RotL64(aCarry, 5U)) + 10963676850938416468U;
            aOrbiterE = (((aWandererD + RotL64(aScatter, 21U)) + 4872917367399752405U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordI;
            aOrbiterD = ((((aWandererG + RotL64(aCross, 5U)) + RotL64(aCarry, 21U)) + 15218882377875616148U) + aPhaseHOrbiterAssignSaltE[((aIndex + 13U)) & S_SALT1]) + aNonceWordE;
            aOrbiterG = ((aWandererC + RotL64(aPrevious, 51U)) + RotL64(aCarry, 41U)) + 5934166612122118251U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 14215280930872003003U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 11428034799044600979U;
            aOrbiterC = RotL64((aOrbiterC * 12162528943733976177U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 5453003654321728726U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterF) ^ 14273775120265649389U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterK = RotL64((aOrbiterK * 5139018128323795309U), 21U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 328723770018440271U) + aNonceWordN;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 13032190719588211088U;
            aOrbiterF = RotL64((aOrbiterF * 13363368478932798315U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 2386881543033598494U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterC) ^ 1649501123340887116U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterD = RotL64((aOrbiterD * 11148976582360499033U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 16462401546754210583U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 1510579201823042227U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 16287912400104043275U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 6889066000014251983U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 11324594596597724357U;
            aOrbiterH = RotL64((aOrbiterH * 15344987814648586023U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 12237796033168436537U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 17306069670330000343U;
            aOrbiterE = RotL64((aOrbiterE * 3167451351403385259U), 35U);
            //
            aIngress = RotL64(aOrbiterC, 19U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 13U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 51U));
            aIngress = aIngress + RotL64(aOrbiterE, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aCross, 19U) + aOrbiterK) + RotL64(aOrbiterD, 13U));
            aWandererF = aWandererF + ((RotL64(aIngress, 13U) + RotL64(aOrbiterK, 57U)) + aOrbiterF);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 53U) + aOrbiterE) + RotL64(aOrbiterG, 21U));
            aWandererB = aWandererB + (((((RotL64(aScatter, 47U) + aOrbiterF) + RotL64(aOrbiterC, 34U)) + RotL64(aCarry, 23U)) + aNonceWordC) + aPhaseHWandererUpdateSaltC[((aIndex + 21U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 27U) + aOrbiterH) + RotL64(aOrbiterC, 27U)) + aNonceWordP);
            aWandererD = aWandererD + (((RotL64(aPrevious, 40U) + aOrbiterD) + RotL64(aOrbiterE, 3U)) + RotL64(aCarry, 53U));
            aWandererC = aWandererC ^ ((((RotL64(aScatter, 3U) + RotL64(aOrbiterE, 41U)) + aOrbiterF) + aNonceWordK) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 35U) ^ aWandererG);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 19U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 41U));
            aCarry = aCarry + RotL64(aWandererK, 60U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_h loop 4
        // ingress from: aExpandLaneA, aWorkLaneA, aInvestLaneD
        // ingress directions: aExpandLaneA forward forced, aWorkLaneA forward forced, aInvestLaneD forward/backward random
        // cross from: aWorkLaneB, aSnowLaneD
        // cross directions: aWorkLaneB backward forced, aSnowLaneD backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 18159U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneA[((aIndex + 20670U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aInvestLaneD[((aIndex + 20150U)) & S_BLOCK1], 44U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordA));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 21048U)) & S_BLOCK1], 3U) ^ RotL64(aSnowLaneD[((aIndex + 21062U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCarry, 43U) ^ RotL64(aIngress, 29U)) ^ (RotL64(aCross, 13U) + RotL64(aPrevious, 60U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterD = (aWandererB + RotL64(aScatter, 3U)) + 12690502671561165478U;
            aOrbiterH = ((((aWandererG + RotL64(aCross, 56U)) + RotL64(aCarry, 37U)) + 17519943923428102801U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordH;
            aOrbiterF = ((aWandererK + RotL64(aPrevious, 37U)) + RotL64(aCarry, 53U)) + 10705515807975331385U;
            aOrbiterE = ((aWandererD + RotL64(aIngress, 21U)) + RotL64(aCarry, 11U)) + 16586447272278538179U;
            aOrbiterC = ((aWandererA + RotL64(aScatter, 43U)) + 8006560996840971798U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = ((aWandererH + RotL64(aCross, 29U)) + 12928600185788857701U) + aNonceWordF;
            aOrbiterI = ((aWandererI + RotL64(aIngress, 13U)) + 14240723153798267172U) + aNonceWordM;
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 8636219177994872072U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 7586790235186467512U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 15052686382507614169U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 1103807034179512424U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 7547526530239498693U;
            aOrbiterC = RotL64((aOrbiterC * 3360295583636013509U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 8380239679344786397U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 5690809173787433519U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 5354724308093372953U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 8390902801141804609U) + aNonceWordK;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 3507306189192059486U;
            aOrbiterJ = RotL64((aOrbiterJ * 18336280496510253103U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 6190745292098482871U) + aNonceWordP;
            aOrbiterH = (((aOrbiterH ^ aOrbiterI) ^ 8065418693975056902U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterH = RotL64((aOrbiterH * 6414621418430102589U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 12111755051718111803U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 7605877769709909297U;
            aOrbiterI = RotL64((aOrbiterI * 17525248694315944599U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 5969794501112646237U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 5127559299360591476U;
            aOrbiterE = RotL64((aOrbiterE * 4521563633438853069U), 41U);
            //
            aIngress = RotL64(aOrbiterF, 57U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterJ, 5U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterD, 21U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterI, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aIngress, 18U) + RotL64(aOrbiterJ, 13U)) + aOrbiterI) + RotL64(aCarry, 29U)) + aPhaseHWandererUpdateSaltB[((aIndex + 11U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 41U) + RotL64(aOrbiterE, 21U)) + aOrbiterC) + aNonceWordI);
            aWandererK = aWandererK + ((RotL64(aCross, 47U) + RotL64(aOrbiterD, 5U)) + aOrbiterJ);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 5U) + aOrbiterD) + RotL64(aOrbiterI, 37U)) + aPhaseHWandererUpdateSaltE[((aIndex + 27U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aIngress, 35U) + aOrbiterH) + RotL64(aOrbiterE, 50U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 53U) + RotL64(aOrbiterI, 57U)) + aOrbiterC) + aNonceWordD);
            aWandererB = aWandererB + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterC, 43U)) + aOrbiterF) + RotL64(aCarry, 43U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 60U) ^ aWandererK);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 47U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 29U));
            aCarry = aCarry + RotL64(aWandererB, 51U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_h loop 5
        // ingress from: aExpandLaneB, aWorkLaneB, aInvestLaneB
        // ingress directions: aExpandLaneB forward forced, aWorkLaneB forward forced, aInvestLaneB forward/backward random
        // cross from: aExpandLaneA, aWorkLaneA
        // cross directions: aExpandLaneA backward forced, aWorkLaneA backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 26923U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((aIndex + 25620U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 22828U)) & S_BLOCK1], 30U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 26735U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23057U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aPrevious, 57U) + RotL64(aCarry, 14U)) ^ (RotL64(aIngress, 41U) ^ RotL64(aCross, 27U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterG = (((aWandererE + RotL64(aCross, 57U)) + RotL64(aCarry, 35U)) + 4384716820085860551U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterD = (((aWandererK + RotL64(aScatter, 3U)) + RotL64(aCarry, 5U)) + 9715780315942116888U) + aNonceWordG;
            aOrbiterK = ((aWandererD + RotL64(aPrevious, 19U)) + 15963520052789178632U) + aNonceWordK;
            aOrbiterC = ((aWandererH + RotL64(aIngress, 35U)) + 14346700690686392938U) + aNonceWordE;
            aOrbiterB = ((aWandererA + RotL64(aPrevious, 29U)) + 6005518012489966643U) + aNonceWordP;
            aOrbiterH = (aWandererI + RotL64(aCross, 50U)) + 2506732930310252119U;
            aOrbiterE = (((aWandererB + RotL64(aIngress, 13U)) + RotL64(aCarry, 21U)) + 16782163084851775826U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 823673076571076303U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 1634084509064077736U) ^ aNonceWordH;
            aOrbiterK = RotL64((aOrbiterK * 1128407326773234517U), 13U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterC) + 1288134975466877686U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordD;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 2998220403162908444U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4321412662318298283U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 220430672180734911U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 10223923547068528867U;
            aOrbiterH = RotL64((aOrbiterH * 12577370238343872139U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 11696469696177647608U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 6545430420379636963U;
            aOrbiterE = RotL64((aOrbiterE * 8387163146257553773U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 79691451831797107U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 8971444023498649419U;
            aOrbiterC = RotL64((aOrbiterC * 7148919880477390009U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 5624403902454498793U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 9468064161002030997U;
            aOrbiterD = RotL64((aOrbiterD * 8243560528100864595U), 43U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterE) + 4619361544913629805U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1]) + aNonceWordI;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 12682446273369750704U) ^ aNonceWordO;
            aOrbiterG = RotL64((aOrbiterG * 10879074713156075641U), 37U);
            //
            aIngress = RotL64(aOrbiterE, 37U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 51U));
            aIngress = aIngress + (RotL64(aOrbiterH, 43U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterK, 12U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aIngress, 19U) + RotL64(aOrbiterE, 14U)) + aOrbiterD) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 37U) + aOrbiterG) + RotL64(aOrbiterK, 35U)) + RotL64(aCarry, 19U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 29U) + aOrbiterG) + RotL64(aOrbiterB, 5U));
            aWandererI = aWandererI + ((((RotL64(aCross, 11U) + aOrbiterK) + RotL64(aOrbiterB, 57U)) + aNonceWordA) + aPhaseHWandererUpdateSaltD[((aIndex + 25U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 44U) + aOrbiterC) + RotL64(aOrbiterD, 47U));
            aWandererK = aWandererK + ((((RotL64(aCross, 51U) + aOrbiterG) + RotL64(aOrbiterH, 41U)) + RotL64(aCarry, 39U)) + aNonceWordB);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 57U) + aOrbiterD) + RotL64(aOrbiterG, 23U)) + aNonceWordM);
            //
            aCarry = aCarry + (RotL64(aWandererD, 35U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererI, 54U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererE, 43U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererK, 5U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 31519U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneA[((aIndex + 28761U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 31452U)) & S_BLOCK1], 38U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31552U)) & S_BLOCK1], 46U) ^ RotL64(aSnowLaneB[((aIndex + 29886U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aPrevious, 13U) + RotL64(aCross, 54U)) ^ (RotL64(aCarry, 41U) ^ RotL64(aIngress, 27U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterJ = (((aWandererF + RotL64(aCross, 19U)) + RotL64(aCarry, 27U)) + 1888427424966603593U) + aNonceWordG;
            aOrbiterD = ((aWandererA + RotL64(aScatter, 3U)) + RotL64(aCarry, 11U)) + 5436761445660415091U;
            aOrbiterH = ((aWandererG + RotL64(aPrevious, 27U)) + 17322876217962143270U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = ((aWandererI + RotL64(aIngress, 34U)) + 9728299982740564979U) + aNonceWordI;
            aOrbiterA = ((aWandererJ + RotL64(aPrevious, 51U)) + 301720335271716921U) + aNonceWordE;
            aOrbiterI = (((aWandererB + RotL64(aIngress, 13U)) + RotL64(aCarry, 53U)) + 8069685428854814396U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterG = ((aWandererK + RotL64(aScatter, 43U)) + 1973715500949100991U) + aNonceWordN;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 87666408799854155U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 12195436904339035245U;
            aOrbiterH = RotL64((aOrbiterH * 15427739165893738105U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 4578742069143400295U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 7828776048774876484U) ^ aNonceWordO;
            aOrbiterA = RotL64((aOrbiterA * 4047964518501081039U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 17203146364542781833U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 16913369550858890466U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 13534417587921978507U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 9632761514552265402U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterH) ^ 9106637671877341286U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 18U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterG = RotL64((aOrbiterG * 9073709119482640391U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 15423680889126750876U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 6087310684583331882U;
            aOrbiterD = RotL64((aOrbiterD * 8964465129744898619U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 5420955876411796789U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 14166807419730848032U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 442659738632823751U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 8118312450347026824U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 4253043584558403086U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 5651748455190536467U), 19U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterH, 19U);
            aIngress = aIngress + (RotL64(aOrbiterE, 50U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterA, 43U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterJ, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aPrevious, 60U) + RotL64(aOrbiterJ, 39U)) + aOrbiterH) + RotL64(aCarry, 47U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterE, 28U)) + aOrbiterG);
            aWandererF = aWandererF + ((RotL64(aIngress, 47U) + aOrbiterA) + RotL64(aOrbiterG, 47U));
            aWandererB = aWandererB ^ ((((RotL64(aScatter, 13U) + aOrbiterJ) + RotL64(aOrbiterA, 5U)) + aNonceWordJ) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aIngress, 29U) + RotL64(aOrbiterD, 57U)) + aOrbiterI) + RotL64(aCarry, 3U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 35U) + aOrbiterD) + RotL64(aOrbiterG, 13U));
            aWandererK = aWandererK + ((((RotL64(aScatter, 41U) + aOrbiterI) + RotL64(aOrbiterJ, 19U)) + aNonceWordD) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 35U) ^ aWandererK);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 40U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 3U));
            aCarry = aCarry + RotL64(aWandererI, 57U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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

void TwistExpander_Hockey_Arx::Twist_A(TwistWorkSpace *pWorkSpace,
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
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltC;
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
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltD;
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
            aIngress = RotL64(aKeyRowReadA[((aIndex + 2678U)) & W_KEY1], 11U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 832U)) & W_KEY1], 56U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 23U)) & W_KEY1], 4U) ^ RotL64(mSource[((aIndex + 592U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 39U) ^ RotL64(aPrevious, 57U)) + (RotL64(aCarry, 11U) ^ RotL64(aIngress, 24U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterH = (aWandererF + RotL64(aCross, 29U)) + 4773124477323378268U;
            aOrbiterF = (aWandererB + RotL64(aScatter, 19U)) + 16848723289435796005U;
            aOrbiterI = (aWandererD + RotL64(aPrevious, 57U)) + 13846642134917107058U;
            aOrbiterB = (aWandererH + RotL64(aIngress, 5U)) + 6472057872482789939U;
            aOrbiterC = (((aWandererK + RotL64(aScatter, 42U)) + RotL64(aCarry, 5U)) + 2747019500690707226U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = ((aWandererJ + RotL64(aCross, 51U)) + RotL64(aCarry, 27U)) + 9003965289739733880U;
            aOrbiterD = (aWandererC + RotL64(aPrevious, 11U)) + 3013390651936257377U;
            aOrbiterJ = (((aWandererE + RotL64(aIngress, 47U)) + RotL64(aCarry, 41U)) + 3331004709895625067U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = (aWandererI + RotL64(aCross, 36U)) + 15355010435553517129U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 7709870658004280052U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 13568728443963926564U;
            aOrbiterI = RotL64((aOrbiterI * 6736090830113688981U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 12409548853419307131U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 969183352023661537U;
            aOrbiterF = RotL64((aOrbiterF * 5549220554838837145U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 15370309834426476775U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 3896803894396631184U;
            aOrbiterD = RotL64((aOrbiterD * 11018830202891911603U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 10848873633291935766U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 12885336509190543440U;
            aOrbiterB = RotL64((aOrbiterB * 1487357252619221365U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 8252290890093788010U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 9201553615601641350U;
            aOrbiterG = RotL64((aOrbiterG * 420321130559162915U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 14014209645503188472U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 4015071464301844550U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 17444195018239904971U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 16173085647514027347U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 16916627014974363360U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7699587344277490953U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 1591680303404522110U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 16499606051269327916U;
            aOrbiterH = RotL64((aOrbiterH * 814405848002794813U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 6932673635509444619U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 8745681160108707944U;
            aOrbiterJ = RotL64((aOrbiterJ * 14565255558668084787U), 43U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterH, 5U);
            aIngress = aIngress + (RotL64(aOrbiterF, 39U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterG, 48U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 27U));
            aIngress = aIngress + RotL64(aOrbiterB, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aCross, 23U) + RotL64(aOrbiterF, 18U)) + aOrbiterJ);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 56U) + aOrbiterG) + RotL64(aOrbiterI, 23U));
            aWandererD = aWandererD + (((RotL64(aScatter, 11U) + RotL64(aOrbiterB, 51U)) + aOrbiterA) + RotL64(aCarry, 23U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 39U) + aOrbiterH) + RotL64(aOrbiterC, 41U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterI, 57U)) + aOrbiterH) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterB, 13U)) + aOrbiterD);
            aWandererC = aWandererC + (((RotL64(aIngress, 47U) + RotL64(aOrbiterJ, 28U)) + aOrbiterC) + RotL64(aCarry, 5U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 3U) + aOrbiterC) + RotL64(aOrbiterB, 5U));
            aWandererI = aWandererI + (((RotL64(aIngress, 30U) + aOrbiterA) + RotL64(aOrbiterI, 37U)) + aPhaseAWandererUpdateSaltB[((aIndex + 22U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 35U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererH, 39U) ^ aWandererJ);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 51U));
            aCarry = aCarry + (RotL64(aWandererB, 43U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererK, 11U);
            aCarry = aCarry + RotL64(aIngress, 56U);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 3391U)) & S_BLOCK1], 24U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 3053U)) & W_KEY1], 39U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 2995U)) & W_KEY1], 38U) ^ RotL64(mSource[((aIndex + 4371U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 35U) + RotL64(aPrevious, 48U)) ^ (RotL64(aCarry, 3U) ^ RotL64(aIngress, 21U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterK = (aWandererH + RotL64(aScatter, 57U)) + 7075016829833562104U;
            aOrbiterB = (aWandererK + RotL64(aPrevious, 14U)) + 8783765886115517036U;
            aOrbiterF = (aWandererF + RotL64(aCross, 43U)) + 2996723892384565829U;
            aOrbiterI = (aWandererE + RotL64(aIngress, 19U)) + 9494134707342189476U;
            aOrbiterD = (aWandererD + RotL64(aScatter, 5U)) + 5052642981395679904U;
            aOrbiterA = ((aWandererJ + RotL64(aIngress, 23U)) + 8766787055127962238U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterJ = ((aWandererC + RotL64(aCross, 50U)) + RotL64(aCarry, 21U)) + 4467211954388738079U;
            aOrbiterH = ((aWandererI + RotL64(aPrevious, 27U)) + RotL64(aCarry, 47U)) + 8030255604633658608U;
            aOrbiterG = (((aWandererB + RotL64(aScatter, 39U)) + RotL64(aCarry, 3U)) + 16962408063455702251U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 3768222186567699076U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 14930990410207899871U;
            aOrbiterF = RotL64((aOrbiterF * 10930005786146268241U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 14179761938395502502U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 1879084742719898108U;
            aOrbiterD = RotL64((aOrbiterD * 16783034788172670121U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 5535012408925981515U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 12792553516710295939U;
            aOrbiterJ = RotL64((aOrbiterJ * 8577530993755159329U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 8979253163346099252U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 5559189896063990740U;
            aOrbiterH = RotL64((aOrbiterH * 8832485423727331621U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 13937564337299044079U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 2393376759689394948U;
            aOrbiterG = RotL64((aOrbiterG * 2352815657830413941U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 12647519563697356479U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 10946871249960389549U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 6272580371881237173U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 13376798695582123147U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 10958115913599631271U;
            aOrbiterI = RotL64((aOrbiterI * 18233981473003345217U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 4283914227806672773U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 910842005516235816U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 6722229871617873429U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 1509644316619370324U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 165987596716078174U;
            aOrbiterB = RotL64((aOrbiterB * 13600064054240185123U), 5U);
            //
            aIngress = RotL64(aOrbiterB, 24U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 19U));
            aIngress = aIngress + (RotL64(aOrbiterI, 41U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterA, 51U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterG, 6U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aCross, 53U) + aOrbiterJ) + RotL64(aOrbiterK, 36U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 12U) + aOrbiterD) + RotL64(aOrbiterI, 41U)) + RotL64(aCarry, 57U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 23U) + aOrbiterK) + RotL64(aOrbiterD, 47U));
            aWandererD = aWandererD + ((RotL64(aScatter, 29U) + aOrbiterH) + RotL64(aOrbiterF, 11U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterG, 23U)) + aOrbiterJ);
            aWandererI = aWandererI + ((((RotL64(aCross, 57U) + RotL64(aOrbiterB, 19U)) + aOrbiterF) + RotL64(aCarry, 5U)) + aPhaseAWandererUpdateSaltB[((aIndex + 25U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 35U) + aOrbiterA) + RotL64(aOrbiterI, 60U));
            aWandererE = aWandererE + (((RotL64(aScatter, 43U) + aOrbiterD) + RotL64(aOrbiterG, 27U)) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 4U) + aOrbiterF) + RotL64(aOrbiterA, 53U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 3U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererB, 41U) ^ aWandererC);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 27U));
            aCarry = aCarry + (RotL64(aWandererK, 47U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererF, 14U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = RotL64(aWorkLaneB[((aIndex + 5700U)) & S_BLOCK1], 13U) ^ RotL64(aKeyRowReadB[((aIndex + 7386U)) & W_KEY1], 4U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 6930U)) & W_KEY1], 35U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 5712U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 5590U)) & S_BLOCK1], 12U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 27U) + RotL64(aIngress, 41U)) ^ (RotL64(aCross, 3U) + RotL64(aPrevious, 54U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterI = ((aWandererH + RotL64(aScatter, 13U)) + RotL64(aCarry, 13U)) + 6916817163240024692U;
            aOrbiterE = (aWandererI + RotL64(aPrevious, 23U)) + 14554930751292077817U;
            aOrbiterA = (aWandererG + RotL64(aCross, 37U)) + 1098305064484336101U;
            aOrbiterB = (aWandererA + RotL64(aIngress, 19U)) + 12192821172420471527U;
            aOrbiterH = ((aWandererJ + RotL64(aCross, 44U)) + 2435134991707318845U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterC = ((aWandererB + RotL64(aScatter, 53U)) + 1896745368738512624U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterG = ((aWandererE + RotL64(aIngress, 29U)) + RotL64(aCarry, 3U)) + 1114996424222923873U;
            aOrbiterJ = ((aWandererF + RotL64(aPrevious, 57U)) + RotL64(aCarry, 47U)) + 9839135798371512656U;
            aOrbiterK = (aWandererK + RotL64(aIngress, 48U)) + 8037967239603177043U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 15185468738487237432U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 4912098316394854543U;
            aOrbiterA = RotL64((aOrbiterA * 3072785550384399929U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 13142688607850380888U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 4507379759608945839U;
            aOrbiterH = RotL64((aOrbiterH * 2989332387754215967U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 7299006009652289342U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 5390655277207053627U;
            aOrbiterJ = RotL64((aOrbiterJ * 10973744708856143715U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 6744737023577785725U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 15539737698867067285U;
            aOrbiterE = RotL64((aOrbiterE * 4686092035261336911U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 13329866734681377952U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 13284937458969166257U;
            aOrbiterB = RotL64((aOrbiterB * 3965985432462699445U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 8695002088915702168U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 3858059421620839286U;
            aOrbiterK = RotL64((aOrbiterK * 9559783727301092937U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 6609163873243179836U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 9416165620556710540U;
            aOrbiterG = RotL64((aOrbiterG * 240385043740268229U), 37U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 1578449067529000433U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 14309000104419489303U;
            aOrbiterI = RotL64((aOrbiterI * 7599078306153684729U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 15785180680737461320U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 10099222679918382021U;
            aOrbiterC = RotL64((aOrbiterC * 2012232597046182581U), 5U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterI, 21U);
            aIngress = aIngress + (RotL64(aOrbiterG, 35U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterC, 40U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterA, 43U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterJ, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aScatter, 23U) + aOrbiterB) + RotL64(aOrbiterC, 51U)) + aPhaseAWandererUpdateSaltC[((aIndex + 24U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 57U) + RotL64(aOrbiterG, 12U)) + aOrbiterI) + aPhaseAWandererUpdateSaltB[((aIndex + 7U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aCross, 46U) + RotL64(aOrbiterC, 3U)) + aOrbiterH);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 5U) + aOrbiterC) + RotL64(aOrbiterG, 23U));
            aWandererH = aWandererH + ((RotL64(aPrevious, 51U) + RotL64(aOrbiterJ, 19U)) + aOrbiterE);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 35U) + aOrbiterA) + RotL64(aOrbiterH, 56U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 41U) + aOrbiterE) + RotL64(aOrbiterA, 37U)) + RotL64(aCarry, 43U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 18U) + aOrbiterH) + RotL64(aOrbiterK, 29U));
            aWandererB = aWandererB + (((RotL64(aIngress, 27U) + RotL64(aOrbiterJ, 47U)) + aOrbiterK) + RotL64(aCarry, 27U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 57U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererH, 54U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererK, 47U) ^ aWandererF);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 13U));
            aCarry = aCarry + RotL64(aWandererI, 43U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 8773U)) & S_BLOCK1], 12U) ^ RotL64(aKeyRowReadB[((aIndex + 9568U)) & W_KEY1], 53U));
            aIngress ^= (RotL64(mSource[((aIndex + 8684U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 9734U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 9469U)) & W_KEY1], 58U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 8588U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 37U) ^ RotL64(aCross, 10U)) + (RotL64(aIngress, 53U) + RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterJ = (aWandererH + RotL64(aScatter, 35U)) + 785861751704720606U;
            aOrbiterI = ((aWandererB + RotL64(aIngress, 58U)) + RotL64(aCarry, 51U)) + 15968088718435606299U;
            aOrbiterH = (aWandererD + RotL64(aCross, 39U)) + 1393976526590347151U;
            aOrbiterF = ((aWandererI + RotL64(aPrevious, 21U)) + 17240750947292745884U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterE = ((aWandererC + RotL64(aCross, 11U)) + RotL64(aCarry, 19U)) + 4921576136163183137U;
            aOrbiterC = (aWandererE + RotL64(aPrevious, 46U)) + 3334047873553153032U;
            aOrbiterG = ((aWandererA + RotL64(aIngress, 29U)) + 15086509978458408698U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = ((aWandererJ + RotL64(aScatter, 3U)) + RotL64(aCarry, 27U)) + 892391205397581998U;
            aOrbiterD = (aWandererG + RotL64(aIngress, 51U)) + 2965686403183767521U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 14632215393655706170U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 15740589515342377322U;
            aOrbiterH = RotL64((aOrbiterH * 15677716942904794913U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 11131164813943086445U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 6988080581278900960U;
            aOrbiterE = RotL64((aOrbiterE * 6412189142344044255U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 16021254613117657178U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 6183615599897921154U;
            aOrbiterG = RotL64((aOrbiterG * 9976411093264211033U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 12533992547026652747U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 3104325358982904219U;
            aOrbiterJ = RotL64((aOrbiterJ * 14977348108778147265U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 3878525937957474644U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 2120435259884368445U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 15964718652193073177U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 14928658302694194856U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 9121310461310309348U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 17304439784647477491U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 3715693239100476493U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 7336577492932262490U;
            aOrbiterF = RotL64((aOrbiterF * 11074754160002665253U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 2312452827448455675U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 4322756069651934618U;
            aOrbiterD = RotL64((aOrbiterD * 6908893297397073539U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 4962079617577705818U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 5072727464750706525U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4947670001221089155U), 19U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterK, 5U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 19U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 28U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 53U));
            aIngress = aIngress + RotL64(aOrbiterD, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterD, 39U)) + aOrbiterG);
            aWandererI = aWandererI + ((RotL64(aCross, 58U) + RotL64(aOrbiterC, 60U)) + aOrbiterF);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 43U) + aOrbiterJ) + RotL64(aOrbiterH, 53U));
            aWandererH = aWandererH + (((RotL64(aScatter, 47U) + RotL64(aOrbiterE, 35U)) + aOrbiterD) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 51U) + aOrbiterG) + RotL64(aOrbiterJ, 13U));
            aWandererB = aWandererB + (((RotL64(aCross, 11U) + RotL64(aOrbiterH, 29U)) + aOrbiterK) + RotL64(aCarry, 57U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterJ, 43U)) + aOrbiterI);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 27U) + aOrbiterH) + RotL64(aOrbiterI, 47U)) + RotL64(aCarry, 11U)) + aPhaseBWandererUpdateSaltA[((aIndex + 27U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 20U) + aOrbiterF) + RotL64(aOrbiterI, 24U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 58U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererH, 35U) ^ aWandererB);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 19U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + RotL64(aWandererE, 43U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 12080U)) & S_BLOCK1], 24U) ^ RotL64(aKeyRowReadA[((aIndex + 12765U)) & W_KEY1], 53U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 11624U)) & W_KEY1], 11U) ^ RotL64(mSource[((aIndex + 12474U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 12241U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 12460U)) & S_BLOCK1], 35U) ^ RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 11766U)) & S_BLOCK1], 52U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 57U) ^ RotL64(aIngress, 35U)) ^ (RotL64(aCarry, 5U) + RotL64(aPrevious, 18U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterI = (aWandererH + RotL64(aScatter, 47U)) + 966899917801652720U;
            aOrbiterJ = (aWandererK + RotL64(aIngress, 24U)) + 10996327672320748649U;
            aOrbiterG = ((aWandererI + RotL64(aPrevious, 51U)) + RotL64(aCarry, 23U)) + 4188171566846621107U;
            aOrbiterE = (aWandererG + RotL64(aCross, 3U)) + 5886209243097387959U;
            aOrbiterD = (aWandererJ + RotL64(aIngress, 29U)) + 14940428957136728111U;
            aOrbiterH = ((aWandererD + RotL64(aScatter, 57U)) + RotL64(aCarry, 39U)) + 179187285531914832U;
            aOrbiterA = (aWandererB + RotL64(aPrevious, 14U)) + 6685351948936817752U;
            aOrbiterK = (((aWandererE + RotL64(aCross, 35U)) + RotL64(aCarry, 3U)) + 1894506461704029700U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = ((aWandererA + RotL64(aPrevious, 19U)) + 4182760368636977082U) + aPhaseBOrbiterAssignSaltB[((aIndex + 13U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 12523318028514940790U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 5059306166973366892U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2857409765717296483U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 5890872367917643851U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 17747338389865221534U;
            aOrbiterJ = RotL64((aOrbiterJ * 5306740664798049267U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 13906227834259884100U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 7152105382899756368U;
            aOrbiterE = RotL64((aOrbiterE * 6772157117358310485U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 17868101884759619240U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 11758843266314148347U;
            aOrbiterK = RotL64((aOrbiterK * 5919135169337501485U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 13950566197090324859U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 17278105609930477854U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 11431842718945107359U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 9556785965646738355U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 841298436857932987U;
            aOrbiterI = RotL64((aOrbiterI * 15077843186688841797U), 39U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 1951515285492133830U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 15775839819330588437U;
            aOrbiterB = RotL64((aOrbiterB * 7902654031401620995U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 5585458468816495436U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 17258586689032223623U;
            aOrbiterA = RotL64((aOrbiterA * 1652050227399194271U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 5254132659445988836U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 15440741734777060925U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 17445581079035134067U), 11U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterB, 54U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 41U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 47U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 23U));
            aIngress = aIngress + RotL64(aOrbiterJ, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aCross, 51U) + aOrbiterA) + RotL64(aOrbiterB, 11U));
            aWandererH = aWandererH + ((RotL64(aScatter, 46U) + RotL64(aOrbiterG, 60U)) + aOrbiterE);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 5U) + aOrbiterA) + RotL64(aOrbiterD, 27U));
            aWandererG = aWandererG + ((RotL64(aIngress, 35U) + aOrbiterA) + RotL64(aOrbiterE, 23U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 13U) + RotL64(aOrbiterI, 3U)) + aOrbiterJ) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aIngress, 21U) + RotL64(aOrbiterI, 35U)) + aOrbiterK) + RotL64(aCarry, 35U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 39U) + aOrbiterG) + RotL64(aOrbiterI, 46U)) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 28U) + RotL64(aOrbiterH, 51U)) + aOrbiterI) + RotL64(aCarry, 27U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterE, 39U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 36U));
            aCarry = aCarry + (RotL64(aWandererE, 5U) ^ aWandererJ);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 43U));
            aCarry = aCarry + (RotL64(aWandererH, 19U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererB, 39U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 15233U)) & S_BLOCK1], 56U) ^ RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 13918U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 16279U)) & W_KEY1], 56U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 15926U)) & W_KEY1], 27U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 16026U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 15820U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 14915U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 35U) + RotL64(aIngress, 20U)) ^ (RotL64(aPrevious, 5U) + RotL64(aCross, 47U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterB = ((aWandererJ + RotL64(aCross, 10U)) + RotL64(aCarry, 57U)) + 439898681482066326U;
            aOrbiterC = (aWandererK + RotL64(aScatter, 27U)) + 17362083676671776094U;
            aOrbiterD = (aWandererI + RotL64(aPrevious, 39U)) + 6418499837265155024U;
            aOrbiterG = (aWandererF + RotL64(aIngress, 43U)) + 17262244253027454972U;
            aOrbiterE = ((aWandererD + RotL64(aPrevious, 51U)) + 2382066162993139503U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterJ = (aWandererH + RotL64(aCross, 34U)) + 14345808395587174135U;
            aOrbiterA = (((aWandererA + RotL64(aIngress, 47U)) + RotL64(aCarry, 47U)) + 7534743166385552851U) + aPhaseBOrbiterAssignSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterK = ((aWandererB + RotL64(aScatter, 21U)) + RotL64(aCarry, 37U)) + 16994453324688523966U;
            aOrbiterI = (aWandererC + RotL64(aIngress, 3U)) + 7079553728544045092U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 3562822704508440641U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 13990892681975857821U;
            aOrbiterD = RotL64((aOrbiterD * 8352929306654078795U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 1796728922368577238U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 6605161260520067178U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8147537646591674091U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 13994083795942328918U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 6144523182899107711U;
            aOrbiterA = RotL64((aOrbiterA * 4153879991344611283U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 12247462325297436642U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 1065809332002012789U;
            aOrbiterG = RotL64((aOrbiterG * 5496601177032953251U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 10147919864511540753U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 17138553441127273354U;
            aOrbiterE = RotL64((aOrbiterE * 5773875596275267871U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 2653924016109573974U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 6254416952351699582U;
            aOrbiterB = RotL64((aOrbiterB * 12756861659704947257U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 813046408080197079U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 9624466135414123483U;
            aOrbiterK = RotL64((aOrbiterK * 6960320253124395015U), 39U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 972586705850825744U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 155283774901960223U;
            aOrbiterI = RotL64((aOrbiterI * 9928051687724257041U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 18200100644751360406U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 1168426822045686004U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 5867027156069481313U), 53U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterI, 24U);
            aIngress = aIngress + (RotL64(aOrbiterG, 29U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 5U));
            aIngress = aIngress + (RotL64(aOrbiterB, 51U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterJ, 58U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aIngress, 19U) + aOrbiterJ) + RotL64(aOrbiterD, 51U)) + aPhaseBWandererUpdateSaltB[((aIndex + 29U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 13U) + aOrbiterI) + RotL64(aOrbiterJ, 37U));
            aWandererB = aWandererB + (((RotL64(aScatter, 34U) + RotL64(aOrbiterD, 47U)) + aOrbiterC) + RotL64(aCarry, 47U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterE, 18U)) + aOrbiterG);
            aWandererC = aWandererC + (((RotL64(aIngress, 51U) + RotL64(aOrbiterJ, 29U)) + aOrbiterB) + RotL64(aCarry, 39U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 41U) + aOrbiterA) + RotL64(aOrbiterB, 41U));
            aWandererJ = aWandererJ + ((RotL64(aScatter, 30U) + RotL64(aOrbiterD, 3U)) + aOrbiterB);
            aWandererK = aWandererK ^ ((RotL64(aCross, 47U) + aOrbiterK) + RotL64(aOrbiterI, 60U));
            aWandererI = aWandererI + (((RotL64(aIngress, 23U) + aOrbiterK) + RotL64(aOrbiterG, 11U)) + aPhaseBWandererUpdateSaltE[((aIndex + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 27U) ^ aWandererJ);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 47U));
            aCarry = aCarry + (RotL64(aWandererC, 34U) ^ aWandererI);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 19U));
            aCarry = aCarry + RotL64(aWandererF, 13U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 19093U)) & S_BLOCK1], 23U) ^ RotL64(aKeyRowReadA[((aIndex + 16730U)) & W_KEY1], 60U));
            aIngress ^= (RotL64(mSource[((aIndex + 17781U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneA[((aIndex + 18597U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 16666U)) & W_KEY1], 27U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 18782U)) & S_BLOCK1], 41U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 18687U)) & S_BLOCK1], 18U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 20U) + RotL64(aCross, 39U)) ^ (RotL64(aCarry, 57U) + RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterI = (aWandererH + RotL64(aCross, 5U)) + 13481227414590594621U;
            aOrbiterA = ((aWandererJ + RotL64(aScatter, 11U)) + RotL64(aCarry, 21U)) + 17425964381118918026U;
            aOrbiterC = ((aWandererB + RotL64(aIngress, 19U)) + RotL64(aCarry, 53U)) + 4792004356135956581U;
            aOrbiterD = (aWandererA + RotL64(aPrevious, 47U)) + 11926849936000639098U;
            aOrbiterH = (aWandererD + RotL64(aIngress, 34U)) + 990697329347742142U;
            aOrbiterJ = (aWandererE + RotL64(aCross, 29U)) + 9307721505373076588U;
            aOrbiterF = (aWandererG + RotL64(aScatter, 53U)) + 17605732738841908719U;
            aOrbiterB = (((aWandererK + RotL64(aPrevious, 39U)) + RotL64(aCarry, 39U)) + 13110764518634187439U) + aPhaseCOrbiterAssignSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterK = ((aWandererI + RotL64(aCross, 58U)) + 17970109897810645911U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 10273133817644703654U) + aPhaseCOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 11239046688920468137U;
            aOrbiterC = RotL64((aOrbiterC * 5197802934333553327U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 8355821483275763145U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 15522151127786049345U) ^ aPhaseCOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 4844278537850520413U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 5381663179722418112U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 9551368011768104906U;
            aOrbiterF = RotL64((aOrbiterF * 14202470972121732997U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 16264476585232221270U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 7721417776432288282U;
            aOrbiterH = RotL64((aOrbiterH * 10267770327791051869U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 339418090653475277U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 3247926250495935511U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 16824669543765729097U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 3390560045236418590U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 3894024951542543635U;
            aOrbiterK = RotL64((aOrbiterK * 10599637790900418767U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 3878539166189668154U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 5617705593218220843U;
            aOrbiterJ = RotL64((aOrbiterJ * 82771190372750823U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 12320861089148474544U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 14943790251625519550U;
            aOrbiterD = RotL64((aOrbiterD * 13758322022902008313U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 18119213517612562775U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 1413193144229486646U;
            aOrbiterI = RotL64((aOrbiterI * 14562375280658115687U), 19U);
            //
            aIngress = RotL64(aOrbiterC, 34U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 39U));
            aIngress = aIngress + (RotL64(aOrbiterB, 19U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterJ, 23U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterF, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aIngress, 27U) + RotL64(aOrbiterF, 11U)) + aOrbiterD);
            aWandererE = aWandererE ^ ((RotL64(aCross, 53U) + aOrbiterH) + RotL64(aOrbiterJ, 29U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 13U) + aOrbiterJ) + RotL64(aOrbiterA, 35U)) + RotL64(aCarry, 57U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 42U) + RotL64(aOrbiterJ, 18U)) + aOrbiterC);
            aWandererI = aWandererI + ((((RotL64(aIngress, 47U) + RotL64(aOrbiterI, 23U)) + aOrbiterA) + RotL64(aCarry, 39U)) + aPhaseCWandererUpdateSaltB[((aIndex + 28U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 57U) + aOrbiterK) + RotL64(aOrbiterI, 5U));
            aWandererG = aWandererG + (((RotL64(aCross, 23U) + RotL64(aOrbiterD, 41U)) + aOrbiterB) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 3U) + aOrbiterK) + RotL64(aOrbiterB, 47U));
            aWandererA = aWandererA + ((RotL64(aIngress, 18U) + RotL64(aOrbiterC, 58U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 10U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 53U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 27U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 23U));
            aCarry = aCarry + RotL64(aWandererI, 19U);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 19241U)) & S_BLOCK1], 11U) ^ RotL64(mSource[((aIndex + 20425U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aFireLaneA[((aIndex + 19597U)) & S_BLOCK1], 22U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 20382U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 19551U)) & W_KEY1], 5U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 21269U)) & W_KEY1], 39U));
            aCross ^= (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 19229U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneB[((aIndex + 19162U)) & S_BLOCK1], 30U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 39U) + RotL64(aPrevious, 22U)) ^ (RotL64(aIngress, 5U) + RotL64(aCross, 51U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterK = (aWandererC + RotL64(aPrevious, 53U)) + 380024772508948442U;
            aOrbiterH = (aWandererD + RotL64(aScatter, 39U)) + 7649029098162567210U;
            aOrbiterA = ((aWandererH + RotL64(aCross, 20U)) + RotL64(aCarry, 21U)) + 5329304598870421851U;
            aOrbiterJ = ((aWandererE + RotL64(aIngress, 11U)) + RotL64(aCarry, 37U)) + 12306118665045151326U;
            aOrbiterE = ((aWandererA + RotL64(aScatter, 5U)) + RotL64(aCarry, 13U)) + 960751560457324256U;
            aOrbiterB = ((aWandererF + RotL64(aIngress, 43U)) + 3244070254386191876U) + aPhaseCOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = ((aWandererK + RotL64(aPrevious, 35U)) + 15733408571609521746U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = (aWandererJ + RotL64(aCross, 47U)) + 17623448932647018544U;
            aOrbiterC = (aWandererB + RotL64(aIngress, 26U)) + 8787759896149035829U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 14741681792348288162U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 8801731213568307302U;
            aOrbiterA = RotL64((aOrbiterA * 12127126999570616489U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 9872248187499779222U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 15407371518644528235U;
            aOrbiterE = RotL64((aOrbiterE * 1245102406469471673U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 4242060317152943062U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 9942784962409917541U;
            aOrbiterI = RotL64((aOrbiterI * 888649755587764533U), 39U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 7296348796484458631U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 15061417216070157797U;
            aOrbiterB = RotL64((aOrbiterB * 10349554676953256231U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 3233185810644297433U) + aPhaseCOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 9241229457641024287U;
            aOrbiterJ = RotL64((aOrbiterJ * 2728237515724597517U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 8464051359381554575U) + aPhaseCOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 3307872165699029375U;
            aOrbiterF = RotL64((aOrbiterF * 4859663401033023433U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 5482617843966711997U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 4442149210462943872U;
            aOrbiterK = RotL64((aOrbiterK * 8979352218576515647U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 10591636597580147381U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 14925122230279312217U;
            aOrbiterH = RotL64((aOrbiterH * 15038171961638724013U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 9772367878232735350U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 15800661165607190092U) ^ aPhaseCOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 10493976952980533589U), 3U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterJ, 60U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 5U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 23U));
            aIngress = aIngress + (RotL64(aOrbiterB, 47U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterI, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aPrevious, 51U) + aOrbiterF) + RotL64(aOrbiterK, 35U)) + RotL64(aCarry, 3U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterA, 3U)) + aOrbiterB);
            aWandererC = aWandererC + (((RotL64(aIngress, 60U) + RotL64(aOrbiterJ, 57U)) + aOrbiterF) + RotL64(aCarry, 57U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterE, 52U)) + aOrbiterH);
            aWandererF = aWandererF + ((RotL64(aIngress, 47U) + RotL64(aOrbiterH, 43U)) + aOrbiterI);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 29U) + aOrbiterE) + RotL64(aOrbiterA, 27U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 35U) + aOrbiterH) + RotL64(aOrbiterK, 19U)) + aPhaseCWandererUpdateSaltA[((aIndex + 20U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 12U) + RotL64(aOrbiterC, 47U)) + aOrbiterI);
            aWandererD = aWandererD + (((RotL64(aScatter, 5U) + RotL64(aOrbiterH, 14U)) + aOrbiterJ) + aPhaseCWandererUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 44U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 53U));
            aCarry = aCarry + (RotL64(aWandererH, 11U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererA, 47U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererK, 60U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 22418U)) & S_BLOCK1], 35U) ^ RotL64(aKeyRowReadA[((aIndex + 23204U)) & W_KEY1], 11U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 23664U)) & W_KEY1], 47U) ^ RotL64(aFireLaneC[((aIndex + 22899U)) & S_BLOCK1], 22U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 22693U)) & S_BLOCK1], 53U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 23448U)) & S_BLOCK1], 19U));
            aCross ^= (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 23554U)) & S_BLOCK1], 10U) ^ RotL64(aInvestLaneB[((aIndex + 22211U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aIngress, 39U)) + (RotL64(aCross, 26U) ^ RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterI = (aWandererF + RotL64(aCross, 46U)) + 4739486756133131180U;
            aOrbiterJ = ((aWandererE + RotL64(aIngress, 57U)) + RotL64(aCarry, 5U)) + 16089707555501328184U;
            aOrbiterD = (aWandererI + RotL64(aScatter, 19U)) + 15310047330238536453U;
            aOrbiterF = ((aWandererH + RotL64(aPrevious, 5U)) + 7901411596386834955U) + aPhaseCOrbiterAssignSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = ((aWandererB + RotL64(aCross, 53U)) + RotL64(aCarry, 35U)) + 4357555491060982163U;
            aOrbiterG = (aWandererD + RotL64(aScatter, 37U)) + 15667085602825720102U;
            aOrbiterH = (aWandererC + RotL64(aIngress, 27U)) + 8520635334382269253U;
            aOrbiterA = ((aWandererK + RotL64(aPrevious, 42U)) + 1772509779231068315U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = ((aWandererJ + RotL64(aScatter, 11U)) + RotL64(aCarry, 21U)) + 15336170957886025677U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 8628770833489469980U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 15469234024247246228U;
            aOrbiterD = RotL64((aOrbiterD * 8905266995119987947U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 10796430900884288328U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 10660110397012853289U;
            aOrbiterG = RotL64((aOrbiterG * 9140007610912037461U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 11202284258711214794U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 17509491802893182994U;
            aOrbiterH = RotL64((aOrbiterH * 9329107599972703671U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 16212572740740103554U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 2190030203761579226U;
            aOrbiterA = RotL64((aOrbiterA * 3101886685668871045U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 12014337082293041909U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 3733531010807001506U;
            aOrbiterI = RotL64((aOrbiterI * 5797362244066062299U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 7100994963061975529U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 17837541162838600258U;
            aOrbiterE = RotL64((aOrbiterE * 8745987361678166553U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 3311518938023146951U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 7709505172646831553U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 7121143171245765213U), 39U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 4979968094554018443U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 16822214821463034107U) ^ aPhaseCOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8618262120451291765U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 8376124175020587079U) + aPhaseCOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 11084586282092424876U;
            aOrbiterF = RotL64((aOrbiterF * 5835632742522563537U), 5U);
            //
            aIngress = RotL64(aOrbiterE, 47U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterC, 20U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterJ, 53U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterF, 41U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterA, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aScatter, 10U) + aOrbiterE) + RotL64(aOrbiterD, 29U)) + RotL64(aCarry, 11U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 37U) + aOrbiterA) + RotL64(aOrbiterE, 35U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 41U) + aOrbiterF) + RotL64(aOrbiterA, 24U)) + aPhaseCWandererUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterD, 5U)) + aOrbiterJ);
            aWandererC = aWandererC + (((RotL64(aCross, 19U) + RotL64(aOrbiterC, 53U)) + aOrbiterG) + RotL64(aCarry, 57U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 27U) + RotL64(aOrbiterG, 43U)) + aOrbiterI) + aPhaseCWandererUpdateSaltB[((aIndex + 25U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 57U) + aOrbiterJ) + RotL64(aOrbiterF, 39U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 48U) + aOrbiterF) + RotL64(aOrbiterG, 14U));
            aWandererK = aWandererK + ((RotL64(aCross, 53U) + aOrbiterH) + RotL64(aOrbiterI, 19U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 39U));
            aCarry = aCarry + (RotL64(aWandererK, 53U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererB, 60U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererF, 3U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererH, 19U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 25859U)) & S_BLOCK1], 3U) ^ RotL64(aKeyRowReadA[((aIndex + 26474U)) & W_KEY1], 21U));
            aIngress ^= (RotL64(aFireLaneD[((aIndex + 25991U)) & S_BLOCK1], 38U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 25143U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 25849U)) & W_KEY1], 47U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 26556U)) & S_BLOCK1], 58U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 26647U)) & S_BLOCK1], 3U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 24900U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 21U) + RotL64(aCross, 5U)) ^ (RotL64(aCarry, 54U) ^ RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterB = ((aWandererD + RotL64(aIngress, 58U)) + RotL64(aCarry, 23U)) + 18191288703716505885U;
            aOrbiterH = (aWandererC + RotL64(aPrevious, 3U)) + 9824014524910417136U;
            aOrbiterJ = ((aWandererK + RotL64(aCross, 13U)) + RotL64(aCarry, 57U)) + 11953012029254917548U;
            aOrbiterD = ((aWandererE + RotL64(aScatter, 23U)) + 6297568011027199089U) + aPhaseDOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = (aWandererG + RotL64(aCross, 27U)) + 2576999400457367975U;
            aOrbiterC = (aWandererB + RotL64(aPrevious, 35U)) + 13176139160575558254U;
            aOrbiterK = (aWandererH + RotL64(aIngress, 42U)) + 9978408174563621810U;
            aOrbiterE = ((aWandererI + RotL64(aScatter, 53U)) + RotL64(aCarry, 37U)) + 16765834875061607142U;
            aOrbiterG = ((aWandererF + RotL64(aIngress, 19U)) + 16534507305459121344U) + aPhaseDOrbiterAssignSaltD[((aIndex + 8U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 3114710944346151807U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 10240517868726718592U;
            aOrbiterJ = RotL64((aOrbiterJ * 4645691562915606463U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 10721450637990777883U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 16689590768796583952U;
            aOrbiterC = RotL64((aOrbiterC * 3046344179729901637U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 2427422768928450209U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 13495584061816457831U;
            aOrbiterE = RotL64((aOrbiterE * 6670984773768885119U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 7058636403765106682U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 9897341853944713767U;
            aOrbiterG = RotL64((aOrbiterG * 14286816859999869231U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 17749559755733386064U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 12515645083926326659U;
            aOrbiterK = RotL64((aOrbiterK * 6582878478865838245U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 2625692458813609962U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 10596240255026143019U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11605800195771080135U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 12374290338067865540U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 1507386663796330249U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 1210241080424446087U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 9288099549484146726U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 15159312464747000702U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 500055502081347757U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 14998608679505446229U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 17625038109437732009U;
            aOrbiterD = RotL64((aOrbiterD * 14785862243019841689U), 57U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterC, 27U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 60U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 3U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 53U));
            aIngress = aIngress + RotL64(aOrbiterE, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aCross, 48U) + aOrbiterH) + RotL64(aOrbiterC, 48U)) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aIngress, 27U) + aOrbiterK) + RotL64(aOrbiterE, 57U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 37U) + RotL64(aOrbiterC, 35U)) + aOrbiterG) + aPhaseDWandererUpdateSaltF[((aIndex + 3U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 53U) + aOrbiterI) + RotL64(aOrbiterD, 11U)) + RotL64(aCarry, 13U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 3U) + aOrbiterB) + RotL64(aOrbiterJ, 3U));
            aWandererB = aWandererB + (((RotL64(aScatter, 19U) + RotL64(aOrbiterC, 27U)) + aOrbiterK) + RotL64(aCarry, 21U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 58U) + aOrbiterD) + RotL64(aOrbiterB, 39U));
            aWandererF = aWandererF + ((RotL64(aPrevious, 11U) + aOrbiterG) + RotL64(aOrbiterI, 43U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterG, 22U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererH, 43U) ^ aWandererK);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 26U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 35U));
            aCarry = aCarry + (RotL64(aWandererD, 39U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererF, 53U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 28060U)) & S_BLOCK1], 47U) ^ RotL64(aFireLaneD[((aIndex + 27760U)) & S_BLOCK1], 60U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 28673U)) & W_KEY1], 21U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 28031U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 28960U)) & W_KEY1], 57U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 29226U)) & S_BLOCK1], 29U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 28308U)) & S_BLOCK1], 13U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 27756U)) & S_BLOCK1], 40U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 44U) + RotL64(aCarry, 13U)) ^ (RotL64(aCross, 27U) ^ RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterI = (aWandererC + RotL64(aIngress, 60U)) + 4980738603982643969U;
            aOrbiterC = ((aWandererH + RotL64(aPrevious, 53U)) + 17660278413018470020U) + aPhaseDOrbiterAssignSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = (aWandererK + RotL64(aScatter, 39U)) + 17598114429859543466U;
            aOrbiterJ = (aWandererB + RotL64(aCross, 35U)) + 10993929335279994739U;
            aOrbiterA = (aWandererF + RotL64(aScatter, 29U)) + 17967203122976322481U;
            aOrbiterF = ((aWandererE + RotL64(aPrevious, 3U)) + RotL64(aCarry, 23U)) + 1872290205549034384U;
            aOrbiterK = (aWandererG + RotL64(aIngress, 43U)) + 16607778671782810797U;
            aOrbiterG = ((aWandererJ + RotL64(aCross, 21U)) + RotL64(aCarry, 41U)) + 4895226930754394376U;
            aOrbiterB = (((aWandererI + RotL64(aIngress, 48U)) + RotL64(aCarry, 51U)) + 14960359005982301383U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 9921642352377700630U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 893281964367208693U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2345509157333444217U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 8232519988397858732U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 4433022122758913407U;
            aOrbiterA = RotL64((aOrbiterA * 834240393225479419U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 12689609831247168353U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 404535388957472176U;
            aOrbiterC = RotL64((aOrbiterC * 14534020545479806593U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 3349108201964013155U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 4386449511297371730U;
            aOrbiterK = RotL64((aOrbiterK * 9596273264321140229U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 14314587717949070586U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 10923886625271054985U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 7838969002623486809U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 17634909585329833520U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 2021301459918350372U;
            aOrbiterG = RotL64((aOrbiterG * 1388242915918642741U), 41U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 5219599112498224367U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 10641339455385046206U;
            aOrbiterB = RotL64((aOrbiterB * 1022283727595400719U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 5003342156562330058U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 10951027475628404336U;
            aOrbiterF = RotL64((aOrbiterF * 17836928292555158461U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 13040991872592235460U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 11149099984302782267U;
            aOrbiterI = RotL64((aOrbiterI * 4248667283139686251U), 13U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterD, 60U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 19U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 29U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 51U));
            aIngress = aIngress + RotL64(aOrbiterJ, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aIngress, 39U) + RotL64(aOrbiterK, 37U)) + aOrbiterI) + aPhaseDWandererUpdateSaltE[((aIndex + 29U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aPrevious, 34U) + aOrbiterB) + RotL64(aOrbiterI, 46U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 23U) + aOrbiterC) + RotL64(aOrbiterI, 19U));
            aWandererF = aWandererF + ((RotL64(aCross, 43U) + RotL64(aOrbiterF, 41U)) + aOrbiterC);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 11U) + aOrbiterG) + RotL64(aOrbiterI, 13U));
            aWandererK = aWandererK + (((RotL64(aCross, 19U) + RotL64(aOrbiterI, 23U)) + aOrbiterD) + RotL64(aCarry, 51U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 48U) + RotL64(aOrbiterA, 60U)) + aOrbiterC);
            aWandererC = aWandererC + (((RotL64(aIngress, 27U) + RotL64(aOrbiterJ, 27U)) + aOrbiterC) + RotL64(aCarry, 41U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 5U) + RotL64(aOrbiterB, 3U)) + aOrbiterC) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 23U));
            aCarry = aCarry + (RotL64(aWandererI, 20U) ^ aWandererF);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 39U));
            aCarry = aCarry + (RotL64(aWandererC, 27U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererB, 43U);
            aCarry = aCarry + RotL64(aIngress, 48U);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 31385U)) & S_BLOCK1], 28U) ^ RotL64(aKeyRowReadA[((aIndex + 30380U)) & W_KEY1], 57U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 31559U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31135U)) & S_BLOCK1], 19U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30552U)) & S_BLOCK1], 47U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 30876U)) & W_KEY1], 28U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 23U) ^ RotL64(aCarry, 3U)) + (RotL64(aIngress, 54U) ^ RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = (aWandererE + RotL64(aCross, 29U)) + 9080426856729228705U;
            aOrbiterB = ((aWandererC + RotL64(aIngress, 23U)) + 7851218321653539276U) + aPhaseDOrbiterAssignSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterC = (aWandererH + RotL64(aPrevious, 46U)) + 7023344692919298036U;
            aOrbiterH = (aWandererF + RotL64(aScatter, 35U)) + 9772846154227440734U;
            aOrbiterA = (aWandererI + RotL64(aIngress, 19U)) + 12008298632429608431U;
            aOrbiterF = (aWandererG + RotL64(aCross, 57U)) + 12201090455849562875U;
            aOrbiterE = (((aWandererD + RotL64(aScatter, 12U)) + RotL64(aCarry, 53U)) + 9498721803411445471U) + aPhaseDOrbiterAssignSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = ((aWandererB + RotL64(aPrevious, 5U)) + RotL64(aCarry, 3U)) + 351203764023093632U;
            aOrbiterG = ((aWandererK + RotL64(aCross, 51U)) + RotL64(aCarry, 21U)) + 4966360430644539250U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 9194167899071345693U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 4922477697284269116U;
            aOrbiterC = RotL64((aOrbiterC * 8444814161720407881U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 15742625291642356429U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 7528703106518431730U;
            aOrbiterA = RotL64((aOrbiterA * 11530049278751507567U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 15279053574704935317U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 2425839793660355555U;
            aOrbiterH = RotL64((aOrbiterH * 11486964816849830667U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 13209849392400008898U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 9041500097716231309U;
            aOrbiterJ = RotL64((aOrbiterJ * 340661035700748739U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 7885423750878814599U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 1992993999902904603U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 1478629826632201617U), 39U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 6120758615019314102U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 8529621625846992066U;
            aOrbiterG = RotL64((aOrbiterG * 8485991471612862467U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 9125182130757385320U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 15691232622970220043U;
            aOrbiterF = RotL64((aOrbiterF * 16517916951054758147U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 11413090085435424697U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 11563151001080914939U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 16828196274450408201U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 1778975369262558069U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 3232132443557192010U;
            aOrbiterE = RotL64((aOrbiterE * 17132823737792200981U), 11U);
            //
            aIngress = RotL64(aOrbiterG, 57U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 53U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 47U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 6U));
            aIngress = aIngress + RotL64(aOrbiterE, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aPrevious, 37U) + aOrbiterA) + RotL64(aOrbiterF, 13U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 3U) + aOrbiterE) + RotL64(aOrbiterB, 6U));
            aWandererI = aWandererI + ((((RotL64(aIngress, 56U) + RotL64(aOrbiterJ, 43U)) + aOrbiterH) + RotL64(aCarry, 5U)) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 23U) + RotL64(aOrbiterG, 29U)) + aOrbiterE) + aPhaseDWandererUpdateSaltD[((aIndex + 23U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterD, 39U)) + aOrbiterH) + RotL64(aCarry, 51U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 47U) + aOrbiterA) + RotL64(aOrbiterD, 53U));
            aWandererK = aWandererK + ((RotL64(aScatter, 60U) + aOrbiterJ) + RotL64(aOrbiterE, 47U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 19U) + aOrbiterC) + RotL64(aOrbiterG, 19U));
            aWandererE = aWandererE + ((RotL64(aScatter, 13U) + aOrbiterD) + RotL64(aOrbiterC, 60U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 41U));
            aCarry = aCarry + (RotL64(aWandererI, 6U) ^ aWandererF);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 53U));
            aCarry = aCarry + RotL64(aWandererD, 13U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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

void TwistExpander_Hockey_Arx::Twist_B(TwistWorkSpace *pWorkSpace,
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
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneA, aExpandLaneC, aExpandLaneD, aInvestLaneC, aFireLaneC, aInvestLaneD, aFireLaneB, aOperationLaneA, aFireLaneD, aOperationLaneB, aOperationLaneC
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 564U)) & S_BLOCK1], 24U) ^ RotL64(aExpandLaneB[((aIndex + 4362U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 1394U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 1966U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 743U)) & S_BLOCK1], 42U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 51U) ^ RotL64(aIngress, 34U)) + (RotL64(aCross, 5U) ^ RotL64(aPrevious, 21U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterI = ((aWandererH + RotL64(aCross, 5U)) + RotL64(aCarry, 19U)) + 12131317914288566437U;
            aOrbiterF = (aWandererJ + RotL64(aPrevious, 41U)) + 5672805657999385496U;
            aOrbiterC = ((aWandererI + RotL64(aScatter, 35U)) + 3581710244233124197U) + aPhaseEOrbiterAssignSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterH = ((aWandererC + RotL64(aIngress, 27U)) + RotL64(aCarry, 5U)) + 15251296040538489436U;
            aOrbiterD = ((aWandererB + RotL64(aScatter, 13U)) + RotL64(aCarry, 43U)) + 11295008604679904153U;
            aOrbiterJ = (aWandererE + RotL64(aPrevious, 47U)) + 2230897493419504490U;
            aOrbiterK = ((aWandererG + RotL64(aIngress, 20U)) + 7109600123297458999U) + aPhaseEOrbiterAssignSaltA[((aIndex + 9U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 13119156643107683803U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 14755160867807355250U;
            aOrbiterC = RotL64((aOrbiterC * 10007087518844899239U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 16829363373287496832U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 16981122946707720883U;
            aOrbiterF = RotL64((aOrbiterF * 5394974422201576627U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 8806000776958603317U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 16810923047720876014U;
            aOrbiterJ = RotL64((aOrbiterJ * 17872735050219539145U), 37U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 8129657889554436328U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 8653100378491974463U;
            aOrbiterD = RotL64((aOrbiterD * 11395283153912468661U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 17048985838727432415U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 10892675550889823573U;
            aOrbiterK = RotL64((aOrbiterK * 976298937314081913U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 15960158965421254346U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 12290011578634850001U;
            aOrbiterI = RotL64((aOrbiterI * 9280475585104357745U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 16265047040311479093U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 10312956912303656248U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 3012584393253845131U), 43U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterJ, 4U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 41U));
            aIngress = aIngress + (RotL64(aOrbiterI, 57U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterD, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aScatter, 47U) + aOrbiterD) + RotL64(aOrbiterC, 53U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterC, 47U)) + aOrbiterK);
            aWandererI = aWandererI + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterD, 21U)) + aOrbiterK) + aPhaseEWandererUpdateSaltC[((aIndex + 21U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 12U) + RotL64(aOrbiterJ, 13U)) + aOrbiterF);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 23U) + aOrbiterI) + RotL64(aOrbiterC, 29U)) + RotL64(aCarry, 43U)) + aPhaseEWandererUpdateSaltA[((aIndex + 23U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterF, 4U)) + aOrbiterI);
            aWandererG = aWandererG + (((RotL64(aIngress, 41U) + RotL64(aOrbiterC, 35U)) + aOrbiterH) + RotL64(aCarry, 23U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 27U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererJ, 60U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererE, 39U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererC, 51U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = (RotL64(aInvestLaneC[((aIndex + 8168U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneC[((aIndex + 10316U)) & S_BLOCK1], 24U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 10096U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 10789U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 5968U)) & S_BLOCK1], 44U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 39U) ^ RotL64(aCarry, 6U)) + (RotL64(aCross, 57U) + RotL64(aPrevious, 19U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterC = ((aWandererG + RotL64(aIngress, 43U)) + RotL64(aCarry, 3U)) + 13924571355038625040U;
            aOrbiterA = (aWandererH + RotL64(aCross, 50U)) + 16328300979357156658U;
            aOrbiterD = ((aWandererD + RotL64(aPrevious, 11U)) + RotL64(aCarry, 53U)) + 3947771961206012461U;
            aOrbiterE = (aWandererI + RotL64(aScatter, 37U)) + 15428284250569311285U;
            aOrbiterK = ((aWandererE + RotL64(aIngress, 29U)) + 5777369485254032486U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterJ = ((aWandererK + RotL64(aScatter, 57U)) + RotL64(aCarry, 27U)) + 16813320300717644673U;
            aOrbiterB = ((aWandererJ + RotL64(aCross, 21U)) + 16689933050200758251U) + aPhaseEOrbiterAssignSaltD[((aIndex + 29U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 1856422419049390708U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 18214498743831925517U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 10744120577560529379U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 18278550878494094923U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 797712062039591797U;
            aOrbiterK = RotL64((aOrbiterK * 7212998747080137625U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 15854849439012341347U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 996882939768167773U;
            aOrbiterE = RotL64((aOrbiterE * 14936703950807908575U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 3005829974130671692U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 8793495343509953906U;
            aOrbiterC = RotL64((aOrbiterC * 14065479348374612031U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 7710453029930631112U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 9511995836117707047U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7250766204781428201U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 670902975693341744U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 9045820304668279777U;
            aOrbiterB = RotL64((aOrbiterB * 18373074917532639027U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 12417212387607119470U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 12816983560669985622U;
            aOrbiterJ = RotL64((aOrbiterJ * 8406003970221889847U), 51U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterA, 5U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 12U));
            aIngress = aIngress + (RotL64(aOrbiterC, 57U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterJ, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aCross, 5U) + RotL64(aOrbiterA, 27U)) + aOrbiterC) + RotL64(aCarry, 47U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 11U) + aOrbiterA) + RotL64(aOrbiterK, 3U));
            aWandererD = aWandererD + ((RotL64(aScatter, 27U) + RotL64(aOrbiterE, 35U)) + aOrbiterK);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 35U) + RotL64(aOrbiterD, 21U)) + aOrbiterC) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aScatter, 54U) + aOrbiterJ) + RotL64(aOrbiterD, 57U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterK, 50U)) + aOrbiterD);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 19U) + aOrbiterJ) + RotL64(aOrbiterB, 13U)) + RotL64(aCarry, 13U)) + aPhaseEWandererUpdateSaltE[((aIndex + 28U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 26U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 51U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 19U));
            aCarry = aCarry + RotL64(aWandererK, 3U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aInvestLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_b loop 3
        // ingress from: aInvestLaneD, aExpandLaneD, aFireLaneB
        // ingress directions: aInvestLaneD forward forced, aExpandLaneD forward forced, aFireLaneB forward/backward random
        // cross from: aInvestLaneC, aExpandLaneB, aExpandLaneA
        // cross directions: aInvestLaneC backward forced, aExpandLaneB backward forced, aExpandLaneA backward/forward random
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneD[((aIndex + 14372U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneD[((aIndex + 14880U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 15814U)) & S_BLOCK1], 20U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 15289U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 14252U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 15222U)) & S_BLOCK1], 54U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 57U) ^ RotL64(aCarry, 5U)) ^ (RotL64(aCross, 28U) + RotL64(aIngress, 43U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterF = (aWandererK + RotL64(aPrevious, 23U)) + 5295352595333316211U;
            aOrbiterJ = ((aWandererI + RotL64(aScatter, 37U)) + RotL64(aCarry, 13U)) + 2341795367042042605U;
            aOrbiterA = ((aWandererG + RotL64(aIngress, 3U)) + RotL64(aCarry, 27U)) + 10122175780504033663U;
            aOrbiterB = ((aWandererB + RotL64(aCross, 44U)) + RotL64(aCarry, 57U)) + 10084612804696198554U;
            aOrbiterE = ((aWandererD + RotL64(aPrevious, 53U)) + 16470424309851045971U) + aPhaseEOrbiterAssignSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterD = (aWandererH + RotL64(aIngress, 29U)) + 656016130975227994U;
            aOrbiterH = ((aWandererC + RotL64(aScatter, 13U)) + 15313268829659834317U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 3795220914993923394U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 14044442220988813825U;
            aOrbiterA = RotL64((aOrbiterA * 3270650852546606835U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 3804224626734584802U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 7980006306010255693U;
            aOrbiterB = RotL64((aOrbiterB * 13958505239726088561U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 13746830564584711549U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 11852212099729274845U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2164880979318247855U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 9083223471018084847U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 13706723820703853346U;
            aOrbiterF = RotL64((aOrbiterF * 11361854103656219887U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 1713819986642275223U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 1382000168233902914U;
            aOrbiterE = RotL64((aOrbiterE * 3894160765130198157U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 4540474625764565485U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 1756168174375757220U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 12739160208010092017U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 1409297070183609309U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 6082750101445444357U;
            aOrbiterJ = RotL64((aOrbiterJ * 17438740230251860935U), 29U);
            //
            aIngress = RotL64(aOrbiterB, 35U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterF, 13U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 3U));
            aIngress = aIngress + RotL64(aOrbiterJ, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aIngress, 47U) + aOrbiterF) + RotL64(aOrbiterH, 47U));
            aWandererC = aWandererC + (((RotL64(aScatter, 27U) + RotL64(aOrbiterB, 13U)) + aOrbiterE) + RotL64(aCarry, 37U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterJ, 3U)) + aOrbiterF);
            aWandererD = aWandererD + ((((RotL64(aCross, 57U) + RotL64(aOrbiterB, 29U)) + aOrbiterF) + RotL64(aCarry, 5U)) + aPhaseEWandererUpdateSaltD[((aIndex + 17U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 41U) + aOrbiterA) + RotL64(aOrbiterF, 21U));
            aWandererK = aWandererK + (((RotL64(aIngress, 10U) + RotL64(aOrbiterA, 37U)) + aOrbiterJ) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 35U) + aOrbiterD) + RotL64(aOrbiterE, 60U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 60U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererI, 19U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererC, 53U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererG, 41U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_b loop 4
        // ingress from: aOperationLaneA, aInvestLaneC, aFireLaneD
        // ingress directions: aOperationLaneA forward forced, aInvestLaneC forward forced, aFireLaneD forward/backward random
        // cross from: aInvestLaneD, aExpandLaneD, aExpandLaneC
        // cross directions: aInvestLaneD backward forced, aExpandLaneD backward forced, aExpandLaneC backward/forward random
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 18504U)) & S_BLOCK1], 51U) ^ RotL64(aInvestLaneC[((aIndex + 20496U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 20374U)) & S_BLOCK1], 4U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 21808U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 18925U)) & S_BLOCK1], 52U));
            aCross ^= RotL64(aExpandLaneC[((aIndex + 16498U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 52U) ^ RotL64(aIngress, 35U)) + (RotL64(aPrevious, 21U) + RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterE = ((aWandererE + RotL64(aScatter, 43U)) + RotL64(aCarry, 51U)) + 12809562813316740345U;
            aOrbiterH = (aWandererF + RotL64(aPrevious, 35U)) + 17084212535326321199U;
            aOrbiterA = ((aWandererB + RotL64(aCross, 27U)) + 16074921689983846769U) + aPhaseEOrbiterAssignSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterK = ((aWandererJ + RotL64(aIngress, 60U)) + RotL64(aCarry, 23U)) + 14027986153007120145U;
            aOrbiterC = ((aWandererG + RotL64(aPrevious, 53U)) + 7633455951809250227U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterF = (aWandererK + RotL64(aScatter, 13U)) + 340989348513370174U;
            aOrbiterG = ((aWandererH + RotL64(aCross, 5U)) + RotL64(aCarry, 39U)) + 5307820377645020116U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 5605285015771527274U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 5293500434746182790U;
            aOrbiterA = RotL64((aOrbiterA * 17674669610895537063U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 7263156475892261811U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 10672879570907433005U;
            aOrbiterF = RotL64((aOrbiterF * 2506338667179450741U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 16659226780900986107U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 9774892622769850665U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7487477727543183211U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 10728057184108279042U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 5032485856947407217U;
            aOrbiterG = RotL64((aOrbiterG * 16651577903809154285U), 21U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 14642241075374862345U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 8386481273395203518U;
            aOrbiterE = RotL64((aOrbiterE * 11649977733867003445U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 2874153265304098104U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 11519900149177261000U;
            aOrbiterK = RotL64((aOrbiterK * 2010158758971864505U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 8885690878540115768U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 4482143389870987714U;
            aOrbiterH = RotL64((aOrbiterH * 7105332459437434281U), 53U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterK, 27U);
            aIngress = aIngress + (RotL64(aOrbiterC, 19U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 57U));
            aIngress = aIngress + RotL64(aOrbiterG, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aIngress, 35U) + aOrbiterC) + RotL64(aOrbiterH, 3U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterE, 13U)) + aOrbiterA) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aCross, 41U) + RotL64(aOrbiterE, 35U)) + aOrbiterC) + RotL64(aCarry, 47U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterG, 44U)) + aOrbiterK);
            aWandererF = aWandererF + (((RotL64(aPrevious, 60U) + RotL64(aOrbiterA, 51U)) + aOrbiterH) + RotL64(aCarry, 27U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 51U) + aOrbiterF) + RotL64(aOrbiterC, 23U));
            aWandererJ = aWandererJ + ((RotL64(aCross, 27U) + RotL64(aOrbiterG, 29U)) + aOrbiterH);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 44U));
            aCarry = aCarry + (RotL64(aWandererH, 23U) ^ aWandererF);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 3U));
            aCarry = aCarry + RotL64(aWandererB, 53U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 26406U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneA[((aIndex + 25735U)) & S_BLOCK1], 46U));
            aIngress ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 24223U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 22131U)) & S_BLOCK1], 35U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 22967U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 23430U)) & S_BLOCK1], 18U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 41U) + RotL64(aPrevious, 19U)) + (RotL64(aCarry, 56U) ^ RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterC = (aWandererB + RotL64(aPrevious, 11U)) + 5088525177670191619U;
            aOrbiterJ = (aWandererG + RotL64(aIngress, 28U)) + 9966456257813932112U;
            aOrbiterG = ((aWandererD + RotL64(aCross, 43U)) + RotL64(aCarry, 35U)) + 7707646574027146307U;
            aOrbiterK = ((aWandererK + RotL64(aScatter, 57U)) + RotL64(aCarry, 21U)) + 75480203757681173U;
            aOrbiterA = ((aWandererH + RotL64(aIngress, 19U)) + 384659134071835163U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = ((aWandererI + RotL64(aPrevious, 51U)) + RotL64(aCarry, 47U)) + 3158769775373307778U;
            aOrbiterD = ((aWandererE + RotL64(aCross, 35U)) + 17360830943513941272U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 5317278822721604586U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 1371427105215954781U;
            aOrbiterG = RotL64((aOrbiterG * 10956603063464438611U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 3162710551223553423U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 5332921933853550756U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11709546145149357887U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 10572462410297815854U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 10234389605554817892U;
            aOrbiterK = RotL64((aOrbiterK * 2130374833440291193U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 13421365517991380605U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 10186643614984034083U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 8554471709467808453U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 4742438973260817120U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 6081590345899008846U;
            aOrbiterJ = RotL64((aOrbiterJ * 7069396301823124931U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 15360092808493795340U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 12186413069553132646U;
            aOrbiterC = RotL64((aOrbiterC * 3815981440611914267U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 16756221656224451552U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 12232880965861373143U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 14196910735715726471U), 35U);
            //
            aIngress = RotL64(aOrbiterC, 19U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 41U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 35U));
            aIngress = aIngress + RotL64(aOrbiterJ, 58U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterB, 29U)) + aOrbiterJ);
            aWandererG = aWandererG + (((RotL64(aScatter, 13U) + RotL64(aOrbiterG, 39U)) + aOrbiterK) + RotL64(aCarry, 51U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterD, 57U)) + aOrbiterK);
            aWandererH = aWandererH + (((RotL64(aCross, 58U) + RotL64(aOrbiterC, 47U)) + aOrbiterB) + aPhaseEWandererUpdateSaltF[((aIndex + 16U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 27U) + RotL64(aOrbiterA, 12U)) + aOrbiterK) + aPhaseEWandererUpdateSaltE[((aIndex + 15U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 51U) + aOrbiterD) + RotL64(aOrbiterA, 3U)) + RotL64(aCarry, 3U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterK, 23U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererI, 26U) ^ aWandererB);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 13U));
            aCarry = aCarry + (RotL64(aWandererH, 57U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererK, 43U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 28844U)) & S_BLOCK1], 34U) ^ RotL64(aExpandLaneA[((aIndex + 32320U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 29317U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28281U)) & S_BLOCK1], 58U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 29303U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 30614U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 11U) ^ RotL64(aPrevious, 56U)) + (RotL64(aCarry, 27U) + RotL64(aIngress, 43U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterJ = (aWandererF + RotL64(aScatter, 23U)) + 12849591986267890852U;
            aOrbiterI = (aWandererC + RotL64(aIngress, 47U)) + 8232614804696815750U;
            aOrbiterH = ((aWandererI + RotL64(aCross, 3U)) + RotL64(aCarry, 11U)) + 12141567259210877281U;
            aOrbiterE = ((aWandererG + RotL64(aPrevious, 11U)) + 2928641981037885644U) + aPhaseEOrbiterAssignSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = ((aWandererE + RotL64(aScatter, 53U)) + RotL64(aCarry, 57U)) + 980733350554783938U;
            aOrbiterF = ((aWandererK + RotL64(aPrevious, 29U)) + 2683985177993350746U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = ((aWandererA + RotL64(aIngress, 38U)) + RotL64(aCarry, 41U)) + 14532148403815527355U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 7736296629433884203U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 10428437770166310549U;
            aOrbiterH = RotL64((aOrbiterH * 326634742742373401U), 21U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 18327174144859461029U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 6810436935194432002U;
            aOrbiterB = RotL64((aOrbiterB * 2715987179577753597U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 12606153309690753435U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 17123256945895150555U;
            aOrbiterC = RotL64((aOrbiterC * 13469111258504672565U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 9057777759026189541U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 16478485918911194442U;
            aOrbiterF = RotL64((aOrbiterF * 11054247078884894131U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 18064460487552100483U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 11477276762421684083U;
            aOrbiterJ = RotL64((aOrbiterJ * 3886501230380184395U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 18318375441973295081U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 13849305985380030986U;
            aOrbiterI = RotL64((aOrbiterI * 12962140243967824959U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 10240409420338313641U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 18360586077779529086U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 18196875422391501927U), 29U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterI, 39U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 29U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 47U));
            aIngress = aIngress + RotL64(aOrbiterC, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aCross, 53U) + aOrbiterE) + RotL64(aOrbiterC, 11U));
            aWandererC = aWandererC + ((((RotL64(aPrevious, 35U) + aOrbiterC) + RotL64(aOrbiterJ, 51U)) + RotL64(aCarry, 51U)) + aPhaseEWandererUpdateSaltB[((aIndex + 18U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 21U) + RotL64(aOrbiterF, 35U)) + aOrbiterB) + aPhaseEWandererUpdateSaltD[((aIndex + 12U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aIngress, 47U) + RotL64(aOrbiterI, 19U)) + aOrbiterJ);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 27U) + aOrbiterH) + RotL64(aOrbiterF, 3U));
            aWandererF = aWandererF + (((RotL64(aScatter, 60U) + RotL64(aOrbiterI, 60U)) + aOrbiterE) + RotL64(aCarry, 21U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 5U) + aOrbiterH) + RotL64(aOrbiterJ, 27U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 14U));
            aCarry = aCarry + (RotL64(aWandererA, 41U) ^ aWandererI);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 19U));
            aCarry = aCarry + RotL64(aWandererG, 37U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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

void TwistExpander_Hockey_Arx::Twist_C(TwistWorkSpace *pWorkSpace,
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
        // read from: aOperationLaneA, aOperationLaneB, aInvestLaneD, aOperationLaneC, aOperationLaneD, aInvestLaneA, aSnowLaneA, aExpandLaneA, aInvestLaneB, aSnowLaneB, aExpandLaneC, aWorkLaneA, aInvestLaneC, aWorkLaneB, aExpandLaneB, aWorkLaneC, aExpandLaneD
        // write to: aSnowLaneA, aSnowLaneB, aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // twist_loop_c loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aInvestLaneD
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aInvestLaneD forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aInvestLaneA
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aInvestLaneA backward/forward random
        // write to: aSnowLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 3564U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneB[((aIndex + 2552U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aInvestLaneD[((aIndex + 2864U)) & S_BLOCK1], 38U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 672U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 701U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aInvestLaneA[((aIndex + 2468U)) & S_BLOCK1], 56U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 51U) ^ RotL64(aCarry, 3U)) + (RotL64(aCross, 38U) ^ RotL64(aPrevious, 21U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterK = (aWandererB + RotL64(aPrevious, 51U)) + 1898718075389870739U;
            aOrbiterJ = (aWandererE + RotL64(aScatter, 11U)) + 5631794889237247403U;
            aOrbiterA = ((aWandererJ + RotL64(aIngress, 19U)) + RotL64(aCarry, 21U)) + 18219714659484524607U;
            aOrbiterB = ((aWandererF + RotL64(aCross, 47U)) + RotL64(aCarry, 37U)) + 15419581386225732921U;
            aOrbiterF = ((aWandererG + RotL64(aScatter, 36U)) + RotL64(aCarry, 3U)) + 9125575431710198210U;
            aOrbiterI = ((aWandererD + RotL64(aPrevious, 39U)) + 12205871520544965505U) + aPhaseFOrbiterAssignSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterC = (aWandererH + RotL64(aCross, 41U)) + 7617534300497343422U;
            aOrbiterD = (aWandererA + RotL64(aIngress, 23U)) + 18017579105368135814U;
            aOrbiterG = (aWandererK + RotL64(aCross, 27U)) + 10693882161946020042U;
            aOrbiterH = (aWandererI + RotL64(aPrevious, 57U)) + 11669615701700895306U;
            aOrbiterE = ((aWandererC + RotL64(aScatter, 14U)) + 11045110212889232165U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 18019107802806469913U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 12315940560472528716U;
            aOrbiterA = RotL64((aOrbiterA * 4505122470351404065U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 4899009736070044310U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 17412253404253730364U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10791901166391946485U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 4826286251927854181U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 4523455921321845084U;
            aOrbiterJ = RotL64((aOrbiterJ * 14534103906736598099U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 4132514462154182215U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 7164745605985109269U;
            aOrbiterG = RotL64((aOrbiterG * 14107325508977225261U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 6297434295807635654U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 8813887638672996646U;
            aOrbiterH = RotL64((aOrbiterH * 17495632530773158201U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 11086381278955626084U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 5660733992573928887U;
            aOrbiterK = RotL64((aOrbiterK * 11248164458720777889U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 14851044686208609882U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 12707776386060264479U;
            aOrbiterE = RotL64((aOrbiterE * 4470919091467313071U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 11508023384209716657U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 11752973809740920034U;
            aOrbiterB = RotL64((aOrbiterB * 10212754472298834769U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 16746821150860017820U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 9659421716296641396U;
            aOrbiterI = RotL64((aOrbiterI * 7530071874978553673U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 3192309064305104593U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 11409078048681398061U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14991409124701807765U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 315359495275427324U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 1898718075389870739U;
            aOrbiterD = RotL64((aOrbiterD * 13126661894614781343U), 39U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterI, 34U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 19U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 21U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 11U));
            aIngress = aIngress + (RotL64(aOrbiterA, 51U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterK, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aIngress, 18U) + aOrbiterB) + RotL64(aOrbiterG, 48U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterB, 21U)) + aOrbiterI);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 13U) + RotL64(aOrbiterB, 53U)) + aOrbiterA) + RotL64(aCarry, 23U)) + aPhaseFWandererUpdateSaltD[((aIndex + 12U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterF, 37U)) + aOrbiterG);
            aWandererH = aWandererH + (((RotL64(aCross, 43U) + RotL64(aOrbiterE, 35U)) + aOrbiterH) + RotL64(aCarry, 47U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 54U) + RotL64(aOrbiterB, 18U)) + aOrbiterF);
            aWandererI = aWandererI + ((RotL64(aPrevious, 5U) + aOrbiterD) + RotL64(aOrbiterC, 5U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 57U) + aOrbiterD) + RotL64(aOrbiterJ, 29U));
            aWandererC = aWandererC + (((RotL64(aScatter, 37U) + aOrbiterD) + RotL64(aOrbiterE, 11U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 11U) + aOrbiterH) + RotL64(aOrbiterG, 13U));
            aWandererF = aWandererF + ((RotL64(aPrevious, 23U) + RotL64(aOrbiterK, 57U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 44U));
            aCarry = aCarry + (RotL64(aWandererC, 53U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererA);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 37U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 27U));
            aCarry = aCarry + RotL64(aWandererK, 34U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aSnowLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_c loop 2
        // ingress from: aSnowLaneA, aOperationLaneC, aOperationLaneD, aExpandLaneA
        // ingress directions: aSnowLaneA forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aExpandLaneA forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aInvestLaneB
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aInvestLaneB backward/forward random
        // write to: aSnowLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneA[((aIndex + 8353U)) & S_BLOCK1], 38U) ^ RotL64(aOperationLaneC[((aIndex + 9585U)) & S_BLOCK1], 53U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 5787U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneA[((aIndex + 7386U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 6009U)) & S_BLOCK1], 6U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 6573U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 6849U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 27U) + RotL64(aPrevious, 54U)) ^ (RotL64(aIngress, 5U) + RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterH = ((aWandererA + RotL64(aIngress, 60U)) + 3650233661228036955U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = (aWandererF + RotL64(aScatter, 19U)) + 11607036400067735729U;
            aOrbiterJ = (aWandererK + RotL64(aCross, 47U)) + 3899614406903883035U;
            aOrbiterI = (aWandererG + RotL64(aPrevious, 41U)) + 8159156925629965143U;
            aOrbiterC = ((aWandererJ + RotL64(aCross, 53U)) + RotL64(aCarry, 23U)) + 7148903913967261270U;
            aOrbiterG = (aWandererD + RotL64(aScatter, 35U)) + 9161665622287517848U;
            aOrbiterA = ((aWandererI + RotL64(aPrevious, 37U)) + RotL64(aCarry, 3U)) + 2981535013474059469U;
            aOrbiterE = ((aWandererH + RotL64(aIngress, 13U)) + 15812469008200319549U) + aPhaseFOrbiterAssignSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = (aWandererC + RotL64(aScatter, 28U)) + 14687469489893270300U;
            aOrbiterB = ((aWandererB + RotL64(aIngress, 57U)) + RotL64(aCarry, 13U)) + 6025209349511417063U;
            aOrbiterD = (aWandererE + RotL64(aPrevious, 43U)) + 12964750392311112676U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 6572355895765394340U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 3542300121890027981U;
            aOrbiterJ = RotL64((aOrbiterJ * 11201491178181273935U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 6477175684045398359U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 1081388388827929314U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8752188637514143529U), 37U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 13754328481584620771U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 3684673342659575917U;
            aOrbiterH = RotL64((aOrbiterH * 6139923312873039143U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 6542045150319909445U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 5352102692424060388U;
            aOrbiterG = RotL64((aOrbiterG * 7385758355501860261U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 9110100774657340354U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 2813273684436269057U;
            aOrbiterF = RotL64((aOrbiterF * 10468759062594022273U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 5860425751137403755U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 1598622981888978548U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 651816500461718345U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 14710305692377606725U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 16280545617802383463U;
            aOrbiterB = RotL64((aOrbiterB * 12541767206978802063U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 6849565243667718750U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 12152381961996750050U;
            aOrbiterC = RotL64((aOrbiterC * 11185935780063403807U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 1318947876257794796U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 5447559252769140391U;
            aOrbiterD = RotL64((aOrbiterD * 13683733413554766327U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 2766869582494246454U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 15757729967222729304U;
            aOrbiterA = RotL64((aOrbiterA * 1858683399257513171U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 13063432816787882618U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 3650233661228036955U;
            aOrbiterI = RotL64((aOrbiterI * 16230564672533821641U), 47U);
            //
            aIngress = RotL64(aOrbiterC, 39U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterF, 19U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 29U));
            aIngress = aIngress + (RotL64(aOrbiterA, 21U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 35U));
            aIngress = aIngress + RotL64(aOrbiterG, 60U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aCross, 43U) + aOrbiterC) + RotL64(aOrbiterH, 37U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 53U) + aOrbiterD) + RotL64(aOrbiterG, 27U)) + RotL64(aCarry, 11U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 10U) + RotL64(aOrbiterB, 53U)) + aOrbiterD);
            aWandererD = aWandererD + ((RotL64(aScatter, 19U) + aOrbiterK) + RotL64(aOrbiterG, 39U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 35U) + aOrbiterD) + RotL64(aOrbiterK, 41U));
            aWandererE = aWandererE + ((RotL64(aPrevious, 21U) + aOrbiterA) + RotL64(aOrbiterJ, 12U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterA, 51U)) + aOrbiterF) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 29U) + RotL64(aOrbiterK, 43U)) + aOrbiterE);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 27U) + aOrbiterI) + RotL64(aOrbiterC, 21U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 13U) + RotL64(aOrbiterB, 14U)) + aOrbiterC) + RotL64(aCarry, 37U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 4U) + RotL64(aOrbiterD, 23U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererH, 10U) ^ aWandererB);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 53U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 21U));
            aCarry = aCarry + (RotL64(aWandererC, 3U) ^ aWandererE);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 37U));
            aCarry = aCarry + RotL64(aWandererA, 27U);
            aCarry = aCarry + RotL64(aIngress, 14U);
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
            aIngress = (RotL64(aSnowLaneB[((aIndex + 12571U)) & S_BLOCK1], 20U) ^ RotL64(aOperationLaneA[((aIndex + 16012U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 16094U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 14951U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 14176U)) & S_BLOCK1], 40U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 57U) ^ RotL64(aPrevious, 43U)) ^ (RotL64(aCross, 13U) + RotL64(aIngress, 30U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterD = (aWandererF + RotL64(aPrevious, 3U)) + 5173905450211892891U;
            aOrbiterG = ((aWandererJ + RotL64(aScatter, 47U)) + 3555542451908039957U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = (aWandererH + RotL64(aIngress, 41U)) + 11559884700283861559U;
            aOrbiterJ = (aWandererC + RotL64(aCross, 57U)) + 1352524329968738673U;
            aOrbiterF = (((aWandererB + RotL64(aIngress, 27U)) + RotL64(aCarry, 51U)) + 8914206450420616349U) + aPhaseFOrbiterAssignSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = (aWandererI + RotL64(aPrevious, 14U)) + 2251523378498463946U;
            aOrbiterK = (aWandererG + RotL64(aCross, 29U)) + 9541575923299247038U;
            aOrbiterH = ((aWandererA + RotL64(aScatter, 23U)) + RotL64(aCarry, 41U)) + 1239854507907214595U;
            aOrbiterI = (aWandererD + RotL64(aCross, 37U)) + 17698101462598498934U;
            aOrbiterA = ((aWandererK + RotL64(aPrevious, 44U)) + RotL64(aCarry, 19U)) + 12305566971683256060U;
            aOrbiterC = (aWandererE + RotL64(aScatter, 35U)) + 13804545036303215569U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 10239749097704329264U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 4212214906286320308U;
            aOrbiterE = RotL64((aOrbiterE * 3661436621615751071U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 12192418916967430783U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 4475514289326450361U;
            aOrbiterB = RotL64((aOrbiterB * 17497164630368757887U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 17376102613298827459U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 18129393209955439341U;
            aOrbiterH = RotL64((aOrbiterH * 6404089025014118979U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 4014763724300253568U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 17325007199676828814U;
            aOrbiterG = RotL64((aOrbiterG * 1420888274815627083U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 15480474849292388685U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 14357924730184375449U;
            aOrbiterA = RotL64((aOrbiterA * 16723492259068034209U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 4335731868597970070U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 8296023680394303015U;
            aOrbiterI = RotL64((aOrbiterI * 14027415401430120543U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 2807312426993262800U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 15510369660839648501U;
            aOrbiterJ = RotL64((aOrbiterJ * 18207954408298333959U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 12597844696606519907U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 7231012798553551535U;
            aOrbiterK = RotL64((aOrbiterK * 2841306785994479299U), 37U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 849663631945232360U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 4002310581470781194U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2148877014350721479U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 16067735571435654555U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 4607980694199923842U;
            aOrbiterF = RotL64((aOrbiterF * 10401780756830017477U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 5346879191913449715U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 5173905450211892891U;
            aOrbiterC = RotL64((aOrbiterC * 15360571827429301833U), 53U);
            //
            aIngress = RotL64(aOrbiterE, 35U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 46U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 23U));
            aIngress = aIngress + (RotL64(aOrbiterD, 41U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 29U));
            aIngress = aIngress + RotL64(aOrbiterG, 38U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aIngress, 41U) + RotL64(aOrbiterB, 3U)) + aOrbiterJ);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 3U) + aOrbiterB) + RotL64(aOrbiterE, 34U)) + aPhaseFWandererUpdateSaltF[((aIndex + 26U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 60U) + RotL64(aOrbiterI, 21U)) + aOrbiterH) + RotL64(aCarry, 27U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 23U) + RotL64(aOrbiterK, 41U)) + aOrbiterC) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aIngress, 5U) + aOrbiterC) + RotL64(aOrbiterG, 43U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterF, 39U)) + aOrbiterA);
            aWandererC = aWandererC + (((RotL64(aPrevious, 37U) + RotL64(aOrbiterJ, 27U)) + aOrbiterG) + RotL64(aCarry, 51U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterD, 37U)) + aOrbiterF);
            aWandererK = aWandererK + ((RotL64(aIngress, 57U) + aOrbiterF) + RotL64(aOrbiterK, 13U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 46U) + RotL64(aOrbiterH, 58U)) + aOrbiterB);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 21U) + aOrbiterC) + RotL64(aOrbiterA, 5U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 40U));
            aCarry = aCarry + (RotL64(aWandererF, 51U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererC, 37U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererD, 3U) ^ aWandererJ);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 21U));
            aCarry = aCarry + RotL64(aWandererH, 5U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_c loop 4
        // ingress from: aWorkLaneA, aSnowLaneA, aInvestLaneC
        // ingress directions: aWorkLaneA forward forced, aSnowLaneA forward forced, aInvestLaneC forward/backward random
        // cross from: aSnowLaneB, aOperationLaneD
        // cross directions: aSnowLaneB backward forced, aOperationLaneD backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 16804U)) & S_BLOCK1], 21U) ^ RotL64(aSnowLaneA[((aIndex + 20488U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aInvestLaneC[((aIndex + 20418U)) & S_BLOCK1], 56U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 21789U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 19466U)) & S_BLOCK1], 34U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 18U) ^ RotL64(aCross, 5U)) + (RotL64(aCarry, 51U) + RotL64(aIngress, 37U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterD = ((aWandererI + RotL64(aPrevious, 39U)) + RotL64(aCarry, 51U)) + 13915875634607599122U;
            aOrbiterE = ((aWandererA + RotL64(aScatter, 21U)) + RotL64(aCarry, 27U)) + 1695770381382411673U;
            aOrbiterC = (aWandererE + RotL64(aCross, 60U)) + 3709105579778295511U;
            aOrbiterF = (aWandererD + RotL64(aIngress, 37U)) + 7673376335333251804U;
            aOrbiterH = (aWandererK + RotL64(aScatter, 13U)) + 8814147709738503518U;
            aOrbiterI = (aWandererB + RotL64(aIngress, 47U)) + 13451412605350381172U;
            aOrbiterJ = ((aWandererC + RotL64(aCross, 57U)) + RotL64(aCarry, 5U)) + 6447870234069609538U;
            aOrbiterK = ((aWandererJ + RotL64(aPrevious, 43U)) + 13419487997946496825U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterB = (aWandererH + RotL64(aCross, 18U)) + 5478309847615220345U;
            aOrbiterA = ((aWandererG + RotL64(aPrevious, 53U)) + 3635184969215610049U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterG = (aWandererF + RotL64(aIngress, 29U)) + 12527903812035294828U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 1684685110885338814U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 12860354576326835090U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12743745087733307255U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 9081823570147481835U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 14369321778210049109U;
            aOrbiterH = RotL64((aOrbiterH * 17865953349448767035U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 11518132079084873250U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 11893535026126957389U;
            aOrbiterK = RotL64((aOrbiterK * 15751374986135615095U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 7084079180579206226U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 2999676609847603277U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 14602698397511266403U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 17683445810614029153U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 11576460512964896969U;
            aOrbiterA = RotL64((aOrbiterA * 5243651036457051155U), 23U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 13429800604736567949U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 14661785761747367546U;
            aOrbiterG = RotL64((aOrbiterG * 4765843989277333421U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 12837164345582888950U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 6222666313184669392U;
            aOrbiterE = RotL64((aOrbiterE * 17402483466567712319U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 5358647039491079457U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 12459911673401497180U;
            aOrbiterB = RotL64((aOrbiterB * 13605465035256188065U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 3333017644772803587U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 15501587702102554928U;
            aOrbiterJ = RotL64((aOrbiterJ * 4921693371641768339U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 8492287653837766613U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 3432736785678875404U;
            aOrbiterD = RotL64((aOrbiterD * 7326419883291516513U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 2841486107704281869U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 13915875634607599122U;
            aOrbiterI = RotL64((aOrbiterI * 707861617246345083U), 13U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterE, 46U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 21U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 39U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 43U));
            aIngress = aIngress + (RotL64(aOrbiterD, 3U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterH, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aPrevious, 51U) + RotL64(aOrbiterI, 47U)) + aOrbiterB);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterH, 50U)) + aOrbiterB);
            aWandererE = aWandererE + ((RotL64(aIngress, 46U) + aOrbiterD) + RotL64(aOrbiterI, 29U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterH, 23U)) + aOrbiterE);
            aWandererA = aWandererA + ((RotL64(aIngress, 35U) + RotL64(aOrbiterH, 37U)) + aOrbiterC);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterB, 19U)) + aOrbiterJ);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 14U) + RotL64(aOrbiterG, 39U)) + aOrbiterA) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterF, 41U)) + aOrbiterE);
            aWandererC = aWandererC + (((RotL64(aIngress, 19U) + aOrbiterK) + RotL64(aOrbiterF, 3U)) + RotL64(aCarry, 27U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterG, 6U)) + aOrbiterK);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 29U) + RotL64(aOrbiterA, 13U)) + aOrbiterH) + RotL64(aCarry, 53U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 5U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererF, 35U) ^ aWandererK);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 43U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 40U));
            aCarry = aCarry + (RotL64(aWandererG, 3U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererH, 19U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_c loop 5
        // ingress from: aWorkLaneB, aSnowLaneB, aExpandLaneB
        // ingress directions: aWorkLaneB forward forced, aSnowLaneB forward forced, aExpandLaneB forward/backward random
        // cross from: aWorkLaneA, aSnowLaneA
        // cross directions: aWorkLaneA backward forced, aSnowLaneA backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 26093U)) & S_BLOCK1], 27U) ^ RotL64(aSnowLaneB[((aIndex + 22042U)) & S_BLOCK1], 12U));
            aIngress ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 21957U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 27002U)) & S_BLOCK1], 39U) ^ RotL64(aSnowLaneA[((aIndex + 22929U)) & S_BLOCK1], 20U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 21U) ^ RotL64(aCarry, 41U)) ^ (RotL64(aIngress, 57U) + RotL64(aCross, 6U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterI = ((aWandererC + RotL64(aIngress, 51U)) + 6521330037475130256U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = (aWandererE + RotL64(aPrevious, 19U)) + 12611880456055428940U;
            aOrbiterA = (aWandererG + RotL64(aScatter, 29U)) + 12061611078130934708U;
            aOrbiterK = (aWandererA + RotL64(aCross, 27U)) + 1558112410801116984U;
            aOrbiterC = (aWandererB + RotL64(aIngress, 41U)) + 10509115227850160786U;
            aOrbiterE = (aWandererD + RotL64(aPrevious, 21U)) + 4045915960688792066U;
            aOrbiterF = (((aWandererJ + RotL64(aScatter, 56U)) + RotL64(aCarry, 51U)) + 1196541286513243082U) + aPhaseFOrbiterAssignSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = ((aWandererK + RotL64(aCross, 5U)) + RotL64(aCarry, 13U)) + 15564991032722373702U;
            aOrbiterB = (aWandererH + RotL64(aScatter, 37U)) + 4897765238703641798U;
            aOrbiterG = (aWandererI + RotL64(aCross, 53U)) + 12327429514907752733U;
            aOrbiterJ = ((aWandererF + RotL64(aIngress, 60U)) + RotL64(aCarry, 21U)) + 6189189797708711636U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 6374267075282018852U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 1888758503831341439U;
            aOrbiterA = RotL64((aOrbiterA * 74387714918264257U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 14956857689299491800U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 14879361107223331957U;
            aOrbiterE = RotL64((aOrbiterE * 9166712966729591953U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 16086885494838105042U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 8069724185844303923U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8878470736758734353U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 10854345917959911439U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 7078313614360332089U;
            aOrbiterB = RotL64((aOrbiterB * 9864025732292844871U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 15083669236062255011U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 594879695916679116U;
            aOrbiterG = RotL64((aOrbiterG * 9852515479152735283U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 6721466068234534523U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 475816724162626782U;
            aOrbiterJ = RotL64((aOrbiterJ * 4799725182757588407U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 4341655358154605899U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 15477254302340298586U;
            aOrbiterI = RotL64((aOrbiterI * 13961520225881974201U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 10179091913200895775U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 6310490897546909571U;
            aOrbiterK = RotL64((aOrbiterK * 15080621088825477613U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 13462682513035460711U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 16739138858084100385U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 16386371811268298031U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 13608837667062268989U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 12902415667552110103U;
            aOrbiterH = RotL64((aOrbiterH * 16398790854093048017U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 16596211634603915761U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 6521330037475130256U;
            aOrbiterC = RotL64((aOrbiterC * 631958426544321145U), 37U);
            //
            aIngress = RotL64(aOrbiterA, 51U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterE, 57U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterG, 30U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterC, 27U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 53U));
            aIngress = aIngress + RotL64(aOrbiterB, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterF, 39U)) + aOrbiterA);
            aWandererH = aWandererH + ((RotL64(aScatter, 51U) + aOrbiterB) + RotL64(aOrbiterI, 35U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 21U) + aOrbiterE) + RotL64(aOrbiterD, 37U));
            aWandererI = aWandererI + (((RotL64(aIngress, 29U) + aOrbiterG) + RotL64(aOrbiterH, 29U)) + RotL64(aCarry, 3U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterA, 11U)) + aOrbiterI);
            aWandererG = aWandererG + (((RotL64(aCross, 10U) + RotL64(aOrbiterB, 26U)) + aOrbiterD) + aPhaseFWandererUpdateSaltE[((aIndex + 18U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterJ, 13U)) + aOrbiterC);
            aWandererA = aWandererA + ((RotL64(aPrevious, 57U) + aOrbiterI) + RotL64(aOrbiterG, 3U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 35U) + aOrbiterJ) + RotL64(aOrbiterF, 43U));
            aWandererB = aWandererB + ((((RotL64(aScatter, 60U) + RotL64(aOrbiterG, 60U)) + aOrbiterB) + RotL64(aCarry, 27U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 53U) + aOrbiterK) + RotL64(aOrbiterG, 41U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 26U) ^ aWandererI);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 51U));
            aCarry = aCarry + (RotL64(aWandererF, 53U) ^ aWandererB);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 29U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 44U));
            aCarry = aCarry + RotL64(aWandererE, 37U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // twist_loop_c loop 6
        // ingress from: aWorkLaneC, aWorkLaneA, aExpandLaneD
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aExpandLaneD forward/backward random
        // cross from: aWorkLaneB, aOperationLaneB
        // cross directions: aWorkLaneB backward forced, aOperationLaneB backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 28937U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneA[((aIndex + 30358U)) & S_BLOCK1], 54U));
            aIngress ^= RotL64(aExpandLaneD[((aIndex + 29733U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27721U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 27450U)) & S_BLOCK1], 34U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 11U) + RotL64(aCarry, 23U)) + (RotL64(aIngress, 52U) ^ RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterC = ((aWandererK + RotL64(aIngress, 35U)) + 12690502671561165478U) + aPhaseFOrbiterAssignSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = ((aWandererE + RotL64(aScatter, 53U)) + RotL64(aCarry, 39U)) + 17519943923428102801U;
            aOrbiterF = (aWandererD + RotL64(aCross, 13U)) + 10705515807975331385U;
            aOrbiterE = ((aWandererC + RotL64(aPrevious, 3U)) + RotL64(aCarry, 47U)) + 16586447272278538179U;
            aOrbiterK = (aWandererI + RotL64(aIngress, 46U)) + 8006560996840971798U;
            aOrbiterJ = (aWandererH + RotL64(aCross, 19U)) + 12928600185788857701U;
            aOrbiterH = ((aWandererG + RotL64(aPrevious, 39U)) + 14240723153798267172U) + aPhaseFOrbiterAssignSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterA = (aWandererA + RotL64(aScatter, 21U)) + 8636219177994872072U;
            aOrbiterG = ((aWandererF + RotL64(aCross, 57U)) + RotL64(aCarry, 19U)) + 7586790235186467512U;
            aOrbiterD = (aWandererJ + RotL64(aIngress, 26U)) + 1103807034179512424U;
            aOrbiterB = (aWandererB + RotL64(aScatter, 43U)) + 7547526530239498693U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 8380239679344786397U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 5690809173787433519U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 5354724308093372953U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 8390902801141804609U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 3507306189192059486U;
            aOrbiterJ = RotL64((aOrbiterJ * 18336280496510253103U), 39U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 6190745292098482871U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 8065418693975056902U;
            aOrbiterC = RotL64((aOrbiterC * 6414621418430102589U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 12111755051718111803U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 7605877769709909297U;
            aOrbiterE = RotL64((aOrbiterE * 17525248694315944599U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 5969794501112646237U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 5127559299360591476U;
            aOrbiterG = RotL64((aOrbiterG * 4521563633438853069U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 10593847754747739786U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 4401750688524310121U;
            aOrbiterD = RotL64((aOrbiterD * 14265829318976633707U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 6927893132508779499U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 4874009978647014479U;
            aOrbiterH = RotL64((aOrbiterH * 13340466017023540755U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 13146693487138744677U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 3298472134223595298U;
            aOrbiterK = RotL64((aOrbiterK * 2145005258008477281U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 8729305340729268734U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 18347161842033439538U;
            aOrbiterI = RotL64((aOrbiterI * 7952715248988302017U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 166831495912855225U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 4943633045563697271U;
            aOrbiterB = RotL64((aOrbiterB * 1809857625425000137U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 2460623715340753589U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 12690502671561165478U;
            aOrbiterA = RotL64((aOrbiterA * 16421139715633515623U), 19U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterJ, 35U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 13U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 18U));
            aIngress = aIngress + (RotL64(aOrbiterH, 47U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 57U));
            aIngress = aIngress + RotL64(aOrbiterB, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterA, 53U)) + aOrbiterK);
            aWandererB = aWandererB + ((RotL64(aPrevious, 37U) + RotL64(aOrbiterC, 60U)) + aOrbiterF);
            aWandererC = aWandererC ^ ((RotL64(aCross, 60U) + aOrbiterH) + RotL64(aOrbiterD, 21U));
            aWandererA = aWandererA + (((RotL64(aIngress, 29U) + aOrbiterJ) + RotL64(aOrbiterD, 37U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterB, 57U)) + aOrbiterF);
            aWandererF = aWandererF + (((RotL64(aIngress, 11U) + aOrbiterE) + RotL64(aOrbiterA, 13U)) + RotL64(aCarry, 23U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterG, 19U)) + aOrbiterJ);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 41U) + aOrbiterC) + RotL64(aOrbiterK, 29U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 14U) + RotL64(aOrbiterG, 43U)) + aOrbiterA);
            aWandererK = aWandererK + ((((RotL64(aScatter, 39U) + RotL64(aOrbiterE, 3U)) + aOrbiterJ) + RotL64(aCarry, 27U)) + aPhaseFWandererUpdateSaltF[((aIndex + 25U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 3U) + aOrbiterI) + RotL64(aOrbiterA, 26U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 10U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererA, 37U) ^ aWandererE);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 27U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 5U));
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererI, 19U);
            aCarry = aCarry + RotL64(aIngress, 12U);
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

void TwistExpander_Hockey_Arx::GROW_A(TwistWorkSpace *pWorkSpace,
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 3622U)) & S_BLOCK1], 40U) ^ RotL64(aWorkLaneB[((aIndex + 6600U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 4261U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 2101U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 5337U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 2794U)) & S_BLOCK1], 54U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 50U) ^ RotL64(aCarry, 37U)) ^ (RotL64(aPrevious, 23U) + RotL64(aCross, 11U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterH = ((aWandererD + RotL64(aIngress, 47U)) + 1888427424966603593U) + aPhaseGOrbiterAssignSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = (aWandererB + RotL64(aScatter, 27U)) + 5436761445660415091U;
            aOrbiterD = ((aWandererF + RotL64(aCross, 35U)) + RotL64(aCarry, 41U)) + 17322876217962143270U;
            aOrbiterG = ((aWandererG + RotL64(aPrevious, 5U)) + RotL64(aCarry, 57U)) + 9728299982740564979U;
            aOrbiterF = (((aWandererC + RotL64(aIngress, 56U)) + RotL64(aCarry, 29U)) + 301720335271716921U) + aPhaseGOrbiterAssignSaltA[((aIndex + 13U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 8069685428854814396U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 1973715500949100991U) ^ aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 7940531594430629427U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 87666408799854155U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 12195436904339035245U) ^ aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 15427739165893738105U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 4578742069143400295U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 7828776048774876484U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4047964518501081039U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 17203146364542781833U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 16913369550858890466U;
            aOrbiterG = RotL64((aOrbiterG * 13534417587921978507U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 9632761514552265402U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 9106637671877341286U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 9073709119482640391U), 27U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterF, 47U);
            aIngress = aIngress + (RotL64(aOrbiterD, 35U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterH, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aCross, 29U) + aOrbiterG) + RotL64(aOrbiterH, 27U)) + RotL64(aCarry, 27U)) + aPhaseGWandererUpdateSaltA[((aIndex + 3U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 5U) + aOrbiterD) + RotL64(aOrbiterG, 37U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterG, 19U)) + aOrbiterJ) + RotL64(aCarry, 51U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 37U) + aOrbiterJ) + RotL64(aOrbiterF, 4U));
            aWandererD = aWandererD + (((RotL64(aCross, 18U) + aOrbiterJ) + RotL64(aOrbiterD, 47U)) + aPhaseGWandererUpdateSaltD[((aIndex + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 47U));
            aCarry = aCarry + (RotL64(aWandererF, 39U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererB, 5U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 12739U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneB[((aIndex + 16110U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 8278U)) & S_BLOCK1], 12U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 12023U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 9774U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aWorkLaneD[((aIndex + 10095U)) & S_BLOCK1], 58U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 22U) + RotL64(aPrevious, 57U)) ^ (RotL64(aCross, 41U) ^ RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterB = ((aWandererA + RotL64(aScatter, 43U)) + RotL64(aCarry, 57U)) + 4259993311776766595U;
            aOrbiterF = ((aWandererG + RotL64(aIngress, 51U)) + RotL64(aCarry, 11U)) + 2857813330021126753U;
            aOrbiterE = (((aWandererI + RotL64(aCross, 35U)) + RotL64(aCarry, 27U)) + 1345396841329442896U) + aPhaseGOrbiterAssignSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterC = ((aWandererJ + RotL64(aPrevious, 5U)) + 320992148982301024U) + aPhaseGOrbiterAssignSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterG = (aWandererB + RotL64(aScatter, 26U)) + 5619109532065293074U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 10380157329426706345U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 12449831150625409695U;
            aOrbiterE = RotL64((aOrbiterE * 3354095240459774437U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 7847096607042268396U) + aPhaseGOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 11707184096803214678U;
            aOrbiterG = RotL64((aOrbiterG * 1959476948106553973U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 9893643746186827088U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 333687403830908774U) ^ aPhaseGOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 17911256836121454271U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 13837360705077441580U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 4367119682175710689U;
            aOrbiterF = RotL64((aOrbiterF * 10295744669174603401U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 1193493435041306784U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 15062951612027370606U) ^ aPhaseGOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2509383510565136549U), 47U);
            //
            aIngress = RotL64(aOrbiterF, 39U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 29U));
            aIngress = aIngress + RotL64(aOrbiterE, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterB, 19U)) + aOrbiterF) + RotL64(aCarry, 41U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 4U) + RotL64(aOrbiterE, 53U)) + aOrbiterG) + aPhaseGWandererUpdateSaltC[((aIndex + 13U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aIngress, 51U) + RotL64(aOrbiterE, 29U)) + aOrbiterF) + RotL64(aCarry, 53U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterG, 11U)) + aOrbiterF);
            aWandererA = aWandererA + (((RotL64(aIngress, 21U) + aOrbiterC) + RotL64(aOrbiterB, 40U)) + aPhaseGWandererUpdateSaltF[((aIndex + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 60U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererA, 47U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererG, 37U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 18779U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneA[((aIndex + 20016U)) & S_BLOCK1], 34U));
            aIngress ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 21313U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 20073U)) & S_BLOCK1], 18U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 19730U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aWorkLaneC[((aIndex + 19652U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 53U) ^ RotL64(aCarry, 27U)) + (RotL64(aIngress, 40U) ^ RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterA = ((aWandererH + RotL64(aPrevious, 22U)) + RotL64(aCarry, 57U)) + 1087148170018530502U;
            aOrbiterK = (aWandererJ + RotL64(aScatter, 3U)) + 15530846874509311414U;
            aOrbiterB = (((aWandererK + RotL64(aIngress, 13U)) + RotL64(aCarry, 27U)) + 16987358651515511212U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = ((aWandererE + RotL64(aCross, 57U)) + 12504143181007924259U) + aPhaseGOrbiterAssignSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = ((aWandererA + RotL64(aScatter, 43U)) + RotL64(aCarry, 41U)) + 393322117322732418U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 14325937299241887166U) + aPhaseGOrbiterUpdateSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 9395262907017475742U;
            aOrbiterB = RotL64((aOrbiterB * 3442643798173589117U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 13658510441418344769U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 6410754322737005336U;
            aOrbiterJ = RotL64((aOrbiterJ * 6932217611373076391U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 9257290738538818434U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 7489828960857692286U;
            aOrbiterK = RotL64((aOrbiterK * 16519674788777989043U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 4118778591214588387U) + aPhaseGOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 16619215231168796563U;
            aOrbiterA = RotL64((aOrbiterA * 14876884956536265157U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 11326283811003573430U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 1865401866017614604U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8378326058282460073U), 53U);
            //
            aIngress = RotL64(aOrbiterA, 39U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 54U));
            aIngress = aIngress + RotL64(aOrbiterH, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aScatter, 19U) + aOrbiterK) + RotL64(aOrbiterB, 37U)) + RotL64(aCarry, 41U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 29U) + aOrbiterH) + RotL64(aOrbiterJ, 5U)) + aPhaseGWandererUpdateSaltE[((aIndex + 3U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aCross, 42U) + aOrbiterK) + RotL64(aOrbiterA, 50U)) + RotL64(aCarry, 11U)) + aPhaseGWandererUpdateSaltB[((aIndex + 11U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 53U) + aOrbiterA) + RotL64(aOrbiterJ, 19U));
            aWandererH = aWandererH + ((RotL64(aCross, 5U) + RotL64(aOrbiterH, 27U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 11U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 35U));
            aCarry = aCarry + RotL64(aWandererH, 44U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 30677U)) & S_BLOCK1], 34U) ^ RotL64(aExpandLaneB[((aIndex + 26674U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 25066U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27288U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32617U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 27867U)) & S_BLOCK1], 40U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 28U) ^ RotL64(aIngress, 53U)) ^ (RotL64(aPrevious, 5U) + RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterA = (aWandererK + RotL64(aScatter, 43U)) + 3561491146322798260U;
            aOrbiterG = (((aWandererH + RotL64(aIngress, 19U)) + RotL64(aCarry, 5U)) + 7075025056181885339U) + aPhaseGOrbiterAssignSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterI = ((aWandererB + RotL64(aPrevious, 29U)) + RotL64(aCarry, 23U)) + 9230910887904171613U;
            aOrbiterJ = ((aWandererG + RotL64(aCross, 3U)) + RotL64(aCarry, 37U)) + 4119781172609908917U;
            aOrbiterD = ((aWandererD + RotL64(aScatter, 56U)) + 17155609083870983149U) + aPhaseGOrbiterAssignSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 2423018561430181695U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 12957280305617615744U;
            aOrbiterI = RotL64((aOrbiterI * 17696410107705645631U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 2461704174772065813U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 7907123257849391997U) ^ aPhaseGOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9416171962847312179U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 7257868138318960007U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 16425903703085702285U;
            aOrbiterA = RotL64((aOrbiterA * 7996935869077231999U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 2990822664594079467U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 5654819006718953817U;
            aOrbiterG = RotL64((aOrbiterG * 4465096036756887801U), 21U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 12183676471235678779U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 15026286960542123922U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 17199049329995315279U), 5U);
            //
            aIngress = RotL64(aOrbiterJ, 3U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterD, 23U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterA, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aPrevious, 14U) + RotL64(aOrbiterD, 53U)) + aOrbiterA) + RotL64(aCarry, 23U)) + aPhaseGWandererUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 47U) + aOrbiterG) + RotL64(aOrbiterI, 35U)) + aPhaseGWandererUpdateSaltD[((aIndex + 8U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aCross, 23U) + RotL64(aOrbiterA, 27U)) + aOrbiterG);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterJ, 5U)) + aOrbiterD);
            aWandererG = aWandererG + (((RotL64(aCross, 35U) + aOrbiterG) + RotL64(aOrbiterD, 14U)) + RotL64(aCarry, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 56U) ^ aWandererD);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 3U));
            aCarry = aCarry + RotL64(aWandererG, 19U);
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

void TwistExpander_Hockey_Arx::GROW_B(TwistWorkSpace *pWorkSpace,
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
        // ingress from: aExpandLaneA, aExpandLaneB, aExpandLaneC
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aExpandLaneC forward/backward random
        // cross from: aExpandLaneB, aExpandLaneC, aExpandLaneD
        // cross directions: aExpandLaneB backward forced, aExpandLaneC backward forced, aExpandLaneD backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 8030U)) & S_BLOCK1], 24U) ^ RotL64(aExpandLaneB[((aIndex + 2855U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4911U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 4247U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 549U)) & S_BLOCK1], 58U));
            aCross ^= RotL64(aExpandLaneD[((aIndex + 8141U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 54U) + RotL64(aPrevious, 5U)) ^ (RotL64(aCross, 21U) + RotL64(aIngress, 37U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterA = ((aWandererD + RotL64(aScatter, 50U)) + RotL64(aCarry, 3U)) + 4634399531433127141U;
            aOrbiterD = (((aWandererH + RotL64(aIngress, 5U)) + RotL64(aCarry, 47U)) + 16961792729406903200U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = ((aWandererJ + RotL64(aCross, 13U)) + RotL64(aCarry, 19U)) + 4105280732301137738U;
            aOrbiterH = (aWandererF + RotL64(aPrevious, 23U)) + 15692013501147331191U;
            aOrbiterB = ((aWandererI + RotL64(aIngress, 39U)) + 1252216715968780587U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 7958289043012473752U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 6611577301818896615U;
            aOrbiterE = RotL64((aOrbiterE * 2757493607265637973U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 8506226754305949140U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 3648813120449403353U;
            aOrbiterD = RotL64((aOrbiterD * 9521367946879238849U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 5195245426245535735U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 542948051600803051U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4631106308856448475U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 11974253551208964789U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 10596463592332655367U;
            aOrbiterB = RotL64((aOrbiterB * 10941161258815714641U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 12015129484061440159U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 8254944355710109060U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3233697992479357615U), 37U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterA, 37U);
            aIngress = aIngress + (RotL64(aOrbiterE, 47U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterH, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aScatter, 41U) + RotL64(aOrbiterB, 14U)) + aOrbiterA) + RotL64(aCarry, 51U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 29U) + aOrbiterB) + RotL64(aOrbiterH, 37U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 14U) + RotL64(aOrbiterE, 5U)) + aOrbiterA) + RotL64(aCarry, 13U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 5U) + aOrbiterD) + RotL64(aOrbiterA, 27U)) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 53U) + aOrbiterB) + RotL64(aOrbiterD, 57U)) + aPhaseHWandererUpdateSaltE[((aIndex + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 57U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 46U));
            aCarry = aCarry + RotL64(aWandererD, 23U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 9533U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneB[((aIndex + 10682U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aExpandLaneC[((aIndex + 10778U)) & S_BLOCK1], 28U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 14243U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 13636U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 10675U)) & S_BLOCK1], 42U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 51U) ^ RotL64(aIngress, 23U)) ^ (RotL64(aCross, 35U) + RotL64(aPrevious, 4U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = ((aWandererG + RotL64(aIngress, 29U)) + RotL64(aCarry, 53U)) + 15813325389431304548U;
            aOrbiterC = ((aWandererA + RotL64(aCross, 3U)) + RotL64(aCarry, 13U)) + 2223874171125403602U;
            aOrbiterG = ((aWandererI + RotL64(aScatter, 42U)) + 5510483568496824130U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterE = (((aWandererB + RotL64(aPrevious, 57U)) + RotL64(aCarry, 41U)) + 15474152493495661876U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = (aWandererF + RotL64(aCross, 19U)) + 16846339705130829195U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 1289670576865739669U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 18017354919647006944U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 13103155460891498469U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 8539685539928984921U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 3333721400836704048U;
            aOrbiterI = RotL64((aOrbiterI * 3745286323481400085U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 2261560416623815491U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 4377786131746816567U;
            aOrbiterE = RotL64((aOrbiterE * 9164777834392621157U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 18047393176583722719U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 8184724021940434631U;
            aOrbiterD = RotL64((aOrbiterD * 9800116157750921119U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 10469895939183324807U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 14543391765109879223U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4817987697437667225U), 21U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterI, 19U);
            aIngress = aIngress + (RotL64(aOrbiterE, 4U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterG, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aScatter, 19U) + aOrbiterD) + RotL64(aOrbiterG, 21U)) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aCross, 3U) + aOrbiterE) + RotL64(aOrbiterG, 40U)) + RotL64(aCarry, 5U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterC, 57U)) + aOrbiterI);
            aWandererI = aWandererI + (((RotL64(aIngress, 57U) + RotL64(aOrbiterI, 11U)) + aOrbiterG) + RotL64(aCarry, 37U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 38U) + RotL64(aOrbiterG, 29U)) + aOrbiterC) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 3U) ^ aWandererF);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 47U));
            aCarry = aCarry + RotL64(aWandererB, 27U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 17631U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneA[((aIndex + 19696U)) & S_BLOCK1], 54U));
            aIngress ^= RotL64(aExpandLaneD[((aIndex + 19407U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18713U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 22876U)) & S_BLOCK1], 46U));
            aCross ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 16720U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 53U) + RotL64(aCross, 38U)) + (RotL64(aPrevious, 19U) ^ RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterH = (aWandererD + RotL64(aScatter, 14U)) + 10726035965553989335U;
            aOrbiterD = ((aWandererJ + RotL64(aPrevious, 47U)) + RotL64(aCarry, 3U)) + 967354339530195662U;
            aOrbiterB = (aWandererG + RotL64(aCross, 5U)) + 10834593005478605624U;
            aOrbiterC = (((aWandererA + RotL64(aIngress, 39U)) + RotL64(aCarry, 53U)) + 1012888282838656933U) + aPhaseHOrbiterAssignSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = (((aWandererI + RotL64(aScatter, 57U)) + RotL64(aCarry, 29U)) + 15283530351725183253U) + aPhaseHOrbiterAssignSaltD[((aIndex + 17U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 11724495956731703750U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 4288330117317505776U;
            aOrbiterB = RotL64((aOrbiterB * 2738997410474076757U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 10894778070022873473U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 15563886747621617467U;
            aOrbiterD = RotL64((aOrbiterD * 17884709931569040065U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 11182488628562891937U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 10420140066310588580U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 13898299782819948719U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 11775138062167543111U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 16545391898578161683U;
            aOrbiterH = RotL64((aOrbiterH * 14588306527161321535U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 1550144656312299266U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 14903504853138279883U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8003033561266164387U), 3U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterB, 5U);
            aIngress = aIngress + (RotL64(aOrbiterF, 39U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterC, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 58U) + RotL64(aOrbiterC, 29U)) + aOrbiterH);
            aWandererA = aWandererA + (((RotL64(aPrevious, 23U) + RotL64(aOrbiterF, 51U)) + aOrbiterC) + RotL64(aCarry, 5U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 35U) + aOrbiterB) + RotL64(aOrbiterC, 3U));
            aWandererI = aWandererI + ((((RotL64(aCross, 13U) + RotL64(aOrbiterF, 19U)) + aOrbiterB) + RotL64(aCarry, 21U)) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterD, 42U)) + aOrbiterH) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 13U) ^ aWandererI);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 48U));
            aCarry = aCarry + RotL64(aWandererA, 5U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 30677U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneB[((aIndex + 32623U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aWorkLaneA[((aIndex + 29065U)) & S_BLOCK1], 40U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 31183U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 31150U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 32239U)) & S_BLOCK1], 14U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 54U) + RotL64(aCross, 3U)) ^ (RotL64(aPrevious, 41U) + RotL64(aCarry, 27U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterF = ((aWandererF + RotL64(aCross, 21U)) + RotL64(aCarry, 41U)) + 6467297102954816305U;
            aOrbiterG = ((aWandererA + RotL64(aScatter, 43U)) + 7921154109831114952U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterJ = (((aWandererH + RotL64(aPrevious, 51U)) + RotL64(aCarry, 57U)) + 5701131763215638919U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = (aWandererB + RotL64(aIngress, 60U)) + 10022999076719002684U;
            aOrbiterB = ((aWandererD + RotL64(aScatter, 29U)) + RotL64(aCarry, 27U)) + 4367135243038982316U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 14445846824810383592U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 7683697954545773253U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4832124801510084629U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 17517006750428030899U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 2052484792684025476U;
            aOrbiterF = RotL64((aOrbiterF * 12463117571122469643U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 6279463052085808926U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 679280153651813684U;
            aOrbiterB = RotL64((aOrbiterB * 3047031560593583881U), 39U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 2939516520188460569U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 1960616434964712325U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 15145998415466343039U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 12273819390719947361U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 5685033154709449397U;
            aOrbiterG = RotL64((aOrbiterG * 9845666295874714959U), 53U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterB, 24U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 41U));
            aIngress = aIngress + RotL64(aOrbiterJ, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aCross, 39U) + aOrbiterJ) + RotL64(aOrbiterA, 21U)) + aPhaseHWandererUpdateSaltE[((aIndex + 27U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 52U) + RotL64(aOrbiterB, 51U)) + aOrbiterF) + RotL64(aCarry, 19U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 5U) + aOrbiterB) + RotL64(aOrbiterA, 11U));
            aWandererH = aWandererH + (((RotL64(aIngress, 13U) + RotL64(aOrbiterA, 29U)) + aOrbiterF) + RotL64(aCarry, 47U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 23U) + aOrbiterJ) + RotL64(aOrbiterG, 38U)) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 5U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 22U));
            aCarry = aCarry + RotL64(aWandererD, 51U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
