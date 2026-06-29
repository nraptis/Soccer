#include "TwistExpander_BasketBall_Arx.hpp"
#include "TwistFunctional.hpp"
#include "TwistMix32.hpp"
#include "TwistMix64.hpp"

#include <cstdint>

void TwistExpander_BasketBall_Arx::KDF_A_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x82C80D147F55EFDFULL + 0xFACB9EE830A778B7ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xF02EAF224237EB81ULL + 0x9CBFA0006F2EF2CFULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x984FC3F759AD2907ULL + 0xA1E8613868B90BABULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x9A4D8A035024688FULL + 0xF395ABF097F84F8EULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xB7B8A388F946113DULL + 0xB2119981DD066668ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x9F00DA1820AA0AD3ULL + 0xEBADA79F0F13C8F9ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xCD81FA61D48C700FULL + 0xCEAADA1B97733A3CULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xA96EF1171D84C9A3ULL + 0x961073F1C0073D8FULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xB44092105E606063ULL + 0xA60DBCCD3372EC96ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xE7105A9A658F8287ULL + 0xD92829F03C845D7BULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xC8608A169065AA97ULL + 0xF73515953358A4BBULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xC2DF8713BED8E7F1ULL + 0xAE6ACC9872342AB1ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xCE727FB7CFF3880DULL + 0xB32299943D66C46AULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x876343C2799024F1ULL + 0x98BB3CB9F55F8492ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x9791676D3B7C38D1ULL + 0xCA2D90C3B6D29529ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xE89625BA1FE8EE23ULL + 0xC5BFFC6DC90EB994ULL);
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
            aIngress = RotL64(mSource[((aIndex + 4576U)) & S_BLOCK1], 23U) ^ RotL64(pSnow[((aIndex + 4198U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(pSnow[((S_BLOCK1 - aIndex + 4880U)) & S_BLOCK1], 38U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 2340U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCarry, 23U) + RotL64(aIngress, 5U)) ^ (RotL64(aCross, 36U) ^ RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterH = (aWandererG + RotL64(aIngress, 14U)) + 16519040829220310189U;
            aOrbiterD = ((aWandererA + RotL64(aScatter, 3U)) + 6888002778416941825U) + aNonceWordA;
            aOrbiterA = ((aWandererC + RotL64(aPrevious, 11U)) + 1310832187746534025U) + aNonceWordB;
            aOrbiterE = ((aWandererJ + RotL64(aCross, 27U)) + 5890888009051281674U) + aNonceWordK;
            aOrbiterC = (aWandererK + RotL64(aScatter, 19U)) + 5143864838362464857U;
            aOrbiterG = (((aWandererF + RotL64(aIngress, 51U)) + 15591534069452660003U) + aOrbiterAssignSaltB[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordC;
            aOrbiterJ = (((aWandererE + RotL64(aCross, 57U)) + RotL64(aCarry, 21U)) + 1466867671765325096U) + aOrbiterAssignSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterB = ((aWandererI + RotL64(aPrevious, 42U)) + RotL64(aCarry, 57U)) + 13931443680107902488U;
            aOrbiterK = ((aWandererD + RotL64(aScatter, 21U)) + RotL64(aCarry, 29U)) + 15400747367673245552U;
            aOrbiterI = (aWandererH + RotL64(aIngress, 23U)) + 2836975369734495759U;
            aOrbiterF = (aWandererB + RotL64(aPrevious, 53U)) + 2370720358274970117U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 3470677184188006133U) + aOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 7175584278499266723U;
            aOrbiterA = RotL64((aOrbiterA * 10067096593682482345U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 6095078817776863055U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 2176637999243513070U;
            aOrbiterG = RotL64((aOrbiterG * 12215701810843975501U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 5580391239754903129U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 15196125567953871184U) ^ aNonceWordG;
            aOrbiterB = RotL64((aOrbiterB * 12686361960729564519U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 12787014151503209931U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 1523153207064063495U;
            aOrbiterC = RotL64((aOrbiterC * 3113907543551927561U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 12973289026485937829U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 9087439766232078173U) ^ aNonceWordE;
            aOrbiterD = RotL64((aOrbiterD * 5817029335999350327U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 16318022893068674015U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 11089160685103562409U;
            aOrbiterI = RotL64((aOrbiterI * 17087834321385147603U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 8680037953925067235U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 3112588943274158119U) ^ aNonceWordM;
            aOrbiterF = RotL64((aOrbiterF * 9214011370307670371U), 41U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 16749015684369649821U) + aOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = (((aOrbiterH ^ aOrbiterC) ^ 9419550535891334966U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterH = RotL64((aOrbiterH * 5421312787569114811U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 12309598080688360615U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 12244971765096881835U;
            aOrbiterE = RotL64((aOrbiterE * 17260277357109449509U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 10088685417774847648U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 3241987595838650154U;
            aOrbiterK = RotL64((aOrbiterK * 14096986158958931367U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 17916401586500786536U) + aOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 16519040829220310189U;
            aOrbiterJ = RotL64((aOrbiterJ * 6742024268853509861U), 43U);
            //
            aIngress = RotL64(aOrbiterE, 48U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterD, 27U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 39U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 41U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 19U));
            aIngress = aIngress + RotL64(aOrbiterG, 46U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aCross, 5U) + RotL64(aOrbiterC, 19U)) + aOrbiterH) + aNonceWordJ);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterA, 43U)) + aOrbiterH);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 37U) + RotL64(aOrbiterA, 53U)) + aOrbiterC);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 23U) + aOrbiterI) + RotL64(aOrbiterG, 23U));
            aWandererI = aWandererI + (((RotL64(aCross, 18U) + aOrbiterG) + RotL64(aOrbiterJ, 35U)) + aNonceWordD);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 53U) + aOrbiterE) + RotL64(aOrbiterF, 14U));
            aWandererB = aWandererB + (((RotL64(aScatter, 29U) + aOrbiterA) + RotL64(aOrbiterB, 57U)) + RotL64(aCarry, 47U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 39U) + aOrbiterI) + RotL64(aOrbiterA, 41U)) + aWandererUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aIngress, 50U) + RotL64(aOrbiterK, 29U)) + aOrbiterF) + aWandererUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 27U) + RotL64(aOrbiterG, 37U)) + aOrbiterF) + aNonceWordF);
            aWandererA = aWandererA + (((RotL64(aCross, 43U) + RotL64(aOrbiterB, 26U)) + aOrbiterD) + RotL64(aCarry, 27U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 57U));
            aCarry = aCarry + (RotL64(aWandererE, 48U) ^ aWandererF);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 51U));
            aCarry = aCarry + (RotL64(aWandererK, 19U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererB, 29U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererD, 40U);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 10458U)) & S_BLOCK1], 18U) ^ RotL64(mSource[((aIndex + 10216U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 5547U)) & S_BLOCK1], 3U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 9605U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCarry, 54U) ^ RotL64(aIngress, 5U)) ^ (RotL64(aPrevious, 19U) + RotL64(aCross, 37U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterH = ((aWandererD + RotL64(aScatter, 3U)) + 16124889768301047791U) + aOrbiterAssignSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = (aWandererB + RotL64(aIngress, 51U)) + 11912338587186717280U;
            aOrbiterF = (aWandererG + RotL64(aCross, 57U)) + 8594012868813114354U;
            aOrbiterC = (aWandererF + RotL64(aPrevious, 19U)) + 18281043566156682815U;
            aOrbiterA = (aWandererK + RotL64(aScatter, 38U)) + 16853106130200942302U;
            aOrbiterD = ((((aWandererA + RotL64(aPrevious, 11U)) + RotL64(aCarry, 13U)) + 2611212958619673086U) + aOrbiterAssignSaltE[((aIndex + 24U)) & S_SALT1]) + aNonceWordI;
            aOrbiterE = (aWandererI + RotL64(aIngress, 21U)) + 18039472325066855180U;
            aOrbiterB = (((aWandererH + RotL64(aCross, 29U)) + RotL64(aCarry, 19U)) + 14495785571345122046U) + aNonceWordD;
            aOrbiterJ = ((aWandererE + RotL64(aScatter, 53U)) + 4556063793412832418U) + aNonceWordA;
            aOrbiterG = ((aWandererC + RotL64(aPrevious, 13U)) + 14896419970271244358U) + aNonceWordH;
            aOrbiterK = ((aWandererJ + RotL64(aIngress, 24U)) + RotL64(aCarry, 43U)) + 880028529183500036U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 2379557167489415783U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 11854373946064529806U) ^ aNonceWordB;
            aOrbiterF = RotL64((aOrbiterF * 150755294320438887U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 1487252775956449964U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 12777924204511625545U;
            aOrbiterD = RotL64((aOrbiterD * 1366019527386994789U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 15998631485222477969U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 8864212892296191613U;
            aOrbiterB = RotL64((aOrbiterB * 579242788050369815U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 17069347835763226743U) + aNonceWordM;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 7443008171694679791U;
            aOrbiterJ = RotL64((aOrbiterJ * 748894368884566607U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 17334256152350782002U) + aOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 8986626119086556393U) ^ aNonceWordK;
            aOrbiterE = RotL64((aOrbiterE * 2258172145924120235U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 8528180968228358674U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 12702290928064582589U;
            aOrbiterA = RotL64((aOrbiterA * 15673603224146737631U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 7742438100860023610U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 3729687240959702198U) ^ aOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 3756794766163746783U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 426129097367382096U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 16782175452274911213U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 1041477289638333659U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 5942016166948841079U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 5260815086125551703U;
            aOrbiterH = RotL64((aOrbiterH * 1603799103692438147U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 11732742583346900772U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 17182924380693084401U) ^ aNonceWordF;
            aOrbiterC = RotL64((aOrbiterC * 14858685629471497071U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 8539335803784852017U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 16124889768301047791U;
            aOrbiterK = RotL64((aOrbiterK * 6607245691919237755U), 39U);
            //
            aIngress = RotL64(aOrbiterD, 51U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterF, 29U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 27U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 53U));
            aIngress = aIngress + (RotL64(aOrbiterB, 38U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterC, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 39U) + aOrbiterB) + RotL64(aOrbiterD, 13U)) + aWandererUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aIngress, 29U) + RotL64(aOrbiterB, 47U)) + aOrbiterF) + RotL64(aCarry, 3U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 60U) + aOrbiterB) + RotL64(aOrbiterH, 19U)) + aNonceWordN);
            aWandererG = aWandererG + (((RotL64(aScatter, 19U) + aOrbiterH) + RotL64(aOrbiterA, 44U)) + aWandererUpdateSaltB[((aIndex + 29U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterI, 51U)) + aOrbiterK);
            aWandererH = aWandererH + (((RotL64(aScatter, 37U) + RotL64(aOrbiterC, 57U)) + aOrbiterJ) + RotL64(aCarry, 29U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 48U) + RotL64(aOrbiterB, 5U)) + aOrbiterE);
            aWandererC = aWandererC + ((RotL64(aCross, 11U) + aOrbiterE) + RotL64(aOrbiterH, 53U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 51U) + RotL64(aOrbiterC, 29U)) + aOrbiterK) + aNonceWordC);
            aWandererF = aWandererF + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterI, 39U)) + aOrbiterB) + aNonceWordG);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 53U) + aOrbiterC) + RotL64(aOrbiterG, 60U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 21U) ^ aWandererH);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 51U));
            aCarry = aCarry + (RotL64(aWandererA, 28U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererB, 5U) ^ aWandererF);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 57U));
            aCarry = aCarry + RotL64(aWandererK, 43U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = RotL64(aWorkLaneB[((aIndex + 11258U)) & S_BLOCK1], 39U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 15179U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(pSnow[((S_BLOCK1 - aIndex + 14966U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneA[((aIndex + 14507U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aPrevious, 11U) ^ RotL64(aCross, 51U)) + (RotL64(aCarry, 38U) ^ RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterH = ((aWandererG + RotL64(aPrevious, 51U)) + 4259993311776766595U) + aNonceWordE;
            aOrbiterF = ((aWandererB + RotL64(aCross, 30U)) + RotL64(aCarry, 41U)) + 2857813330021126753U;
            aOrbiterG = ((aWandererH + RotL64(aIngress, 11U)) + 1345396841329442896U) + aNonceWordO;
            aOrbiterA = (((aWandererJ + RotL64(aScatter, 41U)) + 320992148982301024U) + aOrbiterAssignSaltD[((aIndex + 12U)) & S_SALT1]) + aNonceWordH;
            aOrbiterB = (((aWandererF + RotL64(aPrevious, 21U)) + RotL64(aCarry, 57U)) + 5619109532065293074U) + aOrbiterAssignSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = ((aWandererE + RotL64(aIngress, 35U)) + RotL64(aCarry, 19U)) + 10380157329426706345U;
            aOrbiterD = (aWandererC + RotL64(aCross, 3U)) + 12449831150625409695U;
            aOrbiterI = (aWandererA + RotL64(aScatter, 23U)) + 7847096607042268396U;
            aOrbiterE = (aWandererI + RotL64(aPrevious, 13U)) + 11707184096803214678U;
            aOrbiterK = (aWandererK + RotL64(aIngress, 43U)) + 9893643746186827088U;
            aOrbiterC = (aWandererD + RotL64(aScatter, 54U)) + 333687403830908774U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 13837360705077441580U) + aNonceWordN;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 4367119682175710689U) ^ aOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10295744669174603401U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 1193493435041306784U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 15062951612027370606U;
            aOrbiterJ = RotL64((aOrbiterJ * 2509383510565136549U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 16000173839235429105U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 15294482444605409961U;
            aOrbiterI = RotL64((aOrbiterI * 1031800997944302665U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 5720749055549773527U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 17248674962996093668U) ^ aOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 15730637462755795591U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 16956840483882091059U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 9637715107943515594U;
            aOrbiterE = RotL64((aOrbiterE * 8878362378343603463U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 7147495779349862274U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 7508890985889484275U) ^ aNonceWordF;
            aOrbiterH = RotL64((aOrbiterH * 17728368447504622035U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 4407738164617959366U) + aNonceWordP;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 17027017782352660454U;
            aOrbiterB = RotL64((aOrbiterB * 417183060881259295U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 3174658601748235285U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 9779053567370714831U;
            aOrbiterK = RotL64((aOrbiterK * 6383245776181968033U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 16256981360027888091U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 12778335633397105924U;
            aOrbiterC = RotL64((aOrbiterC * 10821225965811763659U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 13985909343937844583U) + aOrbiterUpdateSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 14307218309393008729U;
            aOrbiterF = RotL64((aOrbiterF * 12053366452617039877U), 27U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 15549857305890093491U) + aNonceWordC;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 4259993311776766595U;
            aOrbiterD = RotL64((aOrbiterD * 13703695714360435719U), 3U);
            //
            aIngress = RotL64(aOrbiterD, 24U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 19U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 39U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 13U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 10U));
            aIngress = aIngress + RotL64(aOrbiterE, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aIngress, 37U) + aOrbiterH) + RotL64(aOrbiterA, 5U)) + aNonceWordD);
            aWandererE = aWandererE + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterB, 14U)) + aOrbiterF) + RotL64(aCarry, 51U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 52U) + aOrbiterE) + RotL64(aOrbiterG, 23U)) + aWandererUpdateSaltE[((aIndex + 28U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 21U) + aOrbiterD) + RotL64(aOrbiterH, 43U)) + aWandererUpdateSaltF[((aIndex + 14U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 41U) + aOrbiterH) + RotL64(aOrbiterF, 47U));
            aWandererK = aWandererK + (((RotL64(aScatter, 13U) + RotL64(aOrbiterK, 41U)) + aOrbiterJ) + RotL64(aCarry, 21U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 5U) + aOrbiterJ) + RotL64(aOrbiterI, 21U)) + aNonceWordM);
            aWandererH = aWandererH + ((RotL64(aIngress, 57U) + aOrbiterC) + RotL64(aOrbiterG, 57U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterF, 38U)) + aOrbiterE);
            aWandererD = aWandererD + ((RotL64(aIngress, 10U) + aOrbiterJ) + RotL64(aOrbiterE, 29U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 47U) + aOrbiterI) + RotL64(aOrbiterH, 3U)) + aNonceWordB);
            //
            aCarry = aCarry + (RotL64(aWandererG, 13U) ^ aWandererH);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 4U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 27U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 43U));
            aCarry = aCarry + RotL64(aWandererK, 50U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 21738U)) & S_BLOCK1], 42U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19810U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 20570U)) & S_BLOCK1], 47U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 21517U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 20287U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCarry, 13U) + RotL64(aIngress, 27U)) ^ (RotL64(aCross, 47U) + RotL64(aPrevious, 60U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterA = ((aWandererE + RotL64(aPrevious, 53U)) + RotL64(aCarry, 5U)) + 13204735390996728477U;
            aOrbiterE = ((aWandererG + RotL64(aScatter, 27U)) + 851171359595647173U) + aNonceWordI;
            aOrbiterJ = (aWandererF + RotL64(aCross, 24U)) + 16745304202825290723U;
            aOrbiterB = ((aWandererC + RotL64(aIngress, 41U)) + 562392736584913979U) + aOrbiterAssignSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterC = (aWandererD + RotL64(aPrevious, 47U)) + 3244267012529053918U;
            aOrbiterK = (aWandererH + RotL64(aScatter, 13U)) + 17282536111067869133U;
            aOrbiterH = ((aWandererB + RotL64(aIngress, 39U)) + RotL64(aCarry, 27U)) + 14851130066471729068U;
            aOrbiterI = (aWandererA + RotL64(aCross, 37U)) + 5256130407952363129U;
            aOrbiterD = (((aWandererI + RotL64(aScatter, 29U)) + RotL64(aCarry, 47U)) + 2904742485828362001U) + aOrbiterAssignSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = (aWandererJ + RotL64(aCross, 11U)) + 3723346325449225387U;
            aOrbiterF = ((aWandererK + RotL64(aPrevious, 60U)) + 5344621093694027341U) + aNonceWordM;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 12919263300833603026U) + aNonceWordF;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 17989801264160996071U;
            aOrbiterJ = RotL64((aOrbiterJ * 15468293047311883751U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 5022175042377172157U) + aNonceWordG;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 16684822380107847758U;
            aOrbiterK = RotL64((aOrbiterK * 2834049270263837537U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 2740326510600876682U) + aOrbiterUpdateSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 13981423865219318820U;
            aOrbiterA = RotL64((aOrbiterA * 14593082145080056441U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 231945878229848395U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 14139797734944312580U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 6492256080432266407U), 37U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 16704102101387552373U) + aNonceWordB;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 8506734780526852552U) ^ aOrbiterUpdateSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4684566118627414659U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 2774630043988894695U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 12490034334296488127U;
            aOrbiterG = RotL64((aOrbiterG * 16765455396278233145U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 545238171291436006U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 1023872898002379590U;
            aOrbiterI = RotL64((aOrbiterI * 8626333831510136515U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 5065187021047872560U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 10391809965648089863U;
            aOrbiterC = RotL64((aOrbiterC * 10912471108849550469U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 5576919045471579002U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 9761904001375034639U;
            aOrbiterH = RotL64((aOrbiterH * 8612901811320541361U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 2001472279505185946U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 11576457012366242134U;
            aOrbiterF = RotL64((aOrbiterF * 1070815118051466731U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 17713147845216099336U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 13204735390996728477U) ^ aOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 10889281795183444943U), 57U);
            //
            aIngress = RotL64(aOrbiterI, 13U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterA, 19U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterK, 26U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 57U));
            aIngress = aIngress + (RotL64(aOrbiterB, 41U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterJ, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aIngress, 41U) + aOrbiterG) + RotL64(aOrbiterE, 53U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 21U) + aOrbiterF) + RotL64(aOrbiterG, 48U));
            aWandererA = aWandererA + ((((RotL64(aPrevious, 37U) + RotL64(aOrbiterA, 3U)) + aOrbiterD) + RotL64(aCarry, 3U)) + aWandererUpdateSaltC[((aIndex + 17U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 60U) + RotL64(aOrbiterF, 21U)) + aOrbiterB);
            aWandererB = aWandererB + (((RotL64(aScatter, 57U) + aOrbiterG) + RotL64(aOrbiterJ, 27U)) + aWandererUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterB, 51U)) + aOrbiterE);
            aWandererE = aWandererE + ((RotL64(aCross, 23U) + RotL64(aOrbiterD, 13U)) + aOrbiterB);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterC, 5U)) + aOrbiterJ);
            aWandererD = aWandererD + ((((RotL64(aScatter, 6U) + aOrbiterB) + RotL64(aOrbiterK, 37U)) + RotL64(aCarry, 43U)) + aNonceWordE);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 47U) + aOrbiterI) + RotL64(aOrbiterE, 35U)) + aNonceWordO);
            aWandererH = aWandererH + ((RotL64(aPrevious, 39U) + RotL64(aOrbiterG, 60U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererI, 27U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererJ, 10U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererB, 21U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererH, 13U) ^ aWandererD);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 29U));
            aCarry = aCarry + RotL64(aWandererA, 56U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 23449U)) & S_BLOCK1], 47U) ^ RotL64(mSource[((aIndex + 24762U)) & S_BLOCK1], 38U));
            aIngress ^= (RotL64(pSnow[((aIndex + 23699U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 25727U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 25280U)) & S_BLOCK1], 54U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 22606U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCarry, 57U) ^ RotL64(aIngress, 36U)) ^ (RotL64(aPrevious, 5U) + RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterH = (aWandererB + RotL64(aPrevious, 47U)) + 785861751704720606U;
            aOrbiterG = (aWandererF + RotL64(aCross, 53U)) + 15968088718435606299U;
            aOrbiterF = (aWandererH + RotL64(aScatter, 51U)) + 1393976526590347151U;
            aOrbiterA = (((aWandererD + RotL64(aIngress, 29U)) + RotL64(aCarry, 57U)) + 17240750947292745884U) + aNonceWordO;
            aOrbiterC = ((aWandererG + RotL64(aScatter, 57U)) + RotL64(aCarry, 39U)) + 4921576136163183137U;
            aOrbiterJ = ((aWandererI + RotL64(aCross, 19U)) + RotL64(aCarry, 27U)) + 3334047873553153032U;
            aOrbiterI = (aWandererJ + RotL64(aIngress, 10U)) + 15086509978458408698U;
            aOrbiterB = ((aWandererC + RotL64(aPrevious, 21U)) + 892391205397581998U) + aOrbiterAssignSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = ((aWandererK + RotL64(aScatter, 37U)) + 2965686403183767521U) + aNonceWordE;
            aOrbiterK = ((aWandererE + RotL64(aCross, 41U)) + 14632215393655706170U) + aNonceWordH;
            aOrbiterD = ((aWandererA + RotL64(aPrevious, 26U)) + 15740589515342377322U) + aOrbiterAssignSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 11131164813943086445U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 6988080581278900960U) ^ aNonceWordK;
            aOrbiterF = RotL64((aOrbiterF * 6412189142344044255U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 16021254613117657178U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 6183615599897921154U) ^ aOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9976411093264211033U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 12533992547026652747U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 3104325358982904219U;
            aOrbiterB = RotL64((aOrbiterB * 14977348108778147265U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 3878525937957474644U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 2120435259884368445U) ^ aOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 15964718652193073177U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 14928658302694194856U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 9121310461310309348U;
            aOrbiterA = RotL64((aOrbiterA * 17304439784647477491U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 3715693239100476493U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 7336577492932262490U;
            aOrbiterD = RotL64((aOrbiterD * 11074754160002665253U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 2312452827448455675U) + aNonceWordL;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 4322756069651934618U;
            aOrbiterK = RotL64((aOrbiterK * 6908893297397073539U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 4962079617577705818U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 5072727464750706525U;
            aOrbiterJ = RotL64((aOrbiterJ * 4947670001221089155U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 4553791875259778686U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 15823770920225774233U) ^ aNonceWordN;
            aOrbiterE = RotL64((aOrbiterE * 409663191536830375U), 23U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 9468608484284459072U) + aNonceWordC;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 8658861660659699947U;
            aOrbiterH = RotL64((aOrbiterH * 2933359123761406353U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 14453429515273506170U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 785861751704720606U;
            aOrbiterG = RotL64((aOrbiterG * 3544627380583668815U), 21U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterJ, 13U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 21U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 29U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 19U));
            aIngress = aIngress + (RotL64(aOrbiterC, 57U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterF, 44U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aScatter, 37U) + aOrbiterB) + RotL64(aOrbiterJ, 5U)) + aNonceWordM);
            aWandererK = aWandererK ^ ((((RotL64(aCross, 48U) + RotL64(aOrbiterF, 53U)) + aOrbiterE) + aNonceWordP) + aWandererUpdateSaltB[((aIndex + 11U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aPrevious, 39U) + RotL64(aOrbiterD, 29U)) + aOrbiterA);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterB, 13U)) + aOrbiterD);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 41U) + aOrbiterG) + RotL64(aOrbiterI, 34U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 19U) + aOrbiterK) + RotL64(aOrbiterI, 3U));
            aWandererH = aWandererH + (((RotL64(aIngress, 13U) + aOrbiterJ) + RotL64(aOrbiterK, 51U)) + RotL64(aCarry, 37U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 58U) + aOrbiterC) + RotL64(aOrbiterJ, 37U)) + aNonceWordB);
            aWandererE = aWandererE + (((RotL64(aScatter, 53U) + aOrbiterJ) + RotL64(aOrbiterD, 58U)) + RotL64(aCarry, 23U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterH, 27U)) + aOrbiterF);
            aWandererA = aWandererA + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterH, 11U)) + aOrbiterE) + aWandererUpdateSaltA[((aIndex + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 39U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 12U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 53U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 29U));
            aCarry = aCarry + (RotL64(aWandererF, 41U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererG, 14U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 30134U)) & S_BLOCK1], 3U) ^ RotL64(pSnow[((aIndex + 30860U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 31032U)) & S_BLOCK1], 52U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 29896U)) & S_BLOCK1], 3U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 32661U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 30046U)) & S_BLOCK1], 14U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCross, 11U) ^ RotL64(aIngress, 60U)) ^ (RotL64(aPrevious, 43U) + RotL64(aCarry, 29U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterD = (aWandererC + RotL64(aPrevious, 27U)) + 15652862298542575895U;
            aOrbiterI = ((aWandererD + RotL64(aIngress, 29U)) + RotL64(aCarry, 53U)) + 16925323928418184554U;
            aOrbiterB = (aWandererG + RotL64(aCross, 41U)) + 4413861484961668394U;
            aOrbiterJ = (aWandererB + RotL64(aScatter, 60U)) + 2215946422098155969U;
            aOrbiterK = ((((aWandererJ + RotL64(aPrevious, 5U)) + RotL64(aCarry, 35U)) + 14975185533513111110U) + aOrbiterAssignSaltD[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterA = (((aWandererH + RotL64(aCross, 35U)) + RotL64(aCarry, 5U)) + 9711613814905834552U) + aOrbiterAssignSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterC = (aWandererI + RotL64(aIngress, 37U)) + 13154957291850149471U;
            aOrbiterE = (aWandererK + RotL64(aScatter, 53U)) + 5058313016418534840U;
            aOrbiterF = ((aWandererE + RotL64(aCross, 43U)) + 15011423472941211620U) + aNonceWordH;
            aOrbiterG = (aWandererF + RotL64(aScatter, 11U)) + 2030053257469580168U;
            aOrbiterH = (aWandererA + RotL64(aIngress, 14U)) + 150530795186791193U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 10878237472104183427U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 11724672539469573109U) ^ aOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 16158741837357985395U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 9589700906445846956U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 1367381624958248949U;
            aOrbiterA = RotL64((aOrbiterA * 8459515089081211977U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 12003215666757518106U) + aNonceWordD;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 11232479330848006729U;
            aOrbiterE = RotL64((aOrbiterE * 10993290955464593033U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 13013910456628561621U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 6092509838924105265U) ^ aNonceWordI;
            aOrbiterI = RotL64((aOrbiterI * 805601154718006061U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 11999225836250312801U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 14421271973875748413U;
            aOrbiterG = RotL64((aOrbiterG * 9529010940887430157U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 15536288285741825272U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 2071793889925436679U;
            aOrbiterJ = RotL64((aOrbiterJ * 1526376970151714589U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 5622386476463436967U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 16147972771639168516U) ^ aNonceWordC;
            aOrbiterD = RotL64((aOrbiterD * 11826916832825159095U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 4519892856053952290U) + aNonceWordO;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 12059500374938843538U;
            aOrbiterF = RotL64((aOrbiterF * 14987533625537956299U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 4547335128847992282U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 15378473334472216418U) ^ aOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 13907560285280544037U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 14644123269581735633U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 6434315615480805381U;
            aOrbiterC = RotL64((aOrbiterC * 4335857173941645355U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 14241680137158382296U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 15652862298542575895U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4190840063924551519U), 27U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterE, 11U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 35U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 40U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 57U));
            aIngress = aIngress + (RotL64(aOrbiterH, 43U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterD, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aScatter, 47U) + aOrbiterF) + RotL64(aOrbiterI, 37U));
            aWandererF = aWandererF + ((((RotL64(aIngress, 37U) + RotL64(aOrbiterE, 40U)) + aOrbiterK) + aNonceWordG) + aWandererUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 5U) + RotL64(aOrbiterD, 5U)) + aOrbiterJ) + aNonceWordE);
            aWandererA = aWandererA + (((RotL64(aPrevious, 12U) + RotL64(aOrbiterD, 19U)) + aOrbiterC) + RotL64(aCarry, 57U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterK, 47U)) + aOrbiterB);
            aWandererD = aWandererD + (((RotL64(aCross, 35U) + RotL64(aOrbiterC, 50U)) + aOrbiterA) + RotL64(aCarry, 43U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 19U) + aOrbiterJ) + RotL64(aOrbiterK, 57U));
            aWandererE = aWandererE + ((RotL64(aPrevious, 53U) + RotL64(aOrbiterD, 11U)) + aOrbiterG);
            aWandererK = aWandererK ^ (((RotL64(aCross, 27U) + RotL64(aOrbiterG, 27U)) + aOrbiterF) + aWandererUpdateSaltF[((aIndex + 16U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aPrevious, 60U) + aOrbiterH) + RotL64(aOrbiterG, 29U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterI, 43U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 4U) ^ aWandererG);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 11U));
            aCarry = aCarry + (RotL64(aWandererF, 39U) ^ aWandererB);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 51U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 37U));
            aCarry = aCarry + RotL64(aWandererK, 26U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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

void TwistExpander_BasketBall_Arx::KDF_A_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xFEDF2F1C0F063E2BULL + 0x81D2309C69AC6C51ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xF1C4948940783FFFULL + 0xE2FCA555ED4ED8A9ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x8449C70857B0731DULL + 0x865EC3E033CA6663ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xAF60DE25D4EAC997ULL + 0xE42514A6E73BADAAULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xB994CFC90F877D4DULL + 0xBD4C2F3AF8973E46ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xA4C35EBCDCDBEC31ULL + 0xE98D36A898C224BDULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x91EB7955300A94EBULL + 0x81569B7E4D3708EDULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xC2CF037DC84288EFULL + 0x9E38CF001682216EULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x85E6DB7579A67317ULL + 0x80CA4F313C3101C0ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0x805684D294552DAFULL + 0x9731C93A38ACE6F4ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xF4C95A418E6EA3A7ULL + 0x9F99897810CEFDEDULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x8EB5B0FD295B3F2BULL + 0xB0EB8836F3B5470FULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xCBF9AD68B1341A69ULL + 0xA5CB8ACEC534F6BCULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0x954B1747349E4E7BULL + 0xEC0CD1E7E798674CULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xBBA87638F2455841ULL + 0x964A8C22AF3B78F5ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xBEA889B4ADC4A9E3ULL + 0x95FF8647EED89617ULL);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 1477U)) & S_BLOCK1], 53U) ^ RotL64(aFireLaneB[((aIndex + 306U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 6119U)) & S_BLOCK1], 46U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 3154U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aPrevious, 54U) ^ RotL64(aCarry, 23U)) ^ (RotL64(aIngress, 39U) + RotL64(aCross, 11U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterE = (((aWandererA + RotL64(aIngress, 47U)) + RotL64(aCarry, 35U)) + 8375305456876489425U) + aOrbiterAssignSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = (aWandererB + RotL64(aPrevious, 19U)) + 16193562952772453047U;
            aOrbiterC = (((aWandererI + RotL64(aCross, 56U)) + RotL64(aCarry, 5U)) + 18088652458594816223U) + aOrbiterAssignSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = (((aWandererG + RotL64(aScatter, 5U)) + RotL64(aCarry, 53U)) + 767344788620249944U) + aNonceWordC;
            aOrbiterB = (aWandererJ + RotL64(aCross, 35U)) + 7705194930396368752U;
            aOrbiterJ = (aWandererF + RotL64(aPrevious, 23U)) + 3829736891311272834U;
            aOrbiterF = ((aWandererK + RotL64(aScatter, 52U)) + 9881681671347640061U) + aNonceWordF;
            aOrbiterG = (aWandererE + RotL64(aIngress, 11U)) + 1721196560190164264U;
            aOrbiterK = ((aWandererH + RotL64(aPrevious, 41U)) + 3002652618388454213U) + aNonceWordA;
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 9811621464004005202U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 5652598941069986530U;
            aOrbiterC = RotL64((aOrbiterC * 4797973356708091621U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 6250499348327316328U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterI) ^ 16025054277615264530U) ^ aOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterJ = RotL64((aOrbiterJ * 16446892258704281903U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 13800298546867243172U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 12256104592865905782U;
            aOrbiterF = RotL64((aOrbiterF * 16983140179497142713U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 17817225416918329229U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 17738671327352776217U;
            aOrbiterD = RotL64((aOrbiterD * 393488251327705063U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 6816031224188400541U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 16989563985059237014U) ^ aNonceWordH;
            aOrbiterI = RotL64((aOrbiterI * 8677884225771717797U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 16891524847268207549U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 1833508573940405571U) ^ aOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 9709196587703979539U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 12729999421507068973U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 6839758643521968957U;
            aOrbiterG = RotL64((aOrbiterG * 16350557395881283975U), 39U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterF) + 8524167125469267428U) + aOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1]) + aNonceWordK;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 14741523560290472617U;
            aOrbiterE = RotL64((aOrbiterE * 4367850822282205897U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 10983798459868424892U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 5649250846622078964U) ^ aNonceWordJ;
            aOrbiterB = RotL64((aOrbiterB * 7149612714806023987U), 43U);
            //
            aIngress = RotL64(aOrbiterG, 14U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterK, 27U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 41U));
            aIngress = aIngress + (RotL64(aOrbiterC, 57U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterB, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aIngress, 23U) + aOrbiterE) + RotL64(aOrbiterI, 30U)) + aNonceWordE);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 27U) + aOrbiterI) + RotL64(aOrbiterC, 43U)) + RotL64(aCarry, 23U)) + aWandererUpdateSaltE[((aIndex + 26U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 56U) + RotL64(aOrbiterB, 53U)) + aOrbiterJ);
            aWandererI = aWandererI + ((RotL64(aScatter, 19U) + RotL64(aOrbiterJ, 47U)) + aOrbiterF);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 13U) + aOrbiterI) + RotL64(aOrbiterF, 11U)) + aWandererUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 3U) + aOrbiterK) + RotL64(aOrbiterB, 60U)) + aNonceWordN);
            aWandererK = aWandererK ^ ((RotL64(aCross, 48U) + aOrbiterI) + RotL64(aOrbiterB, 21U));
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 35U) + RotL64(aOrbiterI, 39U)) + aOrbiterD) + RotL64(aCarry, 37U)) + aNonceWordL);
            aWandererA = aWandererA ^ ((RotL64(aCross, 43U) + aOrbiterG) + RotL64(aOrbiterC, 3U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 57U));
            aCarry = aCarry + (RotL64(aWandererF, 35U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererA, 4U) ^ aWandererJ);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 11U));
            aCarry = aCarry + RotL64(aWandererK, 19U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 8244U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneB[((aIndex + 12056U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 10462U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 11905U)) & S_BLOCK1], 39U) ^ RotL64(aFireLaneD[((aIndex + 16131U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aPrevious, 3U) + RotL64(aCarry, 39U)) ^ (RotL64(aIngress, 21U) ^ RotL64(aCross, 54U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterB = (((aWandererB + RotL64(aCross, 37U)) + RotL64(aCarry, 27U)) + 4068921616130916949U) + aOrbiterAssignSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterD = ((aWandererD + RotL64(aIngress, 60U)) + 12077715273915151726U) + aNonceWordN;
            aOrbiterI = (aWandererA + RotL64(aPrevious, 27U)) + 16047546802670596833U;
            aOrbiterG = ((aWandererC + RotL64(aScatter, 11U)) + 9690277462716999763U) + aNonceWordL;
            aOrbiterK = ((aWandererI + RotL64(aIngress, 3U)) + RotL64(aCarry, 51U)) + 14484814700447992628U;
            aOrbiterC = (aWandererK + RotL64(aCross, 54U)) + 17089267243053958210U;
            aOrbiterH = (((aWandererJ + RotL64(aPrevious, 41U)) + RotL64(aCarry, 13U)) + 9138746214446211147U) + aOrbiterAssignSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = (aWandererG + RotL64(aScatter, 19U)) + 10181001536979097045U;
            aOrbiterF = (aWandererE + RotL64(aIngress, 23U)) + 6657458969093373191U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 7515983477876590988U) + aNonceWordA;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 3039935555863947600U;
            aOrbiterI = RotL64((aOrbiterI * 12511160550780270119U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 16209389224740851136U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 725253312098083182U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 17535989492095522597U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 13307041115748941383U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 7159572004825238263U;
            aOrbiterH = RotL64((aOrbiterH * 4855009895002398449U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 12027236743251643820U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 8717826175991286553U) ^ aNonceWordD;
            aOrbiterC = RotL64((aOrbiterC * 1175614802543098451U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 4769096034227659937U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 11201226563992939616U;
            aOrbiterB = RotL64((aOrbiterB * 15595355978388159931U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 17295978531215563256U) + aOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 11850923890626719833U;
            aOrbiterK = RotL64((aOrbiterK * 3854851059897397075U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 14139441565288097706U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 988684899382304485U;
            aOrbiterA = RotL64((aOrbiterA * 11929090869999700891U), 3U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterF) + 6159251276942253175U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordC;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 4849529993914550651U;
            aOrbiterG = RotL64((aOrbiterG * 18240712676783671317U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 6679745455842119497U) + aNonceWordB;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 15838404437552215214U) ^ aOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 17357853511591350887U), 13U);
            //
            aIngress = RotL64(aOrbiterK, 37U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterD, 43U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterG, 54U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterB, 23U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterA, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 22U) + aOrbiterB) + RotL64(aOrbiterI, 57U));
            aWandererA = aWandererA + ((((RotL64(aScatter, 5U) + RotL64(aOrbiterB, 42U)) + aOrbiterA) + RotL64(aCarry, 57U)) + aNonceWordK);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 43U) + aOrbiterF) + RotL64(aOrbiterA, 37U));
            aWandererD = aWandererD + (((((RotL64(aIngress, 39U) + aOrbiterB) + RotL64(aOrbiterC, 11U)) + RotL64(aCarry, 37U)) + aNonceWordG) + aWandererUpdateSaltC[((aIndex + 22U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aCross, 47U) + aOrbiterC) + RotL64(aOrbiterD, 21U)) + aNonceWordF);
            aWandererK = aWandererK + ((RotL64(aScatter, 57U) + aOrbiterC) + RotL64(aOrbiterI, 47U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterG, 29U)) + aOrbiterK);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 30U) + aOrbiterH) + RotL64(aOrbiterC, 3U)) + aNonceWordO) + aWandererUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterI, 52U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 13U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 29U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 35U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 40U));
            aCarry = aCarry + RotL64(aWandererC, 47U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 16756U)) & S_BLOCK1], 13U) ^ RotL64(aFireLaneD[((aIndex + 22086U)) & S_BLOCK1], 36U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 23520U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 20649U)) & S_BLOCK1], 54U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 22888U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 21791U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCross, 56U)) + (RotL64(aPrevious, 43U) ^ RotL64(aCarry, 19U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterE = (aWandererC + RotL64(aIngress, 29U)) + 17912271996338180948U;
            aOrbiterI = (aWandererB + RotL64(aCross, 11U)) + 13259276608841847058U;
            aOrbiterF = ((aWandererH + RotL64(aScatter, 48U)) + 16225936008657276089U) + aOrbiterAssignSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = ((aWandererF + RotL64(aPrevious, 43U)) + RotL64(aCarry, 47U)) + 2243058962151834071U;
            aOrbiterJ = (((aWandererJ + RotL64(aScatter, 39U)) + RotL64(aCarry, 3U)) + 10637439274127347861U) + aNonceWordB;
            aOrbiterC = (aWandererD + RotL64(aPrevious, 5U)) + 15312219216405992627U;
            aOrbiterG = (aWandererE + RotL64(aCross, 57U)) + 2393933972129878613U;
            aOrbiterA = ((aWandererA + RotL64(aIngress, 35U)) + RotL64(aCarry, 35U)) + 4327069337247976513U;
            aOrbiterH = (((aWandererK + RotL64(aPrevious, 20U)) + 8307656353434167837U) + aOrbiterAssignSaltC[((aIndex + 20U)) & S_SALT1]) + aNonceWordN;
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 17299145556933889336U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 14458100581172798164U) ^ aNonceWordP;
            aOrbiterF = RotL64((aOrbiterF * 16543734663677070509U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 6410095654927998067U) + aNonceWordL;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 6168964796264687686U) ^ aOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 16218071040190475953U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 3667999465041020730U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 16021552859323602007U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 6427266472526362663U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 12941668202330045095U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 4222032891850449934U;
            aOrbiterA = RotL64((aOrbiterA * 17292856787431308097U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 1346342592002730785U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 16860611785008118820U;
            aOrbiterI = RotL64((aOrbiterI * 384963420804756607U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 3193572711804730241U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 5866881282680588589U;
            aOrbiterD = RotL64((aOrbiterD * 9226331800853634597U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 17180332731328479126U) + aOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 10222097519535882241U;
            aOrbiterE = RotL64((aOrbiterE * 9422887302872778795U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 8863502179821584859U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterJ) ^ 14872318155712512999U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterC = RotL64((aOrbiterC * 11830641277356873233U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 16478790641892781150U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 8414944141232294781U;
            aOrbiterH = RotL64((aOrbiterH * 17443775794621154023U), 47U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterC, 29U);
            aIngress = aIngress + (RotL64(aOrbiterE, 56U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterD, 11U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterH, 35U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterA, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aIngress, 6U) + RotL64(aOrbiterG, 18U)) + aOrbiterH) + RotL64(aCarry, 53U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 43U) + aOrbiterE) + RotL64(aOrbiterF, 47U));
            aWandererD = aWandererD + ((RotL64(aScatter, 51U) + aOrbiterC) + RotL64(aOrbiterF, 53U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterH, 41U)) + aOrbiterE);
            aWandererC = aWandererC + (((RotL64(aIngress, 35U) + aOrbiterI) + RotL64(aOrbiterE, 14U)) + aWandererUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 18U) + aOrbiterC) + RotL64(aOrbiterJ, 3U));
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 27U) + aOrbiterH) + RotL64(aOrbiterA, 23U)) + RotL64(aCarry, 5U)) + aNonceWordK);
            aWandererF = aWandererF ^ (((RotL64(aCross, 47U) + aOrbiterF) + RotL64(aOrbiterD, 57U)) + aWandererUpdateSaltB[((aIndex + 18U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 23U) + RotL64(aOrbiterI, 29U)) + aOrbiterH) + aNonceWordF);
            //
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererF, 54U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererJ, 5U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererD, 43U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererK, 57U);
            aCarry = aCarry + RotL64(aIngress, 30U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 28530U)) & S_BLOCK1], 34U) ^ RotL64(aFireLaneC[((aIndex + 32014U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 24957U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31867U)) & S_BLOCK1], 43U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 28767U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 26369U)) & S_BLOCK1], 6U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCarry, 36U) + RotL64(aIngress, 5U)) + (RotL64(aPrevious, 19U) ^ RotL64(aCross, 51U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterJ = ((aWandererI + RotL64(aPrevious, 18U)) + 15045917390223766480U) + aOrbiterAssignSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = (aWandererB + RotL64(aScatter, 41U)) + 10763054007033668758U;
            aOrbiterC = ((aWandererC + RotL64(aIngress, 23U)) + RotL64(aCarry, 35U)) + 13190170142593666607U;
            aOrbiterK = ((aWandererF + RotL64(aCross, 29U)) + RotL64(aCarry, 27U)) + 9657025731441167065U;
            aOrbiterG = (((aWandererE + RotL64(aScatter, 35U)) + RotL64(aCarry, 51U)) + 11433367178975954211U) + aNonceWordC;
            aOrbiterE = ((aWandererJ + RotL64(aIngress, 57U)) + 17904920143996810366U) + aNonceWordA;
            aOrbiterH = (aWandererH + RotL64(aCross, 6U)) + 3244383020512113283U;
            aOrbiterA = (((aWandererG + RotL64(aPrevious, 13U)) + 6538815775171139091U) + aOrbiterAssignSaltE[((aIndex + 20U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterF = (aWandererA + RotL64(aIngress, 51U)) + 7195368312757976343U;
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterI) + 18134430713910279374U) + aOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1]) + aNonceWordP;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 6571776588427107976U;
            aOrbiterC = RotL64((aOrbiterC * 11916502085252589161U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 11830778129647517758U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 9793702760907767365U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 4096246227968677179U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 2287235876793192036U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 8951959188326141794U;
            aOrbiterJ = RotL64((aOrbiterJ * 9968356718110753845U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 7583061790273240157U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 3571364625022806085U;
            aOrbiterA = RotL64((aOrbiterA * 6238360922735480669U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 13869345563551689212U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 277480328952975002U;
            aOrbiterE = RotL64((aOrbiterE * 1057564597096163085U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 4983735092494677578U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterF) ^ 9490022869381030928U) ^ aOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterH = RotL64((aOrbiterH * 12926352917961703123U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 7928039573014765566U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 6504190875809407084U;
            aOrbiterK = RotL64((aOrbiterK * 14648214826494826711U), 39U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 2787985600176307413U) + aNonceWordF;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 16308785053443116826U;
            aOrbiterI = RotL64((aOrbiterI * 17867565986311256691U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 12788128335006767824U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 1187040019537798339U;
            aOrbiterF = RotL64((aOrbiterF * 10834905007658184183U), 51U);
            //
            aIngress = RotL64(aOrbiterK, 53U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterG, 36U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 29U));
            aIngress = aIngress + (RotL64(aOrbiterF, 3U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterJ, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterJ, 19U)) + aOrbiterE);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 27U) + aOrbiterA) + RotL64(aOrbiterH, 30U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 10U) + aOrbiterE) + RotL64(aOrbiterK, 47U));
            aWandererH = aWandererH + ((((RotL64(aScatter, 53U) + RotL64(aOrbiterH, 43U)) + aOrbiterG) + RotL64(aCarry, 47U)) + aNonceWordE);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterK, 3U)) + aOrbiterI) + aWandererUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aCross, 43U) + RotL64(aOrbiterC, 11U)) + aOrbiterJ) + RotL64(aCarry, 19U)) + aWandererUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterH, 57U)) + aOrbiterC);
            aWandererI = aWandererI + ((RotL64(aPrevious, 19U) + RotL64(aOrbiterJ, 53U)) + aOrbiterA);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 38U) + aOrbiterC) + RotL64(aOrbiterF, 36U)) + aNonceWordI);
            //
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererE);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 53U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 41U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 26U));
            aCarry = aCarry + RotL64(aWandererA, 57U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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

void TwistExpander_BasketBall_Arx::KDF_A_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xA0AA92A2CDC03419ULL + 0xFDD9A29D10DFBFF4ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xB4D6BB89D4C6732FULL + 0xFC153848C7CC7692ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xED3D2D8636F93421ULL + 0xE58894946926CD22ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xA3E1248344AC141FULL + 0xDA66A89993DB56B7ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xC65889AB440C8977ULL + 0xEE02F798FEB21F86ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xA45AB7F11B283B23ULL + 0xD88AF708CFA609ADULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xCB9F358CF32379A7ULL + 0xDCD4223B0710A74EULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xC255DC724E94BD95ULL + 0xC5884536611EA862ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xC781E4AE203A1083ULL + 0xE7E678AF946FF2A2ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xA9EF69E1E784F853ULL + 0x87BD7A1125A28DCCULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xC74487FC3C3B8EFDULL + 0x87FAC06401C74157ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xBDB6710A696D4733ULL + 0x9D1285A56B8DE85CULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x9010EE6131A204F9ULL + 0xFE15DECD3274FDD6ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x9EEEFA8541999FE3ULL + 0x9C2D23194D131F32ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xED71975DCF70AFE3ULL + 0xD25AD9717B6DA2F9ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xCAC05D755EB3AFCFULL + 0xD3CB4AF2319A81B4ULL);
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
        // read from: aOperationLaneA, aOperationLaneB, aFireLaneD, aOperationLaneC, aOperationLaneD, aWorkLaneA, aFireLaneB, aWorkLaneB, aFireLaneA, aWorkLaneC, aFireLaneC
        // write to: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // kdf_a_loop_c loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aFireLaneD
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aFireLaneD forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 8006U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneB[((aIndex + 4243U)) & S_BLOCK1], 56U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 6958U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 6929U)) & S_BLOCK1], 58U) ^ RotL64(aOperationLaneD[((aIndex + 5258U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCarry, 3U) ^ RotL64(aPrevious, 35U)) + (RotL64(aCross, 21U) ^ RotL64(aIngress, 54U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterH = ((((aWandererD + RotL64(aIngress, 35U)) + RotL64(aCarry, 5U)) + 3448371607470865612U) + aOrbiterAssignSaltC[((aIndex + 25U)) & S_SALT1]) + aNonceWordI;
            aOrbiterA = (((aWandererI + RotL64(aCross, 11U)) + 3743742913651580573U) + aOrbiterAssignSaltB[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordD;
            aOrbiterE = ((aWandererG + RotL64(aScatter, 56U)) + RotL64(aCarry, 21U)) + 13069491287948807280U;
            aOrbiterI = ((aWandererK + RotL64(aPrevious, 23U)) + 16872779275586545632U) + aNonceWordJ;
            aOrbiterC = (((aWandererA + RotL64(aCross, 3U)) + RotL64(aCarry, 47U)) + 17945792656755062795U) + aNonceWordH;
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 18199747196793731853U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 15953311878379809513U;
            aOrbiterE = RotL64((aOrbiterE * 5476802169152352897U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 941268763494588338U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterI) ^ 10090221530365796809U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterH = RotL64((aOrbiterH * 14035236086292997613U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 8335698093307607001U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 6147498804734306100U) ^ aOrbiterUpdateSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 6904444049941211327U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 5980246079567570090U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 4152167624425912978U;
            aOrbiterC = RotL64((aOrbiterC * 10019421651535123573U), 13U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterH) + 14990418790239735916U) + aOrbiterUpdateSaltA[((aIndex + 6U)) & S_SALT1]) + aNonceWordG;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 3418668387496597219U) ^ aOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12814077238529863119U), 57U);
            //
            aIngress = RotL64(aOrbiterE, 3U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterA, 51U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterI, 40U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((((RotL64(aIngress, 13U) + aOrbiterA) + RotL64(aOrbiterI, 13U)) + aNonceWordP) + aWandererUpdateSaltB[((aIndex + 19U)) & S_SALT1]);
            aWandererK = aWandererK + (((((RotL64(aCross, 35U) + aOrbiterH) + RotL64(aOrbiterE, 4U)) + RotL64(aCarry, 39U)) + aNonceWordL) + aWandererUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterI, 27U)) + aOrbiterH);
            aWandererI = aWandererI + (((RotL64(aPrevious, 5U) + aOrbiterA) + RotL64(aOrbiterC, 37U)) + RotL64(aCarry, 21U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 26U) + RotL64(aOrbiterC, 47U)) + aOrbiterE) + aNonceWordC);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 39U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 14U));
            aCarry = aCarry + RotL64(aWandererI, 57U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 15633U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneC[((aIndex + 12702U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 11502U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 10245U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 9994U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 14907U)) & S_BLOCK1], 52U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCarry, 51U) ^ RotL64(aIngress, 4U)) + (RotL64(aPrevious, 39U) ^ RotL64(aCross, 19U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterB = (((aWandererA + RotL64(aScatter, 47U)) + RotL64(aCarry, 57U)) + 14008824488073394623U) + aOrbiterAssignSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = (((aWandererB + RotL64(aPrevious, 3U)) + RotL64(aCarry, 21U)) + 13317978415866411468U) + aOrbiterAssignSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = (((aWandererE + RotL64(aIngress, 39U)) + RotL64(aCarry, 37U)) + 13209180141897453900U) + aNonceWordM;
            aOrbiterF = (aWandererF + RotL64(aCross, 14U)) + 11870521586865233578U;
            aOrbiterH = ((aWandererI + RotL64(aPrevious, 57U)) + 8052156380448047385U) + aNonceWordJ;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 12158131176743680605U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 14674467487607719347U) ^ aNonceWordG;
            aOrbiterC = RotL64((aOrbiterC * 18372548574199176503U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 18055496790566231147U) + aOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 3838105585041578784U;
            aOrbiterK = RotL64((aOrbiterK * 1075709247574580091U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 2839568255183054418U) + aNonceWordO;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 11933612922864258179U) ^ aOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 7571964469321160347U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 6289849094151630580U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 2640344350528492271U) ^ aNonceWordK;
            aOrbiterF = RotL64((aOrbiterF * 16197726750829369365U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 16306175266267657791U) + aOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 3339898380394883600U;
            aOrbiterH = RotL64((aOrbiterH * 7105436590182982373U), 57U);
            //
            aIngress = RotL64(aOrbiterK, 23U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterC, 43U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterH, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 29U) + aOrbiterB) + RotL64(aOrbiterK, 41U)) + aNonceWordP);
            aWandererB = aWandererB + (((RotL64(aScatter, 50U) + aOrbiterF) + RotL64(aOrbiterB, 27U)) + RotL64(aCarry, 23U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 3U) + aOrbiterC) + RotL64(aOrbiterF, 11U)) + aWandererUpdateSaltD[((aIndex + 22U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aIngress, 39U) + RotL64(aOrbiterC, 60U)) + aOrbiterH) + RotL64(aCarry, 11U));
            aWandererI = aWandererI ^ ((((RotL64(aCross, 11U) + aOrbiterB) + RotL64(aOrbiterC, 51U)) + aNonceWordD) + aWandererUpdateSaltF[((aIndex + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 43U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererF, 3U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererE, 11U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 21846U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneD[((aIndex + 18611U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 20531U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22098U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 16889U)) & S_BLOCK1], 30U));
            aCross ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 19391U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCross, 26U) ^ RotL64(aIngress, 5U)) + (RotL64(aCarry, 51U) + RotL64(aPrevious, 39U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterH = (aWandererC + RotL64(aPrevious, 3U)) + 10336802574069791273U;
            aOrbiterG = (((aWandererJ + RotL64(aScatter, 18U)) + 169025388197058936U) + aOrbiterAssignSaltA[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordC;
            aOrbiterC = ((aWandererA + RotL64(aIngress, 51U)) + RotL64(aCarry, 13U)) + 6541354188379168846U;
            aOrbiterF = ((((aWandererB + RotL64(aCross, 43U)) + RotL64(aCarry, 41U)) + 16223920526599306104U) + aOrbiterAssignSaltE[((aIndex + 6U)) & S_SALT1]) + aNonceWordM;
            aOrbiterJ = ((aWandererG + RotL64(aScatter, 35U)) + RotL64(aCarry, 53U)) + 12756613707692514808U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 5082475548176484035U) + aNonceWordH;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 4907435526952698526U;
            aOrbiterC = RotL64((aOrbiterC * 1379692095754989215U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 14236627073831834337U) + aOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 11502511046130497584U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 3460330807286625917U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 3679044835550219497U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 11254838916686736746U;
            aOrbiterF = RotL64((aOrbiterF * 8631695922983532915U), 39U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 10582608424233200966U) + aOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 10449735026385340313U) ^ aNonceWordG;
            aOrbiterH = RotL64((aOrbiterH * 7363770199734997411U), 47U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterC) + 4628253464169957835U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1]) + aNonceWordF;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 17664454668473204465U;
            aOrbiterJ = RotL64((aOrbiterJ * 4234720298731378527U), 19U);
            //
            aIngress = RotL64(aOrbiterF, 51U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterG, 29U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterH, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterH, 23U)) + aOrbiterF) + aNonceWordA);
            aWandererJ = aWandererJ + (((((RotL64(aPrevious, 22U) + RotL64(aOrbiterJ, 35U)) + aOrbiterH) + RotL64(aCarry, 5U)) + aNonceWordL) + aWandererUpdateSaltE[((aIndex + 27U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterJ, 13U)) + aOrbiterF);
            aWandererG = aWandererG + ((((RotL64(aScatter, 53U) + aOrbiterG) + RotL64(aOrbiterC, 4U)) + RotL64(aCarry, 19U)) + aNonceWordB);
            aWandererA = aWandererA ^ ((((RotL64(aIngress, 3U) + aOrbiterG) + RotL64(aOrbiterH, 51U)) + aNonceWordJ) + aWandererUpdateSaltA[((aIndex + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 13U));
            aCarry = aCarry + RotL64(aWandererG, 3U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 27274U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneA[((aIndex + 27245U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 26192U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 32745U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 30608U)) & S_BLOCK1], 53U));
            aCross ^= (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 30146U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneA[((aIndex + 26236U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCarry, 57U) + RotL64(aPrevious, 20U)) + (RotL64(aIngress, 5U) ^ RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterG = ((aWandererJ + RotL64(aIngress, 19U)) + 5088525177670191619U) + aNonceWordA;
            aOrbiterD = ((((aWandererF + RotL64(aPrevious, 47U)) + RotL64(aCarry, 57U)) + 9966456257813932112U) + aOrbiterAssignSaltB[((aIndex + 23U)) & S_SALT1]) + aNonceWordF;
            aOrbiterH = (((aWandererH + RotL64(aScatter, 10U)) + RotL64(aCarry, 29U)) + 7707646574027146307U) + aNonceWordB;
            aOrbiterE = (((aWandererA + RotL64(aCross, 57U)) + RotL64(aCarry, 11U)) + 75480203757681173U) + aOrbiterAssignSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterI = ((aWandererC + RotL64(aPrevious, 27U)) + 384659134071835163U) + aNonceWordI;
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 3158769775373307778U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 17360830943513941272U;
            aOrbiterH = RotL64((aOrbiterH * 9986023786908098621U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 5317278822721604586U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 1371427105215954781U;
            aOrbiterE = RotL64((aOrbiterE * 10956603063464438611U), 39U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 3162710551223553423U) + aNonceWordO;
            aOrbiterI = (((aOrbiterI ^ aOrbiterH) ^ 5332921933853550756U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterI = RotL64((aOrbiterI * 11709546145149357887U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 10572462410297815854U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 10234389605554817892U) ^ aOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2130374833440291193U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 13421365517991380605U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 10186643614984034083U;
            aOrbiterG = RotL64((aOrbiterG * 8554471709467808453U), 51U);
            //
            aIngress = RotL64(aOrbiterG, 42U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 5U));
            aIngress = aIngress + RotL64(aOrbiterI, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 51U) + RotL64(aOrbiterH, 35U)) + aOrbiterI) + aNonceWordP);
            aWandererF = aWandererF + ((((RotL64(aCross, 23U) + RotL64(aOrbiterE, 6U)) + aOrbiterI) + RotL64(aCarry, 53U)) + aWandererUpdateSaltC[((aIndex + 24U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterI, 53U)) + aOrbiterG);
            aWandererH = aWandererH + ((((RotL64(aScatter, 14U) + RotL64(aOrbiterD, 43U)) + aOrbiterH) + RotL64(aCarry, 21U)) + aNonceWordN);
            aWandererA = aWandererA ^ (((RotL64(aCross, 3U) + aOrbiterE) + RotL64(aOrbiterH, 23U)) + aWandererUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 20U) ^ aWandererA);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 57U));
            aCarry = aCarry + RotL64(aWandererC, 39U);
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

void TwistExpander_BasketBall_Arx::KDF_A_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xA6E33F9EBB5721EDULL + 0xC45A81ADD2E292B1ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xA2FECDF341F2B0ADULL + 0xC043DAFE1403B912ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xB783139410526631ULL + 0xB838FB9DCDA013D4ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x89166519F19A5D2FULL + 0xD16F4F80113F7ABCULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xA701ED1CBB9E9EF5ULL + 0xBDA06DD051253A63ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x849EAFB542A29E55ULL + 0xF1DF44A584C8A936ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xEEF6E946BDADC703ULL + 0xB206F2D42C60C666ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xCFCA299D51CF1B85ULL + 0x89ECC81BE204FAB6ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xCC4057B144F69565ULL + 0xF2A4FB62B7FAA7F9ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xA6947C4C6896485BULL + 0xE875171F99F4C1D5ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xD9A4B42C0011105DULL + 0xBBFABB666B4F0ABBULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xAC880A077809C35BULL + 0x9AF85F45070D9863ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xBA8FD570EDAE9E1BULL + 0xE51A3D35781F5702ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xE5C0F06958E7E755ULL + 0xABF621261B4CC4FEULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xBA541BA449E45573ULL + 0xE7553049B52AD5ABULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xAEFC642C034CDF61ULL + 0xF4524AB4E7FF31ADULL);
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
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneD, aExpandLaneC, aExpandLaneD, aFireLaneB, aWorkLaneA, aFireLaneC, aOperationLaneA, aWorkLaneB, aOperationLaneD, aOperationLaneB, aWorkLaneC, aOperationLaneC, aFireLaneA
        // write to: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // kdf_a_loop_d loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aFireLaneD
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aFireLaneD forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD, aFireLaneB
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward forced, aFireLaneB backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 5328U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneB[((aIndex + 1473U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 7925U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4698U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 3067U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 891U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCarry, 27U) + RotL64(aPrevious, 6U)) + (RotL64(aIngress, 57U) ^ RotL64(aCross, 43U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterF = ((aWandererJ + RotL64(aScatter, 26U)) + RotL64(aCarry, 43U)) + 18191288703716505885U;
            aOrbiterB = ((aWandererF + RotL64(aPrevious, 57U)) + 9824014524910417136U) + aOrbiterAssignSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterE = (((aWandererA + RotL64(aIngress, 11U)) + RotL64(aCarry, 5U)) + 11953012029254917548U) + aNonceWordN;
            aOrbiterK = (aWandererC + RotL64(aCross, 41U)) + 6297568011027199089U;
            aOrbiterC = (((aWandererH + RotL64(aPrevious, 3U)) + RotL64(aCarry, 21U)) + 2576999400457367975U) + aOrbiterAssignSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = (aWandererI + RotL64(aScatter, 47U)) + 13176139160575558254U;
            aOrbiterI = ((aWandererD + RotL64(aCross, 35U)) + 9978408174563621810U) + aNonceWordA;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 16765834875061607142U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 16534507305459121344U) ^ aNonceWordJ;
            aOrbiterE = RotL64((aOrbiterE * 8943988574248229067U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 3114710944346151807U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 10240517868726718592U) ^ aOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4645691562915606463U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 10721450637990777883U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 16689590768796583952U) ^ aOrbiterUpdateSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 3046344179729901637U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 2427422768928450209U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 13495584061816457831U;
            aOrbiterF = RotL64((aOrbiterF * 6670984773768885119U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 7058636403765106682U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 9897341853944713767U) ^ aNonceWordB;
            aOrbiterI = RotL64((aOrbiterI * 14286816859999869231U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 17749559755733386064U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 12515645083926326659U) ^ aOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 6582878478865838245U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 2625692458813609962U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 10596240255026143019U;
            aOrbiterA = RotL64((aOrbiterA * 11605800195771080135U), 29U);
            //
            aIngress = RotL64(aOrbiterB, 13U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 57U));
            aIngress = aIngress + (RotL64(aOrbiterI, 5U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterK, 50U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aCross, 11U) + aOrbiterK) + RotL64(aOrbiterE, 23U)) + aNonceWordI);
            aWandererI = aWandererI + (((RotL64(aPrevious, 41U) + RotL64(aOrbiterA, 56U)) + aOrbiterB) + RotL64(aCarry, 23U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterE, 5U)) + aOrbiterC);
            aWandererD = aWandererD + (((RotL64(aScatter, 60U) + aOrbiterI) + RotL64(aOrbiterB, 47U)) + RotL64(aCarry, 51U));
            aWandererA = aWandererA ^ ((((RotL64(aCross, 23U) + aOrbiterE) + RotL64(aOrbiterF, 29U)) + aNonceWordF) + aWandererUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aIngress, 47U) + aOrbiterF) + RotL64(aOrbiterK, 35U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 29U) + aOrbiterI) + RotL64(aOrbiterA, 11U)) + aWandererUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 4U) ^ aWandererC);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 39U));
            aCarry = aCarry + (RotL64(aWandererH, 19U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererF, 27U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 2
        // ingress from: aWorkLaneA, aExpandLaneC, aFireLaneC
        // ingress directions: aWorkLaneA forward forced, aExpandLaneC forward forced, aFireLaneC forward/backward random
        // cross from: aExpandLaneA, aExpandLaneD, aOperationLaneA
        // cross directions: aExpandLaneA backward forced, aExpandLaneD backward forced, aOperationLaneA backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 12086U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneC[((aIndex + 11462U)) & S_BLOCK1], 36U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 14603U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 9787U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 11994U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 14783U)) & S_BLOCK1], 6U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aPrevious, 24U) + RotL64(aCarry, 43U)) + (RotL64(aCross, 57U) ^ RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterI = (((aWandererD + RotL64(aPrevious, 37U)) + RotL64(aCarry, 19U)) + 252059974543142812U) + aOrbiterAssignSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterC = ((aWandererF + RotL64(aIngress, 19U)) + RotL64(aCarry, 37U)) + 11690823093681457368U;
            aOrbiterD = (((aWandererE + RotL64(aCross, 13U)) + RotL64(aCarry, 3U)) + 13282189752890971123U) + aNonceWordI;
            aOrbiterG = (aWandererH + RotL64(aScatter, 29U)) + 9507416294305708435U;
            aOrbiterJ = ((aWandererC + RotL64(aPrevious, 47U)) + 14053038174390776539U) + aOrbiterAssignSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterK = ((aWandererI + RotL64(aIngress, 3U)) + 14605253312318725009U) + aNonceWordL;
            aOrbiterA = (aWandererK + RotL64(aCross, 58U)) + 18138286582677863671U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 8530091235978489988U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 14381731677571170073U;
            aOrbiterD = RotL64((aOrbiterD * 11675896999665768253U), 43U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterD) + 13316413456378978456U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordE;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 3910529530149320706U) ^ aNonceWordD;
            aOrbiterJ = RotL64((aOrbiterJ * 16000139333493588429U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 6302070286831566901U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 12324134652758551396U) ^ aNonceWordP;
            aOrbiterI = RotL64((aOrbiterI * 17136438281540250165U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 4773478557638475048U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 4031153435446078944U) ^ aOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3876928995240982769U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 3114794895962903899U) + aOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 3552936509969106796U) ^ aOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 16823186892738820299U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 5828754613946145627U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 17985241114076114558U) ^ aNonceWordA;
            aOrbiterC = RotL64((aOrbiterC * 1986669631395606833U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 11319331046368072261U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 6104267020171882160U;
            aOrbiterK = RotL64((aOrbiterK * 12525117969211576177U), 51U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterG, 23U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 47U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 4U));
            aIngress = aIngress + RotL64(aOrbiterJ, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aScatter, 53U) + aOrbiterK) + RotL64(aOrbiterD, 26U)) + aNonceWordO);
            aWandererC = aWandererC + ((RotL64(aPrevious, 27U) + RotL64(aOrbiterI, 19U)) + aOrbiterD);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 3U) + aOrbiterA) + RotL64(aOrbiterC, 43U));
            aWandererK = aWandererK + (((RotL64(aCross, 35U) + RotL64(aOrbiterC, 57U)) + aOrbiterJ) + RotL64(aCarry, 23U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 47U) + RotL64(aOrbiterD, 5U)) + aOrbiterG) + aWandererUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 60U) + aOrbiterK) + RotL64(aOrbiterJ, 51U)) + RotL64(aCarry, 53U));
            aWandererD = aWandererD ^ ((((RotL64(aCross, 21U) + RotL64(aOrbiterC, 37U)) + aOrbiterK) + aNonceWordC) + aWandererUpdateSaltE[((aIndex + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererI, 4U) ^ aWandererH);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 41U));
            aCarry = aCarry + RotL64(aWandererF, 51U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 3
        // ingress from: aWorkLaneB, aExpandLaneD, aOperationLaneD
        // ingress directions: aWorkLaneB forward forced, aExpandLaneD forward forced, aOperationLaneD forward/backward random
        // cross from: aWorkLaneA, aExpandLaneB, aOperationLaneB
        // cross directions: aWorkLaneA backward forced, aExpandLaneB backward forced, aOperationLaneB backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 18924U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneD[((aIndex + 17040U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 21102U)) & S_BLOCK1], 12U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21651U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 24211U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aOperationLaneB[((aIndex + 24125U)) & S_BLOCK1], 60U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCarry, 27U) + RotL64(aIngress, 39U)) ^ (RotL64(aPrevious, 56U) ^ RotL64(aCross, 11U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterE = ((aWandererB + RotL64(aPrevious, 21U)) + 12426357877879529292U) + aOrbiterAssignSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = (aWandererF + RotL64(aCross, 43U)) + 12604900366173639176U;
            aOrbiterD = ((aWandererJ + RotL64(aIngress, 3U)) + 13511119007338929401U) + aNonceWordB;
            aOrbiterG = ((aWandererA + RotL64(aScatter, 29U)) + RotL64(aCarry, 39U)) + 9878720081166788060U;
            aOrbiterB = (((aWandererE + RotL64(aCross, 57U)) + RotL64(aCarry, 11U)) + 15463195409806395076U) + aNonceWordD;
            aOrbiterI = ((aWandererH + RotL64(aIngress, 10U)) + 6407922778852833423U) + aNonceWordL;
            aOrbiterH = ((((aWandererD + RotL64(aPrevious, 35U)) + RotL64(aCarry, 23U)) + 7690427254160734016U) + aOrbiterAssignSaltB[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordI;
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 18030974031722143619U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterE) ^ 17983938038322737041U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterD = RotL64((aOrbiterD * 12479365337221685413U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 16605512170117753884U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 681802273302348322U) ^ aNonceWordC;
            aOrbiterI = RotL64((aOrbiterI * 14608920184802647123U), 21U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 15550312921312083819U) + aOrbiterUpdateSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 17824154101711884508U;
            aOrbiterJ = RotL64((aOrbiterJ * 7358612830654795357U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 1939207786756735430U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 3132864634777826569U;
            aOrbiterE = RotL64((aOrbiterE * 13606281919426730325U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 12822929773923954849U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterH) ^ 16576106045887115660U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterB = RotL64((aOrbiterB * 16370914370769903051U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 2398825881649235260U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 13700821892926092479U;
            aOrbiterG = RotL64((aOrbiterG * 10830623703416956043U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 2439833784883391606U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 15870638514107637833U) ^ aNonceWordP;
            aOrbiterH = RotL64((aOrbiterH * 3797380922767479287U), 29U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterB, 10U);
            aIngress = aIngress + (RotL64(aOrbiterE, 35U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 3U));
            aIngress = aIngress + RotL64(aOrbiterD, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aScatter, 27U) + aOrbiterI) + RotL64(aOrbiterB, 29U));
            aWandererH = aWandererH + (((RotL64(aCross, 53U) + RotL64(aOrbiterI, 21U)) + aOrbiterJ) + RotL64(aCarry, 57U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterD, 53U)) + aOrbiterH);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 14U) + RotL64(aOrbiterH, 42U)) + aOrbiterG) + RotL64(aCarry, 37U)) + aNonceWordF);
            aWandererF = aWandererF ^ ((((RotL64(aIngress, 35U) + RotL64(aOrbiterJ, 5U)) + aOrbiterE) + aNonceWordH) + aWandererUpdateSaltA[((aIndex + 13U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aCross, 41U) + aOrbiterJ) + RotL64(aOrbiterH, 13U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 47U) + aOrbiterJ) + RotL64(aOrbiterD, 35U)) + aWandererUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 46U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererF, 35U) ^ aWandererB);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 5U));
            aCarry = aCarry + RotL64(aWandererJ, 23U);
            aCarry = aCarry + RotL64(aIngress, 50U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 30706U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneA[((aIndex + 26634U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aOperationLaneC[((aIndex + 28948U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 25407U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 32708U)) & S_BLOCK1], 40U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 26818U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aIngress, 19U)) + (RotL64(aPrevious, 37U) + RotL64(aCarry, 54U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterJ = ((aWandererE + RotL64(aCross, 47U)) + 15383045568644941552U) + aOrbiterAssignSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterH = ((aWandererK + RotL64(aIngress, 12U)) + 17452811657750910067U) + aNonceWordI;
            aOrbiterE = ((aWandererJ + RotL64(aScatter, 3U)) + RotL64(aCarry, 5U)) + 15660117718455155603U;
            aOrbiterC = (((aWandererD + RotL64(aPrevious, 35U)) + RotL64(aCarry, 47U)) + 10396441207743665753U) + aNonceWordL;
            aOrbiterG = (((aWandererI + RotL64(aCross, 41U)) + RotL64(aCarry, 19U)) + 3708971058200841442U) + aOrbiterAssignSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = (aWandererC + RotL64(aScatter, 27U)) + 7000673057768598750U;
            aOrbiterI = ((aWandererA + RotL64(aIngress, 21U)) + 9886354469011131596U) + aNonceWordB;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 16018065329058043467U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 5024756166109352320U;
            aOrbiterE = RotL64((aOrbiterE * 11660932185479046483U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 6587818720728886652U) + aNonceWordD;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 3652672354944162319U;
            aOrbiterJ = RotL64((aOrbiterJ * 10807121230791716109U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 6307315649915348048U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 16405347331742979258U;
            aOrbiterI = RotL64((aOrbiterI * 7183142442906743699U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 5427299664054601957U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 4983381733483185898U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 14646556236306407673U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 10182995521328377487U) + aNonceWordG;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 8694282877540593550U;
            aOrbiterH = RotL64((aOrbiterH * 14614602561910403893U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 4085927978153269932U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 6176195962815240877U) ^ aOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 16792916528959579875U), 37U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 6966742100601433005U) + aNonceWordA;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 9920952446921247521U) ^ aOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 1879821050131820933U), 51U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterG, 19U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 3U));
            aIngress = aIngress + (RotL64(aOrbiterI, 53U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterH, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterH, 13U)) + aOrbiterE) + aNonceWordN);
            aWandererA = aWandererA + (((RotL64(aPrevious, 39U) + RotL64(aOrbiterH, 57U)) + aOrbiterG) + aWandererUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterJ, 29U)) + aOrbiterG) + aNonceWordF);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 5U) + aOrbiterH) + RotL64(aOrbiterJ, 3U)) + RotL64(aCarry, 47U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterI, 44U)) + aOrbiterE);
            aWandererE = aWandererE + (((((RotL64(aCross, 57U) + aOrbiterB) + RotL64(aOrbiterC, 19U)) + RotL64(aCarry, 21U)) + aNonceWordH) + aWandererUpdateSaltB[((aIndex + 29U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 12U) + aOrbiterB) + RotL64(aOrbiterH, 37U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 43U) ^ aWandererI);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 34U));
            aCarry = aCarry + (RotL64(aWandererD, 19U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererC, 11U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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

void TwistExpander_BasketBall_Arx::KDF_B_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
    std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xB82F9540D293FE77ULL + 0xCB3501D9C46B5CE3ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xFE020C3AFE7C7649ULL + 0x8DF692F08ECD9F39ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xB0B1ABFBBBE79E57ULL + 0xCCF837720D43790EULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xA58863CA1C527113ULL + 0xB92F4234A06472D7ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xF988BC2FA19EEB77ULL + 0x968EC11867640C10ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x81B27A8E789481DBULL + 0xAB0C4F221791DEE4ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xDA3ED0E859C4146DULL + 0xA8DBE982D4525624ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xAD29DDBA473B3BBBULL + 0x8DF6D0657E30A6A3ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xBB273256A18CFB75ULL + 0xDA03B2D677E81C91ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xBB2BFFEFFD02D911ULL + 0x9A6FA276165EA45FULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x85C8119E49F461AFULL + 0x9914419E7D4C1E06ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xD05C0AFCC3B656A1ULL + 0xD0FA00B732D86492ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xF4B3C47DD7274E83ULL + 0xCE9022CFFBF3555CULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0x9B3114B7539BDFAFULL + 0x84CC82D378396BE3ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xFC8D22F8C258F3EBULL + 0xBDF1CE240AE292A9ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xD9A671C0E78BB5DBULL + 0x907AA61C25588598ULL);
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
        // read from: aWorkLaneA, aWorkLaneB, aOperationLaneD, aWorkLaneC, aWorkLaneD, aFireLaneC, aExpandLaneA, aOperationLaneA, aFireLaneB, aExpandLaneB, aOperationLaneC, aFireLaneA, aExpandLaneC, aFireLaneD, aOperationLaneB
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_a loop 1
        // ingress from: aWorkLaneA, aWorkLaneB, aOperationLaneD
        // ingress directions: aWorkLaneA forward forced, aWorkLaneB forward forced, aOperationLaneD forward/backward random
        // cross from: aWorkLaneC, aWorkLaneD, aFireLaneC
        // cross directions: aWorkLaneC backward forced, aWorkLaneD backward forced, aFireLaneC backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 4953U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneB[((aIndex + 7014U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aOperationLaneD[((aIndex + 1266U)) & S_BLOCK1], 6U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 1743U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 2154U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 6875U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aPrevious, 54U) ^ RotL64(aCross, 21U)) + (RotL64(aIngress, 5U) + RotL64(aCarry, 39U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterH = (aWandererG + RotL64(aPrevious, 38U)) + 15188686795415908074U;
            aOrbiterK = (((aWandererC + RotL64(aIngress, 57U)) + 17310049041983079779U) + aOrbiterAssignSaltF[((aIndex + 17U)) & S_SALT1]) + aNonceWordA;
            aOrbiterA = (aWandererD + RotL64(aCross, 51U)) + 8246925977992441471U;
            aOrbiterD = ((aWandererB + RotL64(aScatter, 29U)) + RotL64(aCarry, 39U)) + 8644260919918112781U;
            aOrbiterF = (((aWandererJ + RotL64(aPrevious, 3U)) + RotL64(aCarry, 13U)) + 13401663736874819483U) + aOrbiterAssignSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = (aWandererA + RotL64(aIngress, 13U)) + 7940358935238314973U;
            aOrbiterC = (((aWandererK + RotL64(aCross, 21U)) + RotL64(aCarry, 53U)) + 13278990328548007839U) + aNonceWordC;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 11346868298353840706U) + aOrbiterUpdateSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 2374077904806833579U;
            aOrbiterA = RotL64((aOrbiterA * 1765686942154321425U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 6978903378645019166U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 11951633297870965212U) ^ aNonceWordE;
            aOrbiterH = RotL64((aOrbiterH * 12778236598654492185U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 17398460995357409673U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 1215437945597836770U) ^ aOrbiterUpdateSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9322970054123481621U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 1878751468043972239U) + aNonceWordB;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 5343002808239712390U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11878640995447558811U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 9884918450053276861U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 15894599082080422550U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8359936745539546131U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 13917339232771145459U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 18101134009493720683U) ^ aNonceWordF;
            aOrbiterK = RotL64((aOrbiterK * 15835859435306756387U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 3830086372356903769U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 15894394599564584010U) ^ aNonceWordP;
            aOrbiterJ = RotL64((aOrbiterJ * 9513921913446609263U), 29U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterA, 23U);
            aIngress = aIngress + (RotL64(aOrbiterF, 50U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 29U));
            aIngress = aIngress + RotL64(aOrbiterK, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterK, 36U)) + aOrbiterC);
            aWandererK = aWandererK + ((((RotL64(aCross, 41U) + aOrbiterC) + RotL64(aOrbiterH, 11U)) + RotL64(aCarry, 23U)) + aNonceWordL);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 60U) + aOrbiterJ) + RotL64(aOrbiterC, 3U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 23U) + RotL64(aOrbiterF, 57U)) + aOrbiterA) + RotL64(aCarry, 47U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 47U) + aOrbiterJ) + RotL64(aOrbiterF, 19U)) + aWandererUpdateSaltD[((aIndex + 25U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 13U) + aOrbiterF) + RotL64(aOrbiterD, 27U)) + aNonceWordJ);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 5U) + RotL64(aOrbiterK, 43U)) + aOrbiterF) + aWandererUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererJ);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 6U));
            aCarry = aCarry + (RotL64(aWandererD, 35U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererK, 43U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 2
        // ingress from: aExpandLaneA, aWorkLaneC, aOperationLaneA
        // ingress directions: aExpandLaneA forward forced, aWorkLaneC forward forced, aOperationLaneA forward/backward random
        // cross from: aWorkLaneA, aWorkLaneD, aFireLaneB
        // cross directions: aWorkLaneA backward forced, aWorkLaneD backward forced, aFireLaneB backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 15067U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneC[((aIndex + 15394U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aOperationLaneA[((aIndex + 11388U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 10136U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 14498U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 12495U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aPrevious, 39U) + RotL64(aCross, 54U)) ^ (RotL64(aCarry, 23U) + RotL64(aIngress, 11U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterH = ((aWandererG + RotL64(aCross, 28U)) + 6318740973868639425U) + aNonceWordI;
            aOrbiterD = ((aWandererH + RotL64(aPrevious, 41U)) + 5487840061430920881U) + aNonceWordF;
            aOrbiterI = (aWandererD + RotL64(aScatter, 5U)) + 10258706763248072672U;
            aOrbiterA = (((aWandererF + RotL64(aIngress, 57U)) + RotL64(aCarry, 57U)) + 18356875269730338208U) + aOrbiterAssignSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = ((aWandererC + RotL64(aScatter, 21U)) + RotL64(aCarry, 29U)) + 12883160282903147010U;
            aOrbiterC = (aWandererA + RotL64(aIngress, 51U)) + 1010140474942697730U;
            aOrbiterJ = (((aWandererE + RotL64(aPrevious, 35U)) + RotL64(aCarry, 11U)) + 17733939421700898293U) + aOrbiterAssignSaltC[((aIndex + 5U)) & S_SALT1];
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 13693055887924981201U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 14574732452793385269U) ^ aOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 9373765929885750185U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 10832873941223609012U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 8212600587135328040U) ^ aNonceWordE;
            aOrbiterD = RotL64((aOrbiterD * 5334613996794796145U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 5312744319781971178U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 6173741211706546923U) ^ aOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12854414066390848249U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 3693249147883790810U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 18365859989736602556U) ^ aNonceWordB;
            aOrbiterA = RotL64((aOrbiterA * 3348463719324104997U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 10645056678337549771U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 1175668356822251045U) ^ aNonceWordO;
            aOrbiterG = RotL64((aOrbiterG * 6579675292775345579U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 13556844570541823717U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 4790355739411849736U;
            aOrbiterJ = RotL64((aOrbiterJ * 4083544011788850307U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 14905575502272644116U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 17047244574558476634U;
            aOrbiterH = RotL64((aOrbiterH * 2356386971503880047U), 39U);
            //
            aIngress = RotL64(aOrbiterA, 47U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 53U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 13U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterC, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aScatter, 41U) + RotL64(aOrbiterH, 39U)) + aOrbiterG) + aNonceWordG);
            aWandererA = aWandererA ^ ((((RotL64(aCross, 35U) + aOrbiterJ) + RotL64(aOrbiterD, 47U)) + aNonceWordN) + aWandererUpdateSaltE[((aIndex + 9U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 47U) + aOrbiterA) + RotL64(aOrbiterJ, 60U)) + RotL64(aCarry, 13U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 57U) + aOrbiterH) + RotL64(aOrbiterI, 11U)) + aNonceWordH);
            aWandererD = aWandererD + ((((RotL64(aScatter, 11U) + RotL64(aOrbiterC, 21U)) + aOrbiterG) + RotL64(aCarry, 29U)) + aNonceWordC);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 26U) + RotL64(aOrbiterI, 53U)) + aOrbiterC) + aWandererUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aIngress, 3U) + aOrbiterA) + RotL64(aOrbiterD, 27U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 43U));
            aCarry = aCarry + (RotL64(aWandererF, 36U) ^ aWandererH);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 19U));
            aCarry = aCarry + RotL64(aWandererD, 3U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 3
        // ingress from: aExpandLaneB, aWorkLaneD, aOperationLaneC
        // ingress directions: aExpandLaneB forward forced, aWorkLaneD forward forced, aOperationLaneC forward/backward random
        // cross from: aExpandLaneA, aWorkLaneB, aFireLaneA
        // cross directions: aExpandLaneA backward forced, aWorkLaneB backward forced, aFireLaneA backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 21125U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneD[((aIndex + 19110U)) & S_BLOCK1], 6U));
            aIngress ^= RotL64(aOperationLaneC[((aIndex + 19387U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 20379U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 24073U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 19016U)) & S_BLOCK1], 50U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aPrevious, 41U) + RotL64(aCarry, 19U)) ^ (RotL64(aCross, 5U) ^ RotL64(aIngress, 56U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterG = (aWandererA + RotL64(aIngress, 57U)) + 1898718075389870739U;
            aOrbiterD = ((aWandererE + RotL64(aScatter, 13U)) + 5631794889237247403U) + aOrbiterAssignSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterA = ((((aWandererG + RotL64(aCross, 41U)) + RotL64(aCarry, 5U)) + 18219714659484524607U) + aOrbiterAssignSaltA[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordE;
            aOrbiterB = ((aWandererD + RotL64(aPrevious, 28U)) + RotL64(aCarry, 21U)) + 15419581386225732921U;
            aOrbiterC = ((aWandererC + RotL64(aCross, 21U)) + 9125575431710198210U) + aNonceWordH;
            aOrbiterK = (aWandererF + RotL64(aIngress, 47U)) + 12205871520544965505U;
            aOrbiterH = ((aWandererH + RotL64(aScatter, 5U)) + RotL64(aCarry, 41U)) + 7617534300497343422U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 18017579105368135814U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 10693882161946020042U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2326507900303932855U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 11669615701700895306U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 11045110212889232165U;
            aOrbiterG = RotL64((aOrbiterG * 5965171269273719849U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 18019107802806469913U) + aOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 12315940560472528716U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4505122470351404065U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 4899009736070044310U) + aNonceWordO;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 17412253404253730364U;
            aOrbiterC = RotL64((aOrbiterC * 10791901166391946485U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 4826286251927854181U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 4523455921321845084U) ^ aNonceWordL;
            aOrbiterD = RotL64((aOrbiterD * 14534103906736598099U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 4132514462154182215U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 7164745605985109269U;
            aOrbiterK = RotL64((aOrbiterK * 14107325508977225261U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 6297434295807635654U) + aNonceWordF;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 8813887638672996646U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 17495632530773158201U), 37U);
            //
            aIngress = RotL64(aOrbiterD, 60U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 21U));
            aIngress = aIngress + (RotL64(aOrbiterC, 27U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterK, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterB, 48U)) + aOrbiterG);
            aWandererA = aWandererA + ((((RotL64(aIngress, 60U) + RotL64(aOrbiterC, 11U)) + aOrbiterD) + aNonceWordB) + aWandererUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterC, 41U)) + aOrbiterB) + aWandererUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aScatter, 35U) + RotL64(aOrbiterD, 57U)) + aOrbiterA) + RotL64(aCarry, 41U)) + aNonceWordC);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 53U) + aOrbiterH) + RotL64(aOrbiterC, 35U));
            aWandererH = aWandererH + (((RotL64(aCross, 3U) + aOrbiterC) + RotL64(aOrbiterG, 29U)) + RotL64(aCarry, 23U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterK, 3U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 57U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 19U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 38U));
            aCarry = aCarry + RotL64(aWandererC, 43U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aFireLaneD
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aFireLaneD forward/backward random
        // cross from: aExpandLaneB, aWorkLaneC, aOperationLaneB
        // cross directions: aExpandLaneB backward forced, aWorkLaneC backward forced, aOperationLaneB backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 28622U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneA[((aIndex + 26634U)) & S_BLOCK1], 12U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 29105U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30586U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 31162U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31286U)) & S_BLOCK1], 60U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCross, 35U) + RotL64(aIngress, 21U)) + (RotL64(aCarry, 4U) ^ RotL64(aPrevious, 51U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterA = ((aWandererI + RotL64(aPrevious, 28U)) + 12690502671561165478U) + aNonceWordO;
            aOrbiterB = ((((aWandererH + RotL64(aIngress, 13U)) + RotL64(aCarry, 51U)) + 17519943923428102801U) + aOrbiterAssignSaltF[(((31U - aIndex) + 22U)) & S_SALT1]) + aNonceWordG;
            aOrbiterH = ((aWandererA + RotL64(aScatter, 19U)) + 10705515807975331385U) + aNonceWordB;
            aOrbiterI = (((aWandererD + RotL64(aCross, 35U)) + RotL64(aCarry, 3U)) + 16586447272278538179U) + aNonceWordL;
            aOrbiterF = (aWandererB + RotL64(aIngress, 51U)) + 8006560996840971798U;
            aOrbiterD = (aWandererC + RotL64(aCross, 5U)) + 12928600185788857701U;
            aOrbiterJ = (((aWandererF + RotL64(aScatter, 41U)) + RotL64(aCarry, 27U)) + 14240723153798267172U) + aOrbiterAssignSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 8636219177994872072U) + aOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 7586790235186467512U;
            aOrbiterH = RotL64((aOrbiterH * 15052686382507614169U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 1103807034179512424U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 7547526530239498693U) ^ aNonceWordE;
            aOrbiterB = RotL64((aOrbiterB * 3360295583636013509U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 8380239679344786397U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 5690809173787433519U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5354724308093372953U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 8390902801141804609U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 3507306189192059486U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 18336280496510253103U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 6190745292098482871U) + aNonceWordH;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 8065418693975056902U;
            aOrbiterD = RotL64((aOrbiterD * 6414621418430102589U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 12111755051718111803U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterD) ^ 7605877769709909297U) ^ aOrbiterUpdateSaltB[((aIndex + 14U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterA = RotL64((aOrbiterA * 17525248694315944599U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 5969794501112646237U) + aNonceWordC;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 5127559299360591476U;
            aOrbiterF = RotL64((aOrbiterF * 4521563633438853069U), 5U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterF, 47U);
            aIngress = aIngress + (RotL64(aOrbiterI, 27U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 53U));
            aIngress = aIngress + RotL64(aOrbiterA, 4U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aIngress, 3U) + RotL64(aOrbiterA, 57U)) + aOrbiterI) + aNonceWordF);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterF, 43U)) + aOrbiterA);
            aWandererC = aWandererC + ((RotL64(aScatter, 21U) + aOrbiterA) + RotL64(aOrbiterH, 11U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 29U) + aOrbiterI) + RotL64(aOrbiterB, 51U)) + aNonceWordD);
            aWandererI = aWandererI + ((((RotL64(aIngress, 37U) + aOrbiterB) + RotL64(aOrbiterA, 19U)) + RotL64(aCarry, 23U)) + aNonceWordM);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 43U) + RotL64(aOrbiterD, 34U)) + aOrbiterF) + aWandererUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 60U) + RotL64(aOrbiterJ, 27U)) + aOrbiterF) + RotL64(aCarry, 41U)) + aWandererUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 43U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererI, 6U) ^ aWandererD);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 13U));
            aCarry = aCarry + RotL64(aWandererH, 47U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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

void TwistExpander_BasketBall_Arx::KDF_B_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xADE7222098B756DBULL + 0xFD16F429604908C6ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xCA4952008CD56D8DULL + 0x85781A303A883C66ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xA109F918331A0F61ULL + 0xD28C87705D065F3DULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xDC7EEC5195C9F4CBULL + 0x91A8B9ECD2FF75D2ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x96C5A1D50A0E067BULL + 0xBFAF8E1292E1DCB1ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xB13234C18F8DA307ULL + 0xABADEEACD82A837AULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xF80E5A6BDC0FA705ULL + 0xC8BC67CDB240A3ADULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xFD25A65C232905B9ULL + 0xC8D5C8B7E1E99C4EULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x8ECED62710943C4BULL + 0xD9434058D71C1E4EULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xF3918D8D729EAE93ULL + 0xF6310A309B95A8B0ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x92BFB50C1F88E84FULL + 0xF4AB212F9504EEE5ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xCC78D609EE34EB53ULL + 0xBDD2B54E02A12D7CULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xB063EED5D4FB415FULL + 0x8EF98484621373A1ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xFBE02286CF7686F3ULL + 0xE4CC423E9B069B24ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x9E85081B123ABA67ULL + 0xA6CDCEE4EA1BF1C9ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0x8EC7FAA1CA6E01EBULL + 0xF225F77EA2667934ULL);
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
        // read from: aExpandLaneA, aExpandLaneB, aWorkLaneA, aExpandLaneC, aExpandLaneD, aFireLaneA, aOperationLaneA, aFireLaneD, aWorkLaneB, aOperationLaneB, aFireLaneC, aWorkLaneD, aOperationLaneC, aFireLaneB, aWorkLaneC
        // write to: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD
    
        // kdf_b_loop_b loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aWorkLaneA
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aWorkLaneA forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD, aFireLaneA
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward forced, aFireLaneA backward/forward random
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 1914U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneB[((aIndex + 4301U)) & S_BLOCK1], 44U));
            aIngress ^= RotL64(aWorkLaneA[((aIndex + 1356U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 1259U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 6627U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 6191U)) & S_BLOCK1], 20U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aIngress, 27U)) + (RotL64(aPrevious, 57U) + RotL64(aCross, 42U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterI = (aWandererK + RotL64(aScatter, 37U)) + 18255347001097480328U;
            aOrbiterE = ((aWandererI + RotL64(aIngress, 11U)) + RotL64(aCarry, 11U)) + 13679246790311505735U;
            aOrbiterJ = ((aWandererJ + RotL64(aPrevious, 13U)) + 10565839529765027116U) + aOrbiterAssignSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = (aWandererH + RotL64(aCross, 21U)) + 14327172566224769901U;
            aOrbiterG = ((aWandererB + RotL64(aScatter, 51U)) + 16239024612038195174U) + aNonceWordK;
            aOrbiterC = (aWandererF + RotL64(aCross, 27U)) + 13800012174212131890U;
            aOrbiterD = (aWandererA + RotL64(aIngress, 54U)) + 13900288860157577583U;
            aOrbiterA = (aWandererC + RotL64(aPrevious, 19U)) + 4144386119777112740U;
            aOrbiterB = (((aWandererD + RotL64(aScatter, 57U)) + RotL64(aCarry, 53U)) + 3154558262670631372U) + aNonceWordJ;
            aOrbiterF = ((aWandererG + RotL64(aIngress, 3U)) + 7456728543137614001U) + aOrbiterAssignSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterH = ((aWandererE + RotL64(aCross, 46U)) + RotL64(aCarry, 5U)) + 11709519851158935384U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 15607438907832240304U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 9276575329661725624U) ^ aNonceWordP;
            aOrbiterJ = RotL64((aOrbiterJ * 8879744070762412745U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 6459435969129449226U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 6442382118416542275U) ^ aNonceWordB;
            aOrbiterC = RotL64((aOrbiterC * 2921027306686588233U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 12117432107282150865U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 6831279293184793243U;
            aOrbiterK = RotL64((aOrbiterK * 2435360641135249073U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 9520022957804572889U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterC) ^ 8322178689474588679U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterA = RotL64((aOrbiterA * 1627707191467537115U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 4162401591586869316U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 8994015844714895961U;
            aOrbiterD = RotL64((aOrbiterD * 15421910378057951895U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 10038095909727959633U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 17756404450592957616U;
            aOrbiterB = RotL64((aOrbiterB * 14255952184627347295U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 3379089265413427719U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 11341713098678108441U;
            aOrbiterI = RotL64((aOrbiterI * 2500587373161411961U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 4030296130743454165U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 6332387792111212064U) ^ aOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 16490982218150897861U), 21U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 14893209417387662133U) + aNonceWordD;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 9265457389326311687U;
            aOrbiterF = RotL64((aOrbiterF * 9778404505547862689U), 39U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 13496086915199406901U) + aOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 14576555328710787951U;
            aOrbiterG = RotL64((aOrbiterG * 13155395071667672943U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 11482324648071976743U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 18255347001097480328U;
            aOrbiterE = RotL64((aOrbiterE * 10918514878283385643U), 37U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterH, 5U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 27U));
            aIngress = aIngress + (RotL64(aOrbiterD, 29U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterB, 57U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterE, 36U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterI, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aCross, 43U) + aOrbiterE) + RotL64(aOrbiterH, 3U)) + RotL64(aCarry, 23U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 13U) + aOrbiterF) + RotL64(aOrbiterK, 37U)) + aNonceWordH);
            aWandererK = aWandererK + ((((RotL64(aScatter, 57U) + RotL64(aOrbiterJ, 41U)) + aOrbiterB) + RotL64(aCarry, 5U)) + aWandererUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 19U) + RotL64(aOrbiterH, 14U)) + aOrbiterG) + aNonceWordM);
            aWandererF = aWandererF + ((RotL64(aCross, 39U) + RotL64(aOrbiterI, 5U)) + aOrbiterC);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 22U) + aOrbiterC) + RotL64(aOrbiterK, 57U));
            aWandererI = aWandererI + ((RotL64(aScatter, 47U) + aOrbiterA) + RotL64(aOrbiterF, 23U));
            aWandererD = aWandererD ^ ((((RotL64(aPrevious, 3U) + RotL64(aOrbiterC, 53U)) + aOrbiterB) + aNonceWordA) + aWandererUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aScatter, 35U) + RotL64(aOrbiterG, 39U)) + aOrbiterC);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 50U) + aOrbiterK) + RotL64(aOrbiterE, 19U)) + aNonceWordO);
            aWandererA = aWandererA + ((RotL64(aPrevious, 29U) + RotL64(aOrbiterD, 10U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 24U));
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererJ);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 5U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 27U));
            aCarry = aCarry + (RotL64(aWandererG, 3U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererI, 29U);
            aCarry = aCarry + RotL64(aIngress, 36U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 2
        // ingress from: aOperationLaneA, aExpandLaneC, aFireLaneD
        // ingress directions: aOperationLaneA forward forced, aExpandLaneC forward forced, aFireLaneD forward/backward random
        // cross from: aExpandLaneA, aExpandLaneD, aWorkLaneB
        // cross directions: aExpandLaneA backward forced, aExpandLaneD backward forced, aWorkLaneB backward/forward random
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 13104U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneC[((aIndex + 13402U)) & S_BLOCK1], 56U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 12589U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 13811U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 14136U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 15373U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aPrevious, 27U) ^ RotL64(aCross, 5U)) ^ (RotL64(aCarry, 52U) + RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterK = (aWandererH + RotL64(aIngress, 57U)) + 10038936806177516123U;
            aOrbiterD = (aWandererE + RotL64(aCross, 13U)) + 1773168435195292638U;
            aOrbiterG = (aWandererD + RotL64(aScatter, 51U)) + 10655711161526628072U;
            aOrbiterI = ((aWandererJ + RotL64(aPrevious, 19U)) + RotL64(aCarry, 19U)) + 14422295664639740437U;
            aOrbiterC = ((aWandererG + RotL64(aCross, 27U)) + 4125228715513159576U) + aNonceWordB;
            aOrbiterE = (aWandererA + RotL64(aPrevious, 34U)) + 3670449653158650845U;
            aOrbiterH = ((aWandererK + RotL64(aIngress, 21U)) + 17553727567180813057U) + aOrbiterAssignSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = (((aWandererC + RotL64(aScatter, 3U)) + 5111401772713882743U) + aOrbiterAssignSaltB[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordK;
            aOrbiterB = ((aWandererF + RotL64(aCross, 37U)) + RotL64(aCarry, 53U)) + 7688573124662314413U;
            aOrbiterF = (((aWandererB + RotL64(aScatter, 47U)) + RotL64(aCarry, 5U)) + 9438375825507814395U) + aNonceWordO;
            aOrbiterA = (aWandererI + RotL64(aIngress, 10U)) + 14177477039902118886U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 16329942595859623928U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 3990536794006836672U;
            aOrbiterG = RotL64((aOrbiterG * 579024714339065373U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 5072881436583180756U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 16789727877867289997U;
            aOrbiterC = RotL64((aOrbiterC * 8766246302636197905U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 17313956922306689438U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterE) ^ 11530878396329822041U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterJ = RotL64((aOrbiterJ * 11356860047841383129U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 3612616532321160196U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 4172189825359187763U;
            aOrbiterB = RotL64((aOrbiterB * 12938945495299393177U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 8677279703778052804U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 1912172980909479362U;
            aOrbiterF = RotL64((aOrbiterF * 10053289257955474143U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 1460085850227494500U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 12116763868122868147U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 6076945628020280957U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 17571840610366424432U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 15581362592611080868U;
            aOrbiterE = RotL64((aOrbiterE * 1129054058044872003U), 27U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterJ) + 14434700039977611666U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordN;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 4534294602623329152U;
            aOrbiterD = RotL64((aOrbiterD * 5860911553425182045U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 865998255725903702U) + aOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 16407778704555344108U;
            aOrbiterH = RotL64((aOrbiterH * 15571344643129797977U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 1948990288894429805U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 18218556219056835250U;
            aOrbiterK = RotL64((aOrbiterK * 16574160087642377293U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 1309229265173143398U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 10038936806177516123U;
            aOrbiterA = RotL64((aOrbiterA * 12954594462760207923U), 37U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterG, 3U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 47U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 11U));
            aIngress = aIngress + (RotL64(aOrbiterI, 29U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterC, 21U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterA, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aIngress, 38U) + aOrbiterE) + RotL64(aOrbiterA, 53U));
            aWandererJ = aWandererJ ^ ((((RotL64(aCross, 41U) + RotL64(aOrbiterC, 11U)) + aOrbiterK) + aNonceWordE) + aWandererUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aScatter, 27U) + RotL64(aOrbiterF, 43U)) + aOrbiterE) + RotL64(aCarry, 19U)) + aNonceWordD);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterB, 50U)) + aOrbiterA);
            aWandererC = aWandererC + (((RotL64(aIngress, 11U) + aOrbiterE) + RotL64(aOrbiterG, 29U)) + aWandererUpdateSaltD[((aIndex + 29U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 3U) + aOrbiterH) + RotL64(aOrbiterG, 27U));
            aWandererI = aWandererI + ((RotL64(aPrevious, 29U) + RotL64(aOrbiterI, 19U)) + aOrbiterJ);
            aWandererH = aWandererH ^ ((RotL64(aCross, 14U) + RotL64(aOrbiterC, 60U)) + aOrbiterD);
            aWandererK = aWandererK + (((RotL64(aPrevious, 47U) + aOrbiterJ) + RotL64(aOrbiterK, 37U)) + RotL64(aCarry, 23U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 19U) + aOrbiterA) + RotL64(aOrbiterK, 21U));
            aWandererE = aWandererE + ((RotL64(aScatter, 51U) + RotL64(aOrbiterB, 5U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 29U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererF, 21U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererD, 6U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererB, 19U) ^ aWandererG);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 11U));
            aCarry = aCarry + RotL64(aWandererA, 41U);
            aCarry = aCarry + RotL64(aIngress, 50U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 24411U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneD[((aIndex + 23215U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 24506U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 19856U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 18736U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 23454U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aIngress, 57U) ^ RotL64(aCarry, 5U)) ^ (RotL64(aPrevious, 24U) + RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterK = ((aWandererK + RotL64(aScatter, 37U)) + RotL64(aCarry, 35U)) + 3684295017013759987U;
            aOrbiterB = (aWandererA + RotL64(aPrevious, 43U)) + 6740408842457292881U;
            aOrbiterG = (((aWandererE + RotL64(aCross, 57U)) + RotL64(aCarry, 13U)) + 4563975890702399441U) + aNonceWordP;
            aOrbiterJ = ((aWandererC + RotL64(aIngress, 23U)) + RotL64(aCarry, 41U)) + 797804144825287940U;
            aOrbiterF = (aWandererJ + RotL64(aCross, 10U)) + 2763779540450101303U;
            aOrbiterC = (aWandererG + RotL64(aIngress, 53U)) + 13211846164102089685U;
            aOrbiterH = (aWandererF + RotL64(aScatter, 27U)) + 15214578447281401982U;
            aOrbiterA = ((aWandererI + RotL64(aPrevious, 35U)) + 13745208628754232427U) + aNonceWordC;
            aOrbiterI = (aWandererD + RotL64(aCross, 46U)) + 17358621225969190747U;
            aOrbiterE = ((aWandererB + RotL64(aIngress, 41U)) + 779739369960480023U) + aOrbiterAssignSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = (((aWandererH + RotL64(aScatter, 29U)) + 4370963533701407813U) + aOrbiterAssignSaltD[((aIndex + 14U)) & S_SALT1]) + aNonceWordE;
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 6061333005507739975U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 3589705340762734456U;
            aOrbiterG = RotL64((aOrbiterG * 16499293983611196967U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 10607697666369230567U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 9356757995305239271U;
            aOrbiterF = RotL64((aOrbiterF * 10945513661439954731U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 10093033335903048138U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 11037328061699834100U;
            aOrbiterA = RotL64((aOrbiterA * 11189760551792389605U), 43U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterF) + 558431161176115540U) + aOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1]) + aNonceWordL;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 17795680919453449358U;
            aOrbiterC = RotL64((aOrbiterC * 3910117359996283803U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 6096779391116214109U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 17594243286880690775U;
            aOrbiterI = RotL64((aOrbiterI * 12655610181937429915U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 15414704802398002423U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 18040588240488602196U;
            aOrbiterH = RotL64((aOrbiterH * 16344249573086571225U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 14636298592697156931U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 9677305688594936561U) ^ aNonceWordB;
            aOrbiterK = RotL64((aOrbiterK * 8354776999961642997U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 16408025751875050713U) + aNonceWordI;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 10018342878801454965U;
            aOrbiterB = RotL64((aOrbiterB * 10349132962708124117U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 1841090936357114866U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 16142637455878447020U) ^ aNonceWordO;
            aOrbiterD = RotL64((aOrbiterD * 10565394571714418033U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 4089676582910615502U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 8749600984499831109U;
            aOrbiterJ = RotL64((aOrbiterJ * 3421055105090316521U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 11408932421005107097U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 3684295017013759987U;
            aOrbiterE = RotL64((aOrbiterE * 7037953759624065417U), 11U);
            //
            aIngress = RotL64(aOrbiterF, 41U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterB, 46U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterG, 3U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterH, 23U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterI, 37U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterJ, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aIngress, 11U) + aOrbiterA) + RotL64(aOrbiterC, 41U));
            aWandererD = aWandererD + ((RotL64(aScatter, 43U) + RotL64(aOrbiterH, 3U)) + aOrbiterD);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 41U) + aOrbiterB) + RotL64(aOrbiterJ, 27U)) + aWandererUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererK = aWandererK + (((((RotL64(aCross, 24U) + aOrbiterI) + RotL64(aOrbiterB, 44U)) + RotL64(aCarry, 3U)) + aNonceWordD) + aWandererUpdateSaltC[((aIndex + 29U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterH, 19U)) + aOrbiterC);
            aWandererC = aWandererC + (((RotL64(aScatter, 37U) + aOrbiterI) + RotL64(aOrbiterK, 21U)) + RotL64(aCarry, 35U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterE, 39U)) + aOrbiterF);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 19U) + RotL64(aOrbiterG, 35U)) + aOrbiterE) + aNonceWordF);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterK, 23U)) + aOrbiterB);
            aWandererI = aWandererI + ((RotL64(aIngress, 39U) + aOrbiterI) + RotL64(aOrbiterG, 14U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 22U) + aOrbiterK) + RotL64(aOrbiterH, 51U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 41U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 20U));
            aCarry = aCarry + (RotL64(aWandererF, 27U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererA, 57U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererH, 39U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererD, 35U);
            aCarry = aCarry + RotL64(aIngress, 14U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aOperationLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 4
        // ingress from: aOperationLaneC, aOperationLaneA, aFireLaneB
        // ingress directions: aOperationLaneC forward forced, aOperationLaneA forward forced, aFireLaneB forward/backward random
        // cross from: aOperationLaneB, aExpandLaneC, aWorkLaneC
        // cross directions: aOperationLaneB backward forced, aExpandLaneC backward forced, aWorkLaneC backward/forward random
        // write to: aOperationLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneC[((aIndex + 26958U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneA[((aIndex + 31571U)) & S_BLOCK1], 12U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 28415U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 25722U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 30342U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aWorkLaneC[((aIndex + 31916U)) & S_BLOCK1], 36U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aIngress, 36U) + RotL64(aCarry, 57U)) + (RotL64(aPrevious, 11U) ^ RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterD = ((aWandererA + RotL64(aIngress, 50U)) + RotL64(aCarry, 13U)) + 11039986441331892533U;
            aOrbiterC = ((aWandererC + RotL64(aPrevious, 3U)) + RotL64(aCarry, 53U)) + 6256024955965426119U;
            aOrbiterH = (aWandererD + RotL64(aCross, 13U)) + 9857443189988995666U;
            aOrbiterE = (aWandererG + RotL64(aScatter, 41U)) + 11900944813380998208U;
            aOrbiterI = ((aWandererK + RotL64(aPrevious, 39U)) + 8422577734978875541U) + aNonceWordL;
            aOrbiterK = ((aWandererF + RotL64(aIngress, 57U)) + 3100835100713928724U) + aOrbiterAssignSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = (((aWandererE + RotL64(aCross, 35U)) + RotL64(aCarry, 57U)) + 11871553509810206993U) + aNonceWordP;
            aOrbiterG = (aWandererI + RotL64(aScatter, 53U)) + 17614749493763417027U;
            aOrbiterF = (((aWandererJ + RotL64(aIngress, 23U)) + 3638372131856199916U) + aOrbiterAssignSaltF[((aIndex + 23U)) & S_SALT1]) + aNonceWordB;
            aOrbiterB = (aWandererH + RotL64(aPrevious, 44U)) + 6582275259281025770U;
            aOrbiterA = ((aWandererB + RotL64(aScatter, 21U)) + 17016882418498941958U) + aNonceWordC;
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 1747214688658984715U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 9356088987044015278U) ^ aNonceWordN;
            aOrbiterH = RotL64((aOrbiterH * 16221733545319753695U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 4056238112133473456U) + aNonceWordJ;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 16013150119949532998U;
            aOrbiterD = RotL64((aOrbiterD * 12913648646318115315U), 39U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 16076621211111834889U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 9940824359571581765U;
            aOrbiterG = RotL64((aOrbiterG * 11624767861336495331U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 15624084004784515753U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 7630989544834680335U;
            aOrbiterB = RotL64((aOrbiterB * 12261063237156822067U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 18003586430673313786U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 1654118743290334161U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 1153250137357176071U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 3254189676528343910U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 15629083361573065165U;
            aOrbiterE = RotL64((aOrbiterE * 17024833368570949107U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 10056859810555674806U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 15976683222786846254U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 2801754232182942635U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 11872378594829637933U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 7633773773528713489U;
            aOrbiterA = RotL64((aOrbiterA * 8218288492011593353U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 16305188578382203720U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 13293036594949754170U;
            aOrbiterF = RotL64((aOrbiterF * 1300645662609848183U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 15185013801659166674U) + aNonceWordE;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 11562899709899198100U;
            aOrbiterI = RotL64((aOrbiterI * 9115495024409604629U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 1525205566739385260U) + aNonceWordK;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 11039986441331892533U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9802284050237622047U), 23U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterD, 29U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 10U));
            aIngress = aIngress + (RotL64(aOrbiterH, 53U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 21U));
            aIngress = aIngress + (RotL64(aOrbiterB, 37U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterE, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aScatter, 3U) + RotL64(aOrbiterC, 11U)) + aOrbiterI) + aNonceWordG);
            aWandererF = aWandererF + ((RotL64(aCross, 50U) + aOrbiterD) + RotL64(aOrbiterB, 56U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 23U) + aOrbiterA) + RotL64(aOrbiterJ, 13U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 41U) + RotL64(aOrbiterA, 23U)) + aOrbiterB) + RotL64(aCarry, 11U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterF, 51U)) + aOrbiterJ);
            aWandererH = aWandererH + ((RotL64(aScatter, 29U) + RotL64(aOrbiterI, 27U)) + aOrbiterB);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 6U) + aOrbiterH) + RotL64(aOrbiterK, 40U)) + aWandererUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aCross, 11U) + aOrbiterD) + RotL64(aOrbiterC, 53U)) + RotL64(aCarry, 23U)) + aNonceWordH);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterC, 43U)) + aOrbiterE);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 39U) + RotL64(aOrbiterH, 3U)) + aOrbiterG) + aNonceWordA) + aWandererUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterH, 37U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 24U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 57U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 51U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 53U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 29U));
            aCarry = aCarry + RotL64(aWandererB, 21U);
            aCarry = aCarry + RotL64(aIngress, 60U);
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

void TwistExpander_BasketBall_Arx::KDF_B_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xAAFAEAD682A61CA3ULL + 0xFE9FA86CD6C1ED16ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x8498EA298AF3247BULL + 0x9E0938CC1990EB2DULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xF20AF255C8DD2165ULL + 0xBD5C484BF20A3C27ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xD94FF5D52D505E0FULL + 0xB80AFE9CE3774BB0ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xC5B7F77918579ADBULL + 0xA7AB6AA127E1AD50ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xD9B21943FF8EBB1BULL + 0xCDDEC98A43317259ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x98C700AF509ACC5DULL + 0x86C6C671830715B4ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x8CE0733F6437E64DULL + 0x8114ADCB17CAD396ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xAB58F6923F6780D1ULL + 0xF88D504D399378F6ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xFE6CAAD12EFC402DULL + 0x81A1D471B7DB9792ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xCA57A5D33623DE1BULL + 0xAF12EBD534EE9AC5ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x9AA4036994CFE7B9ULL + 0x8F61228933A03E84ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xCAA49FE48BCDDF59ULL + 0xC33F84E9C77E1518ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xB770B2D602B0E0FDULL + 0xC0862A91552E3AFEULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xCCF2A91315082C11ULL + 0x8275FDF203D3BF85ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xAE95AE4760D4F567ULL + 0xD1CF4325BB008994ULL);
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
        // read from: aOperationLaneA, aOperationLaneB, aWorkLaneA, aOperationLaneC, aOperationLaneD, aFireLaneD, aExpandLaneA, aWorkLaneC, aWorkLaneD, aExpandLaneB, aFireLaneA, aFireLaneB, aExpandLaneC, aFireLaneC, aWorkLaneB
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_c loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aWorkLaneA
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aWorkLaneA forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aFireLaneD
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aFireLaneD backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 5706U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneB[((aIndex + 5809U)) & S_BLOCK1], 54U));
            aIngress ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 2891U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 4879U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 5042U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 7638U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aPrevious, 57U) ^ RotL64(aCross, 11U)) ^ (RotL64(aIngress, 44U) + RotL64(aCarry, 27U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterB = (((aWandererC + RotL64(aScatter, 47U)) + RotL64(aCarry, 43U)) + 2558105147674438050U) + aNonceWordM;
            aOrbiterC = ((aWandererI + RotL64(aIngress, 11U)) + 15856662514774702561U) + aNonceWordP;
            aOrbiterK = ((aWandererH + RotL64(aCross, 5U)) + 13346869226246584582U) + aNonceWordO;
            aOrbiterJ = (aWandererF + RotL64(aPrevious, 52U)) + 7632111846116243973U;
            aOrbiterH = ((aWandererG + RotL64(aIngress, 19U)) + RotL64(aCarry, 51U)) + 2102101361626976279U;
            aOrbiterA = ((aWandererA + RotL64(aScatter, 29U)) + 5605968705067851563U) + aOrbiterAssignSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterD = (aWandererB + RotL64(aCross, 57U)) + 6842483186584326681U;
            aOrbiterI = (((aWandererJ + RotL64(aPrevious, 41U)) + RotL64(aCarry, 13U)) + 5559797213819425064U) + aNonceWordK;
            aOrbiterE = ((aWandererE + RotL64(aCross, 34U)) + 12422313931331576759U) + aOrbiterAssignSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 2751024420047872601U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 11031320239359798610U;
            aOrbiterK = RotL64((aOrbiterK * 8607639453141148025U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 14366375309473793217U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 11971479429768505316U;
            aOrbiterH = RotL64((aOrbiterH * 10063001532313098203U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 3947595951884469542U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 17882767922372770896U;
            aOrbiterD = RotL64((aOrbiterD * 3361906348965810211U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 513871456983509223U) + aOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 5951677013597794294U) ^ aNonceWordI;
            aOrbiterE = RotL64((aOrbiterE * 8508629569649935293U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 437626309049021931U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 466674061172005705U) ^ aNonceWordA;
            aOrbiterB = RotL64((aOrbiterB * 1310502572084891157U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 12362602809233133718U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 10525852878882195702U;
            aOrbiterC = RotL64((aOrbiterC * 17755022180514914325U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 17927000184308583095U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 566723721423470052U) ^ aOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 17710534355278632573U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 9504585484034413577U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 4614306037721859929U;
            aOrbiterA = RotL64((aOrbiterA * 170807293799483539U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 1463218357720031588U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 4036696102163560633U;
            aOrbiterI = RotL64((aOrbiterI * 15389914226155130065U), 5U);
            //
            aIngress = RotL64(aOrbiterC, 34U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 37U));
            aIngress = aIngress + (RotL64(aOrbiterE, 23U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 3U));
            aIngress = aIngress + RotL64(aOrbiterH, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 42U) + RotL64(aOrbiterH, 14U)) + aOrbiterD);
            aWandererF = aWandererF + (((RotL64(aIngress, 53U) + aOrbiterA) + RotL64(aOrbiterE, 29U)) + aWandererUpdateSaltD[((aIndex + 29U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aCross, 23U) + RotL64(aOrbiterJ, 43U)) + aOrbiterC) + aNonceWordD);
            aWandererE = aWandererE + ((((RotL64(aScatter, 13U) + RotL64(aOrbiterC, 47U)) + aOrbiterH) + RotL64(aCarry, 41U)) + aWandererUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterA, 19U)) + aOrbiterD) + aNonceWordN);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 47U) + aOrbiterB) + RotL64(aOrbiterE, 51U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterK, 23U)) + aOrbiterI) + aNonceWordH);
            aWandererA = aWandererA + (((RotL64(aIngress, 35U) + aOrbiterI) + RotL64(aOrbiterH, 56U)) + RotL64(aCarry, 11U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 18U) + RotL64(aOrbiterI, 37U)) + aOrbiterB) + aNonceWordF);
            //
            aCarry = aCarry + (RotL64(aWandererH, 40U) ^ aWandererJ);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 35U));
            aCarry = aCarry + (RotL64(aWandererF, 51U) ^ aWandererA);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 3U));
            aCarry = aCarry + RotL64(aWandererG, 43U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 2
        // ingress from: aExpandLaneA, aOperationLaneC, aWorkLaneC
        // ingress directions: aExpandLaneA forward forced, aOperationLaneC forward forced, aWorkLaneC forward/backward random
        // cross from: aOperationLaneA, aOperationLaneD, aWorkLaneD
        // cross directions: aOperationLaneA backward forced, aOperationLaneD backward forced, aWorkLaneD backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 10428U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneC[((aIndex + 12831U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 13167U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 13243U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 13581U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aWorkLaneD[((aIndex + 10966U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCross, 35U)) ^ (RotL64(aCarry, 19U) + RotL64(aPrevious, 48U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterB = ((aWandererJ + RotL64(aIngress, 43U)) + 3650233661228036955U) + aOrbiterAssignSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterE = ((aWandererD + RotL64(aCross, 39U)) + 11607036400067735729U) + aNonceWordI;
            aOrbiterG = ((aWandererB + RotL64(aScatter, 50U)) + 3899614406903883035U) + aOrbiterAssignSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterH = ((aWandererC + RotL64(aPrevious, 13U)) + 8159156925629965143U) + aNonceWordG;
            aOrbiterF = (((aWandererI + RotL64(aScatter, 35U)) + RotL64(aCarry, 53U)) + 7148903913967261270U) + aNonceWordN;
            aOrbiterI = (((aWandererF + RotL64(aCross, 27U)) + RotL64(aCarry, 5U)) + 9161665622287517848U) + aNonceWordC;
            aOrbiterD = ((aWandererK + RotL64(aIngress, 3U)) + RotL64(aCarry, 23U)) + 2981535013474059469U;
            aOrbiterJ = (aWandererH + RotL64(aPrevious, 58U)) + 15812469008200319549U;
            aOrbiterC = (aWandererE + RotL64(aCross, 21U)) + 14687469489893270300U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 6025209349511417063U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 12964750392311112676U) ^ aOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12955480283032701843U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 6572355895765394340U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 3542300121890027981U;
            aOrbiterF = RotL64((aOrbiterF * 11201491178181273935U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 6477175684045398359U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 1081388388827929314U) ^ aNonceWordA;
            aOrbiterH = RotL64((aOrbiterH * 8752188637514143529U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 13754328481584620771U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 3684673342659575917U;
            aOrbiterJ = RotL64((aOrbiterJ * 6139923312873039143U), 39U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 6542045150319909445U) + aOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 5352102692424060388U;
            aOrbiterD = RotL64((aOrbiterD * 7385758355501860261U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 9110100774657340354U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 2813273684436269057U;
            aOrbiterI = RotL64((aOrbiterI * 10468759062594022273U), 19U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterF) + 5860425751137403755U) + aOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1]) + aNonceWordP;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 1598622981888978548U;
            aOrbiterB = RotL64((aOrbiterB * 651816500461718345U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 14710305692377606725U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 16280545617802383463U;
            aOrbiterC = RotL64((aOrbiterC * 12541767206978802063U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 6849565243667718750U) + aOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 12152381961996750050U;
            aOrbiterE = RotL64((aOrbiterE * 11185935780063403807U), 53U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterJ, 47U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 39U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 5U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 36U));
            aIngress = aIngress + RotL64(aOrbiterH, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aIngress, 19U) + RotL64(aOrbiterF, 47U)) + aOrbiterD);
            aWandererI = aWandererI ^ (((RotL64(aCross, 5U) + RotL64(aOrbiterG, 6U)) + aOrbiterD) + aWandererUpdateSaltE[((aIndex + 27U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 14U) + RotL64(aOrbiterI, 27U)) + aOrbiterC) + RotL64(aCarry, 51U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterJ, 41U)) + aOrbiterF);
            aWandererC = aWandererC + ((RotL64(aScatter, 27U) + RotL64(aOrbiterI, 13U)) + aOrbiterE);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 35U) + RotL64(aOrbiterB, 58U)) + aOrbiterH) + aNonceWordH);
            aWandererE = aWandererE + (((((RotL64(aCross, 43U) + aOrbiterF) + RotL64(aOrbiterI, 23U)) + RotL64(aCarry, 13U)) + aNonceWordB) + aWandererUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 52U) + aOrbiterF) + RotL64(aOrbiterE, 19U)) + aNonceWordM);
            aWandererD = aWandererD + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterG, 51U)) + aOrbiterH) + aNonceWordD);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 28U));
            aCarry = aCarry + (RotL64(aWandererK, 13U) ^ aWandererC);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 3U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 35U));
            aCarry = aCarry + RotL64(aWandererE, 51U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 23080U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneD[((aIndex + 18655U)) & S_BLOCK1], 60U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 19643U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 22008U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 17763U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 16527U)) & S_BLOCK1], 26U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aIngress, 54U) + RotL64(aCarry, 21U)) + (RotL64(aCross, 39U) ^ RotL64(aPrevious, 3U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterK = ((aWandererH + RotL64(aIngress, 20U)) + 7948891781097675369U) + aNonceWordF;
            aOrbiterF = ((aWandererI + RotL64(aCross, 53U)) + 13928362874228230226U) + aNonceWordM;
            aOrbiterD = ((aWandererB + RotL64(aScatter, 47U)) + 10776180542602258926U) + aNonceWordE;
            aOrbiterC = (((aWandererD + RotL64(aPrevious, 11U)) + RotL64(aCarry, 43U)) + 5735115172149470447U) + aOrbiterAssignSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = ((aWandererE + RotL64(aCross, 39U)) + 5353591822981766987U) + aOrbiterAssignSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterE = ((aWandererA + RotL64(aScatter, 43U)) + RotL64(aCarry, 27U)) + 562301708107268570U;
            aOrbiterG = (aWandererC + RotL64(aPrevious, 57U)) + 10467810247578364868U;
            aOrbiterB = ((aWandererK + RotL64(aIngress, 3U)) + RotL64(aCarry, 11U)) + 14541630141152308564U;
            aOrbiterH = (aWandererG + RotL64(aScatter, 24U)) + 2350076897065139429U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 17519109078651162228U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 6061035173339902910U;
            aOrbiterD = RotL64((aOrbiterD * 10021905773432907835U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 15654836633731000065U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 13723521735153718904U) ^ aNonceWordG;
            aOrbiterF = RotL64((aOrbiterF * 14459516479283070563U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 2849680038315532197U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 17336102435576647923U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10984689101753586739U), 43U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 7671010488872356142U) + aNonceWordB;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 11485114338165600777U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4162584865462407791U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 8759060657343458985U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 11009137869375286581U;
            aOrbiterA = RotL64((aOrbiterA * 8741417343929809115U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 15792999392743144135U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 6180808423175992479U;
            aOrbiterC = RotL64((aOrbiterC * 13681230339693676907U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 361487389591183005U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 15292753806514404853U;
            aOrbiterH = RotL64((aOrbiterH * 17478232597253311153U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 14929153438443362045U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 7904556383593914086U;
            aOrbiterK = RotL64((aOrbiterK * 2484130486635511403U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 3793180909904286848U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 10391957637467171320U;
            aOrbiterB = RotL64((aOrbiterB * 505484041943467117U), 35U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterA, 27U);
            aIngress = aIngress + (RotL64(aOrbiterG, 54U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterE, 47U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 35U));
            aIngress = aIngress + RotL64(aOrbiterF, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aScatter, 43U) + aOrbiterG) + RotL64(aOrbiterE, 36U)) + aNonceWordN);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 10U) + RotL64(aOrbiterA, 51U)) + aOrbiterD);
            aWandererG = aWandererG + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterG, 57U)) + aOrbiterH) + aWandererUpdateSaltA[((aIndex + 25U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterE, 29U)) + aOrbiterD);
            aWandererH = aWandererH + ((((RotL64(aScatter, 57U) + aOrbiterD) + RotL64(aOrbiterK, 5U)) + RotL64(aCarry, 19U)) + aNonceWordK);
            aWandererB = aWandererB ^ (((RotL64(aCross, 39U) + RotL64(aOrbiterF, 47U)) + aOrbiterH) + aWandererUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aIngress, 19U) + aOrbiterK) + RotL64(aOrbiterC, 40U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterK, 11U)) + aOrbiterB);
            aWandererA = aWandererA + (((RotL64(aIngress, 14U) + aOrbiterF) + RotL64(aOrbiterB, 23U)) + RotL64(aCarry, 39U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 34U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererG, 23U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererD, 19U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererA, 27U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererC, 39U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aFireLaneC
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aFireLaneC forward/backward random
        // cross from: aExpandLaneB, aOperationLaneC, aWorkLaneB
        // cross directions: aExpandLaneB backward forced, aOperationLaneC backward forced, aWorkLaneB backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 24884U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneA[((aIndex + 27214U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 25842U)) & S_BLOCK1], 58U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27150U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 25113U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 24873U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCross, 37U) + RotL64(aPrevious, 21U)) ^ (RotL64(aIngress, 52U) ^ RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterI = ((aWandererB + RotL64(aPrevious, 46U)) + 13924571355038625040U) + aNonceWordH;
            aOrbiterJ = (aWandererI + RotL64(aScatter, 19U)) + 16328300979357156658U;
            aOrbiterB = ((aWandererA + RotL64(aIngress, 51U)) + 3947771961206012461U) + aNonceWordC;
            aOrbiterH = (aWandererF + RotL64(aCross, 35U)) + 15428284250569311285U;
            aOrbiterG = (aWandererH + RotL64(aIngress, 11U)) + 5777369485254032486U;
            aOrbiterA = (((aWandererK + RotL64(aPrevious, 27U)) + RotL64(aCarry, 23U)) + 16813320300717644673U) + aOrbiterAssignSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterD = (((aWandererC + RotL64(aCross, 3U)) + RotL64(aCarry, 57U)) + 16689933050200758251U) + aOrbiterAssignSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = (((aWandererG + RotL64(aScatter, 41U)) + RotL64(aCarry, 47U)) + 1856422419049390708U) + aNonceWordG;
            aOrbiterF = ((aWandererE + RotL64(aCross, 56U)) + 18214498743831925517U) + aNonceWordA;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 18278550878494094923U) + aOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 797712062039591797U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 7212998747080137625U), 27U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 15854849439012341347U) + aNonceWordM;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 996882939768167773U;
            aOrbiterA = RotL64((aOrbiterA * 14936703950807908575U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 3005829974130671692U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 8793495343509953906U;
            aOrbiterJ = RotL64((aOrbiterJ * 14065479348374612031U), 39U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 7710453029930631112U) + aNonceWordI;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 9511995836117707047U;
            aOrbiterF = RotL64((aOrbiterF * 7250766204781428201U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 670902975693341744U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 9045820304668279777U;
            aOrbiterG = RotL64((aOrbiterG * 18373074917532639027U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 12417212387607119470U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 12816983560669985622U;
            aOrbiterH = RotL64((aOrbiterH * 8406003970221889847U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 17245432086377688540U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 6806521945548502014U;
            aOrbiterI = RotL64((aOrbiterI * 11335859481858640857U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 8947500746292365294U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 4468060468522895852U) ^ aNonceWordE;
            aOrbiterK = RotL64((aOrbiterK * 7022481284816599797U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 9892975931958803992U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 3042599331526937836U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 3308512896171443645U), 13U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterG, 47U);
            aIngress = aIngress + (RotL64(aOrbiterA, 11U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterB, 39U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterI, 5U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterF, 58U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aScatter, 30U) + aOrbiterA) + RotL64(aOrbiterI, 44U));
            aWandererK = aWandererK + ((RotL64(aIngress, 57U) + RotL64(aOrbiterF, 19U)) + aOrbiterJ);
            aWandererB = aWandererB ^ ((RotL64(aCross, 23U) + aOrbiterD) + RotL64(aOrbiterH, 35U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 35U) + aOrbiterD) + RotL64(aOrbiterF, 27U)) + RotL64(aCarry, 43U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 11U) + RotL64(aOrbiterK, 23U)) + aOrbiterI) + aWandererUpdateSaltF[((aIndex + 3U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aScatter, 41U) + aOrbiterA) + RotL64(aOrbiterJ, 39U)) + RotL64(aCarry, 57U));
            aWandererE = aWandererE ^ ((((RotL64(aCross, 6U) + RotL64(aOrbiterD, 13U)) + aOrbiterG) + aNonceWordK) + aWandererUpdateSaltD[((aIndex + 11U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterB, 50U)) + aOrbiterH) + aNonceWordJ);
            aWandererC = aWandererC ^ ((RotL64(aCross, 19U) + aOrbiterB) + RotL64(aOrbiterK, 3U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 47U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 23U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 53U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 11U));
            aCarry = aCarry + RotL64(aWandererK, 50U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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

void TwistExpander_BasketBall_Arx::KDF_B_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
    std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xB39BA7229BFE0177ULL + 0x8F169405F1D0B994ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xFC970D1D28907209ULL + 0xCA112751EA6D5616ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xD45E4CCB41417DA1ULL + 0xAC340EA60126E172ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x8812E21BC45AEC2DULL + 0xD9486C5AD9F0A6B0ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xDF78CD0FEAE2D41BULL + 0xE9D1177097BC4BA5ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x81DA9898D16124A7ULL + 0xB886F35E92B40594ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xB0C7A4935AB74049ULL + 0x89604C476F461CF9ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xA49C36079049F855ULL + 0x8C72B4637AD5DD2BULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xC61C4CBD73DA3999ULL + 0xC550952728344E94ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xCD9A1935E2F0DACFULL + 0x8E3BA9EBE94724A1ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xA5659134F7A92479ULL + 0xE4736CDBA1AAC555ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xDDE490A565389F33ULL + 0xFBA5E2296B467967ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xC68CB34D012504DDULL + 0xEDB2485AA9EF6447ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xE1777A2BFB28DAF5ULL + 0xC1C1A8DD288A4D74ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x856382FC371982BDULL + 0x834698A04A95E9FBULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xCE4509A6C433C093ULL + 0xA7EB1053588B4A36ULL);
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
        // read from: aWorkLaneA, aWorkLaneB, aFireLaneB, aWorkLaneC, aWorkLaneD, aOperationLaneA, aExpandLaneA, aOperationLaneB, aFireLaneC, aExpandLaneB, aOperationLaneC, aOperationLaneD, aExpandLaneC, aFireLaneA, aFireLaneD
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_d loop 1
        // ingress from: aWorkLaneA, aWorkLaneB, aFireLaneB
        // ingress directions: aWorkLaneA forward forced, aWorkLaneB forward forced, aFireLaneB forward/backward random
        // cross from: aWorkLaneC, aWorkLaneD, aOperationLaneA
        // cross directions: aWorkLaneC backward forced, aWorkLaneD backward forced, aOperationLaneA backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 3182U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((aIndex + 5495U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 305U)) & S_BLOCK1], 18U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 3692U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 1295U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 1913U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aPrevious, 43U) + RotL64(aCross, 11U)) ^ (RotL64(aCarry, 27U) + RotL64(aIngress, 60U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterC = ((aWandererB + RotL64(aIngress, 39U)) + RotL64(aCarry, 21U)) + 9446153639709651566U;
            aOrbiterI = ((aWandererF + RotL64(aCross, 14U)) + RotL64(aCarry, 35U)) + 10550762260670758167U;
            aOrbiterA = (aWandererD + RotL64(aScatter, 51U)) + 7062634922142578383U;
            aOrbiterD = ((aWandererE + RotL64(aPrevious, 23U)) + RotL64(aCarry, 3U)) + 9178499097812764515U;
            aOrbiterB = ((aWandererJ + RotL64(aIngress, 29U)) + 6887103379773525538U) + aOrbiterAssignSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = (((aWandererG + RotL64(aScatter, 57U)) + 6239750312052010257U) + aOrbiterAssignSaltF[((aIndex + 29U)) & S_SALT1]) + aNonceWordC;
            aOrbiterG = ((aWandererK + RotL64(aCross, 3U)) + 17645022614523287959U) + aNonceWordM;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 3639618183259408272U) + aNonceWordP;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 3131737117548745095U;
            aOrbiterA = RotL64((aOrbiterA * 6585057380704940395U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 7253994382396406554U) + aOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 15217993711938379561U;
            aOrbiterC = RotL64((aOrbiterC * 17853313384747259923U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 12594152227603630033U) + aOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 11250170200489647869U;
            aOrbiterG = RotL64((aOrbiterG * 546800378327864723U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 12936942656624279424U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 10990736056052106149U;
            aOrbiterB = RotL64((aOrbiterB * 7123916809953459187U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 12787293075893090465U) + aNonceWordI;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 17154990205620778151U;
            aOrbiterK = RotL64((aOrbiterK * 10031369940028159521U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 1270827262969060301U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 17337623431665013136U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 1517262088236356107U), 39U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 830330490987911853U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 6828309232554560547U;
            aOrbiterD = RotL64((aOrbiterD * 9742464176986145819U), 3U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterB, 51U);
            aIngress = aIngress + (RotL64(aOrbiterC, 36U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 43U));
            aIngress = aIngress + RotL64(aOrbiterI, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aIngress, 13U) + aOrbiterK) + RotL64(aOrbiterI, 13U)) + RotL64(aCarry, 39U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 27U) + RotL64(aOrbiterK, 41U)) + aOrbiterG) + aWandererUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aPrevious, 4U) + aOrbiterA) + RotL64(aOrbiterB, 51U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 39U) + RotL64(aOrbiterD, 35U)) + aOrbiterG) + aNonceWordH);
            aWandererJ = aWandererJ + (((RotL64(aCross, 47U) + RotL64(aOrbiterC, 28U)) + aOrbiterK) + aNonceWordK);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 53U) + aOrbiterD) + RotL64(aOrbiterI, 19U)) + aNonceWordN);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 21U) + aOrbiterA) + RotL64(aOrbiterC, 57U)) + RotL64(aCarry, 23U)) + aWandererUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 11U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 47U));
            aCarry = aCarry + (RotL64(aWandererK, 36U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererD, 23U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 2
        // ingress from: aExpandLaneA, aWorkLaneC, aOperationLaneB
        // ingress directions: aExpandLaneA forward forced, aWorkLaneC forward forced, aOperationLaneB forward/backward random
        // cross from: aWorkLaneA, aWorkLaneD, aFireLaneC
        // cross directions: aWorkLaneA backward forced, aWorkLaneD backward forced, aFireLaneC backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 12913U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneC[((aIndex + 11814U)) & S_BLOCK1], 12U));
            aIngress ^= RotL64(aOperationLaneB[((aIndex + 15434U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 9934U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 13090U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aFireLaneC[((aIndex + 9224U)) & S_BLOCK1], 4U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aPrevious, 4U) ^ RotL64(aCross, 21U)) ^ (RotL64(aIngress, 53U) + RotL64(aCarry, 39U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterG = (((aWandererA + RotL64(aCross, 54U)) + RotL64(aCarry, 3U)) + 18144572925667544139U) + aNonceWordK;
            aOrbiterI = (((aWandererI + RotL64(aScatter, 47U)) + 5659758077574059728U) + aOrbiterAssignSaltA[((aIndex + 13U)) & S_SALT1]) + aNonceWordA;
            aOrbiterA = ((((aWandererJ + RotL64(aIngress, 35U)) + RotL64(aCarry, 53U)) + 6343330616999166392U) + aOrbiterAssignSaltB[(((31U - aIndex) + 22U)) & S_SALT1]) + aNonceWordL;
            aOrbiterH = (aWandererG + RotL64(aPrevious, 29U)) + 17754639838410839447U;
            aOrbiterC = (aWandererD + RotL64(aScatter, 11U)) + 9451843819849581729U;
            aOrbiterF = (aWandererE + RotL64(aCross, 21U)) + 7957854457197462212U;
            aOrbiterB = (((aWandererF + RotL64(aPrevious, 41U)) + RotL64(aCarry, 21U)) + 1461994799722205010U) + aNonceWordG;
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 18002214276252170177U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 14689869073147027164U) ^ aOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12242482963989582191U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 3978104368003440293U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 8512135845221335386U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 10506667163729414667U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 1477533446382953439U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 2166717790929947990U;
            aOrbiterB = RotL64((aOrbiterB * 6538884492418324461U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 8082437060686606995U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 4363687722464700362U) ^ aNonceWordB;
            aOrbiterG = RotL64((aOrbiterG * 7199165810993478887U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 15782763348014924206U) + aOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 8572509150015960728U;
            aOrbiterF = RotL64((aOrbiterF * 3340528604891897779U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 12248271773316742521U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 9602078627638561949U) ^ aNonceWordC;
            aOrbiterI = RotL64((aOrbiterI * 1860631869877427405U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 17244849374768558859U) + aNonceWordH;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 1030743048280579012U;
            aOrbiterH = RotL64((aOrbiterH * 10858949914285817051U), 35U);
            //
            aIngress = RotL64(aOrbiterA, 47U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 57U));
            aIngress = aIngress + (RotL64(aOrbiterI, 11U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterH, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aCross, 43U) + aOrbiterC) + RotL64(aOrbiterB, 41U)) + aNonceWordN);
            aWandererG = aWandererG + (((RotL64(aIngress, 29U) + RotL64(aOrbiterI, 53U)) + aOrbiterB) + aNonceWordE);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 22U) + aOrbiterI) + RotL64(aOrbiterG, 20U)) + aWandererUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aScatter, 57U) + aOrbiterA) + RotL64(aOrbiterG, 35U)) + RotL64(aCarry, 19U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 13U) + RotL64(aOrbiterH, 47U)) + aOrbiterA) + aNonceWordM);
            aWandererF = aWandererF + ((((RotL64(aCross, 3U) + RotL64(aOrbiterG, 27U)) + aOrbiterH) + RotL64(aCarry, 51U)) + aWandererUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 37U) + aOrbiterF) + RotL64(aOrbiterB, 11U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 52U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererD, 5U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererA, 11U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererJ, 19U);
            aCarry = aCarry + RotL64(aIngress, 56U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 3
        // ingress from: aExpandLaneB, aWorkLaneD, aOperationLaneC
        // ingress directions: aExpandLaneB forward forced, aWorkLaneD forward forced, aOperationLaneC forward/backward random
        // cross from: aExpandLaneA, aWorkLaneB, aOperationLaneD
        // cross directions: aExpandLaneA backward forced, aWorkLaneB backward forced, aOperationLaneD backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 16908U)) & S_BLOCK1], 58U) ^ RotL64(aWorkLaneD[((aIndex + 16390U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aOperationLaneC[((aIndex + 19408U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 21768U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 21449U)) & S_BLOCK1], 53U));
            aCross ^= RotL64(aOperationLaneD[((aIndex + 21775U)) & S_BLOCK1], 12U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aIngress, 27U) ^ RotL64(aCross, 54U)) + (RotL64(aPrevious, 39U) ^ RotL64(aCarry, 11U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterJ = ((aWandererE + RotL64(aCross, 13U)) + 18302975933754610273U) + aOrbiterAssignSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterF = ((aWandererG + RotL64(aIngress, 34U)) + 16736972646771456082U) + aNonceWordP;
            aOrbiterA = (((aWandererD + RotL64(aPrevious, 3U)) + RotL64(aCarry, 53U)) + 17389406266488137442U) + aNonceWordI;
            aOrbiterB = (aWandererA + RotL64(aScatter, 27U)) + 5252511566486165539U;
            aOrbiterK = (((aWandererI + RotL64(aIngress, 47U)) + RotL64(aCarry, 39U)) + 5730715427422747640U) + aNonceWordJ;
            aOrbiterD = ((aWandererC + RotL64(aCross, 53U)) + RotL64(aCarry, 23U)) + 6412695646456045825U;
            aOrbiterI = ((aWandererK + RotL64(aScatter, 41U)) + 9539701605708994494U) + aOrbiterAssignSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 18355107116412945722U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 11735742491750132942U;
            aOrbiterA = RotL64((aOrbiterA * 18129835093627763685U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 12363819388562658842U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 5861430292304371543U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 12989055611235382695U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 15027487084595017708U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterK) ^ 7012850020745791926U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterB = RotL64((aOrbiterB * 15952928839355613939U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 11904871669287886120U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 11199760114477343208U;
            aOrbiterJ = RotL64((aOrbiterJ * 7156374911847525867U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 3856004502263742700U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 3705931243173921893U;
            aOrbiterD = RotL64((aOrbiterD * 10334871178498711485U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 12305785390539209389U) + aNonceWordH;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 18057980996551978823U;
            aOrbiterI = RotL64((aOrbiterI * 4850564181113470859U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 3229431819292153014U) + aOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = (((aOrbiterK ^ aOrbiterA) ^ 2994716629242460094U) ^ aOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterK = RotL64((aOrbiterK * 1029427328395257917U), 19U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterA, 11U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 30U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 5U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterB, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aScatter, 20U) + RotL64(aOrbiterB, 19U)) + aOrbiterD) + aWandererUpdateSaltB[((aIndex + 17U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 47U) + RotL64(aOrbiterK, 41U)) + aOrbiterI) + RotL64(aCarry, 43U)) + aNonceWordG);
            aWandererI = aWandererI ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterD, 5U)) + aOrbiterJ);
            aWandererG = aWandererG + (((RotL64(aIngress, 27U) + RotL64(aOrbiterI, 35U)) + aOrbiterF) + RotL64(aCarry, 57U));
            aWandererA = aWandererA ^ ((((RotL64(aCross, 57U) + RotL64(aOrbiterF, 26U)) + aOrbiterA) + aNonceWordE) + aWandererUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 3U) + aOrbiterA) + RotL64(aOrbiterJ, 47U)) + aNonceWordA);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterJ, 11U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 43U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 23U));
            aCarry = aCarry + (RotL64(aWandererK, 30U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererC, 19U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aFireLaneA
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aFireLaneA forward/backward random
        // cross from: aExpandLaneB, aWorkLaneC, aFireLaneD
        // cross directions: aExpandLaneB backward forced, aWorkLaneC backward forced, aFireLaneD backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 28623U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneA[((aIndex + 30186U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 27341U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 26951U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 31279U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 30930U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCarry, 35U) + RotL64(aPrevious, 51U)) + (RotL64(aCross, 4U) ^ RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterF = ((aWandererH + RotL64(aIngress, 11U)) + 1888427424966603593U) + aOrbiterAssignSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterK = ((aWandererD + RotL64(aScatter, 29U)) + 5436761445660415091U) + aNonceWordA;
            aOrbiterJ = (((aWandererE + RotL64(aCross, 23U)) + RotL64(aCarry, 5U)) + 17322876217962143270U) + aOrbiterAssignSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = (((aWandererA + RotL64(aPrevious, 57U)) + RotL64(aCarry, 19U)) + 9728299982740564979U) + aNonceWordB;
            aOrbiterH = (((aWandererC + RotL64(aScatter, 36U)) + RotL64(aCarry, 53U)) + 301720335271716921U) + aNonceWordN;
            aOrbiterG = (aWandererI + RotL64(aCross, 43U)) + 8069685428854814396U;
            aOrbiterI = ((aWandererK + RotL64(aIngress, 5U)) + 1973715500949100991U) + aNonceWordI;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 87666408799854155U) + aNonceWordO;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 12195436904339035245U;
            aOrbiterJ = RotL64((aOrbiterJ * 15427739165893738105U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 4578742069143400295U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 7828776048774876484U) ^ aOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4047964518501081039U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 17203146364542781833U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 16913369550858890466U;
            aOrbiterH = RotL64((aOrbiterH * 13534417587921978507U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 9632761514552265402U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 9106637671877341286U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 9073709119482640391U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 15423680889126750876U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 6087310684583331882U;
            aOrbiterC = RotL64((aOrbiterC * 8964465129744898619U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 5420955876411796789U) + aNonceWordH;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 14166807419730848032U) ^ aNonceWordD;
            aOrbiterG = RotL64((aOrbiterG * 442659738632823751U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 8118312450347026824U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterH) ^ 4253043584558403086U) ^ aOrbiterUpdateSaltF[((aIndex + 24U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterK = RotL64((aOrbiterK * 5651748455190536467U), 57U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterJ, 43U);
            aIngress = aIngress + (RotL64(aOrbiterK, 3U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterH, 60U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterI, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aScatter, 27U) + RotL64(aOrbiterI, 13U)) + aOrbiterJ) + aNonceWordK);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 41U) + aOrbiterF) + RotL64(aOrbiterJ, 3U)) + RotL64(aCarry, 51U)) + aNonceWordP);
            aWandererC = aWandererC ^ ((RotL64(aCross, 47U) + aOrbiterK) + RotL64(aOrbiterH, 57U));
            aWandererK = aWandererK + (((RotL64(aIngress, 54U) + aOrbiterF) + RotL64(aOrbiterC, 39U)) + aNonceWordM);
            aWandererH = aWandererH ^ ((((RotL64(aCross, 21U) + RotL64(aOrbiterG, 29U)) + aOrbiterC) + aNonceWordE) + aWandererUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aScatter, 11U) + aOrbiterG) + RotL64(aOrbiterH, 23U)) + RotL64(aCarry, 35U)) + aWandererUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 3U) + aOrbiterK) + RotL64(aOrbiterF, 50U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 18U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 41U));
            aCarry = aCarry + (RotL64(aWandererK, 3U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererD, 35U);
            aCarry = aCarry + RotL64(aIngress, 52U);
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

void TwistExpander_BasketBall_Arx::Seed_A(TwistWorkSpace *pWorkSpace,
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
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltE;
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
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltF;
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
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltC;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xDDB5881DFF756DEDULL + 0xCBA8BA48D72CE0CEULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xEE3FB445EDB89083ULL + 0x816B6002D4069502ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xC783A9CD1ED02CCDULL + 0xC1C509CC9EAF1A1CULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xEE1C892E64CE29F5ULL + 0xBA265407C0E0EE62ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xE3CB0F0DF075543DULL + 0xB7C285B77C3D7871ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xA39DB9F16646D155ULL + 0xFFF5A9D2160D1B7EULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xF0ABE91F1CD50423ULL + 0x96C1A183877D661DULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xD68B2F6B657AC7E3ULL + 0xDECABD851961A013ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xF4DFD08DFBC8D52BULL + 0xEA4B96BBBCB2D2F3ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x85E5E6AA3BBD37B7ULL + 0xE577D5BD8733A2F9ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xAA85C10335AA3261ULL + 0x852A39A40D0CF096ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x85939007EDC509B3ULL + 0x91C08377CA5F68D9ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0x8F6C384A8E06A4A3ULL + 0xBBCCB1DD922DF792ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xDDAEBA9C79021109ULL + 0x883B4AF8001DC12CULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x9000D9F06DB83559ULL + 0xF4848F9BE4983C5FULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0x9C7482A58458D409ULL + 0xE6090BFD2CDE5763ULL);
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
            aIngress = RotL64(aKeyRowReadA[((aIndex + 2007U)) & W_KEY1], 51U) ^ RotL64(aKeyRowReadB[((aIndex + 929U)) & W_KEY1], 43U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 2406U)) & W_KEY1], 6U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 2193U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCross, 23U) + RotL64(aIngress, 5U)) + (RotL64(aPrevious, 56U) ^ RotL64(aCarry, 35U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterF = (aWandererA + RotL64(aIngress, 57U)) + 4739486756133131180U;
            aOrbiterJ = ((((aWandererH + RotL64(aPrevious, 43U)) + RotL64(aCarry, 3U)) + 16089707555501328184U) + aPhaseEOrbiterAssignSaltE[((aIndex + 17U)) & S_SALT1]) + aNonceWordD;
            aOrbiterE = ((aWandererF + RotL64(aCross, 5U)) + RotL64(aCarry, 47U)) + 15310047330238536453U;
            aOrbiterC = ((aWandererJ + RotL64(aScatter, 30U)) + RotL64(aCarry, 29U)) + 7901411596386834955U;
            aOrbiterH = (aWandererE + RotL64(aIngress, 13U)) + 4357555491060982163U;
            aOrbiterK = (((aWandererD + RotL64(aScatter, 37U)) + 15667085602825720102U) + aPhaseEOrbiterAssignSaltB[((aIndex + 12U)) & S_SALT1]) + aNonceWordP;
            aOrbiterG = ((aWandererG + RotL64(aPrevious, 21U)) + 8520635334382269253U) + aNonceWordC;
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 1772509779231068315U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 15336170957886025677U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 10996880551392077399U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 8628770833489469980U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 15469234024247246228U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8905266995119987947U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 10796430900884288328U) + aNonceWordJ;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 10660110397012853289U;
            aOrbiterC = RotL64((aOrbiterC * 9140007610912037461U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 11202284258711214794U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterG = (((aOrbiterG ^ aOrbiterE) ^ 17509491802893182994U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterG = RotL64((aOrbiterG * 9329107599972703671U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 16212572740740103554U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 2190030203761579226U) ^ aNonceWordG;
            aOrbiterF = RotL64((aOrbiterF * 3101886685668871045U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 12014337082293041909U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 3733531010807001506U;
            aOrbiterK = RotL64((aOrbiterK * 5797362244066062299U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 7100994963061975529U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 17837541162838600258U;
            aOrbiterJ = RotL64((aOrbiterJ * 8745987361678166553U), 5U);
            //
            aIngress = RotL64(aOrbiterG, 27U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 53U));
            aIngress = aIngress + (RotL64(aOrbiterK, 60U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterJ, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aScatter, 37U) + aOrbiterJ) + RotL64(aOrbiterG, 28U)) + aNonceWordM);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterG, 47U)) + aOrbiterK) + aPhaseEWandererUpdateSaltF[((aIndex + 7U)) & S_SALT1]);
            aWandererE = aWandererE + (((((RotL64(aIngress, 3U) + aOrbiterH) + RotL64(aOrbiterF, 19U)) + RotL64(aCarry, 3U)) + aNonceWordL) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterF, 3U)) + aOrbiterJ);
            aWandererF = aWandererF + ((((RotL64(aScatter, 19U) + RotL64(aOrbiterK, 13U)) + aOrbiterE) + RotL64(aCarry, 47U)) + aNonceWordB);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterH, 57U)) + aOrbiterK);
            aWandererH = aWandererH + (((RotL64(aIngress, 58U) + RotL64(aOrbiterC, 35U)) + aOrbiterH) + aNonceWordA);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 52U));
            aCarry = aCarry + (RotL64(aWandererF, 39U) ^ aWandererA);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 57U));
            aCarry = aCarry + RotL64(aWandererJ, 43U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 5302U)) & S_BLOCK1], 11U) ^ RotL64(aKeyRowReadA[((aIndex + 3055U)) & W_KEY1], 60U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 4170U)) & W_KEY1], 6U) ^ RotL64(mSource[((aIndex + 4558U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCarry, 27U) + RotL64(aIngress, 6U)) ^ (RotL64(aCross, 43U) ^ RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterF = (aWandererI + RotL64(aScatter, 35U)) + 1888427424966603593U;
            aOrbiterA = ((((aWandererD + RotL64(aIngress, 46U)) + RotL64(aCarry, 39U)) + 5436761445660415091U) + aPhaseEOrbiterAssignSaltA[((aIndex + 7U)) & S_SALT1]) + aNonceWordA;
            aOrbiterE = (aWandererJ + RotL64(aCross, 13U)) + 17322876217962143270U;
            aOrbiterK = (((aWandererB + RotL64(aPrevious, 19U)) + 9728299982740564979U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordP;
            aOrbiterH = (((aWandererF + RotL64(aCross, 27U)) + RotL64(aCarry, 23U)) + 301720335271716921U) + aNonceWordK;
            aOrbiterC = (aWandererA + RotL64(aScatter, 5U)) + 8069685428854814396U;
            aOrbiterD = ((aWandererE + RotL64(aPrevious, 57U)) + RotL64(aCarry, 51U)) + 1973715500949100991U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 87666408799854155U) + aNonceWordB;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 12195436904339035245U;
            aOrbiterE = RotL64((aOrbiterE * 15427739165893738105U), 41U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterF) + 4578742069143400295U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordG;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 7828776048774876484U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4047964518501081039U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 17203146364542781833U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 16913369550858890466U) ^ aNonceWordO;
            aOrbiterK = RotL64((aOrbiterK * 13534417587921978507U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 9632761514552265402U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 9106637671877341286U;
            aOrbiterF = RotL64((aOrbiterF * 9073709119482640391U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 15423680889126750876U) + aNonceWordD;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 6087310684583331882U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8964465129744898619U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 5420955876411796789U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 14166807419730848032U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 442659738632823751U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 8118312450347026824U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 4253043584558403086U;
            aOrbiterA = RotL64((aOrbiterA * 5651748455190536467U), 47U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterH, 47U);
            aIngress = aIngress + (RotL64(aOrbiterE, 3U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterA, 39U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterK, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aPrevious, 51U) + RotL64(aOrbiterF, 3U)) + aOrbiterC);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 21U) + RotL64(aOrbiterH, 35U)) + aOrbiterA) + aPhaseEWandererUpdateSaltC[((aIndex + 9U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aIngress, 27U) + aOrbiterK) + RotL64(aOrbiterE, 27U)) + aNonceWordF);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 35U) + aOrbiterF) + RotL64(aOrbiterH, 51U)) + aNonceWordI);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 58U) + aOrbiterH) + RotL64(aOrbiterD, 12U)) + RotL64(aCarry, 13U)) + aNonceWordM);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 13U) + aOrbiterD) + RotL64(aOrbiterC, 41U));
            aWandererI = aWandererI + ((((RotL64(aCross, 43U) + RotL64(aOrbiterH, 21U)) + aOrbiterE) + RotL64(aCarry, 53U)) + aPhaseEWandererUpdateSaltB[((aIndex + 4U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 35U) ^ aWandererD);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 44U));
            aCarry = aCarry + (RotL64(aWandererI, 19U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererF, 57U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = RotL64(aWorkLaneB[((aIndex + 5724U)) & S_BLOCK1], 3U) ^ RotL64(aKeyRowReadB[((aIndex + 8105U)) & W_KEY1], 22U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 7975U)) & W_KEY1], 37U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 7473U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 7957U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCarry, 57U) + RotL64(aPrevious, 43U)) ^ (RotL64(aIngress, 13U) + RotL64(aCross, 28U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterB = ((aWandererE + RotL64(aIngress, 13U)) + 6467297102954816305U) + aNonceWordB;
            aOrbiterI = (((aWandererD + RotL64(aCross, 3U)) + RotL64(aCarry, 43U)) + 7921154109831114952U) + aNonceWordL;
            aOrbiterH = (((aWandererH + RotL64(aScatter, 39U)) + 5701131763215638919U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordI;
            aOrbiterD = (aWandererF + RotL64(aPrevious, 47U)) + 10022999076719002684U;
            aOrbiterJ = (((aWandererB + RotL64(aIngress, 23U)) + RotL64(aCarry, 29U)) + 4367135243038982316U) + aPhaseEOrbiterAssignSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterK = ((aWandererK + RotL64(aPrevious, 60U)) + RotL64(aCarry, 11U)) + 14445846824810383592U;
            aOrbiterF = ((aWandererG + RotL64(aCross, 53U)) + 7683697954545773253U) + aNonceWordJ;
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 17517006750428030899U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 2052484792684025476U;
            aOrbiterH = RotL64((aOrbiterH * 12463117571122469643U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 6279463052085808926U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 679280153651813684U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 3047031560593583881U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 2939516520188460569U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 1960616434964712325U) ^ aNonceWordO;
            aOrbiterB = RotL64((aOrbiterB * 15145998415466343039U), 27U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 12273819390719947361U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 5685033154709449397U) ^ aNonceWordF;
            aOrbiterF = RotL64((aOrbiterF * 9845666295874714959U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 9314494172199500653U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 15757631834636427621U;
            aOrbiterJ = RotL64((aOrbiterJ * 15483543888965744529U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 10878078046389399574U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 3583495913766365232U) ^ aNonceWordE;
            aOrbiterI = RotL64((aOrbiterI * 2913540984990155225U), 41U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterJ) + 7385544065754622301U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1]) + aNonceWordK;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 16839599460207922881U;
            aOrbiterK = RotL64((aOrbiterK * 240651605910592561U), 51U);
            //
            aIngress = RotL64(aOrbiterJ, 21U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 29U));
            aIngress = aIngress + (RotL64(aOrbiterH, 57U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterI, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterF, 11U)) + aOrbiterH);
            aWandererG = aWandererG + (((RotL64(aScatter, 27U) + RotL64(aOrbiterD, 60U)) + aOrbiterH) + RotL64(aCarry, 43U));
            aWandererE = aWandererE ^ ((((RotL64(aCross, 13U) + aOrbiterH) + RotL64(aOrbiterB, 37U)) + aNonceWordP) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aIngress, 48U) + aOrbiterK) + RotL64(aOrbiterJ, 23U)) + RotL64(aCarry, 3U)) + aNonceWordM);
            aWandererB = aWandererB ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterJ, 53U)) + aOrbiterF);
            aWandererH = aWandererH + ((RotL64(aPrevious, 35U) + RotL64(aOrbiterH, 47U)) + aOrbiterI);
            aWandererD = aWandererD ^ ((((RotL64(aScatter, 3U) + RotL64(aOrbiterK, 5U)) + aOrbiterB) + aNonceWordC) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 57U) ^ aWandererF);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 48U));
            aCarry = aCarry + (RotL64(aWandererE, 43U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererG, 21U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 8349U)) & S_BLOCK1], 35U) ^ RotL64(aKeyRowReadB[((aIndex + 9062U)) & W_KEY1], 19U));
            aIngress ^= (RotL64(mSource[((aIndex + 10295U)) & S_BLOCK1], 6U) ^ RotL64(aWorkLaneA[((aIndex + 9704U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 10859U)) & W_KEY1], 18U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 8732U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aPrevious, 57U) ^ RotL64(aCarry, 27U)) ^ (RotL64(aIngress, 39U) + RotL64(aCross, 10U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterD = (((aWandererD + RotL64(aScatter, 51U)) + 15188686795415908074U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordN;
            aOrbiterK = ((aWandererG + RotL64(aCross, 4U)) + RotL64(aCarry, 23U)) + 17310049041983079779U;
            aOrbiterB = ((aWandererB + RotL64(aPrevious, 29U)) + 8246925977992441471U) + aNonceWordI;
            aOrbiterJ = ((((aWandererK + RotL64(aIngress, 57U)) + RotL64(aCarry, 5U)) + 8644260919918112781U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 4U)) & S_SALT1]) + aNonceWordL;
            aOrbiterH = (aWandererA + RotL64(aCross, 23U)) + 13401663736874819483U;
            aOrbiterE = (((aWandererF + RotL64(aPrevious, 37U)) + RotL64(aCarry, 51U)) + 7940358935238314973U) + aNonceWordG;
            aOrbiterI = (aWandererC + RotL64(aIngress, 11U)) + 13278990328548007839U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 11346868298353840706U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 2374077904806833579U;
            aOrbiterB = RotL64((aOrbiterB * 1765686942154321425U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 6978903378645019166U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 11951633297870965212U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 12778236598654492185U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 17398460995357409673U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 1215437945597836770U;
            aOrbiterK = RotL64((aOrbiterK * 9322970054123481621U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 1878751468043972239U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 5343002808239712390U) ^ aNonceWordA;
            aOrbiterD = RotL64((aOrbiterD * 11878640995447558811U), 41U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 9884918450053276861U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterE = (((aOrbiterE ^ aOrbiterJ) ^ 15894599082080422550U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterE = RotL64((aOrbiterE * 8359936745539546131U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 13917339232771145459U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterB) ^ 18101134009493720683U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterI = RotL64((aOrbiterI * 15835859435306756387U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 3830086372356903769U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 15894394599564584010U;
            aOrbiterH = RotL64((aOrbiterH * 9513921913446609263U), 29U);
            //
            aIngress = RotL64(aOrbiterD, 13U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterK, 29U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterB, 3U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterI, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((((RotL64(aCross, 21U) + aOrbiterH) + RotL64(aOrbiterE, 57U)) + aNonceWordO) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 51U) + RotL64(aOrbiterK, 35U)) + aOrbiterH) + aNonceWordC) + aPhaseFWandererUpdateSaltF[((aIndex + 5U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 43U) + aOrbiterK) + RotL64(aOrbiterJ, 5U)) + aNonceWordK);
            aWandererB = aWandererB + (((RotL64(aIngress, 37U) + aOrbiterI) + RotL64(aOrbiterE, 43U)) + RotL64(aCarry, 51U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterB, 29U)) + aOrbiterD);
            aWandererC = aWandererC + (((RotL64(aPrevious, 13U) + aOrbiterB) + RotL64(aOrbiterI, 18U)) + RotL64(aCarry, 11U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 30U) + aOrbiterB) + RotL64(aOrbiterJ, 11U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 48U) ^ aWandererA);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 41U));
            aCarry = aCarry + (RotL64(aWandererD, 57U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererB, 13U);
            aCarry = aCarry + RotL64(aIngress, 18U);
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
            aIngress = (RotL64(aWorkLaneD[((aIndex + 11200U)) & S_BLOCK1], 39U) ^ RotL64(aKeyRowReadA[((aIndex + 11821U)) & W_KEY1], 3U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 13255U)) & W_KEY1], 47U) ^ RotL64(mSource[((aIndex + 12917U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 11178U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 11582U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 12501U)) & S_BLOCK1], 56U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCarry, 39U) ^ RotL64(aIngress, 53U)) + (RotL64(aPrevious, 23U) ^ RotL64(aCross, 10U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterC = (aWandererF + RotL64(aCross, 37U)) + 16189787374324972735U;
            aOrbiterF = (((aWandererD + RotL64(aPrevious, 23U)) + RotL64(aCarry, 13U)) + 17563763730956242224U) + aNonceWordN;
            aOrbiterK = ((((aWandererA + RotL64(aScatter, 4U)) + RotL64(aCarry, 39U)) + 10572803498593789385U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordD;
            aOrbiterJ = ((aWandererG + RotL64(aIngress, 29U)) + 7713105232072974166U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = ((aWandererE + RotL64(aPrevious, 57U)) + 10760839534772718139U) + aNonceWordP;
            aOrbiterI = (((aWandererI + RotL64(aCross, 43U)) + RotL64(aCarry, 51U)) + 13397069448391230253U) + aNonceWordK;
            aOrbiterE = (aWandererH + RotL64(aIngress, 13U)) + 4569255679998375682U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 9888769350817876949U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = (((aOrbiterK ^ aOrbiterC) ^ 11351796060878856300U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterK = RotL64((aOrbiterK * 13356749147334008399U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 18153775071965707204U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 1282846411145853435U;
            aOrbiterG = RotL64((aOrbiterG * 12294455920906257823U), 27U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterC) + 16457743979262460660U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1]) + aNonceWordM;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 173493260775251032U;
            aOrbiterI = RotL64((aOrbiterI * 4935807229040883505U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 3927345926316409630U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 5158769729850853623U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2446452358663812945U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 12331351600010165154U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 3940794200348684050U;
            aOrbiterC = RotL64((aOrbiterC * 13248997263062075043U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 11248514843822945425U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 1391497323278226522U;
            aOrbiterJ = RotL64((aOrbiterJ * 8376841806072565005U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 13265623528678787307U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 2802033745265647317U;
            aOrbiterE = RotL64((aOrbiterE * 3437626962562016147U), 21U);
            //
            aIngress = RotL64(aOrbiterK, 53U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 19U));
            aIngress = aIngress + (RotL64(aOrbiterG, 47U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterF, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aCross, 21U) + aOrbiterF) + RotL64(aOrbiterI, 11U)) + aNonceWordC);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterG, 51U)) + aOrbiterC);
            aWandererH = aWandererH + (((RotL64(aIngress, 57U) + aOrbiterJ) + RotL64(aOrbiterE, 3U)) + RotL64(aCarry, 37U));
            aWandererI = aWandererI ^ ((((RotL64(aPrevious, 51U) + aOrbiterG) + RotL64(aOrbiterE, 37U)) + aNonceWordF) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aCross, 35U) + aOrbiterJ) + RotL64(aOrbiterF, 27U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 43U) + aOrbiterK) + RotL64(aOrbiterC, 19U)) + aPhaseFWandererUpdateSaltB[((aIndex + 15U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 14U) + RotL64(aOrbiterC, 60U)) + aOrbiterI) + RotL64(aCarry, 11U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 47U));
            aCarry = aCarry + (RotL64(aWandererH, 13U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererG, 6U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererA, 39U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 15444U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneC[((aIndex + 15760U)) & S_BLOCK1], 30U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 13836U)) & W_KEY1], 39U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 15909U)) & W_KEY1], 29U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 14925U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 14618U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 14988U)) & S_BLOCK1], 60U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCarry, 56U) ^ RotL64(aPrevious, 37U)) ^ (RotL64(aIngress, 11U) + RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterG = ((aWandererK + RotL64(aPrevious, 13U)) + 11177787645248006236U) + aPhaseFOrbiterAssignSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterC = ((aWandererD + RotL64(aScatter, 58U)) + 3808340254579817169U) + aNonceWordL;
            aOrbiterA = (((aWandererH + RotL64(aIngress, 21U)) + RotL64(aCarry, 3U)) + 828030667598518279U) + aNonceWordA;
            aOrbiterK = (((aWandererG + RotL64(aCross, 27U)) + RotL64(aCarry, 21U)) + 16177835921238398371U) + aNonceWordN;
            aOrbiterB = (aWandererA + RotL64(aScatter, 3U)) + 5518747735458708741U;
            aOrbiterF = ((aWandererF + RotL64(aIngress, 43U)) + 17346319082399995165U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterI = ((aWandererE + RotL64(aPrevious, 35U)) + RotL64(aCarry, 41U)) + 6397156921893030937U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 15559381654710713582U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 940404446491415088U;
            aOrbiterA = RotL64((aOrbiterA * 16401260971303026881U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 8047166032048732645U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterG = (((aOrbiterG ^ aOrbiterK) ^ 4688468645859470491U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterG = RotL64((aOrbiterG * 14383536431614496369U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 3710878044770337260U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 116343189456629220U) ^ aNonceWordG;
            aOrbiterF = RotL64((aOrbiterF * 5637725064169289339U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 883908030159391659U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 18058691521694880482U;
            aOrbiterC = RotL64((aOrbiterC * 3132200449123497619U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 17521015077103586117U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 3668332225435714918U) ^ aNonceWordF;
            aOrbiterK = RotL64((aOrbiterK * 12658899101297839881U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 12229480388278883300U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterF) ^ 16206524049491531816U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterI = RotL64((aOrbiterI * 11122340196620859805U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 5743265849441077466U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 2812293020719282236U;
            aOrbiterB = RotL64((aOrbiterB * 8903956475200417109U), 29U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterC, 41U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 27U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 57U));
            aIngress = aIngress + RotL64(aOrbiterG, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aScatter, 58U) + RotL64(aOrbiterI, 35U)) + aOrbiterF);
            aWandererG = aWandererG + (((RotL64(aPrevious, 3U) + aOrbiterI) + RotL64(aOrbiterK, 60U)) + aNonceWordP);
            aWandererK = aWandererK ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterF, 3U)) + aOrbiterG) + aNonceWordJ);
            aWandererF = aWandererF + ((((RotL64(aIngress, 51U) + RotL64(aOrbiterI, 53U)) + aOrbiterG) + RotL64(aCarry, 35U)) + aPhaseFWandererUpdateSaltD[((aIndex + 23U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterC, 47U)) + aOrbiterK);
            aWandererD = aWandererD + (((((RotL64(aPrevious, 43U) + RotL64(aOrbiterB, 27U)) + aOrbiterI) + RotL64(aCarry, 13U)) + aNonceWordM) + aPhaseFWandererUpdateSaltB[((aIndex + 24U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterB, 19U)) + aOrbiterA) + aNonceWordI);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 13U));
            aCarry = aCarry + (RotL64(aWandererF, 52U) ^ aWandererH);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 29U));
            aCarry = aCarry + RotL64(aWandererA, 19U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 18021U)) & S_BLOCK1], 19U) ^ RotL64(aKeyRowReadA[((aIndex + 17267U)) & W_KEY1], 56U));
            aIngress ^= (RotL64(mSource[((aIndex + 17953U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18266U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 17003U)) & W_KEY1], 43U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 17213U)) & S_BLOCK1], 30U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 17470U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 20U)) + (RotL64(aCross, 51U) ^ RotL64(aIngress, 35U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterK = ((aWandererA + RotL64(aScatter, 41U)) + RotL64(aCarry, 43U)) + 13053031069776604052U;
            aOrbiterF = ((aWandererC + RotL64(aPrevious, 23U)) + 1331396630251085122U) + aNonceWordH;
            aOrbiterB = ((((aWandererE + RotL64(aCross, 3U)) + RotL64(aCarry, 11U)) + 15879286043343942393U) + aPhaseGOrbiterAssignSaltB[((aIndex + 14U)) & S_SALT1]) + aNonceWordD;
            aOrbiterD = (aWandererJ + RotL64(aIngress, 54U)) + 13590365633321406830U;
            aOrbiterC = ((aWandererK + RotL64(aScatter, 29U)) + 14569235423040242618U) + aNonceWordC;
            aOrbiterA = (((aWandererF + RotL64(aIngress, 47U)) + RotL64(aCarry, 23U)) + 11397370636618371560U) + aPhaseGOrbiterAssignSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterE = (aWandererH + RotL64(aPrevious, 13U)) + 3455933494593971847U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 1307153376443784593U) + aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 10688618762584786871U;
            aOrbiterB = RotL64((aOrbiterB * 9503823896874842411U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 17746248451153600096U) + aNonceWordN;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 8512568600755410158U;
            aOrbiterC = RotL64((aOrbiterC * 16648320170768234063U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 8950230550112591092U) + aNonceWordP;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 17790968369472845496U;
            aOrbiterA = RotL64((aOrbiterA * 5104988920132008913U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 12583323865381967534U) + aNonceWordE;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 11243927099685293887U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 12867003042486433971U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 9690268715525781389U) + aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 7466066217365074653U) ^ aNonceWordG;
            aOrbiterD = RotL64((aOrbiterD * 17565696765505320889U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 3673528673209875118U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 14079103852360952255U;
            aOrbiterF = RotL64((aOrbiterF * 17449228863409999629U), 41U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 6747836856132250630U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 5027692924422297153U;
            aOrbiterE = RotL64((aOrbiterE * 2492421273167124437U), 57U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterE, 57U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 51U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 37U));
            aIngress = aIngress + RotL64(aOrbiterK, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aScatter, 35U) + RotL64(aOrbiterK, 35U)) + aOrbiterC) + aPhaseGWandererUpdateSaltE[((aIndex + 17U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterE, 43U)) + aOrbiterK);
            aWandererA = aWandererA + ((RotL64(aCross, 50U) + RotL64(aOrbiterK, 11U)) + aOrbiterD);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 21U) + RotL64(aOrbiterF, 60U)) + aOrbiterA) + aPhaseGWandererUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aPrevious, 3U) + aOrbiterD) + RotL64(aOrbiterB, 21U)) + RotL64(aCarry, 57U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 41U) + aOrbiterD) + RotL64(aOrbiterC, 27U)) + aNonceWordL);
            aWandererH = aWandererH + ((((RotL64(aCross, 11U) + aOrbiterE) + RotL64(aOrbiterA, 53U)) + RotL64(aCarry, 35U)) + aNonceWordJ);
            //
            aCarry = aCarry + (RotL64(aWandererK, 48U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererF, 37U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererH, 3U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererC, 43U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 19516U)) & S_BLOCK1], 3U) ^ RotL64(mSource[((aIndex + 20220U)) & S_BLOCK1], 19U));
            aIngress ^= (RotL64(aFireLaneA[((aIndex + 21694U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19835U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 20643U)) & W_KEY1], 27U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 21514U)) & W_KEY1], 57U));
            aCross ^= (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 21748U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneB[((aIndex + 21748U)) & S_BLOCK1], 4U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCross, 60U) ^ RotL64(aIngress, 11U)) + (RotL64(aPrevious, 29U) ^ RotL64(aCarry, 47U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterH = (((aWandererH + RotL64(aPrevious, 13U)) + RotL64(aCarry, 39U)) + 15920462086654025436U) + aNonceWordI;
            aOrbiterF = (aWandererC + RotL64(aCross, 54U)) + 487844076858004017U;
            aOrbiterB = (((aWandererB + RotL64(aIngress, 21U)) + RotL64(aCarry, 5U)) + 14502883786442630566U) + aNonceWordP;
            aOrbiterK = (((aWandererD + RotL64(aScatter, 37U)) + 3787107318658233674U) + aPhaseGOrbiterAssignSaltE[((aIndex + 3U)) & S_SALT1]) + aNonceWordH;
            aOrbiterJ = (((aWandererK + RotL64(aCross, 5U)) + RotL64(aCarry, 53U)) + 12548777544693755491U) + aPhaseGOrbiterAssignSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = ((aWandererA + RotL64(aPrevious, 27U)) + 4907309444075181683U) + aNonceWordO;
            aOrbiterA = (aWandererI + RotL64(aScatter, 47U)) + 18342396700266492072U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 13503051997624242670U) + aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 17845742460521374571U;
            aOrbiterB = RotL64((aOrbiterB * 1366356786138085155U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 8640887211877858169U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 5273913123709097537U) ^ aPhaseGOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 1661149444148461791U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 17756844173695563883U) + aNonceWordJ;
            aOrbiterG = (((aOrbiterG ^ aOrbiterJ) ^ 6713055830729302951U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterG = RotL64((aOrbiterG * 2832836748513174311U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 5106468334224035972U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 10228769728713526172U;
            aOrbiterK = RotL64((aOrbiterK * 9760310686414358435U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 7687649520668883142U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 7757480627354711605U;
            aOrbiterA = RotL64((aOrbiterA * 7222553727737349209U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 10876291698508634557U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 8149278085586014186U) ^ aNonceWordK;
            aOrbiterH = RotL64((aOrbiterH * 8577133863470695381U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 15592893988925610485U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 8639028256640537165U;
            aOrbiterF = RotL64((aOrbiterF * 1880655276432963955U), 21U);
            //
            aIngress = RotL64(aOrbiterB, 57U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 47U));
            aIngress = aIngress + (RotL64(aOrbiterK, 14U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterF, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aScatter, 21U) + RotL64(aOrbiterA, 13U)) + aOrbiterG) + aNonceWordM) + aPhaseGWandererUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((((RotL64(aPrevious, 37U) + RotL64(aOrbiterF, 5U)) + aOrbiterH) + aNonceWordA) + aPhaseGWandererUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aIngress, 27U) + RotL64(aOrbiterJ, 21U)) + aOrbiterG) + RotL64(aCarry, 57U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 56U) + aOrbiterF) + RotL64(aOrbiterJ, 43U)) + aNonceWordC);
            aWandererK = aWandererK + ((RotL64(aIngress, 43U) + RotL64(aOrbiterH, 27U)) + aOrbiterK);
            aWandererC = aWandererC ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterB, 60U)) + aOrbiterK);
            aWandererD = aWandererD + (((RotL64(aPrevious, 5U) + aOrbiterJ) + RotL64(aOrbiterB, 35U)) + RotL64(aCarry, 21U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 13U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererI, 51U) ^ aWandererH);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 18U));
            aCarry = aCarry + RotL64(aWandererA, 37U);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 22221U)) & S_BLOCK1], 18U) ^ RotL64(aKeyRowReadA[((aIndex + 21877U)) & W_KEY1], 51U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 22476U)) & W_KEY1], 27U) ^ RotL64(aFireLaneC[((aIndex + 23739U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 22089U)) & S_BLOCK1], 11U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 23892U)) & S_BLOCK1], 3U));
            aCross ^= (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 23916U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneD[((aIndex + 22383U)) & S_BLOCK1], 22U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCross, 3U) ^ RotL64(aIngress, 18U)) + (RotL64(aPrevious, 51U) + RotL64(aCarry, 35U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterA = ((aWandererH + RotL64(aScatter, 14U)) + 2101601659597850213U) + aPhaseGOrbiterAssignSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = (aWandererF + RotL64(aIngress, 39U)) + 2759794072560720121U;
            aOrbiterI = (((aWandererA + RotL64(aPrevious, 29U)) + RotL64(aCarry, 19U)) + 9443562552411269339U) + aNonceWordM;
            aOrbiterG = (aWandererC + RotL64(aCross, 21U)) + 10801360546699857975U;
            aOrbiterK = (((aWandererG + RotL64(aScatter, 5U)) + RotL64(aCarry, 35U)) + 8020716394829332019U) + aNonceWordL;
            aOrbiterB = (((aWandererJ + RotL64(aPrevious, 53U)) + 1021894212367773801U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordK;
            aOrbiterF = ((aWandererD + RotL64(aIngress, 47U)) + RotL64(aCarry, 47U)) + 13346855534622490176U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 16359309548462953836U) + aNonceWordH;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 12642446944680783519U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12197935153255283321U), 37U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 8197424982767553380U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 14346334610901859094U;
            aOrbiterA = RotL64((aOrbiterA * 16982899923227935679U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 14171304260534233539U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 334531601308283605U) ^ aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5012968232749075075U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 10707856298471572695U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 18364775750091914766U;
            aOrbiterD = RotL64((aOrbiterD * 15735143943129143265U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 8531394793118363836U) + aNonceWordD;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 15352876929406908882U;
            aOrbiterF = RotL64((aOrbiterF * 475199047053777179U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 567682016232278157U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 2068146551757663119U;
            aOrbiterK = RotL64((aOrbiterK * 1557877740957797555U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 7776122587613256525U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 16430938890724272256U) ^ aNonceWordI;
            aOrbiterG = RotL64((aOrbiterG * 4540270493783593257U), 3U);
            //
            aIngress = RotL64(aOrbiterG, 29U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 13U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 36U));
            aIngress = aIngress + RotL64(aOrbiterI, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aIngress, 37U) + aOrbiterI) + RotL64(aOrbiterF, 23U)) + aNonceWordF);
            aWandererC = aWandererC + (((RotL64(aCross, 29U) + aOrbiterG) + RotL64(aOrbiterK, 11U)) + RotL64(aCarry, 29U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 13U) + aOrbiterB) + RotL64(aOrbiterG, 5U)) + aNonceWordB);
            aWandererD = aWandererD + (((RotL64(aScatter, 4U) + RotL64(aOrbiterG, 30U)) + aOrbiterD) + RotL64(aCarry, 11U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 51U) + RotL64(aOrbiterD, 37U)) + aOrbiterB) + aPhaseGWandererUpdateSaltB[((aIndex + 19U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 43U) + RotL64(aOrbiterD, 47U)) + aOrbiterI) + aNonceWordC) + aPhaseGWandererUpdateSaltA[((aIndex + 27U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterI, 57U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererF, 41U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererJ, 26U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererH, 13U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererA, 57U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 26639U)) & S_BLOCK1], 43U) ^ RotL64(aKeyRowReadA[((aIndex + 25283U)) & W_KEY1], 13U));
            aIngress ^= (RotL64(aFireLaneD[((aIndex + 25799U)) & S_BLOCK1], 29U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 27157U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 27195U)) & W_KEY1], 53U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 27141U)) & S_BLOCK1], 20U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 24795U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 25789U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 52U)) + (RotL64(aCross, 21U) ^ RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterJ = (((aWandererI + RotL64(aScatter, 35U)) + RotL64(aCarry, 51U)) + 5295352595333316211U) + aNonceWordE;
            aOrbiterI = (aWandererJ + RotL64(aPrevious, 47U)) + 2341795367042042605U;
            aOrbiterF = ((((aWandererD + RotL64(aIngress, 19U)) + RotL64(aCarry, 37U)) + 10122175780504033663U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordG;
            aOrbiterG = ((aWandererE + RotL64(aCross, 5U)) + RotL64(aCarry, 19U)) + 10084612804696198554U;
            aOrbiterC = ((aWandererF + RotL64(aIngress, 54U)) + 16470424309851045971U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterK = ((aWandererB + RotL64(aPrevious, 13U)) + 656016130975227994U) + aNonceWordN;
            aOrbiterH = ((aWandererC + RotL64(aScatter, 27U)) + 15313268829659834317U) + aNonceWordJ;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 3795220914993923394U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 14044442220988813825U;
            aOrbiterF = RotL64((aOrbiterF * 3270650852546606835U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 3804224626734584802U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 7980006306010255693U) ^ aNonceWordK;
            aOrbiterK = RotL64((aOrbiterK * 13958505239726088561U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 13746830564584711549U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 11852212099729274845U;
            aOrbiterC = RotL64((aOrbiterC * 2164880979318247855U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 9083223471018084847U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 13706723820703853346U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 11361854103656219887U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 1713819986642275223U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 1382000168233902914U) ^ aNonceWordA;
            aOrbiterG = RotL64((aOrbiterG * 3894160765130198157U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 4540474625764565485U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 1756168174375757220U;
            aOrbiterI = RotL64((aOrbiterI * 12739160208010092017U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 1409297070183609309U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 6082750101445444357U) ^ aNonceWordH;
            aOrbiterH = RotL64((aOrbiterH * 17438740230251860935U), 35U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterF, 20U);
            aIngress = aIngress + (RotL64(aOrbiterK, 35U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterG, 43U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterH, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((((RotL64(aPrevious, 13U) + aOrbiterG) + RotL64(aOrbiterF, 28U)) + RotL64(aCarry, 23U)) + aNonceWordC) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 39U) + aOrbiterK) + RotL64(aOrbiterC, 21U));
            aWandererI = aWandererI + ((RotL64(aIngress, 27U) + aOrbiterK) + RotL64(aOrbiterH, 11U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 19U) + aOrbiterI) + RotL64(aOrbiterF, 3U)) + aNonceWordP);
            aWandererC = aWandererC + (((RotL64(aPrevious, 57U) + aOrbiterJ) + RotL64(aOrbiterH, 57U)) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterH, 47U)) + aOrbiterC);
            aWandererD = aWandererD + (((RotL64(aCross, 4U) + aOrbiterF) + RotL64(aOrbiterJ, 35U)) + RotL64(aCarry, 53U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 13U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererE, 46U) ^ aWandererF);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 23U));
            aCarry = aCarry + RotL64(aWandererJ, 37U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 27426U)) & S_BLOCK1], 21U) ^ RotL64(aFireLaneD[((aIndex + 28604U)) & S_BLOCK1], 51U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 27652U)) & W_KEY1], 34U) ^ RotL64(aFireLaneC[((aIndex + 29422U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 28057U)) & W_KEY1], 37U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 29755U)) & S_BLOCK1], 57U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 28381U)) & S_BLOCK1], 6U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 28200U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCross, 54U) + RotL64(aPrevious, 23U)) ^ (RotL64(aIngress, 3U) + RotL64(aCarry, 39U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterE = ((aWandererA + RotL64(aIngress, 11U)) + 8866844335448071821U) + aNonceWordO;
            aOrbiterK = (((aWandererG + RotL64(aCross, 3U)) + RotL64(aCarry, 57U)) + 15159698739856430085U) + aNonceWordL;
            aOrbiterA = ((aWandererK + RotL64(aScatter, 27U)) + 9582805772989594633U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = (aWandererC + RotL64(aPrevious, 43U)) + 1438538239931588373U;
            aOrbiterH = (((aWandererD + RotL64(aScatter, 60U)) + RotL64(aCarry, 11U)) + 10862044156620436139U) + aPhaseHOrbiterAssignSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = (((aWandererF + RotL64(aIngress, 19U)) + RotL64(aCarry, 29U)) + 13682173320058164615U) + aNonceWordP;
            aOrbiterJ = (aWandererJ + RotL64(aCross, 51U)) + 8351013291045977592U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 15777857431516633916U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 16178966745333885377U;
            aOrbiterA = RotL64((aOrbiterA * 7545129923202147703U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 9031889187993001617U) + aNonceWordI;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 6308472367425865347U) ^ aNonceWordC;
            aOrbiterE = RotL64((aOrbiterE * 17118710301967158153U), 53U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 642109145903321046U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 9186268569255318035U) ^ aNonceWordH;
            aOrbiterK = RotL64((aOrbiterK * 10714674348507516749U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 6091345356803675860U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 13218507921880873749U;
            aOrbiterJ = RotL64((aOrbiterJ * 15415157927185637717U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 4266652275234474616U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 4391422098164506195U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 17634679403195085867U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 5160682323243635577U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 10351728852161347404U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 11105410036471745951U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 3950932176454814023U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 9536466386833427441U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 18064984243491293435U), 47U);
            //
            aIngress = RotL64(aOrbiterH, 51U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 57U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 23U));
            aIngress = aIngress + RotL64(aOrbiterA, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aScatter, 47U) + aOrbiterH) + RotL64(aOrbiterK, 41U)) + aNonceWordA);
            aWandererF = aWandererF + (((RotL64(aCross, 27U) + aOrbiterK) + RotL64(aOrbiterD, 35U)) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterK, 53U)) + aOrbiterE) + aNonceWordN);
            aWandererA = aWandererA + ((((RotL64(aIngress, 56U) + aOrbiterA) + RotL64(aOrbiterJ, 27U)) + RotL64(aCarry, 3U)) + aNonceWordF);
            aWandererD = aWandererD ^ (((RotL64(aCross, 41U) + RotL64(aOrbiterD, 5U)) + aOrbiterH) + aPhaseHWandererUpdateSaltB[((aIndex + 17U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterJ, 60U)) + aOrbiterH) + RotL64(aCarry, 43U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterE, 21U)) + aOrbiterF) + aNonceWordM);
            //
            aCarry = aCarry + (RotL64(aWandererA, 52U) ^ aWandererC);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 29U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 13U));
            aCarry = aCarry + RotL64(aWandererF, 57U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 30640U)) & S_BLOCK1], 39U) ^ RotL64(aKeyRowReadA[((aIndex + 30388U)) & W_KEY1], 13U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 30442U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31035U)) & S_BLOCK1], 29U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31223U)) & S_BLOCK1], 54U) ^ RotL64(aKeyRowReadB[((aIndex + 32440U)) & W_KEY1], 21U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aPrevious, 3U) ^ RotL64(aCross, 41U)) ^ (RotL64(aIngress, 28U) + RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterE = ((aWandererA + RotL64(aIngress, 3U)) + RotL64(aCarry, 57U)) + 8604208734152026945U;
            aOrbiterB = ((((aWandererI + RotL64(aPrevious, 23U)) + RotL64(aCarry, 43U)) + 1374329953253889829U) + aPhaseHOrbiterAssignSaltB[((aIndex + 22U)) & S_SALT1]) + aNonceWordK;
            aOrbiterA = ((aWandererD + RotL64(aCross, 58U)) + 5779278910548228339U) + aPhaseHOrbiterAssignSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = ((aWandererC + RotL64(aScatter, 11U)) + RotL64(aCarry, 23U)) + 17670451230882805140U;
            aOrbiterC = (aWandererJ + RotL64(aPrevious, 43U)) + 8193848740764866860U;
            aOrbiterF = ((aWandererH + RotL64(aScatter, 29U)) + 15801168428145650104U) + aNonceWordL;
            aOrbiterG = ((aWandererE + RotL64(aIngress, 37U)) + 2584718176087499066U) + aNonceWordA;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 14950366247822737997U) + aNonceWordM;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 9779293225265670135U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11625969538497982117U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 8688968319288372383U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 13665723186950342601U;
            aOrbiterC = RotL64((aOrbiterC * 292035540396910837U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 9395428688359973510U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterF) ^ 2152719218018108418U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterG = RotL64((aOrbiterG * 15271961483518392671U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 1350324137411377992U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 8729317951386057921U) ^ aNonceWordB;
            aOrbiterB = RotL64((aOrbiterB * 6008790836417785083U), 37U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 6317310451893678411U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 10175620379041384281U;
            aOrbiterF = RotL64((aOrbiterF * 14079679617394330781U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 1203082119358827708U) + aNonceWordO;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 523869107818193101U;
            aOrbiterE = RotL64((aOrbiterE * 4629501113595689157U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 4028324959540432983U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 15447631947468213912U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 6037306615787729185U), 13U);
            //
            aIngress = RotL64(aOrbiterD, 58U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 39U));
            aIngress = aIngress + (RotL64(aOrbiterE, 21U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterF, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aIngress, 57U) + aOrbiterB) + RotL64(aOrbiterD, 43U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 36U) + RotL64(aOrbiterF, 11U)) + aOrbiterG) + RotL64(aCarry, 53U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 3U) + aOrbiterG) + RotL64(aOrbiterE, 19U));
            aWandererA = aWandererA + (((RotL64(aCross, 29U) + aOrbiterA) + RotL64(aOrbiterD, 60U)) + aNonceWordE);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterF, 5U)) + aOrbiterC) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((((RotL64(aCross, 21U) + aOrbiterA) + RotL64(aOrbiterC, 35U)) + RotL64(aCarry, 13U)) + aNonceWordH) + aPhaseHWandererUpdateSaltE[((aIndex + 12U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterD, 29U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 44U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 23U));
            aCarry = aCarry + (RotL64(aWandererA, 35U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererJ, 27U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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

void TwistExpander_BasketBall_Arx::Seed_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x8F035B7E92B0043DULL + 0x84AE1D48B57C049AULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x9C44B6154D14FD29ULL + 0xB49B7835284128DDULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xA226AEA51603D6B7ULL + 0xA656FC9AB6C0BBCCULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xD018BA0725B65DC5ULL + 0xCA8B6A82C840B15BULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xE219CAD6F697EC23ULL + 0x887AAB141E664AEAULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xABC6CF63863A0681ULL + 0xE24ACA9376CF57F5ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xA6B58F7E03317A29ULL + 0xD5BB3CA58C92D103ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xF6A2AA0A23E695FDULL + 0x8DED86AD4F0C07D4ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x9B5FB914C5AD83E5ULL + 0xF737E2BD07D545D0ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xE7C1E04D45D0EAA9ULL + 0x93EFE423684A547EULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xFBFE3EDE50CDB6C5ULL + 0x9ADAFFB14A5C1B37ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xABC01078A2782355ULL + 0xA4D0777BD1E228E2ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x87451F3E23F138F5ULL + 0x83C6C7E36F329C02ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xD4A67D3A1C1E169DULL + 0x87F88C8743D5CB3FULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xAE2FFBEA50D401FFULL + 0xF2AD63AFF7B4D269ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xDB8F8529F7C8E6ABULL + 0xD66EB7BD25DA56F2ULL);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 3438U)) & S_BLOCK1], 26U) ^ RotL64(aExpandLaneB[((aIndex + 1948U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 4957U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordE));
            //
            aCross = RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 2126U)) & S_BLOCK1], 22U) ^ RotL64(aExpandLaneD[((aIndex + 1170U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aIngress, 56U) + RotL64(aCarry, 5U)) ^ (RotL64(aPrevious, 37U) + RotL64(aCross, 19U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterA = ((aWandererG + RotL64(aPrevious, 29U)) + 13880995121909552664U) + aNonceWordK;
            aOrbiterB = ((((aWandererH + RotL64(aScatter, 51U)) + RotL64(aCarry, 35U)) + 14534942818069300546U) + aPhaseAOrbiterAssignSaltB[((aIndex + 15U)) & S_SALT1]) + aNonceWordF;
            aOrbiterG = ((aWandererA + RotL64(aIngress, 37U)) + 17745973100886007133U) + aNonceWordG;
            aOrbiterE = ((aWandererD + RotL64(aCross, 21U)) + RotL64(aCarry, 53U)) + 2249805580771946872U;
            aOrbiterK = ((((aWandererJ + RotL64(aIngress, 4U)) + RotL64(aCarry, 11U)) + 4460116116396439410U) + aPhaseAOrbiterAssignSaltC[((aIndex + 5U)) & S_SALT1]) + aNonceWordH;
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 3378683994078106878U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterA) ^ 3992996501048809123U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterG = RotL64((aOrbiterG * 13273544260537223797U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 12057768808864451929U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterG) ^ 4115362079047921130U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterK = RotL64((aOrbiterK * 12263015903331031345U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 15297384955502206698U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 17623548383481905636U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7487278217901483685U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 3559213898000162417U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 12311605719074507335U;
            aOrbiterA = RotL64((aOrbiterA * 3982199462062847697U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 14807313864347885885U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 11222085523291581822U) ^ aNonceWordI;
            aOrbiterB = RotL64((aOrbiterB * 12580941911587215653U), 21U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterG, 53U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 41U));
            aIngress = aIngress + RotL64(aOrbiterE, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aIngress, 3U) + aOrbiterG) + RotL64(aOrbiterB, 56U)) + aPhaseAWandererUpdateSaltA[((aIndex + 19U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 27U) + aOrbiterE) + RotL64(aOrbiterB, 35U)) + RotL64(aCarry, 37U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 12U) + aOrbiterK) + RotL64(aOrbiterB, 21U)) + aNonceWordB);
            aWandererG = aWandererG + (((((RotL64(aCross, 57U) + aOrbiterG) + RotL64(aOrbiterA, 3U)) + RotL64(aCarry, 3U)) + aNonceWordL) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 41U) + aOrbiterB) + RotL64(aOrbiterA, 47U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 29U) ^ aWandererH);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 38U));
            aCarry = aCarry + RotL64(aWandererD, 3U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 10703U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneC[((aIndex + 10201U)) & S_BLOCK1], 20U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 5994U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 10283U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneD[((aIndex + 7501U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aIngress, 3U) ^ RotL64(aCross, 23U)) + (RotL64(aCarry, 35U) + RotL64(aPrevious, 52U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterB = ((aWandererF + RotL64(aCross, 60U)) + RotL64(aCarry, 5U)) + 6654158889644956636U;
            aOrbiterI = (((aWandererJ + RotL64(aPrevious, 27U)) + RotL64(aCarry, 29U)) + 9045779659363991870U) + aNonceWordA;
            aOrbiterJ = ((aWandererE + RotL64(aIngress, 19U)) + 3888897662136993491U) + aPhaseAOrbiterAssignSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = (((aWandererA + RotL64(aScatter, 5U)) + RotL64(aCarry, 41U)) + 6882016842864459345U) + aNonceWordN;
            aOrbiterK = ((aWandererG + RotL64(aIngress, 37U)) + 15601891715956172291U) + aPhaseAOrbiterAssignSaltD[((aIndex + 4U)) & S_SALT1];
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 5176811598629335350U) + aNonceWordO;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 12519945150889074325U) ^ aNonceWordK;
            aOrbiterJ = RotL64((aOrbiterJ * 8721098129033306427U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 4552583214397603278U) + aNonceWordC;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 14225482701804864688U) ^ aNonceWordL;
            aOrbiterK = RotL64((aOrbiterK * 8526052833180466359U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 5485298070606280363U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 11237713257388094289U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11032429223099413011U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 14340345895626142788U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 16275167270553643347U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7308578867128951199U), 21U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 14041860597556520250U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 1436068974197066343U;
            aOrbiterB = RotL64((aOrbiterB * 3938460345031496843U), 11U);
            //
            aIngress = RotL64(aOrbiterK, 50U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 13U));
            aIngress = aIngress + RotL64(aOrbiterI, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aCross, 11U) + aOrbiterJ) + RotL64(aOrbiterK, 29U)) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 19U) + aOrbiterI) + RotL64(aOrbiterB, 38U)) + RotL64(aCarry, 35U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterG, 5U)) + aOrbiterJ);
            aWandererG = aWandererG + ((((RotL64(aScatter, 29U) + aOrbiterK) + RotL64(aOrbiterG, 51U)) + RotL64(aCarry, 57U)) + aNonceWordE);
            aWandererF = aWandererF ^ ((((RotL64(aIngress, 46U) + aOrbiterB) + RotL64(aOrbiterK, 19U)) + aNonceWordD) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + (RotL64(aWandererA, 5U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererG, 27U);
            aCarry = aCarry + RotL64(aIngress, 60U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 14994U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneD[((aIndex + 11519U)) & S_BLOCK1], 42U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 11617U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 12402U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 15779U)) & S_BLOCK1], 6U));
            aCross ^= RotL64(aExpandLaneA[((aIndex + 14333U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aPrevious, 13U) ^ RotL64(aCross, 57U)) ^ (RotL64(aCarry, 27U) + RotL64(aIngress, 42U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterA = ((aWandererF + RotL64(aPrevious, 47U)) + 10805654776556844351U) + aNonceWordC;
            aOrbiterC = (((aWandererJ + RotL64(aCross, 11U)) + RotL64(aCarry, 47U)) + 582794182442795335U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = ((((aWandererK + RotL64(aScatter, 24U)) + RotL64(aCarry, 13U)) + 2858343650974681068U) + aPhaseAOrbiterAssignSaltA[((aIndex + 4U)) & S_SALT1]) + aNonceWordE;
            aOrbiterH = ((aWandererB + RotL64(aIngress, 57U)) + RotL64(aCarry, 29U)) + 8189584049022064284U;
            aOrbiterJ = (aWandererE + RotL64(aScatter, 39U)) + 1565100751996962893U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 8062028016947611891U) + aNonceWordL;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 8280504280578451745U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 5212851648135050483U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 11326869194491655350U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 1671695656567777163U;
            aOrbiterJ = RotL64((aOrbiterJ * 7511554500524257921U), 37U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 2349843105293943452U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 13015545152052004254U;
            aOrbiterC = RotL64((aOrbiterC * 1316662811685429983U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 16703354404749291869U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 8713231044374305801U;
            aOrbiterH = RotL64((aOrbiterH * 9242480982197688625U), 11U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterJ) + 11118401674497783533U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordF;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 14857556493734710364U;
            aOrbiterA = RotL64((aOrbiterA * 3452566050389715195U), 3U);
            //
            aIngress = RotL64(aOrbiterH, 19U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 35U));
            aIngress = aIngress + RotL64(aOrbiterG, 6U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((((RotL64(aPrevious, 24U) + aOrbiterJ) + RotL64(aOrbiterH, 47U)) + aNonceWordP) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aIngress, 53U) + RotL64(aOrbiterJ, 19U)) + aOrbiterA) + RotL64(aCarry, 11U)) + aNonceWordM);
            aWandererE = aWandererE ^ (((RotL64(aCross, 13U) + aOrbiterA) + RotL64(aOrbiterC, 57U)) + aNonceWordA);
            aWandererF = aWandererF + (((RotL64(aScatter, 39U) + RotL64(aOrbiterA, 38U)) + aOrbiterG) + RotL64(aCarry, 37U));
            aWandererJ = aWandererJ ^ ((((RotL64(aPrevious, 5U) + aOrbiterG) + RotL64(aOrbiterC, 5U)) + aNonceWordN) + aPhaseAWandererUpdateSaltE[((aIndex + 14U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 57U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 13U));
            aCarry = aCarry + RotL64(aWandererE, 5U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 19099U)) & S_BLOCK1], 51U) ^ RotL64(aInvestLaneA[((aIndex + 20462U)) & S_BLOCK1], 30U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 16984U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 16523U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 17871U)) & S_BLOCK1], 46U));
            aCross ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 21032U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aIngress, 53U) ^ RotL64(aCross, 27U)) + (RotL64(aPrevious, 40U) + RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterK = ((aWandererF + RotL64(aCross, 44U)) + 2225397913940961213U) + aNonceWordE;
            aOrbiterD = ((aWandererE + RotL64(aIngress, 13U)) + RotL64(aCarry, 21U)) + 8342544893601343643U;
            aOrbiterJ = (((aWandererK + RotL64(aScatter, 21U)) + 162922186381417187U) + aPhaseAOrbiterAssignSaltB[((aIndex + 8U)) & S_SALT1]) + aNonceWordH;
            aOrbiterB = (((aWandererG + RotL64(aPrevious, 3U)) + RotL64(aCarry, 57U)) + 11660218373710972210U) + aPhaseAOrbiterAssignSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = ((aWandererJ + RotL64(aScatter, 53U)) + RotL64(aCarry, 39U)) + 14909034764605802354U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 16776955237009701511U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterK) ^ 5834487809188925253U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterJ = RotL64((aOrbiterJ * 4458820879204327709U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 1498492772767040320U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 4161765458781579617U;
            aOrbiterB = RotL64((aOrbiterB * 15535994410289065281U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 10511923076962447765U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 8575954471692620021U) ^ aNonceWordF;
            aOrbiterE = RotL64((aOrbiterE * 12526744988828982731U), 21U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 6536325446331340573U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 1790628986900286346U;
            aOrbiterD = RotL64((aOrbiterD * 5262997114200816715U), 37U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 2623814807619278590U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 11676970995834706612U;
            aOrbiterK = RotL64((aOrbiterK * 10057461115132434901U), 5U);
            //
            aIngress = RotL64(aOrbiterB, 13U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 35U));
            aIngress = aIngress + RotL64(aOrbiterD, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aIngress, 3U) + RotL64(aOrbiterE, 43U)) + aOrbiterB) + RotL64(aCarry, 11U)) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((((RotL64(aScatter, 34U) + RotL64(aOrbiterJ, 3U)) + aOrbiterD) + aNonceWordA) + aPhaseAWandererUpdateSaltA[((aIndex + 19U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aCross, 57U) + aOrbiterB) + RotL64(aOrbiterJ, 14U)) + aNonceWordN);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 11U) + aOrbiterJ) + RotL64(aOrbiterK, 27U)) + aNonceWordC);
            aWandererK = aWandererK + ((((RotL64(aCross, 23U) + RotL64(aOrbiterE, 35U)) + aOrbiterK) + RotL64(aCarry, 41U)) + aNonceWordG);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 11U));
            aCarry = aCarry + (RotL64(aWandererG, 48U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererK, 3U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 27179U)) & S_BLOCK1], 28U) ^ RotL64(aOperationLaneA[((aIndex + 23303U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 22763U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 25844U)) & S_BLOCK1], 5U) ^ RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 22333U)) & S_BLOCK1], 48U));
            aCross ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 27095U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCross, 37U) ^ RotL64(aIngress, 11U)) + (RotL64(aCarry, 56U) + RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterI = (((aWandererC + RotL64(aPrevious, 4U)) + 3973833383430652211U) + aPhaseAOrbiterAssignSaltF[((aIndex + 5U)) & S_SALT1]) + aNonceWordO;
            aOrbiterC = (((aWandererA + RotL64(aIngress, 53U)) + RotL64(aCarry, 21U)) + 5760227042747169187U) + aNonceWordK;
            aOrbiterK = ((aWandererK + RotL64(aCross, 13U)) + RotL64(aCarry, 47U)) + 4923009065139227286U;
            aOrbiterH = (((aWandererH + RotL64(aScatter, 21U)) + RotL64(aCarry, 5U)) + 1477807307009107590U) + aPhaseAOrbiterAssignSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = (aWandererF + RotL64(aIngress, 41U)) + 5707194514329007301U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 5340439728375269724U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 17080457898946572387U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 17719588880215414933U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 281559150259472813U) + aNonceWordC;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 16160633048230910560U;
            aOrbiterC = RotL64((aOrbiterC * 16883442583309073785U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 9003989610509592121U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 10579322462808454333U;
            aOrbiterH = RotL64((aOrbiterH * 100832431598087235U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 15059383289528723069U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 10417647757852880956U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 1457919230286043137U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 14484665027393813330U) + aNonceWordM;
            aOrbiterF = (((aOrbiterF ^ aOrbiterH) ^ 12344463053485837974U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterF = RotL64((aOrbiterF * 5762654194001525041U), 53U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterK, 50U);
            aIngress = aIngress + (RotL64(aOrbiterI, 39U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterC, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aScatter, 48U) + aOrbiterK) + RotL64(aOrbiterF, 30U)) + RotL64(aCarry, 3U)) + aNonceWordB);
            aWandererH = aWandererH ^ (((RotL64(aCross, 57U) + aOrbiterH) + RotL64(aOrbiterI, 3U)) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aIngress, 39U) + aOrbiterH) + RotL64(aOrbiterK, 53U)) + RotL64(aCarry, 27U)) + aNonceWordH);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 27U) + aOrbiterF) + RotL64(aOrbiterC, 19U)) + aPhaseAWandererUpdateSaltB[((aIndex + 11U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aCross, 19U) + aOrbiterC) + RotL64(aOrbiterK, 43U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 29U) ^ aWandererC);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 19U));
            aCarry = aCarry + RotL64(aWandererF, 47U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 29802U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneA[((aIndex + 30274U)) & S_BLOCK1], 18U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 30055U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 32535U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 27481U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 29906U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aPrevious, 39U) ^ RotL64(aCross, 27U)) + (RotL64(aCarry, 52U) + RotL64(aIngress, 13U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterC = (((aWandererD + RotL64(aCross, 13U)) + RotL64(aCarry, 35U)) + 17470880031634374199U) + aPhaseAOrbiterAssignSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterF = (((aWandererC + RotL64(aScatter, 39U)) + RotL64(aCarry, 19U)) + 757565846006937746U) + aNonceWordC;
            aOrbiterG = (((aWandererK + RotL64(aIngress, 47U)) + 9419282475801345674U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordD;
            aOrbiterA = ((aWandererI + RotL64(aPrevious, 58U)) + RotL64(aCarry, 5U)) + 2014248014107898196U;
            aOrbiterI = ((aWandererJ + RotL64(aIngress, 5U)) + 15113928519446490441U) + aNonceWordL;
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 7346126964886259935U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 5594123113093162359U;
            aOrbiterG = RotL64((aOrbiterG * 18043634828891483403U), 37U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 5659237263369402005U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = (((aOrbiterI ^ aOrbiterG) ^ 11565709683423969703U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterI = RotL64((aOrbiterI * 16731289017588574671U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 16782863743534856287U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 13499100900072115907U;
            aOrbiterC = RotL64((aOrbiterC * 5567729598873214433U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 11414447651044205242U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterF) ^ 7545993795121430538U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterA = RotL64((aOrbiterA * 10758488381206257261U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 11778229237616454988U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 2544793391976514665U;
            aOrbiterF = RotL64((aOrbiterF * 4021060413798523299U), 27U);
            //
            aIngress = RotL64(aOrbiterI, 27U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 13U));
            aIngress = aIngress + RotL64(aOrbiterC, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aCross, 13U) + aOrbiterC) + RotL64(aOrbiterG, 53U)) + RotL64(aCarry, 37U)) + aNonceWordH);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 54U) + aOrbiterA) + RotL64(aOrbiterC, 13U)) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 29U) + aOrbiterA) + RotL64(aOrbiterG, 35U)) + RotL64(aCarry, 3U)) + aNonceWordB);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 3U) + aOrbiterA) + RotL64(aOrbiterF, 44U)) + aNonceWordF);
            aWandererD = aWandererD + ((((RotL64(aIngress, 37U) + RotL64(aOrbiterF, 5U)) + aOrbiterI) + aNonceWordO) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 13U));
            aCarry = aCarry + (RotL64(aWandererJ, 39U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererK, 29U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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

void TwistExpander_BasketBall_Arx::Seed_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xB9CE4BB40674EECBULL + 0x81B5620FF879A96AULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xCB9ABCC39CCD0991ULL + 0xA79E1B498FAC042FULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xC8BDAC65E642EA0FULL + 0xFDCD363EF773D784ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xF864B76C09BCD9D9ULL + 0xF7B402E0381B4BC7ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xB370E8CFE0223381ULL + 0xC024D355825CD480ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xA5DBDCC2D850E36FULL + 0xEA8596C69B8D03A6ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x8C1A0C93D1847B01ULL + 0xD37F4CC78503EAFFULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xBE28F24C909FEDE5ULL + 0xB3E90AACE091FF96ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xBE4478C521ADED1DULL + 0xB5AA77578B77404DULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xB4744F920AC41957ULL + 0xF9CD54B0DEC29D7AULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xC45F28C75A5969D5ULL + 0xF6A1C6EF2008938AULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xD30155575C6644D7ULL + 0xC318033DFB0B5BD1ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xDE404E6AE4FF3953ULL + 0xEBA713BAF4BE9F80ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xF2A6A54E7D807ECFULL + 0xA85286595EF2963FULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xE6721B1A3416B4E7ULL + 0xC6E6A5271C06A579ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xD008947BAB601BEDULL + 0x8CDD7640D3FDA285ULL);
    // GSeedRunSeed_C seed_loop_b (start)
    {
        // GSeedRunSeed_C seed_loop_b lane group
        // read from: aOperationLaneA, aOperationLaneB, aFireLaneB, aOperationLaneC, aOperationLaneD, aExpandLaneB, aInvestLaneC, aExpandLaneC, aExpandLaneA, aInvestLaneD, aFireLaneD, aWorkLaneA, aFireLaneA, aWorkLaneB, aFireLaneC, aWorkLaneC, aExpandLaneD
        // write to: aInvestLaneC, aInvestLaneD, aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // seed_loop_b loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aFireLaneB
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aFireLaneB forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aExpandLaneB
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aExpandLaneB backward/forward random
        // write to: aInvestLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 4089U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneB[((aIndex + 2803U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 5046U)) & S_BLOCK1], 36U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 2784U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 3826U)) & S_BLOCK1], 40U));
            aCross ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 3387U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCross, 23U) + RotL64(aIngress, 53U)) + (RotL64(aPrevious, 37U) ^ RotL64(aCarry, 6U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterB = ((aWandererH + RotL64(aPrevious, 60U)) + 15188686795415908074U) + aNonceWordJ;
            aOrbiterI = ((aWandererI + RotL64(aScatter, 5U)) + 17310049041983079779U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = ((aWandererK + RotL64(aCross, 29U)) + 8246925977992441471U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterE = (aWandererG + RotL64(aIngress, 19U)) + 8644260919918112781U;
            aOrbiterC = (aWandererD + RotL64(aPrevious, 35U)) + 13401663736874819483U;
            aOrbiterF = ((aWandererE + RotL64(aIngress, 11U)) + 7940358935238314973U) + aNonceWordB;
            aOrbiterD = (((aWandererJ + RotL64(aScatter, 54U)) + RotL64(aCarry, 27U)) + 13278990328548007839U) + aNonceWordP;
            aOrbiterA = (((aWandererC + RotL64(aCross, 47U)) + RotL64(aCarry, 53U)) + 11346868298353840706U) + aNonceWordI;
            aOrbiterJ = ((aWandererB + RotL64(aIngress, 43U)) + RotL64(aCarry, 3U)) + 2374077904806833579U;
            //
            aOrbiterB = (((aOrbiterB + aOrbiterI) + 6978903378645019166U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordC;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 11951633297870965212U) ^ aNonceWordK;
            aOrbiterG = RotL64((aOrbiterG * 12778236598654492185U), 39U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 17398460995357409673U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 1215437945597836770U) ^ aNonceWordM;
            aOrbiterC = RotL64((aOrbiterC * 9322970054123481621U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 1878751468043972239U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 5343002808239712390U;
            aOrbiterD = RotL64((aOrbiterD * 11878640995447558811U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 9884918450053276861U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 15894599082080422550U;
            aOrbiterB = RotL64((aOrbiterB * 8359936745539546131U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 13917339232771145459U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 18101134009493720683U;
            aOrbiterF = RotL64((aOrbiterF * 15835859435306756387U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 3830086372356903769U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 15894394599564584010U;
            aOrbiterI = RotL64((aOrbiterI * 9513921913446609263U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 5127590955274245812U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 9410946933309720054U;
            aOrbiterJ = RotL64((aOrbiterJ * 14507476989423060561U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 15544384157294987085U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 998801294460434123U;
            aOrbiterA = RotL64((aOrbiterA * 5946968142746472745U), 23U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterB) + 16442095194965452163U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordN;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 14294936349037516932U;
            aOrbiterE = RotL64((aOrbiterE * 14655345374740882581U), 3U);
            //
            aIngress = RotL64(aOrbiterC, 29U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterE, 3U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 26U));
            aIngress = aIngress + (RotL64(aOrbiterG, 13U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterD, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aPrevious, 51U) + aOrbiterA) + RotL64(aOrbiterC, 35U)) + aNonceWordE);
            aWandererI = aWandererI ^ ((((RotL64(aScatter, 19U) + aOrbiterJ) + RotL64(aOrbiterC, 13U)) + aNonceWordD) + aPhaseBWandererUpdateSaltA[((aIndex + 21U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 29U) + RotL64(aOrbiterD, 47U)) + aOrbiterI) + RotL64(aCarry, 43U)) + aPhaseBWandererUpdateSaltD[((aIndex + 3U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 42U) + RotL64(aOrbiterA, 42U)) + aOrbiterJ) + aNonceWordA);
            aWandererG = aWandererG + ((RotL64(aCross, 57U) + aOrbiterE) + RotL64(aOrbiterD, 3U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterB, 53U)) + aOrbiterD);
            aWandererH = aWandererH + (((RotL64(aPrevious, 35U) + aOrbiterD) + RotL64(aOrbiterC, 27U)) + RotL64(aCarry, 5U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 23U) + aOrbiterC) + RotL64(aOrbiterF, 57U));
            aWandererE = aWandererE + ((RotL64(aCross, 12U) + RotL64(aOrbiterI, 22U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 13U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 50U));
            aCarry = aCarry + (RotL64(aWandererG, 53U) ^ aWandererC);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 19U));
            aCarry = aCarry + RotL64(aWandererE, 35U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aInvestLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_b loop 2
        // ingress from: aInvestLaneC, aOperationLaneC, aOperationLaneD, aExpandLaneC
        // ingress directions: aInvestLaneC forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aExpandLaneC forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aExpandLaneA
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aExpandLaneA backward/forward random
        // write to: aInvestLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneC[((aIndex + 7172U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneC[((aIndex + 10146U)) & S_BLOCK1], 51U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 9383U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 6249U)) & S_BLOCK1], 26U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 9399U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 5789U)) & S_BLOCK1], 18U));
            aCross ^= RotL64(aExpandLaneA[((aIndex + 7169U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCross, 51U) ^ RotL64(aPrevious, 23U)) + (RotL64(aIngress, 4U) ^ RotL64(aCarry, 37U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterE = (aWandererI + RotL64(aPrevious, 23U)) + 8375305456876489425U;
            aOrbiterD = ((aWandererB + RotL64(aCross, 6U)) + 16193562952772453047U) + aNonceWordF;
            aOrbiterF = (((aWandererD + RotL64(aIngress, 53U)) + RotL64(aCarry, 11U)) + 18088652458594816223U) + aPhaseBOrbiterAssignSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterH = (aWandererK + RotL64(aScatter, 37U)) + 767344788620249944U;
            aOrbiterJ = (((aWandererH + RotL64(aPrevious, 13U)) + RotL64(aCarry, 23U)) + 7705194930396368752U) + aNonceWordE;
            aOrbiterA = ((aWandererF + RotL64(aCross, 48U)) + 3829736891311272834U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterI = (aWandererC + RotL64(aScatter, 41U)) + 9881681671347640061U;
            aOrbiterC = ((aWandererE + RotL64(aIngress, 19U)) + 1721196560190164264U) + aNonceWordO;
            aOrbiterB = (((aWandererA + RotL64(aScatter, 27U)) + RotL64(aCarry, 3U)) + 3002652618388454213U) + aNonceWordC;
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 9811621464004005202U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 5652598941069986530U;
            aOrbiterF = RotL64((aOrbiterF * 4797973356708091621U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 6250499348327316328U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 16025054277615264530U;
            aOrbiterD = RotL64((aOrbiterD * 16446892258704281903U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 13800298546867243172U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 12256104592865905782U;
            aOrbiterI = RotL64((aOrbiterI * 16983140179497142713U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 17817225416918329229U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 17738671327352776217U) ^ aNonceWordI;
            aOrbiterH = RotL64((aOrbiterH * 393488251327705063U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 6816031224188400541U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterB) ^ 16989563985059237014U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterE = RotL64((aOrbiterE * 8677884225771717797U), 23U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterF) + 16891524847268207549U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordP;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 1833508573940405571U;
            aOrbiterB = RotL64((aOrbiterB * 9709196587703979539U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 12729999421507068973U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 6839758643521968957U;
            aOrbiterC = RotL64((aOrbiterC * 16350557395881283975U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 8524167125469267428U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 14741523560290472617U;
            aOrbiterJ = RotL64((aOrbiterJ * 4367850822282205897U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 10983798459868424892U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 5649250846622078964U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7149612714806023987U), 35U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterF, 11U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 44U));
            aIngress = aIngress + (RotL64(aOrbiterE, 41U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterI, 23U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterB, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aIngress, 56U) + RotL64(aOrbiterJ, 30U)) + aOrbiterF);
            aWandererI = aWandererI + ((RotL64(aCross, 27U) + RotL64(aOrbiterC, 19U)) + aOrbiterH);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 43U) + RotL64(aOrbiterF, 11U)) + aOrbiterA) + aPhaseBWandererUpdateSaltF[((aIndex + 18U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aScatter, 3U) + aOrbiterB) + RotL64(aOrbiterC, 35U)) + RotL64(aCarry, 27U)) + aNonceWordL);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 60U) + aOrbiterF) + RotL64(aOrbiterC, 3U));
            aWandererK = aWandererK + (((RotL64(aCross, 39U) + aOrbiterI) + RotL64(aOrbiterH, 46U)) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterC, 51U)) + aOrbiterJ);
            aWandererH = aWandererH + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterA, 57U)) + aOrbiterD) + RotL64(aCarry, 11U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 23U) + RotL64(aOrbiterD, 41U)) + aOrbiterE) + aNonceWordM);
            //
            aCarry = aCarry + (RotL64(aWandererE, 47U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererK, 13U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererF, 35U) ^ aWandererA);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 19U));
            aCarry = aCarry + RotL64(aWandererD, 24U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aInvestLaneD[((aIndex + 10976U)) & S_BLOCK1], 12U) ^ RotL64(aOperationLaneA[((aIndex + 11456U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 12686U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordE));
            //
            aCross = RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 12652U)) & S_BLOCK1], 12U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 12767U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aPrevious, 11U) ^ RotL64(aCross, 51U)) + (RotL64(aCarry, 37U) + RotL64(aIngress, 24U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterJ = (((aWandererD + RotL64(aCross, 4U)) + RotL64(aCarry, 19U)) + 12222235191147985484U) + aNonceWordB;
            aOrbiterB = (aWandererC + RotL64(aIngress, 35U)) + 16367317014523328414U;
            aOrbiterH = ((aWandererF + RotL64(aPrevious, 53U)) + 3511378091284703789U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterK = (aWandererK + RotL64(aScatter, 57U)) + 15247492830966725949U;
            aOrbiterG = ((aWandererH + RotL64(aCross, 30U)) + 7745995913390407897U) + aNonceWordP;
            aOrbiterE = ((aWandererB + RotL64(aScatter, 43U)) + 6463593307540108810U) + aPhaseBOrbiterAssignSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = ((aWandererA + RotL64(aPrevious, 19U)) + RotL64(aCarry, 29U)) + 1101669311005268630U;
            aOrbiterF = (((aWandererG + RotL64(aIngress, 11U)) + RotL64(aCarry, 43U)) + 12988052764067518580U) + aNonceWordC;
            aOrbiterI = (aWandererJ + RotL64(aCross, 23U)) + 17717179747434679772U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 11662190906682400416U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 6563014073547628748U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 16967910471722117761U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 13099094932059419219U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 16342730862261868847U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10988124108686164829U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 16855346813127524624U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 6570063128502306944U;
            aOrbiterK = RotL64((aOrbiterK * 4571570049463124831U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 11328352033809240501U) + aNonceWordG;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 11640986648833160901U;
            aOrbiterC = RotL64((aOrbiterC * 2895830492089678919U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 2675226158571501666U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 17700531248266458165U;
            aOrbiterF = RotL64((aOrbiterF * 2231403813970188657U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 7729597396731910874U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 15172374484412053756U;
            aOrbiterB = RotL64((aOrbiterB * 149009041406406517U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 9178769489257842683U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 9020154972097834926U;
            aOrbiterI = RotL64((aOrbiterI * 8910504667566521429U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 1317403761217790562U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 17151528554929201571U;
            aOrbiterE = RotL64((aOrbiterE * 3735945655450625203U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 11621882033959669977U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 10289504450815075623U) ^ aNonceWordN;
            aOrbiterJ = RotL64((aOrbiterJ * 13365982786836243195U), 19U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterF, 37U);
            aIngress = aIngress + (RotL64(aOrbiterG, 5U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterJ, 34U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 23U));
            aIngress = aIngress + RotL64(aOrbiterI, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aPrevious, 4U) + RotL64(aOrbiterB, 14U)) + aOrbiterI) + RotL64(aCarry, 51U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterH, 21U)) + aOrbiterK) + aNonceWordD);
            aWandererB = aWandererB + ((RotL64(aScatter, 11U) + RotL64(aOrbiterH, 47U)) + aOrbiterE);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterE, 3U)) + aOrbiterG) + aPhaseBWandererUpdateSaltE[((aIndex + 21U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 19U) + RotL64(aOrbiterG, 10U)) + aOrbiterI) + aNonceWordM);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 47U) + aOrbiterJ) + RotL64(aOrbiterK, 57U));
            aWandererD = aWandererD + (((RotL64(aIngress, 39U) + RotL64(aOrbiterE, 51U)) + aOrbiterF) + RotL64(aCarry, 39U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 26U) + RotL64(aOrbiterF, 39U)) + aOrbiterC) + aPhaseBWandererUpdateSaltC[((aIndex + 15U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 43U) + RotL64(aOrbiterC, 27U)) + aOrbiterE) + aNonceWordA);
            //
            aCarry = aCarry + (RotL64(aWandererC, 44U) ^ aWandererG);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 3U));
            aCarry = aCarry + (RotL64(aWandererJ, 23U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererH, 51U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererF, 35U);
            aCarry = aCarry + RotL64(aIngress, 6U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 20259U)) & S_BLOCK1], 5U) ^ RotL64(aInvestLaneC[((aIndex + 21354U)) & S_BLOCK1], 20U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 19889U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordA));
            //
            aCross = RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 21154U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneD[((aIndex + 19774U)) & S_BLOCK1], 22U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aIngress, 54U) + RotL64(aCross, 41U)) + (RotL64(aPrevious, 23U) ^ RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterC = (aWandererA + RotL64(aCross, 35U)) + 7722279280863371124U;
            aOrbiterK = (((aWandererI + RotL64(aPrevious, 57U)) + 11584220561732385598U) + aPhaseBOrbiterAssignSaltD[((aIndex + 18U)) & S_SALT1]) + aNonceWordF;
            aOrbiterG = (aWandererE + RotL64(aScatter, 4U)) + 7834679350105534657U;
            aOrbiterI = ((aWandererB + RotL64(aIngress, 27U)) + RotL64(aCarry, 27U)) + 11347994382444180879U;
            aOrbiterJ = (((aWandererJ + RotL64(aCross, 39U)) + RotL64(aCarry, 5U)) + 9449903188047063431U) + aNonceWordL;
            aOrbiterF = ((aWandererD + RotL64(aIngress, 11U)) + 6516243976652795170U) + aNonceWordC;
            aOrbiterD = (aWandererH + RotL64(aScatter, 53U)) + 8420815253991184777U;
            aOrbiterB = (aWandererC + RotL64(aPrevious, 44U)) + 9081386852515170937U;
            aOrbiterE = (((aWandererK + RotL64(aScatter, 21U)) + RotL64(aCarry, 57U)) + 14375955191735286867U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 880757589768436072U) + aNonceWordH;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 3349856625725164229U;
            aOrbiterG = RotL64((aOrbiterG * 681514212582331781U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 7826309957607577207U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 8057435761214313635U;
            aOrbiterJ = RotL64((aOrbiterJ * 4718430712767038607U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 9565237500443303103U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 15893066735310588501U;
            aOrbiterK = RotL64((aOrbiterK * 8457633439171452397U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 3276844534476430842U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 6828644383891274120U;
            aOrbiterF = RotL64((aOrbiterF * 979580351653410157U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 2815676923011504251U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 5030251870850928417U;
            aOrbiterE = RotL64((aOrbiterE * 7075653570570819253U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 13464083008377887034U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 8994560761846897590U) ^ aNonceWordO;
            aOrbiterD = RotL64((aOrbiterD * 9892839554658865143U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 8398813387154468736U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 8136429428340910892U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 3348811490733577295U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 418587250696862341U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 4111667833838312094U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 860949442143849147U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 6075478294190926371U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 2208124955874142264U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 15741988616251072075U), 23U);
            //
            aIngress = RotL64(aOrbiterG, 13U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterF, 27U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 23U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 20U));
            aIngress = aIngress + RotL64(aOrbiterD, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aScatter, 5U) + aOrbiterD) + RotL64(aOrbiterC, 57U)) + RotL64(aCarry, 39U)) + aNonceWordE);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterK, 5U)) + aOrbiterJ);
            aWandererH = aWandererH + ((RotL64(aPrevious, 60U) + RotL64(aOrbiterI, 21U)) + aOrbiterD);
            aWandererK = aWandererK ^ (((RotL64(aCross, 37U) + RotL64(aOrbiterB, 30U)) + aOrbiterF) + aNonceWordB);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 29U) + aOrbiterD) + RotL64(aOrbiterB, 51U)) + RotL64(aCarry, 3U)) + aPhaseBWandererUpdateSaltD[((aIndex + 21U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 51U) + aOrbiterE) + RotL64(aOrbiterB, 39U));
            aWandererE = aWandererE + (((RotL64(aCross, 21U) + RotL64(aOrbiterG, 11U)) + aOrbiterC) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterK, 35U)) + aOrbiterI);
            aWandererA = aWandererA + ((RotL64(aCross, 12U) + RotL64(aOrbiterF, 44U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererA, 37U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererE, 47U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererH, 57U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererJ, 3U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererB, 29U);
            aCarry = aCarry + RotL64(aIngress, 34U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 26422U)) & S_BLOCK1], 14U) ^ RotL64(aInvestLaneD[((aIndex + 26412U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 23120U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 25363U)) & S_BLOCK1], 21U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 23352U)) & S_BLOCK1], 42U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCross, 19U) + RotL64(aIngress, 56U)) ^ (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 39U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterF = ((aWandererD + RotL64(aIngress, 35U)) + 12690502671561165478U) + aPhaseBOrbiterAssignSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = (aWandererE + RotL64(aPrevious, 3U)) + 17519943923428102801U;
            aOrbiterB = ((aWandererF + RotL64(aScatter, 43U)) + RotL64(aCarry, 39U)) + 10705515807975331385U;
            aOrbiterJ = (aWandererH + RotL64(aCross, 30U)) + 16586447272278538179U;
            aOrbiterA = (((aWandererK + RotL64(aIngress, 19U)) + RotL64(aCarry, 21U)) + 8006560996840971798U) + aNonceWordE;
            aOrbiterH = (((aWandererI + RotL64(aPrevious, 39U)) + RotL64(aCarry, 3U)) + 12928600185788857701U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterC = ((aWandererB + RotL64(aScatter, 57U)) + 14240723153798267172U) + aNonceWordI;
            aOrbiterE = ((aWandererG + RotL64(aCross, 52U)) + 8636219177994872072U) + aNonceWordJ;
            aOrbiterI = ((aWandererJ + RotL64(aPrevious, 13U)) + 7586790235186467512U) + aNonceWordP;
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 1103807034179512424U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 7547526530239498693U;
            aOrbiterB = RotL64((aOrbiterB * 3360295583636013509U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 8380239679344786397U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 5690809173787433519U) ^ aNonceWordM;
            aOrbiterF = RotL64((aOrbiterF * 5354724308093372953U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 8390902801141804609U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 3507306189192059486U;
            aOrbiterD = RotL64((aOrbiterD * 18336280496510253103U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 6190745292098482871U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 8065418693975056902U;
            aOrbiterA = RotL64((aOrbiterA * 6414621418430102589U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 12111755051718111803U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 7605877769709909297U) ^ aNonceWordF;
            aOrbiterH = RotL64((aOrbiterH * 17525248694315944599U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 5969794501112646237U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 5127559299360591476U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4521563633438853069U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 10593847754747739786U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 4401750688524310121U) ^ aNonceWordK;
            aOrbiterI = RotL64((aOrbiterI * 14265829318976633707U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 6927893132508779499U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 4874009978647014479U;
            aOrbiterJ = RotL64((aOrbiterJ * 13340466017023540755U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 13146693487138744677U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 3298472134223595298U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2145005258008477281U), 19U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterF, 11U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 18U));
            aIngress = aIngress + (RotL64(aOrbiterE, 41U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 47U));
            aIngress = aIngress + RotL64(aOrbiterA, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aCross, 28U) + aOrbiterJ) + RotL64(aOrbiterE, 47U)) + RotL64(aCarry, 51U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 19U) + aOrbiterA) + RotL64(aOrbiterD, 27U));
            aWandererJ = aWandererJ + ((RotL64(aScatter, 53U) + aOrbiterC) + RotL64(aOrbiterB, 39U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 3U) + aOrbiterA) + RotL64(aOrbiterB, 12U));
            aWandererF = aWandererF + ((RotL64(aPrevious, 57U) + RotL64(aOrbiterB, 57U)) + aOrbiterH);
            aWandererD = aWandererD ^ ((((RotL64(aIngress, 46U) + RotL64(aOrbiterH, 5U)) + aOrbiterF) + aNonceWordO) + aPhaseBWandererUpdateSaltF[((aIndex + 27U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aCross, 11U) + RotL64(aOrbiterA, 19U)) + aOrbiterJ);
            aWandererH = aWandererH ^ ((((RotL64(aScatter, 23U) + aOrbiterH) + RotL64(aOrbiterI, 35U)) + aNonceWordH) + aPhaseBWandererUpdateSaltB[((aIndex + 7U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aPrevious, 39U) + RotL64(aOrbiterI, 52U)) + aOrbiterC) + RotL64(aCarry, 35U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 29U));
            aCarry = aCarry + (RotL64(aWandererF, 46U) ^ aWandererI);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 43U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 19U));
            aCarry = aCarry + RotL64(aWandererD, 11U);
            aCarry = aCarry + RotL64(aIngress, 6U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 28577U)) & S_BLOCK1], 42U) ^ RotL64(aWorkLaneA[((aIndex + 27370U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aExpandLaneD[((aIndex + 31634U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 31147U)) & S_BLOCK1], 58U) ^ RotL64(aOperationLaneB[((aIndex + 30912U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCarry, 44U) + RotL64(aIngress, 57U)) ^ (RotL64(aCross, 5U) + RotL64(aPrevious, 19U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterI = ((aWandererJ + RotL64(aPrevious, 3U)) + 17470880031634374199U) + aNonceWordJ;
            aOrbiterE = (aWandererA + RotL64(aScatter, 35U)) + 757565846006937746U;
            aOrbiterA = (aWandererH + RotL64(aIngress, 39U)) + 9419282475801345674U;
            aOrbiterB = ((aWandererE + RotL64(aCross, 12U)) + 2014248014107898196U) + aNonceWordD;
            aOrbiterC = (((aWandererK + RotL64(aPrevious, 57U)) + RotL64(aCarry, 47U)) + 15113928519446490441U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = (aWandererC + RotL64(aIngress, 43U)) + 7346126964886259935U;
            aOrbiterH = (((aWandererF + RotL64(aCross, 23U)) + RotL64(aCarry, 27U)) + 5594123113093162359U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterG = (((aWandererD + RotL64(aScatter, 53U)) + RotL64(aCarry, 37U)) + 5659237263369402005U) + aNonceWordE;
            aOrbiterD = (aWandererB + RotL64(aIngress, 18U)) + 11565709683423969703U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 16782863743534856287U) + aNonceWordG;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 13499100900072115907U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5567729598873214433U), 23U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterB) + 11414447651044205242U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1]) + aNonceWordC;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 7545993795121430538U;
            aOrbiterC = RotL64((aOrbiterC * 10758488381206257261U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 11778229237616454988U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 2544793391976514665U;
            aOrbiterH = RotL64((aOrbiterH * 4021060413798523299U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 9972156716619459164U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 17651030383827445664U;
            aOrbiterJ = RotL64((aOrbiterJ * 6742914240706775487U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 17439147296849134543U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 10021926927948343656U;
            aOrbiterE = RotL64((aOrbiterE * 18139540407315440909U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 9309867875882669289U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 14951424455944346337U;
            aOrbiterD = RotL64((aOrbiterD * 10569523948169951309U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 2166343974068770659U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 11386993629011562026U;
            aOrbiterB = RotL64((aOrbiterB * 3091639433512536097U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 5747849744680120960U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 4019290369160113026U;
            aOrbiterI = RotL64((aOrbiterI * 5567515306039646735U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 3820540009554769592U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 8210747198363020939U;
            aOrbiterG = RotL64((aOrbiterG * 16215133106542452509U), 5U);
            //
            aIngress = RotL64(aOrbiterD, 53U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterH, 4U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 35U));
            aIngress = aIngress + (RotL64(aOrbiterB, 57U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterJ, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aIngress, 51U) + RotL64(aOrbiterI, 23U)) + aOrbiterC) + aNonceWordA);
            aWandererK = aWandererK + ((RotL64(aPrevious, 19U) + RotL64(aOrbiterH, 11U)) + aOrbiterA);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 10U) + RotL64(aOrbiterI, 6U)) + aOrbiterH) + aNonceWordK);
            aWandererB = aWandererB + (((RotL64(aScatter, 39U) + aOrbiterE) + RotL64(aOrbiterA, 43U)) + RotL64(aCarry, 27U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 47U) + aOrbiterJ) + RotL64(aOrbiterC, 35U));
            aWandererD = aWandererD + ((RotL64(aScatter, 57U) + RotL64(aOrbiterE, 39U)) + aOrbiterC);
            aWandererC = aWandererC ^ ((RotL64(aCross, 34U) + RotL64(aOrbiterI, 19U)) + aOrbiterG);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 5U) + aOrbiterD) + RotL64(aOrbiterC, 53U)) + RotL64(aCarry, 35U)) + aPhaseBWandererUpdateSaltE[((aIndex + 23U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 27U) + aOrbiterA) + RotL64(aOrbiterB, 28U)) + aPhaseBWandererUpdateSaltC[((aIndex + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 42U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 53U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 5U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 57U));
            aCarry = aCarry + RotL64(aWandererH, 37U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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

void TwistExpander_BasketBall_Arx::Seed_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xA8FB360AFD604149ULL + 0xC65184C86B2A498FULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xDFC14828891FBC8BULL + 0xA5AAFBD2F9B383C9ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xC3E52BB2D5D5325FULL + 0xCA1FB350DF09EEF9ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xD21C4264D999DA27ULL + 0xA1BB9394CA00539DULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xB9ECE989796B434FULL + 0x8B8B81C0A8B946EFULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xA86C8523051370CFULL + 0xA61327E48DD150D0ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xA9BA18CC0A00AB99ULL + 0x972ABB019147041FULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xACCABA6DC7DC4545ULL + 0x8B9546688347E4E3ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0x93E844D26133BF1DULL + 0x985C14547DC74441ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xF8E4026BE493FE19ULL + 0xB16F542289505B52ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x92E8901A55CBE98FULL + 0xC95897AE73B69F25ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x82334C2363CF6747ULL + 0xA9B683F63DF81BB3ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xA485C69E5349A8CBULL + 0x8678DEC0DA4421BAULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xD3D1C456CE13E79FULL + 0xE1635FCB3C124B56ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x962D6E04B5909E2DULL + 0xC76F8600034005EFULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0x968A3F477654B011ULL + 0xD44E59D363FA9AB6ULL);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 3243U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneB[((aIndex + 5046U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 281U)) & S_BLOCK1], 42U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 1432U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 217U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 4829U)) & S_BLOCK1], 50U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCarry, 43U) ^ RotL64(aPrevious, 29U)) + (RotL64(aCross, 10U) + RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterG = (((aWandererB + RotL64(aPrevious, 57U)) + RotL64(aCarry, 35U)) + 13053031069776604052U) + aNonceWordK;
            aOrbiterB = ((aWandererK + RotL64(aCross, 19U)) + 1331396630251085122U) + aNonceWordE;
            aOrbiterE = (aWandererC + RotL64(aScatter, 3U)) + 15879286043343942393U;
            aOrbiterC = ((aWandererJ + RotL64(aIngress, 11U)) + RotL64(aCarry, 5U)) + 13590365633321406830U;
            aOrbiterJ = (((aWandererD + RotL64(aScatter, 51U)) + RotL64(aCarry, 57U)) + 14569235423040242618U) + aNonceWordA;
            aOrbiterA = ((aWandererI + RotL64(aCross, 30U)) + 11397370636618371560U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterK = (((aWandererA + RotL64(aPrevious, 37U)) + 3455933494593971847U) + aPhaseDOrbiterAssignSaltC[((aIndex + 3U)) & S_SALT1]) + aNonceWordD;
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 1307153376443784593U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 10688618762584786871U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 9503823896874842411U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 17746248451153600096U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 8512568600755410158U;
            aOrbiterB = RotL64((aOrbiterB * 16648320170768234063U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 8950230550112591092U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 17790968369472845496U;
            aOrbiterC = RotL64((aOrbiterC * 5104988920132008913U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 12583323865381967534U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 11243927099685293887U;
            aOrbiterK = RotL64((aOrbiterK * 12867003042486433971U), 37U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 9690268715525781389U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = (((aOrbiterG ^ aOrbiterK) ^ 7466066217365074653U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterG = RotL64((aOrbiterG * 17565696765505320889U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 3673528673209875118U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 14079103852360952255U;
            aOrbiterA = RotL64((aOrbiterA * 17449228863409999629U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 6747836856132250630U) + aNonceWordB;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 5027692924422297153U;
            aOrbiterJ = RotL64((aOrbiterJ * 2492421273167124437U), 11U);
            //
            aIngress = RotL64(aOrbiterC, 57U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterA, 35U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 13U));
            aIngress = aIngress + RotL64(aOrbiterG, 48U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aCross, 53U) + RotL64(aOrbiterK, 47U)) + aOrbiterB) + RotL64(aCarry, 5U)) + aNonceWordG);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 5U) + aOrbiterG) + RotL64(aOrbiterA, 19U)) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aScatter, 19U) + aOrbiterJ) + RotL64(aOrbiterA, 41U)) + RotL64(aCarry, 29U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterK, 57U)) + aOrbiterC);
            aWandererA = aWandererA + (((RotL64(aCross, 29U) + aOrbiterK) + RotL64(aOrbiterG, 35U)) + aPhaseDWandererUpdateSaltF[((aIndex + 7U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 35U) + aOrbiterJ) + RotL64(aOrbiterC, 12U)) + aNonceWordJ);
            aWandererD = aWandererD + ((RotL64(aIngress, 12U) + aOrbiterE) + RotL64(aOrbiterJ, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 4U) ^ aWandererB);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 29U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 21U));
            aCarry = aCarry + RotL64(aWandererA, 41U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = (RotL64(aSnowLaneA[((aIndex + 9528U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneC[((aIndex + 6787U)) & S_BLOCK1], 47U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 8853U)) & S_BLOCK1], 39U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 7736U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 8735U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 8658U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aInvestLaneD[((aIndex + 6792U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aPrevious, 58U) ^ RotL64(aCross, 23U)) ^ (RotL64(aIngress, 11U) + RotL64(aCarry, 37U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterE = (aWandererI + RotL64(aPrevious, 57U)) + 15383045568644941552U;
            aOrbiterH = ((aWandererH + RotL64(aIngress, 12U)) + 17452811657750910067U) + aNonceWordB;
            aOrbiterB = (((aWandererD + RotL64(aScatter, 47U)) + 15660117718455155603U) + aPhaseDOrbiterAssignSaltE[((aIndex + 28U)) & S_SALT1]) + aNonceWordA;
            aOrbiterJ = (((aWandererF + RotL64(aCross, 41U)) + RotL64(aCarry, 13U)) + 10396441207743665753U) + aPhaseDOrbiterAssignSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterI = (((aWandererE + RotL64(aIngress, 29U)) + RotL64(aCarry, 53U)) + 3708971058200841442U) + aNonceWordL;
            aOrbiterK = (((aWandererA + RotL64(aScatter, 5U)) + RotL64(aCarry, 41U)) + 7000673057768598750U) + aNonceWordD;
            aOrbiterD = (aWandererJ + RotL64(aPrevious, 35U)) + 9886354469011131596U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 16018065329058043467U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 5024756166109352320U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 11660932185479046483U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 6587818720728886652U) + aNonceWordI;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 3652672354944162319U;
            aOrbiterI = RotL64((aOrbiterI * 10807121230791716109U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 6307315649915348048U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 16405347331742979258U;
            aOrbiterJ = RotL64((aOrbiterJ * 7183142442906743699U), 37U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 5427299664054601957U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 4983381733483185898U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 14646556236306407673U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 10182995521328377487U) + aNonceWordG;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 8694282877540593550U;
            aOrbiterH = RotL64((aOrbiterH * 14614602561910403893U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 4085927978153269932U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 6176195962815240877U;
            aOrbiterD = RotL64((aOrbiterD * 16792916528959579875U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 6966742100601433005U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 9920952446921247521U) ^ aNonceWordF;
            aOrbiterK = RotL64((aOrbiterK * 1879821050131820933U), 5U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterH, 5U);
            aIngress = aIngress + (RotL64(aOrbiterD, 53U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterK, 35U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterB, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aIngress, 41U) + aOrbiterH) + RotL64(aOrbiterE, 20U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 21U) + aOrbiterI) + RotL64(aOrbiterK, 41U)) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterJ, 57U)) + aOrbiterI) + aPhaseDWandererUpdateSaltA[((aIndex + 8U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 51U) + RotL64(aOrbiterJ, 47U)) + aOrbiterB) + RotL64(aCarry, 21U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterH, 35U)) + aOrbiterD);
            aWandererD = aWandererD + ((((RotL64(aCross, 4U) + aOrbiterJ) + RotL64(aOrbiterD, 29U)) + RotL64(aCarry, 3U)) + aNonceWordN);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 57U) + aOrbiterJ) + RotL64(aOrbiterE, 5U)) + aNonceWordC);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 46U));
            aCarry = aCarry + (RotL64(aWandererA, 57U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererD, 37U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererF, 29U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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
            aIngress = (RotL64(aSnowLaneB[((aIndex + 13028U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneA[((aIndex + 15322U)) & S_BLOCK1], 24U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 15630U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordD));
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 14145U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 11072U)) & S_BLOCK1], 18U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCarry, 34U) + RotL64(aIngress, 19U)) + (RotL64(aPrevious, 53U) ^ RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterA = ((aWandererK + RotL64(aIngress, 5U)) + 6342299552323486695U) + aNonceWordF;
            aOrbiterB = (((aWandererH + RotL64(aScatter, 21U)) + RotL64(aCarry, 57U)) + 12692748514781367538U) + aNonceWordG;
            aOrbiterK = (((aWandererD + RotL64(aPrevious, 39U)) + RotL64(aCarry, 23U)) + 8202639945493229155U) + aNonceWordL;
            aOrbiterG = ((aWandererJ + RotL64(aCross, 47U)) + 4439975701793231639U) + aPhaseDOrbiterAssignSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterC = (aWandererF + RotL64(aPrevious, 12U)) + 16774235182859553759U;
            aOrbiterF = ((((aWandererA + RotL64(aIngress, 57U)) + RotL64(aCarry, 43U)) + 8764155413335405667U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordP;
            aOrbiterJ = (aWandererI + RotL64(aCross, 27U)) + 7167848811974967685U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 16768278912125334220U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 9090838954826296201U;
            aOrbiterK = RotL64((aOrbiterK * 5459329624017272077U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 7644075729758006298U) + aNonceWordK;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 17326182797908071215U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2408330168749256075U), 51U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterK) + 16158809721888137555U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1]) + aNonceWordM;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 8029938783858263694U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12628072435324195483U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 8716553521415553404U) + aNonceWordJ;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 7012599977009208840U;
            aOrbiterB = RotL64((aOrbiterB * 8775355876188948851U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 13250558696578541499U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 13705957059101025396U;
            aOrbiterA = RotL64((aOrbiterA * 16889495686487056367U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 2796775206291902461U) + aNonceWordE;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 13741676263512390669U;
            aOrbiterJ = RotL64((aOrbiterJ * 10455782033465595947U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 1691908360612389252U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 4114939415206031540U;
            aOrbiterC = RotL64((aOrbiterC * 2797401802892718297U), 29U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterC, 37U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 3U));
            aIngress = aIngress + (RotL64(aOrbiterG, 11U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterJ, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aCross, 43U) + RotL64(aOrbiterA, 23U)) + aOrbiterK) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aIngress, 21U) + aOrbiterB) + RotL64(aOrbiterK, 53U)) + RotL64(aCarry, 35U)) + aNonceWordA);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 5U) + aOrbiterJ) + RotL64(aOrbiterC, 47U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 51U) + aOrbiterB) + RotL64(aOrbiterJ, 29U)) + RotL64(aCarry, 53U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 57U) + aOrbiterK) + RotL64(aOrbiterF, 11U)) + aPhaseDWandererUpdateSaltB[((aIndex + 13U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aIngress, 27U) + aOrbiterK) + RotL64(aOrbiterG, 3U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 36U) + aOrbiterK) + RotL64(aOrbiterC, 38U)) + aNonceWordO);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 30U));
            aCarry = aCarry + (RotL64(aWandererK, 47U) ^ aWandererD);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 13U));
            aCarry = aCarry + RotL64(aWandererA, 57U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 20370U)) & S_BLOCK1], 3U) ^ RotL64(aSnowLaneA[((aIndex + 20094U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 16994U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordE));
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 19261U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 16887U)) & S_BLOCK1], 60U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 23U)) + (RotL64(aIngress, 53U) ^ RotL64(aCross, 36U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterD = ((aWandererE + RotL64(aIngress, 37U)) + 9220392006207660113U) + aNonceWordP;
            aOrbiterJ = (((aWandererI + RotL64(aPrevious, 13U)) + RotL64(aCarry, 21U)) + 11305018553489132882U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterF = (aWandererA + RotL64(aScatter, 57U)) + 5860373868073513684U;
            aOrbiterI = ((aWandererK + RotL64(aCross, 51U)) + RotL64(aCarry, 3U)) + 12319586170883987589U;
            aOrbiterK = ((aWandererJ + RotL64(aIngress, 20U)) + 14072333614354649021U) + aNonceWordG;
            aOrbiterG = ((aWandererG + RotL64(aScatter, 5U)) + RotL64(aCarry, 43U)) + 9332158529453194608U;
            aOrbiterA = ((aWandererF + RotL64(aCross, 43U)) + 3860569321145958686U) + aPhaseDOrbiterAssignSaltA[((aIndex + 23U)) & S_SALT1];
            //
            aOrbiterD = (((aOrbiterD + aOrbiterJ) + 8119005668901240093U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 13918259792880333239U;
            aOrbiterF = RotL64((aOrbiterF * 5441062406822088853U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 6938856216758228704U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 3960905839118710604U;
            aOrbiterG = RotL64((aOrbiterG * 16203746868670689793U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 6043879193734253929U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 15691425268831319195U) ^ aNonceWordB;
            aOrbiterD = RotL64((aOrbiterD * 7189195135654636271U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 14912209933584715274U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 16180183395910618923U;
            aOrbiterI = RotL64((aOrbiterI * 3942858974766467849U), 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 4966642362507707776U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 6962226782462822861U) ^ aNonceWordK;
            aOrbiterK = RotL64((aOrbiterK * 3647802407741095419U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 12409120845092026295U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 2302946450253872465U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 7099576330777297911U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 16118304388937163838U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 15968419034359049422U;
            aOrbiterA = RotL64((aOrbiterA * 11736207775827080165U), 57U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterJ, 43U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 34U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 5U));
            aIngress = aIngress + RotL64(aOrbiterK, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterK, 3U)) + aOrbiterA);
            aWandererE = aWandererE + (((RotL64(aIngress, 12U) + RotL64(aOrbiterJ, 47U)) + aOrbiterD) + RotL64(aCarry, 3U));
            aWandererK = aWandererK ^ ((((RotL64(aPrevious, 39U) + RotL64(aOrbiterI, 53U)) + aOrbiterF) + aNonceWordL) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererF = aWandererF + (((((RotL64(aScatter, 3U) + aOrbiterI) + RotL64(aOrbiterG, 21U)) + RotL64(aCarry, 29U)) + aNonceWordD) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterD, 29U)) + aOrbiterK);
            aWandererG = aWandererG + ((RotL64(aIngress, 27U) + RotL64(aOrbiterK, 37U)) + aOrbiterI);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 57U) + aOrbiterA) + RotL64(aOrbiterI, 12U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 34U));
            aCarry = aCarry + (RotL64(aWandererK, 51U) ^ aWandererI);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 5U));
            aCarry = aCarry + RotL64(aWandererA, 57U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 24216U)) & S_BLOCK1], 11U) ^ RotL64(aSnowLaneB[((aIndex + 24257U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 24298U)) & S_BLOCK1], 52U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordA));
            //
            aCross = RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 24444U)) & S_BLOCK1], 19U) ^ RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 23949U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCross, 19U) + RotL64(aPrevious, 5U)) ^ (RotL64(aCarry, 37U) ^ RotL64(aIngress, 54U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterD = (aWandererG + RotL64(aCross, 3U)) + 4848316479321533394U;
            aOrbiterB = ((aWandererK + RotL64(aIngress, 47U)) + 6919360256662636195U) + aPhaseDOrbiterAssignSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterI = (((aWandererB + RotL64(aPrevious, 41U)) + RotL64(aCarry, 39U)) + 9897013582181108544U) + aNonceWordD;
            aOrbiterA = (aWandererC + RotL64(aScatter, 27U)) + 7319353809896158678U;
            aOrbiterF = ((aWandererD + RotL64(aIngress, 14U)) + RotL64(aCarry, 3U)) + 2848175435514849859U;
            aOrbiterE = (((aWandererJ + RotL64(aScatter, 57U)) + RotL64(aCarry, 21U)) + 6967780718720437934U) + aPhaseDOrbiterAssignSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = ((aWandererA + RotL64(aPrevious, 35U)) + 10143884766603388136U) + aNonceWordM;
            //
            aOrbiterD = (((aOrbiterD + aOrbiterB) + 8675965006150972051U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordI;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 16350117755560994281U;
            aOrbiterI = RotL64((aOrbiterI * 15072308930382994425U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 17976597517118423760U) + aNonceWordK;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 1399631141355370237U;
            aOrbiterF = RotL64((aOrbiterF * 16537788276543236833U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 3590613762034716792U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 5134624314245932157U) ^ aNonceWordL;
            aOrbiterA = RotL64((aOrbiterA * 13077589037975283371U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 10082236952942943654U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 4015535035905433450U;
            aOrbiterE = RotL64((aOrbiterE * 4961808568701908559U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 611474103801573800U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 5786708483794098001U;
            aOrbiterD = RotL64((aOrbiterD * 7694007039340089267U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 5201943497363274455U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 9282160506938328489U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5368182164239021367U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 4932320527498940158U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 11576526341731392916U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 1712051774729439363U), 43U);
            //
            aIngress = RotL64(aOrbiterA, 57U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterF, 51U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterE, 13U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterB, 4U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((((RotL64(aCross, 44U) + RotL64(aOrbiterK, 29U)) + aOrbiterB) + aNonceWordG) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aIngress, 5U) + RotL64(aOrbiterK, 5U)) + aOrbiterI);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 35U) + aOrbiterB) + RotL64(aOrbiterA, 23U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterE, 53U)) + aOrbiterD) + RotL64(aCarry, 53U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterD, 37U)) + aOrbiterK);
            aWandererA = aWandererA + ((((RotL64(aIngress, 11U) + RotL64(aOrbiterB, 44U)) + aOrbiterF) + RotL64(aCarry, 3U)) + aPhaseDWandererUpdateSaltA[((aIndex + 9U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 53U) + RotL64(aOrbiterK, 13U)) + aOrbiterF) + aNonceWordC);
            //
            aCarry = aCarry + (RotL64(aWandererB, 23U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererG, 4U) ^ aWandererK);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 29U));
            aCarry = aCarry + RotL64(aWandererD, 57U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = (RotL64(aInvestLaneC[((aIndex + 29435U)) & S_BLOCK1], 4U) ^ RotL64(aInvestLaneA[((aIndex + 32282U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 28566U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 30251U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29586U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aPrevious, 23U) + RotL64(aCarry, 11U)) + (RotL64(aIngress, 43U) ^ RotL64(aCross, 58U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterK = ((aWandererA + RotL64(aScatter, 37U)) + RotL64(aCarry, 3U)) + 15036852811491820366U;
            aOrbiterD = ((aWandererD + RotL64(aCross, 47U)) + 305637140752898475U) + aNonceWordK;
            aOrbiterH = ((aWandererJ + RotL64(aIngress, 11U)) + 11948631574496129610U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = (((aWandererG + RotL64(aPrevious, 58U)) + RotL64(aCarry, 37U)) + 5321623592482991426U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterE = (((aWandererB + RotL64(aCross, 3U)) + RotL64(aCarry, 23U)) + 4075270159062690728U) + aNonceWordI;
            aOrbiterC = ((aWandererE + RotL64(aScatter, 27U)) + 15111580500356908928U) + aNonceWordP;
            aOrbiterJ = ((aWandererK + RotL64(aIngress, 19U)) + 7244150695504160363U) + aNonceWordF;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 5131563519577488862U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 5881954992088651371U;
            aOrbiterH = RotL64((aOrbiterH * 2424421828597294607U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 12780935808751507998U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 12599159643925470226U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 17690046932587062701U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 9466589929741834066U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 6093158735705189789U) ^ aNonceWordO;
            aOrbiterC = RotL64((aOrbiterC * 7453778295800853653U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 17461243886150519249U) + aNonceWordM;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 15456408913739900718U;
            aOrbiterB = RotL64((aOrbiterB * 16093292401746174671U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 11260643903290392780U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 7870342756041882616U;
            aOrbiterJ = RotL64((aOrbiterJ * 2431528656086173419U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 134484990005888936U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 10626896209992890407U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 12034131076645285597U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 14031164129515132292U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 1771835705730244212U;
            aOrbiterK = RotL64((aOrbiterK * 186981668443596623U), 27U);
            //
            aIngress = RotL64(aOrbiterC, 43U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 54U));
            aIngress = aIngress + (RotL64(aOrbiterH, 13U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterK, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aIngress, 13U) + RotL64(aOrbiterE, 60U)) + aOrbiterH) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 23U) + RotL64(aOrbiterE, 47U)) + aOrbiterJ) + aNonceWordG);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 41U) + aOrbiterK) + RotL64(aOrbiterJ, 11U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 3U) + RotL64(aOrbiterB, 27U)) + aOrbiterK) + RotL64(aCarry, 23U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 35U) + aOrbiterC) + RotL64(aOrbiterE, 53U)) + aNonceWordH);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 48U) + RotL64(aOrbiterH, 41U)) + aOrbiterB) + RotL64(aCarry, 11U)) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterD, 19U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 60U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 43U));
            aCarry = aCarry + (RotL64(aWandererA, 51U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererE, 29U);
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

void TwistExpander_BasketBall_Arx::Seed_E(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xBD4E37B7B1075115ULL + 0xABD0C635A7435089ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xAA0C4A77432DBD09ULL + 0xA1DEDEE2EE19EE8FULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xBC213E64C3DECF1BULL + 0xB8DDD5BFBC2B1B48ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xBFD39561D75238F7ULL + 0xA0069B931D6F7535ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xCE94CF8C8A65D6B1ULL + 0x90CDC7D6471B3878ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xDAFACD0324C11ED5ULL + 0xDAD3F9830B9B4FD6ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xE5BDB466861529A3ULL + 0xFB3CD12E425A088AULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xE3F7A891B8D38F83ULL + 0xE35C8462ABB0C319ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xE196EE85CD821985ULL + 0xE28AAB231317BDE3ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xF03C1029248EB71FULL + 0xF444D3326DEDF21CULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xBFC1EA0BA7F304C7ULL + 0xB0856FEFA4FB8704ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xF242EF6D83FDCFBFULL + 0x8457A086C1F0D499ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xA40367D494B80A07ULL + 0xCFB289CD560AB1F0ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xD69D15244B9510CBULL + 0xC9D98CC2D25CDB44ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xD80747D7AFB4959BULL + 0xB41CA198AEDE221CULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0x81F9315261F4C293ULL + 0x9EE363C54BE6F536ULL);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 740U)) & S_BLOCK1], 30U) ^ RotL64(aInvestLaneB[((aIndex + 5036U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 860U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 378U)) & S_BLOCK1], 27U) ^ RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 3082U)) & S_BLOCK1], 14U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 2990U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCross, 28U) + RotL64(aIngress, 53U)) ^ (RotL64(aCarry, 3U) + RotL64(aPrevious, 41U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterD = ((aWandererG + RotL64(aScatter, 27U)) + RotL64(aCarry, 5U)) + 6163290588946759209U;
            aOrbiterH = (aWandererE + RotL64(aPrevious, 43U)) + 7342672468560105447U;
            aOrbiterE = ((aWandererJ + RotL64(aIngress, 46U)) + 11574563167017282321U) + aNonceWordJ;
            aOrbiterI = ((aWandererH + RotL64(aCross, 39U)) + 2254820206194758964U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = (aWandererB + RotL64(aIngress, 19U)) + 1469783447473099498U;
            aOrbiterC = ((aWandererI + RotL64(aPrevious, 21U)) + 14174828900676165088U) + aNonceWordI;
            aOrbiterA = (aWandererD + RotL64(aScatter, 11U)) + 16277954291890598132U;
            aOrbiterG = (((aWandererK + RotL64(aCross, 51U)) + RotL64(aCarry, 19U)) + 14845750668693136766U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterB = (((aWandererA + RotL64(aPrevious, 57U)) + RotL64(aCarry, 35U)) + 150099699692047766U) + aNonceWordB;
            aOrbiterJ = (aWandererF + RotL64(aScatter, 34U)) + 1200784917165131703U;
            aOrbiterF = (aWandererC + RotL64(aIngress, 3U)) + 9469982764806754302U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 10956702761701710182U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 7915506894975487807U) ^ aNonceWordM;
            aOrbiterE = RotL64((aOrbiterE * 8874108311712727983U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 17335794183733623213U) + aNonceWordO;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 557028996286989506U;
            aOrbiterK = RotL64((aOrbiterK * 3993359298602424281U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 1597385667771002414U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 4376417959915162639U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 4626236858205178149U), 53U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterI) + 549770198518993876U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordK;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 756554555648070919U;
            aOrbiterA = RotL64((aOrbiterA * 16272320259614325355U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 7298557532533152193U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 3336802611342112013U;
            aOrbiterB = RotL64((aOrbiterB * 14679103452120080499U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 2314938232094714365U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 12215066333571149153U;
            aOrbiterJ = RotL64((aOrbiterJ * 10747052773052630601U), 37U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 7762752719356805046U) + aNonceWordG;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 6519429915769040078U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 15548676502167938513U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 7556691736109752918U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 13731245903412646404U;
            aOrbiterH = RotL64((aOrbiterH * 15581965016668635409U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 5910925625723735162U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 16037704866415841869U;
            aOrbiterF = RotL64((aOrbiterF * 11628217027073824759U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 12605882248192797360U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 9579778913978981884U;
            aOrbiterC = RotL64((aOrbiterC * 5372577227818787957U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 6063171520266734946U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 6163290588946759209U;
            aOrbiterD = RotL64((aOrbiterD * 291843698316138251U), 47U);
            //
            aIngress = RotL64(aOrbiterA, 19U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 13U));
            aIngress = aIngress + (RotL64(aOrbiterD, 29U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 43U));
            aIngress = aIngress + (RotL64(aOrbiterH, 24U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterJ, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aScatter, 21U) + aOrbiterJ) + RotL64(aOrbiterG, 51U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 50U) + aOrbiterF) + RotL64(aOrbiterE, 26U)) + aNonceWordE);
            aWandererG = aWandererG + (((((RotL64(aIngress, 53U) + RotL64(aOrbiterH, 29U)) + aOrbiterF) + RotL64(aCarry, 37U)) + aNonceWordN) + aPhaseEWandererUpdateSaltD[((aIndex + 8U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterG, 53U)) + aOrbiterK);
            aWandererC = aWandererC + ((RotL64(aIngress, 47U) + RotL64(aOrbiterD, 11U)) + aOrbiterJ);
            aWandererF = aWandererF ^ ((RotL64(aCross, 34U) + RotL64(aOrbiterA, 21U)) + aOrbiterF);
            aWandererH = aWandererH + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterC, 14U)) + aOrbiterG) + aNonceWordC);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterG, 39U)) + aOrbiterF);
            aWandererI = aWandererI + ((RotL64(aPrevious, 39U) + aOrbiterF) + RotL64(aOrbiterI, 19U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterK, 47U)) + aOrbiterB) + aPhaseEWandererUpdateSaltB[((aIndex + 11U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 41U) + aOrbiterD) + RotL64(aOrbiterF, 35U)) + RotL64(aCarry, 11U)) + aNonceWordL);
            //
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererB);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 26U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 57U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 43U));
            aCarry = aCarry + (RotL64(aWandererJ, 19U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererH, 41U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aFireLaneA[((aIndex + 10666U)) & S_BLOCK1], 29U) ^ RotL64(aInvestLaneC[((aIndex + 8414U)) & S_BLOCK1], 5U));
            aIngress ^= (RotL64(aInvestLaneD[((aIndex + 10489U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneA[((aIndex + 10433U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 7042U)) & S_BLOCK1], 37U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 8535U)) & S_BLOCK1], 46U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 7179U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aIngress, 57U) + RotL64(aCross, 37U)) ^ (RotL64(aCarry, 23U) + RotL64(aPrevious, 10U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterK = (aWandererB + RotL64(aScatter, 13U)) + 8793908991006073956U;
            aOrbiterD = (aWandererA + RotL64(aPrevious, 56U)) + 2932916283348441943U;
            aOrbiterE = ((aWandererJ + RotL64(aCross, 29U)) + 11069042087940968262U) + aNonceWordF;
            aOrbiterJ = (((aWandererC + RotL64(aIngress, 23U)) + RotL64(aCarry, 3U)) + 14369628676782894441U) + aPhaseEOrbiterAssignSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = ((aWandererD + RotL64(aScatter, 35U)) + RotL64(aCarry, 53U)) + 8602903272780978282U;
            aOrbiterF = (aWandererI + RotL64(aIngress, 43U)) + 3827036107178568820U;
            aOrbiterH = ((aWandererE + RotL64(aCross, 51U)) + 8905245209036772489U) + aPhaseEOrbiterAssignSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = (aWandererF + RotL64(aPrevious, 19U)) + 13331387530760017893U;
            aOrbiterC = (((aWandererK + RotL64(aCross, 53U)) + RotL64(aCarry, 19U)) + 9880107580289737823U) + aNonceWordN;
            aOrbiterI = (aWandererG + RotL64(aPrevious, 48U)) + 10199619040626900278U;
            aOrbiterG = (aWandererH + RotL64(aScatter, 5U)) + 2466307560891374281U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 13973403407981259448U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 2851460278409385243U;
            aOrbiterE = RotL64((aOrbiterE * 11226902976321781743U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 10365453393815690776U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 2382382358987358791U;
            aOrbiterF = RotL64((aOrbiterF * 481563628980705781U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 5058198848163792422U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 10500434740387593487U;
            aOrbiterJ = RotL64((aOrbiterJ * 5946747708776079787U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 11289798395177667084U) + aNonceWordE;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 14327152153231286666U;
            aOrbiterC = RotL64((aOrbiterC * 18155778059595245561U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 8065137263811956313U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 3865153574847924816U) ^ aNonceWordM;
            aOrbiterD = RotL64((aOrbiterD * 9495741102667755161U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 18102279969722473375U) + aNonceWordC;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 6306428427188742325U;
            aOrbiterH = RotL64((aOrbiterH * 17826782872351406167U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 16953348204663693724U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 11950791817032898613U;
            aOrbiterG = RotL64((aOrbiterG * 1498946055469611133U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 11980823193543752994U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 17845490308799454871U;
            aOrbiterK = RotL64((aOrbiterK * 16385153013485463791U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 5566398755702887071U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 10308378271388889968U;
            aOrbiterB = RotL64((aOrbiterB * 142732084484961281U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 6717846700455219260U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 8297225372883997017U;
            aOrbiterA = RotL64((aOrbiterA * 14102812043481327907U), 37U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterH) + 12249337046267666603U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1]) + aNonceWordG;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 8793908991006073956U;
            aOrbiterI = RotL64((aOrbiterI * 5851229209188473467U), 43U);
            //
            aIngress = RotL64(aOrbiterH, 48U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 21U));
            aIngress = aIngress + (RotL64(aOrbiterE, 29U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 53U));
            aIngress = aIngress + (RotL64(aOrbiterA, 51U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterB, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aScatter, 58U) + aOrbiterC) + RotL64(aOrbiterI, 11U)) + aNonceWordP);
            aWandererK = aWandererK + (((((RotL64(aIngress, 53U) + aOrbiterH) + RotL64(aOrbiterB, 3U)) + RotL64(aCarry, 47U)) + aNonceWordD) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterB, 6U)) + aOrbiterC);
            aWandererG = aWandererG + ((RotL64(aCross, 13U) + aOrbiterF) + RotL64(aOrbiterK, 53U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 28U) + RotL64(aOrbiterA, 23U)) + aOrbiterE) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 3U) + aOrbiterF) + RotL64(aOrbiterC, 43U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterH, 13U)) + aOrbiterK);
            aWandererI = aWandererI + ((RotL64(aCross, 41U) + RotL64(aOrbiterD, 35U)) + aOrbiterA);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 19U) + aOrbiterG) + RotL64(aOrbiterI, 57U)) + aNonceWordI);
            aWandererE = aWandererE + (((RotL64(aScatter, 5U) + aOrbiterA) + RotL64(aOrbiterB, 20U)) + RotL64(aCarry, 39U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterK, 51U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 13U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 18U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 29U));
            aCarry = aCarry + (RotL64(aWandererI, 51U) ^ aWandererK);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 23U));
            aCarry = aCarry + RotL64(aWandererC, 44U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 11867U)) & S_BLOCK1], 29U) ^ RotL64(aInvestLaneA[((aIndex + 15377U)) & S_BLOCK1], 44U));
            aIngress ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 15313U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 12221U)) & S_BLOCK1], 47U) ^ RotL64(aInvestLaneC[((aIndex + 15440U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCarry, 47U) + RotL64(aPrevious, 11U)) ^ (RotL64(aCross, 27U) + RotL64(aIngress, 60U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterF = (aWandererH + RotL64(aIngress, 51U)) + 9751314027302668907U;
            aOrbiterD = (((aWandererI + RotL64(aPrevious, 27U)) + 12175450995523107056U) + aPhaseEOrbiterAssignSaltA[((aIndex + 29U)) & S_SALT1]) + aNonceWordD;
            aOrbiterJ = (aWandererC + RotL64(aCross, 10U)) + 17519694958730119552U;
            aOrbiterK = (aWandererJ + RotL64(aScatter, 19U)) + 9093525527925682263U;
            aOrbiterI = (((aWandererD + RotL64(aPrevious, 3U)) + RotL64(aCarry, 53U)) + 3713831321786810138U) + aNonceWordJ;
            aOrbiterH = (aWandererK + RotL64(aScatter, 21U)) + 10108355209191835040U;
            aOrbiterA = (aWandererG + RotL64(aIngress, 5U)) + 12956307447311314768U;
            aOrbiterC = (((aWandererE + RotL64(aCross, 29U)) + RotL64(aCarry, 11U)) + 1904298513945877359U) + aNonceWordC;
            aOrbiterG = (aWandererB + RotL64(aScatter, 34U)) + 4658049993308574460U;
            aOrbiterB = (aWandererA + RotL64(aPrevious, 39U)) + 9826333658248851902U;
            aOrbiterE = (((aWandererF + RotL64(aIngress, 23U)) + RotL64(aCarry, 43U)) + 12058666914724365134U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 2516574707110528099U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 13335308331049750235U;
            aOrbiterJ = RotL64((aOrbiterJ * 5880227828760598587U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 8230749255538495304U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterK) ^ 16536559486797811486U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 4U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterF = RotL64((aOrbiterF * 7097036838156464969U), 53U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 12387639130570188998U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 8459259798142872020U;
            aOrbiterA = RotL64((aOrbiterA * 8001346480955847013U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 16083784052002800300U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 1957284290736468379U;
            aOrbiterI = RotL64((aOrbiterI * 5046501301740813065U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 7349538179311335863U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 16395170077006105258U;
            aOrbiterB = RotL64((aOrbiterB * 4230485452156662763U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 3317652065873784068U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 5517155804799120700U;
            aOrbiterK = RotL64((aOrbiterK * 9789270651974719183U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 5568525912112200094U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 9334250662962319598U;
            aOrbiterD = RotL64((aOrbiterD * 5034887614541768961U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 5641394627075994165U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 13524971148931512745U;
            aOrbiterC = RotL64((aOrbiterC * 3699457147759854357U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 15124425790244392471U) + aNonceWordN;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 7896294947517723306U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7526632360108129915U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 15241686066829586263U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 12099799118961857495U;
            aOrbiterG = RotL64((aOrbiterG * 10456171163074630861U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 17529688916595727188U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 9751314027302668907U;
            aOrbiterE = RotL64((aOrbiterE * 521888849578281715U), 47U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterI, 47U);
            aIngress = aIngress + (RotL64(aOrbiterF, 50U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 13U));
            aIngress = aIngress + (RotL64(aOrbiterK, 5U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterA, 43U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterE, 36U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aScatter, 5U) + aOrbiterC) + RotL64(aOrbiterI, 3U));
            aWandererC = aWandererC + ((((RotL64(aIngress, 27U) + RotL64(aOrbiterK, 39U)) + aOrbiterJ) + RotL64(aCarry, 57U)) + aNonceWordM);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 14U) + aOrbiterA) + RotL64(aOrbiterI, 43U));
            aWandererF = aWandererF + ((RotL64(aCross, 19U) + RotL64(aOrbiterG, 19U)) + aOrbiterD);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 21U) + RotL64(aOrbiterI, 57U)) + aOrbiterD) + aPhaseEWandererUpdateSaltF[((aIndex + 24U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aCross, 47U) + RotL64(aOrbiterJ, 24U)) + aOrbiterE);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 34U) + aOrbiterI) + RotL64(aOrbiterK, 51U));
            aWandererH = aWandererH + ((((RotL64(aPrevious, 53U) + RotL64(aOrbiterB, 27U)) + aOrbiterH) + RotL64(aCarry, 53U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 39U) + RotL64(aOrbiterA, 11U)) + aOrbiterJ) + aNonceWordG);
            aWandererA = aWandererA + ((RotL64(aCross, 3U) + aOrbiterJ) + RotL64(aOrbiterB, 37U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 29U) + aOrbiterC) + RotL64(aOrbiterF, 14U)) + aNonceWordK);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 19U));
            aCarry = aCarry + (RotL64(aWandererA, 48U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererD, 27U) ^ aWandererF);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 29U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 23U));
            aCarry = aCarry + RotL64(aWandererE, 39U);
            aCarry = aCarry + RotL64(aIngress, 12U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 16950U)) & S_BLOCK1], 39U) ^ RotL64(aFireLaneA[((aIndex + 17384U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 19581U)) & S_BLOCK1], 20U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordE));
            //
            aCross = RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 16667U)) & S_BLOCK1], 4U) ^ RotL64(aInvestLaneD[((aIndex + 18102U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aIngress, 51U) ^ RotL64(aCross, 5U)) + (RotL64(aCarry, 21U) + RotL64(aPrevious, 34U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterH = (((aWandererH + RotL64(aPrevious, 23U)) + RotL64(aCarry, 39U)) + 13350544654542863236U) + aNonceWordP;
            aOrbiterC = ((aWandererK + RotL64(aIngress, 34U)) + 12364346790125404372U) + aPhaseEOrbiterAssignSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = (aWandererC + RotL64(aScatter, 27U)) + 9738750172849512764U;
            aOrbiterF = (aWandererI + RotL64(aCross, 11U)) + 3781373837635491421U;
            aOrbiterE = ((aWandererE + RotL64(aPrevious, 3U)) + 16635020317512702337U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = (aWandererA + RotL64(aIngress, 37U)) + 5383653921676231276U;
            aOrbiterG = (aWandererB + RotL64(aCross, 19U)) + 10181959815492056493U;
            aOrbiterA = (aWandererF + RotL64(aScatter, 43U)) + 10005510924273927017U;
            aOrbiterI = (aWandererG + RotL64(aIngress, 54U)) + 9524687662265740565U;
            aOrbiterK = (((aWandererD + RotL64(aCross, 21U)) + RotL64(aCarry, 29U)) + 4259138552009771014U) + aNonceWordM;
            aOrbiterJ = (((aWandererJ + RotL64(aScatter, 39U)) + RotL64(aCarry, 5U)) + 8973051213213726023U) + aNonceWordI;
            //
            aOrbiterH = (((aOrbiterH + aOrbiterC) + 17602611840127337490U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordG;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 8218984546932905269U;
            aOrbiterD = RotL64((aOrbiterD * 17504305273683304231U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 18102186122213487888U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 2629927500298092976U;
            aOrbiterB = RotL64((aOrbiterB * 6983280164448292723U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 2491581597835795234U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 9506602492971620955U;
            aOrbiterH = RotL64((aOrbiterH * 9559829640915637163U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 13422942713680612924U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 15037354693234876601U;
            aOrbiterI = RotL64((aOrbiterI * 12692376075738621447U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 12896066842192894694U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 2202952306291905855U;
            aOrbiterG = RotL64((aOrbiterG * 6779368532763429997U), 37U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 12160313482450599313U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 10812986281270407756U;
            aOrbiterA = RotL64((aOrbiterA * 7786608700746771809U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 12474638293190144525U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 5882870951276225224U;
            aOrbiterC = RotL64((aOrbiterC * 15532427302173572457U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 3782896138051179209U) + aNonceWordD;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 10965680631059882311U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 14060923998307082385U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 15650420683333746952U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 4110674660963676864U;
            aOrbiterF = RotL64((aOrbiterF * 11724979274890265275U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 694817156953099464U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 4402927404825116007U;
            aOrbiterE = RotL64((aOrbiterE * 579586789292520113U), 39U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 6849178151532923489U) + aNonceWordH;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 13350544654542863236U;
            aOrbiterJ = RotL64((aOrbiterJ * 2416097748778941523U), 47U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterK, 29U);
            aIngress = aIngress + (RotL64(aOrbiterB, 37U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 26U));
            aIngress = aIngress + (RotL64(aOrbiterA, 47U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 5U));
            aIngress = aIngress + RotL64(aOrbiterD, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterK, 43U)) + aOrbiterD);
            aWandererF = aWandererF + ((((RotL64(aScatter, 37U) + aOrbiterJ) + RotL64(aOrbiterB, 39U)) + RotL64(aCarry, 29U)) + aNonceWordA);
            aWandererK = aWandererK ^ (((RotL64(aCross, 19U) + aOrbiterE) + RotL64(aOrbiterF, 48U)) + aNonceWordB);
            aWandererH = aWandererH + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterH, 3U)) + aOrbiterJ) + RotL64(aCarry, 53U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 56U) + aOrbiterJ) + RotL64(aOrbiterG, 5U)) + aNonceWordF);
            aWandererE = aWandererE + ((RotL64(aCross, 13U) + RotL64(aOrbiterJ, 53U)) + aOrbiterC);
            aWandererG = aWandererG ^ ((((RotL64(aPrevious, 39U) + RotL64(aOrbiterI, 19U)) + aOrbiterD) + aNonceWordO) + aPhaseEWandererUpdateSaltB[((aIndex + 6U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 29U) + aOrbiterA) + RotL64(aOrbiterF, 23U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 52U) + aOrbiterD) + RotL64(aOrbiterB, 46U));
            aWandererJ = aWandererJ + ((RotL64(aIngress, 41U) + aOrbiterH) + RotL64(aOrbiterF, 27U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterH, 11U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 47U));
            aCarry = aCarry + (RotL64(aWandererJ, 39U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererK, 37U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererI, 26U) ^ aWandererH);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 11U));
            aCarry = aCarry + RotL64(aWandererF, 13U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 26512U)) & S_BLOCK1], 21U) ^ RotL64(aFireLaneB[((aIndex + 24255U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 24236U)) & S_BLOCK1], 6U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 24840U)) & S_BLOCK1], 57U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 23198U)) & S_BLOCK1], 42U));
            aCross ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 23623U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aPrevious, 53U) ^ RotL64(aCarry, 40U)) ^ (RotL64(aCross, 11U) + RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterH = ((aWandererG + RotL64(aPrevious, 13U)) + 4622023259121087483U) + aPhaseEOrbiterAssignSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterC = ((aWandererB + RotL64(aIngress, 27U)) + 10253505250223501352U) + aNonceWordF;
            aOrbiterG = (aWandererH + RotL64(aCross, 6U)) + 17133877904420462669U;
            aOrbiterD = (((aWandererC + RotL64(aScatter, 11U)) + RotL64(aCarry, 27U)) + 6162827793741796700U) + aNonceWordP;
            aOrbiterA = ((aWandererA + RotL64(aPrevious, 51U)) + RotL64(aCarry, 19U)) + 9610986424765907615U;
            aOrbiterJ = ((aWandererI + RotL64(aIngress, 19U)) + 11210747154264753754U) + aNonceWordJ;
            aOrbiterI = (((aWandererK + RotL64(aCross, 23U)) + RotL64(aCarry, 5U)) + 16554205219580654546U) + aPhaseEOrbiterAssignSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterB = (aWandererD + RotL64(aScatter, 41U)) + 10352576357413766388U;
            aOrbiterE = (aWandererF + RotL64(aPrevious, 37U)) + 3651845783283479752U;
            aOrbiterK = (aWandererJ + RotL64(aScatter, 39U)) + 18145542190463500476U;
            aOrbiterF = (aWandererE + RotL64(aIngress, 46U)) + 5415609566767162857U;
            //
            aOrbiterH = (((aOrbiterH + aOrbiterC) + 2033734872464201570U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1]) + aNonceWordO;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 3507213117125813345U;
            aOrbiterG = RotL64((aOrbiterG * 5453058336688881113U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 8716253393049851856U) + aNonceWordL;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 695984869565941856U;
            aOrbiterJ = RotL64((aOrbiterJ * 8377921610764044735U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 7661578828878284931U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 906654265099155956U;
            aOrbiterI = RotL64((aOrbiterI * 8117625377607536949U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 6050049984731254612U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 17882717590338190821U;
            aOrbiterE = RotL64((aOrbiterE * 10807367411402733215U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 4996521991532815957U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 4246460672800604436U;
            aOrbiterD = RotL64((aOrbiterD * 12047466401960824903U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 8700148116452518842U) + aNonceWordN;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 10039050281847466206U;
            aOrbiterA = RotL64((aOrbiterA * 11884791271239660157U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 4513844680425845372U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 3037563127442815153U;
            aOrbiterK = RotL64((aOrbiterK * 18363509277992292407U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 1005237931570968724U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 1373258132025712065U;
            aOrbiterC = RotL64((aOrbiterC * 10458020799382532395U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 12759144329395682277U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 5139371668116336931U;
            aOrbiterB = RotL64((aOrbiterB * 10761543179345026943U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 3211005174890625715U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 18045286961878287418U;
            aOrbiterF = RotL64((aOrbiterF * 4536094526540761611U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 4454078771279674978U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 4622023259121087483U;
            aOrbiterH = RotL64((aOrbiterH * 8991756794989027019U), 21U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterB, 51U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 21U));
            aIngress = aIngress + (RotL64(aOrbiterK, 35U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 13U));
            aIngress = aIngress + (RotL64(aOrbiterH, 29U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterG, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterC, 21U)) + aOrbiterA);
            aWandererJ = aWandererJ + ((RotL64(aCross, 51U) + aOrbiterH) + RotL64(aOrbiterJ, 19U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 18U) + aOrbiterD) + RotL64(aOrbiterA, 43U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 39U) + aOrbiterE) + RotL64(aOrbiterJ, 51U)) + RotL64(aCarry, 19U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterI, 54U)) + aOrbiterF);
            aWandererF = aWandererF + ((((RotL64(aScatter, 35U) + aOrbiterK) + RotL64(aOrbiterG, 3U)) + RotL64(aCarry, 43U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 23U) + RotL64(aOrbiterG, 41U)) + aOrbiterD) + aNonceWordH);
            aWandererI = aWandererI + (((RotL64(aPrevious, 5U) + aOrbiterC) + RotL64(aOrbiterK, 35U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterB, 11U)) + aOrbiterI) + aNonceWordI);
            aWandererC = aWandererC + ((RotL64(aPrevious, 11U) + aOrbiterA) + RotL64(aOrbiterJ, 57U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 26U) + aOrbiterG) + RotL64(aOrbiterB, 46U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 39U));
            aCarry = aCarry + (RotL64(aWandererH, 4U) ^ aWandererD);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 41U));
            aCarry = aCarry + (RotL64(aWandererK, 35U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererI, 21U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererJ, 57U);
            aCarry = aCarry + RotL64(aIngress, 6U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 27752U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneA[((aIndex + 30861U)) & S_BLOCK1], 41U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 29127U)) & S_BLOCK1], 24U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31682U)) & S_BLOCK1], 53U) ^ RotL64(aInvestLaneB[((aIndex + 27573U)) & S_BLOCK1], 22U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aPrevious, 38U) + RotL64(aCarry, 5U)) + (RotL64(aCross, 51U) ^ RotL64(aIngress, 19U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterG = (((aWandererA + RotL64(aPrevious, 35U)) + RotL64(aCarry, 29U)) + 6318740973868639425U) + aNonceWordF;
            aOrbiterK = ((aWandererK + RotL64(aCross, 37U)) + 5487840061430920881U) + aNonceWordD;
            aOrbiterD = ((aWandererJ + RotL64(aScatter, 3U)) + 10258706763248072672U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterH = ((aWandererB + RotL64(aIngress, 39U)) + RotL64(aCarry, 47U)) + 18356875269730338208U;
            aOrbiterI = (aWandererI + RotL64(aScatter, 19U)) + 12883160282903147010U;
            aOrbiterF = ((aWandererH + RotL64(aIngress, 57U)) + 1010140474942697730U) + aNonceWordN;
            aOrbiterA = (aWandererC + RotL64(aCross, 50U)) + 17733939421700898293U;
            aOrbiterE = ((aWandererF + RotL64(aPrevious, 23U)) + 13693055887924981201U) + aPhaseEOrbiterAssignSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterJ = (aWandererD + RotL64(aScatter, 47U)) + 14574732452793385269U;
            aOrbiterB = (aWandererG + RotL64(aIngress, 5U)) + 10832873941223609012U;
            aOrbiterC = ((aWandererE + RotL64(aCross, 30U)) + RotL64(aCarry, 13U)) + 8212600587135328040U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 5312744319781971178U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 6173741211706546923U;
            aOrbiterD = RotL64((aOrbiterD * 12854414066390848249U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 3693249147883790810U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterH) ^ 18365859989736602556U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterK = RotL64((aOrbiterK * 3348463719324104997U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 10645056678337549771U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 1175668356822251045U;
            aOrbiterA = RotL64((aOrbiterA * 6579675292775345579U), 39U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 13556844570541823717U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 4790355739411849736U;
            aOrbiterG = RotL64((aOrbiterG * 4083544011788850307U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 14905575502272644116U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 17047244574558476634U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 2356386971503880047U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 10161614295718414869U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 13413914082651612468U;
            aOrbiterI = RotL64((aOrbiterI * 16224039093981079491U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 6072693130156927774U) + aNonceWordC;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 4333656233793103787U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9374745547133955709U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 17209776289202130250U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 11752001118070361543U) ^ aNonceWordB;
            aOrbiterH = RotL64((aOrbiterH * 4416523594812872339U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 15367365111105608277U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 8650687767097460704U;
            aOrbiterE = RotL64((aOrbiterE * 11430451559660578667U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 18074648514448405693U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 10857586858462237581U;
            aOrbiterF = RotL64((aOrbiterF * 3722891011080095849U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 17219932344278345591U) + aNonceWordE;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 6318740973868639425U;
            aOrbiterB = RotL64((aOrbiterB * 8846295038878812229U), 37U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterK, 11U);
            aIngress = aIngress + (RotL64(aOrbiterF, 39U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterD, 21U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 28U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 57U));
            aIngress = aIngress + RotL64(aOrbiterC, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 43U) + RotL64(aOrbiterA, 21U)) + aOrbiterH) + aNonceWordL);
            aWandererD = aWandererD + ((RotL64(aCross, 51U) + aOrbiterH) + RotL64(aOrbiterF, 44U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 53U) + aOrbiterA) + RotL64(aOrbiterE, 23U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aScatter, 6U) + RotL64(aOrbiterK, 3U)) + aOrbiterC) + RotL64(aCarry, 29U)) + aNonceWordO);
            aWandererH = aWandererH ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterI, 19U)) + aOrbiterD);
            aWandererF = aWandererF + ((RotL64(aScatter, 11U) + RotL64(aOrbiterD, 39U)) + aOrbiterB);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 29U) + aOrbiterK) + RotL64(aOrbiterA, 29U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aPrevious, 26U) + RotL64(aOrbiterG, 35U)) + aOrbiterK);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterB, 57U)) + aOrbiterJ);
            aWandererG = aWandererG + (((RotL64(aCross, 13U) + RotL64(aOrbiterK, 47U)) + aOrbiterH) + RotL64(aCarry, 53U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterI, 10U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 50U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererA, 39U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererC, 35U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererI, 13U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererG, 57U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererB, 60U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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

void TwistExpander_BasketBall_Arx::Seed_F(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xA61FDEB6BD67379BULL + 0xED2C637B8C1189C7ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xA5D34FC05AF17949ULL + 0xFF03AD11A9405AE0ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xF8F5BB68449D2C9FULL + 0xE4ACF8FA27727BB5ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xD8B645A018B1F943ULL + 0xEE28B0A06A52AC15ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xAA05AA0A071CF427ULL + 0xC2D8B2B6F35ADB9CULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xDB6E2992139CFA3BULL + 0xBBDEDC04439D26F9ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xB26FA42B6E89A5F9ULL + 0xB9DBF10817DD9FE2ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xEAEFF05A10A534C3ULL + 0x8700FA1F1274C127ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x857DDCD8553CE30BULL + 0xB0EBBFCE2AB50AA5ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xADD671704938AEB3ULL + 0xD110F32D1A9A59F3ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x9056913A3AC84C7BULL + 0xCF5BA5575BB57F2FULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xA3EDF67E32DB10EBULL + 0xBA612579A7335C1BULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x87651D4F3AD9D23BULL + 0xF9E60BA36810704EULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x9B106E5CFE679CB9ULL + 0xF9EECBA4E94000DAULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x982BC9EF1B086BE9ULL + 0x91B69BCCF33F2C9DULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xC83CB1DDAAC910D5ULL + 0x8C149A9C96721FCEULL);
    // GSeedRunSeed_F seed_loop_f (start)
    {
        // GSeedRunSeed_F seed_loop_f lane group
        // read from: aOperationLaneA, aOperationLaneB, aInvestLaneC, aOperationLaneC, aOperationLaneD, aSnowLaneA, aSnowLaneC, aWorkLaneD, aSnowLaneB, aSnowLaneD, aInvestLaneA, aExpandLaneA, aWorkLaneC, aExpandLaneB, aInvestLaneD, aExpandLaneC, aInvestLaneB
        // write to: aSnowLaneC, aSnowLaneD, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // seed_loop_f loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aInvestLaneC
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aInvestLaneC forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aSnowLaneA
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aSnowLaneA backward/forward random
        // write to: aSnowLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 2550U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneB[((aIndex + 1280U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 4761U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 3857U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 5136U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aSnowLaneA[((aIndex + 4915U)) & S_BLOCK1], 60U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCarry, 57U) ^ RotL64(aIngress, 40U)) ^ (RotL64(aPrevious, 5U) + RotL64(aCross, 21U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterB = (aWandererI + RotL64(aCross, 46U)) + 1457104756581596530U;
            aOrbiterD = (aWandererK + RotL64(aScatter, 51U)) + 6127240317844622874U;
            aOrbiterC = ((aWandererF + RotL64(aIngress, 19U)) + RotL64(aCarry, 57U)) + 16492290056044189421U;
            aOrbiterJ = ((aWandererJ + RotL64(aPrevious, 13U)) + 10963676850938416468U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = ((aWandererA + RotL64(aScatter, 5U)) + 4872917367399752405U) + aNonceWordB;
            aOrbiterE = (((aWandererE + RotL64(aPrevious, 29U)) + RotL64(aCarry, 21U)) + 15218882377875616148U) + aNonceWordK;
            aOrbiterG = ((aWandererH + RotL64(aCross, 41U)) + RotL64(aCarry, 43U)) + 5934166612122118251U;
            aOrbiterK = ((aWandererG + RotL64(aIngress, 23U)) + 14215280930872003003U) + aNonceWordL;
            aOrbiterI = ((aWandererC + RotL64(aCross, 34U)) + 11428034799044600979U) + aPhaseFOrbiterAssignSaltC[((aIndex + 7U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 5453003654321728726U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 14273775120265649389U;
            aOrbiterC = RotL64((aOrbiterC * 5139018128323795309U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 328723770018440271U) + aNonceWordG;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 13032190719588211088U;
            aOrbiterA = RotL64((aOrbiterA * 13363368478932798315U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 2386881543033598494U) + aNonceWordA;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 1649501123340887116U;
            aOrbiterE = RotL64((aOrbiterE * 11148976582360499033U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 16462401546754210583U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 1510579201823042227U;
            aOrbiterD = RotL64((aOrbiterD * 16287912400104043275U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 6889066000014251983U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = (((aOrbiterB ^ aOrbiterI) ^ 11324594596597724357U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterB = RotL64((aOrbiterB * 15344987814648586023U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 12237796033168436537U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 17306069670330000343U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 3167451351403385259U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 14197284538008811658U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 4754134852883071927U;
            aOrbiterK = RotL64((aOrbiterK * 3484427259538998699U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 17201907781639753736U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 8318419319239859855U;
            aOrbiterJ = RotL64((aOrbiterJ * 10320390501983802091U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 16012488623961565780U) + aNonceWordE;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 15583721012865354925U;
            aOrbiterI = RotL64((aOrbiterI * 10656414363201743961U), 13U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterJ, 60U);
            aIngress = aIngress + (RotL64(aOrbiterG, 13U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterK, 23U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 3U));
            aIngress = aIngress + RotL64(aOrbiterE, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterI, 53U)) + aOrbiterD);
            aWandererE = aWandererE + (((RotL64(aPrevious, 22U) + RotL64(aOrbiterG, 28U)) + aOrbiterC) + aNonceWordJ);
            aWandererJ = aWandererJ ^ ((((RotL64(aIngress, 11U) + RotL64(aOrbiterA, 37U)) + aOrbiterE) + aNonceWordC) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aCross, 5U) + aOrbiterE) + RotL64(aOrbiterJ, 13U)) + RotL64(aCarry, 11U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 41U) + aOrbiterC) + RotL64(aOrbiterA, 57U));
            aWandererF = aWandererF + ((((RotL64(aIngress, 37U) + RotL64(aOrbiterC, 5U)) + aOrbiterE) + RotL64(aCarry, 19U)) + aNonceWordP);
            aWandererH = aWandererH ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterI, 19U)) + aOrbiterB);
            aWandererG = aWandererG + ((RotL64(aPrevious, 52U) + RotL64(aOrbiterJ, 42U)) + aOrbiterI);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterK, 23U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererH, 53U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererG, 27U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererJ, 23U) ^ aWandererA);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 10U));
            aCarry = aCarry + RotL64(aWandererE, 57U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aSnowLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_f loop 2
        // ingress from: aSnowLaneC, aOperationLaneC, aOperationLaneD, aWorkLaneD
        // ingress directions: aSnowLaneC forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aWorkLaneD forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aSnowLaneB
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aSnowLaneB backward/forward random
        // write to: aSnowLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneC[((aIndex + 9367U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneC[((aIndex + 9450U)) & S_BLOCK1], 29U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 7602U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneD[((aIndex + 9040U)) & S_BLOCK1], 54U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 8671U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 8364U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aSnowLaneB[((aIndex + 8533U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aPrevious, 39U) ^ RotL64(aCarry, 27U)) ^ (RotL64(aIngress, 12U) + RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterC = (aWandererI + RotL64(aScatter, 3U)) + 2617613537256538553U;
            aOrbiterF = ((aWandererE + RotL64(aIngress, 58U)) + 16642868916835132715U) + aPhaseFOrbiterAssignSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterH = ((aWandererF + RotL64(aPrevious, 11U)) + RotL64(aCarry, 23U)) + 10860291124337073254U;
            aOrbiterE = ((aWandererK + RotL64(aCross, 19U)) + 6432511273906902472U) + aNonceWordI;
            aOrbiterG = ((aWandererH + RotL64(aScatter, 51U)) + 7505375005848241910U) + aNonceWordK;
            aOrbiterD = ((aWandererG + RotL64(aIngress, 35U)) + RotL64(aCarry, 57U)) + 11086616004678821329U;
            aOrbiterI = (aWandererD + RotL64(aCross, 47U)) + 3298830587569881951U;
            aOrbiterJ = (aWandererJ + RotL64(aPrevious, 43U)) + 9775143140064220979U;
            aOrbiterB = ((((aWandererC + RotL64(aCross, 30U)) + RotL64(aCarry, 13U)) + 4147601326580823120U) + aPhaseFOrbiterAssignSaltF[((aIndex + 24U)) & S_SALT1]) + aNonceWordF;
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 12245920269898100415U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 8391940489176734499U;
            aOrbiterH = RotL64((aOrbiterH * 9119606167674098007U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 17876893379544668477U) + aNonceWordH;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 18301882058180370541U;
            aOrbiterG = RotL64((aOrbiterG * 16680384667098921309U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 6869225862715140102U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 15404118372589259800U;
            aOrbiterI = RotL64((aOrbiterI * 5766851935950389915U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 17757381020518233814U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 17677969146092374455U;
            aOrbiterF = RotL64((aOrbiterF * 3469432916562405063U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 15783378556632870114U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 5792858258663697864U;
            aOrbiterE = RotL64((aOrbiterE * 12008981883482080427U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 11737803388202260296U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 16001927091970715330U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 3062030309852922061U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 1749586939123286632U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 6169421068855905938U;
            aOrbiterB = RotL64((aOrbiterB * 12374789910763348695U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 10073586820719728062U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 17744171227198661555U;
            aOrbiterD = RotL64((aOrbiterD * 10658375268803957647U), 41U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterG) + 1149819647337612792U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1]) + aNonceWordA;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 7725598665625892006U;
            aOrbiterJ = RotL64((aOrbiterJ * 15097586655234391559U), 27U);
            //
            aIngress = RotL64(aOrbiterB, 19U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 11U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 38U));
            aIngress = aIngress + (RotL64(aOrbiterC, 47U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterD, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterE, 28U)) + aOrbiterD) + aNonceWordM);
            aWandererH = aWandererH + (((RotL64(aIngress, 5U) + aOrbiterF) + RotL64(aOrbiterG, 11U)) + RotL64(aCarry, 39U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 23U) + aOrbiterB) + RotL64(aOrbiterE, 19U)) + aNonceWordP);
            aWandererE = aWandererE + ((RotL64(aScatter, 57U) + RotL64(aOrbiterI, 35U)) + aOrbiterG);
            aWandererK = aWandererK ^ (((RotL64(aCross, 38U) + RotL64(aOrbiterG, 41U)) + aOrbiterD) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aIngress, 43U) + RotL64(aOrbiterE, 53U)) + aOrbiterJ);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 19U) + aOrbiterC) + RotL64(aOrbiterF, 24U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 51U) + aOrbiterH) + RotL64(aOrbiterJ, 5U)) + RotL64(aCarry, 19U)) + aNonceWordO);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 30U) + RotL64(aOrbiterI, 57U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererI, 6U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererD, 29U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererG, 3U) ^ aWandererJ);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 23U));
            aCarry = aCarry + RotL64(aWandererE, 47U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aSnowLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_f loop 3
        // ingress from: aSnowLaneD, aOperationLaneA, aInvestLaneA
        // ingress directions: aSnowLaneD forward forced, aOperationLaneA forward forced, aInvestLaneA forward/backward random
        // cross from: aSnowLaneC, aOperationLaneC
        // cross directions: aSnowLaneC backward forced, aOperationLaneC backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneD[((aIndex + 16305U)) & S_BLOCK1], 40U) ^ RotL64(aOperationLaneA[((aIndex + 11652U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aInvestLaneA[((aIndex + 14307U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 10968U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneC[((aIndex + 12657U)) & S_BLOCK1], 24U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCarry, 56U)) ^ (RotL64(aCross, 37U) + RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterE = ((((aWandererC + RotL64(aIngress, 5U)) + RotL64(aCarry, 35U)) + 2571116506511057880U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 10U)) & S_SALT1]) + aNonceWordG;
            aOrbiterJ = ((aWandererJ + RotL64(aCross, 34U)) + 13112435411509707292U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterG = (aWandererF + RotL64(aPrevious, 41U)) + 10403251762787357256U;
            aOrbiterA = ((aWandererA + RotL64(aScatter, 47U)) + RotL64(aCarry, 43U)) + 8461951095541400405U;
            aOrbiterC = ((aWandererI + RotL64(aPrevious, 57U)) + 9890793478557463815U) + aNonceWordA;
            aOrbiterB = (aWandererK + RotL64(aCross, 23U)) + 3030229465991783707U;
            aOrbiterI = (aWandererD + RotL64(aIngress, 29U)) + 7273848154043719247U;
            aOrbiterK = ((aWandererE + RotL64(aScatter, 19U)) + 10681774862516028276U) + aNonceWordI;
            aOrbiterH = ((aWandererH + RotL64(aPrevious, 10U)) + RotL64(aCarry, 3U)) + 7105082755586853104U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 6588579345319551129U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 14616333550242386092U;
            aOrbiterG = RotL64((aOrbiterG * 2934574715879306337U), 39U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 15439666290229654921U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = (((aOrbiterB ^ aOrbiterA) ^ 3360304356760164799U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterB = RotL64((aOrbiterB * 5164191920584106237U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 14438730801970761889U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 14515616787452085729U;
            aOrbiterK = RotL64((aOrbiterK * 2041601927968559821U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 4167853822635132419U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 8950982233003320239U;
            aOrbiterJ = RotL64((aOrbiterJ * 887144270884244907U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 12391327853728029953U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 7100871010552394421U;
            aOrbiterE = RotL64((aOrbiterE * 16552349374101955967U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 15381697462381887944U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 6801677551341079401U;
            aOrbiterA = RotL64((aOrbiterA * 13325954438427340703U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 947011315719204867U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 6356920162398333481U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 5566721941682667419U), 27U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 8910262020598577378U) + aNonceWordH;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 8778455415977526457U) ^ aNonceWordD;
            aOrbiterH = RotL64((aOrbiterH * 4092470497616637283U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 5585696961453127223U) + aNonceWordF;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 9670655481681494412U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7863197168965036383U), 47U);
            //
            aIngress = RotL64(aOrbiterI, 3U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterJ, 53U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterH, 37U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterK, 40U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterB, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aScatter, 47U) + RotL64(aOrbiterG, 47U)) + aOrbiterJ) + RotL64(aCarry, 39U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 10U) + aOrbiterH) + RotL64(aOrbiterK, 30U));
            aWandererE = aWandererE + ((((RotL64(aIngress, 35U) + RotL64(aOrbiterE, 19U)) + aOrbiterB) + RotL64(aCarry, 57U)) + aNonceWordJ);
            aWandererA = aWandererA ^ (((RotL64(aCross, 5U) + aOrbiterI) + RotL64(aOrbiterK, 35U)) + aNonceWordE);
            aWandererI = aWandererI + (((RotL64(aPrevious, 39U) + aOrbiterJ) + RotL64(aOrbiterC, 57U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterC, 23U)) + aOrbiterH) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aScatter, 27U) + RotL64(aOrbiterA, 4U)) + aOrbiterJ);
            aWandererC = aWandererC ^ ((RotL64(aCross, 14U) + RotL64(aOrbiterE, 13U)) + aOrbiterJ);
            aWandererK = aWandererK + ((RotL64(aScatter, 57U) + RotL64(aOrbiterB, 51U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 23U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 44U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 13U));
            aCarry = aCarry + (RotL64(aWandererI, 57U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererA, 47U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 20776U)) & S_BLOCK1], 13U) ^ RotL64(aSnowLaneC[((aIndex + 18252U)) & S_BLOCK1], 24U));
            aIngress ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 18414U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 20147U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 21293U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCross, 43U) ^ RotL64(aPrevious, 11U)) + (RotL64(aIngress, 58U) ^ RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterG = (aWandererG + RotL64(aScatter, 39U)) + 2558105147674438050U;
            aOrbiterE = ((aWandererE + RotL64(aIngress, 24U)) + RotL64(aCarry, 3U)) + 15856662514774702561U;
            aOrbiterD = ((aWandererH + RotL64(aPrevious, 35U)) + 13346869226246584582U) + aNonceWordD;
            aOrbiterK = (aWandererK + RotL64(aCross, 19U)) + 7632111846116243973U;
            aOrbiterA = (aWandererI + RotL64(aIngress, 43U)) + 2102101361626976279U;
            aOrbiterH = ((aWandererA + RotL64(aScatter, 14U)) + 5605968705067851563U) + aPhaseFOrbiterAssignSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterC = ((aWandererC + RotL64(aCross, 57U)) + RotL64(aCarry, 41U)) + 6842483186584326681U;
            aOrbiterJ = ((((aWandererF + RotL64(aPrevious, 29U)) + RotL64(aCarry, 19U)) + 5559797213819425064U) + aPhaseFOrbiterAssignSaltE[((aIndex + 17U)) & S_SALT1]) + aNonceWordF;
            aOrbiterI = (aWandererB + RotL64(aCross, 5U)) + 12422313931331576759U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 2751024420047872601U) + aNonceWordN;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 11031320239359798610U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8607639453141148025U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 14366375309473793217U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 11971479429768505316U;
            aOrbiterA = RotL64((aOrbiterA * 10063001532313098203U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 3947595951884469542U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 17882767922372770896U;
            aOrbiterC = RotL64((aOrbiterC * 3361906348965810211U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 513871456983509223U) + aNonceWordB;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 5951677013597794294U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8508629569649935293U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 437626309049021931U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 466674061172005705U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 1310502572084891157U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 12362602809233133718U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 10525852878882195702U;
            aOrbiterI = RotL64((aOrbiterI * 17755022180514914325U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 17927000184308583095U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 566723721423470052U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 17710534355278632573U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 9504585484034413577U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 4614306037721859929U;
            aOrbiterK = RotL64((aOrbiterK * 170807293799483539U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 1463218357720031588U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 4036696102163560633U;
            aOrbiterH = RotL64((aOrbiterH * 15389914226155130065U), 47U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterH, 27U);
            aIngress = aIngress + (RotL64(aOrbiterK, 47U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 40U));
            aIngress = aIngress + (RotL64(aOrbiterC, 43U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterI, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterE, 39U)) + aOrbiterD);
            aWandererC = aWandererC + (((RotL64(aPrevious, 10U) + aOrbiterE) + RotL64(aOrbiterJ, 21U)) + RotL64(aCarry, 57U));
            aWandererI = aWandererI ^ ((((RotL64(aIngress, 47U) + RotL64(aOrbiterH, 14U)) + aOrbiterK) + aNonceWordG) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 19U) + RotL64(aOrbiterG, 57U)) + aOrbiterI) + RotL64(aCarry, 35U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 41U) + RotL64(aOrbiterE, 35U)) + aOrbiterI) + aNonceWordA);
            aWandererA = aWandererA + ((RotL64(aPrevious, 27U) + aOrbiterG) + RotL64(aOrbiterK, 43U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 56U) + aOrbiterA) + RotL64(aOrbiterE, 3U));
            aWandererB = aWandererB + ((RotL64(aIngress, 3U) + aOrbiterJ) + RotL64(aOrbiterC, 50U));
            aWandererG = aWandererG ^ ((((RotL64(aScatter, 35U) + aOrbiterA) + RotL64(aOrbiterD, 29U)) + aNonceWordH) + aPhaseFWandererUpdateSaltC[((aIndex + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 23U));
            aCarry = aCarry + (RotL64(aWandererB, 19U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererE, 42U) ^ aWandererG);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 57U));
            aCarry = aCarry + RotL64(aWandererA, 35U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 25856U)) & S_BLOCK1], 3U) ^ RotL64(aSnowLaneD[((aIndex + 22997U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aInvestLaneD[((aIndex + 26475U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 22975U)) & S_BLOCK1], 29U) ^ RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 23013U)) & S_BLOCK1], 58U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aIngress, 39U) + RotL64(aCross, 27U)) ^ (RotL64(aPrevious, 13U) ^ RotL64(aCarry, 52U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterB = (((aWandererF + RotL64(aCross, 35U)) + RotL64(aCarry, 53U)) + 439898681482066326U) + aNonceWordD;
            aOrbiterK = ((aWandererI + RotL64(aIngress, 19U)) + 17362083676671776094U) + aNonceWordM;
            aOrbiterC = (((aWandererH + RotL64(aPrevious, 26U)) + RotL64(aCarry, 5U)) + 6418499837265155024U) + aNonceWordC;
            aOrbiterI = (aWandererA + RotL64(aScatter, 5U)) + 17262244253027454972U;
            aOrbiterD = (aWandererE + RotL64(aPrevious, 43U)) + 2382066162993139503U;
            aOrbiterE = (aWandererJ + RotL64(aCross, 11U)) + 14345808395587174135U;
            aOrbiterG = ((aWandererG + RotL64(aIngress, 30U)) + 7534743166385552851U) + aNonceWordH;
            aOrbiterH = (((aWandererK + RotL64(aScatter, 53U)) + RotL64(aCarry, 39U)) + 16994453324688523966U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterJ = ((aWandererB + RotL64(aIngress, 39U)) + 7079553728544045092U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 3562822704508440641U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 13990892681975857821U;
            aOrbiterC = RotL64((aOrbiterC * 8352929306654078795U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 1796728922368577238U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 6605161260520067178U;
            aOrbiterD = RotL64((aOrbiterD * 8147537646591674091U), 39U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 13994083795942328918U) + aNonceWordE;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 6144523182899107711U;
            aOrbiterE = RotL64((aOrbiterE * 4153879991344611283U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 12247462325297436642U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 1065809332002012789U;
            aOrbiterB = RotL64((aOrbiterB * 5496601177032953251U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 10147919864511540753U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 17138553441127273354U;
            aOrbiterI = RotL64((aOrbiterI * 5773875596275267871U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 2653924016109573974U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 6254416952351699582U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 12756861659704947257U), 43U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterI) + 813046408080197079U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1]) + aNonceWordI;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 9624466135414123483U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 6960320253124395015U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 972586705850825744U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 155283774901960223U;
            aOrbiterH = RotL64((aOrbiterH * 9928051687724257041U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 18200100644751360406U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 1168426822045686004U) ^ aNonceWordA;
            aOrbiterG = RotL64((aOrbiterG * 5867027156069481313U), 5U);
            //
            aIngress = RotL64(aOrbiterI, 19U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 5U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 28U));
            aIngress = aIngress + (RotL64(aOrbiterH, 57U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterD, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterI, 11U)) + aOrbiterH);
            aWandererA = aWandererA + (((RotL64(aCross, 35U) + RotL64(aOrbiterJ, 30U)) + aOrbiterE) + RotL64(aCarry, 23U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 12U) + aOrbiterD) + RotL64(aOrbiterJ, 37U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 3U) + aOrbiterB) + RotL64(aOrbiterI, 19U)) + RotL64(aCarry, 39U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterB, 3U)) + aOrbiterH) + aPhaseFWandererUpdateSaltE[((aIndex + 15U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aScatter, 57U) + aOrbiterE) + RotL64(aOrbiterG, 58U)) + aNonceWordJ);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 28U) + RotL64(aOrbiterD, 53U)) + aOrbiterE) + aNonceWordL);
            aWandererB = aWandererB + (((RotL64(aPrevious, 43U) + aOrbiterK) + RotL64(aOrbiterD, 47U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 51U) + aOrbiterH) + RotL64(aOrbiterC, 23U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + (RotL64(aWandererK, 54U) ^ aWandererA);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 51U));
            aCarry = aCarry + (RotL64(aWandererE, 43U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererG, 27U);
            aCarry = aCarry + RotL64(aIngress, 22U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 29619U)) & S_BLOCK1], 20U) ^ RotL64(aExpandLaneA[((aIndex + 31677U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aInvestLaneB[((aIndex + 29862U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28712U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneB[((aIndex + 30781U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCross, 53U) + RotL64(aPrevious, 23U)) ^ (RotL64(aIngress, 37U) ^ RotL64(aCarry, 6U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterC = ((aWandererD + RotL64(aIngress, 57U)) + 4848316479321533394U) + aNonceWordA;
            aOrbiterJ = (aWandererG + RotL64(aPrevious, 46U)) + 6919360256662636195U;
            aOrbiterF = ((((aWandererA + RotL64(aScatter, 29U)) + RotL64(aCarry, 3U)) + 9897013582181108544U) + aPhaseFOrbiterAssignSaltB[((aIndex + 13U)) & S_SALT1]) + aNonceWordC;
            aOrbiterI = ((aWandererC + RotL64(aCross, 41U)) + RotL64(aCarry, 29U)) + 7319353809896158678U;
            aOrbiterE = (aWandererF + RotL64(aScatter, 5U)) + 2848175435514849859U;
            aOrbiterB = (aWandererB + RotL64(aIngress, 37U)) + 6967780718720437934U;
            aOrbiterA = (((aWandererE + RotL64(aPrevious, 51U)) + RotL64(aCarry, 51U)) + 10143884766603388136U) + aPhaseFOrbiterAssignSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = (aWandererJ + RotL64(aCross, 18U)) + 8675965006150972051U;
            aOrbiterH = ((aWandererK + RotL64(aScatter, 23U)) + 16350117755560994281U) + aNonceWordF;
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 17976597517118423760U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 1399631141355370237U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 16537788276543236833U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 3590613762034716792U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 5134624314245932157U;
            aOrbiterJ = RotL64((aOrbiterJ * 13077589037975283371U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 10082236952942943654U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 4015535035905433450U;
            aOrbiterC = RotL64((aOrbiterC * 4961808568701908559U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 611474103801573800U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 5786708483794098001U;
            aOrbiterB = RotL64((aOrbiterB * 7694007039340089267U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 5201943497363274455U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 9282160506938328489U;
            aOrbiterE = RotL64((aOrbiterE * 5368182164239021367U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 4932320527498940158U) + aNonceWordJ;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 11576526341731392916U;
            aOrbiterH = RotL64((aOrbiterH * 1712051774729439363U), 41U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 10790691517638887125U) + aNonceWordN;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 16280649213607464422U;
            aOrbiterI = RotL64((aOrbiterI * 10756733801499471873U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 9553716940667712810U) + aNonceWordH;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 11827518270964003341U;
            aOrbiterA = RotL64((aOrbiterA * 1322489827908132831U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 16777463701235809321U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterJ) ^ 3375489084588454149U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterG = RotL64((aOrbiterG * 3335010977457647307U), 47U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterE, 34U);
            aIngress = aIngress + (RotL64(aOrbiterI, 37U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 11U));
            aIngress = aIngress + (RotL64(aOrbiterB, 5U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterA, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aPrevious, 21U) + aOrbiterA) + RotL64(aOrbiterC, 51U)) + RotL64(aCarry, 5U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 60U) + aOrbiterE) + RotL64(aOrbiterI, 47U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aScatter, 41U) + aOrbiterG) + RotL64(aOrbiterA, 36U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterJ, 5U)) + aOrbiterF);
            aWandererK = aWandererK + ((((RotL64(aCross, 13U) + RotL64(aOrbiterH, 27U)) + aOrbiterC) + RotL64(aCarry, 27U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 54U) + aOrbiterB) + RotL64(aOrbiterI, 43U)) + aNonceWordD);
            aWandererE = aWandererE + (((RotL64(aPrevious, 5U) + aOrbiterI) + RotL64(aOrbiterF, 13U)) + aNonceWordE);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 27U) + RotL64(aOrbiterB, 23U)) + aOrbiterA) + aNonceWordM);
            aWandererF = aWandererF + ((RotL64(aPrevious, 35U) + RotL64(aOrbiterE, 18U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 53U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 43U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 3U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 13U));
            aCarry = aCarry + RotL64(aWandererK, 10U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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

void TwistExpander_BasketBall_Arx::Seed_G(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xE46E686D69D3B7ADULL + 0xDFD8F1D32A13C22EULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x83DDE2959C72DD27ULL + 0x9F1297CF8B2585A1ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xCF99A73403D74543ULL + 0xE21CE1427F0E0F24ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xA55A5998C629EF53ULL + 0x819BE2A67C05F43FULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xE29D02B53DDD687FULL + 0xD8ED8D53BA3DDEABULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xDCEE83630239D9B9ULL + 0xF0AA7760002BD9EAULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x9C278958756CF057ULL + 0xADA51E47CB0A0902ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xC5A0E2DBC7B43C5BULL + 0xB0C5712053934F07ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xC6C457392466745DULL + 0xA625C2E3ED680CA2ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xFBCDD2CD3BBA96E7ULL + 0xA182D94E4D7C32FAULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xA16B495EF93AFE3BULL + 0x9371B077A7C5AF08ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xB5B6AB8268F617F3ULL + 0xAC85A6B2492AFDC6ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xB9C13F8341E48F8FULL + 0xC4BDD6B82458671EULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xC7A35CECB42E963DULL + 0x9917F22BA0FAAA5FULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x8F163ADE575D4A4DULL + 0x936DD2C36F1CD513ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0x96480BE1719BB877ULL + 0xEE5F6CE5ABDC6726ULL);
    // GSeedRunSeed_G seed_loop_h (start)
    {
        // GSeedRunSeed_G seed_loop_h lane group
        // read from: aSnowLaneA, aSnowLaneB, aInvestLaneB, aSnowLaneC, aSnowLaneD, aFireLaneB, aWorkLaneA, aInvestLaneD, aFireLaneA, aWorkLaneB, aFireLaneC, aExpandLaneA, aFireLaneD, aExpandLaneB, aInvestLaneA, aExpandLaneC, aInvestLaneC
        // write to: aWorkLaneA, aWorkLaneB, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // seed_loop_h loop 1
        // ingress from: aSnowLaneA, aSnowLaneB, aInvestLaneB
        // ingress directions: aSnowLaneA forward forced, aSnowLaneB forward forced, aInvestLaneB forward/backward random
        // cross from: aSnowLaneC, aSnowLaneD, aFireLaneB
        // cross directions: aSnowLaneC backward forced, aSnowLaneD backward forced, aFireLaneB backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneA[((aIndex + 1277U)) & S_BLOCK1], 37U) ^ RotL64(aSnowLaneB[((aIndex + 1141U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 146U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 1213U)) & S_BLOCK1], 10U) ^ RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 1793U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 498U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aPrevious, 23U) ^ RotL64(aCross, 3U)) + (RotL64(aCarry, 54U) + RotL64(aIngress, 37U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterD = ((aWandererI + RotL64(aScatter, 13U)) + 11480359716598965890U) + aNonceWordN;
            aOrbiterI = (aWandererB + RotL64(aPrevious, 27U)) + 15431182525482873419U;
            aOrbiterG = (aWandererJ + RotL64(aIngress, 43U)) + 11360504974812776707U;
            aOrbiterH = ((aWandererE + RotL64(aCross, 57U)) + RotL64(aCarry, 3U)) + 9292576416573382769U;
            aOrbiterB = ((aWandererD + RotL64(aIngress, 37U)) + RotL64(aCarry, 29U)) + 1549257414531028975U;
            aOrbiterK = ((((aWandererG + RotL64(aPrevious, 50U)) + RotL64(aCarry, 51U)) + 5347769463033129317U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 10U)) & S_SALT1]) + aNonceWordM;
            aOrbiterE = (((aWandererA + RotL64(aScatter, 19U)) + 17019199177478377234U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordL;
            //
            aOrbiterD = (((aOrbiterD + aOrbiterI) + 16558106007323125094U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1]) + aNonceWordC;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 3976182233825939422U;
            aOrbiterG = RotL64((aOrbiterG * 4392162052317572289U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 2889047161195954395U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 2241831345026962605U;
            aOrbiterB = RotL64((aOrbiterB * 5757458560979927857U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 12850802412140579294U) + aNonceWordP;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 13541744735436450160U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 906089290000537439U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 2085863085516538212U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 2969034221711544086U;
            aOrbiterK = RotL64((aOrbiterK * 7768528124408400403U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 6482666944512391472U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 16969153556875844613U;
            aOrbiterD = RotL64((aOrbiterD * 9483462388353216219U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 5161314086757363678U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 7150282484670673211U;
            aOrbiterI = RotL64((aOrbiterI * 8522427002337918663U), 37U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 5465304381272305847U) + aNonceWordG;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 2344610773390354017U) ^ aNonceWordH;
            aOrbiterE = RotL64((aOrbiterE * 17010258514288089191U), 51U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterK, 29U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 10U));
            aIngress = aIngress + (RotL64(aOrbiterB, 57U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterH, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((((RotL64(aIngress, 11U) + RotL64(aOrbiterB, 34U)) + aOrbiterK) + aNonceWordB) + aPhaseHWandererUpdateSaltD[((aIndex + 17U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aCross, 19U) + aOrbiterE) + RotL64(aOrbiterI, 5U)) + RotL64(aCarry, 39U)) + aNonceWordE);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 54U) + RotL64(aOrbiterG, 21U)) + aOrbiterD) + aNonceWordI);
            aWandererG = aWandererG + (((RotL64(aPrevious, 5U) + aOrbiterE) + RotL64(aOrbiterK, 57U)) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 37U) + aOrbiterE) + RotL64(aOrbiterG, 27U));
            aWandererI = aWandererI + ((((RotL64(aPrevious, 43U) + aOrbiterE) + RotL64(aOrbiterB, 11U)) + RotL64(aCarry, 19U)) + aNonceWordD);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterH, 47U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 46U));
            aCarry = aCarry + (RotL64(aWandererI, 41U) ^ aWandererE);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 29U));
            aCarry = aCarry + RotL64(aWandererA, 23U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_h loop 2
        // ingress from: aWorkLaneA, aSnowLaneC, aSnowLaneD, aInvestLaneD
        // ingress directions: aWorkLaneA forward forced, aSnowLaneC forward forced, aSnowLaneD forward forced, aInvestLaneD forward/backward random
        // cross from: aSnowLaneA, aSnowLaneB, aFireLaneA
        // cross directions: aSnowLaneA backward forced, aSnowLaneB backward forced, aFireLaneA backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 10814U)) & S_BLOCK1], 39U) ^ RotL64(aSnowLaneC[((aIndex + 7500U)) & S_BLOCK1], 19U));
            aIngress ^= (RotL64(aSnowLaneD[((aIndex + 6293U)) & S_BLOCK1], 3U) ^ RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 9325U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 8075U)) & S_BLOCK1], 5U) ^ RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 10059U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 10368U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCarry, 43U) ^ RotL64(aPrevious, 23U)) + (RotL64(aIngress, 11U) + RotL64(aCross, 58U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterK = (((aWandererB + RotL64(aIngress, 51U)) + RotL64(aCarry, 41U)) + 10038936806177516123U) + aNonceWordB;
            aOrbiterF = ((aWandererJ + RotL64(aCross, 13U)) + 1773168435195292638U) + aNonceWordG;
            aOrbiterA = ((aWandererA + RotL64(aPrevious, 5U)) + 10655711161526628072U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = (((aWandererF + RotL64(aScatter, 34U)) + RotL64(aCarry, 5U)) + 14422295664639740437U) + aNonceWordM;
            aOrbiterE = ((aWandererK + RotL64(aCross, 57U)) + RotL64(aCarry, 23U)) + 4125228715513159576U;
            aOrbiterJ = ((aWandererC + RotL64(aPrevious, 27U)) + 3670449653158650845U) + aNonceWordI;
            aOrbiterI = ((aWandererH + RotL64(aIngress, 41U)) + 17553727567180813057U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 5111401772713882743U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 7688573124662314413U;
            aOrbiterA = RotL64((aOrbiterA * 10846442063022821393U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 9438375825507814395U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 14177477039902118886U;
            aOrbiterE = RotL64((aOrbiterE * 6467406626985022537U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 16329942595859623928U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 3990536794006836672U;
            aOrbiterJ = RotL64((aOrbiterJ * 579024714339065373U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 5072881436583180756U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 16789727877867289997U;
            aOrbiterI = RotL64((aOrbiterI * 8766246302636197905U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 17313956922306689438U) + aNonceWordE;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 11530878396329822041U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11356860047841383129U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 3612616532321160196U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 4172189825359187763U;
            aOrbiterK = RotL64((aOrbiterK * 12938945495299393177U), 57U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterJ) + 8677279703778052804U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1]) + aNonceWordF;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 1912172980909479362U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 10053289257955474143U), 51U);
            //
            aIngress = RotL64(aOrbiterI, 47U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterJ, 35U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterC, 11U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterF, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((((RotL64(aCross, 57U) + RotL64(aOrbiterA, 21U)) + aOrbiterJ) + aNonceWordC) + aPhaseHWandererUpdateSaltE[((aIndex + 16U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 11U) + aOrbiterE) + RotL64(aOrbiterF, 47U)) + aNonceWordP);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 35U) + aOrbiterK) + RotL64(aOrbiterF, 53U)) + aPhaseHWandererUpdateSaltC[((aIndex + 17U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 21U) + aOrbiterA) + RotL64(aOrbiterC, 60U)) + RotL64(aCarry, 5U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 29U) + aOrbiterC) + RotL64(aOrbiterK, 13U));
            aWandererB = aWandererB + ((((RotL64(aPrevious, 5U) + RotL64(aOrbiterA, 5U)) + aOrbiterK) + RotL64(aCarry, 21U)) + aNonceWordL);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 50U) + aOrbiterJ) + RotL64(aOrbiterI, 39U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 18U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 41U));
            aCarry = aCarry + (RotL64(aWandererJ, 23U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererF, 35U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 12887U)) & S_BLOCK1], 24U) ^ RotL64(aSnowLaneA[((aIndex + 12696U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 11718U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16022U)) & S_BLOCK1], 56U) ^ RotL64(aSnowLaneC[((aIndex + 12769U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aPrevious, 39U) ^ RotL64(aCross, 23U)) + (RotL64(aIngress, 10U) + RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterA = (((aWandererH + RotL64(aCross, 53U)) + RotL64(aCarry, 23U)) + 1087148170018530502U) + aNonceWordJ;
            aOrbiterJ = ((aWandererE + RotL64(aScatter, 5U)) + 15530846874509311414U) + aPhaseHOrbiterAssignSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterG = (aWandererC + RotL64(aPrevious, 19U)) + 16987358651515511212U;
            aOrbiterB = (aWandererK + RotL64(aIngress, 41U)) + 12504143181007924259U;
            aOrbiterF = (((aWandererJ + RotL64(aScatter, 26U)) + 393322117322732418U) + aPhaseHOrbiterAssignSaltE[((aIndex + 15U)) & S_SALT1]) + aNonceWordI;
            aOrbiterK = ((aWandererA + RotL64(aPrevious, 35U)) + RotL64(aCarry, 35U)) + 14325937299241887166U;
            aOrbiterH = (((aWandererI + RotL64(aIngress, 47U)) + RotL64(aCarry, 53U)) + 9395262907017475742U) + aNonceWordM;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 13658510441418344769U) + aNonceWordE;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 6410754322737005336U;
            aOrbiterG = RotL64((aOrbiterG * 6932217611373076391U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 9257290738538818434U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterB) ^ 7489828960857692286U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterK = RotL64((aOrbiterK * 16519674788777989043U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 4118778591214588387U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 16619215231168796563U;
            aOrbiterA = RotL64((aOrbiterA * 14876884956536265157U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 11326283811003573430U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 1865401866017614604U;
            aOrbiterJ = RotL64((aOrbiterJ * 8378326058282460073U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 670150121105733604U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterG) ^ 1499331510641068749U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterB = RotL64((aOrbiterB * 16623742535540383107U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 1116410848560838532U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 2696841341036281779U;
            aOrbiterF = RotL64((aOrbiterF * 9598953298074904869U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 5487352391229549881U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 12008243050943342979U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9087261224804582459U), 19U);
            //
            aIngress = RotL64(aOrbiterH, 53U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 29U));
            aIngress = aIngress + (RotL64(aOrbiterA, 10U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterK, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 19U) + aOrbiterG) + RotL64(aOrbiterJ, 51U));
            aWandererE = aWandererE + ((((RotL64(aPrevious, 43U) + RotL64(aOrbiterF, 3U)) + aOrbiterK) + RotL64(aCarry, 19U)) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 35U) + aOrbiterG) + RotL64(aOrbiterH, 13U)) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 57U) + RotL64(aOrbiterB, 29U)) + aOrbiterF) + RotL64(aCarry, 51U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 10U) + RotL64(aOrbiterA, 57U)) + aOrbiterF) + aNonceWordL);
            aWandererK = aWandererK + ((RotL64(aScatter, 51U) + RotL64(aOrbiterF, 39U)) + aOrbiterH);
            aWandererC = aWandererC ^ (((RotL64(aCross, 29U) + aOrbiterF) + RotL64(aOrbiterG, 20U)) + aNonceWordO);
            //
            aCarry = aCarry + (RotL64(aWandererC, 12U) ^ aWandererI);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 57U));
            aCarry = aCarry + (RotL64(aWandererA, 43U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererK, 19U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_h loop 4
        // ingress from: aExpandLaneA, aWorkLaneA, aFireLaneD
        // ingress directions: aExpandLaneA forward forced, aWorkLaneA forward forced, aFireLaneD forward/backward random
        // cross from: aWorkLaneB, aSnowLaneD
        // cross directions: aWorkLaneB backward forced, aSnowLaneD backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 21284U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneA[((aIndex + 19642U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 19727U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 21349U)) & S_BLOCK1], 53U) ^ RotL64(aSnowLaneD[((aIndex + 18435U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aPrevious, 20U) ^ RotL64(aCross, 51U)) + (RotL64(aIngress, 3U) ^ RotL64(aCarry, 37U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterE = ((aWandererB + RotL64(aCross, 47U)) + 9774364261626083532U) + aNonceWordF;
            aOrbiterC = ((aWandererA + RotL64(aPrevious, 29U)) + RotL64(aCarry, 11U)) + 18059001521926116420U;
            aOrbiterB = (((aWandererJ + RotL64(aIngress, 21U)) + RotL64(aCarry, 29U)) + 10615626210406381148U) + aNonceWordO;
            aOrbiterG = (aWandererE + RotL64(aScatter, 41U)) + 10536484278007898620U;
            aOrbiterH = ((aWandererH + RotL64(aPrevious, 35U)) + 13320663045139972700U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = ((((aWandererG + RotL64(aScatter, 3U)) + RotL64(aCarry, 51U)) + 17127001787268166583U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordE;
            aOrbiterI = (aWandererC + RotL64(aIngress, 60U)) + 16742574590844166551U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 8347719720758228053U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 13502468705946051986U;
            aOrbiterB = RotL64((aOrbiterB * 13822952083584784695U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 3512687886188904904U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 495660316165795934U;
            aOrbiterK = RotL64((aOrbiterK * 6724596801190194913U), 21U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterI) + 5092722552034477356U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordP;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 15641128019608284015U;
            aOrbiterE = RotL64((aOrbiterE * 3621036395703527059U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 15421873776811085458U) + aNonceWordI;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 17978775513204574125U;
            aOrbiterG = RotL64((aOrbiterG * 18359600395119440183U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 16617179197537669849U) + aNonceWordK;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 1931805387534012528U;
            aOrbiterI = RotL64((aOrbiterI * 3400139345857733775U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 9544923119559308431U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 12930999400470173353U;
            aOrbiterC = RotL64((aOrbiterC * 16791006919271490005U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 13673733276226249890U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterB) ^ 2032263473309124738U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterH = RotL64((aOrbiterH * 3088728329261360607U), 41U);
            //
            aIngress = RotL64(aOrbiterH, 37U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 23U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 51U));
            aIngress = aIngress + RotL64(aOrbiterI, 12U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aCross, 13U) + RotL64(aOrbiterC, 51U)) + aOrbiterE) + aNonceWordA);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 23U) + aOrbiterE) + RotL64(aOrbiterK, 13U)) + RotL64(aCarry, 37U)) + aNonceWordC);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 29U) + aOrbiterB) + RotL64(aOrbiterE, 28U)) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aIngress, 56U) + aOrbiterG) + RotL64(aOrbiterH, 43U)) + RotL64(aCarry, 19U)) + aNonceWordM);
            aWandererG = aWandererG ^ (((RotL64(aCross, 47U) + aOrbiterB) + RotL64(aOrbiterH, 37U)) + aPhaseHWandererUpdateSaltA[((aIndex + 27U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 5U) + aOrbiterI) + RotL64(aOrbiterE, 5U)) + aNonceWordB);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 39U) + aOrbiterB) + RotL64(aOrbiterG, 57U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 48U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererC, 21U) ^ aWandererG);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 3U));
            aCarry = aCarry + RotL64(aWandererE, 39U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 24412U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneB[((aIndex + 23641U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 23615U)) & S_BLOCK1], 22U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordD));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 25978U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneA[((aIndex + 26728U)) & S_BLOCK1], 58U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCarry, 37U)) + (RotL64(aCross, 24U) ^ RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterC = ((aWandererE + RotL64(aCross, 29U)) + 2783898056762489197U) + aNonceWordO;
            aOrbiterG = ((aWandererF + RotL64(aScatter, 35U)) + RotL64(aCarry, 5U)) + 7177192902873343053U;
            aOrbiterD = (((aWandererK + RotL64(aIngress, 60U)) + RotL64(aCarry, 51U)) + 12254703232691980774U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterB = (((aWandererG + RotL64(aPrevious, 13U)) + RotL64(aCarry, 21U)) + 15446547245691219559U) + aNonceWordG;
            aOrbiterE = (aWandererA + RotL64(aScatter, 53U)) + 888475203006174856U;
            aOrbiterI = ((aWandererI + RotL64(aIngress, 5U)) + 3649183529366307877U) + aPhaseHOrbiterAssignSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = ((aWandererD + RotL64(aCross, 47U)) + 4642631047518805167U) + aNonceWordM;
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 6108329730724782250U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterC) ^ 8334054653023816636U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterD = RotL64((aOrbiterD * 9352516059501924393U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 5891895375031474350U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 3176720746238477862U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 1869961473768307911U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 6111038696865301675U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterI) ^ 11914998302228682704U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterA = RotL64((aOrbiterA * 11738924766359642853U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 17005063057791320948U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 18333780598768130670U;
            aOrbiterG = RotL64((aOrbiterG * 5416759844884107303U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 2056115016443263153U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 10245512728872962677U;
            aOrbiterI = RotL64((aOrbiterI * 707106795383284903U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 4810366069422162351U) + aNonceWordP;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 3051442983125942469U;
            aOrbiterB = RotL64((aOrbiterB * 13558537578054436423U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 9285068547223654308U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 13067251130180968842U;
            aOrbiterE = RotL64((aOrbiterE * 7000687697769766605U), 43U);
            //
            aIngress = RotL64(aOrbiterE, 43U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterD, 51U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterG, 37U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterB, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aPrevious, 3U) + RotL64(aOrbiterI, 57U)) + aOrbiterC);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 19U) + aOrbiterD) + RotL64(aOrbiterB, 44U)) + aNonceWordE);
            aWandererI = aWandererI + (((RotL64(aCross, 35U) + RotL64(aOrbiterG, 3U)) + aOrbiterC) + RotL64(aCarry, 21U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 60U) + aOrbiterA) + RotL64(aOrbiterG, 27U));
            aWandererE = aWandererE + (((RotL64(aIngress, 27U) + aOrbiterD) + RotL64(aOrbiterI, 51U)) + RotL64(aCarry, 39U));
            aWandererA = aWandererA ^ ((((RotL64(aScatter, 13U) + aOrbiterA) + RotL64(aOrbiterI, 11U)) + aNonceWordF) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aCross, 53U) + aOrbiterE) + RotL64(aOrbiterI, 35U)) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 21U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererK, 11U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererD, 34U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererF, 39U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 31662U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneA[((aIndex + 28714U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 30872U)) & S_BLOCK1], 54U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30782U)) & S_BLOCK1], 3U) ^ RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 31308U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aPrevious, 51U) + RotL64(aCross, 38U)) + (RotL64(aCarry, 5U) ^ RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterH = ((aWandererJ + RotL64(aPrevious, 13U)) + 15188686795415908074U) + aNonceWordM;
            aOrbiterB = ((aWandererH + RotL64(aScatter, 3U)) + RotL64(aCarry, 57U)) + 17310049041983079779U;
            aOrbiterF = (((aWandererF + RotL64(aCross, 29U)) + RotL64(aCarry, 5U)) + 8246925977992441471U) + aNonceWordD;
            aOrbiterG = ((aWandererG + RotL64(aIngress, 19U)) + 8644260919918112781U) + aPhaseHOrbiterAssignSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterE = (aWandererI + RotL64(aCross, 39U)) + 13401663736874819483U;
            aOrbiterI = (aWandererD + RotL64(aIngress, 51U)) + 7940358935238314973U;
            aOrbiterD = (((aWandererA + RotL64(aPrevious, 58U)) + RotL64(aCarry, 27U)) + 13278990328548007839U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 11346868298353840706U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 2374077904806833579U;
            aOrbiterF = RotL64((aOrbiterF * 1765686942154321425U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 6978903378645019166U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 11951633297870965212U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 12778236598654492185U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 17398460995357409673U) + aNonceWordF;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 1215437945597836770U;
            aOrbiterI = RotL64((aOrbiterI * 9322970054123481621U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 1878751468043972239U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 5343002808239712390U;
            aOrbiterD = RotL64((aOrbiterD * 11878640995447558811U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 9884918450053276861U) + aNonceWordN;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 15894599082080422550U) ^ aNonceWordA;
            aOrbiterB = RotL64((aOrbiterB * 8359936745539546131U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 13917339232771145459U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 18101134009493720683U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 15835859435306756387U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 3830086372356903769U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 15894394599564584010U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 9513921913446609263U), 41U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterF, 51U);
            aIngress = aIngress + (RotL64(aOrbiterD, 37U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterH, 27U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterI, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((((RotL64(aPrevious, 29U) + RotL64(aOrbiterI, 21U)) + aOrbiterB) + aNonceWordI) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 11U) + RotL64(aOrbiterF, 41U)) + aOrbiterE) + RotL64(aCarry, 11U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 43U) + aOrbiterB) + RotL64(aOrbiterG, 5U));
            aWandererF = aWandererF + ((RotL64(aScatter, 37U) + aOrbiterF) + RotL64(aOrbiterD, 34U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 54U) + aOrbiterH) + RotL64(aOrbiterB, 27U)) + aNonceWordG);
            aWandererH = aWandererH + (((RotL64(aCross, 5U) + RotL64(aOrbiterF, 47U)) + aOrbiterI) + RotL64(aCarry, 29U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 23U) + RotL64(aOrbiterD, 11U)) + aOrbiterG) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 35U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererA, 47U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererH, 58U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererG, 43U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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

void TwistExpander_BasketBall_Arx::Twist_A(TwistWorkSpace *pWorkSpace,
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
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltD;
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
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseDWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltA;
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
            aIngress = RotL64(aKeyRowReadA[((aIndex + 2569U)) & W_KEY1], 48U) ^ RotL64(aKeyRowReadB[((aIndex + 2097U)) & W_KEY1], 11U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 2283U)) & W_KEY1], 14U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 2187U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 4U) ^ RotL64(aCross, 23U)) ^ (RotL64(aPrevious, 35U) + RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterE = ((aWandererA + RotL64(aPrevious, 58U)) + 5721224134332887360U) + aPhaseAOrbiterAssignSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterB = (aWandererK + RotL64(aScatter, 51U)) + 6892749729775049095U;
            aOrbiterF = ((aWandererD + RotL64(aCross, 3U)) + RotL64(aCarry, 11U)) + 3884839462099556836U;
            aOrbiterK = (aWandererC + RotL64(aIngress, 11U)) + 4365431706830216193U;
            aOrbiterA = (aWandererE + RotL64(aCross, 35U)) + 15501528746571578773U;
            aOrbiterC = (((aWandererI + RotL64(aPrevious, 29U)) + RotL64(aCarry, 29U)) + 4505911326320650606U) + aPhaseAOrbiterAssignSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = ((aWandererF + RotL64(aIngress, 41U)) + RotL64(aCarry, 39U)) + 1865129050927879580U;
            aOrbiterD = (aWandererB + RotL64(aScatter, 22U)) + 2011737665969640369U;
            aOrbiterG = (aWandererH + RotL64(aCross, 47U)) + 611672935827062688U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 663547038310431047U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 5468932264754299556U;
            aOrbiterF = RotL64((aOrbiterF * 11968657455484578525U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 17920294117231191705U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 486058453837528110U;
            aOrbiterC = RotL64((aOrbiterC * 8851102552244026737U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 2789178451938129313U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 420772587981211184U;
            aOrbiterD = RotL64((aOrbiterD * 17402987842294006667U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 16196774774442181825U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 16264169656793713547U;
            aOrbiterB = RotL64((aOrbiterB * 6900221986041638783U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 10207659833859860796U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 8593749091183323678U;
            aOrbiterE = RotL64((aOrbiterE * 10696776033512404927U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 7224922076047787384U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 15366267474865172373U;
            aOrbiterI = RotL64((aOrbiterI * 10134187073321814217U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 4235342515820080294U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 5239480080426950612U;
            aOrbiterK = RotL64((aOrbiterK * 12077621553561927079U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 10891752830598395582U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 7797358829694471108U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7621206775460997431U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 3755715857903753416U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 3172069024987421726U;
            aOrbiterA = RotL64((aOrbiterA * 16048490837178650865U), 35U);
            //
            aIngress = RotL64(aOrbiterF, 40U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 43U));
            aIngress = aIngress + (RotL64(aOrbiterB, 23U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterE, 57U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterD, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aIngress, 4U) + RotL64(aOrbiterB, 23U)) + aOrbiterC);
            aWandererI = aWandererI + ((RotL64(aScatter, 57U) + RotL64(aOrbiterF, 18U)) + aOrbiterC);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 23U) + aOrbiterG) + RotL64(aOrbiterB, 29U));
            aWandererH = aWandererH + (((RotL64(aCross, 11U) + RotL64(aOrbiterK, 43U)) + aOrbiterB) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 35U) + aOrbiterE) + RotL64(aOrbiterC, 5U));
            aWandererF = aWandererF + (((RotL64(aCross, 47U) + RotL64(aOrbiterE, 47U)) + aOrbiterA) + RotL64(aCarry, 23U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterB, 11U)) + aOrbiterA);
            aWandererE = aWandererE + ((((RotL64(aIngress, 19U) + RotL64(aOrbiterF, 37U)) + aOrbiterI) + RotL64(aCarry, 35U)) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 28U) + RotL64(aOrbiterE, 60U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 23U));
            aCarry = aCarry + (RotL64(aWandererH, 58U) ^ aWandererA);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 47U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 27U));
            aCarry = aCarry + RotL64(aWandererE, 35U);
            aCarry = aCarry + RotL64(aIngress, 4U);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 4145U)) & S_BLOCK1], 21U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 4913U)) & W_KEY1], 56U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 5207U)) & W_KEY1], 27U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 3484U)) & S_BLOCK1], 14U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 18U) + RotL64(aCarry, 57U)) + (RotL64(aCross, 5U) ^ RotL64(aIngress, 43U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterK = (aWandererB + RotL64(aIngress, 19U)) + 11700815697312060726U;
            aOrbiterG = ((aWandererE + RotL64(aPrevious, 35U)) + RotL64(aCarry, 21U)) + 11808423452327465441U;
            aOrbiterA = (aWandererF + RotL64(aScatter, 60U)) + 8670503858631730886U;
            aOrbiterD = ((aWandererK + RotL64(aCross, 3U)) + RotL64(aCarry, 43U)) + 2400061067991988544U;
            aOrbiterE = (aWandererH + RotL64(aScatter, 29U)) + 16163118178366229686U;
            aOrbiterJ = (((aWandererJ + RotL64(aIngress, 23U)) + RotL64(aCarry, 57U)) + 3280178595904941068U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterH = (aWandererD + RotL64(aCross, 44U)) + 3298683600817047727U;
            aOrbiterF = (aWandererA + RotL64(aPrevious, 53U)) + 16321624053445183574U;
            aOrbiterB = ((aWandererG + RotL64(aScatter, 39U)) + 6730229877611375225U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 10162830636713641322U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 15646771327759599256U;
            aOrbiterA = RotL64((aOrbiterA * 15333053762177144775U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 14841751262270544102U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 9545541117228834895U;
            aOrbiterJ = RotL64((aOrbiterJ * 11529769874752969377U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 14676615635857599982U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 1231768638470558855U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2716808508509014677U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 1945905595345404833U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 1406171421638586846U;
            aOrbiterD = RotL64((aOrbiterD * 4577864352425476233U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 1970292335806697198U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 12309719390375013297U;
            aOrbiterE = RotL64((aOrbiterE * 16540660957923687327U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 5352135521358954576U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 15465675376193501658U;
            aOrbiterF = RotL64((aOrbiterF * 16385761112921041387U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 2842123638916600369U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 3544764287036748668U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 3360772950777850115U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 6038297172906492282U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 10249342332287140970U;
            aOrbiterB = RotL64((aOrbiterB * 16701083081566042277U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 1662076777040529446U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 1949705569959740274U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 11340691546658994529U), 35U);
            //
            aIngress = RotL64(aOrbiterD, 29U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterF, 47U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterG, 35U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterJ, 38U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterK, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aScatter, 46U) + RotL64(aOrbiterK, 11U)) + aOrbiterE) + RotL64(aCarry, 41U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterH, 28U)) + aOrbiterA);
            aWandererG = aWandererG + (((RotL64(aIngress, 29U) + aOrbiterB) + RotL64(aOrbiterA, 47U)) + aPhaseAWandererUpdateSaltC[((aIndex + 25U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterK, 21U)) + aOrbiterF);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 41U) + RotL64(aOrbiterA, 37U)) + aOrbiterD);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterF, 57U)) + aOrbiterA);
            aWandererK = aWandererK + ((RotL64(aPrevious, 18U) + aOrbiterB) + RotL64(aOrbiterJ, 6U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 51U) + aOrbiterG) + RotL64(aOrbiterB, 41U)) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aIngress, 3U) + RotL64(aOrbiterA, 51U)) + aOrbiterJ) + RotL64(aCarry, 57U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 29U));
            aCarry = aCarry + (RotL64(aWandererE, 37U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererG, 23U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererK, 26U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = RotL64(aWorkLaneB[((aIndex + 7890U)) & S_BLOCK1], 6U) ^ RotL64(aKeyRowReadB[((aIndex + 7493U)) & W_KEY1], 47U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 6549U)) & W_KEY1], 57U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 7068U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 7798U)) & S_BLOCK1], 12U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 52U) + RotL64(aPrevious, 35U)) + (RotL64(aCross, 19U) ^ RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterK = ((aWandererC + RotL64(aPrevious, 12U)) + RotL64(aCarry, 23U)) + 13350544654542863236U;
            aOrbiterD = (((aWandererK + RotL64(aCross, 5U)) + RotL64(aCarry, 35U)) + 12364346790125404372U) + aPhaseAOrbiterAssignSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterE = (aWandererE + RotL64(aIngress, 27U)) + 9738750172849512764U;
            aOrbiterG = ((aWandererF + RotL64(aScatter, 57U)) + 3781373837635491421U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = (aWandererI + RotL64(aCross, 39U)) + 16635020317512702337U;
            aOrbiterB = (aWandererG + RotL64(aPrevious, 47U)) + 5383653921676231276U;
            aOrbiterC = ((aWandererJ + RotL64(aScatter, 19U)) + RotL64(aCarry, 51U)) + 10181959815492056493U;
            aOrbiterF = (aWandererD + RotL64(aIngress, 23U)) + 10005510924273927017U;
            aOrbiterJ = (aWandererB + RotL64(aCross, 52U)) + 9524687662265740565U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 4259138552009771014U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 8973051213213726023U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 12625091476068190979U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 17602611840127337490U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 8218984546932905269U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 17504305273683304231U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 18102186122213487888U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 2629927500298092976U;
            aOrbiterC = RotL64((aOrbiterC * 6983280164448292723U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 2491581597835795234U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 9506602492971620955U;
            aOrbiterK = RotL64((aOrbiterK * 9559829640915637163U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 13422942713680612924U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 15037354693234876601U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12692376075738621447U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 12896066842192894694U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 2202952306291905855U;
            aOrbiterG = RotL64((aOrbiterG * 6779368532763429997U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 12160313482450599313U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 10812986281270407756U;
            aOrbiterJ = RotL64((aOrbiterJ * 7786608700746771809U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 12474638293190144525U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 5882870951276225224U;
            aOrbiterB = RotL64((aOrbiterB * 15532427302173572457U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 3782896138051179209U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 10965680631059882311U;
            aOrbiterF = RotL64((aOrbiterF * 14060923998307082385U), 51U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterK, 57U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 39U));
            aIngress = aIngress + (RotL64(aOrbiterC, 23U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 14U));
            aIngress = aIngress + RotL64(aOrbiterB, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aScatter, 11U) + RotL64(aOrbiterB, 54U)) + aOrbiterF);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 18U) + RotL64(aOrbiterE, 3U)) + aOrbiterF);
            aWandererC = aWandererC + (((RotL64(aCross, 29U) + RotL64(aOrbiterD, 29U)) + aOrbiterB) + aPhaseAWandererUpdateSaltB[((aIndex + 29U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 39U) + aOrbiterD) + RotL64(aOrbiterC, 37U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 43U) + aOrbiterG) + RotL64(aOrbiterD, 47U)) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterC, 43U)) + aOrbiterK);
            aWandererE = aWandererE + (((RotL64(aScatter, 52U) + aOrbiterJ) + RotL64(aOrbiterF, 21U)) + RotL64(aCarry, 23U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 57U) + aOrbiterE) + RotL64(aOrbiterI, 13U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterI, 60U)) + aOrbiterB) + RotL64(aCarry, 37U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 53U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 3U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 21U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 60U));
            aCarry = aCarry + RotL64(aWandererK, 43U);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 9999U)) & S_BLOCK1], 47U) ^ RotL64(aKeyRowReadB[((aIndex + 9787U)) & W_KEY1], 4U));
            aIngress ^= (RotL64(mSource[((aIndex + 9041U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneA[((aIndex + 8215U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 9811U)) & W_KEY1], 30U) ^ RotL64(aWorkLaneB[((aIndex + 9609U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 58U) + RotL64(aPrevious, 23U)) ^ (RotL64(aCross, 11U) ^ RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterI = (aWandererA + RotL64(aPrevious, 29U)) + 9220392006207660113U;
            aOrbiterD = ((aWandererF + RotL64(aScatter, 47U)) + RotL64(aCarry, 5U)) + 11305018553489132882U;
            aOrbiterJ = (aWandererD + RotL64(aCross, 43U)) + 5860373868073513684U;
            aOrbiterK = (aWandererC + RotL64(aIngress, 52U)) + 12319586170883987589U;
            aOrbiterB = ((aWandererG + RotL64(aPrevious, 11U)) + RotL64(aCarry, 39U)) + 14072333614354649021U;
            aOrbiterE = ((aWandererE + RotL64(aIngress, 23U)) + 9332158529453194608U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = ((aWandererK + RotL64(aCross, 35U)) + RotL64(aCarry, 29U)) + 3860569321145958686U;
            aOrbiterF = ((aWandererJ + RotL64(aScatter, 19U)) + 8119005668901240093U) + aPhaseBOrbiterAssignSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterA = (aWandererI + RotL64(aPrevious, 58U)) + 13918259792880333239U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 6938856216758228704U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 3960905839118710604U;
            aOrbiterJ = RotL64((aOrbiterJ * 16203746868670689793U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 6043879193734253929U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 15691425268831319195U;
            aOrbiterE = RotL64((aOrbiterE * 7189195135654636271U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 14912209933584715274U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 16180183395910618923U;
            aOrbiterD = RotL64((aOrbiterD * 3942858974766467849U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 4966642362507707776U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 6962226782462822861U;
            aOrbiterB = RotL64((aOrbiterB * 3647802407741095419U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 12409120845092026295U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 2302946450253872465U;
            aOrbiterI = RotL64((aOrbiterI * 7099576330777297911U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 16118304388937163838U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 15968419034359049422U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11736207775827080165U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 17098982091525008231U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 10298979200690822062U;
            aOrbiterK = RotL64((aOrbiterK * 12620028874653521945U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 552826643694256437U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 11786560990790695378U;
            aOrbiterG = RotL64((aOrbiterG * 11190309640069208311U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 13730399230389329793U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 17614226859252305432U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2640019643570222977U), 47U);
            //
            aIngress = RotL64(aOrbiterK, 51U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterJ, 6U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterB, 19U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 27U));
            aIngress = aIngress + RotL64(aOrbiterA, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aPrevious, 27U) + RotL64(aOrbiterJ, 57U)) + aOrbiterB) + RotL64(aCarry, 11U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 58U) + aOrbiterK) + RotL64(aOrbiterA, 28U));
            aWandererI = aWandererI + (((RotL64(aCross, 5U) + RotL64(aOrbiterG, 19U)) + aOrbiterB) + RotL64(aCarry, 3U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 47U) + aOrbiterF) + RotL64(aOrbiterG, 3U));
            aWandererD = aWandererD + ((RotL64(aIngress, 23U) + RotL64(aOrbiterA, 51U)) + aOrbiterI);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 42U) + RotL64(aOrbiterF, 44U)) + aOrbiterI);
            aWandererJ = aWandererJ + (((RotL64(aCross, 35U) + RotL64(aOrbiterA, 11U)) + aOrbiterB) + aPhaseBWandererUpdateSaltA[((aIndex + 18U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 13U) + aOrbiterE) + RotL64(aOrbiterD, 37U));
            aWandererC = aWandererC + (((RotL64(aIngress, 19U) + RotL64(aOrbiterE, 23U)) + aOrbiterG) + aPhaseBWandererUpdateSaltD[((aIndex + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 35U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererE, 11U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererD, 39U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererJ, 54U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererI, 47U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 13642U)) & S_BLOCK1], 5U) ^ RotL64(aKeyRowReadA[((aIndex + 11632U)) & W_KEY1], 13U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 11005U)) & W_KEY1], 51U) ^ RotL64(mSource[((aIndex + 12951U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aWorkLaneB[((aIndex + 13170U)) & S_BLOCK1], 22U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 12729U)) & S_BLOCK1], 29U) ^ RotL64(aInvestLaneA[((aIndex + 11179U)) & S_BLOCK1], 20U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 11U) ^ RotL64(aCarry, 57U)) + (RotL64(aCross, 26U) + RotL64(aPrevious, 43U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterJ = ((aWandererI + RotL64(aCross, 10U)) + 6973892330986118220U) + aPhaseBOrbiterAssignSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterK = ((aWandererA + RotL64(aPrevious, 23U)) + RotL64(aCarry, 29U)) + 9886813896272094864U;
            aOrbiterF = (aWandererF + RotL64(aScatter, 43U)) + 10996306582517553173U;
            aOrbiterE = ((aWandererC + RotL64(aIngress, 39U)) + RotL64(aCarry, 57U)) + 8490648283899856223U;
            aOrbiterA = (aWandererD + RotL64(aCross, 51U)) + 105141713530704655U;
            aOrbiterD = (aWandererE + RotL64(aIngress, 47U)) + 3114337422810562588U;
            aOrbiterC = ((aWandererB + RotL64(aScatter, 29U)) + RotL64(aCarry, 43U)) + 980857684690886131U;
            aOrbiterG = (aWandererK + RotL64(aPrevious, 34U)) + 6562042345807072665U;
            aOrbiterH = ((aWandererH + RotL64(aIngress, 57U)) + 15665371138706353619U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 18113013571374375028U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 17405346422601997299U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11162604605443005253U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 5130876096426182506U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 1813821672299154629U;
            aOrbiterA = RotL64((aOrbiterA * 15478100342425611875U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 15793814882743306728U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 13925299440495476399U;
            aOrbiterJ = RotL64((aOrbiterJ * 12049601510660117401U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 9924458846049579438U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 7810034662781768090U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 10310594595026622513U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 12812586478656872854U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 5709576448057435237U;
            aOrbiterC = RotL64((aOrbiterC * 9101555233909853025U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 7839807649914541516U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 4717944526755429647U;
            aOrbiterE = RotL64((aOrbiterE * 8515229146471335721U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 3933911971504256022U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 4814079680865379831U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 15100740696230557391U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 18352577312212175569U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 9670612998448920742U;
            aOrbiterD = RotL64((aOrbiterD * 5743579439303300553U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 72737302703035726U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 10032869372369626210U;
            aOrbiterG = RotL64((aOrbiterG * 7449905669249993731U), 51U);
            //
            aIngress = RotL64(aOrbiterJ, 47U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterK, 26U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterH, 21U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterG, 13U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterC, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aCross, 34U) + RotL64(aOrbiterJ, 10U)) + aOrbiterA) + aPhaseBWandererUpdateSaltA[((aIndex + 19U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aIngress, 47U) + aOrbiterF) + RotL64(aOrbiterJ, 47U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 29U) + aOrbiterJ) + RotL64(aOrbiterK, 37U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterD, 19U)) + aOrbiterA) + RotL64(aCarry, 51U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 11U) + aOrbiterF) + RotL64(aOrbiterC, 27U));
            aWandererK = aWandererK + (((RotL64(aCross, 57U) + aOrbiterD) + RotL64(aOrbiterG, 57U)) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 24U) + RotL64(aOrbiterH, 53U)) + aOrbiterG);
            aWandererA = aWandererA + (((RotL64(aIngress, 43U) + RotL64(aOrbiterE, 41U)) + aOrbiterF) + RotL64(aCarry, 19U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterD, 14U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 3U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 47U));
            aCarry = aCarry + (RotL64(aWandererF, 18U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererI, 35U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererA, 57U);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 14449U)) & S_BLOCK1], 29U) ^ RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 14433U)) & S_BLOCK1], 48U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 15325U)) & W_KEY1], 35U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 14599U)) & W_KEY1], 43U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 15055U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 14617U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 15325U)) & S_BLOCK1], 52U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 48U) + RotL64(aCarry, 5U)) + (RotL64(aIngress, 35U) ^ RotL64(aCross, 21U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterG = (aWandererA + RotL64(aScatter, 13U)) + 15652862298542575895U;
            aOrbiterD = (aWandererH + RotL64(aIngress, 5U)) + 16925323928418184554U;
            aOrbiterK = ((aWandererJ + RotL64(aPrevious, 53U)) + RotL64(aCarry, 11U)) + 4413861484961668394U;
            aOrbiterJ = (aWandererG + RotL64(aCross, 57U)) + 2215946422098155969U;
            aOrbiterE = ((aWandererK + RotL64(aIngress, 34U)) + 14975185533513111110U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = ((aWandererB + RotL64(aScatter, 27U)) + RotL64(aCarry, 21U)) + 9711613814905834552U;
            aOrbiterC = (aWandererD + RotL64(aCross, 43U)) + 13154957291850149471U;
            aOrbiterB = ((aWandererE + RotL64(aPrevious, 19U)) + 5058313016418534840U) + aPhaseBOrbiterAssignSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterA = ((aWandererC + RotL64(aIngress, 48U)) + RotL64(aCarry, 43U)) + 15011423472941211620U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 2030053257469580168U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 150530795186791193U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 11106050063717096073U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 10878237472104183427U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 11724672539469573109U;
            aOrbiterE = RotL64((aOrbiterE * 16158741837357985395U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 9589700906445846956U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 1367381624958248949U;
            aOrbiterG = RotL64((aOrbiterG * 8459515089081211977U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 12003215666757518106U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 11232479330848006729U;
            aOrbiterB = RotL64((aOrbiterB * 10993290955464593033U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 13013910456628561621U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 6092509838924105265U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 805601154718006061U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 11999225836250312801U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 14421271973875748413U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 9529010940887430157U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 15536288285741825272U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 2071793889925436679U;
            aOrbiterC = RotL64((aOrbiterC * 1526376970151714589U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 5622386476463436967U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 16147972771639168516U;
            aOrbiterA = RotL64((aOrbiterA * 11826916832825159095U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 4519892856053952290U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 12059500374938843538U;
            aOrbiterJ = RotL64((aOrbiterJ * 14987533625537956299U), 5U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterA, 34U);
            aIngress = aIngress + (RotL64(aOrbiterE, 29U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterK, 43U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterC, 21U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterI, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aIngress, 58U) + aOrbiterG) + RotL64(aOrbiterC, 34U));
            aWandererC = aWandererC + ((RotL64(aCross, 19U) + aOrbiterG) + RotL64(aOrbiterD, 21U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 39U) + aOrbiterD) + RotL64(aOrbiterB, 29U));
            aWandererD = aWandererD + (((RotL64(aScatter, 47U) + aOrbiterI) + RotL64(aOrbiterB, 47U)) + RotL64(aCarry, 29U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 13U) + aOrbiterK) + RotL64(aOrbiterG, 51U)) + aPhaseBWandererUpdateSaltD[((aIndex + 21U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aIngress, 6U) + aOrbiterA) + RotL64(aOrbiterJ, 43U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterK, 39U)) + aOrbiterE);
            aWandererH = aWandererH + ((((RotL64(aCross, 53U) + aOrbiterA) + RotL64(aOrbiterE, 60U)) + RotL64(aCarry, 13U)) + aPhaseBWandererUpdateSaltE[((aIndex + 12U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 29U) + aOrbiterB) + RotL64(aOrbiterA, 5U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 20U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 29U));
            aCarry = aCarry + (RotL64(aWandererD, 11U) ^ aWandererB);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 57U));
            aCarry = aCarry + RotL64(aWandererH, 5U);
            aCarry = aCarry + RotL64(aIngress, 14U);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 17812U)) & S_BLOCK1], 44U) ^ RotL64(aKeyRowReadA[((aIndex + 16978U)) & W_KEY1], 3U));
            aIngress ^= (RotL64(mSource[((aIndex + 17631U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18085U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 17176U)) & W_KEY1], 3U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 17923U)) & S_BLOCK1], 58U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 18711U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 53U) + RotL64(aPrevious, 23U)) + (RotL64(aCross, 40U) ^ RotL64(aIngress, 11U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterE = ((aWandererD + RotL64(aIngress, 29U)) + 12222235191147985484U) + aPhaseCOrbiterAssignSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = (aWandererA + RotL64(aScatter, 12U)) + 16367317014523328414U;
            aOrbiterK = (aWandererI + RotL64(aPrevious, 35U)) + 3511378091284703789U;
            aOrbiterA = ((aWandererH + RotL64(aCross, 47U)) + RotL64(aCarry, 21U)) + 15247492830966725949U;
            aOrbiterB = ((aWandererJ + RotL64(aIngress, 53U)) + 7745995913390407897U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterF = ((aWandererF + RotL64(aScatter, 3U)) + RotL64(aCarry, 37U)) + 6463593307540108810U;
            aOrbiterI = (aWandererC + RotL64(aPrevious, 19U)) + 1101669311005268630U;
            aOrbiterH = (aWandererG + RotL64(aCross, 40U)) + 12988052764067518580U;
            aOrbiterJ = ((aWandererE + RotL64(aIngress, 23U)) + RotL64(aCarry, 53U)) + 17717179747434679772U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 11662190906682400416U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 6563014073547628748U;
            aOrbiterK = RotL64((aOrbiterK * 16967910471722117761U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 13099094932059419219U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 16342730862261868847U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10988124108686164829U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 16855346813127524624U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 6570063128502306944U;
            aOrbiterE = RotL64((aOrbiterE * 4571570049463124831U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 11328352033809240501U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 11640986648833160901U;
            aOrbiterH = RotL64((aOrbiterH * 2895830492089678919U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 2675226158571501666U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 17700531248266458165U;
            aOrbiterF = RotL64((aOrbiterF * 2231403813970188657U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 7729597396731910874U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 15172374484412053756U) ^ aPhaseCOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 149009041406406517U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 9178769489257842683U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 9020154972097834926U;
            aOrbiterA = RotL64((aOrbiterA * 8910504667566521429U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 1317403761217790562U) + aPhaseCOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 17151528554929201571U;
            aOrbiterJ = RotL64((aOrbiterJ * 3735945655450625203U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 11621882033959669977U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 10289504450815075623U) ^ aPhaseCOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 13365982786836243195U), 39U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterK, 37U);
            aIngress = aIngress + (RotL64(aOrbiterC, 51U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterB, 23U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 44U));
            aIngress = aIngress + RotL64(aOrbiterA, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aIngress, 58U) + RotL64(aOrbiterH, 41U)) + aOrbiterF);
            aWandererA = aWandererA + (((RotL64(aCross, 43U) + aOrbiterK) + RotL64(aOrbiterF, 27U)) + RotL64(aCarry, 53U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterF, 37U)) + aOrbiterE);
            aWandererI = aWandererI + ((RotL64(aPrevious, 47U) + aOrbiterB) + RotL64(aOrbiterH, 10U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterH, 19U)) + aOrbiterI);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 13U) + aOrbiterA) + RotL64(aOrbiterH, 5U)) + RotL64(aCarry, 27U)) + aPhaseCWandererUpdateSaltA[((aIndex + 6U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 34U) + aOrbiterF) + RotL64(aOrbiterC, 53U));
            aWandererD = aWandererD + (((RotL64(aCross, 39U) + aOrbiterJ) + RotL64(aOrbiterI, 23U)) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 51U) + aOrbiterE) + RotL64(aOrbiterB, 48U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 13U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererH, 19U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererJ, 37U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererD, 51U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererC, 10U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 21528U)) & S_BLOCK1], 28U) ^ RotL64(mSource[((aIndex + 21511U)) & S_BLOCK1], 13U));
            aIngress ^= (RotL64(aFireLaneA[((aIndex + 21367U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 20474U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 19359U)) & W_KEY1], 29U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 21766U)) & W_KEY1], 41U));
            aCross ^= (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 21337U)) & S_BLOCK1], 54U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 20427U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 56U) ^ RotL64(aCross, 27U)) + (RotL64(aCarry, 41U) ^ RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterF = (aWandererG + RotL64(aCross, 60U)) + 14499676118633326000U;
            aOrbiterK = (aWandererK + RotL64(aPrevious, 39U)) + 17191273593018552288U;
            aOrbiterC = (aWandererC + RotL64(aIngress, 23U)) + 4085176294948097737U;
            aOrbiterJ = (aWandererF + RotL64(aScatter, 53U)) + 11112671474158908186U;
            aOrbiterD = ((aWandererE + RotL64(aCross, 18U)) + 8745787969012266485U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = (aWandererB + RotL64(aPrevious, 11U)) + 18074049663777707948U;
            aOrbiterE = ((aWandererH + RotL64(aScatter, 43U)) + RotL64(aCarry, 3U)) + 2543758649719164688U;
            aOrbiterH = (((aWandererJ + RotL64(aIngress, 3U)) + RotL64(aCarry, 51U)) + 4659584749412700523U) + aPhaseCOrbiterAssignSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = ((aWandererD + RotL64(aCross, 27U)) + RotL64(aCarry, 43U)) + 974639159259871273U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 9211220687971081987U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 8567024626862182714U) ^ aPhaseCOrbiterUpdateSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7755874089832496393U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 5803002132294840900U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 11968489432878148467U;
            aOrbiterD = RotL64((aOrbiterD * 4501441062617123165U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 9470807228394903442U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 1692347973120388469U;
            aOrbiterE = RotL64((aOrbiterE * 17433393164156231575U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 16510815732690193145U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 755159406833096510U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 14091736464659561165U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 1518824876475937620U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 701225390867330446U;
            aOrbiterF = RotL64((aOrbiterF * 12264618860580199927U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 8425976693733003889U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 7182176375442410367U;
            aOrbiterG = RotL64((aOrbiterG * 8860605703761731859U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 4546566785167467924U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 2593340999038753749U;
            aOrbiterJ = RotL64((aOrbiterJ * 10152461487764567563U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 9756331608356622299U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 5511625814747641978U;
            aOrbiterI = RotL64((aOrbiterI * 4806076157539829529U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 8694400787420160733U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 12648969491371382682U;
            aOrbiterK = RotL64((aOrbiterK * 5346585704222643759U), 43U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterG, 56U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 3U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 13U));
            aIngress = aIngress + (RotL64(aOrbiterI, 53U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterK, 24U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aIngress, 53U) + aOrbiterF) + RotL64(aOrbiterH, 53U)) + RotL64(aCarry, 41U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 60U) + aOrbiterJ) + RotL64(aOrbiterE, 41U));
            aWandererD = aWandererD + ((RotL64(aCross, 29U) + RotL64(aOrbiterI, 47U)) + aOrbiterC);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 39U) + aOrbiterH) + RotL64(aOrbiterJ, 10U));
            aWandererG = aWandererG + (((RotL64(aCross, 11U) + RotL64(aOrbiterF, 35U)) + aOrbiterE) + RotL64(aCarry, 51U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 3U) + aOrbiterG) + RotL64(aOrbiterE, 21U)) + aPhaseCWandererUpdateSaltA[((aIndex + 5U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aScatter, 44U) + RotL64(aOrbiterC, 57U)) + aOrbiterD);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 23U) + aOrbiterF) + RotL64(aOrbiterK, 6U)) + aPhaseCWandererUpdateSaltF[((aIndex + 27U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aIngress, 35U) + aOrbiterC) + RotL64(aOrbiterE, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 19U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererK, 26U) ^ aWandererB);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 47U));
            aCarry = aCarry + (RotL64(aWandererJ, 5U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererH, 23U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 24036U)) & S_BLOCK1], 19U) ^ RotL64(aKeyRowReadA[((aIndex + 21991U)) & W_KEY1], 58U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 23094U)) & W_KEY1], 27U) ^ RotL64(aFireLaneC[((aIndex + 21850U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 23431U)) & S_BLOCK1], 27U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 24536U)) & S_BLOCK1], 13U));
            aCross ^= (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 23770U)) & S_BLOCK1], 50U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 24050U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 24U) + RotL64(aCross, 5U)) ^ (RotL64(aCarry, 39U) + RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterE = (aWandererK + RotL64(aIngress, 12U)) + 8367680518550579791U;
            aOrbiterF = (aWandererF + RotL64(aCross, 29U)) + 11491674725611181241U;
            aOrbiterH = ((aWandererI + RotL64(aScatter, 21U)) + RotL64(aCarry, 39U)) + 16673861720782164214U;
            aOrbiterC = ((aWandererG + RotL64(aPrevious, 51U)) + RotL64(aCarry, 19U)) + 9786610124108350855U;
            aOrbiterI = (aWandererE + RotL64(aScatter, 60U)) + 5745080601557577637U;
            aOrbiterG = (((aWandererC + RotL64(aCross, 43U)) + RotL64(aCarry, 51U)) + 1959402215131684684U) + aPhaseCOrbiterAssignSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterB = (aWandererH + RotL64(aPrevious, 39U)) + 6121650036079196522U;
            aOrbiterK = ((aWandererA + RotL64(aIngress, 5U)) + 12016309761037342392U) + aPhaseCOrbiterAssignSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = (aWandererB + RotL64(aScatter, 47U)) + 5986936646177049603U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 1000367700904043468U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 17425288243569101032U;
            aOrbiterH = RotL64((aOrbiterH * 2174614006719048535U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 4856917474950325209U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 16312111093223166419U;
            aOrbiterF = RotL64((aOrbiterF * 11046477664487805241U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 456110002032422270U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 11393724374787795662U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 1176984359123668389U), 5U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 8378176867715697176U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 8086186452345234815U;
            aOrbiterC = RotL64((aOrbiterC * 8450438271765985235U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 8470349167474173245U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 2528229938740192694U;
            aOrbiterK = RotL64((aOrbiterK * 8717790851266520943U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 13247168811545753141U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 8745293957516815264U;
            aOrbiterG = RotL64((aOrbiterG * 14270617180621072619U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 6165915500564961987U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 12015407798844173213U;
            aOrbiterD = RotL64((aOrbiterD * 3913451986559154153U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 545006684939922156U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 16366753936267185001U;
            aOrbiterB = RotL64((aOrbiterB * 6495185976430013201U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 3097605623436091728U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 15950167830259022926U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 4415538963984293323U), 57U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterF, 54U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 3U));
            aIngress = aIngress + (RotL64(aOrbiterD, 35U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 19U));
            aIngress = aIngress + RotL64(aOrbiterK, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aPrevious, 52U) + RotL64(aOrbiterG, 42U)) + aOrbiterF);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterC, 3U)) + aOrbiterK);
            aWandererF = aWandererF + ((RotL64(aCross, 37U) + aOrbiterH) + RotL64(aOrbiterE, 53U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterD, 47U)) + aOrbiterB);
            aWandererG = aWandererG + (((RotL64(aIngress, 47U) + aOrbiterE) + RotL64(aOrbiterK, 23U)) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 5U) + aOrbiterD) + RotL64(aOrbiterI, 35U));
            aWandererB = aWandererB + ((((RotL64(aScatter, 19U) + aOrbiterC) + RotL64(aOrbiterB, 27U)) + RotL64(aCarry, 35U)) + aPhaseCWandererUpdateSaltA[((aIndex + 12U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 29U) + aOrbiterC) + RotL64(aOrbiterF, 13U));
            aWandererC = aWandererC + (((RotL64(aCross, 60U) + RotL64(aOrbiterC, 58U)) + aOrbiterH) + RotL64(aCarry, 13U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 48U) ^ aWandererC);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 35U));
            aCarry = aCarry + (RotL64(aWandererB, 29U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererA, 53U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererG, 3U);
            aCarry = aCarry + RotL64(aIngress, 6U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 26525U)) & S_BLOCK1], 51U) ^ RotL64(aKeyRowReadA[((aIndex + 24658U)) & W_KEY1], 6U));
            aIngress ^= (RotL64(aFireLaneD[((aIndex + 25074U)) & S_BLOCK1], 35U) ^ RotL64(aFireLaneB[((aIndex + 26438U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 24744U)) & W_KEY1], 4U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 26030U)) & S_BLOCK1], 13U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 26566U)) & S_BLOCK1], 37U) ^ RotL64(aInvestLaneB[((aIndex + 26251U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 37U) ^ RotL64(aCross, 5U)) + (RotL64(aCarry, 19U) ^ RotL64(aIngress, 50U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterC = (aWandererG + RotL64(aIngress, 51U)) + 6467297102954816305U;
            aOrbiterA = (aWandererI + RotL64(aCross, 47U)) + 7921154109831114952U;
            aOrbiterD = ((aWandererJ + RotL64(aScatter, 18U)) + 5701131763215638919U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterH = ((aWandererK + RotL64(aPrevious, 43U)) + RotL64(aCarry, 3U)) + 10022999076719002684U;
            aOrbiterE = ((aWandererC + RotL64(aIngress, 5U)) + RotL64(aCarry, 13U)) + 4367135243038982316U;
            aOrbiterK = (aWandererA + RotL64(aPrevious, 23U)) + 14445846824810383592U;
            aOrbiterJ = ((aWandererH + RotL64(aCross, 38U)) + RotL64(aCarry, 57U)) + 7683697954545773253U;
            aOrbiterI = (aWandererB + RotL64(aScatter, 11U)) + 17517006750428030899U;
            aOrbiterB = ((aWandererE + RotL64(aIngress, 57U)) + 2052484792684025476U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 6279463052085808926U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 679280153651813684U;
            aOrbiterD = RotL64((aOrbiterD * 3047031560593583881U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 2939516520188460569U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 1960616434964712325U;
            aOrbiterE = RotL64((aOrbiterE * 15145998415466343039U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 12273819390719947361U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 5685033154709449397U;
            aOrbiterI = RotL64((aOrbiterI * 9845666295874714959U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 9314494172199500653U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 15757631834636427621U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 15483543888965744529U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 10878078046389399574U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 3583495913766365232U;
            aOrbiterK = RotL64((aOrbiterK * 2913540984990155225U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 7385544065754622301U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 16839599460207922881U;
            aOrbiterA = RotL64((aOrbiterA * 240651605910592561U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 13038163804940349251U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 2587538594933924000U;
            aOrbiterB = RotL64((aOrbiterB * 3091149760401278671U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 13109518583364738004U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 2447689055742474261U;
            aOrbiterJ = RotL64((aOrbiterJ * 12100180201235703193U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 5752044906692668618U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 6637725371036522120U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 6021986525167161115U), 13U);
            //
            aIngress = RotL64(aOrbiterE, 57U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 19U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 4U));
            aIngress = aIngress + (RotL64(aOrbiterK, 39U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterD, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aIngress, 12U) + RotL64(aOrbiterB, 35U)) + aOrbiterD) + RotL64(aCarry, 37U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 47U) + aOrbiterA) + RotL64(aOrbiterI, 27U));
            aWandererH = aWandererH + ((RotL64(aCross, 27U) + RotL64(aOrbiterA, 57U)) + aOrbiterE);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterI, 14U)) + aOrbiterH);
            aWandererB = aWandererB + ((RotL64(aScatter, 39U) + aOrbiterD) + RotL64(aOrbiterK, 19U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 3U) + aOrbiterH) + RotL64(aOrbiterE, 5U));
            aWandererG = aWandererG + ((((RotL64(aPrevious, 35U) + RotL64(aOrbiterB, 53U)) + aOrbiterC) + RotL64(aCarry, 47U)) + aPhaseDWandererUpdateSaltD[((aIndex + 7U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterE, 39U)) + aOrbiterJ) + aPhaseDWandererUpdateSaltE[((aIndex + 11U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aCross, 22U) + RotL64(aOrbiterK, 46U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 38U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 27U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 51U));
            aCarry = aCarry + (RotL64(aWandererC, 23U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererB, 43U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 29568U)) & S_BLOCK1], 39U) ^ RotL64(aFireLaneD[((aIndex + 29944U)) & S_BLOCK1], 4U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 27427U)) & W_KEY1], 29U) ^ RotL64(aFireLaneC[((aIndex + 29357U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 27490U)) & W_KEY1], 53U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 29942U)) & S_BLOCK1], 19U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27475U)) & S_BLOCK1], 27U) ^ RotL64(aFireLaneB[((aIndex + 29230U)) & S_BLOCK1], 38U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 39U) ^ RotL64(aCarry, 5U)) + (RotL64(aPrevious, 52U) ^ RotL64(aCross, 21U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterH = (aWandererC + RotL64(aScatter, 51U)) + 7948891781097675369U;
            aOrbiterG = (aWandererI + RotL64(aCross, 35U)) + 13928362874228230226U;
            aOrbiterE = ((aWandererG + RotL64(aIngress, 4U)) + RotL64(aCarry, 23U)) + 10776180542602258926U;
            aOrbiterJ = ((aWandererB + RotL64(aPrevious, 23U)) + 5735115172149470447U) + aPhaseDOrbiterAssignSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterC = ((aWandererD + RotL64(aCross, 29U)) + RotL64(aCarry, 47U)) + 5353591822981766987U;
            aOrbiterK = (aWandererJ + RotL64(aIngress, 57U)) + 562301708107268570U;
            aOrbiterA = ((aWandererF + RotL64(aPrevious, 43U)) + 10467810247578364868U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = (aWandererE + RotL64(aScatter, 11U)) + 14541630141152308564U;
            aOrbiterD = ((aWandererH + RotL64(aPrevious, 18U)) + RotL64(aCarry, 3U)) + 2350076897065139429U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 17519109078651162228U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 6061035173339902910U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 10021905773432907835U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 15654836633731000065U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 13723521735153718904U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 14459516479283070563U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 2849680038315532197U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 17336102435576647923U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 10984689101753586739U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 7671010488872356142U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 11485114338165600777U;
            aOrbiterI = RotL64((aOrbiterI * 4162584865462407791U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 8759060657343458985U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 11009137869375286581U;
            aOrbiterC = RotL64((aOrbiterC * 8741417343929809115U), 53U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 15792999392743144135U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 6180808423175992479U;
            aOrbiterD = RotL64((aOrbiterD * 13681230339693676907U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 361487389591183005U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 15292753806514404853U;
            aOrbiterG = RotL64((aOrbiterG * 17478232597253311153U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 14929153438443362045U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 7904556383593914086U;
            aOrbiterA = RotL64((aOrbiterA * 2484130486635511403U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 3793180909904286848U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 10391957637467171320U;
            aOrbiterJ = RotL64((aOrbiterJ * 505484041943467117U), 3U);
            //
            aIngress = RotL64(aOrbiterH, 42U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterC, 51U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterG, 57U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterD, 27U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterJ, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aCross, 48U) + RotL64(aOrbiterK, 18U)) + aOrbiterG);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 13U) + aOrbiterC) + RotL64(aOrbiterE, 35U)) + RotL64(aCarry, 47U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 37U) + RotL64(aOrbiterD, 39U)) + aOrbiterG) + aPhaseDWandererUpdateSaltC[((aIndex + 13U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aPrevious, 27U) + RotL64(aOrbiterK, 13U)) + aOrbiterJ) + RotL64(aCarry, 35U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterJ, 30U)) + aOrbiterA);
            aWandererF = aWandererF + ((RotL64(aPrevious, 18U) + RotL64(aOrbiterH, 51U)) + aOrbiterC);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 57U) + aOrbiterA) + RotL64(aOrbiterH, 47U));
            aWandererC = aWandererC + ((RotL64(aScatter, 53U) + RotL64(aOrbiterA, 5U)) + aOrbiterI);
            aWandererE = aWandererE ^ (((RotL64(aCross, 43U) + RotL64(aOrbiterD, 23U)) + aOrbiterH) + aPhaseDWandererUpdateSaltF[((aIndex + 6U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererE, 19U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererJ, 23U) ^ aWandererC);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 13U));
            aCarry = aCarry + RotL64(aWandererF, 53U);
            aCarry = aCarry + RotL64(aIngress, 50U);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 31699U)) & S_BLOCK1], 27U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 31616U)) & W_KEY1], 54U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 30407U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31752U)) & S_BLOCK1], 57U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31988U)) & S_BLOCK1], 38U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 31703U)) & W_KEY1], 27U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 4U) + RotL64(aPrevious, 51U)) + (RotL64(aIngress, 39U) ^ RotL64(aCarry, 21U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterF = ((aWandererJ + RotL64(aPrevious, 20U)) + RotL64(aCarry, 27U)) + 14624277139785904404U;
            aOrbiterJ = ((aWandererF + RotL64(aIngress, 11U)) + RotL64(aCarry, 43U)) + 6966977309498165611U;
            aOrbiterK = (((aWandererG + RotL64(aCross, 29U)) + RotL64(aCarry, 35U)) + 205536824352530761U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = (aWandererC + RotL64(aScatter, 47U)) + 16629575265808255692U;
            aOrbiterH = (aWandererI + RotL64(aPrevious, 37U)) + 596881340147972746U;
            aOrbiterE = (aWandererD + RotL64(aCross, 41U)) + 11944412799107412650U;
            aOrbiterI = (aWandererB + RotL64(aIngress, 24U)) + 4615021315668210206U;
            aOrbiterC = (aWandererH + RotL64(aScatter, 57U)) + 8497630055977606216U;
            aOrbiterD = ((aWandererE + RotL64(aIngress, 53U)) + 11131601107309336885U) + aPhaseDOrbiterAssignSaltA[((aIndex + 12U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 5935883479805510099U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 15629346719765798174U;
            aOrbiterK = RotL64((aOrbiterK * 8535523790685945275U), 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 5279128339113651273U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 16778365912440331821U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 705421028266789241U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 16003052937645491524U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 6723226158737614764U;
            aOrbiterI = RotL64((aOrbiterI * 16690657664909260573U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 9785784358981219543U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 10055457337292292710U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 17919129940751761111U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 11779163108592974175U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 1177999477942202687U;
            aOrbiterJ = RotL64((aOrbiterJ * 13475069421684114643U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 9190694445141492214U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 15605342360346353457U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 14547769706392595647U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 14877565450677523492U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 1074095623308025684U;
            aOrbiterE = RotL64((aOrbiterE * 7884068939436891093U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 12803174154216941583U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 8813356463693637033U;
            aOrbiterC = RotL64((aOrbiterC * 4898237214617563167U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 6063909634038581414U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 15112191502834052566U;
            aOrbiterD = RotL64((aOrbiterD * 6780741782103553485U), 37U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterC, 27U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 44U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 47U));
            aIngress = aIngress + (RotL64(aOrbiterH, 13U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterJ, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aIngress, 56U) + RotL64(aOrbiterK, 53U)) + aOrbiterC);
            aWandererI = aWandererI + (((RotL64(aScatter, 19U) + aOrbiterD) + RotL64(aOrbiterA, 24U)) + RotL64(aCarry, 23U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterE, 43U)) + aOrbiterD);
            aWandererE = aWandererE + (((RotL64(aCross, 3U) + aOrbiterA) + RotL64(aOrbiterF, 47U)) + RotL64(aCarry, 51U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterF, 29U)) + aOrbiterH);
            aWandererB = aWandererB + ((RotL64(aScatter, 35U) + RotL64(aOrbiterC, 3U)) + aOrbiterA);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 60U) + aOrbiterD) + RotL64(aOrbiterF, 35U)) + aPhaseDWandererUpdateSaltA[((aIndex + 8U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterI, 60U)) + aOrbiterJ) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 27U) + aOrbiterJ) + RotL64(aOrbiterC, 11U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 35U) ^ aWandererJ);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 57U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 51U));
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererC, 22U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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

void TwistExpander_BasketBall_Arx::Twist_B(TwistWorkSpace *pWorkSpace,
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
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneA, aExpandLaneC, aExpandLaneD, aInvestLaneC, aFireLaneB, aInvestLaneD, aFireLaneC, aOperationLaneA, aFireLaneD, aOperationLaneB, aOperationLaneC
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 3697U)) & S_BLOCK1], 10U) ^ RotL64(aExpandLaneB[((aIndex + 1903U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 554U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 1074U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneD[((aIndex + 3846U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 57U) ^ RotL64(aIngress, 27U)) ^ (RotL64(aPrevious, 41U) + RotL64(aCarry, 10U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterC = (((aWandererJ + RotL64(aCross, 5U)) + RotL64(aCarry, 57U)) + 5173905450211892891U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterI = (aWandererA + RotL64(aPrevious, 35U)) + 3555542451908039957U;
            aOrbiterF = (aWandererI + RotL64(aIngress, 27U)) + 11559884700283861559U;
            aOrbiterJ = ((aWandererG + RotL64(aScatter, 43U)) + RotL64(aCarry, 37U)) + 1352524329968738673U;
            aOrbiterD = (aWandererF + RotL64(aCross, 13U)) + 8914206450420616349U;
            aOrbiterA = (((aWandererH + RotL64(aPrevious, 52U)) + RotL64(aCarry, 19U)) + 2251523378498463946U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = (aWandererE + RotL64(aScatter, 21U)) + 9541575923299247038U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 1239854507907214595U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 17698101462598498934U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2304948713665996433U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 12305566971683256060U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 13804545036303215569U;
            aOrbiterD = RotL64((aOrbiterD * 10359543704152744971U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 10239749097704329264U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 4212214906286320308U;
            aOrbiterJ = RotL64((aOrbiterJ * 3661436621615751071U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 12192418916967430783U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 4475514289326450361U;
            aOrbiterA = RotL64((aOrbiterA * 17497164630368757887U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 17376102613298827459U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 18129393209955439341U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 6404089025014118979U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 4014763724300253568U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 17325007199676828814U;
            aOrbiterI = RotL64((aOrbiterI * 1420888274815627083U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 15480474849292388685U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 14357924730184375449U;
            aOrbiterE = RotL64((aOrbiterE * 16723492259068034209U), 29U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterC, 5U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 21U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 11U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterD, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterF, 3U)) + aOrbiterA);
            aWandererE = aWandererE + ((RotL64(aCross, 21U) + RotL64(aOrbiterE, 51U)) + aOrbiterJ);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 29U) + aOrbiterE) + RotL64(aOrbiterD, 13U));
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 50U) + RotL64(aOrbiterA, 19U)) + aOrbiterE) + RotL64(aCarry, 19U)) + aPhaseEWandererUpdateSaltF[((aIndex + 19U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 57U) + aOrbiterF) + RotL64(aOrbiterD, 35U));
            aWandererI = aWandererI + ((((RotL64(aCross, 3U) + RotL64(aOrbiterC, 57U)) + aOrbiterI) + RotL64(aCarry, 53U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 13U) + aOrbiterI) + RotL64(aOrbiterD, 26U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 20U));
            aCarry = aCarry + (RotL64(aWandererF, 5U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererJ, 41U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererH, 57U);
            aCarry = aCarry + RotL64(aIngress, 24U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aInvestLaneC[aIndex] = aIngress;
        }
    
        // twist_loop_b loop 2
        // ingress from: aInvestLaneC, aExpandLaneC, aFireLaneB
        // ingress directions: aInvestLaneC forward forced, aExpandLaneC forward forced, aFireLaneB forward/backward random
        // cross from: aExpandLaneA, aExpandLaneD
        // cross directions: aExpandLaneA backward forced, aExpandLaneD backward/forward random
        // write to: aInvestLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneC[((aIndex + 8104U)) & S_BLOCK1], 28U) ^ RotL64(aExpandLaneC[((aIndex + 7511U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 9702U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 7276U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneD[((aIndex + 5485U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 57U) ^ RotL64(aIngress, 13U)) + (RotL64(aCarry, 27U) + RotL64(aPrevious, 42U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterG = ((aWandererB + RotL64(aScatter, 20U)) + 8685374557928800912U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterI = ((aWandererE + RotL64(aCross, 51U)) + RotL64(aCarry, 19U)) + 3482312691892161229U;
            aOrbiterD = (aWandererJ + RotL64(aPrevious, 43U)) + 6948130297389161165U;
            aOrbiterC = ((aWandererC + RotL64(aIngress, 29U)) + RotL64(aCarry, 3U)) + 5506385663788942690U;
            aOrbiterK = (((aWandererA + RotL64(aScatter, 5U)) + RotL64(aCarry, 37U)) + 17859982009307397161U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterF = (aWandererG + RotL64(aCross, 11U)) + 9178488809207094043U;
            aOrbiterE = (aWandererD + RotL64(aPrevious, 35U)) + 1835479501226057169U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 5368101733632614939U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 9050459666576835422U;
            aOrbiterD = RotL64((aOrbiterD * 10351719549990259551U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 9042186993119635078U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 17528342580198295025U;
            aOrbiterI = RotL64((aOrbiterI * 14316671546614386775U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 6495418332558436882U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 8834495762667327342U;
            aOrbiterG = RotL64((aOrbiterG * 10783141541937645995U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 4364314196965690905U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 6357485231062120459U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 289429584586504995U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 3321488322626415347U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 10817330671781848737U;
            aOrbiterF = RotL64((aOrbiterF * 15875919466358823335U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 17974092279281611763U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 2871472057292789157U;
            aOrbiterC = RotL64((aOrbiterC * 16104199340711015181U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 15187929795092006849U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 13482063681546475923U;
            aOrbiterK = RotL64((aOrbiterK * 14466266308157364963U), 39U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterD, 19U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 12U));
            aIngress = aIngress + (RotL64(aOrbiterK, 35U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterE, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterD, 58U)) + aOrbiterK);
            aWandererD = aWandererD + (((RotL64(aScatter, 35U) + RotL64(aOrbiterF, 37U)) + aOrbiterG) + RotL64(aCarry, 41U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterI, 43U)) + aOrbiterC);
            aWandererG = aWandererG + (((RotL64(aPrevious, 57U) + aOrbiterC) + RotL64(aOrbiterE, 29U)) + RotL64(aCarry, 5U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 21U) + RotL64(aOrbiterK, 51U)) + aOrbiterG) + aPhaseEWandererUpdateSaltD[((aIndex + 18U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aPrevious, 42U) + RotL64(aOrbiterI, 3U)) + aOrbiterE);
            aWandererC = aWandererC ^ (((RotL64(aCross, 13U) + RotL64(aOrbiterK, 19U)) + aOrbiterC) + aPhaseEWandererUpdateSaltB[((aIndex + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 57U));
            aCarry = aCarry + (RotL64(aWandererB, 14U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererC, 39U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererA, 43U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = (RotL64(aInvestLaneD[((aIndex + 15035U)) & S_BLOCK1], 22U) ^ RotL64(aExpandLaneD[((aIndex + 15905U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 11993U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 12941U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 15427U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 11525U)) & S_BLOCK1], 52U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 22U) + RotL64(aCross, 57U)) ^ (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 39U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterE = (aWandererB + RotL64(aCross, 41U)) + 4179952823252098240U;
            aOrbiterJ = (aWandererK + RotL64(aIngress, 19U)) + 3745613452332101749U;
            aOrbiterG = ((aWandererH + RotL64(aPrevious, 58U)) + RotL64(aCarry, 11U)) + 2955689793395307176U;
            aOrbiterF = ((aWandererG + RotL64(aScatter, 11U)) + RotL64(aCarry, 43U)) + 5639060180251322019U;
            aOrbiterA = (aWandererE + RotL64(aPrevious, 5U)) + 7901969163853586463U;
            aOrbiterI = ((aWandererI + RotL64(aScatter, 29U)) + 2242166787816318119U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = (((aWandererD + RotL64(aCross, 35U)) + RotL64(aCarry, 23U)) + 5239936443960750064U) + aPhaseEOrbiterAssignSaltC[((aIndex + 26U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 13939136954732185558U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 17058884136712717463U;
            aOrbiterG = RotL64((aOrbiterG * 7222348891215482977U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 18148618660054585941U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 7022023484530327814U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 650100011311048589U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 7722084537340095637U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 11764151879690934182U;
            aOrbiterA = RotL64((aOrbiterA * 12264384877711365655U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 16412785901758144708U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 9666718667728274824U;
            aOrbiterI = RotL64((aOrbiterI * 10865799822751771795U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 4307127540152109364U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 2457646804702647606U;
            aOrbiterB = RotL64((aOrbiterB * 6340030928007058595U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 3179394870088602208U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 504977947273774249U;
            aOrbiterJ = RotL64((aOrbiterJ * 16190282058883481551U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 16182729401018310837U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 7110817020445860609U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 13371352088428584087U), 13U);
            //
            aIngress = RotL64(aOrbiterE, 53U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterB, 29U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterJ, 21U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterI, 12U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aPrevious, 57U) + aOrbiterB) + RotL64(aOrbiterA, 57U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 21U) + aOrbiterB) + RotL64(aOrbiterJ, 5U));
            aWandererG = aWandererG + (((RotL64(aScatter, 27U) + RotL64(aOrbiterF, 47U)) + aOrbiterA) + aPhaseEWandererUpdateSaltA[((aIndex + 17U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterA, 37U)) + aOrbiterI);
            aWandererE = aWandererE + ((((RotL64(aIngress, 37U) + aOrbiterE) + RotL64(aOrbiterI, 19U)) + RotL64(aCarry, 37U)) + aPhaseEWandererUpdateSaltE[((aIndex + 19U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 13U) + aOrbiterF) + RotL64(aOrbiterG, 27U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 46U) + RotL64(aOrbiterB, 12U)) + aOrbiterE) + RotL64(aCarry, 11U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 28U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 11U));
            aCarry = aCarry + (RotL64(aWandererB, 3U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererD, 19U);
            aCarry = aCarry + RotL64(aIngress, 60U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 17092U)) & S_BLOCK1], 41U) ^ RotL64(aInvestLaneC[((aIndex + 21712U)) & S_BLOCK1], 22U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 17273U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 21623U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 21240U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 20051U)) & S_BLOCK1], 26U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aIngress, 24U)) ^ (RotL64(aCross, 57U) + RotL64(aPrevious, 41U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterB = (aWandererK + RotL64(aCross, 43U)) + 380024772508948442U;
            aOrbiterA = ((aWandererC + RotL64(aScatter, 13U)) + 7649029098162567210U) + aPhaseEOrbiterAssignSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = ((aWandererI + RotL64(aPrevious, 5U)) + 5329304598870421851U) + aPhaseEOrbiterAssignSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = ((aWandererE + RotL64(aIngress, 51U)) + RotL64(aCarry, 53U)) + 12306118665045151326U;
            aOrbiterG = ((aWandererD + RotL64(aScatter, 21U)) + RotL64(aCarry, 37U)) + 960751560457324256U;
            aOrbiterI = (aWandererB + RotL64(aCross, 36U)) + 3244070254386191876U;
            aOrbiterC = ((aWandererG + RotL64(aPrevious, 29U)) + RotL64(aCarry, 19U)) + 15733408571609521746U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 17623448932647018544U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 8787759896149035829U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7092515868845497573U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 14741681792348288162U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 8801731213568307302U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12127126999570616489U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 9872248187499779222U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 15407371518644528235U;
            aOrbiterA = RotL64((aOrbiterA * 1245102406469471673U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 4242060317152943062U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 9942784962409917541U;
            aOrbiterK = RotL64((aOrbiterK * 888649755587764533U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 7296348796484458631U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 15061417216070157797U;
            aOrbiterB = RotL64((aOrbiterB * 10349554676953256231U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 3233185810644297433U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 9241229457641024287U;
            aOrbiterC = RotL64((aOrbiterC * 2728237515724597517U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 8464051359381554575U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 3307872165699029375U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 4859663401033023433U), 13U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterK, 51U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 11U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 3U));
            aIngress = aIngress + RotL64(aOrbiterI, 58U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aPrevious, 19U) + aOrbiterI) + RotL64(aOrbiterK, 3U)) + RotL64(aCarry, 23U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 43U) + aOrbiterI) + RotL64(aOrbiterG, 29U));
            aWandererI = aWandererI + ((((RotL64(aScatter, 5U) + aOrbiterB) + RotL64(aOrbiterA, 57U)) + RotL64(aCarry, 53U)) + aPhaseEWandererUpdateSaltF[((aIndex + 7U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterE, 48U)) + aOrbiterB);
            aWandererC = aWandererC + ((RotL64(aScatter, 29U) + aOrbiterA) + RotL64(aOrbiterC, 11U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterI, 39U)) + aOrbiterC) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aIngress, 50U) + aOrbiterC) + RotL64(aOrbiterB, 21U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 43U));
            aCarry = aCarry + (RotL64(aWandererE, 39U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererK, 30U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererD, 51U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 23983U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneA[((aIndex + 23313U)) & S_BLOCK1], 12U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 24878U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 23668U)) & S_BLOCK1], 43U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 27088U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aInvestLaneD[((aIndex + 21972U)) & S_BLOCK1], 52U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 23U) ^ RotL64(aCross, 51U)) + (RotL64(aIngress, 4U) ^ RotL64(aCarry, 37U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterK = (aWandererI + RotL64(aCross, 43U)) + 12775735908960052604U;
            aOrbiterD = (aWandererH + RotL64(aIngress, 57U)) + 11791373812080296887U;
            aOrbiterI = (((aWandererJ + RotL64(aScatter, 27U)) + RotL64(aCarry, 13U)) + 5537362877706057303U) + aPhaseEOrbiterAssignSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterH = ((aWandererD + RotL64(aPrevious, 5U)) + RotL64(aCarry, 47U)) + 2023912048504189380U;
            aOrbiterE = (aWandererA + RotL64(aCross, 13U)) + 17668828109963766893U;
            aOrbiterJ = ((aWandererF + RotL64(aScatter, 50U)) + 558908629933941224U) + aPhaseEOrbiterAssignSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = ((aWandererB + RotL64(aIngress, 21U)) + RotL64(aCarry, 29U)) + 1479633119685446888U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 15460320397843364063U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 10059749397555469054U;
            aOrbiterI = RotL64((aOrbiterI * 8671817118586065469U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 9987633811929693924U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 10087337844580228269U;
            aOrbiterE = RotL64((aOrbiterE * 13817142288940843815U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 4446204415503364254U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 15106063243302192717U;
            aOrbiterD = RotL64((aOrbiterD * 13273756657334709803U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 9430197906134676162U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 1226048679997253363U;
            aOrbiterA = RotL64((aOrbiterA * 14247538885252664127U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 10611580584157624739U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 3137391249289641509U;
            aOrbiterH = RotL64((aOrbiterH * 5462682413239873181U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 9327201928815412810U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 7890659377013147073U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13827717178378062047U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 10675114832750356941U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 8804440385852327267U;
            aOrbiterK = RotL64((aOrbiterK * 8520671775587260601U), 29U);
            //
            aIngress = RotL64(aOrbiterD, 51U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 43U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 21U));
            aIngress = aIngress + RotL64(aOrbiterH, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aIngress, 57U) + aOrbiterH) + RotL64(aOrbiterI, 35U)) + aPhaseEWandererUpdateSaltB[((aIndex + 26U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 5U) + aOrbiterD) + RotL64(aOrbiterJ, 21U)) + RotL64(aCarry, 47U)) + aPhaseEWandererUpdateSaltD[((aIndex + 14U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterE, 47U)) + aOrbiterI);
            aWandererB = aWandererB + (((RotL64(aScatter, 44U) + aOrbiterD) + RotL64(aOrbiterH, 56U)) + RotL64(aCarry, 3U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 51U) + aOrbiterJ) + RotL64(aOrbiterA, 5U));
            aWandererA = aWandererA + ((RotL64(aCross, 23U) + RotL64(aOrbiterK, 13U)) + aOrbiterI);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 37U) + aOrbiterJ) + RotL64(aOrbiterH, 29U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 60U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 5U));
            aCarry = aCarry + (RotL64(aWandererA, 27U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererD, 23U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 30624U)) & S_BLOCK1], 38U) ^ RotL64(aExpandLaneA[((aIndex + 28744U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 29506U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28026U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 28635U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aInvestLaneD[((aIndex + 31858U)) & S_BLOCK1], 28U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 60U) ^ RotL64(aIngress, 47U)) + (RotL64(aPrevious, 13U) + RotL64(aCarry, 29U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterK = ((aWandererC + RotL64(aCross, 60U)) + RotL64(aCarry, 23U)) + 6069475454765660321U;
            aOrbiterI = (aWandererH + RotL64(aPrevious, 35U)) + 11483704742497268068U;
            aOrbiterJ = ((aWandererI + RotL64(aIngress, 41U)) + 11055697447388986418U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = (aWandererE + RotL64(aScatter, 47U)) + 10897095046039997004U;
            aOrbiterD = (((aWandererF + RotL64(aPrevious, 5U)) + RotL64(aCarry, 3U)) + 4731637118230457840U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterA = (aWandererD + RotL64(aCross, 29U)) + 13855839187084986751U;
            aOrbiterG = ((aWandererK + RotL64(aScatter, 13U)) + RotL64(aCarry, 41U)) + 5328208115460188239U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 12479538544291412985U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 10740165998792608231U;
            aOrbiterJ = RotL64((aOrbiterJ * 14046827922294477379U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 6492798157284955373U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 13056825957483891921U;
            aOrbiterD = RotL64((aOrbiterD * 14882112110627751751U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 2068184064919194657U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 5656302738780746294U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 16493021179127646345U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 11193756120230763294U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 17306750816837208999U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 7949360041241439741U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 12952818800389361804U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 15380412293642628312U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2914662289178925547U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 7706090204767242996U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 14598802276412649570U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 4821408736292041399U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 17819762117328075515U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 6481384240915075101U;
            aOrbiterG = RotL64((aOrbiterG * 4836701121865783029U), 39U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterK, 29U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 11U));
            aIngress = aIngress + (RotL64(aOrbiterG, 58U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterI, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aScatter, 13U) + aOrbiterG) + RotL64(aOrbiterJ, 4U)) + RotL64(aCarry, 29U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 53U) + RotL64(aOrbiterF, 43U)) + aOrbiterI) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aCross, 47U) + aOrbiterG) + RotL64(aOrbiterA, 13U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 36U) + RotL64(aOrbiterI, 51U)) + aOrbiterG) + aPhaseEWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 5U) + aOrbiterD) + RotL64(aOrbiterK, 21U)) + RotL64(aCarry, 57U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterD, 29U)) + aOrbiterI);
            aWandererF = aWandererF + ((RotL64(aPrevious, 29U) + RotL64(aOrbiterJ, 57U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 23U));
            aCarry = aCarry + (RotL64(aWandererK, 47U) ^ aWandererD);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 58U));
            aCarry = aCarry + RotL64(aWandererF, 19U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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

void TwistExpander_BasketBall_Arx::Twist_C(TwistWorkSpace *pWorkSpace,
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
        // read from: aOperationLaneA, aOperationLaneB, aExpandLaneC, aOperationLaneC, aOperationLaneD, aExpandLaneB, aSnowLaneA, aExpandLaneD, aInvestLaneC, aSnowLaneB, aInvestLaneA, aWorkLaneA, aExpandLaneA, aWorkLaneB, aInvestLaneD, aWorkLaneC, aInvestLaneB
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 2402U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneB[((aIndex + 1592U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aExpandLaneC[((aIndex + 5196U)) & S_BLOCK1], 26U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 3270U)) & S_BLOCK1], 56U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 2377U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aExpandLaneB[((aIndex + 3107U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 39U) + RotL64(aPrevious, 3U)) + (RotL64(aIngress, 23U) ^ RotL64(aCarry, 52U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterF = (aWandererI + RotL64(aScatter, 19U)) + 4634399531433127141U;
            aOrbiterI = (aWandererB + RotL64(aIngress, 43U)) + 16961792729406903200U;
            aOrbiterJ = ((aWandererF + RotL64(aPrevious, 5U)) + 4105280732301137738U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterA = (aWandererK + RotL64(aCross, 39U)) + 15692013501147331191U;
            aOrbiterC = (((aWandererC + RotL64(aIngress, 13U)) + RotL64(aCarry, 5U)) + 1252216715968780587U) + aPhaseFOrbiterAssignSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterH = (aWandererG + RotL64(aPrevious, 60U)) + 7958289043012473752U;
            aOrbiterB = ((aWandererJ + RotL64(aScatter, 53U)) + RotL64(aCarry, 47U)) + 6611577301818896615U;
            aOrbiterK = (aWandererA + RotL64(aCross, 11U)) + 8506226754305949140U;
            aOrbiterG = (aWandererH + RotL64(aIngress, 37U)) + 3648813120449403353U;
            aOrbiterE = (aWandererE + RotL64(aCross, 51U)) + 5195245426245535735U;
            aOrbiterD = ((aWandererD + RotL64(aPrevious, 24U)) + RotL64(aCarry, 27U)) + 542948051600803051U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 11974253551208964789U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 10596463592332655367U;
            aOrbiterJ = RotL64((aOrbiterJ * 10941161258815714641U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 12015129484061440159U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 8254944355710109060U;
            aOrbiterC = RotL64((aOrbiterC * 3233697992479357615U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 2754858806943915419U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 5007802002906662779U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 15613733948331639723U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 6262190752136523216U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 10528977986487821428U;
            aOrbiterG = RotL64((aOrbiterG * 1184258264034585525U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 8511097226098211854U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 12091864735686692582U;
            aOrbiterH = RotL64((aOrbiterH * 6128140528141411237U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 4970966265236842566U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 10728884018459718341U;
            aOrbiterD = RotL64((aOrbiterD * 18205183219769602827U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 13760057185629905360U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 6590269178744829056U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 14482684769712170123U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 765826377665103262U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 9364759196106579706U;
            aOrbiterK = RotL64((aOrbiterK * 10315111163659289329U), 39U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 4629303338428087146U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 15107221579712215172U;
            aOrbiterB = RotL64((aOrbiterB * 14410837138199304663U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 9407987092859067074U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 13589362515507116096U;
            aOrbiterF = RotL64((aOrbiterF * 4544198075069052713U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 2236921538387014026U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 4634399531433127141U;
            aOrbiterA = RotL64((aOrbiterA * 13132011613143486575U), 19U);
            //
            aIngress = RotL64(aOrbiterH, 37U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 19U));
            aIngress = aIngress + (RotL64(aOrbiterA, 39U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterI, 24U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 3U));
            aIngress = aIngress + RotL64(aOrbiterD, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterE, 6U)) + aOrbiterH);
            aWandererH = aWandererH + (((RotL64(aCross, 42U) + aOrbiterD) + RotL64(aOrbiterA, 47U)) + RotL64(aCarry, 41U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 29U) + aOrbiterB) + RotL64(aOrbiterE, 29U));
            aWandererE = aWandererE + ((RotL64(aIngress, 39U) + RotL64(aOrbiterI, 11U)) + aOrbiterD);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 13U) + aOrbiterD) + RotL64(aOrbiterF, 51U)) + aPhaseFWandererUpdateSaltB[((aIndex + 12U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aPrevious, 56U) + aOrbiterA) + RotL64(aOrbiterC, 41U)) + RotL64(aCarry, 19U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 51U) + aOrbiterA) + RotL64(aOrbiterK, 37U));
            aWandererB = aWandererB + ((RotL64(aIngress, 27U) + RotL64(aOrbiterA, 53U)) + aOrbiterG);
            aWandererG = aWandererG ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterJ, 57U)) + aOrbiterB);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 21U) + aOrbiterB) + RotL64(aOrbiterH, 39U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 53U) + aOrbiterA) + RotL64(aOrbiterI, 18U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 29U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererI, 6U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererG, 39U) ^ aWandererB);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 27U));
            aCarry = aCarry + (RotL64(aWandererF, 35U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererE, 60U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aSnowLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_c loop 2
        // ingress from: aSnowLaneA, aOperationLaneC, aOperationLaneD, aExpandLaneD
        // ingress directions: aSnowLaneA forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aExpandLaneD forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aInvestLaneC
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aInvestLaneC backward/forward random
        // write to: aSnowLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneA[((aIndex + 8164U)) & S_BLOCK1], 14U) ^ RotL64(aOperationLaneC[((aIndex + 6170U)) & S_BLOCK1], 57U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 5565U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 10766U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 10649U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 10887U)) & S_BLOCK1], 48U));
            aCross ^= RotL64(aInvestLaneC[((aIndex + 8151U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 37U) ^ RotL64(aCross, 11U)) ^ (RotL64(aIngress, 60U) + RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterK = (aWandererC + RotL64(aScatter, 60U)) + 2558105147674438050U;
            aOrbiterJ = (aWandererI + RotL64(aCross, 13U)) + 15856662514774702561U;
            aOrbiterI = (aWandererK + RotL64(aPrevious, 37U)) + 13346869226246584582U;
            aOrbiterG = (aWandererF + RotL64(aIngress, 57U)) + 7632111846116243973U;
            aOrbiterF = (((aWandererD + RotL64(aScatter, 21U)) + RotL64(aCarry, 13U)) + 2102101361626976279U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = (aWandererJ + RotL64(aCross, 53U)) + 5605968705067851563U;
            aOrbiterB = ((aWandererE + RotL64(aIngress, 35U)) + RotL64(aCarry, 29U)) + 6842483186584326681U;
            aOrbiterH = (aWandererH + RotL64(aPrevious, 11U)) + 5559797213819425064U;
            aOrbiterE = ((aWandererB + RotL64(aCross, 39U)) + RotL64(aCarry, 37U)) + 12422313931331576759U;
            aOrbiterA = (aWandererA + RotL64(aIngress, 3U)) + 2751024420047872601U;
            aOrbiterC = ((aWandererG + RotL64(aPrevious, 28U)) + 11031320239359798610U) + aPhaseFOrbiterAssignSaltE[((aIndex + 3U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 14366375309473793217U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 11971479429768505316U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 10063001532313098203U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 3947595951884469542U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 17882767922372770896U;
            aOrbiterJ = RotL64((aOrbiterJ * 3361906348965810211U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 513871456983509223U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 5951677013597794294U;
            aOrbiterK = RotL64((aOrbiterK * 8508629569649935293U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 437626309049021931U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 466674061172005705U;
            aOrbiterH = RotL64((aOrbiterH * 1310502572084891157U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 12362602809233133718U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 10525852878882195702U;
            aOrbiterD = RotL64((aOrbiterD * 17755022180514914325U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 17927000184308583095U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 566723721423470052U;
            aOrbiterA = RotL64((aOrbiterA * 17710534355278632573U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 9504585484034413577U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 4614306037721859929U;
            aOrbiterF = RotL64((aOrbiterF * 170807293799483539U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 1463218357720031588U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 4036696102163560633U;
            aOrbiterC = RotL64((aOrbiterC * 15389914226155130065U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 9907678911300898726U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 11804311892289601322U;
            aOrbiterG = RotL64((aOrbiterG * 13986106774841242253U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 6514645538508331396U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 17246364354815744899U;
            aOrbiterE = RotL64((aOrbiterE * 12800661037742526999U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 6725706155285333764U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 2558105147674438050U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 6752457079901154727U), 53U);
            //
            aIngress = RotL64(aOrbiterB, 47U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 18U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 37U));
            aIngress = aIngress + (RotL64(aOrbiterI, 5U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterF, 51U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterH, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 60U) + RotL64(aOrbiterK, 39U)) + aOrbiterF);
            aWandererK = aWandererK + ((RotL64(aIngress, 11U) + aOrbiterH) + RotL64(aOrbiterJ, 53U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterI, 41U)) + aOrbiterC);
            aWandererA = aWandererA + ((RotL64(aCross, 53U) + RotL64(aOrbiterI, 6U)) + aOrbiterK);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 29U) + aOrbiterG) + RotL64(aOrbiterE, 19U));
            aWandererE = aWandererE + (((RotL64(aScatter, 50U) + RotL64(aOrbiterD, 29U)) + aOrbiterA) + RotL64(aCarry, 53U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 39U) + RotL64(aOrbiterF, 3U)) + aOrbiterD) + aPhaseFWandererUpdateSaltC[((aIndex + 17U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 27U) + RotL64(aOrbiterB, 50U)) + aOrbiterK) + RotL64(aCarry, 5U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterJ, 43U)) + aOrbiterE);
            aWandererG = aWandererG + (((RotL64(aCross, 35U) + aOrbiterB) + RotL64(aOrbiterH, 47U)) + aPhaseFWandererUpdateSaltF[((aIndex + 24U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 43U) + aOrbiterF) + RotL64(aOrbiterH, 35U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 13U));
            aCarry = aCarry + (RotL64(aWandererB, 60U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererI, 11U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererD, 27U) ^ aWandererA);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 5U));
            aCarry = aCarry + RotL64(aWandererF, 3U);
            aCarry = aCarry + RotL64(aIngress, 48U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aSnowLaneB[((aIndex + 11691U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneA[((aIndex + 13525U)) & S_BLOCK1], 48U));
            aIngress ^= RotL64(aInvestLaneA[((aIndex + 12261U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 13999U)) & S_BLOCK1], 26U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 12805U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 38U) ^ RotL64(aCarry, 23U)) ^ (RotL64(aCross, 3U) + RotL64(aIngress, 51U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterJ = (((aWandererA + RotL64(aIngress, 41U)) + RotL64(aCarry, 41U)) + 14157904117287696136U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = (aWandererJ + RotL64(aPrevious, 53U)) + 7369512677371640676U;
            aOrbiterD = (aWandererI + RotL64(aCross, 50U)) + 8411250745902073798U;
            aOrbiterH = (aWandererK + RotL64(aScatter, 13U)) + 5002041814539710275U;
            aOrbiterB = (((aWandererF + RotL64(aCross, 5U)) + RotL64(aCarry, 5U)) + 9538041410816283124U) + aPhaseFOrbiterAssignSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterI = (aWandererH + RotL64(aScatter, 29U)) + 5210700103927513061U;
            aOrbiterE = (aWandererB + RotL64(aIngress, 19U)) + 7600709399101287982U;
            aOrbiterG = (aWandererC + RotL64(aPrevious, 37U)) + 2366369466696580499U;
            aOrbiterF = (aWandererD + RotL64(aIngress, 11U)) + 5544575244203019109U;
            aOrbiterA = (aWandererG + RotL64(aCross, 24U)) + 8710073749110329779U;
            aOrbiterK = ((aWandererE + RotL64(aScatter, 47U)) + RotL64(aCarry, 29U)) + 15998211310115361630U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 15354357553877376422U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 10657523549259276169U;
            aOrbiterD = RotL64((aOrbiterD * 13695239532898311073U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 10405750198355464768U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 3465819693133515142U;
            aOrbiterI = RotL64((aOrbiterI * 14678343718277562799U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 16724189641701408630U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 3484340153620198872U;
            aOrbiterG = RotL64((aOrbiterG * 17247547677520703125U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 7420442404884871126U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 11138445997256757636U;
            aOrbiterJ = RotL64((aOrbiterJ * 11167543379937571127U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 1428191560884663125U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 16950093140800653985U;
            aOrbiterA = RotL64((aOrbiterA * 4423012306984814805U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 17288299075036481960U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 13793597915359681028U;
            aOrbiterK = RotL64((aOrbiterK * 9639204979982125757U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 5017972942710079726U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 12409957957614320964U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 10273295741911545745U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 12487994181992095174U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 1573393166996612118U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13364311829104520751U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 13227642825780350128U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 7961292096150889569U;
            aOrbiterB = RotL64((aOrbiterB * 16627209081334341289U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 10312485102088913337U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 3177620041478410950U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15918551366833593853U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 2599092792737616563U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 14157904117287696136U;
            aOrbiterH = RotL64((aOrbiterH * 14883446269291639813U), 23U);
            //
            aIngress = RotL64(aOrbiterH, 41U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 23U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 43U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 35U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 47U));
            aIngress = aIngress + RotL64(aOrbiterG, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aScatter, 57U) + aOrbiterJ) + RotL64(aOrbiterC, 28U));
            aWandererH = aWandererH + ((RotL64(aPrevious, 38U) + aOrbiterG) + RotL64(aOrbiterD, 51U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 3U) + aOrbiterA) + RotL64(aOrbiterI, 11U));
            aWandererE = aWandererE + (((RotL64(aIngress, 35U) + aOrbiterF) + RotL64(aOrbiterB, 35U)) + RotL64(aCarry, 19U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 13U) + aOrbiterD) + RotL64(aOrbiterJ, 3U)) + aPhaseFWandererUpdateSaltD[((aIndex + 8U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aPrevious, 5U) + aOrbiterH) + RotL64(aOrbiterB, 37U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 47U) + aOrbiterD) + RotL64(aOrbiterI, 5U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aCross, 27U) + RotL64(aOrbiterI, 57U)) + aOrbiterG);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterK, 40U)) + aOrbiterA);
            aWandererA = aWandererA + (((RotL64(aPrevious, 54U) + aOrbiterE) + RotL64(aOrbiterJ, 13U)) + RotL64(aCarry, 57U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterF, 21U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 26U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 37U));
            aCarry = aCarry + (RotL64(aWandererA, 13U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererB, 43U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererK, 18U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererE, 3U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_c loop 4
        // ingress from: aWorkLaneA, aSnowLaneA, aExpandLaneA
        // ingress directions: aWorkLaneA forward forced, aSnowLaneA forward forced, aExpandLaneA forward/backward random
        // cross from: aSnowLaneB, aOperationLaneD
        // cross directions: aSnowLaneB backward forced, aOperationLaneD backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 19322U)) & S_BLOCK1], 38U) ^ RotL64(aSnowLaneA[((aIndex + 20258U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 20859U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 19074U)) & S_BLOCK1], 18U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 17608U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 57U) ^ RotL64(aCross, 36U)) + (RotL64(aCarry, 19U) + RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterE = (((aWandererK + RotL64(aScatter, 57U)) + RotL64(aCarry, 43U)) + 1888427424966603593U) + aPhaseFOrbiterAssignSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterH = (aWandererE + RotL64(aIngress, 5U)) + 5436761445660415091U;
            aOrbiterI = (aWandererD + RotL64(aPrevious, 43U)) + 17322876217962143270U;
            aOrbiterF = (aWandererH + RotL64(aCross, 21U)) + 9728299982740564979U;
            aOrbiterJ = (aWandererI + RotL64(aIngress, 46U)) + 301720335271716921U;
            aOrbiterK = ((aWandererG + RotL64(aPrevious, 41U)) + RotL64(aCarry, 57U)) + 8069685428854814396U;
            aOrbiterA = ((aWandererA + RotL64(aScatter, 37U)) + 1973715500949100991U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = (aWandererB + RotL64(aCross, 51U)) + 87666408799854155U;
            aOrbiterG = (aWandererC + RotL64(aScatter, 53U)) + 12195436904339035245U;
            aOrbiterB = (aWandererJ + RotL64(aIngress, 39U)) + 4578742069143400295U;
            aOrbiterD = ((aWandererF + RotL64(aCross, 34U)) + RotL64(aCarry, 29U)) + 7828776048774876484U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 17203146364542781833U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 16913369550858890466U;
            aOrbiterI = RotL64((aOrbiterI * 13534417587921978507U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 9632761514552265402U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 9106637671877341286U;
            aOrbiterK = RotL64((aOrbiterK * 9073709119482640391U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 15423680889126750876U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 6087310684583331882U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8964465129744898619U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 5420955876411796789U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 14166807419730848032U;
            aOrbiterE = RotL64((aOrbiterE * 442659738632823751U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 8118312450347026824U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 4253043584558403086U;
            aOrbiterC = RotL64((aOrbiterC * 5651748455190536467U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 8810774678371762700U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 12218479555589447835U;
            aOrbiterB = RotL64((aOrbiterB * 11026364205248516355U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 11389930523582876358U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 16334420553471379915U;
            aOrbiterJ = RotL64((aOrbiterJ * 13830132212033904777U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 18201289372553710279U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 7196540389657785361U;
            aOrbiterH = RotL64((aOrbiterH * 13058135202554889791U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 2601046573550065116U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 2243003381737071984U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 10518763530499878945U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 6058992247656841580U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 10083863011670540073U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 17908394295613117155U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 8505005026063156940U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 1888427424966603593U;
            aOrbiterA = RotL64((aOrbiterA * 18298382581929885653U), 23U);
            //
            aIngress = RotL64(aOrbiterC, 19U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 27U));
            aIngress = aIngress + (RotL64(aOrbiterB, 37U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterD, 5U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 54U));
            aIngress = aIngress + RotL64(aOrbiterG, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterF, 23U)) + aOrbiterD);
            aWandererD = aWandererD + ((RotL64(aIngress, 13U) + aOrbiterG) + RotL64(aOrbiterC, 37U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 53U) + aOrbiterJ) + RotL64(aOrbiterK, 13U));
            aWandererH = aWandererH + (((RotL64(aCross, 3U) + aOrbiterA) + RotL64(aOrbiterH, 5U)) + RotL64(aCarry, 5U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 35U) + aOrbiterD) + RotL64(aOrbiterB, 27U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 56U) + RotL64(aOrbiterK, 60U)) + aOrbiterI) + RotL64(aCarry, 53U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 5U) + aOrbiterC) + RotL64(aOrbiterH, 21U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aCross, 51U) + aOrbiterD) + RotL64(aOrbiterH, 41U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 47U) + aOrbiterK) + RotL64(aOrbiterA, 11U)) + aPhaseFWandererUpdateSaltA[((aIndex + 7U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aPrevious, 22U) + RotL64(aOrbiterI, 53U)) + aOrbiterE);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterK, 58U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererF, 24U) ^ aWandererC);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 3U));
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererH, 11U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererG, 6U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererE, 35U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 25692U)) & S_BLOCK1], 23U) ^ RotL64(aSnowLaneB[((aIndex + 23598U)) & S_BLOCK1], 58U));
            aIngress ^= RotL64(aInvestLaneD[((aIndex + 26835U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21846U)) & S_BLOCK1], 51U) ^ RotL64(aSnowLaneA[((aIndex + 27083U)) & S_BLOCK1], 34U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 57U) ^ RotL64(aPrevious, 44U)) ^ (RotL64(aIngress, 13U) + RotL64(aCross, 27U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterE = ((aWandererI + RotL64(aPrevious, 47U)) + 11700815697312060726U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = (aWandererA + RotL64(aCross, 19U)) + 11808423452327465441U;
            aOrbiterD = ((aWandererB + RotL64(aScatter, 54U)) + RotL64(aCarry, 53U)) + 8670503858631730886U;
            aOrbiterA = ((aWandererK + RotL64(aIngress, 51U)) + RotL64(aCarry, 19U)) + 2400061067991988544U;
            aOrbiterI = (aWandererC + RotL64(aCross, 37U)) + 16163118178366229686U;
            aOrbiterJ = (aWandererE + RotL64(aPrevious, 13U)) + 3280178595904941068U;
            aOrbiterC = ((aWandererH + RotL64(aIngress, 23U)) + 3298683600817047727U) + aPhaseFOrbiterAssignSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = (aWandererJ + RotL64(aScatter, 57U)) + 16321624053445183574U;
            aOrbiterF = (aWandererG + RotL64(aCross, 44U)) + 6730229877611375225U;
            aOrbiterK = ((aWandererF + RotL64(aPrevious, 27U)) + RotL64(aCarry, 39U)) + 10162830636713641322U;
            aOrbiterH = (aWandererD + RotL64(aIngress, 21U)) + 15646771327759599256U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 14841751262270544102U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 9545541117228834895U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 11529769874752969377U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 14676615635857599982U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 1231768638470558855U;
            aOrbiterE = RotL64((aOrbiterE * 2716808508509014677U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 1945905595345404833U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 1406171421638586846U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4577864352425476233U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 1970292335806697198U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 12309719390375013297U;
            aOrbiterI = RotL64((aOrbiterI * 16540660957923687327U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 5352135521358954576U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 15465675376193501658U;
            aOrbiterJ = RotL64((aOrbiterJ * 16385761112921041387U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 2842123638916600369U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 3544764287036748668U;
            aOrbiterF = RotL64((aOrbiterF * 3360772950777850115U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 6038297172906492282U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 10249342332287140970U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 16701083081566042277U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 1662076777040529446U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 1949705569959740274U;
            aOrbiterK = RotL64((aOrbiterK * 11340691546658994529U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 13934194245417822360U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 5720408806425535958U;
            aOrbiterA = RotL64((aOrbiterA * 15237561081637415383U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 2209251362417210658U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 4917447930929521699U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 17489570156694692569U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 14817115766683623486U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 11700815697312060726U;
            aOrbiterG = RotL64((aOrbiterG * 16982411053956669181U), 57U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterE, 11U);
            aIngress = aIngress + (RotL64(aOrbiterH, 57U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterI, 53U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterD, 21U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterJ, 47U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterC, 26U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aPrevious, 41U) + aOrbiterF) + RotL64(aOrbiterE, 48U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 26U) + RotL64(aOrbiterG, 41U)) + aOrbiterI);
            aWandererI = aWandererI + ((((RotL64(aScatter, 51U) + aOrbiterJ) + RotL64(aOrbiterH, 11U)) + RotL64(aCarry, 23U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterJ, 13U)) + aOrbiterB);
            aWandererE = aWandererE + ((RotL64(aCross, 5U) + RotL64(aOrbiterF, 23U)) + aOrbiterA);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 54U) + aOrbiterD) + RotL64(aOrbiterC, 21U));
            aWandererA = aWandererA + ((RotL64(aScatter, 13U) + RotL64(aOrbiterK, 29U)) + aOrbiterJ);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterA, 19U)) + aOrbiterC);
            aWandererB = aWandererB + ((((RotL64(aCross, 19U) + RotL64(aOrbiterJ, 43U)) + aOrbiterG) + RotL64(aCarry, 19U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 11U) + aOrbiterA) + RotL64(aOrbiterD, 35U));
            aWandererG = aWandererG + ((RotL64(aPrevious, 21U) + aOrbiterB) + RotL64(aOrbiterH, 52U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 34U) ^ aWandererB);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 29U));
            aCarry = aCarry + (RotL64(aWandererH, 11U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererK, 43U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererC, 37U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererG, 56U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 30797U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneA[((aIndex + 31777U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aInvestLaneB[((aIndex + 30953U)) & S_BLOCK1], 54U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27948U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 27697U)) & S_BLOCK1], 48U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 47U) ^ RotL64(aIngress, 11U)) + (RotL64(aCarry, 60U) + RotL64(aPrevious, 29U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterA = ((aWandererK + RotL64(aCross, 29U)) + RotL64(aCarry, 13U)) + 785861751704720606U;
            aOrbiterC = (aWandererG + RotL64(aPrevious, 35U)) + 15968088718435606299U;
            aOrbiterB = (((aWandererD + RotL64(aIngress, 24U)) + RotL64(aCarry, 41U)) + 1393976526590347151U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterG = ((aWandererF + RotL64(aScatter, 43U)) + RotL64(aCarry, 53U)) + 17240750947292745884U;
            aOrbiterJ = (aWandererB + RotL64(aCross, 21U)) + 4921576136163183137U;
            aOrbiterI = (aWandererE + RotL64(aScatter, 3U)) + 3334047873553153032U;
            aOrbiterF = (aWandererJ + RotL64(aIngress, 53U)) + 15086509978458408698U;
            aOrbiterD = (aWandererI + RotL64(aPrevious, 6U)) + 892391205397581998U;
            aOrbiterH = ((aWandererC + RotL64(aIngress, 27U)) + 2965686403183767521U) + aPhaseFOrbiterAssignSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = (aWandererH + RotL64(aPrevious, 41U)) + 14632215393655706170U;
            aOrbiterK = (aWandererA + RotL64(aCross, 11U)) + 15740589515342377322U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 11131164813943086445U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 6988080581278900960U;
            aOrbiterB = RotL64((aOrbiterB * 6412189142344044255U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 16021254613117657178U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 6183615599897921154U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9976411093264211033U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 12533992547026652747U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 3104325358982904219U;
            aOrbiterI = RotL64((aOrbiterI * 14977348108778147265U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 3878525937957474644U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 2120435259884368445U;
            aOrbiterJ = RotL64((aOrbiterJ * 15964718652193073177U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 14928658302694194856U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 9121310461310309348U;
            aOrbiterH = RotL64((aOrbiterH * 17304439784647477491U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 3715693239100476493U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 7336577492932262490U;
            aOrbiterE = RotL64((aOrbiterE * 11074754160002665253U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 2312452827448455675U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 4322756069651934618U;
            aOrbiterG = RotL64((aOrbiterG * 6908893297397073539U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 4962079617577705818U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 5072727464750706525U;
            aOrbiterK = RotL64((aOrbiterK * 4947670001221089155U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 4553791875259778686U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 15823770920225774233U;
            aOrbiterD = RotL64((aOrbiterD * 409663191536830375U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 9468608484284459072U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 8658861660659699947U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2933359123761406353U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 14453429515273506170U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 785861751704720606U;
            aOrbiterA = RotL64((aOrbiterA * 3544627380583668815U), 47U);
            //
            aIngress = RotL64(aOrbiterB, 43U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 5U));
            aIngress = aIngress + (RotL64(aOrbiterG, 53U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterH, 13U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 37U));
            aIngress = aIngress + RotL64(aOrbiterC, 56U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aIngress, 42U) + aOrbiterG) + RotL64(aOrbiterK, 51U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterJ, 13U)) + aOrbiterI);
            aWandererB = aWandererB + (((RotL64(aCross, 47U) + RotL64(aOrbiterE, 22U)) + aOrbiterB) + aPhaseFWandererUpdateSaltE[((aIndex + 7U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 27U) + RotL64(aOrbiterC, 53U)) + aOrbiterE) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aCross, 13U) + RotL64(aOrbiterH, 43U)) + aOrbiterC);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 58U) + aOrbiterJ) + RotL64(aOrbiterF, 57U));
            aWandererC = aWandererC + (((RotL64(aIngress, 23U) + RotL64(aOrbiterE, 29U)) + aOrbiterD) + RotL64(aCarry, 13U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 11U) + aOrbiterG) + RotL64(aOrbiterI, 34U));
            aWandererI = aWandererI + ((RotL64(aCross, 37U) + RotL64(aOrbiterJ, 11U)) + aOrbiterA);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 21U) + aOrbiterI) + RotL64(aOrbiterH, 47U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 39U) + RotL64(aOrbiterA, 3U)) + aOrbiterB) + RotL64(aCarry, 19U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 48U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererK, 37U) ^ aWandererD);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 51U));
            aCarry = aCarry + (RotL64(aWandererC, 13U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererF, 23U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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

void TwistExpander_BasketBall_Arx::GROW_A(TwistWorkSpace *pWorkSpace,
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

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterD = 0; std::uint64_t aOrbiterE = 0;
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 3818U)) & S_BLOCK1], 48U) ^ RotL64(aWorkLaneB[((aIndex + 6103U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aInvestLaneA[((aIndex + 3924U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 916U)) & S_BLOCK1], 50U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 2201U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 3452U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aIngress, 53U)) + (RotL64(aPrevious, 37U) ^ RotL64(aCarry, 18U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterE = ((aWandererK + RotL64(aCross, 11U)) + 701291026547470433U) + aPhaseGOrbiterAssignSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterI = ((aWandererF + RotL64(aIngress, 39U)) + RotL64(aCarry, 5U)) + 17283292650462111643U;
            aOrbiterF = ((aWandererB + RotL64(aPrevious, 27U)) + RotL64(aCarry, 53U)) + 9969124091931303406U;
            aOrbiterD = (((aWandererC + RotL64(aScatter, 3U)) + RotL64(aCarry, 21U)) + 889176772718046988U) + aPhaseGOrbiterAssignSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = (aWandererE + RotL64(aCross, 50U)) + 6054541844643748084U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 14703226235143028132U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 7977975878522921062U) ^ aPhaseGOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 9030855800028448469U), 39U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 16894322614172266274U) + aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 12160451749345900570U;
            aOrbiterE = RotL64((aOrbiterE * 18055355572903901749U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 10870847008043897470U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 8159920947172520247U;
            aOrbiterH = RotL64((aOrbiterH * 4833194641611011805U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 2440099120969517932U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 2428396147731468007U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9363073341539598441U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 2213226274394673479U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 7079731443427765333U;
            aOrbiterI = RotL64((aOrbiterI * 16918930776877030559U), 57U);
            //
            aIngress = RotL64(aOrbiterF, 6U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterE, 57U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterD, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 21U) + aOrbiterD) + RotL64(aOrbiterE, 10U));
            aWandererC = aWandererC + (((RotL64(aCross, 3U) + aOrbiterH) + RotL64(aOrbiterI, 53U)) + RotL64(aCarry, 13U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 13U) + aOrbiterD) + RotL64(aOrbiterI, 39U)) + aPhaseGWandererUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aScatter, 53U) + aOrbiterI) + RotL64(aOrbiterF, 19U)) + RotL64(aCarry, 35U)) + aPhaseGWandererUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 44U) + aOrbiterE) + RotL64(aOrbiterF, 27U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 27U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 35U));
            aCarry = aCarry + RotL64(aWandererK, 47U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 13921U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneC[((aIndex + 10290U)) & S_BLOCK1], 58U));
            aIngress ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 14492U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 12643U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 13780U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aOperationLaneB[((aIndex + 8725U)) & S_BLOCK1], 48U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 23U) + RotL64(aPrevious, 38U)) ^ (RotL64(aIngress, 53U) ^ RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterA = (aWandererH + RotL64(aPrevious, 11U)) + 4068921616130916949U;
            aOrbiterB = ((aWandererF + RotL64(aIngress, 58U)) + RotL64(aCarry, 29U)) + 12077715273915151726U;
            aOrbiterK = (aWandererK + RotL64(aCross, 29U)) + 16047546802670596833U;
            aOrbiterI = (((aWandererD + RotL64(aScatter, 39U)) + RotL64(aCarry, 3U)) + 9690277462716999763U) + aPhaseGOrbiterAssignSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = (((aWandererE + RotL64(aPrevious, 3U)) + RotL64(aCarry, 41U)) + 14484814700447992628U) + aPhaseGOrbiterAssignSaltD[((aIndex + 15U)) & S_SALT1];
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 17089267243053958210U) + aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 9138746214446211147U;
            aOrbiterK = RotL64((aOrbiterK * 8244950097712975043U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 10181001536979097045U) + aPhaseGOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 6657458969093373191U) ^ aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 4311019792293202747U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 7515983477876590988U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 3039935555863947600U;
            aOrbiterB = RotL64((aOrbiterB * 12511160550780270119U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 16209389224740851136U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 725253312098083182U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 17535989492095522597U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 13307041115748941383U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 7159572004825238263U;
            aOrbiterI = RotL64((aOrbiterI * 4855009895002398449U), 13U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterB, 3U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 13U));
            aIngress = aIngress + RotL64(aOrbiterK, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 27U) + aOrbiterI) + RotL64(aOrbiterK, 5U));
            aWandererF = aWandererF + ((((RotL64(aCross, 19U) + aOrbiterD) + RotL64(aOrbiterK, 27U)) + RotL64(aCarry, 29U)) + aPhaseGWandererUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 35U) + aOrbiterB) + RotL64(aOrbiterI, 57U));
            aWandererE = aWandererE + ((((RotL64(aIngress, 10U) + aOrbiterA) + RotL64(aOrbiterB, 44U)) + RotL64(aCarry, 57U)) + aPhaseGWandererUpdateSaltF[((aIndex + 25U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 51U) + aOrbiterD) + RotL64(aOrbiterA, 13U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 51U));
            aCarry = aCarry + (RotL64(aWandererK, 60U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererD, 13U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 18564U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneD[((aIndex + 17941U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 18781U)) & S_BLOCK1], 30U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 18036U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 19170U)) & S_BLOCK1], 22U));
            aCross ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 17981U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCross, 57U)) + (RotL64(aIngress, 20U) + RotL64(aCarry, 37U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterH = ((aWandererJ + RotL64(aCross, 29U)) + 2974056819475622600U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = ((aWandererA + RotL64(aIngress, 13U)) + RotL64(aCarry, 21U)) + 7345051759236356098U;
            aOrbiterG = ((aWandererG + RotL64(aPrevious, 40U)) + RotL64(aCarry, 5U)) + 12738468816846628882U;
            aOrbiterI = (((aWandererD + RotL64(aScatter, 21U)) + RotL64(aCarry, 39U)) + 7694520596043297922U) + aPhaseGOrbiterAssignSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterK = (aWandererK + RotL64(aCross, 51U)) + 5530753590015084774U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 3776309161718383105U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 784780304358106404U;
            aOrbiterG = RotL64((aOrbiterG * 1503119308251871519U), 39U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 8999942326995036509U) + aPhaseGOrbiterUpdateSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 5194986506064092779U;
            aOrbiterK = RotL64((aOrbiterK * 15070787038006135963U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 7920040007459652762U) + aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 11311997270710107937U;
            aOrbiterI = RotL64((aOrbiterI * 6227571709361790209U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 5365231114813547251U) + aPhaseGOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 8630110234623825263U;
            aOrbiterJ = RotL64((aOrbiterJ * 2735881715888325759U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 2358235238039571072U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 18059414891616491807U;
            aOrbiterH = RotL64((aOrbiterH * 17150786106857185467U), 47U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterJ, 53U);
            aIngress = aIngress + (RotL64(aOrbiterI, 39U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterH, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterH, 11U)) + aOrbiterJ);
            aWandererA = aWandererA + (((RotL64(aPrevious, 35U) + aOrbiterI) + RotL64(aOrbiterG, 58U)) + RotL64(aCarry, 35U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 3U) + aOrbiterK) + RotL64(aOrbiterI, 3U));
            aWandererD = aWandererD + ((((RotL64(aScatter, 58U) + aOrbiterG) + RotL64(aOrbiterK, 43U)) + RotL64(aCarry, 11U)) + aPhaseGWandererUpdateSaltD[((aIndex + 14U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 19U) + aOrbiterG) + RotL64(aOrbiterJ, 29U)) + aPhaseGWandererUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 21U) ^ aWandererG);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 41U));
            aCarry = aCarry + RotL64(aWandererA, 11U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 28672U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneA[((aIndex + 32014U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aInvestLaneD[((aIndex + 25031U)) & S_BLOCK1], 12U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29201U)) & S_BLOCK1], 26U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 31982U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 26334U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 11U) + RotL64(aPrevious, 27U)) ^ (RotL64(aCarry, 60U) + RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterE = ((aWandererE + RotL64(aPrevious, 57U)) + RotL64(aCarry, 11U)) + 16124889768301047791U;
            aOrbiterF = (((aWandererD + RotL64(aCross, 18U)) + RotL64(aCarry, 35U)) + 11912338587186717280U) + aPhaseGOrbiterAssignSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterA = (aWandererK + RotL64(aIngress, 37U)) + 8594012868813114354U;
            aOrbiterK = (((aWandererH + RotL64(aScatter, 27U)) + RotL64(aCarry, 23U)) + 18281043566156682815U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterH = (aWandererB + RotL64(aIngress, 5U)) + 16853106130200942302U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 2611212958619673086U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 18039472325066855180U;
            aOrbiterA = RotL64((aOrbiterA * 10213999643376367785U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 14495785571345122046U) + aPhaseGOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 4556063793412832418U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 13166927543135467627U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 14896419970271244358U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 880028529183500036U;
            aOrbiterK = RotL64((aOrbiterK * 14228281807461251361U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 2379557167489415783U) + aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 11854373946064529806U;
            aOrbiterF = RotL64((aOrbiterF * 150755294320438887U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 1487252775956449964U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 12777924204511625545U) ^ aPhaseGOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 1366019527386994789U), 27U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterF, 37U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 24U));
            aIngress = aIngress + RotL64(aOrbiterE, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterA, 48U)) + aOrbiterK) + aPhaseGWandererUpdateSaltA[((aIndex + 21U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 37U) + RotL64(aOrbiterF, 3U)) + aOrbiterH) + RotL64(aCarry, 11U)) + aPhaseGWandererUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 56U) + aOrbiterA) + RotL64(aOrbiterF, 23U));
            aWandererE = aWandererE + (((RotL64(aIngress, 21U) + RotL64(aOrbiterE, 13U)) + aOrbiterF) + RotL64(aCarry, 37U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 29U) + aOrbiterH) + RotL64(aOrbiterK, 35U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 43U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 53U));
            aCarry = aCarry + RotL64(aWandererB, 11U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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

void TwistExpander_BasketBall_Arx::GROW_B(TwistWorkSpace *pWorkSpace,
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 5560U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneB[((aIndex + 7379U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 842U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4461U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 3062U)) & S_BLOCK1], 53U));
            aCross ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 7431U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aPrevious, 39U)) ^ (RotL64(aIngress, 53U) ^ RotL64(aCross, 22U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterF = ((aWandererD + RotL64(aPrevious, 11U)) + RotL64(aCarry, 53U)) + 17470880031634374199U;
            aOrbiterH = ((aWandererB + RotL64(aIngress, 3U)) + RotL64(aCarry, 41U)) + 757565846006937746U;
            aOrbiterC = ((aWandererF + RotL64(aScatter, 37U)) + RotL64(aCarry, 23U)) + 9419282475801345674U;
            aOrbiterG = ((aWandererI + RotL64(aCross, 19U)) + 2014248014107898196U) + aPhaseHOrbiterAssignSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = ((aWandererA + RotL64(aIngress, 54U)) + 15113928519446490441U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 7346126964886259935U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 5594123113093162359U;
            aOrbiterC = RotL64((aOrbiterC * 18043634828891483403U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 5659237263369402005U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 11565709683423969703U;
            aOrbiterG = RotL64((aOrbiterG * 16731289017588574671U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 16782863743534856287U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 13499100900072115907U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5567729598873214433U), 21U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 11414447651044205242U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 7545993795121430538U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 10758488381206257261U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 11778229237616454988U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 2544793391976514665U;
            aOrbiterF = RotL64((aOrbiterF * 4021060413798523299U), 3U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterC, 19U);
            aIngress = aIngress + (RotL64(aOrbiterI, 6U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterH, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aPrevious, 57U) + RotL64(aOrbiterG, 26U)) + aOrbiterH) + RotL64(aCarry, 39U)) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 14U) + RotL64(aOrbiterG, 3U)) + aOrbiterF);
            aWandererB = aWandererB + (((RotL64(aCross, 23U) + RotL64(aOrbiterG, 51U)) + aOrbiterC) + RotL64(aCarry, 19U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterC, 11U)) + aOrbiterI);
            aWandererF = aWandererF + (((RotL64(aPrevious, 47U) + aOrbiterF) + RotL64(aOrbiterI, 37U)) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 47U) ^ aWandererF);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 19U));
            aCarry = aCarry + RotL64(aWandererI, 3U);
            aCarry = aCarry + RotL64(aIngress, 56U);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 15653U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneC[((aIndex + 12596U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aInvestLaneB[((aIndex + 14763U)) & S_BLOCK1], 28U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 13913U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 13585U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aOperationLaneB[((aIndex + 12306U)) & S_BLOCK1], 54U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 50U) + RotL64(aIngress, 37U)) ^ (RotL64(aCross, 5U) + RotL64(aPrevious, 19U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterG = (((aWandererJ + RotL64(aScatter, 12U)) + RotL64(aCarry, 13U)) + 12980104182836602177U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterK = (((aWandererH + RotL64(aIngress, 41U)) + RotL64(aCarry, 27U)) + 3172622203188863995U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = (aWandererA + RotL64(aPrevious, 53U)) + 1170974132219980203U;
            aOrbiterB = (aWandererC + RotL64(aCross, 29U)) + 6035201940965047490U;
            aOrbiterI = ((aWandererD + RotL64(aPrevious, 3U)) + RotL64(aCarry, 43U)) + 18033907118424996722U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 14604813424800580304U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 13720232492851066035U;
            aOrbiterJ = RotL64((aOrbiterJ * 8927246214721284759U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 3902659710585257448U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 8331560652661619868U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11418103770615560205U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 4485014147538689794U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 168202636924512424U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 13711020666131492091U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 16227825670092707848U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 4792781933944671365U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 15859849676231455283U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 12636865372722601282U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 18198291399585556632U;
            aOrbiterG = RotL64((aOrbiterG * 18155803890313399795U), 23U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterI, 35U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 13U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterK, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aCross, 35U) + RotL64(aOrbiterB, 47U)) + aOrbiterJ) + RotL64(aCarry, 13U)) + aPhaseHWandererUpdateSaltF[((aIndex + 18U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 14U) + RotL64(aOrbiterI, 5U)) + aOrbiterK) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aScatter, 3U) + RotL64(aOrbiterG, 27U)) + aOrbiterB) + RotL64(aCarry, 53U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterI, 19U)) + aOrbiterJ);
            aWandererA = aWandererA + ((RotL64(aScatter, 57U) + RotL64(aOrbiterK, 38U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererH, 43U) ^ aWandererJ);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 13U));
            aCarry = aCarry + RotL64(aWandererC, 35U);
            aCarry = aCarry + RotL64(aIngress, 52U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 23564U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneD[((aIndex + 21237U)) & S_BLOCK1], 22U));
            aIngress ^= RotL64(aInvestLaneC[((aIndex + 17183U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21205U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 19062U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aOperationLaneC[((aIndex + 24324U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 57U)) ^ (RotL64(aCross, 34U) + RotL64(aIngress, 19U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterJ = (((aWandererG + RotL64(aScatter, 29U)) + RotL64(aCarry, 37U)) + 6024062041314952357U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterD = ((aWandererD + RotL64(aIngress, 56U)) + RotL64(aCarry, 5U)) + 18340757093658015585U;
            aOrbiterA = (((aWandererI + RotL64(aCross, 19U)) + RotL64(aCarry, 53U)) + 11911120493880346751U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterK = (aWandererK + RotL64(aPrevious, 41U)) + 17428074353884654439U;
            aOrbiterH = (aWandererA + RotL64(aCross, 5U)) + 12790849760814795936U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 12633397052172117800U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 11946150433665237945U;
            aOrbiterA = RotL64((aOrbiterA * 10324089534873171291U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 16842157900909419285U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 14186235783224155962U;
            aOrbiterJ = RotL64((aOrbiterJ * 10521157787073684417U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 13284904542579767591U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 11609181965078844357U;
            aOrbiterD = RotL64((aOrbiterD * 5455780554452453513U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 9628562297095374984U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 7850281529011259759U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 17611485102925470357U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 257458718073794527U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 10693404545773519306U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 14821443722828498323U), 43U);
            //
            aIngress = RotL64(aOrbiterK, 23U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterD, 35U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterJ, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aScatter, 47U) + RotL64(aOrbiterD, 21U)) + aOrbiterJ) + aPhaseHWandererUpdateSaltC[((aIndex + 20U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterK, 13U)) + aOrbiterA);
            aWandererD = aWandererD + (((RotL64(aIngress, 57U) + RotL64(aOrbiterH, 5U)) + aOrbiterK) + RotL64(aCarry, 27U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 37U) + aOrbiterD) + RotL64(aOrbiterA, 41U));
            aWandererA = aWandererA + ((((RotL64(aScatter, 4U) + RotL64(aOrbiterH, 52U)) + aOrbiterA) + RotL64(aCarry, 5U)) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 27U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 43U));
            aCarry = aCarry + RotL64(aWandererD, 13U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 28995U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneA[((aIndex + 28240U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aInvestLaneD[((aIndex + 28824U)) & S_BLOCK1], 4U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 31723U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 32116U)) & S_BLOCK1], 46U));
            aCross ^= RotL64(aOperationLaneD[((aIndex + 29720U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 41U) ^ RotL64(aPrevious, 27U)) ^ (RotL64(aIngress, 14U) + RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterI = ((aWandererE + RotL64(aIngress, 18U)) + RotL64(aCarry, 13U)) + 11521331427196538632U;
            aOrbiterA = ((aWandererC + RotL64(aPrevious, 53U)) + 16653824187682957632U) + aPhaseHOrbiterAssignSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = ((aWandererA + RotL64(aScatter, 27U)) + RotL64(aCarry, 41U)) + 11654676587350088289U;
            aOrbiterG = (((aWandererK + RotL64(aCross, 3U)) + RotL64(aCarry, 53U)) + 8010313317412193584U) + aPhaseHOrbiterAssignSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterB = (aWandererG + RotL64(aScatter, 43U)) + 1108775560502907471U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 243952321439823521U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 2324945800401240403U;
            aOrbiterJ = RotL64((aOrbiterJ * 9471328582043504473U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 9257554497543369657U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 16701314607244592540U;
            aOrbiterG = RotL64((aOrbiterG * 8790054741039817107U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 3900445848034341782U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 7652316487347103658U;
            aOrbiterA = RotL64((aOrbiterA * 11480123491361589799U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 14980368605272070578U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 2001165460948764796U;
            aOrbiterI = RotL64((aOrbiterI * 8110980921827107649U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 1911044015666991050U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 11366207111147818339U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 17234439040652553865U), 27U);
            //
            aIngress = RotL64(aOrbiterI, 3U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterG, 23U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterJ, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aCross, 3U) + aOrbiterA) + RotL64(aOrbiterB, 19U)) + aPhaseHWandererUpdateSaltA[((aIndex + 15U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterJ, 47U)) + aOrbiterG) + RotL64(aCarry, 35U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterA, 27U)) + aOrbiterJ);
            aWandererK = aWandererK + ((((RotL64(aIngress, 41U) + aOrbiterA) + RotL64(aOrbiterI, 6U)) + RotL64(aCarry, 57U)) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 30U) + aOrbiterG) + RotL64(aOrbiterA, 37U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + (RotL64(aWandererA, 19U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererK, 58U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
