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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xCABA850A32BA3F13ULL + 0xC304F30FAD63919EULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xB92C2AD48AFAB91BULL + 0x8A99D088563142B0ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xB2D34B1BEAA770EFULL + 0xE86F15C7A59A4122ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xCE1B5348C5EB8D5BULL + 0xD5655D91135910ECULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x9024AFA9B7AD889BULL + 0xE3D575B2E1A02AEDULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xFF525EC8C060F8D7ULL + 0xDBDAE15E68E65A54ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xAAEC6E1E3FDB9C61ULL + 0xC6A4576215C5DC43ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x9D0E821C62068A8DULL + 0x98A54D38264AF6BDULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0x89844F13C6351119ULL + 0xD188AE3D9633392EULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xC78F3157BBCC36CDULL + 0xB87BE346A7953C4FULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0x9614A712DC345F23ULL + 0x9CC6E23DF0B9E89BULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xB4DC02E973308F41ULL + 0xF7A5ACF4EF1692C2ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xBED8BADA97C6EF97ULL + 0xEF665F4C425CAC33ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xDE5AF001FA48996FULL + 0xEE2BE589E2229491ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xCB591E87E01F1063ULL + 0xC74D21A48E87AC7AULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xD3ECC1A03286F413ULL + 0x87602CDE9903F931ULL);
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
            aIngress = RotL64(mSource[((aIndex + 4389U)) & S_BLOCK1], 50U) ^ RotL64(pSnow[((aIndex + 3723U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = RotL64(pSnow[((S_BLOCK1 - aIndex + 4481U)) & S_BLOCK1], 29U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 393U)) & S_BLOCK1], 42U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aPrevious, 19U) + RotL64(aCarry, 4U)) ^ (RotL64(aIngress, 39U) ^ RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterH = (((aWandererH + RotL64(aCross, 21U)) + 8988572360732005217U) + aOrbiterAssignSaltB[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterA = (aWandererI + RotL64(aScatter, 10U)) + 17889613225105985335U;
            aOrbiterF = (aWandererF + RotL64(aPrevious, 37U)) + 15563478320513948626U;
            aOrbiterD = ((aWandererE + RotL64(aIngress, 51U)) + 3441351228410524816U) + aNonceWordD;
            aOrbiterK = (((aWandererG + RotL64(aCross, 29U)) + RotL64(aCarry, 41U)) + 4425592689451435346U) + aNonceWordM;
            aOrbiterC = ((aWandererJ + RotL64(aScatter, 14U)) + 12733160231627305928U) + aOrbiterAssignSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterI = (aWandererA + RotL64(aPrevious, 39U)) + 3574152157304607854U;
            aOrbiterB = ((aWandererC + RotL64(aIngress, 43U)) + RotL64(aCarry, 37U)) + 15167631896729808783U;
            aOrbiterE = (aWandererK + RotL64(aPrevious, 3U)) + 15822667973915417055U;
            aOrbiterG = ((aWandererB + RotL64(aScatter, 57U)) + RotL64(aCarry, 13U)) + 17181685481076577637U;
            aOrbiterJ = (aWandererD + RotL64(aCross, 19U)) + 9979204751408873468U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 1334240485667164762U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 9190066751460137016U) ^ aOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 14585141844653660363U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 15465215829109246336U) + aNonceWordO;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 2305208282453624419U;
            aOrbiterC = RotL64((aOrbiterC * 10257861974108363283U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 16951510027310993926U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 11117938943423526901U;
            aOrbiterK = RotL64((aOrbiterK * 7805486716716924787U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 12461379120662979432U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 11719697049048823897U;
            aOrbiterD = RotL64((aOrbiterD * 14880996802304818757U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 6843357278142933570U) + aNonceWordC;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 12727898578324702374U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9786435451654365097U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 18127999660067652233U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 11754709060558683082U;
            aOrbiterI = RotL64((aOrbiterI * 12798744012150745847U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 16940151146420516184U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 12924950783056761895U;
            aOrbiterB = RotL64((aOrbiterB * 8898170377271926745U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 14829713915929878471U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 840466047621042565U;
            aOrbiterE = RotL64((aOrbiterE * 10748511630509529489U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 11469637840333471085U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 5561780312837795893U) ^ aNonceWordL;
            aOrbiterA = RotL64((aOrbiterA * 11935079844970978957U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 1059834104159730610U) + aNonceWordA;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 10122108814456766430U) ^ aOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 2184693583782179921U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 14857099570072635006U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 8988572360732005217U;
            aOrbiterG = RotL64((aOrbiterG * 14409836741925393077U), 21U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterA, 43U);
            aIngress = aIngress + (RotL64(aOrbiterH, 29U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 5U));
            aIngress = aIngress + (RotL64(aOrbiterF, 53U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterK, 36U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterD, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aCross, 57U) + aOrbiterD) + RotL64(aOrbiterF, 27U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 11U) + aOrbiterE) + RotL64(aOrbiterJ, 44U)) + RotL64(aCarry, 47U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 13U) + aOrbiterC) + RotL64(aOrbiterH, 57U));
            aWandererI = aWandererI + ((RotL64(aIngress, 26U) + RotL64(aOrbiterD, 13U)) + aOrbiterK);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterE, 47U)) + aOrbiterF);
            aWandererA = aWandererA + ((RotL64(aPrevious, 43U) + aOrbiterK) + RotL64(aOrbiterG, 19U));
            aWandererD = aWandererD ^ ((((RotL64(aCross, 19U) + RotL64(aOrbiterD, 41U)) + aOrbiterC) + aNonceWordH) + aWandererUpdateSaltF[((aIndex + 19U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 37U) + RotL64(aOrbiterE, 29U)) + aOrbiterA);
            aWandererC = aWandererC ^ ((((RotL64(aPrevious, 35U) + aOrbiterA) + RotL64(aOrbiterG, 39U)) + aNonceWordG) + aWandererUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 21U) + aOrbiterH) + RotL64(aOrbiterI, 22U)) + RotL64(aCarry, 39U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 4U) + RotL64(aOrbiterF, 5U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererC, 19U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererB, 44U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererJ, 11U) ^ aWandererF);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 41U));
            aCarry = aCarry + (RotL64(aWandererE, 51U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererI, 21U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 8137U)) & S_BLOCK1], 38U) ^ RotL64(mSource[((aIndex + 10789U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 8365U)) & S_BLOCK1], 29U) ^ RotL64(pSnow[((aIndex + 8711U)) & S_BLOCK1], 54U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aIngress, 28U) ^ RotL64(aCross, 41U)) + (RotL64(aCarry, 57U) + RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterB = ((aWandererB + RotL64(aIngress, 3U)) + 380024772508948442U) + aNonceWordF;
            aOrbiterH = (aWandererK + RotL64(aScatter, 21U)) + 7649029098162567210U;
            aOrbiterG = (((aWandererC + RotL64(aPrevious, 19U)) + 5329304598870421851U) + aOrbiterAssignSaltE[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordN;
            aOrbiterI = (aWandererE + RotL64(aCross, 27U)) + 12306118665045151326U;
            aOrbiterA = (((aWandererD + RotL64(aScatter, 57U)) + RotL64(aCarry, 29U)) + 960751560457324256U) + aNonceWordE;
            aOrbiterC = ((aWandererG + RotL64(aIngress, 11U)) + RotL64(aCarry, 21U)) + 3244070254386191876U;
            aOrbiterD = ((aWandererI + RotL64(aPrevious, 50U)) + RotL64(aCarry, 53U)) + 15733408571609521746U;
            aOrbiterF = (aWandererF + RotL64(aCross, 43U)) + 17623448932647018544U;
            aOrbiterE = (aWandererJ + RotL64(aPrevious, 35U)) + 8787759896149035829U;
            aOrbiterK = (aWandererA + RotL64(aIngress, 29U)) + 14741681792348288162U;
            aOrbiterJ = (((aWandererH + RotL64(aCross, 38U)) + 8801731213568307302U) + aOrbiterAssignSaltA[(((31U - aIndex) + 28U)) & S_SALT1]) + aNonceWordO;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 9872248187499779222U) + aOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 15407371518644528235U;
            aOrbiterG = RotL64((aOrbiterG * 1245102406469471673U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 4242060317152943062U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 9942784962409917541U;
            aOrbiterB = RotL64((aOrbiterB * 888649755587764533U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 7296348796484458631U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 15061417216070157797U) ^ aOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 10349554676953256231U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 3233185810644297433U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 9241229457641024287U;
            aOrbiterF = RotL64((aOrbiterF * 2728237515724597517U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 8464051359381554575U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterK = (((aOrbiterK ^ aOrbiterE) ^ 3307872165699029375U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterK = RotL64((aOrbiterK * 4859663401033023433U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 5482617843966711997U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 4442149210462943872U;
            aOrbiterH = RotL64((aOrbiterH * 8979352218576515647U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 10591636597580147381U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 14925122230279312217U;
            aOrbiterC = RotL64((aOrbiterC * 15038171961638724013U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 9772367878232735350U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 15800661165607190092U;
            aOrbiterA = RotL64((aOrbiterA * 10493976952980533589U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 1571665862499272194U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 3162847040693387901U;
            aOrbiterJ = RotL64((aOrbiterJ * 2747235335326991399U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 4868791925868749848U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 13134549226315884613U;
            aOrbiterD = RotL64((aOrbiterD * 3551955270718495869U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 7830447320021657240U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 380024772508948442U) ^ aNonceWordI;
            aOrbiterE = RotL64((aOrbiterE * 5143324968958616357U), 51U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterD, 11U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 41U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 3U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 34U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 19U));
            aIngress = aIngress + RotL64(aOrbiterB, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aScatter, 41U) + aOrbiterA) + RotL64(aOrbiterK, 56U)) + aNonceWordK);
            aWandererK = aWandererK + ((((RotL64(aIngress, 54U) + aOrbiterB) + RotL64(aOrbiterC, 21U)) + RotL64(aCarry, 29U)) + aNonceWordB);
            aWandererD = aWandererD ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterA, 37U)) + aOrbiterJ);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 19U) + aOrbiterC) + RotL64(aOrbiterI, 47U)) + aNonceWordA);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterG, 3U)) + aOrbiterH);
            aWandererI = aWandererI + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterB, 30U)) + aOrbiterF) + aWandererUpdateSaltB[((aIndex + 15U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 23U) + aOrbiterG) + RotL64(aOrbiterC, 43U));
            aWandererC = aWandererC + ((RotL64(aCross, 58U) + aOrbiterB) + RotL64(aOrbiterI, 53U));
            aWandererH = aWandererH ^ ((((RotL64(aIngress, 11U) + RotL64(aOrbiterA, 35U)) + aOrbiterD) + aNonceWordM) + aWandererUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 29U) + RotL64(aOrbiterD, 27U)) + aOrbiterJ) + RotL64(aCarry, 21U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 51U) + aOrbiterE) + RotL64(aOrbiterC, 51U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 13U) ^ aWandererI);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 41U));
            aCarry = aCarry + (RotL64(aWandererK, 21U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererG, 34U) ^ aWandererJ);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 5U));
            aCarry = aCarry + RotL64(aWandererE, 23U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = RotL64(aWorkLaneB[((aIndex + 15718U)) & S_BLOCK1], 53U) ^ RotL64(mSource[((aIndex + 13081U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(pSnow[((S_BLOCK1 - aIndex + 11505U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 14848U)) & S_BLOCK1], 54U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCarry, 43U) ^ RotL64(aIngress, 29U)) + (RotL64(aCross, 6U) + RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterI = (aWandererC + RotL64(aCross, 3U)) + 13687218104610230596U;
            aOrbiterJ = ((aWandererG + RotL64(aIngress, 37U)) + 6841550124960692709U) + aNonceWordB;
            aOrbiterF = (((aWandererB + RotL64(aScatter, 21U)) + RotL64(aCarry, 21U)) + 17418968668458764131U) + aOrbiterAssignSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = ((aWandererA + RotL64(aPrevious, 46U)) + 8303537912696948204U) + aNonceWordK;
            aOrbiterH = (aWandererF + RotL64(aCross, 19U)) + 12376614417285936537U;
            aOrbiterA = (aWandererK + RotL64(aPrevious, 27U)) + 14215749063579232654U;
            aOrbiterD = ((aWandererE + RotL64(aScatter, 41U)) + 4111736931433665347U) + aNonceWordP;
            aOrbiterB = ((aWandererD + RotL64(aIngress, 29U)) + RotL64(aCarry, 3U)) + 11250375934571631522U;
            aOrbiterG = ((aWandererI + RotL64(aScatter, 13U)) + 5367367837773331275U) + aOrbiterAssignSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterK = ((aWandererH + RotL64(aPrevious, 50U)) + RotL64(aCarry, 51U)) + 15514089192382674434U;
            aOrbiterE = (aWandererJ + RotL64(aIngress, 5U)) + 1475991716685034960U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 5531622777788629748U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 8363822215908303335U;
            aOrbiterF = RotL64((aOrbiterF * 17850203366840994883U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 3741256932685720414U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterJ) ^ 11634667238062155772U) ^ aOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterH = RotL64((aOrbiterH * 15925089729784547403U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 18180546911210417155U) + aOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 5123234656838556335U;
            aOrbiterA = RotL64((aOrbiterA * 15362857462853398025U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 11215734271189250284U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 16863747802158398092U) ^ aOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 1828035970246160023U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 9859050606636646323U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 9331300036643654675U;
            aOrbiterJ = RotL64((aOrbiterJ * 2502263410556166281U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 15028845665427209759U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 8916444839488901676U;
            aOrbiterG = RotL64((aOrbiterG * 6646561894156038791U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 8024631140949068570U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 1116378858490660031U;
            aOrbiterK = RotL64((aOrbiterK * 4247798531910227367U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 5066486214537899212U) + aOrbiterUpdateSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 9346312092322423057U) ^ aNonceWordA;
            aOrbiterI = RotL64((aOrbiterI * 13443190089768875191U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 11651011617027950122U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 11308862427412671711U;
            aOrbiterC = RotL64((aOrbiterC * 12167147966934334703U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 3850136281462840708U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 13461307727665667424U;
            aOrbiterD = RotL64((aOrbiterD * 10788040812090673421U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 17824744996404571928U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 13687218104610230596U;
            aOrbiterE = RotL64((aOrbiterE * 325803029547254631U), 47U);
            //
            aIngress = RotL64(aOrbiterK, 58U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterJ, 39U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 21U));
            aIngress = aIngress + (RotL64(aOrbiterI, 3U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 53U));
            aIngress = aIngress + RotL64(aOrbiterF, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aPrevious, 51U) + RotL64(aOrbiterJ, 13U)) + aOrbiterH);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 14U) + aOrbiterD) + RotL64(aOrbiterC, 11U)) + aNonceWordG);
            aWandererA = aWandererA + ((((RotL64(aCross, 11U) + aOrbiterE) + RotL64(aOrbiterF, 57U)) + RotL64(aCarry, 29U)) + aNonceWordN);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 47U) + aOrbiterB) + RotL64(aOrbiterF, 19U)) + aNonceWordL);
            aWandererD = aWandererD + (((RotL64(aScatter, 53U) + RotL64(aOrbiterB, 43U)) + aOrbiterD) + RotL64(aCarry, 53U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 58U) + aOrbiterH) + RotL64(aOrbiterG, 54U));
            aWandererK = aWandererK + (((RotL64(aIngress, 21U) + aOrbiterH) + RotL64(aOrbiterK, 5U)) + aWandererUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 23U) + aOrbiterE) + RotL64(aOrbiterI, 29U));
            aWandererJ = aWandererJ + ((RotL64(aCross, 43U) + aOrbiterB) + RotL64(aOrbiterC, 47U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 35U) + aOrbiterA) + RotL64(aOrbiterG, 51U)) + aWandererUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aIngress, 29U) + RotL64(aOrbiterD, 60U)) + aOrbiterK) + aNonceWordE);
            //
            aCarry = aCarry + (RotL64(aWandererF, 5U) ^ aWandererB);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 29U));
            aCarry = aCarry + (RotL64(aWandererE, 48U) ^ aWandererA);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 27U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 23U));
            aCarry = aCarry + RotL64(aWandererI, 57U);
            aCarry = aCarry + RotL64(aIngress, 36U);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 17787U)) & S_BLOCK1], 10U) ^ RotL64(aWorkLaneA[((aIndex + 20942U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 16875U)) & S_BLOCK1], 39U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 20768U)) & S_BLOCK1], 60U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 19256U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCarry, 57U) + RotL64(aPrevious, 26U)) + (RotL64(aCross, 43U) ^ RotL64(aIngress, 13U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterE = ((aWandererF + RotL64(aIngress, 3U)) + 2974056819475622600U) + aNonceWordI;
            aOrbiterD = (aWandererD + RotL64(aCross, 19U)) + 7345051759236356098U;
            aOrbiterB = ((aWandererJ + RotL64(aPrevious, 21U)) + 12738468816846628882U) + aNonceWordF;
            aOrbiterH = ((aWandererA + RotL64(aScatter, 60U)) + 7694520596043297922U) + aNonceWordJ;
            aOrbiterC = (aWandererE + RotL64(aCross, 29U)) + 5530753590015084774U;
            aOrbiterG = ((aWandererB + RotL64(aIngress, 43U)) + RotL64(aCarry, 19U)) + 3776309161718383105U;
            aOrbiterA = ((aWandererC + RotL64(aScatter, 57U)) + RotL64(aCarry, 27U)) + 784780304358106404U;
            aOrbiterI = ((((aWandererG + RotL64(aPrevious, 11U)) + RotL64(aCarry, 11U)) + 8999942326995036509U) + aOrbiterAssignSaltB[((aIndex + 18U)) & S_SALT1]) + aNonceWordC;
            aOrbiterJ = (aWandererK + RotL64(aIngress, 50U)) + 5194986506064092779U;
            aOrbiterK = (aWandererI + RotL64(aCross, 41U)) + 7920040007459652762U;
            aOrbiterF = ((aWandererH + RotL64(aScatter, 37U)) + 11311997270710107937U) + aOrbiterAssignSaltC[((aIndex + 29U)) & S_SALT1];
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 5365231114813547251U) + aNonceWordD;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 8630110234623825263U;
            aOrbiterB = RotL64((aOrbiterB * 2735881715888325759U), 39U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 2358235238039571072U) + aNonceWordM;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 18059414891616491807U;
            aOrbiterC = RotL64((aOrbiterC * 17150786106857185467U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 14526050556461782864U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 6937282036603272474U;
            aOrbiterD = RotL64((aOrbiterD * 14954512365270028029U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 10105832250694931310U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 3884223553012098137U;
            aOrbiterE = RotL64((aOrbiterE * 16340956813003906195U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 10385284339549648087U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 1257633893341505930U;
            aOrbiterG = RotL64((aOrbiterG * 2669950791270500977U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 5528890519572824318U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 15664241747527713256U;
            aOrbiterK = RotL64((aOrbiterK * 16670884497088220497U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 14264122979415331887U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 17985061405540198036U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2729487440173395133U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 1663986734997903415U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 3706166884286400587U;
            aOrbiterH = RotL64((aOrbiterH * 10549736618301955745U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 12736963182099961466U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 95411267612114381U;
            aOrbiterJ = RotL64((aOrbiterJ * 8011937916302325057U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 4966620136499917388U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 8478316876240452401U;
            aOrbiterI = RotL64((aOrbiterI * 13297718919105366563U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 11123814701411614557U) + aOrbiterUpdateSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 2974056819475622600U;
            aOrbiterF = RotL64((aOrbiterF * 5913569942407618997U), 41U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterH, 23U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 3U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 47U));
            aIngress = aIngress + (RotL64(aOrbiterD, 26U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterE, 19U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterI, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterF, 21U)) + aOrbiterD);
            aWandererH = aWandererH + (((RotL64(aCross, 39U) + aOrbiterC) + RotL64(aOrbiterJ, 5U)) + RotL64(aCarry, 21U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 30U) + aOrbiterG) + RotL64(aOrbiterF, 37U));
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 47U) + RotL64(aOrbiterE, 11U)) + aOrbiterK) + aNonceWordN) + aWandererUpdateSaltF[((aIndex + 9U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 41U) + aOrbiterJ) + RotL64(aOrbiterH, 47U));
            aWandererK = aWandererK + (((RotL64(aIngress, 19U) + aOrbiterJ) + RotL64(aOrbiterE, 41U)) + aNonceWordO);
            aWandererC = aWandererC ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterI, 56U)) + aOrbiterK) + aWandererUpdateSaltC[((aIndex + 5U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 14U) + aOrbiterK) + RotL64(aOrbiterJ, 53U)) + RotL64(aCarry, 43U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 11U) + aOrbiterK) + RotL64(aOrbiterB, 39U)) + aNonceWordB);
            aWandererB = aWandererB + ((RotL64(aCross, 37U) + RotL64(aOrbiterB, 43U)) + aOrbiterA);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterD, 60U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererF, 3U) ^ aWandererK);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 56U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 21U));
            aCarry = aCarry + (RotL64(aWandererD, 35U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererI, 51U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererA, 14U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 26500U)) & S_BLOCK1], 11U) ^ RotL64(mSource[((aIndex + 26265U)) & S_BLOCK1], 35U));
            aIngress ^= (RotL64(pSnow[((aIndex + 21879U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22213U)) & S_BLOCK1], 44U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 25769U)) & S_BLOCK1], 40U) ^ RotL64(aWorkLaneB[((aIndex + 25997U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aIngress, 22U) + RotL64(aCross, 39U)) ^ (RotL64(aCarry, 51U) ^ RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterI = (((aWandererC + RotL64(aIngress, 19U)) + RotL64(aCarry, 35U)) + 12027839670755583592U) + aNonceWordL;
            aOrbiterE = ((aWandererH + RotL64(aScatter, 12U)) + RotL64(aCarry, 27U)) + 15380130703509859843U;
            aOrbiterK = (aWandererB + RotL64(aPrevious, 37U)) + 4590907433867798074U;
            aOrbiterA = (((aWandererG + RotL64(aCross, 39U)) + RotL64(aCarry, 43U)) + 1754574023602519724U) + aNonceWordB;
            aOrbiterD = ((aWandererJ + RotL64(aPrevious, 21U)) + 9832756659564903767U) + aOrbiterAssignSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = ((aWandererI + RotL64(aCross, 53U)) + 5035088494491470403U) + aNonceWordO;
            aOrbiterB = (aWandererK + RotL64(aScatter, 47U)) + 14199170923323644638U;
            aOrbiterF = (aWandererF + RotL64(aIngress, 56U)) + 8325619421264440438U;
            aOrbiterJ = ((aWandererE + RotL64(aPrevious, 29U)) + 969534320779067977U) + aOrbiterAssignSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = ((aWandererD + RotL64(aScatter, 43U)) + 270575869402913847U) + aNonceWordN;
            aOrbiterH = (aWandererA + RotL64(aCross, 5U)) + 13344806516599578910U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 15143147951139409101U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 14425582489214169238U) ^ aNonceWordH;
            aOrbiterK = RotL64((aOrbiterK * 16893787086337916355U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 13951127523239064584U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterA) ^ 14177925225918293579U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterC = RotL64((aOrbiterC * 13079514031864998485U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 8258920744278218901U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 7408161179397242453U;
            aOrbiterB = RotL64((aOrbiterB * 975737128100519169U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 8581481606764773468U) + aOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 10078416198417433133U;
            aOrbiterJ = RotL64((aOrbiterJ * 1102721083915858247U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 18299772198826189580U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 18304668908084397946U;
            aOrbiterG = RotL64((aOrbiterG * 10589455451200578687U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 16729632621573817223U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 13362300981585573239U;
            aOrbiterE = RotL64((aOrbiterE * 9824473895535518785U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 8629682832849915380U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 6852852009091469641U;
            aOrbiterD = RotL64((aOrbiterD * 11912646687050011915U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 7433098156961745198U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 10931806208899417308U;
            aOrbiterI = RotL64((aOrbiterI * 14699197041038067483U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 629604718211675247U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 1487372736719237118U;
            aOrbiterF = RotL64((aOrbiterF * 705192821277928909U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 3567439893461603384U) + aOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 11143068753134694333U;
            aOrbiterH = RotL64((aOrbiterH * 15529326960229305389U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 14242098279913980463U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 12027839670755583592U) ^ aNonceWordM;
            aOrbiterA = RotL64((aOrbiterA * 6630014752150544153U), 27U);
            //
            aIngress = RotL64(aOrbiterG, 19U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 37U));
            aIngress = aIngress + (RotL64(aOrbiterK, 39U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterA, 21U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 29U));
            aIngress = aIngress + RotL64(aOrbiterJ, 56U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aIngress, 41U) + aOrbiterA) + RotL64(aOrbiterB, 23U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterJ, 3U)) + aOrbiterI);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 19U) + aOrbiterK) + RotL64(aOrbiterF, 37U)) + RotL64(aCarry, 21U)) + aNonceWordK);
            aWandererE = aWandererE ^ ((RotL64(aCross, 21U) + aOrbiterE) + RotL64(aOrbiterH, 30U));
            aWandererI = aWandererI + (((RotL64(aIngress, 37U) + aOrbiterI) + RotL64(aOrbiterC, 21U)) + RotL64(aCarry, 43U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 52U) + RotL64(aOrbiterH, 13U)) + aOrbiterJ);
            aWandererD = aWandererD + (((RotL64(aCross, 13U) + aOrbiterH) + RotL64(aOrbiterG, 19U)) + aNonceWordF);
            aWandererJ = aWandererJ ^ ((((RotL64(aScatter, 43U) + RotL64(aOrbiterD, 10U)) + aOrbiterA) + aNonceWordJ) + aWandererUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aCross, 39U) + aOrbiterE) + RotL64(aOrbiterF, 53U)) + aNonceWordP);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 27U) + aOrbiterJ) + RotL64(aOrbiterC, 57U)) + aWandererUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aPrevious, 4U) + RotL64(aOrbiterD, 5U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 56U));
            aCarry = aCarry + (RotL64(aWandererJ, 21U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererB, 11U) ^ aWandererG);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 3U));
            aCarry = aCarry + RotL64(aWandererH, 51U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 30438U)) & S_BLOCK1], 26U) ^ RotL64(pSnow[((aIndex + 32464U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 29512U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 30142U)) & S_BLOCK1], 11U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 27439U)) & S_BLOCK1], 46U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 30751U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aIngress, 57U)) + (RotL64(aPrevious, 34U) + RotL64(aCarry, 19U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterG = (aWandererE + RotL64(aPrevious, 56U)) + 14686411261024919129U;
            aOrbiterE = ((aWandererA + RotL64(aScatter, 21U)) + RotL64(aCarry, 13U)) + 7514582233957632005U;
            aOrbiterF = (((aWandererC + RotL64(aIngress, 39U)) + 6520710480103365552U) + aOrbiterAssignSaltF[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordH;
            aOrbiterD = ((aWandererD + RotL64(aCross, 37U)) + RotL64(aCarry, 27U)) + 1983621978676188036U;
            aOrbiterC = (((aWandererI + RotL64(aPrevious, 11U)) + RotL64(aCarry, 47U)) + 9003524602590749672U) + aNonceWordA;
            aOrbiterJ = (aWandererF + RotL64(aScatter, 13U)) + 6428568234045228995U;
            aOrbiterA = ((aWandererB + RotL64(aIngress, 23U)) + 8656552687136446989U) + aNonceWordC;
            aOrbiterB = (aWandererH + RotL64(aCross, 19U)) + 16916248288415922490U;
            aOrbiterI = ((aWandererK + RotL64(aPrevious, 43U)) + 9740237548002535784U) + aOrbiterAssignSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = (aWandererG + RotL64(aScatter, 35U)) + 907561000814618339U;
            aOrbiterH = (aWandererJ + RotL64(aIngress, 50U)) + 4751108900841197631U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 167774899400732287U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 11907484918310854962U;
            aOrbiterF = RotL64((aOrbiterF * 7213139491146402985U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 14910318613649863924U) + aNonceWordN;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 14882888155751455276U) ^ aOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 11394136445442060201U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 16175942562693781908U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 11022373758481651102U;
            aOrbiterE = RotL64((aOrbiterE * 6836331461393816027U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 12548405399045031548U) + aNonceWordK;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 10850926364556828443U;
            aOrbiterA = RotL64((aOrbiterA * 16231561687709867431U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 13391684887911141790U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 14648937281264822988U;
            aOrbiterG = RotL64((aOrbiterG * 6533299316940026059U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 8298658887198526821U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 13822977698661348891U;
            aOrbiterK = RotL64((aOrbiterK * 17769262972278410937U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 7505646847564645719U) + aOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 3238749538197209166U;
            aOrbiterB = RotL64((aOrbiterB * 15394286542600778567U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 15853506915123709257U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 8426329899401071248U;
            aOrbiterD = RotL64((aOrbiterD * 1330397096577715113U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 14848635392815613098U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 3549927798350175044U) ^ aOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 1899044682313056949U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 1798973117197750802U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 13056711228618953977U;
            aOrbiterI = RotL64((aOrbiterI * 9102877396419306689U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 1395893547965799281U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 14686411261024919129U;
            aOrbiterC = RotL64((aOrbiterC * 17075377081365066067U), 21U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterI, 35U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 47U));
            aIngress = aIngress + (RotL64(aOrbiterF, 11U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 27U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 38U));
            aIngress = aIngress + RotL64(aOrbiterH, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aCross, 53U) + RotL64(aOrbiterD, 29U)) + aOrbiterC) + RotL64(aCarry, 47U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 41U) + aOrbiterC) + RotL64(aOrbiterI, 19U));
            aWandererG = aWandererG + (((RotL64(aIngress, 56U) + aOrbiterE) + RotL64(aOrbiterA, 3U)) + aNonceWordB);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 27U) + aOrbiterG) + RotL64(aOrbiterK, 54U));
            aWandererF = aWandererF + (((RotL64(aIngress, 19U) + aOrbiterC) + RotL64(aOrbiterA, 41U)) + RotL64(aCarry, 39U));
            aWandererC = aWandererC ^ ((((RotL64(aPrevious, 39U) + aOrbiterH) + RotL64(aOrbiterB, 21U)) + aNonceWordO) + aWandererUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aCross, 21U) + RotL64(aOrbiterH, 47U)) + aOrbiterJ);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterF, 37U)) + aOrbiterJ);
            aWandererE = aWandererE + (((RotL64(aIngress, 58U) + RotL64(aOrbiterJ, 35U)) + aOrbiterI) + aWandererUpdateSaltE[((aIndex + 28U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 37U) + RotL64(aOrbiterK, 58U)) + aOrbiterC) + aNonceWordM);
            aWandererI = aWandererI + ((RotL64(aCross, 23U) + aOrbiterE) + RotL64(aOrbiterI, 51U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 27U));
            aCarry = aCarry + (RotL64(aWandererG, 19U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererJ, 14U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererE, 35U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererC, 39U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererH, 41U);
            aCarry = aCarry + RotL64(aIngress, 48U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x9D829D9E134F5113ULL + 0xF7519184ADF3D905ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xCD322009F97D2FA5ULL + 0xBCAB32595E300A67ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x81141A3CB3C01617ULL + 0x83DD361FF94CAA0CULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xDBFE4DA8A92F464BULL + 0xD70BD68403372715ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xEE4DB474BE426467ULL + 0xBE1872F7AEA806C7ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xCBCD2496C772D4B3ULL + 0x9879A10E9F621BE7ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x823C450083C9665BULL + 0xBD8581CCC5264B36ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xE45FA2F332971FF7ULL + 0xE87A00D0367486DDULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xA42E160F2684C3DFULL + 0xE14A714AE047627AULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xC5D1984E56B55FF5ULL + 0xF05F7264F6BA9BB8ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xE5B9DBA7028AC5D5ULL + 0x87DF01BE1065C849ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xFFCB3EAEB7732663ULL + 0x964D576D4B872BE6ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xDDD8FA1483A61B57ULL + 0xC5820CB80E365C49ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xF23513E6C60941CBULL + 0xF035D6042B668969ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xC3EA37A50A5D97F5ULL + 0x8EA507E0D8750CDBULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xB43998BE4CEB3775ULL + 0xE9E866E9C6021C49ULL);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 7533U)) & S_BLOCK1], 10U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 1553U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 3915U)) & S_BLOCK1], 23U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 7869U)) & S_BLOCK1], 54U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aPrevious, 54U) ^ RotL64(aCarry, 5U)) ^ (RotL64(aCross, 19U) + RotL64(aIngress, 37U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterC = (aWandererD + RotL64(aIngress, 56U)) + 14624277139785904404U;
            aOrbiterI = (aWandererE + RotL64(aPrevious, 3U)) + 6966977309498165611U;
            aOrbiterE = (aWandererC + RotL64(aScatter, 23U)) + 205536824352530761U;
            aOrbiterB = ((aWandererH + RotL64(aCross, 27U)) + 16629575265808255692U) + aOrbiterAssignSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = ((aWandererF + RotL64(aIngress, 47U)) + 596881340147972746U) + aNonceWordD;
            aOrbiterJ = (((aWandererG + RotL64(aScatter, 19U)) + RotL64(aCarry, 39U)) + 11944412799107412650U) + aOrbiterAssignSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterA = (((aWandererA + RotL64(aCross, 13U)) + RotL64(aCarry, 23U)) + 4615021315668210206U) + aNonceWordP;
            aOrbiterF = (((aWandererB + RotL64(aPrevious, 35U)) + RotL64(aCarry, 47U)) + 8497630055977606216U) + aNonceWordF;
            aOrbiterH = (aWandererJ + RotL64(aIngress, 42U)) + 11131601107309336885U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 5935883479805510099U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 15629346719765798174U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 8535523790685945275U), 5U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 5279128339113651273U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 16778365912440331821U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 705421028266789241U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 16003052937645491524U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 6723226158737614764U;
            aOrbiterA = RotL64((aOrbiterA * 16690657664909260573U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 9785784358981219543U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 10055457337292292710U;
            aOrbiterF = RotL64((aOrbiterF * 17919129940751761111U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 11779163108592974175U) + aNonceWordG;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 1177999477942202687U;
            aOrbiterD = RotL64((aOrbiterD * 13475069421684114643U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 9190694445141492214U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 15605342360346353457U;
            aOrbiterJ = RotL64((aOrbiterJ * 14547769706392595647U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 14877565450677523492U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 1074095623308025684U) ^ aNonceWordC;
            aOrbiterC = RotL64((aOrbiterC * 7884068939436891093U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 12803174154216941583U) + aOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 8813356463693637033U;
            aOrbiterB = RotL64((aOrbiterB * 4898237214617563167U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 6063909634038581414U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 15112191502834052566U) ^ aNonceWordE;
            aOrbiterH = RotL64((aOrbiterH * 6780741782103553485U), 43U);
            //
            aIngress = RotL64(aOrbiterF, 39U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterI, 14U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 35U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 5U));
            aIngress = aIngress + RotL64(aOrbiterB, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterA, 21U)) + aOrbiterC) + aWandererUpdateSaltB[((aIndex + 12U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 12U) + RotL64(aOrbiterC, 51U)) + aOrbiterI) + RotL64(aCarry, 35U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 53U) + aOrbiterB) + RotL64(aOrbiterI, 12U)) + aNonceWordL);
            aWandererG = aWandererG + (((RotL64(aCross, 29U) + aOrbiterF) + RotL64(aOrbiterH, 39U)) + RotL64(aCarry, 3U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterH, 29U)) + aOrbiterE);
            aWandererB = aWandererB + ((RotL64(aIngress, 5U) + aOrbiterA) + RotL64(aOrbiterI, 5U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterD, 60U)) + aOrbiterB);
            aWandererH = aWandererH + ((RotL64(aCross, 23U) + aOrbiterF) + RotL64(aOrbiterI, 35U));
            aWandererD = aWandererD ^ ((((RotL64(aIngress, 38U) + RotL64(aOrbiterC, 47U)) + aOrbiterJ) + aNonceWordN) + aWandererUpdateSaltF[((aIndex + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 5U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererD, 50U) ^ aWandererJ);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 27U));
            aCarry = aCarry + (RotL64(aWandererA, 57U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererC, 37U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 14276U)) & S_BLOCK1], 11U) ^ RotL64(aFireLaneB[((aIndex + 15180U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 12616U)) & S_BLOCK1], 60U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 13951U)) & S_BLOCK1], 57U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 15080U)) & S_BLOCK1], 34U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCross, 43U)) + (RotL64(aCarry, 29U) ^ RotL64(aPrevious, 56U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterJ = (aWandererH + RotL64(aScatter, 53U)) + 12615321415808640429U;
            aOrbiterC = (aWandererJ + RotL64(aIngress, 18U)) + 15712784676459931207U;
            aOrbiterG = ((aWandererG + RotL64(aCross, 43U)) + 11013335427004930046U) + aNonceWordO;
            aOrbiterD = ((((aWandererF + RotL64(aPrevious, 29U)) + RotL64(aCarry, 19U)) + 8298733856304768806U) + aOrbiterAssignSaltA[((aIndex + 18U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterF = ((aWandererK + RotL64(aCross, 57U)) + RotL64(aCarry, 41U)) + 6207732959150824216U;
            aOrbiterA = (aWandererC + RotL64(aIngress, 4U)) + 9769864876127544038U;
            aOrbiterH = (aWandererB + RotL64(aPrevious, 39U)) + 10782181918651152563U;
            aOrbiterK = ((aWandererI + RotL64(aScatter, 23U)) + 5790454015845620939U) + aOrbiterAssignSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = ((aWandererD + RotL64(aIngress, 47U)) + RotL64(aCarry, 57U)) + 15606578025386733803U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 5522352539991175304U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 5993355818572869649U) ^ aNonceWordC;
            aOrbiterG = RotL64((aOrbiterG * 15221467311057431139U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 10864534396947622047U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 12090053126235913528U) ^ aNonceWordI;
            aOrbiterC = RotL64((aOrbiterC * 7250801471645972261U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 14191181677234981396U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 2258570108233924592U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8307541155393855209U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 8448114811381534603U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 2702389315763499817U;
            aOrbiterJ = RotL64((aOrbiterJ * 6710443836432274393U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 17202184076718780200U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 150549910056015002U;
            aOrbiterF = RotL64((aOrbiterF * 195034681254956335U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 4910512055808124967U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 4783477997418403079U) ^ aOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 861977492146512865U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 13842899106208709771U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 7930112618036681468U) ^ aNonceWordB;
            aOrbiterA = RotL64((aOrbiterA * 8609551859830858419U), 39U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 8790107242863198659U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 6882768826643279144U;
            aOrbiterD = RotL64((aOrbiterD * 13745521454063360763U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 12136498871759890015U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 8120456314755584336U;
            aOrbiterK = RotL64((aOrbiterK * 1830725195528043575U), 5U);
            //
            aIngress = RotL64(aOrbiterG, 39U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 27U));
            aIngress = aIngress + (RotL64(aOrbiterB, 52U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterF, 23U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterH, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aPrevious, 21U) + RotL64(aOrbiterB, 27U)) + aOrbiterC);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 41U) + RotL64(aOrbiterK, 58U)) + aOrbiterC) + aWandererUpdateSaltE[((aIndex + 12U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aIngress, 51U) + RotL64(aOrbiterC, 41U)) + aOrbiterA) + RotL64(aCarry, 19U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 58U) + aOrbiterK) + RotL64(aOrbiterJ, 51U));
            aWandererC = aWandererC + ((RotL64(aIngress, 37U) + aOrbiterD) + RotL64(aOrbiterA, 47U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterD, 21U)) + aOrbiterG);
            aWandererD = aWandererD + ((((RotL64(aScatter, 47U) + RotL64(aOrbiterH, 36U)) + aOrbiterB) + RotL64(aCarry, 51U)) + aNonceWordH);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 10U) + RotL64(aOrbiterF, 5U)) + aOrbiterK);
            aWandererB = aWandererB + ((((RotL64(aIngress, 27U) + RotL64(aOrbiterJ, 13U)) + aOrbiterG) + aNonceWordL) + aWandererUpdateSaltC[((aIndex + 4U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 3U));
            aCarry = aCarry + (RotL64(aWandererB, 21U) ^ aWandererH);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 43U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 6U));
            aCarry = aCarry + RotL64(aWandererI, 29U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 23353U)) & S_BLOCK1], 13U) ^ RotL64(aFireLaneD[((aIndex + 20026U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 22856U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 19110U)) & S_BLOCK1], 47U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 21367U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 16642U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aIngress, 27U) + RotL64(aCross, 4U)) ^ (RotL64(aPrevious, 39U) + RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterJ = (aWandererJ + RotL64(aCross, 35U)) + 13442819395490639310U;
            aOrbiterD = (aWandererC + RotL64(aScatter, 26U)) + 8187292523194120936U;
            aOrbiterH = ((aWandererD + RotL64(aIngress, 57U)) + RotL64(aCarry, 3U)) + 11469697159823131388U;
            aOrbiterK = (aWandererK + RotL64(aPrevious, 3U)) + 13414083692375929653U;
            aOrbiterB = ((aWandererG + RotL64(aIngress, 39U)) + 11404010733687907517U) + aOrbiterAssignSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterC = (aWandererF + RotL64(aPrevious, 11U)) + 6783212827186218247U;
            aOrbiterE = (((aWandererE + RotL64(aScatter, 21U)) + RotL64(aCarry, 19U)) + 8561131439340372614U) + aNonceWordK;
            aOrbiterG = (((aWandererI + RotL64(aCross, 44U)) + RotL64(aCarry, 53U)) + 6252609642004429113U) + aOrbiterAssignSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterI = ((aWandererA + RotL64(aScatter, 53U)) + 12804867444200448952U) + aNonceWordF;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 2739648749603690781U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 14808861217017399752U;
            aOrbiterH = RotL64((aOrbiterH * 373911885694012101U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 17588866502571268888U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 5882260142735642980U;
            aOrbiterC = RotL64((aOrbiterC * 7688252946143263869U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 15493099088132862949U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 5175647411532429582U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 15226544495598541883U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 14279707376173642767U) + aNonceWordH;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 6826363572161275158U;
            aOrbiterE = RotL64((aOrbiterE * 5263708315440161809U), 39U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 13267185753040999992U) + aNonceWordN;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 9980987858092888720U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13210290848800728635U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 3582972937645514549U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 10140409019562890804U;
            aOrbiterD = RotL64((aOrbiterD * 6944490201647678479U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 6160444117287330557U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 16344602960561293113U;
            aOrbiterG = RotL64((aOrbiterG * 2319964919335633293U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 3497141036108337171U) + aOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 91269118352540308U;
            aOrbiterI = RotL64((aOrbiterI * 5160060720189045505U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 12739932748793144857U) + aNonceWordL;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 12820180915064791197U;
            aOrbiterK = RotL64((aOrbiterK * 5843849637411948699U), 3U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterE, 44U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 47U));
            aIngress = aIngress + (RotL64(aOrbiterH, 53U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 57U));
            aIngress = aIngress + RotL64(aOrbiterI, 40U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aCross, 51U) + aOrbiterH) + RotL64(aOrbiterJ, 60U)) + aNonceWordE) + aWandererUpdateSaltD[((aIndex + 20U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 36U) + RotL64(aOrbiterE, 11U)) + aOrbiterD);
            aWandererA = aWandererA + ((RotL64(aPrevious, 29U) + RotL64(aOrbiterC, 3U)) + aOrbiterD);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterI, 37U)) + aOrbiterH);
            aWandererD = aWandererD + ((((RotL64(aIngress, 43U) + aOrbiterJ) + RotL64(aOrbiterB, 47U)) + RotL64(aCarry, 29U)) + aWandererUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterI, 21U)) + aOrbiterC);
            aWandererG = aWandererG + (((RotL64(aCross, 13U) + aOrbiterK) + RotL64(aOrbiterG, 52U)) + RotL64(aCarry, 51U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 5U) + aOrbiterG) + RotL64(aOrbiterI, 41U)) + aNonceWordC);
            aWandererE = aWandererE + ((RotL64(aIngress, 24U) + aOrbiterE) + RotL64(aOrbiterB, 29U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 43U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 18U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 13U));
            aCarry = aCarry + (RotL64(aWandererC, 21U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererK, 29U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 28188U)) & S_BLOCK1], 38U) ^ RotL64(aFireLaneC[((aIndex + 31757U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aOperationLaneA[((aIndex + 29965U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 30369U)) & S_BLOCK1], 60U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 30373U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 31586U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCarry, 58U) ^ RotL64(aIngress, 11U)) + (RotL64(aCross, 39U) ^ RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterD = (aWandererF + RotL64(aCross, 34U)) + 2974056819475622600U;
            aOrbiterI = ((aWandererD + RotL64(aPrevious, 47U)) + RotL64(aCarry, 57U)) + 7345051759236356098U;
            aOrbiterK = ((aWandererH + RotL64(aScatter, 21U)) + 12738468816846628882U) + aNonceWordF;
            aOrbiterF = ((aWandererK + RotL64(aIngress, 27U)) + 7694520596043297922U) + aOrbiterAssignSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = (aWandererA + RotL64(aCross, 38U)) + 5530753590015084774U;
            aOrbiterC = ((aWandererG + RotL64(aIngress, 13U)) + RotL64(aCarry, 37U)) + 3776309161718383105U;
            aOrbiterJ = (((aWandererI + RotL64(aPrevious, 3U)) + 784780304358106404U) + aOrbiterAssignSaltC[(((31U - aIndex) + 10U)) & S_SALT1]) + aNonceWordM;
            aOrbiterA = (((aWandererE + RotL64(aScatter, 57U)) + RotL64(aCarry, 27U)) + 8999942326995036509U) + aNonceWordC;
            aOrbiterH = ((aWandererJ + RotL64(aIngress, 43U)) + 5194986506064092779U) + aNonceWordO;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 7920040007459652762U) + aNonceWordK;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 11311997270710107937U) ^ aOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 6227571709361790209U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 5365231114813547251U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 8630110234623825263U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 2735881715888325759U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 2358235238039571072U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 18059414891616491807U;
            aOrbiterA = RotL64((aOrbiterA * 17150786106857185467U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 14526050556461782864U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 6937282036603272474U;
            aOrbiterC = RotL64((aOrbiterC * 14954512365270028029U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 10105832250694931310U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 3884223553012098137U;
            aOrbiterH = RotL64((aOrbiterH * 16340956813003906195U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 10385284339549648087U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 1257633893341505930U;
            aOrbiterJ = RotL64((aOrbiterJ * 2669950791270500977U), 29U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterH) + 5528890519572824318U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordH;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 15664241747527713256U) ^ aNonceWordP;
            aOrbiterD = RotL64((aOrbiterD * 16670884497088220497U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 14264122979415331887U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 17985061405540198036U) ^ aOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2729487440173395133U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 1663986734997903415U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 3706166884286400587U;
            aOrbiterF = RotL64((aOrbiterF * 10549736618301955745U), 57U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterC, 39U);
            aIngress = aIngress + (RotL64(aOrbiterK, 23U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterJ, 60U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterA, 27U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterF, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aIngress, 19U) + RotL64(aOrbiterI, 42U)) + aOrbiterK) + RotL64(aCarry, 41U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 43U) + aOrbiterJ) + RotL64(aOrbiterE, 51U));
            aWandererH = aWandererH + (((RotL64(aCross, 58U) + RotL64(aOrbiterH, 3U)) + aOrbiterC) + RotL64(aCarry, 11U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 23U) + aOrbiterE) + RotL64(aOrbiterK, 19U)) + aNonceWordE);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 53U) + aOrbiterK) + RotL64(aOrbiterC, 47U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterE, 35U)) + aOrbiterF);
            aWandererA = aWandererA + ((((RotL64(aCross, 39U) + aOrbiterA) + RotL64(aOrbiterH, 27U)) + aNonceWordI) + aWandererUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((((RotL64(aIngress, 4U) + RotL64(aOrbiterD, 58U)) + aOrbiterK) + aNonceWordD) + aWandererUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aCross, 29U) + RotL64(aOrbiterF, 11U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererK, 47U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererG, 38U) ^ aWandererH);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 43U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 35U));
            aCarry = aCarry + RotL64(aWandererF, 11U);
            aCarry = aCarry + RotL64(aIngress, 54U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xE950D4C66916A75BULL + 0x8F8C670E449ECA48ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xFC51782C388F95CDULL + 0xBE8DA040C7F7BC1EULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xB0E64AC38803E29BULL + 0x9E5EEBDD16308533ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xD86505BD002A5FADULL + 0xC54E76448E57DE67ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xBD93085F754E91E7ULL + 0xC685CDB9E1D1832AULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xCCCBB474B075A0F1ULL + 0x8528184593F431E2ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xBAD0488B53C2C49DULL + 0x8B3DC823235D2981ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xD55C13DFFD9ECF3DULL + 0xBA63B3F80067CDEEULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xF632CD48A84E8A7DULL + 0xD6CF539EBE757BD9ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xCCE175CE546E7141ULL + 0x9F50906D693CB033ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xF99B29EE5444AEFBULL + 0xB6E3F0F52F562E0FULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xDF832CE7DA0C78BDULL + 0xE328108DBEF0D894ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xE2BA955F3C3D5779ULL + 0xCAFFAC11E5F4E9D7ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xB29F0CADB65D2E69ULL + 0xF6EA9833A8AA260EULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xBF0BDA0240CBFAFFULL + 0x9D86417E3CBBF97DULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0x86AF5B5598DF33EFULL + 0x9D3F9D7B0F28D44FULL);
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
        // read from: aOperationLaneA, aOperationLaneB, aFireLaneC, aOperationLaneC, aOperationLaneD, aWorkLaneA, aFireLaneD, aWorkLaneB, aFireLaneA, aWorkLaneC, aFireLaneB
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 7480U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneB[((aIndex + 958U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 4946U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 7313U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneD[((aIndex + 2580U)) & S_BLOCK1], 52U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCross, 21U) + RotL64(aPrevious, 6U)) ^ (RotL64(aCarry, 57U) ^ RotL64(aIngress, 37U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterI = ((aWandererF + RotL64(aCross, 37U)) + 12849591986267890852U) + aOrbiterAssignSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = (((aWandererG + RotL64(aIngress, 53U)) + RotL64(aCarry, 13U)) + 8232614804696815750U) + aNonceWordA;
            aOrbiterA = (((aWandererE + RotL64(aScatter, 11U)) + RotL64(aCarry, 27U)) + 12141567259210877281U) + aNonceWordO;
            aOrbiterC = ((aWandererB + RotL64(aPrevious, 29U)) + 2928641981037885644U) + aOrbiterAssignSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterF = ((aWandererC + RotL64(aCross, 20U)) + RotL64(aCarry, 53U)) + 980733350554783938U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 2683985177993350746U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 14532148403815527355U) ^ aOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 15985362037094864225U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 7736296629433884203U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 10428437770166310549U;
            aOrbiterG = RotL64((aOrbiterG * 326634742742373401U), 27U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterF) + 18327174144859461029U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordP;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 6810436935194432002U;
            aOrbiterC = RotL64((aOrbiterC * 2715987179577753597U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 12606153309690753435U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 17123256945895150555U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13469111258504672565U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 9057777759026189541U) + aOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 16478485918911194442U) ^ aNonceWordD;
            aOrbiterI = RotL64((aOrbiterI * 11054247078884894131U), 11U);
            //
            aIngress = RotL64(aOrbiterF, 13U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterI, 54U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterC, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aScatter, 39U) + RotL64(aOrbiterG, 19U)) + aOrbiterF) + RotL64(aCarry, 51U)) + aWandererUpdateSaltD[((aIndex + 18U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 5U) + aOrbiterA) + RotL64(aOrbiterC, 48U));
            aWandererF = aWandererF + ((((RotL64(aIngress, 19U) + aOrbiterC) + RotL64(aOrbiterG, 37U)) + RotL64(aCarry, 37U)) + aNonceWordH);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterG, 3U)) + aOrbiterI) + aWandererUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 58U) + RotL64(aOrbiterG, 29U)) + aOrbiterA) + aNonceWordM);
            //
            aCarry = aCarry + (RotL64(aWandererE, 29U) ^ aWandererB);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 48U));
            aCarry = aCarry + RotL64(aWandererG, 39U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // kdf_a_loop_c loop 2
        // ingress from: aWorkLaneA, aOperationLaneC, aFireLaneD
        // ingress directions: aWorkLaneA forward forced, aOperationLaneC forward forced, aFireLaneD forward/backward random
        // cross from: aOperationLaneA, aOperationLaneD, aOperationLaneB
        // cross directions: aOperationLaneA backward forced, aOperationLaneD backward forced, aOperationLaneB backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 15093U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneC[((aIndex + 10938U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 13186U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 10588U)) & S_BLOCK1], 14U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 9892U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 10435U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aPrevious, 21U) + RotL64(aCross, 51U)) ^ (RotL64(aCarry, 6U) ^ RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterD = ((((aWandererB + RotL64(aIngress, 11U)) + RotL64(aCarry, 57U)) + 8604208734152026945U) + aOrbiterAssignSaltE[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterB = (((aWandererJ + RotL64(aScatter, 3U)) + RotL64(aCarry, 11U)) + 1374329953253889829U) + aNonceWordO;
            aOrbiterH = ((aWandererG + RotL64(aCross, 19U)) + 5779278910548228339U) + aOrbiterAssignSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterJ = ((aWandererK + RotL64(aPrevious, 29U)) + RotL64(aCarry, 37U)) + 17670451230882805140U;
            aOrbiterG = (aWandererI + RotL64(aCross, 50U)) + 8193848740764866860U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 15801168428145650104U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterD) ^ 2584718176087499066U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterH = RotL64((aOrbiterH * 5687189872016780831U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 14950366247822737997U) + aOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 9779293225265670135U) ^ aNonceWordM;
            aOrbiterD = RotL64((aOrbiterD * 11625969538497982117U), 37U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 8688968319288372383U) + aNonceWordK;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 13665723186950342601U;
            aOrbiterJ = RotL64((aOrbiterJ * 292035540396910837U), 53U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 9395428688359973510U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 2152719218018108418U;
            aOrbiterG = RotL64((aOrbiterG * 15271961483518392671U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 1350324137411377992U) + aOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 8729317951386057921U;
            aOrbiterB = RotL64((aOrbiterB * 6008790836417785083U), 3U);
            //
            aIngress = RotL64(aOrbiterD, 19U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 54U));
            aIngress = aIngress + RotL64(aOrbiterB, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aIngress, 26U) + aOrbiterJ) + RotL64(aOrbiterB, 39U));
            aWandererG = aWandererG + ((((RotL64(aScatter, 5U) + RotL64(aOrbiterD, 47U)) + aOrbiterG) + RotL64(aCarry, 53U)) + aWandererUpdateSaltB[((aIndex + 13U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 13U) + aOrbiterH) + RotL64(aOrbiterG, 23U)) + aWandererUpdateSaltF[((aIndex + 18U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 41U) + RotL64(aOrbiterJ, 3U)) + aOrbiterH) + RotL64(aCarry, 39U)) + aNonceWordG);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterD, 14U)) + aOrbiterJ) + aNonceWordL);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 11U));
            aCarry = aCarry + (RotL64(aWandererB, 53U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererG, 43U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_a_loop_c loop 3
        // ingress from: aWorkLaneB, aOperationLaneD, aFireLaneA
        // ingress directions: aWorkLaneB forward forced, aOperationLaneD forward forced, aFireLaneA forward/backward random
        // cross from: aWorkLaneA, aOperationLaneB, aOperationLaneC
        // cross directions: aWorkLaneA backward forced, aOperationLaneB backward forced, aOperationLaneC backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 21641U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneD[((aIndex + 16928U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 17899U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22900U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 23774U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aOperationLaneC[((aIndex + 18976U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCross, 39U) + RotL64(aIngress, 10U)) ^ (RotL64(aPrevious, 51U) + RotL64(aCarry, 27U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterK = ((((aWandererA + RotL64(aScatter, 29U)) + RotL64(aCarry, 39U)) + 18255347001097480328U) + aOrbiterAssignSaltC[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordN;
            aOrbiterD = ((aWandererD + RotL64(aCross, 43U)) + 13679246790311505735U) + aNonceWordD;
            aOrbiterE = ((aWandererF + RotL64(aIngress, 52U)) + 10565839529765027116U) + aOrbiterAssignSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterF = ((aWandererB + RotL64(aPrevious, 11U)) + RotL64(aCarry, 3U)) + 14327172566224769901U;
            aOrbiterJ = (((aWandererC + RotL64(aCross, 21U)) + RotL64(aCarry, 27U)) + 16239024612038195174U) + aNonceWordK;
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 13800012174212131890U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 13900288860157577583U) ^ aOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 13177682776510523095U), 21U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterJ) + 4144386119777112740U) + aOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1]) + aNonceWordA;
            aOrbiterK = (((aOrbiterK ^ aOrbiterF) ^ 3154558262670631372U) ^ aOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterK = RotL64((aOrbiterK * 13236911910092437063U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 7456728543137614001U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 11709519851158935384U;
            aOrbiterF = RotL64((aOrbiterF * 7016689518570071587U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 15607438907832240304U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 9276575329661725624U;
            aOrbiterJ = RotL64((aOrbiterJ * 8879744070762412745U), 37U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 6459435969129449226U) + aNonceWordO;
            aOrbiterD = (((aOrbiterD ^ aOrbiterJ) ^ 6442382118416542275U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterD = RotL64((aOrbiterD * 2921027306686588233U), 29U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterD, 3U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 30U));
            aIngress = aIngress + RotL64(aOrbiterK, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aIngress, 13U) + aOrbiterJ) + RotL64(aOrbiterF, 39U)) + aNonceWordP);
            aWandererD = aWandererD + (((((RotL64(aCross, 51U) + aOrbiterK) + RotL64(aOrbiterJ, 18U)) + RotL64(aCarry, 35U)) + aNonceWordM) + aWandererUpdateSaltA[((aIndex + 19U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 34U) + aOrbiterK) + RotL64(aOrbiterD, 3U)) + aNonceWordJ);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 43U) + aOrbiterE) + RotL64(aOrbiterK, 29U)) + RotL64(aCarry, 51U)) + aNonceWordG);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 21U) + RotL64(aOrbiterK, 47U)) + aOrbiterF) + aWandererUpdateSaltE[((aIndex + 14U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 21U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererB, 29U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererA, 51U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 29331U)) & S_BLOCK1], 22U) ^ RotL64(aWorkLaneA[((aIndex + 26864U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 31985U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 31451U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 25513U)) & S_BLOCK1], 57U));
            aCross ^= (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 25919U)) & S_BLOCK1], 14U) ^ RotL64(aOperationLaneA[((aIndex + 24798U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aPrevious, 19U) ^ RotL64(aCross, 57U)) ^ (RotL64(aCarry, 6U) + RotL64(aIngress, 41U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterA = (((aWandererB + RotL64(aIngress, 21U)) + RotL64(aCarry, 41U)) + 12029393034357490020U) + aNonceWordH;
            aOrbiterI = ((aWandererJ + RotL64(aCross, 39U)) + 4526754731580694987U) + aNonceWordE;
            aOrbiterH = ((((aWandererI + RotL64(aPrevious, 47U)) + RotL64(aCarry, 5U)) + 17060419646421271853U) + aOrbiterAssignSaltD[((aIndex + 28U)) & S_SALT1]) + aNonceWordL;
            aOrbiterK = (((aWandererC + RotL64(aScatter, 57U)) + RotL64(aCarry, 21U)) + 4128488893837059683U) + aOrbiterAssignSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = ((aWandererF + RotL64(aIngress, 10U)) + 12706894827547160110U) + aNonceWordG;
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 12506324593645825056U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 12581344490649250025U) ^ aOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 16311882267466003291U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 14357032418199130132U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 15341977701796331249U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 6332369248718076031U), 29U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterD) + 7086602307544733241U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1]) + aNonceWordN;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 12398300065276832486U) ^ aNonceWordC;
            aOrbiterA = RotL64((aOrbiterA * 18157408831225635333U), 21U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 2499745046076601988U) + aNonceWordP;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 7249361592814001829U;
            aOrbiterK = RotL64((aOrbiterK * 14597139848072319685U), 39U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterA) + 3254456186337366437U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordI;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 3472973415969046680U;
            aOrbiterI = RotL64((aOrbiterI * 14583566953969168353U), 3U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterD, 58U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 35U));
            aIngress = aIngress + RotL64(aOrbiterH, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aPrevious, 13U) + RotL64(aOrbiterK, 13U)) + aOrbiterD) + RotL64(aCarry, 11U)) + aNonceWordA);
            aWandererC = aWandererC ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterA, 37U)) + aOrbiterD) + aWandererUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aIngress, 54U) + RotL64(aOrbiterH, 27U)) + aOrbiterK) + RotL64(aCarry, 51U)) + aNonceWordJ);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterI, 46U)) + aOrbiterA) + aNonceWordK);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 39U) + RotL64(aOrbiterA, 5U)) + aOrbiterK) + aNonceWordB) + aWandererUpdateSaltC[((aIndex + 20U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 40U) ^ aWandererF);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 3U));
            aCarry = aCarry + RotL64(aWandererJ, 53U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xE4A6234403322089ULL + 0xDF82230EEA7BD27CULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x83517BD6FFA2D5E9ULL + 0xD265809F9D187658ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xA28811CBF1927E61ULL + 0x89C3E9C82925D7A4ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xBB5B43F54E23F151ULL + 0xD6C11BF20B482AECULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xF8FEDEB79C632DE5ULL + 0x98ECBDF54E01FEB6ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xD19A0BBE00195CA9ULL + 0x9720CE9B08B895FDULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xB0C050D86C9B93E5ULL + 0xC88B1253AA031276ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xF1B11528CBDA104BULL + 0x9934FFA33963B092ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xACB6DE77F34B05FBULL + 0xD9E5B9DA5B2C8D80ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xFC8B58829D50E89DULL + 0xD5943885580E1AECULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xB164747F094016A7ULL + 0xDBCC138C6EB74A6BULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xF8CF1FF4E61CF06BULL + 0xF4EEE6E1DF58B15BULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xDF7FAE78A9A46381ULL + 0xD259942065711DE9ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xE6837AA8BB3240E1ULL + 0xAFBB966DA6CB7296ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xF4FE37B39F1B1879ULL + 0xD0127A1A93A86B3BULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0x9F3F554FEC11042FULL + 0x94099FACFAD99B9BULL);
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
        // read from: aExpandLaneA, aExpandLaneB, aOperationLaneB, aExpandLaneC, aExpandLaneD, aFireLaneC, aWorkLaneA, aFireLaneD, aFireLaneA, aWorkLaneB, aOperationLaneA, aOperationLaneD, aWorkLaneC, aFireLaneB, aOperationLaneC
        // write to: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // kdf_a_loop_d loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aOperationLaneB
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aOperationLaneB forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD, aFireLaneC
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward forced, aFireLaneC backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 5131U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneB[((aIndex + 524U)) & S_BLOCK1], 12U));
            aIngress ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 2156U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 3899U)) & S_BLOCK1], 10U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 7174U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aFireLaneC[((aIndex + 139U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aIngress, 23U)) ^ (RotL64(aCross, 48U) + RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterA = ((aWandererF + RotL64(aIngress, 57U)) + RotL64(aCarry, 51U)) + 898812731947995389U;
            aOrbiterD = (((aWandererI + RotL64(aScatter, 3U)) + RotL64(aCarry, 3U)) + 8677347622525527167U) + aNonceWordI;
            aOrbiterG = ((aWandererG + RotL64(aPrevious, 19U)) + 770321564027567654U) + aOrbiterAssignSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterI = ((aWandererA + RotL64(aCross, 46U)) + RotL64(aCarry, 21U)) + 11020474858081526395U;
            aOrbiterC = ((aWandererK + RotL64(aScatter, 35U)) + 17289793580414993470U) + aOrbiterAssignSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterE = ((aWandererH + RotL64(aIngress, 11U)) + 10111912559295118444U) + aNonceWordB;
            aOrbiterH = (aWandererC + RotL64(aPrevious, 29U)) + 8083622125544542011U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 7149858558922988240U) + aNonceWordH;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 5919683821379905699U;
            aOrbiterG = RotL64((aOrbiterG * 16705119888884231567U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 6860902846079238714U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 15083517836867542075U;
            aOrbiterA = RotL64((aOrbiterA * 4686657139237578325U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 14852868368708376381U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 9860233289028878323U) ^ aOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 13418143547952204667U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 772406119079116272U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 7971141501337627589U;
            aOrbiterC = RotL64((aOrbiterC * 10168120622976358617U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 8478568022896691911U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 4027604850785607101U) ^ aOrbiterUpdateSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4826627523578901467U), 51U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterG) + 17199331557841535430U) + aOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1]) + aNonceWordM;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 7515957656979776361U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5468950152869656599U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 17138249294921502391U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 16236812863923234668U;
            aOrbiterD = RotL64((aOrbiterD * 2925542836624164807U), 13U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterH, 60U);
            aIngress = aIngress + (RotL64(aOrbiterE, 53U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterD, 39U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterI, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aIngress, 21U) + RotL64(aOrbiterD, 11U)) + aOrbiterC) + RotL64(aCarry, 47U)) + aNonceWordJ);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 29U) + aOrbiterH) + RotL64(aOrbiterE, 21U)) + aNonceWordL);
            aWandererA = aWandererA + (((((RotL64(aScatter, 5U) + aOrbiterH) + RotL64(aOrbiterC, 3U)) + RotL64(aCarry, 13U)) + aNonceWordN) + aWandererUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aCross, 43U) + RotL64(aOrbiterH, 29U)) + aOrbiterG) + aWandererUpdateSaltA[((aIndex + 13U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 37U) + RotL64(aOrbiterG, 47U)) + aOrbiterI) + aNonceWordO);
            aWandererF = aWandererF ^ ((RotL64(aCross, 53U) + aOrbiterI) + RotL64(aOrbiterC, 57U));
            aWandererI = aWandererI + ((RotL64(aIngress, 12U) + aOrbiterA) + RotL64(aOrbiterE, 36U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 29U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererA, 43U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererC, 34U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererH, 23U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 2
        // ingress from: aWorkLaneA, aExpandLaneC, aFireLaneD
        // ingress directions: aWorkLaneA forward forced, aExpandLaneC forward forced, aFireLaneD forward/backward random
        // cross from: aExpandLaneA, aExpandLaneD, aFireLaneA
        // cross directions: aExpandLaneA backward forced, aExpandLaneD backward forced, aFireLaneA backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 15718U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneC[((aIndex + 13658U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 15794U)) & S_BLOCK1], 40U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 8487U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 12888U)) & S_BLOCK1], 38U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 13853U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aIngress, 35U) + RotL64(aCarry, 53U)) ^ (RotL64(aPrevious, 5U) ^ RotL64(aCross, 22U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterC = ((((aWandererI + RotL64(aPrevious, 29U)) + RotL64(aCarry, 39U)) + 9888431329297626900U) + aOrbiterAssignSaltF[((aIndex + 4U)) & S_SALT1]) + aNonceWordP;
            aOrbiterK = (((aWandererF + RotL64(aScatter, 5U)) + 2937735167534624403U) + aOrbiterAssignSaltE[(((31U - aIndex) + 28U)) & S_SALT1]) + aNonceWordA;
            aOrbiterJ = (((aWandererH + RotL64(aIngress, 35U)) + RotL64(aCarry, 19U)) + 17626022970343789617U) + aNonceWordE;
            aOrbiterI = (aWandererE + RotL64(aCross, 12U)) + 5665660859333693743U;
            aOrbiterH = ((aWandererD + RotL64(aIngress, 43U)) + 1060537034632076669U) + aNonceWordN;
            aOrbiterD = (aWandererG + RotL64(aPrevious, 53U)) + 743777763907175800U;
            aOrbiterE = ((aWandererC + RotL64(aScatter, 19U)) + RotL64(aCarry, 53U)) + 5744905970181808845U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 3545351394494002180U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 4877547088414106007U;
            aOrbiterJ = RotL64((aOrbiterJ * 5416792889338547109U), 47U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterH) + 11669378338379598445U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordO;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 2961072441706158212U;
            aOrbiterC = RotL64((aOrbiterC * 2677988507090705371U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 13984945589234919765U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 1433097875470903205U) ^ aNonceWordM;
            aOrbiterI = RotL64((aOrbiterI * 451996840039906781U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 716415411025451152U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 8542286150858297810U) ^ aOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 9139015340823332449U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 12932391786479661299U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 14005503313299177013U;
            aOrbiterD = RotL64((aOrbiterD * 802663466907819743U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 9382792812676318046U) + aNonceWordG;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 5138554251079724724U;
            aOrbiterE = RotL64((aOrbiterE * 6386016499265056247U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 8522380066269546172U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 11825536408101906458U) ^ aOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 17042837108792016849U), 35U);
            //
            aIngress = RotL64(aOrbiterC, 19U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterI, 41U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterK, 35U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterE, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aCross, 35U) + aOrbiterE) + RotL64(aOrbiterC, 51U)) + aNonceWordH);
            aWandererH = aWandererH + ((((RotL64(aScatter, 41U) + aOrbiterK) + RotL64(aOrbiterH, 12U)) + RotL64(aCarry, 47U)) + aNonceWordK);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 19U) + aOrbiterD) + RotL64(aOrbiterK, 29U));
            aWandererD = aWandererD + ((RotL64(aPrevious, 5U) + RotL64(aOrbiterI, 57U)) + aOrbiterC);
            aWandererG = aWandererG ^ (((RotL64(aCross, 48U) + aOrbiterE) + RotL64(aOrbiterJ, 21U)) + aWandererUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 57U) + aOrbiterD) + RotL64(aOrbiterH, 5U)) + RotL64(aCarry, 21U)) + aNonceWordB);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 11U) + aOrbiterJ) + RotL64(aOrbiterD, 35U)) + aWandererUpdateSaltF[((aIndex + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 14U));
            aCarry = aCarry + (RotL64(aWandererG, 43U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererC, 29U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererE, 47U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 3
        // ingress from: aWorkLaneB, aExpandLaneD, aOperationLaneA
        // ingress directions: aWorkLaneB forward forced, aExpandLaneD forward forced, aOperationLaneA forward/backward random
        // cross from: aWorkLaneA, aExpandLaneB, aOperationLaneD
        // cross directions: aWorkLaneA backward forced, aExpandLaneB backward forced, aOperationLaneD backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 24283U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneD[((aIndex + 21401U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 18803U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21842U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 17812U)) & S_BLOCK1], 28U));
            aCross ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 20595U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aIngress, 43U) ^ RotL64(aCarry, 56U)) + (RotL64(aCross, 23U) ^ RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterH = (((aWandererB + RotL64(aPrevious, 47U)) + RotL64(aCarry, 53U)) + 8793908991006073956U) + aNonceWordF;
            aOrbiterD = (((aWandererJ + RotL64(aScatter, 13U)) + 2932916283348441943U) + aOrbiterAssignSaltD[((aIndex + 3U)) & S_SALT1]) + aNonceWordI;
            aOrbiterA = (aWandererF + RotL64(aIngress, 21U)) + 11069042087940968262U;
            aOrbiterF = ((aWandererI + RotL64(aCross, 5U)) + RotL64(aCarry, 27U)) + 14369628676782894441U;
            aOrbiterC = (aWandererH + RotL64(aScatter, 53U)) + 8602903272780978282U;
            aOrbiterK = ((aWandererA + RotL64(aCross, 60U)) + 3827036107178568820U) + aOrbiterAssignSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterG = ((aWandererC + RotL64(aIngress, 35U)) + RotL64(aCarry, 5U)) + 8905245209036772489U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 13331387530760017893U) + aNonceWordC;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 9880107580289737823U;
            aOrbiterA = RotL64((aOrbiterA * 10302652857542703753U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 10199619040626900278U) + aOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 2466307560891374281U;
            aOrbiterC = RotL64((aOrbiterC * 6295342978834217571U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 13973403407981259448U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 2851460278409385243U;
            aOrbiterH = RotL64((aOrbiterH * 11226902976321781743U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 10365453393815690776U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 2382382358987358791U) ^ aNonceWordL;
            aOrbiterG = RotL64((aOrbiterG * 481563628980705781U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 5058198848163792422U) + aOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 10500434740387593487U;
            aOrbiterK = RotL64((aOrbiterK * 5946747708776079787U), 21U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 11289798395177667084U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 14327152153231286666U) ^ aNonceWordG;
            aOrbiterD = RotL64((aOrbiterD * 18155778059595245561U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 8065137263811956313U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 3865153574847924816U) ^ aOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 9495741102667755161U), 11U);
            //
            aIngress = RotL64(aOrbiterC, 27U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 6U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 13U));
            aIngress = aIngress + RotL64(aOrbiterG, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aIngress, 43U) + aOrbiterD) + RotL64(aOrbiterH, 11U)) + aNonceWordM);
            aWandererI = aWandererI ^ ((((RotL64(aCross, 11U) + RotL64(aOrbiterD, 36U)) + aOrbiterF) + aNonceWordO) + aWandererUpdateSaltB[((aIndex + 14U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aPrevious, 30U) + aOrbiterC) + RotL64(aOrbiterK, 27U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterC, 57U)) + aOrbiterF);
            aWandererB = aWandererB + (((RotL64(aIngress, 5U) + aOrbiterD) + RotL64(aOrbiterG, 51U)) + RotL64(aCarry, 3U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 51U) + aOrbiterA) + RotL64(aOrbiterC, 5U));
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 37U) + aOrbiterH) + RotL64(aOrbiterK, 43U)) + RotL64(aCarry, 37U)) + aWandererUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 43U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 39U));
            aCarry = aCarry + (RotL64(aWandererB, 52U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererA, 57U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 4
        // ingress from: aWorkLaneC, aWorkLaneA, aFireLaneB
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aFireLaneB forward/backward random
        // cross from: aWorkLaneB, aExpandLaneC, aOperationLaneC
        // cross directions: aWorkLaneB backward forced, aExpandLaneC backward forced, aOperationLaneC backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 31888U)) & S_BLOCK1], 54U) ^ RotL64(aWorkLaneA[((aIndex + 25750U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 25242U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 30399U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 24840U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 29299U)) & S_BLOCK1], 12U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aIngress, 10U) ^ RotL64(aCross, 53U)) ^ (RotL64(aPrevious, 27U) + RotL64(aCarry, 39U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterD = (((aWandererK + RotL64(aScatter, 57U)) + RotL64(aCarry, 47U)) + 3105313968748067810U) + aNonceWordD;
            aOrbiterF = (((aWandererG + RotL64(aPrevious, 3U)) + RotL64(aCarry, 3U)) + 9977249451119627064U) + aNonceWordB;
            aOrbiterJ = (aWandererD + RotL64(aCross, 29U)) + 17941392803495349366U;
            aOrbiterG = (((aWandererE + RotL64(aIngress, 19U)) + 4279533326705471133U) + aOrbiterAssignSaltA[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordH;
            aOrbiterI = ((aWandererJ + RotL64(aScatter, 47U)) + 13983828966811580039U) + aNonceWordF;
            aOrbiterB = (((aWandererB + RotL64(aIngress, 41U)) + RotL64(aCarry, 21U)) + 3983490984234810378U) + aOrbiterAssignSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = (aWandererH + RotL64(aCross, 10U)) + 308786542215259956U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 8443607695364427037U) + aOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 14939626441464340668U) ^ aNonceWordM;
            aOrbiterJ = RotL64((aOrbiterJ * 16793255020331774983U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 9350693577306121110U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 1717071159396961752U) ^ aOrbiterUpdateSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11062480662625054525U), 41U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 15911765265202100610U) + aNonceWordE;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 14898546272333182767U) ^ aOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2674900543810733067U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 3560903518513465868U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 5367062725726860234U) ^ aNonceWordO;
            aOrbiterF = RotL64((aOrbiterF * 8521908836601319553U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 15233321480618877327U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 9288449812290126074U;
            aOrbiterG = RotL64((aOrbiterG * 6815298520404038519U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 5504840529511585676U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 6825598386801620046U) ^ aNonceWordN;
            aOrbiterE = RotL64((aOrbiterE * 11666542445846250077U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 6433024450721339470U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 97934156644929458U;
            aOrbiterD = RotL64((aOrbiterD * 8630530773006923215U), 21U);
            //
            aIngress = RotL64(aOrbiterG, 39U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterD, 47U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 13U));
            aIngress = aIngress + RotL64(aOrbiterB, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aScatter, 41U) + RotL64(aOrbiterI, 13U)) + aOrbiterG) + aNonceWordI);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterB, 57U)) + aOrbiterG);
            aWandererD = aWandererD + ((((RotL64(aCross, 13U) + aOrbiterI) + RotL64(aOrbiterJ, 26U)) + RotL64(aCarry, 23U)) + aWandererUpdateSaltD[((aIndex + 11U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 3U) + aOrbiterE) + RotL64(aOrbiterF, 39U));
            aWandererH = aWandererH + ((RotL64(aCross, 35U) + aOrbiterE) + RotL64(aOrbiterB, 51U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 19U) + aOrbiterD) + RotL64(aOrbiterB, 5U));
            aWandererK = aWandererK + (((((RotL64(aIngress, 26U) + RotL64(aOrbiterF, 19U)) + aOrbiterD) + RotL64(aCarry, 37U)) + aNonceWordJ) + aWandererUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 46U) ^ aWandererK);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 57U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 3U));
            aCarry = aCarry + RotL64(aWandererB, 29U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xB6790DFA1672CCBFULL + 0x98660AA2DCACED00ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xD97A63E5BCADF4E3ULL + 0xF28BE3F0114723F6ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xDEE25DFEF512548BULL + 0xAAE4B85EB745BCC6ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x86F5D70D4E032C57ULL + 0xAB1C14FE62E1711EULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xF9292032C37D5751ULL + 0xC216F1691DB83E10ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xC299630E7F01E853ULL + 0xACD7D92E617AB2D0ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xC219AC5DD78CB75BULL + 0xDB5765E62B779ED2ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xE54267FBA843418BULL + 0x8B6ED4D5EA117F63ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xF8A056F211491B81ULL + 0xEAA770EB304F18BAULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xE9B872A84E91C127ULL + 0xC9A0CC139181CC77ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x9607A6FA28757ADFULL + 0x82EBCD0C62B56ECAULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xB9A01AE33D687921ULL + 0xEFFF6ADEE61D3A81ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0x9B47CBE3B28C81CFULL + 0xE2EB114AFDBC84DCULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0x9B3B42C641146BB1ULL + 0xC02A2A7B9741AE3FULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xFCCDC8B8FED2437FULL + 0xB189A4DF5FD61D90ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xBFC2FF550D99B8E3ULL + 0xC2B8A497E56AA046ULL);
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
        // read from: aWorkLaneA, aWorkLaneB, aFireLaneB, aWorkLaneC, aWorkLaneD, aOperationLaneA, aExpandLaneA, aOperationLaneC, aFireLaneD, aExpandLaneB, aOperationLaneD, aFireLaneC, aExpandLaneC, aOperationLaneB, aFireLaneA
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_a loop 1
        // ingress from: aWorkLaneA, aWorkLaneB, aFireLaneB
        // ingress directions: aWorkLaneA forward forced, aWorkLaneB forward forced, aFireLaneB forward/backward random
        // cross from: aWorkLaneC, aWorkLaneD, aOperationLaneA
        // cross directions: aWorkLaneC backward forced, aWorkLaneD backward forced, aOperationLaneA backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 494U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneB[((aIndex + 1819U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 3476U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 495U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 4521U)) & S_BLOCK1], 41U));
            aCross ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 2498U)) & S_BLOCK1], 52U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCross, 4U) + RotL64(aIngress, 37U)) + (RotL64(aCarry, 21U) ^ RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterF = ((aWandererD + RotL64(aScatter, 13U)) + RotL64(aCarry, 43U)) + 16124889768301047791U;
            aOrbiterI = ((aWandererF + RotL64(aCross, 3U)) + 11912338587186717280U) + aOrbiterAssignSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterH = (aWandererJ + RotL64(aPrevious, 47U)) + 8594012868813114354U;
            aOrbiterJ = (((aWandererG + RotL64(aIngress, 20U)) + RotL64(aCarry, 57U)) + 18281043566156682815U) + aNonceWordL;
            aOrbiterB = (aWandererI + RotL64(aCross, 53U)) + 16853106130200942302U;
            aOrbiterK = (((aWandererB + RotL64(aIngress, 35U)) + 2611212958619673086U) + aOrbiterAssignSaltB[((aIndex + 23U)) & S_SALT1]) + aNonceWordB;
            aOrbiterA = (((aWandererA + RotL64(aPrevious, 41U)) + RotL64(aCarry, 11U)) + 18039472325066855180U) + aNonceWordI;
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 14495785571345122046U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 4556063793412832418U;
            aOrbiterH = RotL64((aOrbiterH * 13166927543135467627U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 14896419970271244358U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 880028529183500036U;
            aOrbiterB = RotL64((aOrbiterB * 14228281807461251361U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 2379557167489415783U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterK) ^ 11854373946064529806U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterI = RotL64((aOrbiterI * 150755294320438887U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 1487252775956449964U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 12777924204511625545U;
            aOrbiterF = RotL64((aOrbiterF * 1366019527386994789U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 15998631485222477969U) + aOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 8864212892296191613U) ^ aNonceWordH;
            aOrbiterA = RotL64((aOrbiterA * 579242788050369815U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 17069347835763226743U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 7443008171694679791U;
            aOrbiterK = RotL64((aOrbiterK * 748894368884566607U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 17334256152350782002U) + aOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 8986626119086556393U) ^ aOrbiterUpdateSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 2258172145924120235U), 3U);
            //
            aIngress = RotL64(aOrbiterI, 47U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 29U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 13U));
            aIngress = aIngress + RotL64(aOrbiterJ, 56U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aIngress, 57U) + RotL64(aOrbiterK, 5U)) + aOrbiterI) + RotL64(aCarry, 39U)) + aNonceWordA);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterA, 57U)) + aOrbiterI);
            aWandererI = aWandererI + ((((RotL64(aScatter, 20U) + aOrbiterH) + RotL64(aOrbiterA, 50U)) + aNonceWordC) + aWandererUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 51U) + aOrbiterB) + RotL64(aOrbiterA, 43U));
            aWandererF = aWandererF + (((RotL64(aIngress, 11U) + RotL64(aOrbiterF, 13U)) + aOrbiterH) + aNonceWordN);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 37U) + aOrbiterJ) + RotL64(aOrbiterH, 35U)) + aWandererUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 27U) + aOrbiterA) + RotL64(aOrbiterF, 29U)) + RotL64(aCarry, 57U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 58U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererG, 27U) ^ aWandererI);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 35U));
            aCarry = aCarry + RotL64(aWandererA, 39U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 2
        // ingress from: aExpandLaneA, aWorkLaneC, aOperationLaneC
        // ingress directions: aExpandLaneA forward forced, aWorkLaneC forward forced, aOperationLaneC forward/backward random
        // cross from: aWorkLaneA, aWorkLaneD, aFireLaneD
        // cross directions: aWorkLaneA backward forced, aWorkLaneD backward forced, aFireLaneD backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 13725U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneC[((aIndex + 10176U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aOperationLaneC[((aIndex + 9234U)) & S_BLOCK1], 20U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 14072U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 16337U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 12958U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aIngress, 57U) ^ RotL64(aCarry, 5U)) + (RotL64(aPrevious, 21U) ^ RotL64(aCross, 44U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterG = (aWandererA + RotL64(aCross, 37U)) + 6342299552323486695U;
            aOrbiterA = ((((aWandererI + RotL64(aIngress, 13U)) + RotL64(aCarry, 39U)) + 12692748514781367538U) + aOrbiterAssignSaltF[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordF;
            aOrbiterF = (((aWandererB + RotL64(aPrevious, 6U)) + RotL64(aCarry, 27U)) + 8202639945493229155U) + aOrbiterAssignSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterH = ((aWandererC + RotL64(aScatter, 53U)) + 4439975701793231639U) + aNonceWordD;
            aOrbiterB = (aWandererK + RotL64(aIngress, 27U)) + 16774235182859553759U;
            aOrbiterK = (((aWandererF + RotL64(aScatter, 19U)) + RotL64(aCarry, 3U)) + 8764155413335405667U) + aNonceWordC;
            aOrbiterJ = (aWandererH + RotL64(aCross, 43U)) + 7167848811974967685U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 16768278912125334220U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 9090838954826296201U) ^ aOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 5459329624017272077U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 7644075729758006298U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 17326182797908071215U;
            aOrbiterG = RotL64((aOrbiterG * 2408330168749256075U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 16158809721888137555U) + aNonceWordE;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 8029938783858263694U) ^ aOrbiterUpdateSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 12628072435324195483U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 8716553521415553404U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 7012599977009208840U;
            aOrbiterJ = RotL64((aOrbiterJ * 8775355876188948851U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 13250558696578541499U) + aOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 13705957059101025396U;
            aOrbiterH = RotL64((aOrbiterH * 16889495686487056367U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 2796775206291902461U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 13741676263512390669U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10455782033465595947U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 1691908360612389252U) + aNonceWordL;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 4114939415206031540U;
            aOrbiterB = RotL64((aOrbiterB * 2797401802892718297U), 21U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterA, 5U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 22U));
            aIngress = aIngress + (RotL64(aOrbiterG, 57U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterF, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aIngress, 5U) + RotL64(aOrbiterG, 60U)) + aOrbiterH);
            aWandererC = aWandererC ^ ((((RotL64(aCross, 43U) + RotL64(aOrbiterF, 51U)) + aOrbiterK) + aNonceWordH) + aWandererUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 57U) + aOrbiterJ) + RotL64(aOrbiterK, 29U)) + RotL64(aCarry, 11U));
            aWandererB = aWandererB ^ ((((RotL64(aPrevious, 11U) + aOrbiterB) + RotL64(aOrbiterK, 19U)) + aNonceWordP) + aWandererUpdateSaltF[((aIndex + 15U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aIngress, 30U) + RotL64(aOrbiterH, 41U)) + aOrbiterA) + aNonceWordI);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterB, 13U)) + aOrbiterA);
            aWandererI = aWandererI + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterJ, 3U)) + aOrbiterB) + RotL64(aCarry, 43U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 43U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 28U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 57U));
            aCarry = aCarry + RotL64(aWandererA, 47U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 3
        // ingress from: aExpandLaneB, aWorkLaneD, aOperationLaneD
        // ingress directions: aExpandLaneB forward forced, aWorkLaneD forward forced, aOperationLaneD forward/backward random
        // cross from: aExpandLaneA, aWorkLaneB, aFireLaneC
        // cross directions: aExpandLaneA backward forced, aWorkLaneB backward forced, aFireLaneC backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 21896U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneD[((aIndex + 18666U)) & S_BLOCK1], 28U));
            aIngress ^= RotL64(aOperationLaneD[((aIndex + 17310U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 20563U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 17615U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aFireLaneC[((aIndex + 20825U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aIngress, 40U) + RotL64(aCross, 5U)) ^ (RotL64(aCarry, 27U) + RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterA = ((aWandererA + RotL64(aCross, 3U)) + RotL64(aCarry, 51U)) + 11450949896247900941U;
            aOrbiterK = (aWandererC + RotL64(aScatter, 51U)) + 3905542253538116335U;
            aOrbiterH = ((aWandererE + RotL64(aIngress, 13U)) + RotL64(aCarry, 5U)) + 9529740545977785305U;
            aOrbiterI = ((aWandererB + RotL64(aPrevious, 60U)) + 1856876631533143492U) + aNonceWordG;
            aOrbiterF = (((aWandererF + RotL64(aCross, 27U)) + 84253466320181686U) + aOrbiterAssignSaltE[((aIndex + 10U)) & S_SALT1]) + aNonceWordL;
            aOrbiterE = (((aWandererD + RotL64(aScatter, 21U)) + 12577480918745432444U) + aOrbiterAssignSaltC[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordA;
            aOrbiterG = ((aWandererJ + RotL64(aPrevious, 35U)) + RotL64(aCarry, 21U)) + 5625703170397704029U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 694608607323629282U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 3993981243536262204U;
            aOrbiterH = RotL64((aOrbiterH * 2502835860198146381U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 4119215953484892051U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 8785040118556157146U) ^ aOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 17113521266125471625U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 16234403619456882890U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 10398727475672860610U;
            aOrbiterG = RotL64((aOrbiterG * 5086871400049644715U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 18327987141759096769U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 2645964788056875452U) ^ aNonceWordC;
            aOrbiterE = RotL64((aOrbiterE * 8778681366114628045U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 2859452497983106129U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 7196557924940881076U;
            aOrbiterI = RotL64((aOrbiterI * 14415389907490256711U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 930127943984174668U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 15673596916054795749U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7505660488733199479U), 41U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 16673140529110941163U) + aOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 2258448294877833760U) ^ aNonceWordO;
            aOrbiterA = RotL64((aOrbiterA * 1821550319748977445U), 3U);
            //
            aIngress = RotL64(aOrbiterK, 5U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 54U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 21U));
            aIngress = aIngress + RotL64(aOrbiterI, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aScatter, 53U) + RotL64(aOrbiterA, 13U)) + aOrbiterK) + RotL64(aCarry, 13U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterI, 29U)) + aOrbiterA);
            aWandererD = aWandererD + (((((RotL64(aCross, 23U) + aOrbiterE) + RotL64(aOrbiterG, 5U)) + RotL64(aCarry, 53U)) + aNonceWordF) + aWandererUpdateSaltC[((aIndex + 6U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterH, 43U)) + aOrbiterE);
            aWandererE = aWandererE + (((RotL64(aScatter, 60U) + RotL64(aOrbiterH, 36U)) + aOrbiterK) + aNonceWordI);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterF, 19U)) + aOrbiterK);
            aWandererC = aWandererC + (((RotL64(aCross, 39U) + aOrbiterI) + RotL64(aOrbiterG, 53U)) + aWandererUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 47U) ^ aWandererD);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 58U));
            aCarry = aCarry + (RotL64(aWandererF, 41U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererE, 53U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aOperationLaneB
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aOperationLaneB forward/backward random
        // cross from: aExpandLaneB, aWorkLaneC, aFireLaneA
        // cross directions: aExpandLaneB backward forced, aWorkLaneC backward forced, aFireLaneA backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 29316U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneA[((aIndex + 29478U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 26198U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 26351U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 29135U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 29682U)) & S_BLOCK1], 56U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aIngress, 11U) ^ RotL64(aCarry, 35U)) + (RotL64(aPrevious, 56U) ^ RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterH = (aWandererJ + RotL64(aIngress, 6U)) + 16016931609704150191U;
            aOrbiterC = (((aWandererA + RotL64(aPrevious, 35U)) + RotL64(aCarry, 57U)) + 14511433515861302636U) + aNonceWordL;
            aOrbiterD = (aWandererD + RotL64(aScatter, 13U)) + 11691237442613269593U;
            aOrbiterB = ((((aWandererG + RotL64(aCross, 19U)) + RotL64(aCarry, 19U)) + 16383220587320484649U) + aOrbiterAssignSaltD[(((31U - aIndex) + 14U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterI = ((aWandererI + RotL64(aIngress, 57U)) + 14293015313458219868U) + aNonceWordF;
            aOrbiterJ = (((aWandererF + RotL64(aScatter, 47U)) + RotL64(aCarry, 41U)) + 4407695248205526670U) + aOrbiterAssignSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = ((aWandererC + RotL64(aPrevious, 41U)) + 1158323195324398372U) + aNonceWordP;
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 6577683409653864555U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 171080079472863843U) ^ aNonceWordM;
            aOrbiterD = RotL64((aOrbiterD * 3063978974927752653U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 5766333425872228205U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 16173508656917582960U;
            aOrbiterC = RotL64((aOrbiterC * 12187968015372936695U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 11781450063402219202U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 13033139686637576694U;
            aOrbiterB = RotL64((aOrbiterB * 4331137994135472025U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 4006310759400926020U) + aNonceWordA;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 13156817947481574467U;
            aOrbiterE = RotL64((aOrbiterE * 563189239835001483U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 12791290558893516411U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 989729955679243234U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 8757228712495095017U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 838379839663022790U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 2830743864262313606U) ^ aOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 10173947177104802797U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 2146646527331684652U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 4629168181742174906U;
            aOrbiterJ = RotL64((aOrbiterJ * 9046124907945045131U), 11U);
            //
            aIngress = RotL64(aOrbiterI, 50U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterH, 57U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterE, 3U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterD, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterC, 41U)) + aOrbiterH);
            aWandererC = aWandererC + (((RotL64(aIngress, 35U) + RotL64(aOrbiterC, 5U)) + aOrbiterE) + RotL64(aCarry, 3U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 4U) + RotL64(aOrbiterJ, 11U)) + aOrbiterI) + aNonceWordE);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 29U) + aOrbiterH) + RotL64(aOrbiterB, 18U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 53U) + RotL64(aOrbiterD, 29U)) + aOrbiterH) + aWandererUpdateSaltB[((aIndex + 25U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 21U) + aOrbiterE) + RotL64(aOrbiterI, 35U)) + RotL64(aCarry, 37U)) + aNonceWordO);
            aWandererA = aWandererA ^ ((((RotL64(aIngress, 47U) + aOrbiterH) + RotL64(aOrbiterI, 51U)) + aNonceWordI) + aWandererUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 41U));
            aCarry = aCarry + (RotL64(aWandererI, 60U) ^ aWandererJ);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 3U));
            aCarry = aCarry + RotL64(aWandererG, 47U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xE06EDB49AE53A1BBULL + 0xF4BBD15D968CF6E5ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xADD2BDE2D3FEFD9BULL + 0x8A6B392F396445B4ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x96D0A4204FFC24EDULL + 0x9664E7C3044737FEULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xC0AE759BE10C7C7BULL + 0xD6451A2C3C6B2661ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xA85A271CEC6BDC6BULL + 0xC51E16BADCBC510CULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xF4F23B290E6BCBEDULL + 0x9D37EC9A88DF69C4ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xB1559BE5B766714FULL + 0xDD20A558BD84644BULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xBF44AE96C5F16B81ULL + 0xCA905E831AFDC69CULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xC6748F7AD63350ABULL + 0xFFE59C9898756F57ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xA033EF787B442125ULL + 0x8354E53B13578648ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0x9BD0109CFAE46703ULL + 0xEE6FF310DDB3D20BULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xBD39E940F6F395B5ULL + 0xF187C1542D2437E3ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x8A84B612830944D1ULL + 0x8F3FFC86B7A989A1ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0x97852F689F74A207ULL + 0xDABFD342F9A6072DULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xCA4973737471124DULL + 0x806F70236527676DULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xFCFD34E0C380D907ULL + 0x9E001C894C7FB9B9ULL);
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
        // read from: aExpandLaneA, aExpandLaneB, aWorkLaneD, aExpandLaneC, aExpandLaneD, aWorkLaneA, aOperationLaneA, aWorkLaneB, aWorkLaneC, aOperationLaneB, aFireLaneA, aFireLaneC, aOperationLaneC, aFireLaneD, aFireLaneB
        // write to: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD
    
        // kdf_b_loop_b loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aWorkLaneD
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aWorkLaneD forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD, aWorkLaneA
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward forced, aWorkLaneA backward/forward random
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 8147U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneB[((aIndex + 5636U)) & S_BLOCK1], 26U));
            aIngress ^= RotL64(aWorkLaneD[((aIndex + 6071U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 1597U)) & S_BLOCK1], 46U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 7322U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 5832U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aIngress, 35U) ^ RotL64(aCross, 20U)) ^ (RotL64(aCarry, 5U) + RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterD = (aWandererH + RotL64(aScatter, 19U)) + 12615321415808640429U;
            aOrbiterG = ((aWandererK + RotL64(aCross, 53U)) + RotL64(aCarry, 57U)) + 15712784676459931207U;
            aOrbiterK = (aWandererD + RotL64(aPrevious, 34U)) + 11013335427004930046U;
            aOrbiterC = ((((aWandererA + RotL64(aIngress, 11U)) + RotL64(aCarry, 27U)) + 8298733856304768806U) + aOrbiterAssignSaltE[((aIndex + 8U)) & S_SALT1]) + aNonceWordO;
            aOrbiterF = (aWandererI + RotL64(aCross, 57U)) + 6207732959150824216U;
            aOrbiterH = (((aWandererB + RotL64(aScatter, 51U)) + RotL64(aCarry, 19U)) + 9769864876127544038U) + aNonceWordM;
            aOrbiterJ = (aWandererF + RotL64(aIngress, 47U)) + 10782181918651152563U;
            aOrbiterB = (aWandererC + RotL64(aPrevious, 3U)) + 5790454015845620939U;
            aOrbiterA = (aWandererG + RotL64(aScatter, 27U)) + 15606578025386733803U;
            aOrbiterI = ((aWandererE + RotL64(aIngress, 39U)) + 5522352539991175304U) + aOrbiterAssignSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterE = ((aWandererJ + RotL64(aCross, 14U)) + 5993355818572869649U) + aNonceWordA;
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 10864534396947622047U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 12090053126235913528U;
            aOrbiterK = RotL64((aOrbiterK * 7250801471645972261U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 14191181677234981396U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 2258570108233924592U) ^ aOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8307541155393855209U), 39U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 8448114811381534603U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 2702389315763499817U;
            aOrbiterJ = RotL64((aOrbiterJ * 6710443836432274393U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 17202184076718780200U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 150549910056015002U;
            aOrbiterA = RotL64((aOrbiterA * 195034681254956335U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 4910512055808124967U) + aNonceWordJ;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 4783477997418403079U;
            aOrbiterG = RotL64((aOrbiterG * 861977492146512865U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 13842899106208709771U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 7930112618036681468U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 8609551859830858419U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 8790107242863198659U) + aNonceWordF;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 6882768826643279144U;
            aOrbiterC = RotL64((aOrbiterC * 13745521454063360763U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 12136498871759890015U) + aNonceWordD;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 8120456314755584336U;
            aOrbiterE = RotL64((aOrbiterE * 1830725195528043575U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 14425711740351183016U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterE) ^ 15907406009196323049U) ^ aOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterH = RotL64((aOrbiterH * 8599371693260686839U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 4878521420367891861U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 1184672056055028939U;
            aOrbiterF = RotL64((aOrbiterF * 5963961755367831967U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 10126736568567000180U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 12615321415808640429U;
            aOrbiterB = RotL64((aOrbiterB * 11663715449073755137U), 57U);
            //
            aIngress = RotL64(aOrbiterA, 5U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 50U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 27U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 21U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 43U));
            aIngress = aIngress + RotL64(aOrbiterI, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aCross, 43U) + aOrbiterI) + RotL64(aOrbiterG, 46U)) + aWandererUpdateSaltE[((aIndex + 29U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 39U) + aOrbiterB) + RotL64(aOrbiterE, 11U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 37U) + aOrbiterA) + RotL64(aOrbiterI, 37U)) + aNonceWordB);
            aWandererE = aWandererE + ((((RotL64(aScatter, 19U) + aOrbiterB) + RotL64(aOrbiterJ, 39U)) + RotL64(aCarry, 29U)) + aNonceWordG);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 57U) + aOrbiterF) + RotL64(aOrbiterC, 43U));
            aWandererI = aWandererI + (((RotL64(aCross, 48U) + RotL64(aOrbiterI, 5U)) + aOrbiterB) + RotL64(aCarry, 53U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 27U) + RotL64(aOrbiterH, 34U)) + aOrbiterF) + aNonceWordH);
            aWandererF = aWandererF + ((RotL64(aScatter, 29U) + RotL64(aOrbiterK, 29U)) + aOrbiterC);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 23U) + aOrbiterK) + RotL64(aOrbiterA, 51U)) + aWandererUpdateSaltF[((aIndex + 25U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aScatter, 13U) + aOrbiterK) + RotL64(aOrbiterE, 3U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 46U) + RotL64(aOrbiterJ, 27U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 35U));
            aCarry = aCarry + (RotL64(aWandererD, 44U) ^ aWandererA);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 13U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 39U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 57U));
            aCarry = aCarry + RotL64(aWandererC, 26U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 2
        // ingress from: aOperationLaneA, aExpandLaneC, aWorkLaneB
        // ingress directions: aOperationLaneA forward forced, aExpandLaneC forward forced, aWorkLaneB forward/backward random
        // cross from: aExpandLaneA, aExpandLaneD, aWorkLaneC
        // cross directions: aExpandLaneA backward forced, aExpandLaneD backward forced, aWorkLaneC backward/forward random
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 15211U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneC[((aIndex + 10620U)) & S_BLOCK1], 44U));
            aIngress ^= RotL64(aWorkLaneB[((aIndex + 8991U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 14595U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 12896U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aWorkLaneC[((aIndex + 13122U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCross, 36U) ^ RotL64(aIngress, 53U)) ^ (RotL64(aPrevious, 5U) + RotL64(aCarry, 21U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterI = (aWandererB + RotL64(aCross, 11U)) + 5160910997561396461U;
            aOrbiterA = ((aWandererF + RotL64(aScatter, 24U)) + 14920764751058512062U) + aOrbiterAssignSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = (aWandererA + RotL64(aPrevious, 13U)) + 6080952401749660022U;
            aOrbiterD = ((aWandererK + RotL64(aIngress, 51U)) + 17667234330526298627U) + aNonceWordE;
            aOrbiterG = (((aWandererI + RotL64(aCross, 41U)) + 760630072638686756U) + aOrbiterAssignSaltF[((aIndex + 6U)) & S_SALT1]) + aNonceWordD;
            aOrbiterE = ((aWandererE + RotL64(aIngress, 27U)) + RotL64(aCarry, 21U)) + 3504157162816997476U;
            aOrbiterB = ((aWandererG + RotL64(aPrevious, 43U)) + RotL64(aCarry, 11U)) + 9489022223422585882U;
            aOrbiterC = (aWandererC + RotL64(aScatter, 19U)) + 1149898536879968964U;
            aOrbiterJ = (aWandererJ + RotL64(aCross, 57U)) + 10492284328940025310U;
            aOrbiterH = ((aWandererH + RotL64(aIngress, 30U)) + 13213275606286399312U) + aNonceWordJ;
            aOrbiterK = ((aWandererD + RotL64(aScatter, 5U)) + RotL64(aCarry, 43U)) + 10557118912847180413U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 15618980209023994776U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 5268600749854045564U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3849660559223919613U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 8011552687609649990U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 3148133096349525066U;
            aOrbiterA = RotL64((aOrbiterA * 5245156554959620007U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 12032847944237867285U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 14999005703490824673U;
            aOrbiterG = RotL64((aOrbiterG * 6631584955208646049U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 5426735969392906710U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 3593177531650386729U;
            aOrbiterJ = RotL64((aOrbiterJ * 12997284886192717043U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 1701444719333347373U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 15928731228196894960U) ^ aNonceWordP;
            aOrbiterB = RotL64((aOrbiterB * 1919318226904213433U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 5960179456039157036U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 5716434224061596483U;
            aOrbiterI = RotL64((aOrbiterI * 3731976564761202801U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 2136841536293340279U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 12969550408652728526U;
            aOrbiterE = RotL64((aOrbiterE * 7612191387451455137U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 3641997570461447114U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterG) ^ 4677572491523684525U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterH = RotL64((aOrbiterH * 2730358077882211651U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 2741372094325164504U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 4998631511811832690U) ^ aNonceWordO;
            aOrbiterK = RotL64((aOrbiterK * 10619395395977372695U), 23U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 6260464862798783617U) + aOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 16489087874167346533U;
            aOrbiterC = RotL64((aOrbiterC * 11278053967185244867U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 7043760915859224327U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 5160910997561396461U) ^ aNonceWordI;
            aOrbiterD = RotL64((aOrbiterD * 15260149870590431675U), 27U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterF, 35U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 51U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 14U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterD, 19U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 53U));
            aIngress = aIngress + RotL64(aOrbiterI, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((((RotL64(aPrevious, 13U) + RotL64(aOrbiterB, 29U)) + aOrbiterF) + aNonceWordH) + aWandererUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 19U) + RotL64(aOrbiterF, 43U)) + aOrbiterK) + RotL64(aCarry, 27U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterE, 41U)) + aOrbiterA);
            aWandererD = aWandererD + ((RotL64(aIngress, 39U) + RotL64(aOrbiterD, 27U)) + aOrbiterA);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterH, 3U)) + aOrbiterC);
            aWandererH = aWandererH + ((RotL64(aIngress, 50U) + aOrbiterJ) + RotL64(aOrbiterF, 47U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterC, 56U)) + aOrbiterD) + aNonceWordA);
            aWandererK = aWandererK + ((RotL64(aCross, 53U) + RotL64(aOrbiterI, 53U)) + aOrbiterA);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 37U) + RotL64(aOrbiterJ, 37U)) + aOrbiterH) + aWandererUpdateSaltC[((aIndex + 13U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aCross, 11U) + aOrbiterJ) + RotL64(aOrbiterI, 19U)) + RotL64(aCarry, 5U)) + aNonceWordB);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 6U) + aOrbiterG) + RotL64(aOrbiterE, 10U)) + aNonceWordG);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 46U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 13U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 23U));
            aCarry = aCarry + (RotL64(aWandererG, 53U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererA, 26U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererH, 41U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aOperationLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 3
        // ingress from: aOperationLaneB, aExpandLaneD, aFireLaneA
        // ingress directions: aOperationLaneB forward forced, aExpandLaneD forward forced, aFireLaneA forward/backward random
        // cross from: aOperationLaneA, aExpandLaneB, aFireLaneC
        // cross directions: aOperationLaneA backward forced, aExpandLaneB backward forced, aFireLaneC backward/forward random
        // write to: aOperationLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneB[((aIndex + 17496U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneD[((aIndex + 20884U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 18132U)) & S_BLOCK1], 4U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 17909U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 22969U)) & S_BLOCK1], 41U));
            aCross ^= RotL64(aFireLaneC[((aIndex + 23500U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCarry, 27U) ^ RotL64(aIngress, 5U)) + (RotL64(aPrevious, 56U) + RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterG = ((aWandererB + RotL64(aCross, 43U)) + RotL64(aCarry, 29U)) + 2786079456995203065U;
            aOrbiterI = (((aWandererE + RotL64(aScatter, 13U)) + RotL64(aCarry, 3U)) + 7237256119153857253U) + aNonceWordC;
            aOrbiterB = (aWandererA + RotL64(aPrevious, 27U)) + 9310834010563647604U;
            aOrbiterC = ((aWandererH + RotL64(aIngress, 37U)) + 17361734905706517877U) + aNonceWordO;
            aOrbiterK = ((aWandererG + RotL64(aCross, 6U)) + 15837111231884647451U) + aOrbiterAssignSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = ((aWandererI + RotL64(aIngress, 3U)) + 18065431964418026445U) + aOrbiterAssignSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterE = (aWandererJ + RotL64(aScatter, 39U)) + 3029123922999952652U;
            aOrbiterJ = (aWandererD + RotL64(aPrevious, 23U)) + 5166926595573507837U;
            aOrbiterH = ((aWandererC + RotL64(aIngress, 19U)) + RotL64(aCarry, 23U)) + 1918425684273807598U;
            aOrbiterA = (aWandererK + RotL64(aCross, 29U)) + 4724551751012661440U;
            aOrbiterD = (aWandererF + RotL64(aScatter, 46U)) + 1818014487579644390U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 6670090372241084216U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 8485757110007268693U;
            aOrbiterB = RotL64((aOrbiterB * 11876760095108618363U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 4928130251509514742U) + aNonceWordP;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 2528788422725346792U) ^ aNonceWordM;
            aOrbiterK = RotL64((aOrbiterK * 1855982047967756661U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 2860387120895147503U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 12927802338151379368U) ^ aNonceWordG;
            aOrbiterE = RotL64((aOrbiterE * 8876144125458603029U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 18029699867733207083U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 13361836994951253312U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5349767426256597073U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 11957294454794128079U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 3755417922063414648U;
            aOrbiterC = RotL64((aOrbiterC * 13896364063651241401U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 18001157153447913032U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 16214145724690286854U) ^ aOrbiterUpdateSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 5874139687703360515U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 3860958772090975562U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 12395621524459640173U;
            aOrbiterJ = RotL64((aOrbiterJ * 722817135977510161U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 3402035664910754484U) + aNonceWordF;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 2139099117325745602U;
            aOrbiterA = RotL64((aOrbiterA * 14008983756425796029U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 7769274487425053026U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 6492669707749367728U) ^ aOrbiterUpdateSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 5149771861620757839U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 14963366447884375043U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 11398874662567519691U;
            aOrbiterD = RotL64((aOrbiterD * 8221521452475029835U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 7168445485232814860U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 2786079456995203065U;
            aOrbiterI = RotL64((aOrbiterI * 14258367164534307955U), 57U);
            //
            aIngress = RotL64(aOrbiterF, 56U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 3U));
            aIngress = aIngress + (RotL64(aOrbiterI, 39U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterJ, 43U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 47U));
            aIngress = aIngress + RotL64(aOrbiterH, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aScatter, 21U) + RotL64(aOrbiterI, 19U)) + aOrbiterD) + RotL64(aCarry, 51U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 27U) + aOrbiterF) + RotL64(aOrbiterC, 37U));
            aWandererG = aWandererG + ((((RotL64(aCross, 29U) + aOrbiterB) + RotL64(aOrbiterA, 57U)) + aNonceWordL) + aWandererUpdateSaltA[((aIndex + 19U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 19U) + RotL64(aOrbiterK, 10U)) + aOrbiterJ) + aNonceWordE);
            aWandererH = aWandererH + (((RotL64(aIngress, 41U) + aOrbiterH) + RotL64(aOrbiterI, 43U)) + aNonceWordD);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 36U) + RotL64(aOrbiterE, 27U)) + aOrbiterC);
            aWandererK = aWandererK + ((((RotL64(aScatter, 47U) + RotL64(aOrbiterA, 21U)) + aOrbiterD) + aNonceWordK) + aWandererUpdateSaltB[((aIndex + 15U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterK, 54U)) + aOrbiterE);
            aWandererA = aWandererA + ((RotL64(aIngress, 43U) + aOrbiterF) + RotL64(aOrbiterI, 47U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 39U) + aOrbiterC) + RotL64(aOrbiterB, 51U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 24U) + RotL64(aOrbiterD, 41U)) + aOrbiterG) + RotL64(aCarry, 39U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 29U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererB, 44U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererK, 11U) ^ aWandererF);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 41U));
            aCarry = aCarry + (RotL64(aWandererI, 35U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererA, 3U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aOperationLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 4
        // ingress from: aOperationLaneC, aOperationLaneA, aFireLaneD
        // ingress directions: aOperationLaneC forward forced, aOperationLaneA forward forced, aFireLaneD forward/backward random
        // cross from: aOperationLaneB, aExpandLaneC, aFireLaneB
        // cross directions: aOperationLaneB backward forced, aExpandLaneC backward forced, aFireLaneB backward/forward random
        // write to: aOperationLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneC[((aIndex + 28012U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneA[((aIndex + 28069U)) & S_BLOCK1], 54U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 31045U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31778U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 25321U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 32454U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aPrevious, 11U) + RotL64(aCarry, 47U)) + (RotL64(aIngress, 35U) ^ RotL64(aCross, 60U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterK = (aWandererB + RotL64(aScatter, 28U)) + 16922357079016918108U;
            aOrbiterG = ((aWandererG + RotL64(aIngress, 47U)) + 11771749797137599131U) + aNonceWordO;
            aOrbiterI = (aWandererA + RotL64(aPrevious, 39U)) + 4635668433708036077U;
            aOrbiterD = (aWandererI + RotL64(aCross, 37U)) + 15827952719230577008U;
            aOrbiterB = (aWandererK + RotL64(aScatter, 53U)) + 1495675306110023086U;
            aOrbiterH = ((aWandererD + RotL64(aIngress, 41U)) + RotL64(aCarry, 5U)) + 7294835466949728365U;
            aOrbiterA = ((aWandererJ + RotL64(aCross, 57U)) + RotL64(aCarry, 11U)) + 179122461212041978U;
            aOrbiterJ = ((aWandererC + RotL64(aPrevious, 35U)) + RotL64(aCarry, 23U)) + 545981421632236251U;
            aOrbiterC = (((aWandererF + RotL64(aIngress, 11U)) + 15338259639814630535U) + aOrbiterAssignSaltC[((aIndex + 24U)) & S_SALT1]) + aNonceWordM;
            aOrbiterE = ((aWandererH + RotL64(aCross, 44U)) + 12924313840290895215U) + aOrbiterAssignSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterF = ((aWandererE + RotL64(aPrevious, 51U)) + 17846785921286020610U) + aNonceWordE;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 5721472794107057875U) + aNonceWordL;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 16359630793856870319U;
            aOrbiterI = RotL64((aOrbiterI * 14186771515526698907U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 10614102110239037308U) + aOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 16421992251278236531U;
            aOrbiterB = RotL64((aOrbiterB * 2561232904676068089U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 8668149834861244963U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 12699331834360948734U;
            aOrbiterA = RotL64((aOrbiterA * 2249360824172616357U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 4470693178142950471U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 526000656022724741U;
            aOrbiterK = RotL64((aOrbiterK * 16688501462334673493U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 6880246132270094141U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 7126466778855297013U) ^ aNonceWordB;
            aOrbiterJ = RotL64((aOrbiterJ * 5692237926830293205U), 27U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterE) + 6436404501390442054U) + aOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1]) + aNonceWordG;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 1213633065612242699U;
            aOrbiterD = RotL64((aOrbiterD * 17604454985534439259U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 8186529105901185854U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 10607460957358250935U;
            aOrbiterH = RotL64((aOrbiterH * 17172191011625677861U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 9743278964993305169U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 14007577681873418075U;
            aOrbiterE = RotL64((aOrbiterE * 4231122580398039133U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 11636165671710638530U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 9334375905020670988U;
            aOrbiterC = RotL64((aOrbiterC * 8801600439900803907U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 4261340110915336428U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 12336921031446129288U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2306768964600968743U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 2029125959974424325U) + aOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 16922357079016918108U;
            aOrbiterG = RotL64((aOrbiterG * 8718484611517064455U), 53U);
            //
            aIngress = RotL64(aOrbiterH, 60U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterD, 41U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 43U));
            aIngress = aIngress + (RotL64(aOrbiterA, 13U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterB, 27U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterJ, 50U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 13U) + aOrbiterF) + RotL64(aOrbiterA, 43U));
            aWandererB = aWandererB + (((RotL64(aIngress, 37U) + RotL64(aOrbiterH, 53U)) + aOrbiterE) + aWandererUpdateSaltE[((aIndex + 21U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 26U) + aOrbiterA) + RotL64(aOrbiterE, 3U)) + aNonceWordD);
            aWandererE = aWandererE + (((RotL64(aCross, 19U) + RotL64(aOrbiterI, 6U)) + aOrbiterB) + aNonceWordI);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 47U) + aOrbiterJ) + RotL64(aOrbiterC, 29U));
            aWandererK = aWandererK + (((RotL64(aCross, 35U) + aOrbiterD) + RotL64(aOrbiterI, 11U)) + RotL64(aCarry, 21U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterI, 47U)) + aOrbiterE);
            aWandererH = aWandererH + (((((RotL64(aPrevious, 51U) + RotL64(aOrbiterG, 41U)) + aOrbiterH) + RotL64(aCarry, 37U)) + aNonceWordA) + aWandererUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 57U) + aOrbiterI) + RotL64(aOrbiterK, 23U));
            aWandererD = aWandererD + ((RotL64(aPrevious, 6U) + RotL64(aOrbiterD, 39U)) + aOrbiterC);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 39U) + RotL64(aOrbiterF, 18U)) + aOrbiterC) + aNonceWordK);
            //
            aCarry = aCarry + (RotL64(aWandererC, 50U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererJ, 3U) ^ aWandererI);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 39U));
            aCarry = aCarry + (RotL64(aWandererA, 29U) ^ aWandererB);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 26U));
            aCarry = aCarry + RotL64(aWandererF, 23U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xBF8851241E0CA603ULL + 0x9D604C0CEAB34D43ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xC52EDFC725AA1BAFULL + 0xF3D7A38ADBC23593ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xE6CFF2A320A0EB6DULL + 0xAE0F4564AC4B1FA1ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xAA4EC08342262DF9ULL + 0xC5C54A1F57CC6F19ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x842DDF377630820BULL + 0xAB701ED935621571ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xF2898E588E2C124DULL + 0xE92CD9B5234CD0FBULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xCBA24D73B53CD8A5ULL + 0xFAE63AE9A35E5A1EULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x8F125ED5700B91EDULL + 0xF267B535AF80DFFFULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xF79D5D0F7D9A8AC7ULL + 0x888C7E97CAD7DD73ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xE816A55DB9A873D9ULL + 0xF8932556A966FD26ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xA6486770762501CBULL + 0xC5AC18C05064596BULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xD8143CDDF9F63467ULL + 0x8C8171DCBA0A8A28ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xB488931790163CABULL + 0x945BC98A57AA8210ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xEA249E4B8EC1B017ULL + 0xA41AF6036374691BULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xAAE7570F4D06C8EBULL + 0xB561AA7EDEFD84A9ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xD8414D5A4E90C4B5ULL + 0xD1E5D31727B0BD00ULL);
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
        // read from: aOperationLaneA, aOperationLaneB, aWorkLaneB, aOperationLaneC, aOperationLaneD, aFireLaneC, aExpandLaneA, aWorkLaneA, aWorkLaneC, aExpandLaneB, aFireLaneA, aFireLaneB, aExpandLaneC, aFireLaneD, aWorkLaneD
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_c loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aWorkLaneB
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aWorkLaneB forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aFireLaneC
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aFireLaneC backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 2021U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneB[((aIndex + 8081U)) & S_BLOCK1], 28U));
            aIngress ^= RotL64(aWorkLaneB[((aIndex + 8054U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 896U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 448U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 3754U)) & S_BLOCK1], 12U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aIngress, 27U) + RotL64(aCross, 10U)) ^ (RotL64(aPrevious, 57U) + RotL64(aCarry, 43U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterC = (aWandererI + RotL64(aPrevious, 42U)) + 4751694786009671052U;
            aOrbiterA = (aWandererA + RotL64(aScatter, 19U)) + 16362725160370844224U;
            aOrbiterI = (((aWandererF + RotL64(aIngress, 23U)) + RotL64(aCarry, 27U)) + 6360885380915941057U) + aNonceWordL;
            aOrbiterH = ((aWandererC + RotL64(aCross, 11U)) + RotL64(aCarry, 13U)) + 5154536007972297036U;
            aOrbiterF = (aWandererE + RotL64(aPrevious, 27U)) + 9362540581874808253U;
            aOrbiterG = ((aWandererD + RotL64(aCross, 52U)) + 13902493871525612934U) + aNonceWordD;
            aOrbiterD = (((aWandererH + RotL64(aScatter, 47U)) + 10208452885367546542U) + aOrbiterAssignSaltA[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordA;
            aOrbiterK = ((aWandererK + RotL64(aIngress, 37U)) + 3117030377279160998U) + aNonceWordN;
            aOrbiterB = (((aWandererB + RotL64(aScatter, 3U)) + RotL64(aCarry, 39U)) + 17286247690414027870U) + aOrbiterAssignSaltB[((aIndex + 7U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 3930314320040949141U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 7289525252391668404U;
            aOrbiterI = RotL64((aOrbiterI * 15452162299105112187U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 3434167955466809185U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 17852573095128575663U;
            aOrbiterC = RotL64((aOrbiterC * 1485660158767033425U), 53U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 6137259687928853253U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 13992510605237574698U;
            aOrbiterD = RotL64((aOrbiterD * 15346263295995333395U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 6470556523400123474U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 4333255670390099293U;
            aOrbiterG = RotL64((aOrbiterG * 11089933812030082647U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 7700424876430257995U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 16920736951239453071U;
            aOrbiterK = RotL64((aOrbiterK * 8920407493132380497U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 1635071690430295730U) + aOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 9966700845966398620U;
            aOrbiterF = RotL64((aOrbiterF * 17210048121896546867U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 9833458070123027075U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterK) ^ 1990346556486746432U) ^ aOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterH = RotL64((aOrbiterH * 8704943923474148699U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 13339523466436517327U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 5018264760406215603U;
            aOrbiterA = RotL64((aOrbiterA * 2769197961801783627U), 35U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterC) + 123427497520755346U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordI;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 4535841104215792886U;
            aOrbiterB = RotL64((aOrbiterB * 1417676310539177131U), 43U);
            //
            aIngress = RotL64(aOrbiterI, 11U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 39U));
            aIngress = aIngress + (RotL64(aOrbiterD, 23U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterK, 48U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterB, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterA, 18U)) + aOrbiterD);
            aWandererA = aWandererA + ((((RotL64(aIngress, 4U) + RotL64(aOrbiterC, 39U)) + aOrbiterG) + RotL64(aCarry, 47U)) + aNonceWordP);
            aWandererH = aWandererH ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterH, 3U)) + aOrbiterC) + aWandererUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aPrevious, 35U) + RotL64(aOrbiterG, 23U)) + aOrbiterF);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterD, 29U)) + aOrbiterC);
            aWandererE = aWandererE + (((RotL64(aCross, 39U) + RotL64(aOrbiterI, 10U)) + aOrbiterK) + RotL64(aCarry, 21U));
            aWandererF = aWandererF ^ ((((RotL64(aPrevious, 21U) + aOrbiterC) + RotL64(aOrbiterI, 43U)) + aNonceWordE) + aWandererUpdateSaltF[((aIndex + 25U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aIngress, 52U) + aOrbiterG) + RotL64(aOrbiterB, 35U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterD, 53U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 14U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 57U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 23U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 3U));
            aCarry = aCarry + RotL64(aWandererB, 47U);
            aCarry = aCarry + RotL64(aIngress, 20U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 2
        // ingress from: aExpandLaneA, aOperationLaneC, aWorkLaneA
        // ingress directions: aExpandLaneA forward forced, aOperationLaneC forward forced, aWorkLaneA forward/backward random
        // cross from: aOperationLaneA, aOperationLaneD, aWorkLaneC
        // cross directions: aOperationLaneA backward forced, aOperationLaneD backward forced, aWorkLaneC backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 14268U)) & S_BLOCK1], 12U) ^ RotL64(aOperationLaneC[((aIndex + 12147U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aWorkLaneA[((aIndex + 9031U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 11417U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 13408U)) & S_BLOCK1], 41U));
            aCross ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 15623U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCross, 57U) ^ RotL64(aIngress, 19U)) ^ (RotL64(aCarry, 5U) + RotL64(aPrevious, 42U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterA = (aWandererF + RotL64(aScatter, 35U)) + 17912271996338180948U;
            aOrbiterK = (((aWandererA + RotL64(aPrevious, 6U)) + RotL64(aCarry, 35U)) + 13259276608841847058U) + aNonceWordE;
            aOrbiterE = (aWandererJ + RotL64(aIngress, 39U)) + 16225936008657276089U;
            aOrbiterH = (aWandererE + RotL64(aCross, 13U)) + 2243058962151834071U;
            aOrbiterD = (((aWandererC + RotL64(aIngress, 23U)) + RotL64(aCarry, 51U)) + 10637439274127347861U) + aOrbiterAssignSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterC = (aWandererG + RotL64(aCross, 18U)) + 15312219216405992627U;
            aOrbiterB = (((aWandererI + RotL64(aScatter, 43U)) + RotL64(aCarry, 11U)) + 2393933972129878613U) + aNonceWordB;
            aOrbiterG = (aWandererH + RotL64(aPrevious, 47U)) + 4327069337247976513U;
            aOrbiterJ = ((aWandererB + RotL64(aCross, 53U)) + 8307656353434167837U) + aOrbiterAssignSaltC[((aIndex + 10U)) & S_SALT1];
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 17299145556933889336U) + aOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 14458100581172798164U;
            aOrbiterE = RotL64((aOrbiterE * 16543734663677070509U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 6410095654927998067U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 6168964796264687686U;
            aOrbiterK = RotL64((aOrbiterK * 16218071040190475953U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 3667999465041020730U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 16021552859323602007U;
            aOrbiterA = RotL64((aOrbiterA * 6427266472526362663U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 12941668202330045095U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 4222032891850449934U) ^ aOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 17292856787431308097U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 1346342592002730785U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterK) ^ 16860611785008118820U) ^ aOrbiterUpdateSaltF[((aIndex + 26U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterJ = RotL64((aOrbiterJ * 384963420804756607U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 3193572711804730241U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 5866881282680588589U;
            aOrbiterD = RotL64((aOrbiterD * 9226331800853634597U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 17180332731328479126U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 10222097519535882241U) ^ aNonceWordO;
            aOrbiterB = RotL64((aOrbiterB * 9422887302872778795U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 8863502179821584859U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 14872318155712512999U;
            aOrbiterH = RotL64((aOrbiterH * 11830641277356873233U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 16478790641892781150U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 8414944141232294781U;
            aOrbiterC = RotL64((aOrbiterC * 17443775794621154023U), 53U);
            //
            aIngress = RotL64(aOrbiterD, 13U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterH, 5U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterE, 30U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 41U));
            aIngress = aIngress + RotL64(aOrbiterJ, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aCross, 12U) + aOrbiterA) + RotL64(aOrbiterC, 43U)) + RotL64(aCarry, 27U));
            aWandererH = aWandererH ^ ((((RotL64(aPrevious, 51U) + RotL64(aOrbiterK, 39U)) + aOrbiterA) + aNonceWordF) + aWandererUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aScatter, 5U) + aOrbiterC) + RotL64(aOrbiterJ, 30U)) + RotL64(aCarry, 19U)) + aWandererUpdateSaltA[((aIndex + 21U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 37U) + RotL64(aOrbiterG, 3U)) + aOrbiterH) + aNonceWordN);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 23U) + aOrbiterB) + RotL64(aOrbiterE, 35U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterK, 51U)) + aOrbiterB);
            aWandererI = aWandererI + ((RotL64(aScatter, 28U) + aOrbiterE) + RotL64(aOrbiterJ, 13U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterH, 26U)) + aOrbiterK);
            aWandererA = aWandererA + ((RotL64(aCross, 57U) + RotL64(aOrbiterA, 47U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 14U) ^ aWandererA);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + (RotL64(aWandererG, 39U) ^ aWandererH);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 35U));
            aCarry = aCarry + RotL64(aWandererI, 21U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 3
        // ingress from: aExpandLaneB, aOperationLaneD, aFireLaneA
        // ingress directions: aExpandLaneB forward forced, aOperationLaneD forward forced, aFireLaneA forward/backward random
        // cross from: aExpandLaneA, aOperationLaneB, aFireLaneB
        // cross directions: aExpandLaneA backward forced, aOperationLaneB backward forced, aFireLaneB backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 16897U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneD[((aIndex + 20328U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 18541U)) & S_BLOCK1], 56U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 17014U)) & S_BLOCK1], 56U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 18780U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 21759U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCross, 50U)) ^ (RotL64(aCarry, 19U) ^ RotL64(aIngress, 37U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterK = ((((aWandererA + RotL64(aScatter, 23U)) + RotL64(aCarry, 41U)) + 5041131702736607991U) + aOrbiterAssignSaltF[((aIndex + 29U)) & S_SALT1]) + aNonceWordM;
            aOrbiterD = ((aWandererF + RotL64(aCross, 44U)) + 9295010428212681446U) + aOrbiterAssignSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterH = ((aWandererC + RotL64(aIngress, 53U)) + 6235875895358766017U) + aNonceWordK;
            aOrbiterG = (aWandererJ + RotL64(aPrevious, 57U)) + 2622227802531866918U;
            aOrbiterC = ((aWandererI + RotL64(aIngress, 39U)) + RotL64(aCarry, 5U)) + 3888894734834524972U;
            aOrbiterE = ((aWandererH + RotL64(aScatter, 5U)) + 241682012014701753U) + aNonceWordJ;
            aOrbiterB = (aWandererB + RotL64(aPrevious, 11U)) + 15758000422451568079U;
            aOrbiterA = ((aWandererK + RotL64(aCross, 48U)) + RotL64(aCarry, 13U)) + 2061944548396976912U;
            aOrbiterI = ((aWandererD + RotL64(aIngress, 35U)) + 8177144990755754531U) + aNonceWordD;
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 554978075608818497U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 250408260560714933U) ^ aNonceWordP;
            aOrbiterH = RotL64((aOrbiterH * 1295379390497107727U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 8700027645880997552U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 10026130047465480902U;
            aOrbiterD = RotL64((aOrbiterD * 12417270861933696623U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 9785843014096326696U) + aNonceWordG;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 9998582683258411251U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7197956237569462269U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 13817734599383455151U) + aOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 6647207154174092691U;
            aOrbiterA = RotL64((aOrbiterA * 1578528131687283531U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 4957715980509035719U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 4994885315786213197U;
            aOrbiterB = RotL64((aOrbiterB * 5676683798126497011U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 5072908311783966503U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 5535039946192891515U;
            aOrbiterE = RotL64((aOrbiterE * 2989412783482309753U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 6594577050344146271U) + aOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 8750154123258714856U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 6942158167127532003U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 3514769314840874873U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 8626045200273524281U;
            aOrbiterI = RotL64((aOrbiterI * 4315441782689789689U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 8524870284841706517U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 1841819423572964209U;
            aOrbiterG = RotL64((aOrbiterG * 9802481758007234681U), 57U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterK, 37U);
            aIngress = aIngress + (RotL64(aOrbiterB, 46U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 11U));
            aIngress = aIngress + (RotL64(aOrbiterD, 5U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterC, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aScatter, 53U) + aOrbiterE) + RotL64(aOrbiterB, 47U)) + aNonceWordH);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 5U) + aOrbiterB) + RotL64(aOrbiterA, 34U));
            aWandererK = aWandererK + ((RotL64(aPrevious, 60U) + aOrbiterE) + RotL64(aOrbiterK, 5U));
            aWandererB = aWandererB ^ ((((RotL64(aCross, 19U) + RotL64(aOrbiterH, 57U)) + aOrbiterC) + aNonceWordB) + aWandererUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 29U) + aOrbiterI) + RotL64(aOrbiterG, 19U)) + RotL64(aCarry, 23U)) + aWandererUpdateSaltD[((aIndex + 14U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 35U) + aOrbiterH) + RotL64(aOrbiterI, 53U));
            aWandererA = aWandererA + (((RotL64(aIngress, 43U) + RotL64(aOrbiterB, 14U)) + aOrbiterI) + RotL64(aCarry, 35U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 10U) + aOrbiterG) + RotL64(aOrbiterE, 39U));
            aWandererD = aWandererD + (((RotL64(aScatter, 47U) + aOrbiterD) + RotL64(aOrbiterG, 29U)) + aNonceWordA);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 27U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 39U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 23U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 6U));
            aCarry = aCarry + RotL64(aWandererB, 53U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aFireLaneD
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aFireLaneD forward/backward random
        // cross from: aExpandLaneB, aOperationLaneC, aWorkLaneD
        // cross directions: aExpandLaneB backward forced, aOperationLaneC backward forced, aWorkLaneD backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 25313U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneA[((aIndex + 27761U)) & S_BLOCK1], 12U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 29111U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29556U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 29441U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 25829U)) & S_BLOCK1], 14U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCarry, 37U) + RotL64(aPrevious, 50U)) + (RotL64(aCross, 21U) ^ RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterA = (aWandererK + RotL64(aScatter, 38U)) + 4752759164691497960U;
            aOrbiterB = ((aWandererE + RotL64(aCross, 5U)) + RotL64(aCarry, 43U)) + 12088872623537639782U;
            aOrbiterD = ((aWandererF + RotL64(aPrevious, 47U)) + 3734943577379734227U) + aNonceWordN;
            aOrbiterF = ((aWandererH + RotL64(aIngress, 29U)) + 8854778183012444234U) + aOrbiterAssignSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterE = ((aWandererB + RotL64(aPrevious, 53U)) + RotL64(aCarry, 35U)) + 16948373492893967275U;
            aOrbiterG = (((aWandererJ + RotL64(aScatter, 57U)) + RotL64(aCarry, 57U)) + 7962415690046184385U) + aOrbiterAssignSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = ((aWandererC + RotL64(aCross, 42U)) + 1872682375669714454U) + aNonceWordD;
            aOrbiterK = ((aWandererI + RotL64(aIngress, 11U)) + 7776801806943853566U) + aNonceWordE;
            aOrbiterC = ((aWandererG + RotL64(aScatter, 19U)) + 16665439117257230732U) + aNonceWordH;
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 11088186766134265676U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 10850237991780969350U;
            aOrbiterD = RotL64((aOrbiterD * 7547414856143095121U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 6464817712131305812U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 244557182884209844U) ^ aNonceWordI;
            aOrbiterG = RotL64((aOrbiterG * 2394270354887582889U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 13261563971157415841U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 2323811103717827362U;
            aOrbiterK = RotL64((aOrbiterK * 11483723582415081925U), 37U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 12338803568475493422U) + aOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 2811342930111104982U;
            aOrbiterC = RotL64((aOrbiterC * 5020981755203607757U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 5554497011738996057U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 12712169745460598698U;
            aOrbiterF = RotL64((aOrbiterF * 1985586486150377769U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 17415058661427002973U) + aNonceWordG;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 9430421222715343818U;
            aOrbiterI = RotL64((aOrbiterI * 10321140659099470811U), 53U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 3926618548181233180U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 6172453297026957838U;
            aOrbiterB = RotL64((aOrbiterB * 1161551082037835233U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 8633288765997226004U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 17270881130844274342U;
            aOrbiterE = RotL64((aOrbiterE * 8888559940161770791U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 12232950994807835262U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 15352600312956742750U;
            aOrbiterA = RotL64((aOrbiterA * 6140396356904933003U), 3U);
            //
            aIngress = RotL64(aOrbiterC, 56U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 53U));
            aIngress = aIngress + (RotL64(aOrbiterF, 27U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 39U));
            aIngress = aIngress + RotL64(aOrbiterE, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterI, 19U)) + aOrbiterG);
            aWandererC = aWandererC + ((((RotL64(aIngress, 41U) + RotL64(aOrbiterD, 60U)) + aOrbiterA) + RotL64(aCarry, 21U)) + aWandererUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 60U) + RotL64(aOrbiterC, 23U)) + aOrbiterE);
            aWandererK = aWandererK + (((RotL64(aCross, 11U) + RotL64(aOrbiterD, 29U)) + aOrbiterK) + aNonceWordA);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 23U) + aOrbiterF) + RotL64(aOrbiterC, 47U));
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 19U) + aOrbiterI) + RotL64(aOrbiterB, 4U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterE, 53U)) + aOrbiterF);
            aWandererE = aWandererE + ((((RotL64(aCross, 37U) + RotL64(aOrbiterA, 35U)) + aOrbiterG) + RotL64(aCarry, 29U)) + aWandererUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 48U) + RotL64(aOrbiterI, 11U)) + aOrbiterK) + aNonceWordJ);
            //
            aCarry = aCarry + (RotL64(aWandererG, 43U) ^ aWandererF);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 35U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 39U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 13U));
            aCarry = aCarry + RotL64(aWandererE, 20U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xA12FD63C79CC774BULL + 0x9DCD35026F7BBB3BULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xB6E64B5F5678D02DULL + 0xAA099CF758C7F160ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x8F41B5F185B948CDULL + 0x8BFCE2B613CC30BFULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xB31498E1D35AA053ULL + 0xC6CA831EED3686EBULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xADB85C725228BA81ULL + 0x88F2E205D9336DE7ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xF89B9C130F3DEF7DULL + 0xB594D85AB53BE935ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xCDEB66B4C440202DULL + 0xFB8FF924446222E9ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xBF094ACB8ABCD097ULL + 0xB73DC4ECC653E1D1ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xFD0FE28143D30C8DULL + 0x9AD07D47DF08757CULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xDE0E2E24693A6D43ULL + 0xCFDCD32808229366ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0x833760D5A349F6DDULL + 0xCBC4893042870EE4ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xEC3BEFD2E4DEC597ULL + 0xEBBFBBAEA0CB8B2EULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xF33B40C97A1307F9ULL + 0x8B0C297DDD2A70BDULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xAD69BF023D8F00ADULL + 0xA4FD18A082108803ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x9F2A6484B2F08E45ULL + 0xF1C6346EE05AA3F8ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xB314647C8F72972BULL + 0x9DDED6CAA79B7BCFULL);
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
        // read from: aWorkLaneA, aWorkLaneB, aFireLaneD, aWorkLaneC, aWorkLaneD, aOperationLaneA, aExpandLaneA, aFireLaneA, aOperationLaneB, aExpandLaneB, aOperationLaneD, aOperationLaneC, aExpandLaneC, aFireLaneB, aFireLaneC
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 8011U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneB[((aIndex + 4239U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 1438U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 6161U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 5735U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 3152U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCross, 21U) + RotL64(aIngress, 34U)) ^ (RotL64(aPrevious, 47U) + RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterD = (((aWandererG + RotL64(aIngress, 29U)) + 12849591986267890852U) + aOrbiterAssignSaltF[((aIndex + 12U)) & S_SALT1]) + aNonceWordG;
            aOrbiterJ = ((aWandererH + RotL64(aScatter, 11U)) + 8232614804696815750U) + aOrbiterAssignSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterE = ((aWandererK + RotL64(aCross, 57U)) + RotL64(aCarry, 53U)) + 12141567259210877281U;
            aOrbiterB = ((aWandererB + RotL64(aPrevious, 35U)) + 2928641981037885644U) + aNonceWordO;
            aOrbiterI = ((aWandererE + RotL64(aIngress, 19U)) + RotL64(aCarry, 41U)) + 980733350554783938U;
            aOrbiterC = (aWandererA + RotL64(aScatter, 4U)) + 2683985177993350746U;
            aOrbiterF = (((aWandererC + RotL64(aPrevious, 41U)) + RotL64(aCarry, 5U)) + 14532148403815527355U) + aNonceWordI;
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 7736296629433884203U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 10428437770166310549U;
            aOrbiterE = RotL64((aOrbiterE * 326634742742373401U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 18327174144859461029U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 6810436935194432002U;
            aOrbiterJ = RotL64((aOrbiterJ * 2715987179577753597U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 12606153309690753435U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterC) ^ 17123256945895150555U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterI = RotL64((aOrbiterI * 13469111258504672565U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 9057777759026189541U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 16478485918911194442U;
            aOrbiterD = RotL64((aOrbiterD * 11054247078884894131U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 18064460487552100483U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 11477276762421684083U) ^ aOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3886501230380184395U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 18318375441973295081U) + aOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 13849305985380030986U;
            aOrbiterC = RotL64((aOrbiterC * 12962140243967824959U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 10240409420338313641U) + aOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 18360586077779529086U) ^ aNonceWordJ;
            aOrbiterB = RotL64((aOrbiterB * 18196875422391501927U), 47U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterC, 57U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 3U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 41U));
            aIngress = aIngress + RotL64(aOrbiterB, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aScatter, 12U) + aOrbiterI) + RotL64(aOrbiterC, 4U)) + aNonceWordF) + aWandererUpdateSaltB[((aIndex + 20U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterC, 43U)) + aOrbiterJ) + aNonceWordH);
            aWandererE = aWandererE + (((RotL64(aIngress, 35U) + aOrbiterD) + RotL64(aOrbiterE, 57U)) + RotL64(aCarry, 41U));
            aWandererC = aWandererC ^ ((((RotL64(aPrevious, 57U) + aOrbiterF) + RotL64(aOrbiterJ, 29U)) + aNonceWordE) + aWandererUpdateSaltE[((aIndex + 21U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aCross, 29U) + RotL64(aOrbiterB, 37U)) + aOrbiterE);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 5U) + aOrbiterF) + RotL64(aOrbiterD, 51U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 41U) + RotL64(aOrbiterI, 11U)) + aOrbiterE) + RotL64(aCarry, 5U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 35U));
            aCarry = aCarry + (RotL64(aWandererE, 60U) ^ aWandererC);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 5U));
            aCarry = aCarry + RotL64(aWandererH, 51U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 2
        // ingress from: aExpandLaneA, aWorkLaneC, aFireLaneA
        // ingress directions: aExpandLaneA forward forced, aWorkLaneC forward forced, aFireLaneA forward/backward random
        // cross from: aWorkLaneA, aWorkLaneD, aOperationLaneB
        // cross directions: aWorkLaneA backward forced, aWorkLaneD backward forced, aOperationLaneB backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 10876U)) & S_BLOCK1], 10U) ^ RotL64(aWorkLaneC[((aIndex + 10300U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 11208U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 9256U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 10853U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aOperationLaneB[((aIndex + 14776U)) & S_BLOCK1], 56U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCarry, 35U) ^ RotL64(aIngress, 6U)) + (RotL64(aCross, 51U) + RotL64(aPrevious, 21U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterE = (((aWandererJ + RotL64(aScatter, 3U)) + RotL64(aCarry, 51U)) + 6654158889644956636U) + aNonceWordJ;
            aOrbiterH = (((aWandererF + RotL64(aIngress, 29U)) + RotL64(aCarry, 21U)) + 9045779659363991870U) + aNonceWordK;
            aOrbiterD = ((aWandererC + RotL64(aPrevious, 41U)) + RotL64(aCarry, 39U)) + 3888897662136993491U;
            aOrbiterA = ((aWandererE + RotL64(aCross, 53U)) + 6882016842864459345U) + aOrbiterAssignSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterG = (aWandererK + RotL64(aPrevious, 23U)) + 15601891715956172291U;
            aOrbiterK = (aWandererI + RotL64(aIngress, 60U)) + 5176811598629335350U;
            aOrbiterC = ((aWandererD + RotL64(aCross, 35U)) + 12519945150889074325U) + aOrbiterAssignSaltE[((aIndex + 24U)) & S_SALT1];
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 4552583214397603278U) + aOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 14225482701804864688U;
            aOrbiterD = RotL64((aOrbiterD * 8526052833180466359U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 5485298070606280363U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 11237713257388094289U) ^ aNonceWordE;
            aOrbiterH = RotL64((aOrbiterH * 11032429223099413011U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 14340345895626142788U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 16275167270553643347U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7308578867128951199U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 14041860597556520250U) + aNonceWordF;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 1436068974197066343U) ^ aOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 3938460345031496843U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 11483155566419547004U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 4608508534724289325U;
            aOrbiterC = RotL64((aOrbiterC * 13461385011638899485U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 2389196334288832895U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 4062682330273866602U;
            aOrbiterE = RotL64((aOrbiterE * 8787682133271101901U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 5655656046585592034U) + aNonceWordP;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 7977947821249746880U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 10082104644185964787U), 3U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterC, 41U);
            aIngress = aIngress + (RotL64(aOrbiterE, 21U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 35U));
            aIngress = aIngress + RotL64(aOrbiterH, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aIngress, 27U) + aOrbiterG) + RotL64(aOrbiterK, 57U)) + aWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aCross, 60U) + aOrbiterK) + RotL64(aOrbiterD, 12U)) + aWandererUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterH, 5U)) + aOrbiterE);
            aWandererE = aWandererE + ((((RotL64(aScatter, 41U) + aOrbiterK) + RotL64(aOrbiterA, 35U)) + RotL64(aCarry, 29U)) + aNonceWordL);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 47U) + aOrbiterC) + RotL64(aOrbiterH, 29U));
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 5U) + RotL64(aOrbiterA, 19U)) + aOrbiterC) + RotL64(aCarry, 51U)) + aNonceWordG);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterK, 51U)) + aOrbiterH);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 34U));
            aCarry = aCarry + (RotL64(aWandererI, 27U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererE, 23U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererC, 57U);
            aCarry = aCarry + RotL64(aIngress, 48U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 3
        // ingress from: aExpandLaneB, aWorkLaneD, aOperationLaneD
        // ingress directions: aExpandLaneB forward forced, aWorkLaneD forward forced, aOperationLaneD forward/backward random
        // cross from: aExpandLaneA, aWorkLaneB, aOperationLaneC
        // cross directions: aExpandLaneA backward forced, aWorkLaneB backward forced, aOperationLaneC backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 22495U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneD[((aIndex + 24110U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 19269U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 23485U)) & S_BLOCK1], 34U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 22255U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aOperationLaneC[((aIndex + 21551U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aPrevious, 13U) ^ RotL64(aCarry, 26U)) ^ (RotL64(aIngress, 53U) + RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterA = (aWandererB + RotL64(aPrevious, 19U)) + 4476099022490972343U;
            aOrbiterJ = ((((aWandererC + RotL64(aCross, 13U)) + RotL64(aCarry, 51U)) + 16836423700375760429U) + aOrbiterAssignSaltA[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordC;
            aOrbiterK = (((aWandererF + RotL64(aScatter, 27U)) + RotL64(aCarry, 3U)) + 8850577488928703557U) + aNonceWordI;
            aOrbiterE = (((aWandererK + RotL64(aIngress, 57U)) + RotL64(aCarry, 19U)) + 7091631824560042743U) + aOrbiterAssignSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = ((aWandererA + RotL64(aScatter, 43U)) + 12560498899956759494U) + aNonceWordA;
            aOrbiterG = (aWandererI + RotL64(aPrevious, 3U)) + 7797973377112012161U;
            aOrbiterF = ((aWandererH + RotL64(aIngress, 36U)) + 6173820673874805794U) + aNonceWordG;
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 10805025132310245348U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 7139216143268029968U;
            aOrbiterK = RotL64((aOrbiterK * 8349754682635765573U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 8241544862261635722U) + aOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 4735527016563596150U;
            aOrbiterG = RotL64((aOrbiterG * 6621354217673598381U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 5166171126690294033U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 11117641762075368393U;
            aOrbiterF = RotL64((aOrbiterF * 4980156869201219393U), 53U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterF) + 6312932356458415421U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordF;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 1304139291184508668U;
            aOrbiterA = RotL64((aOrbiterA * 90744653170922319U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 10085025354842771067U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 16745854428789531080U;
            aOrbiterJ = RotL64((aOrbiterJ * 1945983905747274355U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 2497187958708890337U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 16069701876646548995U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 16606039730973709495U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 17242004368025978091U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 12334315722243232121U) ^ aNonceWordK;
            aOrbiterD = RotL64((aOrbiterD * 16528598396696346719U), 27U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterD, 28U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 53U));
            aIngress = aIngress + (RotL64(aOrbiterG, 3U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterA, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aIngress, 29U) + aOrbiterG) + RotL64(aOrbiterE, 3U)) + aWandererUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 41U) + RotL64(aOrbiterJ, 56U)) + aOrbiterA) + RotL64(aCarry, 27U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 47U) + aOrbiterG) + RotL64(aOrbiterK, 21U)) + aNonceWordO);
            aWandererH = aWandererH + (((RotL64(aPrevious, 60U) + RotL64(aOrbiterD, 13U)) + aOrbiterK) + RotL64(aCarry, 11U));
            aWandererK = aWandererK ^ ((((RotL64(aCross, 53U) + aOrbiterF) + RotL64(aOrbiterD, 27U)) + aNonceWordL) + aWandererUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 21U) + RotL64(aOrbiterG, 47U)) + aOrbiterA) + aNonceWordE);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 35U) + aOrbiterA) + RotL64(aOrbiterF, 37U)) + aNonceWordH);
            //
            aCarry = aCarry + (RotL64(aWandererI, 3U) ^ aWandererC);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 11U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 24U));
            aCarry = aCarry + RotL64(aWandererH, 47U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aFireLaneB
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aFireLaneB forward/backward random
        // cross from: aExpandLaneB, aWorkLaneC, aFireLaneC
        // cross directions: aExpandLaneB backward forced, aWorkLaneC backward forced, aFireLaneC backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 27574U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneA[((aIndex + 27697U)) & S_BLOCK1], 34U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 24747U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30293U)) & S_BLOCK1], 28U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 25434U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aFireLaneC[((aIndex + 31060U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCarry, 58U) + RotL64(aIngress, 13U)) + (RotL64(aPrevious, 39U) ^ RotL64(aCross, 27U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterF = (aWandererB + RotL64(aPrevious, 11U)) + 12809562813316740345U;
            aOrbiterB = (((aWandererF + RotL64(aIngress, 23U)) + RotL64(aCarry, 23U)) + 17084212535326321199U) + aNonceWordG;
            aOrbiterH = (((aWandererI + RotL64(aCross, 36U)) + RotL64(aCarry, 57U)) + 16074921689983846769U) + aOrbiterAssignSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = (aWandererK + RotL64(aScatter, 43U)) + 14027986153007120145U;
            aOrbiterG = ((aWandererJ + RotL64(aCross, 29U)) + 7633455951809250227U) + aNonceWordC;
            aOrbiterJ = ((aWandererC + RotL64(aPrevious, 51U)) + 340989348513370174U) + aOrbiterAssignSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = ((aWandererE + RotL64(aScatter, 5U)) + RotL64(aCarry, 39U)) + 5307820377645020116U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 5605285015771527274U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 5293500434746182790U;
            aOrbiterH = RotL64((aOrbiterH * 17674669610895537063U), 41U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterH) + 7263156475892261811U) + aOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1]) + aNonceWordN;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 10672879570907433005U;
            aOrbiterI = RotL64((aOrbiterI * 2506338667179450741U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 16659226780900986107U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 9774892622769850665U;
            aOrbiterE = RotL64((aOrbiterE * 7487477727543183211U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 10728057184108279042U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 5032485856947407217U) ^ aOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 16651577903809154285U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 14642241075374862345U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 8386481273395203518U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 11649977733867003445U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 2874153265304098104U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 11519900149177261000U;
            aOrbiterJ = RotL64((aOrbiterJ * 2010158758971864505U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 8885690878540115768U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterJ) ^ 4482143389870987714U) ^ aOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterF = RotL64((aOrbiterF * 7105332459437434281U), 11U);
            //
            aIngress = RotL64(aOrbiterI, 41U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 5U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 21U));
            aIngress = aIngress + RotL64(aOrbiterG, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aScatter, 60U) + RotL64(aOrbiterE, 13U)) + aOrbiterF);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 35U) + RotL64(aOrbiterJ, 41U)) + aOrbiterE) + RotL64(aCarry, 41U)) + aWandererUpdateSaltB[((aIndex + 27U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aCross, 21U) + RotL64(aOrbiterI, 19U)) + aOrbiterB) + aNonceWordH);
            aWandererF = aWandererF + (((RotL64(aIngress, 53U) + aOrbiterH) + RotL64(aOrbiterF, 47U)) + RotL64(aCarry, 3U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 41U) + RotL64(aOrbiterH, 35U)) + aOrbiterI) + aNonceWordK);
            aWandererC = aWandererC + ((RotL64(aScatter, 29U) + RotL64(aOrbiterI, 53U)) + aOrbiterG);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 47U) + aOrbiterF) + RotL64(aOrbiterJ, 26U)) + aWandererUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 6U));
            aCarry = aCarry + (RotL64(aWandererB, 53U) ^ aWandererJ);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 35U));
            aCarry = aCarry + RotL64(aWandererI, 47U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA;
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
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseHWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseHWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltC;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x8C9217D2EA3B6779ULL + 0xEF0AE06B61DCC3C0ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xCBAAA4213AECC3CDULL + 0xE620E396E45D4E84ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xDBAEC436807D8713ULL + 0xFF3217D0BDC533F4ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x8273EEF77E4349F7ULL + 0xAD74C73CE6C9161AULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xD4C0D2632D74B875ULL + 0xB20AF449D24AAC1CULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xD69EE8DC457622C5ULL + 0xA6625DE064AE62BBULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x8643AF2A222B77D7ULL + 0xF65AAE7923E030ABULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xA53E23DBD8144545ULL + 0xF530498307FA452BULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xD8D1ADF10F166E9FULL + 0xCB1B25EDB4518AC2ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x8209093668DF1B7BULL + 0xDC89C40444787428ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xEC1731117D10AB67ULL + 0xCED7E6F3FC9DFF1CULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xD3291FCBC909F8B7ULL + 0xDEF3206EE84B58DCULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xBE3228FE9A0A39C5ULL + 0xCE7A1A4C96C7C811ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xA187290A7E3EB245ULL + 0xB8E87AB42726D5BAULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x98B489B3356843D1ULL + 0xA88ABB39830F8239ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0x9A86945699F5D0E7ULL + 0xF434AEE122E3EE6EULL);
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
            aIngress = RotL64(aKeyRowReadA[((aIndex + 1372U)) & W_KEY1], 13U) ^ RotL64(aKeyRowReadB[((aIndex + 1658U)) & W_KEY1], 29U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 8U)) & W_KEY1], 23U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 1126U)) & S_BLOCK1], 60U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aPrevious, 39U) + RotL64(aCarry, 54U)) ^ (RotL64(aCross, 19U) ^ RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterE = (aWandererC + RotL64(aPrevious, 53U)) + 14179205183062705133U;
            aOrbiterH = (aWandererH + RotL64(aIngress, 3U)) + 210032324058740920U;
            aOrbiterG = ((aWandererB + RotL64(aCross, 35U)) + RotL64(aCarry, 5U)) + 7387115089142500152U;
            aOrbiterC = ((aWandererA + RotL64(aScatter, 47U)) + 17583362781238061430U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = ((aWandererJ + RotL64(aIngress, 14U)) + RotL64(aCarry, 43U)) + 4991442849150005943U;
            aOrbiterD = ((((aWandererF + RotL64(aScatter, 29U)) + RotL64(aCarry, 29U)) + 2891376254689854555U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordL;
            aOrbiterJ = ((aWandererG + RotL64(aPrevious, 23U)) + 10523274382407446239U) + aNonceWordA;
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 3861893764676218667U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 3366674459852093746U) ^ aNonceWordD;
            aOrbiterG = RotL64((aOrbiterG * 14005994095369483813U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 5898492634386601145U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 7047353571244768721U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2257518291062508467U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 14374108805453186316U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 8763667021501226510U;
            aOrbiterH = RotL64((aOrbiterH * 7694695426430267863U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 18261523829316379575U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 650477532238860965U;
            aOrbiterD = RotL64((aOrbiterD * 8291758490821819851U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 2162326554604894042U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 5776546692501825278U;
            aOrbiterE = RotL64((aOrbiterE * 14911545784585246537U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 3501863793638415049U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 14853789267425352958U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10590325397179928739U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 15399673014671329743U) + aNonceWordK;
            aOrbiterC = (((aOrbiterC ^ aOrbiterJ) ^ 12253428583438990426U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterC = RotL64((aOrbiterC * 12052855472196447849U), 27U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterJ, 19U);
            aIngress = aIngress + (RotL64(aOrbiterH, 53U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 42U));
            aIngress = aIngress + RotL64(aOrbiterG, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aCross, 51U) + aOrbiterG) + RotL64(aOrbiterJ, 3U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 5U) + aOrbiterG) + RotL64(aOrbiterF, 12U)) + aNonceWordC);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 38U) + RotL64(aOrbiterD, 27U)) + aOrbiterJ);
            aWandererB = aWandererB + (((((RotL64(aIngress, 19U) + aOrbiterE) + RotL64(aOrbiterH, 57U)) + RotL64(aCarry, 21U)) + aNonceWordN) + aPhaseEWandererUpdateSaltC[((aIndex + 3U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterD, 51U)) + aOrbiterC);
            aWandererJ = aWandererJ + (((((RotL64(aCross, 13U) + aOrbiterE) + RotL64(aOrbiterC, 43U)) + RotL64(aCarry, 3U)) + aNonceWordM) + aPhaseEWandererUpdateSaltF[((aIndex + 20U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 57U) + aOrbiterF) + RotL64(aOrbiterE, 37U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 40U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererG, 3U) ^ aWandererF);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 53U));
            aCarry = aCarry + RotL64(aWandererJ, 35U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 4929U)) & S_BLOCK1], 57U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 4519U)) & W_KEY1], 5U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 4323U)) & W_KEY1], 56U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 4579U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCarry, 11U) ^ RotL64(aPrevious, 47U)) + (RotL64(aIngress, 23U) + RotL64(aCross, 60U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterH = ((aWandererJ + RotL64(aPrevious, 19U)) + 13960289014350612206U) + aNonceWordG;
            aOrbiterA = ((((aWandererE + RotL64(aIngress, 53U)) + RotL64(aCarry, 53U)) + 3483331015269589730U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordD;
            aOrbiterB = ((aWandererC + RotL64(aCross, 37U)) + 6873299241002444518U) + aNonceWordM;
            aOrbiterJ = ((aWandererG + RotL64(aScatter, 11U)) + RotL64(aCarry, 39U)) + 3562094007125534229U;
            aOrbiterE = (aWandererI + RotL64(aIngress, 47U)) + 11422367439932782705U;
            aOrbiterF = ((aWandererF + RotL64(aScatter, 5U)) + 532453428514259816U) + aNonceWordE;
            aOrbiterG = (((aWandererB + RotL64(aCross, 26U)) + RotL64(aCarry, 3U)) + 17810941465810193088U) + aPhaseEOrbiterAssignSaltC[((aIndex + 5U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 11869759058631106331U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 8837581071876177566U;
            aOrbiterB = RotL64((aOrbiterB * 15329827515970522213U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 17185378327053837778U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 7578253375676981500U;
            aOrbiterE = RotL64((aOrbiterE * 13371647568758721729U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 17112646434432814442U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 14949096407295697881U;
            aOrbiterF = RotL64((aOrbiterF * 14770977858283051753U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 4259590620758467836U) + aNonceWordB;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 6534899413644542303U;
            aOrbiterA = RotL64((aOrbiterA * 7987609419215568661U), 13U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterH) + 2637407498893694243U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1]) + aNonceWordO;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 15819295597921425711U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 5202015597375051399U), 19U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterG) + 6373559542002699718U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1]) + aNonceWordA;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 11694562937392022505U;
            aOrbiterH = RotL64((aOrbiterH * 9311557972331218597U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 3308736483775453062U) + aNonceWordF;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 12749929710650475901U;
            aOrbiterG = RotL64((aOrbiterG * 248428400724560945U), 57U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterF, 43U);
            aIngress = aIngress + (RotL64(aOrbiterA, 51U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 5U));
            aIngress = aIngress + RotL64(aOrbiterG, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 51U) + aOrbiterA) + RotL64(aOrbiterB, 35U));
            aWandererC = aWandererC + (((RotL64(aIngress, 28U) + RotL64(aOrbiterG, 13U)) + aOrbiterJ) + RotL64(aCarry, 21U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 19U) + RotL64(aOrbiterA, 27U)) + aOrbiterJ) + aNonceWordJ);
            aWandererF = aWandererF + (((RotL64(aCross, 11U) + RotL64(aOrbiterB, 21U)) + aOrbiterE) + aPhaseEWandererUpdateSaltA[((aIndex + 21U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 43U) + aOrbiterF) + RotL64(aOrbiterB, 42U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 35U) + RotL64(aOrbiterF, 57U)) + aOrbiterJ) + RotL64(aCarry, 57U)) + aNonceWordL);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 57U) + aOrbiterB) + RotL64(aOrbiterH, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 18U) ^ aWandererJ);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 43U));
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererG, 53U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = RotL64(aWorkLaneB[((aIndex + 8163U)) & S_BLOCK1], 10U) ^ RotL64(aKeyRowReadB[((aIndex + 6719U)) & W_KEY1], 37U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 7186U)) & W_KEY1], 22U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 7568U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 6809U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aPrevious, 43U) ^ RotL64(aCarry, 11U)) + (RotL64(aCross, 23U) + RotL64(aIngress, 56U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterI = ((aWandererA + RotL64(aPrevious, 47U)) + 4068921616130916949U) + aNonceWordM;
            aOrbiterK = (((aWandererK + RotL64(aIngress, 4U)) + RotL64(aCarry, 57U)) + 12077715273915151726U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterG = ((aWandererB + RotL64(aCross, 29U)) + RotL64(aCarry, 11U)) + 16047546802670596833U;
            aOrbiterA = (aWandererG + RotL64(aScatter, 23U)) + 9690277462716999763U;
            aOrbiterE = (((aWandererH + RotL64(aPrevious, 35U)) + RotL64(aCarry, 37U)) + 14484814700447992628U) + aNonceWordL;
            aOrbiterC = (aWandererE + RotL64(aScatter, 57U)) + 17089267243053958210U;
            aOrbiterH = ((aWandererJ + RotL64(aCross, 41U)) + 9138746214446211147U) + aPhaseEOrbiterAssignSaltF[((aIndex + 7U)) & S_SALT1];
            //
            aOrbiterI = (((aOrbiterI + aOrbiterK) + 10181001536979097045U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1]) + aNonceWordC;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 6657458969093373191U) ^ aNonceWordN;
            aOrbiterG = RotL64((aOrbiterG * 4311019792293202747U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 7515983477876590988U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 3039935555863947600U;
            aOrbiterK = RotL64((aOrbiterK * 12511160550780270119U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 16209389224740851136U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 725253312098083182U;
            aOrbiterI = RotL64((aOrbiterI * 17535989492095522597U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 13307041115748941383U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 7159572004825238263U;
            aOrbiterH = RotL64((aOrbiterH * 4855009895002398449U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 12027236743251643820U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 8717826175991286553U) ^ aNonceWordA;
            aOrbiterE = RotL64((aOrbiterE * 1175614802543098451U), 27U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterE) + 4769096034227659937U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordD;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 11201226563992939616U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 15595355978388159931U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 17295978531215563256U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 11850923890626719833U;
            aOrbiterC = RotL64((aOrbiterC * 3854851059897397075U), 57U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterG, 57U);
            aIngress = aIngress + (RotL64(aOrbiterA, 27U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 41U));
            aIngress = aIngress + RotL64(aOrbiterH, 12U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aScatter, 19U) + aOrbiterE) + RotL64(aOrbiterI, 41U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterG, 18U)) + aOrbiterC) + aPhaseEWandererUpdateSaltD[((aIndex + 14U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aPrevious, 60U) + aOrbiterC) + RotL64(aOrbiterH, 5U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterI, 53U)) + aOrbiterK) + aNonceWordH);
            aWandererB = aWandererB + (((RotL64(aIngress, 35U) + aOrbiterG) + RotL64(aOrbiterH, 29U)) + RotL64(aCarry, 37U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterA, 11U)) + aOrbiterK);
            aWandererE = aWandererE + ((((RotL64(aCross, 47U) + aOrbiterH) + RotL64(aOrbiterA, 47U)) + RotL64(aCarry, 51U)) + aNonceWordJ);
            //
            aCarry = aCarry + (RotL64(aWandererK, 6U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererE, 47U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererB, 13U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererG, 57U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 9489U)) & S_BLOCK1], 19U) ^ RotL64(aKeyRowReadB[((aIndex + 10691U)) & W_KEY1], 51U));
            aIngress ^= (RotL64(mSource[((aIndex + 8460U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneA[((aIndex + 10236U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordA));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 8497U)) & W_KEY1], 37U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 9368U)) & S_BLOCK1], 10U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aPrevious, 27U) + RotL64(aCarry, 11U)) + (RotL64(aIngress, 60U) ^ RotL64(aCross, 43U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterE = ((aWandererG + RotL64(aCross, 5U)) + 13350544654542863236U) + aPhaseFOrbiterAssignSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = ((((aWandererB + RotL64(aIngress, 37U)) + RotL64(aCarry, 27U)) + 12364346790125404372U) + aPhaseFOrbiterAssignSaltB[((aIndex + 26U)) & S_SALT1]) + aNonceWordD;
            aOrbiterD = ((aWandererD + RotL64(aScatter, 13U)) + 9738750172849512764U) + aNonceWordC;
            aOrbiterC = ((aWandererK + RotL64(aPrevious, 19U)) + RotL64(aCarry, 5U)) + 3781373837635491421U;
            aOrbiterH = (aWandererF + RotL64(aIngress, 29U)) + 16635020317512702337U;
            aOrbiterG = ((aWandererH + RotL64(aCross, 56U)) + 5383653921676231276U) + aNonceWordM;
            aOrbiterF = ((aWandererA + RotL64(aScatter, 43U)) + RotL64(aCarry, 47U)) + 10181959815492056493U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 10005510924273927017U) + aNonceWordL;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 9524687662265740565U;
            aOrbiterD = RotL64((aOrbiterD * 13687380438646756931U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 4259138552009771014U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 8973051213213726023U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12625091476068190979U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 17602611840127337490U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 8218984546932905269U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 17504305273683304231U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 18102186122213487888U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 2629927500298092976U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 6983280164448292723U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 2491581597835795234U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 9506602492971620955U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9559829640915637163U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 13422942713680612924U) + aNonceWordF;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 15037354693234876601U;
            aOrbiterF = RotL64((aOrbiterF * 12692376075738621447U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 12896066842192894694U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 2202952306291905855U;
            aOrbiterC = RotL64((aOrbiterC * 6779368532763429997U), 57U);
            //
            aIngress = RotL64(aOrbiterA, 27U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterH, 20U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterC, 3U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterE, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aScatter, 11U) + aOrbiterG) + RotL64(aOrbiterH, 5U)) + aPhaseFWandererUpdateSaltC[((aIndex + 6U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterF, 19U)) + aOrbiterC) + aNonceWordO);
            aWandererH = aWandererH ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterF, 11U)) + aOrbiterD) + aNonceWordB);
            aWandererA = aWandererA + (((RotL64(aIngress, 29U) + RotL64(aOrbiterE, 39U)) + aOrbiterA) + RotL64(aCarry, 29U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 41U) + aOrbiterA) + RotL64(aOrbiterC, 27U));
            aWandererB = aWandererB + ((((RotL64(aPrevious, 35U) + RotL64(aOrbiterH, 60U)) + aOrbiterF) + RotL64(aCarry, 47U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 56U) + aOrbiterF) + RotL64(aOrbiterG, 51U)) + aNonceWordJ);
            //
            aCarry = aCarry + (RotL64(aWandererF, 53U) ^ aWandererG);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 38U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 19U));
            aCarry = aCarry + RotL64(aWandererB, 57U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = (RotL64(aWorkLaneD[((aIndex + 11471U)) & S_BLOCK1], 57U) ^ RotL64(aKeyRowReadA[((aIndex + 11778U)) & W_KEY1], 12U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 13368U)) & W_KEY1], 29U) ^ RotL64(mSource[((aIndex + 13493U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aWorkLaneB[((aIndex + 12938U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 11653U)) & S_BLOCK1], 44U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 11624U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCross, 29U) + RotL64(aPrevious, 60U)) + (RotL64(aCarry, 47U) ^ RotL64(aIngress, 11U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterD = (aWandererC + RotL64(aPrevious, 12U)) + 380024772508948442U;
            aOrbiterE = ((((aWandererJ + RotL64(aCross, 47U)) + RotL64(aCarry, 23U)) + 7649029098162567210U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordH;
            aOrbiterA = ((aWandererD + RotL64(aScatter, 35U)) + RotL64(aCarry, 3U)) + 5329304598870421851U;
            aOrbiterI = ((aWandererK + RotL64(aIngress, 29U)) + 12306118665045151326U) + aNonceWordI;
            aOrbiterC = (aWandererE + RotL64(aCross, 3U)) + 960751560457324256U;
            aOrbiterB = ((aWandererF + RotL64(aScatter, 53U)) + 3244070254386191876U) + aNonceWordL;
            aOrbiterG = (((aWandererI + RotL64(aPrevious, 19U)) + RotL64(aCarry, 47U)) + 15733408571609521746U) + aPhaseFOrbiterAssignSaltC[((aIndex + 17U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 17623448932647018544U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 8787759896149035829U) ^ aNonceWordF;
            aOrbiterA = RotL64((aOrbiterA * 7092515868845497573U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 14741681792348288162U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 8801731213568307302U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12127126999570616489U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 9872248187499779222U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 15407371518644528235U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 1245102406469471673U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 4242060317152943062U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 9942784962409917541U;
            aOrbiterD = RotL64((aOrbiterD * 888649755587764533U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 7296348796484458631U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 15061417216070157797U) ^ aNonceWordC;
            aOrbiterB = RotL64((aOrbiterB * 10349554676953256231U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 3233185810644297433U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 9241229457641024287U;
            aOrbiterG = RotL64((aOrbiterG * 2728237515724597517U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 8464051359381554575U) + aNonceWordB;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 3307872165699029375U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 4859663401033023433U), 51U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterB, 29U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 37U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 43U));
            aIngress = aIngress + RotL64(aOrbiterC, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aIngress, 3U) + aOrbiterC) + RotL64(aOrbiterD, 47U));
            aWandererJ = aWandererJ ^ ((((RotL64(aCross, 19U) + RotL64(aOrbiterA, 41U)) + aOrbiterD) + aNonceWordN) + aPhaseFWandererUpdateSaltE[((aIndex + 5U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aScatter, 13U) + RotL64(aOrbiterA, 57U)) + aOrbiterG);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 48U) + aOrbiterB) + RotL64(aOrbiterC, 35U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aCross, 27U) + aOrbiterB) + RotL64(aOrbiterI, 13U)) + RotL64(aCarry, 35U)) + aNonceWordE);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 35U) + RotL64(aOrbiterG, 19U)) + aOrbiterC) + aNonceWordM);
            aWandererF = aWandererF + ((((RotL64(aScatter, 41U) + aOrbiterE) + RotL64(aOrbiterI, 26U)) + RotL64(aCarry, 5U)) + aNonceWordK);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 53U));
            aCarry = aCarry + (RotL64(aWandererI, 57U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererK, 48U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererD, 29U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 14211U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 14735U)) & S_BLOCK1], 4U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 16153U)) & W_KEY1], 35U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 14356U)) & W_KEY1], 60U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 14714U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 14710U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 14227U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCross, 11U) ^ RotL64(aPrevious, 41U)) + (RotL64(aIngress, 27U) + RotL64(aCarry, 58U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterI = (aWandererK + RotL64(aIngress, 35U)) + 7896237440058555694U;
            aOrbiterJ = ((aWandererA + RotL64(aCross, 13U)) + 11870529476037558635U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterK = (aWandererF + RotL64(aScatter, 3U)) + 9158983227801569448U;
            aOrbiterH = ((aWandererD + RotL64(aPrevious, 19U)) + 4710172270996950329U) + aNonceWordO;
            aOrbiterF = ((((aWandererI + RotL64(aScatter, 27U)) + RotL64(aCarry, 47U)) + 14634482800356647630U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordA;
            aOrbiterB = ((aWandererE + RotL64(aCross, 53U)) + RotL64(aCarry, 3U)) + 8822207952170610891U;
            aOrbiterD = (((aWandererB + RotL64(aIngress, 44U)) + RotL64(aCarry, 27U)) + 13755891414028982553U) + aNonceWordE;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 4555293067488040719U) + aNonceWordF;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 2816805148093762081U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 16838149138341713943U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 2122631477965135190U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 4592922416380416071U;
            aOrbiterJ = RotL64((aOrbiterJ * 11644507904538573165U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 7102471666524164715U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 17274623547879474204U;
            aOrbiterD = RotL64((aOrbiterD * 5443572270546181789U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 938587316977094680U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 18258015823797023523U;
            aOrbiterF = RotL64((aOrbiterF * 6068819567674605919U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 5809987756043471595U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterF) ^ 5083075160112581620U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterB = RotL64((aOrbiterB * 3313957222154937503U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 5960021727750946496U) + aNonceWordC;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 5967477320950630150U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 330964768256424655U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 6578428711689296132U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 5601728218197771276U;
            aOrbiterI = RotL64((aOrbiterI * 9552559022315971847U), 35U);
            //
            aIngress = RotL64(aOrbiterB, 13U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterJ, 41U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterK, 3U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterI, 50U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((((RotL64(aCross, 35U) + RotL64(aOrbiterB, 3U)) + aOrbiterH) + aNonceWordB) + aPhaseFWandererUpdateSaltC[((aIndex + 15U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aIngress, 5U) + aOrbiterJ) + RotL64(aOrbiterH, 43U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 13U) + aOrbiterK) + RotL64(aOrbiterH, 11U));
            aWandererB = aWandererB + ((((RotL64(aScatter, 57U) + aOrbiterB) + RotL64(aOrbiterJ, 57U)) + RotL64(aCarry, 21U)) + aNonceWordN);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 28U) + RotL64(aOrbiterK, 37U)) + aOrbiterI) + aNonceWordL);
            aWandererF = aWandererF + ((((RotL64(aIngress, 21U) + aOrbiterD) + RotL64(aOrbiterK, 29U)) + RotL64(aCarry, 43U)) + aPhaseFWandererUpdateSaltE[((aIndex + 5U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterF, 20U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 24U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 39U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 5U));
            aCarry = aCarry + RotL64(aWandererI, 51U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 17091U)) & S_BLOCK1], 57U) ^ RotL64(aKeyRowReadA[((aIndex + 17977U)) & W_KEY1], 27U));
            aIngress ^= (RotL64(mSource[((aIndex + 18437U)) & S_BLOCK1], 38U) ^ RotL64(aWorkLaneA[((aIndex + 18399U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 18839U)) & W_KEY1], 36U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 18566U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 18665U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCross, 39U) + RotL64(aPrevious, 26U)) ^ (RotL64(aCarry, 53U) + RotL64(aIngress, 11U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterK = (((aWandererE + RotL64(aCross, 3U)) + RotL64(aCarry, 39U)) + 16183871922837164759U) + aNonceWordP;
            aOrbiterG = (((aWandererK + RotL64(aIngress, 19U)) + 7002058258090219055U) + aPhaseGOrbiterAssignSaltB[((aIndex + 9U)) & S_SALT1]) + aNonceWordF;
            aOrbiterA = (aWandererF + RotL64(aScatter, 30U)) + 5650868611888303705U;
            aOrbiterJ = ((aWandererI + RotL64(aPrevious, 41U)) + RotL64(aCarry, 53U)) + 11899839660943876690U;
            aOrbiterH = (aWandererH + RotL64(aCross, 57U)) + 15349649504488111111U;
            aOrbiterE = ((aWandererJ + RotL64(aIngress, 11U)) + RotL64(aCarry, 19U)) + 14060149569086744970U;
            aOrbiterI = ((aWandererA + RotL64(aScatter, 47U)) + 12920917574225030112U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 2831994965175330135U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 18312543585028439192U;
            aOrbiterA = RotL64((aOrbiterA * 11618182708195744321U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 11657562205118394239U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 10850792819281246052U) ^ aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 10663100544207879337U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 17810371216216125323U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 7963413941144223128U) ^ aNonceWordN;
            aOrbiterE = RotL64((aOrbiterE * 534217972450595401U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 5498715358793875584U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 9256727548911651373U;
            aOrbiterI = RotL64((aOrbiterI * 10498848323914000989U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 17246360111302191699U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterE) ^ 18309978718113983369U) ^ aPhaseGOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterK = RotL64((aOrbiterK * 18267472694666221077U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 3100998994319502921U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 8129301860291235970U) ^ aNonceWordM;
            aOrbiterG = RotL64((aOrbiterG * 17847033539279176187U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 1889641029473279114U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterG) ^ 16538494307002917945U) ^ aPhaseGOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterJ = RotL64((aOrbiterJ * 8081488217920885783U), 37U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterE, 47U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 18U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 11U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterG, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aScatter, 35U) + aOrbiterA) + RotL64(aOrbiterK, 36U)) + aNonceWordB);
            aWandererK = aWandererK + (((RotL64(aIngress, 41U) + aOrbiterG) + RotL64(aOrbiterK, 11U)) + aPhaseGWandererUpdateSaltE[((aIndex + 6U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterE, 53U)) + aOrbiterJ);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 53U) + aOrbiterA) + RotL64(aOrbiterJ, 23U)) + RotL64(aCarry, 19U)) + aNonceWordL);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 21U) + aOrbiterH) + RotL64(aOrbiterE, 47U)) + aNonceWordJ);
            aWandererI = aWandererI + (((((RotL64(aCross, 13U) + RotL64(aOrbiterH, 5U)) + aOrbiterI) + RotL64(aCarry, 47U)) + aNonceWordE) + aPhaseGWandererUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 4U) + aOrbiterH) + RotL64(aOrbiterJ, 29U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 53U));
            aCarry = aCarry + (RotL64(aWandererJ, 19U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererF, 14U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererE, 39U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 20937U)) & S_BLOCK1], 3U) ^ RotL64(mSource[((aIndex + 21417U)) & S_BLOCK1], 29U));
            aIngress ^= (RotL64(aFireLaneA[((aIndex + 21801U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 20983U)) & S_BLOCK1], 42U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 20743U)) & W_KEY1], 5U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 19169U)) & W_KEY1], 43U));
            aCross ^= (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 20444U)) & S_BLOCK1], 56U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 20891U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aPrevious, 19U) ^ RotL64(aCarry, 53U)) ^ (RotL64(aIngress, 36U) + RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterD = (aWandererE + RotL64(aPrevious, 13U)) + 10336802574069791273U;
            aOrbiterJ = ((aWandererA + RotL64(aScatter, 51U)) + 169025388197058936U) + aNonceWordK;
            aOrbiterI = (aWandererH + RotL64(aIngress, 4U)) + 6541354188379168846U;
            aOrbiterH = ((aWandererF + RotL64(aCross, 57U)) + RotL64(aCarry, 57U)) + 16223920526599306104U;
            aOrbiterB = ((aWandererI + RotL64(aScatter, 35U)) + 12756613707692514808U) + aPhaseGOrbiterAssignSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterC = (((aWandererB + RotL64(aPrevious, 27U)) + RotL64(aCarry, 19U)) + 5082475548176484035U) + aNonceWordB;
            aOrbiterK = (((aWandererC + RotL64(aIngress, 21U)) + RotL64(aCarry, 35U)) + 4907435526952698526U) + aPhaseGOrbiterAssignSaltA[((aIndex + 5U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 14236627073831834337U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 11502511046130497584U) ^ aNonceWordI;
            aOrbiterI = RotL64((aOrbiterI * 3460330807286625917U), 37U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 3679044835550219497U) + aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 11254838916686736746U;
            aOrbiterD = RotL64((aOrbiterD * 8631695922983532915U), 11U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterH) + 10582608424233200966U) + aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordF;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 10449735026385340313U) ^ aPhaseGOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7363770199734997411U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 4628253464169957835U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 17664454668473204465U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4234720298731378527U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 3798386391743884889U) + aNonceWordH;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 1379331161819246587U;
            aOrbiterJ = RotL64((aOrbiterJ * 13086160171095077295U), 21U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 9816600392407327227U) + aNonceWordE;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 16781971616348376878U;
            aOrbiterK = RotL64((aOrbiterK * 12503867584828289879U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 4807797577690520554U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 2492057261148595922U;
            aOrbiterH = RotL64((aOrbiterH * 9453302540675483005U), 43U);
            //
            aIngress = RotL64(aOrbiterJ, 5U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 19U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 37U));
            aIngress = aIngress + RotL64(aOrbiterB, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aIngress, 11U) + RotL64(aOrbiterJ, 37U)) + aOrbiterH) + aNonceWordO);
            aWandererF = aWandererF + (((RotL64(aCross, 35U) + aOrbiterH) + RotL64(aOrbiterI, 57U)) + RotL64(aCarry, 53U));
            aWandererB = aWandererB ^ ((((RotL64(aPrevious, 50U) + aOrbiterK) + RotL64(aOrbiterB, 29U)) + aNonceWordC) + aPhaseGWandererUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aScatter, 19U) + aOrbiterD) + RotL64(aOrbiterJ, 11U)) + RotL64(aCarry, 35U)) + aNonceWordJ);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterJ, 18U)) + aOrbiterC);
            aWandererC = aWandererC + ((((RotL64(aScatter, 27U) + aOrbiterI) + RotL64(aOrbiterD, 51U)) + aNonceWordL) + aPhaseGWandererUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterJ, 3U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 29U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 34U));
            aCarry = aCarry + (RotL64(aWandererC, 39U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererE, 43U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 22051U)) & S_BLOCK1], 29U) ^ RotL64(aKeyRowReadA[((aIndex + 22154U)) & W_KEY1], 37U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 23169U)) & W_KEY1], 20U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 23998U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 23472U)) & S_BLOCK1], 24U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 23026U)) & S_BLOCK1], 47U));
            aCross ^= (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 21940U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneD[((aIndex + 22488U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCarry, 43U) + RotL64(aIngress, 11U)) ^ (RotL64(aPrevious, 30U) + RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterJ = (aWandererB + RotL64(aPrevious, 35U)) + 16802219662864902427U;
            aOrbiterD = ((aWandererF + RotL64(aScatter, 6U)) + RotL64(aCarry, 37U)) + 14332033461409490629U;
            aOrbiterC = (((aWandererC + RotL64(aCross, 57U)) + RotL64(aCarry, 19U)) + 8781794298640286845U) + aNonceWordB;
            aOrbiterB = (((aWandererJ + RotL64(aIngress, 51U)) + RotL64(aCarry, 57U)) + 8459933908074937264U) + aNonceWordK;
            aOrbiterI = (((aWandererE + RotL64(aPrevious, 43U)) + 1883580287986004426U) + aPhaseGOrbiterAssignSaltA[((aIndex + 3U)) & S_SALT1]) + aNonceWordH;
            aOrbiterK = ((aWandererD + RotL64(aCross, 13U)) + 17500258188004626118U) + aNonceWordE;
            aOrbiterG = ((aWandererA + RotL64(aScatter, 27U)) + 7934811305150872870U) + aPhaseGOrbiterAssignSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 6380363892361098905U) + aPhaseGOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 12623079132626676910U) ^ aNonceWordG;
            aOrbiterC = RotL64((aOrbiterC * 12406671746344127399U), 53U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 10455208121949202703U) + aNonceWordF;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 8805532707916767629U;
            aOrbiterD = RotL64((aOrbiterD * 666082374369701881U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 9161544391400377699U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 3501434325829663268U;
            aOrbiterK = RotL64((aOrbiterK * 7933545151293799637U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 651783304096081996U) + aNonceWordM;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 441505031509930622U) ^ aPhaseGOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 8045355432310956143U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 1771159983581326424U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 15227946417377695989U;
            aOrbiterJ = RotL64((aOrbiterJ * 1563141188972797601U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 4153717524193279095U) + aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 4404521756523902829U) ^ aNonceWordN;
            aOrbiterG = RotL64((aOrbiterG * 1410342912973206203U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 6231945075461813285U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 3864780227164426690U;
            aOrbiterB = RotL64((aOrbiterB * 18031353247480673617U), 11U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterC, 23U);
            aIngress = aIngress + (RotL64(aOrbiterK, 3U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterG, 29U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterB, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aIngress, 3U) + RotL64(aOrbiterD, 37U)) + aOrbiterJ);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterB, 47U)) + aOrbiterK);
            aWandererA = aWandererA + (((((RotL64(aScatter, 23U) + RotL64(aOrbiterG, 23U)) + aOrbiterK) + RotL64(aCarry, 23U)) + aNonceWordL) + aPhaseGWandererUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((((RotL64(aPrevious, 29U) + aOrbiterB) + RotL64(aOrbiterJ, 29U)) + aNonceWordI) + aPhaseGWandererUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aScatter, 50U) + aOrbiterI) + RotL64(aOrbiterB, 14U)) + aNonceWordD);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 11U) + RotL64(aOrbiterI, 53U)) + aOrbiterC) + aNonceWordJ);
            aWandererB = aWandererB + (((RotL64(aPrevious, 35U) + aOrbiterK) + RotL64(aOrbiterC, 3U)) + RotL64(aCarry, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 13U) ^ aWandererE);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 57U));
            aCarry = aCarry + (RotL64(aWandererC, 48U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererB, 19U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 25938U)) & S_BLOCK1], 29U) ^ RotL64(aKeyRowReadA[((aIndex + 25308U)) & W_KEY1], 20U));
            aIngress ^= (RotL64(aFireLaneD[((aIndex + 25501U)) & S_BLOCK1], 47U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 25815U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 26040U)) & W_KEY1], 57U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 25919U)) & S_BLOCK1], 43U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 26342U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneD[((aIndex + 24623U)) & S_BLOCK1], 22U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aPrevious, 19U) ^ RotL64(aCarry, 38U)) ^ (RotL64(aIngress, 51U) + RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterA = (((aWandererI + RotL64(aIngress, 11U)) + 785861751704720606U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 16U)) & S_SALT1]) + aNonceWordL;
            aOrbiterH = (aWandererE + RotL64(aPrevious, 19U)) + 15968088718435606299U;
            aOrbiterJ = ((aWandererB + RotL64(aScatter, 3U)) + RotL64(aCarry, 57U)) + 1393976526590347151U;
            aOrbiterB = (((aWandererA + RotL64(aCross, 46U)) + RotL64(aCarry, 37U)) + 17240750947292745884U) + aNonceWordD;
            aOrbiterG = ((aWandererF + RotL64(aPrevious, 53U)) + RotL64(aCarry, 23U)) + 4921576136163183137U;
            aOrbiterE = ((aWandererG + RotL64(aScatter, 27U)) + 3334047873553153032U) + aPhaseHOrbiterAssignSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = (aWandererC + RotL64(aCross, 37U)) + 15086509978458408698U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 892391205397581998U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 2965686403183767521U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 709160942482770225U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 14632215393655706170U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 15740589515342377322U) ^ aNonceWordI;
            aOrbiterB = RotL64((aOrbiterB * 15677716942904794913U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 11131164813943086445U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 6988080581278900960U;
            aOrbiterH = RotL64((aOrbiterH * 6412189142344044255U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 16021254613117657178U) + aNonceWordF;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 6183615599897921154U;
            aOrbiterA = RotL64((aOrbiterA * 9976411093264211033U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 12533992547026652747U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 3104325358982904219U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 14977348108778147265U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 3878525937957474644U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 2120435259884368445U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 15964718652193073177U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 14928658302694194856U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 9121310461310309348U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 17304439784647477491U), 57U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterB, 35U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 22U));
            aIngress = aIngress + (RotL64(aOrbiterH, 29U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterE, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aCross, 60U) + RotL64(aOrbiterH, 43U)) + aOrbiterJ);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 53U) + RotL64(aOrbiterG, 51U)) + aOrbiterE) + aPhaseHWandererUpdateSaltE[((aIndex + 17U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aIngress, 21U) + aOrbiterG) + RotL64(aOrbiterF, 6U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 27U) + aOrbiterG) + RotL64(aOrbiterH, 57U));
            aWandererI = aWandererI + ((((RotL64(aCross, 13U) + aOrbiterF) + RotL64(aOrbiterB, 29U)) + RotL64(aCarry, 39U)) + aNonceWordH);
            aWandererG = aWandererG ^ ((((RotL64(aIngress, 39U) + aOrbiterJ) + RotL64(aOrbiterB, 13U)) + aNonceWordO) + aPhaseHWandererUpdateSaltA[((aIndex + 5U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 47U) + aOrbiterE) + RotL64(aOrbiterA, 21U)) + RotL64(aCarry, 21U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 4U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererF, 19U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererI, 51U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererC, 35U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 27578U)) & S_BLOCK1], 35U) ^ RotL64(aFireLaneD[((aIndex + 27357U)) & S_BLOCK1], 5U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 28843U)) & W_KEY1], 44U) ^ RotL64(aFireLaneC[((aIndex + 29233U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 28716U)) & W_KEY1], 57U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 27990U)) & S_BLOCK1], 37U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27540U)) & S_BLOCK1], 24U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 29359U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCross, 11U) ^ RotL64(aPrevious, 52U)) + (RotL64(aIngress, 39U) + RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterC = ((aWandererC + RotL64(aIngress, 13U)) + RotL64(aCarry, 5U)) + 17454559218352016650U;
            aOrbiterD = ((((aWandererA + RotL64(aScatter, 21U)) + RotL64(aCarry, 37U)) + 8005709669325164803U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 16U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterH = (((aWandererF + RotL64(aCross, 41U)) + RotL64(aCarry, 51U)) + 13393741948412816357U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterF = (aWandererG + RotL64(aPrevious, 58U)) + 3665865624348875553U;
            aOrbiterG = (aWandererE + RotL64(aScatter, 5U)) + 8334142570031883436U;
            aOrbiterJ = ((aWandererJ + RotL64(aCross, 35U)) + 17226066128706139657U) + aNonceWordK;
            aOrbiterK = ((aWandererI + RotL64(aPrevious, 27U)) + 3319093033121522613U) + aNonceWordA;
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 6657535603401588798U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 5469746182326331147U;
            aOrbiterH = RotL64((aOrbiterH * 11315450342347794329U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 17846791786050221418U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 15939541003714896288U;
            aOrbiterC = RotL64((aOrbiterC * 1400351482213119809U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 12076763190461077406U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 3594038213596405284U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10244002692575821495U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 8301291631324464622U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 8460406137668390582U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9117147929757711595U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 7612394867020871200U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 8525076134853103975U) ^ aNonceWordE;
            aOrbiterG = RotL64((aOrbiterG * 5790440201072204659U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 11929899088215090379U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 7119509166360685726U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 1662341427992528823U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 5081078459225240607U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 17149991983909906705U) ^ aNonceWordN;
            aOrbiterF = RotL64((aOrbiterF * 950223374568067343U), 51U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterC, 19U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 35U));
            aIngress = aIngress + (RotL64(aOrbiterK, 5U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterJ, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aScatter, 57U) + aOrbiterD) + RotL64(aOrbiterK, 29U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 35U) + RotL64(aOrbiterD, 3U)) + aOrbiterH) + aNonceWordG);
            aWandererG = aWandererG + ((((RotL64(aCross, 47U) + RotL64(aOrbiterF, 43U)) + aOrbiterH) + RotL64(aCarry, 39U)) + aNonceWordB);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 18U) + aOrbiterF) + RotL64(aOrbiterC, 53U)) + aNonceWordM);
            aWandererI = aWandererI + ((((RotL64(aCross, 11U) + RotL64(aOrbiterJ, 11U)) + aOrbiterC) + aNonceWordH) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 5U) + RotL64(aOrbiterF, 37U)) + aOrbiterG) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aIngress, 29U) + aOrbiterH) + RotL64(aOrbiterC, 60U)) + RotL64(aCarry, 57U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 13U));
            aCarry = aCarry + (RotL64(aWandererI, 58U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererE, 39U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererF, 29U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 32376U)) & S_BLOCK1], 19U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 30566U)) & W_KEY1], 58U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 32296U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 32660U)) & S_BLOCK1], 13U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30228U)) & S_BLOCK1], 46U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 32425U)) & W_KEY1], 29U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCross, 23U) ^ RotL64(aIngress, 37U)) + (RotL64(aPrevious, 6U) ^ RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterC = (((aWandererD + RotL64(aCross, 41U)) + RotL64(aCarry, 13U)) + 9630214189402543339U) + aNonceWordF;
            aOrbiterF = (aWandererF + RotL64(aIngress, 27U)) + 4072576573737526819U;
            aOrbiterA = ((aWandererK + RotL64(aScatter, 35U)) + 15994787452709618869U) + aPhaseHOrbiterAssignSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterD = (((aWandererB + RotL64(aPrevious, 47U)) + RotL64(aCarry, 29U)) + 6403240137132259482U) + aNonceWordM;
            aOrbiterH = (aWandererJ + RotL64(aIngress, 21U)) + 10229266900170507720U;
            aOrbiterK = (((aWandererH + RotL64(aScatter, 5U)) + RotL64(aCarry, 47U)) + 5025294577989748989U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = (aWandererE + RotL64(aPrevious, 60U)) + 16696461238217956883U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 9878318855341719119U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 16086635438116177346U;
            aOrbiterA = RotL64((aOrbiterA * 5585682357395705671U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 12295437783084203730U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 7681150419912842402U;
            aOrbiterH = RotL64((aOrbiterH * 7289497379725191451U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 2639104034287637448U) + aNonceWordJ;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 12298170009332243573U;
            aOrbiterF = RotL64((aOrbiterF * 9397919591171238575U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 3485932317267669626U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterD) ^ 16569551670038752475U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterC = RotL64((aOrbiterC * 8139802826402217631U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 4448490103784103954U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 14510534073046885941U;
            aOrbiterB = RotL64((aOrbiterB * 7777192047386438305U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 4286195398675733451U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 15790355933840266463U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 13342257823027075501U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 6362891510370156055U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 15121822034579983174U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 7268045994574844937U), 41U);
            //
            aIngress = RotL64(aOrbiterK, 34U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterB, 27U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 57U));
            aIngress = aIngress + RotL64(aOrbiterA, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterF, 57U)) + aOrbiterH);
            aWandererK = aWandererK + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterK, 3U)) + aOrbiterD) + RotL64(aCarry, 13U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterB, 51U)) + aOrbiterA) + aPhaseHWandererUpdateSaltD[((aIndex + 23U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aScatter, 27U) + RotL64(aOrbiterA, 19U)) + aOrbiterH) + aNonceWordH);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 53U) + aOrbiterB) + RotL64(aOrbiterK, 37U)) + aNonceWordD);
            aWandererE = aWandererE + (((RotL64(aScatter, 19U) + aOrbiterF) + RotL64(aOrbiterC, 11U)) + RotL64(aCarry, 39U));
            aWandererJ = aWandererJ ^ ((((RotL64(aCross, 60U) + aOrbiterH) + RotL64(aOrbiterB, 28U)) + aNonceWordI) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 3U) ^ aWandererJ);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 19U));
            aCarry = aCarry + (RotL64(aWandererK, 50U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererB, 27U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterD = 0; std::uint64_t aOrbiterE = 0;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xBAD68EAE26A38AD3ULL + 0xFA42EBEE3F81AA51ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xEB082A38C0FCE813ULL + 0xEC7995B344FB26EDULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xF3129CA4B6922B5BULL + 0x9FD09C2F6A365629ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xF5E5D7C44B67E649ULL + 0xFB1BBEECA055B765ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xBC582ACA53315783ULL + 0xC1AF58AC336A6138ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x8A4181103552D7E1ULL + 0xC0A2BB8B2CF3938AULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xEF3AA02822C7E315ULL + 0x8A933D042050D09AULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xB7C237AB423DAA11ULL + 0xD478B7E93E391C2DULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xF88E6DB781A851F9ULL + 0x8EE82E471B1879A6ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xD28E42778F13E2BDULL + 0xFD68AE158B8A46D9ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xB5422C0663D8D53FULL + 0xB912EEC3B773435CULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xB6C0F9D5428323AFULL + 0xF6A778B122C170D1ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xFFD3AD746A632569ULL + 0xD4D4A1AF5A264203ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xA797A50405CE04A7ULL + 0xE3D6F8FB1488AD39ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x9B53FDA2B928AB65ULL + 0xE4057D48E1059837ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xB32C2ABAEB233ADDULL + 0xB55B304721B863A0ULL);
    // GSeedRunSeed_B seed_loop_a (start)
    {
        // GSeedRunSeed_B seed_loop_a lane group
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneD, aExpandLaneC, aExpandLaneD, aInvestLaneA, aFireLaneA, aInvestLaneB, aFireLaneC, aOperationLaneA, aFireLaneB, aOperationLaneB, aOperationLaneC
        // write to: aInvestLaneA, aInvestLaneB, aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD
    
        // seed_loop_a loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aFireLaneD
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aFireLaneD forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward/forward random
        // write to: aInvestLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 4349U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneB[((aIndex + 3445U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 1229U)) & S_BLOCK1], 6U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 2118U)) & S_BLOCK1], 22U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 3234U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCarry, 53U) + RotL64(aPrevious, 23U)) + (RotL64(aCross, 6U) ^ RotL64(aIngress, 35U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterG = (((aWandererI + RotL64(aCross, 53U)) + 10915618884692072446U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordK;
            aOrbiterE = (((aWandererJ + RotL64(aPrevious, 42U)) + 12634922308499254909U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordA;
            aOrbiterA = ((aWandererH + RotL64(aIngress, 27U)) + RotL64(aCarry, 51U)) + 6533934734564499389U;
            aOrbiterH = ((aWandererE + RotL64(aScatter, 3U)) + RotL64(aCarry, 39U)) + 6744203303756105181U;
            aOrbiterF = ((aWandererA + RotL64(aCross, 11U)) + RotL64(aCarry, 5U)) + 13086782386652045658U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 5693840533331397822U) + aNonceWordM;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 1803663542535024611U) ^ aNonceWordB;
            aOrbiterA = RotL64((aOrbiterA * 8511046986156781857U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 3597219300593287708U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 1429753448204448904U;
            aOrbiterF = RotL64((aOrbiterF * 10927459251773273143U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 17229017825587322715U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 1137574712801062932U;
            aOrbiterE = RotL64((aOrbiterE * 3645832160939819415U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 2401991077004083378U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 1332473247826139292U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 15029831858261506447U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 11730946340796899885U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 15319163439700390962U;
            aOrbiterH = RotL64((aOrbiterH * 1349242001887975499U), 13U);
            //
            aIngress = RotL64(aOrbiterA, 14U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterG, 3U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterF, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aScatter, 36U) + RotL64(aOrbiterH, 3U)) + aOrbiterE);
            aWandererH = aWandererH + ((((RotL64(aCross, 53U) + aOrbiterA) + RotL64(aOrbiterG, 47U)) + RotL64(aCarry, 35U)) + aNonceWordI);
            aWandererA = aWandererA ^ ((((RotL64(aIngress, 27U) + RotL64(aOrbiterH, 57U)) + aOrbiterF) + aNonceWordJ) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((((RotL64(aPrevious, 3U) + aOrbiterG) + RotL64(aOrbiterH, 23U)) + RotL64(aCarry, 11U)) + aNonceWordH) + aPhaseAWandererUpdateSaltD[((aIndex + 21U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 11U) + aOrbiterF) + RotL64(aOrbiterE, 34U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 13U));
            aCarry = aCarry + (RotL64(aWandererI, 58U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererE, 5U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 6052U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneC[((aIndex + 10709U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 6857U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 10364U)) & S_BLOCK1], 34U) ^ RotL64(aExpandLaneD[((aIndex + 5731U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aIngress, 56U) + RotL64(aCarry, 5U)) + (RotL64(aCross, 41U) ^ RotL64(aPrevious, 29U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterD = (aWandererG + RotL64(aCross, 19U)) + 10805654776556844351U;
            aOrbiterA = (((aWandererI + RotL64(aScatter, 5U)) + 582794182442795335U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 14U)) & S_SALT1]) + aNonceWordH;
            aOrbiterF = (((aWandererC + RotL64(aPrevious, 41U)) + RotL64(aCarry, 27U)) + 2858343650974681068U) + aNonceWordB;
            aOrbiterI = ((((aWandererJ + RotL64(aIngress, 54U)) + RotL64(aCarry, 41U)) + 8189584049022064284U) + aPhaseAOrbiterAssignSaltE[((aIndex + 18U)) & S_SALT1]) + aNonceWordL;
            aOrbiterG = ((aWandererB + RotL64(aCross, 29U)) + RotL64(aCarry, 5U)) + 1565100751996962893U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 8062028016947611891U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 8280504280578451745U;
            aOrbiterF = RotL64((aOrbiterF * 5212851648135050483U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 11326869194491655350U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 1671695656567777163U;
            aOrbiterD = RotL64((aOrbiterD * 7511554500524257921U), 5U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterG) + 2349843105293943452U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1]) + aNonceWordI;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 13015545152052004254U;
            aOrbiterA = RotL64((aOrbiterA * 1316662811685429983U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 16703354404749291869U) + aNonceWordG;
            aOrbiterG = (((aOrbiterG ^ aOrbiterA) ^ 8713231044374305801U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterG = RotL64((aOrbiterG * 9242480982197688625U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 11118401674497783533U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 14857556493734710364U) ^ aNonceWordN;
            aOrbiterI = RotL64((aOrbiterI * 3452566050389715195U), 37U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterD, 47U);
            aIngress = aIngress + (RotL64(aOrbiterG, 21U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterI, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aScatter, 5U) + aOrbiterG) + RotL64(aOrbiterD, 20U)) + aNonceWordC);
            aWandererC = aWandererC + (((((RotL64(aPrevious, 47U) + aOrbiterF) + RotL64(aOrbiterG, 29U)) + RotL64(aCarry, 53U)) + aNonceWordK) + aPhaseAWandererUpdateSaltB[((aIndex + 10U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aCross, 23U) + aOrbiterI) + RotL64(aOrbiterA, 39U)) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aIngress, 13U) + aOrbiterG) + RotL64(aOrbiterA, 53U)) + RotL64(aCarry, 13U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 56U) + aOrbiterA) + RotL64(aOrbiterD, 11U)) + aNonceWordJ);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 3U));
            aCarry = aCarry + (RotL64(aWandererB, 11U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererJ, 30U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aInvestLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_a loop 3
        // ingress from: aInvestLaneB, aExpandLaneD, aFireLaneC
        // ingress directions: aInvestLaneB forward forced, aExpandLaneD forward forced, aFireLaneC forward/backward random
        // cross from: aInvestLaneA, aExpandLaneB, aExpandLaneA
        // cross directions: aInvestLaneA backward forced, aExpandLaneB backward forced, aExpandLaneA backward/forward random
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneB[((aIndex + 13583U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneD[((aIndex + 12924U)) & S_BLOCK1], 12U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 14947U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 16373U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 13355U)) & S_BLOCK1], 26U));
            aCross ^= RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 16323U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aPrevious, 19U) ^ RotL64(aCross, 36U)) + (RotL64(aCarry, 51U) + RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterA = ((aWandererC + RotL64(aScatter, 19U)) + 18255347001097480328U) + aNonceWordB;
            aOrbiterB = ((((aWandererH + RotL64(aIngress, 27U)) + RotL64(aCarry, 53U)) + 13679246790311505735U) + aPhaseAOrbiterAssignSaltB[((aIndex + 27U)) & S_SALT1]) + aNonceWordI;
            aOrbiterE = (((aWandererJ + RotL64(aPrevious, 58U)) + RotL64(aCarry, 3U)) + 10565839529765027116U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterD = ((aWandererI + RotL64(aCross, 43U)) + RotL64(aCarry, 37U)) + 14327172566224769901U;
            aOrbiterH = ((aWandererK + RotL64(aScatter, 3U)) + 16239024612038195174U) + aNonceWordO;
            //
            aOrbiterA = (((aOrbiterA + aOrbiterB) + 13800012174212131890U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1]) + aNonceWordM;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 13900288860157577583U;
            aOrbiterE = RotL64((aOrbiterE * 13177682776510523095U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 4144386119777112740U) + aNonceWordP;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 3154558262670631372U;
            aOrbiterH = RotL64((aOrbiterH * 13236911910092437063U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 7456728543137614001U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 11709519851158935384U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 7016689518570071587U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 15607438907832240304U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 9276575329661725624U;
            aOrbiterD = RotL64((aOrbiterD * 8879744070762412745U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 6459435969129449226U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 6442382118416542275U;
            aOrbiterA = RotL64((aOrbiterA * 2921027306686588233U), 57U);
            //
            aIngress = RotL64(aOrbiterB, 23U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterE, 37U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterA, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterE, 3U)) + aOrbiterD) + aNonceWordA);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 48U) + RotL64(aOrbiterB, 39U)) + aOrbiterE) + aNonceWordH);
            aWandererK = aWandererK + ((((RotL64(aCross, 27U) + aOrbiterH) + RotL64(aOrbiterE, 19U)) + RotL64(aCarry, 51U)) + aNonceWordL);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 5U) + RotL64(aOrbiterD, 11U)) + aOrbiterA) + aPhaseAWandererUpdateSaltE[((aIndex + 25U)) & S_SALT1]);
            aWandererC = aWandererC + (((((RotL64(aPrevious, 57U) + aOrbiterA) + RotL64(aOrbiterH, 28U)) + RotL64(aCarry, 27U)) + aNonceWordD) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 58U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 47U));
            aCarry = aCarry + RotL64(aWandererK, 39U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_a loop 4
        // ingress from: aOperationLaneA, aInvestLaneA, aFireLaneB
        // ingress directions: aOperationLaneA forward forced, aInvestLaneA forward forced, aFireLaneB forward/backward random
        // cross from: aInvestLaneB, aExpandLaneD, aExpandLaneC
        // cross directions: aInvestLaneB backward forced, aExpandLaneD backward forced, aExpandLaneC backward/forward random
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 16997U)) & S_BLOCK1], 35U) ^ RotL64(aInvestLaneA[((aIndex + 21502U)) & S_BLOCK1], 14U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 20104U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 19957U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 21623U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aExpandLaneC[((aIndex + 18145U)) & S_BLOCK1], 60U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCarry, 60U) + RotL64(aIngress, 47U)) + (RotL64(aPrevious, 13U) ^ RotL64(aCross, 27U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterA = (((aWandererA + RotL64(aCross, 21U)) + 5088525177670191619U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordL;
            aOrbiterF = ((aWandererE + RotL64(aPrevious, 51U)) + 9966456257813932112U) + aNonceWordB;
            aOrbiterH = ((aWandererH + RotL64(aIngress, 38U)) + RotL64(aCarry, 41U)) + 7707646574027146307U;
            aOrbiterI = ((aWandererF + RotL64(aScatter, 29U)) + RotL64(aCarry, 11U)) + 75480203757681173U;
            aOrbiterG = (((aWandererK + RotL64(aCross, 3U)) + RotL64(aCarry, 27U)) + 384659134071835163U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 3158769775373307778U) + aNonceWordM;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 17360830943513941272U;
            aOrbiterH = RotL64((aOrbiterH * 9986023786908098621U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 5317278822721604586U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 1371427105215954781U;
            aOrbiterG = RotL64((aOrbiterG * 10956603063464438611U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 3162710551223553423U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 5332921933853550756U;
            aOrbiterF = RotL64((aOrbiterF * 11709546145149357887U), 11U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterG) + 10572462410297815854U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterA = (((aOrbiterA ^ aOrbiterI) ^ 10234389605554817892U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterA = RotL64((aOrbiterA * 2130374833440291193U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 13421365517991380605U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 10186643614984034083U) ^ aNonceWordD;
            aOrbiterI = RotL64((aOrbiterI * 8554471709467808453U), 57U);
            //
            aIngress = RotL64(aOrbiterA, 3U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 27U));
            aIngress = aIngress + RotL64(aOrbiterI, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aIngress, 56U) + RotL64(aOrbiterG, 54U)) + aOrbiterI) + aPhaseAWandererUpdateSaltD[((aIndex + 14U)) & S_SALT1]);
            aWandererK = aWandererK + (((((RotL64(aCross, 13U) + aOrbiterF) + RotL64(aOrbiterH, 13U)) + RotL64(aCarry, 47U)) + aNonceWordE) + aPhaseAWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 23U) + aOrbiterG) + RotL64(aOrbiterA, 21U)) + aNonceWordP);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 39U) + RotL64(aOrbiterI, 41U)) + aOrbiterH) + RotL64(aCarry, 29U)) + aNonceWordA);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 3U) + aOrbiterF) + RotL64(aOrbiterA, 5U)) + aNonceWordH);
            //
            aCarry = aCarry + (RotL64(aWandererK, 29U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererA, 47U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererF, 19U);
            aCarry = aCarry + RotL64(aIngress, 10U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 23004U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneA[((aIndex + 23673U)) & S_BLOCK1], 56U));
            aIngress ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 22718U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 23243U)) & S_BLOCK1], 24U) ^ RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 24122U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 23562U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCross, 38U) ^ RotL64(aIngress, 19U)) + (RotL64(aCarry, 3U) + RotL64(aPrevious, 51U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterB = ((aWandererF + RotL64(aScatter, 37U)) + RotL64(aCarry, 3U)) + 18302975933754610273U;
            aOrbiterK = (aWandererA + RotL64(aIngress, 21U)) + 16736972646771456082U;
            aOrbiterG = ((((aWandererE + RotL64(aCross, 3U)) + RotL64(aCarry, 35U)) + 17389406266488137442U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordI;
            aOrbiterD = (((aWandererK + RotL64(aPrevious, 29U)) + RotL64(aCarry, 21U)) + 5252511566486165539U) + aNonceWordJ;
            aOrbiterF = ((aWandererI + RotL64(aCross, 50U)) + 5730715427422747640U) + aPhaseAOrbiterAssignSaltE[((aIndex + 25U)) & S_SALT1];
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 6412695646456045825U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 9539701605708994494U;
            aOrbiterG = RotL64((aOrbiterG * 6511935168278632407U), 27U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterB) + 18355107116412945722U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordF;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 11735742491750132942U) ^ aNonceWordP;
            aOrbiterF = RotL64((aOrbiterF * 18129835093627763685U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 12363819388562658842U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 5861430292304371543U;
            aOrbiterD = RotL64((aOrbiterD * 12989055611235382695U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 15027487084595017708U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterF) ^ 7012850020745791926U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterB = RotL64((aOrbiterB * 15952928839355613939U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 11904871669287886120U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 11199760114477343208U;
            aOrbiterK = RotL64((aOrbiterK * 7156374911847525867U), 3U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterK, 3U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 26U));
            aIngress = aIngress + RotL64(aOrbiterD, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aPrevious, 3U) + aOrbiterK) + RotL64(aOrbiterF, 3U)) + RotL64(aCarry, 13U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 57U) + aOrbiterK) + RotL64(aOrbiterB, 35U)) + aNonceWordO);
            aWandererF = aWandererF + ((((RotL64(aCross, 37U) + aOrbiterG) + RotL64(aOrbiterD, 44U)) + aNonceWordA) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 14U) + aOrbiterF) + RotL64(aOrbiterG, 19U)) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aScatter, 23U) + aOrbiterD) + RotL64(aOrbiterB, 57U)) + RotL64(aCarry, 53U)) + aNonceWordL);
            //
            aCarry = aCarry + (RotL64(aWandererE, 27U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererK, 11U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererF, 37U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 30580U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneA[((aIndex + 27597U)) & S_BLOCK1], 36U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 27464U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31985U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 28394U)) & S_BLOCK1], 38U));
            aCross ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 32410U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aIngress, 53U) + RotL64(aCarry, 27U)) ^ (RotL64(aPrevious, 3U) + RotL64(aCross, 40U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterI = ((aWandererC + RotL64(aPrevious, 23U)) + 12122689833405846292U) + aNonceWordN;
            aOrbiterD = ((aWandererA + RotL64(aScatter, 41U)) + RotL64(aCarry, 23U)) + 9640400270962766788U;
            aOrbiterJ = ((aWandererE + RotL64(aIngress, 11U)) + 9141937998266739071U) + aNonceWordD;
            aOrbiterK = (((aWandererB + RotL64(aCross, 54U)) + RotL64(aCarry, 3U)) + 12899395770434090537U) + aPhaseAOrbiterAssignSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterG = ((((aWandererI + RotL64(aIngress, 3U)) + RotL64(aCarry, 39U)) + 13457918115408031842U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordL;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 15134784483576000943U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterI) ^ 12540961268790055438U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterJ = RotL64((aOrbiterJ * 3295706140418040089U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 6306886773092764230U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 13573343491337243121U;
            aOrbiterK = RotL64((aOrbiterK * 15893457012357368707U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 8545588657348974413U) + aNonceWordM;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 10891410570357275120U;
            aOrbiterG = RotL64((aOrbiterG * 5399310978367842841U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 2877137119767060151U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterG) ^ 9178097682386595144U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterD = RotL64((aOrbiterD * 3524486002084427513U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 15528007881855616978U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 11368419529245281435U) ^ aNonceWordJ;
            aOrbiterI = RotL64((aOrbiterI * 12433207037378339309U), 47U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterJ, 41U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 3U));
            aIngress = aIngress + RotL64(aOrbiterK, 54U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aCross, 35U) + aOrbiterJ) + RotL64(aOrbiterG, 10U)) + aNonceWordC);
            aWandererB = aWandererB ^ ((((RotL64(aIngress, 3U) + aOrbiterG) + RotL64(aOrbiterD, 19U)) + aNonceWordH) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 13U) + aOrbiterI) + RotL64(aOrbiterK, 27U)) + RotL64(aCarry, 47U)) + aNonceWordA);
            aWandererE = aWandererE ^ ((((RotL64(aScatter, 23U) + aOrbiterK) + RotL64(aOrbiterD, 51U)) + aNonceWordF) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 48U) + aOrbiterG) + RotL64(aOrbiterI, 35U)) + RotL64(aCarry, 23U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 21U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererE, 30U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererB, 5U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xC19BB7BB64210A3BULL + 0xB07995459B9D6F64ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xA48568FBEAF4E9AFULL + 0xF9AB59FFD23404A0ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x8369148547E3C2A9ULL + 0x93EA2445678DA8A0ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xACECA80F3E9C9117ULL + 0xBF4FCB959005D827ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xFE88515C06A107D9ULL + 0xB5E64569140A5C2BULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xCE87AC79F68890D3ULL + 0xDCB4C2C8ADEB2E91ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xE491B79FFB53D3D1ULL + 0xE528CAB17694A213ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xDD3CFD56DCD2BEFBULL + 0x8F153137CF97C702ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x937C2E5C6FA75EEBULL + 0xEAD127493DE24A9EULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xA5DB689514E23DD5ULL + 0xC69CC7F80B9DBD33ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x9548274921E8E1C3ULL + 0xAE8E0D73815C2C43ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xD65102030A1D7997ULL + 0xAEFFDC8DA2C633FBULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xB5595700718BAAA9ULL + 0x9B13B192784E730DULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x8BE8983C0E53F401ULL + 0xDB4A64ADA65E3419ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xB0DAA744169323F3ULL + 0xF0C0F3FA7B96DE3AULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xA257A7DD20881B69ULL + 0x80B7DB94E7D7A89AULL);
    // GSeedRunSeed_C seed_loop_b (start)
    {
        // GSeedRunSeed_C seed_loop_b lane group
        // read from: aOperationLaneA, aOperationLaneB, aExpandLaneC, aOperationLaneC, aOperationLaneD, aFireLaneA, aInvestLaneC, aExpandLaneB, aExpandLaneD, aInvestLaneD, aFireLaneD, aWorkLaneA, aExpandLaneA, aWorkLaneB, aFireLaneC, aWorkLaneC, aFireLaneB
        // write to: aInvestLaneC, aInvestLaneD, aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // seed_loop_b loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aExpandLaneC
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aExpandLaneC forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aFireLaneA
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aFireLaneA backward/forward random
        // write to: aInvestLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 442U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneB[((aIndex + 2901U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aExpandLaneC[((aIndex + 3458U)) & S_BLOCK1], 56U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 3619U)) & S_BLOCK1], 46U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 1132U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 764U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aPrevious, 21U) + RotL64(aCarry, 5U)) ^ (RotL64(aIngress, 52U) ^ RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterE = (((aWandererF + RotL64(aScatter, 18U)) + RotL64(aCarry, 19U)) + 13333509828310369865U) + aNonceWordH;
            aOrbiterG = ((aWandererG + RotL64(aCross, 47U)) + 7645352517103840797U) + aPhaseBOrbiterAssignSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterB = (aWandererK + RotL64(aPrevious, 43U)) + 5310766306660062655U;
            aOrbiterK = ((aWandererB + RotL64(aIngress, 37U)) + 5165635069832352932U) + aNonceWordP;
            aOrbiterH = ((aWandererD + RotL64(aCross, 52U)) + RotL64(aCarry, 39U)) + 15684141764734281849U;
            aOrbiterI = (((aWandererA + RotL64(aIngress, 57U)) + RotL64(aCarry, 27U)) + 3327963374225061738U) + aNonceWordM;
            aOrbiterJ = (aWandererC + RotL64(aScatter, 13U)) + 8625811794878848871U;
            aOrbiterD = (aWandererE + RotL64(aPrevious, 5U)) + 7598657468430485291U;
            aOrbiterC = (((aWandererI + RotL64(aScatter, 29U)) + 2881171216276746485U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 14U)) & S_SALT1]) + aNonceWordK;
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 10237691227222918101U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 6419254255884834497U;
            aOrbiterB = RotL64((aOrbiterB * 3816625473642865305U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 4238455444646479956U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 14936613353493061492U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 3544216916806292273U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 15324699725208372627U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 9506640480601832011U;
            aOrbiterE = RotL64((aOrbiterE * 12819564111348390227U), 5U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 3709149613660215641U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 1724290199312754307U) ^ aNonceWordC;
            aOrbiterK = RotL64((aOrbiterK * 12597580418257897965U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 13191172833570139194U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 3686087945377837886U;
            aOrbiterJ = RotL64((aOrbiterJ * 10883609557429936283U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 10418330386245397022U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 5383531313632347245U;
            aOrbiterG = RotL64((aOrbiterG * 2987755379396160073U), 39U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 7414716553072652212U) + aNonceWordE;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 11301761123966206201U) ^ aNonceWordL;
            aOrbiterH = RotL64((aOrbiterH * 1546727321088592187U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 8570229732236388847U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 8773754460060264773U;
            aOrbiterC = RotL64((aOrbiterC * 3251360788932563495U), 57U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterI) + 13636929800504199371U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1]) + aNonceWordD;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 5486599841558573720U;
            aOrbiterD = RotL64((aOrbiterD * 2867914211589815153U), 11U);
            //
            aIngress = RotL64(aOrbiterC, 47U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterE, 60U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterK, 51U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterB, 5U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterH, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aCross, 60U) + RotL64(aOrbiterI, 26U)) + aOrbiterJ);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 35U) + aOrbiterJ) + RotL64(aOrbiterG, 51U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 23U) + aOrbiterK) + RotL64(aOrbiterJ, 35U)) + aNonceWordI);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 19U) + aOrbiterE) + RotL64(aOrbiterG, 11U)) + aPhaseBWandererUpdateSaltF[((aIndex + 11U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 6U) + aOrbiterH) + RotL64(aOrbiterB, 47U)) + RotL64(aCarry, 53U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 53U) + aOrbiterD) + RotL64(aOrbiterE, 41U));
            aWandererD = aWandererD + ((((RotL64(aPrevious, 13U) + RotL64(aOrbiterH, 5U)) + aOrbiterG) + RotL64(aCarry, 39U)) + aPhaseBWandererUpdateSaltC[((aIndex + 5U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterI, 60U)) + aOrbiterB);
            aWandererF = aWandererF + (((RotL64(aPrevious, 27U) + RotL64(aOrbiterC, 19U)) + aOrbiterB) + aNonceWordA);
            //
            aCarry = aCarry + (RotL64(aWandererD, 13U) ^ aWandererF);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 27U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 36U));
            aCarry = aCarry + (RotL64(aWandererC, 53U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererG, 39U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aInvestLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_b loop 2
        // ingress from: aInvestLaneC, aOperationLaneC, aOperationLaneD, aExpandLaneB
        // ingress directions: aInvestLaneC forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aExpandLaneB forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aExpandLaneD
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aExpandLaneD backward/forward random
        // write to: aInvestLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneC[((aIndex + 9983U)) & S_BLOCK1], 14U) ^ RotL64(aOperationLaneC[((aIndex + 10904U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 6967U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 9104U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 9932U)) & S_BLOCK1], 50U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 7485U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aExpandLaneD[((aIndex + 5774U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCross, 40U) + RotL64(aIngress, 53U)) + (RotL64(aCarry, 27U) ^ RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterG = ((aWandererF + RotL64(aScatter, 23U)) + 2558105147674438050U) + aPhaseBOrbiterAssignSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = ((aWandererD + RotL64(aCross, 11U)) + RotL64(aCarry, 29U)) + 15856662514774702561U;
            aOrbiterD = (aWandererJ + RotL64(aPrevious, 39U)) + 13346869226246584582U;
            aOrbiterA = (((aWandererG + RotL64(aIngress, 18U)) + RotL64(aCarry, 11U)) + 7632111846116243973U) + aNonceWordK;
            aOrbiterF = ((aWandererK + RotL64(aScatter, 57U)) + RotL64(aCarry, 53U)) + 2102101361626976279U;
            aOrbiterI = (aWandererI + RotL64(aCross, 29U)) + 5605968705067851563U;
            aOrbiterJ = ((aWandererE + RotL64(aPrevious, 51U)) + 6842483186584326681U) + aNonceWordL;
            aOrbiterE = ((aWandererA + RotL64(aIngress, 5U)) + 5559797213819425064U) + aNonceWordJ;
            aOrbiterH = (((aWandererB + RotL64(aCross, 46U)) + 12422313931331576759U) + aPhaseBOrbiterAssignSaltC[((aIndex + 9U)) & S_SALT1]) + aNonceWordF;
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 2751024420047872601U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 11031320239359798610U;
            aOrbiterD = RotL64((aOrbiterD * 8607639453141148025U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 14366375309473793217U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 11971479429768505316U;
            aOrbiterG = RotL64((aOrbiterG * 10063001532313098203U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 3947595951884469542U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 17882767922372770896U;
            aOrbiterA = RotL64((aOrbiterA * 3361906348965810211U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 513871456983509223U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 5951677013597794294U;
            aOrbiterK = RotL64((aOrbiterK * 8508629569649935293U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 437626309049021931U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 466674061172005705U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 1310502572084891157U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 12362602809233133718U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 10525852878882195702U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 17755022180514914325U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 17927000184308583095U) + aNonceWordB;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterH) ^ 566723721423470052U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterJ = RotL64((aOrbiterJ * 17710534355278632573U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 9504585484034413577U) + aNonceWordP;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 4614306037721859929U;
            aOrbiterF = RotL64((aOrbiterF * 170807293799483539U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 1463218357720031588U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 4036696102163560633U;
            aOrbiterH = RotL64((aOrbiterH * 15389914226155130065U), 19U);
            //
            aIngress = RotL64(aOrbiterG, 39U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 53U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 23U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 35U));
            aIngress = aIngress + RotL64(aOrbiterH, 26U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((((RotL64(aPrevious, 43U) + RotL64(aOrbiterA, 22U)) + aOrbiterH) + RotL64(aCarry, 39U)) + aNonceWordC) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 5U) + aOrbiterE) + RotL64(aOrbiterJ, 29U));
            aWandererK = aWandererK + (((RotL64(aIngress, 39U) + aOrbiterE) + RotL64(aOrbiterD, 35U)) + RotL64(aCarry, 27U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 12U) + RotL64(aOrbiterJ, 47U)) + aOrbiterK);
            aWandererD = aWandererD + ((RotL64(aIngress, 57U) + RotL64(aOrbiterI, 13U)) + aOrbiterK);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterA, 41U)) + aOrbiterG);
            aWandererA = aWandererA + ((RotL64(aPrevious, 47U) + aOrbiterI) + RotL64(aOrbiterE, 51U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterJ, 57U)) + aOrbiterF) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aScatter, 18U) + RotL64(aOrbiterK, 18U)) + aOrbiterA) + aNonceWordD);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 27U));
            aCarry = aCarry + (RotL64(aWandererG, 43U) ^ aWandererJ);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 40U));
            aCarry = aCarry + (RotL64(aWandererK, 47U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererB, 13U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = (RotL64(aInvestLaneD[((aIndex + 13881U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneA[((aIndex + 11624U)) & S_BLOCK1], 38U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 11809U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 11585U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 11157U)) & S_BLOCK1], 52U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCross, 41U) + RotL64(aIngress, 26U)) ^ (RotL64(aCarry, 13U) ^ RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterC = ((aWandererJ + RotL64(aCross, 47U)) + 4384716820085860551U) + aNonceWordB;
            aOrbiterF = (((aWandererG + RotL64(aScatter, 34U)) + RotL64(aCarry, 57U)) + 9715780315942116888U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterJ = ((aWandererI + RotL64(aPrevious, 29U)) + RotL64(aCarry, 5U)) + 15963520052789178632U;
            aOrbiterD = ((aWandererF + RotL64(aIngress, 23U)) + 14346700690686392938U) + aNonceWordC;
            aOrbiterB = ((aWandererK + RotL64(aPrevious, 51U)) + 6005518012489966643U) + aNonceWordM;
            aOrbiterK = ((aWandererH + RotL64(aIngress, 6U)) + RotL64(aCarry, 47U)) + 2506732930310252119U;
            aOrbiterG = (((aWandererD + RotL64(aCross, 19U)) + 16782163084851775826U) + aPhaseBOrbiterAssignSaltD[((aIndex + 15U)) & S_SALT1]) + aNonceWordE;
            aOrbiterA = (aWandererC + RotL64(aScatter, 11U)) + 823673076571076303U;
            aOrbiterI = (aWandererA + RotL64(aIngress, 39U)) + 1634084509064077736U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 1288134975466877686U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 2998220403162908444U;
            aOrbiterJ = RotL64((aOrbiterJ * 4321412662318298283U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 220430672180734911U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 10223923547068528867U;
            aOrbiterB = RotL64((aOrbiterB * 12577370238343872139U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 11696469696177647608U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 6545430420379636963U;
            aOrbiterG = RotL64((aOrbiterG * 8387163146257553773U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 79691451831797107U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 8971444023498649419U;
            aOrbiterC = RotL64((aOrbiterC * 7148919880477390009U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 5624403902454498793U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 9468064161002030997U;
            aOrbiterA = RotL64((aOrbiterA * 8243560528100864595U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 4619361544913629805U) + aNonceWordK;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 12682446273369750704U;
            aOrbiterD = RotL64((aOrbiterD * 10879074713156075641U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 8728730962617599223U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 9099675924074253030U;
            aOrbiterF = RotL64((aOrbiterF * 5525644236954497523U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 3298303921318288541U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 5953276499411658358U) ^ aNonceWordN;
            aOrbiterK = RotL64((aOrbiterK * 10565471305001292693U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 6725769507592688539U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 1057277456510215817U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 8269412198279297075U), 3U);
            //
            aIngress = RotL64(aOrbiterC, 6U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 37U));
            aIngress = aIngress + (RotL64(aOrbiterA, 11U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterB, 23U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterF, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aScatter, 41U) + RotL64(aOrbiterC, 30U)) + aOrbiterG);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 58U) + aOrbiterB) + RotL64(aOrbiterD, 57U));
            aWandererI = aWandererI + (((RotL64(aCross, 3U) + aOrbiterA) + RotL64(aOrbiterK, 11U)) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 37U) + RotL64(aOrbiterB, 5U)) + aOrbiterJ) + aNonceWordL);
            aWandererK = aWandererK + ((RotL64(aCross, 21U) + aOrbiterB) + RotL64(aOrbiterK, 41U));
            aWandererA = aWandererA ^ ((((RotL64(aIngress, 30U) + aOrbiterC) + RotL64(aOrbiterF, 48U)) + aNonceWordH) + aPhaseBWandererUpdateSaltB[((aIndex + 17U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aScatter, 47U) + RotL64(aOrbiterB, 53U)) + aOrbiterF) + RotL64(aCarry, 27U)) + aNonceWordJ);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 13U) + RotL64(aOrbiterA, 37U)) + aOrbiterI) + aNonceWordI);
            aWandererJ = aWandererJ + (((RotL64(aCross, 51U) + aOrbiterK) + RotL64(aOrbiterG, 23U)) + RotL64(aCarry, 19U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 56U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererJ, 5U) ^ aWandererH);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 47U));
            aCarry = aCarry + (RotL64(aWandererG, 37U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererA, 23U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 16761U)) & S_BLOCK1], 19U) ^ RotL64(aInvestLaneC[((aIndex + 18903U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 21801U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 17336U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneD[((aIndex + 19085U)) & S_BLOCK1], 34U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCross, 3U) ^ RotL64(aIngress, 54U)) + (RotL64(aPrevious, 41U) + RotL64(aCarry, 19U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterB = (((aWandererG + RotL64(aPrevious, 10U)) + 18144572925667544139U) + aPhaseBOrbiterAssignSaltF[((aIndex + 17U)) & S_SALT1]) + aNonceWordM;
            aOrbiterD = (aWandererB + RotL64(aScatter, 3U)) + 5659758077574059728U;
            aOrbiterA = ((aWandererE + RotL64(aCross, 51U)) + RotL64(aCarry, 5U)) + 6343330616999166392U;
            aOrbiterC = ((aWandererJ + RotL64(aIngress, 41U)) + RotL64(aCarry, 13U)) + 17754639838410839447U;
            aOrbiterE = (aWandererH + RotL64(aCross, 47U)) + 9451843819849581729U;
            aOrbiterJ = (aWandererC + RotL64(aIngress, 27U)) + 7957854457197462212U;
            aOrbiterH = ((((aWandererF + RotL64(aPrevious, 14U)) + RotL64(aCarry, 39U)) + 1461994799722205010U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordN;
            aOrbiterK = (aWandererD + RotL64(aScatter, 35U)) + 18002214276252170177U;
            aOrbiterF = (aWandererA + RotL64(aCross, 23U)) + 14689869073147027164U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 3978104368003440293U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 8512135845221335386U;
            aOrbiterA = RotL64((aOrbiterA * 10506667163729414667U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 1477533446382953439U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 2166717790929947990U;
            aOrbiterD = RotL64((aOrbiterD * 6538884492418324461U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 8082437060686606995U) + aNonceWordK;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 4363687722464700362U;
            aOrbiterE = RotL64((aOrbiterE * 7199165810993478887U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 15782763348014924206U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 8572509150015960728U;
            aOrbiterF = RotL64((aOrbiterF * 3340528604891897779U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 12248271773316742521U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 9602078627638561949U) ^ aNonceWordB;
            aOrbiterJ = RotL64((aOrbiterJ * 1860631869877427405U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 17244849374768558859U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 1030743048280579012U;
            aOrbiterC = RotL64((aOrbiterC * 10858949914285817051U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 17722342363541914280U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = (((aOrbiterK ^ aOrbiterE) ^ 15667504059789880034U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterK = RotL64((aOrbiterK * 15872269872168533709U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 12645332941998550794U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 9938135244509986497U;
            aOrbiterB = RotL64((aOrbiterB * 16548185968987392957U), 37U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 4024609904162105979U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 6732064218696157303U;
            aOrbiterH = RotL64((aOrbiterH * 3815409766145891393U), 3U);
            //
            aIngress = RotL64(aOrbiterF, 5U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterA, 13U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterH, 39U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 27U));
            aIngress = aIngress + RotL64(aOrbiterE, 18U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterC, 34U)) + aOrbiterB);
            aWandererG = aWandererG + (((RotL64(aCross, 39U) + aOrbiterK) + RotL64(aOrbiterB, 27U)) + RotL64(aCarry, 3U));
            aWandererD = aWandererD ^ ((((RotL64(aScatter, 35U) + aOrbiterC) + RotL64(aOrbiterF, 57U)) + aNonceWordO) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aIngress, 54U) + RotL64(aOrbiterH, 21U)) + aOrbiterF);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 5U) + RotL64(aOrbiterJ, 51U)) + aOrbiterE) + aNonceWordJ);
            aWandererE = aWandererE + ((RotL64(aCross, 19U) + aOrbiterB) + RotL64(aOrbiterA, 4U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 29U) + aOrbiterK) + RotL64(aOrbiterD, 39U)) + aPhaseBWandererUpdateSaltC[((aIndex + 15U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aIngress, 24U) + aOrbiterH) + RotL64(aOrbiterE, 11U)) + RotL64(aCarry, 29U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterD, 47U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererA, 29U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererD, 51U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererE, 19U) ^ aWandererH);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 56U));
            aCarry = aCarry + RotL64(aWandererC, 35U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_b loop 5
        // ingress from: aWorkLaneB, aInvestLaneD, aFireLaneC
        // ingress directions: aWorkLaneB forward forced, aInvestLaneD forward forced, aFireLaneC forward/backward random
        // cross from: aWorkLaneA, aInvestLaneC
        // cross directions: aWorkLaneA backward forced, aInvestLaneC backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 22108U)) & S_BLOCK1], 21U) ^ RotL64(aInvestLaneD[((aIndex + 24682U)) & S_BLOCK1], 56U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 23885U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 27167U)) & S_BLOCK1], 47U) ^ RotL64(aInvestLaneC[((aIndex + 24838U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aPrevious, 21U)) + (RotL64(aIngress, 56U) ^ RotL64(aCarry, 35U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterE = ((aWandererE + RotL64(aPrevious, 27U)) + 10915618884692072446U) + aNonceWordF;
            aOrbiterD = ((aWandererK + RotL64(aScatter, 3U)) + RotL64(aCarry, 53U)) + 12634922308499254909U;
            aOrbiterC = ((aWandererJ + RotL64(aIngress, 37U)) + 6533934734564499389U) + aNonceWordJ;
            aOrbiterH = (aWandererC + RotL64(aCross, 18U)) + 6744203303756105181U;
            aOrbiterI = (((aWandererF + RotL64(aPrevious, 51U)) + RotL64(aCarry, 13U)) + 13086782386652045658U) + aPhaseBOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = ((aWandererG + RotL64(aScatter, 41U)) + 5693840533331397822U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = (aWandererB + RotL64(aIngress, 13U)) + 1803663542535024611U;
            aOrbiterJ = ((aWandererA + RotL64(aCross, 22U)) + RotL64(aCarry, 37U)) + 3597219300593287708U;
            aOrbiterB = (aWandererD + RotL64(aIngress, 47U)) + 1429753448204448904U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 17229017825587322715U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 1137574712801062932U;
            aOrbiterC = RotL64((aOrbiterC * 3645832160939819415U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 2401991077004083378U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 1332473247826139292U;
            aOrbiterI = RotL64((aOrbiterI * 15029831858261506447U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 11730946340796899885U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 15319163439700390962U;
            aOrbiterD = RotL64((aOrbiterD * 1349242001887975499U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 4744141870145159917U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterH) ^ 6067132201862688684U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterJ = RotL64((aOrbiterJ * 6046100687757836027U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 14991509179286371800U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 4342608825699398682U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 10240526103933275875U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 3727521409410742075U) + aNonceWordI;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 3302027219498304367U;
            aOrbiterB = RotL64((aOrbiterB * 12153634588200479559U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 6039539483340398858U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 2902581519976937051U;
            aOrbiterE = RotL64((aOrbiterE * 2057584328877854239U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 12332784713738947242U) + aNonceWordA;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 13761272577223712786U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 14930145045480030821U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 2947946397617043735U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 11107014023853644521U) ^ aNonceWordL;
            aOrbiterK = RotL64((aOrbiterK * 15030903626191481831U), 37U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterJ, 5U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 54U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 23U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 29U));
            aIngress = aIngress + RotL64(aOrbiterH, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aScatter, 57U) + RotL64(aOrbiterE, 27U)) + aOrbiterD);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 42U) + RotL64(aOrbiterC, 53U)) + aOrbiterB);
            aWandererE = aWandererE + ((((RotL64(aCross, 29U) + aOrbiterA) + RotL64(aOrbiterK, 12U)) + aNonceWordE) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 3U) + aOrbiterJ) + RotL64(aOrbiterD, 57U));
            aWandererG = aWandererG + ((RotL64(aPrevious, 53U) + aOrbiterE) + RotL64(aOrbiterH, 5U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 46U) + RotL64(aOrbiterI, 37U)) + aOrbiterJ);
            aWandererC = aWandererC + ((((RotL64(aCross, 35U) + aOrbiterI) + RotL64(aOrbiterA, 46U)) + RotL64(aCarry, 37U)) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 19U) + aOrbiterC) + RotL64(aOrbiterK, 21U));
            aWandererB = aWandererB + ((((RotL64(aIngress, 23U) + aOrbiterK) + RotL64(aOrbiterB, 41U)) + RotL64(aCarry, 27U)) + aNonceWordH);
            //
            aCarry = aCarry + (RotL64(aWandererD, 14U) ^ aWandererG);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 23U));
            aCarry = aCarry + (RotL64(aWandererE, 11U) ^ aWandererK);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 39U));
            aCarry = aCarry + RotL64(aWandererF, 53U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 31009U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneA[((aIndex + 31762U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 30239U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordD));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 32007U)) & S_BLOCK1], 4U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 29519U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCarry, 57U) ^ RotL64(aPrevious, 39U)) ^ (RotL64(aIngress, 5U) + RotL64(aCross, 24U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterD = (aWandererC + RotL64(aPrevious, 35U)) + 826930775230515406U;
            aOrbiterI = ((aWandererI + RotL64(aCross, 14U)) + 5137814617363250861U) + aNonceWordM;
            aOrbiterA = (aWandererE + RotL64(aScatter, 39U)) + 14761561947426681616U;
            aOrbiterC = ((aWandererG + RotL64(aIngress, 27U)) + 12773023438753662590U) + aNonceWordC;
            aOrbiterK = (aWandererJ + RotL64(aPrevious, 23U)) + 7331345852207096322U;
            aOrbiterE = ((aWandererH + RotL64(aScatter, 47U)) + 3899381212671247460U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterB = (((aWandererK + RotL64(aIngress, 52U)) + RotL64(aCarry, 57U)) + 10072004147620068599U) + aPhaseBOrbiterAssignSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = ((aWandererF + RotL64(aCross, 19U)) + RotL64(aCarry, 11U)) + 3424585039401897560U;
            aOrbiterH = ((aWandererA + RotL64(aScatter, 3U)) + RotL64(aCarry, 35U)) + 8246760141625966321U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 3655992860610853290U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 11154618022505863898U;
            aOrbiterA = RotL64((aOrbiterA * 4791494171286145231U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 15629361991059709973U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 10842068502278489664U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 17223002513104960799U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 5571312349016336686U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterE) ^ 589313823745748879U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterC = RotL64((aOrbiterC * 1356685926549786027U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 13633457935771935260U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 12684602052812183096U) ^ aNonceWordA;
            aOrbiterD = RotL64((aOrbiterD * 4689206269919806711U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 5711307583717354204U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 7181854170553728211U;
            aOrbiterF = RotL64((aOrbiterF * 9835601115561325911U), 57U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterK) + 1884620014396115821U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1]) + aNonceWordL;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 1471516373272364262U;
            aOrbiterE = RotL64((aOrbiterE * 5126319375714848029U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 742739371092077733U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 8075893317715227838U;
            aOrbiterH = RotL64((aOrbiterH * 11208274111743259795U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 8179547722249281263U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 15305282712174742323U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7951986906055462929U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 1430543231751281079U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 14585341768267283387U;
            aOrbiterB = RotL64((aOrbiterB * 313213844964269133U), 35U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterI, 35U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 53U));
            aIngress = aIngress + (RotL64(aOrbiterK, 44U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterB, 47U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterA, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aScatter, 42U) + aOrbiterK) + RotL64(aOrbiterH, 27U)) + aNonceWordB);
            aWandererA = aWandererA + (((RotL64(aIngress, 51U) + RotL64(aOrbiterB, 5U)) + aOrbiterD) + aNonceWordO);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 5U) + aOrbiterA) + RotL64(aOrbiterF, 52U));
            aWandererG = aWandererG + (((RotL64(aCross, 13U) + RotL64(aOrbiterI, 19U)) + aOrbiterK) + aPhaseBWandererUpdateSaltB[((aIndex + 15U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((((RotL64(aScatter, 23U) + RotL64(aOrbiterC, 57U)) + aOrbiterB) + aNonceWordP) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 35U) + RotL64(aOrbiterK, 39U)) + aOrbiterB) + RotL64(aCarry, 21U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 47U) + aOrbiterH) + RotL64(aOrbiterD, 13U)) + aNonceWordG);
            aWandererH = aWandererH + (((RotL64(aPrevious, 30U) + aOrbiterE) + RotL64(aOrbiterK, 47U)) + RotL64(aCarry, 3U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 57U) + aOrbiterA) + RotL64(aOrbiterB, 34U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 23U) ^ aWandererC);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 28U));
            aCarry = aCarry + (RotL64(aWandererK, 43U) ^ aWandererG);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 35U));
            aCarry = aCarry + RotL64(aWandererE, 13U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xB2EFE7E052895C33ULL + 0xE94195E702AFDF6BULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xEB5EB52830F15B91ULL + 0x9F560C5DEB27200EULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x9DF2395641E8D723ULL + 0xAD967FE8C5AD7B92ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xB7E5D730FF4AF011ULL + 0x82097D2CEC3D1153ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x879B2D22146C2147ULL + 0xE7FE3A6D859B08B7ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x8A7104AC4FB7A755ULL + 0xA154F6CE5E5D388EULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xCFE8628A124CDF69ULL + 0xE9E43FF22417FB98ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xBB4DA71954112F05ULL + 0xE559863516903C93ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xC45380D46F94F055ULL + 0x906FCD3C9B6BD277ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xBBC0D4998829EB65ULL + 0x9041A8C617456672ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xFC06A65EC0864C63ULL + 0xB8CD67CA5917BB61ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x935991F41712F7B1ULL + 0xB00D47B3D4E2173EULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0x981F6583952A81E3ULL + 0xE707A25295D41120ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0x83FB71F962D3B681ULL + 0xB6A821B268A8D18FULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xCC7F7FF43EFE2F61ULL + 0xAB3717CA2569AF68ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xCFAC2DBDEEFA725BULL + 0xCE7A107F7782DE02ULL);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 1693U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneB[((aIndex + 2688U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 2160U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 1687U)) & S_BLOCK1], 50U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 5007U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 5428U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aIngress, 36U) + RotL64(aCross, 57U)) ^ (RotL64(aPrevious, 21U) + RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterH = ((aWandererI + RotL64(aPrevious, 35U)) + RotL64(aCarry, 5U)) + 13687218104610230596U;
            aOrbiterB = ((aWandererB + RotL64(aIngress, 41U)) + RotL64(aCarry, 37U)) + 6841550124960692709U;
            aOrbiterG = ((aWandererA + RotL64(aCross, 18U)) + 17418968668458764131U) + aNonceWordB;
            aOrbiterE = (aWandererJ + RotL64(aScatter, 5U)) + 8303537912696948204U;
            aOrbiterK = ((aWandererG + RotL64(aPrevious, 29U)) + 12376614417285936537U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterJ = (((aWandererH + RotL64(aCross, 51U)) + 14215749063579232654U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordF;
            aOrbiterI = ((aWandererK + RotL64(aScatter, 57U)) + RotL64(aCarry, 21U)) + 4111736931433665347U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 11250375934571631522U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 5367367837773331275U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7262723007545807179U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 15514089192382674434U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 1475991716685034960U) ^ aNonceWordK;
            aOrbiterH = RotL64((aOrbiterH * 17720681295551650891U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 5531622777788629748U) + aNonceWordP;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 8363822215908303335U;
            aOrbiterB = RotL64((aOrbiterB * 17850203366840994883U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 3741256932685720414U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 11634667238062155772U;
            aOrbiterI = RotL64((aOrbiterI * 15925089729784547403U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 18180546911210417155U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 5123234656838556335U;
            aOrbiterJ = RotL64((aOrbiterJ * 15362857462853398025U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 11215734271189250284U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 16863747802158398092U;
            aOrbiterK = RotL64((aOrbiterK * 1828035970246160023U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 9859050606636646323U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 9331300036643654675U;
            aOrbiterE = RotL64((aOrbiterE * 2502263410556166281U), 35U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterI, 11U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 41U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 5U));
            aIngress = aIngress + RotL64(aOrbiterJ, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aScatter, 3U) + aOrbiterB) + RotL64(aOrbiterH, 35U));
            aWandererI = aWandererI + (((((RotL64(aPrevious, 13U) + RotL64(aOrbiterG, 14U)) + aOrbiterK) + RotL64(aCarry, 27U)) + aNonceWordA) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 27U) + aOrbiterK) + RotL64(aOrbiterJ, 51U)) + aNonceWordD);
            aWandererH = aWandererH + ((RotL64(aIngress, 47U) + aOrbiterE) + RotL64(aOrbiterH, 3U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 54U) + aOrbiterK) + RotL64(aOrbiterE, 57U)) + aNonceWordC);
            aWandererG = aWandererG + ((((RotL64(aCross, 39U) + RotL64(aOrbiterH, 29U)) + aOrbiterI) + RotL64(aCarry, 13U)) + aPhaseDWandererUpdateSaltD[((aIndex + 5U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 21U) + aOrbiterB) + RotL64(aOrbiterE, 21U)) + aNonceWordJ);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 54U));
            aCarry = aCarry + (RotL64(aWandererJ, 23U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererG, 27U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererI, 39U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aSnowLaneA[((aIndex + 7231U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneC[((aIndex + 6721U)) & S_BLOCK1], 4U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 9123U)) & S_BLOCK1], 13U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 8245U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 10178U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 7499U)) & S_BLOCK1], 10U));
            aCross ^= RotL64(aInvestLaneD[((aIndex + 6564U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCross, 41U) ^ RotL64(aIngress, 13U)) ^ (RotL64(aCarry, 28U) + RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterK = ((aWandererI + RotL64(aCross, 57U)) + 6381335981879993247U) + aNonceWordJ;
            aOrbiterC = ((aWandererJ + RotL64(aPrevious, 37U)) + 15595429101600023172U) + aNonceWordI;
            aOrbiterJ = (((aWandererB + RotL64(aIngress, 29U)) + RotL64(aCarry, 39U)) + 5449234297249826461U) + aNonceWordF;
            aOrbiterB = ((aWandererH + RotL64(aScatter, 44U)) + RotL64(aCarry, 51U)) + 11213734849329731168U;
            aOrbiterF = (aWandererG + RotL64(aIngress, 21U)) + 16438473952464514248U;
            aOrbiterD = (((aWandererE + RotL64(aCross, 5U)) + 7357872882115186976U) + aPhaseDOrbiterAssignSaltE[((aIndex + 3U)) & S_SALT1]) + aNonceWordN;
            aOrbiterG = (((aWandererD + RotL64(aPrevious, 51U)) + RotL64(aCarry, 21U)) + 394402075160738643U) + aPhaseDOrbiterAssignSaltA[((aIndex + 5U)) & S_SALT1];
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 11112941985410283532U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 14955125011182736212U;
            aOrbiterJ = RotL64((aOrbiterJ * 10711684773326395603U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 14770727009821304070U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 11286366598129204910U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 15884310771003021989U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 7358400908565425780U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 15635109923749114761U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12415152149408700329U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 13826842523738623579U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 1072811298828325231U) ^ aNonceWordE;
            aOrbiterD = RotL64((aOrbiterD * 9662800288646215083U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 4017334196009350776U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 8812213572751410831U) ^ aNonceWordP;
            aOrbiterB = RotL64((aOrbiterB * 12744171921566782795U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 6723457786170634403U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 9785583533999417673U) ^ aNonceWordG;
            aOrbiterC = RotL64((aOrbiterC * 7776915427605471097U), 13U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterJ) + 10265132640322153964U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordC;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 8435670887514808087U;
            aOrbiterF = RotL64((aOrbiterF * 2706263045620662131U), 43U);
            //
            aIngress = RotL64(aOrbiterG, 53U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterK, 11U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 39U));
            aIngress = aIngress + RotL64(aOrbiterB, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aIngress, 13U) + aOrbiterJ) + RotL64(aOrbiterK, 50U)) + aNonceWordB);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 51U) + aOrbiterD) + RotL64(aOrbiterK, 35U));
            aWandererD = aWandererD + ((((RotL64(aCross, 29U) + aOrbiterG) + RotL64(aOrbiterJ, 3U)) + RotL64(aCarry, 35U)) + aNonceWordK);
            aWandererG = aWandererG ^ ((((RotL64(aPrevious, 19U) + RotL64(aOrbiterG, 21U)) + aOrbiterF) + aNonceWordO) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aIngress, 4U) + aOrbiterD) + RotL64(aOrbiterF, 11U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 57U) + aOrbiterB) + RotL64(aOrbiterC, 27U)) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 43U) + RotL64(aOrbiterB, 43U)) + aOrbiterK) + RotL64(aCarry, 47U)) + aNonceWordM);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 35U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 51U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 28U));
            aCarry = aCarry + RotL64(aWandererI, 21U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aSnowLaneB[((aIndex + 12785U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneA[((aIndex + 13953U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 13794U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordE));
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 12933U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 14664U)) & S_BLOCK1], 22U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aPrevious, 53U) ^ RotL64(aCross, 23U)) + (RotL64(aCarry, 5U) ^ RotL64(aIngress, 36U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterD = (aWandererC + RotL64(aScatter, 27U)) + 826930775230515406U;
            aOrbiterF = ((aWandererH + RotL64(aCross, 50U)) + 5137814617363250861U) + aNonceWordF;
            aOrbiterE = ((aWandererB + RotL64(aPrevious, 41U)) + 14761561947426681616U) + aPhaseDOrbiterAssignSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterC = (aWandererD + RotL64(aIngress, 13U)) + 12773023438753662590U;
            aOrbiterB = (((aWandererK + RotL64(aPrevious, 3U)) + RotL64(aCarry, 51U)) + 7331345852207096322U) + aNonceWordH;
            aOrbiterA = (((aWandererE + RotL64(aScatter, 21U)) + RotL64(aCarry, 5U)) + 3899381212671247460U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterJ = ((aWandererA + RotL64(aCross, 35U)) + RotL64(aCarry, 29U)) + 10072004147620068599U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 3424585039401897560U) + aNonceWordN;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 8246760141625966321U;
            aOrbiterE = RotL64((aOrbiterE * 11478879365443736383U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 3655992860610853290U) + aNonceWordG;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 11154618022505863898U;
            aOrbiterB = RotL64((aOrbiterB * 4791494171286145231U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 15629361991059709973U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 10842068502278489664U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 17223002513104960799U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 5571312349016336686U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 589313823745748879U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 1356685926549786027U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 13633457935771935260U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 12684602052812183096U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4689206269919806711U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 5711307583717354204U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 7181854170553728211U;
            aOrbiterD = RotL64((aOrbiterD * 9835601115561325911U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 1884620014396115821U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 1471516373272364262U;
            aOrbiterA = RotL64((aOrbiterA * 5126319375714848029U), 13U);
            //
            aIngress = RotL64(aOrbiterB, 29U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 13U));
            aIngress = aIngress + (RotL64(aOrbiterD, 57U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterF, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aScatter, 44U) + aOrbiterF) + RotL64(aOrbiterD, 47U)) + RotL64(aCarry, 11U)) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((((RotL64(aIngress, 11U) + RotL64(aOrbiterD, 13U)) + aOrbiterE) + aNonceWordP) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 29U) + aOrbiterD) + RotL64(aOrbiterJ, 41U)) + RotL64(aCarry, 47U)) + aNonceWordO);
            aWandererA = aWandererA ^ ((RotL64(aCross, 19U) + aOrbiterE) + RotL64(aOrbiterB, 23U));
            aWandererH = aWandererH + (((RotL64(aIngress, 51U) + RotL64(aOrbiterC, 57U)) + aOrbiterF) + aNonceWordC);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 5U) + aOrbiterB) + RotL64(aOrbiterC, 6U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 57U) + aOrbiterC) + RotL64(aOrbiterA, 35U)) + aNonceWordA);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 58U));
            aCarry = aCarry + (RotL64(aWandererH, 19U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererK, 5U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererA, 43U);
            aCarry = aCarry + RotL64(aIngress, 14U);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 21195U)) & S_BLOCK1], 13U) ^ RotL64(aSnowLaneA[((aIndex + 20190U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 20097U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 20373U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneD[((aIndex + 17750U)) & S_BLOCK1], 22U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aPrevious, 57U) ^ RotL64(aCarry, 39U)) ^ (RotL64(aIngress, 13U) + RotL64(aCross, 26U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterF = ((aWandererA + RotL64(aIngress, 43U)) + 6068543441070417854U) + aNonceWordC;
            aOrbiterC = ((aWandererK + RotL64(aPrevious, 57U)) + RotL64(aCarry, 57U)) + 2995980468193441856U;
            aOrbiterI = (((aWandererB + RotL64(aScatter, 3U)) + RotL64(aCarry, 11U)) + 18020277482171594003U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = ((aWandererE + RotL64(aCross, 19U)) + 4293807434721230702U) + aNonceWordD;
            aOrbiterH = ((aWandererC + RotL64(aScatter, 10U)) + 7980599111583893156U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = (aWandererD + RotL64(aIngress, 29U)) + 8593141111851052016U;
            aOrbiterB = ((aWandererH + RotL64(aCross, 37U)) + RotL64(aCarry, 39U)) + 5903487523900084325U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 15112035513447930209U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 9854037263057006439U;
            aOrbiterI = RotL64((aOrbiterI * 396276470208637283U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 16759760289688823193U) + aNonceWordL;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 12622628933030601390U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 2151912984825538321U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 1264668857268123425U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 16302812053619101593U) ^ aNonceWordK;
            aOrbiterH = RotL64((aOrbiterH * 18291400055836111547U), 21U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 16087995784896123610U) + aNonceWordO;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 7970269262800468363U;
            aOrbiterB = RotL64((aOrbiterB * 14924752223305807461U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 5331477046030959632U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 16534913204255550893U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 1013433634373673565U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 11042821902537871209U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 8069677512345031660U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13622218526054132397U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 5737130058129936372U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 1076627182956662997U;
            aOrbiterC = RotL64((aOrbiterC * 14342191224014199929U), 41U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterF, 13U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 44U));
            aIngress = aIngress + (RotL64(aOrbiterC, 5U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterI, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 53U) + aOrbiterH) + RotL64(aOrbiterB, 47U)) + aPhaseDWandererUpdateSaltD[((aIndex + 14U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aCross, 47U) + RotL64(aOrbiterA, 13U)) + aOrbiterB) + RotL64(aCarry, 43U)) + aNonceWordJ);
            aWandererC = aWandererC ^ ((((RotL64(aScatter, 11U) + RotL64(aOrbiterI, 35U)) + aOrbiterJ) + aNonceWordP) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aIngress, 39U) + aOrbiterA) + RotL64(aOrbiterH, 4U)) + RotL64(aCarry, 3U)) + aNonceWordM);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterF, 23U)) + aOrbiterC);
            aWandererD = aWandererD + ((RotL64(aIngress, 60U) + aOrbiterC) + RotL64(aOrbiterI, 41U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 29U) + aOrbiterF) + RotL64(aOrbiterB, 29U)) + aNonceWordN);
            //
            aCarry = aCarry + (RotL64(aWandererC, 52U) ^ aWandererB);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 5U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 39U));
            aCarry = aCarry + RotL64(aWandererA, 43U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 24449U)) & S_BLOCK1], 29U) ^ RotL64(aSnowLaneB[((aIndex + 24504U)) & S_BLOCK1], 12U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 25614U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 25109U)) & S_BLOCK1], 11U) ^ RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 22727U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCross, 57U) + RotL64(aPrevious, 11U)) + (RotL64(aCarry, 42U) ^ RotL64(aIngress, 29U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterH = (((aWandererH + RotL64(aPrevious, 18U)) + RotL64(aCarry, 11U)) + 966899917801652720U) + aNonceWordP;
            aOrbiterK = (((aWandererK + RotL64(aIngress, 27U)) + RotL64(aCarry, 27U)) + 10996327672320748649U) + aNonceWordG;
            aOrbiterJ = ((aWandererA + RotL64(aCross, 3U)) + 4188171566846621107U) + aPhaseDOrbiterAssignSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = (aWandererI + RotL64(aScatter, 47U)) + 5886209243097387959U;
            aOrbiterG = ((aWandererE + RotL64(aPrevious, 35U)) + 14940428957136728111U) + aPhaseDOrbiterAssignSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterD = ((aWandererF + RotL64(aIngress, 41U)) + 179187285531914832U) + aNonceWordO;
            aOrbiterE = ((aWandererC + RotL64(aScatter, 11U)) + RotL64(aCarry, 57U)) + 6685351948936817752U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 1894506461704029700U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 4182760368636977082U;
            aOrbiterJ = RotL64((aOrbiterJ * 972988091869133921U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 12523318028514940790U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 5059306166973366892U) ^ aNonceWordJ;
            aOrbiterG = RotL64((aOrbiterG * 2857409765717296483U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 5890872367917643851U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 17747338389865221534U;
            aOrbiterD = RotL64((aOrbiterD * 5306740664798049267U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 13906227834259884100U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 7152105382899756368U;
            aOrbiterK = RotL64((aOrbiterK * 6772157117358310485U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 17868101884759619240U) + aNonceWordE;
            aOrbiterH = (((aOrbiterH ^ aOrbiterB) ^ 11758843266314148347U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterH = RotL64((aOrbiterH * 5919135169337501485U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 13950566197090324859U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 17278105609930477854U) ^ aNonceWordB;
            aOrbiterB = RotL64((aOrbiterB * 11431842718945107359U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 9556785965646738355U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 841298436857932987U;
            aOrbiterE = RotL64((aOrbiterE * 15077843186688841797U), 11U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterD, 57U);
            aIngress = aIngress + (RotL64(aOrbiterH, 41U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 3U));
            aIngress = aIngress + RotL64(aOrbiterB, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((((RotL64(aScatter, 5U) + aOrbiterJ) + RotL64(aOrbiterH, 34U)) + aNonceWordA) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 11U) + RotL64(aOrbiterD, 57U)) + aOrbiterE) + RotL64(aCarry, 43U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 41U) + RotL64(aOrbiterE, 41U)) + aOrbiterB) + aNonceWordI);
            aWandererC = aWandererC + (((RotL64(aCross, 29U) + RotL64(aOrbiterD, 27U)) + aOrbiterK) + RotL64(aCarry, 3U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 35U) + aOrbiterJ) + RotL64(aOrbiterD, 13U));
            aWandererA = aWandererA + (((RotL64(aCross, 47U) + RotL64(aOrbiterG, 21U)) + aOrbiterD) + aNonceWordC);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 18U) + RotL64(aOrbiterB, 51U)) + aOrbiterJ) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 27U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 36U));
            aCarry = aCarry + (RotL64(aWandererI, 51U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererC, 57U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aInvestLaneC[((aIndex + 27623U)) & S_BLOCK1], 51U) ^ RotL64(aInvestLaneA[((aIndex + 27923U)) & S_BLOCK1], 4U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 29558U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 32584U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29108U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aIngress, 23U) ^ RotL64(aCarry, 56U)) ^ (RotL64(aPrevious, 41U) + RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterI = ((aWandererB + RotL64(aIngress, 35U)) + 5906639480605353429U) + aNonceWordL;
            aOrbiterJ = ((aWandererC + RotL64(aCross, 29U)) + RotL64(aCarry, 51U)) + 5293518570213287605U;
            aOrbiterD = (((aWandererJ + RotL64(aPrevious, 41U)) + RotL64(aCarry, 13U)) + 15383185501428521377U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterH = ((aWandererE + RotL64(aScatter, 3U)) + RotL64(aCarry, 39U)) + 15364072512743978902U;
            aOrbiterF = (((aWandererD + RotL64(aPrevious, 60U)) + 4525473357144014271U) + aPhaseDOrbiterAssignSaltC[((aIndex + 10U)) & S_SALT1]) + aNonceWordF;
            aOrbiterK = (aWandererA + RotL64(aScatter, 51U)) + 10400911938125603074U;
            aOrbiterE = ((aWandererI + RotL64(aIngress, 13U)) + 16417506293824627550U) + aNonceWordB;
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 2419329331753341815U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 14929222427923332069U;
            aOrbiterD = RotL64((aOrbiterD * 11596261802662514979U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 16771573504983922586U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterH) ^ 1863466450051787622U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterF = RotL64((aOrbiterF * 2585626547126027053U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 12895350137096692415U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 3700979086526298327U;
            aOrbiterI = RotL64((aOrbiterI * 10279730254867618193U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 1977099106211282426U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 6144698304096915742U;
            aOrbiterK = RotL64((aOrbiterK * 5039822990560519609U), 11U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterH) + 3858895556659724975U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1]) + aNonceWordN;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 1283646340363435327U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 11622421841377018069U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 6240532051889108891U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 757364889381634634U;
            aOrbiterH = RotL64((aOrbiterH * 943852137901972945U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 5272945693977418174U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 6850528198786172283U;
            aOrbiterJ = RotL64((aOrbiterJ * 1966383079897679953U), 57U);
            //
            aIngress = RotL64(aOrbiterK, 5U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterJ, 27U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterE, 57U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterF, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aCross, 35U) + RotL64(aOrbiterK, 27U)) + aOrbiterF) + aNonceWordH);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 51U) + aOrbiterJ) + RotL64(aOrbiterH, 43U));
            aWandererC = aWandererC + (((RotL64(aScatter, 13U) + RotL64(aOrbiterK, 19U)) + aOrbiterI) + RotL64(aCarry, 43U));
            aWandererB = aWandererB ^ ((((RotL64(aIngress, 43U) + RotL64(aOrbiterE, 57U)) + aOrbiterK) + aNonceWordP) + aPhaseDWandererUpdateSaltC[((aIndex + 16U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aScatter, 28U) + RotL64(aOrbiterH, 5U)) + aOrbiterD);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 21U) + aOrbiterE) + RotL64(aOrbiterD, 37U));
            aWandererD = aWandererD + ((((RotL64(aCross, 57U) + aOrbiterF) + RotL64(aOrbiterE, 50U)) + RotL64(aCarry, 19U)) + aPhaseDWandererUpdateSaltF[((aIndex + 28U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 43U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererJ, 23U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererI, 39U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererD, 34U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xEAD9700218448479ULL + 0x80F27EDDBD3EBDBAULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xFF4E2D611270A9FDULL + 0xA85454CCD35D7D93ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xE7F4A0A4C4023033ULL + 0x9DF8456C1EC73422ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xD1B9675005BCFF0BULL + 0x894903F093AD9ABCULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xB128AB36CB5046F5ULL + 0xE601E03BA5AA94ADULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xEA5776761F2EA3B3ULL + 0xFA4F801DA8006DBFULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xF1D8C23818C1AAC7ULL + 0x8A8E3419CB1DBD80ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xBA39788DBDD0C58DULL + 0xB5918F6FC7488121ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xEE2B4FA133CD6C9BULL + 0xA0C80625EE3937E9ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xDF53A0EC7D96F333ULL + 0x8B286A311EF62315ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x90B475D5DB2CDDF9ULL + 0xB619DD804AC7B234ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xD081BE7E05E96203ULL + 0x89171E6EE395DD0FULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0x8456BDA20AD8014BULL + 0x8BB6485A93EBD27FULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xDD2A817559EB8E71ULL + 0x8C64664A44CB35A8ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xF086C6C721A1E0E7ULL + 0xD96DCB646080DDA1ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xA0336D28254348B3ULL + 0xD0D0112CE9A00048ULL);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 1094U)) & S_BLOCK1], 48U) ^ RotL64(aInvestLaneB[((aIndex + 4632U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 5285U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 434U)) & S_BLOCK1], 60U) ^ RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 5220U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 381U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aPrevious, 57U) ^ RotL64(aCarry, 43U)) + (RotL64(aIngress, 18U) + RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterD = ((aWandererK + RotL64(aPrevious, 52U)) + 9630214189402543339U) + aPhaseEOrbiterAssignSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = (aWandererJ + RotL64(aCross, 47U)) + 4072576573737526819U;
            aOrbiterA = ((aWandererH + RotL64(aIngress, 43U)) + RotL64(aCarry, 41U)) + 15994787452709618869U;
            aOrbiterH = (aWandererI + RotL64(aScatter, 19U)) + 6403240137132259482U;
            aOrbiterJ = ((aWandererB + RotL64(aPrevious, 39U)) + 10229266900170507720U) + aNonceWordP;
            aOrbiterG = ((aWandererF + RotL64(aIngress, 3U)) + 5025294577989748989U) + aPhaseEOrbiterAssignSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterI = (((aWandererC + RotL64(aScatter, 37U)) + RotL64(aCarry, 5U)) + 16696461238217956883U) + aNonceWordO;
            aOrbiterC = (aWandererG + RotL64(aCross, 27U)) + 9878318855341719119U;
            aOrbiterE = (aWandererA + RotL64(aPrevious, 41U)) + 16086635438116177346U;
            aOrbiterF = (aWandererE + RotL64(aIngress, 35U)) + 12295437783084203730U;
            aOrbiterK = ((aWandererD + RotL64(aCross, 6U)) + RotL64(aCarry, 11U)) + 7681150419912842402U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 2639104034287637448U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 12298170009332243573U;
            aOrbiterA = RotL64((aOrbiterA * 9397919591171238575U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 3485932317267669626U) + aNonceWordM;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 16569551670038752475U;
            aOrbiterG = RotL64((aOrbiterG * 8139802826402217631U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 4448490103784103954U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 14510534073046885941U;
            aOrbiterD = RotL64((aOrbiterD * 7777192047386438305U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 4286195398675733451U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 15790355933840266463U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 13342257823027075501U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 6362891510370156055U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 15121822034579983174U;
            aOrbiterJ = RotL64((aOrbiterJ * 7268045994574844937U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 13817341015719915628U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 14113474087906143783U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 12838910141533126059U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 9988301252236121106U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 11287477288382171758U) ^ aNonceWordL;
            aOrbiterH = RotL64((aOrbiterH * 4979297247881426383U), 37U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 9491727010910328644U) + aNonceWordI;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 7961202721830514030U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 16300364540313620767U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 10058066852293995222U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 541563830282750968U;
            aOrbiterI = RotL64((aOrbiterI * 1516823517052019845U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 7791201128863372861U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 8334318157449352359U;
            aOrbiterB = RotL64((aOrbiterB * 2924838607279239375U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 6861081455774799715U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 9630214189402543339U;
            aOrbiterF = RotL64((aOrbiterF * 10837610668580336781U), 53U);
            //
            aIngress = RotL64(aOrbiterF, 37U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 21U));
            aIngress = aIngress + (RotL64(aOrbiterB, 53U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 5U));
            aIngress = aIngress + (RotL64(aOrbiterI, 27U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterG, 34U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterG, 23U)) + aOrbiterH);
            aWandererK = aWandererK + ((RotL64(aCross, 11U) + aOrbiterK) + RotL64(aOrbiterA, 29U));
            aWandererG = aWandererG ^ ((((RotL64(aIngress, 43U) + RotL64(aOrbiterD, 56U)) + aOrbiterE) + aNonceWordG) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 58U) + RotL64(aOrbiterG, 13U)) + aOrbiterK) + RotL64(aCarry, 39U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterG, 21U)) + aOrbiterD);
            aWandererA = aWandererA + ((RotL64(aScatter, 39U) + aOrbiterB) + RotL64(aOrbiterC, 27U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterK, 35U)) + aOrbiterI);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 26U) + RotL64(aOrbiterF, 53U)) + aOrbiterJ) + RotL64(aCarry, 47U)) + aNonceWordA);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 5U) + aOrbiterK) + RotL64(aOrbiterF, 40U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 41U) + aOrbiterJ) + RotL64(aOrbiterA, 47U)) + aNonceWordE);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 21U) + aOrbiterI) + RotL64(aOrbiterB, 19U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 43U));
            aCarry = aCarry + (RotL64(aWandererB, 23U) ^ aWandererC);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 58U));
            aCarry = aCarry + (RotL64(aWandererH, 5U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererE, 27U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererA, 29U);
            aCarry = aCarry + RotL64(aIngress, 52U);
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
            aIngress = (RotL64(aFireLaneA[((aIndex + 6504U)) & S_BLOCK1], 27U) ^ RotL64(aInvestLaneC[((aIndex + 6038U)) & S_BLOCK1], 54U));
            aIngress ^= (RotL64(aInvestLaneD[((aIndex + 10146U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 8736U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 7253U)) & S_BLOCK1], 41U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 9121U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 9070U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aIngress, 23U) + RotL64(aCross, 35U)) + (RotL64(aPrevious, 6U) ^ RotL64(aCarry, 51U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterG = (aWandererI + RotL64(aPrevious, 47U)) + 17081642665820489793U;
            aOrbiterK = (aWandererF + RotL64(aScatter, 51U)) + 14468854040067229623U;
            aOrbiterF = (((aWandererJ + RotL64(aIngress, 37U)) + RotL64(aCarry, 57U)) + 2249450222593057429U) + aNonceWordH;
            aOrbiterH = ((aWandererK + RotL64(aCross, 44U)) + RotL64(aCarry, 47U)) + 14964389079511378664U;
            aOrbiterD = (aWandererB + RotL64(aScatter, 39U)) + 17003491054252360650U;
            aOrbiterE = ((aWandererG + RotL64(aCross, 57U)) + 12710882240582032588U) + aPhaseEOrbiterAssignSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterB = (aWandererD + RotL64(aPrevious, 53U)) + 9887078182156755359U;
            aOrbiterA = (((aWandererA + RotL64(aIngress, 23U)) + 7665284531810584704U) + aPhaseEOrbiterAssignSaltE[((aIndex + 4U)) & S_SALT1]) + aNonceWordF;
            aOrbiterJ = (aWandererH + RotL64(aPrevious, 21U)) + 7304284015511876717U;
            aOrbiterI = (aWandererC + RotL64(aIngress, 30U)) + 5517927023543751734U;
            aOrbiterC = ((aWandererE + RotL64(aScatter, 35U)) + RotL64(aCarry, 23U)) + 17704756310857362759U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 11347400363019508578U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 11696395232760991243U) ^ aNonceWordO;
            aOrbiterF = RotL64((aOrbiterF * 9725231749679442003U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 10875780291242873583U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 7808740614343437672U;
            aOrbiterE = RotL64((aOrbiterE * 8889516201913716283U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 3145390996141902032U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 16080636485642732615U;
            aOrbiterB = RotL64((aOrbiterB * 7445756373012217305U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 3929263288176983844U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 18210228766683996806U) ^ aNonceWordE;
            aOrbiterK = RotL64((aOrbiterK * 13178080076505449091U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 13948962323541421431U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 3037683309790156893U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 13406672352222636739U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 17827265198532699474U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 7270895262023504864U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 13467417362477308167U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 6431243064980879185U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 6680205390976259885U;
            aOrbiterC = RotL64((aOrbiterC * 10421386694108590789U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 15910655919164357152U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 8046213498216027383U;
            aOrbiterG = RotL64((aOrbiterG * 18061867495824063553U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 2521111689480478597U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 13892876610454681741U;
            aOrbiterI = RotL64((aOrbiterI * 17776392934374483875U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 16009217514890880809U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 1221573458193626679U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 73477765605619369U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 9275704218554025797U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 17081642665820489793U;
            aOrbiterJ = RotL64((aOrbiterJ * 5613316790159527375U), 47U);
            //
            aIngress = RotL64(aOrbiterC, 35U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterG, 47U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 51U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 21U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 10U));
            aIngress = aIngress + RotL64(aOrbiterJ, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aCross, 27U) + RotL64(aOrbiterB, 48U)) + aOrbiterF);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterK, 43U)) + aOrbiterB);
            aWandererG = aWandererG + (((RotL64(aScatter, 35U) + aOrbiterF) + RotL64(aOrbiterH, 27U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 46U) + RotL64(aOrbiterE, 51U)) + aOrbiterI);
            aWandererD = aWandererD + (((RotL64(aCross, 41U) + RotL64(aOrbiterF, 5U)) + aOrbiterD) + aNonceWordN);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 5U) + aOrbiterE) + RotL64(aOrbiterC, 54U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aScatter, 51U) + aOrbiterG) + RotL64(aOrbiterA, 11U)) + RotL64(aCarry, 23U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 13U) + RotL64(aOrbiterG, 57U)) + aOrbiterJ) + aNonceWordC);
            aWandererK = aWandererK + ((((RotL64(aCross, 44U) + aOrbiterI) + RotL64(aOrbiterJ, 39U)) + RotL64(aCarry, 11U)) + aNonceWordM);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 53U) + aOrbiterH) + RotL64(aOrbiterE, 23U));
            aWandererC = aWandererC + (((RotL64(aScatter, 39U) + aOrbiterK) + RotL64(aOrbiterG, 37U)) + aNonceWordK);
            //
            aCarry = aCarry + (RotL64(aWandererI, 54U) ^ aWandererG);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + (RotL64(aWandererK, 11U) ^ aWandererD);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 29U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 42U));
            aCarry = aCarry + RotL64(aWandererA, 47U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 11425U)) & S_BLOCK1], 23U) ^ RotL64(aInvestLaneA[((aIndex + 13197U)) & S_BLOCK1], 52U));
            aIngress ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 11831U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 14353U)) & S_BLOCK1], 23U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 11926U)) & S_BLOCK1], 54U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCross, 51U) + RotL64(aIngress, 39U)) ^ (RotL64(aCarry, 26U) ^ RotL64(aPrevious, 13U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterJ = ((aWandererF + RotL64(aIngress, 41U)) + 16519040829220310189U) + aNonceWordG;
            aOrbiterI = ((aWandererA + RotL64(aScatter, 3U)) + 6888002778416941825U) + aPhaseEOrbiterAssignSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = (aWandererK + RotL64(aPrevious, 27U)) + 1310832187746534025U;
            aOrbiterA = (aWandererG + RotL64(aCross, 19U)) + 5890888009051281674U;
            aOrbiterG = ((aWandererD + RotL64(aScatter, 48U)) + 5143864838362464857U) + aNonceWordA;
            aOrbiterB = ((aWandererB + RotL64(aIngress, 51U)) + RotL64(aCarry, 19U)) + 15591534069452660003U;
            aOrbiterK = ((aWandererH + RotL64(aPrevious, 35U)) + RotL64(aCarry, 47U)) + 1466867671765325096U;
            aOrbiterD = (aWandererE + RotL64(aCross, 39U)) + 13931443680107902488U;
            aOrbiterE = ((aWandererC + RotL64(aPrevious, 23U)) + 15400747367673245552U) + aPhaseEOrbiterAssignSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterC = (((aWandererJ + RotL64(aCross, 37U)) + RotL64(aCarry, 43U)) + 2836975369734495759U) + aNonceWordC;
            aOrbiterF = (aWandererI + RotL64(aIngress, 6U)) + 2370720358274970117U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 3470677184188006133U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 7175584278499266723U) ^ aNonceWordM;
            aOrbiterH = RotL64((aOrbiterH * 10067096593682482345U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 6095078817776863055U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 2176637999243513070U;
            aOrbiterI = RotL64((aOrbiterI * 12215701810843975501U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 5580391239754903129U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 15196125567953871184U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 12686361960729564519U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 12787014151503209931U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 1523153207064063495U;
            aOrbiterC = RotL64((aOrbiterC * 3113907543551927561U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 12973289026485937829U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 9087439766232078173U;
            aOrbiterE = RotL64((aOrbiterE * 5817029335999350327U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 16318022893068674015U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 11089160685103562409U;
            aOrbiterG = RotL64((aOrbiterG * 17087834321385147603U), 39U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 8680037953925067235U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 3112588943274158119U;
            aOrbiterF = RotL64((aOrbiterF * 9214011370307670371U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 16749015684369649821U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 9419550535891334966U;
            aOrbiterJ = RotL64((aOrbiterJ * 5421312787569114811U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 12309598080688360615U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 12244971765096881835U;
            aOrbiterK = RotL64((aOrbiterK * 17260277357109449509U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 10088685417774847648U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 3241987595838650154U;
            aOrbiterB = RotL64((aOrbiterB * 14096986158958931367U), 13U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterC) + 17916401586500786536U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordL;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 16519040829220310189U;
            aOrbiterA = RotL64((aOrbiterA * 6742024268853509861U), 23U);
            //
            aIngress = RotL64(aOrbiterH, 43U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 14U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 27U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 57U));
            aIngress = aIngress + (RotL64(aOrbiterC, 21U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterI, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 57U) + aOrbiterI) + RotL64(aOrbiterF, 51U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 14U) + aOrbiterA) + RotL64(aOrbiterG, 57U));
            aWandererH = aWandererH + (((RotL64(aScatter, 29U) + RotL64(aOrbiterA, 35U)) + aOrbiterD) + RotL64(aCarry, 19U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 51U) + aOrbiterA) + RotL64(aOrbiterB, 3U));
            aWandererI = aWandererI + ((RotL64(aIngress, 5U) + RotL64(aOrbiterJ, 23U)) + aOrbiterE);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterC, 40U)) + aOrbiterH);
            aWandererB = aWandererB + ((RotL64(aCross, 19U) + RotL64(aOrbiterK, 11U)) + aOrbiterH);
            aWandererC = aWandererC ^ ((((RotL64(aPrevious, 12U) + aOrbiterA) + RotL64(aOrbiterE, 43U)) + aNonceWordO) + aPhaseEWandererUpdateSaltA[((aIndex + 22U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 53U) + RotL64(aOrbiterG, 13U)) + aOrbiterF) + aNonceWordN);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 41U) + aOrbiterB) + RotL64(aOrbiterJ, 53U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 35U) + aOrbiterC) + RotL64(aOrbiterG, 30U)) + RotL64(aCarry, 43U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 21U) ^ aWandererH);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 28U));
            aCarry = aCarry + (RotL64(aWandererA, 19U) ^ aWandererF);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 37U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 39U));
            aCarry = aCarry + RotL64(aWandererB, 58U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 18200U)) & S_BLOCK1], 43U) ^ RotL64(aFireLaneA[((aIndex + 20853U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 16721U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 18745U)) & S_BLOCK1], 13U) ^ RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 16516U)) & S_BLOCK1], 38U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCarry, 13U) ^ RotL64(aIngress, 28U)) ^ (RotL64(aCross, 53U) + RotL64(aPrevious, 41U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterF = (aWandererB + RotL64(aIngress, 43U)) + 9107326720193244489U;
            aOrbiterJ = (aWandererJ + RotL64(aCross, 39U)) + 10868585484401664145U;
            aOrbiterG = ((aWandererG + RotL64(aPrevious, 54U)) + 13637736741437846622U) + aNonceWordN;
            aOrbiterE = (aWandererI + RotL64(aScatter, 11U)) + 6130725216183918844U;
            aOrbiterK = ((aWandererD + RotL64(aCross, 23U)) + RotL64(aCarry, 3U)) + 2063834478521338187U;
            aOrbiterD = (((aWandererA + RotL64(aScatter, 51U)) + RotL64(aCarry, 27U)) + 8564870627911949158U) + aPhaseEOrbiterAssignSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterC = ((aWandererH + RotL64(aIngress, 29U)) + 6524015751064086390U) + aNonceWordM;
            aOrbiterA = ((aWandererF + RotL64(aPrevious, 41U)) + 9874937766875388236U) + aNonceWordK;
            aOrbiterB = (aWandererE + RotL64(aScatter, 14U)) + 14723718409522680894U;
            aOrbiterI = ((aWandererC + RotL64(aPrevious, 5U)) + RotL64(aCarry, 23U)) + 13767059954741528279U;
            aOrbiterH = ((aWandererK + RotL64(aCross, 19U)) + 6387608251033722169U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 5391425980008431000U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 11524218415655093779U;
            aOrbiterG = RotL64((aOrbiterG * 12508457981779189389U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 155510463350385905U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 10554591788433641311U;
            aOrbiterK = RotL64((aOrbiterK * 5412084824127934293U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 8662160162966241542U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterD) ^ 5092555636369853727U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterA = RotL64((aOrbiterA * 433807340167635499U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 7163345798448796101U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 695089002178413267U;
            aOrbiterD = RotL64((aOrbiterD * 17302689458565434475U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 5409173939213468972U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 15349690077393827541U;
            aOrbiterE = RotL64((aOrbiterE * 10984681254001609841U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 12376011890751302027U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 7809614158898158383U;
            aOrbiterC = RotL64((aOrbiterC * 13845113198736843629U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 13031938699536449576U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 3983178190194056516U;
            aOrbiterI = RotL64((aOrbiterI * 1341678482929213405U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 5567935037909671790U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterC) ^ 17137042627663349797U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterF = RotL64((aOrbiterF * 13535586899620672373U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 8726085717433137208U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 13154097637429217548U;
            aOrbiterJ = RotL64((aOrbiterJ * 5523758597936082363U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 4030516340575723215U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 7121696965917254968U;
            aOrbiterB = RotL64((aOrbiterB * 13569584361980228493U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 12079991626282752674U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 9107326720193244489U;
            aOrbiterH = RotL64((aOrbiterH * 7225937408665051799U), 13U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterG, 19U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 36U));
            aIngress = aIngress + (RotL64(aOrbiterE, 39U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 13U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 21U));
            aIngress = aIngress + RotL64(aOrbiterD, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aPrevious, 37U) + RotL64(aOrbiterE, 5U)) + aOrbiterA) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aCross, 21U) + RotL64(aOrbiterK, 37U)) + aOrbiterE) + aNonceWordH);
            aWandererA = aWandererA + ((RotL64(aScatter, 50U) + aOrbiterJ) + RotL64(aOrbiterH, 47U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 53U) + aOrbiterI) + RotL64(aOrbiterF, 41U));
            aWandererJ = aWandererJ + ((RotL64(aScatter, 35U) + aOrbiterD) + RotL64(aOrbiterC, 52U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 27U) + aOrbiterE) + RotL64(aOrbiterI, 21U)) + aNonceWordO);
            aWandererC = aWandererC + (((RotL64(aCross, 47U) + RotL64(aOrbiterA, 11U)) + aOrbiterI) + RotL64(aCarry, 5U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 41U) + aOrbiterE) + RotL64(aOrbiterG, 57U)) + aNonceWordI);
            aWandererI = aWandererI + ((RotL64(aScatter, 44U) + RotL64(aOrbiterD, 24U)) + aOrbiterB);
            aWandererK = aWandererK ^ (((RotL64(aCross, 19U) + aOrbiterK) + RotL64(aOrbiterB, 29U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aIngress, 39U) + aOrbiterH) + RotL64(aOrbiterC, 13U)) + RotL64(aCarry, 47U)) + aNonceWordG);
            //
            aCarry = aCarry + (RotL64(aWandererB, 43U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererA, 5U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererJ, 30U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererF, 51U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererC, 27U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererH, 53U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 22246U)) & S_BLOCK1], 5U) ^ RotL64(aFireLaneB[((aIndex + 23489U)) & S_BLOCK1], 56U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 22646U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 23981U)) & S_BLOCK1], 52U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 27121U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aInvestLaneA[((aIndex + 24974U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aIngress, 58U) ^ RotL64(aCarry, 27U)) + (RotL64(aPrevious, 13U) + RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterC = ((aWandererD + RotL64(aPrevious, 43U)) + 701291026547470433U) + aNonceWordF;
            aOrbiterB = ((aWandererC + RotL64(aIngress, 27U)) + RotL64(aCarry, 57U)) + 17283292650462111643U;
            aOrbiterH = (aWandererA + RotL64(aScatter, 29U)) + 9969124091931303406U;
            aOrbiterD = (aWandererK + RotL64(aCross, 41U)) + 889176772718046988U;
            aOrbiterK = ((aWandererF + RotL64(aIngress, 13U)) + 6054541844643748084U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = (aWandererH + RotL64(aPrevious, 19U)) + 14703226235143028132U;
            aOrbiterA = (((aWandererJ + RotL64(aScatter, 36U)) + RotL64(aCarry, 39U)) + 7977975878522921062U) + aNonceWordA;
            aOrbiterF = ((aWandererI + RotL64(aCross, 39U)) + 16894322614172266274U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterE = (aWandererG + RotL64(aPrevious, 23U)) + 12160451749345900570U;
            aOrbiterJ = (aWandererE + RotL64(aIngress, 21U)) + 10870847008043897470U;
            aOrbiterI = ((aWandererB + RotL64(aCross, 4U)) + RotL64(aCarry, 11U)) + 8159920947172520247U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 2440099120969517932U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 2428396147731468007U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9363073341539598441U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 2213226274394673479U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 7079731443427765333U;
            aOrbiterG = RotL64((aOrbiterG * 16918930776877030559U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 958896789550478970U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 10788682955708075458U;
            aOrbiterF = RotL64((aOrbiterF * 913321215613559729U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 2003386579317564870U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 8419686358774204999U;
            aOrbiterB = RotL64((aOrbiterB * 6547052526438697621U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 6989167615157578904U) + aNonceWordP;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 17636634003643824148U) ^ aNonceWordG;
            aOrbiterI = RotL64((aOrbiterI * 11038576417283732937U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 13824962118933907859U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 9543912892587859646U;
            aOrbiterD = RotL64((aOrbiterD * 14736710162285997415U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 15729878041027706114U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 9542137475454825463U;
            aOrbiterC = RotL64((aOrbiterC * 11420547128115090491U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 5327302277575009955U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 2707383132257428583U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 6120763309390182129U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 9008601903853562620U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 11050463189491777908U;
            aOrbiterJ = RotL64((aOrbiterJ * 9178386878636430553U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 14683684132116778056U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 5390271065690907120U;
            aOrbiterK = RotL64((aOrbiterK * 17903005409098232619U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 5183407290520277451U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 701291026547470433U;
            aOrbiterA = RotL64((aOrbiterA * 16329261100139524239U), 41U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterJ, 3U);
            aIngress = aIngress + (RotL64(aOrbiterB, 42U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 21U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 39U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 57U));
            aIngress = aIngress + RotL64(aOrbiterF, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aScatter, 60U) + RotL64(aOrbiterC, 21U)) + aOrbiterB);
            aWandererH = aWandererH + ((RotL64(aIngress, 11U) + RotL64(aOrbiterE, 27U)) + aOrbiterA);
            aWandererI = aWandererI ^ ((((RotL64(aPrevious, 53U) + aOrbiterH) + RotL64(aOrbiterI, 58U)) + aNonceWordC) + aPhaseEWandererUpdateSaltE[((aIndex + 21U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 37U) + aOrbiterB) + RotL64(aOrbiterK, 5U)) + RotL64(aCarry, 19U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterF, 51U)) + aOrbiterD) + aNonceWordJ);
            aWandererF = aWandererF + (((RotL64(aIngress, 23U) + RotL64(aOrbiterA, 29U)) + aOrbiterB) + RotL64(aCarry, 41U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 51U) + RotL64(aOrbiterA, 23U)) + aOrbiterI) + aNonceWordL);
            aWandererJ = aWandererJ + ((RotL64(aCross, 18U) + aOrbiterG) + RotL64(aOrbiterJ, 12U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterF, 43U)) + aOrbiterG);
            aWandererE = aWandererE + (((RotL64(aIngress, 35U) + aOrbiterA) + RotL64(aOrbiterG, 41U)) + aPhaseEWandererUpdateSaltF[((aIndex + 15U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 13U) + aOrbiterG) + RotL64(aOrbiterH, 37U)) + aNonceWordN);
            //
            aCarry = aCarry + (RotL64(aWandererD, 37U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererB, 47U) ^ aWandererG);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 60U));
            aCarry = aCarry + (RotL64(aWandererJ, 5U) ^ aWandererC);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 41U));
            aCarry = aCarry + RotL64(aWandererH, 11U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 29179U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneA[((aIndex + 29747U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 32542U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 30230U)) & S_BLOCK1], 12U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 31904U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCross, 28U) + RotL64(aPrevious, 43U)) + (RotL64(aIngress, 5U) ^ RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterD = ((aWandererA + RotL64(aCross, 53U)) + RotL64(aCarry, 29U)) + 13296600294247799698U;
            aOrbiterG = ((aWandererB + RotL64(aIngress, 23U)) + 5818503518080877515U) + aNonceWordH;
            aOrbiterI = (((aWandererE + RotL64(aScatter, 13U)) + RotL64(aCarry, 11U)) + 6735784238734173597U) + aNonceWordB;
            aOrbiterB = (((aWandererH + RotL64(aPrevious, 11U)) + RotL64(aCarry, 41U)) + 7368398209488856201U) + aPhaseEOrbiterAssignSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = ((aWandererK + RotL64(aIngress, 29U)) + 961734029066455638U) + aNonceWordC;
            aOrbiterK = (aWandererG + RotL64(aPrevious, 38U)) + 797011946660892011U;
            aOrbiterH = (aWandererD + RotL64(aScatter, 51U)) + 12841876018396622350U;
            aOrbiterJ = ((aWandererI + RotL64(aCross, 43U)) + 16213253970483895623U) + aNonceWordD;
            aOrbiterF = (aWandererJ + RotL64(aPrevious, 47U)) + 15186950557113470375U;
            aOrbiterA = (aWandererF + RotL64(aCross, 35U)) + 5117930310827477341U;
            aOrbiterE = ((aWandererC + RotL64(aScatter, 56U)) + 12265429373166094162U) + aPhaseEOrbiterAssignSaltA[((aIndex + 3U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 13920531346698601568U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 14695405206998211456U;
            aOrbiterI = RotL64((aOrbiterI * 13950964363414164279U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 7851960904825938443U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 9501511171732550190U;
            aOrbiterK = RotL64((aOrbiterK * 5614164120361489613U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 5663365182245722077U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 9607860124321315555U;
            aOrbiterJ = RotL64((aOrbiterJ * 3461820361914280601U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 18171052650586819280U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 3442698321538580861U;
            aOrbiterH = RotL64((aOrbiterH * 6317525514963824829U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 1491052813469258970U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterA) ^ 3956599824067616133U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 10U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterE = RotL64((aOrbiterE * 2928600779267623085U), 41U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 10963841237346073453U) + aNonceWordN;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 2303020125591252534U;
            aOrbiterC = RotL64((aOrbiterC * 9969099842343321981U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 14503856057958162356U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 11147548150090597694U;
            aOrbiterG = RotL64((aOrbiterG * 11856382308792700441U), 21U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 9191681438318311481U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 13556072770381999852U;
            aOrbiterF = RotL64((aOrbiterF * 18316231099054203683U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 10103207278550444685U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 10415809965217261104U;
            aOrbiterD = RotL64((aOrbiterD * 16562732599511350217U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 17435033201864058457U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 5540494424887364682U;
            aOrbiterB = RotL64((aOrbiterB * 18230910315317249045U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 18020151683897013854U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 13296600294247799698U;
            aOrbiterA = RotL64((aOrbiterA * 10000194329456668845U), 3U);
            //
            aIngress = RotL64(aOrbiterG, 57U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterH, 41U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterF, 51U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 43U));
            aIngress = aIngress + (RotL64(aOrbiterE, 36U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterB, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aCross, 5U) + RotL64(aOrbiterK, 50U)) + aOrbiterA);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 53U) + aOrbiterC) + RotL64(aOrbiterB, 47U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 37U) + RotL64(aOrbiterF, 19U)) + aOrbiterJ) + RotL64(aCarry, 47U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 10U) + aOrbiterI) + RotL64(aOrbiterD, 3U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 39U) + aOrbiterC) + RotL64(aOrbiterJ, 27U)) + aNonceWordM);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 29U) + aOrbiterE) + RotL64(aOrbiterH, 23U)) + aNonceWordI);
            aWandererH = aWandererH + ((RotL64(aPrevious, 21U) + RotL64(aOrbiterF, 41U)) + aOrbiterK);
            aWandererB = aWandererB ^ ((RotL64(aCross, 41U) + aOrbiterG) + RotL64(aOrbiterH, 58U));
            aWandererF = aWandererF + (((RotL64(aIngress, 23U) + aOrbiterI) + RotL64(aOrbiterK, 21U)) + aNonceWordF);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 56U) + aOrbiterJ) + RotL64(aOrbiterA, 35U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aCross, 27U) + aOrbiterB) + RotL64(aOrbiterH, 29U)) + RotL64(aCarry, 39U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 19U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 44U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 35U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 29U));
            aCarry = aCarry + (RotL64(aWandererI, 41U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererG, 13U);
            aCarry = aCarry + RotL64(aIngress, 58U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xC56094B3D96B18FFULL + 0x837F4D691C1A1B94ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xCFA23B10411EB847ULL + 0x9661FFC3B44E8131ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xD5078C84005234E9ULL + 0xE75D583762CD1D89ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xA1F7EB0F441DAE51ULL + 0x9F9F2528B3ED95F2ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xE072666009FE80D1ULL + 0xB4C61EBFDAF80264ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xB1B4BFAC3D7D2101ULL + 0xC0EE8E05ABBBD53DULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x8F93570FF132D75FULL + 0xD7B401A39E33D510ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xC1DC4A07A517F133ULL + 0xF7DAECD43948E05CULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xE9644D87A50E72AFULL + 0x9D8907006EC4EE0DULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xB0418011B7EED5AFULL + 0xE0F676D549F502C4ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xA6D9417189DB052FULL + 0xFEDFD38FE852823EULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xA3A8CC80FF4FDD9FULL + 0xD10E2B75A67D8A01ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xE472337FB26AF5D1ULL + 0xDD768BCB8EE2F1ADULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xE010BEDF30CE6BD9ULL + 0xF08B7A457CBB3B8FULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x96A0F571181492BDULL + 0x91FBC0BDB4CF1F88ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xAB0C526574EACF5BULL + 0x80D5CE100E92E35BULL);
    // GSeedRunSeed_F seed_loop_f (start)
    {
        // GSeedRunSeed_F seed_loop_f lane group
        // read from: aOperationLaneA, aOperationLaneB, aSnowLaneA, aOperationLaneC, aOperationLaneD, aSnowLaneB, aSnowLaneC, aInvestLaneD, aWorkLaneC, aSnowLaneD, aWorkLaneD, aExpandLaneA, aInvestLaneC, aExpandLaneB, aInvestLaneA, aExpandLaneC, aInvestLaneB
        // write to: aSnowLaneC, aSnowLaneD, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // seed_loop_f loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aSnowLaneA
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aSnowLaneA forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aSnowLaneB
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aSnowLaneB backward/forward random
        // write to: aSnowLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 1098U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneB[((aIndex + 2222U)) & S_BLOCK1], 60U));
            aIngress ^= RotL64(aSnowLaneA[((aIndex + 4674U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 2400U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 3091U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aSnowLaneB[((aIndex + 322U)) & S_BLOCK1], 56U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCarry, 41U) + RotL64(aPrevious, 29U)) + (RotL64(aCross, 53U) ^ RotL64(aIngress, 14U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterG = (aWandererJ + RotL64(aPrevious, 39U)) + 3973833383430652211U;
            aOrbiterJ = ((((aWandererH + RotL64(aScatter, 30U)) + RotL64(aCarry, 23U)) + 5760227042747169187U) + aPhaseFOrbiterAssignSaltC[((aIndex + 17U)) & S_SALT1]) + aNonceWordA;
            aOrbiterA = ((aWandererG + RotL64(aIngress, 53U)) + 4923009065139227286U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterF = ((aWandererF + RotL64(aCross, 47U)) + 1477807307009107590U) + aNonceWordK;
            aOrbiterE = ((aWandererC + RotL64(aPrevious, 35U)) + RotL64(aCarry, 43U)) + 5707194514329007301U;
            aOrbiterI = (aWandererA + RotL64(aScatter, 22U)) + 5340439728375269724U;
            aOrbiterD = (aWandererD + RotL64(aIngress, 3U)) + 17080457898946572387U;
            aOrbiterB = ((aWandererK + RotL64(aCross, 57U)) + RotL64(aCarry, 5U)) + 281559150259472813U;
            aOrbiterH = (aWandererB + RotL64(aPrevious, 43U)) + 16160633048230910560U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 9003989610509592121U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 10579322462808454333U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 100832431598087235U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 15059383289528723069U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 10417647757852880956U) ^ aNonceWordO;
            aOrbiterE = RotL64((aOrbiterE * 1457919230286043137U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 14484665027393813330U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 12344463053485837974U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 5762654194001525041U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 5826453246659297805U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 12547902286376986223U;
            aOrbiterB = RotL64((aOrbiterB * 2982850000322672789U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 9637855144278126174U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 2132744427444501938U;
            aOrbiterH = RotL64((aOrbiterH * 5911587798564836199U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 9248933938130311231U) + aNonceWordI;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 13274297928717090383U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2901398809555237563U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 3690262236918560930U) + aNonceWordD;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 3626005326410800344U) ^ aNonceWordH;
            aOrbiterJ = RotL64((aOrbiterJ * 13030443356669355355U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 10801089744186148218U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 5446653082176311031U;
            aOrbiterF = RotL64((aOrbiterF * 4594267575901248321U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 3205541585889107366U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 4532327942368884436U;
            aOrbiterD = RotL64((aOrbiterD * 16287094987689326229U), 29U);
            //
            aIngress = RotL64(aOrbiterJ, 23U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 43U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 29U));
            aIngress = aIngress + (RotL64(aOrbiterD, 35U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterB, 52U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aCross, 18U) + aOrbiterA) + RotL64(aOrbiterF, 53U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 13U) + aOrbiterI) + RotL64(aOrbiterB, 23U));
            aWandererB = aWandererB + ((((RotL64(aPrevious, 37U) + RotL64(aOrbiterF, 41U)) + aOrbiterJ) + RotL64(aCarry, 43U)) + aNonceWordG);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 57U) + aOrbiterJ) + RotL64(aOrbiterG, 36U));
            aWandererG = aWandererG + (((RotL64(aCross, 23U) + RotL64(aOrbiterH, 57U)) + aOrbiterJ) + aNonceWordN);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 28U) + aOrbiterD) + RotL64(aOrbiterF, 19U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aScatter, 3U) + aOrbiterA) + RotL64(aOrbiterB, 11U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterH, 6U)) + aOrbiterF) + aNonceWordL);
            aWandererJ = aWandererJ + (((((RotL64(aCross, 51U) + RotL64(aOrbiterE, 27U)) + aOrbiterH) + RotL64(aCarry, 51U)) + aNonceWordF) + aPhaseFWandererUpdateSaltC[((aIndex + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 29U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererC, 24U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererD, 35U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererG, 43U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererK, 21U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aSnowLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_f loop 2
        // ingress from: aSnowLaneC, aOperationLaneC, aOperationLaneD, aInvestLaneD
        // ingress directions: aSnowLaneC forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aInvestLaneD forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aWorkLaneC
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aWorkLaneC backward/forward random
        // write to: aSnowLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneC[((aIndex + 10339U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneC[((aIndex + 6211U)) & S_BLOCK1], 19U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 5629U)) & S_BLOCK1], 57U) ^ RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 6466U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 8400U)) & S_BLOCK1], 60U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 8445U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 10464U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCross, 11U) ^ RotL64(aIngress, 26U)) + (RotL64(aCarry, 41U) + RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterC = (aWandererH + RotL64(aScatter, 53U)) + 10336802574069791273U;
            aOrbiterB = (((aWandererC + RotL64(aCross, 34U)) + 169025388197058936U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordC;
            aOrbiterK = ((aWandererK + RotL64(aIngress, 27U)) + RotL64(aCarry, 35U)) + 6541354188379168846U;
            aOrbiterD = ((aWandererG + RotL64(aPrevious, 41U)) + RotL64(aCarry, 47U)) + 16223920526599306104U;
            aOrbiterE = (aWandererD + RotL64(aIngress, 19U)) + 12756613707692514808U;
            aOrbiterF = ((aWandererI + RotL64(aCross, 5U)) + RotL64(aCarry, 3U)) + 5082475548176484035U;
            aOrbiterA = ((aWandererF + RotL64(aScatter, 47U)) + 4907435526952698526U) + aPhaseFOrbiterAssignSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterJ = ((aWandererA + RotL64(aPrevious, 13U)) + 14236627073831834337U) + aNonceWordB;
            aOrbiterH = (aWandererJ + RotL64(aIngress, 58U)) + 11502511046130497584U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 3679044835550219497U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 11254838916686736746U;
            aOrbiterK = RotL64((aOrbiterK * 8631695922983532915U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 10582608424233200966U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 10449735026385340313U;
            aOrbiterE = RotL64((aOrbiterE * 7363770199734997411U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 4628253464169957835U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 17664454668473204465U;
            aOrbiterF = RotL64((aOrbiterF * 4234720298731378527U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 3798386391743884889U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 1379331161819246587U;
            aOrbiterB = RotL64((aOrbiterB * 13086160171095077295U), 27U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterC) + 9816600392407327227U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1]) + aNonceWordK;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 16781971616348376878U;
            aOrbiterJ = RotL64((aOrbiterJ * 12503867584828289879U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 4807797577690520554U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 2492057261148595922U;
            aOrbiterD = RotL64((aOrbiterD * 9453302540675483005U), 39U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 7909676419643119585U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 256053568910383007U;
            aOrbiterC = RotL64((aOrbiterC * 11965085163352053161U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 16179914439220412472U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 3968867762761955845U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7473632378251893139U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 7474832923901283742U) + aNonceWordI;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 4736994731050735779U;
            aOrbiterH = RotL64((aOrbiterH * 9839654409121414047U), 23U);
            //
            aIngress = RotL64(aOrbiterF, 43U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 13U));
            aIngress = aIngress + (RotL64(aOrbiterA, 5U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterJ, 60U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterD, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aIngress, 58U) + RotL64(aOrbiterJ, 41U)) + aOrbiterE);
            aWandererG = aWandererG + ((RotL64(aScatter, 37U) + RotL64(aOrbiterE, 23U)) + aOrbiterK);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 5U) + aOrbiterA) + RotL64(aOrbiterK, 46U)) + aNonceWordE);
            aWandererD = aWandererD + (((RotL64(aCross, 43U) + RotL64(aOrbiterF, 19U)) + aOrbiterK) + aPhaseFWandererUpdateSaltD[((aIndex + 3U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 23U) + RotL64(aOrbiterD, 5U)) + aOrbiterB) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aCross, 11U) + aOrbiterD) + RotL64(aOrbiterC, 57U)) + RotL64(aCarry, 29U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 48U) + aOrbiterK) + RotL64(aOrbiterD, 34U));
            aWandererI = aWandererI + ((((RotL64(aScatter, 19U) + aOrbiterE) + RotL64(aOrbiterH, 27U)) + RotL64(aCarry, 47U)) + aNonceWordG);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterA, 53U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 50U));
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererF, 5U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererA, 43U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererG, 39U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aSnowLaneD[((aIndex + 15780U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneA[((aIndex + 11126U)) & S_BLOCK1], 6U));
            aIngress ^= RotL64(aWorkLaneD[((aIndex + 12445U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 11043U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 11641U)) & S_BLOCK1], 50U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aPrevious, 19U) + RotL64(aCarry, 56U)) ^ (RotL64(aCross, 5U) ^ RotL64(aIngress, 43U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterJ = ((aWandererK + RotL64(aCross, 53U)) + 9471546960258473684U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterA = (aWandererA + RotL64(aIngress, 5U)) + 18050235435948942244U;
            aOrbiterD = ((aWandererC + RotL64(aPrevious, 26U)) + 3005107102671544641U) + aNonceWordK;
            aOrbiterH = (((aWandererH + RotL64(aScatter, 41U)) + RotL64(aCarry, 5U)) + 17898396434573801850U) + aNonceWordO;
            aOrbiterE = (aWandererI + RotL64(aPrevious, 21U)) + 15071602525497771648U;
            aOrbiterG = (aWandererE + RotL64(aScatter, 35U)) + 5780119462702672108U;
            aOrbiterI = (((aWandererF + RotL64(aCross, 58U)) + RotL64(aCarry, 57U)) + 13301326224151025687U) + aNonceWordJ;
            aOrbiterB = (((aWandererD + RotL64(aIngress, 47U)) + 18129323022260575961U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordE;
            aOrbiterK = ((aWandererG + RotL64(aPrevious, 13U)) + RotL64(aCarry, 43U)) + 1199228670638790709U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 1839199978088021020U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 4999517042246790165U) ^ aNonceWordM;
            aOrbiterD = RotL64((aOrbiterD * 4585813675677234577U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 8788607633376516299U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 15143903839930468749U;
            aOrbiterE = RotL64((aOrbiterE * 12735914889325422675U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 16674732686428431869U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 15908873150953195581U) ^ aNonceWordD;
            aOrbiterB = RotL64((aOrbiterB * 18049755517524334107U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 11204775359756474667U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 2525984309543939465U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3988529812023791571U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 4566345170476825512U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 14876612901557406267U;
            aOrbiterH = RotL64((aOrbiterH * 9047956948845135339U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 14926290877038883931U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterK) ^ 12710203178186614846U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterG = RotL64((aOrbiterG * 14841163494801662515U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 7315094513967387996U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterI) ^ 11050116830482816766U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterK = RotL64((aOrbiterK * 3702999495721152019U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 4505368486032503953U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 17905748055257551092U;
            aOrbiterJ = RotL64((aOrbiterJ * 14775870175093453197U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 5728886950801376350U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 17998141690182325170U;
            aOrbiterI = RotL64((aOrbiterI * 16008599930125391379U), 37U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterK, 5U);
            aIngress = aIngress + (RotL64(aOrbiterG, 38U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 43U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 53U));
            aIngress = aIngress + RotL64(aOrbiterI, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aScatter, 23U) + RotL64(aOrbiterB, 51U)) + aOrbiterK) + RotL64(aCarry, 3U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 48U) + RotL64(aOrbiterE, 23U)) + aOrbiterI) + aPhaseFWandererUpdateSaltB[((aIndex + 12U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aPrevious, 39U) + RotL64(aOrbiterH, 43U)) + aOrbiterG);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 5U) + RotL64(aOrbiterA, 58U)) + aOrbiterJ) + aNonceWordB);
            aWandererH = aWandererH + ((((RotL64(aScatter, 57U) + aOrbiterE) + RotL64(aOrbiterH, 29U)) + aNonceWordP) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 52U) + RotL64(aOrbiterH, 13U)) + aOrbiterD);
            aWandererG = aWandererG + ((RotL64(aPrevious, 27U) + aOrbiterB) + RotL64(aOrbiterI, 47U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 19U) + aOrbiterH) + RotL64(aOrbiterB, 39U)) + aNonceWordG);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 43U) + aOrbiterE) + RotL64(aOrbiterJ, 4U)) + RotL64(aCarry, 51U)) + aNonceWordL);
            //
            aCarry = aCarry + (RotL64(aWandererA, 51U) ^ aWandererE);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 11U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 34U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 39U));
            aCarry = aCarry + RotL64(aWandererG, 29U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 20035U)) & S_BLOCK1], 5U) ^ RotL64(aSnowLaneC[((aIndex + 18346U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aInvestLaneC[((aIndex + 20344U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 19724U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneD[((aIndex + 17952U)) & S_BLOCK1], 42U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aIngress, 50U) + RotL64(aCarry, 21U)) ^ (RotL64(aPrevious, 5U) ^ RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterG = ((((aWandererI + RotL64(aCross, 14U)) + RotL64(aCarry, 29U)) + 2101601659597850213U) + aPhaseFOrbiterAssignSaltC[((aIndex + 13U)) & S_SALT1]) + aNonceWordC;
            aOrbiterD = (aWandererJ + RotL64(aScatter, 43U)) + 2759794072560720121U;
            aOrbiterI = (aWandererG + RotL64(aIngress, 35U)) + 9443562552411269339U;
            aOrbiterC = (((aWandererD + RotL64(aPrevious, 39U)) + RotL64(aCarry, 43U)) + 10801360546699857975U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = (aWandererK + RotL64(aScatter, 23U)) + 8020716394829332019U;
            aOrbiterJ = (aWandererC + RotL64(aIngress, 51U)) + 1021894212367773801U;
            aOrbiterF = (aWandererA + RotL64(aPrevious, 5U)) + 13346855534622490176U;
            aOrbiterH = ((aWandererB + RotL64(aCross, 57U)) + 16359309548462953836U) + aNonceWordH;
            aOrbiterB = (((aWandererF + RotL64(aScatter, 30U)) + RotL64(aCarry, 57U)) + 12642446944680783519U) + aNonceWordK;
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 8197424982767553380U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 14346334610901859094U;
            aOrbiterI = RotL64((aOrbiterI * 16982899923227935679U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 14171304260534233539U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 334531601308283605U) ^ aNonceWordO;
            aOrbiterE = RotL64((aOrbiterE * 5012968232749075075U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 10707856298471572695U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterE) ^ 18364775750091914766U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterJ = RotL64((aOrbiterJ * 15735143943129143265U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 8531394793118363836U) + aNonceWordA;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 15352876929406908882U;
            aOrbiterH = RotL64((aOrbiterH * 475199047053777179U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 567682016232278157U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 2068146551757663119U;
            aOrbiterD = RotL64((aOrbiterD * 1557877740957797555U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 7776122587613256525U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 16430938890724272256U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4540270493783593257U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 11912000645055436094U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 16800749242578741498U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 17804584625034241737U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 5909199180260499150U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 5751089915336865588U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 15376689503142397927U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 3478216857728853008U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 18007567146937338241U) ^ aNonceWordF;
            aOrbiterB = RotL64((aOrbiterB * 6620498877303917855U), 51U);
            //
            aIngress = RotL64(aOrbiterC, 19U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 40U));
            aIngress = aIngress + (RotL64(aOrbiterG, 57U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 47U));
            aIngress = aIngress + RotL64(aOrbiterI, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterE, 5U)) + aOrbiterG) + aNonceWordL);
            aWandererC = aWandererC + ((RotL64(aCross, 36U) + aOrbiterE) + RotL64(aOrbiterJ, 27U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 23U) + aOrbiterE) + RotL64(aOrbiterI, 19U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 53U) + aOrbiterF) + RotL64(aOrbiterI, 40U)) + aNonceWordB);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 27U) + aOrbiterJ) + RotL64(aOrbiterF, 35U)) + aNonceWordN);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 5U) + RotL64(aOrbiterF, 57U)) + aOrbiterH) + RotL64(aCarry, 11U)) + aPhaseFWandererUpdateSaltA[((aIndex + 15U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 11U) + RotL64(aOrbiterH, 53U)) + aOrbiterC) + aPhaseFWandererUpdateSaltC[((aIndex + 9U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aCross, 18U) + RotL64(aOrbiterD, 23U)) + aOrbiterG) + RotL64(aCarry, 35U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 47U) + aOrbiterB) + RotL64(aOrbiterH, 44U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 24U) ^ aWandererD);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 41U));
            aCarry = aCarry + (RotL64(aWandererB, 11U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererF, 29U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererA, 18U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 23486U)) & S_BLOCK1], 43U) ^ RotL64(aSnowLaneD[((aIndex + 26286U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 26499U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 24572U)) & S_BLOCK1], 53U) ^ RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 22009U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCarry, 35U) ^ RotL64(aIngress, 51U)) + (RotL64(aPrevious, 4U) ^ RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterJ = ((aWandererE + RotL64(aPrevious, 46U)) + 11210042748013785976U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterC = (aWandererH + RotL64(aScatter, 19U)) + 4584747303233477454U;
            aOrbiterD = ((aWandererK + RotL64(aIngress, 27U)) + 8878765929792969517U) + aPhaseFOrbiterAssignSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterB = (aWandererA + RotL64(aCross, 23U)) + 2172232330280041122U;
            aOrbiterK = (((aWandererD + RotL64(aScatter, 57U)) + RotL64(aCarry, 3U)) + 8378937026022264016U) + aNonceWordA;
            aOrbiterA = (aWandererF + RotL64(aIngress, 37U)) + 8683007464695824208U;
            aOrbiterH = ((aWandererJ + RotL64(aCross, 11U)) + RotL64(aCarry, 41U)) + 9564352997357118134U;
            aOrbiterG = ((aWandererC + RotL64(aPrevious, 41U)) + RotL64(aCarry, 13U)) + 11713878436769887528U;
            aOrbiterE = ((aWandererG + RotL64(aIngress, 52U)) + 8052917623074021077U) + aNonceWordG;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 7720597162792145185U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterD = (((aOrbiterD ^ aOrbiterJ) ^ 2602847785328475621U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterD = RotL64((aOrbiterD * 14065077077207224525U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 17813669222300509724U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 8724263063156573013U;
            aOrbiterK = RotL64((aOrbiterK * 3632927017737834359U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 6882429835961613492U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 13213313479525717359U;
            aOrbiterA = RotL64((aOrbiterA * 2411431247725974895U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 2401526093648669573U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 3616448566579979749U) ^ aNonceWordE;
            aOrbiterJ = RotL64((aOrbiterJ * 13323155103752121393U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 18268262471839710401U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 5116424918948694752U;
            aOrbiterE = RotL64((aOrbiterE * 7641143782996332069U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 11405305689555640431U) + aNonceWordC;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 12427591396711015574U;
            aOrbiterG = RotL64((aOrbiterG * 8112834135715541223U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 16960781161508084626U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterA) ^ 12382604781005282628U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterH = RotL64((aOrbiterH * 17196168631120103115U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 10054839091354729292U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 4167641616532985407U;
            aOrbiterC = RotL64((aOrbiterC * 919291747187787625U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 14383737233143309039U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 16258779988369405932U;
            aOrbiterB = RotL64((aOrbiterB * 8348773195366160215U), 47U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterG, 11U);
            aIngress = aIngress + (RotL64(aOrbiterD, 30U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterB, 57U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterJ, 47U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterE, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aIngress, 23U) + aOrbiterE) + RotL64(aOrbiterB, 6U)) + aNonceWordI);
            aWandererG = aWandererG + ((RotL64(aScatter, 41U) + RotL64(aOrbiterA, 19U)) + aOrbiterK);
            aWandererJ = aWandererJ ^ ((((RotL64(aPrevious, 30U) + RotL64(aOrbiterE, 57U)) + aOrbiterJ) + aNonceWordM) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aCross, 35U) + aOrbiterD) + RotL64(aOrbiterG, 47U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 47U) + aOrbiterJ) + RotL64(aOrbiterC, 30U)) + aNonceWordD);
            aWandererK = aWandererK + (((RotL64(aCross, 53U) + aOrbiterA) + RotL64(aOrbiterH, 23U)) + RotL64(aCarry, 41U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 14U) + RotL64(aOrbiterD, 51U)) + aOrbiterA);
            aWandererD = aWandererD + ((((RotL64(aIngress, 19U) + RotL64(aOrbiterC, 43U)) + aOrbiterK) + RotL64(aCarry, 27U)) + aNonceWordF);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterG, 37U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 53U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + (RotL64(aWandererH, 29U) ^ aWandererG);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 47U));
            aCarry = aCarry + RotL64(aWandererD, 18U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_f loop 6
        // ingress from: aExpandLaneC, aExpandLaneA, aInvestLaneB
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aInvestLaneB forward/backward random
        // cross from: aExpandLaneB, aOperationLaneB
        // cross directions: aExpandLaneB backward forced, aOperationLaneB backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 30989U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneA[((aIndex + 30662U)) & S_BLOCK1], 42U));
            aIngress ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 29004U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29031U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneB[((aIndex + 31401U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aPrevious, 57U) ^ RotL64(aCross, 18U)) ^ (RotL64(aIngress, 5U) + RotL64(aCarry, 43U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterF = ((aWandererB + RotL64(aCross, 19U)) + RotL64(aCarry, 53U)) + 4980738603982643969U;
            aOrbiterB = ((aWandererF + RotL64(aScatter, 39U)) + 17660278413018470020U) + aPhaseFOrbiterAssignSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = (((aWandererD + RotL64(aPrevious, 11U)) + RotL64(aCarry, 37U)) + 17598114429859543466U) + aNonceWordK;
            aOrbiterC = ((aWandererE + RotL64(aIngress, 46U)) + 10993929335279994739U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterJ = (aWandererJ + RotL64(aCross, 51U)) + 17967203122976322481U;
            aOrbiterH = (aWandererK + RotL64(aPrevious, 57U)) + 1872290205549034384U;
            aOrbiterD = ((aWandererC + RotL64(aScatter, 23U)) + 16607778671782810797U) + aNonceWordF;
            aOrbiterG = ((aWandererG + RotL64(aIngress, 35U)) + RotL64(aCarry, 11U)) + 4895226930754394376U;
            aOrbiterA = (aWandererI + RotL64(aPrevious, 28U)) + 14960359005982301383U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 9921642352377700630U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 893281964367208693U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2345509157333444217U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 8232519988397858732U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 4433022122758913407U) ^ aNonceWordC;
            aOrbiterH = RotL64((aOrbiterH * 834240393225479419U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 12689609831247168353U) + aNonceWordI;
            aOrbiterB = (((aOrbiterB ^ aOrbiterD) ^ 404535388957472176U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterB = RotL64((aOrbiterB * 14534020545479806593U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 3349108201964013155U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 4386449511297371730U;
            aOrbiterF = RotL64((aOrbiterF * 9596273264321140229U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 14314587717949070586U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 10923886625271054985U;
            aOrbiterC = RotL64((aOrbiterC * 7838969002623486809U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 17634909585329833520U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 2021301459918350372U;
            aOrbiterA = RotL64((aOrbiterA * 1388242915918642741U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 5219599112498224367U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 10641339455385046206U) ^ aNonceWordA;
            aOrbiterD = RotL64((aOrbiterD * 1022283727595400719U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 5003342156562330058U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 10951027475628404336U;
            aOrbiterG = RotL64((aOrbiterG * 17836928292555158461U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 13040991872592235460U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 11149099984302782267U;
            aOrbiterJ = RotL64((aOrbiterJ * 4248667283139686251U), 35U);
            //
            aIngress = RotL64(aOrbiterH, 43U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 60U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 39U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 5U));
            aIngress = aIngress + RotL64(aOrbiterB, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aIngress, 53U) + aOrbiterH) + RotL64(aOrbiterD, 39U)) + aNonceWordB);
            aWandererC = aWandererC + (((RotL64(aPrevious, 30U) + aOrbiterA) + RotL64(aOrbiterF, 19U)) + RotL64(aCarry, 39U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterH, 28U)) + aOrbiterJ);
            aWandererD = aWandererD + (((RotL64(aScatter, 57U) + aOrbiterH) + RotL64(aOrbiterG, 35U)) + RotL64(aCarry, 3U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 3U) + aOrbiterJ) + RotL64(aOrbiterC, 23U)) + aNonceWordP);
            aWandererG = aWandererG + (((RotL64(aPrevious, 23U) + RotL64(aOrbiterB, 11U)) + aOrbiterK) + aPhaseFWandererUpdateSaltB[((aIndex + 11U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 12U) + RotL64(aOrbiterA, 46U)) + aOrbiterH) + aNonceWordE);
            aWandererK = aWandererK + (((RotL64(aScatter, 47U) + aOrbiterB) + RotL64(aOrbiterH, 51U)) + aPhaseFWandererUpdateSaltE[((aIndex + 7U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 37U) + aOrbiterJ) + RotL64(aOrbiterG, 57U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 57U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 54U));
            aCarry = aCarry + (RotL64(aWandererC, 41U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererG, 47U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererE, 3U);
            aCarry = aCarry + RotL64(aIngress, 38U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xD334651B64303771ULL + 0xA895178ED866A7C6ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xDEB8937AECCA29D9ULL + 0xA3033993889E5235ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xDE94F30A561BD03DULL + 0xE819BAD952ECCB1AULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xB39E72D9390BFC2DULL + 0xBA2BD4E699F6A993ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xB2A834672F800105ULL + 0x93619C62FDDC8A5FULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xFD9E943250FD9AF3ULL + 0xF4FBE100E2C5426CULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x90C24F1DAEB71B87ULL + 0x9A99458E2C55FE03ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x8D9211AF83D94FC9ULL + 0xD0ADC7AB95BEC3E5ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xEB2F3A0FFB3999FDULL + 0xACA69462197410E5ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x902AED83E091701BULL + 0xBC1EF964C5F2813DULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0x83F59E463F3AA8DFULL + 0xF0230467CE1515E1ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xA9FE7765A102C61DULL + 0x9774D02A0D5D7529ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xE4E77C468C172C85ULL + 0xF5C53B55596ABCDCULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0x86B89F555A016507ULL + 0xFD9F8B53F2EC7F98ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xD2CA5D7B527F23FDULL + 0x89AC6D61017B837EULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xACCB26740BD3CCE3ULL + 0x917E9AC9DF85960BULL);
    // GSeedRunSeed_G seed_loop_h (start)
    {
        // GSeedRunSeed_G seed_loop_h lane group
        // read from: aSnowLaneA, aSnowLaneB, aFireLaneA, aSnowLaneC, aSnowLaneD, aInvestLaneB, aWorkLaneA, aFireLaneB, aInvestLaneC, aWorkLaneB, aFireLaneC, aExpandLaneA, aInvestLaneA, aExpandLaneB, aFireLaneD, aExpandLaneC, aInvestLaneD
        // write to: aWorkLaneA, aWorkLaneB, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // seed_loop_h loop 1
        // ingress from: aSnowLaneA, aSnowLaneB, aFireLaneA
        // ingress directions: aSnowLaneA forward forced, aSnowLaneB forward forced, aFireLaneA forward/backward random
        // cross from: aSnowLaneC, aSnowLaneD, aInvestLaneB
        // cross directions: aSnowLaneC backward forced, aSnowLaneD backward forced, aInvestLaneB backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneA[((aIndex + 4315U)) & S_BLOCK1], 27U) ^ RotL64(aSnowLaneB[((aIndex + 1693U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 3301U)) & S_BLOCK1], 18U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 1161U)) & S_BLOCK1], 5U) ^ RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 3021U)) & S_BLOCK1], 30U));
            aCross ^= RotL64(aInvestLaneB[((aIndex + 1948U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aIngress, 35U)) + (RotL64(aPrevious, 18U) ^ RotL64(aCross, 51U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterH = ((aWandererA + RotL64(aCross, 29U)) + 5131645209694953015U) + aNonceWordE;
            aOrbiterK = ((((aWandererH + RotL64(aPrevious, 43U)) + RotL64(aCarry, 11U)) + 12070391048835379854U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordN;
            aOrbiterD = ((aWandererC + RotL64(aIngress, 60U)) + RotL64(aCarry, 27U)) + 2604295836242338724U;
            aOrbiterJ = ((aWandererJ + RotL64(aScatter, 37U)) + 14042039029284001596U) + aNonceWordH;
            aOrbiterA = (((aWandererD + RotL64(aCross, 5U)) + RotL64(aCarry, 51U)) + 8914654543854559327U) + aNonceWordM;
            aOrbiterC = (aWandererK + RotL64(aPrevious, 13U)) + 2185619407969359869U;
            aOrbiterE = ((aWandererE + RotL64(aScatter, 19U)) + 5187406295103352574U) + aPhaseHOrbiterAssignSaltD[((aIndex + 19U)) & S_SALT1];
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 8022832481290871217U) + aNonceWordO;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 8783061916740573472U;
            aOrbiterD = RotL64((aOrbiterD * 3309891377744201773U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 10711028365596196301U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 13387065038269133571U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 12444578026365205255U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 11187001318931801582U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 14191473173276034019U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2491253922434756431U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 16207761776716426435U) + aNonceWordA;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 9677408414452078760U;
            aOrbiterC = RotL64((aOrbiterC * 5487303383095129949U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 17812460332794370649U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 7736423148554132028U;
            aOrbiterE = RotL64((aOrbiterE * 15588733747232852555U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 17293203944059014763U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 13487243633338010243U;
            aOrbiterJ = RotL64((aOrbiterJ * 9468688858740539095U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 15979293016815060755U) + aNonceWordL;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 17645215484691359547U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 1449450767288733995U), 29U);
            //
            aIngress = RotL64(aOrbiterA, 50U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterD, 41U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 5U));
            aIngress = aIngress + RotL64(aOrbiterH, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aIngress, 51U) + aOrbiterH) + RotL64(aOrbiterE, 13U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 41U) + aOrbiterK) + RotL64(aOrbiterE, 57U)) + RotL64(aCarry, 21U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterD, 35U)) + aOrbiterC) + aNonceWordB);
            aWandererD = aWandererD + (((RotL64(aPrevious, 12U) + RotL64(aOrbiterJ, 42U)) + aOrbiterA) + RotL64(aCarry, 57U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterE, 51U)) + aOrbiterD);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 23U) + RotL64(aOrbiterD, 5U)) + aOrbiterJ) + aNonceWordG) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((((RotL64(aIngress, 29U) + aOrbiterK) + RotL64(aOrbiterC, 23U)) + aNonceWordP) + aPhaseHWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 14U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererH, 37U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererD, 5U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererE, 23U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_h loop 2
        // ingress from: aWorkLaneA, aSnowLaneC, aSnowLaneD, aFireLaneB
        // ingress directions: aWorkLaneA forward forced, aSnowLaneC forward forced, aSnowLaneD forward forced, aFireLaneB forward/backward random
        // cross from: aSnowLaneA, aSnowLaneB, aInvestLaneC
        // cross directions: aSnowLaneA backward forced, aSnowLaneB backward forced, aInvestLaneC backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 10444U)) & S_BLOCK1], 51U) ^ RotL64(aSnowLaneC[((aIndex + 8117U)) & S_BLOCK1], 43U));
            aIngress ^= (RotL64(aSnowLaneD[((aIndex + 8805U)) & S_BLOCK1], 10U) ^ RotL64(aFireLaneB[((aIndex + 5744U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 10786U)) & S_BLOCK1], 13U) ^ RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 8061U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 10144U)) & S_BLOCK1], 44U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aPrevious, 39U) + RotL64(aCarry, 20U)) ^ (RotL64(aIngress, 3U) ^ RotL64(aCross, 51U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterK = ((aWandererD + RotL64(aPrevious, 29U)) + 16160838483846078448U) + aNonceWordO;
            aOrbiterC = (((aWandererG + RotL64(aIngress, 39U)) + RotL64(aCarry, 5U)) + 15404960896190227946U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterH = (aWandererH + RotL64(aCross, 13U)) + 16904160594024977199U;
            aOrbiterJ = (((aWandererC + RotL64(aScatter, 47U)) + RotL64(aCarry, 51U)) + 17790460246821031802U) + aNonceWordN;
            aOrbiterF = (aWandererJ + RotL64(aCross, 53U)) + 16395168254086971959U;
            aOrbiterG = ((aWandererA + RotL64(aPrevious, 6U)) + RotL64(aCarry, 39U)) + 7484373204039901786U;
            aOrbiterB = ((aWandererE + RotL64(aIngress, 21U)) + 18026814691322913510U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 15244817793136966450U) + aNonceWordK;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 5795491730356335666U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 13253529465289332171U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 3163873518027801504U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 2690791759507349172U;
            aOrbiterF = RotL64((aOrbiterF * 16677948635136515083U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 17898067251167087906U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 8028010015006604239U;
            aOrbiterK = RotL64((aOrbiterK * 5601629670521300241U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 7304739457289910555U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 6476837815096530043U;
            aOrbiterC = RotL64((aOrbiterC * 16380545138701113267U), 5U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterJ) + 14242499233467960602U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordF;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 17305645693017634630U;
            aOrbiterG = RotL64((aOrbiterG * 14442976693206929569U), 39U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 9772864059444171908U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 7897200728282156408U;
            aOrbiterB = RotL64((aOrbiterB * 816306719390807411U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 4890999319172950996U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 8165132649356094963U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 17297706071263690189U), 29U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterH, 35U);
            aIngress = aIngress + (RotL64(aOrbiterF, 20U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 47U));
            aIngress = aIngress + RotL64(aOrbiterC, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aIngress, 13U) + aOrbiterH) + RotL64(aOrbiterK, 41U)) + aNonceWordB);
            aWandererG = aWandererG + (((RotL64(aScatter, 51U) + RotL64(aOrbiterG, 29U)) + aOrbiterK) + aNonceWordG);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 27U) + aOrbiterK) + RotL64(aOrbiterC, 50U)) + aNonceWordA);
            aWandererA = aWandererA + ((((RotL64(aCross, 3U) + aOrbiterB) + RotL64(aOrbiterJ, 11U)) + RotL64(aCarry, 3U)) + aPhaseHWandererUpdateSaltB[((aIndex + 27U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterF, 21U)) + aOrbiterG);
            aWandererH = aWandererH + (((RotL64(aPrevious, 43U) + aOrbiterH) + RotL64(aOrbiterJ, 5U)) + RotL64(aCarry, 43U));
            aWandererE = aWandererE ^ ((((RotL64(aIngress, 36U) + aOrbiterB) + RotL64(aOrbiterK, 57U)) + aNonceWordC) + aPhaseHWandererUpdateSaltF[((aIndex + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 30U) ^ aWandererC);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 43U));
            aCarry = aCarry + (RotL64(aWandererJ, 51U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererA, 13U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_h loop 3
        // ingress from: aWorkLaneB, aSnowLaneA, aFireLaneC
        // ingress directions: aWorkLaneB forward forced, aSnowLaneA forward forced, aFireLaneC forward/backward random
        // cross from: aWorkLaneA, aSnowLaneC
        // cross directions: aWorkLaneA backward forced, aSnowLaneC backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 15233U)) & S_BLOCK1], 47U) ^ RotL64(aSnowLaneA[((aIndex + 13817U)) & S_BLOCK1], 58U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 11540U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 12301U)) & S_BLOCK1], 21U) ^ RotL64(aSnowLaneC[((aIndex + 13037U)) & S_BLOCK1], 4U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aPrevious, 58U) + RotL64(aCarry, 27U)) ^ (RotL64(aCross, 13U) ^ RotL64(aIngress, 41U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterB = (aWandererF + RotL64(aPrevious, 36U)) + 5510690816044082200U;
            aOrbiterE = (aWandererA + RotL64(aCross, 47U)) + 15967820875033940530U;
            aOrbiterA = ((aWandererK + RotL64(aIngress, 29U)) + 539348720848176221U) + aNonceWordM;
            aOrbiterJ = ((((aWandererB + RotL64(aScatter, 5U)) + RotL64(aCarry, 43U)) + 15779318183635560817U) + aPhaseHOrbiterAssignSaltB[((aIndex + 3U)) & S_SALT1]) + aNonceWordK;
            aOrbiterK = ((((aWandererH + RotL64(aIngress, 57U)) + RotL64(aCarry, 29U)) + 14511058534424187469U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordF;
            aOrbiterG = ((aWandererE + RotL64(aPrevious, 23U)) + RotL64(aCarry, 5U)) + 5811130556873428391U;
            aOrbiterF = (aWandererI + RotL64(aCross, 11U)) + 1085928476499444025U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 6973335316600768130U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 10747243745475009744U) ^ aNonceWordJ;
            aOrbiterA = RotL64((aOrbiterA * 17322489216048017061U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 1072260008981349754U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 2018772405352495753U;
            aOrbiterG = RotL64((aOrbiterG * 10840562112080574241U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 1092091597048996547U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 15103140149542167197U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 621856991658027989U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 13194619321108681542U) + aNonceWordA;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 16749188603268621850U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 9575408950550922039U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 7427959503086895166U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 9895804051379551393U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2701997336201570715U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 4526020800679774259U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 4484850928870048176U;
            aOrbiterK = RotL64((aOrbiterK * 17556987520625677313U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 1837404844299040155U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 15213208978489570694U;
            aOrbiterF = RotL64((aOrbiterF * 7062740584650274133U), 21U);
            //
            aIngress = RotL64(aOrbiterB, 11U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 23U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 53U));
            aIngress = aIngress + RotL64(aOrbiterF, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((((RotL64(aPrevious, 57U) + RotL64(aOrbiterK, 19U)) + aOrbiterF) + RotL64(aCarry, 57U)) + aNonceWordB) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 27U) + aOrbiterE) + RotL64(aOrbiterF, 11U));
            aWandererK = aWandererK + (((RotL64(aScatter, 21U) + RotL64(aOrbiterE, 37U)) + aOrbiterG) + aNonceWordD);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 47U) + aOrbiterF) + RotL64(aOrbiterA, 51U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 37U) + aOrbiterG) + RotL64(aOrbiterB, 3U)) + aNonceWordE);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 5U) + aOrbiterJ) + RotL64(aOrbiterA, 58U)) + aNonceWordI);
            aWandererI = aWandererI + ((((RotL64(aCross, 12U) + RotL64(aOrbiterK, 29U)) + aOrbiterJ) + RotL64(aCarry, 39U)) + aPhaseHWandererUpdateSaltD[((aIndex + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 54U));
            aCarry = aCarry + (RotL64(aWandererF, 5U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererI, 29U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererE, 11U);
            aCarry = aCarry + RotL64(aIngress, 60U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_h loop 4
        // ingress from: aExpandLaneA, aWorkLaneA, aInvestLaneA
        // ingress directions: aExpandLaneA forward forced, aWorkLaneA forward forced, aInvestLaneA forward/backward random
        // cross from: aWorkLaneB, aSnowLaneD
        // cross directions: aWorkLaneB backward forced, aSnowLaneD backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 21112U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneA[((aIndex + 16710U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aInvestLaneA[((aIndex + 18990U)) & S_BLOCK1], 42U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 21492U)) & S_BLOCK1], 51U) ^ RotL64(aSnowLaneD[((aIndex + 18856U)) & S_BLOCK1], 20U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCarry, 39U) ^ RotL64(aIngress, 21U)) + (RotL64(aCross, 4U) + RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterG = (((aWandererA + RotL64(aScatter, 3U)) + 8975885703279267062U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordB;
            aOrbiterF = ((aWandererI + RotL64(aPrevious, 12U)) + RotL64(aCarry, 41U)) + 8664844915562660637U;
            aOrbiterI = ((aWandererG + RotL64(aCross, 53U)) + RotL64(aCarry, 21U)) + 12281774799736296726U;
            aOrbiterH = (aWandererE + RotL64(aIngress, 21U)) + 15347461352311329726U;
            aOrbiterK = (aWandererD + RotL64(aScatter, 27U)) + 12967500561828907834U;
            aOrbiterD = (aWandererK + RotL64(aPrevious, 43U)) + 5002833859280402726U;
            aOrbiterC = ((((aWandererH + RotL64(aIngress, 37U)) + RotL64(aCarry, 3U)) + 11908257536954668983U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordK;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 17017174811949227162U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 16851323125613931180U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12446990992858763577U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 13469326957728686706U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 5228638551056105241U;
            aOrbiterG = RotL64((aOrbiterG * 13369947664646167255U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 11945166198089308564U) + aNonceWordI;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 16268645041872996022U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5391448793718370911U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 14781204627695095701U) + aNonceWordD;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 5365325354838101092U;
            aOrbiterD = RotL64((aOrbiterD * 8017284997946310807U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 563147416025715953U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 14660867395395625851U;
            aOrbiterC = RotL64((aOrbiterC * 4769458126865307103U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 3168989056355712105U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 16179131669773665579U) ^ aNonceWordA;
            aOrbiterF = RotL64((aOrbiterF * 5641461617066671723U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 4160220074225527179U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 8597134686962559111U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 639572585431474015U), 3U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterF, 46U);
            aIngress = aIngress + (RotL64(aOrbiterC, 29U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterH, 5U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterI, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aCross, 60U) + aOrbiterI) + RotL64(aOrbiterF, 11U)) + aNonceWordF);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 23U) + RotL64(aOrbiterC, 37U)) + aOrbiterG) + aNonceWordH);
            aWandererD = aWandererD + (((RotL64(aIngress, 37U) + aOrbiterG) + RotL64(aOrbiterK, 27U)) + RotL64(aCarry, 57U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 11U) + RotL64(aOrbiterH, 46U)) + aOrbiterG) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 53U) + RotL64(aOrbiterD, 57U)) + aOrbiterF) + RotL64(aCarry, 27U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 29U) + aOrbiterH) + RotL64(aOrbiterK, 3U));
            aWandererK = aWandererK + ((((RotL64(aScatter, 3U) + RotL64(aOrbiterF, 19U)) + aOrbiterK) + aNonceWordE) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 58U) ^ aWandererD);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 39U));
            aCarry = aCarry + (RotL64(aWandererE, 19U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererK, 3U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_h loop 5
        // ingress from: aExpandLaneB, aWorkLaneB, aFireLaneD
        // ingress directions: aExpandLaneB forward forced, aWorkLaneB forward forced, aFireLaneD forward/backward random
        // cross from: aExpandLaneA, aWorkLaneA
        // cross directions: aExpandLaneA backward forced, aWorkLaneA backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 23259U)) & S_BLOCK1], 56U) ^ RotL64(aWorkLaneB[((aIndex + 24598U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 23324U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 25891U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24663U)) & S_BLOCK1], 48U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aIngress, 3U) ^ RotL64(aCarry, 53U)) + (RotL64(aCross, 39U) + RotL64(aPrevious, 24U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterK = (((aWandererC + RotL64(aScatter, 53U)) + RotL64(aCarry, 19U)) + 4773124477323378268U) + aPhaseHOrbiterAssignSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = ((aWandererA + RotL64(aIngress, 35U)) + RotL64(aCarry, 39U)) + 16848723289435796005U;
            aOrbiterG = ((aWandererB + RotL64(aCross, 41U)) + 13846642134917107058U) + aNonceWordC;
            aOrbiterF = ((aWandererD + RotL64(aPrevious, 47U)) + 6472057872482789939U) + aNonceWordL;
            aOrbiterA = (((aWandererG + RotL64(aIngress, 3U)) + 2747019500690707226U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordH;
            aOrbiterH = ((aWandererF + RotL64(aPrevious, 23U)) + 9003965289739733880U) + aNonceWordJ;
            aOrbiterC = ((aWandererJ + RotL64(aCross, 14U)) + RotL64(aCarry, 57U)) + 3013390651936257377U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 3331004709895625067U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 15355010435553517129U;
            aOrbiterG = RotL64((aOrbiterG * 8322759117004876831U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 7709870658004280052U) + aNonceWordG;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 13568728443963926564U;
            aOrbiterA = RotL64((aOrbiterA * 6736090830113688981U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 12409548853419307131U) + aNonceWordP;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 969183352023661537U;
            aOrbiterF = RotL64((aOrbiterF * 5549220554838837145U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 15370309834426476775U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 3896803894396631184U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 11018830202891911603U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 10848873633291935766U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 12885336509190543440U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 1487357252619221365U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 8252290890093788010U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 9201553615601641350U;
            aOrbiterC = RotL64((aOrbiterC * 420321130559162915U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 14014209645503188472U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 4015071464301844550U;
            aOrbiterJ = RotL64((aOrbiterJ * 17444195018239904971U), 57U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterK, 23U);
            aIngress = aIngress + (RotL64(aOrbiterF, 57U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 47U));
            aIngress = aIngress + RotL64(aOrbiterG, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aIngress, 29U) + aOrbiterA) + RotL64(aOrbiterC, 29U)) + RotL64(aCarry, 19U)) + aPhaseHWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 11U) + aOrbiterH) + RotL64(aOrbiterJ, 13U));
            aWandererC = aWandererC + ((RotL64(aCross, 43U) + aOrbiterF) + RotL64(aOrbiterK, 3U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 56U) + aOrbiterJ) + RotL64(aOrbiterK, 47U)) + aNonceWordK);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 3U) + RotL64(aOrbiterG, 23U)) + aOrbiterH) + RotL64(aCarry, 41U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterG, 58U)) + aOrbiterF);
            aWandererB = aWandererB + ((((RotL64(aCross, 21U) + RotL64(aOrbiterJ, 37U)) + aOrbiterC) + aNonceWordE) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 19U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 4U));
            aCarry = aCarry + (RotL64(aWandererG, 23U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererC, 53U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_h loop 6
        // ingress from: aExpandLaneC, aExpandLaneA, aInvestLaneD
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aInvestLaneD forward/backward random
        // cross from: aExpandLaneB, aSnowLaneB
        // cross directions: aExpandLaneB backward forced, aSnowLaneB backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 29282U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneA[((aIndex + 29346U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 32610U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordD));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31706U)) & S_BLOCK1], 23U) ^ RotL64(aSnowLaneB[((aIndex + 31806U)) & S_BLOCK1], 34U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aPrevious, 29U) ^ RotL64(aCarry, 57U)) ^ (RotL64(aCross, 42U) + RotL64(aIngress, 13U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterJ = ((aWandererI + RotL64(aCross, 21U)) + RotL64(aCarry, 53U)) + 8101351470141807662U;
            aOrbiterG = (aWandererA + RotL64(aScatter, 27U)) + 6965474099521076705U;
            aOrbiterK = (aWandererK + RotL64(aPrevious, 3U)) + 6803828268885684784U;
            aOrbiterA = ((aWandererG + RotL64(aIngress, 11U)) + 13454235922950972488U) + aNonceWordL;
            aOrbiterH = ((aWandererF + RotL64(aScatter, 51U)) + 11678091885751244777U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = ((((aWandererB + RotL64(aPrevious, 35U)) + RotL64(aCarry, 5U)) + 5307134544628507141U) + aPhaseHOrbiterAssignSaltA[((aIndex + 10U)) & S_SALT1]) + aNonceWordK;
            aOrbiterF = ((aWandererJ + RotL64(aIngress, 44U)) + RotL64(aCarry, 41U)) + 4873703518950429353U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 8542156221858586039U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 3993726182905296513U;
            aOrbiterK = RotL64((aOrbiterK * 11331376012938127609U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 12113047622035464386U) + aNonceWordO;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 1944244448665721151U;
            aOrbiterJ = RotL64((aOrbiterJ * 7010050836758762003U), 19U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterK) + 12914188029425467576U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1]) + aNonceWordP;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 2486762763475327024U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12319769994433811617U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 14580191602982245481U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 12093414832400135066U;
            aOrbiterG = RotL64((aOrbiterG * 12720286833215690663U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 13623906997320021065U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 9977356009806428696U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2005536391712733499U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 3694954095397810851U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 11453812627797091638U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13730420725113907161U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 542311345544726351U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 3024285045990499484U;
            aOrbiterH = RotL64((aOrbiterH * 5153745952148205645U), 47U);
            //
            aIngress = RotL64(aOrbiterJ, 28U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterF, 47U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterH, 21U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterA, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 6U) + aOrbiterJ) + RotL64(aOrbiterK, 11U));
            aWandererB = aWandererB + ((((RotL64(aIngress, 29U) + aOrbiterI) + RotL64(aOrbiterF, 29U)) + RotL64(aCarry, 21U)) + aNonceWordB);
            aWandererF = aWandererF ^ (((RotL64(aCross, 35U) + aOrbiterK) + RotL64(aOrbiterF, 41U)) + aPhaseHWandererUpdateSaltD[((aIndex + 18U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 51U) + aOrbiterI) + RotL64(aOrbiterK, 5U)) + aNonceWordC);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterA, 18U)) + aOrbiterH) + aNonceWordI);
            aWandererK = aWandererK + (((RotL64(aCross, 19U) + RotL64(aOrbiterG, 35U)) + aOrbiterA) + RotL64(aCarry, 3U));
            aWandererJ = aWandererJ ^ ((((RotL64(aScatter, 13U) + RotL64(aOrbiterH, 53U)) + aOrbiterG) + aNonceWordF) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 27U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererI, 13U) ^ aWandererF);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 52U));
            aCarry = aCarry + RotL64(aWandererJ, 57U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltC;
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
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltC;
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
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltE;
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
            aIngress = RotL64(aKeyRowReadA[((aIndex + 1086U)) & W_KEY1], 57U) ^ RotL64(aKeyRowReadB[((aIndex + 406U)) & W_KEY1], 42U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 723U)) & W_KEY1], 53U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 2628U)) & S_BLOCK1], 6U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 19U) + RotL64(aCross, 57U)) + (RotL64(aPrevious, 34U) ^ RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterE = ((aWandererG + RotL64(aPrevious, 5U)) + 966899917801652720U) + aPhaseAOrbiterAssignSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterG = ((aWandererJ + RotL64(aIngress, 24U)) + RotL64(aCarry, 5U)) + 10996327672320748649U;
            aOrbiterA = ((aWandererC + RotL64(aScatter, 19U)) + RotL64(aCarry, 37U)) + 4188171566846621107U;
            aOrbiterK = (aWandererD + RotL64(aCross, 41U)) + 5886209243097387959U;
            aOrbiterC = ((aWandererH + RotL64(aIngress, 47U)) + 14940428957136728111U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterD = (aWandererI + RotL64(aScatter, 29U)) + 179187285531914832U;
            aOrbiterI = (aWandererE + RotL64(aPrevious, 13U)) + 6685351948936817752U;
            aOrbiterF = ((aWandererK + RotL64(aCross, 57U)) + RotL64(aCarry, 13U)) + 1894506461704029700U;
            aOrbiterH = (aWandererB + RotL64(aPrevious, 34U)) + 4182760368636977082U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 12523318028514940790U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 5059306166973366892U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2857409765717296483U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 5890872367917643851U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 17747338389865221534U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5306740664798049267U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 13906227834259884100U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 7152105382899756368U;
            aOrbiterK = RotL64((aOrbiterK * 6772157117358310485U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 17868101884759619240U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 11758843266314148347U;
            aOrbiterD = RotL64((aOrbiterD * 5919135169337501485U), 39U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 13950566197090324859U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 17278105609930477854U;
            aOrbiterH = RotL64((aOrbiterH * 11431842718945107359U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 9556785965646738355U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 841298436857932987U;
            aOrbiterG = RotL64((aOrbiterG * 15077843186688841797U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 1951515285492133830U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 15775839819330588437U;
            aOrbiterF = RotL64((aOrbiterF * 7902654031401620995U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 5585458468816495436U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 17258586689032223623U;
            aOrbiterI = RotL64((aOrbiterI * 1652050227399194271U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 5254132659445988836U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 15440741734777060925U;
            aOrbiterC = RotL64((aOrbiterC * 17445581079035134067U), 51U);
            //
            aIngress = RotL64(aOrbiterG, 14U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterI, 23U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 39U));
            aIngress = aIngress + (RotL64(aOrbiterC, 11U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterD, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterI, 58U)) + aOrbiterC);
            aWandererC = aWandererC + (((RotL64(aPrevious, 20U) + aOrbiterI) + RotL64(aOrbiterD, 23U)) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 43U) + aOrbiterA) + RotL64(aOrbiterK, 19U));
            aWandererG = aWandererG + ((RotL64(aCross, 35U) + aOrbiterG) + RotL64(aOrbiterH, 39U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 47U) + aOrbiterD) + RotL64(aOrbiterH, 53U)) + aPhaseAWandererUpdateSaltA[((aIndex + 9U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aIngress, 53U) + aOrbiterI) + RotL64(aOrbiterA, 4U)) + RotL64(aCarry, 23U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 27U) + aOrbiterF) + RotL64(aOrbiterE, 43U));
            aWandererK = aWandererK + (((RotL64(aCross, 4U) + aOrbiterE) + RotL64(aOrbiterI, 47U)) + RotL64(aCarry, 11U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterA, 13U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererK, 37U) ^ aWandererE);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 50U));
            aCarry = aCarry + (RotL64(aWandererI, 27U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererH, 3U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererG, 43U);
            aCarry = aCarry + RotL64(aIngress, 30U);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 4516U)) & S_BLOCK1], 37U) ^ RotL64(aKeyRowReadA[((aIndex + 3158U)) & W_KEY1], 58U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 4698U)) & W_KEY1], 47U) ^ RotL64(mSource[((aIndex + 3343U)) & S_BLOCK1], 4U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 54U) ^ RotL64(aPrevious, 41U)) + (RotL64(aCross, 3U) + RotL64(aIngress, 29U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterH = (aWandererI + RotL64(aCross, 39U)) + 17019646486641172469U;
            aOrbiterB = ((aWandererD + RotL64(aPrevious, 5U)) + 12276141179299971572U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = ((aWandererA + RotL64(aIngress, 14U)) + RotL64(aCarry, 51U)) + 3617241694029841555U;
            aOrbiterI = (aWandererJ + RotL64(aScatter, 47U)) + 6967963401259371737U;
            aOrbiterA = (aWandererK + RotL64(aIngress, 29U)) + 6340709284279891017U;
            aOrbiterF = (((aWandererB + RotL64(aCross, 35U)) + RotL64(aCarry, 3U)) + 456065368903896482U) + aPhaseAOrbiterAssignSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = (aWandererG + RotL64(aScatter, 57U)) + 17686765719908116203U;
            aOrbiterJ = ((aWandererE + RotL64(aPrevious, 22U)) + RotL64(aCarry, 13U)) + 1322045955429785736U;
            aOrbiterE = (aWandererF + RotL64(aCross, 53U)) + 5163772703302372887U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 13268431135020363252U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 6538789950366849332U;
            aOrbiterG = RotL64((aOrbiterG * 5352960308459065837U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 10390344544314544893U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 5087084271300584267U;
            aOrbiterF = RotL64((aOrbiterF * 15149302947570776165U), 39U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 13423071121590981727U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 18324443012024134729U;
            aOrbiterH = RotL64((aOrbiterH * 15814349432207734533U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 4129091815978464507U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 17024797553831962245U;
            aOrbiterB = RotL64((aOrbiterB * 3137753479364378175U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 6501545108779991661U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 11930037791867597447U;
            aOrbiterD = RotL64((aOrbiterD * 4904739567549702851U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 4667298703308315851U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 6315980380900062127U;
            aOrbiterE = RotL64((aOrbiterE * 12080555704907924637U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 12732382340390769888U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 7792095326183864547U;
            aOrbiterJ = RotL64((aOrbiterJ * 12645556660611824631U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 17428384983571405782U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 3193205313177048443U;
            aOrbiterA = RotL64((aOrbiterA * 14488006565106259731U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 2813743367131107264U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 2742138679703780981U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 18356569025783532225U), 11U);
            //
            aIngress = RotL64(aOrbiterA, 39U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 21U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 54U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterB, 47U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterI, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 57U) + aOrbiterD) + RotL64(aOrbiterA, 43U));
            aWandererF = aWandererF + (((RotL64(aIngress, 3U) + RotL64(aOrbiterJ, 29U)) + aOrbiterF) + RotL64(aCarry, 11U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 10U) + aOrbiterH) + RotL64(aOrbiterG, 5U));
            aWandererE = aWandererE + ((RotL64(aScatter, 51U) + RotL64(aOrbiterA, 38U)) + aOrbiterB);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 39U) + aOrbiterA) + RotL64(aOrbiterE, 21U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterD, 53U)) + aOrbiterI) + aPhaseAWandererUpdateSaltB[((aIndex + 21U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 28U) + aOrbiterE) + RotL64(aOrbiterH, 57U));
            aWandererB = aWandererB + (((RotL64(aScatter, 21U) + aOrbiterF) + RotL64(aOrbiterI, 13U)) + RotL64(aCarry, 27U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 43U) + RotL64(aOrbiterG, 34U)) + aOrbiterI) + aPhaseAWandererUpdateSaltE[((aIndex + 4U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 41U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 28U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 13U));
            aCarry = aCarry + RotL64(aWandererG, 19U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = RotL64(aWorkLaneB[((aIndex + 7798U)) & S_BLOCK1], 11U) ^ RotL64(aKeyRowReadB[((aIndex + 5739U)) & W_KEY1], 56U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 8147U)) & W_KEY1], 21U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 6606U)) & S_BLOCK1], 58U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 8066U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 41U) + RotL64(aCarry, 13U)) ^ (RotL64(aCross, 56U) + RotL64(aPrevious, 27U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterG = (aWandererJ + RotL64(aCross, 14U)) + 16519040829220310189U;
            aOrbiterF = (aWandererD + RotL64(aScatter, 27U)) + 6888002778416941825U;
            aOrbiterD = (aWandererA + RotL64(aPrevious, 47U)) + 1310832187746534025U;
            aOrbiterJ = ((aWandererI + RotL64(aIngress, 37U)) + 5890888009051281674U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterI = ((aWandererG + RotL64(aScatter, 57U)) + RotL64(aCarry, 19U)) + 5143864838362464857U;
            aOrbiterK = ((aWandererE + RotL64(aPrevious, 5U)) + 15591534069452660003U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = ((aWandererH + RotL64(aIngress, 18U)) + RotL64(aCarry, 27U)) + 1466867671765325096U;
            aOrbiterE = ((aWandererF + RotL64(aCross, 41U)) + RotL64(aCarry, 35U)) + 13931443680107902488U;
            aOrbiterH = (aWandererB + RotL64(aScatter, 23U)) + 15400747367673245552U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 2836975369734495759U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 2370720358274970117U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 4615571902817575375U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 3470677184188006133U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 7175584278499266723U;
            aOrbiterI = RotL64((aOrbiterI * 10067096593682482345U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 6095078817776863055U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 2176637999243513070U;
            aOrbiterA = RotL64((aOrbiterA * 12215701810843975501U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 5580391239754903129U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 15196125567953871184U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 12686361960729564519U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 12787014151503209931U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 1523153207064063495U;
            aOrbiterG = RotL64((aOrbiterG * 3113907543551927561U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 12973289026485937829U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 9087439766232078173U;
            aOrbiterJ = RotL64((aOrbiterJ * 5817029335999350327U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 16318022893068674015U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 11089160685103562409U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 17087834321385147603U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 8680037953925067235U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 3112588943274158119U;
            aOrbiterF = RotL64((aOrbiterF * 9214011370307670371U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 16749015684369649821U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 9419550535891334966U;
            aOrbiterE = RotL64((aOrbiterE * 5421312787569114811U), 35U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterF, 50U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 47U));
            aIngress = aIngress + (RotL64(aOrbiterD, 29U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterG, 57U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterH, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aScatter, 19U) + aOrbiterD) + RotL64(aOrbiterF, 5U)) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aIngress, 28U) + aOrbiterG) + RotL64(aOrbiterA, 58U)) + RotL64(aCarry, 3U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 51U) + aOrbiterF) + RotL64(aOrbiterJ, 47U)) + aPhaseAWandererUpdateSaltE[((aIndex + 14U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aPrevious, 35U) + aOrbiterK) + RotL64(aOrbiterE, 29U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 47U) + aOrbiterI) + RotL64(aOrbiterG, 43U));
            aWandererI = aWandererI + ((RotL64(aCross, 41U) + RotL64(aOrbiterG, 51U)) + aOrbiterD);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 11U) + aOrbiterK) + RotL64(aOrbiterA, 35U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 58U) + RotL64(aOrbiterA, 12U)) + aOrbiterI) + RotL64(aCarry, 35U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 5U) + aOrbiterF) + RotL64(aOrbiterH, 21U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 47U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 53U));
            aCarry = aCarry + (RotL64(aWandererJ, 50U) ^ aWandererI);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 21U));
            aCarry = aCarry + RotL64(aWandererA, 3U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 9466U)) & S_BLOCK1], 19U) ^ RotL64(aKeyRowReadB[((aIndex + 8730U)) & W_KEY1], 60U));
            aIngress ^= (RotL64(mSource[((aIndex + 9324U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneA[((aIndex + 9523U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 10678U)) & W_KEY1], 57U) ^ RotL64(aWorkLaneB[((aIndex + 10213U)) & S_BLOCK1], 20U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 41U) + RotL64(aPrevious, 53U)) + (RotL64(aIngress, 20U) ^ RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterK = ((aWandererJ + RotL64(aCross, 43U)) + RotL64(aCarry, 35U)) + 13350544654542863236U;
            aOrbiterE = ((aWandererA + RotL64(aScatter, 19U)) + 12364346790125404372U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = ((aWandererF + RotL64(aIngress, 58U)) + RotL64(aCarry, 19U)) + 9738750172849512764U;
            aOrbiterD = ((aWandererI + RotL64(aPrevious, 13U)) + RotL64(aCarry, 5U)) + 3781373837635491421U;
            aOrbiterJ = (aWandererB + RotL64(aScatter, 39U)) + 16635020317512702337U;
            aOrbiterG = (aWandererE + RotL64(aCross, 51U)) + 5383653921676231276U;
            aOrbiterB = (aWandererG + RotL64(aPrevious, 27U)) + 10181959815492056493U;
            aOrbiterI = ((aWandererK + RotL64(aIngress, 35U)) + 10005510924273927017U) + aPhaseBOrbiterAssignSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = (aWandererH + RotL64(aScatter, 4U)) + 9524687662265740565U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 4259138552009771014U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 8973051213213726023U;
            aOrbiterC = RotL64((aOrbiterC * 12625091476068190979U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 17602611840127337490U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 8218984546932905269U;
            aOrbiterG = RotL64((aOrbiterG * 17504305273683304231U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 18102186122213487888U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 2629927500298092976U;
            aOrbiterB = RotL64((aOrbiterB * 6983280164448292723U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 2491581597835795234U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 9506602492971620955U;
            aOrbiterE = RotL64((aOrbiterE * 9559829640915637163U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 13422942713680612924U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 15037354693234876601U;
            aOrbiterD = RotL64((aOrbiterD * 12692376075738621447U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 12896066842192894694U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 2202952306291905855U;
            aOrbiterJ = RotL64((aOrbiterJ * 6779368532763429997U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 12160313482450599313U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 10812986281270407756U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7786608700746771809U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 12474638293190144525U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 5882870951276225224U;
            aOrbiterK = RotL64((aOrbiterK * 15532427302173572457U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 3782896138051179209U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 10965680631059882311U;
            aOrbiterH = RotL64((aOrbiterH * 14060923998307082385U), 23U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterE, 53U);
            aIngress = aIngress + (RotL64(aOrbiterI, 11U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterK, 30U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 43U));
            aIngress = aIngress + RotL64(aOrbiterH, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aIngress, 30U) + aOrbiterE) + RotL64(aOrbiterB, 47U)) + RotL64(aCarry, 13U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 43U) + aOrbiterI) + RotL64(aOrbiterD, 37U));
            aWandererE = aWandererE + (((RotL64(aScatter, 47U) + RotL64(aOrbiterH, 19U)) + aOrbiterI) + RotL64(aCarry, 21U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterI, 5U)) + aOrbiterE);
            aWandererH = aWandererH + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterJ, 56U)) + aOrbiterG) + aPhaseBWandererUpdateSaltB[((aIndex + 26U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterJ, 41U)) + aOrbiterC) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aScatter, 24U) + aOrbiterK) + RotL64(aOrbiterC, 29U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterH, 13U)) + aOrbiterC);
            aWandererB = aWandererB + ((RotL64(aScatter, 3U) + RotL64(aOrbiterD, 60U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 10U));
            aCarry = aCarry + (RotL64(aWandererI, 13U) ^ aWandererB);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 43U));
            aCarry = aCarry + (RotL64(aWandererE, 57U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererK, 5U);
            aCarry = aCarry + RotL64(aIngress, 18U);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 12711U)) & S_BLOCK1], 35U) ^ RotL64(aKeyRowReadA[((aIndex + 13359U)) & W_KEY1], 3U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 12442U)) & W_KEY1], 11U) ^ RotL64(mSource[((aIndex + 11930U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aWorkLaneB[((aIndex + 12342U)) & S_BLOCK1], 26U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 11470U)) & S_BLOCK1], 13U) ^ RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 13269U)) & S_BLOCK1], 34U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 57U) + RotL64(aIngress, 5U)) + (RotL64(aPrevious, 23U) ^ RotL64(aCross, 36U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterJ = (aWandererK + RotL64(aCross, 35U)) + 16651241552253078315U;
            aOrbiterI = (((aWandererB + RotL64(aIngress, 41U)) + RotL64(aCarry, 39U)) + 4558144676982478003U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = (aWandererI + RotL64(aScatter, 13U)) + 8814884320080367550U;
            aOrbiterK = ((aWandererF + RotL64(aPrevious, 56U)) + RotL64(aCarry, 29U)) + 16011579668555672117U;
            aOrbiterA = ((aWandererG + RotL64(aCross, 51U)) + RotL64(aCarry, 19U)) + 4738918668759862438U;
            aOrbiterE = ((aWandererE + RotL64(aScatter, 5U)) + 12526083125540985108U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = (aWandererJ + RotL64(aIngress, 21U)) + 8048723561746000552U;
            aOrbiterC = (aWandererH + RotL64(aPrevious, 47U)) + 1082218464034639039U;
            aOrbiterG = (aWandererA + RotL64(aScatter, 26U)) + 8432043246965946816U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 9982080524048636852U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 6720069955755215919U;
            aOrbiterH = RotL64((aOrbiterH * 1025046364205332059U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 1019035028070247757U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 7360619079463870467U;
            aOrbiterE = RotL64((aOrbiterE * 6623074813047915863U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 10893918488381348474U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 1390297670907738019U;
            aOrbiterK = RotL64((aOrbiterK * 11909657437658597735U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 12512200589031203480U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 14741471280748399540U;
            aOrbiterJ = RotL64((aOrbiterJ * 3012135242889901095U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 8543897248359826770U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 8545972622733791272U;
            aOrbiterA = RotL64((aOrbiterA * 11793879362775346821U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 7049384618581928664U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 14730773807906925408U;
            aOrbiterG = RotL64((aOrbiterG * 10711566871536755073U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 11480717275652449986U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 1135397594974536859U;
            aOrbiterF = RotL64((aOrbiterF * 6347492892938856497U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 6897207625849516702U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 10920630712550287148U;
            aOrbiterI = RotL64((aOrbiterI * 4140705091806993359U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 1094056478999931332U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 6784487144549717207U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 6295177724167067891U), 35U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterJ, 28U);
            aIngress = aIngress + (RotL64(aOrbiterG, 57U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterK, 13U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 37U));
            aIngress = aIngress + RotL64(aOrbiterI, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aIngress, 6U) + aOrbiterI) + RotL64(aOrbiterG, 47U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterA, 5U)) + aOrbiterG);
            aWandererF = aWandererF + (((RotL64(aScatter, 53U) + RotL64(aOrbiterG, 27U)) + aOrbiterE) + RotL64(aCarry, 57U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterJ, 23U)) + aOrbiterH);
            aWandererH = aWandererH + (((RotL64(aScatter, 29U) + RotL64(aOrbiterC, 60U)) + aOrbiterA) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 35U) + aOrbiterJ) + RotL64(aOrbiterK, 37U));
            aWandererI = aWandererI + (((RotL64(aIngress, 13U) + aOrbiterC) + RotL64(aOrbiterF, 41U)) + aPhaseBWandererUpdateSaltB[((aIndex + 28U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 47U) + aOrbiterA) + RotL64(aOrbiterH, 13U));
            aWandererA = aWandererA + (((RotL64(aIngress, 18U) + RotL64(aOrbiterG, 56U)) + aOrbiterF) + RotL64(aCarry, 23U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 11U));
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererH, 43U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererE, 23U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererK, 50U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 15908U)) & S_BLOCK1], 5U) ^ RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 16212U)) & S_BLOCK1], 28U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 16166U)) & W_KEY1], 38U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 13831U)) & W_KEY1], 27U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 14457U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 13851U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16172U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 11U) + RotL64(aPrevious, 58U)) + (RotL64(aIngress, 39U) ^ RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterE = ((aWandererC + RotL64(aIngress, 43U)) + RotL64(aCarry, 5U)) + 252059974543142812U;
            aOrbiterB = ((aWandererK + RotL64(aPrevious, 3U)) + RotL64(aCarry, 21U)) + 11690823093681457368U;
            aOrbiterH = ((aWandererI + RotL64(aScatter, 58U)) + RotL64(aCarry, 43U)) + 13282189752890971123U;
            aOrbiterC = (aWandererF + RotL64(aCross, 23U)) + 9507416294305708435U;
            aOrbiterJ = ((aWandererJ + RotL64(aScatter, 27U)) + 14053038174390776539U) + aPhaseBOrbiterAssignSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = (aWandererD + RotL64(aPrevious, 53U)) + 14605253312318725009U;
            aOrbiterG = ((aWandererA + RotL64(aCross, 18U)) + 18138286582677863671U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterA = (aWandererE + RotL64(aIngress, 11U)) + 8530091235978489988U;
            aOrbiterK = (aWandererB + RotL64(aPrevious, 47U)) + 14381731677571170073U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 13316413456378978456U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 3910529530149320706U;
            aOrbiterH = RotL64((aOrbiterH * 16000139333493588429U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 6302070286831566901U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 12324134652758551396U;
            aOrbiterE = RotL64((aOrbiterE * 17136438281540250165U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 4773478557638475048U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 4031153435446078944U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3876928995240982769U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 3114794895962903899U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 3552936509969106796U;
            aOrbiterC = RotL64((aOrbiterC * 16823186892738820299U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 5828754613946145627U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 17985241114076114558U;
            aOrbiterG = RotL64((aOrbiterG * 1986669631395606833U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 11319331046368072261U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 6104267020171882160U;
            aOrbiterJ = RotL64((aOrbiterJ * 12525117969211576177U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 7662668379725735125U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 6583034411403600735U;
            aOrbiterB = RotL64((aOrbiterB * 262095656452193889U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 5569865728026310280U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 4176065898330374039U;
            aOrbiterF = RotL64((aOrbiterF * 11305749530796963967U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 13677146592276526676U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 2734371113158117596U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13146444882662731975U), 57U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterF, 5U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 46U));
            aIngress = aIngress + (RotL64(aOrbiterK, 11U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterC, 51U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterG, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aPrevious, 47U) + aOrbiterG) + RotL64(aOrbiterK, 5U)) + RotL64(aCarry, 37U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 57U) + aOrbiterK) + RotL64(aOrbiterF, 51U));
            aWandererD = aWandererD + (((RotL64(aCross, 43U) + aOrbiterJ) + RotL64(aOrbiterA, 39U)) + aPhaseBWandererUpdateSaltD[((aIndex + 23U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 12U) + aOrbiterC) + RotL64(aOrbiterF, 29U));
            aWandererK = aWandererK + ((RotL64(aScatter, 23U) + RotL64(aOrbiterK, 14U)) + aOrbiterE);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterC, 23U)) + aOrbiterJ);
            aWandererA = aWandererA + (((RotL64(aIngress, 39U) + aOrbiterH) + RotL64(aOrbiterB, 47U)) + RotL64(aCarry, 5U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterH, 35U)) + aOrbiterF) + aPhaseBWandererUpdateSaltE[((aIndex + 11U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aScatter, 6U) + aOrbiterB) + RotL64(aOrbiterF, 18U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 27U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 43U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 46U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 19U));
            aCarry = aCarry + RotL64(aWandererK, 13U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 18057U)) & S_BLOCK1], 19U) ^ RotL64(aKeyRowReadA[((aIndex + 17119U)) & W_KEY1], 56U));
            aIngress ^= (RotL64(mSource[((aIndex + 19074U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17921U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 17818U)) & W_KEY1], 39U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 18362U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 16864U)) & S_BLOCK1], 52U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 39U) + RotL64(aPrevious, 53U)) ^ (RotL64(aIngress, 6U) + RotL64(aCarry, 19U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterB = ((aWandererG + RotL64(aScatter, 27U)) + RotL64(aCarry, 57U)) + 12583180859826261500U;
            aOrbiterK = (aWandererI + RotL64(aIngress, 35U)) + 9067093488553721468U;
            aOrbiterC = ((aWandererH + RotL64(aPrevious, 56U)) + 12173106198862881754U) + aPhaseCOrbiterAssignSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterJ = (aWandererA + RotL64(aCross, 5U)) + 11333491014394592654U;
            aOrbiterG = ((aWandererE + RotL64(aIngress, 19U)) + RotL64(aCarry, 29U)) + 3511883526940919554U;
            aOrbiterI = (aWandererK + RotL64(aCross, 47U)) + 7416810692106273044U;
            aOrbiterE = (aWandererD + RotL64(aScatter, 51U)) + 8341174972619784110U;
            aOrbiterA = ((aWandererJ + RotL64(aPrevious, 39U)) + RotL64(aCarry, 47U)) + 2220852854836962979U;
            aOrbiterH = ((aWandererB + RotL64(aScatter, 12U)) + 8090781422229383825U) + aPhaseCOrbiterAssignSaltF[((aIndex + 15U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 2338801236599102223U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 12484514711848308104U;
            aOrbiterC = RotL64((aOrbiterC * 10364216764253366067U), 41U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 13684861340589131816U) + aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 12796636819991873058U;
            aOrbiterG = RotL64((aOrbiterG * 5533508014234835669U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 7634198650894837690U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 10240326122201201762U;
            aOrbiterE = RotL64((aOrbiterE * 8758703497719125901U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 4162814763739453934U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 2766504649149048469U) ^ aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 16731843453895178671U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 11051393030148769655U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 17687055068651386665U) ^ aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 1042927176246229537U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 3353615315436983420U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 5971640796220306310U;
            aOrbiterB = RotL64((aOrbiterB * 15804313508835034807U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 12299773092762384765U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 7435804907797063411U;
            aOrbiterA = RotL64((aOrbiterA * 9848139805288165965U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 8735783937125735699U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 11903126115475835615U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 16942088822124940265U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 4427166023462475475U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 6011733469446008137U;
            aOrbiterK = RotL64((aOrbiterK * 17298067225913923517U), 23U);
            //
            aIngress = RotL64(aOrbiterH, 47U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterG, 27U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterI, 11U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 56U));
            aIngress = aIngress + RotL64(aOrbiterA, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aIngress, 47U) + RotL64(aOrbiterG, 53U)) + aOrbiterE) + RotL64(aCarry, 37U)) + aPhaseCWandererUpdateSaltC[((aIndex + 17U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 29U) + aOrbiterH) + RotL64(aOrbiterG, 19U));
            aWandererB = aWandererB + ((RotL64(aCross, 35U) + RotL64(aOrbiterI, 48U)) + aOrbiterC);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 14U) + aOrbiterA) + RotL64(aOrbiterJ, 23U));
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 19U) + aOrbiterK) + RotL64(aOrbiterE, 11U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 23U) + aOrbiterA) + RotL64(aOrbiterB, 3U));
            aWandererG = aWandererG + ((RotL64(aIngress, 5U) + aOrbiterK) + RotL64(aOrbiterC, 42U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 41U) + aOrbiterH) + RotL64(aOrbiterJ, 27U));
            aWandererA = aWandererA + ((((RotL64(aPrevious, 56U) + aOrbiterE) + RotL64(aOrbiterA, 37U)) + RotL64(aCarry, 53U)) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 57U));
            aCarry = aCarry + (RotL64(aWandererA, 29U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererH, 47U) ^ aWandererD);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 53U));
            aCarry = aCarry + RotL64(aWandererJ, 26U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 19444U)) & S_BLOCK1], 4U) ^ RotL64(mSource[((aIndex + 19794U)) & S_BLOCK1], 57U));
            aIngress ^= (RotL64(aFireLaneA[((aIndex + 20533U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneA[((aIndex + 21162U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 21381U)) & W_KEY1], 3U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 21476U)) & W_KEY1], 53U));
            aCross ^= (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 21042U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneB[((aIndex + 21534U)) & S_BLOCK1], 18U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 4U) ^ RotL64(aIngress, 39U)) + (RotL64(aCarry, 53U) ^ RotL64(aPrevious, 27U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterC = (aWandererH + RotL64(aCross, 35U)) + 18302975933754610273U;
            aOrbiterK = ((aWandererB + RotL64(aIngress, 18U)) + RotL64(aCarry, 29U)) + 16736972646771456082U;
            aOrbiterB = (aWandererE + RotL64(aScatter, 47U)) + 17389406266488137442U;
            aOrbiterH = (aWandererA + RotL64(aPrevious, 23U)) + 5252511566486165539U;
            aOrbiterE = ((aWandererD + RotL64(aIngress, 43U)) + 5730715427422747640U) + aPhaseCOrbiterAssignSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = (aWandererK + RotL64(aPrevious, 29U)) + 6412695646456045825U;
            aOrbiterG = (aWandererJ + RotL64(aScatter, 39U)) + 9539701605708994494U;
            aOrbiterA = ((aWandererI + RotL64(aCross, 11U)) + RotL64(aCarry, 37U)) + 18355107116412945722U;
            aOrbiterI = (((aWandererG + RotL64(aScatter, 56U)) + RotL64(aCarry, 51U)) + 11735742491750132942U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 12363819388562658842U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 5861430292304371543U;
            aOrbiterB = RotL64((aOrbiterB * 12989055611235382695U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 15027487084595017708U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 7012850020745791926U;
            aOrbiterE = RotL64((aOrbiterE * 15952928839355613939U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 11904871669287886120U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 11199760114477343208U;
            aOrbiterJ = RotL64((aOrbiterJ * 7156374911847525867U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 3856004502263742700U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 3705931243173921893U;
            aOrbiterK = RotL64((aOrbiterK * 10334871178498711485U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 12305785390539209389U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 18057980996551978823U;
            aOrbiterI = RotL64((aOrbiterI * 4850564181113470859U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 3229431819292153014U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 2994716629242460094U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 1029427328395257917U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 9796307843453735512U) + aPhaseCOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 2957260393651252432U;
            aOrbiterG = RotL64((aOrbiterG * 7261055869794739609U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 4060469664218866340U) + aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 17462081697889685330U;
            aOrbiterA = RotL64((aOrbiterA * 7712009170974461225U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 13638660073917821172U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 15202349592659062565U) ^ aPhaseCOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4514326257446024301U), 23U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterB, 43U);
            aIngress = aIngress + (RotL64(aOrbiterK, 13U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterC, 50U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 19U));
            aIngress = aIngress + RotL64(aOrbiterI, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aIngress, 47U) + aOrbiterC) + RotL64(aOrbiterI, 23U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 40U) + aOrbiterB) + RotL64(aOrbiterE, 41U));
            aWandererI = aWandererI + ((RotL64(aScatter, 19U) + aOrbiterC) + RotL64(aOrbiterH, 19U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterG, 47U)) + aOrbiterH);
            aWandererD = aWandererD + ((RotL64(aScatter, 13U) + aOrbiterH) + RotL64(aOrbiterA, 58U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 29U) + aOrbiterB) + RotL64(aOrbiterA, 51U));
            aWandererG = aWandererG + ((((RotL64(aIngress, 3U) + RotL64(aOrbiterK, 5U)) + aOrbiterJ) + RotL64(aCarry, 3U)) + aPhaseCWandererUpdateSaltD[((aIndex + 15U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterA, 13U)) + aOrbiterI);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 58U) + RotL64(aOrbiterK, 34U)) + aOrbiterI) + RotL64(aCarry, 47U)) + aPhaseCWandererUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 5U) ^ aWandererB);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 38U));
            aCarry = aCarry + (RotL64(aWandererH, 35U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererD, 23U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererE, 41U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 22897U)) & S_BLOCK1], 37U) ^ RotL64(aKeyRowReadA[((aIndex + 24039U)) & W_KEY1], 27U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 22415U)) & W_KEY1], 56U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 21969U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 23238U)) & S_BLOCK1], 13U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 23279U)) & S_BLOCK1], 29U));
            aCross ^= (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 22168U)) & S_BLOCK1], 57U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 23759U)) & S_BLOCK1], 42U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 53U) ^ RotL64(aIngress, 19U)) + (RotL64(aCross, 5U) + RotL64(aPrevious, 34U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterA = (((aWandererG + RotL64(aCross, 18U)) + RotL64(aCarry, 35U)) + 6916817163240024692U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterD = ((aWandererJ + RotL64(aScatter, 3U)) + RotL64(aCarry, 43U)) + 14554930751292077817U;
            aOrbiterE = (aWandererB + RotL64(aIngress, 35U)) + 1098305064484336101U;
            aOrbiterF = ((aWandererI + RotL64(aPrevious, 23U)) + RotL64(aCarry, 51U)) + 12192821172420471527U;
            aOrbiterG = (aWandererH + RotL64(aScatter, 27U)) + 2435134991707318845U;
            aOrbiterJ = (aWandererC + RotL64(aIngress, 12U)) + 1896745368738512624U;
            aOrbiterI = ((aWandererE + RotL64(aPrevious, 53U)) + 1114996424222923873U) + aPhaseCOrbiterAssignSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterK = (aWandererD + RotL64(aCross, 43U)) + 9839135798371512656U;
            aOrbiterB = (aWandererA + RotL64(aScatter, 57U)) + 8037967239603177043U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 15185468738487237432U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 4912098316394854543U;
            aOrbiterE = RotL64((aOrbiterE * 3072785550384399929U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 13142688607850380888U) + aPhaseCOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 4507379759608945839U;
            aOrbiterA = RotL64((aOrbiterA * 2989332387754215967U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 7299006009652289342U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 5390655277207053627U;
            aOrbiterG = RotL64((aOrbiterG * 10973744708856143715U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 6744737023577785725U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 15539737698867067285U;
            aOrbiterF = RotL64((aOrbiterF * 4686092035261336911U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 13329866734681377952U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 13284937458969166257U;
            aOrbiterI = RotL64((aOrbiterI * 3965985432462699445U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 8695002088915702168U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 3858059421620839286U) ^ aPhaseCOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9559783727301092937U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 6609163873243179836U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 9416165620556710540U;
            aOrbiterD = RotL64((aOrbiterD * 240385043740268229U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 1578449067529000433U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 14309000104419489303U;
            aOrbiterK = RotL64((aOrbiterK * 7599078306153684729U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 15785180680737461320U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 10099222679918382021U;
            aOrbiterJ = RotL64((aOrbiterJ * 2012232597046182581U), 27U);
            //
            aIngress = RotL64(aOrbiterI, 51U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterG, 44U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterB, 35U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 3U));
            aIngress = aIngress + RotL64(aOrbiterJ, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aCross, 13U) + RotL64(aOrbiterB, 6U)) + aOrbiterG) + RotL64(aCarry, 5U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterD, 47U)) + aOrbiterJ);
            aWandererG = aWandererG + ((RotL64(aScatter, 41U) + aOrbiterF) + RotL64(aOrbiterD, 51U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 30U) + RotL64(aOrbiterE, 21U)) + aOrbiterB);
            aWandererE = aWandererE + (((RotL64(aPrevious, 23U) + aOrbiterK) + RotL64(aOrbiterB, 39U)) + aPhaseCWandererUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 19U) + aOrbiterJ) + RotL64(aOrbiterB, 34U));
            aWandererC = aWandererC + (((RotL64(aScatter, 3U) + aOrbiterJ) + RotL64(aOrbiterI, 29U)) + aPhaseCWandererUpdateSaltD[((aIndex + 21U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 60U) + aOrbiterA) + RotL64(aOrbiterD, 43U));
            aWandererI = aWandererI + (((RotL64(aScatter, 47U) + aOrbiterE) + RotL64(aOrbiterF, 57U)) + RotL64(aCarry, 39U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 3U));
            aCarry = aCarry + (RotL64(aWandererC, 24U) ^ aWandererD);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 19U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 37U));
            aCarry = aCarry + RotL64(aWandererI, 57U);
            aCarry = aCarry + RotL64(aIngress, 6U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 24951U)) & S_BLOCK1], 12U) ^ RotL64(aKeyRowReadA[((aIndex + 24629U)) & W_KEY1], 37U));
            aIngress ^= (RotL64(aFireLaneD[((aIndex + 25788U)) & S_BLOCK1], 47U) ^ RotL64(aFireLaneB[((aIndex + 27036U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 27022U)) & W_KEY1], 43U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 26335U)) & S_BLOCK1], 29U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 27109U)) & S_BLOCK1], 51U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 24862U)) & S_BLOCK1], 18U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 13U) + RotL64(aPrevious, 43U)) ^ (RotL64(aCross, 58U) + RotL64(aIngress, 29U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterF = (aWandererI + RotL64(aIngress, 27U)) + 5906639480605353429U;
            aOrbiterK = ((aWandererH + RotL64(aScatter, 23U)) + RotL64(aCarry, 37U)) + 5293518570213287605U;
            aOrbiterD = ((aWandererD + RotL64(aPrevious, 5U)) + 15383185501428521377U) + aPhaseDOrbiterAssignSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = ((aWandererF + RotL64(aCross, 52U)) + RotL64(aCarry, 29U)) + 15364072512743978902U;
            aOrbiterE = (aWandererA + RotL64(aScatter, 39U)) + 4525473357144014271U;
            aOrbiterG = ((aWandererE + RotL64(aCross, 43U)) + 10400911938125603074U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterI = (aWandererJ + RotL64(aPrevious, 47U)) + 16417506293824627550U;
            aOrbiterA = ((aWandererB + RotL64(aIngress, 11U)) + RotL64(aCarry, 3U)) + 2419329331753341815U;
            aOrbiterJ = (aWandererK + RotL64(aPrevious, 58U)) + 14929222427923332069U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 16771573504983922586U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 1863466450051787622U;
            aOrbiterD = RotL64((aOrbiterD * 2585626547126027053U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 12895350137096692415U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 3700979086526298327U;
            aOrbiterE = RotL64((aOrbiterE * 10279730254867618193U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 1977099106211282426U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 6144698304096915742U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5039822990560519609U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 3858895556659724975U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 1283646340363435327U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11622421841377018069U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 6240532051889108891U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 757364889381634634U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 943852137901972945U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 5272945693977418174U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 6850528198786172283U;
            aOrbiterJ = RotL64((aOrbiterJ * 1966383079897679953U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 14431587733859573714U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 16124590257870999553U;
            aOrbiterA = RotL64((aOrbiterA * 7755796211433191143U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 14912695018110241411U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 11098623474413346520U;
            aOrbiterG = RotL64((aOrbiterG * 15167688959990872051U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 3484847683376368686U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 2295388097292719800U;
            aOrbiterK = RotL64((aOrbiterK * 1240808318176106909U), 39U);
            //
            aIngress = RotL64(aOrbiterA, 52U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterF, 47U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterJ, 11U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterI, 35U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterK, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aCross, 51U) + aOrbiterB) + RotL64(aOrbiterJ, 43U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 12U) + aOrbiterI) + RotL64(aOrbiterA, 37U));
            aWandererF = aWandererF + ((((RotL64(aIngress, 3U) + RotL64(aOrbiterI, 13U)) + aOrbiterB) + RotL64(aCarry, 39U)) + aPhaseDWandererUpdateSaltF[((aIndex + 19U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterG, 24U)) + aOrbiterA);
            aWandererH = aWandererH + (((RotL64(aScatter, 47U) + RotL64(aOrbiterF, 29U)) + aOrbiterD) + RotL64(aCarry, 5U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 29U) + aOrbiterG) + RotL64(aOrbiterE, 53U));
            aWandererD = aWandererD + ((RotL64(aPrevious, 39U) + RotL64(aOrbiterK, 3U)) + aOrbiterB);
            aWandererI = aWandererI ^ (((RotL64(aCross, 57U) + aOrbiterA) + RotL64(aOrbiterF, 19U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aScatter, 34U) + aOrbiterD) + RotL64(aOrbiterE, 60U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 13U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererJ, 39U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererE, 51U) ^ aWandererB);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 5U));
            aCarry = aCarry + RotL64(aWandererI, 19U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 29033U)) & S_BLOCK1], 47U) ^ RotL64(aFireLaneD[((aIndex + 28578U)) & S_BLOCK1], 35U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 28450U)) & W_KEY1], 3U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 28266U)) & S_BLOCK1], 24U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 27793U)) & W_KEY1], 43U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 29669U)) & S_BLOCK1], 19U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 28761U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneB[((aIndex + 29208U)) & S_BLOCK1], 28U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 36U) ^ RotL64(aPrevious, 19U)) + (RotL64(aIngress, 53U) ^ RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterJ = (aWandererD + RotL64(aIngress, 36U)) + 12262991801139086177U;
            aOrbiterA = (aWandererK + RotL64(aScatter, 23U)) + 7963038771924890197U;
            aOrbiterI = (aWandererF + RotL64(aPrevious, 27U)) + 15540520327933568896U;
            aOrbiterH = (aWandererA + RotL64(aCross, 47U)) + 8745565892055020722U;
            aOrbiterF = (((aWandererE + RotL64(aScatter, 57U)) + RotL64(aCarry, 27U)) + 16619329199683755286U) + aPhaseDOrbiterAssignSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterG = (((aWandererB + RotL64(aCross, 13U)) + RotL64(aCarry, 37U)) + 10865705026433867260U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterD = (aWandererJ + RotL64(aPrevious, 19U)) + 2743368697984518059U;
            aOrbiterK = ((aWandererI + RotL64(aIngress, 42U)) + RotL64(aCarry, 11U)) + 5556006271515473135U;
            aOrbiterE = (aWandererC + RotL64(aScatter, 3U)) + 5355833281353498588U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 8313616108963479829U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 16657121016801866434U;
            aOrbiterI = RotL64((aOrbiterI * 331533349428472477U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 16532226425013000833U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 5800465874932467232U;
            aOrbiterF = RotL64((aOrbiterF * 5966395771690704577U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 17882948163883121328U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 15029375310296563175U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 17021415832288477713U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 10170682648007918739U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 11829089574189398773U;
            aOrbiterA = RotL64((aOrbiterA * 15755874363488568849U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 1746524867389196322U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 10217423427886742775U;
            aOrbiterG = RotL64((aOrbiterG * 9166162099575333519U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 1338457710729082656U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 1319981417675542556U;
            aOrbiterH = RotL64((aOrbiterH * 9518448254565489715U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 3985281993069194761U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 7281264481139915593U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 13498446162967276739U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 17394503335338855566U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 1430703546991948227U;
            aOrbiterD = RotL64((aOrbiterD * 1623206122475721175U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 472559435062214929U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 8065899137826178995U;
            aOrbiterK = RotL64((aOrbiterK * 13287499768933229539U), 13U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterE, 19U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 22U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 5U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 35U));
            aIngress = aIngress + RotL64(aOrbiterD, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aScatter, 12U) + RotL64(aOrbiterI, 43U)) + aOrbiterK);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterF, 51U)) + aOrbiterH);
            aWandererF = aWandererF + ((((RotL64(aIngress, 3U) + aOrbiterI) + RotL64(aOrbiterJ, 35U)) + RotL64(aCarry, 5U)) + aPhaseDWandererUpdateSaltF[((aIndex + 10U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterJ, 19U)) + aOrbiterG);
            aWandererA = aWandererA + ((RotL64(aIngress, 24U) + aOrbiterE) + RotL64(aOrbiterF, 58U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterE, 23U)) + aOrbiterA);
            aWandererK = aWandererK + ((RotL64(aScatter, 51U) + aOrbiterK) + RotL64(aOrbiterG, 47U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterH, 13U)) + aOrbiterK);
            aWandererD = aWandererD + ((((RotL64(aScatter, 43U) + RotL64(aOrbiterD, 28U)) + aOrbiterF) + RotL64(aCarry, 57U)) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 11U) ^ aWandererB);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 23U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 20U));
            aCarry = aCarry + (RotL64(aWandererD, 29U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererE, 37U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 31434U)) & S_BLOCK1], 51U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 30636U)) & W_KEY1], 28U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 32228U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31355U)) & S_BLOCK1], 11U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31769U)) & S_BLOCK1], 41U) ^ RotL64(aKeyRowReadB[((aIndex + 31107U)) & W_KEY1], 54U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 29U) + RotL64(aIngress, 5U)) ^ (RotL64(aCarry, 56U) ^ RotL64(aPrevious, 41U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterH = ((aWandererF + RotL64(aScatter, 12U)) + 13687218104610230596U) + aPhaseDOrbiterAssignSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = (aWandererH + RotL64(aPrevious, 39U)) + 6841550124960692709U;
            aOrbiterG = ((aWandererA + RotL64(aIngress, 35U)) + RotL64(aCarry, 3U)) + 17418968668458764131U;
            aOrbiterB = (aWandererI + RotL64(aCross, 19U)) + 8303537912696948204U;
            aOrbiterF = (aWandererE + RotL64(aPrevious, 51U)) + 12376614417285936537U;
            aOrbiterE = ((aWandererC + RotL64(aCross, 57U)) + RotL64(aCarry, 19U)) + 14215749063579232654U;
            aOrbiterI = (aWandererG + RotL64(aIngress, 4U)) + 4111736931433665347U;
            aOrbiterA = (aWandererJ + RotL64(aScatter, 23U)) + 11250375934571631522U;
            aOrbiterC = (((aWandererK + RotL64(aPrevious, 43U)) + RotL64(aCarry, 11U)) + 5367367837773331275U) + aPhaseDOrbiterAssignSaltB[((aIndex + 15U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 15514089192382674434U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 1475991716685034960U;
            aOrbiterG = RotL64((aOrbiterG * 17720681295551650891U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 5531622777788629748U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 8363822215908303335U;
            aOrbiterE = RotL64((aOrbiterE * 17850203366840994883U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 3741256932685720414U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 11634667238062155772U;
            aOrbiterD = RotL64((aOrbiterD * 15925089729784547403U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 18180546911210417155U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 5123234656838556335U;
            aOrbiterF = RotL64((aOrbiterF * 15362857462853398025U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 11215734271189250284U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 16863747802158398092U;
            aOrbiterB = RotL64((aOrbiterB * 1828035970246160023U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 9859050606636646323U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 9331300036643654675U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2502263410556166281U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 15028845665427209759U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 8916444839488901676U;
            aOrbiterH = RotL64((aOrbiterH * 6646561894156038791U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 8024631140949068570U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 1116378858490660031U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4247798531910227367U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 5066486214537899212U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 9346312092322423057U;
            aOrbiterA = RotL64((aOrbiterA * 13443190089768875191U), 13U);
            //
            aIngress = RotL64(aOrbiterE, 13U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 10U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 23U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 3U));
            aIngress = aIngress + RotL64(aOrbiterI, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aIngress, 18U) + aOrbiterA) + RotL64(aOrbiterE, 57U));
            aWandererG = aWandererG + (((RotL64(aCross, 23U) + RotL64(aOrbiterI, 41U)) + aOrbiterF) + aPhaseDWandererUpdateSaltA[((aIndex + 10U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterD, 37U)) + aOrbiterC);
            aWandererH = aWandererH + (((RotL64(aScatter, 47U) + RotL64(aOrbiterE, 47U)) + aOrbiterI) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 5U) + aOrbiterH) + RotL64(aOrbiterE, 10U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 13U) + aOrbiterH) + RotL64(aOrbiterD, 53U)) + RotL64(aCarry, 41U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterG, 29U)) + aOrbiterC);
            aWandererF = aWandererF + (((RotL64(aScatter, 35U) + RotL64(aOrbiterF, 5U)) + aOrbiterG) + RotL64(aCarry, 13U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 60U) + aOrbiterD) + RotL64(aOrbiterB, 18U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 21U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererG, 5U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererC);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 13U));
            aCarry = aCarry + RotL64(aWandererH, 10U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneA, aExpandLaneC, aExpandLaneD, aInvestLaneC, aFireLaneD, aInvestLaneD, aFireLaneC, aOperationLaneA, aFireLaneB, aOperationLaneB, aOperationLaneC
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 4659U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneB[((aIndex + 3915U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 558U)) & S_BLOCK1], 46U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 683U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 1252U)) & S_BLOCK1], 30U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 19U) ^ RotL64(aCarry, 41U)) + (RotL64(aIngress, 53U) ^ RotL64(aCross, 6U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterK = ((aWandererA + RotL64(aScatter, 56U)) + RotL64(aCarry, 19U)) + 11039986441331892533U;
            aOrbiterF = ((aWandererB + RotL64(aCross, 43U)) + 6256024955965426119U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = (aWandererK + RotL64(aIngress, 3U)) + 9857443189988995666U;
            aOrbiterD = (((aWandererJ + RotL64(aPrevious, 37U)) + RotL64(aCarry, 47U)) + 11900944813380998208U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterB = ((aWandererH + RotL64(aCross, 27U)) + RotL64(aCarry, 3U)) + 8422577734978875541U;
            aOrbiterH = (aWandererI + RotL64(aIngress, 21U)) + 3100835100713928724U;
            aOrbiterA = (aWandererD + RotL64(aPrevious, 11U)) + 11871553509810206993U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 17614749493763417027U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 3638372131856199916U;
            aOrbiterC = RotL64((aOrbiterC * 480683274898147025U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 6582275259281025770U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 17016882418498941958U;
            aOrbiterB = RotL64((aOrbiterB * 4269869255230867823U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 1747214688658984715U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 9356088987044015278U;
            aOrbiterD = RotL64((aOrbiterD * 16221733545319753695U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 4056238112133473456U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 16013150119949532998U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 12913648646318115315U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 16076621211111834889U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 9940824359571581765U;
            aOrbiterA = RotL64((aOrbiterA * 11624767861336495331U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 15624084004784515753U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 7630989544834680335U;
            aOrbiterK = RotL64((aOrbiterK * 12261063237156822067U), 37U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 18003586430673313786U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 1654118743290334161U;
            aOrbiterF = RotL64((aOrbiterF * 1153250137357176071U), 57U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterK, 57U);
            aIngress = aIngress + (RotL64(aOrbiterH, 13U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 30U));
            aIngress = aIngress + RotL64(aOrbiterD, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 21U) + RotL64(aOrbiterH, 53U)) + aOrbiterC) + RotL64(aCarry, 43U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterK, 29U)) + aOrbiterC);
            aWandererB = aWandererB + (((RotL64(aScatter, 41U) + aOrbiterA) + RotL64(aOrbiterC, 36U)) + RotL64(aCarry, 27U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 29U) + RotL64(aOrbiterF, 21U)) + aOrbiterD) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aScatter, 13U) + aOrbiterD) + RotL64(aOrbiterB, 43U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 60U) + RotL64(aOrbiterK, 5U)) + aOrbiterB);
            aWandererH = aWandererH + ((RotL64(aCross, 5U) + aOrbiterH) + RotL64(aOrbiterK, 13U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 43U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererI, 23U) ^ aWandererH);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 34U));
            aCarry = aCarry + RotL64(aWandererB, 51U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aInvestLaneC[aIndex] = aIngress;
        }
    
        // twist_loop_b loop 2
        // ingress from: aInvestLaneC, aExpandLaneC, aFireLaneD
        // ingress directions: aInvestLaneC forward forced, aExpandLaneC forward forced, aFireLaneD forward/backward random
        // cross from: aExpandLaneA, aExpandLaneD
        // cross directions: aExpandLaneA backward forced, aExpandLaneD backward/forward random
        // write to: aInvestLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneC[((aIndex + 7390U)) & S_BLOCK1], 38U) ^ RotL64(aExpandLaneC[((aIndex + 7207U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 7690U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 7748U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 7540U)) & S_BLOCK1], 60U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 11U) + RotL64(aPrevious, 58U)) + (RotL64(aCross, 23U) ^ RotL64(aIngress, 41U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterF = (aWandererF + RotL64(aPrevious, 43U)) + 13960289014350612206U;
            aOrbiterE = (((aWandererG + RotL64(aIngress, 35U)) + RotL64(aCarry, 35U)) + 3483331015269589730U) + aPhaseEOrbiterAssignSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterB = ((aWandererE + RotL64(aScatter, 3U)) + RotL64(aCarry, 47U)) + 6873299241002444518U;
            aOrbiterA = ((aWandererJ + RotL64(aCross, 52U)) + RotL64(aCarry, 5U)) + 3562094007125534229U;
            aOrbiterD = (aWandererB + RotL64(aPrevious, 29U)) + 11422367439932782705U;
            aOrbiterG = ((aWandererI + RotL64(aScatter, 21U)) + 532453428514259816U) + aPhaseEOrbiterAssignSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = (aWandererH + RotL64(aIngress, 13U)) + 17810941465810193088U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 11869759058631106331U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 8837581071876177566U;
            aOrbiterB = RotL64((aOrbiterB * 15329827515970522213U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 17185378327053837778U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 7578253375676981500U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 13371647568758721729U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 17112646434432814442U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 14949096407295697881U;
            aOrbiterA = RotL64((aOrbiterA * 14770977858283051753U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 4259590620758467836U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 6534899413644542303U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 7987609419215568661U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 2637407498893694243U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 15819295597921425711U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 5202015597375051399U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 6373559542002699718U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 11694562937392022505U;
            aOrbiterG = RotL64((aOrbiterG * 9311557972331218597U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 3308736483775453062U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 12749929710650475901U;
            aOrbiterH = RotL64((aOrbiterH * 248428400724560945U), 13U);
            //
            aIngress = RotL64(aOrbiterG, 35U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 41U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 3U));
            aIngress = aIngress + RotL64(aOrbiterB, 60U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aPrevious, 21U) + aOrbiterE) + RotL64(aOrbiterH, 3U)) + RotL64(aCarry, 41U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterF, 11U)) + aOrbiterD);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 3U) + RotL64(aOrbiterA, 57U)) + aOrbiterH);
            aWandererB = aWandererB ^ (((RotL64(aCross, 53U) + RotL64(aOrbiterD, 44U)) + aOrbiterA) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aIngress, 27U) + RotL64(aOrbiterB, 51U)) + aOrbiterE);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterA, 19U)) + aOrbiterG);
            aWandererG = aWandererG + (((RotL64(aCross, 60U) + aOrbiterB) + RotL64(aOrbiterG, 37U)) + RotL64(aCarry, 11U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 13U) ^ aWandererE);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 39U));
            aCarry = aCarry + (RotL64(aWandererI, 21U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererJ, 52U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aInvestLaneD[((aIndex + 13292U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneD[((aIndex + 11592U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 15840U)) & S_BLOCK1], 14U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 13483U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 14480U)) & S_BLOCK1], 4U));
            aCross ^= RotL64(aExpandLaneA[((aIndex + 15068U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 23U) + RotL64(aCarry, 38U)) + (RotL64(aCross, 53U) ^ RotL64(aPrevious, 3U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterF = (aWandererG + RotL64(aCross, 29U)) + 18144572925667544139U;
            aOrbiterC = ((aWandererF + RotL64(aScatter, 60U)) + RotL64(aCarry, 3U)) + 5659758077574059728U;
            aOrbiterB = ((aWandererH + RotL64(aIngress, 47U)) + 6343330616999166392U) + aPhaseEOrbiterAssignSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterK = (aWandererJ + RotL64(aPrevious, 5U)) + 17754639838410839447U;
            aOrbiterH = (aWandererE + RotL64(aScatter, 41U)) + 9451843819849581729U;
            aOrbiterD = (((aWandererC + RotL64(aIngress, 13U)) + RotL64(aCarry, 21U)) + 7957854457197462212U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterA = ((aWandererA + RotL64(aPrevious, 23U)) + RotL64(aCarry, 35U)) + 1461994799722205010U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 18002214276252170177U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 14689869073147027164U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 12242482963989582191U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 3978104368003440293U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 8512135845221335386U;
            aOrbiterH = RotL64((aOrbiterH * 10506667163729414667U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 1477533446382953439U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 2166717790929947990U;
            aOrbiterC = RotL64((aOrbiterC * 6538884492418324461U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 8082437060686606995U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 4363687722464700362U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7199165810993478887U), 41U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 15782763348014924206U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 8572509150015960728U;
            aOrbiterD = RotL64((aOrbiterD * 3340528604891897779U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 12248271773316742521U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 9602078627638561949U;
            aOrbiterK = RotL64((aOrbiterK * 1860631869877427405U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 17244849374768558859U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 1030743048280579012U;
            aOrbiterA = RotL64((aOrbiterA * 10858949914285817051U), 27U);
            //
            aIngress = RotL64(aOrbiterC, 47U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 60U));
            aIngress = aIngress + (RotL64(aOrbiterF, 5U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterK, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 51U) + aOrbiterA) + RotL64(aOrbiterD, 29U));
            aWandererJ = aWandererJ + ((((RotL64(aCross, 38U) + RotL64(aOrbiterB, 58U)) + aOrbiterH) + RotL64(aCarry, 23U)) + aPhaseEWandererUpdateSaltA[((aIndex + 23U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterH, 13U)) + aOrbiterK);
            aWandererH = aWandererH + ((RotL64(aScatter, 5U) + aOrbiterH) + RotL64(aOrbiterD, 43U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterD, 51U)) + aOrbiterF) + aPhaseEWandererUpdateSaltF[((aIndex + 26U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 13U) + aOrbiterC) + RotL64(aOrbiterF, 19U)) + RotL64(aCarry, 51U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterD, 37U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererE, 51U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererC, 39U) ^ aWandererF);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 3U));
            aCarry = aCarry + RotL64(aWandererG, 24U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 21012U)) & S_BLOCK1], 3U) ^ RotL64(aInvestLaneC[((aIndex + 19548U)) & S_BLOCK1], 54U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 20055U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 18054U)) & S_BLOCK1], 22U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 18275U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 19842U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 21U) ^ RotL64(aCross, 37U)) ^ (RotL64(aPrevious, 5U) + RotL64(aCarry, 54U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterH = ((aWandererI + RotL64(aIngress, 29U)) + RotL64(aCarry, 23U)) + 2330952702412094686U;
            aOrbiterK = (aWandererB + RotL64(aPrevious, 37U)) + 7820188225935060799U;
            aOrbiterE = ((aWandererD + RotL64(aCross, 3U)) + 9347644591709839145U) + aPhaseEOrbiterAssignSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterD = (aWandererK + RotL64(aScatter, 51U)) + 2288624878446846870U;
            aOrbiterG = (((aWandererE + RotL64(aPrevious, 13U)) + RotL64(aCarry, 5U)) + 9358977729492824128U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = ((aWandererJ + RotL64(aScatter, 58U)) + RotL64(aCarry, 51U)) + 1858511275052455039U;
            aOrbiterA = (aWandererC + RotL64(aIngress, 23U)) + 13715478509322292552U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 16413396625604260455U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 17714322215518432705U;
            aOrbiterE = RotL64((aOrbiterE * 1904184102419934333U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 16188315436202861122U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 5564445841368207813U;
            aOrbiterG = RotL64((aOrbiterG * 14125834616162835983U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 13717068949900594673U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 14143659432287313765U;
            aOrbiterA = RotL64((aOrbiterA * 17281441046722262917U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 5729546141908425670U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 4297827922736712074U;
            aOrbiterK = RotL64((aOrbiterK * 13631630436759768885U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 829520109395163673U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 11547160328525174295U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 4759690159673049775U), 37U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 2907177944512117206U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 11100346409065275671U;
            aOrbiterD = RotL64((aOrbiterD * 17927994356809011637U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 1344592529249949068U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 6470438516791143572U;
            aOrbiterH = RotL64((aOrbiterH * 13339390828725370475U), 29U);
            //
            aIngress = RotL64(aOrbiterH, 39U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 5U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 11U));
            aIngress = aIngress + RotL64(aOrbiterI, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aPrevious, 36U) + RotL64(aOrbiterD, 29U)) + aOrbiterG);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterK, 53U)) + aOrbiterD);
            aWandererK = aWandererK + (((RotL64(aCross, 3U) + RotL64(aOrbiterA, 3U)) + aOrbiterI) + RotL64(aCarry, 11U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterI, 47U)) + aOrbiterG);
            aWandererB = aWandererB + (((RotL64(aPrevious, 19U) + aOrbiterG) + RotL64(aOrbiterE, 35U)) + RotL64(aCarry, 47U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 51U) + aOrbiterG) + RotL64(aOrbiterA, 41U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 43U) + aOrbiterH) + RotL64(aOrbiterE, 14U)) + aPhaseEWandererUpdateSaltD[((aIndex + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 5U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 18U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 35U));
            aCarry = aCarry + RotL64(aWandererK, 11U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 22710U)) & S_BLOCK1], 56U) ^ RotL64(aOperationLaneA[((aIndex + 25392U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 22918U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 21943U)) & S_BLOCK1], 47U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 23425U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aInvestLaneD[((aIndex + 23086U)) & S_BLOCK1], 18U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 39U) ^ RotL64(aCross, 27U)) + (RotL64(aCarry, 54U) + RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterC = ((aWandererG + RotL64(aCross, 43U)) + 11521331427196538632U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = (aWandererB + RotL64(aScatter, 6U)) + 16653824187682957632U;
            aOrbiterE = (aWandererA + RotL64(aPrevious, 13U)) + 11654676587350088289U;
            aOrbiterI = (aWandererD + RotL64(aIngress, 51U)) + 8010313317412193584U;
            aOrbiterF = ((aWandererK + RotL64(aCross, 19U)) + RotL64(aCarry, 57U)) + 1108775560502907471U;
            aOrbiterK = (((aWandererC + RotL64(aPrevious, 27U)) + RotL64(aCarry, 39U)) + 243952321439823521U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = ((aWandererI + RotL64(aIngress, 35U)) + RotL64(aCarry, 11U)) + 2324945800401240403U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 9257554497543369657U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 16701314607244592540U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 8790054741039817107U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 3900445848034341782U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 7652316487347103658U;
            aOrbiterF = RotL64((aOrbiterF * 11480123491361589799U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 14980368605272070578U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 2001165460948764796U;
            aOrbiterC = RotL64((aOrbiterC * 8110980921827107649U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 1911044015666991050U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 11366207111147818339U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 17234439040652553865U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 16469329744002456607U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 8062793687044950815U;
            aOrbiterH = RotL64((aOrbiterH * 5856142259851144369U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 15364721421972807872U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 8979915611483540231U;
            aOrbiterG = RotL64((aOrbiterG * 10899377466171153383U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 7654234623563110457U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 1526832460342135008U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12766083052650723051U), 29U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterK, 60U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 5U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 19U));
            aIngress = aIngress + RotL64(aOrbiterG, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aScatter, 60U) + aOrbiterF) + RotL64(aOrbiterH, 3U));
            aWandererB = aWandererB + ((RotL64(aIngress, 41U) + aOrbiterI) + RotL64(aOrbiterE, 48U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 35U) + aOrbiterF) + RotL64(aOrbiterG, 57U));
            aWandererG = aWandererG + (((RotL64(aCross, 29U) + RotL64(aOrbiterG, 35U)) + aOrbiterH) + RotL64(aCarry, 35U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 51U) + aOrbiterH) + RotL64(aOrbiterK, 13U)) + aPhaseEWandererUpdateSaltC[((aIndex + 24U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aPrevious, 23U) + RotL64(aOrbiterC, 29U)) + aOrbiterH) + RotL64(aCarry, 53U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 13U) + aOrbiterH) + RotL64(aOrbiterI, 23U)) + aPhaseEWandererUpdateSaltE[((aIndex + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 29U));
            aCarry = aCarry + (RotL64(aWandererD, 34U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererI, 51U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererC, 23U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 29850U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneA[((aIndex + 28291U)) & S_BLOCK1], 28U));
            aIngress ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28404U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 32245U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 29631U)) & S_BLOCK1], 58U));
            aCross ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 30777U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 39U) + RotL64(aCross, 27U)) ^ (RotL64(aIngress, 3U) + RotL64(aCarry, 52U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterC = (aWandererG + RotL64(aScatter, 29U)) + 13650869943246163567U;
            aOrbiterA = ((aWandererC + RotL64(aCross, 19U)) + 3435284932011770999U) + aPhaseEOrbiterAssignSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = ((aWandererA + RotL64(aIngress, 3U)) + 12388155658186776579U) + aPhaseEOrbiterAssignSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = (aWandererK + RotL64(aPrevious, 11U)) + 2374345913955712039U;
            aOrbiterB = ((aWandererJ + RotL64(aScatter, 51U)) + RotL64(aCarry, 3U)) + 6095094526980292156U;
            aOrbiterI = ((aWandererB + RotL64(aPrevious, 43U)) + RotL64(aCarry, 19U)) + 4965147025852444174U;
            aOrbiterK = ((aWandererE + RotL64(aCross, 36U)) + RotL64(aCarry, 39U)) + 3261881216269075298U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 4939780217097329222U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 3019862009792676287U;
            aOrbiterJ = RotL64((aOrbiterJ * 2452316208025448747U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 901910626217143974U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 3647055146712366383U;
            aOrbiterB = RotL64((aOrbiterB * 1792602402476450009U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 7731765438957392967U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 13409819457393479741U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3345078200262410715U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 5415832109107794258U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 8876738832313114471U;
            aOrbiterK = RotL64((aOrbiterK * 1304277600444504135U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 17135570542519390359U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 2373193062766802082U;
            aOrbiterG = RotL64((aOrbiterG * 4213691513185791519U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 16318403285501718552U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 8456043288604687045U;
            aOrbiterC = RotL64((aOrbiterC * 10556964529144571683U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 10572534930284516528U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 14616251186735204677U;
            aOrbiterI = RotL64((aOrbiterI * 2048651204265459805U), 57U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterC, 23U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 3U));
            aIngress = aIngress + (RotL64(aOrbiterB, 53U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterI, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aIngress, 3U) + RotL64(aOrbiterG, 3U)) + aOrbiterJ) + RotL64(aCarry, 37U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterK, 21U)) + aOrbiterI);
            aWandererA = aWandererA + ((RotL64(aScatter, 13U) + aOrbiterG) + RotL64(aOrbiterA, 10U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 56U) + RotL64(aOrbiterC, 51U)) + aOrbiterJ);
            aWandererC = aWandererC + (((RotL64(aPrevious, 41U) + RotL64(aOrbiterG, 27U)) + aOrbiterB) + RotL64(aCarry, 21U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 47U) + aOrbiterB) + RotL64(aOrbiterI, 41U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aIngress, 19U) + aOrbiterJ) + RotL64(aOrbiterA, 35U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 35U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 41U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 18U));
            aCarry = aCarry + RotL64(aWandererC, 3U);
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
        // read from: aOperationLaneA, aOperationLaneB, aInvestLaneD, aOperationLaneC, aOperationLaneD, aInvestLaneB, aSnowLaneA, aExpandLaneC, aInvestLaneC, aSnowLaneB, aInvestLaneA, aWorkLaneA, aExpandLaneB, aWorkLaneB, aExpandLaneA, aWorkLaneC, aExpandLaneD
        // write to: aSnowLaneA, aSnowLaneB, aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // twist_loop_c loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aInvestLaneD
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aInvestLaneD forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aInvestLaneB
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aInvestLaneB backward/forward random
        // write to: aSnowLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 2371U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneB[((aIndex + 4461U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 4771U)) & S_BLOCK1], 40U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 3177U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 2726U)) & S_BLOCK1], 46U));
            aCross ^= RotL64(aInvestLaneB[((aIndex + 3527U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 57U) + RotL64(aCarry, 5U)) + (RotL64(aCross, 42U) ^ RotL64(aIngress, 21U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterJ = (aWandererE + RotL64(aPrevious, 38U)) + 6973892330986118220U;
            aOrbiterE = ((aWandererD + RotL64(aIngress, 11U)) + RotL64(aCarry, 3U)) + 9886813896272094864U;
            aOrbiterB = ((aWandererF + RotL64(aCross, 21U)) + RotL64(aCarry, 43U)) + 10996306582517553173U;
            aOrbiterF = ((aWandererC + RotL64(aScatter, 13U)) + RotL64(aCarry, 39U)) + 8490648283899856223U;
            aOrbiterC = ((aWandererB + RotL64(aPrevious, 51U)) + 105141713530704655U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterG = (aWandererG + RotL64(aCross, 60U)) + 3114337422810562588U;
            aOrbiterH = (aWandererK + RotL64(aScatter, 47U)) + 980857684690886131U;
            aOrbiterI = (aWandererH + RotL64(aIngress, 57U)) + 6562042345807072665U;
            aOrbiterA = (aWandererJ + RotL64(aCross, 53U)) + 15665371138706353619U;
            aOrbiterD = ((aWandererI + RotL64(aPrevious, 27U)) + 18113013571374375028U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterK = (aWandererA + RotL64(aScatter, 19U)) + 17405346422601997299U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 5130876096426182506U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 1813821672299154629U;
            aOrbiterB = RotL64((aOrbiterB * 15478100342425611875U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 15793814882743306728U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 13925299440495476399U;
            aOrbiterC = RotL64((aOrbiterC * 12049601510660117401U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 9924458846049579438U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 7810034662781768090U;
            aOrbiterH = RotL64((aOrbiterH * 10310594595026622513U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 12812586478656872854U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 5709576448057435237U;
            aOrbiterA = RotL64((aOrbiterA * 9101555233909853025U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 7839807649914541516U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 4717944526755429647U;
            aOrbiterJ = RotL64((aOrbiterJ * 8515229146471335721U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 3933911971504256022U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 4814079680865379831U;
            aOrbiterD = RotL64((aOrbiterD * 15100740696230557391U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 18352577312212175569U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 9670612998448920742U;
            aOrbiterG = RotL64((aOrbiterG * 5743579439303300553U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 72737302703035726U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 10032869372369626210U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7449905669249993731U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 2669999453643982386U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 2016129534922291383U;
            aOrbiterK = RotL64((aOrbiterK * 11730911201750754301U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 5108689262300895422U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 3753457479225942895U;
            aOrbiterE = RotL64((aOrbiterE * 11503304711866175497U), 21U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 859776381005289485U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 6973892330986118220U;
            aOrbiterF = RotL64((aOrbiterF * 12337041087475258221U), 19U);
            //
            aIngress = RotL64(aOrbiterB, 43U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 5U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 41U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterD, 57U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterK, 46U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterG, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aScatter, 27U) + aOrbiterF) + RotL64(aOrbiterB, 21U));
            aWandererK = aWandererK + ((RotL64(aPrevious, 12U) + aOrbiterJ) + RotL64(aOrbiterE, 14U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 53U) + aOrbiterI) + RotL64(aOrbiterK, 57U));
            aWandererD = aWandererD + ((RotL64(aIngress, 37U) + aOrbiterK) + RotL64(aOrbiterE, 43U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterF, 53U)) + aOrbiterD);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 3U) + RotL64(aOrbiterF, 47U)) + aOrbiterH) + aPhaseFWandererUpdateSaltE[((aIndex + 18U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aCross, 51U) + RotL64(aOrbiterA, 6U)) + aOrbiterE) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aIngress, 46U) + aOrbiterB) + RotL64(aOrbiterG, 41U)) + RotL64(aCarry, 41U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 35U) + aOrbiterK) + RotL64(aOrbiterJ, 29U));
            aWandererC = aWandererC + (((RotL64(aScatter, 43U) + RotL64(aOrbiterD, 19U)) + aOrbiterE) + RotL64(aCarry, 11U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterC, 51U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 12U));
            aCarry = aCarry + (RotL64(aWandererF, 29U) ^ aWandererC);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 23U));
            aCarry = aCarry + (RotL64(aWandererA, 47U) ^ aWandererI);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 44U));
            aCarry = aCarry + RotL64(aWandererK, 3U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aSnowLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_c loop 2
        // ingress from: aSnowLaneA, aOperationLaneC, aOperationLaneD, aExpandLaneC
        // ingress directions: aSnowLaneA forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aExpandLaneC forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aInvestLaneC
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aInvestLaneC backward/forward random
        // write to: aSnowLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneA[((aIndex + 6157U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneC[((aIndex + 9175U)) & S_BLOCK1], 57U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 8704U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneC[((aIndex + 6240U)) & S_BLOCK1], 6U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 6781U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 8010U)) & S_BLOCK1], 10U));
            aCross ^= RotL64(aInvestLaneC[((aIndex + 9268U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 41U) ^ RotL64(aCross, 5U)) ^ (RotL64(aPrevious, 56U) + RotL64(aCarry, 27U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterC = ((aWandererG + RotL64(aCross, 28U)) + RotL64(aCarry, 3U)) + 3650233661228036955U;
            aOrbiterE = ((aWandererC + RotL64(aIngress, 23U)) + RotL64(aCarry, 37U)) + 11607036400067735729U;
            aOrbiterK = (aWandererH + RotL64(aScatter, 53U)) + 3899614406903883035U;
            aOrbiterF = ((aWandererE + RotL64(aPrevious, 51U)) + 8159156925629965143U) + aPhaseFOrbiterAssignSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = ((aWandererB + RotL64(aScatter, 35U)) + RotL64(aCarry, 19U)) + 7148903913967261270U;
            aOrbiterG = (aWandererA + RotL64(aPrevious, 5U)) + 9161665622287517848U;
            aOrbiterD = ((aWandererK + RotL64(aIngress, 41U)) + 2981535013474059469U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = (aWandererF + RotL64(aCross, 11U)) + 15812469008200319549U;
            aOrbiterJ = (aWandererI + RotL64(aScatter, 3U)) + 14687469489893270300U;
            aOrbiterA = (aWandererD + RotL64(aPrevious, 18U)) + 6025209349511417063U;
            aOrbiterI = (aWandererJ + RotL64(aCross, 57U)) + 12964750392311112676U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 6572355895765394340U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 3542300121890027981U;
            aOrbiterK = RotL64((aOrbiterK * 11201491178181273935U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 6477175684045398359U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 1081388388827929314U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 8752188637514143529U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 13754328481584620771U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 3684673342659575917U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 6139923312873039143U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 6542045150319909445U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 5352102692424060388U;
            aOrbiterJ = RotL64((aOrbiterJ * 7385758355501860261U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 9110100774657340354U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 2813273684436269057U;
            aOrbiterA = RotL64((aOrbiterA * 10468759062594022273U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 5860425751137403755U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 1598622981888978548U;
            aOrbiterD = RotL64((aOrbiterD * 651816500461718345U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 14710305692377606725U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 16280545617802383463U;
            aOrbiterE = RotL64((aOrbiterE * 12541767206978802063U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 6849565243667718750U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 12152381961996750050U;
            aOrbiterC = RotL64((aOrbiterC * 11185935780063403807U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 1318947876257794796U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 5447559252769140391U;
            aOrbiterF = RotL64((aOrbiterF * 13683733413554766327U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 2766869582494246454U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 15757729967222729304U;
            aOrbiterI = RotL64((aOrbiterI * 1858683399257513171U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 13063432816787882618U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 3650233661228036955U;
            aOrbiterG = RotL64((aOrbiterG * 16230564672533821641U), 37U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterC, 43U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 39U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 11U));
            aIngress = aIngress + (RotL64(aOrbiterK, 18U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterI, 5U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterG, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aScatter, 51U) + aOrbiterG) + RotL64(aOrbiterE, 53U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 27U) + aOrbiterH) + RotL64(aOrbiterI, 23U));
            aWandererF = aWandererF + ((RotL64(aIngress, 5U) + RotL64(aOrbiterI, 10U)) + aOrbiterC);
            aWandererE = aWandererE ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterA, 37U)) + aOrbiterI);
            aWandererG = aWandererG + (((RotL64(aScatter, 41U) + aOrbiterC) + RotL64(aOrbiterB, 27U)) + RotL64(aCarry, 43U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 36U) + RotL64(aOrbiterF, 39U)) + aOrbiterD);
            aWandererD = aWandererD + ((RotL64(aCross, 53U) + RotL64(aOrbiterD, 46U)) + aOrbiterI);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 23U) + aOrbiterD) + RotL64(aOrbiterE, 43U));
            aWandererK = aWandererK + (((RotL64(aCross, 57U) + aOrbiterB) + RotL64(aOrbiterK, 5U)) + RotL64(aCarry, 19U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 10U) + RotL64(aOrbiterJ, 35U)) + aOrbiterB) + aPhaseFWandererUpdateSaltF[((aIndex + 20U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 3U) + RotL64(aOrbiterD, 13U)) + aOrbiterB) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 30U));
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererA);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 21U));
            aCarry = aCarry + (RotL64(aWandererF, 43U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererI, 27U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererH, 10U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aSnowLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_c loop 3
        // ingress from: aSnowLaneB, aOperationLaneA, aInvestLaneA
        // ingress directions: aSnowLaneB forward forced, aOperationLaneA forward forced, aInvestLaneA forward/backward random
        // cross from: aSnowLaneA, aOperationLaneC
        // cross directions: aSnowLaneA backward forced, aOperationLaneC backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneB[((aIndex + 13676U)) & S_BLOCK1], 58U) ^ RotL64(aOperationLaneA[((aIndex + 14962U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aInvestLaneA[((aIndex + 12141U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 11576U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneC[((aIndex + 12083U)) & S_BLOCK1], 20U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 20U) ^ RotL64(aCross, 5U)) + (RotL64(aCarry, 39U) ^ RotL64(aPrevious, 51U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterI = (aWandererB + RotL64(aScatter, 34U)) + 17074147006464019918U;
            aOrbiterF = (aWandererI + RotL64(aPrevious, 13U)) + 10559516626129419928U;
            aOrbiterJ = (aWandererC + RotL64(aCross, 57U)) + 13280363679503946221U;
            aOrbiterG = (aWandererH + RotL64(aIngress, 41U)) + 17657115422132457413U;
            aOrbiterB = (aWandererA + RotL64(aScatter, 37U)) + 13325837013304973008U;
            aOrbiterH = (aWandererG + RotL64(aIngress, 29U)) + 3059707750486106037U;
            aOrbiterK = (aWandererK + RotL64(aPrevious, 27U)) + 4529045702503050852U;
            aOrbiterA = ((aWandererJ + RotL64(aCross, 3U)) + RotL64(aCarry, 37U)) + 10726578475550904292U;
            aOrbiterE = ((aWandererE + RotL64(aIngress, 43U)) + 14832537837996659885U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterD = ((aWandererF + RotL64(aScatter, 39U)) + RotL64(aCarry, 53U)) + 220094417441809246U;
            aOrbiterC = (((aWandererD + RotL64(aPrevious, 24U)) + RotL64(aCarry, 11U)) + 15343130035105342194U) + aPhaseFOrbiterAssignSaltC[((aIndex + 24U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 16592263353426409884U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 15649290906447931918U;
            aOrbiterJ = RotL64((aOrbiterJ * 8405875177836650731U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 11437410545843708269U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 5859769136073011444U;
            aOrbiterB = RotL64((aOrbiterB * 1065016088086441107U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 15188064100307340341U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 4367466521843260049U;
            aOrbiterG = RotL64((aOrbiterG * 15916715854192820923U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 8482617283860566845U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 2585745804937342972U;
            aOrbiterE = RotL64((aOrbiterE * 8267269625632139809U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 1687641344403425541U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 13667916445979421400U;
            aOrbiterF = RotL64((aOrbiterF * 8191322670355590027U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 7684258716388029228U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 14764266202380443369U;
            aOrbiterI = RotL64((aOrbiterI * 1746254773647650741U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 12685190466981675661U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 9958374400222383893U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 12696606920219838929U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 1352584794098160330U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 16057453941015251708U;
            aOrbiterC = RotL64((aOrbiterC * 6051546505117202495U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 5642244742563733299U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 2946279435712646692U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 3711867103848631343U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 17305358424001395035U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 1831722001182742673U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 13867284970939557547U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 12354430852596737299U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 17074147006464019918U;
            aOrbiterH = RotL64((aOrbiterH * 17316050599218057961U), 47U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterK, 51U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 46U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 29U));
            aIngress = aIngress + (RotL64(aOrbiterI, 19U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 21U));
            aIngress = aIngress + RotL64(aOrbiterA, 12U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterA, 60U)) + aOrbiterG);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 60U) + RotL64(aOrbiterH, 39U)) + aOrbiterK) + RotL64(aCarry, 43U)) + aPhaseFWandererUpdateSaltA[((aIndex + 25U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 21U) + aOrbiterK) + RotL64(aOrbiterB, 23U));
            aWandererJ = aWandererJ + ((RotL64(aScatter, 57U) + RotL64(aOrbiterE, 21U)) + aOrbiterJ);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterK, 37U)) + aOrbiterI);
            aWandererK = aWandererK + (((RotL64(aScatter, 19U) + RotL64(aOrbiterK, 41U)) + aOrbiterC) + RotL64(aCarry, 47U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 27U) + aOrbiterE) + RotL64(aOrbiterK, 14U));
            aWandererB = aWandererB + ((RotL64(aCross, 51U) + aOrbiterA) + RotL64(aOrbiterE, 47U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterE, 27U)) + aOrbiterD);
            aWandererG = aWandererG + ((RotL64(aScatter, 53U) + aOrbiterH) + RotL64(aOrbiterI, 5U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 6U) + RotL64(aOrbiterF, 3U)) + aOrbiterA) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 30U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererG, 3U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererI, 35U) ^ aWandererE);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 5U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 60U));
            aCarry = aCarry + RotL64(aWandererK, 23U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_c loop 4
        // ingress from: aWorkLaneA, aSnowLaneA, aExpandLaneB
        // ingress directions: aWorkLaneA forward forced, aSnowLaneA forward forced, aExpandLaneB forward/backward random
        // cross from: aSnowLaneB, aOperationLaneD
        // cross directions: aSnowLaneB backward forced, aOperationLaneD backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 17114U)) & S_BLOCK1], 39U) ^ RotL64(aSnowLaneA[((aIndex + 21298U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 20268U)) & S_BLOCK1], 60U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 20585U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneD[((aIndex + 21655U)) & S_BLOCK1], 54U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 23U) + RotL64(aPrevious, 5U)) ^ (RotL64(aCross, 38U) + RotL64(aIngress, 51U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterK = (aWandererF + RotL64(aCross, 14U)) + 9446153639709651566U;
            aOrbiterD = (aWandererD + RotL64(aPrevious, 27U)) + 10550762260670758167U;
            aOrbiterF = (aWandererI + RotL64(aIngress, 3U)) + 7062634922142578383U;
            aOrbiterH = ((aWandererC + RotL64(aScatter, 53U)) + RotL64(aCarry, 5U)) + 9178499097812764515U;
            aOrbiterJ = ((aWandererA + RotL64(aCross, 23U)) + RotL64(aCarry, 43U)) + 6887103379773525538U;
            aOrbiterE = (aWandererK + RotL64(aIngress, 47U)) + 6239750312052010257U;
            aOrbiterA = (aWandererE + RotL64(aPrevious, 5U)) + 17645022614523287959U;
            aOrbiterB = (aWandererH + RotL64(aScatter, 40U)) + 3639618183259408272U;
            aOrbiterG = ((aWandererJ + RotL64(aCross, 29U)) + 3131737117548745095U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterC = (((aWandererG + RotL64(aIngress, 19U)) + RotL64(aCarry, 21U)) + 7253994382396406554U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterI = (aWandererB + RotL64(aPrevious, 37U)) + 15217993711938379561U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 12594152227603630033U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 11250170200489647869U;
            aOrbiterF = RotL64((aOrbiterF * 546800378327864723U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 12936942656624279424U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 10990736056052106149U;
            aOrbiterK = RotL64((aOrbiterK * 7123916809953459187U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 12787293075893090465U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 17154990205620778151U;
            aOrbiterB = RotL64((aOrbiterB * 10031369940028159521U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 1270827262969060301U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 17337623431665013136U;
            aOrbiterE = RotL64((aOrbiterE * 1517262088236356107U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 830330490987911853U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 6828309232554560547U;
            aOrbiterA = RotL64((aOrbiterA * 9742464176986145819U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 11470087853413986203U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 10470148870747884420U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 6766079738799967443U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 18315536891901859637U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 12264670822285914271U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 5841574505408674119U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 10931842095884524879U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 11134871340959676257U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 11714837622285605745U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 11484168476761306078U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 5964766416973454097U;
            aOrbiterG = RotL64((aOrbiterG * 14721123403032510803U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 10646362765367117994U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 8994267196877016381U;
            aOrbiterD = RotL64((aOrbiterD * 17386417559346134797U), 37U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 16797547458402042464U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 9446153639709651566U;
            aOrbiterI = RotL64((aOrbiterI * 567585472220695323U), 3U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterB, 19U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 4U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 37U));
            aIngress = aIngress + (RotL64(aOrbiterA, 11U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 21U));
            aIngress = aIngress + RotL64(aOrbiterJ, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterH, 26U)) + aOrbiterJ);
            aWandererC = aWandererC + (((RotL64(aScatter, 19U) + RotL64(aOrbiterE, 51U)) + aOrbiterK) + RotL64(aCarry, 53U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 47U) + aOrbiterD) + RotL64(aOrbiterA, 47U));
            aWandererD = aWandererD + ((RotL64(aIngress, 51U) + RotL64(aOrbiterH, 39U)) + aOrbiterF);
            aWandererI = aWandererI ^ (((RotL64(aCross, 41U) + aOrbiterF) + RotL64(aOrbiterG, 43U)) + aPhaseFWandererUpdateSaltD[((aIndex + 13U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aPrevious, 44U) + aOrbiterB) + RotL64(aOrbiterE, 13U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 3U) + RotL64(aOrbiterI, 34U)) + aOrbiterA) + aPhaseFWandererUpdateSaltE[((aIndex + 15U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 39U) + RotL64(aOrbiterC, 5U)) + aOrbiterD) + RotL64(aCarry, 11U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterF, 57U)) + aOrbiterJ);
            aWandererF = aWandererF + ((RotL64(aIngress, 56U) + aOrbiterC) + RotL64(aOrbiterK, 11U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterD, 41U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 43U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 6U));
            aCarry = aCarry + (RotL64(aWandererC, 19U) ^ aWandererJ);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 27U));
            aCarry = aCarry + (RotL64(aWandererA, 57U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererF, 53U);
            aCarry = aCarry + RotL64(aIngress, 40U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 22880U)) & S_BLOCK1], 19U) ^ RotL64(aSnowLaneB[((aIndex + 22989U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 26438U)) & S_BLOCK1], 30U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23887U)) & S_BLOCK1], 14U) ^ RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 23417U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 57U) + RotL64(aIngress, 42U)) + (RotL64(aCross, 27U) ^ RotL64(aPrevious, 13U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterJ = (aWandererJ + RotL64(aIngress, 21U)) + 3684295017013759987U;
            aOrbiterF = ((aWandererD + RotL64(aPrevious, 30U)) + 6740408842457292881U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = (aWandererC + RotL64(aScatter, 39U)) + 4563975890702399441U;
            aOrbiterE = (aWandererI + RotL64(aCross, 19U)) + 797804144825287940U;
            aOrbiterI = (aWandererK + RotL64(aScatter, 13U)) + 2763779540450101303U;
            aOrbiterC = ((aWandererA + RotL64(aIngress, 11U)) + 13211846164102089685U) + aPhaseFOrbiterAssignSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterK = ((aWandererH + RotL64(aPrevious, 35U)) + RotL64(aCarry, 11U)) + 15214578447281401982U;
            aOrbiterG = ((aWandererB + RotL64(aCross, 3U)) + RotL64(aCarry, 21U)) + 13745208628754232427U;
            aOrbiterH = (aWandererE + RotL64(aPrevious, 37U)) + 17358621225969190747U;
            aOrbiterA = (aWandererF + RotL64(aCross, 43U)) + 779739369960480023U;
            aOrbiterB = ((aWandererG + RotL64(aIngress, 58U)) + RotL64(aCarry, 47U)) + 4370963533701407813U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 6061333005507739975U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 3589705340762734456U;
            aOrbiterD = RotL64((aOrbiterD * 16499293983611196967U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 10607697666369230567U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 9356757995305239271U;
            aOrbiterI = RotL64((aOrbiterI * 10945513661439954731U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 10093033335903048138U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 11037328061699834100U;
            aOrbiterK = RotL64((aOrbiterK * 11189760551792389605U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 558431161176115540U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 17795680919453449358U;
            aOrbiterH = RotL64((aOrbiterH * 3910117359996283803U), 39U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 6096779391116214109U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 17594243286880690775U;
            aOrbiterC = RotL64((aOrbiterC * 12655610181937429915U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 15414704802398002423U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 18040588240488602196U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 16344249573086571225U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 14636298592697156931U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 9677305688594936561U;
            aOrbiterF = RotL64((aOrbiterF * 8354776999961642997U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 16408025751875050713U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 10018342878801454965U;
            aOrbiterB = RotL64((aOrbiterB * 10349132962708124117U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 1841090936357114866U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 16142637455878447020U;
            aOrbiterG = RotL64((aOrbiterG * 10565394571714418033U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 4089676582910615502U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 8749600984499831109U;
            aOrbiterJ = RotL64((aOrbiterJ * 3421055105090316521U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 11408932421005107097U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 3684295017013759987U;
            aOrbiterA = RotL64((aOrbiterA * 7037953759624065417U), 3U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterF, 60U);
            aIngress = aIngress + (RotL64(aOrbiterI, 35U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 3U));
            aIngress = aIngress + (RotL64(aOrbiterK, 27U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 5U));
            aIngress = aIngress + RotL64(aOrbiterC, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aCross, 41U) + RotL64(aOrbiterD, 37U)) + aOrbiterC) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterD, 10U)) + aOrbiterJ);
            aWandererK = aWandererK + (((RotL64(aPrevious, 26U) + RotL64(aOrbiterK, 43U)) + aOrbiterF) + RotL64(aCarry, 19U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 11U) + aOrbiterB) + RotL64(aOrbiterK, 39U));
            aWandererF = aWandererF + ((RotL64(aIngress, 23U) + aOrbiterK) + RotL64(aOrbiterH, 27U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 57U) + aOrbiterB) + RotL64(aOrbiterH, 23U));
            aWandererA = aWandererA + ((RotL64(aCross, 3U) + aOrbiterG) + RotL64(aOrbiterJ, 21U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 28U) + aOrbiterE) + RotL64(aOrbiterC, 41U));
            aWandererE = aWandererE + ((RotL64(aPrevious, 37U) + RotL64(aOrbiterH, 3U)) + aOrbiterE);
            aWandererC = aWandererC ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterA, 30U)) + aOrbiterI);
            aWandererD = aWandererD + ((((RotL64(aScatter, 43U) + aOrbiterK) + RotL64(aOrbiterA, 13U)) + RotL64(aCarry, 39U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 22U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererB, 29U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererA, 43U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererK, 37U) ^ aWandererD);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 3U));
            aCarry = aCarry + RotL64(aWandererE, 18U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 30113U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((aIndex + 27694U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aExpandLaneD[((aIndex + 27609U)) & S_BLOCK1], 44U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 28492U)) & S_BLOCK1], 40U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 29870U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 57U) ^ RotL64(aCarry, 39U)) + (RotL64(aCross, 5U) + RotL64(aPrevious, 22U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterK = ((aWandererE + RotL64(aPrevious, 51U)) + 10805654776556844351U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = (aWandererB + RotL64(aCross, 60U)) + 582794182442795335U;
            aOrbiterA = (aWandererC + RotL64(aIngress, 41U)) + 2858343650974681068U;
            aOrbiterJ = (aWandererJ + RotL64(aScatter, 43U)) + 8189584049022064284U;
            aOrbiterC = (aWandererK + RotL64(aIngress, 39U)) + 1565100751996962893U;
            aOrbiterD = (aWandererA + RotL64(aPrevious, 36U)) + 8062028016947611891U;
            aOrbiterB = (((aWandererG + RotL64(aCross, 13U)) + RotL64(aCarry, 37U)) + 8280504280578451745U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterE = (aWandererI + RotL64(aScatter, 23U)) + 11326869194491655350U;
            aOrbiterH = (aWandererF + RotL64(aIngress, 27U)) + 1671695656567777163U;
            aOrbiterI = ((aWandererD + RotL64(aScatter, 47U)) + RotL64(aCarry, 21U)) + 2349843105293943452U;
            aOrbiterF = ((aWandererH + RotL64(aPrevious, 3U)) + RotL64(aCarry, 5U)) + 13015545152052004254U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 16703354404749291869U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 8713231044374305801U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 9242480982197688625U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 11118401674497783533U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 14857556493734710364U;
            aOrbiterD = RotL64((aOrbiterD * 3452566050389715195U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 12953419670951660965U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 12666121730825089017U;
            aOrbiterE = RotL64((aOrbiterE * 14049925256934142519U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 11075249639473053423U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 9374217688244187867U;
            aOrbiterI = RotL64((aOrbiterI * 5261156325627117877U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 17608340953291367867U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 13159437499327086340U;
            aOrbiterC = RotL64((aOrbiterC * 4882100944453534805U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 4304700511322366815U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 10172544755256706767U;
            aOrbiterF = RotL64((aOrbiterF * 4013006212154771797U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 17340067939877432472U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 14130447570008179105U;
            aOrbiterK = RotL64((aOrbiterK * 8178075071208718915U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 2652532710498072378U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 10384945384238518296U;
            aOrbiterB = RotL64((aOrbiterB * 17137694272394304045U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 15292159041119433363U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 12103644911645285108U;
            aOrbiterG = RotL64((aOrbiterG * 4565615406415614103U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 16307525158627275744U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 3786908390177579447U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 6592585847755318801U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 13595883419843505634U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 10805654776556844351U;
            aOrbiterJ = RotL64((aOrbiterJ * 10956465099104915639U), 43U);
            //
            aIngress = RotL64(aOrbiterA, 19U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterG, 5U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 41U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 57U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 12U));
            aIngress = aIngress + RotL64(aOrbiterI, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aScatter, 35U) + RotL64(aOrbiterC, 39U)) + aOrbiterK);
            aWandererE = aWandererE ^ (((RotL64(aCross, 4U) + aOrbiterB) + RotL64(aOrbiterE, 5U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aPrevious, 23U) + RotL64(aOrbiterK, 27U)) + aOrbiterJ);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterG, 58U)) + aOrbiterK);
            aWandererA = aWandererA + (((RotL64(aCross, 21U) + RotL64(aOrbiterF, 23U)) + aOrbiterA) + RotL64(aCarry, 21U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 53U) + aOrbiterH) + RotL64(aOrbiterC, 37U));
            aWandererF = aWandererF + (((RotL64(aIngress, 6U) + aOrbiterH) + RotL64(aOrbiterA, 13U)) + RotL64(aCarry, 5U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterB, 47U)) + aOrbiterD);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 27U) + RotL64(aOrbiterA, 21U)) + aOrbiterI);
            aWandererG = aWandererG ^ (((RotL64(aCross, 41U) + aOrbiterC) + RotL64(aOrbiterA, 10U)) + aPhaseFWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aScatter, 29U) + aOrbiterE) + RotL64(aOrbiterG, 35U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 6U) ^ aWandererE);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 13U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 37U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 41U));
            aCarry = aCarry + (RotL64(aWandererH, 34U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererC, 43U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 1928U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneB[((aIndex + 7312U)) & S_BLOCK1], 36U));
            aIngress ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 2814U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 5851U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 6754U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aOperationLaneA[((aIndex + 6557U)) & S_BLOCK1], 52U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 39U) ^ RotL64(aPrevious, 56U)) + (RotL64(aIngress, 23U) ^ RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterJ = ((aWandererF + RotL64(aIngress, 11U)) + RotL64(aCarry, 19U)) + 13687218104610230596U;
            aOrbiterE = (((aWandererD + RotL64(aPrevious, 42U)) + RotL64(aCarry, 5U)) + 6841550124960692709U) + aPhaseGOrbiterAssignSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterH = (((aWandererE + RotL64(aScatter, 3U)) + RotL64(aCarry, 37U)) + 17418968668458764131U) + aPhaseGOrbiterAssignSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = (aWandererC + RotL64(aCross, 19U)) + 8303537912696948204U;
            aOrbiterF = (aWandererB + RotL64(aScatter, 53U)) + 12376614417285936537U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 14215749063579232654U) + aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 4111736931433665347U;
            aOrbiterH = RotL64((aOrbiterH * 8841288213954433049U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 11250375934571631522U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 5367367837773331275U) ^ aPhaseGOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7262723007545807179U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 15514089192382674434U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 1475991716685034960U;
            aOrbiterJ = RotL64((aOrbiterJ * 17720681295551650891U), 21U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 5531622777788629748U) + aPhaseGOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 8363822215908303335U) ^ aPhaseGOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 17850203366840994883U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 3741256932685720414U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 11634667238062155772U;
            aOrbiterF = RotL64((aOrbiterF * 15925089729784547403U), 13U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterJ, 21U);
            aIngress = aIngress + (RotL64(aOrbiterF, 47U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterA, 58U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aCross, 24U) + RotL64(aOrbiterE, 5U)) + aOrbiterF);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 5U) + aOrbiterH) + RotL64(aOrbiterA, 23U)) + RotL64(aCarry, 23U)) + aPhaseGWandererUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 51U) + aOrbiterA) + RotL64(aOrbiterJ, 57U)) + aPhaseGWandererUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 13U) + RotL64(aOrbiterA, 34U)) + aOrbiterE) + RotL64(aCarry, 47U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterJ, 13U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererF, 29U) ^ aWandererB);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 3U));
            aCarry = aCarry + RotL64(aWandererC, 21U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 10170U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneC[((aIndex + 8911U)) & S_BLOCK1], 60U));
            aIngress ^= RotL64(aInvestLaneB[((aIndex + 12322U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16067U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 14260U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 10800U)) & S_BLOCK1], 6U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 57U) ^ RotL64(aIngress, 6U)) ^ (RotL64(aPrevious, 39U) + RotL64(aCarry, 19U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterH = (((aWandererA + RotL64(aScatter, 3U)) + RotL64(aCarry, 23U)) + 77518479758428414U) + aPhaseGOrbiterAssignSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = (aWandererB + RotL64(aCross, 47U)) + 4832061802166300011U;
            aOrbiterE = ((aWandererK + RotL64(aPrevious, 11U)) + RotL64(aCarry, 53U)) + 11695291171006574112U;
            aOrbiterC = (((aWandererG + RotL64(aIngress, 58U)) + RotL64(aCarry, 11U)) + 7467412817843260094U) + aPhaseGOrbiterAssignSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = (aWandererH + RotL64(aScatter, 29U)) + 17801484124471154757U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 5555455638503958639U) + aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 5669470540733721606U) ^ aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 17219613748084498879U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 3042388456327784163U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 2236734925228156691U) ^ aPhaseGOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10076582424701705531U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 14459720401528685450U) + aPhaseGOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 4814967631216658856U;
            aOrbiterC = RotL64((aOrbiterC * 18288097536171386643U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 16950679344449075945U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 6262238639302011050U;
            aOrbiterJ = RotL64((aOrbiterJ * 9942659897425088183U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 3522256359074996724U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 12524717897707074242U;
            aOrbiterH = RotL64((aOrbiterH * 6787771338063891989U), 53U);
            //
            aIngress = RotL64(aOrbiterH, 41U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 19U));
            aIngress = aIngress + RotL64(aOrbiterJ, 6U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aPrevious, 3U) + aOrbiterH) + RotL64(aOrbiterC, 43U)) + RotL64(aCarry, 35U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 30U) + RotL64(aOrbiterA, 35U)) + aOrbiterE);
            aWandererB = aWandererB + ((((RotL64(aScatter, 43U) + aOrbiterC) + RotL64(aOrbiterA, 13U)) + RotL64(aCarry, 53U)) + aPhaseGWandererUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterH, 5U)) + aOrbiterJ);
            aWandererH = aWandererH + (((RotL64(aScatter, 19U) + aOrbiterJ) + RotL64(aOrbiterA, 56U)) + aPhaseGWandererUpdateSaltC[((aIndex + 4U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 57U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererB, 35U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererG, 11U);
            aCarry = aCarry + RotL64(aIngress, 46U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 23659U)) & S_BLOCK1], 50U) ^ RotL64(aWorkLaneD[((aIndex + 21174U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aInvestLaneC[((aIndex + 23061U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 20271U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 19930U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 20341U)) & S_BLOCK1], 58U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 4U) ^ RotL64(aCarry, 35U)) + (RotL64(aIngress, 23U) ^ RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterE = (aWandererG + RotL64(aScatter, 57U)) + 13924571355038625040U;
            aOrbiterG = ((aWandererC + RotL64(aIngress, 21U)) + 16328300979357156658U) + aPhaseGOrbiterAssignSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterJ = ((aWandererI + RotL64(aPrevious, 44U)) + RotL64(aCarry, 53U)) + 3947771961206012461U;
            aOrbiterD = (((aWandererA + RotL64(aCross, 3U)) + RotL64(aCarry, 23U)) + 15428284250569311285U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = ((aWandererK + RotL64(aIngress, 29U)) + RotL64(aCarry, 35U)) + 5777369485254032486U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 16813320300717644673U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 16689933050200758251U;
            aOrbiterJ = RotL64((aOrbiterJ * 4832495563863469353U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 1856422419049390708U) + aPhaseGOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 18214498743831925517U;
            aOrbiterG = RotL64((aOrbiterG * 10744120577560529379U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 18278550878494094923U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 797712062039591797U;
            aOrbiterE = RotL64((aOrbiterE * 7212998747080137625U), 39U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 15854849439012341347U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 996882939768167773U;
            aOrbiterD = RotL64((aOrbiterD * 14936703950807908575U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 3005829974130671692U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 8793495343509953906U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 14065479348374612031U), 57U);
            //
            aIngress = RotL64(aOrbiterB, 47U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 60U));
            aIngress = aIngress + RotL64(aOrbiterJ, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aScatter, 43U) + RotL64(aOrbiterD, 57U)) + aOrbiterE) + aPhaseGWandererUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 3U) + aOrbiterB) + RotL64(aOrbiterJ, 47U)) + RotL64(aCarry, 5U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 11U) + RotL64(aOrbiterG, 22U)) + aOrbiterJ) + aPhaseGWandererUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aPrevious, 23U) + RotL64(aOrbiterB, 3U)) + aOrbiterD) + RotL64(aCarry, 23U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 54U) + RotL64(aOrbiterE, 37U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 35U));
            aCarry = aCarry + (RotL64(aWandererK, 60U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererA, 5U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 32555U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneA[((aIndex + 27477U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 30183U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 26109U)) & S_BLOCK1], 30U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 29995U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aOperationLaneD[((aIndex + 27372U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 53U) + RotL64(aIngress, 41U)) ^ (RotL64(aCarry, 24U) ^ RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterH = ((aWandererD + RotL64(aPrevious, 35U)) + RotL64(aCarry, 39U)) + 13583136155674166402U;
            aOrbiterK = ((aWandererG + RotL64(aCross, 43U)) + 12830472187484919497U) + aPhaseGOrbiterAssignSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterE = (aWandererB + RotL64(aIngress, 3U)) + 18081197909484522509U;
            aOrbiterD = ((aWandererC + RotL64(aScatter, 19U)) + RotL64(aCarry, 57U)) + 8680634051297891550U;
            aOrbiterI = (((aWandererF + RotL64(aCross, 56U)) + RotL64(aCarry, 13U)) + 13939998767458656823U) + aPhaseGOrbiterAssignSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 1795730579103692594U) + aPhaseGOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 17369751719734069999U;
            aOrbiterE = RotL64((aOrbiterE * 2633464694273697123U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 224769585901248068U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 4133547085925268180U;
            aOrbiterK = RotL64((aOrbiterK * 2611561365156544735U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 7022512056309567391U) + aPhaseGOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 10319484359046945495U;
            aOrbiterD = RotL64((aOrbiterD * 3400140531307001933U), 53U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 10483878349412282069U) + aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 6481381149199985736U;
            aOrbiterI = RotL64((aOrbiterI * 9701719367082506253U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 13721077228796934509U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 9704818014314175007U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 760445624027740287U), 29U);
            //
            aIngress = RotL64(aOrbiterH, 53U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterI, 27U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterE, 40U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterH, 4U)) + aOrbiterD);
            aWandererF = aWandererF + (((RotL64(aIngress, 11U) + RotL64(aOrbiterK, 51U)) + aOrbiterE) + RotL64(aCarry, 3U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 19U) + aOrbiterK) + RotL64(aOrbiterH, 39U)) + aPhaseGWandererUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 48U) + aOrbiterI) + RotL64(aOrbiterK, 13U)) + RotL64(aCarry, 23U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 29U) + aOrbiterD) + RotL64(aOrbiterI, 27U)) + aPhaseGWandererUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 51U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererD, 19U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererC, 4U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 4973U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneB[((aIndex + 5424U)) & S_BLOCK1], 18U));
            aIngress ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 7920U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 7767U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 2457U)) & S_BLOCK1], 48U));
            aCross ^= RotL64(aOperationLaneA[((aIndex + 3038U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 3U) + RotL64(aPrevious, 19U)) + (RotL64(aIngress, 51U) ^ RotL64(aCarry, 38U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterH = ((aWandererA + RotL64(aPrevious, 35U)) + 3917730204724097072U) + aPhaseHOrbiterAssignSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterK = ((aWandererC + RotL64(aIngress, 27U)) + RotL64(aCarry, 43U)) + 1874642340716212824U;
            aOrbiterC = ((aWandererE + RotL64(aScatter, 53U)) + RotL64(aCarry, 19U)) + 6900165757434854160U;
            aOrbiterE = ((aWandererJ + RotL64(aCross, 4U)) + 12750946097023807161U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterD = ((aWandererI + RotL64(aPrevious, 43U)) + RotL64(aCarry, 57U)) + 6563216048479513594U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 14960240191349450795U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 16306180275951788289U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12077366095522790283U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 6502066618271045547U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 6219852857850888738U;
            aOrbiterD = RotL64((aOrbiterD * 10892297250334325283U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 2272931312452845850U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 3028929882263199463U;
            aOrbiterK = RotL64((aOrbiterK * 11005324285856805069U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 6067393030073568112U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 10094809900437037258U;
            aOrbiterH = RotL64((aOrbiterH * 18095564940730322769U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 5962414178157074575U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 15755563045799129417U;
            aOrbiterE = RotL64((aOrbiterE * 3692603590609922031U), 23U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterC, 13U);
            aIngress = aIngress + (RotL64(aOrbiterE, 56U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterK, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aIngress, 21U) + aOrbiterK) + RotL64(aOrbiterE, 5U)) + aPhaseHWandererUpdateSaltE[((aIndex + 25U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 11U) + RotL64(aOrbiterD, 18U)) + aOrbiterK) + aPhaseHWandererUpdateSaltC[((aIndex + 26U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 3U) + RotL64(aOrbiterD, 53U)) + aOrbiterC) + RotL64(aCarry, 51U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 52U) + RotL64(aOrbiterE, 35U)) + aOrbiterH);
            aWandererI = aWandererI + (((RotL64(aIngress, 41U) + RotL64(aOrbiterH, 43U)) + aOrbiterC) + RotL64(aCarry, 23U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 23U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 57U));
            aCarry = aCarry + RotL64(aWandererC, 34U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 13720U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneC[((aIndex + 11324U)) & S_BLOCK1], 52U));
            aIngress ^= RotL64(aInvestLaneB[((aIndex + 16254U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 15871U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 14718U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 10795U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 53U) + RotL64(aPrevious, 36U)) ^ (RotL64(aCross, 21U) + RotL64(aIngress, 3U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterE = (aWandererI + RotL64(aPrevious, 19U)) + 13333509828310369865U;
            aOrbiterC = (((aWandererE + RotL64(aCross, 11U)) + RotL64(aCarry, 13U)) + 7645352517103840797U) + aPhaseHOrbiterAssignSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = (((aWandererC + RotL64(aIngress, 29U)) + RotL64(aCarry, 47U)) + 5310766306660062655U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = ((aWandererF + RotL64(aScatter, 39U)) + RotL64(aCarry, 29U)) + 5165635069832352932U;
            aOrbiterI = (aWandererK + RotL64(aIngress, 56U)) + 15684141764734281849U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 3327963374225061738U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 8625811794878848871U;
            aOrbiterG = RotL64((aOrbiterG * 16327750494894125333U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 7598657468430485291U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 2881171216276746485U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 3331350584102843605U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 10237691227222918101U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 6419254255884834497U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 3816625473642865305U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 4238455444646479956U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 14936613353493061492U;
            aOrbiterE = RotL64((aOrbiterE * 3544216916806292273U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 15324699725208372627U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 9506640480601832011U;
            aOrbiterJ = RotL64((aOrbiterJ * 12819564111348390227U), 57U);
            //
            aIngress = RotL64(aOrbiterI, 57U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterE, 36U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterJ, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aScatter, 5U) + aOrbiterG) + RotL64(aOrbiterC, 51U));
            aWandererF = aWandererF + ((((RotL64(aPrevious, 52U) + RotL64(aOrbiterC, 4U)) + aOrbiterE) + RotL64(aCarry, 53U)) + aPhaseHWandererUpdateSaltA[((aIndex + 12U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterJ, 23U)) + aOrbiterG);
            aWandererI = aWandererI + (((RotL64(aIngress, 37U) + RotL64(aOrbiterE, 43U)) + aOrbiterJ) + RotL64(aCarry, 21U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 21U) + RotL64(aOrbiterI, 13U)) + aOrbiterG) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 11U));
            aCarry = aCarry + (RotL64(aWandererI, 51U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererE, 35U);
            aCarry = aCarry + RotL64(aIngress, 60U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 20980U)) & S_BLOCK1], 48U) ^ RotL64(aExpandLaneD[((aIndex + 21469U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aInvestLaneC[((aIndex + 18266U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17357U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 22034U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 20271U)) & S_BLOCK1], 22U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 21U) ^ RotL64(aCross, 53U)) ^ (RotL64(aPrevious, 36U) + RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterC = (((aWandererK + RotL64(aIngress, 30U)) + RotL64(aCarry, 43U)) + 13650869943246163567U) + aPhaseHOrbiterAssignSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterF = ((aWandererD + RotL64(aPrevious, 11U)) + RotL64(aCarry, 29U)) + 3435284932011770999U;
            aOrbiterB = (aWandererA + RotL64(aScatter, 47U)) + 12388155658186776579U;
            aOrbiterI = (((aWandererJ + RotL64(aCross, 21U)) + RotL64(aCarry, 13U)) + 2374345913955712039U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterA = (aWandererB + RotL64(aScatter, 39U)) + 6095094526980292156U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 4965147025852444174U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 3261881216269075298U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4874733445914960785U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 4939780217097329222U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 3019862009792676287U;
            aOrbiterI = RotL64((aOrbiterI * 2452316208025448747U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 901910626217143974U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 3647055146712366383U;
            aOrbiterF = RotL64((aOrbiterF * 1792602402476450009U), 5U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 7731765438957392967U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 13409819457393479741U;
            aOrbiterA = RotL64((aOrbiterA * 3345078200262410715U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 5415832109107794258U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 8876738832313114471U;
            aOrbiterC = RotL64((aOrbiterC * 1304277600444504135U), 13U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterA, 3U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 13U));
            aIngress = aIngress + RotL64(aOrbiterC, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aIngress, 37U) + aOrbiterI) + RotL64(aOrbiterA, 39U)) + RotL64(aCarry, 11U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 21U) + aOrbiterB) + RotL64(aOrbiterF, 6U));
            aWandererA = aWandererA + (((RotL64(aCross, 5U) + aOrbiterA) + RotL64(aOrbiterC, 57U)) + RotL64(aCarry, 39U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 13U) + aOrbiterF) + RotL64(aOrbiterC, 19U)) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 58U) + RotL64(aOrbiterB, 27U)) + aOrbiterI) + aPhaseHWandererUpdateSaltB[((aIndex + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 3U));
            aCarry = aCarry + (RotL64(aWandererK, 11U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererB, 56U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 29273U)) & S_BLOCK1], 18U) ^ RotL64(aWorkLaneA[((aIndex + 29377U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aInvestLaneD[((aIndex + 25567U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 32480U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 29691U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 28224U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 37U) + RotL64(aCross, 53U)) ^ (RotL64(aCarry, 3U) + RotL64(aPrevious, 22U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterE = ((aWandererG + RotL64(aScatter, 5U)) + RotL64(aCarry, 27U)) + 9133751643283278896U;
            aOrbiterF = (((aWandererH + RotL64(aIngress, 20U)) + RotL64(aCarry, 51U)) + 8971581804375380408U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = (aWandererB + RotL64(aPrevious, 29U)) + 12559650383714566592U;
            aOrbiterH = ((aWandererE + RotL64(aCross, 53U)) + RotL64(aCarry, 5U)) + 15753206088872859163U;
            aOrbiterD = ((aWandererK + RotL64(aScatter, 41U)) + 7640756270450762350U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 7340073357551376125U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 5270256573644196046U;
            aOrbiterK = RotL64((aOrbiterK * 13286406906662922841U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 3567367996479995928U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 11939634537492733738U;
            aOrbiterE = RotL64((aOrbiterE * 5640541900117183639U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 7051817732424527120U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 1730487669951837941U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 15191634337956285841U), 43U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 18009252467909454817U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 2361024272031696442U;
            aOrbiterF = RotL64((aOrbiterF * 15215151562500226027U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 15902755877642960397U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 12243517544704116184U;
            aOrbiterD = RotL64((aOrbiterD * 2576071074148141447U), 5U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterE, 40U);
            aIngress = aIngress + (RotL64(aOrbiterH, 51U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterF, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aPrevious, 22U) + aOrbiterD) + RotL64(aOrbiterE, 29U)) + RotL64(aCarry, 43U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterE, 3U)) + aOrbiterF);
            aWandererH = aWandererH + ((((RotL64(aIngress, 13U) + RotL64(aOrbiterF, 19U)) + aOrbiterK) + RotL64(aCarry, 5U)) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterH, 47U)) + aOrbiterK);
            aWandererB = aWandererB + (((RotL64(aIngress, 53U) + RotL64(aOrbiterF, 56U)) + aOrbiterH) + aPhaseHWandererUpdateSaltC[((aIndex + 18U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 5U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 48U));
            aCarry = aCarry + RotL64(aWandererG, 29U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
