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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xA82E8B1E114A9D35ULL + 0xD005570725AFBE5FULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x928C1FCCB72E8889ULL + 0xC243A343BDFC0B0BULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x9F0079C94FB1DC11ULL + 0x92B110DEA66EDBBBULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x83A01D907CB8BC3DULL + 0xD51111BF673DB5A0ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xAC5A339C8002190DULL + 0xAE843764E39CBBE2ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x9DD06002582256A3ULL + 0xF764B343DAA06664ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xA05AA41CE388DC63ULL + 0x9486EC2FBC183E58ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x900BEA719CC2F315ULL + 0xE6E2CF63B9BE328CULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x9282E063B55292C7ULL + 0xDEBEB2540289CC5FULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x898F44AE393971A7ULL + 0xBDC4B1C112FAD418ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xD49E4CC936BE1C27ULL + 0xBC3851389B5726A5ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xACF62D90EAED09F7ULL + 0xDDD271DDE62379FFULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xD36092F472F4EC57ULL + 0xDD432F89BD73F70AULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xDC6DB7D7C3829663ULL + 0xE6110832BDA956DBULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xDC4EE1A08C7A8F41ULL + 0xA8F2A3A4225F1035ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0x903F3F2667D17145ULL + 0xE765ED3F4B268CE3ULL);
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
            aIngress = RotL64(mSource[((aIndex + 4764U)) & S_BLOCK1], 21U) ^ RotL64(pSnow[((aIndex + 3954U)) & S_BLOCK1], 38U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(pSnow[((S_BLOCK1 - aIndex + 2096U)) & S_BLOCK1], 13U) ^ RotL64(mSource[((aIndex + 3942U)) & S_BLOCK1], 36U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aPrevious, 11U) ^ RotL64(aCarry, 41U)) + (RotL64(aCross, 24U) ^ RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterJ = (aWandererE + RotL64(aScatter, 5U)) + 8604208734152026945U;
            aOrbiterF = (aWandererH + RotL64(aIngress, 56U)) + 1374329953253889829U;
            aOrbiterI = ((((aWandererD + RotL64(aPrevious, 43U)) + RotL64(aCarry, 43U)) + 5779278910548228339U) + aOrbiterAssignSaltD[((aIndex + 7U)) & S_SALT1]) + aNonceWordA;
            aOrbiterD = ((aWandererA + RotL64(aCross, 39U)) + 17670451230882805140U) + aOrbiterAssignSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterB = (aWandererK + RotL64(aIngress, 53U)) + 8193848740764866860U;
            aOrbiterA = (aWandererI + RotL64(aPrevious, 47U)) + 15801168428145650104U;
            aOrbiterK = ((aWandererG + RotL64(aCross, 23U)) + RotL64(aCarry, 29U)) + 2584718176087499066U;
            aOrbiterH = ((aWandererJ + RotL64(aScatter, 3U)) + RotL64(aCarry, 51U)) + 14950366247822737997U;
            aOrbiterG = ((aWandererF + RotL64(aPrevious, 41U)) + 9779293225265670135U) + aNonceWordH;
            aOrbiterE = (aWandererC + RotL64(aCross, 37U)) + 8688968319288372383U;
            aOrbiterC = (aWandererB + RotL64(aScatter, 28U)) + 13665723186950342601U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 9395428688359973510U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterJ) ^ 2152719218018108418U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterI = RotL64((aOrbiterI * 15271961483518392671U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 1350324137411377992U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 8729317951386057921U;
            aOrbiterJ = RotL64((aOrbiterJ * 6008790836417785083U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 6317310451893678411U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 10175620379041384281U;
            aOrbiterB = RotL64((aOrbiterB * 14079679617394330781U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 1203082119358827708U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterK) ^ 523869107818193101U) ^ aOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterG = RotL64((aOrbiterG * 4629501113595689157U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 4028324959540432983U) + aNonceWordB;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 15447631947468213912U;
            aOrbiterF = RotL64((aOrbiterF * 6037306615787729185U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 14225888694733041031U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 11925000696281947629U;
            aOrbiterA = RotL64((aOrbiterA * 4337022940520411253U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 15015531024930608745U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 16752579225076943550U;
            aOrbiterD = RotL64((aOrbiterD * 15551083683579981439U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 2432733494869267901U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 10103430321388601485U) ^ aOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 18372919379972432569U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 15943360147468638325U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 9782703760233558733U;
            aOrbiterE = RotL64((aOrbiterE * 685056980418243879U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 18345087852012669037U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 8897505040792027675U;
            aOrbiterC = RotL64((aOrbiterC * 14333687539092412967U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 7402581293947129667U) + aNonceWordK;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 8604208734152026945U;
            aOrbiterK = RotL64((aOrbiterK * 9965525485538037673U), 35U);
            //
            aIngress = RotL64(aOrbiterF, 37U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 19U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 27U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 60U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 39U));
            aIngress = aIngress + RotL64(aOrbiterI, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aScatter, 51U) + aOrbiterD) + RotL64(aOrbiterH, 13U)) + aNonceWordI);
            aWandererG = aWandererG ^ ((RotL64(aCross, 14U) + RotL64(aOrbiterA, 21U)) + aOrbiterH);
            aWandererK = aWandererK + (((RotL64(aIngress, 47U) + aOrbiterH) + RotL64(aOrbiterF, 11U)) + RotL64(aCarry, 53U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 11U) + aOrbiterG) + RotL64(aOrbiterF, 50U)) + aWandererUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aCross, 43U) + RotL64(aOrbiterF, 53U)) + aOrbiterB);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 39U) + aOrbiterH) + RotL64(aOrbiterK, 47U)) + aNonceWordC);
            aWandererD = aWandererD + (((RotL64(aIngress, 19U) + RotL64(aOrbiterJ, 43U)) + aOrbiterH) + aNonceWordL);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterK, 41U)) + aOrbiterI);
            aWandererE = aWandererE + (((RotL64(aScatter, 6U) + aOrbiterJ) + RotL64(aOrbiterC, 58U)) + RotL64(aCarry, 37U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 3U) + aOrbiterJ) + RotL64(aOrbiterF, 39U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterE, 19U)) + aOrbiterH) + aWandererUpdateSaltF[((aIndex + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 42U) ^ aWandererJ);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 27U));
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererI, 57U) ^ aWandererF);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 5U));
            aCarry = aCarry + RotL64(aWandererK, 20U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 6889U)) & S_BLOCK1], 28U) ^ RotL64(mSource[((aIndex + 6937U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 9935U)) & S_BLOCK1], 36U) ^ RotL64(pSnow[((aIndex + 9828U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aIngress, 18U)) + (RotL64(aPrevious, 35U) + RotL64(aCross, 47U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterH = (aWandererG + RotL64(aScatter, 37U)) + 17081642665820489793U;
            aOrbiterB = (aWandererF + RotL64(aPrevious, 19U)) + 14468854040067229623U;
            aOrbiterK = ((aWandererJ + RotL64(aCross, 40U)) + RotL64(aCarry, 29U)) + 2249450222593057429U;
            aOrbiterF = (aWandererK + RotL64(aIngress, 35U)) + 14964389079511378664U;
            aOrbiterC = ((aWandererH + RotL64(aPrevious, 43U)) + RotL64(aCarry, 43U)) + 17003491054252360650U;
            aOrbiterI = (((aWandererB + RotL64(aScatter, 23U)) + RotL64(aCarry, 57U)) + 12710882240582032588U) + aNonceWordE;
            aOrbiterA = ((aWandererD + RotL64(aCross, 13U)) + 9887078182156755359U) + aOrbiterAssignSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterD = (((aWandererC + RotL64(aIngress, 11U)) + 7665284531810584704U) + aOrbiterAssignSaltB[((aIndex + 11U)) & S_SALT1]) + aNonceWordB;
            aOrbiterE = (aWandererI + RotL64(aScatter, 60U)) + 7304284015511876717U;
            aOrbiterG = ((aWandererA + RotL64(aCross, 53U)) + 5517927023543751734U) + aNonceWordO;
            aOrbiterJ = (aWandererE + RotL64(aPrevious, 29U)) + 17704756310857362759U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 11347400363019508578U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 11696395232760991243U;
            aOrbiterK = RotL64((aOrbiterK * 9725231749679442003U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 10875780291242873583U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 7808740614343437672U;
            aOrbiterI = RotL64((aOrbiterI * 8889516201913716283U), 11U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterA) + 3145390996141902032U) + aOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1]) + aNonceWordD;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 16080636485642732615U;
            aOrbiterF = RotL64((aOrbiterF * 7445756373012217305U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 3929263288176983844U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 18210228766683996806U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 13178080076505449091U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 13948962323541421431U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 3037683309790156893U;
            aOrbiterB = RotL64((aOrbiterB * 13406672352222636739U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 17827265198532699474U) + aNonceWordJ;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 7270895262023504864U;
            aOrbiterD = RotL64((aOrbiterD * 13467417362477308167U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 6431243064980879185U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 6680205390976259885U) ^ aNonceWordA;
            aOrbiterJ = RotL64((aOrbiterJ * 10421386694108590789U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 15910655919164357152U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 8046213498216027383U;
            aOrbiterH = RotL64((aOrbiterH * 18061867495824063553U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 2521111689480478597U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 13892876610454681741U;
            aOrbiterC = RotL64((aOrbiterC * 17776392934374483875U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 16009217514890880809U) + aNonceWordC;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 1221573458193626679U) ^ aOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 73477765605619369U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 9275704218554025797U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 17081642665820489793U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 5613316790159527375U), 3U);
            //
            aIngress = RotL64(aOrbiterG, 57U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 19U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 3U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 13U));
            aIngress = aIngress + (RotL64(aOrbiterB, 23U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterA, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterD, 21U)) + aOrbiterG);
            aWandererC = aWandererC + ((RotL64(aPrevious, 54U) + aOrbiterI) + RotL64(aOrbiterC, 3U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 41U) + RotL64(aOrbiterJ, 39U)) + aOrbiterD) + aNonceWordL);
            aWandererD = aWandererD + (((RotL64(aScatter, 29U) + RotL64(aOrbiterJ, 13U)) + aOrbiterA) + aNonceWordI);
            aWandererI = aWandererI ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterB, 41U)) + aOrbiterD);
            aWandererA = aWandererA + (((RotL64(aIngress, 20U) + RotL64(aOrbiterG, 10U)) + aOrbiterE) + RotL64(aCarry, 47U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 27U) + aOrbiterJ) + RotL64(aOrbiterH, 47U)) + aWandererUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aScatter, 11U) + RotL64(aOrbiterE, 53U)) + aOrbiterA);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 47U) + RotL64(aOrbiterA, 57U)) + aOrbiterK) + aWandererUpdateSaltD[((aIndex + 20U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 13U) + aOrbiterJ) + RotL64(aOrbiterF, 27U)) + RotL64(aCarry, 51U)) + aNonceWordM);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 3U) + aOrbiterA) + RotL64(aOrbiterI, 60U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 41U));
            aCarry = aCarry + (RotL64(aWandererD, 27U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererG, 53U) ^ aWandererH);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 44U));
            aCarry = aCarry + (RotL64(aWandererI, 23U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererK, 35U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = RotL64(aWorkLaneB[((aIndex + 15231U)) & S_BLOCK1], 34U) ^ RotL64(mSource[((aIndex + 16297U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(pSnow[((S_BLOCK1 - aIndex + 12831U)) & S_BLOCK1], 18U) ^ RotL64(aWorkLaneA[((aIndex + 10951U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aPrevious, 3U) ^ RotL64(aCarry, 54U)) + (RotL64(aCross, 21U) ^ RotL64(aIngress, 35U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterC = ((aWandererB + RotL64(aCross, 27U)) + RotL64(aCarry, 35U)) + 12131317914288566437U;
            aOrbiterH = (aWandererD + RotL64(aPrevious, 29U)) + 5672805657999385496U;
            aOrbiterF = ((aWandererJ + RotL64(aScatter, 51U)) + RotL64(aCarry, 19U)) + 3581710244233124197U;
            aOrbiterA = ((aWandererK + RotL64(aIngress, 36U)) + RotL64(aCarry, 3U)) + 15251296040538489436U;
            aOrbiterI = (aWandererF + RotL64(aCross, 3U)) + 11295008604679904153U;
            aOrbiterB = (((aWandererI + RotL64(aScatter, 43U)) + 2230897493419504490U) + aOrbiterAssignSaltA[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterG = (aWandererA + RotL64(aPrevious, 39U)) + 7109600123297458999U;
            aOrbiterK = (aWandererH + RotL64(aIngress, 10U)) + 13119156643107683803U;
            aOrbiterD = (aWandererC + RotL64(aScatter, 19U)) + 14755160867807355250U;
            aOrbiterJ = (aWandererE + RotL64(aPrevious, 21U)) + 16829363373287496832U;
            aOrbiterE = (((aWandererG + RotL64(aCross, 23U)) + 16981122946707720883U) + aOrbiterAssignSaltF[((aIndex + 22U)) & S_SALT1]) + aNonceWordP;
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 8806000776958603317U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 16810923047720876014U;
            aOrbiterF = RotL64((aOrbiterF * 17872735050219539145U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 8129657889554436328U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 8653100378491974463U;
            aOrbiterI = RotL64((aOrbiterI * 11395283153912468661U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 17048985838727432415U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 10892675550889823573U;
            aOrbiterK = RotL64((aOrbiterK * 976298937314081913U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 15960158965421254346U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 12290011578634850001U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 9280475585104357745U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 16265047040311479093U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 10312956912303656248U;
            aOrbiterG = RotL64((aOrbiterG * 3012584393253845131U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 16706890352221352779U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 10630955894218491929U;
            aOrbiterC = RotL64((aOrbiterC * 12675937483456206355U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 4009352551041162434U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterA) ^ 3043810773683888556U) ^ aOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterD = RotL64((aOrbiterD * 4328135390387997315U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 1398071019814944785U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 16689766557488135301U;
            aOrbiterH = RotL64((aOrbiterH * 8403881916549404871U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 15934647144489136524U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 13521276033614992223U;
            aOrbiterE = RotL64((aOrbiterE * 18003640895553609933U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 4281211055727414100U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 11848150507497406421U;
            aOrbiterA = RotL64((aOrbiterA * 1107789990317433481U), 41U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 12022829841608199449U) + aNonceWordF;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 12131317914288566437U;
            aOrbiterB = RotL64((aOrbiterB * 13275753083882829973U), 57U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterF, 46U);
            aIngress = aIngress + (RotL64(aOrbiterI, 13U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 41U));
            aIngress = aIngress + (RotL64(aOrbiterH, 51U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 53U));
            aIngress = aIngress + RotL64(aOrbiterG, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterI, 23U)) + aOrbiterF);
            aWandererD = aWandererD + ((((RotL64(aCross, 6U) + aOrbiterE) + RotL64(aOrbiterJ, 6U)) + RotL64(aCarry, 29U)) + aWandererUpdateSaltA[((aIndex + 11U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 41U) + RotL64(aOrbiterH, 37U)) + aOrbiterA) + aNonceWordE);
            aWandererE = aWandererE + (((RotL64(aIngress, 37U) + aOrbiterB) + RotL64(aOrbiterH, 41U)) + aNonceWordN);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterJ, 47U)) + aOrbiterF);
            aWandererG = aWandererG + ((((RotL64(aCross, 35U) + aOrbiterA) + RotL64(aOrbiterD, 57U)) + aNonceWordI) + aWandererUpdateSaltE[((aIndex + 14U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterK, 13U)) + aOrbiterC);
            aWandererB = aWandererB + ((RotL64(aIngress, 60U) + RotL64(aOrbiterD, 60U)) + aOrbiterK);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 23U) + aOrbiterE) + RotL64(aOrbiterA, 19U));
            aWandererA = aWandererA + (((RotL64(aIngress, 19U) + RotL64(aOrbiterB, 35U)) + aOrbiterG) + RotL64(aCarry, 13U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 43U) + aOrbiterI) + RotL64(aOrbiterE, 27U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 30U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererG, 23U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererJ, 53U) ^ aWandererE);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 51U));
            aCarry = aCarry + (RotL64(aWandererI, 12U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererH, 47U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 20783U)) & S_BLOCK1], 6U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18362U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 21429U)) & S_BLOCK1], 41U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 17605U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 18499U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aIngress, 21U) ^ RotL64(aCross, 57U)) + (RotL64(aPrevious, 40U) ^ RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterJ = (((aWandererD + RotL64(aIngress, 35U)) + RotL64(aCarry, 37U)) + 17454559218352016650U) + aNonceWordA;
            aOrbiterH = (aWandererH + RotL64(aCross, 57U)) + 8005709669325164803U;
            aOrbiterF = (aWandererE + RotL64(aPrevious, 13U)) + 13393741948412816357U;
            aOrbiterG = (aWandererF + RotL64(aScatter, 22U)) + 3665865624348875553U;
            aOrbiterB = ((aWandererJ + RotL64(aCross, 53U)) + RotL64(aCarry, 27U)) + 8334142570031883436U;
            aOrbiterE = ((aWandererC + RotL64(aPrevious, 3U)) + 17226066128706139657U) + aOrbiterAssignSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = ((aWandererB + RotL64(aIngress, 19U)) + 3319093033121522613U) + aNonceWordB;
            aOrbiterI = ((aWandererK + RotL64(aScatter, 26U)) + RotL64(aCarry, 57U)) + 6657535603401588798U;
            aOrbiterC = (((aWandererI + RotL64(aIngress, 51U)) + 5469746182326331147U) + aOrbiterAssignSaltD[((aIndex + 11U)) & S_SALT1]) + aNonceWordN;
            aOrbiterA = (aWandererG + RotL64(aScatter, 37U)) + 17846791786050221418U;
            aOrbiterK = (aWandererA + RotL64(aPrevious, 39U)) + 15939541003714896288U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 12076763190461077406U) + aNonceWordF;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 3594038213596405284U) ^ aOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10244002692575821495U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 8301291631324464622U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 8460406137668390582U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 9117147929757711595U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 7612394867020871200U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 8525076134853103975U;
            aOrbiterD = RotL64((aOrbiterD * 5790440201072204659U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 11929899088215090379U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 7119509166360685726U;
            aOrbiterC = RotL64((aOrbiterC * 1662341427992528823U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 5081078459225240607U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 17149991983909906705U;
            aOrbiterA = RotL64((aOrbiterA * 950223374568067343U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 8817303295675241994U) + aOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 7962039282652745113U;
            aOrbiterG = RotL64((aOrbiterG * 12773588587795522121U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 13596273086338032370U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 8186297702278180956U) ^ aNonceWordH;
            aOrbiterB = RotL64((aOrbiterB * 6226504769888753861U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 1696277861691580263U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 17360461831507082959U;
            aOrbiterK = RotL64((aOrbiterK * 1651378456022210983U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 1384868996572650981U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 2039624849777183290U;
            aOrbiterI = RotL64((aOrbiterI * 13148024378138271937U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 14530407348595669913U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 18023931565754525034U;
            aOrbiterH = RotL64((aOrbiterH * 18025122652259338105U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 11245556671533878373U) + aOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 17454559218352016650U;
            aOrbiterE = RotL64((aOrbiterE * 15665798947106818229U), 39U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterF, 19U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 5U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 13U));
            aIngress = aIngress + (RotL64(aOrbiterH, 47U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 26U));
            aIngress = aIngress + RotL64(aOrbiterI, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aCross, 60U) + aOrbiterD) + RotL64(aOrbiterI, 11U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 57U) + aOrbiterK) + RotL64(aOrbiterI, 35U)) + aWandererUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 41U) + aOrbiterK) + RotL64(aOrbiterG, 24U)) + RotL64(aCarry, 21U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 51U) + aOrbiterG) + RotL64(aOrbiterH, 29U)) + aNonceWordJ);
            aWandererB = aWandererB + (((RotL64(aScatter, 13U) + RotL64(aOrbiterB, 3U)) + aOrbiterE) + aNonceWordC);
            aWandererA = aWandererA ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterB, 43U)) + aOrbiterI);
            aWandererK = aWandererK + (((RotL64(aPrevious, 39U) + aOrbiterG) + RotL64(aOrbiterC, 37U)) + aNonceWordK);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 53U) + aOrbiterF) + RotL64(aOrbiterD, 53U));
            aWandererC = aWandererC + (((RotL64(aCross, 21U) + aOrbiterJ) + RotL64(aOrbiterA, 50U)) + aNonceWordE);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 19U) + aOrbiterE) + RotL64(aOrbiterA, 27U)) + aWandererUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 24U) + aOrbiterJ) + RotL64(aOrbiterC, 5U)) + RotL64(aCarry, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 48U) ^ aWandererF);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 37U));
            aCarry = aCarry + (RotL64(aWandererB, 35U) ^ aWandererI);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 11U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 23U));
            aCarry = aCarry + RotL64(aWandererC, 18U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 23229U)) & S_BLOCK1], 47U) ^ RotL64(mSource[((aIndex + 22013U)) & S_BLOCK1], 20U));
            aIngress ^= (RotL64(pSnow[((aIndex + 23150U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneA[((aIndex + 26705U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 26277U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneB[((aIndex + 21882U)) & S_BLOCK1], 46U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCross, 54U) ^ RotL64(aPrevious, 19U)) + (RotL64(aCarry, 3U) + RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterE = ((aWandererB + RotL64(aScatter, 23U)) + 7790166497945719700U) + aNonceWordJ;
            aOrbiterC = (((aWandererA + RotL64(aCross, 38U)) + RotL64(aCarry, 53U)) + 7136208896846119188U) + aOrbiterAssignSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterB = ((aWandererK + RotL64(aIngress, 21U)) + 12123156943355100886U) + aNonceWordC;
            aOrbiterA = (((aWandererJ + RotL64(aPrevious, 29U)) + RotL64(aCarry, 23U)) + 5095546037880875199U) + aOrbiterAssignSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterG = ((aWandererI + RotL64(aIngress, 13U)) + RotL64(aCarry, 11U)) + 17642705393916765992U;
            aOrbiterJ = (aWandererC + RotL64(aScatter, 11U)) + 9918479837334416990U;
            aOrbiterH = ((aWandererF + RotL64(aCross, 44U)) + 4890009823843176466U) + aNonceWordB;
            aOrbiterI = ((aWandererE + RotL64(aPrevious, 41U)) + 17652590786213674124U) + aNonceWordP;
            aOrbiterK = (aWandererG + RotL64(aCross, 53U)) + 870002527644696135U;
            aOrbiterD = (aWandererD + RotL64(aIngress, 47U)) + 12545429703552643682U;
            aOrbiterF = (aWandererH + RotL64(aPrevious, 57U)) + 5310272867406182581U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 3264719049050179440U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 1967241238180278937U;
            aOrbiterB = RotL64((aOrbiterB * 13004319774269457957U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 773883832927040736U) + aOrbiterUpdateSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 12766817190261232485U;
            aOrbiterJ = RotL64((aOrbiterJ * 7448864556802318431U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 260069382395598265U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 15462103891287350123U;
            aOrbiterC = RotL64((aOrbiterC * 5029268763635635753U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 4072032867513289827U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 17153061419083897076U;
            aOrbiterD = RotL64((aOrbiterD * 11934532169271718913U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 6207264270332656966U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 18048064697837314947U;
            aOrbiterG = RotL64((aOrbiterG * 13632594619404208489U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 14484617445340272026U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterG) ^ 16160443600497652026U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterH = RotL64((aOrbiterH * 1988599349457831597U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 5873314228291583482U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 16418290052752166515U;
            aOrbiterA = RotL64((aOrbiterA * 18270363452003213317U), 23U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 9158414409987627714U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 8205937960146492168U;
            aOrbiterI = RotL64((aOrbiterI * 14008398661393344261U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 16386126219854809263U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 12418021156683187869U) ^ aNonceWordL;
            aOrbiterE = RotL64((aOrbiterE * 13897930566207284517U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 5427232681451476584U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 18237670074497382745U) ^ aNonceWordA;
            aOrbiterF = RotL64((aOrbiterF * 15528665160297906195U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 8330262458028468513U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 7790166497945719700U;
            aOrbiterK = RotL64((aOrbiterK * 6001280767763971107U), 39U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterA, 44U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 21U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 41U));
            aIngress = aIngress + (RotL64(aOrbiterC, 29U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 5U));
            aIngress = aIngress + RotL64(aOrbiterG, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aScatter, 27U) + aOrbiterA) + RotL64(aOrbiterE, 43U)) + aWandererUpdateSaltD[((aIndex + 3U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aCross, 48U) + aOrbiterE) + RotL64(aOrbiterJ, 39U)) + RotL64(aCarry, 39U)) + aNonceWordI);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterD, 57U)) + aOrbiterC) + aNonceWordM);
            aWandererK = aWandererK + ((RotL64(aIngress, 21U) + RotL64(aOrbiterH, 30U)) + aOrbiterG);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 53U) + aOrbiterK) + RotL64(aOrbiterJ, 27U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 37U) + aOrbiterK) + RotL64(aOrbiterH, 13U)) + aNonceWordO);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 19U) + RotL64(aOrbiterG, 3U)) + aOrbiterA) + aWandererUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aIngress, 57U) + RotL64(aOrbiterB, 51U)) + aOrbiterG) + RotL64(aCarry, 27U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterE, 5U)) + aOrbiterF);
            aWandererG = aWandererG + ((RotL64(aIngress, 40U) + RotL64(aOrbiterC, 19U)) + aOrbiterJ);
            aWandererH = aWandererH ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterI, 34U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererI, 52U) ^ aWandererE);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 13U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 3U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 21U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 50U));
            aCarry = aCarry + RotL64(aWandererJ, 5U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 29559U)) & S_BLOCK1], 41U) ^ RotL64(pSnow[((aIndex + 28237U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 28867U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 28286U)) & S_BLOCK1], 37U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 32143U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 27899U)) & S_BLOCK1], 50U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aIngress, 50U) ^ RotL64(aCarry, 23U)) ^ (RotL64(aCross, 3U) + RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterF = (aWandererI + RotL64(aPrevious, 41U)) + 898812731947995389U;
            aOrbiterE = (aWandererE + RotL64(aCross, 21U)) + 8677347622525527167U;
            aOrbiterH = (((aWandererB + RotL64(aIngress, 39U)) + RotL64(aCarry, 39U)) + 770321564027567654U) + aOrbiterAssignSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = (((aWandererK + RotL64(aScatter, 35U)) + RotL64(aCarry, 53U)) + 11020474858081526395U) + aNonceWordG;
            aOrbiterB = ((aWandererJ + RotL64(aPrevious, 60U)) + 17289793580414993470U) + aNonceWordP;
            aOrbiterI = (aWandererH + RotL64(aIngress, 53U)) + 10111912559295118444U;
            aOrbiterK = (((aWandererG + RotL64(aCross, 3U)) + RotL64(aCarry, 27U)) + 8083622125544542011U) + aNonceWordJ;
            aOrbiterJ = (aWandererA + RotL64(aScatter, 37U)) + 7149858558922988240U;
            aOrbiterA = (aWandererC + RotL64(aCross, 58U)) + 5919683821379905699U;
            aOrbiterG = (((aWandererF + RotL64(aPrevious, 47U)) + 6860902846079238714U) + aOrbiterAssignSaltF[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordL;
            aOrbiterC = (aWandererD + RotL64(aIngress, 23U)) + 15083517836867542075U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 14852868368708376381U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 9860233289028878323U;
            aOrbiterH = RotL64((aOrbiterH * 13418143547952204667U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 772406119079116272U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 7971141501337627589U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10168120622976358617U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 8478568022896691911U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 4027604850785607101U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 4826627523578901467U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 17199331557841535430U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 7515957656979776361U;
            aOrbiterJ = RotL64((aOrbiterJ * 5468950152869656599U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 17138249294921502391U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 16236812863923234668U;
            aOrbiterE = RotL64((aOrbiterE * 2925542836624164807U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 16941524155859123682U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 11240343728857342866U;
            aOrbiterF = RotL64((aOrbiterF * 7281012444214294659U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 15163914964139858328U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 6673576554415729652U) ^ aNonceWordD;
            aOrbiterK = RotL64((aOrbiterK * 1558880328574736975U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 5399050402101642989U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 11806006719060024615U) ^ aNonceWordE;
            aOrbiterA = RotL64((aOrbiterA * 15782156615926092159U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 9812148913932011655U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 4737919734590584193U) ^ aOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2739737604370936959U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 3415477403346468057U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 5922725868927615919U;
            aOrbiterC = RotL64((aOrbiterC * 12390148483052777871U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 17435294951520465659U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 898812731947995389U;
            aOrbiterG = RotL64((aOrbiterG * 17248379279729365007U), 23U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterA, 3U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 10U));
            aIngress = aIngress + (RotL64(aOrbiterC, 53U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterH, 29U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 43U));
            aIngress = aIngress + RotL64(aOrbiterG, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aPrevious, 44U) + RotL64(aOrbiterI, 35U)) + aOrbiterC);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterF, 47U)) + aOrbiterD);
            aWandererD = aWandererD + ((RotL64(aCross, 5U) + RotL64(aOrbiterI, 21U)) + aOrbiterB);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 39U) + aOrbiterC) + RotL64(aOrbiterH, 41U));
            aWandererA = aWandererA + (((RotL64(aScatter, 41U) + RotL64(aOrbiterC, 10U)) + aOrbiterB) + RotL64(aCarry, 47U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 57U) + aOrbiterC) + RotL64(aOrbiterG, 27U)) + aWandererUpdateSaltE[((aIndex + 25U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aIngress, 11U) + aOrbiterA) + RotL64(aOrbiterJ, 39U)) + aNonceWordN);
            aWandererC = aWandererC ^ (((RotL64(aCross, 51U) + RotL64(aOrbiterC, 29U)) + aOrbiterF) + aWandererUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 26U) + RotL64(aOrbiterK, 51U)) + aOrbiterG) + aNonceWordI);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterE, 56U)) + aOrbiterA);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 23U) + aOrbiterA) + RotL64(aOrbiterH, 19U)) + RotL64(aCarry, 29U)) + aNonceWordM);
            //
            aCarry = aCarry + (RotL64(aWandererA, 53U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererB, 48U) ^ aWandererE);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 39U));
            aCarry = aCarry + (RotL64(aWandererC, 5U) ^ aWandererD);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 41U));
            aCarry = aCarry + RotL64(aWandererF, 23U);
            aCarry = aCarry + RotL64(aIngress, 30U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xAFA51130E5370D67ULL + 0xFC21B1B97F228FC2ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xC6170BB436054575ULL + 0xF9618B3EA2A74B6AULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x9F9781899FD99C89ULL + 0xD12724216F1D57A8ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xA0D8B96BB45641ADULL + 0xC03A43BEEAB5FB70ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xB928904BB1A9AF49ULL + 0xB1FC38C2C8EE2CBDULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xDDB600A260BABA37ULL + 0xD16F4B2BCB201A1AULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xCA1E1293D91B011DULL + 0xDF18750066A31A4CULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xF055EC2924808F71ULL + 0xF7D9A3F1B0DCA930ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xFBD1DBAD50C20E69ULL + 0x87970B7BD385621FULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xCC8E319113D3A287ULL + 0xE5FEB4F757483B82ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xFAF27670B34CFF5DULL + 0xDC87F594AD6D9430ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xA979B465A9F1CE2DULL + 0xC4F52FCD809B6F3FULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xDF1C8B3A7C959647ULL + 0xDE9B3744D9576B42ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xD5BC4EF6F065FEFDULL + 0x861A3B93A4EB8D7FULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xDF19D9978E99CE43ULL + 0xAA657EA6CF7FB7E5ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xCFBE586FD58B9923ULL + 0xE56C8C1685A86F66ULL);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 3090U)) & S_BLOCK1], 39U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 1360U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 8124U)) & S_BLOCK1], 43U) ^ RotL64(aFireLaneD[((aIndex + 844U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCarry, 6U) ^ RotL64(aIngress, 51U)) + (RotL64(aPrevious, 19U) ^ RotL64(aCross, 37U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterK = ((aWandererD + RotL64(aScatter, 29U)) + 4622023259121087483U) + aNonceWordA;
            aOrbiterA = ((aWandererC + RotL64(aPrevious, 19U)) + RotL64(aCarry, 3U)) + 10253505250223501352U;
            aOrbiterJ = (aWandererH + RotL64(aIngress, 56U)) + 17133877904420462669U;
            aOrbiterE = (((aWandererE + RotL64(aCross, 43U)) + RotL64(aCarry, 11U)) + 6162827793741796700U) + aNonceWordI;
            aOrbiterI = ((aWandererI + RotL64(aPrevious, 3U)) + 9610986424765907615U) + aOrbiterAssignSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterD = (aWandererF + RotL64(aCross, 39U)) + 11210747154264753754U;
            aOrbiterH = ((aWandererK + RotL64(aIngress, 51U)) + 16554205219580654546U) + aOrbiterAssignSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterF = (((aWandererG + RotL64(aScatter, 23U)) + RotL64(aCarry, 35U)) + 10352576357413766388U) + aNonceWordL;
            aOrbiterC = (aWandererB + RotL64(aIngress, 60U)) + 3651845783283479752U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 18145542190463500476U) + aOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 5415609566767162857U;
            aOrbiterJ = RotL64((aOrbiterJ * 6474184559323816389U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 2033734872464201570U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 3507213117125813345U;
            aOrbiterA = RotL64((aOrbiterA * 5453058336688881113U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 8716253393049851856U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 695984869565941856U;
            aOrbiterH = RotL64((aOrbiterH * 8377921610764044735U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 7661578828878284931U) + aOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 906654265099155956U) ^ aNonceWordO;
            aOrbiterE = RotL64((aOrbiterE * 8117625377607536949U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 6050049984731254612U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 17882717590338190821U;
            aOrbiterI = RotL64((aOrbiterI * 10807367411402733215U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 4996521991532815957U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 4246460672800604436U;
            aOrbiterF = RotL64((aOrbiterF * 12047466401960824903U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 8700148116452518842U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 10039050281847466206U;
            aOrbiterD = RotL64((aOrbiterD * 11884791271239660157U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 4513844680425845372U) + aNonceWordP;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 3037563127442815153U;
            aOrbiterC = RotL64((aOrbiterC * 18363509277992292407U), 43U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 1005237931570968724U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterK = (((aOrbiterK ^ aOrbiterD) ^ 1373258132025712065U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterK = RotL64((aOrbiterK * 10458020799382532395U), 13U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterF, 43U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 57U));
            aIngress = aIngress + (RotL64(aOrbiterH, 6U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 29U));
            aIngress = aIngress + RotL64(aOrbiterC, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aPrevious, 28U) + RotL64(aOrbiterK, 57U)) + aOrbiterD) + RotL64(aCarry, 11U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterD, 27U)) + aOrbiterF);
            aWandererB = aWandererB + ((((RotL64(aIngress, 57U) + aOrbiterJ) + RotL64(aOrbiterF, 53U)) + RotL64(aCarry, 51U)) + aNonceWordC);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 53U) + aOrbiterH) + RotL64(aOrbiterE, 18U)) + aNonceWordB);
            aWandererH = aWandererH + ((RotL64(aPrevious, 11U) + aOrbiterJ) + RotL64(aOrbiterC, 47U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterD, 39U)) + aOrbiterI);
            aWandererD = aWandererD + (((RotL64(aCross, 42U) + RotL64(aOrbiterA, 43U)) + aOrbiterD) + aNonceWordH);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterE, 10U)) + aOrbiterD) + aWandererUpdateSaltF[((aIndex + 25U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aCross, 5U) + aOrbiterI) + RotL64(aOrbiterF, 23U)) + aNonceWordK) + aWandererUpdateSaltB[((aIndex + 16U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 28U));
            aCarry = aCarry + (RotL64(aWandererE, 35U) ^ aWandererH);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 39U));
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererG, 60U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 10463U)) & S_BLOCK1], 51U) ^ RotL64(aFireLaneB[((aIndex + 12850U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 15049U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 13707U)) & S_BLOCK1], 30U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 10324U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCarry, 27U) + RotL64(aIngress, 56U)) ^ (RotL64(aCross, 43U) + RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterH = (aWandererE + RotL64(aPrevious, 57U)) + 13915875634607599122U;
            aOrbiterJ = ((aWandererC + RotL64(aScatter, 5U)) + 1695770381382411673U) + aNonceWordE;
            aOrbiterK = (((aWandererD + RotL64(aCross, 52U)) + RotL64(aCarry, 51U)) + 3709105579778295511U) + aOrbiterAssignSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = ((aWandererH + RotL64(aIngress, 37U)) + RotL64(aCarry, 35U)) + 7673376335333251804U;
            aOrbiterB = (aWandererB + RotL64(aScatter, 11U)) + 8814147709738503518U;
            aOrbiterG = (((aWandererG + RotL64(aCross, 41U)) + 13451412605350381172U) + aOrbiterAssignSaltA[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordC;
            aOrbiterE = ((aWandererK + RotL64(aPrevious, 29U)) + RotL64(aCarry, 11U)) + 6447870234069609538U;
            aOrbiterA = (aWandererI + RotL64(aIngress, 47U)) + 13419487997946496825U;
            aOrbiterC = (aWandererA + RotL64(aScatter, 24U)) + 5478309847615220345U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 3635184969215610049U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 12527903812035294828U;
            aOrbiterK = RotL64((aOrbiterK * 12540800512035534967U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 1684685110885338814U) + aNonceWordI;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 12860354576326835090U;
            aOrbiterJ = RotL64((aOrbiterJ * 12743745087733307255U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 9081823570147481835U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 14369321778210049109U) ^ aNonceWordB;
            aOrbiterE = RotL64((aOrbiterE * 17865953349448767035U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 11518132079084873250U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 11893535026126957389U) ^ aOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 15751374986135615095U), 23U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 7084079180579206226U) + aOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 2999676609847603277U;
            aOrbiterG = RotL64((aOrbiterG * 14602698397511266403U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 17683445810614029153U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 11576460512964896969U;
            aOrbiterA = RotL64((aOrbiterA * 5243651036457051155U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 13429800604736567949U) + aNonceWordP;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 14661785761747367546U;
            aOrbiterC = RotL64((aOrbiterC * 4765843989277333421U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 12837164345582888950U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 6222666313184669392U) ^ aOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 17402483466567712319U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 5358647039491079457U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 12459911673401497180U;
            aOrbiterD = RotL64((aOrbiterD * 13605465035256188065U), 53U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterB, 34U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 47U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 23U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 5U));
            aIngress = aIngress + RotL64(aOrbiterE, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aPrevious, 47U) + aOrbiterH) + RotL64(aOrbiterB, 58U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 35U) + aOrbiterD) + RotL64(aOrbiterB, 47U));
            aWandererD = aWandererD + ((((RotL64(aCross, 42U) + RotL64(aOrbiterB, 41U)) + aOrbiterE) + RotL64(aCarry, 5U)) + aNonceWordG);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterJ, 51U)) + aOrbiterE);
            aWandererA = aWandererA + ((RotL64(aIngress, 19U) + aOrbiterC) + RotL64(aOrbiterD, 5U));
            aWandererE = aWandererE ^ ((((RotL64(aPrevious, 5U) + aOrbiterE) + RotL64(aOrbiterK, 14U)) + aNonceWordH) + aWandererUpdateSaltC[((aIndex + 6U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 60U) + RotL64(aOrbiterD, 19U)) + aOrbiterA) + aWandererUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aCross, 23U) + RotL64(aOrbiterD, 35U)) + aOrbiterK) + aNonceWordA);
            aWandererI = aWandererI + (((RotL64(aIngress, 29U) + aOrbiterA) + RotL64(aOrbiterG, 23U)) + RotL64(aCarry, 43U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 5U) ^ aWandererA);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 29U));
            aCarry = aCarry + (RotL64(aWandererK, 60U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererC, 53U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererH, 23U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 20847U)) & S_BLOCK1], 57U) ^ RotL64(aFireLaneD[((aIndex + 21885U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 18442U)) & S_BLOCK1], 46U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 24517U)) & S_BLOCK1], 43U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 22825U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aFireLaneC[((aIndex + 22567U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aPrevious, 29U) ^ RotL64(aCross, 11U)) + (RotL64(aCarry, 60U) ^ RotL64(aIngress, 41U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterK = ((aWandererA + RotL64(aPrevious, 21U)) + RotL64(aCarry, 13U)) + 15652862298542575895U;
            aOrbiterG = ((aWandererB + RotL64(aIngress, 54U)) + RotL64(aCarry, 37U)) + 16925323928418184554U;
            aOrbiterC = ((aWandererC + RotL64(aCross, 43U)) + RotL64(aCarry, 57U)) + 4413861484961668394U;
            aOrbiterB = (((aWandererG + RotL64(aScatter, 35U)) + 2215946422098155969U) + aOrbiterAssignSaltC[((aIndex + 3U)) & S_SALT1]) + aNonceWordL;
            aOrbiterJ = ((aWandererI + RotL64(aPrevious, 11U)) + 14975185533513111110U) + aNonceWordH;
            aOrbiterD = (aWandererE + RotL64(aCross, 47U)) + 9711613814905834552U;
            aOrbiterH = ((aWandererK + RotL64(aScatter, 58U)) + 13154957291850149471U) + aNonceWordO;
            aOrbiterF = (aWandererF + RotL64(aIngress, 27U)) + 5058313016418534840U;
            aOrbiterE = (((aWandererJ + RotL64(aPrevious, 3U)) + 15011423472941211620U) + aOrbiterAssignSaltE[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordG;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 2030053257469580168U) + aNonceWordJ;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 150530795186791193U;
            aOrbiterC = RotL64((aOrbiterC * 11106050063717096073U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 10878237472104183427U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 11724672539469573109U;
            aOrbiterG = RotL64((aOrbiterG * 16158741837357985395U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 9589700906445846956U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 1367381624958248949U;
            aOrbiterH = RotL64((aOrbiterH * 8459515089081211977U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 12003215666757518106U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 11232479330848006729U;
            aOrbiterD = RotL64((aOrbiterD * 10993290955464593033U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 13013910456628561621U) + aOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 6092509838924105265U;
            aOrbiterE = RotL64((aOrbiterE * 805601154718006061U), 39U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 11999225836250312801U) + aNonceWordN;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 14421271973875748413U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9529010940887430157U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 15536288285741825272U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 2071793889925436679U;
            aOrbiterK = RotL64((aOrbiterK * 1526376970151714589U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 5622386476463436967U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 16147972771639168516U) ^ aNonceWordE;
            aOrbiterF = RotL64((aOrbiterF * 11826916832825159095U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 4519892856053952290U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 12059500374938843538U) ^ aOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 14987533625537956299U), 43U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterF, 57U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 24U));
            aIngress = aIngress + (RotL64(aOrbiterH, 47U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 29U));
            aIngress = aIngress + RotL64(aOrbiterG, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aCross, 43U) + RotL64(aOrbiterE, 10U)) + aOrbiterC) + aWandererUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aPrevious, 3U) + aOrbiterF) + RotL64(aOrbiterD, 19U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 36U) + aOrbiterK) + RotL64(aOrbiterB, 3U)) + aNonceWordK);
            aWandererK = aWandererK + ((((RotL64(aIngress, 51U) + RotL64(aOrbiterF, 41U)) + aOrbiterJ) + aNonceWordM) + aWandererUpdateSaltA[((aIndex + 24U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterH, 35U)) + aOrbiterB);
            aWandererG = aWandererG + (((RotL64(aIngress, 23U) + aOrbiterH) + RotL64(aOrbiterC, 58U)) + RotL64(aCarry, 57U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 12U) + aOrbiterD) + RotL64(aOrbiterE, 51U)) + aNonceWordD);
            aWandererF = aWandererF + (((RotL64(aScatter, 27U) + RotL64(aOrbiterB, 29U)) + aOrbiterE) + RotL64(aCarry, 43U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterG, 23U)) + aOrbiterH) + aNonceWordF);
            //
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererK);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 27U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 10U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 43U));
            aCarry = aCarry + RotL64(aWandererI, 13U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 24648U)) & S_BLOCK1], 60U) ^ RotL64(aFireLaneC[((aIndex + 31425U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aOperationLaneA[((aIndex + 28132U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 29154U)) & S_BLOCK1], 57U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 32344U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 28199U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aPrevious, 4U) + RotL64(aCarry, 51U)) ^ (RotL64(aIngress, 23U) + RotL64(aCross, 37U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterH = (((aWandererA + RotL64(aPrevious, 18U)) + RotL64(aCarry, 57U)) + 11450949896247900941U) + aNonceWordI;
            aOrbiterD = (aWandererI + RotL64(aCross, 57U)) + 3905542253538116335U;
            aOrbiterC = ((aWandererE + RotL64(aScatter, 13U)) + 9529740545977785305U) + aNonceWordP;
            aOrbiterK = (aWandererB + RotL64(aIngress, 35U)) + 1856876631533143492U;
            aOrbiterJ = (aWandererH + RotL64(aPrevious, 3U)) + 84253466320181686U;
            aOrbiterG = ((aWandererC + RotL64(aCross, 23U)) + RotL64(aCarry, 29U)) + 12577480918745432444U;
            aOrbiterI = (aWandererG + RotL64(aIngress, 51U)) + 5625703170397704029U;
            aOrbiterB = (((aWandererJ + RotL64(aScatter, 28U)) + RotL64(aCarry, 19U)) + 694608607323629282U) + aOrbiterAssignSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = ((aWandererK + RotL64(aPrevious, 43U)) + 3993981243536262204U) + aOrbiterAssignSaltF[((aIndex + 18U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 4119215953484892051U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 8785040118556157146U) ^ aOrbiterUpdateSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 17113521266125471625U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 16234403619456882890U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 10398727475672860610U) ^ aOrbiterUpdateSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 5086871400049644715U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 18327987141759096769U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 2645964788056875452U;
            aOrbiterG = RotL64((aOrbiterG * 8778681366114628045U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 2859452497983106129U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterI) ^ 7196557924940881076U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterK = RotL64((aOrbiterK * 14415389907490256711U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 930127943984174668U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 15673596916054795749U;
            aOrbiterI = RotL64((aOrbiterI * 7505660488733199479U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 16673140529110941163U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 2258448294877833760U;
            aOrbiterB = RotL64((aOrbiterB * 1821550319748977445U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 6870209259643931219U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 12749790107942194104U;
            aOrbiterA = RotL64((aOrbiterA * 4871407285968611725U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 17131374134617173866U) + aNonceWordO;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 6426448390733751612U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 12490559588384058417U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 15592826434339731146U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 14182944418026376183U;
            aOrbiterH = RotL64((aOrbiterH * 7218860482893476233U), 43U);
            //
            aIngress = RotL64(aOrbiterK, 51U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 47U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 26U));
            aIngress = aIngress + (RotL64(aOrbiterG, 57U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterJ, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aCross, 54U) + aOrbiterA) + RotL64(aOrbiterK, 37U)) + aWandererUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aScatter, 23U) + RotL64(aOrbiterB, 6U)) + aOrbiterC);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 3U) + aOrbiterH) + RotL64(aOrbiterD, 23U)) + aNonceWordA);
            aWandererI = aWandererI + (((RotL64(aPrevious, 19U) + aOrbiterI) + RotL64(aOrbiterK, 11U)) + RotL64(aCarry, 23U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 11U) + aOrbiterJ) + RotL64(aOrbiterG, 19U)) + aNonceWordD);
            aWandererG = aWandererG + ((((RotL64(aScatter, 43U) + aOrbiterD) + RotL64(aOrbiterK, 60U)) + RotL64(aCarry, 53U)) + aNonceWordC);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 58U) + RotL64(aOrbiterB, 43U)) + aOrbiterK);
            aWandererC = aWandererC + ((RotL64(aCross, 27U) + RotL64(aOrbiterH, 51U)) + aOrbiterJ);
            aWandererE = aWandererE ^ ((((RotL64(aPrevious, 35U) + RotL64(aOrbiterH, 29U)) + aOrbiterB) + aNonceWordK) + aWandererUpdateSaltF[((aIndex + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 37U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 3U));
            aCarry = aCarry + (RotL64(aWandererC, 23U) ^ aWandererB);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 19U));
            aCarry = aCarry + RotL64(aWandererG, 34U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
    [[maybe_unused]] std::uint8_t *aFireLaneA = pWorkSpace->mFireLaneA;
    [[maybe_unused]] std::uint8_t *aFireLaneB = pWorkSpace->mFireLaneB;
    [[maybe_unused]] std::uint8_t *aFireLaneC = pWorkSpace->mFireLaneC;
    [[maybe_unused]] std::uint8_t *aFireLaneD = pWorkSpace->mFireLaneD;
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xB8A56E550D66FC55ULL + 0x86202E63A83B212EULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xCF8E7B11493EFC53ULL + 0x887DCE45E8CDC1D5ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xBC365BCC90324091ULL + 0xEE1BBDBDD9F9B89DULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xD9C4E09027E72A1BULL + 0xE15EA0A72775BD1DULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xD48857F6B529053BULL + 0xEA7270ED62CF0D51ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xEC1AA1D8F9416AA1ULL + 0x91B8493AD5DA64A4ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xD6009A095A9997A5ULL + 0xA058D4754EA59C78ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xDCC88F2FC96549E5ULL + 0xCBCB8A46A6AAEA2EULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xB39153A3F09E00A7ULL + 0xE5CF833860139AC5ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xCC252E481C2ED3DBULL + 0xC18C7E2876B3E69FULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x99B319CDA17D881DULL + 0x8019C19A5DBD22C0ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xD323EACAE923A6E1ULL + 0x8B31DC9B63691E08ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x8BA08F9E6078FB23ULL + 0xBF023C1F39F82AFAULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xE435057A2C0F65D1ULL + 0x838F7A94ABB170EBULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x9E8B6698776C40E3ULL + 0x9311900F283A4EE3ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xE2372E2607CDA9C1ULL + 0x815BBEC40A883B87ULL);
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
        // read from: aOperationLaneA, aOperationLaneB, aFireLaneA, aOperationLaneC, aOperationLaneD, aWorkLaneA, aFireLaneB, aWorkLaneB, aFireLaneD, aWorkLaneC, aFireLaneC
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 3315U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneB[((aIndex + 4598U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 5938U)) & S_BLOCK1], 14U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 2607U)) & S_BLOCK1], 6U) ^ RotL64(aOperationLaneD[((aIndex + 1322U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aIngress, 20U) + RotL64(aCross, 5U)) + (RotL64(aCarry, 43U) ^ RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterJ = (((aWandererC + RotL64(aCross, 27U)) + 1297415699043177788U) + aOrbiterAssignSaltB[((aIndex + 9U)) & S_SALT1]) + aNonceWordN;
            aOrbiterE = ((((aWandererJ + RotL64(aPrevious, 5U)) + RotL64(aCarry, 37U)) + 17583786534509260153U) + aOrbiterAssignSaltF[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordM;
            aOrbiterC = (((aWandererB + RotL64(aIngress, 60U)) + RotL64(aCarry, 51U)) + 643197858925708798U) + aNonceWordA;
            aOrbiterB = ((aWandererH + RotL64(aScatter, 13U)) + RotL64(aCarry, 3U)) + 5062653766915694874U;
            aOrbiterI = (aWandererF + RotL64(aCross, 35U)) + 7034273638367180511U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 2026909726972916996U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 2785690475553211646U;
            aOrbiterC = RotL64((aOrbiterC * 6612792037861160393U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 2910341716302991892U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 2834181605200829791U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 1510617068750957651U), 39U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterC) + 13323052600571281928U) + aOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1]) + aNonceWordF;
            aOrbiterI = (((aOrbiterI ^ aOrbiterE) ^ 10434901530315760460U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterI = RotL64((aOrbiterI * 2042210188346767033U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 247903955625194782U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 5196515747387257163U;
            aOrbiterJ = RotL64((aOrbiterJ * 1799024689023272275U), 21U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 7196305682377987476U) + aOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 14777739876892587484U;
            aOrbiterB = RotL64((aOrbiterB * 95220583948241581U), 13U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterB, 3U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 13U));
            aIngress = aIngress + RotL64(aOrbiterJ, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterC, 39U)) + aOrbiterJ);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 24U) + RotL64(aOrbiterB, 54U)) + aOrbiterC) + RotL64(aCarry, 51U)) + aWandererUpdateSaltD[((aIndex + 29U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((((RotL64(aCross, 13U) + aOrbiterC) + RotL64(aOrbiterE, 5U)) + aNonceWordL) + aWandererUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aScatter, 43U) + aOrbiterB) + RotL64(aOrbiterE, 19U)) + RotL64(aCarry, 13U)) + aNonceWordK);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterE, 29U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 5U));
            aCarry = aCarry + (RotL64(aWandererJ, 13U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererC, 21U);
            aCarry = aCarry + RotL64(aIngress, 58U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 13564U)) & S_BLOCK1], 18U) ^ RotL64(aOperationLaneC[((aIndex + 8964U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 13278U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 13096U)) & S_BLOCK1], 48U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 13552U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 11926U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCross, 56U) + RotL64(aPrevious, 21U)) ^ (RotL64(aIngress, 41U) + RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterD = (((aWandererD + RotL64(aCross, 3U)) + RotL64(aCarry, 5U)) + 6467297102954816305U) + aNonceWordG;
            aOrbiterF = ((aWandererF + RotL64(aPrevious, 29U)) + 7921154109831114952U) + aNonceWordA;
            aOrbiterB = (((aWandererH + RotL64(aScatter, 41U)) + 5701131763215638919U) + aOrbiterAssignSaltE[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordD;
            aOrbiterI = (((aWandererJ + RotL64(aIngress, 19U)) + RotL64(aCarry, 27U)) + 10022999076719002684U) + aOrbiterAssignSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = (((aWandererG + RotL64(aScatter, 52U)) + RotL64(aCarry, 47U)) + 4367135243038982316U) + aNonceWordP;
            //
            aOrbiterD = (((aOrbiterD + aOrbiterF) + 14445846824810383592U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordH;
            aOrbiterB = (((aOrbiterB ^ aOrbiterD) ^ 7683697954545773253U) ^ aOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterB = RotL64((aOrbiterB * 4832124801510084629U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 17517006750428030899U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 2052484792684025476U;
            aOrbiterD = RotL64((aOrbiterD * 12463117571122469643U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 6279463052085808926U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 679280153651813684U;
            aOrbiterF = RotL64((aOrbiterF * 3047031560593583881U), 41U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterD) + 2939516520188460569U) + aOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1]) + aNonceWordL;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 1960616434964712325U;
            aOrbiterI = RotL64((aOrbiterI * 15145998415466343039U), 11U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterI) + 12273819390719947361U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordI;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 5685033154709449397U;
            aOrbiterA = RotL64((aOrbiterA * 9845666295874714959U), 19U);
            //
            aIngress = RotL64(aOrbiterI, 28U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 3U));
            aIngress = aIngress + RotL64(aOrbiterB, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aScatter, 11U) + aOrbiterA) + RotL64(aOrbiterB, 57U)) + RotL64(aCarry, 19U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 26U) + RotL64(aOrbiterB, 13U)) + aOrbiterI) + aNonceWordB);
            aWandererF = aWandererF + ((((RotL64(aIngress, 35U) + RotL64(aOrbiterD, 37U)) + aOrbiterI) + aNonceWordE) + aWandererUpdateSaltF[((aIndex + 19U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterA, 3U)) + aOrbiterD);
            aWandererH = aWandererH + ((((RotL64(aIngress, 51U) + RotL64(aOrbiterD, 26U)) + aOrbiterF) + RotL64(aCarry, 47U)) + aWandererUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 47U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 10U));
            aCarry = aCarry + RotL64(aWandererJ, 21U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 17614U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneD[((aIndex + 17860U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 22827U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19521U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 23302U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 16434U)) & S_BLOCK1], 4U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCarry, 39U) + RotL64(aPrevious, 57U)) + (RotL64(aCross, 13U) ^ RotL64(aIngress, 26U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterF = ((aWandererD + RotL64(aScatter, 41U)) + 15036852811491820366U) + aOrbiterAssignSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterH = ((aWandererE + RotL64(aIngress, 26U)) + 305637140752898475U) + aNonceWordD;
            aOrbiterI = ((aWandererJ + RotL64(aCross, 13U)) + RotL64(aCarry, 37U)) + 11948631574496129610U;
            aOrbiterG = (((aWandererA + RotL64(aPrevious, 3U)) + RotL64(aCarry, 57U)) + 5321623592482991426U) + aNonceWordJ;
            aOrbiterA = (((aWandererC + RotL64(aScatter, 51U)) + RotL64(aCarry, 23U)) + 4075270159062690728U) + aOrbiterAssignSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 15111580500356908928U) + aOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 7244150695504160363U;
            aOrbiterI = RotL64((aOrbiterI * 2445733898697939969U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 5131563519577488862U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 5881954992088651371U) ^ aOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2424421828597294607U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 12780935808751507998U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 12599159643925470226U;
            aOrbiterF = RotL64((aOrbiterF * 17690046932587062701U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 9466589929741834066U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 6093158735705189789U;
            aOrbiterG = RotL64((aOrbiterG * 7453778295800853653U), 43U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterF) + 17461243886150519249U) + aOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1]) + aNonceWordB;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 15456408913739900718U) ^ aNonceWordO;
            aOrbiterH = RotL64((aOrbiterH * 16093292401746174671U), 53U);
            //
            aIngress = RotL64(aOrbiterG, 57U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterI, 3U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterH, 38U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aCross, 57U) + aOrbiterH) + RotL64(aOrbiterF, 47U)) + RotL64(aCarry, 21U)) + aNonceWordN);
            aWandererD = aWandererD ^ ((((RotL64(aPrevious, 39U) + aOrbiterA) + RotL64(aOrbiterF, 35U)) + aNonceWordP) + aWandererUpdateSaltA[((aIndex + 17U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 13U) + aOrbiterI) + RotL64(aOrbiterH, 13U)) + RotL64(aCarry, 57U)) + aWandererUpdateSaltC[((aIndex + 13U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterG, 5U)) + aOrbiterI) + aNonceWordC);
            aWandererA = aWandererA + (((RotL64(aCross, 22U) + RotL64(aOrbiterF, 26U)) + aOrbiterI) + aNonceWordI);
            //
            aCarry = aCarry + (RotL64(aWandererA, 19U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererC, 56U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererE, 37U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // kdf_a_loop_c loop 4
        // ingress from: aWorkLaneC, aWorkLaneA, aFireLaneC
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aFireLaneC forward/backward random
        // cross from: aWorkLaneB, aOperationLaneC, aOperationLaneD, aOperationLaneA
        // cross directions: aWorkLaneB backward forced, aOperationLaneC backward forced, aOperationLaneD backward forced, aOperationLaneA backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 31701U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneA[((aIndex + 30635U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 27037U)) & S_BLOCK1], 6U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 30145U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 32129U)) & S_BLOCK1], 35U));
            aCross ^= (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 30031U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneA[((aIndex + 31367U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aPrevious, 57U) + RotL64(aCarry, 23U)) ^ (RotL64(aIngress, 10U) ^ RotL64(aCross, 43U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterD = (((aWandererB + RotL64(aIngress, 11U)) + RotL64(aCarry, 11U)) + 4751694786009671052U) + aOrbiterAssignSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = ((aWandererE + RotL64(aScatter, 36U)) + RotL64(aCarry, 53U)) + 16362725160370844224U;
            aOrbiterB = (((aWandererD + RotL64(aPrevious, 23U)) + RotL64(aCarry, 35U)) + 6360885380915941057U) + aNonceWordD;
            aOrbiterF = ((aWandererC + RotL64(aCross, 3U)) + 5154536007972297036U) + aOrbiterAssignSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterI = ((aWandererG + RotL64(aIngress, 53U)) + 9362540581874808253U) + aNonceWordF;
            //
            aOrbiterD = (((aOrbiterD + aOrbiterH) + 13902493871525612934U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordE;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 10208452885367546542U) ^ aNonceWordC;
            aOrbiterB = RotL64((aOrbiterB * 12067703239567933105U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 3117030377279160998U) + aNonceWordI;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 17286247690414027870U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 4896931759653832095U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 3930314320040949141U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 7289525252391668404U;
            aOrbiterH = RotL64((aOrbiterH * 15452162299105112187U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 3434167955466809185U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 17852573095128575663U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 1485660158767033425U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 6137259687928853253U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 13992510605237574698U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 15346263295995333395U), 57U);
            //
            aIngress = RotL64(aOrbiterD, 3U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 29U));
            aIngress = aIngress + RotL64(aOrbiterH, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aIngress, 58U) + aOrbiterH) + RotL64(aOrbiterB, 29U));
            aWandererD = aWandererD + (((((RotL64(aCross, 39U) + RotL64(aOrbiterF, 19U)) + aOrbiterB) + RotL64(aCarry, 39U)) + aNonceWordG) + aWandererUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterF, 5U)) + aOrbiterI);
            aWandererE = aWandererE + ((((RotL64(aScatter, 21U) + aOrbiterH) + RotL64(aOrbiterD, 41U)) + RotL64(aCarry, 11U)) + aNonceWordA);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterF, 56U)) + aOrbiterH) + aWandererUpdateSaltD[((aIndex + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 29U));
            aCarry = aCarry + (RotL64(aWandererD, 37U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererG, 11U);
            aCarry = aCarry + RotL64(aIngress, 46U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xA6602701AC7C9BBBULL + 0xD51743E58022ED82ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xEA99BEF5C9D71FF5ULL + 0x846E9DDBD3CA4E8EULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x96F7E13405E42439ULL + 0xCE998E533F261D70ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xDFCBB7887931481FULL + 0xFC5AEA69539E501FULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xBEDB49C6E2E4713FULL + 0x850E27BC18ACB34FULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xE0A903E7DCAD77F1ULL + 0x952B59D2A6FDD9D9ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xC22E1F121BE14461ULL + 0xC8C8732AD4433E7EULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x994EA868D8FF8761ULL + 0xC7823BF6E85D55EEULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xF7021C0A6A8046A1ULL + 0xE1A59C0322AA6F1DULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0x9BD0B13F9059440BULL + 0xB2A13F024C60A053ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xF75883BB308CD4ABULL + 0x8A8399CEE9D09CD3ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xFFF79171EFE13F27ULL + 0x91C48971EE4C40CCULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xE54E3DE9EC77E32DULL + 0x91A2FCBB049A511BULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xB61D0B5C1C5ECD87ULL + 0xA0E6C224A477A068ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xB64CD2F36E6B440BULL + 0x93E94A1028114000ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xD7A443FB9C7CF137ULL + 0xDFDF886A604B8FECULL);
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
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneD, aExpandLaneC, aExpandLaneD, aOperationLaneC, aWorkLaneA, aOperationLaneB, aOperationLaneA, aWorkLaneB, aFireLaneA, aFireLaneC, aWorkLaneC, aFireLaneB, aOperationLaneD
        // write to: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // kdf_a_loop_d loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aFireLaneD
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aFireLaneD forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD, aOperationLaneC
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward forced, aOperationLaneC backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 8151U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneB[((aIndex + 2777U)) & S_BLOCK1], 58U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 256U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 650U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 5433U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aOperationLaneC[((aIndex + 5880U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aIngress, 12U) ^ RotL64(aCarry, 39U)) + (RotL64(aCross, 53U) + RotL64(aPrevious, 27U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterD = ((aWandererA + RotL64(aCross, 47U)) + 5697928251815176134U) + aOrbiterAssignSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterB = ((aWandererE + RotL64(aPrevious, 35U)) + RotL64(aCarry, 3U)) + 337587740689259575U;
            aOrbiterA = ((aWandererB + RotL64(aScatter, 27U)) + 4927686903263973950U) + aNonceWordD;
            aOrbiterE = ((aWandererD + RotL64(aIngress, 10U)) + 3742409032569801033U) + aNonceWordP;
            aOrbiterI = ((((aWandererK + RotL64(aCross, 53U)) + RotL64(aCarry, 37U)) + 1608092659172197650U) + aOrbiterAssignSaltE[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordK;
            aOrbiterF = (aWandererH + RotL64(aIngress, 3U)) + 15848744267145717509U;
            aOrbiterH = (((aWandererI + RotL64(aScatter, 41U)) + RotL64(aCarry, 23U)) + 15300174177963339253U) + aNonceWordC;
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 14162868453323648628U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 12020167069983729869U) ^ aOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2071080217680099017U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 16259538291658723956U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 8516686212464112245U;
            aOrbiterI = RotL64((aOrbiterI * 4731296903548893627U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 3722184575520553132U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 5663609293306386784U) ^ aNonceWordH;
            aOrbiterF = RotL64((aOrbiterF * 14364218128780764749U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 15265344442454471986U) + aNonceWordM;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 3050323350098829515U;
            aOrbiterD = RotL64((aOrbiterD * 5890624677162388135U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 1093356813820599238U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 15167726103772238440U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5719466863561311069U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 15170797965325981472U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 17826286701992981628U) ^ aNonceWordE;
            aOrbiterH = RotL64((aOrbiterH * 11186808881726573677U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 14710892030473425181U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 397194787697553904U) ^ aOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 14368930300818752833U), 29U);
            //
            aIngress = RotL64(aOrbiterF, 13U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterA, 23U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 57U));
            aIngress = aIngress + RotL64(aOrbiterI, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aScatter, 11U) + aOrbiterI) + RotL64(aOrbiterF, 53U));
            aWandererH = aWandererH + (((((RotL64(aIngress, 41U) + RotL64(aOrbiterH, 21U)) + aOrbiterA) + RotL64(aCarry, 19U)) + aNonceWordJ) + aWandererUpdateSaltF[((aIndex + 11U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterD, 37U)) + aOrbiterA);
            aWandererK = aWandererK + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterE, 30U)) + aOrbiterB) + aNonceWordA);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 5U) + RotL64(aOrbiterI, 47U)) + aOrbiterB) + aNonceWordF);
            aWandererB = aWandererB + (((RotL64(aPrevious, 23U) + RotL64(aOrbiterB, 11U)) + aOrbiterD) + RotL64(aCarry, 39U));
            aWandererA = aWandererA ^ ((((RotL64(aCross, 30U) + aOrbiterE) + RotL64(aOrbiterD, 3U)) + aNonceWordG) + aWandererUpdateSaltB[((aIndex + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 47U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererI, 43U) ^ aWandererD);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 51U));
            aCarry = aCarry + RotL64(aWandererA, 58U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 2
        // ingress from: aWorkLaneA, aExpandLaneC, aOperationLaneB
        // ingress directions: aWorkLaneA forward forced, aExpandLaneC forward forced, aOperationLaneB forward/backward random
        // cross from: aExpandLaneA, aExpandLaneD, aOperationLaneA
        // cross directions: aExpandLaneA backward forced, aExpandLaneD backward forced, aOperationLaneA backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 14692U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneC[((aIndex + 15497U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 10786U)) & S_BLOCK1], 54U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 13223U)) & S_BLOCK1], 54U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 14599U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 16307U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCarry, 13U) + RotL64(aIngress, 27U)) ^ (RotL64(aCross, 58U) + RotL64(aPrevious, 43U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterG = (((aWandererC + RotL64(aIngress, 27U)) + RotL64(aCarry, 13U)) + 18191288703716505885U) + aOrbiterAssignSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = (aWandererB + RotL64(aCross, 39U)) + 9824014524910417136U;
            aOrbiterI = (aWandererI + RotL64(aPrevious, 3U)) + 11953012029254917548U;
            aOrbiterB = ((aWandererA + RotL64(aScatter, 57U)) + 6297568011027199089U) + aNonceWordC;
            aOrbiterE = (((aWandererF + RotL64(aPrevious, 11U)) + 2576999400457367975U) + aOrbiterAssignSaltC[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordA;
            aOrbiterD = (((aWandererG + RotL64(aScatter, 46U)) + RotL64(aCarry, 41U)) + 13176139160575558254U) + aNonceWordI;
            aOrbiterC = ((aWandererJ + RotL64(aCross, 21U)) + RotL64(aCarry, 27U)) + 9978408174563621810U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 16765834875061607142U) + aNonceWordM;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 16534507305459121344U) ^ aOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 8943988574248229067U), 3U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterB) + 3114710944346151807U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordB;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 10240517868726718592U;
            aOrbiterE = RotL64((aOrbiterE * 4645691562915606463U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 10721450637990777883U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 16689590768796583952U;
            aOrbiterB = RotL64((aOrbiterB * 3046344179729901637U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 2427422768928450209U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 13495584061816457831U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 6670984773768885119U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 7058636403765106682U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 9897341853944713767U;
            aOrbiterG = RotL64((aOrbiterG * 14286816859999869231U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 17749559755733386064U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 12515645083926326659U;
            aOrbiterD = RotL64((aOrbiterD * 6582878478865838245U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 2625692458813609962U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 10596240255026143019U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 11605800195771080135U), 35U);
            //
            aIngress = RotL64(aOrbiterB, 5U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterI, 19U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterC, 53U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterG, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterE, 27U)) + aOrbiterI) + aNonceWordP);
            aWandererG = aWandererG + (((RotL64(aIngress, 57U) + RotL64(aOrbiterG, 35U)) + aOrbiterI) + aNonceWordF);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterI, 5U)) + aOrbiterJ);
            aWandererF = aWandererF + ((((RotL64(aCross, 11U) + RotL64(aOrbiterI, 11U)) + aOrbiterB) + RotL64(aCarry, 5U)) + aWandererUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 37U) + aOrbiterB) + RotL64(aOrbiterC, 51U)) + aWandererUpdateSaltD[((aIndex + 12U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aPrevious, 20U) + aOrbiterG) + RotL64(aOrbiterD, 41U)) + RotL64(aCarry, 41U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 43U) + aOrbiterJ) + RotL64(aOrbiterB, 58U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 23U));
            aCarry = aCarry + (RotL64(aWandererI, 40U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererC, 27U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 3
        // ingress from: aWorkLaneB, aExpandLaneD, aFireLaneA
        // ingress directions: aWorkLaneB forward forced, aExpandLaneD forward forced, aFireLaneA forward/backward random
        // cross from: aWorkLaneA, aExpandLaneB, aFireLaneC
        // cross directions: aWorkLaneA backward forced, aExpandLaneB backward forced, aFireLaneC backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 23365U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneD[((aIndex + 20554U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 18173U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18173U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 22371U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aFireLaneC[((aIndex + 21645U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCross, 51U) ^ RotL64(aPrevious, 23U)) ^ (RotL64(aCarry, 39U) + RotL64(aIngress, 10U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterE = ((aWandererH + RotL64(aPrevious, 5U)) + 5160910997561396461U) + aOrbiterAssignSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = ((aWandererC + RotL64(aCross, 21U)) + 14920764751058512062U) + aNonceWordN;
            aOrbiterG = ((aWandererG + RotL64(aIngress, 14U)) + 6080952401749660022U) + aNonceWordD;
            aOrbiterA = (((aWandererB + RotL64(aScatter, 53U)) + RotL64(aCarry, 3U)) + 17667234330526298627U) + aOrbiterAssignSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = (aWandererK + RotL64(aIngress, 47U)) + 760630072638686756U;
            aOrbiterI = ((aWandererE + RotL64(aCross, 41U)) + RotL64(aCarry, 21U)) + 3504157162816997476U;
            aOrbiterB = (((aWandererA + RotL64(aPrevious, 27U)) + RotL64(aCarry, 47U)) + 9489022223422585882U) + aNonceWordM;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 1149898536879968964U) + aNonceWordG;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 10492284328940025310U) ^ aNonceWordB;
            aOrbiterG = RotL64((aOrbiterG * 7893416766300156495U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 13213275606286399312U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 10557118912847180413U) ^ aOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10077877991284587845U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 15618980209023994776U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 5268600749854045564U;
            aOrbiterE = RotL64((aOrbiterE * 3849660559223919613U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 8011552687609649990U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 3148133096349525066U;
            aOrbiterD = RotL64((aOrbiterD * 5245156554959620007U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 12032847944237867285U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 14999005703490824673U;
            aOrbiterI = RotL64((aOrbiterI * 6631584955208646049U), 19U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterD) + 5426735969392906710U) + aOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1]) + aNonceWordE;
            aOrbiterA = (((aOrbiterA ^ aOrbiterB) ^ 3593177531650386729U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterA = RotL64((aOrbiterA * 12997284886192717043U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 1701444719333347373U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 15928731228196894960U;
            aOrbiterB = RotL64((aOrbiterB * 1919318226904213433U), 27U);
            //
            aIngress = RotL64(aOrbiterE, 57U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterD, 48U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 5U));
            aIngress = aIngress + RotL64(aOrbiterB, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((((RotL64(aScatter, 47U) + RotL64(aOrbiterI, 29U)) + aOrbiterD) + RotL64(aCarry, 39U)) + aNonceWordF) + aWandererUpdateSaltE[((aIndex + 28U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 27U) + RotL64(aOrbiterG, 23U)) + aOrbiterJ) + aNonceWordO);
            aWandererC = aWandererC + ((RotL64(aIngress, 41U) + RotL64(aOrbiterA, 41U)) + aOrbiterJ);
            aWandererK = aWandererK ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterG, 35U)) + aOrbiterE);
            aWandererE = aWandererE + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterI, 13U)) + aOrbiterJ) + RotL64(aCarry, 27U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 54U) + aOrbiterI) + RotL64(aOrbiterB, 48U)) + aNonceWordI);
            aWandererH = aWandererH + (((RotL64(aCross, 21U) + RotL64(aOrbiterJ, 57U)) + aOrbiterE) + aWandererUpdateSaltC[((aIndex + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 24U));
            aCarry = aCarry + (RotL64(aWandererB, 35U) ^ aWandererH);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 3U));
            aCarry = aCarry + RotL64(aWandererK, 41U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 4
        // ingress from: aWorkLaneC, aWorkLaneA, aFireLaneB
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aFireLaneB forward/backward random
        // cross from: aWorkLaneB, aExpandLaneC, aOperationLaneD
        // cross directions: aWorkLaneB backward forced, aExpandLaneC backward forced, aOperationLaneD backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 28406U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneA[((aIndex + 30846U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 31701U)) & S_BLOCK1], 52U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 30263U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 25922U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 28391U)) & S_BLOCK1], 20U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aIngress, 57U) ^ RotL64(aCarry, 43U)) ^ (RotL64(aPrevious, 29U) + RotL64(aCross, 12U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterJ = (((aWandererE + RotL64(aIngress, 53U)) + 6916817163240024692U) + aOrbiterAssignSaltE[((aIndex + 23U)) & S_SALT1]) + aNonceWordA;
            aOrbiterD = ((aWandererJ + RotL64(aScatter, 35U)) + RotL64(aCarry, 27U)) + 14554930751292077817U;
            aOrbiterH = ((aWandererI + RotL64(aCross, 27U)) + RotL64(aCarry, 39U)) + 1098305064484336101U;
            aOrbiterG = (((aWandererF + RotL64(aPrevious, 20U)) + 12192821172420471527U) + aOrbiterAssignSaltB[((aIndex + 6U)) & S_SALT1]) + aNonceWordO;
            aOrbiterK = (aWandererC + RotL64(aCross, 43U)) + 2435134991707318845U;
            aOrbiterB = (aWandererA + RotL64(aPrevious, 3U)) + 1896745368738512624U;
            aOrbiterI = ((aWandererB + RotL64(aIngress, 13U)) + RotL64(aCarry, 53U)) + 1114996424222923873U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 9839135798371512656U) + aOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 8037967239603177043U) ^ aNonceWordB;
            aOrbiterH = RotL64((aOrbiterH * 7848951103759663025U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 15185468738487237432U) + aOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 4912098316394854543U;
            aOrbiterB = RotL64((aOrbiterB * 3072785550384399929U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 13142688607850380888U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 4507379759608945839U) ^ aNonceWordH;
            aOrbiterI = RotL64((aOrbiterI * 2989332387754215967U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 7299006009652289342U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 5390655277207053627U;
            aOrbiterD = RotL64((aOrbiterD * 10973744708856143715U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 6744737023577785725U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 15539737698867067285U;
            aOrbiterK = RotL64((aOrbiterK * 4686092035261336911U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 13329866734681377952U) + aOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 13284937458969166257U;
            aOrbiterJ = RotL64((aOrbiterJ * 3965985432462699445U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 8695002088915702168U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 3858059421620839286U;
            aOrbiterG = RotL64((aOrbiterG * 9559783727301092937U), 3U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterH, 21U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 60U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 3U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterD, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((((RotL64(aPrevious, 43U) + RotL64(aOrbiterK, 60U)) + aOrbiterJ) + aNonceWordK) + aWandererUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aIngress, 23U) + aOrbiterH) + RotL64(aOrbiterG, 47U)) + RotL64(aCarry, 51U)) + aNonceWordE);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterJ, 13U)) + aOrbiterH);
            aWandererA = aWandererA + ((RotL64(aCross, 51U) + RotL64(aOrbiterB, 29U)) + aOrbiterI);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 57U) + aOrbiterK) + RotL64(aOrbiterB, 5U)) + aNonceWordC);
            aWandererE = aWandererE + (((RotL64(aCross, 5U) + aOrbiterD) + RotL64(aOrbiterB, 21U)) + RotL64(aCarry, 21U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 14U) + RotL64(aOrbiterI, 37U)) + aOrbiterG) + aWandererUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 48U) ^ aWandererE);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 19U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 11U));
            aCarry = aCarry + RotL64(aWandererC, 35U);
            aCarry = aCarry + RotL64(aIngress, 52U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x926DEFC5F0D9D853ULL + 0xDBE0036D19B507BBULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xA832AB1F75C129E5ULL + 0xE832AADDCAA8C3E8ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xABBF49DC5B591C3FULL + 0xC2513B5325FCE850ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xA6651D894CD1ADC5ULL + 0xE1A0D13A988DEEC8ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xA5A4EBE761B83B1FULL + 0xF8FF8F51B54F9DCAULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xD85AA4973127F4BBULL + 0x9E01AFA4C613CBAAULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xB92CA2FCAFB7CDABULL + 0x9C910E50378828B8ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xA44D14285D98EF7BULL + 0x97DD82E718A47709ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0x9FBD7BAD468201C3ULL + 0x87159962719ACB8CULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xF03015F8513D959BULL + 0xA12A47E4B0F9D2C3ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x8B6DD804ABFE43DBULL + 0xA58F61FB32A97340ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xABAE7D974FA65527ULL + 0x8617294BA5D9F8D2ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xD1E86E32E836B3F1ULL + 0x87A5745FDB5392A5ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xF4B1DE241C6FA215ULL + 0xA40A9C7A808CB0FEULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xA4D8B032C8C90A91ULL + 0x9CB1C8F3AED4F857ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xB94F39AF1D714B87ULL + 0x99585BDCC0DEE531ULL);
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
        // read from: aWorkLaneA, aWorkLaneB, aOperationLaneA, aWorkLaneC, aWorkLaneD, aFireLaneD, aExpandLaneA, aFireLaneA, aOperationLaneB, aExpandLaneB, aFireLaneC, aFireLaneB, aExpandLaneC, aOperationLaneC, aOperationLaneD
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_a loop 1
        // ingress from: aWorkLaneA, aWorkLaneB, aOperationLaneA
        // ingress directions: aWorkLaneA forward forced, aWorkLaneB forward forced, aOperationLaneA forward/backward random
        // cross from: aWorkLaneC, aWorkLaneD, aFireLaneD
        // cross directions: aWorkLaneC backward forced, aWorkLaneD backward forced, aFireLaneD backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 6043U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneB[((aIndex + 805U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aOperationLaneA[((aIndex + 6698U)) & S_BLOCK1], 54U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 7748U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 1210U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 3765U)) & S_BLOCK1], 40U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCarry, 13U) + RotL64(aIngress, 29U)) ^ (RotL64(aPrevious, 54U) ^ RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterB = ((aWandererK + RotL64(aCross, 19U)) + 18255347001097480328U) + aNonceWordP;
            aOrbiterJ = ((aWandererB + RotL64(aIngress, 35U)) + 13679246790311505735U) + aNonceWordH;
            aOrbiterE = (((aWandererI + RotL64(aPrevious, 5U)) + RotL64(aCarry, 13U)) + 10565839529765027116U) + aOrbiterAssignSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterA = (((aWandererG + RotL64(aScatter, 13U)) + RotL64(aCarry, 39U)) + 14327172566224769901U) + aOrbiterAssignSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterF = ((aWandererJ + RotL64(aIngress, 43U)) + 16239024612038195174U) + aNonceWordN;
            aOrbiterG = (aWandererE + RotL64(aPrevious, 58U)) + 13800012174212131890U;
            aOrbiterI = (((aWandererC + RotL64(aCross, 29U)) + RotL64(aCarry, 51U)) + 13900288860157577583U) + aNonceWordO;
            //
            aOrbiterB = (((aOrbiterB + aOrbiterJ) + 4144386119777112740U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1]) + aNonceWordF;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 3154558262670631372U;
            aOrbiterE = RotL64((aOrbiterE * 13236911910092437063U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 7456728543137614001U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 11709519851158935384U) ^ aOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 7016689518570071587U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 15607438907832240304U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 9276575329661725624U;
            aOrbiterB = RotL64((aOrbiterB * 8879744070762412745U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 6459435969129449226U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 6442382118416542275U;
            aOrbiterF = RotL64((aOrbiterF * 2921027306686588233U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 12117432107282150865U) + aOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 6831279293184793243U;
            aOrbiterA = RotL64((aOrbiterA * 2435360641135249073U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 9520022957804572889U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 8322178689474588679U) ^ aNonceWordD;
            aOrbiterG = RotL64((aOrbiterG * 1627707191467537115U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 4162401591586869316U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 8994015844714895961U;
            aOrbiterI = RotL64((aOrbiterI * 15421910378057951895U), 51U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterF, 3U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 11U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 47U));
            aIngress = aIngress + RotL64(aOrbiterJ, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((((RotL64(aScatter, 44U) + aOrbiterG) + RotL64(aOrbiterA, 29U)) + aNonceWordK) + aWandererUpdateSaltC[((aIndex + 7U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 3U) + RotL64(aOrbiterB, 39U)) + aOrbiterJ) + RotL64(aCarry, 11U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 13U) + aOrbiterF) + RotL64(aOrbiterB, 5U)) + aNonceWordC);
            aWandererG = aWandererG + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterB, 46U)) + aOrbiterE) + RotL64(aCarry, 41U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 51U) + aOrbiterA) + RotL64(aOrbiterJ, 21U)) + aNonceWordI);
            aWandererI = aWandererI + ((RotL64(aIngress, 35U) + aOrbiterJ) + RotL64(aOrbiterI, 11U));
            aWandererC = aWandererC ^ ((((RotL64(aPrevious, 29U) + RotL64(aOrbiterG, 53U)) + aOrbiterJ) + aNonceWordM) + aWandererUpdateSaltB[((aIndex + 12U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 19U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererK, 6U) ^ aWandererJ);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 47U));
            aCarry = aCarry + RotL64(aWandererE, 37U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 2
        // ingress from: aExpandLaneA, aWorkLaneC, aFireLaneA
        // ingress directions: aExpandLaneA forward forced, aWorkLaneC forward forced, aFireLaneA forward/backward random
        // cross from: aWorkLaneA, aWorkLaneD, aOperationLaneB
        // cross directions: aWorkLaneA backward forced, aWorkLaneD backward forced, aOperationLaneB backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 12531U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneC[((aIndex + 11096U)) & S_BLOCK1], 24U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 15288U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 10072U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 14151U)) & S_BLOCK1], 41U));
            aCross ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 11775U)) & S_BLOCK1], 10U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCross, 51U) + RotL64(aPrevious, 39U)) + (RotL64(aIngress, 21U) ^ RotL64(aCarry, 6U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterA = ((aWandererJ + RotL64(aScatter, 57U)) + RotL64(aCarry, 5U)) + 8375305456876489425U;
            aOrbiterH = (((aWandererE + RotL64(aIngress, 29U)) + RotL64(aCarry, 23U)) + 16193562952772453047U) + aOrbiterAssignSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = (aWandererK + RotL64(aPrevious, 4U)) + 18088652458594816223U;
            aOrbiterD = (((aWandererC + RotL64(aCross, 35U)) + RotL64(aCarry, 57U)) + 767344788620249944U) + aNonceWordD;
            aOrbiterC = ((aWandererG + RotL64(aScatter, 23U)) + 7705194930396368752U) + aOrbiterAssignSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = (aWandererA + RotL64(aPrevious, 41U)) + 3829736891311272834U;
            aOrbiterK = ((aWandererD + RotL64(aIngress, 11U)) + 9881681671347640061U) + aNonceWordE;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 1721196560190164264U) + aNonceWordI;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 3002652618388454213U;
            aOrbiterI = RotL64((aOrbiterI * 15289749311593032657U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 9811621464004005202U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 5652598941069986530U;
            aOrbiterH = RotL64((aOrbiterH * 4797973356708091621U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 6250499348327316328U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 16025054277615264530U) ^ aOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 16446892258704281903U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 13800298546867243172U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 12256104592865905782U;
            aOrbiterE = RotL64((aOrbiterE * 16983140179497142713U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 17817225416918329229U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 17738671327352776217U) ^ aNonceWordP;
            aOrbiterA = RotL64((aOrbiterA * 393488251327705063U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 6816031224188400541U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 16989563985059237014U) ^ aNonceWordM;
            aOrbiterD = RotL64((aOrbiterD * 8677884225771717797U), 37U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterK) + 16891524847268207549U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordH;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 1833508573940405571U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9709196587703979539U), 51U);
            //
            aIngress = RotL64(aOrbiterI, 60U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 3U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 53U));
            aIngress = aIngress + RotL64(aOrbiterE, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aScatter, 35U) + aOrbiterH) + RotL64(aOrbiterD, 53U)) + aWandererUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 41U) + aOrbiterH) + RotL64(aOrbiterE, 60U));
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 13U) + RotL64(aOrbiterA, 3U)) + aOrbiterC) + RotL64(aCarry, 23U)) + aWandererUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 3U) + aOrbiterH) + RotL64(aOrbiterK, 19U)) + aNonceWordF);
            aWandererG = aWandererG + ((RotL64(aIngress, 19U) + RotL64(aOrbiterD, 35U)) + aOrbiterE);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 47U) + RotL64(aOrbiterK, 29U)) + aOrbiterI) + aNonceWordJ);
            aWandererK = aWandererK + (((RotL64(aCross, 54U) + aOrbiterH) + RotL64(aOrbiterA, 13U)) + RotL64(aCarry, 51U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 30U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 57U));
            aCarry = aCarry + (RotL64(aWandererD, 37U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererK, 41U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 3
        // ingress from: aExpandLaneB, aWorkLaneD, aFireLaneC
        // ingress directions: aExpandLaneB forward forced, aWorkLaneD forward forced, aFireLaneC forward/backward random
        // cross from: aExpandLaneA, aWorkLaneB, aFireLaneB
        // cross directions: aExpandLaneA backward forced, aWorkLaneB backward forced, aFireLaneB backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 22451U)) & S_BLOCK1], 48U) ^ RotL64(aWorkLaneD[((aIndex + 22244U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 24572U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 16544U)) & S_BLOCK1], 18U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 23116U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 17992U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCarry, 6U) + RotL64(aIngress, 57U)) + (RotL64(aPrevious, 43U) ^ RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterC = (aWandererK + RotL64(aCross, 3U)) + 18319689184146942855U;
            aOrbiterA = ((aWandererA + RotL64(aScatter, 47U)) + RotL64(aCarry, 41U)) + 8041304130090501019U;
            aOrbiterD = ((aWandererD + RotL64(aIngress, 29U)) + RotL64(aCarry, 13U)) + 11347064191990897738U;
            aOrbiterB = ((aWandererJ + RotL64(aPrevious, 21U)) + RotL64(aCarry, 29U)) + 15242243470024447468U;
            aOrbiterI = ((aWandererF + RotL64(aScatter, 40U)) + 10619749107163611105U) + aNonceWordE;
            aOrbiterF = (((aWandererH + RotL64(aCross, 53U)) + 14795614276221947128U) + aOrbiterAssignSaltD[((aIndex + 27U)) & S_SALT1]) + aNonceWordC;
            aOrbiterJ = ((aWandererG + RotL64(aPrevious, 13U)) + 1578095288886372393U) + aOrbiterAssignSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 13593906305770501684U) + aNonceWordB;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 8919815528334599172U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2033810402808238127U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 17425548324720065145U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 11125018338392347335U;
            aOrbiterF = RotL64((aOrbiterF * 4377887040461528587U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 3779189180734244399U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 10958224663276134041U;
            aOrbiterC = RotL64((aOrbiterC * 6206963519509783781U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 4317305352561612995U) + aNonceWordN;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 4891139433808505355U) ^ aNonceWordH;
            aOrbiterI = RotL64((aOrbiterI * 11507024985663120317U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 5166074784835930965U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 10080890270621589202U) ^ aOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13170894418184288695U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 4501071771615514619U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 6486573807774431753U;
            aOrbiterB = RotL64((aOrbiterB * 324029625116648669U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 15714881857668975753U) + aOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 3506619392820235900U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5707033870161224499U), 23U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterF, 43U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 50U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterD, 57U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterI, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterA, 57U)) + aOrbiterD);
            aWandererD = aWandererD + ((((RotL64(aCross, 43U) + RotL64(aOrbiterC, 21U)) + aOrbiterF) + RotL64(aCarry, 41U)) + aNonceWordG);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 5U) + aOrbiterI) + RotL64(aOrbiterB, 48U));
            aWandererH = aWandererH + ((RotL64(aIngress, 11U) + aOrbiterI) + RotL64(aOrbiterF, 3U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 53U) + aOrbiterC) + RotL64(aOrbiterA, 39U)) + aWandererUpdateSaltF[((aIndex + 25U)) & S_SALT1]);
            aWandererF = aWandererF + (((((RotL64(aIngress, 36U) + RotL64(aOrbiterJ, 11U)) + aOrbiterC) + RotL64(aCarry, 53U)) + aNonceWordP) + aWandererUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterJ, 27U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererD, 27U) ^ aWandererH);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 5U));
            aCarry = aCarry + (RotL64(aWandererG, 10U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererK, 23U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 29038U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneA[((aIndex + 31249U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aOperationLaneC[((aIndex + 29394U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29719U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 31135U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 29791U)) & S_BLOCK1], 46U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aIngress, 21U) ^ RotL64(aCarry, 41U)) + (RotL64(aCross, 6U) + RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterI = ((aWandererH + RotL64(aCross, 57U)) + 9446153639709651566U) + aNonceWordI;
            aOrbiterD = ((aWandererE + RotL64(aScatter, 19U)) + 10550762260670758167U) + aOrbiterAssignSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterE = (((aWandererF + RotL64(aIngress, 35U)) + RotL64(aCarry, 39U)) + 7062634922142578383U) + aNonceWordM;
            aOrbiterJ = (((aWandererJ + RotL64(aPrevious, 47U)) + 9178499097812764515U) + aOrbiterAssignSaltA[(((31U - aIndex) + 14U)) & S_SALT1]) + aNonceWordF;
            aOrbiterK = ((aWandererK + RotL64(aCross, 3U)) + RotL64(aCarry, 57U)) + 6887103379773525538U;
            aOrbiterH = (aWandererG + RotL64(aScatter, 26U)) + 6239750312052010257U;
            aOrbiterA = ((aWandererB + RotL64(aPrevious, 41U)) + RotL64(aCarry, 21U)) + 17645022614523287959U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 3639618183259408272U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterI) ^ 3131737117548745095U) ^ aOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterE = RotL64((aOrbiterE * 6585057380704940395U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 7253994382396406554U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 15217993711938379561U;
            aOrbiterH = RotL64((aOrbiterH * 17853313384747259923U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 12594152227603630033U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 11250170200489647869U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 546800378327864723U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 12936942656624279424U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 10990736056052106149U;
            aOrbiterD = RotL64((aOrbiterD * 7123916809953459187U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 12787293075893090465U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 17154990205620778151U;
            aOrbiterA = RotL64((aOrbiterA * 10031369940028159521U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 1270827262969060301U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 17337623431665013136U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 1517262088236356107U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 830330490987911853U) + aNonceWordL;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 6828309232554560547U;
            aOrbiterK = RotL64((aOrbiterK * 9742464176986145819U), 5U);
            //
            aIngress = RotL64(aOrbiterK, 29U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterJ, 43U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 12U));
            aIngress = aIngress + RotL64(aOrbiterH, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aScatter, 35U) + aOrbiterD) + RotL64(aOrbiterJ, 35U));
            aWandererK = aWandererK + ((((RotL64(aIngress, 41U) + RotL64(aOrbiterH, 23U)) + aOrbiterI) + RotL64(aCarry, 13U)) + aNonceWordE);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 11U) + aOrbiterJ) + RotL64(aOrbiterE, 13U)) + aWandererUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aPrevious, 19U) + aOrbiterK) + RotL64(aOrbiterA, 29U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 5U) + aOrbiterJ) + RotL64(aOrbiterK, 57U)) + aNonceWordN);
            aWandererG = aWandererG + (((RotL64(aScatter, 51U) + aOrbiterI) + RotL64(aOrbiterD, 5U)) + RotL64(aCarry, 43U));
            aWandererH = aWandererH ^ ((((RotL64(aIngress, 26U) + RotL64(aOrbiterA, 46U)) + aOrbiterD) + aNonceWordG) + aWandererUpdateSaltB[((aIndex + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 39U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererF, 48U) ^ aWandererE);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 43U));
            aCarry = aCarry + RotL64(aWandererJ, 57U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x9CAE90323BD83687ULL + 0xD989698A944A9FEEULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xE2D7F4F06E72E3D5ULL + 0xC1BA466A6D059F2DULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xFE1129978F669257ULL + 0x8CB089B0E25A04F3ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x9513DDB3A31B54C1ULL + 0xA380F8972B5AEABEULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xC23426F73878EF77ULL + 0xCB45EE5CF8C89997ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x8A84B925F536ADC5ULL + 0x86B6068A5FEE1DC6ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xCFDCB19DF23D7DE3ULL + 0x8BF30293760D3859ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xABCD50E50C278621ULL + 0xB0F78BCE3E26CE8AULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x9152B9C35B230819ULL + 0xB7D4B223749896A5ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xE67EC92722295C91ULL + 0xF406BB69346DF30FULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xE2CACDBC02903879ULL + 0xCC1A59003DD7C4F4ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xC504AF1DCD220C45ULL + 0x9E1A555A85532129ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0x86BB4AC61BCE13A3ULL + 0x960D03945A81E466ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x8845A2AF5FB5C2CBULL + 0xC3CCEDCAFDA50AE3ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xEC5E8B5CFFA33381ULL + 0xE0BA3BB21DDBDF6EULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xD736DDCB158EBCD3ULL + 0x8A221440C56F5E8DULL);
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
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneA, aExpandLaneC, aExpandLaneD, aWorkLaneB, aOperationLaneA, aWorkLaneC, aWorkLaneD, aOperationLaneB, aFireLaneC, aWorkLaneA, aOperationLaneC, aFireLaneD, aFireLaneB
        // write to: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD
    
        // kdf_b_loop_b loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aFireLaneA
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aFireLaneA forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD, aWorkLaneB
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward forced, aWorkLaneB backward/forward random
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 2183U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneB[((aIndex + 5598U)) & S_BLOCK1], 36U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 8138U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 3797U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 5125U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 7237U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aPrevious, 54U) + RotL64(aCarry, 39U)) ^ (RotL64(aCross, 5U) ^ RotL64(aIngress, 19U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterE = (aWandererD + RotL64(aPrevious, 57U)) + 2168513956284366370U;
            aOrbiterB = (aWandererG + RotL64(aIngress, 41U)) + 10290361969974613111U;
            aOrbiterG = (aWandererF + RotL64(aCross, 27U)) + 15673836275828498050U;
            aOrbiterH = (aWandererI + RotL64(aScatter, 10U)) + 16600540024145812236U;
            aOrbiterC = (aWandererE + RotL64(aCross, 21U)) + 9428052101528111892U;
            aOrbiterJ = ((aWandererA + RotL64(aScatter, 23U)) + 12763657928312763377U) + aNonceWordP;
            aOrbiterF = ((aWandererK + RotL64(aIngress, 3U)) + 10751286982008662485U) + aNonceWordK;
            aOrbiterD = (((aWandererB + RotL64(aPrevious, 53U)) + RotL64(aCarry, 19U)) + 1708230173038057979U) + aNonceWordB;
            aOrbiterA = ((aWandererH + RotL64(aCross, 43U)) + 4011389705422783816U) + aOrbiterAssignSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterI = ((((aWandererC + RotL64(aIngress, 6U)) + RotL64(aCarry, 3U)) + 11704428328093077714U) + aOrbiterAssignSaltB[((aIndex + 29U)) & S_SALT1]) + aNonceWordC;
            aOrbiterK = ((aWandererJ + RotL64(aScatter, 37U)) + RotL64(aCarry, 39U)) + 2055336619674699284U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 1870865272102705804U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 3574214263751923179U;
            aOrbiterG = RotL64((aOrbiterG * 13132083406834413563U), 37U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 984611970726966186U) + aNonceWordH;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 15207945449947643672U;
            aOrbiterC = RotL64((aOrbiterC * 9539470161576639981U), 41U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 4181398506373973169U) + aOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 15222345431506025949U;
            aOrbiterF = RotL64((aOrbiterF * 6925143692628659467U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 15023513452326240962U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 14965669361708810699U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 587008860996713147U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 7985755518735406360U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 225592097619240187U) ^ aNonceWordN;
            aOrbiterH = RotL64((aOrbiterH * 2313509354133400439U), 23U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 3659537916566939383U) + aOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 17043668033610689611U;
            aOrbiterD = RotL64((aOrbiterD * 10797634709118100773U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 10217321522161675848U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 8013663869536146842U;
            aOrbiterB = RotL64((aOrbiterB * 2293233079384777175U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 13762445330867496042U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 2692400019659269106U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 167704184292219399U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 18232551682424867647U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 14785847596876239854U;
            aOrbiterJ = RotL64((aOrbiterJ * 4569180925037758487U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 5910282247522389536U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 16556038638738871204U;
            aOrbiterK = RotL64((aOrbiterK * 18356922295088260901U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 141620663839815754U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 2168513956284366370U;
            aOrbiterI = RotL64((aOrbiterI * 8605382725635471683U), 3U);
            //
            aIngress = RotL64(aOrbiterC, 5U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 53U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 27U));
            aIngress = aIngress + (RotL64(aOrbiterG, 24U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 39U));
            aIngress = aIngress + RotL64(aOrbiterB, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aIngress, 43U) + aOrbiterE) + RotL64(aOrbiterB, 57U));
            aWandererD = aWandererD + (((RotL64(aScatter, 37U) + aOrbiterJ) + RotL64(aOrbiterC, 30U)) + aWandererUpdateSaltE[((aIndex + 10U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterA, 51U)) + aOrbiterF);
            aWandererI = aWandererI + (((RotL64(aPrevious, 39U) + aOrbiterK) + RotL64(aOrbiterA, 23U)) + aNonceWordE);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 13U) + aOrbiterA) + RotL64(aOrbiterH, 41U));
            aWandererK = aWandererK + (((RotL64(aCross, 60U) + RotL64(aOrbiterD, 27U)) + aOrbiterE) + RotL64(aCarry, 41U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 53U) + RotL64(aOrbiterI, 43U)) + aOrbiterC) + aWandererUpdateSaltF[((aIndex + 23U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 11U) + aOrbiterI) + RotL64(aOrbiterG, 11U)) + RotL64(aCarry, 35U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 29U) + aOrbiterD) + RotL64(aOrbiterJ, 13U)) + aNonceWordF);
            aWandererG = aWandererG + ((RotL64(aCross, 24U) + RotL64(aOrbiterD, 5U)) + aOrbiterA);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 21U) + aOrbiterE) + RotL64(aOrbiterC, 48U)) + aNonceWordG);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 60U));
            aCarry = aCarry + (RotL64(aWandererJ, 11U) ^ aWandererG);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 29U));
            aCarry = aCarry + (RotL64(aWandererD, 19U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererF, 5U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererI, 54U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 2
        // ingress from: aOperationLaneA, aExpandLaneC, aWorkLaneC
        // ingress directions: aOperationLaneA forward forced, aExpandLaneC forward forced, aWorkLaneC forward/backward random
        // cross from: aExpandLaneA, aExpandLaneD, aWorkLaneD
        // cross directions: aExpandLaneA backward forced, aExpandLaneD backward forced, aWorkLaneD backward/forward random
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 8833U)) & S_BLOCK1], 60U) ^ RotL64(aExpandLaneC[((aIndex + 11816U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 15279U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 14690U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 10940U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 14735U)) & S_BLOCK1], 58U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCross, 11U) + RotL64(aIngress, 57U)) ^ (RotL64(aPrevious, 24U) + RotL64(aCarry, 37U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterD = (aWandererF + RotL64(aCross, 6U)) + 1364174714924216027U;
            aOrbiterI = ((aWandererH + RotL64(aScatter, 37U)) + 13561796874229506613U) + aNonceWordM;
            aOrbiterE = (((aWandererD + RotL64(aPrevious, 57U)) + RotL64(aCarry, 3U)) + 11845572344206238305U) + aNonceWordK;
            aOrbiterG = (aWandererK + RotL64(aIngress, 43U)) + 15762708240326773763U;
            aOrbiterB = ((aWandererB + RotL64(aScatter, 53U)) + 1157119665207900473U) + aOrbiterAssignSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterK = (aWandererI + RotL64(aCross, 13U)) + 6823546624372055260U;
            aOrbiterC = (aWandererC + RotL64(aIngress, 35U)) + 14465564210523945121U;
            aOrbiterA = (aWandererE + RotL64(aPrevious, 39U)) + 10667464548080807531U;
            aOrbiterF = ((aWandererJ + RotL64(aIngress, 28U)) + RotL64(aCarry, 47U)) + 13445737493224316575U;
            aOrbiterH = ((aWandererG + RotL64(aScatter, 51U)) + 3009837893785957665U) + aOrbiterAssignSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterJ = ((aWandererA + RotL64(aCross, 3U)) + RotL64(aCarry, 27U)) + 2886920524111083752U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 10886177449328249656U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 15067759884678100433U;
            aOrbiterE = RotL64((aOrbiterE * 5724566815989860041U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 18307930462682331536U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 8791864377579255801U;
            aOrbiterK = RotL64((aOrbiterK * 9265158882471421767U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 805797468642992351U) + aOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 5743305867058244964U;
            aOrbiterG = RotL64((aOrbiterG * 16263000753351131717U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 17102025528234481273U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 1841579177327486899U;
            aOrbiterH = RotL64((aOrbiterH * 3841603385577825265U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 2189493507896508972U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 18209567010094914374U;
            aOrbiterJ = RotL64((aOrbiterJ * 3737080408976852351U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 6697069234216868330U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 927471474577415372U;
            aOrbiterB = RotL64((aOrbiterB * 10680760991009199309U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 13155854301197725408U) + aNonceWordL;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 1014625081915435892U;
            aOrbiterI = RotL64((aOrbiterI * 11592754232949990435U), 37U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 12697209921410914931U) + aOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 11555096613655648647U;
            aOrbiterC = RotL64((aOrbiterC * 4598821388864997089U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 9335308231651271690U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 3160859883353473444U;
            aOrbiterA = RotL64((aOrbiterA * 4753600703924906409U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 15681189182414315768U) + aOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 3147692210581710663U) ^ aNonceWordH;
            aOrbiterD = RotL64((aOrbiterD * 6271949093080510861U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 5373388632562432117U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 1364174714924216027U;
            aOrbiterF = RotL64((aOrbiterF * 4694926665965807945U), 43U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterA, 26U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 43U));
            aIngress = aIngress + (RotL64(aOrbiterH, 53U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 47U));
            aIngress = aIngress + (RotL64(aOrbiterK, 57U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterI, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aCross, 51U) + aOrbiterB) + RotL64(aOrbiterH, 14U)) + aNonceWordB);
            aWandererC = aWandererC + ((RotL64(aScatter, 57U) + RotL64(aOrbiterD, 21U)) + aOrbiterJ);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterA, 53U)) + aOrbiterG);
            aWandererB = aWandererB + (((RotL64(aIngress, 3U) + aOrbiterH) + RotL64(aOrbiterI, 35U)) + aNonceWordC);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 47U) + aOrbiterK) + RotL64(aOrbiterE, 47U)) + aWandererUpdateSaltC[((aIndex + 19U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 40U) + aOrbiterB) + RotL64(aOrbiterF, 37U)) + aNonceWordA);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterK, 43U)) + aOrbiterA) + aNonceWordJ);
            aWandererD = aWandererD + (((RotL64(aCross, 27U) + aOrbiterC) + RotL64(aOrbiterJ, 27U)) + RotL64(aCarry, 21U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 11U) + aOrbiterF) + RotL64(aOrbiterC, 56U));
            aWandererH = aWandererH + (((RotL64(aScatter, 19U) + RotL64(aOrbiterG, 19U)) + aOrbiterB) + RotL64(aCarry, 13U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 30U) + aOrbiterC) + RotL64(aOrbiterK, 23U)) + aWandererUpdateSaltA[((aIndex + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 30U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 35U));
            aCarry = aCarry + (RotL64(aWandererE, 23U) ^ aWandererK);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 41U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 60U));
            aCarry = aCarry + RotL64(aWandererD, 51U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aOperationLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 3
        // ingress from: aOperationLaneB, aExpandLaneD, aFireLaneC
        // ingress directions: aOperationLaneB forward forced, aExpandLaneD forward forced, aFireLaneC forward/backward random
        // cross from: aOperationLaneA, aExpandLaneB, aWorkLaneA
        // cross directions: aOperationLaneA backward forced, aExpandLaneB backward forced, aWorkLaneA backward/forward random
        // write to: aOperationLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneB[((aIndex + 17773U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneD[((aIndex + 22207U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 23894U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 23180U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 19332U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19743U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aPrevious, 23U) ^ RotL64(aCarry, 58U)) ^ (RotL64(aIngress, 11U) + RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterA = ((aWandererA + RotL64(aPrevious, 51U)) + 17081642665820489793U) + aNonceWordM;
            aOrbiterF = (aWandererE + RotL64(aScatter, 27U)) + 14468854040067229623U;
            aOrbiterH = ((aWandererJ + RotL64(aIngress, 47U)) + 2249450222593057429U) + aOrbiterAssignSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterD = ((aWandererI + RotL64(aCross, 57U)) + 14964389079511378664U) + aNonceWordA;
            aOrbiterJ = (aWandererC + RotL64(aPrevious, 3U)) + 17003491054252360650U;
            aOrbiterE = (((aWandererB + RotL64(aScatter, 42U)) + 12710882240582032588U) + aOrbiterAssignSaltA[((aIndex + 10U)) & S_SALT1]) + aNonceWordK;
            aOrbiterI = (aWandererD + RotL64(aCross, 37U)) + 9887078182156755359U;
            aOrbiterB = ((aWandererH + RotL64(aIngress, 5U)) + RotL64(aCarry, 41U)) + 7665284531810584704U;
            aOrbiterC = ((aWandererG + RotL64(aPrevious, 19U)) + RotL64(aCarry, 21U)) + 7304284015511876717U;
            aOrbiterG = ((aWandererK + RotL64(aCross, 23U)) + 5517927023543751734U) + aNonceWordC;
            aOrbiterK = ((aWandererF + RotL64(aScatter, 30U)) + RotL64(aCarry, 13U)) + 17704756310857362759U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 11347400363019508578U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 11696395232760991243U;
            aOrbiterH = RotL64((aOrbiterH * 9725231749679442003U), 37U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 10875780291242873583U) + aNonceWordN;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 7808740614343437672U;
            aOrbiterJ = RotL64((aOrbiterJ * 8889516201913716283U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 3145390996141902032U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 16080636485642732615U;
            aOrbiterB = RotL64((aOrbiterB * 7445756373012217305U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 3929263288176983844U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterC) ^ 18210228766683996806U) ^ aOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterI = RotL64((aOrbiterI * 13178080076505449091U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 13948962323541421431U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 3037683309790156893U;
            aOrbiterC = RotL64((aOrbiterC * 13406672352222636739U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 17827265198532699474U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 7270895262023504864U;
            aOrbiterF = RotL64((aOrbiterF * 13467417362477308167U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 6431243064980879185U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 6680205390976259885U) ^ aOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 10421386694108590789U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 15910655919164357152U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 8046213498216027383U) ^ aOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 18061867495824063553U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 2521111689480478597U) + aNonceWordG;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 13892876610454681741U;
            aOrbiterA = RotL64((aOrbiterA * 17776392934374483875U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 16009217514890880809U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 1221573458193626679U;
            aOrbiterD = RotL64((aOrbiterD * 73477765605619369U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 9275704218554025797U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 17081642665820489793U;
            aOrbiterG = RotL64((aOrbiterG * 5613316790159527375U), 47U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterJ, 48U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 21U));
            aIngress = aIngress + (RotL64(aOrbiterF, 19U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterC, 35U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 23U));
            aIngress = aIngress + RotL64(aOrbiterG, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aScatter, 23U) + RotL64(aOrbiterJ, 60U)) + aOrbiterB) + aWandererUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 42U) + aOrbiterB) + RotL64(aOrbiterH, 51U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 21U) + aOrbiterJ) + RotL64(aOrbiterA, 43U)) + RotL64(aCarry, 57U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 51U) + aOrbiterJ) + RotL64(aOrbiterI, 39U));
            aWandererK = aWandererK + ((((RotL64(aCross, 53U) + aOrbiterI) + RotL64(aOrbiterH, 19U)) + RotL64(aCarry, 51U)) + aNonceWordJ);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterG, 13U)) + aOrbiterB) + aWandererUpdateSaltD[((aIndex + 21U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 47U) + aOrbiterJ) + RotL64(aOrbiterK, 34U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 29U) + aOrbiterC) + RotL64(aOrbiterF, 41U));
            aWandererF = aWandererF + ((RotL64(aPrevious, 35U) + aOrbiterC) + RotL64(aOrbiterI, 29U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 5U) + aOrbiterD) + RotL64(aOrbiterK, 5U));
            aWandererH = aWandererH + (((RotL64(aIngress, 44U) + RotL64(aOrbiterE, 53U)) + aOrbiterJ) + aNonceWordD);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 18U));
            aCarry = aCarry + (RotL64(aWandererK, 21U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererJ, 35U) ^ aWandererF);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 51U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 44U));
            aCarry = aCarry + RotL64(aWandererD, 41U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 32553U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneA[((aIndex + 25089U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 29808U)) & S_BLOCK1], 36U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 30190U)) & S_BLOCK1], 50U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 32275U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 28857U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCarry, 60U) + RotL64(aPrevious, 27U)) ^ (RotL64(aIngress, 47U) ^ RotL64(aCross, 11U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterH = ((aWandererB + RotL64(aIngress, 29U)) + 7790166497945719700U) + aOrbiterAssignSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterJ = (aWandererI + RotL64(aScatter, 47U)) + 7136208896846119188U;
            aOrbiterA = ((aWandererF + RotL64(aCross, 11U)) + 12123156943355100886U) + aNonceWordC;
            aOrbiterK = ((aWandererA + RotL64(aPrevious, 54U)) + RotL64(aCarry, 21U)) + 5095546037880875199U;
            aOrbiterB = (aWandererJ + RotL64(aIngress, 5U)) + 17642705393916765992U;
            aOrbiterI = (aWandererK + RotL64(aPrevious, 43U)) + 9918479837334416990U;
            aOrbiterG = (((aWandererD + RotL64(aScatter, 51U)) + 4890009823843176466U) + aOrbiterAssignSaltB[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordM;
            aOrbiterD = ((aWandererC + RotL64(aCross, 41U)) + 17652590786213674124U) + aNonceWordJ;
            aOrbiterF = (aWandererE + RotL64(aPrevious, 19U)) + 870002527644696135U;
            aOrbiterC = (((aWandererG + RotL64(aCross, 24U)) + RotL64(aCarry, 35U)) + 12545429703552643682U) + aNonceWordB;
            aOrbiterE = ((aWandererH + RotL64(aScatter, 21U)) + RotL64(aCarry, 57U)) + 5310272867406182581U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 3264719049050179440U) + aNonceWordE;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 1967241238180278937U;
            aOrbiterA = RotL64((aOrbiterA * 13004319774269457957U), 37U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 773883832927040736U) + aNonceWordO;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 12766817190261232485U) ^ aOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7448864556802318431U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 260069382395598265U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 15462103891287350123U;
            aOrbiterG = RotL64((aOrbiterG * 5029268763635635753U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 4072032867513289827U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 17153061419083897076U;
            aOrbiterB = RotL64((aOrbiterB * 11934532169271718913U), 53U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 6207264270332656966U) + aNonceWordF;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 18048064697837314947U;
            aOrbiterI = RotL64((aOrbiterI * 13632594619404208489U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 14484617445340272026U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 16160443600497652026U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 1988599349457831597U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 5873314228291583482U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 16418290052752166515U;
            aOrbiterJ = RotL64((aOrbiterJ * 18270363452003213317U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 9158414409987627714U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 8205937960146492168U;
            aOrbiterD = RotL64((aOrbiterD * 14008398661393344261U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 16386126219854809263U) + aOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 12418021156683187869U) ^ aOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13897930566207284517U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 5427232681451476584U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 18237670074497382745U;
            aOrbiterF = RotL64((aOrbiterF * 15528665160297906195U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 8330262458028468513U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 7790166497945719700U) ^ aNonceWordD;
            aOrbiterE = RotL64((aOrbiterE * 6001280767763971107U), 39U);
            //
            aIngress = RotL64(aOrbiterD, 22U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterA, 13U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 35U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 53U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 39U));
            aIngress = aIngress + RotL64(aOrbiterF, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterC, 27U)) + aOrbiterD);
            aWandererA = aWandererA + ((RotL64(aPrevious, 19U) + aOrbiterA) + RotL64(aOrbiterI, 52U));
            aWandererB = aWandererB ^ ((((RotL64(aScatter, 21U) + RotL64(aOrbiterF, 39U)) + aOrbiterG) + aNonceWordL) + aWandererUpdateSaltF[((aIndex + 29U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aIngress, 35U) + RotL64(aOrbiterC, 29U)) + aOrbiterF) + RotL64(aCarry, 3U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 13U) + aOrbiterJ) + RotL64(aOrbiterH, 57U)) + aNonceWordP);
            aWandererK = aWandererK + (((RotL64(aPrevious, 24U) + RotL64(aOrbiterI, 21U)) + aOrbiterE) + RotL64(aCarry, 29U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 11U) + aOrbiterA) + RotL64(aOrbiterG, 23U));
            aWandererF = aWandererF + (((RotL64(aCross, 29U) + aOrbiterJ) + RotL64(aOrbiterB, 3U)) + aWandererUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 41U) + aOrbiterB) + RotL64(aOrbiterK, 5U));
            aWandererG = aWandererG + ((RotL64(aIngress, 56U) + RotL64(aOrbiterD, 12U)) + aOrbiterB);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 27U) + aOrbiterC) + RotL64(aOrbiterG, 43U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 48U) ^ aWandererK);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 53U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 43U));
            aCarry = aCarry + (RotL64(aWandererE, 21U) ^ aWandererJ);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 57U));
            aCarry = aCarry + RotL64(aWandererH, 39U);
            aCarry = aCarry + RotL64(aIngress, 14U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xD0F408E980AE84D5ULL + 0xA23EA004F0791E4DULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xEAD77F0BFF0FB759ULL + 0xF638498194CE2C5FULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x8FA5ACAE5323BFADULL + 0xBC9233B42E80230EULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xD32485489FF4B59DULL + 0xF3332222C0B22558ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xF8136320F13C314FULL + 0xA94D5B2EDD9D9E93ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xE0B1560B9666C74FULL + 0xAE8225309319F9C8ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xF29E8F48AB61B917ULL + 0xCA5CE25EB93ED52FULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xDF979E077131D8C7ULL + 0xDF69A2F42C466AC7ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xCFE172050A93E1A9ULL + 0xA9D1949F9A95756AULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xE9F6FA4945E45589ULL + 0xFFB796E242A00C98ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xFE114365E610A18DULL + 0xE6DF2E53795DF045ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xAFB4FF91D0770D8DULL + 0xE2924CB533488DB9ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0x9F14C572EDCB2023ULL + 0xBF174CD9AF5261FDULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xEEDC5861E9DFB9C3ULL + 0xB68DFEC4A3BAF14FULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xDB4D711FE5792565ULL + 0xD49B45A855855380ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xDD088E6A08014FC1ULL + 0xCA3DD050E2A3D146ULL);
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
        // read from: aOperationLaneA, aOperationLaneB, aWorkLaneC, aOperationLaneC, aOperationLaneD, aWorkLaneA, aExpandLaneA, aFireLaneB, aFireLaneC, aExpandLaneB, aWorkLaneD, aFireLaneA, aExpandLaneC, aFireLaneD, aWorkLaneB
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_c loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aWorkLaneC
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aWorkLaneC forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aWorkLaneA
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aWorkLaneA backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 5884U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneB[((aIndex + 3600U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 983U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 48U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 1392U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 811U)) & S_BLOCK1], 24U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCross, 38U) ^ RotL64(aIngress, 11U)) + (RotL64(aCarry, 23U) ^ RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterD = (aWandererI + RotL64(aScatter, 47U)) + 12206125048349568300U;
            aOrbiterJ = (aWandererJ + RotL64(aIngress, 53U)) + 5843520589343188818U;
            aOrbiterB = (aWandererD + RotL64(aPrevious, 29U)) + 12195046124287121687U;
            aOrbiterA = ((aWandererG + RotL64(aCross, 14U)) + 16769779119214020640U) + aOrbiterAssignSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = ((aWandererC + RotL64(aIngress, 23U)) + RotL64(aCarry, 3U)) + 5257603646260695833U;
            aOrbiterF = ((aWandererF + RotL64(aCross, 57U)) + 8523523946234886745U) + aOrbiterAssignSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterE = (((aWandererH + RotL64(aPrevious, 3U)) + RotL64(aCarry, 13U)) + 7316024684200084096U) + aNonceWordE;
            aOrbiterG = ((aWandererE + RotL64(aScatter, 37U)) + RotL64(aCarry, 37U)) + 11996978575084115207U;
            aOrbiterI = ((aWandererA + RotL64(aCross, 18U)) + 15491711479085513628U) + aNonceWordN;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 6036648530996821484U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 926323222234121863U;
            aOrbiterB = RotL64((aOrbiterB * 6639661141258803779U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 2700323841295743492U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 5852273765810284935U;
            aOrbiterC = RotL64((aOrbiterC * 16665696735016345215U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 11697397483133538067U) + aNonceWordD;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 17777142964957007194U) ^ aNonceWordP;
            aOrbiterE = RotL64((aOrbiterE * 6338967222543284999U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 10892176201151170298U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 11759700374509499684U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 14247697264744736081U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 11343756773329590643U) + aOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 15785048929757652350U;
            aOrbiterI = RotL64((aOrbiterI * 17208103574389502597U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 7508839228498497238U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 13088508510402094665U;
            aOrbiterJ = RotL64((aOrbiterJ * 15730279447009669103U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 16259236641717377699U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 11228995722951003980U) ^ aNonceWordA;
            aOrbiterA = RotL64((aOrbiterA * 4870092259515181323U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 13775851561528617086U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 3023564646900497080U;
            aOrbiterF = RotL64((aOrbiterF * 9936548213275464131U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 154952467284609583U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 14239675888632174461U;
            aOrbiterD = RotL64((aOrbiterD * 1370550680736926425U), 37U);
            //
            aIngress = RotL64(aOrbiterD, 43U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterE, 50U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 3U));
            aIngress = aIngress + (RotL64(aOrbiterI, 23U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterF, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aIngress, 39U) + RotL64(aOrbiterG, 48U)) + aOrbiterA) + RotL64(aCarry, 21U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 43U) + aOrbiterC) + RotL64(aOrbiterE, 41U));
            aWandererI = aWandererI + (((RotL64(aCross, 24U) + RotL64(aOrbiterB, 19U)) + aOrbiterF) + RotL64(aCarry, 13U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 57U) + aOrbiterG) + RotL64(aOrbiterJ, 23U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 13U) + aOrbiterI) + RotL64(aOrbiterD, 53U)) + aNonceWordL);
            aWandererF = aWandererF ^ ((((RotL64(aScatter, 35U) + RotL64(aOrbiterI, 57U)) + aOrbiterF) + aNonceWordM) + aWandererUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 18U) + RotL64(aOrbiterG, 11U)) + aOrbiterC) + aWandererUpdateSaltC[((aIndex + 26U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 53U) + aOrbiterE) + RotL64(aOrbiterF, 34U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterD, 27U)) + aOrbiterB) + aNonceWordG);
            //
            aCarry = aCarry + (RotL64(aWandererD, 19U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererG, 53U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererI, 23U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererE, 26U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererH, 57U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 2
        // ingress from: aExpandLaneA, aOperationLaneC, aFireLaneB
        // ingress directions: aExpandLaneA forward forced, aOperationLaneC forward forced, aFireLaneB forward/backward random
        // cross from: aOperationLaneA, aOperationLaneD, aFireLaneC
        // cross directions: aOperationLaneA backward forced, aOperationLaneD backward forced, aFireLaneC backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 9697U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneC[((aIndex + 11756U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 10636U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 10273U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 9508U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aFireLaneC[((aIndex + 13923U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCarry, 34U) + RotL64(aIngress, 21U)) ^ (RotL64(aPrevious, 3U) ^ RotL64(aCross, 47U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterK = (aWandererA + RotL64(aIngress, 23U)) + 9654059367478508868U;
            aOrbiterJ = (((aWandererK + RotL64(aCross, 13U)) + RotL64(aCarry, 3U)) + 6473006635864677427U) + aNonceWordB;
            aOrbiterB = ((((aWandererG + RotL64(aScatter, 56U)) + RotL64(aCarry, 57U)) + 6944184481315853243U) + aOrbiterAssignSaltB[((aIndex + 17U)) & S_SALT1]) + aNonceWordK;
            aOrbiterG = (aWandererJ + RotL64(aPrevious, 5U)) + 4061496421939102306U;
            aOrbiterF = ((aWandererC + RotL64(aScatter, 27U)) + 15791809275719085463U) + aNonceWordO;
            aOrbiterE = ((aWandererI + RotL64(aCross, 51U)) + 14050798802646323055U) + aOrbiterAssignSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterD = (aWandererF + RotL64(aPrevious, 46U)) + 12072905924741758266U;
            aOrbiterC = ((aWandererB + RotL64(aIngress, 39U)) + RotL64(aCarry, 13U)) + 17639076509231343896U;
            aOrbiterA = ((aWandererD + RotL64(aPrevious, 19U)) + 12195388285571234715U) + aNonceWordI;
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 4325404419499496529U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 5910567888204238382U;
            aOrbiterB = RotL64((aOrbiterB * 11503787177122206937U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 13092940059929942699U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 13381962590820308761U;
            aOrbiterE = RotL64((aOrbiterE * 6345904465930943295U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 15622862439323440527U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 14027151901132249793U;
            aOrbiterC = RotL64((aOrbiterC * 2273573821630510087U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 4584410023907605157U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 15763755180625487157U;
            aOrbiterK = RotL64((aOrbiterK * 6755736130607297639U), 39U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 17023059745666559199U) + aOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 5298529579288492971U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2483562793328357721U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 2870152867331654736U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 12017191100173748848U;
            aOrbiterF = RotL64((aOrbiterF * 9958191466506480519U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 15899529176182436062U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 16482713846343388735U;
            aOrbiterD = RotL64((aOrbiterD * 719465695044265601U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 12943393531812774449U) + aNonceWordM;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 9881108254540483225U) ^ aNonceWordN;
            aOrbiterG = RotL64((aOrbiterG * 8011108108007885059U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 3532054586199716750U) + aNonceWordC;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 7142230313294797435U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 14154176174768868421U), 27U);
            //
            aIngress = RotL64(aOrbiterK, 35U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 29U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 47U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 43U));
            aIngress = aIngress + RotL64(aOrbiterG, 12U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aScatter, 3U) + aOrbiterG) + RotL64(aOrbiterF, 29U));
            aWandererF = aWandererF + (((RotL64(aCross, 43U) + RotL64(aOrbiterB, 13U)) + aOrbiterG) + aNonceWordE);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 51U) + aOrbiterB) + RotL64(aOrbiterE, 23U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 18U) + aOrbiterK) + RotL64(aOrbiterJ, 54U)) + RotL64(aCarry, 27U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 27U) + aOrbiterE) + RotL64(aOrbiterC, 3U)) + aWandererUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 23U) + aOrbiterE) + RotL64(aOrbiterJ, 39U)) + RotL64(aCarry, 57U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 39U) + aOrbiterC) + RotL64(aOrbiterA, 35U));
            aWandererC = aWandererC + (((RotL64(aIngress, 14U) + RotL64(aOrbiterF, 60U)) + aOrbiterA) + aNonceWordF);
            aWandererK = aWandererK ^ ((((RotL64(aCross, 57U) + aOrbiterD) + RotL64(aOrbiterK, 19U)) + aNonceWordL) + aWandererUpdateSaltE[((aIndex + 20U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererA, 29U) ^ aWandererF);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 13U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 26U));
            aCarry = aCarry + RotL64(aWandererB, 43U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 21413U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneD[((aIndex + 22348U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 16388U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 20987U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 24019U)) & S_BLOCK1], 24U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 22756U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aPrevious, 53U) + RotL64(aCarry, 24U)) + (RotL64(aIngress, 37U) ^ RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterK = (((aWandererF + RotL64(aPrevious, 6U)) + RotL64(aCarry, 13U)) + 12027839670755583592U) + aOrbiterAssignSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterJ = ((aWandererK + RotL64(aCross, 35U)) + 15380130703509859843U) + aNonceWordE;
            aOrbiterC = ((aWandererI + RotL64(aScatter, 57U)) + RotL64(aCarry, 57U)) + 4590907433867798074U;
            aOrbiterH = ((aWandererG + RotL64(aIngress, 51U)) + RotL64(aCarry, 21U)) + 1754574023602519724U;
            aOrbiterD = (aWandererJ + RotL64(aCross, 19U)) + 9832756659564903767U;
            aOrbiterA = (aWandererC + RotL64(aIngress, 13U)) + 5035088494491470403U;
            aOrbiterG = ((aWandererD + RotL64(aPrevious, 23U)) + 14199170923323644638U) + aOrbiterAssignSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterI = ((aWandererH + RotL64(aScatter, 39U)) + 8325619421264440438U) + aNonceWordI;
            aOrbiterE = (aWandererB + RotL64(aCross, 46U)) + 969534320779067977U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 270575869402913847U) + aNonceWordN;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 13344806516599578910U;
            aOrbiterC = RotL64((aOrbiterC * 10193544126281901579U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 15143147951139409101U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 14425582489214169238U) ^ aOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 16893787086337916355U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 13951127523239064584U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 14177925225918293579U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13079514031864998485U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 8258920744278218901U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 7408161179397242453U;
            aOrbiterH = RotL64((aOrbiterH * 975737128100519169U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 8581481606764773468U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 10078416198417433133U;
            aOrbiterI = RotL64((aOrbiterI * 1102721083915858247U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 18299772198826189580U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 18304668908084397946U) ^ aNonceWordF;
            aOrbiterK = RotL64((aOrbiterK * 10589455451200578687U), 39U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 16729632621573817223U) + aNonceWordL;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 13362300981585573239U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 9824473895535518785U), 21U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 8629682832849915380U) + aNonceWordA;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 6852852009091469641U;
            aOrbiterE = RotL64((aOrbiterE * 11912646687050011915U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 7433098156961745198U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 10931806208899417308U;
            aOrbiterG = RotL64((aOrbiterG * 14699197041038067483U), 27U);
            //
            aIngress = RotL64(aOrbiterD, 20U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterA, 37U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 3U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 29U));
            aIngress = aIngress + RotL64(aOrbiterH, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 51U) + aOrbiterE) + RotL64(aOrbiterC, 6U));
            aWandererH = aWandererH + (((RotL64(aIngress, 47U) + aOrbiterJ) + RotL64(aOrbiterE, 37U)) + aWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 5U) + aOrbiterA) + RotL64(aOrbiterD, 57U)) + aNonceWordO);
            aWandererG = aWandererG + ((((RotL64(aCross, 30U) + RotL64(aOrbiterC, 27U)) + aOrbiterJ) + RotL64(aCarry, 11U)) + aWandererUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterK, 19U)) + aOrbiterI);
            aWandererC = aWandererC + (((RotL64(aIngress, 23U) + aOrbiterD) + RotL64(aOrbiterH, 43U)) + aNonceWordH);
            aWandererF = aWandererF ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterI, 23U)) + aOrbiterE) + aNonceWordK);
            aWandererD = aWandererD + (((RotL64(aPrevious, 57U) + aOrbiterH) + RotL64(aOrbiterA, 13U)) + RotL64(aCarry, 41U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 42U) + RotL64(aOrbiterC, 52U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererI, 57U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererG, 60U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererD, 23U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererB, 47U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererH, 19U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aFireLaneD
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aFireLaneD forward/backward random
        // cross from: aExpandLaneB, aOperationLaneC, aWorkLaneB
        // cross directions: aExpandLaneB backward forced, aOperationLaneC backward forced, aWorkLaneB backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 30893U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneA[((aIndex + 28645U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 29804U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31445U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 30967U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 30068U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCross, 29U) + RotL64(aIngress, 53U)) + (RotL64(aPrevious, 41U) ^ RotL64(aCarry, 6U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterB = (((aWandererI + RotL64(aScatter, 3U)) + RotL64(aCarry, 29U)) + 964165145848253292U) + aNonceWordD;
            aOrbiterF = ((aWandererE + RotL64(aCross, 10U)) + 10645976767204934746U) + aNonceWordG;
            aOrbiterK = ((aWandererC + RotL64(aPrevious, 19U)) + RotL64(aCarry, 21U)) + 8241612229349212650U;
            aOrbiterE = ((aWandererB + RotL64(aIngress, 39U)) + RotL64(aCarry, 53U)) + 4159196033256913347U;
            aOrbiterC = ((aWandererD + RotL64(aCross, 27U)) + 7194795864620233507U) + aNonceWordC;
            aOrbiterJ = (aWandererK + RotL64(aScatter, 47U)) + 7638928444536778384U;
            aOrbiterD = (aWandererF + RotL64(aPrevious, 60U)) + 11819105916503968109U;
            aOrbiterH = ((aWandererH + RotL64(aIngress, 51U)) + 18052213302858186237U) + aOrbiterAssignSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterA = ((aWandererJ + RotL64(aPrevious, 35U)) + 8663575313970041570U) + aOrbiterAssignSaltC[((aIndex + 6U)) & S_SALT1];
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 16644136720439299786U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 16930316530442679864U;
            aOrbiterK = RotL64((aOrbiterK * 2650922074098320859U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 16251107616988250593U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 7171986193609401665U;
            aOrbiterC = RotL64((aOrbiterC * 3543709971414550087U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 17885046834432626644U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 7757069274715713557U) ^ aOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 15766885299397923879U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 2212805322061155615U) + aNonceWordB;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 6368539134638838822U) ^ aNonceWordJ;
            aOrbiterE = RotL64((aOrbiterE * 13383744883433594259U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 5264326094252925613U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 6126345334815012938U;
            aOrbiterF = RotL64((aOrbiterF * 17180934809764905307U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 13826731214018407061U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 6621261811613643620U) ^ aOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2823596473596114171U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 5964406317285863781U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 2167324450276308078U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 1098346374733634905U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 16740710162977859724U) + aNonceWordK;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 8236083581048717923U;
            aOrbiterA = RotL64((aOrbiterA * 4364887787000704039U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 13967473987446124012U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 5136051802217149813U;
            aOrbiterD = RotL64((aOrbiterD * 13997246005108872883U), 39U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterA, 23U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 19U));
            aIngress = aIngress + (RotL64(aOrbiterH, 36U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterE, 3U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterC, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aPrevious, 56U) + RotL64(aOrbiterJ, 19U)) + aOrbiterH) + aNonceWordN);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterH, 37U)) + aOrbiterE);
            aWandererD = aWandererD + ((((RotL64(aScatter, 13U) + RotL64(aOrbiterA, 47U)) + aOrbiterJ) + RotL64(aCarry, 41U)) + aNonceWordI);
            aWandererI = aWandererI ^ ((RotL64(aCross, 43U) + aOrbiterD) + RotL64(aOrbiterB, 52U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 48U) + RotL64(aOrbiterF, 29U)) + aOrbiterD) + aNonceWordL);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 39U) + aOrbiterE) + RotL64(aOrbiterC, 41U));
            aWandererE = aWandererE + ((((RotL64(aCross, 3U) + aOrbiterB) + RotL64(aOrbiterH, 23U)) + aNonceWordE) + aWandererUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterA, 57U)) + aOrbiterE);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 29U) + aOrbiterK) + RotL64(aOrbiterB, 6U)) + RotL64(aCarry, 53U)) + aWandererUpdateSaltC[((aIndex + 10U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 51U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 54U));
            aCarry = aCarry + (RotL64(aWandererK, 11U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererF, 27U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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

void TwistExpander_PickleBall_Arx::KDF_B_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xD6D862BD217BBB1BULL + 0x9EBB0D50CB232EC6ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xEBBF05EAB217BD41ULL + 0xFA8156CF9B8686D1ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xFDFF75B99627620DULL + 0xBD59EB47EC48F11CULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x91DEA1359D72F2EBULL + 0x99C6407E36246D0AULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xF73247E1B48D1CB7ULL + 0xBB3A19BB2A956532ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x986A94AC40ACFAE5ULL + 0xAEB9BDCCA0990546ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xA45173EF47530E5FULL + 0xF39C28B1F11B282AULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xE5514D57BCAD42FBULL + 0xC3DE03759DCD79A6ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xE08E1273E4814ED1ULL + 0xE697C243A89F845FULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xCAF73808723BA183ULL + 0xC9B901D344155F6BULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xF5B7A7CF0B2D4ECFULL + 0xDEB4550F8A16F95DULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0x99BDF553601992DFULL + 0x9CD3837ECC8112F9ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x835F87FB49834887ULL + 0xF08F091CF85151FBULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x9A4589ABC3A762F9ULL + 0x948E7DBA6122BDC7ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x800126D8F937D24BULL + 0xC885960D5248B97FULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xEF10FD1DDEC344FDULL + 0xC4CF91D2BC5BD97AULL);
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
        // read from: aWorkLaneA, aWorkLaneB, aFireLaneD, aWorkLaneC, aWorkLaneD, aOperationLaneA, aExpandLaneA, aFireLaneC, aOperationLaneB, aExpandLaneB, aOperationLaneC, aFireLaneB, aExpandLaneC, aFireLaneA, aOperationLaneD
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 4572U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneB[((aIndex + 1663U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 527U)) & S_BLOCK1], 38U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 3982U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 7546U)) & S_BLOCK1], 48U));
            aCross ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 228U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aIngress, 23U) ^ RotL64(aCross, 38U)) ^ (RotL64(aCarry, 53U) + RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterF = (aWandererE + RotL64(aCross, 60U)) + 13174219512651137892U;
            aOrbiterD = (((aWandererH + RotL64(aIngress, 23U)) + 2715455762789269341U) + aOrbiterAssignSaltE[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordI;
            aOrbiterH = (aWandererJ + RotL64(aScatter, 29U)) + 1338018183235594313U;
            aOrbiterJ = ((aWandererG + RotL64(aPrevious, 53U)) + RotL64(aCarry, 39U)) + 16566866551729552930U;
            aOrbiterC = (((aWandererA + RotL64(aIngress, 47U)) + RotL64(aCarry, 21U)) + 6901845297307236726U) + aNonceWordP;
            aOrbiterI = (aWandererF + RotL64(aCross, 3U)) + 2476078302049201718U;
            aOrbiterA = (((aWandererI + RotL64(aScatter, 37U)) + RotL64(aCarry, 57U)) + 15531109473927052260U) + aOrbiterAssignSaltA[((aIndex + 12U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 4087849380858572351U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 5167830630098599644U;
            aOrbiterH = RotL64((aOrbiterH * 1982835131228146099U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 7275995452428627217U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 14794340370010024117U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8779497557416568379U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 8509217403041662849U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 2321522025240806996U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 113568101672878697U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 5676672952755594051U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 2304681269233504384U;
            aOrbiterD = RotL64((aOrbiterD * 15731441084605554497U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 8383399721062437300U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 13181984036942227666U) ^ aNonceWordC;
            aOrbiterF = RotL64((aOrbiterF * 1648761328771932069U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 13602604532551684210U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 12725687663616352843U) ^ aOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4684699861686199753U), 35U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterH) + 5831790822416009806U) + aOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1]) + aNonceWordN;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 4535048543735457407U;
            aOrbiterA = RotL64((aOrbiterA * 12076777878870257053U), 53U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterC, 13U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 58U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 29U));
            aIngress = aIngress + RotL64(aOrbiterH, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aScatter, 58U) + RotL64(aOrbiterD, 3U)) + aOrbiterF) + aNonceWordE);
            aWandererH = aWandererH ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterC, 57U)) + aOrbiterH) + aWandererUpdateSaltC[((aIndex + 7U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 41U) + aOrbiterI) + RotL64(aOrbiterH, 13U)) + RotL64(aCarry, 37U)) + aWandererUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 51U) + aOrbiterF) + RotL64(aOrbiterA, 43U)) + aNonceWordH);
            aWandererG = aWandererG + (((RotL64(aCross, 13U) + aOrbiterH) + RotL64(aOrbiterJ, 37U)) + RotL64(aCarry, 19U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 3U) + aOrbiterF) + RotL64(aOrbiterJ, 29U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 29U) + aOrbiterJ) + RotL64(aOrbiterA, 20U)) + aNonceWordL);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 35U));
            aCarry = aCarry + (RotL64(aWandererA, 50U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererH, 27U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererJ, 57U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 10436U)) & S_BLOCK1], 12U) ^ RotL64(aWorkLaneC[((aIndex + 13228U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 15375U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 10292U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 9087U)) & S_BLOCK1], 18U));
            aCross ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 14790U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aPrevious, 41U) ^ RotL64(aCross, 54U)) + (RotL64(aIngress, 27U) ^ RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterJ = (aWandererK + RotL64(aIngress, 3U)) + 77518479758428414U;
            aOrbiterC = (aWandererH + RotL64(aCross, 47U)) + 4832061802166300011U;
            aOrbiterF = ((aWandererI + RotL64(aPrevious, 19U)) + RotL64(aCarry, 57U)) + 11695291171006574112U;
            aOrbiterG = (((aWandererJ + RotL64(aScatter, 53U)) + 7467412817843260094U) + aOrbiterAssignSaltF[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterA = ((aWandererE + RotL64(aCross, 60U)) + 17801484124471154757U) + aOrbiterAssignSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterK = (((aWandererA + RotL64(aIngress, 11U)) + RotL64(aCarry, 27U)) + 5555455638503958639U) + aNonceWordL;
            aOrbiterB = (((aWandererF + RotL64(aScatter, 27U)) + RotL64(aCarry, 41U)) + 5669470540733721606U) + aNonceWordK;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 3042388456327784163U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 2236734925228156691U;
            aOrbiterF = RotL64((aOrbiterF * 10076582424701705531U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 14459720401528685450U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 4814967631216658856U) ^ aNonceWordD;
            aOrbiterA = RotL64((aOrbiterA * 18288097536171386643U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 16950679344449075945U) + aNonceWordF;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 6262238639302011050U) ^ aOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 9942659897425088183U), 39U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 3522256359074996724U) + aNonceWordN;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 12524717897707074242U;
            aOrbiterB = RotL64((aOrbiterB * 6787771338063891989U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 13891759914865623828U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 11910250571469028666U) ^ aOrbiterUpdateSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 12311343917878428995U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 2240189915640314069U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 5365912986308810837U;
            aOrbiterK = RotL64((aOrbiterK * 15133972552032469957U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 9323732721344489753U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 13087326560957916553U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14659491687401151733U), 19U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterF, 3U);
            aIngress = aIngress + (RotL64(aOrbiterB, 47U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterJ, 34U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterK, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aCross, 3U) + RotL64(aOrbiterB, 57U)) + aOrbiterA) + RotL64(aCarry, 51U));
            aWandererH = aWandererH ^ ((((RotL64(aIngress, 13U) + RotL64(aOrbiterC, 5U)) + aOrbiterJ) + aNonceWordM) + aWandererUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 53U) + RotL64(aOrbiterG, 48U)) + aOrbiterJ) + RotL64(aCarry, 35U)) + aNonceWordO);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterK, 19U)) + aOrbiterF);
            aWandererA = aWandererA + (((RotL64(aCross, 47U) + aOrbiterB) + RotL64(aOrbiterG, 11U)) + aNonceWordE);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 30U) + aOrbiterC) + RotL64(aOrbiterG, 35U));
            aWandererF = aWandererF + ((((RotL64(aPrevious, 19U) + aOrbiterG) + RotL64(aOrbiterF, 27U)) + aNonceWordI) + aWandererUpdateSaltD[((aIndex + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 4U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 11U));
            aCarry = aCarry + RotL64(aWandererK, 53U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 3
        // ingress from: aExpandLaneB, aWorkLaneD, aOperationLaneC
        // ingress directions: aExpandLaneB forward forced, aWorkLaneD forward forced, aOperationLaneC forward/backward random
        // cross from: aExpandLaneA, aWorkLaneB, aFireLaneB
        // cross directions: aExpandLaneA backward forced, aWorkLaneB backward forced, aFireLaneB backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 21661U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneD[((aIndex + 21667U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 24141U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 17882U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 24421U)) & S_BLOCK1], 26U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 23064U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCarry, 20U) ^ RotL64(aIngress, 53U)) ^ (RotL64(aPrevious, 39U) + RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterJ = (((aWandererG + RotL64(aScatter, 35U)) + RotL64(aCarry, 41U)) + 5131645209694953015U) + aNonceWordA;
            aOrbiterF = (((aWandererB + RotL64(aIngress, 42U)) + RotL64(aCarry, 53U)) + 12070391048835379854U) + aNonceWordJ;
            aOrbiterG = ((aWandererE + RotL64(aPrevious, 53U)) + RotL64(aCarry, 23U)) + 2604295836242338724U;
            aOrbiterA = ((aWandererK + RotL64(aCross, 21U)) + 14042039029284001596U) + aNonceWordK;
            aOrbiterI = ((aWandererF + RotL64(aIngress, 13U)) + 8914654543854559327U) + aNonceWordB;
            aOrbiterE = ((aWandererD + RotL64(aCross, 27U)) + 2185619407969359869U) + aOrbiterAssignSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterH = ((aWandererJ + RotL64(aScatter, 5U)) + 5187406295103352574U) + aOrbiterAssignSaltC[((aIndex + 21U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 8022832481290871217U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 8783061916740573472U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 3309891377744201773U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 10711028365596196301U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 13387065038269133571U;
            aOrbiterI = RotL64((aOrbiterI * 12444578026365205255U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 11187001318931801582U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 14191473173276034019U;
            aOrbiterF = RotL64((aOrbiterF * 2491253922434756431U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 16207761776716426435U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 9677408414452078760U) ^ aOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5487303383095129949U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 17812460332794370649U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 7736423148554132028U) ^ aNonceWordL;
            aOrbiterA = RotL64((aOrbiterA * 15588733747232852555U), 27U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 17293203944059014763U) + aNonceWordP;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 13487243633338010243U) ^ aOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 9468688858740539095U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 15979293016815060755U) + aNonceWordF;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 17645215484691359547U;
            aOrbiterE = RotL64((aOrbiterE * 1449450767288733995U), 51U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterJ, 29U);
            aIngress = aIngress + (RotL64(aOrbiterF, 35U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterG, 23U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterA, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 35U) + aOrbiterF) + RotL64(aOrbiterJ, 41U));
            aWandererK = aWandererK + (((RotL64(aCross, 41U) + RotL64(aOrbiterF, 14U)) + aOrbiterE) + RotL64(aCarry, 5U));
            aWandererJ = aWandererJ ^ ((((RotL64(aIngress, 19U) + aOrbiterE) + RotL64(aOrbiterA, 47U)) + aNonceWordG) + aWandererUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 60U) + RotL64(aOrbiterH, 5U)) + aOrbiterA) + aNonceWordI);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 3U) + aOrbiterJ) + RotL64(aOrbiterG, 27U));
            aWandererB = aWandererB + (((RotL64(aScatter, 47U) + RotL64(aOrbiterI, 35U)) + aOrbiterE) + RotL64(aCarry, 23U));
            aWandererG = aWandererG ^ ((((RotL64(aCross, 27U) + RotL64(aOrbiterI, 53U)) + aOrbiterH) + aNonceWordC) + aWandererUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 24U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 57U));
            aCarry = aCarry + (RotL64(aWandererD, 11U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererE, 51U);
            aCarry = aCarry + RotL64(aIngress, 36U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aFireLaneA
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aFireLaneA forward/backward random
        // cross from: aExpandLaneB, aWorkLaneC, aOperationLaneD
        // cross directions: aExpandLaneB backward forced, aWorkLaneC backward forced, aOperationLaneD backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 25584U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneA[((aIndex + 31652U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 29842U)) & S_BLOCK1], 20U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28015U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 26721U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 30602U)) & S_BLOCK1], 44U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCross, 23U) + RotL64(aPrevious, 40U)) ^ (RotL64(aIngress, 57U) ^ RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterK = ((aWandererK + RotL64(aScatter, 23U)) + 1142447269198373880U) + aOrbiterAssignSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterC = ((aWandererD + RotL64(aPrevious, 58U)) + 10581460640040336191U) + aOrbiterAssignSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterF = ((aWandererH + RotL64(aIngress, 41U)) + RotL64(aCarry, 39U)) + 14703062773878202900U;
            aOrbiterB = ((aWandererB + RotL64(aCross, 13U)) + 15737525756286914746U) + aNonceWordJ;
            aOrbiterE = ((aWandererF + RotL64(aPrevious, 35U)) + RotL64(aCarry, 27U)) + 16178774478273186999U;
            aOrbiterG = ((aWandererA + RotL64(aCross, 29U)) + 2514897053906809160U) + aNonceWordK;
            aOrbiterI = (((aWandererC + RotL64(aScatter, 3U)) + RotL64(aCarry, 11U)) + 13702496607592508464U) + aNonceWordE;
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 18030885275418337965U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 5241783876161655984U;
            aOrbiterF = RotL64((aOrbiterF * 10970981186787227937U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 2807052676283587925U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 8022804576763271327U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 11727096043219370577U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 15597099852232205860U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 1538435607932096400U;
            aOrbiterC = RotL64((aOrbiterC * 7900752511710516981U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 11147868774413615365U) + aNonceWordP;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 9325213746830411568U;
            aOrbiterK = RotL64((aOrbiterK * 561819005818948769U), 35U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterF) + 13792300423550555634U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1]) + aNonceWordL;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 3134856508983945719U;
            aOrbiterI = RotL64((aOrbiterI * 4271845067763664863U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 8654966018053784882U) + aOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 8937113935476779267U;
            aOrbiterB = RotL64((aOrbiterB * 7386875687217705855U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 4135676350355234788U) + aNonceWordA;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 11407912615743682678U;
            aOrbiterE = RotL64((aOrbiterE * 2773506587480714695U), 11U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterF, 43U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 27U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 19U));
            aIngress = aIngress + RotL64(aOrbiterK, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aScatter, 5U) + RotL64(aOrbiterB, 23U)) + aOrbiterF) + aNonceWordG);
            aWandererH = aWandererH ^ ((((RotL64(aCross, 53U) + aOrbiterI) + RotL64(aOrbiterF, 57U)) + aNonceWordN) + aWandererUpdateSaltB[((aIndex + 17U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aIngress, 29U) + aOrbiterK) + RotL64(aOrbiterE, 29U)) + RotL64(aCarry, 5U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 22U) + RotL64(aOrbiterG, 44U)) + aOrbiterF);
            aWandererF = aWandererF + (((((RotL64(aCross, 11U) + RotL64(aOrbiterE, 11U)) + aOrbiterI) + RotL64(aCarry, 23U)) + aNonceWordM) + aWandererUpdateSaltC[((aIndex + 15U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 43U) + aOrbiterC) + RotL64(aOrbiterK, 3U));
            aWandererD = aWandererD + (((RotL64(aScatter, 35U) + aOrbiterK) + RotL64(aOrbiterG, 37U)) + aNonceWordI);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 41U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 57U));
            aCarry = aCarry + (RotL64(aWandererK, 34U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererA, 11U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
    [[maybe_unused]] std::uint8_t *aWorkLaneC = pWorkSpace->mWorkLaneC;
    [[maybe_unused]] std::uint8_t *aWorkLaneD = pWorkSpace->mWorkLaneD;
    [[maybe_unused]] std::uint8_t *aFireLaneA = pWorkSpace->mFireLaneA;
    [[maybe_unused]] std::uint8_t *aFireLaneB = pWorkSpace->mFireLaneB;
    [[maybe_unused]] std::uint8_t *aFireLaneC = pWorkSpace->mFireLaneC;
    [[maybe_unused]] std::uint8_t *aFireLaneD = pWorkSpace->mFireLaneD;
    [[maybe_unused]] std::uint8_t *aKeyRowReadA = &(pWorkSpace->mKeyBoxA[H_KEY - 1][0]);
    [[maybe_unused]] std::uint8_t *aKeyRowReadB = &(pWorkSpace->mKeyBoxB[H_KEY - 1][0]);
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltA;
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
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA;
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
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltD;
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
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltF;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xD4EC14FDB761386DULL + 0xD9FB70CDED8ABEC8ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xD9B754DD9EFF1BF7ULL + 0xCB537AB1F0E12E3BULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xE6F8F9E0734AF72FULL + 0xB74D286022640CBCULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xCF91B7A5A84D6303ULL + 0x801D5A94C09A5187ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xA89498B3AB9E6289ULL + 0xF7C0DDC65236A29FULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xE1C957E9C8942E29ULL + 0xE759A61C1F31B46BULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xDE83078AC930DA89ULL + 0xC71658B7415FFA0EULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xBE58B318727F5F9BULL + 0x88E44E3323C36AE6ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xDEC7D86F0C82AA53ULL + 0x9084E55D9A37F7BFULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xAFAF54B75C936881ULL + 0xD55206080AAB0DB0ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xD5F9E0E01190C8C7ULL + 0xE95322270F590299ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xD7CB4F50817AD447ULL + 0xA4110D6792AAAD8EULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x8684ED9F2AEFBECFULL + 0xFFD6BD5D5633D6ADULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x9C379B9A5C329B05ULL + 0xC4011244C5D097B7ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xAD51B742E30ABB8DULL + 0xA26BE526DBF184A1ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0x828277E1F7D67E05ULL + 0xEF26878265CE9D00ULL);
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
            aIngress = RotL64(aKeyRowReadA[((aIndex + 738U)) & W_KEY1], 11U) ^ RotL64(aKeyRowReadB[((aIndex + 2517U)) & W_KEY1], 56U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 1415U)) & W_KEY1], 23U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 1627U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCross, 23U) ^ RotL64(aIngress, 11U)) + (RotL64(aPrevious, 38U) + RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterA = (((aWandererE + RotL64(aPrevious, 21U)) + RotL64(aCarry, 19U)) + 4634399531433127141U) + aNonceWordM;
            aOrbiterB = (((aWandererG + RotL64(aIngress, 27U)) + RotL64(aCarry, 41U)) + 16961792729406903200U) + aPhaseEOrbiterAssignSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterJ = ((aWandererA + RotL64(aScatter, 41U)) + 4105280732301137738U) + aNonceWordL;
            aOrbiterC = ((aWandererH + RotL64(aCross, 47U)) + 15692013501147331191U) + aNonceWordH;
            aOrbiterE = ((aWandererK + RotL64(aPrevious, 13U)) + 1252216715968780587U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterK = (aWandererB + RotL64(aIngress, 34U)) + 7958289043012473752U;
            aOrbiterF = ((aWandererF + RotL64(aScatter, 5U)) + RotL64(aCarry, 57U)) + 6611577301818896615U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 8506226754305949140U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 3648813120449403353U;
            aOrbiterJ = RotL64((aOrbiterJ * 9521367946879238849U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 5195245426245535735U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 542948051600803051U;
            aOrbiterE = RotL64((aOrbiterE * 4631106308856448475U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 11974253551208964789U) + aNonceWordN;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 10596463592332655367U;
            aOrbiterK = RotL64((aOrbiterK * 10941161258815714641U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 12015129484061440159U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 8254944355710109060U;
            aOrbiterF = RotL64((aOrbiterF * 3233697992479357615U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 2754858806943915419U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 5007802002906662779U) ^ aNonceWordE;
            aOrbiterC = RotL64((aOrbiterC * 15613733948331639723U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 6262190752136523216U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 10528977986487821428U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 1184258264034585525U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 8511097226098211854U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 12091864735686692582U;
            aOrbiterA = RotL64((aOrbiterA * 6128140528141411237U), 35U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterF, 5U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 11U));
            aIngress = aIngress + (RotL64(aOrbiterK, 29U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterB, 60U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterE, 27U)) + aOrbiterB);
            aWandererA = aWandererA + (((((RotL64(aIngress, 27U) + aOrbiterK) + RotL64(aOrbiterF, 3U)) + RotL64(aCarry, 53U)) + aNonceWordF) + aPhaseEWandererUpdateSaltC[((aIndex + 27U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 11U) + aOrbiterE) + RotL64(aOrbiterJ, 37U));
            aWandererB = aWandererB + ((RotL64(aScatter, 56U) + aOrbiterF) + RotL64(aOrbiterE, 46U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterE, 57U)) + aOrbiterA) + aNonceWordI);
            aWandererH = aWandererH + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterA, 19U)) + aOrbiterC) + RotL64(aCarry, 11U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 21U) + RotL64(aOrbiterK, 13U)) + aOrbiterC) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 19U) ^ aWandererA);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 27U));
            aCarry = aCarry + (RotL64(aWandererF, 12U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererH, 5U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 4502U)) & S_BLOCK1], 29U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 4708U)) & W_KEY1], 39U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 4027U)) & W_KEY1], 23U) ^ RotL64(mSource[((aIndex + 5450U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCarry, 35U) + RotL64(aPrevious, 5U)) ^ (RotL64(aIngress, 54U) ^ RotL64(aCross, 21U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterF = (aWandererE + RotL64(aPrevious, 29U)) + 7722279280863371124U;
            aOrbiterK = (((aWandererJ + RotL64(aCross, 53U)) + RotL64(aCarry, 3U)) + 11584220561732385598U) + aNonceWordM;
            aOrbiterB = (((aWandererF + RotL64(aScatter, 41U)) + 7834679350105534657U) + aPhaseEOrbiterAssignSaltA[((aIndex + 25U)) & S_SALT1]) + aNonceWordA;
            aOrbiterI = ((aWandererB + RotL64(aIngress, 35U)) + 11347994382444180879U) + aNonceWordE;
            aOrbiterE = (((aWandererH + RotL64(aScatter, 4U)) + RotL64(aCarry, 47U)) + 9449903188047063431U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterD = (((aWandererK + RotL64(aPrevious, 47U)) + RotL64(aCarry, 35U)) + 6516243976652795170U) + aNonceWordD;
            aOrbiterJ = (aWandererC + RotL64(aIngress, 21U)) + 8420815253991184777U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 9081386852515170937U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterF) ^ 14375955191735286867U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 12U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterB = RotL64((aOrbiterB * 2772840314542262283U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 880757589768436072U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 3349856625725164229U;
            aOrbiterK = RotL64((aOrbiterK * 681514212582331781U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 7826309957607577207U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 8057435761214313635U;
            aOrbiterJ = RotL64((aOrbiterJ * 4718430712767038607U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 9565237500443303103U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 15893066735310588501U) ^ aNonceWordK;
            aOrbiterI = RotL64((aOrbiterI * 8457633439171452397U), 5U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterI) + 3276844534476430842U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordN;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 6828644383891274120U;
            aOrbiterF = RotL64((aOrbiterF * 979580351653410157U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 2815676923011504251U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 5030251870850928417U;
            aOrbiterD = RotL64((aOrbiterD * 7075653570570819253U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 13464083008377887034U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 8994560761846897590U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 9892839554658865143U), 11U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterB, 35U);
            aIngress = aIngress + (RotL64(aOrbiterI, 29U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterE, 3U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterD, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aCross, 3U) + aOrbiterB) + RotL64(aOrbiterE, 51U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aScatter, 29U) + RotL64(aOrbiterJ, 57U)) + aOrbiterK) + RotL64(aCarry, 3U)) + aNonceWordB);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterB, 37U)) + aOrbiterD);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 10U) + RotL64(aOrbiterB, 44U)) + aOrbiterF) + RotL64(aCarry, 35U)) + aNonceWordI);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 53U) + aOrbiterJ) + RotL64(aOrbiterF, 29U)) + aPhaseEWandererUpdateSaltA[((aIndex + 18U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterI, 3U)) + aOrbiterJ) + aNonceWordO);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterD, 19U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererB, 19U) ^ aWandererJ);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 44U));
            aCarry = aCarry + (RotL64(aWandererC, 29U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererF, 35U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = RotL64(aWorkLaneB[((aIndex + 5475U)) & S_BLOCK1], 48U) ^ RotL64(aKeyRowReadB[((aIndex + 6202U)) & W_KEY1], 5U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 6858U)) & W_KEY1], 53U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 7641U)) & S_BLOCK1], 41U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 6743U)) & S_BLOCK1], 6U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCarry, 3U) ^ RotL64(aIngress, 51U)) ^ (RotL64(aPrevious, 18U) + RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterA = ((aWandererK + RotL64(aPrevious, 53U)) + 8975885703279267062U) + aNonceWordK;
            aOrbiterF = ((aWandererD + RotL64(aScatter, 19U)) + 8664844915562660637U) + aNonceWordD;
            aOrbiterE = ((aWandererG + RotL64(aIngress, 29U)) + RotL64(aCarry, 57U)) + 12281774799736296726U;
            aOrbiterK = (((aWandererB + RotL64(aCross, 5U)) + 15347461352311329726U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordG;
            aOrbiterJ = (((aWandererC + RotL64(aScatter, 37U)) + RotL64(aCarry, 43U)) + 12967500561828907834U) + aPhaseEOrbiterAssignSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = ((aWandererJ + RotL64(aCross, 11U)) + RotL64(aCarry, 27U)) + 5002833859280402726U;
            aOrbiterI = (aWandererA + RotL64(aPrevious, 44U)) + 11908257536954668983U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 17017174811949227162U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 16851323125613931180U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 12446990992858763577U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 13469326957728686706U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 5228638551056105241U) ^ aNonceWordO;
            aOrbiterC = RotL64((aOrbiterC * 13369947664646167255U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 11945166198089308564U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 16268645041872996022U;
            aOrbiterA = RotL64((aOrbiterA * 5391448793718370911U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 14781204627695095701U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 5365325354838101092U;
            aOrbiterF = RotL64((aOrbiterF * 8017284997946310807U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 563147416025715953U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 14660867395395625851U;
            aOrbiterJ = RotL64((aOrbiterJ * 4769458126865307103U), 3U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterC) + 3168989056355712105U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1]) + aNonceWordA;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 16179131669773665579U;
            aOrbiterI = RotL64((aOrbiterI * 5641461617066671723U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 4160220074225527179U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 8597134686962559111U;
            aOrbiterK = RotL64((aOrbiterK * 639572585431474015U), 41U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterK, 35U);
            aIngress = aIngress + (RotL64(aOrbiterC, 53U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 41U));
            aIngress = aIngress + RotL64(aOrbiterA, 60U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aScatter, 35U) + RotL64(aOrbiterK, 13U)) + aOrbiterJ) + RotL64(aCarry, 13U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 28U) + aOrbiterE) + RotL64(aOrbiterA, 29U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 21U) + RotL64(aOrbiterA, 60U)) + aOrbiterC) + RotL64(aCarry, 37U)) + aNonceWordE);
            aWandererC = aWandererC ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterA, 5U)) + aOrbiterI);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 53U) + RotL64(aOrbiterK, 53U)) + aOrbiterF);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 13U) + aOrbiterF) + RotL64(aOrbiterE, 39U)) + aNonceWordL);
            aWandererD = aWandererD + ((((RotL64(aIngress, 43U) + aOrbiterJ) + RotL64(aOrbiterE, 23U)) + aNonceWordJ) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 10U) ^ aWandererD);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 47U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 19U));
            aCarry = aCarry + RotL64(aWandererA, 37U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 9016U)) & S_BLOCK1], 3U) ^ RotL64(aKeyRowReadB[((aIndex + 9555U)) & W_KEY1], 29U));
            aIngress ^= (RotL64(mSource[((aIndex + 9613U)) & S_BLOCK1], 48U) ^ RotL64(aWorkLaneA[((aIndex + 9189U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 8562U)) & W_KEY1], 39U) ^ RotL64(aWorkLaneB[((aIndex + 10690U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aIngress, 39U) ^ RotL64(aCross, 5U)) + (RotL64(aCarry, 20U) ^ RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterD = (((aWandererJ + RotL64(aPrevious, 29U)) + RotL64(aCarry, 21U)) + 13960289014350612206U) + aNonceWordI;
            aOrbiterJ = (aWandererH + RotL64(aScatter, 23U)) + 3483331015269589730U;
            aOrbiterG = (((aWandererF + RotL64(aCross, 13U)) + RotL64(aCarry, 41U)) + 6873299241002444518U) + aNonceWordO;
            aOrbiterK = (aWandererG + RotL64(aIngress, 53U)) + 3562094007125534229U;
            aOrbiterE = ((aWandererK + RotL64(aScatter, 41U)) + 11422367439932782705U) + aPhaseFOrbiterAssignSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = ((aWandererD + RotL64(aIngress, 60U)) + RotL64(aCarry, 3U)) + 532453428514259816U;
            aOrbiterI = ((aWandererC + RotL64(aCross, 3U)) + 17810941465810193088U) + aPhaseFOrbiterAssignSaltA[((aIndex + 7U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 11869759058631106331U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 8837581071876177566U;
            aOrbiterG = RotL64((aOrbiterG * 15329827515970522213U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 17185378327053837778U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 7578253375676981500U;
            aOrbiterD = RotL64((aOrbiterD * 13371647568758721729U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 17112646434432814442U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 14949096407295697881U;
            aOrbiterK = RotL64((aOrbiterK * 14770977858283051753U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 4259590620758467836U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 6534899413644542303U) ^ aNonceWordP;
            aOrbiterI = RotL64((aOrbiterI * 7987609419215568661U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 2637407498893694243U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 15819295597921425711U;
            aOrbiterE = RotL64((aOrbiterE * 5202015597375051399U), 37U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterD) + 6373559542002699718U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordG;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 11694562937392022505U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 9311557972331218597U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 3308736483775453062U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 12749929710650475901U;
            aOrbiterB = RotL64((aOrbiterB * 248428400724560945U), 43U);
            //
            aIngress = RotL64(aOrbiterE, 57U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterD, 41U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 3U));
            aIngress = aIngress + RotL64(aOrbiterJ, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterG, 11U)) + aOrbiterJ);
            aWandererG = aWandererG + ((RotL64(aScatter, 13U) + aOrbiterD) + RotL64(aOrbiterK, 47U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 35U) + RotL64(aOrbiterG, 60U)) + aOrbiterB) + aPhaseFWandererUpdateSaltA[((aIndex + 6U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aIngress, 47U) + aOrbiterK) + RotL64(aOrbiterI, 35U)) + RotL64(aCarry, 13U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 6U) + RotL64(aOrbiterB, 27U)) + aOrbiterD) + aNonceWordH);
            aWandererH = aWandererH + (((RotL64(aScatter, 19U) + aOrbiterK) + RotL64(aOrbiterE, 19U)) + RotL64(aCarry, 39U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 27U) + RotL64(aOrbiterJ, 41U)) + aOrbiterD) + aNonceWordF);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 23U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 29U));
            aCarry = aCarry + (RotL64(aWandererH, 3U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererG, 14U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = (RotL64(aWorkLaneD[((aIndex + 13509U)) & S_BLOCK1], 56U) ^ RotL64(aKeyRowReadA[((aIndex + 11387U)) & W_KEY1], 3U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 12822U)) & W_KEY1], 37U) ^ RotL64(mSource[((aIndex + 11722U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 12805U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 11656U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneC[((aIndex + 12964U)) & S_BLOCK1], 56U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCarry, 57U) + RotL64(aIngress, 19U)) + (RotL64(aCross, 42U) ^ RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterI = ((aWandererJ + RotL64(aIngress, 11U)) + RotL64(aCarry, 39U)) + 18302975933754610273U;
            aOrbiterG = ((aWandererI + RotL64(aScatter, 51U)) + 16736972646771456082U) + aNonceWordE;
            aOrbiterD = (((aWandererB + RotL64(aCross, 57U)) + RotL64(aCarry, 53U)) + 17389406266488137442U) + aNonceWordI;
            aOrbiterC = ((aWandererK + RotL64(aPrevious, 24U)) + 5252511566486165539U) + aPhaseFOrbiterAssignSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = ((aWandererG + RotL64(aCross, 41U)) + 5730715427422747640U) + aPhaseFOrbiterAssignSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = ((aWandererC + RotL64(aPrevious, 35U)) + RotL64(aCarry, 27U)) + 6412695646456045825U;
            aOrbiterE = ((aWandererE + RotL64(aIngress, 3U)) + 9539701605708994494U) + aNonceWordK;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 18355107116412945722U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 11735742491750132942U;
            aOrbiterD = RotL64((aOrbiterD * 18129835093627763685U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 12363819388562658842U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 5861430292304371543U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 12989055611235382695U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 15027487084595017708U) + aNonceWordL;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 7012850020745791926U;
            aOrbiterG = RotL64((aOrbiterG * 15952928839355613939U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 11904871669287886120U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 11199760114477343208U;
            aOrbiterE = RotL64((aOrbiterE * 7156374911847525867U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 3856004502263742700U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 3705931243173921893U) ^ aNonceWordO;
            aOrbiterC = RotL64((aOrbiterC * 10334871178498711485U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 12305785390539209389U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 18057980996551978823U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4850564181113470859U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 3229431819292153014U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 2994716629242460094U) ^ aNonceWordN;
            aOrbiterI = RotL64((aOrbiterI * 1029427328395257917U), 57U);
            //
            aIngress = RotL64(aOrbiterH, 37U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterG, 27U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 5U));
            aIngress = aIngress + RotL64(aOrbiterF, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aCross, 27U) + RotL64(aOrbiterC, 6U)) + aOrbiterE) + aNonceWordA);
            aWandererG = aWandererG + (((RotL64(aScatter, 48U) + RotL64(aOrbiterI, 41U)) + aOrbiterF) + RotL64(aCarry, 5U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 5U) + aOrbiterI) + RotL64(aOrbiterD, 53U));
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 39U) + aOrbiterF) + RotL64(aOrbiterD, 27U)) + aNonceWordP) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 19U) + RotL64(aOrbiterG, 21U)) + aOrbiterC) + aNonceWordF);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 11U) + RotL64(aOrbiterH, 35U)) + aOrbiterG) + RotL64(aCarry, 41U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterD, 47U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererE, 14U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererB, 39U) ^ aWandererC);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 35U));
            aCarry = aCarry + RotL64(aWandererJ, 27U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 14133U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 14003U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 15230U)) & W_KEY1], 5U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 15421U)) & W_KEY1], 43U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 16370U)) & S_BLOCK1], 52U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 14909U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 16114U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aIngress, 53U) + RotL64(aCarry, 20U)) ^ (RotL64(aPrevious, 3U) + RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterC = (aWandererA + RotL64(aCross, 23U)) + 14008824488073394623U;
            aOrbiterK = ((aWandererG + RotL64(aIngress, 47U)) + RotL64(aCarry, 29U)) + 13317978415866411468U;
            aOrbiterD = (aWandererI + RotL64(aPrevious, 3U)) + 13209180141897453900U;
            aOrbiterA = ((aWandererK + RotL64(aScatter, 29U)) + RotL64(aCarry, 5U)) + 11870521586865233578U;
            aOrbiterB = ((aWandererC + RotL64(aCross, 60U)) + RotL64(aCarry, 43U)) + 8052156380448047385U;
            aOrbiterH = (((aWandererF + RotL64(aScatter, 13U)) + 12158131176743680605U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 16U)) & S_SALT1]) + aNonceWordK;
            aOrbiterG = (((aWandererH + RotL64(aPrevious, 41U)) + 14674467487607719347U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 14U)) & S_SALT1]) + aNonceWordO;
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 18055496790566231147U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 3838105585041578784U) ^ aNonceWordB;
            aOrbiterD = RotL64((aOrbiterD * 1075709247574580091U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 2839568255183054418U) + aNonceWordM;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 11933612922864258179U;
            aOrbiterC = RotL64((aOrbiterC * 7571964469321160347U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 6289849094151630580U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 2640344350528492271U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 16197726750829369365U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 16306175266267657791U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 3339898380394883600U;
            aOrbiterB = RotL64((aOrbiterB * 7105436590182982373U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 15017076663742800002U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 8973064296077602496U;
            aOrbiterH = RotL64((aOrbiterH * 9309462227233615761U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 17580319233338139859U) + aNonceWordH;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 14063208878807603874U) ^ aNonceWordP;
            aOrbiterA = RotL64((aOrbiterA * 16601475239075164585U), 23U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 13326130855721009942U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 12843186026737544416U;
            aOrbiterG = RotL64((aOrbiterG * 4975848122837321619U), 43U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterB, 11U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 27U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 60U));
            aIngress = aIngress + RotL64(aOrbiterD, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterC, 53U)) + aOrbiterG) + RotL64(aCarry, 53U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 11U) + aOrbiterK) + RotL64(aOrbiterH, 3U)) + aNonceWordJ);
            aWandererC = aWandererC + ((RotL64(aScatter, 51U) + aOrbiterA) + RotL64(aOrbiterB, 27U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 35U) + aOrbiterC) + RotL64(aOrbiterA, 19U));
            aWandererG = aWandererG + (((((RotL64(aScatter, 57U) + aOrbiterB) + RotL64(aOrbiterD, 44U)) + RotL64(aCarry, 5U)) + aNonceWordD) + aPhaseFWandererUpdateSaltC[((aIndex + 18U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 27U) + aOrbiterH) + RotL64(aOrbiterG, 11U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 20U) + RotL64(aOrbiterH, 37U)) + aOrbiterB) + aPhaseFWandererUpdateSaltE[((aIndex + 4U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 35U));
            aCarry = aCarry + (RotL64(aWandererC, 51U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererG, 46U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererF, 23U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 19062U)) & S_BLOCK1], 43U) ^ RotL64(aKeyRowReadA[((aIndex + 18901U)) & W_KEY1], 4U));
            aIngress ^= (RotL64(mSource[((aIndex + 18909U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneA[((aIndex + 18175U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 18033U)) & W_KEY1], 23U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 17197U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 17138U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCross, 52U) + RotL64(aIngress, 5U)) ^ (RotL64(aCarry, 35U) + RotL64(aPrevious, 19U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterD = (((aWandererK + RotL64(aCross, 29U)) + RotL64(aCarry, 3U)) + 5041131702736607991U) + aNonceWordB;
            aOrbiterB = (((aWandererG + RotL64(aIngress, 57U)) + RotL64(aCarry, 35U)) + 9295010428212681446U) + aNonceWordJ;
            aOrbiterC = ((aWandererJ + RotL64(aPrevious, 41U)) + RotL64(aCarry, 23U)) + 6235875895358766017U;
            aOrbiterK = (((aWandererC + RotL64(aScatter, 3U)) + 2622227802531866918U) + aPhaseGOrbiterAssignSaltD[((aIndex + 21U)) & S_SALT1]) + aNonceWordL;
            aOrbiterG = (aWandererD + RotL64(aIngress, 10U)) + 3888894734834524972U;
            aOrbiterE = (((aWandererB + RotL64(aPrevious, 23U)) + 241682012014701753U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordK;
            aOrbiterI = (aWandererF + RotL64(aScatter, 47U)) + 15758000422451568079U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 2061944548396976912U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 8177144990755754531U;
            aOrbiterC = RotL64((aOrbiterC * 12702392689484397947U), 37U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 554978075608818497U) + aPhaseGOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 250408260560714933U) ^ aNonceWordD;
            aOrbiterG = RotL64((aOrbiterG * 1295379390497107727U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 8700027645880997552U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 10026130047465480902U;
            aOrbiterB = RotL64((aOrbiterB * 12417270861933696623U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 9785843014096326696U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 9998582683258411251U) ^ aNonceWordN;
            aOrbiterD = RotL64((aOrbiterD * 7197956237569462269U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 13817734599383455151U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 6647207154174092691U) ^ aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 1578528131687283531U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 4957715980509035719U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 4994885315786213197U;
            aOrbiterK = RotL64((aOrbiterK * 5676683798126497011U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 5072908311783966503U) + aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 5535039946192891515U) ^ aNonceWordA;
            aOrbiterI = RotL64((aOrbiterI * 2989412783482309753U), 51U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterD, 21U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 41U));
            aIngress = aIngress + (RotL64(aOrbiterC, 5U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterK, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterB, 40U)) + aOrbiterK);
            aWandererC = aWandererC + (((((RotL64(aPrevious, 50U) + aOrbiterK) + RotL64(aOrbiterE, 11U)) + RotL64(aCarry, 21U)) + aNonceWordO) + aPhaseGWandererUpdateSaltC[((aIndex + 9U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 29U) + aOrbiterI) + RotL64(aOrbiterB, 53U));
            aWandererF = aWandererF + (((RotL64(aCross, 23U) + RotL64(aOrbiterG, 29U)) + aOrbiterC) + RotL64(aCarry, 57U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 41U) + aOrbiterC) + RotL64(aOrbiterI, 5U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 35U) + aOrbiterD) + RotL64(aOrbiterI, 47U)) + aPhaseGWandererUpdateSaltB[((aIndex + 3U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterB, 23U)) + aOrbiterG) + aNonceWordP);
            //
            aCarry = aCarry + (RotL64(aWandererK, 24U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererJ, 37U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererB, 11U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererC, 47U);
            aCarry = aCarry + RotL64(aIngress, 28U);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 20732U)) & S_BLOCK1], 18U) ^ RotL64(mSource[((aIndex + 19227U)) & S_BLOCK1], 37U));
            aIngress ^= (RotL64(aFireLaneA[((aIndex + 20997U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21157U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 19371U)) & W_KEY1], 43U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 21336U)) & W_KEY1], 5U));
            aCross ^= (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 21073U)) & S_BLOCK1], 58U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 21357U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCarry, 19U) + RotL64(aIngress, 5U)) ^ (RotL64(aCross, 35U) + RotL64(aPrevious, 54U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterE = ((aWandererE + RotL64(aPrevious, 37U)) + 15045917390223766480U) + aPhaseGOrbiterAssignSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterC = (aWandererB + RotL64(aScatter, 57U)) + 10763054007033668758U;
            aOrbiterI = (((aWandererA + RotL64(aCross, 43U)) + RotL64(aCarry, 57U)) + 13190170142593666607U) + aNonceWordE;
            aOrbiterD = (((aWandererH + RotL64(aIngress, 30U)) + RotL64(aCarry, 27U)) + 9657025731441167065U) + aNonceWordH;
            aOrbiterH = (((aWandererD + RotL64(aCross, 13U)) + 11433367178975954211U) + aPhaseGOrbiterAssignSaltC[((aIndex + 4U)) & S_SALT1]) + aNonceWordI;
            aOrbiterB = ((aWandererI + RotL64(aScatter, 23U)) + 17904920143996810366U) + aNonceWordJ;
            aOrbiterA = ((aWandererJ + RotL64(aPrevious, 51U)) + RotL64(aCarry, 39U)) + 3244383020512113283U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 6538815775171139091U) + aNonceWordL;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 7195368312757976343U) ^ aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 10515679176134176565U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 18134430713910279374U) + aNonceWordO;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 6571776588427107976U) ^ aPhaseGOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 11916502085252589161U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 11830778129647517758U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 9793702760907767365U;
            aOrbiterC = RotL64((aOrbiterC * 4096246227968677179U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 2287235876793192036U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 8951959188326141794U;
            aOrbiterE = RotL64((aOrbiterE * 9968356718110753845U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 7583061790273240157U) + aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 3571364625022806085U;
            aOrbiterA = RotL64((aOrbiterA * 6238360922735480669U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 13869345563551689212U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterA) ^ 277480328952975002U) ^ aPhaseGOrbiterUpdateSaltC[((aIndex + 28U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterB = RotL64((aOrbiterB * 1057564597096163085U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 4983735092494677578U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 9490022869381030928U) ^ aNonceWordM;
            aOrbiterD = RotL64((aOrbiterD * 12926352917961703123U), 3U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterB, 5U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 21U));
            aIngress = aIngress + (RotL64(aOrbiterE, 47U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterD, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aCross, 20U) + aOrbiterB) + RotL64(aOrbiterC, 53U)) + aNonceWordN);
            aWandererA = aWandererA + (((((RotL64(aPrevious, 11U) + RotL64(aOrbiterD, 11U)) + aOrbiterC) + RotL64(aCarry, 13U)) + aNonceWordG) + aPhaseGWandererUpdateSaltF[((aIndex + 3U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 27U) + RotL64(aOrbiterE, 39U)) + aOrbiterD) + aNonceWordP);
            aWandererJ = aWandererJ + (((((RotL64(aIngress, 53U) + RotL64(aOrbiterI, 27U)) + aOrbiterC) + RotL64(aCarry, 43U)) + aNonceWordF) + aPhaseGWandererUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 5U) + aOrbiterA) + RotL64(aOrbiterC, 5U));
            aWandererE = aWandererE + ((RotL64(aPrevious, 41U) + aOrbiterD) + RotL64(aOrbiterI, 18U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 47U) + aOrbiterA) + RotL64(aOrbiterH, 47U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 19U) ^ aWandererA);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 24U));
            aCarry = aCarry + (RotL64(aWandererB, 13U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererD, 51U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 22517U)) & S_BLOCK1], 47U) ^ RotL64(aKeyRowReadA[((aIndex + 23056U)) & W_KEY1], 19U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 22003U)) & W_KEY1], 35U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 22301U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 23335U)) & S_BLOCK1], 5U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 23914U)) & S_BLOCK1], 37U));
            aCross ^= (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 22477U)) & S_BLOCK1], 48U) ^ RotL64(aWorkLaneD[((aIndex + 22908U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCarry, 11U) + RotL64(aIngress, 58U)) ^ (RotL64(aCross, 27U) + RotL64(aPrevious, 41U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterA = ((aWandererA + RotL64(aScatter, 43U)) + 6771552164800695068U) + aNonceWordD;
            aOrbiterK = ((aWandererE + RotL64(aPrevious, 57U)) + RotL64(aCarry, 51U)) + 12131763371571322040U;
            aOrbiterH = (((aWandererD + RotL64(aIngress, 37U)) + RotL64(aCarry, 11U)) + 3326182381395522013U) + aNonceWordM;
            aOrbiterG = ((aWandererC + RotL64(aCross, 27U)) + 12288775097697156383U) + aPhaseGOrbiterAssignSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = (((aWandererG + RotL64(aScatter, 10U)) + 5195948373449796741U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordL;
            aOrbiterI = ((aWandererK + RotL64(aPrevious, 21U)) + 14404044002250137144U) + aNonceWordH;
            aOrbiterC = ((aWandererF + RotL64(aCross, 3U)) + RotL64(aCarry, 39U)) + 11142382920035825426U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 2967149520256475485U) + aPhaseGOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 1470907369577818097U;
            aOrbiterH = RotL64((aOrbiterH * 9398653295177725883U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 9231668148004163910U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 13078929163913892386U) ^ aPhaseGOrbiterUpdateSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 7509829068700523627U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 9485274692075657877U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 12216951187543631673U;
            aOrbiterG = RotL64((aOrbiterG * 6571066246507310805U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 6933334652581744234U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 17260276102423580920U) ^ aNonceWordA;
            aOrbiterC = RotL64((aOrbiterC * 7796879893790990605U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 387767848169714392U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 8597538259308082638U) ^ aNonceWordC;
            aOrbiterI = RotL64((aOrbiterI * 4888054690557707241U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 7996708724489146033U) + aPhaseGOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 15357384191688149939U) ^ aPhaseGOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 9827691726832491373U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 17739222908739454637U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 1614322333281471170U) ^ aNonceWordK;
            aOrbiterA = RotL64((aOrbiterA * 7063116837752240891U), 57U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterG, 11U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 41U));
            aIngress = aIngress + (RotL64(aOrbiterC, 18U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterI, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aScatter, 57U) + aOrbiterK) + RotL64(aOrbiterE, 13U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 11U) + aOrbiterA) + RotL64(aOrbiterH, 29U));
            aWandererE = aWandererE + (((RotL64(aIngress, 27U) + aOrbiterI) + RotL64(aOrbiterC, 47U)) + aNonceWordI);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 34U) + RotL64(aOrbiterC, 21U)) + aOrbiterK) + aNonceWordE);
            aWandererK = aWandererK + (((((RotL64(aIngress, 51U) + aOrbiterK) + RotL64(aOrbiterH, 41U)) + RotL64(aCarry, 35U)) + aNonceWordN) + aPhaseGWandererUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterH, 58U)) + aOrbiterE);
            aWandererG = aWandererG + ((((RotL64(aScatter, 43U) + aOrbiterG) + RotL64(aOrbiterK, 35U)) + RotL64(aCarry, 47U)) + aPhaseGWandererUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 42U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 47U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 51U));
            aCarry = aCarry + RotL64(aWandererA, 11U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 25698U)) & S_BLOCK1], 20U) ^ RotL64(aKeyRowReadA[((aIndex + 26123U)) & W_KEY1], 29U));
            aIngress ^= (RotL64(aFireLaneD[((aIndex + 25225U)) & S_BLOCK1], 53U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 24701U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 25150U)) & W_KEY1], 40U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 25253U)) & S_BLOCK1], 5U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 25618U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneD[((aIndex + 26046U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCarry, 11U) ^ RotL64(aPrevious, 58U)) + (RotL64(aIngress, 27U) ^ RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterH = (aWandererA + RotL64(aScatter, 11U)) + 12632404972795375757U;
            aOrbiterA = ((aWandererE + RotL64(aPrevious, 51U)) + 5351879979055988456U) + aNonceWordP;
            aOrbiterI = (aWandererH + RotL64(aCross, 19U)) + 3597737727467443413U;
            aOrbiterG = (((aWandererB + RotL64(aIngress, 41U)) + RotL64(aCarry, 35U)) + 2830846754917852318U) + aNonceWordF;
            aOrbiterJ = (aWandererC + RotL64(aPrevious, 29U)) + 17311925960294518018U;
            aOrbiterF = ((((aWandererI + RotL64(aCross, 35U)) + RotL64(aCarry, 47U)) + 2083584640523695383U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordN;
            aOrbiterE = ((((aWandererJ + RotL64(aScatter, 58U)) + RotL64(aCarry, 19U)) + 15049343611387010158U) + aPhaseHOrbiterAssignSaltF[((aIndex + 22U)) & S_SALT1]) + aNonceWordD;
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 6443050378205811147U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 6021965178697344070U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 6054064448935006741U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 5080289878758029976U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 576927745306972983U) ^ aNonceWordI;
            aOrbiterJ = RotL64((aOrbiterJ * 16008958833683246115U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 4728489691382690859U) + aNonceWordB;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 6184355840165758855U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 1515043910404156423U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 11220539885798595450U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 11091438724966718214U;
            aOrbiterE = RotL64((aOrbiterE * 8225347114759391961U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 17184210490020062419U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 2150997767099116408U;
            aOrbiterG = RotL64((aOrbiterG * 8058553821648892499U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 7021953562676903717U) + aNonceWordE;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 17159676348343312834U;
            aOrbiterA = RotL64((aOrbiterA * 13877284519668483549U), 41U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 10367891770525239784U) + aNonceWordC;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 11922478487264201233U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9195137452661956029U), 53U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterH, 21U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 53U));
            aIngress = aIngress + (RotL64(aOrbiterE, 11U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterG, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aScatter, 35U) + aOrbiterF) + RotL64(aOrbiterG, 14U)) + aNonceWordL);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 48U) + RotL64(aOrbiterA, 47U)) + aOrbiterG) + aNonceWordM);
            aWandererC = aWandererC + ((((RotL64(aCross, 11U) + RotL64(aOrbiterF, 37U)) + aOrbiterJ) + RotL64(aCarry, 11U)) + aNonceWordO);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterE, 57U)) + aOrbiterA);
            aWandererH = aWandererH + ((((RotL64(aScatter, 19U) + aOrbiterH) + RotL64(aOrbiterA, 21U)) + RotL64(aCarry, 53U)) + aPhaseHWandererUpdateSaltC[((aIndex + 29U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aCross, 3U) + aOrbiterI) + RotL64(aOrbiterH, 27U)) + aPhaseHWandererUpdateSaltF[((aIndex + 24U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aIngress, 27U) + aOrbiterJ) + RotL64(aOrbiterI, 5U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 29U));
            aCarry = aCarry + (RotL64(aWandererI, 34U) ^ aWandererJ);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 47U));
            aCarry = aCarry + RotL64(aWandererH, 21U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 28188U)) & S_BLOCK1], 20U) ^ RotL64(aFireLaneD[((aIndex + 29871U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 27769U)) & W_KEY1], 57U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 28934U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 28655U)) & W_KEY1], 51U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 29564U)) & S_BLOCK1], 20U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 28138U)) & S_BLOCK1], 29U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 28388U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCross, 23U) + RotL64(aIngress, 51U)) ^ (RotL64(aPrevious, 10U) ^ RotL64(aCarry, 39U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterI = (((aWandererC + RotL64(aScatter, 43U)) + 18144572925667544139U) + aPhaseHOrbiterAssignSaltC[((aIndex + 15U)) & S_SALT1]) + aNonceWordI;
            aOrbiterE = (((aWandererB + RotL64(aPrevious, 3U)) + RotL64(aCarry, 3U)) + 5659758077574059728U) + aNonceWordL;
            aOrbiterB = ((aWandererI + RotL64(aCross, 58U)) + RotL64(aCarry, 41U)) + 6343330616999166392U;
            aOrbiterF = (((aWandererD + RotL64(aIngress, 37U)) + RotL64(aCarry, 27U)) + 17754639838410839447U) + aPhaseHOrbiterAssignSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterA = (aWandererG + RotL64(aPrevious, 19U)) + 9451843819849581729U;
            aOrbiterH = ((aWandererF + RotL64(aCross, 51U)) + 7957854457197462212U) + aNonceWordO;
            aOrbiterG = (aWandererH + RotL64(aScatter, 29U)) + 1461994799722205010U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 18002214276252170177U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 14689869073147027164U;
            aOrbiterB = RotL64((aOrbiterB * 12242482963989582191U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 3978104368003440293U) + aNonceWordG;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 8512135845221335386U) ^ aNonceWordA;
            aOrbiterE = RotL64((aOrbiterE * 10506667163729414667U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 1477533446382953439U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 2166717790929947990U;
            aOrbiterI = RotL64((aOrbiterI * 6538884492418324461U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 8082437060686606995U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 4363687722464700362U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7199165810993478887U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 15782763348014924206U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 8572509150015960728U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3340528604891897779U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 12248271773316742521U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 9602078627638561949U;
            aOrbiterH = RotL64((aOrbiterH * 1860631869877427405U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 17244849374768558859U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 1030743048280579012U;
            aOrbiterF = RotL64((aOrbiterF * 10858949914285817051U), 27U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterB, 27U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 5U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 57U));
            aIngress = aIngress + RotL64(aOrbiterI, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aIngress, 5U) + RotL64(aOrbiterH, 5U)) + aOrbiterB) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterI, 13U)) + aOrbiterA);
            aWandererH = aWandererH + (((RotL64(aCross, 11U) + RotL64(aOrbiterA, 43U)) + aOrbiterG) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 53U) + aOrbiterH) + RotL64(aOrbiterF, 28U)) + aNonceWordN);
            aWandererC = aWandererC + ((((RotL64(aIngress, 37U) + RotL64(aOrbiterF, 57U)) + aOrbiterG) + RotL64(aCarry, 57U)) + aNonceWordK);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 27U) + RotL64(aOrbiterF, 51U)) + aOrbiterE) + aNonceWordJ);
            aWandererB = aWandererB + (((RotL64(aCross, 18U) + RotL64(aOrbiterB, 21U)) + aOrbiterG) + RotL64(aCarry, 23U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 43U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererI, 53U) ^ aWandererG);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 39U));
            aCarry = aCarry + RotL64(aWandererB, 10U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 30801U)) & S_BLOCK1], 35U) ^ RotL64(aKeyRowReadA[((aIndex + 30569U)) & W_KEY1], 51U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 32319U)) & S_BLOCK1], 28U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30159U)) & S_BLOCK1], 3U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30689U)) & S_BLOCK1], 11U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 30911U)) & W_KEY1], 51U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aIngress, 53U) + RotL64(aCross, 41U)) + (RotL64(aCarry, 4U) ^ RotL64(aPrevious, 19U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterJ = ((aWandererD + RotL64(aPrevious, 21U)) + RotL64(aCarry, 3U)) + 4980738603982643969U;
            aOrbiterF = ((aWandererH + RotL64(aCross, 5U)) + 17660278413018470020U) + aNonceWordG;
            aOrbiterG = ((aWandererB + RotL64(aIngress, 11U)) + 17598114429859543466U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = (aWandererF + RotL64(aScatter, 54U)) + 10993929335279994739U;
            aOrbiterB = ((aWandererI + RotL64(aIngress, 41U)) + RotL64(aCarry, 19U)) + 17967203122976322481U;
            aOrbiterE = ((aWandererJ + RotL64(aCross, 29U)) + 1872290205549034384U) + aNonceWordO;
            aOrbiterI = ((((aWandererA + RotL64(aScatter, 35U)) + RotL64(aCarry, 47U)) + 16607778671782810797U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordM;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 4895226930754394376U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 14960359005982301383U;
            aOrbiterG = RotL64((aOrbiterG * 8546231310054433721U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 9921642352377700630U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 893281964367208693U;
            aOrbiterJ = RotL64((aOrbiterJ * 2345509157333444217U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 8232519988397858732U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 4433022122758913407U;
            aOrbiterI = RotL64((aOrbiterI * 834240393225479419U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 12689609831247168353U) + aNonceWordE;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 404535388957472176U) ^ aNonceWordL;
            aOrbiterB = RotL64((aOrbiterB * 14534020545479806593U), 53U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterG) + 3349108201964013155U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordB;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 4386449511297371730U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 9596273264321140229U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 14314587717949070586U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 10923886625271054985U;
            aOrbiterF = RotL64((aOrbiterF * 7838969002623486809U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 17634909585329833520U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 2021301459918350372U;
            aOrbiterE = RotL64((aOrbiterE * 1388242915918642741U), 47U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterE, 26U);
            aIngress = aIngress + (RotL64(aOrbiterA, 3U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 47U));
            aIngress = aIngress + RotL64(aOrbiterJ, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((((RotL64(aCross, 28U) + RotL64(aOrbiterB, 57U)) + aOrbiterI) + aNonceWordI) + aPhaseHWandererUpdateSaltF[((aIndex + 15U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aIngress, 35U) + RotL64(aOrbiterI, 28U)) + aOrbiterG) + aNonceWordK);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 53U) + aOrbiterB) + RotL64(aOrbiterA, 11U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 41U) + RotL64(aOrbiterI, 35U)) + aOrbiterE) + RotL64(aCarry, 37U));
            aWandererD = aWandererD ^ ((((RotL64(aCross, 5U) + RotL64(aOrbiterJ, 43U)) + aOrbiterG) + aNonceWordP) + aPhaseHWandererUpdateSaltA[((aIndex + 9U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 47U) + RotL64(aOrbiterF, 5U)) + aOrbiterE) + RotL64(aCarry, 11U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterJ, 19U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 50U));
            aCarry = aCarry + (RotL64(aWandererA, 39U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererD, 57U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererF, 29U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xE7677BA899DA7495ULL + 0xA14813A3F831E53CULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x9675B98C560A11C5ULL + 0x91CFB4CFA9BDD89DULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xE29F68DF4AC6E5C1ULL + 0xC2B28E8AEFD9623CULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xC443D95770350A8BULL + 0xD9AA62DF7C73E5FBULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x90C6A3FC0AD944F7ULL + 0xA3D66BE02D3DE9F6ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xAE33EFA065E6C65BULL + 0xD8534A2B51088567ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xE995FB479C1C421DULL + 0xE3307C18C83BF2C0ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xF01573918F77362DULL + 0xB0BD74A9843D925AULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xB6733DD363C42235ULL + 0x8520269171F4910AULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xC059FE6D93B2749FULL + 0xCD979D7F2BE36B38ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xFD95CE0A2AD90D91ULL + 0xA200BA98CB351403ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x9E688F91B6E8F701ULL + 0xE159A624C22065B2ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xD1EACD4077123461ULL + 0xD02883BA07514D50ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xEFDE612C2C22BE4BULL + 0x8959547C4BA0BC67ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xDFBE6CF5404987B7ULL + 0xAE540BB1CCC2F067ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xC74983D1A3FAD1B9ULL + 0xB1E892729461A7A2ULL);
    // GSeedRunSeed_B seed_loop_a (start)
    {
        // GSeedRunSeed_B seed_loop_a lane group
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneA, aExpandLaneC, aExpandLaneD, aInvestLaneA, aFireLaneB, aInvestLaneB, aFireLaneC, aOperationLaneA, aFireLaneD, aOperationLaneB, aOperationLaneC
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 1776U)) & S_BLOCK1], 22U) ^ RotL64(aExpandLaneB[((aIndex + 658U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 3901U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 2006U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneD[((aIndex + 3820U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCarry, 21U) + RotL64(aIngress, 5U)) + (RotL64(aCross, 56U) ^ RotL64(aPrevious, 41U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterK = (((aWandererK + RotL64(aCross, 43U)) + RotL64(aCarry, 5U)) + 13880995121909552664U) + aNonceWordO;
            aOrbiterF = ((aWandererE + RotL64(aPrevious, 35U)) + 14534942818069300546U) + aNonceWordI;
            aOrbiterJ = ((((aWandererF + RotL64(aScatter, 23U)) + RotL64(aCarry, 53U)) + 17745973100886007133U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 16U)) & S_SALT1]) + aNonceWordA;
            aOrbiterH = (aWandererD + RotL64(aIngress, 14U)) + 2249805580771946872U;
            aOrbiterA = ((((aWandererB + RotL64(aPrevious, 53U)) + RotL64(aCarry, 29U)) + 4460116116396439410U) + aPhaseAOrbiterAssignSaltA[((aIndex + 17U)) & S_SALT1]) + aNonceWordN;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 3378683994078106878U) + aNonceWordL;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 3992996501048809123U;
            aOrbiterJ = RotL64((aOrbiterJ * 13273544260537223797U), 5U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterK) + 12057768808864451929U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1]) + aNonceWordE;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 4115362079047921130U;
            aOrbiterF = RotL64((aOrbiterF * 12263015903331031345U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 15297384955502206698U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 17623548383481905636U;
            aOrbiterA = RotL64((aOrbiterA * 7487278217901483685U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 3559213898000162417U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 12311605719074507335U;
            aOrbiterK = RotL64((aOrbiterK * 3982199462062847697U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 14807313864347885885U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 11222085523291581822U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 12580941911587215653U), 39U);
            //
            aIngress = RotL64(aOrbiterK, 24U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 13U));
            aIngress = aIngress + RotL64(aOrbiterF, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aPrevious, 11U) + aOrbiterF) + RotL64(aOrbiterH, 39U)) + aNonceWordJ) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterF, 23U)) + aOrbiterJ) + aNonceWordD);
            aWandererB = aWandererB + ((((RotL64(aScatter, 38U) + aOrbiterH) + RotL64(aOrbiterJ, 3U)) + RotL64(aCarry, 21U)) + aNonceWordC);
            aWandererF = aWandererF ^ (((RotL64(aCross, 21U) + RotL64(aOrbiterK, 50U)) + aOrbiterA) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 51U) + aOrbiterJ) + RotL64(aOrbiterK, 13U)) + RotL64(aCarry, 5U)) + aNonceWordK);
            //
            aCarry = aCarry + (RotL64(aWandererE, 11U) ^ aWandererB);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 19U));
            aCarry = aCarry + RotL64(aWandererD, 39U);
            aCarry = aCarry + RotL64(aIngress, 28U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aInvestLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_a loop 2
        // ingress from: aInvestLaneA, aExpandLaneC, aFireLaneB
        // ingress directions: aInvestLaneA forward forced, aExpandLaneC forward forced, aFireLaneB forward/backward random
        // cross from: aExpandLaneA, aExpandLaneD
        // cross directions: aExpandLaneA backward forced, aExpandLaneD backward/forward random
        // write to: aInvestLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneA[((aIndex + 5861U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneC[((aIndex + 7824U)) & S_BLOCK1], 41U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 7280U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordE));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 7789U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 6311U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aIngress, 27U) + RotL64(aCarry, 58U)) ^ (RotL64(aCross, 11U) + RotL64(aPrevious, 39U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterE = (((aWandererD + RotL64(aPrevious, 48U)) + RotL64(aCarry, 27U)) + 966899917801652720U) + aNonceWordK;
            aOrbiterC = (((aWandererH + RotL64(aCross, 21U)) + 10996327672320748649U) + aPhaseAOrbiterAssignSaltC[((aIndex + 17U)) & S_SALT1]) + aNonceWordM;
            aOrbiterD = (((aWandererC + RotL64(aScatter, 11U)) + RotL64(aCarry, 39U)) + 4188171566846621107U) + aNonceWordH;
            aOrbiterG = ((aWandererK + RotL64(aIngress, 29U)) + RotL64(aCarry, 51U)) + 5886209243097387959U;
            aOrbiterI = (((aWandererI + RotL64(aCross, 37U)) + 14940428957136728111U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordN;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 179187285531914832U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 6685351948936817752U) ^ aNonceWordI;
            aOrbiterD = RotL64((aOrbiterD * 15533370414711696803U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 1894506461704029700U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 4182760368636977082U;
            aOrbiterE = RotL64((aOrbiterE * 972988091869133921U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 12523318028514940790U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 5059306166973366892U;
            aOrbiterC = RotL64((aOrbiterC * 2857409765717296483U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 5890872367917643851U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterC) ^ 17747338389865221534U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterI = RotL64((aOrbiterI * 5306740664798049267U), 11U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterE) + 13906227834259884100U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordD;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 7152105382899756368U;
            aOrbiterG = RotL64((aOrbiterG * 6772157117358310485U), 43U);
            //
            aIngress = RotL64(aOrbiterG, 24U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 57U));
            aIngress = aIngress + RotL64(aOrbiterI, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aScatter, 50U) + aOrbiterG) + RotL64(aOrbiterE, 56U)) + aNonceWordO) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 27U) + aOrbiterG) + RotL64(aOrbiterD, 21U));
            aWandererI = aWandererI + (((((RotL64(aIngress, 35U) + RotL64(aOrbiterE, 43U)) + aOrbiterI) + RotL64(aCarry, 51U)) + aNonceWordG) + aPhaseAWandererUpdateSaltE[((aIndex + 21U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 19U) + aOrbiterE) + RotL64(aOrbiterC, 13U));
            aWandererK = aWandererK + ((((RotL64(aScatter, 5U) + RotL64(aOrbiterG, 3U)) + aOrbiterC) + RotL64(aCarry, 23U)) + aNonceWordJ);
            //
            aCarry = aCarry + (RotL64(aWandererK, 58U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererC, 13U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererH, 35U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 13117U)) & S_BLOCK1], 18U) ^ RotL64(aExpandLaneD[((aIndex + 13513U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 14341U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 13355U)) & S_BLOCK1], 12U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 11020U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 11288U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCross, 6U) + RotL64(aIngress, 19U)) + (RotL64(aCarry, 57U) ^ RotL64(aPrevious, 43U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterI = ((aWandererH + RotL64(aPrevious, 13U)) + 17225673071833726819U) + aPhaseAOrbiterAssignSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = (((aWandererE + RotL64(aCross, 21U)) + RotL64(aCarry, 53U)) + 10301458382103627331U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = ((aWandererJ + RotL64(aScatter, 57U)) + RotL64(aCarry, 5U)) + 3960233050857362414U;
            aOrbiterK = (((aWandererG + RotL64(aIngress, 47U)) + RotL64(aCarry, 21U)) + 17768665685046605837U) + aNonceWordI;
            aOrbiterH = ((aWandererB + RotL64(aScatter, 38U)) + 14471018461213959767U) + aNonceWordA;
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 10730597892721340453U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 14863394003122760542U) ^ aNonceWordD;
            aOrbiterB = RotL64((aOrbiterB * 17731557030589257169U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 9948587274816688296U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 3573569431435100993U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2303922230056523077U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 8153670675740450590U) + aNonceWordJ;
            aOrbiterK = (((aOrbiterK ^ aOrbiterA) ^ 16438856577722561424U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterK = RotL64((aOrbiterK * 4689247488336908827U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 15765587867581925041U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 1082039522061775213U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 17023740047246402641U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 4202521649260798876U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 15877659681260461141U;
            aOrbiterH = RotL64((aOrbiterH * 11369910758551088173U), 27U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterB, 19U);
            aIngress = aIngress + (RotL64(aOrbiterI, 57U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterA, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aCross, 28U) + RotL64(aOrbiterB, 3U)) + aOrbiterA) + RotL64(aCarry, 5U)) + aNonceWordM);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 39U) + aOrbiterA) + RotL64(aOrbiterI, 39U)) + aPhaseAWandererUpdateSaltD[((aIndex + 6U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aIngress, 5U) + aOrbiterB) + RotL64(aOrbiterK, 11U)) + RotL64(aCarry, 19U)) + aNonceWordE);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterH, 56U)) + aOrbiterI) + aPhaseAWandererUpdateSaltC[((aIndex + 11U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aCross, 51U) + aOrbiterK) + RotL64(aOrbiterH, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 47U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererH, 58U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererG, 5U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 21762U)) & S_BLOCK1], 38U) ^ RotL64(aInvestLaneA[((aIndex + 17026U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 18307U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 17751U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 18822U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 17467U)) & S_BLOCK1], 14U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aIngress, 53U) ^ RotL64(aCarry, 10U)) + (RotL64(aCross, 27U) ^ RotL64(aPrevious, 39U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterK = ((((aWandererK + RotL64(aIngress, 29U)) + RotL64(aCarry, 51U)) + 12262991801139086177U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordA;
            aOrbiterG = (((aWandererI + RotL64(aScatter, 11U)) + RotL64(aCarry, 29U)) + 7963038771924890197U) + aNonceWordH;
            aOrbiterF = (((aWandererD + RotL64(aPrevious, 48U)) + 15540520327933568896U) + aPhaseAOrbiterAssignSaltF[((aIndex + 14U)) & S_SALT1]) + aNonceWordI;
            aOrbiterB = ((aWandererC + RotL64(aCross, 21U)) + RotL64(aCarry, 3U)) + 8745565892055020722U;
            aOrbiterJ = ((aWandererH + RotL64(aIngress, 37U)) + 16619329199683755286U) + aNonceWordK;
            //
            aOrbiterK = (((aOrbiterK + aOrbiterG) + 10865705026433867260U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1]) + aNonceWordO;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 2743368697984518059U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2989232417816919375U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 5556006271515473135U) + aNonceWordL;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 5355833281353498588U) ^ aNonceWordM;
            aOrbiterG = RotL64((aOrbiterG * 4190140212757841511U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 8313616108963479829U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterG) ^ 16657121016801866434U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterJ = RotL64((aOrbiterJ * 331533349428472477U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 16532226425013000833U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 5800465874932467232U;
            aOrbiterB = RotL64((aOrbiterB * 5966395771690704577U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 17882948163883121328U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 15029375310296563175U;
            aOrbiterK = RotL64((aOrbiterK * 17021415832288477713U), 29U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterG, 41U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 3U));
            aIngress = aIngress + RotL64(aOrbiterF, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aScatter, 30U) + RotL64(aOrbiterB, 39U)) + aOrbiterK) + aNonceWordF) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aCross, 21U) + aOrbiterB) + RotL64(aOrbiterJ, 23U)) + aNonceWordE);
            aWandererC = aWandererC + (((((RotL64(aIngress, 41U) + RotL64(aOrbiterJ, 13U)) + aOrbiterG) + RotL64(aCarry, 57U)) + aNonceWordB) + aPhaseAWandererUpdateSaltF[((aIndex + 13U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterG, 56U)) + aOrbiterK);
            aWandererI = aWandererI + ((((RotL64(aCross, 11U) + RotL64(aOrbiterF, 47U)) + aOrbiterJ) + RotL64(aCarry, 21U)) + aNonceWordP);
            //
            aCarry = aCarry + (RotL64(aWandererH, 60U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererC, 21U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 22872U)) & S_BLOCK1], 60U) ^ RotL64(aOperationLaneA[((aIndex + 26655U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 26495U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 24657U)) & S_BLOCK1], 11U) ^ RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 24348U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 24662U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCarry, 35U) + RotL64(aPrevious, 5U)) ^ (RotL64(aCross, 50U) ^ RotL64(aIngress, 19U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterD = ((aWandererD + RotL64(aScatter, 23U)) + 9855743441035905047U) + aNonceWordE;
            aOrbiterE = (((aWandererC + RotL64(aIngress, 37U)) + RotL64(aCarry, 47U)) + 8426286937143990276U) + aNonceWordL;
            aOrbiterI = ((aWandererF + RotL64(aCross, 5U)) + RotL64(aCarry, 11U)) + 7146752367170267002U;
            aOrbiterK = ((((aWandererI + RotL64(aPrevious, 14U)) + RotL64(aCarry, 27U)) + 12947210066678101726U) + aPhaseAOrbiterAssignSaltE[((aIndex + 19U)) & S_SALT1]) + aNonceWordH;
            aOrbiterB = (((aWandererH + RotL64(aScatter, 47U)) + 15902163559925328965U) + aPhaseAOrbiterAssignSaltC[((aIndex + 16U)) & S_SALT1]) + aNonceWordO;
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 8506649889346449469U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 8226286036430263052U) ^ aNonceWordK;
            aOrbiterI = RotL64((aOrbiterI * 7264199281303956141U), 23U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 2703047093452420216U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 6769351326360139560U;
            aOrbiterB = RotL64((aOrbiterB * 5318104980014706265U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 9857025533281333281U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 238297452132277585U;
            aOrbiterE = RotL64((aOrbiterE * 12974709749856065985U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 7203572312072908931U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 12497027346166575632U) ^ aNonceWordC;
            aOrbiterD = RotL64((aOrbiterD * 1703586436725662307U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 473851890609048879U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 1664484956453886047U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8566500756326590209U), 11U);
            //
            aIngress = RotL64(aOrbiterB, 3U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterE, 13U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterK, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aIngress, 35U) + aOrbiterK) + RotL64(aOrbiterD, 37U)) + RotL64(aCarry, 43U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 5U) + aOrbiterD) + RotL64(aOrbiterE, 47U));
            aWandererF = aWandererF + (((((RotL64(aCross, 43U) + RotL64(aOrbiterI, 11U)) + aOrbiterB) + RotL64(aCarry, 23U)) + aNonceWordB) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 57U) + aOrbiterK) + RotL64(aOrbiterI, 57U)) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 22U) + RotL64(aOrbiterK, 26U)) + aOrbiterE) + aNonceWordI);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 29U));
            aCarry = aCarry + (RotL64(aWandererI, 44U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererC, 13U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 31078U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneA[((aIndex + 28044U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31478U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 32669U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 29981U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 30810U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCross, 57U)) ^ (RotL64(aCarry, 24U) + RotL64(aPrevious, 41U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterH = ((aWandererF + RotL64(aCross, 19U)) + 6467297102954816305U) + aNonceWordF;
            aOrbiterK = ((((aWandererB + RotL64(aScatter, 27U)) + RotL64(aCarry, 41U)) + 7921154109831114952U) + aPhaseAOrbiterAssignSaltD[((aIndex + 4U)) & S_SALT1]) + aNonceWordG;
            aOrbiterG = (aWandererE + RotL64(aPrevious, 11U)) + 5701131763215638919U;
            aOrbiterE = ((((aWandererA + RotL64(aIngress, 43U)) + RotL64(aCarry, 57U)) + 10022999076719002684U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 22U)) & S_SALT1]) + aNonceWordN;
            aOrbiterC = (((aWandererJ + RotL64(aPrevious, 52U)) + RotL64(aCarry, 27U)) + 4367135243038982316U) + aNonceWordJ;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 14445846824810383592U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 7683697954545773253U;
            aOrbiterG = RotL64((aOrbiterG * 4832124801510084629U), 47U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterC) + 17517006750428030899U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordD;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 2052484792684025476U) ^ aNonceWordO;
            aOrbiterH = RotL64((aOrbiterH * 12463117571122469643U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 6279463052085808926U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 679280153651813684U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 3047031560593583881U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 2939516520188460569U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 1960616434964712325U;
            aOrbiterE = RotL64((aOrbiterE * 15145998415466343039U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 12273819390719947361U) + aNonceWordK;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 5685033154709449397U;
            aOrbiterK = RotL64((aOrbiterK * 9845666295874714959U), 57U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterG, 14U);
            aIngress = aIngress + (RotL64(aOrbiterE, 3U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterH, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aPrevious, 27U) + RotL64(aOrbiterC, 50U)) + aOrbiterG) + RotL64(aCarry, 23U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 3U) + aOrbiterK) + RotL64(aOrbiterH, 35U));
            aWandererF = aWandererF + (((((RotL64(aIngress, 51U) + RotL64(aOrbiterH, 13U)) + aOrbiterG) + RotL64(aCarry, 37U)) + aNonceWordI) + aPhaseAWandererUpdateSaltC[((aIndex + 27U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aCross, 12U) + RotL64(aOrbiterE, 21U)) + aOrbiterK) + aNonceWordL);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 41U) + aOrbiterH) + RotL64(aOrbiterE, 5U)) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 3U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererF, 40U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererB, 13U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x901CE48358326597ULL + 0x838AF885DAC10277ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x9E6FC219F5B207BFULL + 0xB37703A83B6C5788ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xBCF53B20AA1D05E1ULL + 0x897196CECEF80108ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xD3D3C658CBE9C9E7ULL + 0xEDC4194EDC3D190EULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xA537778D5862DE73ULL + 0xA06DC2694AC7D206ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xC4D3FCA4B57CBE6BULL + 0x92C8058E41A8FBBFULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xB3B9665D47E8C185ULL + 0xBDF40A03E9E32CBEULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xBDB26B3A9CA9E399ULL + 0xD8F725E2EEAD1EC5ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xBEF03ACFC386051DULL + 0xD1A152787DA4F7F5ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xD788DB4AA9377A63ULL + 0x91E8E8D8570A5C99ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xD6429EEF2CB577CDULL + 0xF1E7C3D795FFE7A9ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xF0754B56DEB4A569ULL + 0x83622874C103ECF8ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xDAECA44CC0691063ULL + 0xC5F9AA5E6EC8E8FDULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0x8BC7F41F24ACA6CDULL + 0xEC493C51972D4B62ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xA2C477C01A757B39ULL + 0xFE626E378B0E3591ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0x9326BD424E095EDDULL + 0xBF4952BA86FD3EBBULL);
    // GSeedRunSeed_C seed_loop_b (start)
    {
        // GSeedRunSeed_C seed_loop_b lane group
        // read from: aOperationLaneA, aOperationLaneB, aExpandLaneB, aOperationLaneC, aOperationLaneD, aFireLaneB, aInvestLaneC, aExpandLaneA, aExpandLaneC, aInvestLaneD, aFireLaneD, aWorkLaneA, aFireLaneA, aWorkLaneB, aFireLaneC, aWorkLaneC, aExpandLaneD
        // write to: aInvestLaneC, aInvestLaneD, aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // seed_loop_b loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aExpandLaneB
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aExpandLaneB forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aFireLaneB
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aFireLaneB backward/forward random
        // write to: aInvestLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 4083U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneB[((aIndex + 4950U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 1255U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 1980U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 4756U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 4760U)) & S_BLOCK1], 52U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aIngress, 39U) + RotL64(aCarry, 18U)) + (RotL64(aPrevious, 53U) ^ RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterC = (((aWandererI + RotL64(aScatter, 13U)) + 13333509828310369865U) + aPhaseBOrbiterAssignSaltE[((aIndex + 26U)) & S_SALT1]) + aNonceWordL;
            aOrbiterE = ((aWandererJ + RotL64(aIngress, 23U)) + RotL64(aCarry, 5U)) + 7645352517103840797U;
            aOrbiterK = ((aWandererA + RotL64(aCross, 60U)) + 5310766306660062655U) + aPhaseBOrbiterAssignSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = ((aWandererH + RotL64(aPrevious, 19U)) + RotL64(aCarry, 41U)) + 5165635069832352932U;
            aOrbiterH = (aWandererK + RotL64(aScatter, 47U)) + 15684141764734281849U;
            aOrbiterI = (((aWandererG + RotL64(aCross, 39U)) + RotL64(aCarry, 19U)) + 3327963374225061738U) + aNonceWordO;
            aOrbiterA = ((aWandererD + RotL64(aIngress, 27U)) + 8625811794878848871U) + aNonceWordI;
            aOrbiterF = (aWandererE + RotL64(aPrevious, 3U)) + 7598657468430485291U;
            aOrbiterD = ((aWandererB + RotL64(aCross, 34U)) + 2881171216276746485U) + aNonceWordP;
            //
            aOrbiterC = (((aOrbiterC + aOrbiterE) + 10237691227222918101U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1]) + aNonceWordM;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 6419254255884834497U;
            aOrbiterK = RotL64((aOrbiterK * 3816625473642865305U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 4238455444646479956U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 14936613353493061492U;
            aOrbiterI = RotL64((aOrbiterI * 3544216916806292273U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 15324699725208372627U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 9506640480601832011U;
            aOrbiterH = RotL64((aOrbiterH * 12819564111348390227U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 3709149613660215641U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 1724290199312754307U;
            aOrbiterE = RotL64((aOrbiterE * 12597580418257897965U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 13191172833570139194U) + aNonceWordE;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 3686087945377837886U;
            aOrbiterF = RotL64((aOrbiterF * 10883609557429936283U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 10418330386245397022U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 5383531313632347245U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2987755379396160073U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 7414716553072652212U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 11301761123966206201U;
            aOrbiterA = RotL64((aOrbiterA * 1546727321088592187U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 8570229732236388847U) + aNonceWordK;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 8773754460060264773U;
            aOrbiterD = RotL64((aOrbiterD * 3251360788932563495U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 13636929800504199371U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 5486599841558573720U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2867914211589815153U), 51U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterH, 60U);
            aIngress = aIngress + (RotL64(aOrbiterE, 43U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 23U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 39U));
            aIngress = aIngress + RotL64(aOrbiterA, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 41U) + RotL64(aOrbiterH, 5U)) + aOrbiterC) + RotL64(aCarry, 11U)) + aNonceWordB);
            aWandererH = aWandererH ^ ((((RotL64(aScatter, 47U) + aOrbiterB) + RotL64(aOrbiterC, 41U)) + aNonceWordA) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aCross, 28U) + RotL64(aOrbiterB, 29U)) + aOrbiterK);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 51U) + RotL64(aOrbiterI, 18U)) + aOrbiterC) + aNonceWordG);
            aWandererE = aWandererE + (((RotL64(aCross, 57U) + RotL64(aOrbiterH, 23U)) + aOrbiterF) + RotL64(aCarry, 3U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 11U) + aOrbiterH) + RotL64(aOrbiterA, 51U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 37U) + aOrbiterF) + RotL64(aOrbiterI, 47U)) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 4U) + RotL64(aOrbiterH, 36U)) + aOrbiterD);
            aWandererG = aWandererG + ((RotL64(aIngress, 23U) + aOrbiterB) + RotL64(aOrbiterE, 57U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererE);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 29U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 10U));
            aCarry = aCarry + (RotL64(aWandererA, 51U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererG, 5U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aInvestLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_b loop 2
        // ingress from: aInvestLaneC, aOperationLaneC, aOperationLaneD, aExpandLaneA
        // ingress directions: aInvestLaneC forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aExpandLaneA forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aExpandLaneC
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aExpandLaneC backward/forward random
        // write to: aInvestLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneC[((aIndex + 9867U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneC[((aIndex + 6385U)) & S_BLOCK1], 47U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 8939U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneA[((aIndex + 7565U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 9767U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 10423U)) & S_BLOCK1], 50U));
            aCross ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 9615U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aIngress, 27U) ^ RotL64(aCarry, 53U)) ^ (RotL64(aCross, 39U) + RotL64(aPrevious, 14U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterH = (aWandererB + RotL64(aCross, 35U)) + 11039986441331892533U;
            aOrbiterE = ((aWandererI + RotL64(aPrevious, 57U)) + RotL64(aCarry, 11U)) + 6256024955965426119U;
            aOrbiterF = (aWandererF + RotL64(aIngress, 22U)) + 9857443189988995666U;
            aOrbiterA = ((aWandererE + RotL64(aScatter, 47U)) + 11900944813380998208U) + aNonceWordF;
            aOrbiterI = (aWandererG + RotL64(aIngress, 43U)) + 8422577734978875541U;
            aOrbiterB = (aWandererD + RotL64(aPrevious, 3U)) + 3100835100713928724U;
            aOrbiterK = (((aWandererK + RotL64(aCross, 30U)) + RotL64(aCarry, 29U)) + 11871553509810206993U) + aPhaseBOrbiterAssignSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = (((aWandererC + RotL64(aScatter, 53U)) + RotL64(aCarry, 39U)) + 17614749493763417027U) + aNonceWordG;
            aOrbiterG = ((aWandererJ + RotL64(aIngress, 39U)) + 3638372131856199916U) + aPhaseBOrbiterAssignSaltC[((aIndex + 22U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 6582275259281025770U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 17016882418498941958U;
            aOrbiterF = RotL64((aOrbiterF * 4269869255230867823U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 1747214688658984715U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 9356088987044015278U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 16221733545319753695U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 4056238112133473456U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 16013150119949532998U;
            aOrbiterE = RotL64((aOrbiterE * 12913648646318115315U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 16076621211111834889U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 9940824359571581765U) ^ aNonceWordD;
            aOrbiterH = RotL64((aOrbiterH * 11624767861336495331U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 15624084004784515753U) + aNonceWordC;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 7630989544834680335U;
            aOrbiterD = RotL64((aOrbiterD * 12261063237156822067U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 18003586430673313786U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 1654118743290334161U) ^ aNonceWordB;
            aOrbiterA = RotL64((aOrbiterA * 1153250137357176071U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 3254189676528343910U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 15629083361573065165U;
            aOrbiterK = RotL64((aOrbiterK * 17024833368570949107U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 10056859810555674806U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 15976683222786846254U;
            aOrbiterG = RotL64((aOrbiterG * 2801754232182942635U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 11872378594829637933U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 7633773773528713489U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 8218288492011593353U), 37U);
            //
            aIngress = RotL64(aOrbiterG, 11U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterD, 37U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterA, 34U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterK, 41U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterE, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aPrevious, 37U) + aOrbiterA) + RotL64(aOrbiterI, 39U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 52U) + aOrbiterE) + RotL64(aOrbiterI, 43U)) + aNonceWordJ);
            aWandererF = aWandererF + (((RotL64(aCross, 41U) + aOrbiterH) + RotL64(aOrbiterA, 47U)) + aPhaseBWandererUpdateSaltE[((aIndex + 13U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterG, 58U)) + aOrbiterD) + aNonceWordA);
            aWandererK = aWandererK + (((RotL64(aPrevious, 27U) + RotL64(aOrbiterF, 51U)) + aOrbiterK) + RotL64(aCarry, 53U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterG, 29U)) + aOrbiterI);
            aWandererI = aWandererI + (((RotL64(aIngress, 13U) + RotL64(aOrbiterE, 3U)) + aOrbiterG) + aNonceWordO);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 18U) + aOrbiterG) + RotL64(aOrbiterK, 11U)) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aIngress, 3U) + aOrbiterB) + RotL64(aOrbiterI, 18U)) + RotL64(aCarry, 13U)) + aNonceWordN);
            //
            aCarry = aCarry + (RotL64(aWandererD, 44U) ^ aWandererJ);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 51U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 35U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 29U));
            aCarry = aCarry + RotL64(aWandererF, 47U);
            aCarry = aCarry + RotL64(aIngress, 56U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aInvestLaneD[((aIndex + 14753U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneA[((aIndex + 16338U)) & S_BLOCK1], 30U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 12710U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 13591U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneC[((aIndex + 13397U)) & S_BLOCK1], 22U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCarry, 35U) + RotL64(aPrevious, 18U)) ^ (RotL64(aCross, 5U) ^ RotL64(aIngress, 47U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterC = ((aWandererC + RotL64(aIngress, 29U)) + 10915618884692072446U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterA = (((aWandererK + RotL64(aScatter, 53U)) + 12634922308499254909U) + aPhaseBOrbiterAssignSaltD[((aIndex + 16U)) & S_SALT1]) + aNonceWordN;
            aOrbiterD = (aWandererB + RotL64(aCross, 4U)) + 6533934734564499389U;
            aOrbiterK = (((aWandererE + RotL64(aPrevious, 41U)) + RotL64(aCarry, 3U)) + 6744203303756105181U) + aNonceWordL;
            aOrbiterF = ((aWandererI + RotL64(aScatter, 11U)) + RotL64(aCarry, 41U)) + 13086782386652045658U;
            aOrbiterI = ((aWandererG + RotL64(aPrevious, 57U)) + 5693840533331397822U) + aNonceWordP;
            aOrbiterE = ((aWandererF + RotL64(aCross, 20U)) + RotL64(aCarry, 29U)) + 1803663542535024611U;
            aOrbiterH = ((aWandererA + RotL64(aIngress, 37U)) + 3597219300593287708U) + aNonceWordO;
            aOrbiterB = (aWandererH + RotL64(aCross, 47U)) + 1429753448204448904U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 17229017825587322715U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 1137574712801062932U;
            aOrbiterD = RotL64((aOrbiterD * 3645832160939819415U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 2401991077004083378U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 1332473247826139292U;
            aOrbiterF = RotL64((aOrbiterF * 15029831858261506447U), 37U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 11730946340796899885U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 15319163439700390962U;
            aOrbiterI = RotL64((aOrbiterI * 1349242001887975499U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 4744141870145159917U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 6067132201862688684U;
            aOrbiterE = RotL64((aOrbiterE * 6046100687757836027U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 14991509179286371800U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 4342608825699398682U) ^ aNonceWordE;
            aOrbiterC = RotL64((aOrbiterC * 10240526103933275875U), 53U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 3727521409410742075U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 3302027219498304367U;
            aOrbiterK = RotL64((aOrbiterK * 12153634588200479559U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 6039539483340398858U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterE) ^ 2902581519976937051U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterB = RotL64((aOrbiterB * 2057584328877854239U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 12332784713738947242U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 13761272577223712786U;
            aOrbiterH = RotL64((aOrbiterH * 14930145045480030821U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 2947946397617043735U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 11107014023853644521U;
            aOrbiterA = RotL64((aOrbiterA * 15030903626191481831U), 43U);
            //
            aIngress = RotL64(aOrbiterK, 57U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterE, 60U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterA, 37U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 11U));
            aIngress = aIngress + RotL64(aOrbiterI, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aScatter, 58U) + RotL64(aOrbiterE, 19U)) + aOrbiterH) + RotL64(aCarry, 47U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterC, 53U)) + aOrbiterE);
            aWandererK = aWandererK + ((RotL64(aIngress, 47U) + RotL64(aOrbiterK, 14U)) + aOrbiterI);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 41U) + aOrbiterA) + RotL64(aOrbiterB, 23U)) + aPhaseBWandererUpdateSaltF[((aIndex + 22U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aCross, 54U) + RotL64(aOrbiterE, 29U)) + aOrbiterD);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 23U) + RotL64(aOrbiterD, 37U)) + aOrbiterI) + aNonceWordH);
            aWandererB = aWandererB + ((((RotL64(aIngress, 3U) + RotL64(aOrbiterA, 57U)) + aOrbiterH) + RotL64(aCarry, 39U)) + aNonceWordD);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterF, 42U)) + aOrbiterC) + aPhaseBWandererUpdateSaltB[((aIndex + 27U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aCross, 19U) + aOrbiterH) + RotL64(aOrbiterF, 3U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 27U));
            aCarry = aCarry + (RotL64(aWandererC, 24U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererH);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 19U));
            aCarry = aCarry + RotL64(aWandererA, 3U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 17554U)) & S_BLOCK1], 3U) ^ RotL64(aInvestLaneC[((aIndex + 19030U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 19310U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 19113U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneD[((aIndex + 18836U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCross, 41U) ^ RotL64(aPrevious, 13U)) + (RotL64(aCarry, 58U) + RotL64(aIngress, 27U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterG = (aWandererH + RotL64(aPrevious, 36U)) + 16462052553719977502U;
            aOrbiterJ = (aWandererC + RotL64(aIngress, 43U)) + 12337064059566619581U;
            aOrbiterD = ((aWandererK + RotL64(aScatter, 19U)) + 15801005007094515447U) + aNonceWordA;
            aOrbiterB = (aWandererG + RotL64(aCross, 57U)) + 8228706742665081656U;
            aOrbiterH = ((((aWandererE + RotL64(aPrevious, 13U)) + RotL64(aCarry, 5U)) + 11006723027845190869U) + aPhaseBOrbiterAssignSaltE[((aIndex + 25U)) & S_SALT1]) + aNonceWordM;
            aOrbiterK = ((((aWandererB + RotL64(aCross, 53U)) + RotL64(aCarry, 37U)) + 18173765337829177450U) + aPhaseBOrbiterAssignSaltB[((aIndex + 23U)) & S_SALT1]) + aNonceWordC;
            aOrbiterC = ((aWandererF + RotL64(aScatter, 48U)) + RotL64(aCarry, 47U)) + 530215083653542558U;
            aOrbiterE = (aWandererJ + RotL64(aIngress, 5U)) + 6608611827035564511U;
            aOrbiterI = (aWandererA + RotL64(aPrevious, 29U)) + 2246051826221626809U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 5228575308895381421U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterG) ^ 10999213210689606857U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterD = RotL64((aOrbiterD * 5467601259546342925U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 3773371037240485696U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 8887985779436152504U;
            aOrbiterH = RotL64((aOrbiterH * 698713082830739677U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 11150566414723818350U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 8336366151003049546U;
            aOrbiterC = RotL64((aOrbiterC * 9033771197242493699U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 13233968794237090787U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 8172558473508478819U;
            aOrbiterB = RotL64((aOrbiterB * 17837070423649268435U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 133564480283347997U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 15104810248883567064U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 706802420642303533U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 9138629520201127075U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 13993086066341664080U;
            aOrbiterG = RotL64((aOrbiterG * 4875046427147105077U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 6547273508580516932U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 9838727018769865759U) ^ aNonceWordG;
            aOrbiterE = RotL64((aOrbiterE * 11395273371936839815U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 11685694999526122626U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 8945983172566303116U;
            aOrbiterI = RotL64((aOrbiterI * 17791527981004597623U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 17606249889617356327U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 9296903152000480008U;
            aOrbiterK = RotL64((aOrbiterK * 18066622289408024413U), 19U);
            //
            aIngress = RotL64(aOrbiterI, 53U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterB, 57U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 35U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 48U));
            aIngress = aIngress + RotL64(aOrbiterK, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 11U) + aOrbiterG) + RotL64(aOrbiterJ, 18U)) + aPhaseBWandererUpdateSaltD[((aIndex + 8U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aScatter, 23U) + aOrbiterI) + RotL64(aOrbiterH, 3U)) + RotL64(aCarry, 19U)) + aNonceWordD);
            aWandererK = aWandererK ^ ((((RotL64(aIngress, 39U) + RotL64(aOrbiterE, 27U)) + aOrbiterB) + aNonceWordJ) + aPhaseBWandererUpdateSaltC[((aIndex + 10U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aCross, 44U) + aOrbiterJ) + RotL64(aOrbiterE, 13U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 19U) + aOrbiterJ) + RotL64(aOrbiterB, 46U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 29U) + aOrbiterJ) + RotL64(aOrbiterC, 51U)) + RotL64(aCarry, 29U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 35U) + aOrbiterC) + RotL64(aOrbiterK, 23U));
            aWandererC = aWandererC + ((RotL64(aScatter, 50U) + aOrbiterD) + RotL64(aOrbiterH, 57U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterJ, 41U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 47U));
            aCarry = aCarry + (RotL64(aWandererA, 35U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererJ, 40U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererF, 23U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererC, 53U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 26960U)) & S_BLOCK1], 3U) ^ RotL64(aInvestLaneD[((aIndex + 26465U)) & S_BLOCK1], 38U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 23191U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23614U)) & S_BLOCK1], 37U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 27033U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aIngress, 12U) + RotL64(aCross, 43U)) ^ (RotL64(aPrevious, 57U) ^ RotL64(aCarry, 27U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterC = (aWandererD + RotL64(aPrevious, 22U)) + 12426357877879529292U;
            aOrbiterE = (aWandererE + RotL64(aIngress, 53U)) + 12604900366173639176U;
            aOrbiterF = ((aWandererG + RotL64(aCross, 47U)) + RotL64(aCarry, 29U)) + 13511119007338929401U;
            aOrbiterG = ((aWandererK + RotL64(aScatter, 27U)) + 9878720081166788060U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = ((aWandererA + RotL64(aCross, 3U)) + 15463195409806395076U) + aNonceWordF;
            aOrbiterI = (aWandererH + RotL64(aPrevious, 43U)) + 6407922778852833423U;
            aOrbiterD = ((aWandererI + RotL64(aIngress, 11U)) + RotL64(aCarry, 13U)) + 7690427254160734016U;
            aOrbiterK = ((aWandererB + RotL64(aScatter, 18U)) + 18030974031722143619U) + aNonceWordL;
            aOrbiterA = (((aWandererC + RotL64(aPrevious, 57U)) + RotL64(aCarry, 41U)) + 17983938038322737041U) + aPhaseBOrbiterAssignSaltC[((aIndex + 8U)) & S_SALT1];
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 16605512170117753884U) + aNonceWordH;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 681802273302348322U;
            aOrbiterF = RotL64((aOrbiterF * 14608920184802647123U), 47U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterH) + 15550312921312083819U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 17824154101711884508U;
            aOrbiterC = RotL64((aOrbiterC * 7358612830654795357U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 1939207786756735430U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 3132864634777826569U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 13606281919426730325U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 12822929773923954849U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 16576106045887115660U;
            aOrbiterI = RotL64((aOrbiterI * 16370914370769903051U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 2398825881649235260U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 13700821892926092479U;
            aOrbiterK = RotL64((aOrbiterK * 10830623703416956043U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 2439833784883391606U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 15870638514107637833U;
            aOrbiterD = RotL64((aOrbiterD * 3797380922767479287U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 9165457123134229670U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 8736642509192659417U;
            aOrbiterA = RotL64((aOrbiterA * 16219277537523484065U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 9232719746484835693U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 7826680628853322541U;
            aOrbiterH = RotL64((aOrbiterH * 12578050118133526187U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 14323652326982518782U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 2254524512851399313U;
            aOrbiterG = RotL64((aOrbiterG * 4119339547645451149U), 23U);
            //
            aIngress = RotL64(aOrbiterG, 43U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterC, 35U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 24U));
            aIngress = aIngress + (RotL64(aOrbiterD, 3U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterI, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aCross, 18U) + RotL64(aOrbiterE, 4U)) + aOrbiterD) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterK, 35U)) + aOrbiterC);
            aWandererB = aWandererB + (((RotL64(aPrevious, 47U) + aOrbiterE) + RotL64(aOrbiterI, 27U)) + RotL64(aCarry, 37U));
            aWandererK = aWandererK ^ ((((RotL64(aScatter, 57U) + aOrbiterH) + RotL64(aOrbiterK, 57U)) + aNonceWordC) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterK, 47U)) + aOrbiterA) + aNonceWordO);
            aWandererA = aWandererA ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterH, 43U)) + aOrbiterG);
            aWandererE = aWandererE + ((((RotL64(aScatter, 53U) + RotL64(aOrbiterG, 12U)) + aOrbiterI) + RotL64(aCarry, 47U)) + aNonceWordM);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterD, 39U)) + aOrbiterF);
            aWandererG = aWandererG + (((RotL64(aPrevious, 38U) + RotL64(aOrbiterF, 51U)) + aOrbiterK) + aNonceWordG);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 12U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 3U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 27U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 35U));
            aCarry = aCarry + RotL64(aWandererC, 43U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_b loop 6
        // ingress from: aWorkLaneC, aWorkLaneA, aExpandLaneD
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aExpandLaneD forward/backward random
        // cross from: aWorkLaneB, aOperationLaneB
        // cross directions: aWorkLaneB backward forced, aOperationLaneB backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 30853U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneA[((aIndex + 32122U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 27591U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 28559U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 30582U)) & S_BLOCK1], 54U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aIngress, 41U) ^ RotL64(aCross, 23U)) ^ (RotL64(aCarry, 54U) + RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterH = ((aWandererD + RotL64(aIngress, 26U)) + RotL64(aCarry, 37U)) + 9751314027302668907U;
            aOrbiterJ = (aWandererH + RotL64(aCross, 37U)) + 12175450995523107056U;
            aOrbiterG = ((aWandererG + RotL64(aScatter, 51U)) + 17519694958730119552U) + aNonceWordK;
            aOrbiterE = ((((aWandererA + RotL64(aPrevious, 5U)) + RotL64(aCarry, 51U)) + 9093525527925682263U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordD;
            aOrbiterB = ((aWandererE + RotL64(aScatter, 10U)) + RotL64(aCarry, 19U)) + 3713831321786810138U;
            aOrbiterI = (aWandererF + RotL64(aCross, 21U)) + 10108355209191835040U;
            aOrbiterK = (aWandererC + RotL64(aIngress, 43U)) + 12956307447311314768U;
            aOrbiterA = ((aWandererK + RotL64(aPrevious, 57U)) + 1904298513945877359U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = (aWandererB + RotL64(aIngress, 47U)) + 4658049993308574460U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 9826333658248851902U) + aNonceWordI;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 12058666914724365134U;
            aOrbiterG = RotL64((aOrbiterG * 964233873188373939U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 2516574707110528099U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 13335308331049750235U;
            aOrbiterB = RotL64((aOrbiterB * 5880227828760598587U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 8230749255538495304U) + aNonceWordA;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 16536559486797811486U) ^ aNonceWordE;
            aOrbiterA = RotL64((aOrbiterA * 7097036838156464969U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 12387639130570188998U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 8459259798142872020U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 8001346480955847013U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 16083784052002800300U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 1957284290736468379U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5046501301740813065U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 7349538179311335863U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 16395170077006105258U) ^ aNonceWordL;
            aOrbiterC = RotL64((aOrbiterC * 4230485452156662763U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 3317652065873784068U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 5517155804799120700U;
            aOrbiterJ = RotL64((aOrbiterJ * 9789270651974719183U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 5568525912112200094U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 9334250662962319598U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5034887614541768961U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 5641394627075994165U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 13524971148931512745U;
            aOrbiterH = RotL64((aOrbiterH * 3699457147759854357U), 27U);
            //
            aIngress = RotL64(aOrbiterH, 53U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterE, 14U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 11U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 27U));
            aIngress = aIngress + RotL64(aOrbiterI, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterG, 21U)) + aOrbiterE);
            aWandererC = aWandererC + ((((RotL64(aScatter, 57U) + RotL64(aOrbiterG, 13U)) + aOrbiterI) + RotL64(aCarry, 5U)) + aPhaseBWandererUpdateSaltF[((aIndex + 11U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aCross, 27U) + RotL64(aOrbiterH, 3U)) + aOrbiterJ) + aNonceWordH);
            aWandererH = aWandererH + (((RotL64(aPrevious, 35U) + aOrbiterA) + RotL64(aOrbiterC, 34U)) + RotL64(aCarry, 37U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 10U) + aOrbiterB) + RotL64(aOrbiterK, 39U)) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aCross, 43U) + aOrbiterH) + RotL64(aOrbiterG, 47U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterJ, 57U)) + aOrbiterI);
            aWandererF = aWandererF + (((RotL64(aPrevious, 39U) + aOrbiterG) + RotL64(aOrbiterC, 51U)) + aNonceWordC);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 48U) + RotL64(aOrbiterC, 26U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 30U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 3U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 23U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 27U));
            aCarry = aCarry + RotL64(aWandererC, 41U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xC76821292B912E99ULL + 0x812650B72718A5F0ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xD71A237EEF2029B7ULL + 0xE05162A7D629AA6DULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xB7E29D3249364B3DULL + 0xDFE5E09FDCD37199ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xDD5F1470DD7ACAE7ULL + 0xCB418F2978D9BC4CULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xEFA99951BDE045C1ULL + 0xC5E1D48F1FA8D291ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xD3E6ADF8E4397EEFULL + 0xBA2D8B110417F7A7ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xE7EA6456E7C7FDDDULL + 0x86619C58EB2FADDFULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xDAA7CA414DFEB5FFULL + 0xD26F6942C64AC662ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x83AB7E354981A275ULL + 0xCA1F3B93214F49C5ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xC5DDFFDD76D311E3ULL + 0xF185D6ED351F49B4ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xC3932F5CCBA943DBULL + 0xD76FFCB1D8CC5958ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xDE367F56B403BEBFULL + 0xC22DE11BB2F24924ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xAB24CA74292844DFULL + 0x9847FBC50D8104EBULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x97AC3A3ACE1D7D2FULL + 0xE52BDEE225951671ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xE86FD790AD926CC9ULL + 0xDEFFCAFBFE353541ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xF757AB1FD8FF761BULL + 0xAA7169A938D20F4CULL);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 430U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneB[((aIndex + 4423U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 2775U)) & S_BLOCK1], 38U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 2596U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 34U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 1941U)) & S_BLOCK1], 14U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aIngress, 11U) ^ RotL64(aCross, 23U)) + (RotL64(aPrevious, 47U) + RotL64(aCarry, 60U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterB = ((aWandererH + RotL64(aPrevious, 27U)) + RotL64(aCarry, 3U)) + 7651355040951791298U;
            aOrbiterC = ((aWandererF + RotL64(aIngress, 48U)) + 13988210277931659312U) + aNonceWordD;
            aOrbiterF = ((aWandererI + RotL64(aScatter, 57U)) + 9846849412579537783U) + aPhaseDOrbiterAssignSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterK = (aWandererJ + RotL64(aCross, 39U)) + 12746719939495876158U;
            aOrbiterG = (((aWandererG + RotL64(aIngress, 19U)) + RotL64(aCarry, 51U)) + 11498066185182895284U) + aNonceWordK;
            aOrbiterJ = (((aWandererK + RotL64(aScatter, 3U)) + RotL64(aCarry, 21U)) + 11101058955193080232U) + aNonceWordA;
            aOrbiterA = ((aWandererE + RotL64(aCross, 11U)) + 15513734459555672046U) + aPhaseDOrbiterAssignSaltF[((aIndex + 21U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 15711108675349394643U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 4771231759949468556U;
            aOrbiterF = RotL64((aOrbiterF * 9806191054594333615U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 11449258010811305256U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 17036938391509986723U;
            aOrbiterB = RotL64((aOrbiterB * 7411466953205347639U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 6999245666776654250U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 2106819066263369528U;
            aOrbiterG = RotL64((aOrbiterG * 13005885810757743129U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 12716183358903477216U) + aNonceWordF;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 16752724547046059889U) ^ aNonceWordB;
            aOrbiterA = RotL64((aOrbiterA * 11475905692393034141U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 17623077680983093163U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 6726003022297274986U;
            aOrbiterK = RotL64((aOrbiterK * 14709385877103232653U), 21U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 2842410225096524740U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 9235178377537910514U;
            aOrbiterC = RotL64((aOrbiterC * 11813751114775673845U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 2619888019860844610U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterC) ^ 6295481948199619613U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterJ = RotL64((aOrbiterJ * 15429161806953951205U), 51U);
            //
            aIngress = RotL64(aOrbiterG, 11U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterB, 43U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterC, 60U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterA, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterG, 46U)) + aOrbiterF) + aPhaseDWandererUpdateSaltD[((aIndex + 12U)) & S_SALT1]);
            aWandererK = aWandererK + (((((RotL64(aPrevious, 51U) + RotL64(aOrbiterK, 5U)) + aOrbiterB) + RotL64(aCarry, 3U)) + aNonceWordI) + aPhaseDWandererUpdateSaltE[((aIndex + 27U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 10U) + RotL64(aOrbiterC, 35U)) + aOrbiterA);
            aWandererH = aWandererH + ((RotL64(aCross, 19U) + RotL64(aOrbiterB, 13U)) + aOrbiterC);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 39U) + RotL64(aOrbiterF, 53U)) + aOrbiterJ) + aNonceWordJ);
            aWandererE = aWandererE + ((((RotL64(aCross, 27U) + aOrbiterF) + RotL64(aOrbiterA, 29U)) + RotL64(aCarry, 47U)) + aNonceWordC);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 3U) + aOrbiterA) + RotL64(aOrbiterJ, 19U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 60U));
            aCarry = aCarry + (RotL64(aWandererE, 35U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererJ, 43U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererH, 5U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = (RotL64(aSnowLaneA[((aIndex + 7260U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneC[((aIndex + 8654U)) & S_BLOCK1], 27U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 8707U)) & S_BLOCK1], 35U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 7255U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 6852U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 6977U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 8155U)) & S_BLOCK1], 22U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCross, 57U) + RotL64(aIngress, 44U)) ^ (RotL64(aPrevious, 19U) ^ RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterJ = ((aWandererJ + RotL64(aPrevious, 4U)) + 15813325389431304548U) + aNonceWordF;
            aOrbiterF = (aWandererG + RotL64(aIngress, 35U)) + 2223874171125403602U;
            aOrbiterA = (((aWandererE + RotL64(aScatter, 21U)) + RotL64(aCarry, 41U)) + 5510483568496824130U) + aNonceWordE;
            aOrbiterD = (((aWandererF + RotL64(aCross, 41U)) + 15474152493495661876U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordH;
            aOrbiterE = ((((aWandererK + RotL64(aIngress, 51U)) + RotL64(aCarry, 21U)) + 16846339705130829195U) + aPhaseDOrbiterAssignSaltE[((aIndex + 28U)) & S_SALT1]) + aNonceWordK;
            aOrbiterK = ((aWandererI + RotL64(aCross, 57U)) + RotL64(aCarry, 5U)) + 1289670576865739669U;
            aOrbiterI = (aWandererC + RotL64(aPrevious, 11U)) + 18017354919647006944U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 8539685539928984921U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterJ) ^ 3333721400836704048U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterA = RotL64((aOrbiterA * 3745286323481400085U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 2261560416623815491U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 4377786131746816567U;
            aOrbiterJ = RotL64((aOrbiterJ * 9164777834392621157U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 18047393176583722719U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 8184724021940434631U;
            aOrbiterD = RotL64((aOrbiterD * 9800116157750921119U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 10469895939183324807U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterE) ^ 14543391765109879223U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterF = RotL64((aOrbiterF * 4817987697437667225U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 5757225781746158178U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 3539000495894022869U;
            aOrbiterK = RotL64((aOrbiterK * 1032298408884695925U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 11288971092707065923U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 2761384065186568294U;
            aOrbiterI = RotL64((aOrbiterI * 3323838837427471051U), 23U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 7120580145300417101U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 6977246291769372866U) ^ aNonceWordB;
            aOrbiterE = RotL64((aOrbiterE * 15170353875184253779U), 35U);
            //
            aIngress = RotL64(aOrbiterA, 23U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterK, 13U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 5U));
            aIngress = aIngress + RotL64(aOrbiterE, 42U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aIngress, 47U) + aOrbiterE) + RotL64(aOrbiterI, 3U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 53U) + RotL64(aOrbiterE, 35U)) + aOrbiterK) + aNonceWordC);
            aWandererI = aWandererI + (((RotL64(aPrevious, 13U) + aOrbiterJ) + RotL64(aOrbiterF, 29U)) + RotL64(aCarry, 57U));
            aWandererC = aWandererC ^ ((((RotL64(aCross, 39U) + aOrbiterD) + RotL64(aOrbiterE, 12U)) + aNonceWordL) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 30U) + aOrbiterF) + RotL64(aOrbiterD, 19U)) + aNonceWordJ) + aPhaseDWandererUpdateSaltA[((aIndex + 21U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 3U) + aOrbiterI) + RotL64(aOrbiterA, 47U));
            aWandererK = aWandererK + ((((RotL64(aScatter, 21U) + aOrbiterA) + RotL64(aOrbiterD, 53U)) + RotL64(aCarry, 19U)) + aNonceWordM);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 21U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 29U));
            aCarry = aCarry + (RotL64(aWandererE, 48U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererJ, 35U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = (RotL64(aSnowLaneB[((aIndex + 14459U)) & S_BLOCK1], 28U) ^ RotL64(aExpandLaneA[((aIndex + 15653U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 15387U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 12511U)) & S_BLOCK1], 12U) ^ RotL64(aExpandLaneC[((aIndex + 12007U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCarry, 54U) ^ RotL64(aIngress, 11U)) + (RotL64(aCross, 29U) ^ RotL64(aPrevious, 41U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterC = ((aWandererA + RotL64(aIngress, 43U)) + RotL64(aCarry, 21U)) + 13481227414590594621U;
            aOrbiterJ = (((aWandererI + RotL64(aScatter, 18U)) + RotL64(aCarry, 39U)) + 17425964381118918026U) + aPhaseDOrbiterAssignSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = ((aWandererG + RotL64(aPrevious, 11U)) + 4792004356135956581U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterA = ((aWandererK + RotL64(aCross, 29U)) + 11926849936000639098U) + aNonceWordO;
            aOrbiterD = ((aWandererJ + RotL64(aScatter, 3U)) + 990697329347742142U) + aNonceWordB;
            aOrbiterB = (((aWandererB + RotL64(aCross, 51U)) + RotL64(aCarry, 57U)) + 9307721505373076588U) + aNonceWordP;
            aOrbiterF = ((aWandererD + RotL64(aIngress, 35U)) + 17605732738841908719U) + aNonceWordA;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 13110764518634187439U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 17970109897810645911U;
            aOrbiterI = RotL64((aOrbiterI * 10395095143998920213U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 10273133817644703654U) + aNonceWordE;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 11239046688920468137U;
            aOrbiterC = RotL64((aOrbiterC * 5197802934333553327U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 8355821483275763145U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 15522151127786049345U;
            aOrbiterJ = RotL64((aOrbiterJ * 4844278537850520413U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 5381663179722418112U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 9551368011768104906U) ^ aNonceWordN;
            aOrbiterD = RotL64((aOrbiterD * 14202470972121732997U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 16264476585232221270U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 7721417776432288282U;
            aOrbiterF = RotL64((aOrbiterF * 10267770327791051869U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 339418090653475277U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 3247926250495935511U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 16824669543765729097U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 3390560045236418590U) + aNonceWordL;
            aOrbiterB = (((aOrbiterB ^ aOrbiterI) ^ 3894024951542543635U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterB = RotL64((aOrbiterB * 10599637790900418767U), 11U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterF, 43U);
            aIngress = aIngress + (RotL64(aOrbiterD, 57U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 5U));
            aIngress = aIngress + RotL64(aOrbiterB, 34U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aPrevious, 3U) + RotL64(aOrbiterC, 18U)) + aOrbiterA);
            aWandererB = aWandererB ^ (((RotL64(aCross, 10U) + aOrbiterI) + RotL64(aOrbiterJ, 53U)) + aNonceWordC);
            aWandererD = aWandererD + ((((RotL64(aIngress, 19U) + RotL64(aOrbiterD, 35U)) + aOrbiterJ) + RotL64(aCarry, 57U)) + aNonceWordI);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 29U) + aOrbiterF) + RotL64(aOrbiterJ, 11U)) + aNonceWordG);
            aWandererA = aWandererA + (((RotL64(aCross, 47U) + RotL64(aOrbiterB, 47U)) + aOrbiterF) + aPhaseDWandererUpdateSaltC[((aIndex + 27U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterI, 27U)) + aOrbiterB);
            aWandererG = aWandererG + (((((RotL64(aScatter, 41U) + aOrbiterF) + RotL64(aOrbiterC, 41U)) + RotL64(aCarry, 19U)) + aNonceWordF) + aPhaseDWandererUpdateSaltB[((aIndex + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 37U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 43U));
            aCarry = aCarry + (RotL64(aWandererK, 14U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererA, 27U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 19794U)) & S_BLOCK1], 51U) ^ RotL64(aSnowLaneA[((aIndex + 18376U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 17313U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 18725U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 20317U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aIngress, 30U) + RotL64(aCross, 57U)) + (RotL64(aCarry, 43U) ^ RotL64(aPrevious, 13U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterK = ((aWandererC + RotL64(aScatter, 5U)) + RotL64(aCarry, 3U)) + 5568146815535263910U;
            aOrbiterJ = ((aWandererA + RotL64(aCross, 19U)) + RotL64(aCarry, 27U)) + 7736084960873834666U;
            aOrbiterD = ((((aWandererB + RotL64(aIngress, 13U)) + RotL64(aCarry, 47U)) + 1336413621817562093U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 14U)) & S_SALT1]) + aNonceWordO;
            aOrbiterB = (aWandererE + RotL64(aPrevious, 26U)) + 5218462026934984692U;
            aOrbiterF = ((aWandererG + RotL64(aIngress, 51U)) + 7048890985969555935U) + aNonceWordE;
            aOrbiterH = ((aWandererJ + RotL64(aCross, 35U)) + 13415955213864702118U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterA = ((aWandererH + RotL64(aPrevious, 43U)) + 5657023257021528548U) + aNonceWordI;
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 14338310943137497116U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 12305161641833950473U) ^ aNonceWordB;
            aOrbiterD = RotL64((aOrbiterD * 11949964304435964395U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 14514226578370459131U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterB) ^ 12692904083266024340U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterK = RotL64((aOrbiterK * 14800805065279908839U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 11012959130001327964U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 7106471380403489078U;
            aOrbiterA = RotL64((aOrbiterA * 515626559384817223U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 3718101961355280891U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 13364192077222322664U) ^ aNonceWordK;
            aOrbiterF = RotL64((aOrbiterF * 1411328915372590283U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 6720867800318913440U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 14497243926965866546U;
            aOrbiterB = RotL64((aOrbiterB * 13595058589060114653U), 35U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterK) + 5789056168233262435U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1]) + aNonceWordA;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 14438482587495779937U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10593535547917767263U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 313917798940179945U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 15241845511889502917U;
            aOrbiterH = RotL64((aOrbiterH * 16483477103771326107U), 11U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterD, 11U);
            aIngress = aIngress + (RotL64(aOrbiterH, 57U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterF, 29U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterB, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aIngress, 18U) + aOrbiterK) + RotL64(aOrbiterD, 13U)) + aPhaseDWandererUpdateSaltD[((aIndex + 16U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aCross, 3U) + aOrbiterH) + RotL64(aOrbiterJ, 21U)) + RotL64(aCarry, 37U)) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterF, 57U)) + aOrbiterJ);
            aWandererA = aWandererA + ((RotL64(aPrevious, 35U) + RotL64(aOrbiterD, 5U)) + aOrbiterA);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 51U) + aOrbiterB) + RotL64(aOrbiterF, 41U)) + aNonceWordF);
            aWandererE = aWandererE + (((RotL64(aPrevious, 11U) + aOrbiterA) + RotL64(aOrbiterF, 34U)) + RotL64(aCarry, 13U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 27U) + aOrbiterK) + RotL64(aOrbiterJ, 51U)) + aNonceWordG);
            //
            aCarry = aCarry + (RotL64(aWandererE, 18U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererJ, 51U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererH, 29U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 23500U)) & S_BLOCK1], 39U) ^ RotL64(aSnowLaneB[((aIndex + 22435U)) & S_BLOCK1], 10U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 23576U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 22223U)) & S_BLOCK1], 26U) ^ RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 22379U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aIngress, 37U) ^ RotL64(aCarry, 21U)) + (RotL64(aPrevious, 3U) + RotL64(aCross, 50U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterB = (((aWandererF + RotL64(aScatter, 47U)) + RotL64(aCarry, 37U)) + 15045917390223766480U) + aPhaseDOrbiterAssignSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterJ = ((aWandererA + RotL64(aPrevious, 11U)) + 10763054007033668758U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = ((aWandererB + RotL64(aIngress, 23U)) + 13190170142593666607U) + aNonceWordA;
            aOrbiterH = (aWandererH + RotL64(aCross, 29U)) + 9657025731441167065U;
            aOrbiterC = (((aWandererI + RotL64(aIngress, 3U)) + RotL64(aCarry, 21U)) + 11433367178975954211U) + aNonceWordD;
            aOrbiterI = (aWandererD + RotL64(aCross, 37U)) + 17904920143996810366U;
            aOrbiterF = ((aWandererJ + RotL64(aPrevious, 60U)) + RotL64(aCarry, 3U)) + 3244383020512113283U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 6538815775171139091U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 7195368312757976343U;
            aOrbiterE = RotL64((aOrbiterE * 10515679176134176565U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 18134430713910279374U) + aNonceWordM;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 6571776588427107976U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 11916502085252589161U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 11830778129647517758U) + aNonceWordJ;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 9793702760907767365U;
            aOrbiterJ = RotL64((aOrbiterJ * 4096246227968677179U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 2287235876793192036U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 8951959188326141794U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9968356718110753845U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 7583061790273240157U) + aNonceWordI;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 3571364625022806085U;
            aOrbiterF = RotL64((aOrbiterF * 6238360922735480669U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 13869345563551689212U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 277480328952975002U;
            aOrbiterI = RotL64((aOrbiterI * 1057564597096163085U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 4983735092494677578U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 9490022869381030928U;
            aOrbiterH = RotL64((aOrbiterH * 12926352917961703123U), 23U);
            //
            aIngress = RotL64(aOrbiterC, 35U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterF, 43U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 11U));
            aIngress = aIngress + RotL64(aOrbiterE, 60U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aCross, 51U) + RotL64(aOrbiterJ, 21U)) + aOrbiterI) + aPhaseDWandererUpdateSaltA[((aIndex + 10U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterF, 13U)) + aOrbiterB);
            aWandererA = aWandererA + (((RotL64(aScatter, 60U) + RotL64(aOrbiterJ, 42U)) + aOrbiterC) + RotL64(aCarry, 21U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 23U) + RotL64(aOrbiterH, 5U)) + aOrbiterE) + aNonceWordF);
            aWandererF = aWandererF + ((((RotL64(aScatter, 5U) + RotL64(aOrbiterE, 35U)) + aOrbiterF) + aNonceWordL) + aPhaseDWandererUpdateSaltF[((aIndex + 19U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterB, 51U)) + aOrbiterH);
            aWandererI = aWandererI + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterE, 57U)) + aOrbiterJ) + RotL64(aCarry, 53U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 53U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 36U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 5U));
            aCarry = aCarry + RotL64(aWandererI, 13U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = (RotL64(aInvestLaneC[((aIndex + 31818U)) & S_BLOCK1], 35U) ^ RotL64(aInvestLaneA[((aIndex + 31686U)) & S_BLOCK1], 60U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 31705U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 30261U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneB[((aIndex + 28036U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCross, 35U) ^ RotL64(aIngress, 54U)) ^ (RotL64(aCarry, 19U) + RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterA = (((aWandererB + RotL64(aIngress, 29U)) + RotL64(aCarry, 57U)) + 7896237440058555694U) + aNonceWordO;
            aOrbiterF = (((aWandererC + RotL64(aScatter, 19U)) + RotL64(aCarry, 37U)) + 11870529476037558635U) + aNonceWordM;
            aOrbiterE = (((aWandererA + RotL64(aCross, 35U)) + RotL64(aCarry, 19U)) + 9158983227801569448U) + aPhaseDOrbiterAssignSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterG = (aWandererF + RotL64(aPrevious, 5U)) + 4710172270996950329U;
            aOrbiterH = (((aWandererH + RotL64(aIngress, 50U)) + 14634482800356647630U) + aPhaseDOrbiterAssignSaltD[((aIndex + 23U)) & S_SALT1]) + aNonceWordD;
            aOrbiterJ = ((aWandererK + RotL64(aCross, 41U)) + 8822207952170610891U) + aNonceWordF;
            aOrbiterI = (aWandererG + RotL64(aScatter, 13U)) + 13755891414028982553U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 4555293067488040719U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 2816805148093762081U;
            aOrbiterE = RotL64((aOrbiterE * 16838149138341713943U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 2122631477965135190U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 4592922416380416071U) ^ aNonceWordK;
            aOrbiterF = RotL64((aOrbiterF * 11644507904538573165U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 7102471666524164715U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 17274623547879474204U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5443572270546181789U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 938587316977094680U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 18258015823797023523U) ^ aNonceWordE;
            aOrbiterJ = RotL64((aOrbiterJ * 6068819567674605919U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 5809987756043471595U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 5083075160112581620U;
            aOrbiterG = RotL64((aOrbiterG * 3313957222154937503U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 5960021727750946496U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 5967477320950630150U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 330964768256424655U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 6578428711689296132U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 5601728218197771276U;
            aOrbiterA = RotL64((aOrbiterA * 9552559022315971847U), 35U);
            //
            aIngress = RotL64(aOrbiterG, 11U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 41U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 27U));
            aIngress = aIngress + RotL64(aOrbiterE, 50U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 13U) + RotL64(aOrbiterE, 21U)) + aOrbiterI) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aIngress, 29U) + aOrbiterA) + RotL64(aOrbiterF, 37U)) + aNonceWordA);
            aWandererB = aWandererB ^ ((RotL64(aCross, 39U) + aOrbiterG) + RotL64(aOrbiterF, 3U));
            aWandererG = aWandererG + ((((RotL64(aScatter, 56U) + aOrbiterI) + RotL64(aOrbiterF, 57U)) + RotL64(aCarry, 13U)) + aNonceWordJ);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 47U) + RotL64(aOrbiterE, 51U)) + aOrbiterG) + aNonceWordH);
            aWandererC = aWandererC + (((((RotL64(aCross, 5U) + RotL64(aOrbiterI, 29U)) + aOrbiterH) + RotL64(aCarry, 41U)) + aNonceWordL) + aPhaseDWandererUpdateSaltC[((aIndex + 29U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 21U) + aOrbiterJ) + RotL64(aOrbiterF, 10U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 41U) ^ aWandererK);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 53U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 36U));
            aCarry = aCarry + RotL64(aWandererB, 57U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xE15985CAD499887DULL + 0xA9FEA24C9DAC2939ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xEBBD5BDAE1D4B351ULL + 0xB67F053AD14FA4F3ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xC8E356F70A892F7DULL + 0xA86451224EB0BE20ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xF3C91F459382356FULL + 0xAD2C0CE02E670C9DULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xEB3F6EF12DAFC60BULL + 0xB8518D562DA61C17ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x81E78CB7D6642BCBULL + 0xF86D8AB2002C3135ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xE715278DE2E3EF4BULL + 0x90CAEB9B9D67A23CULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xDC1D89A3564DC611ULL + 0x81AA2DBECA9EE2AFULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0x8C3CFC2F6CE26C31ULL + 0xCD93793899D4610AULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xD13DC1624F3B93B7ULL + 0xB3E660ECED28A4F8ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0x8EFEBF71128C0A13ULL + 0x8BDBA3E1AB57AA4CULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xA01DC6DE49440AB1ULL + 0xE92890067B0ADE75ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xBAC801538BE67791ULL + 0x885859AD3178873CULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xDB298EC0BA53E4B7ULL + 0x86C9933E31D54488ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xEC4DC25C281D1BCDULL + 0x8D8601F945828FFEULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xD51FB9380C75677DULL + 0x8FEBAAAA7B377A58ULL);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 2492U)) & S_BLOCK1], 52U) ^ RotL64(aInvestLaneB[((aIndex + 3860U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 4734U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 1556U)) & S_BLOCK1], 13U) ^ RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 3031U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 4451U)) & S_BLOCK1], 56U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCarry, 44U) ^ RotL64(aPrevious, 57U)) + (RotL64(aCross, 11U) ^ RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterI = (aWandererG + RotL64(aCross, 27U)) + 479672811032092393U;
            aOrbiterJ = ((aWandererC + RotL64(aPrevious, 3U)) + RotL64(aCarry, 43U)) + 18061121631394564425U;
            aOrbiterC = (aWandererI + RotL64(aScatter, 53U)) + 14237400452740566065U;
            aOrbiterF = (aWandererH + RotL64(aIngress, 11U)) + 6723123812257706134U;
            aOrbiterD = ((aWandererF + RotL64(aScatter, 19U)) + 4247997188026499248U) + aNonceWordF;
            aOrbiterK = (aWandererJ + RotL64(aPrevious, 30U)) + 1939107415066134869U;
            aOrbiterE = (aWandererB + RotL64(aCross, 47U)) + 3912640123546395979U;
            aOrbiterA = ((aWandererD + RotL64(aIngress, 39U)) + 8295478436553964298U) + aPhaseEOrbiterAssignSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = ((((aWandererK + RotL64(aScatter, 57U)) + RotL64(aCarry, 29U)) + 3218960600711526885U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordP;
            aOrbiterH = ((aWandererE + RotL64(aIngress, 50U)) + 5874096203353388890U) + aNonceWordG;
            aOrbiterB = ((aWandererA + RotL64(aCross, 23U)) + RotL64(aCarry, 35U)) + 10294536533673023358U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 11268561953904130747U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 16693201256788898423U;
            aOrbiterC = RotL64((aOrbiterC * 16291987237693567209U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 7550969634681894654U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 9501647424602245869U;
            aOrbiterK = RotL64((aOrbiterK * 11265865222096866605U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 8881869255994319423U) + aNonceWordD;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 16770136406906800016U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 1782039587385512923U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 16185384746435761363U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 13841034186650721627U;
            aOrbiterF = RotL64((aOrbiterF * 12000155593277035447U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 15229062695864608309U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 3576122704615303733U;
            aOrbiterG = RotL64((aOrbiterG * 2433987493885779279U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 13898167174453181224U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 12878032061609524049U) ^ aNonceWordA;
            aOrbiterI = RotL64((aOrbiterI * 18104665741338251495U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 12719156051299028649U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 8640980843376950769U;
            aOrbiterD = RotL64((aOrbiterD * 10242616778390983333U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 12133332160916004365U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 8743563985229104484U;
            aOrbiterB = RotL64((aOrbiterB * 4575129690615054691U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 7362223873479167793U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 4230720394788635807U;
            aOrbiterA = RotL64((aOrbiterA * 3658720603716856293U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 5095842824285329272U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 7483469517256234638U;
            aOrbiterE = RotL64((aOrbiterE * 9782114499878763883U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 17426017004856399653U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 479672811032092393U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 14921028515589317919U), 53U);
            //
            aIngress = RotL64(aOrbiterH, 23U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterE, 5U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 18U));
            aIngress = aIngress + (RotL64(aOrbiterA, 41U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterG, 35U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterD, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aPrevious, 42U) + aOrbiterF) + RotL64(aOrbiterA, 57U)) + aNonceWordJ);
            aWandererI = aWandererI ^ ((((RotL64(aScatter, 27U) + aOrbiterK) + RotL64(aOrbiterJ, 3U)) + aNonceWordI) + aPhaseEWandererUpdateSaltD[((aIndex + 24U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aIngress, 3U) + aOrbiterE) + RotL64(aOrbiterF, 27U)) + RotL64(aCarry, 11U)) + aNonceWordE);
            aWandererD = aWandererD ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterI, 53U)) + aOrbiterH);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 5U) + aOrbiterC) + RotL64(aOrbiterG, 48U)) + aPhaseEWandererUpdateSaltA[((aIndex + 19U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterK, 19U)) + aOrbiterG);
            aWandererC = aWandererC + (((RotL64(aIngress, 37U) + RotL64(aOrbiterE, 23U)) + aOrbiterJ) + aNonceWordH);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 21U) + aOrbiterK) + RotL64(aOrbiterB, 21U));
            aWandererE = aWandererE + (((RotL64(aCross, 53U) + RotL64(aOrbiterG, 46U)) + aOrbiterB) + RotL64(aCarry, 5U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 48U) + aOrbiterD) + RotL64(aOrbiterC, 41U));
            aWandererK = aWandererK + ((RotL64(aPrevious, 29U) + aOrbiterF) + RotL64(aOrbiterI, 51U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 37U));
            aCarry = aCarry + (RotL64(aWandererA, 57U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererF, 20U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererH, 5U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererI, 23U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererE, 13U);
            aCarry = aCarry + RotL64(aIngress, 46U);
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
            aIngress = (RotL64(aFireLaneA[((aIndex + 9383U)) & S_BLOCK1], 13U) ^ RotL64(aInvestLaneC[((aIndex + 8172U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aInvestLaneD[((aIndex + 7438U)) & S_BLOCK1], 22U) ^ RotL64(aWorkLaneA[((aIndex + 6568U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 10130U)) & S_BLOCK1], 50U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 9899U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 9332U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCross, 3U) ^ RotL64(aPrevious, 36U)) + (RotL64(aIngress, 53U) ^ RotL64(aCarry, 21U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterI = (aWandererA + RotL64(aScatter, 39U)) + 15904465836916519864U;
            aOrbiterD = (((aWandererG + RotL64(aPrevious, 53U)) + RotL64(aCarry, 57U)) + 17725629806317789307U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterH = ((aWandererK + RotL64(aCross, 37U)) + 13794170125914914828U) + aNonceWordC;
            aOrbiterG = (aWandererF + RotL64(aIngress, 3U)) + 2149055907476874332U;
            aOrbiterF = ((aWandererC + RotL64(aCross, 21U)) + RotL64(aCarry, 47U)) + 5342047776745074649U;
            aOrbiterB = (aWandererE + RotL64(aIngress, 60U)) + 8268148484060546838U;
            aOrbiterC = (aWandererI + RotL64(aPrevious, 29U)) + 10821151364028563719U;
            aOrbiterK = (aWandererJ + RotL64(aScatter, 41U)) + 4294213820894407378U;
            aOrbiterJ = (((aWandererH + RotL64(aCross, 51U)) + 10884726101307943090U) + aPhaseEOrbiterAssignSaltF[((aIndex + 23U)) & S_SALT1]) + aNonceWordB;
            aOrbiterE = ((aWandererB + RotL64(aIngress, 10U)) + RotL64(aCarry, 41U)) + 16432210042202444824U;
            aOrbiterA = (aWandererD + RotL64(aScatter, 57U)) + 15196602644336228055U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 14117787670220328165U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 219833877949480215U;
            aOrbiterH = RotL64((aOrbiterH * 10736293047771972173U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 3326396981881473962U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 14918513066311426279U;
            aOrbiterF = RotL64((aOrbiterF * 14269763278564574663U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 11795234681370163206U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 3068267285352664813U;
            aOrbiterB = RotL64((aOrbiterB * 15746255933920904619U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 245233356957999496U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 709926406353796673U;
            aOrbiterK = RotL64((aOrbiterK * 13627039596842073595U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 5378105439430271038U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 10114555061122044430U;
            aOrbiterC = RotL64((aOrbiterC * 5351295043424885549U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 13233010815716769713U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 8231291294833548389U;
            aOrbiterE = RotL64((aOrbiterE * 10840516135212753869U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 7160760224172419829U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 14767926435411546785U;
            aOrbiterD = RotL64((aOrbiterD * 1643485739468851073U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 4464245330038080103U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterE) ^ 15778166658285494712U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterG = RotL64((aOrbiterG * 13980891936095282989U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 2426340576450960905U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 6030631392508241438U) ^ aNonceWordO;
            aOrbiterJ = RotL64((aOrbiterJ * 13921288910299408423U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 15990180955119402476U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 8707879851984546959U;
            aOrbiterI = RotL64((aOrbiterI * 13794027045755532979U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 11665969506971636052U) + aNonceWordJ;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 15904465836916519864U;
            aOrbiterA = RotL64((aOrbiterA * 17042355185093585101U), 43U);
            //
            aIngress = RotL64(aOrbiterE, 21U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 27U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 53U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 44U));
            aIngress = aIngress + (RotL64(aOrbiterH, 57U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterJ, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((((RotL64(aPrevious, 3U) + aOrbiterK) + RotL64(aOrbiterJ, 35U)) + aNonceWordA) + aPhaseEWandererUpdateSaltF[((aIndex + 17U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aIngress, 51U) + aOrbiterK) + RotL64(aOrbiterF, 38U)) + RotL64(aCarry, 27U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 19U) + aOrbiterI) + RotL64(aOrbiterF, 3U)) + aNonceWordH);
            aWandererD = aWandererD + ((RotL64(aCross, 54U) + aOrbiterA) + RotL64(aOrbiterD, 57U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterA, 51U)) + aOrbiterB);
            aWandererB = aWandererB + ((RotL64(aPrevious, 29U) + aOrbiterG) + RotL64(aOrbiterK, 47U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterK, 13U)) + aOrbiterA);
            aWandererA = aWandererA + (((RotL64(aScatter, 43U) + RotL64(aOrbiterH, 60U)) + aOrbiterF) + aNonceWordF);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 6U) + aOrbiterF) + RotL64(aOrbiterC, 43U));
            aWandererJ = aWandererJ + ((((RotL64(aCross, 57U) + aOrbiterC) + RotL64(aOrbiterI, 21U)) + RotL64(aCarry, 41U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 13U) + aOrbiterH) + RotL64(aOrbiterE, 53U)) + aNonceWordK);
            //
            aCarry = aCarry + (RotL64(aWandererH, 37U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererB, 24U) ^ aWandererD);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 11U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 53U));
            aCarry = aCarry + (RotL64(aWandererF, 39U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererJ, 60U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 12954U)) & S_BLOCK1], 27U) ^ RotL64(aInvestLaneA[((aIndex + 14334U)) & S_BLOCK1], 40U));
            aIngress ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 11657U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordA));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 11432U)) & S_BLOCK1], 39U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 14138U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCross, 6U) + RotL64(aIngress, 35U)) ^ (RotL64(aCarry, 21U) + RotL64(aPrevious, 47U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterC = (aWandererC + RotL64(aPrevious, 13U)) + 6068543441070417854U;
            aOrbiterH = ((aWandererJ + RotL64(aIngress, 51U)) + RotL64(aCarry, 3U)) + 2995980468193441856U;
            aOrbiterE = ((aWandererF + RotL64(aScatter, 41U)) + 18020277482171594003U) + aNonceWordJ;
            aOrbiterA = (((aWandererB + RotL64(aCross, 37U)) + 4293807434721230702U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordB;
            aOrbiterK = (aWandererI + RotL64(aScatter, 22U)) + 7980599111583893156U;
            aOrbiterI = (aWandererH + RotL64(aIngress, 57U)) + 8593141111851052016U;
            aOrbiterD = ((aWandererD + RotL64(aPrevious, 11U)) + 5903487523900084325U) + aNonceWordP;
            aOrbiterG = (aWandererA + RotL64(aCross, 5U)) + 15112035513447930209U;
            aOrbiterF = ((aWandererK + RotL64(aIngress, 27U)) + 9854037263057006439U) + aPhaseEOrbiterAssignSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterB = ((aWandererG + RotL64(aScatter, 60U)) + RotL64(aCarry, 29U)) + 16759760289688823193U;
            aOrbiterJ = (((aWandererE + RotL64(aPrevious, 29U)) + RotL64(aCarry, 21U)) + 12622628933030601390U) + aNonceWordC;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 1264668857268123425U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 16302812053619101593U;
            aOrbiterE = RotL64((aOrbiterE * 18291400055836111547U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 16087995784896123610U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 7970269262800468363U;
            aOrbiterI = RotL64((aOrbiterI * 14924752223305807461U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 5331477046030959632U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterD) ^ 16534913204255550893U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterG = RotL64((aOrbiterG * 1013433634373673565U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 11042821902537871209U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 8069677512345031660U;
            aOrbiterB = RotL64((aOrbiterB * 13622218526054132397U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 5737130058129936372U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 1076627182956662997U;
            aOrbiterA = RotL64((aOrbiterA * 14342191224014199929U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 13911061091801078190U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 15397603151098990373U;
            aOrbiterD = RotL64((aOrbiterD * 1802890451633592245U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 15137326716738637972U) + aNonceWordM;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 11248737008959896786U;
            aOrbiterF = RotL64((aOrbiterF * 90789374131547005U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 1847847987633923657U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 10560748778679145431U;
            aOrbiterC = RotL64((aOrbiterC * 2919333327817231099U), 27U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterB) + 2703726238610290251U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1]) + aNonceWordO;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 12950671360471467310U;
            aOrbiterH = RotL64((aOrbiterH * 7490327691501537047U), 57U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterD) + 10331504168520449467U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordE;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 1541527607705280906U;
            aOrbiterK = RotL64((aOrbiterK * 14197400812600186171U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 9135056476214341809U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 6068543441070417854U;
            aOrbiterJ = RotL64((aOrbiterJ * 14102524444094948875U), 43U);
            //
            aIngress = RotL64(aOrbiterJ, 43U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterI, 57U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 53U));
            aIngress = aIngress + (RotL64(aOrbiterE, 38U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 21U));
            aIngress = aIngress + RotL64(aOrbiterD, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aCross, 37U) + RotL64(aOrbiterC, 5U)) + aOrbiterG) + aNonceWordH);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterA, 53U)) + aOrbiterF);
            aWandererI = aWandererI + ((RotL64(aPrevious, 51U) + RotL64(aOrbiterA, 60U)) + aOrbiterB);
            aWandererC = aWandererC ^ ((((RotL64(aIngress, 53U) + RotL64(aOrbiterB, 41U)) + aOrbiterG) + aNonceWordF) + aPhaseEWandererUpdateSaltB[((aIndex + 5U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 13U) + aOrbiterH) + RotL64(aOrbiterJ, 29U)) + aNonceWordI);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 46U) + aOrbiterI) + RotL64(aOrbiterH, 13U)) + aNonceWordK);
            aWandererG = aWandererG + (((RotL64(aPrevious, 23U) + aOrbiterH) + RotL64(aOrbiterK, 11U)) + RotL64(aCarry, 47U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterE, 56U)) + aOrbiterG);
            aWandererD = aWandererD + (((RotL64(aPrevious, 11U) + aOrbiterE) + RotL64(aOrbiterD, 43U)) + aPhaseEWandererUpdateSaltE[((aIndex + 26U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 21U) + aOrbiterC) + RotL64(aOrbiterH, 47U));
            aWandererF = aWandererF + (((RotL64(aCross, 34U) + aOrbiterG) + RotL64(aOrbiterJ, 19U)) + RotL64(aCarry, 41U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 27U));
            aCarry = aCarry + (RotL64(aWandererJ, 44U) ^ aWandererH);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 23U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 21U));
            aCarry = aCarry + (RotL64(aWandererK, 5U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererI, 11U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 16661U)) & S_BLOCK1], 22U) ^ RotL64(aFireLaneA[((aIndex + 20950U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 19084U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 18603U)) & S_BLOCK1], 43U) ^ RotL64(aInvestLaneD[((aIndex + 17404U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aIngress, 13U) ^ RotL64(aCross, 56U)) + (RotL64(aPrevious, 43U) + RotL64(aCarry, 29U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterD = (((aWandererE + RotL64(aScatter, 12U)) + RotL64(aCarry, 57U)) + 12583180859826261500U) + aNonceWordE;
            aOrbiterK = (((aWandererJ + RotL64(aPrevious, 19U)) + 9067093488553721468U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordL;
            aOrbiterB = ((aWandererB + RotL64(aCross, 27U)) + RotL64(aCarry, 21U)) + 12173106198862881754U;
            aOrbiterA = (aWandererH + RotL64(aIngress, 21U)) + 11333491014394592654U;
            aOrbiterE = (aWandererK + RotL64(aPrevious, 3U)) + 3511883526940919554U;
            aOrbiterH = ((aWandererA + RotL64(aCross, 35U)) + 7416810692106273044U) + aNonceWordP;
            aOrbiterG = (aWandererD + RotL64(aScatter, 40U)) + 8341174972619784110U;
            aOrbiterF = (aWandererF + RotL64(aIngress, 37U)) + 2220852854836962979U;
            aOrbiterI = ((aWandererG + RotL64(aScatter, 43U)) + 8090781422229383825U) + aPhaseEOrbiterAssignSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterC = ((aWandererI + RotL64(aIngress, 51U)) + 2338801236599102223U) + aNonceWordA;
            aOrbiterJ = ((aWandererC + RotL64(aPrevious, 47U)) + RotL64(aCarry, 27U)) + 12484514711848308104U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 13684861340589131816U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 12796636819991873058U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5533508014234835669U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 7634198650894837690U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 10240326122201201762U;
            aOrbiterK = RotL64((aOrbiterK * 8758703497719125901U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 4162814763739453934U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 2766504649149048469U;
            aOrbiterG = RotL64((aOrbiterG * 16731843453895178671U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 11051393030148769655U) + aNonceWordH;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 17687055068651386665U;
            aOrbiterH = RotL64((aOrbiterH * 1042927176246229537U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 3353615315436983420U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 5971640796220306310U;
            aOrbiterF = RotL64((aOrbiterF * 15804313508835034807U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 12299773092762384765U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 7435804907797063411U) ^ aNonceWordO;
            aOrbiterC = RotL64((aOrbiterC * 9848139805288165965U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 8735783937125735699U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 11903126115475835615U;
            aOrbiterD = RotL64((aOrbiterD * 16942088822124940265U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 4427166023462475475U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 6011733469446008137U;
            aOrbiterA = RotL64((aOrbiterA * 17298067225913923517U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 18341473946127677319U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 5423774915753911947U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 14985099502923458523U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 2384393657884193014U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 2650593524388493958U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 892985816665547945U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 15991261431384033176U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 12583180859826261500U;
            aOrbiterI = RotL64((aOrbiterI * 14394838775646875599U), 29U);
            //
            aIngress = RotL64(aOrbiterC, 51U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 34U));
            aIngress = aIngress + (RotL64(aOrbiterD, 11U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterI, 39U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 37U));
            aIngress = aIngress + RotL64(aOrbiterE, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterH, 47U)) + aOrbiterE);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterK, 5U)) + aOrbiterI) + aPhaseEWandererUpdateSaltD[((aIndex + 3U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterD, 13U)) + aOrbiterC) + aNonceWordC);
            aWandererC = aWandererC + ((((RotL64(aCross, 27U) + RotL64(aOrbiterC, 18U)) + aOrbiterA) + RotL64(aCarry, 11U)) + aNonceWordK);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 58U) + aOrbiterI) + RotL64(aOrbiterD, 3U));
            aWandererK = aWandererK + (((RotL64(aScatter, 13U) + RotL64(aOrbiterJ, 37U)) + aOrbiterB) + aPhaseEWandererUpdateSaltA[((aIndex + 13U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 3U) + aOrbiterE) + RotL64(aOrbiterF, 57U));
            aWandererE = aWandererE + ((RotL64(aCross, 43U) + RotL64(aOrbiterE, 35U)) + aOrbiterK);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 20U) + RotL64(aOrbiterF, 21U)) + aOrbiterK) + aNonceWordB);
            aWandererF = aWandererF + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterD, 26U)) + aOrbiterB) + RotL64(aCarry, 51U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 41U) + aOrbiterG) + RotL64(aOrbiterE, 23U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 13U) ^ aWandererG);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 30U));
            aCarry = aCarry + (RotL64(aWandererE, 21U) ^ aWandererF);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 57U));
            aCarry = aCarry + (RotL64(aWandererB, 19U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererH, 43U);
            aCarry = aCarry + RotL64(aIngress, 46U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 26378U)) & S_BLOCK1], 12U) ^ RotL64(aFireLaneB[((aIndex + 22071U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 26666U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 23261U)) & S_BLOCK1], 57U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 23937U)) & S_BLOCK1], 14U));
            aCross ^= RotL64(aInvestLaneA[((aIndex + 26910U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCarry, 57U) ^ RotL64(aPrevious, 21U)) + (RotL64(aCross, 43U) ^ RotL64(aIngress, 6U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterC = ((aWandererK + RotL64(aPrevious, 53U)) + RotL64(aCarry, 11U)) + 1898718075389870739U;
            aOrbiterD = ((aWandererH + RotL64(aCross, 35U)) + 5631794889237247403U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterI = ((aWandererF + RotL64(aIngress, 56U)) + RotL64(aCarry, 39U)) + 18219714659484524607U;
            aOrbiterG = ((aWandererG + RotL64(aScatter, 41U)) + 15419581386225732921U) + aPhaseEOrbiterAssignSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = (aWandererJ + RotL64(aIngress, 37U)) + 9125575431710198210U;
            aOrbiterA = (aWandererC + RotL64(aPrevious, 3U)) + 12205871520544965505U;
            aOrbiterF = (aWandererB + RotL64(aCross, 11U)) + 7617534300497343422U;
            aOrbiterJ = (((aWandererA + RotL64(aScatter, 21U)) + RotL64(aCarry, 5U)) + 18017579105368135814U) + aNonceWordO;
            aOrbiterH = (aWandererD + RotL64(aIngress, 39U)) + 10693882161946020042U;
            aOrbiterB = (aWandererI + RotL64(aCross, 29U)) + 11669615701700895306U;
            aOrbiterK = ((aWandererE + RotL64(aPrevious, 14U)) + 11045110212889232165U) + aNonceWordH;
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 18019107802806469913U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 12315940560472528716U;
            aOrbiterI = RotL64((aOrbiterI * 4505122470351404065U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 4899009736070044310U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 17412253404253730364U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 10791901166391946485U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 4826286251927854181U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 4523455921321845084U) ^ aNonceWordE;
            aOrbiterF = RotL64((aOrbiterF * 14534103906736598099U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 4132514462154182215U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 7164745605985109269U;
            aOrbiterC = RotL64((aOrbiterC * 14107325508977225261U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 6297434295807635654U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 8813887638672996646U;
            aOrbiterB = RotL64((aOrbiterB * 17495632530773158201U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 11086381278955626084U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 5660733992573928887U;
            aOrbiterH = RotL64((aOrbiterH * 11248164458720777889U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 14851044686208609882U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 12707776386060264479U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 4470919091467313071U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 11508023384209716657U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 11752973809740920034U;
            aOrbiterE = RotL64((aOrbiterE * 10212754472298834769U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 16746821150860017820U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 9659421716296641396U;
            aOrbiterJ = RotL64((aOrbiterJ * 7530071874978553673U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 3192309064305104593U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 11409078048681398061U;
            aOrbiterA = RotL64((aOrbiterA * 14991409124701807765U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 315359495275427324U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 1898718075389870739U) ^ aNonceWordB;
            aOrbiterK = RotL64((aOrbiterK * 13126661894614781343U), 53U);
            //
            aIngress = RotL64(aOrbiterE, 19U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 26U));
            aIngress = aIngress + (RotL64(aOrbiterB, 3U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 29U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 47U));
            aIngress = aIngress + RotL64(aOrbiterJ, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterJ, 21U)) + aOrbiterD) + aPhaseEWandererUpdateSaltF[((aIndex + 25U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 41U) + RotL64(aOrbiterD, 41U)) + aOrbiterB) + aNonceWordL);
            aWandererF = aWandererF ^ ((RotL64(aCross, 50U) + RotL64(aOrbiterI, 39U)) + aOrbiterC);
            aWandererK = aWandererK + ((RotL64(aScatter, 23U) + RotL64(aOrbiterF, 47U)) + aOrbiterI);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 19U) + RotL64(aOrbiterG, 50U)) + aOrbiterA) + aNonceWordK);
            aWandererC = aWandererC + ((RotL64(aPrevious, 3U) + aOrbiterI) + RotL64(aOrbiterE, 23U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 39U) + aOrbiterE) + RotL64(aOrbiterA, 19U)) + aPhaseEWandererUpdateSaltC[((aIndex + 5U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 11U) + RotL64(aOrbiterA, 53U)) + aOrbiterD) + RotL64(aCarry, 27U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterI, 37U)) + aOrbiterH) + aNonceWordN);
            aWandererE = aWandererE + (((RotL64(aPrevious, 58U) + RotL64(aOrbiterC, 57U)) + aOrbiterJ) + RotL64(aCarry, 23U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterA, 12U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 13U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererG, 38U) ^ aWandererC);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 3U));
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererD, 27U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererH, 57U);
            aCarry = aCarry + RotL64(aIngress, 60U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 30918U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneA[((aIndex + 28289U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 27865U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordE));
            //
            aCross = RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28972U)) & S_BLOCK1], 47U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 32536U)) & S_BLOCK1], 10U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCarry, 39U)) ^ (RotL64(aPrevious, 53U) + RotL64(aCross, 20U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterH = (((aWandererH + RotL64(aCross, 3U)) + RotL64(aCarry, 47U)) + 2571116506511057880U) + aNonceWordM;
            aOrbiterA = ((aWandererJ + RotL64(aIngress, 13U)) + RotL64(aCarry, 29U)) + 13112435411509707292U;
            aOrbiterC = (((aWandererD + RotL64(aPrevious, 30U)) + RotL64(aCarry, 43U)) + 10403251762787357256U) + aPhaseEOrbiterAssignSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterK = (aWandererF + RotL64(aScatter, 43U)) + 8461951095541400405U;
            aOrbiterE = ((aWandererG + RotL64(aPrevious, 53U)) + 9890793478557463815U) + aPhaseEOrbiterAssignSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = (aWandererI + RotL64(aIngress, 27U)) + 3030229465991783707U;
            aOrbiterD = (aWandererK + RotL64(aCross, 50U)) + 7273848154043719247U;
            aOrbiterB = (aWandererE + RotL64(aScatter, 57U)) + 10681774862516028276U;
            aOrbiterG = (aWandererC + RotL64(aIngress, 41U)) + 7105082755586853104U;
            aOrbiterI = (aWandererB + RotL64(aPrevious, 35U)) + 6588579345319551129U;
            aOrbiterJ = ((aWandererA + RotL64(aScatter, 37U)) + 14616333550242386092U) + aNonceWordJ;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 15439666290229654921U) + aNonceWordC;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 3360304356760164799U) ^ aNonceWordG;
            aOrbiterC = RotL64((aOrbiterC * 5164191920584106237U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 14438730801970761889U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 14515616787452085729U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 2041601927968559821U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 4167853822635132419U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 8950982233003320239U;
            aOrbiterF = RotL64((aOrbiterF * 887144270884244907U), 39U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 12391327853728029953U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 7100871010552394421U;
            aOrbiterK = RotL64((aOrbiterK * 16552349374101955967U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 15381697462381887944U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 6801677551341079401U;
            aOrbiterB = RotL64((aOrbiterB * 13325954438427340703U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 947011315719204867U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterG) ^ 6356920162398333481U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterH = RotL64((aOrbiterH * 5566721941682667419U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 8910262020598577378U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 8778455415977526457U;
            aOrbiterG = RotL64((aOrbiterG * 4092470497616637283U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 5585696961453127223U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 9670655481681494412U;
            aOrbiterD = RotL64((aOrbiterD * 7863197168965036383U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 10713004007087085729U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 4036355047492922339U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 6923922258047667173U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 14580156873863533497U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 7049502932205025182U;
            aOrbiterJ = RotL64((aOrbiterJ * 8665428649262370727U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 12707521269341941677U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 2571116506511057880U) ^ aNonceWordN;
            aOrbiterA = RotL64((aOrbiterA * 2388236789245943699U), 3U);
            //
            aIngress = RotL64(aOrbiterG, 53U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 29U));
            aIngress = aIngress + (RotL64(aOrbiterB, 26U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 47U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 41U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterD, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aScatter, 27U) + aOrbiterD) + RotL64(aOrbiterF, 35U));
            aWandererB = aWandererB + (((RotL64(aCross, 13U) + RotL64(aOrbiterD, 30U)) + aOrbiterH) + RotL64(aCarry, 47U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 52U) + aOrbiterJ) + RotL64(aOrbiterD, 3U)) + aNonceWordF);
            aWandererA = aWandererA + (((RotL64(aPrevious, 37U) + aOrbiterD) + RotL64(aOrbiterE, 39U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 35U) + aOrbiterF) + RotL64(aOrbiterI, 43U));
            aWandererD = aWandererD + ((RotL64(aCross, 19U) + aOrbiterF) + RotL64(aOrbiterC, 37U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterB, 23U)) + aOrbiterD);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 47U) + RotL64(aOrbiterK, 28U)) + aOrbiterJ) + RotL64(aCarry, 43U)) + aNonceWordH);
            aWandererI = aWandererI ^ ((RotL64(aCross, 41U) + aOrbiterH) + RotL64(aOrbiterG, 11U));
            aWandererE = aWandererE + ((RotL64(aPrevious, 11U) + aOrbiterC) + RotL64(aOrbiterA, 47U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 58U) + RotL64(aOrbiterA, 21U)) + aOrbiterK) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 43U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 19U));
            aCarry = aCarry + (RotL64(aWandererG, 38U) ^ aWandererB);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 41U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 21U));
            aCarry = aCarry + RotL64(aWandererE, 29U);
            aCarry = aCarry + RotL64(aIngress, 10U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xD32265637F9C0ABBULL + 0xD049B809B5BFA981ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xEC725C8F947C26E9ULL + 0xCF194DDC32FE1158ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x860496CA4C3AFE1BULL + 0x94FCAFBA2CF972DDULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xC00A74BFE3C7B92FULL + 0xBD658B870CEEAB31ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xEED2C103228BB8BDULL + 0x8A59C98E35A23EAEULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xDFA562AC583F7DFFULL + 0xDF043031704EF113ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xDE9E66591914F9E9ULL + 0xF76F2E7AB9B0366DULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xF6D4998530CC0DF3ULL + 0xB66CC31C7B0B0E5BULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xC8F6C341C24142C3ULL + 0xD0F393D55B56DF8BULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xBE1F93510AA9499FULL + 0x955161D0C90BE9DFULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xF0C0D90F37C1E2AFULL + 0xDFC9B5313A24767AULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xEB73204C6E400AF9ULL + 0xC320469D8525C755ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xF9A8B693F4588FEBULL + 0xDBEEE9716F9D6225ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0x98B6B6C8A07ACBF5ULL + 0xE3DC0D8FADAC28A4ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xBBC4292C528E2C61ULL + 0xD3D6AF5167D24C85ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xCBC28B5CC87F4103ULL + 0x803D80DEB1F3B777ULL);
    // GSeedRunSeed_F seed_loop_f (start)
    {
        // GSeedRunSeed_F seed_loop_f lane group
        // read from: aOperationLaneA, aOperationLaneB, aSnowLaneB, aOperationLaneC, aOperationLaneD, aInvestLaneC, aSnowLaneC, aWorkLaneD, aWorkLaneC, aSnowLaneD, aInvestLaneB, aExpandLaneA, aSnowLaneA, aExpandLaneB, aInvestLaneD, aExpandLaneC, aInvestLaneA
        // write to: aSnowLaneC, aSnowLaneD, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // seed_loop_f loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aSnowLaneB
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aSnowLaneB forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aInvestLaneC
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aInvestLaneC backward/forward random
        // write to: aSnowLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 352U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneB[((aIndex + 3998U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 2727U)) & S_BLOCK1], 50U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 4456U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 403U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aInvestLaneC[((aIndex + 5440U)) & S_BLOCK1], 18U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aIngress, 60U) + RotL64(aCross, 41U)) ^ (RotL64(aPrevious, 23U) + RotL64(aCarry, 11U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterH = (aWandererE + RotL64(aPrevious, 11U)) + 15188686795415908074U;
            aOrbiterD = (aWandererC + RotL64(aScatter, 24U)) + 17310049041983079779U;
            aOrbiterC = ((aWandererJ + RotL64(aCross, 53U)) + 8246925977992441471U) + aNonceWordP;
            aOrbiterA = (((aWandererA + RotL64(aIngress, 43U)) + RotL64(aCarry, 47U)) + 8644260919918112781U) + aPhaseFOrbiterAssignSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterE = ((((aWandererB + RotL64(aCross, 3U)) + RotL64(aCarry, 27U)) + 13401663736874819483U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 28U)) & S_SALT1]) + aNonceWordI;
            aOrbiterJ = ((aWandererI + RotL64(aScatter, 47U)) + 7940358935238314973U) + aNonceWordB;
            aOrbiterG = ((aWandererG + RotL64(aPrevious, 35U)) + RotL64(aCarry, 19U)) + 13278990328548007839U;
            aOrbiterK = ((aWandererK + RotL64(aIngress, 19U)) + 11346868298353840706U) + aNonceWordC;
            aOrbiterB = (aWandererD + RotL64(aCross, 28U)) + 2374077904806833579U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 6978903378645019166U) + aNonceWordE;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 11951633297870965212U;
            aOrbiterC = RotL64((aOrbiterC * 12778236598654492185U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 17398460995357409673U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 1215437945597836770U;
            aOrbiterE = RotL64((aOrbiterE * 9322970054123481621U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 1878751468043972239U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 5343002808239712390U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 11878640995447558811U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 9884918450053276861U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 15894599082080422550U;
            aOrbiterK = RotL64((aOrbiterK * 8359936745539546131U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 13917339232771145459U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 18101134009493720683U;
            aOrbiterD = RotL64((aOrbiterD * 15835859435306756387U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 3830086372356903769U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 15894394599564584010U;
            aOrbiterH = RotL64((aOrbiterH * 9513921913446609263U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 5127590955274245812U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 9410946933309720054U;
            aOrbiterB = RotL64((aOrbiterB * 14507476989423060561U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 15544384157294987085U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterB) ^ 998801294460434123U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterJ = RotL64((aOrbiterJ * 5946968142746472745U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 16442095194965452163U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 14294936349037516932U;
            aOrbiterA = RotL64((aOrbiterA * 14655345374740882581U), 19U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterH, 19U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 23U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 48U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 57U));
            aIngress = aIngress + RotL64(aOrbiterG, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aScatter, 51U) + aOrbiterG) + RotL64(aOrbiterC, 24U)) + RotL64(aCarry, 5U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 6U) + RotL64(aOrbiterJ, 47U)) + aOrbiterD) + aNonceWordF);
            aWandererC = aWandererC + (((RotL64(aIngress, 35U) + aOrbiterH) + RotL64(aOrbiterG, 19U)) + RotL64(aCarry, 51U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 57U) + aOrbiterE) + RotL64(aOrbiterJ, 29U));
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 47U) + RotL64(aOrbiterB, 11U)) + aOrbiterJ) + aNonceWordN) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 29U) + aOrbiterC) + RotL64(aOrbiterH, 5U));
            aWandererE = aWandererE + ((((RotL64(aScatter, 13U) + aOrbiterB) + RotL64(aOrbiterK, 57U)) + aNonceWordJ) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 24U) + RotL64(aOrbiterA, 52U)) + aOrbiterH);
            aWandererD = aWandererD + ((RotL64(aScatter, 41U) + RotL64(aOrbiterB, 43U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererB, 19U) ^ aWandererC);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 35U));
            aCarry = aCarry + (RotL64(aWandererA, 44U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererE, 29U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererK, 11U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aSnowLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_f loop 2
        // ingress from: aSnowLaneC, aOperationLaneC, aOperationLaneD, aWorkLaneD
        // ingress directions: aSnowLaneC forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aWorkLaneD forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aWorkLaneC
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aWorkLaneC backward/forward random
        // write to: aSnowLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneC[((aIndex + 9537U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneC[((aIndex + 10767U)) & S_BLOCK1], 4U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 7560U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 10798U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 7029U)) & S_BLOCK1], 20U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 9421U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 10070U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCross, 39U) ^ RotL64(aIngress, 20U)) + (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 51U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterI = ((aWandererJ + RotL64(aScatter, 30U)) + 6342299552323486695U) + aNonceWordG;
            aOrbiterC = (((aWandererH + RotL64(aIngress, 11U)) + RotL64(aCarry, 5U)) + 12692748514781367538U) + aNonceWordA;
            aOrbiterE = (aWandererA + RotL64(aCross, 57U)) + 8202639945493229155U;
            aOrbiterK = ((aWandererF + RotL64(aPrevious, 53U)) + 4439975701793231639U) + aNonceWordI;
            aOrbiterG = ((aWandererC + RotL64(aScatter, 5U)) + 16774235182859553759U) + aNonceWordC;
            aOrbiterA = (((aWandererK + RotL64(aCross, 19U)) + RotL64(aCarry, 21U)) + 8764155413335405667U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterB = (aWandererB + RotL64(aIngress, 42U)) + 7167848811974967685U;
            aOrbiterF = ((aWandererI + RotL64(aPrevious, 47U)) + 16768278912125334220U) + aPhaseFOrbiterAssignSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterH = ((aWandererE + RotL64(aScatter, 23U)) + RotL64(aCarry, 53U)) + 9090838954826296201U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 7644075729758006298U) + aNonceWordB;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 17326182797908071215U;
            aOrbiterE = RotL64((aOrbiterE * 2408330168749256075U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 16158809721888137555U) + aNonceWordH;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 8029938783858263694U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12628072435324195483U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 8716553521415553404U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 7012599977009208840U;
            aOrbiterB = RotL64((aOrbiterB * 8775355876188948851U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 13250558696578541499U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 13705957059101025396U;
            aOrbiterI = RotL64((aOrbiterI * 16889495686487056367U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 2796775206291902461U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 13741676263512390669U) ^ aNonceWordN;
            aOrbiterF = RotL64((aOrbiterF * 10455782033465595947U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 1691908360612389252U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 4114939415206031540U;
            aOrbiterH = RotL64((aOrbiterH * 2797401802892718297U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 2374911514440738727U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 12377616933668803091U;
            aOrbiterG = RotL64((aOrbiterG * 2505164835116651215U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 681094033415259645U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 13841322124900463362U;
            aOrbiterK = RotL64((aOrbiterK * 4210414203856902329U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 18082983557580381338U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 15731122225678626778U;
            aOrbiterA = RotL64((aOrbiterA * 7785999919955613789U), 13U);
            //
            aIngress = RotL64(aOrbiterE, 28U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 53U));
            aIngress = aIngress + (RotL64(aOrbiterG, 43U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 37U));
            aIngress = aIngress + RotL64(aOrbiterI, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 11U) + aOrbiterC) + RotL64(aOrbiterK, 43U)) + aPhaseFWandererUpdateSaltC[((aIndex + 28U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 30U) + RotL64(aOrbiterF, 14U)) + aOrbiterI);
            aWandererH = aWandererH + ((((RotL64(aScatter, 53U) + RotL64(aOrbiterE, 57U)) + aOrbiterG) + RotL64(aCarry, 47U)) + aNonceWordJ);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 43U) + aOrbiterI) + RotL64(aOrbiterB, 5U));
            aWandererK = aWandererK + ((((RotL64(aPrevious, 23U) + aOrbiterI) + RotL64(aOrbiterA, 27U)) + RotL64(aCarry, 37U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aCross, 35U) + aOrbiterG) + RotL64(aOrbiterA, 47U)) + aNonceWordO);
            aWandererI = aWandererI + (((RotL64(aIngress, 5U) + aOrbiterK) + RotL64(aOrbiterB, 37U)) + aNonceWordP);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 47U) + aOrbiterC) + RotL64(aOrbiterA, 52U));
            aWandererB = aWandererB + ((RotL64(aPrevious, 58U) + aOrbiterF) + RotL64(aOrbiterH, 21U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 47U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 58U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 23U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 39U));
            aCarry = aCarry + RotL64(aWandererJ, 5U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aSnowLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_f loop 3
        // ingress from: aSnowLaneD, aOperationLaneA, aInvestLaneB
        // ingress directions: aSnowLaneD forward forced, aOperationLaneA forward forced, aInvestLaneB forward/backward random
        // cross from: aSnowLaneC, aOperationLaneC
        // cross directions: aSnowLaneC backward forced, aOperationLaneC backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneD[((aIndex + 12251U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneA[((aIndex + 16333U)) & S_BLOCK1], 56U));
            aIngress ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 15238U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordE));
            //
            aCross = RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 12673U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneC[((aIndex + 16313U)) & S_BLOCK1], 44U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aIngress, 41U) ^ RotL64(aCross, 29U)) + (RotL64(aPrevious, 14U) ^ RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterC = ((aWandererG + RotL64(aIngress, 27U)) + RotL64(aCarry, 47U)) + 1210605127156905516U;
            aOrbiterA = (aWandererI + RotL64(aCross, 19U)) + 11964595428173569519U;
            aOrbiterB = (((aWandererB + RotL64(aScatter, 58U)) + RotL64(aCarry, 21U)) + 16277319029916258482U) + aNonceWordM;
            aOrbiterI = ((aWandererJ + RotL64(aPrevious, 47U)) + RotL64(aCarry, 57U)) + 12369497463101824572U;
            aOrbiterJ = ((aWandererE + RotL64(aScatter, 37U)) + 6201248574067068202U) + aNonceWordN;
            aOrbiterE = ((aWandererK + RotL64(aCross, 13U)) + 1727477025667206661U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = (aWandererC + RotL64(aIngress, 4U)) + 1404510627789806851U;
            aOrbiterD = ((aWandererD + RotL64(aPrevious, 43U)) + 6948213591282018925U) + aPhaseFOrbiterAssignSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterK = ((aWandererF + RotL64(aScatter, 23U)) + 6688865181284421478U) + aNonceWordG;
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 3351130769402360855U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 12681032488906270823U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 3680893896579741263U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 3591412591193726763U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 16153817571210878589U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4165137036092246349U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 3808228354421006630U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterA) ^ 1427373776207504205U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 16U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterI = RotL64((aOrbiterI * 4534374093769595531U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 1831554180932501132U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 1114853085120949215U;
            aOrbiterG = RotL64((aOrbiterG * 4264176108298812905U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 2080935638828366835U) + aNonceWordK;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 16104777999646489828U;
            aOrbiterA = RotL64((aOrbiterA * 15205199362011777473U), 43U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterB) + 9782806013673440791U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1]) + aNonceWordD;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 3721620299829386454U;
            aOrbiterD = RotL64((aOrbiterD * 6286765834910272409U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 4013706412064296527U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 5751022780695158579U;
            aOrbiterJ = RotL64((aOrbiterJ * 13766736471646116397U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 17684546333240329338U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 1106947111128020920U;
            aOrbiterE = RotL64((aOrbiterE * 3158839453318658951U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 11564229705849500598U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 1585817314460274286U;
            aOrbiterK = RotL64((aOrbiterK * 12687162159791577431U), 39U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterB, 27U);
            aIngress = aIngress + (RotL64(aOrbiterG, 47U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterK, 43U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterC, 5U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterE, 30U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aCross, 47U) + aOrbiterE) + RotL64(aOrbiterI, 6U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 58U) + aOrbiterG) + RotL64(aOrbiterE, 43U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 43U) + aOrbiterD) + RotL64(aOrbiterA, 27U)) + RotL64(aCarry, 29U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 19U) + aOrbiterD) + RotL64(aOrbiterB, 39U)) + aPhaseFWandererUpdateSaltD[((aIndex + 13U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 3U) + RotL64(aOrbiterA, 11U)) + aOrbiterC) + aNonceWordL);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 28U) + RotL64(aOrbiterJ, 48U)) + aOrbiterE);
            aWandererF = aWandererF + ((RotL64(aPrevious, 39U) + aOrbiterI) + RotL64(aOrbiterB, 35U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 23U) + aOrbiterA) + RotL64(aOrbiterJ, 19U));
            aWandererG = aWandererG + ((((RotL64(aCross, 51U) + RotL64(aOrbiterE, 53U)) + aOrbiterK) + RotL64(aCarry, 5U)) + aNonceWordO);
            //
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererI);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 53U));
            aCarry = aCarry + (RotL64(aWandererG, 47U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererC, 39U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererE, 44U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_f loop 4
        // ingress from: aExpandLaneA, aSnowLaneC, aSnowLaneA
        // ingress directions: aExpandLaneA forward forced, aSnowLaneC forward forced, aSnowLaneA forward/backward random
        // cross from: aSnowLaneD, aOperationLaneD
        // cross directions: aSnowLaneD backward forced, aOperationLaneD backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 17755U)) & S_BLOCK1], 39U) ^ RotL64(aSnowLaneC[((aIndex + 17210U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 18457U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 21115U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneD[((aIndex + 19071U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aIngress, 50U) + RotL64(aCarry, 37U)) ^ (RotL64(aPrevious, 5U) + RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterE = (((aWandererK + RotL64(aPrevious, 29U)) + RotL64(aCarry, 47U)) + 17711946802293254150U) + aNonceWordH;
            aOrbiterK = (((aWandererA + RotL64(aScatter, 3U)) + 16652362590489569378U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordD;
            aOrbiterH = ((aWandererD + RotL64(aIngress, 24U)) + 6972810344198183097U) + aPhaseFOrbiterAssignSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterI = (aWandererF + RotL64(aCross, 37U)) + 13117100889782940546U;
            aOrbiterC = ((aWandererG + RotL64(aIngress, 41U)) + 13199305696782626591U) + aNonceWordG;
            aOrbiterA = (aWandererE + RotL64(aPrevious, 53U)) + 992156184392760945U;
            aOrbiterG = (aWandererB + RotL64(aCross, 11U)) + 13791265442074543880U;
            aOrbiterB = ((aWandererC + RotL64(aScatter, 48U)) + RotL64(aCarry, 37U)) + 17057087245252294859U;
            aOrbiterJ = ((aWandererH + RotL64(aIngress, 19U)) + RotL64(aCarry, 13U)) + 13444195995883541046U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 6723678233676059420U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 7913379431208430475U;
            aOrbiterH = RotL64((aOrbiterH * 2295062944289127123U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 4481887195529300665U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 11892724101424384078U;
            aOrbiterA = RotL64((aOrbiterA * 3468639499716604111U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 7700902083270424194U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 1888001433557140271U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8975562955027025349U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 14996753906788986929U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 939004845422123765U;
            aOrbiterJ = RotL64((aOrbiterJ * 2507090308972292313U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 11922230289291941807U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 15681187459741147199U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 10124947739653819101U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 9119043713532718155U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 8327697433992362166U;
            aOrbiterB = RotL64((aOrbiterB * 11157657162184304567U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 13630755116592440359U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 771252613886022889U;
            aOrbiterG = RotL64((aOrbiterG * 2958918915223536519U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 8524239721467527770U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 17732617735422435572U;
            aOrbiterI = RotL64((aOrbiterI * 13992947983987668631U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 5265753270696005619U) + aNonceWordO;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 14456128349522985053U) ^ aNonceWordC;
            aOrbiterC = RotL64((aOrbiterC * 5406509991740849617U), 43U);
            //
            aIngress = RotL64(aOrbiterI, 10U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterA, 23U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 35U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 13U));
            aIngress = aIngress + RotL64(aOrbiterJ, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterJ, 60U)) + aOrbiterH) + aNonceWordI);
            aWandererH = aWandererH + ((RotL64(aCross, 5U) + aOrbiterG) + RotL64(aOrbiterB, 5U));
            aWandererD = aWandererD ^ ((((RotL64(aPrevious, 10U) + aOrbiterB) + RotL64(aOrbiterI, 47U)) + aNonceWordN) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aIngress, 19U) + aOrbiterB) + RotL64(aOrbiterJ, 53U)) + aPhaseFWandererUpdateSaltA[((aIndex + 10U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 27U) + aOrbiterA) + RotL64(aOrbiterK, 35U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 23U) + aOrbiterI) + RotL64(aOrbiterA, 39U)) + RotL64(aCarry, 51U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 53U) + aOrbiterE) + RotL64(aOrbiterC, 10U));
            aWandererK = aWandererK + ((((RotL64(aIngress, 46U) + RotL64(aOrbiterI, 21U)) + aOrbiterC) + RotL64(aCarry, 37U)) + aNonceWordF);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 37U) + aOrbiterG) + RotL64(aOrbiterJ, 27U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 57U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 18U));
            aCarry = aCarry + (RotL64(aWandererB, 23U) ^ aWandererF);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 3U));
            aCarry = aCarry + RotL64(aWandererH, 53U);
            aCarry = aCarry + RotL64(aIngress, 26U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_f loop 5
        // ingress from: aExpandLaneB, aSnowLaneD, aInvestLaneD
        // ingress directions: aExpandLaneB forward forced, aSnowLaneD forward forced, aInvestLaneD forward/backward random
        // cross from: aExpandLaneA, aSnowLaneC
        // cross directions: aExpandLaneA backward forced, aSnowLaneC backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 24544U)) & S_BLOCK1], 54U) ^ RotL64(aSnowLaneD[((aIndex + 24419U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aInvestLaneD[((aIndex + 23951U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 25637U)) & S_BLOCK1], 60U) ^ RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 26155U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCross, 23U) + RotL64(aPrevious, 57U)) ^ (RotL64(aCarry, 11U) + RotL64(aIngress, 44U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterG = ((aWandererC + RotL64(aScatter, 35U)) + 16802219662864902427U) + aNonceWordC;
            aOrbiterD = ((aWandererF + RotL64(aIngress, 23U)) + RotL64(aCarry, 13U)) + 14332033461409490629U;
            aOrbiterI = ((aWandererB + RotL64(aCross, 27U)) + RotL64(aCarry, 3U)) + 8781794298640286845U;
            aOrbiterB = ((aWandererG + RotL64(aPrevious, 58U)) + 8459933908074937264U) + aPhaseFOrbiterAssignSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterA = (aWandererE + RotL64(aIngress, 39U)) + 1883580287986004426U;
            aOrbiterJ = ((aWandererI + RotL64(aPrevious, 13U)) + RotL64(aCarry, 21U)) + 17500258188004626118U;
            aOrbiterK = (aWandererJ + RotL64(aScatter, 51U)) + 7934811305150872870U;
            aOrbiterC = (((aWandererH + RotL64(aCross, 44U)) + 6380363892361098905U) + aPhaseFOrbiterAssignSaltB[((aIndex + 19U)) & S_SALT1]) + aNonceWordP;
            aOrbiterE = ((aWandererK + RotL64(aScatter, 5U)) + 12623079132626676910U) + aNonceWordG;
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 10455208121949202703U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 8805532707916767629U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 666082374369701881U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 9161544391400377699U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 3501434325829663268U;
            aOrbiterJ = RotL64((aOrbiterJ * 7933545151293799637U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 651783304096081996U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 441505031509930622U;
            aOrbiterD = RotL64((aOrbiterD * 8045355432310956143U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 1771159983581326424U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 15227946417377695989U;
            aOrbiterE = RotL64((aOrbiterE * 1563141188972797601U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 4153717524193279095U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 4404521756523902829U;
            aOrbiterG = RotL64((aOrbiterG * 1410342912973206203U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 6231945075461813285U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 3864780227164426690U;
            aOrbiterB = RotL64((aOrbiterB * 18031353247480673617U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 1509699687948576558U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 17316114302489411191U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 15490661284980281585U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 2250572827340157410U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 6403966113144372915U;
            aOrbiterC = RotL64((aOrbiterC * 726441947009132383U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 2329903609147403156U) + aNonceWordE;
            aOrbiterK = (((aOrbiterK ^ aOrbiterA) ^ 2486330017319455238U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterK = RotL64((aOrbiterK * 17427461345935191757U), 51U);
            //
            aIngress = RotL64(aOrbiterD, 26U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 39U));
            aIngress = aIngress + (RotL64(aOrbiterE, 53U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterG, 29U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterA, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aCross, 57U) + aOrbiterE) + RotL64(aOrbiterC, 19U));
            aWandererE = aWandererE + (((RotL64(aScatter, 48U) + RotL64(aOrbiterG, 47U)) + aOrbiterB) + aNonceWordA);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 29U) + RotL64(aOrbiterG, 27U)) + aOrbiterE) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aPrevious, 19U) + aOrbiterJ) + RotL64(aOrbiterK, 52U)) + RotL64(aCarry, 11U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 3U) + aOrbiterJ) + RotL64(aOrbiterC, 41U)) + aNonceWordO);
            aWandererK = aWandererK + (((RotL64(aIngress, 53U) + RotL64(aOrbiterJ, 13U)) + aOrbiterB) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterI, 5U)) + aOrbiterA);
            aWandererH = aWandererH + (((RotL64(aScatter, 35U) + aOrbiterE) + RotL64(aOrbiterD, 23U)) + RotL64(aCarry, 19U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 44U) + RotL64(aOrbiterC, 36U)) + aOrbiterA) + aNonceWordJ);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 48U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 35U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 53U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 27U));
            aCarry = aCarry + RotL64(aWandererF, 41U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 29737U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneA[((aIndex + 27435U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aInvestLaneA[((aIndex + 31045U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31255U)) & S_BLOCK1], 26U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 32671U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aPrevious, 23U) ^ RotL64(aCarry, 35U)) + (RotL64(aCross, 48U) ^ RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterB = ((aWandererB + RotL64(aIngress, 51U)) + 9855743441035905047U) + aPhaseFOrbiterAssignSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = (aWandererJ + RotL64(aScatter, 43U)) + 8426286937143990276U;
            aOrbiterG = (aWandererE + RotL64(aPrevious, 60U)) + 7146752367170267002U;
            aOrbiterH = ((aWandererA + RotL64(aCross, 21U)) + 12947210066678101726U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterC = ((aWandererI + RotL64(aScatter, 29U)) + RotL64(aCarry, 11U)) + 15902163559925328965U;
            aOrbiterD = (((aWandererH + RotL64(aPrevious, 11U)) + RotL64(aCarry, 37U)) + 8506649889346449469U) + aNonceWordK;
            aOrbiterF = ((aWandererG + RotL64(aCross, 39U)) + RotL64(aCarry, 21U)) + 8226286036430263052U;
            aOrbiterI = ((aWandererC + RotL64(aIngress, 34U)) + 2703047093452420216U) + aNonceWordH;
            aOrbiterJ = (aWandererF + RotL64(aCross, 3U)) + 6769351326360139560U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 9857025533281333281U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 238297452132277585U;
            aOrbiterG = RotL64((aOrbiterG * 12974709749856065985U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 7203572312072908931U) + aNonceWordA;
            aOrbiterC = (((aOrbiterC ^ aOrbiterH) ^ 12497027346166575632U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterC = RotL64((aOrbiterC * 1703586436725662307U), 43U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 473851890609048879U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 1664484956453886047U;
            aOrbiterF = RotL64((aOrbiterF * 8566500756326590209U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 4635095143004754116U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 17695676150967345793U;
            aOrbiterH = RotL64((aOrbiterH * 5780416541584439301U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 15628965269863402796U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 9190117464399730235U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5586437438425999715U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 17835918238346011086U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 4398005402429282682U;
            aOrbiterE = RotL64((aOrbiterE * 14828737209913317463U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 10902589938246551273U) + aNonceWordI;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 15124274429081385923U;
            aOrbiterJ = RotL64((aOrbiterJ * 13524180348258805367U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 8747233520702236018U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 5445611443463112371U;
            aOrbiterB = RotL64((aOrbiterB * 10294109295823410447U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 16296005217836151910U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 6468336224317602364U;
            aOrbiterD = RotL64((aOrbiterD * 7369779919748367133U), 57U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterD, 11U);
            aIngress = aIngress + (RotL64(aOrbiterG, 43U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterJ, 3U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterE, 34U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterB, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aScatter, 19U) + aOrbiterD) + RotL64(aOrbiterH, 29U));
            aWandererI = aWandererI + (((RotL64(aCross, 11U) + RotL64(aOrbiterB, 11U)) + aOrbiterG) + RotL64(aCarry, 41U));
            aWandererA = aWandererA ^ ((((RotL64(aIngress, 42U) + RotL64(aOrbiterB, 47U)) + aOrbiterE) + aNonceWordO) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 35U) + aOrbiterF) + RotL64(aOrbiterJ, 41U)) + RotL64(aCarry, 27U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 29U) + aOrbiterG) + RotL64(aOrbiterC, 6U));
            aWandererC = aWandererC + (((RotL64(aScatter, 57U) + aOrbiterB) + RotL64(aOrbiterF, 21U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 52U) + RotL64(aOrbiterD, 51U)) + aOrbiterF) + aNonceWordD);
            aWandererH = aWandererH + (((RotL64(aCross, 5U) + RotL64(aOrbiterH, 37U)) + aOrbiterB) + aNonceWordE);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterI, 56U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererB, 42U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererJ, 5U) ^ aWandererA);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 23U));
            aCarry = aCarry + (RotL64(aWandererE, 39U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererI, 19U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x89B9F77C9F650EC7ULL + 0x9C3F79B7190B7FDEULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x9EC645446BA5D051ULL + 0xBFAB251C4680FE2DULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x98F53ED2281ECE27ULL + 0xBEBBB60DEFDDC98BULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xB509BEFA009E0CCBULL + 0xD9C8A4AF6C395C18ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xDA31EA3E63E455B5ULL + 0xFAB6E7729B50AD87ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x85E384DE45096617ULL + 0xCF9329AE2CB76B4BULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xD3009C51818E1F79ULL + 0x8F31D79ACFF81CFDULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xA7851D50933F3C5FULL + 0x96616749488337E9ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xBB5687D1FC1B88BDULL + 0xA613582A9A810062ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xF0DCF28905C4B45FULL + 0x8DD01A8820CFC7C9ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xD37E93FC2A0D9ACDULL + 0xD98C170D87E2346BULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xE47A33F99AA950EBULL + 0xFAD887D726B41CC9ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xFC404549AB31FA2BULL + 0xAB453F6ABFCEDA51ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xC96C8ADF172CB7F7ULL + 0xBF6EF56F8E599324ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xD081DAFE72DD35B1ULL + 0xC002A50F145457ECULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xD68691D30DA79721ULL + 0x870E543660C92294ULL);
    // GSeedRunSeed_G seed_loop_h (start)
    {
        // GSeedRunSeed_G seed_loop_h lane group
        // read from: aSnowLaneA, aSnowLaneB, aFireLaneB, aSnowLaneC, aSnowLaneD, aInvestLaneC, aWorkLaneA, aFireLaneD, aFireLaneA, aWorkLaneB, aInvestLaneA, aExpandLaneA, aInvestLaneD, aExpandLaneB, aInvestLaneB, aExpandLaneC, aFireLaneC
        // write to: aWorkLaneA, aWorkLaneB, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // seed_loop_h loop 1
        // ingress from: aSnowLaneA, aSnowLaneB, aFireLaneB
        // ingress directions: aSnowLaneA forward forced, aSnowLaneB forward forced, aFireLaneB forward/backward random
        // cross from: aSnowLaneC, aSnowLaneD, aInvestLaneC
        // cross directions: aSnowLaneC backward forced, aSnowLaneD backward forced, aInvestLaneC backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneA[((aIndex + 233U)) & S_BLOCK1], 39U) ^ RotL64(aSnowLaneB[((aIndex + 4511U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 5428U)) & S_BLOCK1], 10U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 2119U)) & S_BLOCK1], 20U) ^ RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 344U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 910U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aPrevious, 13U) + RotL64(aCross, 54U)) ^ (RotL64(aCarry, 39U) + RotL64(aIngress, 27U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterG = ((aWandererJ + RotL64(aScatter, 29U)) + 5568146815535263910U) + aNonceWordO;
            aOrbiterA = (((aWandererF + RotL64(aCross, 35U)) + RotL64(aCarry, 51U)) + 7736084960873834666U) + aNonceWordC;
            aOrbiterF = (aWandererG + RotL64(aPrevious, 13U)) + 1336413621817562093U;
            aOrbiterB = ((aWandererA + RotL64(aIngress, 19U)) + RotL64(aCarry, 39U)) + 5218462026934984692U;
            aOrbiterE = (((aWandererE + RotL64(aCross, 3U)) + 7048890985969555935U) + aPhaseHOrbiterAssignSaltA[((aIndex + 8U)) & S_SALT1]) + aNonceWordM;
            aOrbiterC = (((aWandererD + RotL64(aPrevious, 41U)) + RotL64(aCarry, 21U)) + 13415955213864702118U) + aNonceWordI;
            aOrbiterI = ((aWandererC + RotL64(aScatter, 50U)) + 5657023257021528548U) + aPhaseHOrbiterAssignSaltC[((aIndex + 18U)) & S_SALT1];
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 14338310943137497116U) + aNonceWordN;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 12305161641833950473U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11949964304435964395U), 13U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterB) + 14514226578370459131U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 12692904083266024340U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 14800805065279908839U), 21U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 11012959130001327964U) + aNonceWordE;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 7106471380403489078U;
            aOrbiterG = RotL64((aOrbiterG * 515626559384817223U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 3718101961355280891U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 13364192077222322664U;
            aOrbiterI = RotL64((aOrbiterI * 1411328915372590283U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 6720867800318913440U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 14497243926965866546U;
            aOrbiterB = RotL64((aOrbiterB * 13595058589060114653U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 5789056168233262435U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterE) ^ 14438482587495779937U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterA = RotL64((aOrbiterA * 10593535547917767263U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 313917798940179945U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 15241845511889502917U;
            aOrbiterC = RotL64((aOrbiterC * 16483477103771326107U), 43U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterF, 36U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 47U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 23U));
            aIngress = aIngress + RotL64(aOrbiterE, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aScatter, 27U) + RotL64(aOrbiterF, 57U)) + aOrbiterB) + aNonceWordA);
            aWandererE = aWandererE + (((RotL64(aIngress, 21U) + aOrbiterE) + RotL64(aOrbiterI, 41U)) + RotL64(aCarry, 53U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 11U) + aOrbiterI) + RotL64(aOrbiterF, 18U)) + aNonceWordH);
            aWandererC = aWandererC + ((RotL64(aCross, 51U) + aOrbiterC) + RotL64(aOrbiterA, 3U));
            aWandererA = aWandererA ^ ((((RotL64(aPrevious, 43U) + RotL64(aOrbiterC, 29U)) + aOrbiterG) + aNonceWordD) + aPhaseHWandererUpdateSaltE[((aIndex + 7U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 3U) + aOrbiterC) + RotL64(aOrbiterE, 35U)) + RotL64(aCarry, 23U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 36U) + RotL64(aOrbiterF, 51U)) + aOrbiterE) + aPhaseHWandererUpdateSaltF[((aIndex + 20U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 13U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 22U));
            aCarry = aCarry + (RotL64(aWandererE, 3U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererA, 35U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 6382U)) & S_BLOCK1], 3U) ^ RotL64(aSnowLaneC[((aIndex + 6115U)) & S_BLOCK1], 51U));
            aIngress ^= (RotL64(aSnowLaneD[((aIndex + 9031U)) & S_BLOCK1], 35U) ^ RotL64(aFireLaneD[((aIndex + 7051U)) & S_BLOCK1], 14U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 5826U)) & S_BLOCK1], 35U) ^ RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 9461U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 9193U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aPrevious, 6U) ^ RotL64(aCarry, 21U)) + (RotL64(aIngress, 53U) + RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterD = (aWandererC + RotL64(aCross, 51U)) + 4773124477323378268U;
            aOrbiterK = (((aWandererH + RotL64(aScatter, 5U)) + 16848723289435796005U) + aPhaseHOrbiterAssignSaltF[((aIndex + 3U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterI = ((((aWandererE + RotL64(aPrevious, 27U)) + RotL64(aCarry, 57U)) + 13846642134917107058U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordP;
            aOrbiterH = ((aWandererG + RotL64(aIngress, 13U)) + RotL64(aCarry, 21U)) + 6472057872482789939U;
            aOrbiterF = ((aWandererI + RotL64(aPrevious, 19U)) + 2747019500690707226U) + aNonceWordO;
            aOrbiterE = ((aWandererB + RotL64(aScatter, 39U)) + RotL64(aCarry, 37U)) + 9003965289739733880U;
            aOrbiterC = ((aWandererJ + RotL64(aCross, 60U)) + 3013390651936257377U) + aNonceWordK;
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 3331004709895625067U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 15355010435553517129U;
            aOrbiterI = RotL64((aOrbiterI * 8322759117004876831U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 7709870658004280052U) + aNonceWordB;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 13568728443963926564U;
            aOrbiterF = RotL64((aOrbiterF * 6736090830113688981U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 12409548853419307131U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 969183352023661537U;
            aOrbiterE = RotL64((aOrbiterE * 5549220554838837145U), 23U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterC) + 15370309834426476775U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1]) + aNonceWordN;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 3896803894396631184U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 11018830202891911603U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 10848873633291935766U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 12885336509190543440U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 1487357252619221365U), 35U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterD) + 8252290890093788010U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1]) + aNonceWordH;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 9201553615601641350U;
            aOrbiterH = RotL64((aOrbiterH * 420321130559162915U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 14014209645503188472U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 4015071464301844550U;
            aOrbiterD = RotL64((aOrbiterD * 17444195018239904971U), 53U);
            //
            aIngress = RotL64(aOrbiterI, 47U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 57U));
            aIngress = aIngress + (RotL64(aOrbiterE, 3U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterH, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 35U) + RotL64(aOrbiterD, 5U)) + aOrbiterI) + aNonceWordF);
            aWandererC = aWandererC + (((RotL64(aCross, 21U) + aOrbiterI) + RotL64(aOrbiterH, 20U)) + RotL64(aCarry, 5U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 51U) + aOrbiterD) + RotL64(aOrbiterF, 35U)) + aNonceWordG);
            aWandererH = aWandererH + ((((RotL64(aIngress, 57U) + RotL64(aOrbiterI, 13U)) + aOrbiterF) + aNonceWordC) + aPhaseHWandererUpdateSaltA[((aIndex + 11U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aCross, 44U) + aOrbiterD) + RotL64(aOrbiterC, 43U)) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aIngress, 5U) + RotL64(aOrbiterK, 29U)) + aOrbiterE) + RotL64(aCarry, 23U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterE, 53U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 44U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 53U));
            aCarry = aCarry + (RotL64(aWandererG, 11U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererH, 5U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_h loop 3
        // ingress from: aWorkLaneB, aSnowLaneA, aInvestLaneA
        // ingress directions: aWorkLaneB forward forced, aSnowLaneA forward forced, aInvestLaneA forward/backward random
        // cross from: aWorkLaneA, aSnowLaneC
        // cross directions: aWorkLaneA backward forced, aSnowLaneC backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 13083U)) & S_BLOCK1], 20U) ^ RotL64(aSnowLaneA[((aIndex + 11035U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 11221U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 12034U)) & S_BLOCK1], 57U) ^ RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 15228U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCross, 4U) + RotL64(aPrevious, 53U)) ^ (RotL64(aIngress, 39U) + RotL64(aCarry, 27U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterJ = (aWandererK + RotL64(aIngress, 30U)) + 701291026547470433U;
            aOrbiterA = (aWandererH + RotL64(aPrevious, 3U)) + 17283292650462111643U;
            aOrbiterC = ((aWandererC + RotL64(aScatter, 19U)) + RotL64(aCarry, 57U)) + 9969124091931303406U;
            aOrbiterK = ((aWandererE + RotL64(aCross, 51U)) + 889176772718046988U) + aPhaseHOrbiterAssignSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterH = ((aWandererF + RotL64(aPrevious, 57U)) + RotL64(aCarry, 21U)) + 6054541844643748084U;
            aOrbiterI = ((aWandererB + RotL64(aIngress, 11U)) + 14703226235143028132U) + aNonceWordG;
            aOrbiterE = ((((aWandererG + RotL64(aCross, 39U)) + RotL64(aCarry, 37U)) + 7977975878522921062U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordE;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 16894322614172266274U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 12160451749345900570U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 18055355572903901749U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 10870847008043897470U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 8159920947172520247U;
            aOrbiterI = RotL64((aOrbiterI * 4833194641611011805U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 2440099120969517932U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 2428396147731468007U;
            aOrbiterK = RotL64((aOrbiterK * 9363073341539598441U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 2213226274394673479U) + aNonceWordH;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 7079731443427765333U;
            aOrbiterJ = RotL64((aOrbiterJ * 16918930776877030559U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 958896789550478970U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 10788682955708075458U;
            aOrbiterE = RotL64((aOrbiterE * 913321215613559729U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 2003386579317564870U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 8419686358774204999U) ^ aNonceWordI;
            aOrbiterH = RotL64((aOrbiterH * 6547052526438697621U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 6989167615157578904U) + aNonceWordM;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 17636634003643824148U;
            aOrbiterA = RotL64((aOrbiterA * 11038576417283732937U), 35U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterK, 43U);
            aIngress = aIngress + (RotL64(aOrbiterC, 5U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterI, 57U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterJ, 26U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aCross, 29U) + aOrbiterH) + RotL64(aOrbiterK, 23U)) + aNonceWordO);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 11U) + RotL64(aOrbiterC, 53U)) + aOrbiterI) + aNonceWordB) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 37U) + RotL64(aOrbiterJ, 41U)) + aOrbiterC) + aPhaseHWandererUpdateSaltC[((aIndex + 16U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aIngress, 53U) + RotL64(aOrbiterA, 29U)) + aOrbiterE) + RotL64(aCarry, 51U)) + aNonceWordK);
            aWandererC = aWandererC ^ ((RotL64(aCross, 44U) + RotL64(aOrbiterH, 35U)) + aOrbiterE);
            aWandererF = aWandererF + (((RotL64(aScatter, 3U) + aOrbiterJ) + RotL64(aOrbiterI, 14U)) + RotL64(aCarry, 11U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 21U) + aOrbiterJ) + RotL64(aOrbiterH, 47U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 47U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 11U));
            aCarry = aCarry + (RotL64(aWandererF, 23U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererC, 38U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 16513U)) & S_BLOCK1], 36U) ^ RotL64(aWorkLaneA[((aIndex + 21176U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 17783U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 18841U)) & S_BLOCK1], 37U) ^ RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 19231U)) & S_BLOCK1], 56U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCarry, 39U) + RotL64(aIngress, 3U)) ^ (RotL64(aPrevious, 20U) + RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterG = (((aWandererB + RotL64(aScatter, 43U)) + 5171470532667965920U) + aPhaseHOrbiterAssignSaltA[((aIndex + 3U)) & S_SALT1]) + aNonceWordE;
            aOrbiterI = ((aWandererF + RotL64(aPrevious, 11U)) + RotL64(aCarry, 51U)) + 750549462358682403U;
            aOrbiterE = ((aWandererH + RotL64(aIngress, 22U)) + 3325689257577120525U) + aNonceWordG;
            aOrbiterB = ((((aWandererJ + RotL64(aCross, 29U)) + RotL64(aCarry, 39U)) + 18031575461559790826U) + aPhaseHOrbiterAssignSaltC[((aIndex + 29U)) & S_SALT1]) + aNonceWordL;
            aOrbiterJ = (aWandererI + RotL64(aPrevious, 3U)) + 13874739537012288677U;
            aOrbiterK = (aWandererK + RotL64(aIngress, 53U)) + 4250029868785016865U;
            aOrbiterA = ((aWandererD + RotL64(aScatter, 37U)) + RotL64(aCarry, 5U)) + 8211158803112611161U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 1083939790236786027U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 3446525462376962464U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 13603702473750888213U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 6973817815000417325U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 15230876489676945543U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 7737039082964537651U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 9359727659738755880U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 8775170107816327654U;
            aOrbiterJ = RotL64((aOrbiterJ * 6910680458261008653U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 11958941755525038545U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 16966819714283167348U) ^ aNonceWordH;
            aOrbiterG = RotL64((aOrbiterG * 16363457661846050749U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 14556087985619763243U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 17915047508377045221U) ^ aNonceWordA;
            aOrbiterA = RotL64((aOrbiterA * 6727635453185130109U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 8578745677485367222U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 7002181668717618866U;
            aOrbiterI = RotL64((aOrbiterI * 12329703532414955235U), 27U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterJ) + 3569939503066735457U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1]) + aNonceWordD;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 2956247934282522184U;
            aOrbiterK = RotL64((aOrbiterK * 9946650822131152531U), 35U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterA, 11U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 53U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 35U));
            aIngress = aIngress + RotL64(aOrbiterK, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aScatter, 57U) + RotL64(aOrbiterK, 35U)) + aOrbiterG) + RotL64(aCarry, 47U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterK, 29U)) + aOrbiterJ);
            aWandererB = aWandererB + (((RotL64(aIngress, 48U) + RotL64(aOrbiterB, 43U)) + aOrbiterK) + aNonceWordB);
            aWandererD = aWandererD ^ ((((RotL64(aPrevious, 13U) + RotL64(aOrbiterJ, 19U)) + aOrbiterI) + aNonceWordM) + aPhaseHWandererUpdateSaltF[((aIndex + 17U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aCross, 19U) + RotL64(aOrbiterG, 53U)) + aOrbiterE);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterA, 13U)) + aOrbiterK);
            aWandererK = aWandererK + ((((RotL64(aIngress, 41U) + aOrbiterB) + RotL64(aOrbiterI, 6U)) + RotL64(aCarry, 29U)) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 29U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererH, 6U) ^ aWandererB);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 57U));
            aCarry = aCarry + RotL64(aWandererD, 21U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 26596U)) & S_BLOCK1], 48U) ^ RotL64(aWorkLaneB[((aIndex + 23532U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 23646U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 26728U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23051U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 37U)) + (RotL64(aIngress, 51U) ^ RotL64(aCross, 22U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterK = (aWandererB + RotL64(aIngress, 44U)) + 14008824488073394623U;
            aOrbiterF = ((aWandererJ + RotL64(aCross, 5U)) + 13317978415866411468U) + aNonceWordF;
            aOrbiterE = ((aWandererE + RotL64(aPrevious, 51U)) + 13209180141897453900U) + aNonceWordL;
            aOrbiterD = (((aWandererD + RotL64(aScatter, 11U)) + RotL64(aCarry, 53U)) + 11870521586865233578U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterH = ((((aWandererH + RotL64(aIngress, 29U)) + RotL64(aCarry, 39U)) + 8052156380448047385U) + aPhaseHOrbiterAssignSaltD[((aIndex + 19U)) & S_SALT1]) + aNonceWordE;
            aOrbiterG = ((aWandererC + RotL64(aPrevious, 57U)) + RotL64(aCarry, 13U)) + 12158131176743680605U;
            aOrbiterC = (aWandererG + RotL64(aCross, 21U)) + 14674467487607719347U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 18055496790566231147U) + aNonceWordG;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 3838105585041578784U;
            aOrbiterE = RotL64((aOrbiterE * 1075709247574580091U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 2839568255183054418U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 11933612922864258179U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7571964469321160347U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 6289849094151630580U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 2640344350528492271U;
            aOrbiterF = RotL64((aOrbiterF * 16197726750829369365U), 41U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 16306175266267657791U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 3339898380394883600U;
            aOrbiterD = RotL64((aOrbiterD * 7105436590182982373U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 15017076663742800002U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 8973064296077602496U;
            aOrbiterK = RotL64((aOrbiterK * 9309462227233615761U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 17580319233338139859U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 14063208878807603874U;
            aOrbiterC = RotL64((aOrbiterC * 16601475239075164585U), 21U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterE) + 13326130855721009942U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1]) + aNonceWordD;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 12843186026737544416U;
            aOrbiterG = RotL64((aOrbiterG * 4975848122837321619U), 13U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterD, 51U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 23U));
            aIngress = aIngress + (RotL64(aOrbiterF, 57U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterK, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aCross, 13U) + RotL64(aOrbiterF, 51U)) + aOrbiterC) + RotL64(aCarry, 3U)) + aNonceWordM);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterF, 5U)) + aOrbiterK);
            aWandererD = aWandererD + ((((RotL64(aScatter, 39U) + aOrbiterG) + RotL64(aOrbiterH, 19U)) + RotL64(aCarry, 39U)) + aNonceWordN);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 53U) + aOrbiterH) + RotL64(aOrbiterE, 27U)) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aCross, 19U) + RotL64(aOrbiterG, 60U)) + aOrbiterD);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 30U) + RotL64(aOrbiterG, 13U)) + aOrbiterF);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 3U) + aOrbiterK) + RotL64(aOrbiterE, 41U)) + aNonceWordH) + aPhaseHWandererUpdateSaltD[((aIndex + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 39U));
            aCarry = aCarry + (RotL64(aWandererG, 43U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererC, 27U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererE, 34U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_h loop 6
        // ingress from: aExpandLaneC, aExpandLaneA, aFireLaneC
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aFireLaneC forward/backward random
        // cross from: aExpandLaneB, aSnowLaneB
        // cross directions: aExpandLaneB backward forced, aSnowLaneB backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 29953U)) & S_BLOCK1], 48U) ^ RotL64(aExpandLaneA[((aIndex + 31007U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 27549U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31904U)) & S_BLOCK1], 41U) ^ RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 30565U)) & S_BLOCK1], 52U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aIngress, 11U) + RotL64(aCross, 51U)) ^ (RotL64(aPrevious, 23U) ^ RotL64(aCarry, 38U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterC = ((aWandererA + RotL64(aCross, 30U)) + 11039986441331892533U) + aPhaseHOrbiterAssignSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterD = ((aWandererF + RotL64(aIngress, 51U)) + 6256024955965426119U) + aNonceWordA;
            aOrbiterE = ((aWandererG + RotL64(aScatter, 43U)) + 9857443189988995666U) + aNonceWordD;
            aOrbiterG = ((((aWandererI + RotL64(aPrevious, 57U)) + RotL64(aCarry, 35U)) + 11900944813380998208U) + aPhaseHOrbiterAssignSaltE[((aIndex + 14U)) & S_SALT1]) + aNonceWordL;
            aOrbiterI = ((aWandererK + RotL64(aScatter, 37U)) + RotL64(aCarry, 11U)) + 8422577734978875541U;
            aOrbiterA = (aWandererE + RotL64(aIngress, 19U)) + 3100835100713928724U;
            aOrbiterJ = ((aWandererH + RotL64(aCross, 11U)) + RotL64(aCarry, 53U)) + 11871553509810206993U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 17614749493763417027U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 3638372131856199916U;
            aOrbiterE = RotL64((aOrbiterE * 480683274898147025U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 6582275259281025770U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 17016882418498941958U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 4269869255230867823U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 1747214688658984715U) + aNonceWordH;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 9356088987044015278U;
            aOrbiterC = RotL64((aOrbiterC * 16221733545319753695U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 4056238112133473456U) + aNonceWordG;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterI) ^ 16013150119949532998U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterJ = RotL64((aOrbiterJ * 12913648646318115315U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 16076621211111834889U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 9940824359571581765U;
            aOrbiterD = RotL64((aOrbiterD * 11624767861336495331U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 15624084004784515753U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterJ) ^ 7630989544834680335U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterG = RotL64((aOrbiterG * 12261063237156822067U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 18003586430673313786U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 1654118743290334161U;
            aOrbiterA = RotL64((aOrbiterA * 1153250137357176071U), 19U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterE, 13U);
            aIngress = aIngress + (RotL64(aOrbiterC, 19U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterI, 51U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterG, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aIngress, 35U) + RotL64(aOrbiterG, 60U)) + aOrbiterD);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 53U) + aOrbiterA) + RotL64(aOrbiterJ, 53U)) + aNonceWordB);
            aWandererH = aWandererH + (((RotL64(aCross, 60U) + aOrbiterD) + RotL64(aOrbiterE, 35U)) + aPhaseHWandererUpdateSaltB[((aIndex + 13U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 3U) + aOrbiterC) + RotL64(aOrbiterI, 5U));
            aWandererF = aWandererF + ((((RotL64(aIngress, 21U) + aOrbiterI) + RotL64(aOrbiterJ, 23U)) + RotL64(aCarry, 29U)) + aNonceWordC);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 41U) + aOrbiterI) + RotL64(aOrbiterE, 41U)) + aNonceWordO);
            aWandererK = aWandererK + (((((RotL64(aScatter, 47U) + RotL64(aOrbiterG, 29U)) + aOrbiterA) + RotL64(aCarry, 43U)) + aNonceWordJ) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 13U) ^ aWandererH);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 60U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 27U));
            aCarry = aCarry + RotL64(aWandererI, 41U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltB;
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
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC;
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
    [[maybe_unused]] std::uint64_t *aPhaseDWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltC;
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
            aIngress = RotL64(aKeyRowReadA[((aIndex + 154U)) & W_KEY1], 51U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 1582U)) & W_KEY1], 20U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 719U)) & W_KEY1], 38U) ^ RotL64(mSource[((aIndex + 858U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 24U) + RotL64(aCarry, 5U)) ^ (RotL64(aCross, 53U) + RotL64(aIngress, 41U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterA = ((aWandererE + RotL64(aPrevious, 14U)) + RotL64(aCarry, 11U)) + 6654158889644956636U;
            aOrbiterE = ((aWandererB + RotL64(aScatter, 57U)) + RotL64(aCarry, 23U)) + 9045779659363991870U;
            aOrbiterI = (aWandererH + RotL64(aCross, 5U)) + 3888897662136993491U;
            aOrbiterK = ((aWandererD + RotL64(aIngress, 53U)) + 6882016842864459345U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = ((aWandererK + RotL64(aScatter, 39U)) + 15601891715956172291U) + aPhaseAOrbiterAssignSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = ((aWandererA + RotL64(aCross, 19U)) + RotL64(aCarry, 39U)) + 5176811598629335350U;
            aOrbiterG = (aWandererJ + RotL64(aPrevious, 35U)) + 12519945150889074325U;
            aOrbiterD = (aWandererC + RotL64(aIngress, 26U)) + 4552583214397603278U;
            aOrbiterH = (aWandererI + RotL64(aScatter, 47U)) + 14225482701804864688U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 5485298070606280363U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 11237713257388094289U;
            aOrbiterI = RotL64((aOrbiterI * 11032429223099413011U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 14340345895626142788U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 16275167270553643347U;
            aOrbiterF = RotL64((aOrbiterF * 7308578867128951199U), 53U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 14041860597556520250U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 1436068974197066343U;
            aOrbiterG = RotL64((aOrbiterG * 3938460345031496843U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 11483155566419547004U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 4608508534724289325U;
            aOrbiterB = RotL64((aOrbiterB * 13461385011638899485U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 2389196334288832895U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 4062682330273866602U;
            aOrbiterD = RotL64((aOrbiterD * 8787682133271101901U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 5655656046585592034U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 7977947821249746880U;
            aOrbiterA = RotL64((aOrbiterA * 10082104644185964787U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 11653718118543974168U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 5456429682072377614U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 12504180638665296649U), 37U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 12457179652004203574U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 445821754230182952U;
            aOrbiterH = RotL64((aOrbiterH * 16043092621697786393U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 12429505513284703263U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 12480745784412363537U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 643617210585287593U), 3U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterK, 13U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 47U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 38U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 43U));
            aIngress = aIngress + RotL64(aOrbiterI, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 36U) + RotL64(aOrbiterB, 23U)) + aOrbiterK);
            aWandererC = aWandererC + ((RotL64(aIngress, 47U) + aOrbiterH) + RotL64(aOrbiterK, 18U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 13U) + aOrbiterG) + RotL64(aOrbiterF, 53U));
            aWandererE = aWandererE + (((RotL64(aScatter, 57U) + aOrbiterF) + RotL64(aOrbiterD, 11U)) + aPhaseAWandererUpdateSaltA[((aIndex + 23U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 42U) + RotL64(aOrbiterI, 5U)) + aOrbiterK);
            aWandererK = aWandererK + ((((RotL64(aScatter, 51U) + RotL64(aOrbiterA, 29U)) + aOrbiterG) + RotL64(aCarry, 57U)) + aPhaseAWandererUpdateSaltF[((aIndex + 27U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 29U) + aOrbiterG) + RotL64(aOrbiterB, 48U));
            aWandererB = aWandererB + (((RotL64(aCross, 19U) + aOrbiterH) + RotL64(aOrbiterE, 57U)) + RotL64(aCarry, 21U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 3U) + aOrbiterE) + RotL64(aOrbiterG, 39U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 57U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 27U));
            aCarry = aCarry + (RotL64(aWandererA, 30U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererK, 51U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 5324U)) & S_BLOCK1], 44U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 3531U)) & W_KEY1], 19U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 4057U)) & W_KEY1], 29U) ^ RotL64(mSource[((aIndex + 4800U)) & S_BLOCK1], 44U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 23U) ^ RotL64(aCarry, 39U)) + (RotL64(aCross, 5U) + RotL64(aIngress, 56U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterJ = ((aWandererG + RotL64(aScatter, 47U)) + 2786079456995203065U) + aPhaseAOrbiterAssignSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterB = ((aWandererK + RotL64(aPrevious, 60U)) + RotL64(aCarry, 13U)) + 7237256119153857253U;
            aOrbiterC = (aWandererA + RotL64(aCross, 5U)) + 9310834010563647604U;
            aOrbiterD = ((aWandererE + RotL64(aIngress, 23U)) + RotL64(aCarry, 5U)) + 17361734905706517877U;
            aOrbiterG = (aWandererF + RotL64(aCross, 41U)) + 15837111231884647451U;
            aOrbiterH = (aWandererB + RotL64(aIngress, 27U)) + 18065431964418026445U;
            aOrbiterK = (((aWandererC + RotL64(aScatter, 19U)) + RotL64(aCarry, 47U)) + 3029123922999952652U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterI = (aWandererD + RotL64(aPrevious, 54U)) + 5166926595573507837U;
            aOrbiterE = (aWandererI + RotL64(aScatter, 11U)) + 1918425684273807598U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 4724551751012661440U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 1818014487579644390U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14904092108647864911U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 6670090372241084216U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 8485757110007268693U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 11876760095108618363U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 4928130251509514742U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 2528788422725346792U;
            aOrbiterK = RotL64((aOrbiterK * 1855982047967756661U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 2860387120895147503U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 12927802338151379368U;
            aOrbiterD = RotL64((aOrbiterD * 8876144125458603029U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 18029699867733207083U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 13361836994951253312U;
            aOrbiterI = RotL64((aOrbiterI * 5349767426256597073U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 11957294454794128079U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 3755417922063414648U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13896364063651241401U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 18001157153447913032U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 16214145724690286854U;
            aOrbiterB = RotL64((aOrbiterB * 5874139687703360515U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 3860958772090975562U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 12395621524459640173U;
            aOrbiterH = RotL64((aOrbiterH * 722817135977510161U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 3402035664910754484U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 2139099117325745602U;
            aOrbiterE = RotL64((aOrbiterE * 14008983756425796029U), 29U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterI, 39U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 19U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 3U));
            aIngress = aIngress + (RotL64(aOrbiterH, 51U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterK, 54U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aPrevious, 3U) + aOrbiterI) + RotL64(aOrbiterH, 23U)) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 48U) + RotL64(aOrbiterB, 48U)) + aOrbiterG) + aPhaseAWandererUpdateSaltB[((aIndex + 13U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 21U) + aOrbiterD) + RotL64(aOrbiterB, 43U)) + RotL64(aCarry, 3U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 35U) + aOrbiterI) + RotL64(aOrbiterE, 19U));
            aWandererD = aWandererD + (((RotL64(aIngress, 53U) + aOrbiterC) + RotL64(aOrbiterD, 13U)) + RotL64(aCarry, 27U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 13U) + aOrbiterE) + RotL64(aOrbiterH, 5U));
            aWandererK = aWandererK + ((RotL64(aCross, 60U) + RotL64(aOrbiterK, 53U)) + aOrbiterE);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterD, 28U)) + aOrbiterK);
            aWandererG = aWandererG + ((RotL64(aPrevious, 43U) + RotL64(aOrbiterG, 35U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 5U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 21U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 53U));
            aCarry = aCarry + (RotL64(aWandererK, 47U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererB, 27U);
            aCarry = aCarry + RotL64(aIngress, 50U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = RotL64(aWorkLaneB[((aIndex + 7689U)) & S_BLOCK1], 43U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 6333U)) & W_KEY1], 56U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 7090U)) & W_KEY1], 43U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 7423U)) & S_BLOCK1], 53U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 8110U)) & S_BLOCK1], 22U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 24U) ^ RotL64(aCarry, 51U)) ^ (RotL64(aPrevious, 39U) + RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterE = ((aWandererG + RotL64(aScatter, 27U)) + RotL64(aCarry, 5U)) + 9774364261626083532U;
            aOrbiterF = (aWandererH + RotL64(aIngress, 47U)) + 18059001521926116420U;
            aOrbiterD = (((aWandererC + RotL64(aPrevious, 56U)) + RotL64(aCarry, 21U)) + 10615626210406381148U) + aPhaseAOrbiterAssignSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = ((aWandererF + RotL64(aCross, 19U)) + RotL64(aCarry, 37U)) + 10536484278007898620U;
            aOrbiterJ = (aWandererI + RotL64(aPrevious, 23U)) + 13320663045139972700U;
            aOrbiterA = ((aWandererB + RotL64(aIngress, 35U)) + 17127001787268166583U) + aPhaseAOrbiterAssignSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterG = (aWandererJ + RotL64(aScatter, 41U)) + 16742574590844166551U;
            aOrbiterB = (aWandererE + RotL64(aCross, 4U)) + 8347719720758228053U;
            aOrbiterK = (aWandererK + RotL64(aPrevious, 11U)) + 13502468705946051986U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 3512687886188904904U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 495660316165795934U;
            aOrbiterD = RotL64((aOrbiterD * 6724596801190194913U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 5092722552034477356U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 15641128019608284015U;
            aOrbiterJ = RotL64((aOrbiterJ * 3621036395703527059U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 15421873776811085458U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 17978775513204574125U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 18359600395119440183U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 16617179197537669849U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 1931805387534012528U;
            aOrbiterK = RotL64((aOrbiterK * 3400139345857733775U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 9544923119559308431U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 12930999400470173353U;
            aOrbiterI = RotL64((aOrbiterI * 16791006919271490005U), 53U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 13673733276226249890U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 2032263473309124738U;
            aOrbiterB = RotL64((aOrbiterB * 3088728329261360607U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 14868502349358414206U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 10116495537187552321U;
            aOrbiterA = RotL64((aOrbiterA * 1380512121796709469U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 5341113995358179244U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 8415417980279705731U;
            aOrbiterE = RotL64((aOrbiterE * 8521501372683793821U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 2462819265072352463U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 7657062767608441931U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 15554638801273540163U), 47U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterF, 11U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 35U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 39U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 14U));
            aIngress = aIngress + RotL64(aOrbiterB, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aCross, 58U) + RotL64(aOrbiterA, 57U)) + aOrbiterE);
            aWandererI = aWandererI + ((((RotL64(aScatter, 41U) + aOrbiterA) + RotL64(aOrbiterG, 23U)) + RotL64(aCarry, 39U)) + aPhaseAWandererUpdateSaltC[((aIndex + 23U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 23U) + aOrbiterI) + RotL64(aOrbiterD, 3U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 19U) + aOrbiterK) + RotL64(aOrbiterF, 48U)) + RotL64(aCarry, 23U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterI, 41U)) + aOrbiterJ);
            aWandererG = aWandererG + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterJ, 27U)) + aOrbiterE) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 4U) + RotL64(aOrbiterG, 19U)) + aOrbiterF);
            aWandererH = aWandererH + ((RotL64(aIngress, 53U) + RotL64(aOrbiterB, 53U)) + aOrbiterA);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 11U) + aOrbiterK) + RotL64(aOrbiterD, 36U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 51U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 43U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 57U));
            aCarry = aCarry + (RotL64(aWandererK, 27U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererG, 54U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 8244U)) & S_BLOCK1], 47U) ^ RotL64(aKeyRowReadB[((aIndex + 8434U)) & W_KEY1], 21U));
            aIngress ^= (RotL64(mSource[((aIndex + 10186U)) & S_BLOCK1], 34U) ^ RotL64(aWorkLaneA[((aIndex + 10075U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 9770U)) & W_KEY1], 23U) ^ RotL64(aWorkLaneB[((aIndex + 8660U)) & S_BLOCK1], 12U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 18U) ^ RotL64(aCross, 5U)) + (RotL64(aPrevious, 39U) + RotL64(aCarry, 51U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterI = ((aWandererH + RotL64(aIngress, 29U)) + 15036852811491820366U) + aPhaseBOrbiterAssignSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = (aWandererG + RotL64(aPrevious, 46U)) + 305637140752898475U;
            aOrbiterF = ((aWandererF + RotL64(aCross, 3U)) + 11948631574496129610U) + aPhaseBOrbiterAssignSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = (aWandererJ + RotL64(aScatter, 39U)) + 5321623592482991426U;
            aOrbiterJ = (aWandererE + RotL64(aPrevious, 35U)) + 4075270159062690728U;
            aOrbiterH = (aWandererI + RotL64(aIngress, 11U)) + 15111580500356908928U;
            aOrbiterD = ((aWandererA + RotL64(aCross, 21U)) + RotL64(aCarry, 37U)) + 7244150695504160363U;
            aOrbiterC = ((aWandererD + RotL64(aScatter, 58U)) + RotL64(aCarry, 47U)) + 5131563519577488862U;
            aOrbiterA = ((aWandererB + RotL64(aIngress, 53U)) + RotL64(aCarry, 29U)) + 5881954992088651371U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 12780935808751507998U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 12599159643925470226U;
            aOrbiterF = RotL64((aOrbiterF * 17690046932587062701U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 9466589929741834066U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 6093158735705189789U;
            aOrbiterG = RotL64((aOrbiterG * 7453778295800853653U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 17461243886150519249U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 15456408913739900718U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 16093292401746174671U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 11260643903290392780U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 7870342756041882616U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 2431528656086173419U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 134484990005888936U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 10626896209992890407U;
            aOrbiterC = RotL64((aOrbiterC * 12034131076645285597U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 14031164129515132292U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 1771835705730244212U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 186981668443596623U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 16395472745067254664U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 1455944290845294254U;
            aOrbiterA = RotL64((aOrbiterA * 6757824754363319079U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 17866422769075350837U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 10226884082632410805U;
            aOrbiterD = RotL64((aOrbiterD * 206035536985843815U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 14474587247775371703U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 8501763445324525303U;
            aOrbiterB = RotL64((aOrbiterB * 5298694643596784007U), 3U);
            //
            aIngress = RotL64(aOrbiterH, 44U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterA, 57U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 11U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 35U));
            aIngress = aIngress + RotL64(aOrbiterB, 60U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aCross, 53U) + aOrbiterD) + RotL64(aOrbiterF, 39U)) + RotL64(aCarry, 53U)) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 10U) + aOrbiterA) + RotL64(aOrbiterF, 43U));
            aWandererG = aWandererG + (((RotL64(aScatter, 29U) + aOrbiterJ) + RotL64(aOrbiterG, 30U)) + RotL64(aCarry, 23U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 57U) + aOrbiterC) + RotL64(aOrbiterI, 51U));
            aWandererF = aWandererF + ((RotL64(aScatter, 43U) + RotL64(aOrbiterJ, 23U)) + aOrbiterI);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterH, 5U)) + aOrbiterI);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 21U) + RotL64(aOrbiterG, 60U)) + aOrbiterB);
            aWandererI = aWandererI ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterI, 11U)) + aOrbiterG);
            aWandererA = aWandererA + (((RotL64(aIngress, 14U) + RotL64(aOrbiterA, 19U)) + aOrbiterD) + aPhaseBWandererUpdateSaltB[((aIndex + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 14U) ^ aWandererJ);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 11U));
            aCarry = aCarry + (RotL64(aWandererA, 5U) ^ aWandererE);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 47U));
            aCarry = aCarry + RotL64(aWandererG, 27U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 11389U)) & S_BLOCK1], 21U) ^ RotL64(aKeyRowReadA[((aIndex + 13380U)) & W_KEY1], 13U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 11015U)) & W_KEY1], 57U) ^ RotL64(mSource[((aIndex + 12322U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 11588U)) & S_BLOCK1], 46U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 12102U)) & S_BLOCK1], 38U) ^ RotL64(aInvestLaneA[((aIndex + 13377U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 13U) + RotL64(aPrevious, 29U)) + (RotL64(aCross, 56U) ^ RotL64(aIngress, 41U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = ((aWandererJ + RotL64(aIngress, 18U)) + 15316464782468770057U) + aPhaseBOrbiterAssignSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterJ = ((aWandererI + RotL64(aPrevious, 3U)) + RotL64(aCarry, 57U)) + 6642872057476351588U;
            aOrbiterH = (aWandererH + RotL64(aScatter, 23U)) + 660732654689529192U;
            aOrbiterE = (aWandererK + RotL64(aCross, 43U)) + 7235418086884000655U;
            aOrbiterF = (aWandererA + RotL64(aPrevious, 29U)) + 14784518476694580493U;
            aOrbiterA = (((aWandererF + RotL64(aScatter, 51U)) + RotL64(aCarry, 43U)) + 12222433977933449375U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterB = (aWandererG + RotL64(aIngress, 35U)) + 8573001207708329927U;
            aOrbiterC = ((aWandererD + RotL64(aCross, 58U)) + RotL64(aCarry, 35U)) + 16035256260815013172U;
            aOrbiterI = (aWandererE + RotL64(aIngress, 47U)) + 15767726974121910203U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 17712217935322939971U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 13488963456923357159U;
            aOrbiterH = RotL64((aOrbiterH * 16785285630840310405U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 10222949131965611079U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 1495561412321657209U;
            aOrbiterD = RotL64((aOrbiterD * 9706305581868526265U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 16156530750584361434U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 7773792489045606309U;
            aOrbiterB = RotL64((aOrbiterB * 10730624207715601393U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 11544578291333360613U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 3665587867634242865U;
            aOrbiterJ = RotL64((aOrbiterJ * 4840528190844842595U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 15248434984650998090U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 15487979645426567581U;
            aOrbiterA = RotL64((aOrbiterA * 10868107809356766183U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 6972347795052712690U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 16074994810010431338U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 1262655238856775853U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 16851139687900415292U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 14630026837021552812U;
            aOrbiterE = RotL64((aOrbiterE * 9577900853521254603U), 27U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 14236330619137368169U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 17778707026111136216U;
            aOrbiterC = RotL64((aOrbiterC * 16239561893843454747U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 9390961969105999083U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 1174881758316573228U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6602061268277529311U), 43U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterA, 13U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 39U));
            aIngress = aIngress + (RotL64(aOrbiterE, 46U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterC, 35U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterI, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aCross, 51U) + aOrbiterC) + RotL64(aOrbiterA, 18U));
            aWandererH = aWandererH + (((RotL64(aScatter, 37U) + aOrbiterI) + RotL64(aOrbiterE, 43U)) + RotL64(aCarry, 57U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 42U) + aOrbiterE) + RotL64(aOrbiterH, 11U)) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aPrevious, 13U) + RotL64(aOrbiterB, 23U)) + aOrbiterA);
            aWandererF = aWandererF ^ ((RotL64(aCross, 23U) + aOrbiterD) + RotL64(aOrbiterH, 27U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 19U) + aOrbiterI) + RotL64(aOrbiterB, 58U)) + RotL64(aCarry, 43U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterJ, 37U)) + aOrbiterF);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 60U) + RotL64(aOrbiterD, 47U)) + aOrbiterJ) + aPhaseBWandererUpdateSaltB[((aIndex + 3U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterE, 51U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererI, 23U) ^ aWandererD);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 41U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 53U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 35U));
            aCarry = aCarry + RotL64(aWandererA, 44U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 14842U)) & S_BLOCK1], 13U) ^ RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 15903U)) & S_BLOCK1], 54U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 14308U)) & W_KEY1], 58U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 16029U)) & W_KEY1], 21U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 14811U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 16324U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 14640U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 43U) ^ RotL64(aCarry, 6U)) + (RotL64(aIngress, 23U) ^ RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterE = (aWandererI + RotL64(aCross, 51U)) + 6916817163240024692U;
            aOrbiterD = (aWandererB + RotL64(aPrevious, 13U)) + 14554930751292077817U;
            aOrbiterC = ((aWandererA + RotL64(aIngress, 47U)) + 1098305064484336101U) + aPhaseBOrbiterAssignSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = (((aWandererF + RotL64(aScatter, 58U)) + RotL64(aCarry, 3U)) + 12192821172420471527U) + aPhaseBOrbiterAssignSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterH = ((aWandererH + RotL64(aPrevious, 41U)) + RotL64(aCarry, 39U)) + 2435134991707318845U;
            aOrbiterI = ((aWandererE + RotL64(aIngress, 27U)) + RotL64(aCarry, 13U)) + 1896745368738512624U;
            aOrbiterF = (aWandererJ + RotL64(aScatter, 35U)) + 1114996424222923873U;
            aOrbiterB = (aWandererG + RotL64(aCross, 20U)) + 9839135798371512656U;
            aOrbiterK = (aWandererD + RotL64(aIngress, 5U)) + 8037967239603177043U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 15185468738487237432U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 4912098316394854543U;
            aOrbiterC = RotL64((aOrbiterC * 3072785550384399929U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 13142688607850380888U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 4507379759608945839U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2989332387754215967U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 7299006009652289342U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 5390655277207053627U;
            aOrbiterF = RotL64((aOrbiterF * 10973744708856143715U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 6744737023577785725U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 15539737698867067285U;
            aOrbiterG = RotL64((aOrbiterG * 4686092035261336911U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 13329866734681377952U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 13284937458969166257U;
            aOrbiterB = RotL64((aOrbiterB * 3965985432462699445U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 8695002088915702168U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 3858059421620839286U;
            aOrbiterE = RotL64((aOrbiterE * 9559783727301092937U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 6609163873243179836U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 9416165620556710540U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 240385043740268229U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 1578449067529000433U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 14309000104419489303U;
            aOrbiterK = RotL64((aOrbiterK * 7599078306153684729U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 15785180680737461320U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 10099222679918382021U;
            aOrbiterD = RotL64((aOrbiterD * 2012232597046182581U), 57U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterB, 57U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 11U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 38U));
            aIngress = aIngress + (RotL64(aOrbiterD, 27U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterH, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterE, 18U)) + aOrbiterB) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aIngress, 30U) + RotL64(aOrbiterE, 13U)) + aOrbiterH);
            aWandererF = aWandererF ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterI, 41U)) + aOrbiterF);
            aWandererH = aWandererH + ((RotL64(aPrevious, 53U) + aOrbiterH) + RotL64(aOrbiterB, 29U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 19U) + aOrbiterB) + RotL64(aOrbiterF, 3U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterK, 23U)) + aOrbiterG) + RotL64(aCarry, 19U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 58U) + RotL64(aOrbiterD, 51U)) + aOrbiterB);
            aWandererD = aWandererD + ((((RotL64(aIngress, 11U) + RotL64(aOrbiterK, 56U)) + aOrbiterC) + RotL64(aCarry, 27U)) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterG, 35U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererD, 60U) ^ aWandererH);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 11U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 57U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 21U));
            aCarry = aCarry + RotL64(aWandererA, 35U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 17353U)) & S_BLOCK1], 27U) ^ RotL64(aKeyRowReadA[((aIndex + 18622U)) & W_KEY1], 13U));
            aIngress ^= (RotL64(mSource[((aIndex + 16828U)) & S_BLOCK1], 42U) ^ RotL64(aWorkLaneA[((aIndex + 16795U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 17315U)) & W_KEY1], 36U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 18641U)) & S_BLOCK1], 53U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 17030U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 23U) ^ RotL64(aCarry, 57U)) + (RotL64(aPrevious, 38U) ^ RotL64(aCross, 11U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterH = ((aWandererB + RotL64(aIngress, 23U)) + RotL64(aCarry, 21U)) + 15726877954695761686U;
            aOrbiterC = ((aWandererA + RotL64(aPrevious, 46U)) + 14187652171881943587U) + aPhaseCOrbiterAssignSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterB = (aWandererE + RotL64(aCross, 19U)) + 8420423151313882782U;
            aOrbiterE = (((aWandererG + RotL64(aScatter, 41U)) + RotL64(aCarry, 11U)) + 14942322692433259283U) + aPhaseCOrbiterAssignSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterF = (aWandererJ + RotL64(aIngress, 29U)) + 7272331475919796255U;
            aOrbiterD = ((aWandererH + RotL64(aCross, 11U)) + RotL64(aCarry, 3U)) + 154504365041805840U;
            aOrbiterA = (aWandererF + RotL64(aScatter, 34U)) + 17475491222554948786U;
            aOrbiterJ = (aWandererC + RotL64(aPrevious, 53U)) + 5759181483165339605U;
            aOrbiterG = (aWandererD + RotL64(aScatter, 5U)) + 5993060214499322845U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 10901786237875941844U) + aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 17135786595614068473U;
            aOrbiterB = RotL64((aOrbiterB * 15923538730142047043U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 5208202073886811165U) + aPhaseCOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 6821452921018900631U;
            aOrbiterC = RotL64((aOrbiterC * 13119330055184115669U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 13348064837402206969U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 8967943922403445136U;
            aOrbiterA = RotL64((aOrbiterA * 300168481725373093U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 8130283784171430891U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 6351113882502502876U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 15960622823993072903U), 39U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 6894708729226455769U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 12065058511247133944U;
            aOrbiterH = RotL64((aOrbiterH * 5432601727436935831U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 17138279326229372741U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 12987698199066890628U;
            aOrbiterG = RotL64((aOrbiterG * 12665716655177320977U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 13688833537574196675U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 4211971980434000618U;
            aOrbiterD = RotL64((aOrbiterD * 1374411763361518851U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 10376917117582537592U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 4807742522197923516U;
            aOrbiterE = RotL64((aOrbiterE * 15257251453302090961U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 18038296468177121243U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 6879666349379745258U;
            aOrbiterF = RotL64((aOrbiterF * 15819475269715810555U), 5U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterC, 39U);
            aIngress = aIngress + (RotL64(aOrbiterH, 34U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 19U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 3U));
            aIngress = aIngress + RotL64(aOrbiterA, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aScatter, 3U) + aOrbiterA) + RotL64(aOrbiterG, 12U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 37U) + RotL64(aOrbiterD, 47U)) + aOrbiterA) + aPhaseCWandererUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 47U) + aOrbiterG) + RotL64(aOrbiterE, 39U));
            aWandererE = aWandererE + (((RotL64(aCross, 24U) + aOrbiterF) + RotL64(aOrbiterE, 3U)) + RotL64(aCarry, 35U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 11U) + aOrbiterB) + RotL64(aOrbiterA, 27U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterF, 23U)) + aOrbiterC) + RotL64(aCarry, 53U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 43U) + aOrbiterG) + RotL64(aOrbiterH, 58U)) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aCross, 57U) + RotL64(aOrbiterF, 35U)) + aOrbiterD);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 18U) + RotL64(aOrbiterJ, 53U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererA, 29U) ^ aWandererJ);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 18U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 47U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 57U));
            aCarry = aCarry + RotL64(aWandererC, 37U);
            aCarry = aCarry + RotL64(aIngress, 10U);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 19215U)) & S_BLOCK1], 28U) ^ RotL64(mSource[((aIndex + 20677U)) & S_BLOCK1], 39U));
            aIngress ^= (RotL64(aFireLaneA[((aIndex + 21741U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneA[((aIndex + 21220U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 19815U)) & W_KEY1], 19U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 21242U)) & W_KEY1], 5U));
            aCross ^= (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 20912U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneB[((aIndex + 19882U)) & S_BLOCK1], 34U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aIngress, 44U)) ^ (RotL64(aCross, 57U) + RotL64(aPrevious, 21U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterC = ((aWandererC + RotL64(aIngress, 35U)) + RotL64(aCarry, 47U)) + 9435962834163239322U;
            aOrbiterI = ((aWandererA + RotL64(aPrevious, 3U)) + RotL64(aCarry, 19U)) + 10524704356081318973U;
            aOrbiterE = ((aWandererF + RotL64(aCross, 10U)) + 7403401305665208680U) + aPhaseCOrbiterAssignSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterJ = ((aWandererE + RotL64(aScatter, 23U)) + RotL64(aCarry, 5U)) + 7525414805023556493U;
            aOrbiterA = (aWandererI + RotL64(aCross, 29U)) + 1116686470029070951U;
            aOrbiterK = ((aWandererB + RotL64(aScatter, 51U)) + 13257612299137802420U) + aPhaseCOrbiterAssignSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterB = (aWandererD + RotL64(aPrevious, 60U)) + 9181543003986598283U;
            aOrbiterG = (aWandererJ + RotL64(aIngress, 39U)) + 9739384852307501107U;
            aOrbiterH = (aWandererG + RotL64(aCross, 19U)) + 11308402900229016057U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 14935167593705272337U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 7171824007631943535U;
            aOrbiterE = RotL64((aOrbiterE * 4839974427616194289U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 8068411284829563567U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 12350207458513447578U;
            aOrbiterA = RotL64((aOrbiterA * 813973258659041895U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 17039236343991574134U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 18291683592714999632U;
            aOrbiterB = RotL64((aOrbiterB * 7771718817924840713U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 6239616841884430968U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 10604527977569876774U;
            aOrbiterJ = RotL64((aOrbiterJ * 6972820410084939637U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 1707724300671717658U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 3802268808625297647U;
            aOrbiterG = RotL64((aOrbiterG * 11296811630387191563U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 9423064323799920219U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 242153923313096551U;
            aOrbiterI = RotL64((aOrbiterI * 12117679073775630197U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 945801070951928277U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 13094814302414492064U) ^ aPhaseCOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14638176479878969775U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 7572219725951040117U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 16494986983782503428U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2739189408707408171U), 53U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 10949497978229234856U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 11219643352002119905U;
            aOrbiterK = RotL64((aOrbiterK * 16900635614259262873U), 5U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterK, 5U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 21U));
            aIngress = aIngress + (RotL64(aOrbiterC, 38U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 47U));
            aIngress = aIngress + RotL64(aOrbiterB, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aCross, 47U) + aOrbiterB) + RotL64(aOrbiterI, 5U)) + RotL64(aCarry, 21U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 60U) + RotL64(aOrbiterJ, 53U)) + aOrbiterG);
            aWandererC = aWandererC + (((RotL64(aScatter, 51U) + RotL64(aOrbiterI, 39U)) + aOrbiterJ) + aPhaseCWandererUpdateSaltF[((aIndex + 18U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterE, 22U)) + aOrbiterB);
            aWandererG = aWandererG + ((RotL64(aScatter, 39U) + aOrbiterA) + RotL64(aOrbiterE, 57U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 13U) + aOrbiterK) + RotL64(aOrbiterI, 13U));
            aWandererF = aWandererF + (((RotL64(aIngress, 4U) + RotL64(aOrbiterI, 47U)) + aOrbiterH) + aPhaseCWandererUpdateSaltA[((aIndex + 28U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterC, 27U)) + aOrbiterH);
            aWandererE = aWandererE + (((RotL64(aPrevious, 27U) + aOrbiterE) + RotL64(aOrbiterJ, 18U)) + RotL64(aCarry, 3U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 47U));
            aCarry = aCarry + (RotL64(aWandererA, 26U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererD, 5U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererJ, 43U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererC, 51U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 21897U)) & S_BLOCK1], 13U) ^ RotL64(aKeyRowReadA[((aIndex + 24457U)) & W_KEY1], 5U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 24040U)) & W_KEY1], 52U) ^ RotL64(aFireLaneC[((aIndex + 23919U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 23263U)) & S_BLOCK1], 12U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 23865U)) & S_BLOCK1], 57U));
            aCross ^= (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 22976U)) & S_BLOCK1], 3U) ^ RotL64(aInvestLaneB[((aIndex + 23626U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 28U) + RotL64(aPrevious, 5U)) + (RotL64(aIngress, 57U) ^ RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterE = (aWandererD + RotL64(aScatter, 19U)) + 16183871922837164759U;
            aOrbiterB = ((aWandererC + RotL64(aCross, 36U)) + RotL64(aCarry, 23U)) + 7002058258090219055U;
            aOrbiterK = (aWandererE + RotL64(aIngress, 51U)) + 5650868611888303705U;
            aOrbiterI = ((aWandererF + RotL64(aPrevious, 29U)) + 11899839660943876690U) + aPhaseCOrbiterAssignSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterH = (aWandererG + RotL64(aIngress, 47U)) + 15349649504488111111U;
            aOrbiterD = (aWandererI + RotL64(aScatter, 3U)) + 14060149569086744970U;
            aOrbiterJ = ((aWandererB + RotL64(aPrevious, 41U)) + RotL64(aCarry, 57U)) + 12920917574225030112U;
            aOrbiterC = ((aWandererA + RotL64(aCross, 11U)) + 2831994965175330135U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterG = ((aWandererK + RotL64(aScatter, 58U)) + RotL64(aCarry, 35U)) + 18312543585028439192U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 11657562205118394239U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 10850792819281246052U;
            aOrbiterK = RotL64((aOrbiterK * 10663100544207879337U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 17810371216216125323U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 7963413941144223128U;
            aOrbiterE = RotL64((aOrbiterE * 534217972450595401U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 5498715358793875584U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 9256727548911651373U;
            aOrbiterJ = RotL64((aOrbiterJ * 10498848323914000989U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 17246360111302191699U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 18309978718113983369U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 18267472694666221077U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 3100998994319502921U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 8129301860291235970U;
            aOrbiterC = RotL64((aOrbiterC * 17847033539279176187U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 1889641029473279114U) + aPhaseCOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 16538494307002917945U;
            aOrbiterI = RotL64((aOrbiterI * 8081488217920885783U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 5432230549146849322U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 2634437941396090817U) ^ aPhaseCOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 7612999214758935211U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 16940172599174185058U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 13151669140593952203U;
            aOrbiterD = RotL64((aOrbiterD * 16225319638131723487U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 3995064294869931681U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 913081077665768816U;
            aOrbiterH = RotL64((aOrbiterH * 9299514648768060453U), 53U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterK, 37U);
            aIngress = aIngress + (RotL64(aOrbiterC, 27U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterJ, 19U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterH, 58U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterE, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterI, 35U)) + aOrbiterH);
            aWandererG = aWandererG + ((RotL64(aPrevious, 27U) + RotL64(aOrbiterC, 23U)) + aOrbiterK);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 58U) + RotL64(aOrbiterD, 3U)) + aOrbiterE);
            aWandererI = aWandererI + ((RotL64(aCross, 19U) + aOrbiterK) + RotL64(aOrbiterB, 10U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 35U) + aOrbiterI) + RotL64(aOrbiterC, 39U)) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aPrevious, 23U) + RotL64(aOrbiterJ, 43U)) + aOrbiterB) + RotL64(aCarry, 53U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterB, 19U)) + aOrbiterI);
            aWandererA = aWandererA + (((RotL64(aCross, 4U) + RotL64(aOrbiterH, 27U)) + aOrbiterD) + RotL64(aCarry, 5U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 53U) + aOrbiterH) + RotL64(aOrbiterG, 56U)) + aPhaseCWandererUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 43U));
            aCarry = aCarry + (RotL64(aWandererK, 47U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererF);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 35U));
            aCarry = aCarry + RotL64(aWandererG, 27U);
            aCarry = aCarry + RotL64(aIngress, 60U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 24739U)) & S_BLOCK1], 21U) ^ RotL64(aKeyRowReadA[((aIndex + 25550U)) & W_KEY1], 13U));
            aIngress ^= (RotL64(aFireLaneD[((aIndex + 25390U)) & S_BLOCK1], 42U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 25906U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 25127U)) & W_KEY1], 21U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 24833U)) & S_BLOCK1], 53U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 25102U)) & S_BLOCK1], 44U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 26364U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 53U) ^ RotL64(aIngress, 23U)) + (RotL64(aCarry, 11U) ^ RotL64(aPrevious, 36U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterK = ((aWandererI + RotL64(aCross, 58U)) + RotL64(aCarry, 43U)) + 2330952702412094686U;
            aOrbiterB = ((aWandererB + RotL64(aIngress, 19U)) + RotL64(aCarry, 27U)) + 7820188225935060799U;
            aOrbiterF = ((aWandererE + RotL64(aPrevious, 11U)) + 9347644591709839145U) + aPhaseDOrbiterAssignSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = ((aWandererF + RotL64(aScatter, 47U)) + RotL64(aCarry, 5U)) + 2288624878446846870U;
            aOrbiterH = ((aWandererK + RotL64(aPrevious, 34U)) + 9358977729492824128U) + aPhaseDOrbiterAssignSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterA = (aWandererA + RotL64(aIngress, 29U)) + 1858511275052455039U;
            aOrbiterJ = (aWandererD + RotL64(aCross, 53U)) + 13715478509322292552U;
            aOrbiterG = (aWandererG + RotL64(aScatter, 43U)) + 16413396625604260455U;
            aOrbiterC = (aWandererC + RotL64(aPrevious, 39U)) + 17714322215518432705U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 16188315436202861122U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 5564445841368207813U;
            aOrbiterF = RotL64((aOrbiterF * 14125834616162835983U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 13717068949900594673U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 14143659432287313765U;
            aOrbiterK = RotL64((aOrbiterK * 17281441046722262917U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 5729546141908425670U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 4297827922736712074U;
            aOrbiterJ = RotL64((aOrbiterJ * 13631630436759768885U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 829520109395163673U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 11547160328525174295U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 4759690159673049775U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 2907177944512117206U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 11100346409065275671U;
            aOrbiterC = RotL64((aOrbiterC * 17927994356809011637U), 21U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 1344592529249949068U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 6470438516791143572U;
            aOrbiterB = RotL64((aOrbiterB * 13339390828725370475U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 5217751823741520847U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 5371275223586938039U;
            aOrbiterG = RotL64((aOrbiterG * 12318403075523724125U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 14218103150268532919U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 1367628876596800571U;
            aOrbiterH = RotL64((aOrbiterH * 13777531272321533137U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 2372041991018455610U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 9870744274890595581U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12093443117747395585U), 47U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterJ, 48U);
            aIngress = aIngress + (RotL64(aOrbiterK, 43U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterB, 3U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 57U));
            aIngress = aIngress + RotL64(aOrbiterC, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aCross, 13U) + RotL64(aOrbiterA, 19U)) + aOrbiterI);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 58U) + RotL64(aOrbiterB, 48U)) + aOrbiterJ) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aPrevious, 5U) + aOrbiterA) + RotL64(aOrbiterK, 37U)) + RotL64(aCarry, 23U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 23U) + aOrbiterC) + RotL64(aOrbiterB, 13U));
            aWandererI = aWandererI + ((RotL64(aPrevious, 53U) + aOrbiterH) + RotL64(aOrbiterB, 23U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterK, 41U)) + aOrbiterF) + aPhaseDWandererUpdateSaltD[((aIndex + 20U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aIngress, 46U) + RotL64(aOrbiterJ, 52U)) + aOrbiterG);
            aWandererG = aWandererG ^ ((RotL64(aCross, 27U) + aOrbiterJ) + RotL64(aOrbiterK, 57U));
            aWandererE = aWandererE + (((RotL64(aScatter, 19U) + aOrbiterG) + RotL64(aOrbiterF, 29U)) + RotL64(aCarry, 11U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 47U) ^ aWandererD);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 5U));
            aCarry = aCarry + (RotL64(aWandererG, 37U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererB, 30U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererC, 11U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 28810U)) & S_BLOCK1], 28U) ^ RotL64(aFireLaneD[((aIndex + 28862U)) & S_BLOCK1], 13U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 27833U)) & W_KEY1], 57U) ^ RotL64(aFireLaneC[((aIndex + 28445U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 28159U)) & W_KEY1], 47U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 29120U)) & S_BLOCK1], 34U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27635U)) & S_BLOCK1], 11U) ^ RotL64(aFireLaneB[((aIndex + 29113U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 21U) ^ RotL64(aPrevious, 37U)) + (RotL64(aIngress, 3U) + RotL64(aCarry, 54U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterF = ((aWandererI + RotL64(aIngress, 5U)) + 4980738603982643969U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = (aWandererF + RotL64(aCross, 60U)) + 17660278413018470020U;
            aOrbiterB = (aWandererK + RotL64(aPrevious, 11U)) + 17598114429859543466U;
            aOrbiterD = (((aWandererC + RotL64(aScatter, 35U)) + RotL64(aCarry, 41U)) + 10993929335279994739U) + aPhaseDOrbiterAssignSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterE = (aWandererA + RotL64(aPrevious, 19U)) + 17967203122976322481U;
            aOrbiterG = (aWandererB + RotL64(aCross, 47U)) + 1872290205549034384U;
            aOrbiterH = ((aWandererJ + RotL64(aIngress, 40U)) + RotL64(aCarry, 27U)) + 16607778671782810797U;
            aOrbiterI = (aWandererD + RotL64(aScatter, 27U)) + 4895226930754394376U;
            aOrbiterC = ((aWandererH + RotL64(aPrevious, 23U)) + RotL64(aCarry, 11U)) + 14960359005982301383U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 9921642352377700630U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 893281964367208693U;
            aOrbiterB = RotL64((aOrbiterB * 2345509157333444217U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 8232519988397858732U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 4433022122758913407U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 834240393225479419U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 12689609831247168353U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 404535388957472176U;
            aOrbiterH = RotL64((aOrbiterH * 14534020545479806593U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 3349108201964013155U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 4386449511297371730U;
            aOrbiterI = RotL64((aOrbiterI * 9596273264321140229U), 27U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 14314587717949070586U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 10923886625271054985U;
            aOrbiterA = RotL64((aOrbiterA * 7838969002623486809U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 17634909585329833520U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 2021301459918350372U;
            aOrbiterF = RotL64((aOrbiterF * 1388242915918642741U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 5219599112498224367U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 10641339455385046206U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 1022283727595400719U), 39U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 5003342156562330058U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 10951027475628404336U;
            aOrbiterD = RotL64((aOrbiterD * 17836928292555158461U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 13040991872592235460U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 11149099984302782267U;
            aOrbiterC = RotL64((aOrbiterC * 4248667283139686251U), 3U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterA, 51U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 10U));
            aIngress = aIngress + (RotL64(aOrbiterB, 57U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterI, 13U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterE, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterI, 23U)) + aOrbiterC) + aPhaseDWandererUpdateSaltC[((aIndex + 29U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aIngress, 27U) + RotL64(aOrbiterD, 35U)) + aOrbiterE);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 18U) + aOrbiterG) + RotL64(aOrbiterH, 28U));
            aWandererH = aWandererH + ((((RotL64(aPrevious, 57U) + RotL64(aOrbiterD, 53U)) + aOrbiterA) + RotL64(aCarry, 51U)) + aPhaseDWandererUpdateSaltA[((aIndex + 19U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterF, 19U)) + aOrbiterD);
            aWandererB = aWandererB + ((RotL64(aPrevious, 41U) + RotL64(aOrbiterB, 43U)) + aOrbiterH);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 34U) + aOrbiterA) + RotL64(aOrbiterF, 12U));
            aWandererK = aWandererK + (((RotL64(aIngress, 11U) + aOrbiterE) + RotL64(aOrbiterC, 39U)) + RotL64(aCarry, 35U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 23U) + aOrbiterI) + RotL64(aOrbiterB, 5U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 24U));
            aCarry = aCarry + (RotL64(aWandererB, 13U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererH, 57U) ^ aWandererA);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 19U));
            aCarry = aCarry + RotL64(aWandererF, 53U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 32717U)) & S_BLOCK1], 10U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 32612U)) & W_KEY1], 19U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 32463U)) & S_BLOCK1], 10U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30395U)) & S_BLOCK1], 27U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30518U)) & S_BLOCK1], 51U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 31866U)) & W_KEY1], 41U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 21U) + RotL64(aIngress, 3U)) ^ (RotL64(aPrevious, 37U) + RotL64(aCarry, 54U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterJ = ((aWandererG + RotL64(aPrevious, 29U)) + RotL64(aCarry, 39U)) + 1364174714924216027U;
            aOrbiterA = (aWandererE + RotL64(aScatter, 23U)) + 13561796874229506613U;
            aOrbiterB = (aWandererB + RotL64(aIngress, 37U)) + 11845572344206238305U;
            aOrbiterI = ((aWandererF + RotL64(aCross, 57U)) + RotL64(aCarry, 3U)) + 15762708240326773763U;
            aOrbiterF = ((aWandererI + RotL64(aPrevious, 18U)) + 1157119665207900473U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterD = (aWandererJ + RotL64(aCross, 47U)) + 6823546624372055260U;
            aOrbiterC = ((aWandererD + RotL64(aScatter, 11U)) + RotL64(aCarry, 21U)) + 14465564210523945121U;
            aOrbiterE = (aWandererH + RotL64(aIngress, 41U)) + 10667464548080807531U;
            aOrbiterK = ((aWandererC + RotL64(aPrevious, 4U)) + 13445737493224316575U) + aPhaseDOrbiterAssignSaltB[((aIndex + 22U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 3009837893785957665U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 2886920524111083752U;
            aOrbiterB = RotL64((aOrbiterB * 15308180928967762543U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 10886177449328249656U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 15067759884678100433U;
            aOrbiterF = RotL64((aOrbiterF * 5724566815989860041U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 18307930462682331536U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 8791864377579255801U;
            aOrbiterA = RotL64((aOrbiterA * 9265158882471421767U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 805797468642992351U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 5743305867058244964U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 16263000753351131717U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 17102025528234481273U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 1841579177327486899U;
            aOrbiterD = RotL64((aOrbiterD * 3841603385577825265U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 2189493507896508972U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 18209567010094914374U;
            aOrbiterK = RotL64((aOrbiterK * 3737080408976852351U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 6697069234216868330U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 927471474577415372U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 10680760991009199309U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 13155854301197725408U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 1014625081915435892U;
            aOrbiterJ = RotL64((aOrbiterJ * 11592754232949990435U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 12697209921410914931U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 11555096613655648647U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4598821388864997089U), 11U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterK, 57U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 48U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 11U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 5U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterA, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aIngress, 29U) + RotL64(aOrbiterB, 40U)) + aOrbiterF) + RotL64(aCarry, 29U)) + aPhaseDWandererUpdateSaltB[((aIndex + 3U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 43U) + aOrbiterB) + RotL64(aOrbiterA, 57U)) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aCross, 39U) + RotL64(aOrbiterA, 19U)) + aOrbiterE);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 58U) + RotL64(aOrbiterJ, 3U)) + aOrbiterA);
            aWandererB = aWandererB + (((RotL64(aCross, 13U) + RotL64(aOrbiterD, 23U)) + aOrbiterA) + RotL64(aCarry, 11U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 23U) + aOrbiterF) + RotL64(aOrbiterK, 35U));
            aWandererF = aWandererF + ((RotL64(aIngress, 5U) + RotL64(aOrbiterI, 47U)) + aOrbiterJ);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 18U) + RotL64(aOrbiterC, 10U)) + aOrbiterD);
            aWandererE = aWandererE + ((RotL64(aScatter, 35U) + aOrbiterI) + RotL64(aOrbiterF, 51U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 54U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 35U));
            aCarry = aCarry + (RotL64(aWandererD, 23U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererC, 57U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererB, 38U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 1196U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneB[((aIndex + 22U)) & S_BLOCK1], 28U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 5426U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 3434U)) & S_BLOCK1], 40U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 254U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 52U) ^ RotL64(aPrevious, 37U)) + (RotL64(aCross, 11U) ^ RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterG = (((aWandererH + RotL64(aPrevious, 13U)) + RotL64(aCarry, 35U)) + 1457104756581596530U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterE = (aWandererE + RotL64(aScatter, 43U)) + 6127240317844622874U;
            aOrbiterI = (aWandererF + RotL64(aIngress, 29U)) + 16492290056044189421U;
            aOrbiterA = (((aWandererD + RotL64(aCross, 21U)) + RotL64(aCarry, 47U)) + 10963676850938416468U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterC = ((aWandererK + RotL64(aScatter, 3U)) + RotL64(aCarry, 19U)) + 4872917367399752405U;
            aOrbiterB = (aWandererI + RotL64(aPrevious, 35U)) + 15218882377875616148U;
            aOrbiterK = (aWandererC + RotL64(aIngress, 50U)) + 5934166612122118251U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 14215280930872003003U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 11428034799044600979U;
            aOrbiterI = RotL64((aOrbiterI * 12162528943733976177U), 37U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 5453003654321728726U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 14273775120265649389U;
            aOrbiterE = RotL64((aOrbiterE * 5139018128323795309U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 328723770018440271U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 13032190719588211088U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 13363368478932798315U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 2386881543033598494U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 1649501123340887116U;
            aOrbiterA = RotL64((aOrbiterA * 11148976582360499033U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 16462401546754210583U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 1510579201823042227U;
            aOrbiterB = RotL64((aOrbiterB * 16287912400104043275U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 6889066000014251983U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 11324594596597724357U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 15344987814648586023U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 12237796033168436537U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 17306069670330000343U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 3167451351403385259U), 51U);
            //
            aIngress = RotL64(aOrbiterE, 51U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterC, 21U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 37U));
            aIngress = aIngress + RotL64(aOrbiterK, 44U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aScatter, 29U) + aOrbiterG) + RotL64(aOrbiterE, 5U)) + RotL64(aCarry, 43U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 35U) + RotL64(aOrbiterK, 46U)) + aOrbiterI) + aPhaseEWandererUpdateSaltC[((aIndex + 22U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aPrevious, 51U) + aOrbiterB) + RotL64(aOrbiterI, 23U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 13U) + aOrbiterC) + RotL64(aOrbiterK, 13U));
            aWandererC = aWandererC + ((RotL64(aIngress, 5U) + RotL64(aOrbiterA, 39U)) + aOrbiterC);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 23U) + aOrbiterI) + RotL64(aOrbiterG, 29U));
            aWandererK = aWandererK + (((RotL64(aCross, 42U) + aOrbiterE) + RotL64(aOrbiterB, 53U)) + RotL64(aCarry, 57U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 6U));
            aCarry = aCarry + (RotL64(aWandererD, 51U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererK, 41U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererI, 29U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = (RotL64(aInvestLaneC[((aIndex + 7187U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneC[((aIndex + 9995U)) & S_BLOCK1], 60U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 8544U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 8576U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneD[((aIndex + 7155U)) & S_BLOCK1], 60U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 29U) ^ RotL64(aPrevious, 54U)) ^ (RotL64(aCarry, 13U) + RotL64(aIngress, 41U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterA = ((aWandererK + RotL64(aCross, 3U)) + 785861751704720606U) + aPhaseEOrbiterAssignSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = ((aWandererF + RotL64(aScatter, 13U)) + RotL64(aCarry, 47U)) + 15968088718435606299U;
            aOrbiterH = (aWandererI + RotL64(aPrevious, 41U)) + 1393976526590347151U;
            aOrbiterK = ((aWandererG + RotL64(aIngress, 20U)) + RotL64(aCarry, 35U)) + 17240750947292745884U;
            aOrbiterE = ((aWandererE + RotL64(aPrevious, 35U)) + RotL64(aCarry, 13U)) + 4921576136163183137U;
            aOrbiterJ = (aWandererC + RotL64(aIngress, 29U)) + 3334047873553153032U;
            aOrbiterG = ((aWandererJ + RotL64(aCross, 57U)) + 15086509978458408698U) + aPhaseEOrbiterAssignSaltD[((aIndex + 14U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 892391205397581998U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 2965686403183767521U;
            aOrbiterH = RotL64((aOrbiterH * 709160942482770225U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 14632215393655706170U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 15740589515342377322U;
            aOrbiterE = RotL64((aOrbiterE * 15677716942904794913U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 11131164813943086445U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 6988080581278900960U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 6412189142344044255U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 16021254613117657178U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 6183615599897921154U;
            aOrbiterK = RotL64((aOrbiterK * 9976411093264211033U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 12533992547026652747U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 3104325358982904219U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14977348108778147265U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 3878525937957474644U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 2120435259884368445U;
            aOrbiterA = RotL64((aOrbiterA * 15964718652193073177U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 14928658302694194856U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 9121310461310309348U;
            aOrbiterJ = RotL64((aOrbiterJ * 17304439784647477491U), 51U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterE, 57U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 5U));
            aIngress = aIngress + (RotL64(aOrbiterA, 47U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterH, 14U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aCross, 3U) + aOrbiterG) + RotL64(aOrbiterC, 47U)) + RotL64(aCarry, 23U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 29U) + aOrbiterH) + RotL64(aOrbiterJ, 5U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 37U) + aOrbiterE) + RotL64(aOrbiterC, 14U)) + aPhaseEWandererUpdateSaltA[((aIndex + 17U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 21U) + aOrbiterG) + RotL64(aOrbiterH, 27U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aScatter, 12U) + RotL64(aOrbiterH, 21U)) + aOrbiterK);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterE, 41U)) + aOrbiterK);
            aWandererK = aWandererK + (((RotL64(aPrevious, 51U) + aOrbiterJ) + RotL64(aOrbiterA, 35U)) + RotL64(aCarry, 39U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 40U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 5U));
            aCarry = aCarry + (RotL64(aWandererI, 57U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererF, 27U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aInvestLaneD[((aIndex + 15818U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneD[((aIndex + 12987U)) & S_BLOCK1], 41U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 15334U)) & S_BLOCK1], 54U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 12424U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 13518U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aExpandLaneA[((aIndex + 14769U)) & S_BLOCK1], 40U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 40U) ^ RotL64(aPrevious, 53U)) ^ (RotL64(aIngress, 3U) + RotL64(aCross, 21U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterE = ((aWandererC + RotL64(aScatter, 5U)) + RotL64(aCarry, 35U)) + 17936518874386450467U;
            aOrbiterK = (((aWandererK + RotL64(aIngress, 19U)) + RotL64(aCarry, 5U)) + 13722737841589910344U) + aPhaseEOrbiterAssignSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterJ = (aWandererA + RotL64(aCross, 35U)) + 11774969167948715796U;
            aOrbiterI = (aWandererH + RotL64(aPrevious, 51U)) + 3640101505680493777U;
            aOrbiterB = (aWandererE + RotL64(aScatter, 27U)) + 1369495382725650822U;
            aOrbiterH = (aWandererI + RotL64(aCross, 44U)) + 11827310354654653345U;
            aOrbiterF = (((aWandererD + RotL64(aPrevious, 57U)) + RotL64(aCarry, 23U)) + 186037671377175394U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 11428829344234627340U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 2275016369870029068U;
            aOrbiterJ = RotL64((aOrbiterJ * 14936799202145280833U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 15471646673734798328U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 12172082573115640145U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9629417882787847753U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 6626736341348283154U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 12220614992483863623U;
            aOrbiterB = RotL64((aOrbiterB * 8137086205714097487U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 13157102324253760215U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 4143587482368093601U;
            aOrbiterK = RotL64((aOrbiterK * 5060677690991506895U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 11007575246013796426U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 11721585930088637162U;
            aOrbiterI = RotL64((aOrbiterI * 15009627907125738519U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 5720789204450196217U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 3094696226821431648U;
            aOrbiterE = RotL64((aOrbiterE * 4412033981712165541U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 14675830108100986773U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 9444071495289719645U;
            aOrbiterF = RotL64((aOrbiterF * 10983136361953366557U), 19U);
            //
            aIngress = RotL64(aOrbiterJ, 29U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 21U));
            aIngress = aIngress + (RotL64(aOrbiterK, 11U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterF, 44U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aIngress, 35U) + RotL64(aOrbiterH, 57U)) + aOrbiterI) + aPhaseEWandererUpdateSaltB[((aIndex + 7U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterJ, 20U)) + aOrbiterK);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 41U) + aOrbiterH) + RotL64(aOrbiterB, 35U)) + RotL64(aCarry, 57U)) + aPhaseEWandererUpdateSaltE[((aIndex + 10U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 60U) + RotL64(aOrbiterJ, 27U)) + aOrbiterE);
            aWandererK = aWandererK + ((RotL64(aCross, 53U) + aOrbiterB) + RotL64(aOrbiterI, 3U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterJ, 11U)) + aOrbiterB);
            aWandererA = aWandererA + (((RotL64(aIngress, 27U) + aOrbiterK) + RotL64(aOrbiterF, 41U)) + RotL64(aCarry, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 6U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererA, 23U) ^ aWandererD);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 47U));
            aCarry = aCarry + RotL64(aWandererK, 19U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 17054U)) & S_BLOCK1], 5U) ^ RotL64(aInvestLaneC[((aIndex + 17996U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 21434U)) & S_BLOCK1], 20U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 18169U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 18251U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 16580U)) & S_BLOCK1], 42U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 27U) ^ RotL64(aCarry, 56U)) + (RotL64(aIngress, 5U) ^ RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterK = ((aWandererK + RotL64(aPrevious, 29U)) + RotL64(aCarry, 51U)) + 10038936806177516123U;
            aOrbiterC = (aWandererE + RotL64(aCross, 3U)) + 1773168435195292638U;
            aOrbiterH = ((aWandererH + RotL64(aScatter, 53U)) + 10655711161526628072U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterG = (aWandererI + RotL64(aIngress, 13U)) + 14422295664639740437U;
            aOrbiterF = ((aWandererG + RotL64(aScatter, 47U)) + RotL64(aCarry, 39U)) + 4125228715513159576U;
            aOrbiterE = (aWandererC + RotL64(aIngress, 35U)) + 3670449653158650845U;
            aOrbiterI = (((aWandererJ + RotL64(aCross, 22U)) + RotL64(aCarry, 13U)) + 17553727567180813057U) + aPhaseEOrbiterAssignSaltC[((aIndex + 29U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 5111401772713882743U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 7688573124662314413U;
            aOrbiterH = RotL64((aOrbiterH * 10846442063022821393U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 9438375825507814395U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 14177477039902118886U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 6467406626985022537U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 16329942595859623928U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 3990536794006836672U;
            aOrbiterG = RotL64((aOrbiterG * 579024714339065373U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 5072881436583180756U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 16789727877867289997U;
            aOrbiterE = RotL64((aOrbiterE * 8766246302636197905U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 17313956922306689438U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 11530878396329822041U;
            aOrbiterC = RotL64((aOrbiterC * 11356860047841383129U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 3612616532321160196U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 4172189825359187763U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 12938945495299393177U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 8677279703778052804U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 1912172980909479362U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 10053289257955474143U), 5U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterC, 13U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 57U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 35U));
            aIngress = aIngress + RotL64(aOrbiterK, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aScatter, 5U) + RotL64(aOrbiterK, 43U)) + aOrbiterG) + RotL64(aCarry, 43U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 41U) + aOrbiterH) + RotL64(aOrbiterE, 60U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 12U) + aOrbiterI) + RotL64(aOrbiterF, 3U)) + RotL64(aCarry, 23U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterC, 19U)) + aOrbiterH);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 21U) + aOrbiterK) + RotL64(aOrbiterH, 13U)) + aPhaseEWandererUpdateSaltD[((aIndex + 3U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterC, 35U)) + aOrbiterF);
            aWandererK = aWandererK + (((RotL64(aIngress, 35U) + aOrbiterF) + RotL64(aOrbiterG, 51U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 57U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererH, 43U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererE, 30U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererC, 53U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 25657U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneA[((aIndex + 24989U)) & S_BLOCK1], 60U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 23771U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 22038U)) & S_BLOCK1], 5U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 21978U)) & S_BLOCK1], 53U));
            aCross ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 26018U)) & S_BLOCK1], 14U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 19U) ^ RotL64(aCross, 5U)) + (RotL64(aCarry, 35U) + RotL64(aIngress, 50U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterB = ((aWandererK + RotL64(aPrevious, 47U)) + RotL64(aCarry, 5U)) + 9888431329297626900U;
            aOrbiterK = (aWandererI + RotL64(aCross, 29U)) + 2937735167534624403U;
            aOrbiterC = (aWandererC + RotL64(aScatter, 35U)) + 17626022970343789617U;
            aOrbiterJ = ((aWandererB + RotL64(aIngress, 56U)) + RotL64(aCarry, 19U)) + 5665660859333693743U;
            aOrbiterG = ((aWandererJ + RotL64(aScatter, 19U)) + 1060537034632076669U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterF = ((aWandererG + RotL64(aCross, 41U)) + RotL64(aCarry, 51U)) + 743777763907175800U;
            aOrbiterD = ((aWandererE + RotL64(aIngress, 13U)) + 5744905970181808845U) + aPhaseEOrbiterAssignSaltD[((aIndex + 16U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 3545351394494002180U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 4877547088414106007U;
            aOrbiterC = RotL64((aOrbiterC * 5416792889338547109U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 11669378338379598445U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 2961072441706158212U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2677988507090705371U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 13984945589234919765U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 1433097875470903205U;
            aOrbiterB = RotL64((aOrbiterB * 451996840039906781U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 716415411025451152U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 8542286150858297810U;
            aOrbiterK = RotL64((aOrbiterK * 9139015340823332449U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 12932391786479661299U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 14005503313299177013U;
            aOrbiterD = RotL64((aOrbiterD * 802663466907819743U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 9382792812676318046U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 5138554251079724724U;
            aOrbiterJ = RotL64((aOrbiterJ * 6386016499265056247U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 8522380066269546172U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 11825536408101906458U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 17042837108792016849U), 35U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterG, 27U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 57U));
            aIngress = aIngress + (RotL64(aOrbiterB, 48U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterJ, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aCross, 41U) + aOrbiterG) + RotL64(aOrbiterF, 47U)) + RotL64(aCarry, 3U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 53U) + aOrbiterD) + RotL64(aOrbiterK, 39U));
            aWandererB = aWandererB + ((RotL64(aIngress, 29U) + aOrbiterG) + RotL64(aOrbiterC, 29U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 35U) + aOrbiterF) + RotL64(aOrbiterJ, 20U));
            aWandererK = aWandererK + ((((RotL64(aScatter, 19U) + aOrbiterK) + RotL64(aOrbiterJ, 13U)) + RotL64(aCarry, 35U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aCross, 6U) + RotL64(aOrbiterB, 57U)) + aOrbiterK) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aIngress, 13U) + aOrbiterD) + RotL64(aOrbiterB, 3U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 27U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 38U));
            aCarry = aCarry + (RotL64(aWandererG, 3U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererJ, 11U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 27451U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneA[((aIndex + 28960U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 32510U)) & S_BLOCK1], 22U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31427U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 30575U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aInvestLaneD[((aIndex + 30004U)) & S_BLOCK1], 52U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 3U) + RotL64(aIngress, 41U)) + (RotL64(aCarry, 20U) ^ RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterJ = ((aWandererB + RotL64(aIngress, 57U)) + RotL64(aCarry, 27U)) + 11700815697312060726U;
            aOrbiterB = ((aWandererD + RotL64(aScatter, 3U)) + 11808423452327465441U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterF = (((aWandererG + RotL64(aPrevious, 21U)) + RotL64(aCarry, 39U)) + 8670503858631730886U) + aPhaseEOrbiterAssignSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = (aWandererI + RotL64(aCross, 28U)) + 2400061067991988544U;
            aOrbiterA = (aWandererF + RotL64(aScatter, 47U)) + 16163118178366229686U;
            aOrbiterG = (aWandererA + RotL64(aIngress, 13U)) + 3280178595904941068U;
            aOrbiterC = ((aWandererC + RotL64(aCross, 35U)) + RotL64(aCarry, 53U)) + 3298683600817047727U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 16321624053445183574U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 6730229877611375225U;
            aOrbiterF = RotL64((aOrbiterF * 2022290495153519279U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 10162830636713641322U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 15646771327759599256U;
            aOrbiterJ = RotL64((aOrbiterJ * 15333053762177144775U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 14841751262270544102U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 9545541117228834895U;
            aOrbiterA = RotL64((aOrbiterA * 11529769874752969377U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 14676615635857599982U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 1231768638470558855U;
            aOrbiterB = RotL64((aOrbiterB * 2716808508509014677U), 37U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 1945905595345404833U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 1406171421638586846U;
            aOrbiterD = RotL64((aOrbiterD * 4577864352425476233U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 1970292335806697198U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 12309719390375013297U;
            aOrbiterC = RotL64((aOrbiterC * 16540660957923687327U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 5352135521358954576U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 15465675376193501658U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 16385761112921041387U), 27U);
            //
            aIngress = RotL64(aOrbiterC, 3U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterJ, 29U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 35U));
            aIngress = aIngress + RotL64(aOrbiterA, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aPrevious, 47U) + aOrbiterJ) + RotL64(aOrbiterG, 57U)) + RotL64(aCarry, 37U)) + aPhaseEWandererUpdateSaltB[((aIndex + 26U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aCross, 13U) + aOrbiterF) + RotL64(aOrbiterG, 44U)) + aPhaseEWandererUpdateSaltE[((aIndex + 14U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aIngress, 29U) + aOrbiterC) + RotL64(aOrbiterD, 5U)) + RotL64(aCarry, 13U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterD, 27U)) + aOrbiterB);
            aWandererB = aWandererB + ((RotL64(aCross, 23U) + aOrbiterF) + RotL64(aOrbiterD, 51U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 4U) + aOrbiterC) + RotL64(aOrbiterA, 13U));
            aWandererG = aWandererG + ((RotL64(aPrevious, 35U) + RotL64(aOrbiterA, 21U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 39U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 6U));
            aCarry = aCarry + (RotL64(aWandererA, 23U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererI, 19U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
        // read from: aOperationLaneA, aOperationLaneB, aExpandLaneC, aOperationLaneC, aOperationLaneD, aInvestLaneB, aSnowLaneA, aInvestLaneC, aExpandLaneD, aSnowLaneB, aExpandLaneA, aWorkLaneA, aExpandLaneB, aWorkLaneB, aInvestLaneA, aWorkLaneC, aInvestLaneD
        // write to: aSnowLaneA, aSnowLaneB, aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // twist_loop_c loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aExpandLaneC
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aExpandLaneC forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aInvestLaneB
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aInvestLaneB backward/forward random
        // write to: aSnowLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 3533U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneB[((aIndex + 5448U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aExpandLaneC[((aIndex + 3965U)) & S_BLOCK1], 34U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 519U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 4759U)) & S_BLOCK1], 44U));
            aCross ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 4371U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 43U) ^ RotL64(aPrevious, 6U)) ^ (RotL64(aIngress, 29U) + RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterI = (aWandererK + RotL64(aScatter, 39U)) + 16200278595895089008U;
            aOrbiterG = ((aWandererE + RotL64(aCross, 5U)) + RotL64(aCarry, 37U)) + 1029614154810465897U;
            aOrbiterE = (aWandererA + RotL64(aPrevious, 13U)) + 7129562468705441295U;
            aOrbiterH = ((aWandererJ + RotL64(aIngress, 60U)) + RotL64(aCarry, 29U)) + 14388903902433951274U;
            aOrbiterD = ((aWandererD + RotL64(aScatter, 51U)) + 1013568949315967455U) + aPhaseFOrbiterAssignSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = ((aWandererB + RotL64(aCross, 35U)) + 3128823373497815651U) + aPhaseFOrbiterAssignSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = ((aWandererH + RotL64(aPrevious, 43U)) + RotL64(aCarry, 47U)) + 14525694606889470589U;
            aOrbiterB = (aWandererG + RotL64(aIngress, 19U)) + 14443983602196782887U;
            aOrbiterJ = (aWandererF + RotL64(aCross, 37U)) + 12244220415328641190U;
            aOrbiterF = (aWandererI + RotL64(aScatter, 27U)) + 10477159225338766614U;
            aOrbiterC = (aWandererC + RotL64(aIngress, 22U)) + 2842870123078131566U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 8621138818955849917U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 5038396344400303181U;
            aOrbiterE = RotL64((aOrbiterE * 14636756322207385447U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 2768613802894372496U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 2027754864051410015U;
            aOrbiterI = RotL64((aOrbiterI * 2461322540050569287U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 2848088309172056399U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 15017458513904884651U;
            aOrbiterB = RotL64((aOrbiterB * 9926904679902843055U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 9079797279596336139U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 15424866642305110811U;
            aOrbiterF = RotL64((aOrbiterF * 12912331089970158845U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 13751764050290602740U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 7694557131324740282U;
            aOrbiterH = RotL64((aOrbiterH * 14980807690491467023U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 3508673897305667669U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 3600868397311393233U;
            aOrbiterG = RotL64((aOrbiterG * 5165032044164139165U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 1222655844979128996U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 2257342337168905875U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 6198995971182272119U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 6290990717563682725U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 15308494772443447109U;
            aOrbiterA = RotL64((aOrbiterA * 1925593111157842325U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 4065385272074155855U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 17216369169581934516U;
            aOrbiterC = RotL64((aOrbiterC * 16172589962950781777U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 15683161334290612079U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 4197626901960576264U;
            aOrbiterK = RotL64((aOrbiterK * 2822547214684481747U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 4400047838649306704U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 16200278595895089008U;
            aOrbiterJ = RotL64((aOrbiterJ * 6603195071605635697U), 23U);
            //
            aIngress = RotL64(aOrbiterB, 50U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 47U));
            aIngress = aIngress + (RotL64(aOrbiterA, 57U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 13U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 52U));
            aIngress = aIngress + RotL64(aOrbiterJ, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aCross, 12U) + aOrbiterA) + RotL64(aOrbiterJ, 26U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterD, 11U)) + aOrbiterG);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 53U) + aOrbiterK) + RotL64(aOrbiterI, 35U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 23U) + aOrbiterE) + RotL64(aOrbiterD, 3U));
            aWandererK = aWandererK + ((RotL64(aPrevious, 34U) + aOrbiterB) + RotL64(aOrbiterD, 44U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 27U) + aOrbiterC) + RotL64(aOrbiterI, 47U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aIngress, 5U) + aOrbiterH) + RotL64(aOrbiterJ, 53U)) + RotL64(aCarry, 39U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterE, 37U)) + aOrbiterF);
            aWandererG = aWandererG + ((RotL64(aIngress, 29U) + RotL64(aOrbiterB, 29U)) + aOrbiterA);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterB, 57U)) + aOrbiterE) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aCross, 51U) + RotL64(aOrbiterK, 23U)) + aOrbiterC) + RotL64(aCarry, 11U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 41U) ^ aWandererC);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 57U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 60U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 47U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 53U));
            aCarry = aCarry + RotL64(aWandererF, 5U);
            aCarry = aCarry + RotL64(aIngress, 24U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aSnowLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_c loop 2
        // ingress from: aSnowLaneA, aOperationLaneC, aOperationLaneD, aInvestLaneC
        // ingress directions: aSnowLaneA forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aInvestLaneC forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aExpandLaneD
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aExpandLaneD backward/forward random
        // write to: aSnowLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneA[((aIndex + 7856U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneC[((aIndex + 7414U)) & S_BLOCK1], 60U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 7579U)) & S_BLOCK1], 47U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 7638U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 6617U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 6107U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 8662U)) & S_BLOCK1], 24U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aIngress, 26U)) ^ (RotL64(aPrevious, 43U) + RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterB = ((aWandererD + RotL64(aScatter, 13U)) + 1457104756581596530U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterI = (aWandererJ + RotL64(aIngress, 40U)) + 6127240317844622874U;
            aOrbiterC = ((aWandererG + RotL64(aCross, 5U)) + RotL64(aCarry, 43U)) + 16492290056044189421U;
            aOrbiterK = ((aWandererA + RotL64(aPrevious, 11U)) + RotL64(aCarry, 13U)) + 10963676850938416468U;
            aOrbiterF = (aWandererF + RotL64(aIngress, 53U)) + 4872917367399752405U;
            aOrbiterA = ((aWandererI + RotL64(aScatter, 21U)) + 15218882377875616148U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterH = (aWandererH + RotL64(aCross, 3U)) + 5934166612122118251U;
            aOrbiterG = (aWandererK + RotL64(aPrevious, 35U)) + 14215280930872003003U;
            aOrbiterE = ((aWandererE + RotL64(aScatter, 30U)) + RotL64(aCarry, 29U)) + 11428034799044600979U;
            aOrbiterD = (aWandererC + RotL64(aIngress, 27U)) + 5453003654321728726U;
            aOrbiterJ = (aWandererB + RotL64(aPrevious, 37U)) + 14273775120265649389U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 328723770018440271U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 13032190719588211088U;
            aOrbiterC = RotL64((aOrbiterC * 13363368478932798315U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 2386881543033598494U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 1649501123340887116U;
            aOrbiterA = RotL64((aOrbiterA * 11148976582360499033U), 27U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 16462401546754210583U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 1510579201823042227U;
            aOrbiterG = RotL64((aOrbiterG * 16287912400104043275U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 6889066000014251983U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 11324594596597724357U;
            aOrbiterH = RotL64((aOrbiterH * 15344987814648586023U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 12237796033168436537U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 17306069670330000343U;
            aOrbiterI = RotL64((aOrbiterI * 3167451351403385259U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 14197284538008811658U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 4754134852883071927U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3484427259538998699U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 17201907781639753736U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 8318419319239859855U;
            aOrbiterE = RotL64((aOrbiterE * 10320390501983802091U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 16012488623961565780U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 15583721012865354925U;
            aOrbiterD = RotL64((aOrbiterD * 10656414363201743961U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 14680351201973315018U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 14483973292275372321U;
            aOrbiterK = RotL64((aOrbiterK * 9279222721410811027U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 16324317860030681248U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 7038506963317910910U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2960451734542956767U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 12767672960346001218U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 1457104756581596530U;
            aOrbiterJ = RotL64((aOrbiterJ * 1560375242310194691U), 5U);
            //
            aIngress = RotL64(aOrbiterH, 19U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 35U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 11U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterF, 41U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterI, 43U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterK, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 28U) + aOrbiterK) + RotL64(aOrbiterB, 39U));
            aWandererF = aWandererF + ((RotL64(aCross, 35U) + aOrbiterK) + RotL64(aOrbiterF, 21U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 11U) + aOrbiterG) + RotL64(aOrbiterJ, 60U));
            aWandererD = aWandererD + (((RotL64(aIngress, 5U) + RotL64(aOrbiterA, 37U)) + aOrbiterI) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterG, 51U)) + aOrbiterH);
            aWandererK = aWandererK + ((((RotL64(aCross, 43U) + RotL64(aOrbiterG, 27U)) + aOrbiterE) + RotL64(aCarry, 27U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 37U) + aOrbiterD) + RotL64(aOrbiterG, 57U));
            aWandererA = aWandererA + ((RotL64(aIngress, 39U) + RotL64(aOrbiterB, 43U)) + aOrbiterC);
            aWandererC = aWandererC ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterF, 6U)) + aOrbiterB);
            aWandererE = aWandererE + (((RotL64(aPrevious, 60U) + aOrbiterK) + RotL64(aOrbiterA, 13U)) + RotL64(aCarry, 57U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterH, 23U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 47U));
            aCarry = aCarry + (RotL64(aWandererF, 42U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererB, 27U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererJ, 3U) ^ aWandererK);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 5U));
            aCarry = aCarry + RotL64(aWandererA, 54U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aSnowLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_c loop 3
        // ingress from: aSnowLaneB, aOperationLaneA, aExpandLaneA
        // ingress directions: aSnowLaneB forward forced, aOperationLaneA forward forced, aExpandLaneA forward/backward random
        // cross from: aSnowLaneA, aOperationLaneC
        // cross directions: aSnowLaneA backward forced, aOperationLaneC backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneB[((aIndex + 12365U)) & S_BLOCK1], 12U) ^ RotL64(aOperationLaneA[((aIndex + 12972U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aExpandLaneA[((aIndex + 12114U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 16305U)) & S_BLOCK1], 52U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 11364U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 42U) ^ RotL64(aPrevious, 57U)) ^ (RotL64(aIngress, 27U) + RotL64(aCarry, 11U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterI = ((aWandererJ + RotL64(aScatter, 40U)) + 14686411261024919129U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterK = (aWandererE + RotL64(aIngress, 5U)) + 7514582233957632005U;
            aOrbiterB = (aWandererH + RotL64(aPrevious, 43U)) + 6520710480103365552U;
            aOrbiterG = ((aWandererA + RotL64(aCross, 21U)) + RotL64(aCarry, 11U)) + 1983621978676188036U;
            aOrbiterH = (((aWandererK + RotL64(aIngress, 13U)) + RotL64(aCarry, 37U)) + 9003524602590749672U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterE = (aWandererF + RotL64(aScatter, 27U)) + 6428568234045228995U;
            aOrbiterF = (aWandererI + RotL64(aCross, 29U)) + 8656552687136446989U;
            aOrbiterJ = ((aWandererG + RotL64(aPrevious, 18U)) + RotL64(aCarry, 27U)) + 16916248288415922490U;
            aOrbiterD = (aWandererC + RotL64(aScatter, 3U)) + 9740237548002535784U;
            aOrbiterC = (aWandererB + RotL64(aIngress, 51U)) + 907561000814618339U;
            aOrbiterA = (aWandererD + RotL64(aCross, 57U)) + 4751108900841197631U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 167774899400732287U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 11907484918310854962U;
            aOrbiterB = RotL64((aOrbiterB * 7213139491146402985U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 14910318613649863924U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 14882888155751455276U;
            aOrbiterE = RotL64((aOrbiterE * 11394136445442060201U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 16175942562693781908U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 11022373758481651102U;
            aOrbiterJ = RotL64((aOrbiterJ * 6836331461393816027U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 12548405399045031548U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 10850926364556828443U;
            aOrbiterG = RotL64((aOrbiterG * 16231561687709867431U), 43U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 13391684887911141790U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 14648937281264822988U;
            aOrbiterC = RotL64((aOrbiterC * 6533299316940026059U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 8298658887198526821U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 13822977698661348891U;
            aOrbiterK = RotL64((aOrbiterK * 17769262972278410937U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 7505646847564645719U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 3238749538197209166U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 15394286542600778567U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 15853506915123709257U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 8426329899401071248U;
            aOrbiterF = RotL64((aOrbiterF * 1330397096577715113U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 14848635392815613098U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 3549927798350175044U;
            aOrbiterA = RotL64((aOrbiterA * 1899044682313056949U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 1798973117197750802U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 13056711228618953977U;
            aOrbiterI = RotL64((aOrbiterI * 9102877396419306689U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 1395893547965799281U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 14686411261024919129U;
            aOrbiterH = RotL64((aOrbiterH * 17075377081365066067U), 5U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterK, 27U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 60U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 29U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 51U));
            aIngress = aIngress + (RotL64(aOrbiterF, 19U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterI, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aIngress, 53U) + aOrbiterI) + RotL64(aOrbiterF, 43U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 60U) + aOrbiterA) + RotL64(aOrbiterC, 21U));
            aWandererF = aWandererF + ((RotL64(aPrevious, 39U) + RotL64(aOrbiterD, 13U)) + aOrbiterI);
            aWandererH = aWandererH ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterH, 60U)) + aOrbiterG);
            aWandererD = aWandererD + ((RotL64(aPrevious, 13U) + aOrbiterJ) + RotL64(aOrbiterB, 51U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 43U) + RotL64(aOrbiterA, 47U)) + aOrbiterH) + aPhaseFWandererUpdateSaltD[((aIndex + 22U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aIngress, 23U) + RotL64(aOrbiterD, 23U)) + aOrbiterE) + RotL64(aCarry, 39U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 3U) + aOrbiterK) + RotL64(aOrbiterD, 3U));
            aWandererA = aWandererA + ((RotL64(aIngress, 10U) + RotL64(aOrbiterG, 6U)) + aOrbiterC);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 41U) + aOrbiterJ) + RotL64(aOrbiterA, 11U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 57U) + aOrbiterK) + RotL64(aOrbiterE, 57U)) + RotL64(aCarry, 11U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 40U));
            aCarry = aCarry + (RotL64(aWandererG, 43U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererE, 27U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererH, 37U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererD, 20U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererF, 5U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 21114U)) & S_BLOCK1], 3U) ^ RotL64(aSnowLaneA[((aIndex + 20143U)) & S_BLOCK1], 50U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 21181U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 19527U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 17272U)) & S_BLOCK1], 22U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 37U) + RotL64(aIngress, 50U)) + (RotL64(aCross, 23U) ^ RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterF = ((aWandererE + RotL64(aPrevious, 28U)) + RotL64(aCarry, 37U)) + 3650233661228036955U;
            aOrbiterA = ((aWandererA + RotL64(aIngress, 19U)) + 11607036400067735729U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterB = ((aWandererB + RotL64(aCross, 57U)) + RotL64(aCarry, 53U)) + 3899614406903883035U;
            aOrbiterJ = ((aWandererH + RotL64(aScatter, 53U)) + 8159156925629965143U) + aPhaseFOrbiterAssignSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterH = (aWandererF + RotL64(aCross, 3U)) + 7148903913967261270U;
            aOrbiterI = (aWandererJ + RotL64(aPrevious, 35U)) + 9161665622287517848U;
            aOrbiterK = (aWandererC + RotL64(aScatter, 21U)) + 2981535013474059469U;
            aOrbiterE = ((aWandererD + RotL64(aIngress, 23U)) + RotL64(aCarry, 21U)) + 15812469008200319549U;
            aOrbiterG = (aWandererI + RotL64(aCross, 47U)) + 14687469489893270300U;
            aOrbiterD = (aWandererG + RotL64(aPrevious, 13U)) + 6025209349511417063U;
            aOrbiterC = (aWandererK + RotL64(aScatter, 50U)) + 12964750392311112676U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 6572355895765394340U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 3542300121890027981U;
            aOrbiterB = RotL64((aOrbiterB * 11201491178181273935U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 6477175684045398359U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 1081388388827929314U;
            aOrbiterH = RotL64((aOrbiterH * 8752188637514143529U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 13754328481584620771U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 3684673342659575917U;
            aOrbiterK = RotL64((aOrbiterK * 6139923312873039143U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 6542045150319909445U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 5352102692424060388U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7385758355501860261U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 9110100774657340354U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 2813273684436269057U;
            aOrbiterF = RotL64((aOrbiterF * 10468759062594022273U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 5860425751137403755U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 1598622981888978548U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 651816500461718345U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 14710305692377606725U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 16280545617802383463U;
            aOrbiterA = RotL64((aOrbiterA * 12541767206978802063U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 6849565243667718750U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 12152381961996750050U;
            aOrbiterG = RotL64((aOrbiterG * 11185935780063403807U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 1318947876257794796U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 5447559252769140391U;
            aOrbiterC = RotL64((aOrbiterC * 13683733413554766327U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 2766869582494246454U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 15757729967222729304U;
            aOrbiterJ = RotL64((aOrbiterJ * 1858683399257513171U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 13063432816787882618U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 3650233661228036955U;
            aOrbiterD = RotL64((aOrbiterD * 16230564672533821641U), 47U);
            //
            aIngress = RotL64(aOrbiterK, 13U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterC, 30U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterE, 37U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 57U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 43U));
            aIngress = aIngress + RotL64(aOrbiterD, 24U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aCross, 43U) + RotL64(aOrbiterG, 43U)) + aOrbiterF);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterA, 47U)) + aOrbiterJ);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 39U) + aOrbiterJ) + RotL64(aOrbiterK, 57U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 47U) + aOrbiterC) + RotL64(aOrbiterE, 52U));
            aWandererH = aWandererH + ((((RotL64(aCross, 53U) + RotL64(aOrbiterD, 5U)) + aOrbiterC) + RotL64(aCarry, 5U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterK, 41U)) + aOrbiterC);
            aWandererA = aWandererA + ((RotL64(aPrevious, 20U) + aOrbiterH) + RotL64(aOrbiterK, 29U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 41U) + aOrbiterI) + RotL64(aOrbiterD, 27U));
            aWandererE = aWandererE + ((RotL64(aCross, 51U) + aOrbiterH) + RotL64(aOrbiterB, 21U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 11U) + aOrbiterF) + RotL64(aOrbiterJ, 35U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 24U) + aOrbiterG) + RotL64(aOrbiterK, 12U)) + RotL64(aCarry, 43U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 58U) ^ aWandererJ);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 21U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + (RotL64(aWandererK, 5U) ^ aWandererD);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 47U));
            aCarry = aCarry + RotL64(aWandererA, 42U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_c loop 5
        // ingress from: aWorkLaneB, aSnowLaneB, aInvestLaneA
        // ingress directions: aWorkLaneB forward forced, aSnowLaneB forward forced, aInvestLaneA forward/backward random
        // cross from: aWorkLaneA, aSnowLaneA
        // cross directions: aWorkLaneA backward forced, aSnowLaneA backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 26241U)) & S_BLOCK1], 14U) ^ RotL64(aSnowLaneB[((aIndex + 23480U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aInvestLaneA[((aIndex + 22274U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 26798U)) & S_BLOCK1], 22U) ^ RotL64(aSnowLaneA[((aIndex + 26235U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 13U) ^ RotL64(aIngress, 41U)) + (RotL64(aCross, 58U) + RotL64(aPrevious, 27U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = (aWandererI + RotL64(aScatter, 3U)) + 5510690816044082200U;
            aOrbiterA = ((aWandererG + RotL64(aIngress, 11U)) + RotL64(aCarry, 27U)) + 15967820875033940530U;
            aOrbiterJ = (aWandererB + RotL64(aCross, 34U)) + 539348720848176221U;
            aOrbiterG = (aWandererC + RotL64(aPrevious, 39U)) + 15779318183635560817U;
            aOrbiterC = (aWandererE + RotL64(aScatter, 29U)) + 14511058534424187469U;
            aOrbiterE = ((aWandererF + RotL64(aPrevious, 21U)) + RotL64(aCarry, 19U)) + 5811130556873428391U;
            aOrbiterF = (aWandererD + RotL64(aIngress, 23U)) + 1085928476499444025U;
            aOrbiterI = ((aWandererA + RotL64(aCross, 58U)) + 6973335316600768130U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = ((aWandererK + RotL64(aScatter, 41U)) + RotL64(aCarry, 43U)) + 10747243745475009744U;
            aOrbiterB = ((aWandererH + RotL64(aCross, 27U)) + 1072260008981349754U) + aPhaseFOrbiterAssignSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterH = (aWandererJ + RotL64(aPrevious, 37U)) + 2018772405352495753U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 1092091597048996547U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 15103140149542167197U;
            aOrbiterJ = RotL64((aOrbiterJ * 621856991658027989U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 13194619321108681542U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 16749188603268621850U;
            aOrbiterC = RotL64((aOrbiterC * 9575408950550922039U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 7427959503086895166U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 9895804051379551393U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2701997336201570715U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 4526020800679774259U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 4484850928870048176U;
            aOrbiterE = RotL64((aOrbiterE * 17556987520625677313U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 1837404844299040155U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 15213208978489570694U;
            aOrbiterH = RotL64((aOrbiterH * 7062740584650274133U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 9615231781751396800U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 15872192167825648096U;
            aOrbiterA = RotL64((aOrbiterA * 2900526493682580729U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 12530672039655918903U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 10617836782870315804U;
            aOrbiterK = RotL64((aOrbiterK * 9716778004909794973U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 550750725406860977U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 3498554352021622907U;
            aOrbiterB = RotL64((aOrbiterB * 9846933294851238495U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 4059346317776216057U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 14161853870874499023U;
            aOrbiterI = RotL64((aOrbiterI * 8601560894939097781U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 4088411647683253905U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 9321241420172776158U;
            aOrbiterG = RotL64((aOrbiterG * 4167888281125330225U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 8527337525861632945U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 5510690816044082200U;
            aOrbiterD = RotL64((aOrbiterD * 12464836001483233379U), 23U);
            //
            aIngress = RotL64(aOrbiterC, 51U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 53U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 60U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 37U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 11U));
            aIngress = aIngress + RotL64(aOrbiterJ, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aScatter, 27U) + aOrbiterG) + RotL64(aOrbiterF, 12U)) + aPhaseFWandererUpdateSaltA[((aIndex + 27U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aPrevious, 21U) + RotL64(aOrbiterD, 43U)) + aOrbiterA);
            aWandererA = aWandererA ^ ((RotL64(aCross, 41U) + aOrbiterD) + RotL64(aOrbiterE, 53U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 23U) + aOrbiterH) + RotL64(aOrbiterI, 23U)) + RotL64(aCarry, 5U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 29U) + aOrbiterI) + RotL64(aOrbiterE, 19U));
            aWandererK = aWandererK + (((RotL64(aScatter, 52U) + RotL64(aOrbiterE, 21U)) + aOrbiterG) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterJ, 5U)) + aOrbiterG);
            aWandererB = aWandererB + (((RotL64(aCross, 19U) + RotL64(aOrbiterC, 51U)) + aOrbiterI) + RotL64(aCarry, 29U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 57U) + aOrbiterC) + RotL64(aOrbiterD, 34U));
            aWandererE = aWandererE + ((RotL64(aPrevious, 3U) + aOrbiterF) + RotL64(aOrbiterK, 57U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 6U) + aOrbiterC) + RotL64(aOrbiterB, 41U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 18U) ^ aWandererG);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 53U));
            aCarry = aCarry + (RotL64(aWandererD, 43U) ^ aWandererA);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 11U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 47U));
            aCarry = aCarry + RotL64(aWandererF, 39U);
            aCarry = aCarry + RotL64(aIngress, 4U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // twist_loop_c loop 6
        // ingress from: aWorkLaneC, aWorkLaneA, aInvestLaneD
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aInvestLaneD forward/backward random
        // cross from: aWorkLaneB, aOperationLaneB
        // cross directions: aWorkLaneB backward forced, aOperationLaneB backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 31162U)) & S_BLOCK1], 50U) ^ RotL64(aWorkLaneA[((aIndex + 29950U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aInvestLaneD[((aIndex + 31429U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 28770U)) & S_BLOCK1], 56U) ^ RotL64(aOperationLaneB[((aIndex + 32101U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 24U) + RotL64(aCarry, 39U)) + (RotL64(aPrevious, 3U) ^ RotL64(aCross, 51U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterJ = (aWandererG + RotL64(aCross, 21U)) + 17711946802293254150U;
            aOrbiterD = ((aWandererB + RotL64(aIngress, 24U)) + RotL64(aCarry, 27U)) + 16652362590489569378U;
            aOrbiterB = (aWandererA + RotL64(aPrevious, 13U)) + 6972810344198183097U;
            aOrbiterK = ((aWandererC + RotL64(aScatter, 5U)) + 13117100889782940546U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterH = (aWandererJ + RotL64(aPrevious, 11U)) + 13199305696782626591U;
            aOrbiterF = (aWandererK + RotL64(aCross, 29U)) + 992156184392760945U;
            aOrbiterC = (aWandererD + RotL64(aIngress, 56U)) + 13791265442074543880U;
            aOrbiterE = ((aWandererI + RotL64(aScatter, 47U)) + RotL64(aCarry, 21U)) + 17057087245252294859U;
            aOrbiterG = (aWandererE + RotL64(aPrevious, 37U)) + 13444195995883541046U;
            aOrbiterI = ((aWandererF + RotL64(aCross, 43U)) + RotL64(aCarry, 47U)) + 6723678233676059420U;
            aOrbiterA = ((aWandererH + RotL64(aIngress, 53U)) + 7913379431208430475U) + aPhaseFOrbiterAssignSaltA[((aIndex + 6U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 4481887195529300665U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 11892724101424384078U;
            aOrbiterB = RotL64((aOrbiterB * 3468639499716604111U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 7700902083270424194U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 1888001433557140271U;
            aOrbiterH = RotL64((aOrbiterH * 8975562955027025349U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 14996753906788986929U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 939004845422123765U;
            aOrbiterD = RotL64((aOrbiterD * 2507090308972292313U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 11922230289291941807U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 15681187459741147199U;
            aOrbiterG = RotL64((aOrbiterG * 10124947739653819101U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 9119043713532718155U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 8327697433992362166U;
            aOrbiterE = RotL64((aOrbiterE * 11157657162184304567U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 13630755116592440359U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 771252613886022889U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2958918915223536519U), 37U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 8524239721467527770U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 17732617735422435572U;
            aOrbiterJ = RotL64((aOrbiterJ * 13992947983987668631U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 5265753270696005619U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 14456128349522985053U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5406509991740849617U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 12909993509014176457U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 10113568710432654194U;
            aOrbiterI = RotL64((aOrbiterI * 6857806395910432831U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 14818978163348513071U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 17843349910031998923U;
            aOrbiterC = RotL64((aOrbiterC * 13608449524810499593U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 12589077818524017161U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 17711946802293254150U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 9454569713107675231U), 43U);
            //
            aIngress = RotL64(aOrbiterF, 22U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterD, 43U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 19U));
            aIngress = aIngress + (RotL64(aOrbiterK, 29U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 37U));
            aIngress = aIngress + RotL64(aOrbiterE, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterK, 3U)) + aOrbiterE) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 34U) + RotL64(aOrbiterJ, 29U)) + aOrbiterC);
            aWandererI = aWandererI + ((RotL64(aIngress, 41U) + RotL64(aOrbiterC, 46U)) + aOrbiterI);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 19U) + RotL64(aOrbiterE, 37U)) + aOrbiterA) + aPhaseFWandererUpdateSaltD[((aIndex + 27U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aPrevious, 39U) + RotL64(aOrbiterK, 51U)) + aOrbiterB) + RotL64(aCarry, 57U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 27U) + aOrbiterI) + RotL64(aOrbiterG, 19U));
            aWandererK = aWandererK + ((RotL64(aIngress, 43U) + aOrbiterF) + RotL64(aOrbiterD, 60U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 21U) + aOrbiterG) + RotL64(aOrbiterD, 57U));
            aWandererA = aWandererA + (((RotL64(aScatter, 29U) + RotL64(aOrbiterC, 41U)) + aOrbiterK) + RotL64(aCarry, 41U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 12U) + aOrbiterJ) + RotL64(aOrbiterE, 21U));
            aWandererE = aWandererE + ((RotL64(aIngress, 57U) + RotL64(aOrbiterH, 27U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererG, 21U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererF, 42U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererA, 19U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererJ, 23U) ^ aWandererH);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 57U));
            aCarry = aCarry + RotL64(aWandererK, 38U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 8002U)) & S_BLOCK1], 34U) ^ RotL64(aWorkLaneB[((aIndex + 4282U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 5047U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 4284U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 2178U)) & S_BLOCK1], 10U));
            aCross ^= RotL64(aOperationLaneA[((aIndex + 3520U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 29U) + RotL64(aCross, 13U)) ^ (RotL64(aPrevious, 54U) + RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterA = (aWandererE + RotL64(aScatter, 3U)) + 3970829908171131502U;
            aOrbiterF = ((aWandererD + RotL64(aPrevious, 43U)) + RotL64(aCarry, 21U)) + 7040283759419531991U;
            aOrbiterH = ((aWandererK + RotL64(aCross, 11U)) + RotL64(aCarry, 3U)) + 11856292169397052901U;
            aOrbiterC = (((aWandererJ + RotL64(aIngress, 35U)) + RotL64(aCarry, 53U)) + 819598588791819022U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterK = ((aWandererG + RotL64(aScatter, 58U)) + 2176451710970866848U) + aPhaseGOrbiterAssignSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 6454704928613390494U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 11792122387218053841U;
            aOrbiterH = RotL64((aOrbiterH * 17994898985794518565U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 9254780213489752211U) + aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 16591812589999846482U) ^ aPhaseGOrbiterUpdateSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5425771603523423167U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 1471246223935074832U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 1424843083106386453U) ^ aPhaseGOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 15020536982657410783U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 1856469958050891629U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 6331743690452052712U;
            aOrbiterC = RotL64((aOrbiterC * 15327924647897459645U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 10351075711345476487U) + aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 9518585245330480185U;
            aOrbiterK = RotL64((aOrbiterK * 3792179827396760391U), 37U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterH, 19U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 3U));
            aIngress = aIngress + RotL64(aOrbiterA, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterH, 3U)) + aOrbiterK);
            aWandererG = aWandererG + ((((RotL64(aCross, 3U) + aOrbiterC) + RotL64(aOrbiterA, 18U)) + RotL64(aCarry, 43U)) + aPhaseGWandererUpdateSaltA[((aIndex + 4U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterF, 51U)) + aOrbiterK);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 22U) + aOrbiterC) + RotL64(aOrbiterF, 29U)) + RotL64(aCarry, 57U)) + aPhaseGWandererUpdateSaltB[((aIndex + 5U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 11U) + aOrbiterH) + RotL64(aOrbiterA, 43U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 57U) ^ aWandererJ);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 43U));
            aCarry = aCarry + RotL64(aWandererK, 35U);
            aCarry = aCarry + RotL64(aIngress, 10U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 14503U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneC[((aIndex + 11560U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 10296U)) & S_BLOCK1], 12U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 12934U)) & S_BLOCK1], 40U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 9585U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 12915U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 36U) ^ RotL64(aCarry, 51U)) ^ (RotL64(aIngress, 19U) + RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterH = (((aWandererA + RotL64(aIngress, 43U)) + RotL64(aCarry, 3U)) + 1866656689936219099U) + aPhaseGOrbiterAssignSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterJ = ((aWandererE + RotL64(aCross, 3U)) + 2312314528139448289U) + aPhaseGOrbiterAssignSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterI = ((aWandererD + RotL64(aScatter, 21U)) + RotL64(aCarry, 47U)) + 3554037526469185237U;
            aOrbiterF = (aWandererG + RotL64(aPrevious, 13U)) + 405707755060974111U;
            aOrbiterB = ((aWandererC + RotL64(aCross, 30U)) + RotL64(aCarry, 27U)) + 1862976326004007697U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 12992483065443288263U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 3793854946371595197U;
            aOrbiterI = RotL64((aOrbiterI * 1819119223110966487U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 4244007978867369382U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 10280867500312580308U) ^ aPhaseGOrbiterUpdateSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13729899124177931289U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 472563452959164242U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 12041770406895816553U;
            aOrbiterH = RotL64((aOrbiterH * 17811798500132002631U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 6118634015704900486U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 13637107920449233307U;
            aOrbiterB = RotL64((aOrbiterB * 17712028184714868053U), 37U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 16673735670669318830U) + aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 8602681273646630496U;
            aOrbiterF = RotL64((aOrbiterF * 6995213887710749241U), 19U);
            //
            aIngress = RotL64(aOrbiterJ, 13U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterI, 26U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterF, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 26U) + RotL64(aOrbiterF, 3U)) + aOrbiterH) + aPhaseGWandererUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aScatter, 43U) + RotL64(aOrbiterJ, 57U)) + aOrbiterH) + RotL64(aCarry, 37U)) + aPhaseGWandererUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 5U) + aOrbiterI) + RotL64(aOrbiterF, 29U));
            aWandererG = aWandererG + (((RotL64(aIngress, 13U) + RotL64(aOrbiterI, 13U)) + aOrbiterH) + RotL64(aCarry, 23U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 57U) + aOrbiterJ) + RotL64(aOrbiterB, 44U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 35U) ^ aWandererG);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 57U));
            aCarry = aCarry + RotL64(aWandererC, 22U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 19279U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneD[((aIndex + 22610U)) & S_BLOCK1], 26U));
            aIngress ^= RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 18324U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 17843U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 17628U)) & S_BLOCK1], 24U));
            aCross ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 19169U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 22U) ^ RotL64(aCross, 35U)) ^ (RotL64(aCarry, 47U) + RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterJ = ((aWandererH + RotL64(aCross, 11U)) + RotL64(aCarry, 37U)) + 380024772508948442U;
            aOrbiterK = (aWandererF + RotL64(aIngress, 35U)) + 7649029098162567210U;
            aOrbiterG = (((aWandererG + RotL64(aScatter, 47U)) + RotL64(aCarry, 3U)) + 5329304598870421851U) + aPhaseGOrbiterAssignSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterE = ((aWandererE + RotL64(aPrevious, 56U)) + RotL64(aCarry, 21U)) + 12306118665045151326U;
            aOrbiterA = ((aWandererA + RotL64(aCross, 19U)) + 960751560457324256U) + aPhaseGOrbiterAssignSaltB[((aIndex + 6U)) & S_SALT1];
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 3244070254386191876U) + aPhaseGOrbiterUpdateSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 15733408571609521746U;
            aOrbiterG = RotL64((aOrbiterG * 11280008313548121407U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 17623448932647018544U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 8787759896149035829U;
            aOrbiterJ = RotL64((aOrbiterJ * 7092515868845497573U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 14741681792348288162U) + aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 8801731213568307302U;
            aOrbiterA = RotL64((aOrbiterA * 12127126999570616489U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 9872248187499779222U) + aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 15407371518644528235U;
            aOrbiterE = RotL64((aOrbiterE * 1245102406469471673U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 4242060317152943062U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 9942784962409917541U;
            aOrbiterK = RotL64((aOrbiterK * 888649755587764533U), 37U);
            //
            aIngress = RotL64(aOrbiterG, 35U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 47U));
            aIngress = aIngress + RotL64(aOrbiterK, 58U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aIngress, 13U) + RotL64(aOrbiterA, 27U)) + aOrbiterE) + RotL64(aCarry, 19U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 60U) + aOrbiterA) + RotL64(aOrbiterJ, 47U)) + aPhaseGWandererUpdateSaltE[((aIndex + 9U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 21U) + RotL64(aOrbiterJ, 14U)) + aOrbiterE) + RotL64(aCarry, 47U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 47U) + RotL64(aOrbiterG, 5U)) + aOrbiterK) + aPhaseGWandererUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aIngress, 5U) + RotL64(aOrbiterG, 35U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 48U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 13U));
            aCarry = aCarry + RotL64(aWandererH, 21U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 32168U)) & S_BLOCK1], 12U) ^ RotL64(aExpandLaneA[((aIndex + 26177U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 30548U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30464U)) & S_BLOCK1], 52U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 25852U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aOperationLaneD[((aIndex + 30751U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 43U) + RotL64(aCarry, 26U)) ^ (RotL64(aIngress, 11U) + RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterD = ((aWandererE + RotL64(aIngress, 19U)) + RotL64(aCarry, 51U)) + 1142447269198373880U;
            aOrbiterB = (aWandererJ + RotL64(aScatter, 11U)) + 10581460640040336191U;
            aOrbiterC = (((aWandererD + RotL64(aPrevious, 50U)) + RotL64(aCarry, 39U)) + 14703062773878202900U) + aPhaseGOrbiterAssignSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterE = ((aWandererI + RotL64(aCross, 39U)) + RotL64(aCarry, 5U)) + 15737525756286914746U;
            aOrbiterG = ((aWandererG + RotL64(aScatter, 3U)) + 16178774478273186999U) + aPhaseGOrbiterAssignSaltD[((aIndex + 5U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 2514897053906809160U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 13702496607592508464U;
            aOrbiterC = RotL64((aOrbiterC * 16540143680974064057U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 18030885275418337965U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 5241783876161655984U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 10970981186787227937U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 2807052676283587925U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 8022804576763271327U;
            aOrbiterG = RotL64((aOrbiterG * 11727096043219370577U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 15597099852232205860U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 1538435607932096400U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7900752511710516981U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 11147868774413615365U) + aPhaseGOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 9325213746830411568U) ^ aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 561819005818948769U), 5U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterC, 54U);
            aIngress = aIngress + (RotL64(aOrbiterE, 43U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterD, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aCross, 37U) + RotL64(aOrbiterG, 13U)) + aOrbiterE) + RotL64(aCarry, 27U)) + aPhaseGWandererUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 46U) + aOrbiterG) + RotL64(aOrbiterD, 37U));
            aWandererD = aWandererD + (((RotL64(aIngress, 23U) + RotL64(aOrbiterC, 29U)) + aOrbiterE) + aPhaseGWandererUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterB, 46U)) + aOrbiterD);
            aWandererI = aWandererI + (((RotL64(aIngress, 57U) + aOrbiterE) + RotL64(aOrbiterD, 3U)) + RotL64(aCarry, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 35U) ^ aWandererI);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 3U));
            aCarry = aCarry + RotL64(aWandererJ, 56U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterE = 0;
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
        // ingress from: aExpandLaneA, aExpandLaneB, aInvestLaneA
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aInvestLaneA forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD, aOperationLaneA
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward forced, aOperationLaneA backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 7826U)) & S_BLOCK1], 46U) ^ RotL64(aExpandLaneB[((aIndex + 7959U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aInvestLaneA[((aIndex + 5722U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 2028U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 104U)) & S_BLOCK1], 56U));
            aCross ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 5412U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 11U) ^ RotL64(aCross, 23U)) ^ (RotL64(aPrevious, 54U) + RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterF = (((aWandererD + RotL64(aIngress, 29U)) + RotL64(aCarry, 27U)) + 9133751643283278896U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = (aWandererC + RotL64(aPrevious, 54U)) + 8971581804375380408U;
            aOrbiterH = ((aWandererI + RotL64(aCross, 21U)) + RotL64(aCarry, 51U)) + 12559650383714566592U;
            aOrbiterJ = (((aWandererJ + RotL64(aScatter, 3U)) + RotL64(aCarry, 11U)) + 15753206088872859163U) + aPhaseHOrbiterAssignSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterB = (aWandererG + RotL64(aIngress, 13U)) + 7640756270450762350U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 7340073357551376125U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 5270256573644196046U;
            aOrbiterH = RotL64((aOrbiterH * 13286406906662922841U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 3567367996479995928U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 11939634537492733738U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5640541900117183639U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 7051817732424527120U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 1730487669951837941U;
            aOrbiterA = RotL64((aOrbiterA * 15191634337956285841U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 18009252467909454817U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 2361024272031696442U;
            aOrbiterJ = RotL64((aOrbiterJ * 15215151562500226027U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 15902755877642960397U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 12243517544704116184U;
            aOrbiterF = RotL64((aOrbiterF * 2576071074148141447U), 11U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterA, 60U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 47U));
            aIngress = aIngress + RotL64(aOrbiterJ, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aIngress, 26U) + RotL64(aOrbiterJ, 35U)) + aOrbiterA) + aPhaseHWandererUpdateSaltE[((aIndex + 27U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 51U) + aOrbiterF) + RotL64(aOrbiterJ, 43U)) + RotL64(aCarry, 37U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterB, 27U)) + aOrbiterH);
            aWandererG = aWandererG + (((RotL64(aCross, 13U) + aOrbiterH) + RotL64(aOrbiterJ, 53U)) + RotL64(aCarry, 23U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 43U) + RotL64(aOrbiterB, 12U)) + aOrbiterF) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 39U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererJ, 29U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererD, 47U);
            aCarry = aCarry + RotL64(aIngress, 56U);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 10370U)) & S_BLOCK1], 24U) ^ RotL64(aExpandLaneC[((aIndex + 16153U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 10252U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 9617U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 15860U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 9993U)) & S_BLOCK1], 48U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 21U) ^ RotL64(aCross, 39U)) ^ (RotL64(aCarry, 53U) + RotL64(aIngress, 4U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterH = ((aWandererD + RotL64(aCross, 11U)) + RotL64(aCarry, 27U)) + 3973833383430652211U;
            aOrbiterB = ((aWandererH + RotL64(aScatter, 54U)) + 5760227042747169187U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterK = (aWandererE + RotL64(aIngress, 21U)) + 4923009065139227286U;
            aOrbiterG = (((aWandererK + RotL64(aPrevious, 39U)) + RotL64(aCarry, 57U)) + 1477807307009107590U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = ((aWandererI + RotL64(aIngress, 29U)) + RotL64(aCarry, 11U)) + 5707194514329007301U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 5340439728375269724U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 17080457898946572387U;
            aOrbiterK = RotL64((aOrbiterK * 17719588880215414933U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 281559150259472813U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 16160633048230910560U;
            aOrbiterA = RotL64((aOrbiterA * 16883442583309073785U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 9003989610509592121U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 10579322462808454333U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 100832431598087235U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 15059383289528723069U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 10417647757852880956U;
            aOrbiterG = RotL64((aOrbiterG * 1457919230286043137U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 14484665027393813330U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 12344463053485837974U;
            aOrbiterB = RotL64((aOrbiterB * 5762654194001525041U), 11U);
            //
            aIngress = RotL64(aOrbiterH, 3U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterK, 27U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterB, 14U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aIngress, 19U) + RotL64(aOrbiterK, 52U)) + aOrbiterA) + aPhaseHWandererUpdateSaltF[((aIndex + 15U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 48U) + RotL64(aOrbiterG, 39U)) + aOrbiterK) + RotL64(aCarry, 3U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 57U) + aOrbiterH) + RotL64(aOrbiterA, 29U));
            aWandererD = aWandererD + (((RotL64(aScatter, 39U) + aOrbiterG) + RotL64(aOrbiterB, 13U)) + RotL64(aCarry, 53U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterB, 5U)) + aOrbiterH) + aPhaseHWandererUpdateSaltB[((aIndex + 22U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 13U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererE, 21U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererH, 39U);
            aCarry = aCarry + RotL64(aIngress, 30U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 20940U)) & S_BLOCK1], 60U) ^ RotL64(aExpandLaneD[((aIndex + 21261U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 21024U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 20354U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 19760U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 17974U)) & S_BLOCK1], 14U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aIngress, 22U)) + (RotL64(aPrevious, 57U) ^ RotL64(aCross, 43U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterK = (aWandererF + RotL64(aIngress, 29U)) + 5510690816044082200U;
            aOrbiterG = ((aWandererG + RotL64(aPrevious, 21U)) + RotL64(aCarry, 23U)) + 15967820875033940530U;
            aOrbiterC = ((aWandererK + RotL64(aCross, 13U)) + RotL64(aCarry, 3U)) + 539348720848176221U;
            aOrbiterI = (((aWandererD + RotL64(aScatter, 3U)) + RotL64(aCarry, 51U)) + 15779318183635560817U) + aPhaseHOrbiterAssignSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = ((aWandererH + RotL64(aPrevious, 48U)) + 14511058534424187469U) + aPhaseHOrbiterAssignSaltF[((aIndex + 18U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 5811130556873428391U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 1085928476499444025U;
            aOrbiterC = RotL64((aOrbiterC * 13965845678632598921U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 6973335316600768130U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 10747243745475009744U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 17322489216048017061U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 1072260008981349754U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 2018772405352495753U;
            aOrbiterE = RotL64((aOrbiterE * 10840562112080574241U), 37U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 1092091597048996547U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 15103140149542167197U;
            aOrbiterK = RotL64((aOrbiterK * 621856991658027989U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 13194619321108681542U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 16749188603268621850U;
            aOrbiterG = RotL64((aOrbiterG * 9575408950550922039U), 47U);
            //
            aIngress = RotL64(aOrbiterI, 13U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterG, 46U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterK, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aPrevious, 37U) + RotL64(aOrbiterK, 3U)) + aOrbiterG);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 60U) + RotL64(aOrbiterC, 30U)) + aOrbiterI);
            aWandererG = aWandererG + ((((RotL64(aIngress, 13U) + aOrbiterE) + RotL64(aOrbiterI, 19U)) + RotL64(aCarry, 51U)) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aCross, 51U) + aOrbiterK) + RotL64(aOrbiterE, 51U)) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 23U) + aOrbiterG) + RotL64(aOrbiterC, 11U)) + RotL64(aCarry, 11U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 43U));
            aCarry = aCarry + (RotL64(aWandererD, 3U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererF, 53U);
            aCarry = aCarry + RotL64(aIngress, 20U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 30183U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((aIndex + 29556U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 24790U)) & S_BLOCK1], 54U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27014U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 28523U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aOperationLaneD[((aIndex + 25518U)) & S_BLOCK1], 60U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 6U) + RotL64(aCarry, 27U)) ^ (RotL64(aIngress, 39U) + RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterA = ((aWandererJ + RotL64(aScatter, 35U)) + RotL64(aCarry, 5U)) + 4068921616130916949U;
            aOrbiterJ = ((aWandererA + RotL64(aIngress, 13U)) + 12077715273915151726U) + aPhaseHOrbiterAssignSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterB = ((aWandererE + RotL64(aPrevious, 52U)) + RotL64(aCarry, 53U)) + 16047546802670596833U;
            aOrbiterE = ((aWandererH + RotL64(aCross, 43U)) + RotL64(aCarry, 41U)) + 9690277462716999763U;
            aOrbiterK = ((aWandererG + RotL64(aIngress, 23U)) + 14484814700447992628U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 17089267243053958210U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 9138746214446211147U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 8244950097712975043U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 10181001536979097045U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 6657458969093373191U;
            aOrbiterK = RotL64((aOrbiterK * 4311019792293202747U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 7515983477876590988U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 3039935555863947600U;
            aOrbiterE = RotL64((aOrbiterE * 12511160550780270119U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 16209389224740851136U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 725253312098083182U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 17535989492095522597U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 13307041115748941383U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 7159572004825238263U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 4855009895002398449U), 53U);
            //
            aIngress = RotL64(aOrbiterB, 57U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 40U));
            aIngress = aIngress + RotL64(aOrbiterJ, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aIngress, 11U) + aOrbiterB) + RotL64(aOrbiterK, 40U)) + RotL64(aCarry, 19U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 29U) + aOrbiterJ) + RotL64(aOrbiterA, 13U));
            aWandererH = aWandererH + (((RotL64(aCross, 19U) + RotL64(aOrbiterJ, 5U)) + aOrbiterB) + RotL64(aCarry, 39U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 50U) + aOrbiterB) + RotL64(aOrbiterE, 57U)) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 39U) + aOrbiterA) + RotL64(aOrbiterK, 23U)) + aPhaseHWandererUpdateSaltE[((aIndex + 6U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 3U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererG, 21U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererA, 48U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
