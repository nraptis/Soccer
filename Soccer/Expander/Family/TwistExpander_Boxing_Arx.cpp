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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x903D9512ED73E411ULL + 0x85CADDCF707881F1ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xA97148D863612847ULL + 0xD61E4E75C55B5753ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xA5E582BA17DDB89FULL + 0xAA112538F392AC67ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xEE08B6108626F01BULL + 0xBAB4BE85B423DF5BULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xC69FA7DA46692F25ULL + 0xD61E5A12CDF6EBF5ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x97460DF727F9492DULL + 0xA50FFCE4E4587126ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xFF11F70FE0AD5687ULL + 0xC5D96B9BCE323DF2ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x81D5D92A5C066A55ULL + 0x9B79355CDDCFEC81ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xA6F7A54DCE2563F3ULL + 0x8A345A76A5798FEBULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0x8C63AC8DB939DFF3ULL + 0xD2DE218200BE6896ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xDA3DBFAA0D54FD67ULL + 0x8BF36A5A0ECB77F1ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xA44A0E7F2340F043ULL + 0x91D75DDD84F12A0BULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xFBD160F5A164E969ULL + 0xEC1DD58A388236C2ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xBC66089E844B7F05ULL + 0xB2AB5648F88E140EULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xE317ABCBF8F9DB09ULL + 0xF40548049CEFF12CULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xA316F293690261CFULL + 0xAB790AEE8575624AULL);
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
            aIngress = RotL64(mSource[((aIndex + 2521U)) & S_BLOCK1], 13U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 3437U)) & S_BLOCK1], 46U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(pSnow[((S_BLOCK1 - aIndex + 4707U)) & S_BLOCK1], 28U) ^ RotL64(mSource[((aIndex + 2709U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aPrevious, 27U) ^ RotL64(aCarry, 54U)) ^ (RotL64(aIngress, 39U) + RotL64(aCross, 11U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterD = ((aWandererK + RotL64(aIngress, 57U)) + 10336802574069791273U) + aNonceWordN;
            aOrbiterJ = (aWandererG + RotL64(aPrevious, 50U)) + 169025388197058936U;
            aOrbiterF = ((aWandererJ + RotL64(aCross, 37U)) + 6541354188379168846U) + aNonceWordG;
            aOrbiterK = ((((aWandererB + RotL64(aScatter, 41U)) + RotL64(aCarry, 27U)) + 16223920526599306104U) + aOrbiterAssignSaltF[((aIndex + 22U)) & S_SALT1]) + aNonceWordP;
            aOrbiterG = ((aWandererE + RotL64(aCross, 5U)) + RotL64(aCarry, 11U)) + 12756613707692514808U;
            aOrbiterC = (aWandererC + RotL64(aPrevious, 23U)) + 5082475548176484035U;
            aOrbiterB = ((aWandererH + RotL64(aScatter, 3U)) + 4907435526952698526U) + aNonceWordO;
            aOrbiterH = (aWandererF + RotL64(aIngress, 11U)) + 14236627073831834337U;
            aOrbiterI = (((aWandererD + RotL64(aPrevious, 44U)) + RotL64(aCarry, 3U)) + 11502511046130497584U) + aOrbiterAssignSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterE = (aWandererA + RotL64(aScatter, 47U)) + 3679044835550219497U;
            aOrbiterA = (aWandererI + RotL64(aCross, 13U)) + 11254838916686736746U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 10582608424233200966U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 10449735026385340313U;
            aOrbiterF = RotL64((aOrbiterF * 7363770199734997411U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 4628253464169957835U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 17664454668473204465U;
            aOrbiterD = RotL64((aOrbiterD * 4234720298731378527U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 3798386391743884889U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 1379331161819246587U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 13086160171095077295U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 9816600392407327227U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 16781971616348376878U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12503867584828289879U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 4807797577690520554U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 2492057261148595922U;
            aOrbiterC = RotL64((aOrbiterC * 9453302540675483005U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 7909676419643119585U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 256053568910383007U;
            aOrbiterK = RotL64((aOrbiterK * 11965085163352053161U), 53U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 16179914439220412472U) + aNonceWordJ;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 3968867762761955845U;
            aOrbiterE = RotL64((aOrbiterE * 7473632378251893139U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 7474832923901283742U) + aNonceWordD;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 4736994731050735779U) ^ aNonceWordL;
            aOrbiterJ = RotL64((aOrbiterJ * 9839654409121414047U), 37U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 596484364660389193U) + aOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 13822222274464306169U;
            aOrbiterH = RotL64((aOrbiterH * 1723502278319885511U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 16307920280681985443U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 3505106171801702915U;
            aOrbiterG = RotL64((aOrbiterG * 8479675421552861243U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 4987142580981135150U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 10336802574069791273U) ^ aNonceWordC;
            aOrbiterA = RotL64((aOrbiterA * 2670706512498539705U), 11U);
            //
            aIngress = RotL64(aOrbiterI, 39U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 18U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 41U));
            aIngress = aIngress + (RotL64(aOrbiterF, 43U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 21U));
            aIngress = aIngress + RotL64(aOrbiterJ, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aScatter, 60U) + aOrbiterJ) + RotL64(aOrbiterB, 26U)) + aNonceWordA);
            aWandererH = aWandererH + ((RotL64(aPrevious, 23U) + aOrbiterG) + RotL64(aOrbiterC, 53U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterI, 37U)) + aOrbiterF) + aWandererUpdateSaltF[((aIndex + 18U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aCross, 5U) + aOrbiterG) + RotL64(aOrbiterA, 41U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterC, 3U)) + aOrbiterF);
            aWandererK = aWandererK + (((RotL64(aScatter, 41U) + aOrbiterH) + RotL64(aOrbiterI, 29U)) + RotL64(aCarry, 5U));
            aWandererC = aWandererC ^ ((((RotL64(aIngress, 10U) + RotL64(aOrbiterF, 13U)) + aOrbiterE) + aNonceWordE) + aWandererUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 3U) + RotL64(aOrbiterF, 6U)) + aOrbiterD) + RotL64(aCarry, 13U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 27U) + aOrbiterE) + RotL64(aOrbiterG, 19U)) + aNonceWordI);
            aWandererF = aWandererF + ((RotL64(aScatter, 19U) + RotL64(aOrbiterD, 43U)) + aOrbiterB);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterH, 11U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 39U));
            aCarry = aCarry + (RotL64(aWandererJ, 37U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererI, 54U) ^ aWandererD);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 21U));
            aCarry = aCarry + (RotL64(aWandererF, 43U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererE, 11U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 7684U)) & S_BLOCK1], 23U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 9669U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 8512U)) & S_BLOCK1], 60U) ^ RotL64(pSnow[((aIndex + 7170U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCross, 40U) + RotL64(aPrevious, 13U)) ^ (RotL64(aIngress, 27U) + RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterC = (aWandererH + RotL64(aIngress, 39U)) + 16189787374324972735U;
            aOrbiterB = ((aWandererK + RotL64(aPrevious, 13U)) + 17563763730956242224U) + aNonceWordO;
            aOrbiterJ = (aWandererB + RotL64(aScatter, 35U)) + 10572803498593789385U;
            aOrbiterE = (aWandererE + RotL64(aCross, 21U)) + 7713105232072974166U;
            aOrbiterA = ((aWandererI + RotL64(aScatter, 60U)) + RotL64(aCarry, 57U)) + 10760839534772718139U;
            aOrbiterK = ((aWandererJ + RotL64(aPrevious, 23U)) + RotL64(aCarry, 27U)) + 13397069448391230253U;
            aOrbiterF = ((aWandererC + RotL64(aCross, 47U)) + 4569255679998375682U) + aNonceWordC;
            aOrbiterG = (((aWandererF + RotL64(aIngress, 19U)) + 9888769350817876949U) + aOrbiterAssignSaltE[((aIndex + 3U)) & S_SALT1]) + aNonceWordH;
            aOrbiterH = ((aWandererG + RotL64(aCross, 52U)) + 11351796060878856300U) + aOrbiterAssignSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterD = ((aWandererD + RotL64(aIngress, 27U)) + RotL64(aCarry, 5U)) + 18153775071965707204U;
            aOrbiterI = ((aWandererA + RotL64(aPrevious, 29U)) + 1282846411145853435U) + aNonceWordJ;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 16457743979262460660U) + aNonceWordL;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 173493260775251032U) ^ aNonceWordN;
            aOrbiterJ = RotL64((aOrbiterJ * 4935807229040883505U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 3927345926316409630U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 5158769729850853623U;
            aOrbiterK = RotL64((aOrbiterK * 2446452358663812945U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 12331351600010165154U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 3940794200348684050U;
            aOrbiterE = RotL64((aOrbiterE * 13248997263062075043U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 11248514843822945425U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 1391497323278226522U) ^ aOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8376841806072565005U), 39U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 13265623528678787307U) + aOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 2802033745265647317U;
            aOrbiterD = RotL64((aOrbiterD * 3437626962562016147U), 37U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 6938444301018051844U) + aOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 1086544666755559028U;
            aOrbiterG = RotL64((aOrbiterG * 16039728388882079889U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 16156443117365816536U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 3619942859562697142U;
            aOrbiterI = RotL64((aOrbiterI * 7589346043159112151U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 17681848914912743292U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 8848238631758130416U;
            aOrbiterB = RotL64((aOrbiterB * 810402256099500607U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 6019192027793541890U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 16917288363166352778U) ^ aOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 17673667086593738207U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 5598218150530046752U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 17285995539011279010U;
            aOrbiterC = RotL64((aOrbiterC * 15621233176885995065U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 12380627610747299268U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 16189787374324972735U;
            aOrbiterA = RotL64((aOrbiterA * 2144714828503219209U), 43U);
            //
            aIngress = RotL64(aOrbiterD, 13U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterA, 21U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 35U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 53U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 19U));
            aIngress = aIngress + RotL64(aOrbiterH, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterF, 57U)) + aOrbiterH) + RotL64(aCarry, 41U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterA, 13U)) + aOrbiterH);
            aWandererD = aWandererD + ((((RotL64(aCross, 44U) + RotL64(aOrbiterK, 60U)) + aOrbiterE) + aNonceWordE) + aWandererUpdateSaltA[((aIndex + 9U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 53U) + RotL64(aOrbiterA, 35U)) + aOrbiterC) + aNonceWordA);
            aWandererB = aWandererB + (((RotL64(aCross, 41U) + aOrbiterK) + RotL64(aOrbiterD, 29U)) + RotL64(aCarry, 37U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterG, 3U)) + aOrbiterD);
            aWandererI = aWandererI + ((RotL64(aIngress, 30U) + RotL64(aOrbiterA, 37U)) + aOrbiterI);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 13U) + aOrbiterD) + RotL64(aOrbiterC, 41U));
            aWandererJ = aWandererJ + ((RotL64(aCross, 19U) + aOrbiterA) + RotL64(aOrbiterB, 18U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 21U) + aOrbiterH) + RotL64(aOrbiterE, 27U)) + aWandererUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aPrevious, 39U) + RotL64(aOrbiterK, 39U)) + aOrbiterJ) + aNonceWordP);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 19U));
            aCarry = aCarry + (RotL64(aWandererI, 14U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererD, 57U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererJ, 23U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererB, 35U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererE, 54U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = RotL64(aWorkLaneB[((aIndex + 12078U)) & S_BLOCK1], 22U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 13896U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(pSnow[((S_BLOCK1 - aIndex + 11294U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneA[((aIndex + 13484U)) & S_BLOCK1], 48U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCarry, 53U)) + (RotL64(aCross, 40U) + RotL64(aPrevious, 27U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterA = (aWandererI + RotL64(aPrevious, 43U)) + 5131645209694953015U;
            aOrbiterC = (aWandererG + RotL64(aScatter, 19U)) + 12070391048835379854U;
            aOrbiterE = ((aWandererE + RotL64(aIngress, 11U)) + 2604295836242338724U) + aOrbiterAssignSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterF = (aWandererA + RotL64(aCross, 48U)) + 14042039029284001596U;
            aOrbiterK = (aWandererF + RotL64(aScatter, 23U)) + 8914654543854559327U;
            aOrbiterD = ((aWandererJ + RotL64(aPrevious, 5U)) + RotL64(aCarry, 41U)) + 2185619407969359869U;
            aOrbiterG = (aWandererH + RotL64(aIngress, 51U)) + 5187406295103352574U;
            aOrbiterJ = ((aWandererK + RotL64(aCross, 37U)) + RotL64(aCarry, 23U)) + 8022832481290871217U;
            aOrbiterB = ((aWandererD + RotL64(aScatter, 27U)) + RotL64(aCarry, 11U)) + 8783061916740573472U;
            aOrbiterI = ((aWandererB + RotL64(aPrevious, 29U)) + 10711028365596196301U) + aNonceWordA;
            aOrbiterH = (((aWandererC + RotL64(aCross, 14U)) + 13387065038269133571U) + aOrbiterAssignSaltD[((aIndex + 18U)) & S_SALT1]) + aNonceWordF;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 11187001318931801582U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 14191473173276034019U;
            aOrbiterE = RotL64((aOrbiterE * 2491253922434756431U), 11U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterK) + 16207761776716426435U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordL;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 9677408414452078760U) ^ aNonceWordI;
            aOrbiterA = RotL64((aOrbiterA * 5487303383095129949U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 17812460332794370649U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 7736423148554132028U) ^ aNonceWordB;
            aOrbiterG = RotL64((aOrbiterG * 15588733747232852555U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 17293203944059014763U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 13487243633338010243U;
            aOrbiterC = RotL64((aOrbiterC * 9468688858740539095U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 15979293016815060755U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 17645215484691359547U;
            aOrbiterJ = RotL64((aOrbiterJ * 1449450767288733995U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 11635961468586927692U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 10530136578329059784U;
            aOrbiterI = RotL64((aOrbiterI * 8785021493374398437U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 4900370530116992731U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 15952900504821599445U;
            aOrbiterH = RotL64((aOrbiterH * 5413316082800365261U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 9938000151832814778U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 14170277411106520726U) ^ aOrbiterUpdateSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 5058343552974910737U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 14091010427448547620U) + aNonceWordG;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 13658560822164111421U;
            aOrbiterB = RotL64((aOrbiterB * 9523184040517290629U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 13954269172267844623U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 3921811946419945868U;
            aOrbiterF = RotL64((aOrbiterF * 6839440867046147039U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 14296483810577739898U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 5131645209694953015U;
            aOrbiterK = RotL64((aOrbiterK * 10190969526209064367U), 47U);
            //
            aIngress = RotL64(aOrbiterA, 58U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterE, 11U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 51U));
            aIngress = aIngress + (RotL64(aOrbiterD, 3U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 47U));
            aIngress = aIngress + RotL64(aOrbiterF, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aScatter, 5U) + RotL64(aOrbiterJ, 23U)) + aOrbiterF) + RotL64(aCarry, 47U)) + aWandererUpdateSaltD[((aIndex + 3U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterD, 57U)) + aOrbiterJ) + aNonceWordP);
            aWandererG = aWandererG + (((RotL64(aIngress, 30U) + RotL64(aOrbiterK, 53U)) + aOrbiterH) + aWandererUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 13U) + aOrbiterH) + RotL64(aOrbiterA, 42U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 37U) + aOrbiterE) + RotL64(aOrbiterI, 47U)) + RotL64(aCarry, 35U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterB, 29U)) + aOrbiterA);
            aWandererD = aWandererD + (((RotL64(aCross, 21U) + aOrbiterE) + RotL64(aOrbiterG, 51U)) + aNonceWordN);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 51U) + aOrbiterK) + RotL64(aOrbiterA, 11U));
            aWandererH = aWandererH + (((RotL64(aCross, 3U) + RotL64(aOrbiterK, 44U)) + aOrbiterC) + aNonceWordC);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 28U) + aOrbiterH) + RotL64(aOrbiterG, 19U)) + aNonceWordH);
            aWandererC = aWandererC + ((RotL64(aIngress, 57U) + RotL64(aOrbiterE, 3U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 26U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 21U));
            aCarry = aCarry + (RotL64(aWandererB, 37U) ^ aWandererC);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 43U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 23U));
            aCarry = aCarry + RotL64(aWandererG, 60U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 17081U)) & S_BLOCK1], 34U) ^ RotL64(aWorkLaneA[((aIndex + 21729U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 16556U)) & S_BLOCK1], 35U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 17919U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 20932U)) & S_BLOCK1], 4U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aPrevious, 47U) ^ RotL64(aCarry, 5U)) + (RotL64(aCross, 34U) + RotL64(aIngress, 19U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterJ = (aWandererH + RotL64(aPrevious, 51U)) + 16451272412693907816U;
            aOrbiterG = (aWandererF + RotL64(aScatter, 11U)) + 10099485419723255462U;
            aOrbiterD = ((aWandererI + RotL64(aCross, 3U)) + 17668900099534923192U) + aNonceWordC;
            aOrbiterB = ((aWandererE + RotL64(aIngress, 14U)) + 5497093724143181753U) + aNonceWordO;
            aOrbiterA = ((aWandererG + RotL64(aScatter, 41U)) + RotL64(aCarry, 5U)) + 10354044773550071706U;
            aOrbiterF = (aWandererA + RotL64(aCross, 39U)) + 12728258851198019099U;
            aOrbiterE = (((aWandererD + RotL64(aPrevious, 57U)) + RotL64(aCarry, 11U)) + 4144050505314242618U) + aOrbiterAssignSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = ((aWandererB + RotL64(aIngress, 60U)) + 14133805325480076530U) + aNonceWordI;
            aOrbiterK = ((aWandererJ + RotL64(aPrevious, 23U)) + 308863673210602899U) + aOrbiterAssignSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterC = (aWandererK + RotL64(aCross, 35U)) + 11741180130160569753U;
            aOrbiterH = (((aWandererC + RotL64(aIngress, 43U)) + RotL64(aCarry, 51U)) + 12926863156769180448U) + aNonceWordN;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 211920854786494259U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 13234608842479411078U;
            aOrbiterD = RotL64((aOrbiterD * 2556747209733759467U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 9164711974854618892U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 6667377062281954219U;
            aOrbiterG = RotL64((aOrbiterG * 2603737166987437649U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 4559040002406721850U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 1749875480850675109U;
            aOrbiterI = RotL64((aOrbiterI * 15822640067349481089U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 9555365165561936366U) + aNonceWordB;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 18289733999504213574U;
            aOrbiterC = RotL64((aOrbiterC * 14156217554673229429U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 8727162691639622461U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 291406782452963706U;
            aOrbiterJ = RotL64((aOrbiterJ * 8413500075082350243U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 8294911802626492257U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 15853578397277298548U;
            aOrbiterB = RotL64((aOrbiterB * 13256191781365357747U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 11535146194939658681U) + aNonceWordL;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 2177540476748375661U;
            aOrbiterA = RotL64((aOrbiterA * 15791341922007841029U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 2705306323728084136U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 17617871830709148043U;
            aOrbiterE = RotL64((aOrbiterE * 3449981219502809255U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 3699834746313613206U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 17952609181629473245U;
            aOrbiterK = RotL64((aOrbiterK * 6103160209028988839U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 8016694658897707674U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 6971251395823324489U) ^ aNonceWordM;
            aOrbiterF = RotL64((aOrbiterF * 13483776115929040277U), 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 17467528888050817915U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 16451272412693907816U) ^ aOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 13689734638238895071U), 13U);
            //
            aIngress = RotL64(aOrbiterC, 57U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 20U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 23U));
            aIngress = aIngress + (RotL64(aOrbiterG, 39U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 5U));
            aIngress = aIngress + RotL64(aOrbiterK, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aIngress, 13U) + aOrbiterJ) + RotL64(aOrbiterD, 35U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterC, 43U)) + aOrbiterE);
            aWandererA = aWandererA + ((RotL64(aCross, 36U) + aOrbiterB) + RotL64(aOrbiterA, 27U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterK, 3U)) + aOrbiterE);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 47U) + RotL64(aOrbiterA, 50U)) + aOrbiterF) + RotL64(aCarry, 43U)) + aWandererUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterC, 53U)) + aOrbiterG);
            aWandererH = aWandererH + (((RotL64(aScatter, 51U) + RotL64(aOrbiterD, 37U)) + aOrbiterF) + RotL64(aCarry, 53U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterI, 47U)) + aOrbiterH);
            aWandererE = aWandererE + ((RotL64(aScatter, 53U) + aOrbiterK) + RotL64(aOrbiterD, 39U));
            aWandererF = aWandererF ^ ((((RotL64(aPrevious, 5U) + aOrbiterH) + RotL64(aOrbiterC, 29U)) + aNonceWordK) + aWandererUpdateSaltE[((aIndex + 6U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aIngress, 18U) + aOrbiterK) + RotL64(aOrbiterA, 22U)) + aNonceWordE);
            //
            aCarry = aCarry + (RotL64(aWandererD, 46U) ^ aWandererH);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 43U));
            aCarry = aCarry + (RotL64(aWandererE, 41U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererI, 29U) ^ aWandererB);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 12U));
            aCarry = aCarry + RotL64(aWandererK, 5U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 22019U)) & S_BLOCK1], 27U) ^ RotL64(mSource[((aIndex + 24108U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(pSnow[((aIndex + 24710U)) & S_BLOCK1], 56U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23745U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 23088U)) & S_BLOCK1], 36U) ^ RotL64(aWorkLaneB[((aIndex + 25147U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCarry, 36U) ^ RotL64(aPrevious, 51U)) ^ (RotL64(aIngress, 5U) + RotL64(aCross, 19U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterG = (aWandererK + RotL64(aCross, 11U)) + 16519040829220310189U;
            aOrbiterI = ((aWandererJ + RotL64(aPrevious, 5U)) + 6888002778416941825U) + aOrbiterAssignSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = ((aWandererF + RotL64(aIngress, 26U)) + 1310832187746534025U) + aNonceWordC;
            aOrbiterF = (aWandererE + RotL64(aScatter, 39U)) + 5890888009051281674U;
            aOrbiterC = (aWandererA + RotL64(aCross, 57U)) + 5143864838362464857U;
            aOrbiterE = (aWandererH + RotL64(aPrevious, 53U)) + 15591534069452660003U;
            aOrbiterK = ((aWandererD + RotL64(aIngress, 46U)) + RotL64(aCarry, 27U)) + 1466867671765325096U;
            aOrbiterH = ((aWandererI + RotL64(aScatter, 13U)) + RotL64(aCarry, 51U)) + 13931443680107902488U;
            aOrbiterJ = ((aWandererG + RotL64(aCross, 43U)) + RotL64(aCarry, 47U)) + 15400747367673245552U;
            aOrbiterB = (aWandererC + RotL64(aPrevious, 19U)) + 2836975369734495759U;
            aOrbiterD = (((aWandererB + RotL64(aIngress, 3U)) + 2370720358274970117U) + aOrbiterAssignSaltE[((aIndex + 5U)) & S_SALT1]) + aNonceWordL;
            //
            aOrbiterG = (((aOrbiterG + aOrbiterI) + 3470677184188006133U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordF;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 7175584278499266723U;
            aOrbiterA = RotL64((aOrbiterA * 10067096593682482345U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 6095078817776863055U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterF) ^ 2176637999243513070U) ^ aOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterC = RotL64((aOrbiterC * 12215701810843975501U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 5580391239754903129U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 15196125567953871184U;
            aOrbiterK = RotL64((aOrbiterK * 12686361960729564519U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 12787014151503209931U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 1523153207064063495U;
            aOrbiterG = RotL64((aOrbiterG * 3113907543551927561U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 12973289026485937829U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 9087439766232078173U;
            aOrbiterE = RotL64((aOrbiterE * 5817029335999350327U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 16318022893068674015U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 11089160685103562409U;
            aOrbiterH = RotL64((aOrbiterH * 17087834321385147603U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 8680037953925067235U) + aNonceWordH;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 3112588943274158119U;
            aOrbiterJ = RotL64((aOrbiterJ * 9214011370307670371U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 16749015684369649821U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 9419550535891334966U;
            aOrbiterI = RotL64((aOrbiterI * 5421312787569114811U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 12309598080688360615U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 12244971765096881835U;
            aOrbiterF = RotL64((aOrbiterF * 17260277357109449509U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 10088685417774847648U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 3241987595838650154U) ^ aOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 14096986158958931367U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 17916401586500786536U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 16519040829220310189U) ^ aNonceWordO;
            aOrbiterD = RotL64((aOrbiterD * 6742024268853509861U), 27U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterF, 43U);
            aIngress = aIngress + (RotL64(aOrbiterH, 3U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 35U));
            aIngress = aIngress + (RotL64(aOrbiterD, 46U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterJ, 51U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterB, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aScatter, 30U) + RotL64(aOrbiterC, 3U)) + aOrbiterJ) + aNonceWordD);
            aWandererF = aWandererF + ((((RotL64(aCross, 3U) + RotL64(aOrbiterK, 41U)) + aOrbiterG) + RotL64(aCarry, 51U)) + aWandererUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterE, 35U)) + aOrbiterD);
            aWandererH = aWandererH + ((RotL64(aIngress, 51U) + RotL64(aOrbiterH, 18U)) + aOrbiterG);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 53U) + aOrbiterG) + RotL64(aOrbiterJ, 43U)) + aNonceWordB);
            aWandererC = aWandererC + ((RotL64(aPrevious, 35U) + RotL64(aOrbiterF, 37U)) + aOrbiterE);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 27U) + aOrbiterK) + RotL64(aOrbiterC, 53U)) + aWandererUpdateSaltA[((aIndex + 18U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aCross, 11U) + RotL64(aOrbiterI, 11U)) + aOrbiterH);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 14U) + RotL64(aOrbiterA, 26U)) + aOrbiterI);
            aWandererD = aWandererD + (((RotL64(aPrevious, 41U) + RotL64(aOrbiterF, 51U)) + aOrbiterJ) + RotL64(aCarry, 57U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 37U) + RotL64(aOrbiterC, 23U)) + aOrbiterB) + aNonceWordP);
            //
            aCarry = aCarry + (RotL64(aWandererE, 58U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererG, 39U) ^ aWandererK);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 5U));
            aCarry = aCarry + (RotL64(aWandererJ, 21U) ^ aWandererB);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 18U));
            aCarry = aCarry + RotL64(aWandererI, 11U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 31192U)) & S_BLOCK1], 29U) ^ RotL64(pSnow[((aIndex + 30609U)) & S_BLOCK1], 60U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 31217U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 29691U)) & S_BLOCK1], 47U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 28898U)) & S_BLOCK1], 56U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 31555U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCross, 21U) + RotL64(aIngress, 36U)) ^ (RotL64(aPrevious, 3U) ^ RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterB = ((aWandererG + RotL64(aPrevious, 3U)) + 4751694786009671052U) + aNonceWordH;
            aOrbiterF = ((aWandererE + RotL64(aIngress, 53U)) + RotL64(aCarry, 23U)) + 16362725160370844224U;
            aOrbiterC = (aWandererK + RotL64(aScatter, 48U)) + 6360885380915941057U;
            aOrbiterG = (aWandererA + RotL64(aCross, 39U)) + 5154536007972297036U;
            aOrbiterK = ((aWandererH + RotL64(aIngress, 43U)) + 9362540581874808253U) + aOrbiterAssignSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterH = (aWandererC + RotL64(aCross, 11U)) + 13902493871525612934U;
            aOrbiterE = (aWandererI + RotL64(aPrevious, 21U)) + 10208452885367546542U;
            aOrbiterI = (((aWandererJ + RotL64(aScatter, 46U)) + RotL64(aCarry, 5U)) + 3117030377279160998U) + aNonceWordB;
            aOrbiterD = (aWandererB + RotL64(aPrevious, 23U)) + 17286247690414027870U;
            aOrbiterA = (((aWandererF + RotL64(aCross, 57U)) + RotL64(aCarry, 57U)) + 3930314320040949141U) + aOrbiterAssignSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterJ = (aWandererD + RotL64(aIngress, 19U)) + 7289525252391668404U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 3434167955466809185U) + aNonceWordM;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 17852573095128575663U;
            aOrbiterC = RotL64((aOrbiterC * 1485660158767033425U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 6137259687928853253U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 13992510605237574698U;
            aOrbiterH = RotL64((aOrbiterH * 15346263295995333395U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 6470556523400123474U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 4333255670390099293U;
            aOrbiterF = RotL64((aOrbiterF * 11089933812030082647U), 37U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterB) + 7700424876430257995U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordL;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 16920736951239453071U) ^ aOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 8920407493132380497U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 1635071690430295730U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 9966700845966398620U;
            aOrbiterB = RotL64((aOrbiterB * 17210048121896546867U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 9833458070123027075U) + aOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 1990346556486746432U;
            aOrbiterK = RotL64((aOrbiterK * 8704943923474148699U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 13339523466436517327U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 5018264760406215603U;
            aOrbiterA = RotL64((aOrbiterA * 2769197961801783627U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 123427497520755346U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 4535841104215792886U;
            aOrbiterJ = RotL64((aOrbiterJ * 1417676310539177131U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 3525925567359163763U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 3273741481392187986U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 16116160744647235811U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 6230742908784102407U) + aNonceWordP;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 7578784912496239362U;
            aOrbiterG = RotL64((aOrbiterG * 2614448818452560369U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 14669810330213234082U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 4751694786009671052U;
            aOrbiterD = RotL64((aOrbiterD * 9583151676882991817U), 11U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterJ, 37U);
            aIngress = aIngress + (RotL64(aOrbiterC, 5U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterI, 53U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterG, 50U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterE, 39U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterA, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((((RotL64(aIngress, 57U) + RotL64(aOrbiterK, 13U)) + aOrbiterE) + aNonceWordA) + aWandererUpdateSaltB[((aIndex + 4U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 27U) + aOrbiterD) + RotL64(aOrbiterB, 21U)) + RotL64(aCarry, 41U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 34U) + RotL64(aOrbiterG, 60U)) + aOrbiterB) + aWandererUpdateSaltD[((aIndex + 16U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 43U) + aOrbiterK) + RotL64(aOrbiterI, 5U)) + RotL64(aCarry, 3U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 3U) + aOrbiterK) + RotL64(aOrbiterC, 19U)) + aNonceWordK);
            aWandererA = aWandererA + ((RotL64(aPrevious, 37U) + RotL64(aOrbiterJ, 53U)) + aOrbiterD);
            aWandererC = aWandererC ^ ((RotL64(aCross, 50U) + aOrbiterD) + RotL64(aOrbiterI, 29U));
            aWandererG = aWandererG + ((RotL64(aIngress, 13U) + RotL64(aOrbiterE, 27U)) + aOrbiterH);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 41U) + aOrbiterA) + RotL64(aOrbiterB, 42U));
            aWandererH = aWandererH + ((RotL64(aPrevious, 23U) + aOrbiterB) + RotL64(aOrbiterH, 35U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 11U) + aOrbiterF) + RotL64(aOrbiterJ, 47U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 41U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererF, 6U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererH, 21U) ^ aWandererB);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 43U));
            aCarry = aCarry + RotL64(aWandererK, 30U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xAADC7A2CC933813DULL + 0xEBDCDB64118D9FFDULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x8C8CA063EB789B75ULL + 0x9D0AFCE2AB15418EULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x9FD870964D179D3BULL + 0xE8AF151BBB9466EAULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xE1B70AA26CE166F7ULL + 0x8CD6E64031B07A60ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x88647CCCA8D71B39ULL + 0xA785A4ED5850A0BAULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xA7E33BCE1DD2E133ULL + 0xE190CAAB8D38E1C2ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xED647D84186C846BULL + 0x996E1D74B301D293ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x862DA2837218007FULL + 0xDF5957FCCBCA5192ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xD640FBA35D5237EFULL + 0xDF110C0CE421A5F6ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xC80CDA23449899EDULL + 0x91ACEB63D21E62A1ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xEF31CA82108885D3ULL + 0xEEA5A1441F0095EFULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xC2A3EB322EFD52FBULL + 0xEF62ECC375D80BDCULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xACBA7584E1AF412BULL + 0x88135B6426E2204BULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xF6F6AF3788D95A17ULL + 0xC8CCD287F178E8EEULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xBEA16DCC0ABBBB7BULL + 0xD2BE7F87D93CA6E7ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xE4B5E8394A6249F9ULL + 0xA561A5B363F0FC12ULL);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 1195U)) & S_BLOCK1], 21U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 159U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 3682U)) & S_BLOCK1], 27U) ^ RotL64(aFireLaneD[((aIndex + 6201U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aPrevious, 37U) + RotL64(aCarry, 52U)) + (RotL64(aCross, 3U) ^ RotL64(aIngress, 19U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterH = (aWandererA + RotL64(aScatter, 19U)) + 5960680319644404115U;
            aOrbiterA = (aWandererJ + RotL64(aIngress, 60U)) + 16050752633567034185U;
            aOrbiterI = ((aWandererI + RotL64(aCross, 27U)) + RotL64(aCarry, 19U)) + 8447503223226854741U;
            aOrbiterB = (((aWandererE + RotL64(aPrevious, 53U)) + RotL64(aCarry, 57U)) + 14176813813397917591U) + aNonceWordI;
            aOrbiterK = ((aWandererD + RotL64(aCross, 5U)) + 10534915376130006644U) + aNonceWordN;
            aOrbiterJ = (aWandererK + RotL64(aPrevious, 11U)) + 6866224454375302514U;
            aOrbiterC = ((((aWandererH + RotL64(aIngress, 47U)) + RotL64(aCarry, 27U)) + 16506374165041008396U) + aOrbiterAssignSaltA[((aIndex + 9U)) & S_SALT1]) + aNonceWordC;
            aOrbiterE = (aWandererB + RotL64(aScatter, 39U)) + 7167814023968794098U;
            aOrbiterD = (((aWandererF + RotL64(aPrevious, 34U)) + 13870852197416596664U) + aOrbiterAssignSaltF[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordJ;
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 18064038854848993105U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 9869630811507771691U;
            aOrbiterI = RotL64((aOrbiterI * 13723164383800461387U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 863613100452759380U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 16597969741225436529U) ^ aOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2680793528887208903U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 6575347108051310653U) + aOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 17062262265485019063U) ^ aNonceWordA;
            aOrbiterA = RotL64((aOrbiterA * 7601045488473620019U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 7193399224636409133U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 14146747818810433849U;
            aOrbiterJ = RotL64((aOrbiterJ * 5273185769989530041U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 9441449106442431427U) + aNonceWordG;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 4303295336545399503U) ^ aNonceWordB;
            aOrbiterH = RotL64((aOrbiterH * 8829695296836242587U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 12604760768543193458U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 15779327512379787715U;
            aOrbiterD = RotL64((aOrbiterD * 14000905201441272597U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 15553000781122708728U) + aNonceWordL;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 17162740616060079717U;
            aOrbiterC = RotL64((aOrbiterC * 9458662233556750239U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 1032374679817715156U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 16413393156165548232U) ^ aOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 549659738811935015U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 14056855000013992045U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 7399202019042538829U;
            aOrbiterE = RotL64((aOrbiterE * 6103508549612077695U), 19U);
            //
            aIngress = RotL64(aOrbiterE, 20U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 29U));
            aIngress = aIngress + (RotL64(aOrbiterD, 57U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterB, 47U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterJ, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aScatter, 56U) + aOrbiterI) + RotL64(aOrbiterJ, 58U)) + aNonceWordM);
            aWandererF = aWandererF + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterA, 35U)) + aOrbiterB) + RotL64(aCarry, 11U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterI, 51U)) + aOrbiterC);
            aWandererI = aWandererI + (((RotL64(aCross, 11U) + RotL64(aOrbiterE, 5U)) + aOrbiterI) + RotL64(aCarry, 3U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 19U) + RotL64(aOrbiterD, 27U)) + aOrbiterA) + aNonceWordH);
            aWandererJ = aWandererJ + ((RotL64(aCross, 24U) + aOrbiterH) + RotL64(aOrbiterC, 22U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 29U) + RotL64(aOrbiterC, 11U)) + aOrbiterK) + aWandererUpdateSaltB[((aIndex + 26U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aPrevious, 5U) + aOrbiterB) + RotL64(aOrbiterD, 41U)) + aWandererUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 47U) + aOrbiterE) + RotL64(aOrbiterC, 47U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 37U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererB, 41U) ^ aWandererE);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 6U));
            aCarry = aCarry + (RotL64(aWandererJ, 11U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererI, 57U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 14527U)) & S_BLOCK1], 54U) ^ RotL64(aFireLaneB[((aIndex + 15855U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 12071U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 13887U)) & S_BLOCK1], 26U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 8192U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aPrevious, 39U) + RotL64(aCross, 5U)) ^ (RotL64(aIngress, 24U) + RotL64(aCarry, 51U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterC = ((aWandererB + RotL64(aPrevious, 13U)) + RotL64(aCarry, 3U)) + 6318740973868639425U;
            aOrbiterI = ((aWandererK + RotL64(aScatter, 6U)) + RotL64(aCarry, 37U)) + 5487840061430920881U;
            aOrbiterF = (aWandererF + RotL64(aCross, 19U)) + 10258706763248072672U;
            aOrbiterE = ((aWandererA + RotL64(aIngress, 29U)) + 18356875269730338208U) + aOrbiterAssignSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterJ = ((aWandererJ + RotL64(aCross, 43U)) + RotL64(aCarry, 47U)) + 12883160282903147010U;
            aOrbiterB = ((aWandererH + RotL64(aScatter, 57U)) + 1010140474942697730U) + aNonceWordC;
            aOrbiterA = ((aWandererE + RotL64(aIngress, 39U)) + 17733939421700898293U) + aNonceWordG;
            aOrbiterH = (aWandererC + RotL64(aPrevious, 50U)) + 13693055887924981201U;
            aOrbiterG = ((aWandererD + RotL64(aCross, 23U)) + 14574732452793385269U) + aOrbiterAssignSaltD[((aIndex + 13U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 10832873941223609012U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 8212600587135328040U;
            aOrbiterF = RotL64((aOrbiterF * 5334613996794796145U), 39U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 5312744319781971178U) + aOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 6173741211706546923U;
            aOrbiterJ = RotL64((aOrbiterJ * 12854414066390848249U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 3693249147883790810U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 18365859989736602556U;
            aOrbiterB = RotL64((aOrbiterB * 3348463719324104997U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 10645056678337549771U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 1175668356822251045U) ^ aNonceWordE;
            aOrbiterH = RotL64((aOrbiterH * 6579675292775345579U), 5U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 13556844570541823717U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 4790355739411849736U) ^ aNonceWordN;
            aOrbiterC = RotL64((aOrbiterC * 4083544011788850307U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 14905575502272644116U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 17047244574558476634U;
            aOrbiterI = RotL64((aOrbiterI * 2356386971503880047U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 10161614295718414869U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 13413914082651612468U;
            aOrbiterA = RotL64((aOrbiterA * 16224039093981079491U), 21U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 6072693130156927774U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 4333656233793103787U;
            aOrbiterE = RotL64((aOrbiterE * 9374745547133955709U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 17209776289202130250U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 11752001118070361543U;
            aOrbiterG = RotL64((aOrbiterG * 4416523594812872339U), 29U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterC, 50U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 47U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 13U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 27U));
            aIngress = aIngress + RotL64(aOrbiterA, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 53U) + aOrbiterB) + RotL64(aOrbiterA, 11U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 24U) + aOrbiterF) + RotL64(aOrbiterA, 39U)) + RotL64(aCarry, 39U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 19U) + RotL64(aOrbiterF, 44U)) + aOrbiterC) + aWandererUpdateSaltE[((aIndex + 25U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aIngress, 57U) + aOrbiterH) + RotL64(aOrbiterG, 27U)) + aNonceWordL);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 3U) + aOrbiterI) + RotL64(aOrbiterJ, 53U));
            aWandererD = aWandererD + ((RotL64(aScatter, 39U) + aOrbiterG) + RotL64(aOrbiterE, 35U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 47U) + aOrbiterJ) + RotL64(aOrbiterA, 48U));
            aWandererB = aWandererB + (((((RotL64(aCross, 13U) + aOrbiterG) + RotL64(aOrbiterA, 19U)) + RotL64(aCarry, 53U)) + aNonceWordM) + aWandererUpdateSaltD[((aIndex + 11U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 28U) + RotL64(aOrbiterF, 3U)) + aOrbiterG) + aNonceWordP);
            //
            aCarry = aCarry + (RotL64(aWandererK, 46U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererE, 29U) ^ aWandererH);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 43U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 53U));
            aCarry = aCarry + RotL64(aWandererD, 50U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 22501U)) & S_BLOCK1], 11U) ^ RotL64(aFireLaneD[((aIndex + 21664U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 19159U)) & S_BLOCK1], 56U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 22348U)) & S_BLOCK1], 30U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 19704U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aFireLaneC[((aIndex + 17772U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCarry, 57U) + RotL64(aPrevious, 28U)) ^ (RotL64(aIngress, 41U) + RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterI = ((aWandererK + RotL64(aIngress, 35U)) + 2617613537256538553U) + aOrbiterAssignSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = (aWandererB + RotL64(aPrevious, 39U)) + 16642868916835132715U;
            aOrbiterA = (aWandererG + RotL64(aScatter, 51U)) + 10860291124337073254U;
            aOrbiterD = ((aWandererI + RotL64(aCross, 27U)) + 6432511273906902472U) + aNonceWordF;
            aOrbiterH = (((aWandererD + RotL64(aScatter, 60U)) + RotL64(aCarry, 21U)) + 7505375005848241910U) + aNonceWordG;
            aOrbiterC = (((aWandererF + RotL64(aIngress, 47U)) + RotL64(aCarry, 57U)) + 11086616004678821329U) + aNonceWordB;
            aOrbiterJ = (aWandererA + RotL64(aPrevious, 13U)) + 3298830587569881951U;
            aOrbiterB = ((aWandererH + RotL64(aCross, 23U)) + RotL64(aCarry, 35U)) + 9775143140064220979U;
            aOrbiterF = (((aWandererC + RotL64(aIngress, 18U)) + 4147601326580823120U) + aOrbiterAssignSaltC[((aIndex + 29U)) & S_SALT1]) + aNonceWordE;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 12245920269898100415U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 8391940489176734499U;
            aOrbiterA = RotL64((aOrbiterA * 9119606167674098007U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 17876893379544668477U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 18301882058180370541U;
            aOrbiterH = RotL64((aOrbiterH * 16680384667098921309U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 6869225862715140102U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 15404118372589259800U;
            aOrbiterJ = RotL64((aOrbiterJ * 5766851935950389915U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 17757381020518233814U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 17677969146092374455U;
            aOrbiterI = RotL64((aOrbiterI * 3469432916562405063U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 15783378556632870114U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 5792858258663697864U;
            aOrbiterD = RotL64((aOrbiterD * 12008981883482080427U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 11737803388202260296U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 16001927091970715330U) ^ aOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 3062030309852922061U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 1749586939123286632U) + aNonceWordI;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 6169421068855905938U) ^ aNonceWordM;
            aOrbiterC = RotL64((aOrbiterC * 12374789910763348695U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 10073586820719728062U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterB) ^ 17744171227198661555U) ^ aOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterK = RotL64((aOrbiterK * 10658375268803957647U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 1149819647337612792U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 7725598665625892006U;
            aOrbiterF = RotL64((aOrbiterF * 15097586655234391559U), 19U);
            //
            aIngress = RotL64(aOrbiterB, 41U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterK, 27U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 51U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 23U));
            aIngress = aIngress + RotL64(aOrbiterD, 30U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aIngress, 39U) + aOrbiterF) + RotL64(aOrbiterJ, 34U));
            aWandererD = aWandererD + (((RotL64(aCross, 29U) + aOrbiterJ) + RotL64(aOrbiterC, 19U)) + aWandererUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 4U) + aOrbiterK) + RotL64(aOrbiterA, 57U));
            aWandererC = aWandererC + ((RotL64(aScatter, 35U) + aOrbiterF) + RotL64(aOrbiterI, 29U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterB, 39U)) + aOrbiterC);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 13U) + RotL64(aOrbiterI, 14U)) + aOrbiterK) + RotL64(aCarry, 47U)) + aWandererUpdateSaltA[((aIndex + 12U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 58U) + aOrbiterD) + RotL64(aOrbiterC, 43U));
            aWandererH = aWandererH + ((((RotL64(aCross, 21U) + RotL64(aOrbiterI, 47U)) + aOrbiterC) + RotL64(aCarry, 39U)) + aNonceWordJ);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterH, 23U)) + aOrbiterF) + aNonceWordK);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 37U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 57U));
            aCarry = aCarry + (RotL64(aWandererA, 23U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererK, 50U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererB, 47U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 26789U)) & S_BLOCK1], 5U) ^ RotL64(aFireLaneC[((aIndex + 27825U)) & S_BLOCK1], 14U));
            aIngress ^= RotL64(aOperationLaneA[((aIndex + 31581U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 29409U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 32020U)) & S_BLOCK1], 54U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 26918U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCross, 53U) ^ RotL64(aPrevious, 14U)) ^ (RotL64(aIngress, 39U) + RotL64(aCarry, 27U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterK = (((aWandererD + RotL64(aCross, 4U)) + RotL64(aCarry, 57U)) + 5480870806135400132U) + aNonceWordE;
            aOrbiterH = ((aWandererF + RotL64(aIngress, 29U)) + RotL64(aCarry, 39U)) + 8034874599430768743U;
            aOrbiterI = (aWandererJ + RotL64(aPrevious, 53U)) + 4006919843736863767U;
            aOrbiterA = (aWandererA + RotL64(aScatter, 47U)) + 2988069748674633718U;
            aOrbiterF = (aWandererI + RotL64(aCross, 43U)) + 12347295651973135786U;
            aOrbiterE = ((aWandererK + RotL64(aScatter, 58U)) + 14152683894431568192U) + aOrbiterAssignSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = ((aWandererB + RotL64(aPrevious, 21U)) + RotL64(aCarry, 23U)) + 15765143815254196598U;
            aOrbiterC = (((aWandererE + RotL64(aIngress, 13U)) + 10473067082331244233U) + aOrbiterAssignSaltA[((aIndex + 5U)) & S_SALT1]) + aNonceWordK;
            aOrbiterD = (aWandererH + RotL64(aCross, 37U)) + 1089466925383677249U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 13215039929873682230U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 3957997712247961479U;
            aOrbiterI = RotL64((aOrbiterI * 7631186240013784703U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 10023907397941685546U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 14593012591254614353U) ^ aNonceWordG;
            aOrbiterE = RotL64((aOrbiterE * 17111300092082154687U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 13353797968154036726U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 9259966668512102858U;
            aOrbiterK = RotL64((aOrbiterK * 8326732574268308221U), 23U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterC) + 10757861831070349321U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1]) + aNonceWordO;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 10530223113483866178U) ^ aOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11269177745265396583U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 7554320926405521865U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 6978052067277966996U) ^ aNonceWordJ;
            aOrbiterJ = RotL64((aOrbiterJ * 18020134738536217801U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 1053695861967171420U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 15980734683539854451U;
            aOrbiterD = RotL64((aOrbiterD * 3208466640010555357U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 17041258393808061556U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 12846551858751995530U;
            aOrbiterC = RotL64((aOrbiterC * 9303891433380993639U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 14617434286683320666U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 3999309956180741302U;
            aOrbiterH = RotL64((aOrbiterH * 15037707937050015205U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 13452627760403094126U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 2633241575260427158U) ^ aOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2638570213290747581U), 29U);
            //
            aIngress = RotL64(aOrbiterD, 39U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterC, 60U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 21U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 57U));
            aIngress = aIngress + RotL64(aOrbiterF, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aIngress, 6U) + RotL64(aOrbiterK, 11U)) + aOrbiterI) + aNonceWordL);
            aWandererA = aWandererA + ((RotL64(aCross, 23U) + aOrbiterJ) + RotL64(aOrbiterF, 57U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterH, 6U)) + aOrbiterE);
            aWandererK = aWandererK + ((((RotL64(aScatter, 43U) + aOrbiterD) + RotL64(aOrbiterC, 53U)) + RotL64(aCarry, 21U)) + aWandererUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterD, 43U)) + aOrbiterJ);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 53U) + aOrbiterA) + RotL64(aOrbiterH, 39U)) + RotL64(aCarry, 51U)) + aNonceWordH);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 60U) + RotL64(aOrbiterA, 28U)) + aOrbiterF) + aNonceWordF);
            aWandererF = aWandererF + (((RotL64(aIngress, 13U) + aOrbiterK) + RotL64(aOrbiterF, 23U)) + aNonceWordD);
            aWandererI = aWandererI ^ (((RotL64(aCross, 29U) + aOrbiterC) + RotL64(aOrbiterK, 35U)) + aWandererUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 54U) ^ aWandererH);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 27U));
            aCarry = aCarry + (RotL64(aWandererE, 13U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererB, 19U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererF, 3U);
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

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0; std::uint64_t aOrbiterE = 0;
    std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
    std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xCCAF740B011178DFULL + 0x9931D24E8C0B63F6ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x810B041B7B25E083ULL + 0xBA49ECFFAABF0C39ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xE6A27E8DF20691F7ULL + 0xDF254D371C680003ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xDCD233732113C54DULL + 0xC2690C5637EE60D9ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x9AC375A9A3DC4C09ULL + 0xBDD2999502CD0397ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x933D6C99A7FA2F39ULL + 0xD978C1FA02DD0688ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x9EDD08A89FAA7857ULL + 0xA1F71A9E7869A64AULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xD74F4D96427B03F9ULL + 0xB2E04B54D4B88887ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xB52E0CE69089AE7FULL + 0xA6F2158F9C236C38ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xE8DEAF4A03491811ULL + 0xA79FED0EDC170325ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xB477F4AC29EF4907ULL + 0x872E0DFE02D09EDEULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xF645F3152B1EF4F1ULL + 0xE7479FC954ABF8C6ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xF67C6B7246F6F377ULL + 0x8AB2D6692A5461F2ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0x88F200FE03687801ULL + 0xE9928BA132D1958AULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xE54E73F78FAEFC7DULL + 0x807837A0618EC778ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xC706C29DC6DF5989ULL + 0xAF180BFBD3C7F664ULL);
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
        // read from: aOperationLaneA, aOperationLaneB, aFireLaneD, aOperationLaneC, aOperationLaneD, aWorkLaneA, aFireLaneA, aWorkLaneB, aFireLaneC, aWorkLaneC, aFireLaneB
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 7647U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneB[((aIndex + 4637U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 2948U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 7780U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneD[((aIndex + 200U)) & S_BLOCK1], 34U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aPrevious, 37U)) ^ (RotL64(aCross, 51U) ^ RotL64(aIngress, 22U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterF = ((((aWandererG + RotL64(aScatter, 53U)) + RotL64(aCarry, 11U)) + 4476099022490972343U) + aOrbiterAssignSaltE[(((31U - aIndex) + 16U)) & S_SALT1]) + aNonceWordD;
            aOrbiterG = (((aWandererJ + RotL64(aCross, 3U)) + RotL64(aCarry, 47U)) + 16836423700375760429U) + aNonceWordM;
            aOrbiterC = ((aWandererK + RotL64(aIngress, 36U)) + RotL64(aCarry, 29U)) + 8850577488928703557U;
            aOrbiterK = ((aWandererB + RotL64(aPrevious, 19U)) + 7091631824560042743U) + aNonceWordE;
            aOrbiterD = (((aWandererE + RotL64(aScatter, 11U)) + 12560498899956759494U) + aOrbiterAssignSaltC[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordP;
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 7797973377112012161U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 6173820673874805794U;
            aOrbiterC = RotL64((aOrbiterC * 15741300047917486527U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 10805025132310245348U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 7139216143268029968U) ^ aOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8349754682635765573U), 29U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterF) + 8241544862261635722U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordO;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 4735527016563596150U) ^ aNonceWordI;
            aOrbiterG = RotL64((aOrbiterG * 6621354217673598381U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 5166171126690294033U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 11117641762075368393U;
            aOrbiterD = RotL64((aOrbiterD * 4980156869201219393U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 6312932356458415421U) + aOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 1304139291184508668U) ^ aOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 90744653170922319U), 21U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterG, 53U);
            aIngress = aIngress + (RotL64(aOrbiterD, 39U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterF, 6U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((((RotL64(aScatter, 11U) + RotL64(aOrbiterC, 37U)) + aOrbiterD) + aNonceWordH) + aWandererUpdateSaltB[((aIndex + 13U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aIngress, 56U) + aOrbiterD) + RotL64(aOrbiterG, 57U)) + RotL64(aCarry, 51U)) + aNonceWordN);
            aWandererJ = aWandererJ ^ ((((RotL64(aPrevious, 27U) + aOrbiterF) + RotL64(aOrbiterD, 19U)) + aNonceWordK) + aWandererUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 3U) + RotL64(aOrbiterK, 10U)) + aOrbiterF) + RotL64(aCarry, 13U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 41U) + RotL64(aOrbiterK, 29U)) + aOrbiterG) + aNonceWordL);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 24U));
            aCarry = aCarry + (RotL64(aWandererJ, 57U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererB, 43U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 9105U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneC[((aIndex + 15316U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 15347U)) & S_BLOCK1], 56U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 13728U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 9949U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 9677U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCross, 24U) + RotL64(aPrevious, 5U)) ^ (RotL64(aCarry, 39U) ^ RotL64(aIngress, 51U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterF = ((((aWandererG + RotL64(aPrevious, 27U)) + RotL64(aCarry, 27U)) + 13714409587461539863U) + aOrbiterAssignSaltF[(((31U - aIndex) + 16U)) & S_SALT1]) + aNonceWordC;
            aOrbiterK = ((aWandererF + RotL64(aCross, 35U)) + 14101156723903265839U) + aNonceWordJ;
            aOrbiterG = (aWandererH + RotL64(aIngress, 14U)) + 7063754562895369001U;
            aOrbiterA = ((aWandererK + RotL64(aScatter, 3U)) + RotL64(aCarry, 11U)) + 12320578575245519386U;
            aOrbiterI = (((aWandererJ + RotL64(aCross, 47U)) + RotL64(aCarry, 47U)) + 11744826789631008424U) + aOrbiterAssignSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 8744816505096675597U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 10405435520084528645U;
            aOrbiterG = RotL64((aOrbiterG * 13279521344071568023U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 1463157688070683543U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterK) ^ 12379603577919617703U) ^ aOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterI = RotL64((aOrbiterI * 14858901470015109311U), 21U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 1343439118031348146U) + aOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 16118850268070235540U) ^ aNonceWordL;
            aOrbiterK = RotL64((aOrbiterK * 11184386483735388257U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 14116264435819277136U) + aOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 5251698273012432109U;
            aOrbiterA = RotL64((aOrbiterA * 1495818611622063967U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 14806408656041403829U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 11569345414052398227U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 9913158908301414861U), 37U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterF, 53U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 40U));
            aIngress = aIngress + RotL64(aOrbiterG, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterG, 52U)) + aOrbiterI) + aNonceWordO);
            aWandererF = aWandererF + (((((RotL64(aCross, 11U) + aOrbiterK) + RotL64(aOrbiterI, 27U)) + RotL64(aCarry, 35U)) + aNonceWordB) + aWandererUpdateSaltC[((aIndex + 17U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((((RotL64(aScatter, 58U) + RotL64(aOrbiterI, 43U)) + aOrbiterF) + aNonceWordE) + aWandererUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 39U) + aOrbiterG) + RotL64(aOrbiterA, 35U)) + RotL64(aCarry, 57U)) + aNonceWordN);
            aWandererK = aWandererK ^ ((RotL64(aCross, 21U) + aOrbiterG) + RotL64(aOrbiterF, 19U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 48U));
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererJ, 3U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 17361U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneD[((aIndex + 18751U)) & S_BLOCK1], 26U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 16605U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19623U)) & S_BLOCK1], 38U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 21193U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aOperationLaneC[((aIndex + 24012U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCross, 19U) + RotL64(aPrevious, 35U)) + (RotL64(aCarry, 6U) ^ RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterI = ((((aWandererD + RotL64(aIngress, 5U)) + RotL64(aCarry, 39U)) + 3621877681473089725U) + aOrbiterAssignSaltD[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordA;
            aOrbiterG = (((aWandererI + RotL64(aCross, 13U)) + RotL64(aCarry, 5U)) + 4451752751536414717U) + aNonceWordH;
            aOrbiterE = (aWandererA + RotL64(aPrevious, 42U)) + 11371625415377772117U;
            aOrbiterA = ((((aWandererH + RotL64(aScatter, 53U)) + RotL64(aCarry, 27U)) + 6046792758881150619U) + aOrbiterAssignSaltA[((aIndex + 25U)) & S_SALT1]) + aNonceWordL;
            aOrbiterH = ((aWandererB + RotL64(aPrevious, 21U)) + 8213166120394461682U) + aNonceWordG;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 4343156661140422645U) + aNonceWordP;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 11105271483234947905U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 853531080115819287U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 348904609985341372U) + aOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 12924652822526858767U;
            aOrbiterG = RotL64((aOrbiterG * 2801892489296408735U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 7461211697358520287U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 16551553555297890558U;
            aOrbiterA = RotL64((aOrbiterA * 16432952324635746293U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 11908056404140782995U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterH) ^ 9147367258259948715U) ^ aOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterI = RotL64((aOrbiterI * 10777628928376261667U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 8876461054692728610U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 10546855952702525404U;
            aOrbiterH = RotL64((aOrbiterH * 10071104785895309677U), 13U);
            //
            aIngress = RotL64(aOrbiterA, 3U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterI, 52U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterE, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aPrevious, 5U) + RotL64(aOrbiterG, 11U)) + aOrbiterI) + RotL64(aCarry, 35U)) + aNonceWordK);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 43U) + RotL64(aOrbiterH, 47U)) + aOrbiterE) + aWandererUpdateSaltD[((aIndex + 14U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 19U) + RotL64(aOrbiterH, 39U)) + aOrbiterA) + aNonceWordN);
            aWandererD = aWandererD ^ (((RotL64(aCross, 30U) + aOrbiterG) + RotL64(aOrbiterE, 26U)) + aNonceWordO);
            aWandererI = aWandererI + ((((RotL64(aIngress, 53U) + aOrbiterA) + RotL64(aOrbiterG, 57U)) + RotL64(aCarry, 21U)) + aWandererUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 46U));
            aCarry = aCarry + (RotL64(aWandererD, 29U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererI, 11U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 26011U)) & S_BLOCK1], 10U) ^ RotL64(aWorkLaneA[((aIndex + 29331U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 25740U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 28689U)) & S_BLOCK1], 50U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 32679U)) & S_BLOCK1], 29U));
            aCross ^= (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 26993U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneA[((aIndex + 29300U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCross, 21U) ^ RotL64(aIngress, 35U)) ^ (RotL64(aCarry, 5U) + RotL64(aPrevious, 54U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterA = ((aWandererG + RotL64(aPrevious, 11U)) + 16160838483846078448U) + aNonceWordP;
            aOrbiterH = ((((aWandererD + RotL64(aIngress, 19U)) + RotL64(aCarry, 5U)) + 15404960896190227946U) + aOrbiterAssignSaltC[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordM;
            aOrbiterE = (((aWandererH + RotL64(aScatter, 47U)) + RotL64(aCarry, 53U)) + 16904160594024977199U) + aNonceWordB;
            aOrbiterC = (((aWandererJ + RotL64(aCross, 29U)) + RotL64(aCarry, 19U)) + 17790460246821031802U) + aOrbiterAssignSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = (aWandererI + RotL64(aIngress, 58U)) + 16395168254086971959U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 7484373204039901786U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 18026814691322913510U) ^ aNonceWordC;
            aOrbiterE = RotL64((aOrbiterE * 12688155753775099489U), 3U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterA) + 15244817793136966450U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordF;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 5795491730356335666U) ^ aNonceWordK;
            aOrbiterH = RotL64((aOrbiterH * 13253529465289332171U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 3163873518027801504U) + aOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 2690791759507349172U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 16677948635136515083U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 17898067251167087906U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 8028010015006604239U) ^ aOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 5601629670521300241U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 7304739457289910555U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 6476837815096530043U;
            aOrbiterA = RotL64((aOrbiterA * 16380545138701113267U), 23U);
            //
            aIngress = RotL64(aOrbiterC, 43U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterD, 29U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterE, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aCross, 3U) + RotL64(aOrbiterH, 11U)) + aOrbiterD) + aWandererUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 41U) + RotL64(aOrbiterH, 19U)) + aOrbiterE) + aNonceWordA);
            aWandererH = aWandererH + ((((RotL64(aIngress, 29U) + RotL64(aOrbiterA, 47U)) + aOrbiterC) + RotL64(aCarry, 57U)) + aNonceWordJ);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 52U) + RotL64(aOrbiterH, 57U)) + aOrbiterA);
            aWandererG = aWandererG + ((((RotL64(aCross, 13U) + aOrbiterD) + RotL64(aOrbiterE, 36U)) + RotL64(aCarry, 35U)) + aWandererUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererJ);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 11U));
            aCarry = aCarry + RotL64(aWandererH, 35U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xC1A2CB99D779446FULL + 0xD7894C1C1214C56EULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xFD02CE937D0C7DBDULL + 0xDC1F5061FAE30680ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xE7DED55FB81B3E13ULL + 0x9CECFC449A877B2EULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xF26ECD07188071A3ULL + 0xF8E9FEF087B091B7ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xA3B06FC668944B19ULL + 0x8FADCE2A3A4BB803ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xFA56961AA1E4C34FULL + 0xD76FB582C3A90898ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xC2066984F62FB58FULL + 0xD260408898CF8782ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xA6D47AC20A115001ULL + 0xF313376CA35AF4FBULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xEA98B4B14D32AE5FULL + 0xFF204EB109D777E6ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xD50658EFCFA5E957ULL + 0xAB345030A099143CULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xEB0E16BB9E0A0ECFULL + 0xD702CF914EEB2A32ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xF6DBBAD73F69C8D9ULL + 0x836EA93F3931880BULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0x89DD49BD12280FB7ULL + 0xB93718FCC9917507ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x8CD1D52414F46C0FULL + 0xAA87892C9D97ED72ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xEC0635B48B80576DULL + 0x91680D4C8AE59712ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0x9445EC0AA8ED707FULL + 0x8483B665819748E3ULL);
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
        // read from: aExpandLaneA, aExpandLaneB, aOperationLaneA, aExpandLaneC, aExpandLaneD, aFireLaneC, aWorkLaneA, aOperationLaneD, aFireLaneD, aWorkLaneB, aOperationLaneB, aFireLaneB, aWorkLaneC, aFireLaneA, aOperationLaneC
        // write to: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // kdf_a_loop_d loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aOperationLaneA
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aOperationLaneA forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD, aFireLaneC
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward forced, aFireLaneC backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 2881U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneB[((aIndex + 7328U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 4738U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4104U)) & S_BLOCK1], 46U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 2271U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 288U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aIngress, 18U) + RotL64(aCross, 5U)) ^ (RotL64(aCarry, 57U) ^ RotL64(aPrevious, 39U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterE = (aWandererB + RotL64(aCross, 35U)) + 18319689184146942855U;
            aOrbiterD = ((aWandererF + RotL64(aIngress, 19U)) + RotL64(aCarry, 13U)) + 8041304130090501019U;
            aOrbiterC = ((aWandererC + RotL64(aScatter, 57U)) + 11347064191990897738U) + aNonceWordN;
            aOrbiterH = ((aWandererA + RotL64(aPrevious, 42U)) + RotL64(aCarry, 29U)) + 15242243470024447468U;
            aOrbiterG = (((aWandererI + RotL64(aScatter, 5U)) + 10619749107163611105U) + aOrbiterAssignSaltD[((aIndex + 17U)) & S_SALT1]) + aNonceWordK;
            aOrbiterA = (aWandererE + RotL64(aPrevious, 27U)) + 14795614276221947128U;
            aOrbiterJ = (((aWandererH + RotL64(aCross, 11U)) + RotL64(aCarry, 53U)) + 1578095288886372393U) + aOrbiterAssignSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 13593906305770501684U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 8919815528334599172U;
            aOrbiterC = RotL64((aOrbiterC * 2033810402808238127U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 17425548324720065145U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 11125018338392347335U;
            aOrbiterG = RotL64((aOrbiterG * 4377887040461528587U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 3779189180734244399U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 10958224663276134041U;
            aOrbiterD = RotL64((aOrbiterD * 6206963519509783781U), 29U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterE) + 4317305352561612995U) + aOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1]) + aNonceWordE;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 4891139433808505355U) ^ aNonceWordM;
            aOrbiterA = RotL64((aOrbiterA * 11507024985663120317U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 5166074784835930965U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 10080890270621589202U;
            aOrbiterH = RotL64((aOrbiterH * 13170894418184288695U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 4501071771615514619U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 6486573807774431753U;
            aOrbiterJ = RotL64((aOrbiterJ * 324029625116648669U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 15714881857668975753U) + aOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 3506619392820235900U) ^ aOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5707033870161224499U), 3U);
            //
            aIngress = RotL64(aOrbiterG, 37U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterC, 53U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterA, 11U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterJ, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterE, 3U)) + aOrbiterC) + aNonceWordB);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterE, 37U)) + aOrbiterD);
            aWandererF = aWandererF + (((RotL64(aCross, 43U) + aOrbiterA) + RotL64(aOrbiterG, 29U)) + RotL64(aCarry, 27U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 56U) + RotL64(aOrbiterH, 44U)) + aOrbiterE) + aWandererUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aCross, 35U) + RotL64(aOrbiterJ, 23U)) + aOrbiterD) + aNonceWordO);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 5U) + RotL64(aOrbiterH, 51U)) + aOrbiterA) + aWandererUpdateSaltA[((aIndex + 9U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 13U) + RotL64(aOrbiterH, 13U)) + aOrbiterC) + RotL64(aCarry, 11U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 47U) ^ aWandererH);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 27U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 4U));
            aCarry = aCarry + RotL64(aWandererC, 37U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 2
        // ingress from: aWorkLaneA, aExpandLaneC, aOperationLaneD
        // ingress directions: aWorkLaneA forward forced, aExpandLaneC forward forced, aOperationLaneD forward/backward random
        // cross from: aExpandLaneA, aExpandLaneD, aFireLaneD
        // cross directions: aExpandLaneA backward forced, aExpandLaneD backward forced, aFireLaneD backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 8345U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneC[((aIndex + 13659U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 8611U)) & S_BLOCK1], 54U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 12414U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 13341U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 16378U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCross, 3U) + RotL64(aPrevious, 34U)) ^ (RotL64(aIngress, 51U) + RotL64(aCarry, 19U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterJ = (((aWandererE + RotL64(aPrevious, 35U)) + RotL64(aCarry, 35U)) + 6024062041314952357U) + aOrbiterAssignSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = (aWandererK + RotL64(aCross, 13U)) + 18340757093658015585U;
            aOrbiterF = (((aWandererA + RotL64(aScatter, 53U)) + RotL64(aCarry, 57U)) + 11911120493880346751U) + aNonceWordD;
            aOrbiterE = (((aWandererF + RotL64(aIngress, 29U)) + 17428074353884654439U) + aOrbiterAssignSaltF[((aIndex + 29U)) & S_SALT1]) + aNonceWordB;
            aOrbiterC = (((aWandererG + RotL64(aCross, 19U)) + RotL64(aCarry, 11U)) + 12790849760814795936U) + aNonceWordP;
            aOrbiterH = (aWandererJ + RotL64(aPrevious, 47U)) + 12633397052172117800U;
            aOrbiterK = (aWandererB + RotL64(aIngress, 4U)) + 11946150433665237945U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 16842157900909419285U) + aNonceWordM;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 14186235783224155962U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10521157787073684417U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 13284904542579767591U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 11609181965078844357U) ^ aOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 5455780554452453513U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 9628562297095374984U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 7850281529011259759U;
            aOrbiterE = RotL64((aOrbiterE * 17611485102925470357U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 257458718073794527U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 10693404545773519306U) ^ aOrbiterUpdateSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 14821443722828498323U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 3430519236533871460U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 6183054506953198055U) ^ aNonceWordN;
            aOrbiterC = RotL64((aOrbiterC * 6121082743789970911U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 2905610989884221654U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 4472163910775333862U;
            aOrbiterK = RotL64((aOrbiterK * 7770678426310856745U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 16870142883133769663U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 1403692060594816451U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9740854430251597879U), 47U);
            //
            aIngress = RotL64(aOrbiterH, 5U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 11U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 19U));
            aIngress = aIngress + RotL64(aOrbiterK, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aScatter, 13U) + RotL64(aOrbiterE, 13U)) + aOrbiterC);
            aWandererF = aWandererF ^ (((RotL64(aCross, 57U) + aOrbiterC) + RotL64(aOrbiterH, 47U)) + aNonceWordH);
            aWandererB = aWandererB + (((((RotL64(aPrevious, 35U) + RotL64(aOrbiterF, 37U)) + aOrbiterH) + RotL64(aCarry, 27U)) + aNonceWordL) + aWandererUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 29U) + aOrbiterJ) + RotL64(aOrbiterF, 26U));
            aWandererG = aWandererG + ((RotL64(aPrevious, 3U) + RotL64(aOrbiterA, 5U)) + aOrbiterE);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 41U) + aOrbiterK) + RotL64(aOrbiterF, 19U));
            aWandererE = aWandererE + ((((RotL64(aIngress, 50U) + RotL64(aOrbiterA, 53U)) + aOrbiterC) + RotL64(aCarry, 57U)) + aWandererUpdateSaltE[((aIndex + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 21U) ^ aWandererB);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 42U));
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererA, 29U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 3
        // ingress from: aWorkLaneB, aExpandLaneD, aOperationLaneB
        // ingress directions: aWorkLaneB forward forced, aExpandLaneD forward forced, aOperationLaneB forward/backward random
        // cross from: aWorkLaneA, aExpandLaneB, aFireLaneB
        // cross directions: aWorkLaneA backward forced, aExpandLaneB backward forced, aFireLaneB backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 22577U)) & S_BLOCK1], 24U) ^ RotL64(aExpandLaneD[((aIndex + 18193U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aOperationLaneB[((aIndex + 18574U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21760U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 21523U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 24483U)) & S_BLOCK1], 4U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCross, 12U) ^ RotL64(aIngress, 41U)) + (RotL64(aCarry, 57U) ^ RotL64(aPrevious, 27U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterI = ((aWandererK + RotL64(aIngress, 5U)) + RotL64(aCarry, 5U)) + 16651241552253078315U;
            aOrbiterA = (((aWandererG + RotL64(aPrevious, 56U)) + 4558144676982478003U) + aOrbiterAssignSaltC[((aIndex + 18U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterJ = (aWandererA + RotL64(aCross, 19U)) + 8814884320080367550U;
            aOrbiterE = ((aWandererC + RotL64(aScatter, 41U)) + 16011579668555672117U) + aOrbiterAssignSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterF = (((aWandererI + RotL64(aCross, 47U)) + RotL64(aCarry, 57U)) + 4738918668759862438U) + aNonceWordC;
            aOrbiterG = (((aWandererF + RotL64(aPrevious, 29U)) + RotL64(aCarry, 43U)) + 12526083125540985108U) + aNonceWordN;
            aOrbiterK = (aWandererD + RotL64(aScatter, 13U)) + 8048723561746000552U;
            //
            aOrbiterI = (((aOrbiterI + aOrbiterA) + 1082218464034639039U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordP;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 8432043246965946816U;
            aOrbiterJ = RotL64((aOrbiterJ * 7801965585991025451U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 9982080524048636852U) + aNonceWordO;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 6720069955755215919U;
            aOrbiterI = RotL64((aOrbiterI * 1025046364205332059U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 1019035028070247757U) + aNonceWordF;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 7360619079463870467U) ^ aOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6623074813047915863U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 10893918488381348474U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 1390297670907738019U;
            aOrbiterE = RotL64((aOrbiterE * 11909657437658597735U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 12512200589031203480U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 14741471280748399540U) ^ aNonceWordA;
            aOrbiterA = RotL64((aOrbiterA * 3012135242889901095U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 8543897248359826770U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 8545972622733791272U) ^ aOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 11793879362775346821U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 7049384618581928664U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 14730773807906925408U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10711566871536755073U), 3U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterA, 35U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 58U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 29U));
            aIngress = aIngress + RotL64(aOrbiterE, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aScatter, 53U) + RotL64(aOrbiterI, 21U)) + aOrbiterJ) + RotL64(aCarry, 53U)) + aNonceWordL);
            aWandererA = aWandererA ^ (((RotL64(aCross, 60U) + aOrbiterK) + RotL64(aOrbiterE, 41U)) + aWandererUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aPrevious, 27U) + RotL64(aOrbiterK, 57U)) + aOrbiterG);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 3U) + aOrbiterI) + RotL64(aOrbiterE, 30U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 19U) + aOrbiterE) + RotL64(aOrbiterF, 47U)) + RotL64(aCarry, 11U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 13U) + aOrbiterF) + RotL64(aOrbiterA, 5U)) + aNonceWordK);
            aWandererK = aWandererK + ((((RotL64(aIngress, 41U) + RotL64(aOrbiterI, 11U)) + aOrbiterK) + aNonceWordE) + aWandererUpdateSaltB[((aIndex + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 21U));
            aCarry = aCarry + (RotL64(aWandererI, 58U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererC, 11U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererD, 47U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 4
        // ingress from: aWorkLaneC, aWorkLaneA, aFireLaneA
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aFireLaneA forward/backward random
        // cross from: aWorkLaneB, aExpandLaneC, aOperationLaneC
        // cross directions: aWorkLaneB backward forced, aExpandLaneC backward forced, aOperationLaneC backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 29620U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneA[((aIndex + 29886U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 30025U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 28803U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 30445U)) & S_BLOCK1], 58U));
            aCross ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 30634U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aPrevious, 60U) + RotL64(aCross, 13U)) + (RotL64(aIngress, 35U) ^ RotL64(aCarry, 47U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterC = (aWandererH + RotL64(aCross, 19U)) + 6318740973868639425U;
            aOrbiterH = (aWandererJ + RotL64(aPrevious, 27U)) + 5487840061430920881U;
            aOrbiterI = (aWandererD + RotL64(aIngress, 11U)) + 10258706763248072672U;
            aOrbiterK = (((aWandererG + RotL64(aScatter, 41U)) + RotL64(aCarry, 23U)) + 18356875269730338208U) + aOrbiterAssignSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterD = ((aWandererF + RotL64(aIngress, 47U)) + RotL64(aCarry, 43U)) + 12883160282903147010U;
            aOrbiterB = (((aWandererK + RotL64(aCross, 57U)) + RotL64(aCarry, 3U)) + 1010140474942697730U) + aNonceWordJ;
            aOrbiterF = (((aWandererC + RotL64(aPrevious, 34U)) + 17733939421700898293U) + aOrbiterAssignSaltD[((aIndex + 16U)) & S_SALT1]) + aNonceWordG;
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 13693055887924981201U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterC) ^ 14574732452793385269U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterI = RotL64((aOrbiterI * 9373765929885750185U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 10832873941223609012U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 8212600587135328040U;
            aOrbiterD = RotL64((aOrbiterD * 5334613996794796145U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 5312744319781971178U) + aOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 6173741211706546923U;
            aOrbiterC = RotL64((aOrbiterC * 12854414066390848249U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 3693249147883790810U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 18365859989736602556U;
            aOrbiterB = RotL64((aOrbiterB * 3348463719324104997U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 10645056678337549771U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 1175668356822251045U) ^ aNonceWordC;
            aOrbiterK = RotL64((aOrbiterK * 6579675292775345579U), 3U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterB) + 13556844570541823717U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordK;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 4790355739411849736U) ^ aOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4083544011788850307U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 14905575502272644116U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 17047244574558476634U;
            aOrbiterH = RotL64((aOrbiterH * 2356386971503880047U), 21U);
            //
            aIngress = RotL64(aOrbiterC, 51U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterD, 29U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterK, 14U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterB, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aScatter, 11U) + RotL64(aOrbiterH, 21U)) + aOrbiterK);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 29U) + aOrbiterC) + RotL64(aOrbiterB, 35U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 37U) + aOrbiterH) + RotL64(aOrbiterI, 5U)) + aNonceWordB);
            aWandererF = aWandererF ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterF, 13U)) + aOrbiterD);
            aWandererD = aWandererD + ((((RotL64(aScatter, 3U) + RotL64(aOrbiterB, 29U)) + aOrbiterK) + RotL64(aCarry, 29U)) + aWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 60U) + aOrbiterK) + RotL64(aOrbiterD, 44U)) + aWandererUpdateSaltF[((aIndex + 13U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aCross, 21U) + RotL64(aOrbiterF, 53U)) + aOrbiterH) + RotL64(aCarry, 47U)) + aNonceWordD);
            //
            aCarry = aCarry + (RotL64(aWandererG, 11U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererH, 56U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererF, 27U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererD, 41U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
    std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
    std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x8B81C7E3AD4C3447ULL + 0xE19296CBC14178B2ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xE00B679C3ABC9FFBULL + 0xBC993495C57F9755ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xCA1AC28ED53A955FULL + 0x97B8182A80AD0088ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x9DC3B828FBD7659BULL + 0xD1DD720D0ABAA1F9ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xBEBA1C9FA9488F85ULL + 0xA99484F90BDB22CFULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xF9630F6B1F7F497DULL + 0x87A564665BAB490CULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xDEFC0EE9AE21DD8FULL + 0xF6E7EF6348A525FAULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xA0B1F1CE3BD76319ULL + 0xC92C96B8ADE1000EULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0x9BE1251A0F644F87ULL + 0xF6A5856EECE3AF0DULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xD9037F80BD39BFF1ULL + 0xCE3F1647A753D30AULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xEFA7EAE7332DD0CBULL + 0xB179F7E0A7DC9CEAULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xC5FAE1A63A7EA097ULL + 0xF2B271893219238BULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0x9CB67F7B6B5A13BDULL + 0xF1587684B105D6DAULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xDB56DE4362E4747FULL + 0x97E015CC73FD902DULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xE9EBA76FF7DA69D7ULL + 0x9763AC00B8921E69ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0x92983EC9FB904281ULL + 0xA91151819D50947BULL);
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
        // read from: aWorkLaneA, aWorkLaneB, aOperationLaneB, aWorkLaneC, aWorkLaneD, aFireLaneB, aExpandLaneA, aFireLaneC, aOperationLaneD, aExpandLaneB, aFireLaneD, aOperationLaneA, aExpandLaneC, aFireLaneA, aOperationLaneC
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_a loop 1
        // ingress from: aWorkLaneA, aWorkLaneB, aOperationLaneB
        // ingress directions: aWorkLaneA forward forced, aWorkLaneB forward forced, aOperationLaneB forward/backward random
        // cross from: aWorkLaneC, aWorkLaneD, aFireLaneB
        // cross directions: aWorkLaneC backward forced, aWorkLaneD backward forced, aFireLaneB backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 3980U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneB[((aIndex + 6204U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aOperationLaneB[((aIndex + 7608U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 2017U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 7318U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 1108U)) & S_BLOCK1], 60U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aIngress, 11U) ^ RotL64(aCarry, 47U)) ^ (RotL64(aPrevious, 23U) + RotL64(aCross, 60U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterJ = ((aWandererK + RotL64(aIngress, 51U)) + RotL64(aCarry, 53U)) + 12535417189990029950U;
            aOrbiterF = (aWandererG + RotL64(aScatter, 3U)) + 6204401443676390273U;
            aOrbiterA = ((((aWandererF + RotL64(aCross, 12U)) + RotL64(aCarry, 19U)) + 869613505613154672U) + aOrbiterAssignSaltD[(((31U - aIndex) + 4U)) & S_SALT1]) + aNonceWordN;
            aOrbiterD = (((aWandererD + RotL64(aPrevious, 23U)) + 15053590879563855802U) + aOrbiterAssignSaltE[((aIndex + 29U)) & S_SALT1]) + aNonceWordM;
            aOrbiterK = ((aWandererC + RotL64(aScatter, 43U)) + RotL64(aCarry, 35U)) + 13338989605204591428U;
            aOrbiterI = (aWandererB + RotL64(aIngress, 29U)) + 18306470022403825392U;
            aOrbiterH = (aWandererI + RotL64(aPrevious, 37U)) + 1150696349434090218U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 13549541786420596437U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 14302878430259588461U;
            aOrbiterA = RotL64((aOrbiterA * 16813606782134305513U), 43U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterD) + 4660437084477165225U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 1653628537860912069U;
            aOrbiterK = RotL64((aOrbiterK * 2624835201155303123U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 5594199757006711631U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 11008472193138708891U;
            aOrbiterI = RotL64((aOrbiterI * 13645764762027798301U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 3668516817279364310U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 128159531749679984U;
            aOrbiterJ = RotL64((aOrbiterJ * 4523246859249826987U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 6378674346113979108U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 11438762460659123362U) ^ aNonceWordC;
            aOrbiterF = RotL64((aOrbiterF * 2733309638158283953U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 10624263004446482910U) + aOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 12546839706919241411U;
            aOrbiterD = RotL64((aOrbiterD * 11468326687628079347U), 37U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 8466639576503293921U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = (((aOrbiterH ^ aOrbiterI) ^ 5828694979857951504U) ^ aOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterH = RotL64((aOrbiterH * 7835487310289634515U), 13U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterF, 41U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 57U));
            aIngress = aIngress + (RotL64(aOrbiterD, 5U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterK, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aIngress, 13U) + aOrbiterJ) + RotL64(aOrbiterH, 27U)) + aWandererUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 57U) + RotL64(aOrbiterF, 35U)) + aOrbiterD) + aWandererUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 43U) + aOrbiterA) + RotL64(aOrbiterK, 3U)) + aNonceWordL);
            aWandererD = aWandererD + ((((RotL64(aCross, 37U) + aOrbiterF) + RotL64(aOrbiterH, 57U)) + RotL64(aCarry, 41U)) + aNonceWordD);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterI, 10U)) + aOrbiterK);
            aWandererB = aWandererB + (((RotL64(aIngress, 4U) + aOrbiterI) + RotL64(aOrbiterA, 41U)) + RotL64(aCarry, 21U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 51U) + aOrbiterK) + RotL64(aOrbiterF, 47U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 35U));
            aCarry = aCarry + (RotL64(aWandererB, 41U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererK, 21U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererF, 58U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 2
        // ingress from: aExpandLaneA, aWorkLaneC, aFireLaneC
        // ingress directions: aExpandLaneA forward forced, aWorkLaneC forward forced, aFireLaneC forward/backward random
        // cross from: aWorkLaneA, aWorkLaneD, aOperationLaneD
        // cross directions: aWorkLaneA backward forced, aWorkLaneD backward forced, aOperationLaneD backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 13381U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneC[((aIndex + 10602U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 14069U)) & S_BLOCK1], 26U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 9682U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 13525U)) & S_BLOCK1], 54U));
            aCross ^= RotL64(aOperationLaneD[((aIndex + 16275U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCross, 29U) ^ RotL64(aIngress, 44U)) + (RotL64(aCarry, 57U) + RotL64(aPrevious, 13U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterJ = ((aWandererI + RotL64(aScatter, 27U)) + RotL64(aCarry, 41U)) + 3621877681473089725U;
            aOrbiterH = (((aWandererD + RotL64(aIngress, 47U)) + RotL64(aCarry, 13U)) + 4451752751536414717U) + aNonceWordC;
            aOrbiterC = (aWandererC + RotL64(aCross, 35U)) + 11371625415377772117U;
            aOrbiterK = ((aWandererF + RotL64(aPrevious, 5U)) + 6046792758881150619U) + aOrbiterAssignSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterG = ((aWandererH + RotL64(aIngress, 11U)) + 8213166120394461682U) + aOrbiterAssignSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = ((aWandererG + RotL64(aPrevious, 60U)) + 4343156661140422645U) + aNonceWordD;
            aOrbiterB = ((aWandererB + RotL64(aCross, 41U)) + RotL64(aCarry, 29U)) + 11105271483234947905U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 348904609985341372U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 12924652822526858767U;
            aOrbiterC = RotL64((aOrbiterC * 2801892489296408735U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 7461211697358520287U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 16551553555297890558U) ^ aNonceWordM;
            aOrbiterG = RotL64((aOrbiterG * 16432952324635746293U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 11908056404140782995U) + aNonceWordJ;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 9147367258259948715U;
            aOrbiterJ = RotL64((aOrbiterJ * 10777628928376261667U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 8876461054692728610U) + aOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 10546855952702525404U) ^ aOrbiterUpdateSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 10071104785895309677U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 4748636139110443794U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 783046909529525098U;
            aOrbiterH = RotL64((aOrbiterH * 8969157702460927215U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 16683965945838696665U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 12385412690177109575U) ^ aNonceWordL;
            aOrbiterD = RotL64((aOrbiterD * 10795062772707143187U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 8210546822184469023U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 13146493623236979963U;
            aOrbiterB = RotL64((aOrbiterB * 13199947810161148155U), 3U);
            //
            aIngress = RotL64(aOrbiterJ, 13U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterK, 48U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterG, 27U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterB, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 10U) + aOrbiterC) + RotL64(aOrbiterK, 18U));
            aWandererG = aWandererG + (((RotL64(aCross, 47U) + RotL64(aOrbiterG, 35U)) + aOrbiterK) + RotL64(aCarry, 11U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterG, 11U)) + aOrbiterB) + aNonceWordH);
            aWandererD = aWandererD + (((((RotL64(aScatter, 19U) + aOrbiterH) + RotL64(aOrbiterG, 47U)) + RotL64(aCarry, 53U)) + aNonceWordN) + aWandererUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterC, 57U)) + aOrbiterJ);
            aWandererC = aWandererC + (((RotL64(aPrevious, 27U) + RotL64(aOrbiterG, 5U)) + aOrbiterJ) + aWandererUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aCross, 41U) + aOrbiterJ) + RotL64(aOrbiterD, 27U)) + aNonceWordI);
            //
            aCarry = aCarry + (RotL64(aWandererB, 56U) ^ aWandererD);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 51U));
            aCarry = aCarry + (RotL64(aWandererF, 11U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererH, 47U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 3
        // ingress from: aExpandLaneB, aWorkLaneD, aFireLaneD
        // ingress directions: aExpandLaneB forward forced, aWorkLaneD forward forced, aFireLaneD forward/backward random
        // cross from: aExpandLaneA, aWorkLaneB, aOperationLaneA
        // cross directions: aExpandLaneA backward forced, aWorkLaneB backward forced, aOperationLaneA backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 24085U)) & S_BLOCK1], 50U) ^ RotL64(aWorkLaneD[((aIndex + 19796U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 20984U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 24536U)) & S_BLOCK1], 12U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 18376U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 23281U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aPrevious, 3U) ^ RotL64(aCarry, 21U)) ^ (RotL64(aIngress, 37U) + RotL64(aCross, 54U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterH = ((aWandererC + RotL64(aScatter, 35U)) + RotL64(aCarry, 53U)) + 6068543441070417854U;
            aOrbiterA = (((aWandererE + RotL64(aPrevious, 12U)) + 2995980468193441856U) + aOrbiterAssignSaltB[((aIndex + 18U)) & S_SALT1]) + aNonceWordI;
            aOrbiterI = ((((aWandererJ + RotL64(aIngress, 47U)) + RotL64(aCarry, 41U)) + 18020277482171594003U) + aOrbiterAssignSaltC[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordG;
            aOrbiterF = ((aWandererA + RotL64(aCross, 3U)) + 4293807434721230702U) + aNonceWordM;
            aOrbiterK = ((aWandererB + RotL64(aPrevious, 19U)) + RotL64(aCarry, 13U)) + 7980599111583893156U;
            aOrbiterG = (aWandererK + RotL64(aIngress, 57U)) + 8593141111851052016U;
            aOrbiterB = ((aWandererI + RotL64(aScatter, 29U)) + 5903487523900084325U) + aNonceWordL;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 15112035513447930209U) + aOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 9854037263057006439U) ^ aOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 396276470208637283U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 16759760289688823193U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 12622628933030601390U) ^ aNonceWordC;
            aOrbiterK = RotL64((aOrbiterK * 2151912984825538321U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 1264668857268123425U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 16302812053619101593U;
            aOrbiterH = RotL64((aOrbiterH * 18291400055836111547U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 16087995784896123610U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 7970269262800468363U;
            aOrbiterG = RotL64((aOrbiterG * 14924752223305807461U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 5331477046030959632U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 16534913204255550893U) ^ aOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 1013433634373673565U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 11042821902537871209U) + aOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 8069677512345031660U) ^ aNonceWordD;
            aOrbiterB = RotL64((aOrbiterB * 13622218526054132397U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 5737130058129936372U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 1076627182956662997U;
            aOrbiterA = RotL64((aOrbiterA * 14342191224014199929U), 47U);
            //
            aIngress = RotL64(aOrbiterK, 41U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 47U));
            aIngress = aIngress + (RotL64(aOrbiterB, 34U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterI, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aPrevious, 53U) + aOrbiterH) + RotL64(aOrbiterB, 29U)) + RotL64(aCarry, 47U));
            aWandererB = aWandererB ^ ((((RotL64(aCross, 23U) + RotL64(aOrbiterA, 4U)) + aOrbiterF) + aNonceWordF) + aWandererUpdateSaltF[((aIndex + 20U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aScatter, 41U) + aOrbiterK) + RotL64(aOrbiterI, 21U)) + aNonceWordO) + aWandererUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 47U) + aOrbiterF) + RotL64(aOrbiterI, 47U)) + aNonceWordP);
            aWandererI = aWandererI + ((RotL64(aScatter, 13U) + aOrbiterB) + RotL64(aOrbiterG, 35U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterA, 57U)) + aOrbiterI);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 30U) + aOrbiterF) + RotL64(aOrbiterG, 13U)) + RotL64(aCarry, 11U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 58U));
            aCarry = aCarry + (RotL64(aWandererB, 13U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererJ, 41U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererC, 19U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 32056U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneA[((aIndex + 28500U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 25915U)) & S_BLOCK1], 26U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32636U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 30208U)) & S_BLOCK1], 44U));
            aCross ^= RotL64(aOperationLaneC[((aIndex + 27369U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCross, 42U) ^ RotL64(aPrevious, 57U)) + (RotL64(aCarry, 23U) ^ RotL64(aIngress, 11U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterD = ((aWandererH + RotL64(aPrevious, 47U)) + 1952750591494698524U) + aNonceWordF;
            aOrbiterC = ((aWandererA + RotL64(aScatter, 23U)) + 4488270851303332830U) + aNonceWordP;
            aOrbiterI = (aWandererG + RotL64(aIngress, 35U)) + 2738763375328927635U;
            aOrbiterJ = (((aWandererJ + RotL64(aCross, 3U)) + RotL64(aCarry, 27U)) + 6728843649480454340U) + aOrbiterAssignSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterH = ((aWandererC + RotL64(aIngress, 12U)) + RotL64(aCarry, 47U)) + 10490717875258865358U;
            aOrbiterB = (aWandererK + RotL64(aCross, 57U)) + 1429288737812910205U;
            aOrbiterA = (((aWandererB + RotL64(aPrevious, 41U)) + RotL64(aCarry, 5U)) + 2761375016998907636U) + aOrbiterAssignSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 1088988605204499835U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 6829840407300289709U;
            aOrbiterI = RotL64((aOrbiterI * 13101432880030791787U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 9267240337867690471U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 8120113021183975703U;
            aOrbiterJ = RotL64((aOrbiterJ * 14296504593187173107U), 41U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 1340980511302566784U) + aOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 11874452169979878835U;
            aOrbiterC = RotL64((aOrbiterC * 8638486178860092537U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 1872314794140971426U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 6013952618696225751U) ^ aOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7994863587373565715U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 3644011378086236002U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 8501867691997891731U;
            aOrbiterB = RotL64((aOrbiterB * 7115282675461711509U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 2493546555198066143U) + aNonceWordL;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 5179240189571799179U) ^ aOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 1267579130962756135U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 11273348247858394197U) + aNonceWordM;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 4577476419423118925U;
            aOrbiterH = RotL64((aOrbiterH * 8427261005061162673U), 13U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterH, 47U);
            aIngress = aIngress + (RotL64(aOrbiterI, 21U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterJ, 56U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterC, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aCross, 29U) + RotL64(aOrbiterD, 29U)) + aOrbiterA) + RotL64(aCarry, 27U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterH, 14U)) + aOrbiterC);
            aWandererH = aWandererH + ((((RotL64(aIngress, 41U) + RotL64(aOrbiterJ, 51U)) + aOrbiterI) + RotL64(aCarry, 43U)) + aNonceWordH);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 21U) + RotL64(aOrbiterB, 39U)) + aOrbiterJ) + aNonceWordA);
            aWandererA = aWandererA + ((((RotL64(aScatter, 51U) + RotL64(aOrbiterC, 5U)) + aOrbiterD) + aNonceWordK) + aWandererUpdateSaltE[((aIndex + 5U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 35U) + aOrbiterD) + RotL64(aOrbiterI, 57U)) + aWandererUpdateSaltC[((aIndex + 26U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aPrevious, 60U) + RotL64(aOrbiterA, 21U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererK, 48U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererG, 57U) ^ aWandererH);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 35U));
            aCarry = aCarry + RotL64(aWandererJ, 43U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x89BE41962584D237ULL + 0xF252FC27FBC683FDULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x9EDB04F9F962DB1DULL + 0xCA3A03A68D9FC1E1ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x8EEFF71B50DF839BULL + 0x9BA809301C6DC24BULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xE7A8BC15A0BE4BA3ULL + 0xF57100AB1373087CULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xDC59D9F535CD4199ULL + 0xF92BBDDB38CA92E5ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x88C12DE94B2B3B6FULL + 0x8571B71BDA7981CDULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xA0EB505F3B7F2771ULL + 0xD97CF6D13E4B9B64ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x98D929CEE78AC615ULL + 0xD1F35D7533ABF80FULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xFDEC667E42672FFBULL + 0xF08E0934C29E9717ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0x995F31E6190A2963ULL + 0x9A8C57D5B52137EBULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xD7ED4CE1FB231F8DULL + 0x9F14D287C1A34BBFULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xEC860C2E222CB233ULL + 0x9CC9BEFB1B30EDB2ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xDEBB440E18235FC5ULL + 0xDB1F8E45A8D17B7EULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0x889FBA9083397B4FULL + 0xBFE45326B5B9B600ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x887C3ED5EBFDD243ULL + 0xCA203144213F2AE1ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xFCC4284D757CE119ULL + 0x9AD97DE29F0528F2ULL);
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
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneD, aExpandLaneC, aExpandLaneD, aFireLaneA, aOperationLaneA, aWorkLaneB, aWorkLaneA, aOperationLaneB, aWorkLaneC, aFireLaneC, aOperationLaneC, aFireLaneB, aWorkLaneD
        // write to: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD
    
        // kdf_b_loop_b loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aFireLaneD
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aFireLaneD forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD, aFireLaneA
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward forced, aFireLaneA backward/forward random
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 2278U)) & S_BLOCK1], 20U) ^ RotL64(aExpandLaneB[((aIndex + 7696U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 1803U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4669U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 37U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 2547U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCarry, 53U) ^ RotL64(aPrevious, 34U)) + (RotL64(aCross, 5U) + RotL64(aIngress, 19U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterH = (aWandererI + RotL64(aIngress, 11U)) + 5131645209694953015U;
            aOrbiterE = ((aWandererE + RotL64(aScatter, 57U)) + RotL64(aCarry, 39U)) + 12070391048835379854U;
            aOrbiterJ = (((aWandererD + RotL64(aPrevious, 3U)) + 2604295836242338724U) + aOrbiterAssignSaltA[((aIndex + 15U)) & S_SALT1]) + aNonceWordG;
            aOrbiterK = (aWandererJ + RotL64(aCross, 14U)) + 14042039029284001596U;
            aOrbiterA = (((aWandererB + RotL64(aPrevious, 27U)) + 8914654543854559327U) + aOrbiterAssignSaltD[((aIndex + 21U)) & S_SALT1]) + aNonceWordI;
            aOrbiterF = (aWandererA + RotL64(aScatter, 37U)) + 2185619407969359869U;
            aOrbiterD = ((aWandererH + RotL64(aCross, 35U)) + RotL64(aCarry, 29U)) + 5187406295103352574U;
            aOrbiterB = (aWandererF + RotL64(aIngress, 5U)) + 8022832481290871217U;
            aOrbiterG = ((aWandererK + RotL64(aCross, 39U)) + 8783061916740573472U) + aNonceWordK;
            aOrbiterC = (aWandererG + RotL64(aScatter, 29U)) + 10711028365596196301U;
            aOrbiterI = ((aWandererC + RotL64(aPrevious, 22U)) + RotL64(aCarry, 13U)) + 13387065038269133571U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 11187001318931801582U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 14191473173276034019U) ^ aNonceWordD;
            aOrbiterJ = RotL64((aOrbiterJ * 2491253922434756431U), 37U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 16207761776716426435U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 9677408414452078760U;
            aOrbiterF = RotL64((aOrbiterF * 5487303383095129949U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 17812460332794370649U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 7736423148554132028U;
            aOrbiterB = RotL64((aOrbiterB * 15588733747232852555U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 17293203944059014763U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 13487243633338010243U;
            aOrbiterG = RotL64((aOrbiterG * 9468688858740539095U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 15979293016815060755U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 17645215484691359547U;
            aOrbiterH = RotL64((aOrbiterH * 1449450767288733995U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 11635961468586927692U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 10530136578329059784U) ^ aOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8785021493374398437U), 35U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterF) + 4900370530116992731U) + aOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1]) + aNonceWordB;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 15952900504821599445U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5413316082800365261U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 9938000151832814778U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 14170277411106520726U;
            aOrbiterK = RotL64((aOrbiterK * 5058343552974910737U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 14091010427448547620U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 13658560822164111421U;
            aOrbiterE = RotL64((aOrbiterE * 9523184040517290629U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 13954269172267844623U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 3921811946419945868U) ^ aNonceWordN;
            aOrbiterA = RotL64((aOrbiterA * 6839440867046147039U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 14296483810577739898U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 5131645209694953015U;
            aOrbiterD = RotL64((aOrbiterD * 10190969526209064367U), 3U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterB, 43U);
            aIngress = aIngress + (RotL64(aOrbiterI, 22U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 41U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 5U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 35U));
            aIngress = aIngress + RotL64(aOrbiterE, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterJ, 60U)) + aOrbiterC);
            aWandererB = aWandererB + (((RotL64(aCross, 50U) + aOrbiterA) + RotL64(aOrbiterK, 29U)) + RotL64(aCarry, 11U));
            aWandererJ = aWandererJ ^ ((((RotL64(aPrevious, 53U) + aOrbiterB) + RotL64(aOrbiterI, 21U)) + aNonceWordF) + aWandererUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aScatter, 5U) + RotL64(aOrbiterE, 37U)) + aOrbiterA);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 47U) + aOrbiterA) + RotL64(aOrbiterD, 5U));
            aWandererK = aWandererK + (((RotL64(aIngress, 21U) + RotL64(aOrbiterD, 3U)) + aOrbiterH) + RotL64(aCarry, 23U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 41U) + aOrbiterI) + RotL64(aOrbiterG, 44U));
            aWandererA = aWandererA + ((RotL64(aCross, 35U) + RotL64(aOrbiterJ, 13U)) + aOrbiterH);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterJ, 35U)) + aOrbiterG) + aNonceWordE);
            aWandererH = aWandererH + ((RotL64(aScatter, 13U) + aOrbiterG) + RotL64(aOrbiterD, 11U));
            aWandererG = aWandererG ^ ((((RotL64(aIngress, 38U) + aOrbiterF) + RotL64(aOrbiterH, 41U)) + aNonceWordJ) + aWandererUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 11U));
            aCarry = aCarry + (RotL64(aWandererC, 48U) ^ aWandererK);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 27U));
            aCarry = aCarry + (RotL64(aWandererE, 41U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererJ, 29U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererF, 44U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 2
        // ingress from: aOperationLaneA, aExpandLaneC, aWorkLaneB
        // ingress directions: aOperationLaneA forward forced, aExpandLaneC forward forced, aWorkLaneB forward/backward random
        // cross from: aExpandLaneA, aExpandLaneD, aWorkLaneA
        // cross directions: aExpandLaneA backward forced, aExpandLaneD backward forced, aWorkLaneA backward/forward random
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 10745U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneC[((aIndex + 11534U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 11670U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 13858U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 8223U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 11312U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCross, 27U) ^ RotL64(aPrevious, 41U)) + (RotL64(aIngress, 54U) ^ RotL64(aCarry, 11U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterF = ((aWandererK + RotL64(aCross, 37U)) + RotL64(aCarry, 21U)) + 5697928251815176134U;
            aOrbiterK = (aWandererG + RotL64(aPrevious, 35U)) + 337587740689259575U;
            aOrbiterD = ((aWandererF + RotL64(aIngress, 13U)) + 4927686903263973950U) + aNonceWordA;
            aOrbiterG = ((aWandererJ + RotL64(aScatter, 29U)) + 3742409032569801033U) + aNonceWordC;
            aOrbiterH = (aWandererC + RotL64(aCross, 6U)) + 1608092659172197650U;
            aOrbiterJ = ((aWandererI + RotL64(aPrevious, 3U)) + 15848744267145717509U) + aOrbiterAssignSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterA = ((((aWandererD + RotL64(aIngress, 47U)) + RotL64(aCarry, 53U)) + 15300174177963339253U) + aOrbiterAssignSaltF[(((31U - aIndex) + 22U)) & S_SALT1]) + aNonceWordK;
            aOrbiterB = (aWandererE + RotL64(aScatter, 27U)) + 14162868453323648628U;
            aOrbiterC = (aWandererH + RotL64(aCross, 54U)) + 12020167069983729869U;
            aOrbiterE = (aWandererB + RotL64(aIngress, 39U)) + 16259538291658723956U;
            aOrbiterI = ((aWandererA + RotL64(aPrevious, 11U)) + RotL64(aCarry, 41U)) + 8516686212464112245U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 3722184575520553132U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 5663609293306386784U;
            aOrbiterD = RotL64((aOrbiterD * 14364218128780764749U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 15265344442454471986U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterH = (((aOrbiterH ^ aOrbiterG) ^ 3050323350098829515U) ^ aOrbiterUpdateSaltD[((aIndex + 12U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterH = RotL64((aOrbiterH * 5890624677162388135U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 1093356813820599238U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 15167726103772238440U;
            aOrbiterA = RotL64((aOrbiterA * 5719466863561311069U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 15170797965325981472U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 17826286701992981628U;
            aOrbiterG = RotL64((aOrbiterG * 11186808881726573677U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 14710892030473425181U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 397194787697553904U;
            aOrbiterK = RotL64((aOrbiterK * 14368930300818752833U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 1273724124862533034U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 13018397560392545616U;
            aOrbiterF = RotL64((aOrbiterF * 4644812473262395329U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 9638716186445643730U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 7255587739807843785U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 6055682981584011189U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 9272350563697399628U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 1040729335295009339U;
            aOrbiterC = RotL64((aOrbiterC * 17825687660830291443U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 12128124729613601747U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 2285238815562202219U;
            aOrbiterB = RotL64((aOrbiterB * 15398840993074390573U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 6339113298619163493U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 5911895708485037040U) ^ aNonceWordH;
            aOrbiterJ = RotL64((aOrbiterJ * 3271006139923200439U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 7601399508218901328U) + aOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 5697928251815176134U;
            aOrbiterE = RotL64((aOrbiterE * 8184257916861355735U), 53U);
            //
            aIngress = RotL64(aOrbiterI, 11U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 57U));
            aIngress = aIngress + (RotL64(aOrbiterH, 13U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterC, 50U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 53U));
            aIngress = aIngress + RotL64(aOrbiterA, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 58U) + RotL64(aOrbiterJ, 6U)) + aOrbiterF);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 35U) + RotL64(aOrbiterK, 43U)) + aOrbiterI) + RotL64(aCarry, 29U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterA, 13U)) + aOrbiterF) + aWandererUpdateSaltD[((aIndex + 25U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aIngress, 5U) + RotL64(aOrbiterC, 41U)) + aOrbiterH) + RotL64(aCarry, 11U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 19U) + aOrbiterC) + RotL64(aOrbiterI, 3U));
            aWandererD = aWandererD + (((RotL64(aCross, 51U) + aOrbiterC) + RotL64(aOrbiterB, 37U)) + aNonceWordM);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 43U) + aOrbiterA) + RotL64(aOrbiterD, 23U)) + aNonceWordN);
            aWandererF = aWandererF + ((RotL64(aIngress, 37U) + aOrbiterJ) + RotL64(aOrbiterH, 57U));
            aWandererH = aWandererH ^ ((((RotL64(aCross, 29U) + aOrbiterG) + RotL64(aOrbiterC, 27U)) + aNonceWordP) + aWandererUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aScatter, 54U) + RotL64(aOrbiterK, 20U)) + aOrbiterE);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 41U) + aOrbiterE) + RotL64(aOrbiterB, 11U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 60U) ^ aWandererE);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 23U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 47U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 3U));
            aCarry = aCarry + (RotL64(aWandererJ, 34U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererA, 53U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aOperationLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 3
        // ingress from: aOperationLaneB, aExpandLaneD, aWorkLaneC
        // ingress directions: aOperationLaneB forward forced, aExpandLaneD forward forced, aWorkLaneC forward/backward random
        // cross from: aOperationLaneA, aExpandLaneB, aFireLaneC
        // cross directions: aOperationLaneA backward forced, aExpandLaneB backward forced, aFireLaneC backward/forward random
        // write to: aOperationLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneB[((aIndex + 20833U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneD[((aIndex + 18119U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 17518U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 18219U)) & S_BLOCK1], 12U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 21838U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 19335U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCarry, 23U) ^ RotL64(aIngress, 11U)) + (RotL64(aPrevious, 60U) + RotL64(aCross, 47U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterH = (aWandererH + RotL64(aScatter, 10U)) + 10805654776556844351U;
            aOrbiterF = (aWandererG + RotL64(aIngress, 57U)) + 582794182442795335U;
            aOrbiterI = (aWandererJ + RotL64(aCross, 35U)) + 2858343650974681068U;
            aOrbiterG = ((aWandererE + RotL64(aPrevious, 21U)) + 8189584049022064284U) + aNonceWordF;
            aOrbiterJ = ((aWandererF + RotL64(aScatter, 12U)) + 1565100751996962893U) + aNonceWordL;
            aOrbiterD = (aWandererC + RotL64(aPrevious, 53U)) + 8062028016947611891U;
            aOrbiterC = ((aWandererI + RotL64(aCross, 5U)) + 8280504280578451745U) + aOrbiterAssignSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterK = (((aWandererA + RotL64(aIngress, 41U)) + RotL64(aCarry, 37U)) + 11326869194491655350U) + aOrbiterAssignSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterB = ((aWandererB + RotL64(aPrevious, 3U)) + RotL64(aCarry, 27U)) + 1671695656567777163U;
            aOrbiterA = (aWandererD + RotL64(aScatter, 43U)) + 2349843105293943452U;
            aOrbiterE = ((aWandererK + RotL64(aCross, 27U)) + RotL64(aCarry, 5U)) + 13015545152052004254U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 16703354404749291869U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 8713231044374305801U;
            aOrbiterI = RotL64((aOrbiterI * 9242480982197688625U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 11118401674497783533U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 14857556493734710364U;
            aOrbiterD = RotL64((aOrbiterD * 3452566050389715195U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 12953419670951660965U) + aNonceWordM;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 12666121730825089017U;
            aOrbiterK = RotL64((aOrbiterK * 14049925256934142519U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 11075249639473053423U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 9374217688244187867U) ^ aNonceWordG;
            aOrbiterC = RotL64((aOrbiterC * 5261156325627117877U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 17608340953291367867U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 13159437499327086340U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4882100944453534805U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 4304700511322366815U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 10172544755256706767U) ^ aOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4013006212154771797U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 17340067939877432472U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 14130447570008179105U;
            aOrbiterJ = RotL64((aOrbiterJ * 8178075071208718915U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 2652532710498072378U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 10384945384238518296U;
            aOrbiterG = RotL64((aOrbiterG * 17137694272394304045U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 15292159041119433363U) + aOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 12103644911645285108U;
            aOrbiterA = RotL64((aOrbiterA * 4565615406415614103U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 16307525158627275744U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 3786908390177579447U;
            aOrbiterE = RotL64((aOrbiterE * 6592585847755318801U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 13595883419843505634U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 10805654776556844351U;
            aOrbiterB = RotL64((aOrbiterB * 10956465099104915639U), 23U);
            //
            aIngress = RotL64(aOrbiterK, 47U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 58U));
            aIngress = aIngress + (RotL64(aOrbiterH, 3U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterB, 27U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 51U));
            aIngress = aIngress + RotL64(aOrbiterA, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 23U) + aOrbiterI) + RotL64(aOrbiterC, 29U)) + aWandererUpdateSaltC[((aIndex + 6U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aPrevious, 11U) + aOrbiterJ) + RotL64(aOrbiterI, 23U)) + RotL64(aCarry, 19U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 44U) + aOrbiterF) + RotL64(aOrbiterC, 46U));
            aWandererE = aWandererE + ((RotL64(aScatter, 19U) + aOrbiterE) + RotL64(aOrbiterI, 27U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 51U) + aOrbiterK) + RotL64(aOrbiterG, 13U));
            aWandererI = aWandererI + (((RotL64(aCross, 35U) + RotL64(aOrbiterK, 21U)) + aOrbiterD) + RotL64(aCarry, 23U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 26U) + aOrbiterA) + RotL64(aOrbiterJ, 48U));
            aWandererD = aWandererD + (((RotL64(aScatter, 21U) + RotL64(aOrbiterA, 37U)) + aOrbiterK) + aNonceWordI);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 53U) + aOrbiterF) + RotL64(aOrbiterH, 19U)) + aNonceWordB);
            aWandererA = aWandererA + ((RotL64(aPrevious, 3U) + aOrbiterG) + RotL64(aOrbiterJ, 3U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 37U) + aOrbiterE) + RotL64(aOrbiterB, 51U)) + aWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 60U));
            aCarry = aCarry + (RotL64(aWandererG, 53U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererC, 29U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererI, 37U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererF, 34U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aOperationLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 4
        // ingress from: aOperationLaneC, aOperationLaneA, aFireLaneB
        // ingress directions: aOperationLaneC forward forced, aOperationLaneA forward forced, aFireLaneB forward/backward random
        // cross from: aOperationLaneB, aExpandLaneC, aWorkLaneD
        // cross directions: aOperationLaneB backward forced, aExpandLaneC backward forced, aWorkLaneD backward/forward random
        // write to: aOperationLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneC[((aIndex + 26965U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneA[((aIndex + 30111U)) & S_BLOCK1], 34U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 30360U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28913U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 29090U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aWorkLaneD[((aIndex + 25999U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aIngress, 3U) + RotL64(aCarry, 20U)) ^ (RotL64(aPrevious, 35U) ^ RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterA = ((aWandererJ + RotL64(aScatter, 19U)) + 15316464782468770057U) + aOrbiterAssignSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterD = (aWandererE + RotL64(aCross, 47U)) + 6642872057476351588U;
            aOrbiterF = (((aWandererD + RotL64(aPrevious, 29U)) + RotL64(aCarry, 21U)) + 660732654689529192U) + aNonceWordI;
            aOrbiterB = (aWandererI + RotL64(aIngress, 21U)) + 7235418086884000655U;
            aOrbiterH = ((aWandererC + RotL64(aPrevious, 50U)) + 14784518476694580493U) + aNonceWordN;
            aOrbiterG = (aWandererF + RotL64(aScatter, 3U)) + 12222433977933449375U;
            aOrbiterC = ((aWandererH + RotL64(aCross, 41U)) + RotL64(aCarry, 29U)) + 8573001207708329927U;
            aOrbiterE = ((aWandererK + RotL64(aIngress, 27U)) + 16035256260815013172U) + aNonceWordF;
            aOrbiterJ = ((aWandererA + RotL64(aScatter, 53U)) + RotL64(aCarry, 43U)) + 15767726974121910203U;
            aOrbiterI = ((aWandererG + RotL64(aIngress, 11U)) + 17712217935322939971U) + aNonceWordJ;
            aOrbiterK = ((aWandererB + RotL64(aCross, 58U)) + 13488963456923357159U) + aOrbiterAssignSaltD[((aIndex + 8U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 10222949131965611079U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 1495561412321657209U;
            aOrbiterF = RotL64((aOrbiterF * 9706305581868526265U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 16156530750584361434U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 7773792489045606309U;
            aOrbiterH = RotL64((aOrbiterH * 10730624207715601393U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 11544578291333360613U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 3665587867634242865U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4840528190844842595U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 15248434984650998090U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 15487979645426567581U) ^ aOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10868107809356766183U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 6972347795052712690U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 16074994810010431338U;
            aOrbiterG = RotL64((aOrbiterG * 1262655238856775853U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 16851139687900415292U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 14630026837021552812U;
            aOrbiterD = RotL64((aOrbiterD * 9577900853521254603U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 14236330619137368169U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 17778707026111136216U) ^ aNonceWordG;
            aOrbiterB = RotL64((aOrbiterB * 16239561893843454747U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 9390961969105999083U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 1174881758316573228U;
            aOrbiterI = RotL64((aOrbiterI * 6602061268277529311U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 3025148570039849574U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 2813499258480831171U;
            aOrbiterA = RotL64((aOrbiterA * 12272555492688861861U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 15397952138592662354U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 10394648143430175275U;
            aOrbiterK = RotL64((aOrbiterK * 18195627209519212303U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 3043205345760158739U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 15316464782468770057U) ^ aNonceWordA;
            aOrbiterE = RotL64((aOrbiterE * 8162506622688910545U), 57U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterA, 58U);
            aIngress = aIngress + (RotL64(aOrbiterK, 11U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 23U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 29U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 39U));
            aIngress = aIngress + RotL64(aOrbiterG, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aIngress, 13U) + RotL64(aOrbiterE, 19U)) + aOrbiterI);
            aWandererD = aWandererD ^ ((((RotL64(aScatter, 21U) + aOrbiterH) + RotL64(aOrbiterF, 21U)) + aNonceWordP) + aWandererUpdateSaltB[((aIndex + 27U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aCross, 57U) + aOrbiterC) + RotL64(aOrbiterH, 23U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 37U) + RotL64(aOrbiterC, 28U)) + aOrbiterD) + aWandererUpdateSaltF[((aIndex + 19U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aCross, 29U) + aOrbiterB) + RotL64(aOrbiterF, 57U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 40U) + RotL64(aOrbiterJ, 5U)) + aOrbiterC) + aNonceWordC);
            aWandererB = aWandererB + (((RotL64(aScatter, 5U) + RotL64(aOrbiterB, 47U)) + aOrbiterG) + RotL64(aCarry, 53U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterI, 11U)) + aOrbiterJ);
            aWandererG = aWandererG + ((((RotL64(aCross, 11U) + RotL64(aOrbiterJ, 39U)) + aOrbiterK) + RotL64(aCarry, 11U)) + aNonceWordM);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 52U) + RotL64(aOrbiterK, 43U)) + aOrbiterA);
            aWandererH = aWandererH + ((RotL64(aPrevious, 19U) + RotL64(aOrbiterH, 52U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 3U));
            aCarry = aCarry + (RotL64(aWandererG, 58U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererK, 37U) ^ aWandererJ);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 41U));
            aCarry = aCarry + (RotL64(aWandererE, 13U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererB, 51U);
            aCarry = aCarry + RotL64(aIngress, 26U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x85A1BFC6691A49A1ULL + 0xB3E006393990CE61ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xD1AF73966CA96D49ULL + 0xD7F2F9F973F999FCULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xFCA80FFA9E61A399ULL + 0x914DEC7819726B38ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x83E6D086398D17E7ULL + 0xB1E060D4398AF411ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xAC61FD59B7E35AC9ULL + 0xDCF2414236D07E12ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xECBD7D3F73F37BF7ULL + 0x96C87E6EBF123EE1ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xF6D3B3752095A61DULL + 0x9FF4016BCD600FCAULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xB777F0D551E70345ULL + 0xEA89830BD32DAC67ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xB9E941D60F44586BULL + 0xA0D4B0ED5C249731ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0x952E4B16A1315961ULL + 0xD1B7B0FA5D20FA71ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xB43C01849E50E16DULL + 0xD527C8E0BF367CD3ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xEE599DB2DA0439C9ULL + 0x990F397F048FAB3FULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xC595F060359F3FBBULL + 0x8A8FA340D6D2D2BBULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x84014A80418A4F4BULL + 0x854BC2C5C0F8FEA4ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x97CF586A4C5CE7A5ULL + 0x9B586497C41C06E7ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xE4B1AB785B2661CFULL + 0xCC3188231BAD27DBULL);
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
        // read from: aOperationLaneA, aOperationLaneB, aFireLaneA, aOperationLaneC, aOperationLaneD, aWorkLaneD, aExpandLaneA, aWorkLaneC, aFireLaneD, aExpandLaneB, aFireLaneC, aFireLaneB, aExpandLaneC, aWorkLaneA, aWorkLaneB
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_c loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aFireLaneA
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aFireLaneA forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aWorkLaneD
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aWorkLaneD backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 7055U)) & S_BLOCK1], 18U) ^ RotL64(aOperationLaneB[((aIndex + 6754U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 7285U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 250U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 486U)) & S_BLOCK1], 50U));
            aCross ^= RotL64(aWorkLaneD[((aIndex + 7545U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCarry, 23U) ^ RotL64(aPrevious, 41U)) ^ (RotL64(aIngress, 3U) + RotL64(aCross, 54U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterJ = (aWandererD + RotL64(aPrevious, 11U)) + 11480359716598965890U;
            aOrbiterF = (aWandererK + RotL64(aScatter, 29U)) + 15431182525482873419U;
            aOrbiterG = ((aWandererI + RotL64(aCross, 57U)) + 11360504974812776707U) + aNonceWordD;
            aOrbiterK = ((aWandererG + RotL64(aIngress, 18U)) + RotL64(aCarry, 21U)) + 9292576416573382769U;
            aOrbiterI = (aWandererE + RotL64(aPrevious, 23U)) + 1549257414531028975U;
            aOrbiterE = ((aWandererJ + RotL64(aScatter, 39U)) + RotL64(aCarry, 3U)) + 5347769463033129317U;
            aOrbiterB = ((aWandererA + RotL64(aIngress, 47U)) + 17019199177478377234U) + aNonceWordI;
            aOrbiterD = (((aWandererF + RotL64(aCross, 34U)) + RotL64(aCarry, 11U)) + 16558106007323125094U) + aOrbiterAssignSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterC = ((aWandererC + RotL64(aPrevious, 3U)) + 3976182233825939422U) + aOrbiterAssignSaltB[((aIndex + 15U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 2889047161195954395U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 2241831345026962605U;
            aOrbiterG = RotL64((aOrbiterG * 5757458560979927857U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 12850802412140579294U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 13541744735436450160U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 906089290000537439U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 2085863085516538212U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterF) ^ 2969034221711544086U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterB = RotL64((aOrbiterB * 7768528124408400403U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 6482666944512391472U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 16969153556875844613U;
            aOrbiterE = RotL64((aOrbiterE * 9483462388353216219U), 37U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 5161314086757363678U) + aOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 7150282484670673211U;
            aOrbiterD = RotL64((aOrbiterD * 8522427002337918663U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 5465304381272305847U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 2344610773390354017U) ^ aNonceWordP;
            aOrbiterJ = RotL64((aOrbiterJ * 17010258514288089191U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 8335906578006588582U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 13668796013474193793U) ^ aNonceWordK;
            aOrbiterK = RotL64((aOrbiterK * 8228000547141147777U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 9663362594301419686U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 3683773739120343413U;
            aOrbiterC = RotL64((aOrbiterC * 8319320803406104749U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 2538583190438044942U) + aNonceWordE;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 4454069062219406996U;
            aOrbiterI = RotL64((aOrbiterI * 16329554225309389599U), 57U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterC, 27U);
            aIngress = aIngress + (RotL64(aOrbiterD, 5U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterJ, 12U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 23U));
            aIngress = aIngress + RotL64(aOrbiterB, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterB, 57U)) + aOrbiterC);
            aWandererF = aWandererF + (((RotL64(aIngress, 44U) + RotL64(aOrbiterK, 43U)) + aOrbiterE) + RotL64(aCarry, 43U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 3U) + aOrbiterG) + RotL64(aOrbiterB, 13U)) + aNonceWordL);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 23U) + aOrbiterJ) + RotL64(aOrbiterB, 47U)) + RotL64(aCarry, 21U)) + aWandererUpdateSaltD[((aIndex + 25U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aCross, 27U) + aOrbiterJ) + RotL64(aOrbiterD, 20U)) + aWandererUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aScatter, 35U) + RotL64(aOrbiterF, 5U)) + aOrbiterB);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 58U) + aOrbiterB) + RotL64(aOrbiterD, 53U));
            aWandererK = aWandererK + (((RotL64(aIngress, 19U) + RotL64(aOrbiterK, 37U)) + aOrbiterI) + aNonceWordO);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterJ, 26U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 5U));
            aCarry = aCarry + (RotL64(aWandererE, 23U) ^ aWandererA);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 41U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 27U));
            aCarry = aCarry + RotL64(aWandererF, 51U);
            aCarry = aCarry + RotL64(aIngress, 60U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 2
        // ingress from: aExpandLaneA, aOperationLaneC, aWorkLaneC
        // ingress directions: aExpandLaneA forward forced, aOperationLaneC forward forced, aWorkLaneC forward/backward random
        // cross from: aOperationLaneA, aOperationLaneD, aFireLaneD
        // cross directions: aOperationLaneA backward forced, aOperationLaneD backward forced, aFireLaneD backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 11008U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneC[((aIndex + 10800U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 12739U)) & S_BLOCK1], 58U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 12056U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 10925U)) & S_BLOCK1], 12U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 12147U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aIngress, 3U) + RotL64(aCross, 18U)) ^ (RotL64(aPrevious, 51U) ^ RotL64(aCarry, 37U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterG = (aWandererE + RotL64(aPrevious, 48U)) + 7825479804710770560U;
            aOrbiterD = (((aWandererH + RotL64(aIngress, 5U)) + RotL64(aCarry, 3U)) + 5298124167101358123U) + aNonceWordD;
            aOrbiterJ = (((aWandererC + RotL64(aCross, 35U)) + RotL64(aCarry, 13U)) + 17774541024369233726U) + aNonceWordK;
            aOrbiterB = ((aWandererB + RotL64(aScatter, 29U)) + 7679371833537454082U) + aOrbiterAssignSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = (aWandererD + RotL64(aIngress, 53U)) + 5385914900748772224U;
            aOrbiterF = (aWandererF + RotL64(aCross, 23U)) + 3879781930908486531U;
            aOrbiterA = (((aWandererI + RotL64(aScatter, 11U)) + RotL64(aCarry, 29U)) + 659110346638873236U) + aOrbiterAssignSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = (aWandererG + RotL64(aPrevious, 39U)) + 10749021728538539749U;
            aOrbiterH = ((aWandererA + RotL64(aScatter, 58U)) + 3631252455767429457U) + aNonceWordO;
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 2271978810960685021U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 5963558780692551176U;
            aOrbiterJ = RotL64((aOrbiterJ * 4772055335210781149U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 974909966119198104U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 9296998242911152296U;
            aOrbiterC = RotL64((aOrbiterC * 2613629915877957661U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 2245318466901521959U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 13391076374843288568U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 18094558036982107419U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 6184487746594236737U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 1563385912137291418U;
            aOrbiterD = RotL64((aOrbiterD * 4805455299959232321U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 1744840092006498629U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 2100927276837188416U;
            aOrbiterH = RotL64((aOrbiterH * 3541788262067077997U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 9998911862807246338U) + aNonceWordG;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 12239948725635220096U;
            aOrbiterG = RotL64((aOrbiterG * 7098620484129489129U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 3307447094994950246U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 12746613971448298932U;
            aOrbiterF = RotL64((aOrbiterF * 9463975886346934681U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 11577488293733790649U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterB = (((aOrbiterB ^ aOrbiterA) ^ 191108997585598809U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterB = RotL64((aOrbiterB * 9574978681405356871U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 18096145693841273722U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterJ) ^ 10026281133603934071U) ^ aOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterK = RotL64((aOrbiterK * 17261343107314203471U), 43U);
            //
            aIngress = RotL64(aOrbiterB, 40U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 57U));
            aIngress = aIngress + (RotL64(aOrbiterC, 43U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterF, 23U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterH, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aIngress, 10U) + RotL64(aOrbiterH, 51U)) + aOrbiterD) + aNonceWordF) + aWandererUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 51U) + aOrbiterJ) + RotL64(aOrbiterC, 27U));
            aWandererD = aWandererD + ((RotL64(aCross, 29U) + RotL64(aOrbiterC, 34U)) + aOrbiterF);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 35U) + RotL64(aOrbiterK, 3U)) + aOrbiterA) + aWandererUpdateSaltF[((aIndex + 24U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aCross, 21U) + RotL64(aOrbiterB, 43U)) + aOrbiterK) + aNonceWordI);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterB, 47U)) + aOrbiterA) + aNonceWordE);
            aWandererE = aWandererE + (((RotL64(aIngress, 39U) + aOrbiterH) + RotL64(aOrbiterC, 57U)) + RotL64(aCarry, 3U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 44U) + RotL64(aOrbiterK, 14U)) + aOrbiterG);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 57U) + RotL64(aOrbiterJ, 39U)) + aOrbiterA) + RotL64(aCarry, 41U)) + aNonceWordJ);
            //
            aCarry = aCarry + (RotL64(aWandererB, 51U) ^ aWandererI);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 47U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 43U));
            aCarry = aCarry + (RotL64(aWandererA, 39U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererE, 58U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 3
        // ingress from: aExpandLaneB, aOperationLaneD, aFireLaneC
        // ingress directions: aExpandLaneB forward forced, aOperationLaneD forward forced, aFireLaneC forward/backward random
        // cross from: aExpandLaneA, aOperationLaneB, aFireLaneB
        // cross directions: aExpandLaneA backward forced, aOperationLaneB backward forced, aFireLaneB backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 19235U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneD[((aIndex + 21422U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 20253U)) & S_BLOCK1], 36U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 23077U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 20749U)) & S_BLOCK1], 41U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 16963U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCarry, 27U) ^ RotL64(aPrevious, 40U)) + (RotL64(aIngress, 11U) + RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterB = ((aWandererG + RotL64(aCross, 41U)) + RotL64(aCarry, 39U)) + 9751314027302668907U;
            aOrbiterC = ((aWandererD + RotL64(aScatter, 19U)) + RotL64(aCarry, 13U)) + 12175450995523107056U;
            aOrbiterJ = (((aWandererK + RotL64(aIngress, 52U)) + RotL64(aCarry, 21U)) + 17519694958730119552U) + aNonceWordN;
            aOrbiterE = (aWandererJ + RotL64(aPrevious, 35U)) + 9093525527925682263U;
            aOrbiterG = ((aWandererC + RotL64(aScatter, 29U)) + 3713831321786810138U) + aOrbiterAssignSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterA = ((aWandererE + RotL64(aCross, 13U)) + 10108355209191835040U) + aNonceWordJ;
            aOrbiterF = (aWandererI + RotL64(aPrevious, 6U)) + 12956307447311314768U;
            aOrbiterH = ((aWandererB + RotL64(aIngress, 23U)) + 1904298513945877359U) + aOrbiterAssignSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterD = ((aWandererH + RotL64(aCross, 47U)) + 4658049993308574460U) + aNonceWordM;
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 9826333658248851902U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 12058666914724365134U;
            aOrbiterJ = RotL64((aOrbiterJ * 964233873188373939U), 39U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 2516574707110528099U) + aNonceWordG;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 13335308331049750235U;
            aOrbiterA = RotL64((aOrbiterA * 5880227828760598587U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 8230749255538495304U) + aOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 16536559486797811486U;
            aOrbiterE = RotL64((aOrbiterE * 7097036838156464969U), 47U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterH) + 12387639130570188998U) + aOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1]) + aNonceWordE;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 8459259798142872020U;
            aOrbiterG = RotL64((aOrbiterG * 8001346480955847013U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 16083784052002800300U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 1957284290736468379U;
            aOrbiterB = RotL64((aOrbiterB * 5046501301740813065U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 7349538179311335863U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 16395170077006105258U;
            aOrbiterC = RotL64((aOrbiterC * 4230485452156662763U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 3317652065873784068U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 5517155804799120700U) ^ aNonceWordF;
            aOrbiterH = RotL64((aOrbiterH * 9789270651974719183U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 5568525912112200094U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 9334250662962319598U;
            aOrbiterD = RotL64((aOrbiterD * 5034887614541768961U), 21U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 5641394627075994165U) + aNonceWordH;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 13524971148931512745U;
            aOrbiterF = RotL64((aOrbiterF * 3699457147759854357U), 29U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterE, 3U);
            aIngress = aIngress + (RotL64(aOrbiterB, 41U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 30U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 19U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterH, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aScatter, 37U) + aOrbiterD) + RotL64(aOrbiterA, 6U)) + aWandererUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aIngress, 11U) + RotL64(aOrbiterD, 43U)) + aOrbiterE);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterA, 39U)) + aOrbiterF);
            aWandererB = aWandererB + ((RotL64(aCross, 19U) + aOrbiterC) + RotL64(aOrbiterB, 47U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 6U) + aOrbiterJ) + RotL64(aOrbiterG, 56U)) + aNonceWordA);
            aWandererH = aWandererH + ((((RotL64(aIngress, 47U) + RotL64(aOrbiterH, 11U)) + aOrbiterB) + RotL64(aCarry, 51U)) + aNonceWordI);
            aWandererG = aWandererG ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterG, 23U)) + aOrbiterF);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 41U) + aOrbiterJ) + RotL64(aOrbiterE, 27U)) + RotL64(aCarry, 21U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 60U) + RotL64(aOrbiterH, 19U)) + aOrbiterC) + aWandererUpdateSaltC[((aIndex + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 53U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 56U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 35U));
            aCarry = aCarry + (RotL64(aWandererB, 19U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererE, 3U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aWorkLaneA
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aWorkLaneA forward/backward random
        // cross from: aExpandLaneB, aOperationLaneC, aWorkLaneB
        // cross directions: aExpandLaneB backward forced, aOperationLaneC backward forced, aWorkLaneB backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 32764U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneA[((aIndex + 30267U)) & S_BLOCK1], 58U));
            aIngress ^= RotL64(aWorkLaneA[((aIndex + 26776U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32657U)) & S_BLOCK1], 26U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 28510U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 32309U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aPrevious, 37U) + RotL64(aCarry, 11U)) + (RotL64(aIngress, 24U) ^ RotL64(aCross, 51U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterK = ((aWandererH + RotL64(aCross, 29U)) + 3339283916456813609U) + aNonceWordK;
            aOrbiterJ = ((aWandererI + RotL64(aScatter, 11U)) + RotL64(aCarry, 11U)) + 11339086426180649584U;
            aOrbiterB = (aWandererD + RotL64(aIngress, 24U)) + 16819191669329316585U;
            aOrbiterD = (((aWandererC + RotL64(aPrevious, 3U)) + RotL64(aCarry, 3U)) + 8361916937762630725U) + aNonceWordM;
            aOrbiterH = ((aWandererJ + RotL64(aIngress, 47U)) + RotL64(aCarry, 19U)) + 18031328374429899857U;
            aOrbiterF = ((aWandererE + RotL64(aScatter, 43U)) + 18261756894092897276U) + aOrbiterAssignSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = (aWandererB + RotL64(aCross, 18U)) + 4250319792907645666U;
            aOrbiterG = (((aWandererF + RotL64(aPrevious, 39U)) + 1492411503643460886U) + aOrbiterAssignSaltF[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordO;
            aOrbiterC = (aWandererG + RotL64(aCross, 53U)) + 17369549067879344180U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 7301713524358676722U) + aNonceWordI;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 2985193736033012535U;
            aOrbiterB = RotL64((aOrbiterB * 7473297294949338265U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 14086975808140927408U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 10390516547834639800U;
            aOrbiterH = RotL64((aOrbiterH * 11441293212275890819U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 18205555540941493267U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 16967799565443938873U) ^ aNonceWordF;
            aOrbiterA = RotL64((aOrbiterA * 3009081009044782443U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 9209505304067579944U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 3522631966146762306U;
            aOrbiterJ = RotL64((aOrbiterJ * 3441982898533162599U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 8811497120829041188U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 14707301680850257294U;
            aOrbiterK = RotL64((aOrbiterK * 11383709499376464085U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 10080595991787801029U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 6822892187784299166U) ^ aOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7417016898027778287U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 1981637172055758689U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 16463077485583119324U;
            aOrbiterC = RotL64((aOrbiterC * 2876782050665869121U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 8383837717361569465U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 2788511294985017326U;
            aOrbiterF = RotL64((aOrbiterF * 2809163242875130677U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 3529607472855930041U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 8850940802020173766U) ^ aNonceWordN;
            aOrbiterD = RotL64((aOrbiterD * 7821450253655655943U), 3U);
            //
            aIngress = RotL64(aOrbiterJ, 35U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterK, 60U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterB, 13U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterC, 39U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterG, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aScatter, 35U) + aOrbiterH) + RotL64(aOrbiterD, 41U));
            aWandererB = aWandererB + ((((RotL64(aCross, 19U) + aOrbiterG) + RotL64(aOrbiterK, 58U)) + aNonceWordC) + aWandererUpdateSaltD[((aIndex + 20U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 23U) + RotL64(aOrbiterJ, 51U)) + aOrbiterA) + aWandererUpdateSaltB[((aIndex + 11U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aIngress, 13U) + aOrbiterB) + RotL64(aOrbiterA, 27U)) + aNonceWordA);
            aWandererG = aWandererG ^ ((RotL64(aCross, 44U) + RotL64(aOrbiterG, 19U)) + aOrbiterC);
            aWandererD = aWandererD + (((RotL64(aIngress, 27U) + RotL64(aOrbiterK, 46U)) + aOrbiterC) + RotL64(aCarry, 37U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 3U) + aOrbiterF) + RotL64(aOrbiterB, 5U)) + aNonceWordP);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 51U) + aOrbiterG) + RotL64(aOrbiterJ, 35U)) + RotL64(aCarry, 21U)) + aNonceWordJ);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 60U) + RotL64(aOrbiterD, 11U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererI, 54U) ^ aWandererF);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 47U));
            aCarry = aCarry + (RotL64(aWandererE, 23U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererD, 41U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererB, 57U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterD = 0; std::uint64_t aOrbiterE = 0;
    std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
    std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xF81D9A38C127E76DULL + 0x91792F837AF6BFFEULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xE83792ECCC440391ULL + 0xEC2E00C43BBA70DCULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xCF743D0EC5BEAAD1ULL + 0x80558CA61CFB9B45ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xF9FA46E3514AD391ULL + 0xC245A4D13FC6DA2FULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xDAD362DD2E2FBE6FULL + 0x8168D6BB2ED6CF7FULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xF40DB4951B9BD6A3ULL + 0xECF6DE8D7339A23FULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xDEC96C141838D8E1ULL + 0x90298ACF9D162261ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xE03689ACBDC6AF49ULL + 0xACACA19616F0EEDDULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xC20A5CB263A17143ULL + 0xDF5A10DAD0E6D597ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x8191484B11601D8BULL + 0xF63B8DE82B45D56AULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0x9EF9FED87F8773CFULL + 0xBE3A5A2B6E11B671ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xC35B6D9B8D254E9BULL + 0xDE42576862F626FAULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xF6858F9740C4234BULL + 0x88267EEA6AFDA8F7ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xFD7DADF9CD0BC729ULL + 0xAFA69CAF3EC191D3ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xE54E2DD685A01BC5ULL + 0xF2AE5B96FE9AB02DULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xD662B83F53C28A25ULL + 0xEC3D3D21229CBF43ULL);
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
        // read from: aWorkLaneA, aWorkLaneB, aOperationLaneA, aWorkLaneC, aWorkLaneD, aOperationLaneB, aExpandLaneA, aFireLaneB, aFireLaneC, aExpandLaneB, aOperationLaneD, aFireLaneD, aExpandLaneC, aOperationLaneC, aFireLaneA
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_d loop 1
        // ingress from: aWorkLaneA, aWorkLaneB, aOperationLaneA
        // ingress directions: aWorkLaneA forward forced, aWorkLaneB forward forced, aOperationLaneA forward/backward random
        // cross from: aWorkLaneC, aWorkLaneD, aOperationLaneB
        // cross directions: aWorkLaneC backward forced, aWorkLaneD backward forced, aOperationLaneB backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 6142U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((aIndex + 4909U)) & S_BLOCK1], 38U));
            aIngress ^= RotL64(aOperationLaneA[((aIndex + 507U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 2U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 3876U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aOperationLaneB[((aIndex + 556U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCross, 35U)) ^ (RotL64(aCarry, 23U) + RotL64(aPrevious, 50U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterE = (((aWandererH + RotL64(aIngress, 3U)) + 14157904117287696136U) + aOrbiterAssignSaltA[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordK;
            aOrbiterJ = (((aWandererB + RotL64(aCross, 57U)) + RotL64(aCarry, 41U)) + 7369512677371640676U) + aOrbiterAssignSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = (((aWandererK + RotL64(aScatter, 29U)) + RotL64(aCarry, 27U)) + 8411250745902073798U) + aNonceWordC;
            aOrbiterA = ((aWandererA + RotL64(aPrevious, 41U)) + 5002041814539710275U) + aNonceWordA;
            aOrbiterH = (aWandererG + RotL64(aScatter, 50U)) + 9538041410816283124U;
            aOrbiterG = (((aWandererF + RotL64(aPrevious, 19U)) + RotL64(aCarry, 53U)) + 5210700103927513061U) + aNonceWordO;
            aOrbiterK = (aWandererC + RotL64(aIngress, 35U)) + 7600709399101287982U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 2366369466696580499U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 5544575244203019109U;
            aOrbiterB = RotL64((aOrbiterB * 16231219246786333057U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 8710073749110329779U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 15998211310115361630U;
            aOrbiterH = RotL64((aOrbiterH * 15275657696897688955U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 15354357553877376422U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 10657523549259276169U) ^ aOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 13695239532898311073U), 23U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 10405750198355464768U) + aNonceWordE;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 3465819693133515142U) ^ aOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 14678343718277562799U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 16724189641701408630U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 3484340153620198872U) ^ aNonceWordL;
            aOrbiterJ = RotL64((aOrbiterJ * 17247547677520703125U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 7420442404884871126U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 11138445997256757636U;
            aOrbiterK = RotL64((aOrbiterK * 11167543379937571127U), 37U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 1428191560884663125U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 16950093140800653985U;
            aOrbiterG = RotL64((aOrbiterG * 4423012306984814805U), 51U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterE, 3U);
            aIngress = aIngress + (RotL64(aOrbiterG, 13U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 23U));
            aIngress = aIngress + RotL64(aOrbiterK, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aIngress, 41U) + aOrbiterG) + RotL64(aOrbiterB, 58U)) + aWandererUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 3U) + RotL64(aOrbiterJ, 35U)) + aOrbiterH) + RotL64(aCarry, 37U)) + aNonceWordI);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 29U) + aOrbiterA) + RotL64(aOrbiterK, 27U)) + aNonceWordD);
            aWandererB = aWandererB + ((((RotL64(aCross, 23U) + RotL64(aOrbiterA, 19U)) + aOrbiterG) + RotL64(aCarry, 13U)) + aNonceWordN);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 35U) + RotL64(aOrbiterH, 13U)) + aOrbiterE) + aWandererUpdateSaltE[((aIndex + 20U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aPrevious, 51U) + aOrbiterB) + RotL64(aOrbiterK, 5U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 12U) + RotL64(aOrbiterE, 51U)) + aOrbiterJ) + aNonceWordJ);
            //
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererH, 42U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererC, 5U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererB, 35U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 2
        // ingress from: aExpandLaneA, aWorkLaneC, aFireLaneB
        // ingress directions: aExpandLaneA forward forced, aWorkLaneC forward forced, aFireLaneB forward/backward random
        // cross from: aWorkLaneA, aWorkLaneD, aFireLaneC
        // cross directions: aWorkLaneA backward forced, aWorkLaneD backward forced, aFireLaneC backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 15799U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneC[((aIndex + 9284U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 9547U)) & S_BLOCK1], 14U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 10958U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 12245U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 9160U)) & S_BLOCK1], 50U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCross, 29U) ^ RotL64(aPrevious, 41U)) + (RotL64(aIngress, 56U) + RotL64(aCarry, 11U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterF = (aWandererF + RotL64(aIngress, 56U)) + 14624277139785904404U;
            aOrbiterI = (((aWandererC + RotL64(aPrevious, 35U)) + RotL64(aCarry, 3U)) + 6966977309498165611U) + aNonceWordJ;
            aOrbiterA = (((aWandererB + RotL64(aCross, 47U)) + RotL64(aCarry, 53U)) + 205536824352530761U) + aOrbiterAssignSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = (aWandererH + RotL64(aScatter, 19U)) + 16629575265808255692U;
            aOrbiterK = ((aWandererD + RotL64(aIngress, 29U)) + 596881340147972746U) + aNonceWordF;
            aOrbiterD = (((aWandererI + RotL64(aScatter, 5U)) + RotL64(aCarry, 39U)) + 11944412799107412650U) + aOrbiterAssignSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterG = ((aWandererJ + RotL64(aCross, 11U)) + 4615021315668210206U) + aNonceWordL;
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 8497630055977606216U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 11131601107309336885U;
            aOrbiterA = RotL64((aOrbiterA * 18028349768453554935U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 5935883479805510099U) + aOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 15629346719765798174U;
            aOrbiterI = RotL64((aOrbiterI * 8535523790685945275U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 5279128339113651273U) + aOrbiterUpdateSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 16778365912440331821U;
            aOrbiterG = RotL64((aOrbiterG * 705421028266789241U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 16003052937645491524U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 6723226158737614764U) ^ aNonceWordI;
            aOrbiterJ = RotL64((aOrbiterJ * 16690657664909260573U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 9785784358981219543U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 10055457337292292710U;
            aOrbiterK = RotL64((aOrbiterK * 17919129940751761111U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 11779163108592974175U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 1177999477942202687U) ^ aNonceWordO;
            aOrbiterD = RotL64((aOrbiterD * 13475069421684114643U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 9190694445141492214U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 15605342360346353457U;
            aOrbiterF = RotL64((aOrbiterF * 14547769706392595647U), 3U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterA, 36U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 57U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 51U));
            aIngress = aIngress + RotL64(aOrbiterF, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aPrevious, 41U) + aOrbiterD) + RotL64(aOrbiterF, 3U)) + RotL64(aCarry, 53U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 29U) + aOrbiterA) + RotL64(aOrbiterK, 60U));
            aWandererF = aWandererF + ((RotL64(aScatter, 51U) + RotL64(aOrbiterJ, 29U)) + aOrbiterG);
            aWandererI = aWandererI ^ (((RotL64(aCross, 23U) + aOrbiterI) + RotL64(aOrbiterG, 41U)) + aNonceWordB);
            aWandererC = aWandererC + ((((RotL64(aScatter, 57U) + aOrbiterG) + RotL64(aOrbiterA, 11U)) + RotL64(aCarry, 23U)) + aWandererUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((((RotL64(aPrevious, 35U) + RotL64(aOrbiterA, 51U)) + aOrbiterD) + aNonceWordE) + aWandererUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 12U) + RotL64(aOrbiterF, 21U)) + aOrbiterI) + aNonceWordK);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 39U));
            aCarry = aCarry + (RotL64(aWandererC, 58U) ^ aWandererD);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 23U));
            aCarry = aCarry + RotL64(aWandererJ, 19U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 3
        // ingress from: aExpandLaneB, aWorkLaneD, aOperationLaneD
        // ingress directions: aExpandLaneB forward forced, aWorkLaneD forward forced, aOperationLaneD forward/backward random
        // cross from: aExpandLaneA, aWorkLaneB, aFireLaneD
        // cross directions: aExpandLaneA backward forced, aWorkLaneB backward forced, aFireLaneD backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 22122U)) & S_BLOCK1], 4U) ^ RotL64(aWorkLaneD[((aIndex + 22941U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 20576U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 22793U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 22947U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 16863U)) & S_BLOCK1], 54U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aPrevious, 43U) ^ RotL64(aCarry, 13U)) + (RotL64(aCross, 29U) ^ RotL64(aIngress, 58U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterH = (((aWandererI + RotL64(aCross, 57U)) + RotL64(aCarry, 53U)) + 11698283336767769359U) + aNonceWordB;
            aOrbiterA = ((aWandererB + RotL64(aIngress, 47U)) + 13297826354831483872U) + aOrbiterAssignSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterE = (((aWandererF + RotL64(aScatter, 23U)) + RotL64(aCarry, 13U)) + 15254999058287530795U) + aNonceWordD;
            aOrbiterD = (aWandererK + RotL64(aPrevious, 13U)) + 17474166585085346567U;
            aOrbiterJ = (aWandererE + RotL64(aCross, 41U)) + 15684783498452840289U;
            aOrbiterF = (((aWandererG + RotL64(aScatter, 5U)) + 5061229733465216486U) + aOrbiterAssignSaltC[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordP;
            aOrbiterG = ((aWandererA + RotL64(aPrevious, 30U)) + RotL64(aCarry, 41U)) + 15370981279168377944U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 17966672773619554092U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 14685092893994491068U;
            aOrbiterE = RotL64((aOrbiterE * 1627758964162892429U), 39U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 12798804186209406389U) + aNonceWordF;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 2848444181474221574U;
            aOrbiterH = RotL64((aOrbiterH * 13730480364920876877U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 8551142075919636146U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 8833198159158950723U) ^ aOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7650289040764974737U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 7351473160893666232U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 14204899612487622222U;
            aOrbiterA = RotL64((aOrbiterA * 6317485031956448029U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 7008985178526543258U) + aOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 13576796403863120356U;
            aOrbiterF = RotL64((aOrbiterF * 13745839827679114077U), 57U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterD) + 5769784656937900699U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordN;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 14075925808204936705U;
            aOrbiterJ = RotL64((aOrbiterJ * 5844894088757604713U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 17818667502858010896U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 16016922065572683130U;
            aOrbiterD = RotL64((aOrbiterD * 7525645833898085373U), 27U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterJ, 19U);
            aIngress = aIngress + (RotL64(aOrbiterD, 35U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 10U));
            aIngress = aIngress + RotL64(aOrbiterA, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterD, 48U)) + aOrbiterF);
            aWandererE = aWandererE + ((((RotL64(aCross, 23U) + aOrbiterG) + RotL64(aOrbiterJ, 29U)) + aNonceWordC) + aWandererUpdateSaltC[((aIndex + 15U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 54U) + RotL64(aOrbiterF, 57U)) + aOrbiterE) + aWandererUpdateSaltA[((aIndex + 17U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aScatter, 47U) + RotL64(aOrbiterA, 41U)) + aOrbiterE) + RotL64(aCarry, 43U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterG, 13U)) + aOrbiterF);
            aWandererG = aWandererG + ((((RotL64(aCross, 29U) + aOrbiterD) + RotL64(aOrbiterG, 3U)) + RotL64(aCarry, 3U)) + aNonceWordO);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 41U) + aOrbiterD) + RotL64(aOrbiterH, 21U)) + aNonceWordK);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 21U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 12U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 39U));
            aCarry = aCarry + RotL64(aWandererG, 5U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aOperationLaneC
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aOperationLaneC forward/backward random
        // cross from: aExpandLaneB, aWorkLaneC, aFireLaneA
        // cross directions: aExpandLaneB backward forced, aWorkLaneC backward forced, aFireLaneA backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 24820U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneA[((aIndex + 29010U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aOperationLaneC[((aIndex + 26024U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31905U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 26990U)) & S_BLOCK1], 36U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 28631U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCarry, 27U) + RotL64(aPrevious, 60U)) + (RotL64(aCross, 39U) ^ RotL64(aIngress, 13U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterJ = ((aWandererC + RotL64(aCross, 29U)) + 6973892330986118220U) + aNonceWordH;
            aOrbiterI = (((aWandererI + RotL64(aScatter, 60U)) + RotL64(aCarry, 3U)) + 9886813896272094864U) + aNonceWordM;
            aOrbiterF = (((aWandererJ + RotL64(aPrevious, 41U)) + RotL64(aCarry, 53U)) + 10996306582517553173U) + aNonceWordO;
            aOrbiterB = ((aWandererF + RotL64(aIngress, 51U)) + 8490648283899856223U) + aOrbiterAssignSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterG = ((aWandererA + RotL64(aCross, 19U)) + RotL64(aCarry, 39U)) + 105141713530704655U;
            aOrbiterA = (((aWandererG + RotL64(aIngress, 11U)) + 3114337422810562588U) + aOrbiterAssignSaltA[((aIndex + 11U)) & S_SALT1]) + aNonceWordP;
            aOrbiterK = (aWandererB + RotL64(aScatter, 3U)) + 980857684690886131U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 6562042345807072665U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 15665371138706353619U) ^ aOrbiterUpdateSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8086237578564620623U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 18113013571374375028U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 17405346422601997299U;
            aOrbiterG = RotL64((aOrbiterG * 11162604605443005253U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 5130876096426182506U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 1813821672299154629U;
            aOrbiterI = RotL64((aOrbiterI * 15478100342425611875U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 15793814882743306728U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 13925299440495476399U;
            aOrbiterA = RotL64((aOrbiterA * 12049601510660117401U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 9924458846049579438U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 7810034662781768090U) ^ aNonceWordK;
            aOrbiterK = RotL64((aOrbiterK * 10310594595026622513U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 12812586478656872854U) + aOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 5709576448057435237U) ^ aNonceWordD;
            aOrbiterJ = RotL64((aOrbiterJ * 9101555233909853025U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 7839807649914541516U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 4717944526755429647U) ^ aNonceWordN;
            aOrbiterB = RotL64((aOrbiterB * 8515229146471335721U), 41U);
            //
            aIngress = RotL64(aOrbiterG, 43U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterA, 23U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterB, 10U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterI, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aIngress, 57U) + RotL64(aOrbiterB, 39U)) + aOrbiterK) + RotL64(aCarry, 11U));
            aWandererG = aWandererG ^ ((((RotL64(aCross, 5U) + aOrbiterA) + RotL64(aOrbiterG, 51U)) + aNonceWordA) + aWandererUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 19U) + aOrbiterI) + RotL64(aOrbiterJ, 26U)) + aWandererUpdateSaltF[((aIndex + 3U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 11U) + aOrbiterI) + RotL64(aOrbiterF, 3U)) + aNonceWordJ);
            aWandererC = aWandererC + ((((RotL64(aScatter, 41U) + aOrbiterG) + RotL64(aOrbiterF, 57U)) + RotL64(aCarry, 53U)) + aNonceWordI);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 34U) + aOrbiterG) + RotL64(aOrbiterK, 19U));
            aWandererJ = aWandererJ + ((RotL64(aCross, 47U) + aOrbiterA) + RotL64(aOrbiterI, 11U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 43U) ^ aWandererJ);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 5U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 20U));
            aCarry = aCarry + RotL64(aWandererA, 51U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA;
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
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltC;
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
    [[maybe_unused]] std::uint64_t *aPhaseHWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseHWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltD;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xF070E16E0D3C476BULL + 0x86BDC84792F7E379ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xE7F1FAE40DAF57A5ULL + 0xD148368C926CABE3ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xE8239B09581E227FULL + 0x82B266BFDF9B5242ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xD64BC8C5674F2419ULL + 0xDF31D5AC6AE22416ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xB5DF159314D570F3ULL + 0x80EA40DDA2AEF355ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x8B13C583E29E21E7ULL + 0xA0C8343BDD1FFDE7ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xFDCEED1097521525ULL + 0xB40D33089363E68EULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x97E66866951670A1ULL + 0xFA70A62031B87612ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x906594DE8DC171B1ULL + 0xE2A982CF253BBB2BULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xAFC0AF37D3643CD9ULL + 0xED38C1C9F83BB776ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xEF1A7D44E20645EFULL + 0xA82BA53D3C064966ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xD4A713A5F1567FCDULL + 0xEDA4F75348491E00ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xD43CD6A238F43FCFULL + 0xE8F677F72897B32AULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x95027A112B6277BDULL + 0xE227AC06311F6905ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xD87859AB9FE41321ULL + 0xD46FC379A4E83EA6ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xF56C92C25C256111ULL + 0xC9801A55CE526F8DULL);
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
            aIngress = RotL64(aKeyRowReadA[((aIndex + 2054U)) & W_KEY1], 47U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 904U)) & W_KEY1], 37U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 2194U)) & W_KEY1], 26U) ^ RotL64(mSource[((aIndex + 2166U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCarry, 30U) + RotL64(aPrevious, 11U)) + (RotL64(aIngress, 43U) ^ RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterF = ((aWandererJ + RotL64(aIngress, 35U)) + RotL64(aCarry, 23U)) + 11450949896247900941U;
            aOrbiterH = (((aWandererH + RotL64(aPrevious, 21U)) + RotL64(aCarry, 53U)) + 3905542253538116335U) + aNonceWordH;
            aOrbiterC = (((aWandererA + RotL64(aCross, 41U)) + RotL64(aCarry, 41U)) + 9529740545977785305U) + aNonceWordB;
            aOrbiterD = (((aWandererE + RotL64(aScatter, 60U)) + 1856876631533143492U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordC;
            aOrbiterG = ((aWandererI + RotL64(aPrevious, 13U)) + 84253466320181686U) + aPhaseEOrbiterAssignSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = ((aWandererB + RotL64(aCross, 51U)) + 12577480918745432444U) + aNonceWordD;
            aOrbiterK = (aWandererF + RotL64(aScatter, 3U)) + 5625703170397704029U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 694608607323629282U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 3993981243536262204U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2502835860198146381U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 4119215953484892051U) + aNonceWordM;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 8785040118556157146U;
            aOrbiterG = RotL64((aOrbiterG * 17113521266125471625U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 16234403619456882890U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 10398727475672860610U;
            aOrbiterB = RotL64((aOrbiterB * 5086871400049644715U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 18327987141759096769U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 2645964788056875452U;
            aOrbiterH = RotL64((aOrbiterH * 8778681366114628045U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 2859452497983106129U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 7196557924940881076U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 14415389907490256711U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 930127943984174668U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 15673596916054795749U;
            aOrbiterD = RotL64((aOrbiterD * 7505660488733199479U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 16673140529110941163U) + aNonceWordE;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 2258448294877833760U) ^ aNonceWordO;
            aOrbiterF = RotL64((aOrbiterF * 1821550319748977445U), 57U);
            //
            aIngress = RotL64(aOrbiterK, 3U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 21U));
            aIngress = aIngress + (RotL64(aOrbiterC, 47U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterH, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aIngress, 37U) + aOrbiterF) + RotL64(aOrbiterK, 23U)) + aNonceWordP);
            aWandererB = aWandererB + ((((RotL64(aScatter, 19U) + RotL64(aOrbiterF, 60U)) + aOrbiterG) + RotL64(aCarry, 37U)) + aNonceWordI);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 43U) + aOrbiterD) + RotL64(aOrbiterB, 11U)) + aPhaseEWandererUpdateSaltB[((aIndex + 9U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aCross, 30U) + aOrbiterD) + RotL64(aOrbiterK, 41U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 57U) + aOrbiterD) + RotL64(aOrbiterF, 3U)) + aNonceWordF);
            aWandererE = aWandererE + (((RotL64(aIngress, 5U) + RotL64(aOrbiterK, 29U)) + aOrbiterH) + RotL64(aCarry, 21U));
            aWandererJ = aWandererJ ^ ((((RotL64(aCross, 51U) + RotL64(aOrbiterK, 51U)) + aOrbiterC) + aNonceWordK) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 56U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 39U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 19U));
            aCarry = aCarry + RotL64(aWandererA, 29U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 4277U)) & S_BLOCK1], 60U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 5029U)) & W_KEY1], 37U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 4256U)) & W_KEY1], 48U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 5332U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCarry, 35U) ^ RotL64(aIngress, 5U)) + (RotL64(aCross, 47U) ^ RotL64(aPrevious, 18U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterK = ((aWandererH + RotL64(aIngress, 29U)) + RotL64(aCarry, 47U)) + 3255291173184001106U;
            aOrbiterI = ((aWandererG + RotL64(aCross, 19U)) + 15308468160116255528U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterC = (aWandererE + RotL64(aScatter, 35U)) + 18186972408589866656U;
            aOrbiterJ = ((aWandererJ + RotL64(aPrevious, 41U)) + 4439324265978331914U) + aNonceWordA;
            aOrbiterH = (aWandererK + RotL64(aIngress, 3U)) + 13099263173016322486U;
            aOrbiterB = ((((aWandererA + RotL64(aPrevious, 58U)) + RotL64(aCarry, 11U)) + 7041561081767500660U) + aPhaseEOrbiterAssignSaltF[((aIndex + 11U)) & S_SALT1]) + aNonceWordK;
            aOrbiterD = ((aWandererD + RotL64(aScatter, 51U)) + RotL64(aCarry, 35U)) + 6196422612687812971U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 7664260932541281413U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterC = (((aOrbiterC ^ aOrbiterK) ^ 17802347823020441056U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterC = RotL64((aOrbiterC * 2220679459017369255U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 4253107484061190446U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 13799496534030645312U;
            aOrbiterK = RotL64((aOrbiterK * 9167675060053848207U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 14252892847595951926U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 5663527578664291422U) ^ aNonceWordB;
            aOrbiterH = RotL64((aOrbiterH * 18314294235895182465U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 11148755959699137661U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 17036900929333594592U;
            aOrbiterJ = RotL64((aOrbiterJ * 16041243617369003291U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 2403828181385259549U) + aNonceWordE;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 17813580350434928194U;
            aOrbiterI = RotL64((aOrbiterI * 13666780980793857831U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 5623611126885414523U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 7293224381174846969U;
            aOrbiterD = RotL64((aOrbiterD * 7032561584670788117U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 10602620906929686163U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 18015916257203385982U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10684090189688871993U), 51U);
            //
            aIngress = RotL64(aOrbiterJ, 29U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterB, 60U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterI, 5U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterC, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterH, 21U)) + aOrbiterJ);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 23U) + RotL64(aOrbiterB, 43U)) + aOrbiterC) + RotL64(aCarry, 27U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterI, 10U)) + aOrbiterH);
            aWandererK = aWandererK + (((((RotL64(aScatter, 41U) + RotL64(aOrbiterC, 3U)) + aOrbiterK) + RotL64(aCarry, 5U)) + aNonceWordL) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aCross, 14U) + aOrbiterH) + RotL64(aOrbiterD, 57U)) + aPhaseEWandererUpdateSaltF[((aIndex + 19U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterC, 51U)) + aOrbiterD) + aNonceWordO);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterH, 29U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererA, 6U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererD, 51U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererH, 19U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererG, 39U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = RotL64(aWorkLaneB[((aIndex + 6256U)) & S_BLOCK1], 23U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 8091U)) & W_KEY1], 46U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 6852U)) & W_KEY1], 19U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 7087U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 6389U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aPrevious, 21U) + RotL64(aCross, 52U)) ^ (RotL64(aCarry, 35U) + RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterG = ((aWandererA + RotL64(aIngress, 35U)) + RotL64(aCarry, 57U)) + 12849591986267890852U;
            aOrbiterA = (aWandererG + RotL64(aPrevious, 20U)) + 8232614804696815750U;
            aOrbiterC = (((aWandererH + RotL64(aScatter, 47U)) + 12141567259210877281U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordB;
            aOrbiterB = ((aWandererF + RotL64(aCross, 27U)) + RotL64(aCarry, 27U)) + 2928641981037885644U;
            aOrbiterK = (((aWandererI + RotL64(aScatter, 5U)) + RotL64(aCarry, 41U)) + 980733350554783938U) + aNonceWordE;
            aOrbiterI = ((aWandererE + RotL64(aIngress, 11U)) + 2683985177993350746U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterE = ((aWandererB + RotL64(aPrevious, 41U)) + 14532148403815527355U) + aNonceWordK;
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 7736296629433884203U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 10428437770166310549U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 326634742742373401U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 18327174144859461029U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 6810436935194432002U) ^ aNonceWordF;
            aOrbiterB = RotL64((aOrbiterB * 2715987179577753597U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 12606153309690753435U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 17123256945895150555U;
            aOrbiterE = RotL64((aOrbiterE * 13469111258504672565U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 9057777759026189541U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 16478485918911194442U;
            aOrbiterA = RotL64((aOrbiterA * 11054247078884894131U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 18064460487552100483U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 11477276762421684083U) ^ aNonceWordH;
            aOrbiterK = RotL64((aOrbiterK * 3886501230380184395U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 18318375441973295081U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 13849305985380030986U;
            aOrbiterG = RotL64((aOrbiterG * 12962140243967824959U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 10240409420338313641U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 18360586077779529086U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 18196875422391501927U), 41U);
            //
            aIngress = RotL64(aOrbiterG, 3U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 11U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 57U));
            aIngress = aIngress + RotL64(aOrbiterA, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aScatter, 60U) + aOrbiterK) + RotL64(aOrbiterE, 57U));
            aWandererE = aWandererE + ((((RotL64(aCross, 3U) + RotL64(aOrbiterI, 14U)) + aOrbiterK) + RotL64(aCarry, 19U)) + aPhaseEWandererUpdateSaltC[((aIndex + 7U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((((RotL64(aPrevious, 13U) + aOrbiterB) + RotL64(aOrbiterI, 51U)) + aNonceWordM) + aPhaseEWandererUpdateSaltE[((aIndex + 5U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aIngress, 23U) + aOrbiterC) + RotL64(aOrbiterA, 39U)) + RotL64(aCarry, 5U)) + aNonceWordG);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 53U) + RotL64(aOrbiterG, 29U)) + aOrbiterI) + aNonceWordO);
            aWandererH = aWandererH + (((RotL64(aIngress, 29U) + RotL64(aOrbiterA, 3U)) + aOrbiterB) + aNonceWordL);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 47U) + aOrbiterA) + RotL64(aOrbiterG, 21U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 11U));
            aCarry = aCarry + (RotL64(aWandererA, 19U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererI, 42U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererG, 35U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 9931U)) & S_BLOCK1], 39U) ^ RotL64(aKeyRowReadB[((aIndex + 8947U)) & W_KEY1], 56U));
            aIngress ^= (RotL64(mSource[((aIndex + 9741U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneA[((aIndex + 9725U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordE));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 9034U)) & W_KEY1], 26U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 9188U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCross, 43U) + RotL64(aPrevious, 14U)) ^ (RotL64(aCarry, 29U) + RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterD = ((aWandererK + RotL64(aPrevious, 26U)) + 13960289014350612206U) + aNonceWordM;
            aOrbiterC = ((aWandererJ + RotL64(aCross, 57U)) + RotL64(aCarry, 51U)) + 3483331015269589730U;
            aOrbiterJ = (((aWandererC + RotL64(aScatter, 19U)) + RotL64(aCarry, 3U)) + 6873299241002444518U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = ((aWandererG + RotL64(aIngress, 35U)) + 3562094007125534229U) + aNonceWordP;
            aOrbiterI = ((aWandererA + RotL64(aPrevious, 13U)) + 11422367439932782705U) + aPhaseFOrbiterAssignSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterE = ((aWandererB + RotL64(aIngress, 43U)) + RotL64(aCarry, 37U)) + 532453428514259816U;
            aOrbiterA = (aWandererD + RotL64(aCross, 3U)) + 17810941465810193088U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 11869759058631106331U) + aNonceWordO;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 8837581071876177566U;
            aOrbiterJ = RotL64((aOrbiterJ * 15329827515970522213U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 17185378327053837778U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 7578253375676981500U;
            aOrbiterE = RotL64((aOrbiterE * 13371647568758721729U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 17112646434432814442U) + aNonceWordH;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 14949096407295697881U;
            aOrbiterC = RotL64((aOrbiterC * 14770977858283051753U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 4259590620758467836U) + aNonceWordG;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 6534899413644542303U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7987609419215568661U), 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 2637407498893694243U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 15819295597921425711U;
            aOrbiterI = RotL64((aOrbiterI * 5202015597375051399U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 6373559542002699718U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 11694562937392022505U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 9311557972331218597U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 3308736483775453062U) + aNonceWordN;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 12749929710650475901U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 248428400724560945U), 23U);
            //
            aIngress = RotL64(aOrbiterC, 23U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 5U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 13U));
            aIngress = aIngress + RotL64(aOrbiterF, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aIngress, 19U) + RotL64(aOrbiterI, 57U)) + aOrbiterF) + RotL64(aCarry, 41U)) + aNonceWordD);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterE, 51U)) + aOrbiterF);
            aWandererA = aWandererA + (((RotL64(aPrevious, 37U) + RotL64(aOrbiterC, 35U)) + aOrbiterD) + aPhaseFWandererUpdateSaltB[((aIndex + 11U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 3U) + aOrbiterI) + RotL64(aOrbiterD, 19U));
            aWandererB = aWandererB + (((RotL64(aIngress, 11U) + aOrbiterJ) + RotL64(aOrbiterA, 12U)) + aPhaseFWandererUpdateSaltD[((aIndex + 3U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aCross, 29U) + aOrbiterF) + RotL64(aOrbiterA, 41U)) + aNonceWordC);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 58U) + RotL64(aOrbiterA, 29U)) + aOrbiterC) + RotL64(aCarry, 19U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 23U));
            aCarry = aCarry + (RotL64(aWandererC, 12U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererB, 53U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererA, 39U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = (RotL64(aWorkLaneD[((aIndex + 12477U)) & S_BLOCK1], 35U) ^ RotL64(aKeyRowReadA[((aIndex + 12629U)) & W_KEY1], 47U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 13292U)) & W_KEY1], 3U) ^ RotL64(mSource[((aIndex + 11709U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aWorkLaneB[((aIndex + 10966U)) & S_BLOCK1], 56U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 13313U)) & S_BLOCK1], 36U) ^ RotL64(aWorkLaneC[((aIndex + 11724U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aIngress, 19U) ^ RotL64(aCross, 38U)) + (RotL64(aCarry, 5U) + RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterD = (aWandererH + RotL64(aCross, 41U)) + 2330952702412094686U;
            aOrbiterC = ((aWandererC + RotL64(aPrevious, 21U)) + 7820188225935060799U) + aPhaseFOrbiterAssignSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = (((aWandererA + RotL64(aScatter, 47U)) + RotL64(aCarry, 5U)) + 9347644591709839145U) + aNonceWordJ;
            aOrbiterJ = (aWandererJ + RotL64(aIngress, 53U)) + 2288624878446846870U;
            aOrbiterA = (((aWandererB + RotL64(aPrevious, 35U)) + 9358977729492824128U) + aPhaseFOrbiterAssignSaltC[((aIndex + 25U)) & S_SALT1]) + aNonceWordC;
            aOrbiterE = ((aWandererI + RotL64(aIngress, 28U)) + RotL64(aCarry, 19U)) + 1858511275052455039U;
            aOrbiterG = ((aWandererE + RotL64(aCross, 13U)) + RotL64(aCarry, 47U)) + 13715478509322292552U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 16413396625604260455U) + aNonceWordB;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 17714322215518432705U;
            aOrbiterI = RotL64((aOrbiterI * 1904184102419934333U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 16188315436202861122U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 5564445841368207813U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 14125834616162835983U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 13717068949900594673U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 14143659432287313765U) ^ aNonceWordE;
            aOrbiterJ = RotL64((aOrbiterJ * 17281441046722262917U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 5729546141908425670U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 4297827922736712074U;
            aOrbiterC = RotL64((aOrbiterC * 13631630436759768885U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 829520109395163673U) + aNonceWordK;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 11547160328525174295U;
            aOrbiterD = RotL64((aOrbiterD * 4759690159673049775U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 2907177944512117206U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 11100346409065275671U;
            aOrbiterE = RotL64((aOrbiterE * 17927994356809011637U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 1344592529249949068U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 6470438516791143572U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 13339390828725370475U), 51U);
            //
            aIngress = RotL64(aOrbiterC, 29U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterI, 60U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterD, 3U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterJ, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((((RotL64(aIngress, 53U) + RotL64(aOrbiterD, 43U)) + aOrbiterC) + aNonceWordG) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aPrevious, 60U) + aOrbiterI) + RotL64(aOrbiterD, 58U)) + RotL64(aCarry, 3U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterJ, 11U)) + aOrbiterD) + aNonceWordO);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 5U) + RotL64(aOrbiterA, 27U)) + aOrbiterJ) + aNonceWordH);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 37U) + aOrbiterD) + RotL64(aOrbiterE, 21U)) + aNonceWordI);
            aWandererI = aWandererI + (((RotL64(aScatter, 29U) + aOrbiterC) + RotL64(aOrbiterG, 37U)) + RotL64(aCarry, 21U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 11U) + aOrbiterE) + RotL64(aOrbiterC, 51U)) + aPhaseFWandererUpdateSaltC[((aIndex + 16U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 12U));
            aCarry = aCarry + (RotL64(aWandererH, 27U) ^ aWandererI);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + RotL64(aWandererB, 3U);
            aCarry = aCarry + RotL64(aIngress, 54U);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 15263U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 15536U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 14666U)) & W_KEY1], 29U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 14636U)) & W_KEY1], 57U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 14830U)) & S_BLOCK1], 48U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 14278U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 15637U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCarry, 52U)) ^ (RotL64(aCross, 35U) ^ RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterK = ((aWandererC + RotL64(aScatter, 13U)) + RotL64(aCarry, 53U)) + 12690502671561165478U;
            aOrbiterA = ((aWandererF + RotL64(aPrevious, 27U)) + 17519943923428102801U) + aNonceWordF;
            aOrbiterH = ((aWandererK + RotL64(aIngress, 51U)) + 10705515807975331385U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterF = ((aWandererG + RotL64(aCross, 37U)) + RotL64(aCarry, 41U)) + 16586447272278538179U;
            aOrbiterJ = (((aWandererB + RotL64(aIngress, 4U)) + RotL64(aCarry, 19U)) + 8006560996840971798U) + aNonceWordE;
            aOrbiterI = ((aWandererD + RotL64(aCross, 43U)) + 12928600185788857701U) + aPhaseFOrbiterAssignSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = ((aWandererI + RotL64(aPrevious, 19U)) + 14240723153798267172U) + aNonceWordH;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 8636219177994872072U) + aNonceWordL;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 7586790235186467512U;
            aOrbiterH = RotL64((aOrbiterH * 15052686382507614169U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 1103807034179512424U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 7547526530239498693U;
            aOrbiterJ = RotL64((aOrbiterJ * 3360295583636013509U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 8380239679344786397U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 5690809173787433519U;
            aOrbiterK = RotL64((aOrbiterK * 5354724308093372953U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 8390902801141804609U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 3507306189192059486U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 18336280496510253103U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 6190745292098482871U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 8065418693975056902U) ^ aNonceWordN;
            aOrbiterB = RotL64((aOrbiterB * 6414621418430102589U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 12111755051718111803U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 7605877769709909297U) ^ aNonceWordC;
            aOrbiterF = RotL64((aOrbiterF * 17525248694315944599U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 5969794501112646237U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterA = (((aOrbiterA ^ aOrbiterI) ^ 5127559299360591476U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterA = RotL64((aOrbiterA * 4521563633438853069U), 35U);
            //
            aIngress = RotL64(aOrbiterB, 35U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 14U));
            aIngress = aIngress + (RotL64(aOrbiterK, 57U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterH, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((((RotL64(aCross, 5U) + aOrbiterK) + RotL64(aOrbiterH, 29U)) + aNonceWordD) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aIngress, 37U) + aOrbiterK) + RotL64(aOrbiterA, 42U)) + RotL64(aCarry, 11U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 21U) + aOrbiterJ) + RotL64(aOrbiterA, 51U)) + aNonceWordA);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 11U) + RotL64(aOrbiterA, 5U)) + aOrbiterF) + aNonceWordO) + aPhaseFWandererUpdateSaltC[((aIndex + 26U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 27U) + aOrbiterB) + RotL64(aOrbiterI, 23U));
            aWandererG = aWandererG + (((RotL64(aScatter, 44U) + RotL64(aOrbiterI, 13U)) + aOrbiterA) + RotL64(aCarry, 39U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 57U) + aOrbiterJ) + RotL64(aOrbiterI, 57U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 4U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 43U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 29U));
            aCarry = aCarry + RotL64(aWandererC, 19U);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 16697U)) & S_BLOCK1], 11U) ^ RotL64(aKeyRowReadA[((aIndex + 18172U)) & W_KEY1], 39U));
            aIngress ^= (RotL64(mSource[((aIndex + 17617U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneA[((aIndex + 16751U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 17914U)) & W_KEY1], 5U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 17615U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 17156U)) & S_BLOCK1], 24U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aPrevious, 19U) + RotL64(aCarry, 34U)) ^ (RotL64(aIngress, 51U) ^ RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterH = (aWandererI + RotL64(aIngress, 47U)) + 4476099022490972343U;
            aOrbiterD = ((aWandererC + RotL64(aScatter, 29U)) + 16836423700375760429U) + aPhaseGOrbiterAssignSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = ((aWandererF + RotL64(aCross, 41U)) + RotL64(aCarry, 11U)) + 8850577488928703557U;
            aOrbiterK = (aWandererK + RotL64(aPrevious, 21U)) + 7091631824560042743U;
            aOrbiterG = (((aWandererJ + RotL64(aIngress, 5U)) + RotL64(aCarry, 23U)) + 12560498899956759494U) + aNonceWordM;
            aOrbiterC = ((aWandererH + RotL64(aScatter, 35U)) + 7797973377112012161U) + aPhaseGOrbiterAssignSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = (((aWandererG + RotL64(aPrevious, 54U)) + RotL64(aCarry, 43U)) + 6173820673874805794U) + aNonceWordL;
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 10805025132310245348U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 7139216143268029968U;
            aOrbiterJ = RotL64((aOrbiterJ * 8349754682635765573U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 8241544862261635722U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterD) ^ 4735527016563596150U) ^ aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterG = RotL64((aOrbiterG * 6621354217673598381U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 5166171126690294033U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 11117641762075368393U;
            aOrbiterC = RotL64((aOrbiterC * 4980156869201219393U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 6312932356458415421U) + aNonceWordI;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 1304139291184508668U;
            aOrbiterK = RotL64((aOrbiterK * 90744653170922319U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 10085025354842771067U) + aNonceWordG;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 16745854428789531080U;
            aOrbiterH = RotL64((aOrbiterH * 1945983905747274355U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 2497187958708890337U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 16069701876646548995U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 16606039730973709495U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 17242004368025978091U) + aPhaseGOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = (((aOrbiterD ^ aOrbiterA) ^ 12334315722243232121U) ^ aPhaseGOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterD = RotL64((aOrbiterD * 16528598396696346719U), 41U);
            //
            aIngress = RotL64(aOrbiterJ, 11U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterK, 3U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 23U));
            aIngress = aIngress + RotL64(aOrbiterA, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aIngress, 29U) + aOrbiterH) + RotL64(aOrbiterK, 37U)) + RotL64(aCarry, 23U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 53U) + RotL64(aOrbiterA, 43U)) + aOrbiterC) + aPhaseGWandererUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 47U) + aOrbiterC) + RotL64(aOrbiterJ, 29U)) + RotL64(aCarry, 35U));
            aWandererF = aWandererF ^ ((((RotL64(aCross, 13U) + RotL64(aOrbiterG, 19U)) + aOrbiterC) + aNonceWordO) + aPhaseGWandererUpdateSaltC[((aIndex + 27U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aIngress, 4U) + aOrbiterH) + RotL64(aOrbiterJ, 11U)) + aNonceWordK);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 35U) + aOrbiterD) + RotL64(aOrbiterA, 4U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 19U) + RotL64(aOrbiterD, 53U)) + aOrbiterJ) + aNonceWordD);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 47U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 35U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 23U));
            aCarry = aCarry + RotL64(aWandererH, 60U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 19876U)) & S_BLOCK1], 46U) ^ RotL64(mSource[((aIndex + 20549U)) & S_BLOCK1], 57U));
            aIngress ^= (RotL64(aFireLaneA[((aIndex + 20737U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneA[((aIndex + 20057U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 20244U)) & W_KEY1], 35U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 20483U)) & W_KEY1], 19U));
            aCross ^= (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 21255U)) & S_BLOCK1], 46U) ^ RotL64(aWorkLaneB[((aIndex + 20996U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCarry, 52U) ^ RotL64(aIngress, 23U)) ^ (RotL64(aPrevious, 11U) + RotL64(aCross, 37U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterE = ((aWandererG + RotL64(aCross, 43U)) + RotL64(aCarry, 3U)) + 13687218104610230596U;
            aOrbiterA = (aWandererA + RotL64(aIngress, 13U)) + 6841550124960692709U;
            aOrbiterJ = ((aWandererH + RotL64(aScatter, 60U)) + 17418968668458764131U) + aNonceWordK;
            aOrbiterF = (((aWandererF + RotL64(aPrevious, 21U)) + 8303537912696948204U) + aPhaseGOrbiterAssignSaltA[((aIndex + 15U)) & S_SALT1]) + aNonceWordB;
            aOrbiterK = ((aWandererK + RotL64(aIngress, 3U)) + RotL64(aCarry, 43U)) + 12376614417285936537U;
            aOrbiterI = ((aWandererJ + RotL64(aScatter, 35U)) + 14215749063579232654U) + aNonceWordC;
            aOrbiterD = (((aWandererB + RotL64(aPrevious, 51U)) + RotL64(aCarry, 19U)) + 4111736931433665347U) + aPhaseGOrbiterAssignSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            //
            aOrbiterE = (((aOrbiterE + aOrbiterA) + 11250375934571631522U) + aPhaseGOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1]) + aNonceWordH;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 5367367837773331275U;
            aOrbiterJ = RotL64((aOrbiterJ * 7262723007545807179U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 15514089192382674434U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 1475991716685034960U) ^ aNonceWordE;
            aOrbiterK = RotL64((aOrbiterK * 17720681295551650891U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 5531622777788629748U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 8363822215908303335U;
            aOrbiterF = RotL64((aOrbiterF * 17850203366840994883U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 3741256932685720414U) + aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 11634667238062155772U;
            aOrbiterE = RotL64((aOrbiterE * 15925089729784547403U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 18180546911210417155U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 5123234656838556335U) ^ aNonceWordM;
            aOrbiterD = RotL64((aOrbiterD * 15362857462853398025U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 11215734271189250284U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 16863747802158398092U;
            aOrbiterA = RotL64((aOrbiterA * 1828035970246160023U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 9859050606636646323U) + aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 9331300036643654675U;
            aOrbiterI = RotL64((aOrbiterI * 2502263410556166281U), 35U);
            //
            aIngress = RotL64(aOrbiterK, 23U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterE, 13U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterF, 57U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterJ, 34U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aCross, 19U) + RotL64(aOrbiterJ, 27U)) + aOrbiterE) + RotL64(aCarry, 41U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 27U) + RotL64(aOrbiterI, 51U)) + aOrbiterJ) + aPhaseGWandererUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aIngress, 13U) + RotL64(aOrbiterD, 11U)) + aOrbiterJ);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterI, 57U)) + aOrbiterK);
            aWandererA = aWandererA + (((RotL64(aCross, 3U) + aOrbiterF) + RotL64(aOrbiterI, 20U)) + aNonceWordF);
            aWandererB = aWandererB ^ ((((RotL64(aIngress, 51U) + RotL64(aOrbiterF, 35U)) + aOrbiterA) + aNonceWordL) + aPhaseGWandererUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 36U) + RotL64(aOrbiterE, 5U)) + aOrbiterA) + RotL64(aCarry, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 52U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererA, 43U) ^ aWandererB);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 35U));
            aCarry = aCarry + RotL64(aWandererH, 13U);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 24087U)) & S_BLOCK1], 57U) ^ RotL64(aKeyRowReadA[((aIndex + 22543U)) & W_KEY1], 11U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 23567U)) & W_KEY1], 39U) ^ RotL64(aFireLaneC[((aIndex + 21849U)) & S_BLOCK1], 48U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 21987U)) & S_BLOCK1], 4U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 24420U)) & S_BLOCK1], 27U));
            aCross ^= (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 24168U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneD[((aIndex + 22160U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aPrevious, 35U) ^ RotL64(aCross, 3U)) ^ (RotL64(aIngress, 52U) + RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterG = ((aWandererG + RotL64(aCross, 48U)) + 3105313968748067810U) + aNonceWordF;
            aOrbiterD = (((aWandererA + RotL64(aIngress, 29U)) + RotL64(aCarry, 11U)) + 9977249451119627064U) + aNonceWordO;
            aOrbiterJ = (aWandererH + RotL64(aScatter, 39U)) + 17941392803495349366U;
            aOrbiterF = ((aWandererF + RotL64(aPrevious, 57U)) + RotL64(aCarry, 51U)) + 4279533326705471133U;
            aOrbiterH = ((aWandererC + RotL64(aScatter, 3U)) + 13983828966811580039U) + aPhaseGOrbiterAssignSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterC = (aWandererD + RotL64(aPrevious, 21U)) + 3983490984234810378U;
            aOrbiterK = ((((aWandererK + RotL64(aCross, 13U)) + RotL64(aCarry, 27U)) + 308786542215259956U) + aPhaseGOrbiterAssignSaltF[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordA;
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 8443607695364427037U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 14939626441464340668U) ^ aNonceWordE;
            aOrbiterJ = RotL64((aOrbiterJ * 16793255020331774983U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 9350693577306121110U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 1717071159396961752U;
            aOrbiterF = RotL64((aOrbiterF * 11062480662625054525U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 15911765265202100610U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 14898546272333182767U) ^ aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2674900543810733067U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 3560903518513465868U) + aPhaseGOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 5367062725726860234U) ^ aPhaseGOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8521908836601319553U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 15233321480618877327U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 9288449812290126074U;
            aOrbiterD = RotL64((aOrbiterD * 6815298520404038519U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 5504840529511585676U) + aNonceWordD;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 6825598386801620046U;
            aOrbiterG = RotL64((aOrbiterG * 11666542445846250077U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 6433024450721339470U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 97934156644929458U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8630530773006923215U), 35U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterF, 29U);
            aIngress = aIngress + (RotL64(aOrbiterK, 35U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 3U));
            aIngress = aIngress + RotL64(aOrbiterJ, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aIngress, 29U) + aOrbiterC) + RotL64(aOrbiterG, 51U));
            aWandererA = aWandererA + ((RotL64(aScatter, 41U) + aOrbiterK) + RotL64(aOrbiterH, 57U));
            aWandererG = aWandererG ^ ((((RotL64(aPrevious, 14U) + RotL64(aOrbiterD, 35U)) + aOrbiterJ) + aNonceWordI) + aPhaseGWandererUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererD = aWandererD + (((((RotL64(aCross, 51U) + RotL64(aOrbiterJ, 44U)) + aOrbiterG) + RotL64(aCarry, 35U)) + aNonceWordJ) + aPhaseGWandererUpdateSaltD[((aIndex + 23U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 35U) + RotL64(aOrbiterH, 13U)) + aOrbiterJ) + aNonceWordN);
            aWandererK = aWandererK + (((RotL64(aScatter, 23U) + aOrbiterK) + RotL64(aOrbiterG, 3U)) + RotL64(aCarry, 21U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterF, 29U)) + aOrbiterH) + aNonceWordG);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 24U));
            aCarry = aCarry + (RotL64(aWandererK, 35U) ^ aWandererG);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 3U));
            aCarry = aCarry + RotL64(aWandererD, 51U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 26167U)) & S_BLOCK1], 21U) ^ RotL64(aKeyRowReadA[((aIndex + 26519U)) & W_KEY1], 53U));
            aIngress ^= (RotL64(aFireLaneD[((aIndex + 25700U)) & S_BLOCK1], 5U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 27181U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 25666U)) & W_KEY1], 27U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 26522U)) & S_BLOCK1], 38U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 26428U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneD[((aIndex + 26051U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCarry, 47U) + RotL64(aIngress, 34U)) ^ (RotL64(aCross, 3U) + RotL64(aPrevious, 19U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterH = ((((aWandererH + RotL64(aIngress, 29U)) + RotL64(aCarry, 53U)) + 3612110001869385068U) + aPhaseHOrbiterAssignSaltC[((aIndex + 19U)) & S_SALT1]) + aNonceWordM;
            aOrbiterD = ((aWandererG + RotL64(aPrevious, 3U)) + 16340824141280225936U) + aNonceWordH;
            aOrbiterG = (aWandererJ + RotL64(aScatter, 35U)) + 15222338965130765231U;
            aOrbiterK = (aWandererI + RotL64(aCross, 41U)) + 6649270508107155041U;
            aOrbiterB = ((aWandererD + RotL64(aScatter, 57U)) + RotL64(aCarry, 5U)) + 768217258655426384U;
            aOrbiterF = ((aWandererB + RotL64(aPrevious, 20U)) + 4481855259658861851U) + aNonceWordE;
            aOrbiterJ = (((aWandererC + RotL64(aCross, 11U)) + RotL64(aCarry, 39U)) + 18318041934562434016U) + aPhaseHOrbiterAssignSaltF[((aIndex + 21U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 4212457153804401807U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 16143621095636987628U;
            aOrbiterG = RotL64((aOrbiterG * 6576072860505961427U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 2095664232866642086U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 4339527736737366572U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 17503569508822244125U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 13679353177869884790U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 11582168502846418236U;
            aOrbiterB = RotL64((aOrbiterB * 135539430034462861U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 10451330452898542191U) + aNonceWordD;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 12951448817640617841U) ^ aNonceWordJ;
            aOrbiterH = RotL64((aOrbiterH * 4141870904192742091U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 15389161934419370747U) + aNonceWordN;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 4754886272708253014U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 16638243718191281597U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 11746389873929280688U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 12042680172517298768U;
            aOrbiterF = RotL64((aOrbiterF * 3814780289755857543U), 3U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterF) + 2648103752465009244U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordA;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 451594673632597973U;
            aOrbiterK = RotL64((aOrbiterK * 8496763663271072425U), 53U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterF, 23U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 11U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 41U));
            aIngress = aIngress + RotL64(aOrbiterJ, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aPrevious, 5U) + aOrbiterB) + RotL64(aOrbiterG, 23U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 37U) + aOrbiterG) + RotL64(aOrbiterJ, 41U)) + aNonceWordO);
            aWandererG = aWandererG + ((RotL64(aIngress, 50U) + aOrbiterF) + RotL64(aOrbiterB, 14U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 43U) + aOrbiterK) + RotL64(aOrbiterB, 29U));
            aWandererI = aWandererI + ((((RotL64(aPrevious, 19U) + RotL64(aOrbiterJ, 35U)) + aOrbiterF) + RotL64(aCarry, 37U)) + aPhaseHWandererUpdateSaltF[((aIndex + 25U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((((RotL64(aScatter, 29U) + RotL64(aOrbiterH, 47U)) + aOrbiterG) + aNonceWordB) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aIngress, 11U) + RotL64(aOrbiterD, 53U)) + aOrbiterH) + RotL64(aCarry, 57U)) + aNonceWordL);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 34U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 11U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 43U));
            aCarry = aCarry + RotL64(aWandererH, 53U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 28274U)) & S_BLOCK1], 39U) ^ RotL64(aFireLaneD[((aIndex + 28874U)) & S_BLOCK1], 60U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 29167U)) & W_KEY1], 29U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 29294U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 28413U)) & W_KEY1], 3U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 29881U)) & S_BLOCK1], 37U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29063U)) & S_BLOCK1], 56U) ^ RotL64(aFireLaneB[((aIndex + 27585U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aIngress, 19U) + RotL64(aCross, 47U)) ^ (RotL64(aCarry, 60U) ^ RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterH = ((aWandererB + RotL64(aScatter, 47U)) + 5171470532667965920U) + aNonceWordO;
            aOrbiterA = ((((aWandererG + RotL64(aIngress, 11U)) + RotL64(aCarry, 11U)) + 750549462358682403U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 22U)) & S_SALT1]) + aNonceWordB;
            aOrbiterK = (((aWandererD + RotL64(aCross, 28U)) + RotL64(aCarry, 57U)) + 3325689257577120525U) + aNonceWordN;
            aOrbiterD = ((aWandererC + RotL64(aPrevious, 19U)) + RotL64(aCarry, 35U)) + 18031575461559790826U;
            aOrbiterC = ((aWandererJ + RotL64(aScatter, 35U)) + 13874739537012288677U) + aNonceWordG;
            aOrbiterI = (aWandererI + RotL64(aCross, 3U)) + 4250029868785016865U;
            aOrbiterG = ((aWandererE + RotL64(aIngress, 53U)) + 8211158803112611161U) + aPhaseHOrbiterAssignSaltB[((aIndex + 25U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 1083939790236786027U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 3446525462376962464U;
            aOrbiterK = RotL64((aOrbiterK * 13603702473750888213U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 6973817815000417325U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 15230876489676945543U;
            aOrbiterC = RotL64((aOrbiterC * 7737039082964537651U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 9359727659738755880U) + aNonceWordL;
            aOrbiterI = (((aOrbiterI ^ aOrbiterC) ^ 8775170107816327654U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterI = RotL64((aOrbiterI * 6910680458261008653U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 11958941755525038545U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 16966819714283167348U) ^ aNonceWordA;
            aOrbiterA = RotL64((aOrbiterA * 16363457661846050749U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 14556087985619763243U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 17915047508377045221U;
            aOrbiterG = RotL64((aOrbiterG * 6727635453185130109U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 8578745677485367222U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 7002181668717618866U;
            aOrbiterH = RotL64((aOrbiterH * 12329703532414955235U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 3569939503066735457U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 2956247934282522184U;
            aOrbiterD = RotL64((aOrbiterD * 9946650822131152531U), 41U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterC, 11U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 23U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 56U));
            aIngress = aIngress + RotL64(aOrbiterI, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aScatter, 41U) + RotL64(aOrbiterD, 53U)) + aOrbiterG) + RotL64(aCarry, 53U)) + aNonceWordI);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterI, 11U)) + aOrbiterK);
            aWandererG = aWandererG + ((RotL64(aIngress, 51U) + RotL64(aOrbiterA, 27U)) + aOrbiterI);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 27U) + aOrbiterH) + RotL64(aOrbiterC, 60U)) + aNonceWordC);
            aWandererC = aWandererC + (((RotL64(aScatter, 19U) + aOrbiterD) + RotL64(aOrbiterH, 35U)) + aPhaseHWandererUpdateSaltD[((aIndex + 27U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 12U) + RotL64(aOrbiterC, 43U)) + aOrbiterI) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterC, 3U)) + aOrbiterG) + RotL64(aCarry, 35U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 47U));
            aCarry = aCarry + (RotL64(aWandererE, 13U) ^ aWandererG);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 39U));
            aCarry = aCarry + RotL64(aWandererC, 54U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 30791U)) & S_BLOCK1], 18U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 31094U)) & W_KEY1], 57U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 30946U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31165U)) & S_BLOCK1], 4U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32085U)) & S_BLOCK1], 23U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 30371U)) & W_KEY1], 57U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aIngress, 6U) + RotL64(aCarry, 23U)) ^ (RotL64(aCross, 39U) + RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterA = ((((aWandererB + RotL64(aCross, 39U)) + RotL64(aCarry, 23U)) + 11698283336767769359U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordC;
            aOrbiterJ = ((aWandererD + RotL64(aIngress, 5U)) + RotL64(aCarry, 37U)) + 13297826354831483872U;
            aOrbiterF = ((aWandererF + RotL64(aPrevious, 60U)) + 15254999058287530795U) + aNonceWordI;
            aOrbiterC = ((aWandererE + RotL64(aScatter, 13U)) + RotL64(aCarry, 53U)) + 17474166585085346567U;
            aOrbiterI = ((aWandererG + RotL64(aCross, 29U)) + 15684783498452840289U) + aNonceWordM;
            aOrbiterB = (aWandererA + RotL64(aIngress, 23U)) + 5061229733465216486U;
            aOrbiterE = (((aWandererC + RotL64(aPrevious, 53U)) + 15370981279168377944U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordL;
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 17966672773619554092U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 14685092893994491068U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 1627758964162892429U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 12798804186209406389U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 2848444181474221574U;
            aOrbiterI = RotL64((aOrbiterI * 13730480364920876877U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 8551142075919636146U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 8833198159158950723U;
            aOrbiterB = RotL64((aOrbiterB * 7650289040764974737U), 51U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterE) + 7351473160893666232U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1]) + aNonceWordA;
            aOrbiterA = (((aOrbiterA ^ aOrbiterB) ^ 14204899612487622222U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterA = RotL64((aOrbiterA * 6317485031956448029U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 7008985178526543258U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 13576796403863120356U;
            aOrbiterC = RotL64((aOrbiterC * 13745839827679114077U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 5769784656937900699U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 14075925808204936705U;
            aOrbiterE = RotL64((aOrbiterE * 5844894088757604713U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 17818667502858010896U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 16016922065572683130U;
            aOrbiterJ = RotL64((aOrbiterJ * 7525645833898085373U), 19U);
            //
            aIngress = RotL64(aOrbiterC, 58U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 29U));
            aIngress = aIngress + (RotL64(aOrbiterI, 11U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterF, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aCross, 28U) + RotL64(aOrbiterI, 54U)) + aOrbiterC);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 43U) + aOrbiterF) + RotL64(aOrbiterC, 11U));
            aWandererB = aWandererB + (((RotL64(aIngress, 51U) + RotL64(aOrbiterF, 3U)) + aOrbiterE) + aNonceWordG);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 21U) + aOrbiterF) + RotL64(aOrbiterA, 47U)) + aPhaseHWandererUpdateSaltD[((aIndex + 29U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aPrevious, 57U) + aOrbiterE) + RotL64(aOrbiterA, 21U)) + RotL64(aCarry, 11U));
            aWandererF = aWandererF ^ ((((RotL64(aIngress, 11U) + aOrbiterE) + RotL64(aOrbiterJ, 27U)) + aNonceWordB) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aScatter, 35U) + aOrbiterB) + RotL64(aOrbiterE, 35U)) + RotL64(aCarry, 43U)) + aNonceWordE);
            //
            aCarry = aCarry + (RotL64(aWandererF, 35U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererB, 52U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererA, 5U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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

    std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0; std::uint64_t aOrbiterE = 0;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xE081BEDEB206F7B1ULL + 0xE64C89C096DC4725ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x8F1669AE1FF5D6FFULL + 0xE816CC152563B7BFULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xB1D9A788CBF7849BULL + 0xA53C2951C8CFD14AULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xF95B5F69DD02B5FDULL + 0xA6D85D0982EC1EB9ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x846BE0D9001D1ECDULL + 0x8280620DB68A497CULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xB5A37933DB426279ULL + 0x999AB3AD8AFBA33AULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xE533998FBAE18767ULL + 0xABCE496D6A51A581ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xFFC7642520C4C019ULL + 0xC198BAAE10C662D1ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xB13A12593D9B29CDULL + 0xE2960DC8F891B43CULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xBE55FFABC73A0F47ULL + 0xCBF4BDD4C90F82A2ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0x9483F80C951DFC85ULL + 0xC31AE9F3B0BF6A3CULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xDFC3D43CDFD7539DULL + 0xDBCF24108B4C53AFULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xCA700A62B3D8FB99ULL + 0xEB1589381A665ACEULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xD82D3B2D1592E295ULL + 0x801758020488568DULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xCC2B40B322CD8FAFULL + 0xFFC05D5AEAAD8068ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xE6C97DBD45CD6831ULL + 0xBBECD4D4811DB771ULL);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 4863U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneB[((aIndex + 1122U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 3831U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 2428U)) & S_BLOCK1], 44U) ^ RotL64(aExpandLaneD[((aIndex + 4979U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aPrevious, 26U) ^ RotL64(aCarry, 13U)) + (RotL64(aIngress, 57U) + RotL64(aCross, 43U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterG = ((aWandererK + RotL64(aCross, 19U)) + 785861751704720606U) + aNonceWordC;
            aOrbiterF = ((aWandererA + RotL64(aIngress, 3U)) + RotL64(aCarry, 5U)) + 15968088718435606299U;
            aOrbiterJ = (((aWandererG + RotL64(aPrevious, 39U)) + RotL64(aCarry, 47U)) + 1393976526590347151U) + aPhaseAOrbiterAssignSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterD = ((((aWandererE + RotL64(aScatter, 50U)) + RotL64(aCarry, 29U)) + 17240750947292745884U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordF;
            aOrbiterH = ((aWandererC + RotL64(aCross, 27U)) + 4921576136163183137U) + aNonceWordP;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 3334047873553153032U) + aNonceWordK;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 15086509978458408698U;
            aOrbiterJ = RotL64((aOrbiterJ * 2162818176367899893U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 892391205397581998U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 2965686403183767521U;
            aOrbiterD = RotL64((aOrbiterD * 709160942482770225U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 14632215393655706170U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 15740589515342377322U) ^ aNonceWordI;
            aOrbiterF = RotL64((aOrbiterF * 15677716942904794913U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 11131164813943086445U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterG = (((aOrbiterG ^ aOrbiterD) ^ 6988080581278900960U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterG = RotL64((aOrbiterG * 6412189142344044255U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 16021254613117657178U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 6183615599897921154U;
            aOrbiterH = RotL64((aOrbiterH * 9976411093264211033U), 53U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterD, 47U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 21U));
            aIngress = aIngress + RotL64(aOrbiterJ, 34U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((((RotL64(aScatter, 48U) + RotL64(aOrbiterJ, 29U)) + aOrbiterH) + aNonceWordE) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aIngress, 23U) + aOrbiterD) + RotL64(aOrbiterG, 43U)) + RotL64(aCarry, 21U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 13U) + RotL64(aOrbiterF, 20U)) + aOrbiterD) + aNonceWordN);
            aWandererK = aWandererK + (((((RotL64(aCross, 5U) + aOrbiterH) + RotL64(aOrbiterD, 11U)) + RotL64(aCarry, 57U)) + aNonceWordA) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterF, 53U)) + aOrbiterH) + aNonceWordD);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 51U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 4U));
            aCarry = aCarry + RotL64(aWandererG, 35U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 10073U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneC[((aIndex + 5885U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 8073U)) & S_BLOCK1], 50U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordD));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 9901U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 10455U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCarry, 23U) + RotL64(aIngress, 11U)) ^ (RotL64(aCross, 48U) ^ RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterG = (((aWandererJ + RotL64(aIngress, 37U)) + RotL64(aCarry, 35U)) + 9220392006207660113U) + aNonceWordC;
            aOrbiterB = ((((aWandererK + RotL64(aPrevious, 5U)) + RotL64(aCarry, 5U)) + 11305018553489132882U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 4U)) & S_SALT1]) + aNonceWordF;
            aOrbiterK = ((aWandererI + RotL64(aCross, 13U)) + 5860373868073513684U) + aNonceWordB;
            aOrbiterJ = ((aWandererF + RotL64(aScatter, 29U)) + RotL64(aCarry, 47U)) + 12319586170883987589U;
            aOrbiterI = (((aWandererA + RotL64(aCross, 52U)) + 14072333614354649021U) + aPhaseAOrbiterAssignSaltF[((aIndex + 7U)) & S_SALT1]) + aNonceWordK;
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 9332158529453194608U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 3860569321145958686U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 907977527866467591U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 8119005668901240093U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 13918259792880333239U;
            aOrbiterI = RotL64((aOrbiterI * 5441062406822088853U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 6938856216758228704U) + aNonceWordL;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 3960905839118710604U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 16203746868670689793U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 6043879193734253929U) + aNonceWordH;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 15691425268831319195U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 7189195135654636271U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 14912209933584715274U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 16180183395910618923U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 3942858974766467849U), 57U);
            //
            aIngress = RotL64(aOrbiterK, 19U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 57U));
            aIngress = aIngress + RotL64(aOrbiterG, 4U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aIngress, 21U) + RotL64(aOrbiterB, 48U)) + aOrbiterG);
            aWandererI = aWandererI ^ ((((RotL64(aScatter, 57U) + aOrbiterB) + RotL64(aOrbiterK, 37U)) + aNonceWordP) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 30U) + aOrbiterG) + RotL64(aOrbiterJ, 27U)) + RotL64(aCarry, 27U)) + aNonceWordN);
            aWandererK = aWandererK ^ (((RotL64(aCross, 13U) + RotL64(aOrbiterJ, 57U)) + aOrbiterK) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aIngress, 43U) + RotL64(aOrbiterK, 19U)) + aOrbiterI) + RotL64(aCarry, 47U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 11U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 39U));
            aCarry = aCarry + RotL64(aWandererA, 26U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 11048U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneD[((aIndex + 14986U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 15150U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 14988U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 16010U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aExpandLaneA[((aIndex + 14240U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCarry, 29U) ^ RotL64(aPrevious, 11U)) ^ (RotL64(aIngress, 47U) + RotL64(aCross, 60U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterB = ((aWandererK + RotL64(aCross, 44U)) + RotL64(aCarry, 3U)) + 7651355040951791298U;
            aOrbiterC = ((aWandererF + RotL64(aIngress, 3U)) + RotL64(aCarry, 19U)) + 13988210277931659312U;
            aOrbiterI = ((((aWandererH + RotL64(aScatter, 11U)) + RotL64(aCarry, 39U)) + 9846849412579537783U) + aPhaseAOrbiterAssignSaltE[((aIndex + 23U)) & S_SALT1]) + aNonceWordM;
            aOrbiterF = ((aWandererE + RotL64(aPrevious, 57U)) + 12746719939495876158U) + aNonceWordN;
            aOrbiterE = ((aWandererD + RotL64(aScatter, 35U)) + 11498066185182895284U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 11101058955193080232U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterB) ^ 15513734459555672046U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterI = RotL64((aOrbiterI * 6974281215677538561U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 15711108675349394643U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 4771231759949468556U;
            aOrbiterF = RotL64((aOrbiterF * 9806191054594333615U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 11449258010811305256U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 17036938391509986723U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7411466953205347639U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 6999245666776654250U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterF) ^ 2106819066263369528U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterB = RotL64((aOrbiterB * 13005885810757743129U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 12716183358903477216U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 16752724547046059889U) ^ aNonceWordF;
            aOrbiterE = RotL64((aOrbiterE * 11475905692393034141U), 57U);
            //
            aIngress = RotL64(aOrbiterF, 3U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterE, 57U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterI, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((((RotL64(aCross, 19U) + RotL64(aOrbiterC, 57U)) + aOrbiterI) + RotL64(aCarry, 37U)) + aNonceWordH) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 3U) + aOrbiterE) + RotL64(aOrbiterB, 48U)) + aNonceWordK);
            aWandererD = aWandererD + (((RotL64(aPrevious, 56U) + RotL64(aOrbiterC, 3U)) + aOrbiterB) + RotL64(aCarry, 51U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 11U) + RotL64(aOrbiterB, 13U)) + aOrbiterI) + aNonceWordJ);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 37U) + RotL64(aOrbiterE, 37U)) + aOrbiterF) + aNonceWordC) + aPhaseAWandererUpdateSaltE[((aIndex + 10U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 29U));
            aCarry = aCarry + (RotL64(aWandererD, 13U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererE, 37U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 17779U)) & S_BLOCK1], 27U) ^ RotL64(aInvestLaneA[((aIndex + 17456U)) & S_BLOCK1], 42U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 19011U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 17113U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 17041U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 21233U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aPrevious, 11U) ^ RotL64(aCross, 23U)) + (RotL64(aCarry, 60U) + RotL64(aIngress, 43U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterC = ((aWandererH + RotL64(aPrevious, 44U)) + RotL64(aCarry, 21U)) + 12380376990224645149U;
            aOrbiterI = ((aWandererG + RotL64(aScatter, 13U)) + 18296928500297384014U) + aNonceWordC;
            aOrbiterB = (((aWandererC + RotL64(aCross, 57U)) + RotL64(aCarry, 43U)) + 3550626816361145100U) + aNonceWordD;
            aOrbiterG = ((((aWandererF + RotL64(aIngress, 27U)) + RotL64(aCarry, 3U)) + 2667792936946706027U) + aPhaseAOrbiterAssignSaltA[((aIndex + 17U)) & S_SALT1]) + aNonceWordB;
            aOrbiterJ = (((aWandererB + RotL64(aPrevious, 35U)) + 12020969779370926953U) + aPhaseAOrbiterAssignSaltB[((aIndex + 4U)) & S_SALT1]) + aNonceWordN;
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 737340727886903447U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 1681797651799760502U;
            aOrbiterB = RotL64((aOrbiterB * 11923920414802777451U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 2956186342689489064U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 1876852870402977177U;
            aOrbiterI = RotL64((aOrbiterI * 8875540081346621757U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 6433205819353555071U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterB) ^ 9065076854974222998U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 28U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterG = RotL64((aOrbiterG * 5459675878087242021U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 3254410578766789992U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 2005081975473815576U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 9947701153722014085U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 15992999234834560419U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterC = (((aOrbiterC ^ aOrbiterJ) ^ 3458344156815120948U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterC = RotL64((aOrbiterC * 1668460113964608051U), 41U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterB, 3U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 23U));
            aIngress = aIngress + RotL64(aOrbiterJ, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((((RotL64(aCross, 3U) + aOrbiterC) + RotL64(aOrbiterJ, 47U)) + RotL64(aCarry, 47U)) + aNonceWordH) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((((RotL64(aIngress, 38U) + RotL64(aOrbiterC, 29U)) + aOrbiterI) + aNonceWordK) + aPhaseAWandererUpdateSaltB[((aIndex + 7U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 53U) + aOrbiterJ) + RotL64(aOrbiterB, 60U)) + RotL64(aCarry, 21U)) + aNonceWordM);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 21U) + RotL64(aOrbiterB, 5U)) + aOrbiterI) + aNonceWordG);
            aWandererH = aWandererH + ((RotL64(aCross, 13U) + RotL64(aOrbiterJ, 37U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererG, 35U) ^ aWandererB);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 5U));
            aCarry = aCarry + RotL64(aWandererF, 13U);
            aCarry = aCarry + RotL64(aIngress, 56U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 23459U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneA[((aIndex + 24717U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27190U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 22932U)) & S_BLOCK1], 11U) ^ RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 23901U)) & S_BLOCK1], 41U));
            aCross ^= RotL64(aInvestLaneB[((aIndex + 24511U)) & S_BLOCK1], 30U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCarry, 51U) + RotL64(aIngress, 34U)) ^ (RotL64(aCross, 5U) ^ RotL64(aPrevious, 19U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterK = ((((aWandererF + RotL64(aCross, 44U)) + RotL64(aCarry, 13U)) + 898812731947995389U) + aPhaseAOrbiterAssignSaltF[((aIndex + 25U)) & S_SALT1]) + aNonceWordL;
            aOrbiterJ = ((aWandererA + RotL64(aScatter, 27U)) + 8677347622525527167U) + aPhaseAOrbiterAssignSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterH = (((aWandererI + RotL64(aPrevious, 19U)) + RotL64(aCarry, 27U)) + 770321564027567654U) + aNonceWordO;
            aOrbiterB = (((aWandererH + RotL64(aIngress, 53U)) + RotL64(aCarry, 41U)) + 11020474858081526395U) + aNonceWordF;
            aOrbiterG = ((aWandererD + RotL64(aPrevious, 3U)) + 17289793580414993470U) + aNonceWordK;
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 10111912559295118444U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 8083622125544542011U;
            aOrbiterH = RotL64((aOrbiterH * 3610772128071340341U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 7149858558922988240U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 5919683821379905699U;
            aOrbiterK = RotL64((aOrbiterK * 16705119888884231567U), 11U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterB) + 6860902846079238714U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 10U)) & S_SALT1]) + aNonceWordM;
            aOrbiterG = (((aOrbiterG ^ aOrbiterJ) ^ 15083517836867542075U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterG = RotL64((aOrbiterG * 4686657139237578325U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 14852868368708376381U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 9860233289028878323U) ^ aNonceWordI;
            aOrbiterB = RotL64((aOrbiterB * 13418143547952204667U), 41U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 772406119079116272U) + aNonceWordN;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 7971141501337627589U;
            aOrbiterJ = RotL64((aOrbiterJ * 10168120622976358617U), 53U);
            //
            aIngress = RotL64(aOrbiterJ, 4U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterK, 23U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterH, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aPrevious, 47U) + aOrbiterJ) + RotL64(aOrbiterB, 29U)) + aNonceWordH);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 4U) + RotL64(aOrbiterK, 21U)) + aOrbiterJ) + aPhaseAWandererUpdateSaltA[((aIndex + 21U)) & S_SALT1]);
            aWandererD = aWandererD + (((((RotL64(aIngress, 13U) + RotL64(aOrbiterG, 39U)) + aOrbiterK) + RotL64(aCarry, 53U)) + aNonceWordJ) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aCross, 39U) + aOrbiterG) + RotL64(aOrbiterH, 57U)) + aNonceWordD);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 27U) + RotL64(aOrbiterH, 4U)) + aOrbiterJ) + RotL64(aCarry, 5U)) + aNonceWordC);
            //
            aCarry = aCarry + (RotL64(aWandererI, 12U) ^ aWandererF);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 3U));
            aCarry = aCarry + RotL64(aWandererH, 51U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 31213U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneA[((aIndex + 29058U)) & S_BLOCK1], 30U));
            aIngress ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27726U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28551U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 29905U)) & S_BLOCK1], 60U));
            aCross ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 31895U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCarry, 41U) ^ RotL64(aPrevious, 57U)) + (RotL64(aCross, 28U) ^ RotL64(aIngress, 13U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterD = (((aWandererI + RotL64(aScatter, 6U)) + RotL64(aCarry, 5U)) + 4773124477323378268U) + aNonceWordE;
            aOrbiterE = (aWandererH + RotL64(aIngress, 35U)) + 16848723289435796005U;
            aOrbiterI = (((aWandererK + RotL64(aCross, 19U)) + 13846642134917107058U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordO;
            aOrbiterC = ((((aWandererE + RotL64(aPrevious, 51U)) + RotL64(aCarry, 23U)) + 6472057872482789939U) + aPhaseAOrbiterAssignSaltD[((aIndex + 15U)) & S_SALT1]) + aNonceWordI;
            aOrbiterF = (((aWandererG + RotL64(aCross, 27U)) + RotL64(aCarry, 41U)) + 2747019500690707226U) + aNonceWordN;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 9003965289739733880U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 3013390651936257377U;
            aOrbiterI = RotL64((aOrbiterI * 11081353600889943167U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 3331004709895625067U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 15355010435553517129U;
            aOrbiterE = RotL64((aOrbiterE * 8322759117004876831U), 41U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterI) + 7709870658004280052U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1]) + aNonceWordC;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 13568728443963926564U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6736090830113688981U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 12409548853419307131U) + aNonceWordB;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 969183352023661537U;
            aOrbiterD = RotL64((aOrbiterD * 5549220554838837145U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 15370309834426476775U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 3896803894396631184U;
            aOrbiterC = RotL64((aOrbiterC * 11018830202891911603U), 13U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterI, 43U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 30U));
            aIngress = aIngress + RotL64(aOrbiterD, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((((RotL64(aScatter, 5U) + RotL64(aOrbiterF, 51U)) + aOrbiterD) + RotL64(aCarry, 37U)) + aNonceWordL) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterC, 43U)) + aOrbiterE);
            aWandererI = aWandererI + (((RotL64(aIngress, 28U) + aOrbiterI) + RotL64(aOrbiterC, 26U)) + aNonceWordJ);
            aWandererK = aWandererK ^ (((RotL64(aCross, 41U) + aOrbiterF) + RotL64(aOrbiterE, 35U)) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aIngress, 13U) + RotL64(aOrbiterD, 3U)) + aOrbiterI) + RotL64(aCarry, 21U)) + aNonceWordM);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 30U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 19U));
            aCarry = aCarry + RotL64(aWandererK, 41U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x91A0210DE3902459ULL + 0xFF74437AC8008645ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x9680E7DC601760F1ULL + 0xDA2B3B70CB6108E2ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xAAD757C7AC17EFE3ULL + 0x9677DB527E6169B9ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xE55B20A1EFFA66A9ULL + 0xB92D2D3ED140FC2CULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xDADD9C10CC0B47DBULL + 0xAA0BB4B1770947D8ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xFF29C714BDDECADBULL + 0x803254EE51BFA65DULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xEECE7C6A28649C7BULL + 0xD17BDB43A7FDF2DDULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xC1AEA396D69B392DULL + 0xAC7EF27B699468E6ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x94F0AD76CA5F05C7ULL + 0xC199F0D5EA1CDF6DULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xB22A4070B1C6C2E5ULL + 0xC1C84F8DF157F932ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xEDF45B2FC98F1A35ULL + 0xB6186D6FF1126ADCULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xA42281FEB9F43407ULL + 0xF964C4DF2A1D949BULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0x81CFCD3B8F1E293DULL + 0xFE3E985FC6B363CAULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x9AB463A6AEEFEF7FULL + 0xD03FAC1C9D43A4BFULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xBF417F4143676FC5ULL + 0xC0AE4578313951BAULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xAF5557A60AA7ABDBULL + 0xAF85B6333165ACAEULL);
    // GSeedRunSeed_C seed_loop_b (start)
    {
        // GSeedRunSeed_C seed_loop_b lane group
        // read from: aOperationLaneA, aOperationLaneB, aFireLaneA, aOperationLaneC, aOperationLaneD, aExpandLaneA, aInvestLaneC, aExpandLaneB, aFireLaneB, aInvestLaneD, aExpandLaneC, aWorkLaneA, aFireLaneC, aWorkLaneB, aFireLaneD, aWorkLaneC, aExpandLaneD
        // write to: aInvestLaneC, aInvestLaneD, aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // seed_loop_b loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aFireLaneA
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aFireLaneA forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aExpandLaneA
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aExpandLaneA backward/forward random
        // write to: aInvestLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 2904U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneB[((aIndex + 2212U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 995U)) & S_BLOCK1], 30U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 1377U)) & S_BLOCK1], 12U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 4533U)) & S_BLOCK1], 41U));
            aCross ^= RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 3518U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCross, 19U) + RotL64(aIngress, 53U)) + (RotL64(aPrevious, 34U) ^ RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterC = ((aWandererC + RotL64(aScatter, 35U)) + RotL64(aCarry, 53U)) + 15813325389431304548U;
            aOrbiterE = (aWandererK + RotL64(aIngress, 53U)) + 2223874171125403602U;
            aOrbiterG = (((aWandererH + RotL64(aPrevious, 47U)) + RotL64(aCarry, 39U)) + 5510483568496824130U) + aNonceWordC;
            aOrbiterD = ((aWandererI + RotL64(aCross, 4U)) + RotL64(aCarry, 3U)) + 15474152493495661876U;
            aOrbiterF = (aWandererJ + RotL64(aScatter, 19U)) + 16846339705130829195U;
            aOrbiterH = (aWandererF + RotL64(aPrevious, 41U)) + 1289670576865739669U;
            aOrbiterI = (aWandererG + RotL64(aIngress, 29U)) + 18017354919647006944U;
            aOrbiterK = ((aWandererB + RotL64(aCross, 60U)) + 8539685539928984921U) + aPhaseBOrbiterAssignSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterJ = (((aWandererD + RotL64(aPrevious, 11U)) + 3333721400836704048U) + aPhaseBOrbiterAssignSaltF[((aIndex + 5U)) & S_SALT1]) + aNonceWordM;
            //
            aOrbiterC = (((aOrbiterC + aOrbiterE) + 2261560416623815491U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordO;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 4377786131746816567U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 9164777834392621157U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 18047393176583722719U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 8184724021940434631U;
            aOrbiterF = RotL64((aOrbiterF * 9800116157750921119U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 10469895939183324807U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 14543391765109879223U) ^ aNonceWordI;
            aOrbiterI = RotL64((aOrbiterI * 4817987697437667225U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 5757225781746158178U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 3539000495894022869U;
            aOrbiterK = RotL64((aOrbiterK * 1032298408884695925U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 11288971092707065923U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 2761384065186568294U;
            aOrbiterD = RotL64((aOrbiterD * 3323838837427471051U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 7120580145300417101U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 6977246291769372866U;
            aOrbiterC = RotL64((aOrbiterC * 15170353875184253779U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 17625434527765525937U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterJ) ^ 3299714663631376190U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 18U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterE = RotL64((aOrbiterE * 6532628892760776767U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 10331889953489885250U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 8550932256881727932U;
            aOrbiterJ = RotL64((aOrbiterJ * 13085531621192583719U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 11151195711186126257U) + aNonceWordN;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 2552002192824926483U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9754056316698523849U), 19U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterC, 47U);
            aIngress = aIngress + (RotL64(aOrbiterE, 30U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 53U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 35U));
            aIngress = aIngress + RotL64(aOrbiterF, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aIngress, 6U) + RotL64(aOrbiterK, 12U)) + aOrbiterI) + RotL64(aCarry, 57U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 43U) + aOrbiterF) + RotL64(aOrbiterE, 51U)) + aPhaseBWandererUpdateSaltE[((aIndex + 11U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aCross, 39U) + RotL64(aOrbiterG, 47U)) + aOrbiterJ) + RotL64(aCarry, 19U)) + aNonceWordD);
            aWandererG = aWandererG ^ ((((RotL64(aScatter, 29U) + RotL64(aOrbiterE, 5U)) + aOrbiterH) + aNonceWordG) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aIngress, 13U) + aOrbiterI) + RotL64(aOrbiterC, 43U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 53U) + RotL64(aOrbiterE, 57U)) + aOrbiterG) + aNonceWordJ);
            aWandererH = aWandererH + ((RotL64(aScatter, 19U) + RotL64(aOrbiterD, 39U)) + aOrbiterJ);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 24U) + RotL64(aOrbiterH, 34U)) + aOrbiterD);
            aWandererK = aWandererK + (((RotL64(aIngress, 47U) + aOrbiterF) + RotL64(aOrbiterC, 27U)) + aNonceWordB);
            //
            aCarry = aCarry + (RotL64(aWandererF, 35U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererH, 39U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererK, 43U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererD, 57U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererJ, 19U);
            aCarry = aCarry + RotL64(aIngress, 50U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aInvestLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_b loop 2
        // ingress from: aInvestLaneC, aOperationLaneC, aOperationLaneD, aExpandLaneB
        // ingress directions: aInvestLaneC forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aExpandLaneB forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aFireLaneB
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aFireLaneB backward/forward random
        // write to: aInvestLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneC[((aIndex + 10782U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneC[((aIndex + 7634U)) & S_BLOCK1], 41U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 6526U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 9307U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 9420U)) & S_BLOCK1], 60U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 10013U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 7216U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aPrevious, 39U) + RotL64(aCarry, 11U)) + (RotL64(aIngress, 23U) ^ RotL64(aCross, 52U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterI = ((aWandererB + RotL64(aPrevious, 43U)) + RotL64(aCarry, 11U)) + 10038936806177516123U;
            aOrbiterJ = ((aWandererE + RotL64(aCross, 28U)) + 1773168435195292638U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = ((aWandererJ + RotL64(aScatter, 39U)) + 10655711161526628072U) + aPhaseBOrbiterAssignSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = ((aWandererH + RotL64(aIngress, 3U)) + RotL64(aCarry, 51U)) + 14422295664639740437U;
            aOrbiterG = ((aWandererG + RotL64(aScatter, 57U)) + 4125228715513159576U) + aNonceWordM;
            aOrbiterB = (aWandererD + RotL64(aPrevious, 53U)) + 3670449653158650845U;
            aOrbiterA = ((aWandererC + RotL64(aCross, 48U)) + RotL64(aCarry, 27U)) + 17553727567180813057U;
            aOrbiterH = ((aWandererA + RotL64(aIngress, 19U)) + 5111401772713882743U) + aNonceWordJ;
            aOrbiterD = (aWandererI + RotL64(aScatter, 13U)) + 7688573124662314413U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 9438375825507814395U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 14177477039902118886U) ^ aNonceWordG;
            aOrbiterF = RotL64((aOrbiterF * 6467406626985022537U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 16329942595859623928U) + aNonceWordH;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 3990536794006836672U;
            aOrbiterB = RotL64((aOrbiterB * 579024714339065373U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 5072881436583180756U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 16789727877867289997U;
            aOrbiterI = RotL64((aOrbiterI * 8766246302636197905U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 17313956922306689438U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 11530878396329822041U;
            aOrbiterD = RotL64((aOrbiterD * 11356860047841383129U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 3612616532321160196U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 4172189825359187763U;
            aOrbiterG = RotL64((aOrbiterG * 12938945495299393177U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 8677279703778052804U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 1912172980909479362U;
            aOrbiterA = RotL64((aOrbiterA * 10053289257955474143U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 1460085850227494500U) + aNonceWordI;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 12116763868122868147U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 6076945628020280957U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 17571840610366424432U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 15581362592611080868U;
            aOrbiterH = RotL64((aOrbiterH * 1129054058044872003U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 14434700039977611666U) + aNonceWordC;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 4534294602623329152U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5860911553425182045U), 35U);
            //
            aIngress = RotL64(aOrbiterF, 37U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 3U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 56U));
            aIngress = aIngress + (RotL64(aOrbiterI, 51U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterE, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aCross, 29U) + RotL64(aOrbiterG, 29U)) + aOrbiterJ);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 54U) + aOrbiterI) + RotL64(aOrbiterA, 6U));
            aWandererG = aWandererG + ((RotL64(aScatter, 35U) + RotL64(aOrbiterB, 51U)) + aOrbiterF);
            aWandererH = aWandererH ^ ((((RotL64(aPrevious, 11U) + RotL64(aOrbiterD, 57U)) + aOrbiterH) + aNonceWordO) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 23U) + RotL64(aOrbiterG, 19U)) + aOrbiterF) + RotL64(aCarry, 19U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 43U) + aOrbiterD) + RotL64(aOrbiterE, 24U));
            aWandererC = aWandererC + ((((RotL64(aCross, 47U) + aOrbiterA) + RotL64(aOrbiterG, 39U)) + RotL64(aCarry, 39U)) + aNonceWordF);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 39U) + aOrbiterH) + RotL64(aOrbiterB, 35U)) + aPhaseBWandererUpdateSaltF[((aIndex + 8U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aIngress, 60U) + RotL64(aOrbiterD, 11U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 3U));
            aCarry = aCarry + (RotL64(aWandererE, 51U) ^ aWandererH);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 57U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 41U));
            aCarry = aCarry + RotL64(aWandererJ, 44U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aInvestLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_b loop 3
        // ingress from: aInvestLaneD, aOperationLaneA, aExpandLaneC
        // ingress directions: aInvestLaneD forward forced, aOperationLaneA forward forced, aExpandLaneC forward/backward random
        // cross from: aInvestLaneC, aOperationLaneC
        // cross directions: aInvestLaneC backward forced, aOperationLaneC backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneD[((aIndex + 14901U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneA[((aIndex + 11888U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aExpandLaneC[((aIndex + 13963U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 13642U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 11780U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCarry, 27U) ^ RotL64(aIngress, 44U)) + (RotL64(aCross, 11U) + RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterC = (((aWandererH + RotL64(aScatter, 23U)) + 11410829607777684449U) + aPhaseBOrbiterAssignSaltE[((aIndex + 25U)) & S_SALT1]) + aNonceWordB;
            aOrbiterA = ((aWandererB + RotL64(aIngress, 51U)) + 7502698839700975347U) + aNonceWordJ;
            aOrbiterD = (((aWandererI + RotL64(aCross, 41U)) + 13267685058252106173U) + aPhaseBOrbiterAssignSaltC[((aIndex + 24U)) & S_SALT1]) + aNonceWordN;
            aOrbiterF = (aWandererE + RotL64(aPrevious, 13U)) + 238242706996630625U;
            aOrbiterI = (((aWandererK + RotL64(aIngress, 30U)) + RotL64(aCarry, 3U)) + 8184695499511454281U) + aNonceWordL;
            aOrbiterE = ((aWandererC + RotL64(aCross, 47U)) + RotL64(aCarry, 11U)) + 12767823220461985403U;
            aOrbiterH = (aWandererJ + RotL64(aPrevious, 3U)) + 12293198423143850330U;
            aOrbiterB = ((aWandererF + RotL64(aScatter, 35U)) + RotL64(aCarry, 21U)) + 11149495229952495939U;
            aOrbiterK = (aWandererG + RotL64(aCross, 60U)) + 7556992689338382800U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 3431338808774134649U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 16863099140844995099U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 752376661101787919U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 17872458049880677604U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 16760153457252546974U;
            aOrbiterE = RotL64((aOrbiterE * 11225037229069712805U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 3115544493537438408U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 4359882942759752958U;
            aOrbiterH = RotL64((aOrbiterH * 561477566995575801U), 23U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 13387113067202396536U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 12955690074544490161U;
            aOrbiterC = RotL64((aOrbiterC * 12449941770827974511U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 15614054443728226807U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 1939441328066616114U;
            aOrbiterI = RotL64((aOrbiterI * 4484917074808974359U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 4599016263007782537U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 9962305629016158048U;
            aOrbiterK = RotL64((aOrbiterK * 1496184427500037279U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 8428467674122750557U) + aNonceWordA;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 3938884087806393439U;
            aOrbiterA = RotL64((aOrbiterA * 12810531094050481761U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 6018636830758044658U) + aNonceWordG;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 1510372000641305416U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9002834928626918247U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 17592782466215337843U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 8119921507606870360U;
            aOrbiterF = RotL64((aOrbiterF * 1299795061644535485U), 57U);
            //
            aIngress = RotL64(aOrbiterK, 43U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 52U));
            aIngress = aIngress + (RotL64(aOrbiterF, 5U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 11U));
            aIngress = aIngress + RotL64(aOrbiterA, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aIngress, 22U) + RotL64(aOrbiterB, 58U)) + aOrbiterF) + aNonceWordK);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 53U) + RotL64(aOrbiterC, 37U)) + aOrbiterE) + aNonceWordM);
            aWandererG = aWandererG + ((RotL64(aCross, 57U) + RotL64(aOrbiterA, 47U)) + aOrbiterC);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 39U) + RotL64(aOrbiterH, 19U)) + aOrbiterK) + aNonceWordC);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 35U) + aOrbiterH) + RotL64(aOrbiterI, 23U)) + RotL64(aCarry, 23U)) + aPhaseBWandererUpdateSaltC[((aIndex + 9U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterA, 53U)) + aOrbiterD);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 47U) + aOrbiterH) + RotL64(aOrbiterE, 5U)) + RotL64(aCarry, 43U)) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 11U) + aOrbiterK) + RotL64(aOrbiterB, 10U)) + aNonceWordE);
            aWandererC = aWandererC + ((RotL64(aCross, 18U) + RotL64(aOrbiterC, 43U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererH, 26U) ^ aWandererE);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 57U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 5U));
            aCarry = aCarry + (RotL64(aWandererI, 13U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererF, 37U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 21410U)) & S_BLOCK1], 43U) ^ RotL64(aInvestLaneC[((aIndex + 18999U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 19140U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 19480U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneD[((aIndex + 18229U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCross, 39U) ^ RotL64(aPrevious, 5U)) ^ (RotL64(aIngress, 22U) + RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterC = (((aWandererF + RotL64(aIngress, 39U)) + RotL64(aCarry, 5U)) + 5295352595333316211U) + aNonceWordD;
            aOrbiterE = (aWandererI + RotL64(aCross, 29U)) + 2341795367042042605U;
            aOrbiterI = (aWandererC + RotL64(aPrevious, 57U)) + 10122175780504033663U;
            aOrbiterH = (aWandererB + RotL64(aScatter, 46U)) + 10084612804696198554U;
            aOrbiterF = (aWandererD + RotL64(aPrevious, 19U)) + 16470424309851045971U;
            aOrbiterK = ((aWandererK + RotL64(aCross, 23U)) + 656016130975227994U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterG = (((aWandererH + RotL64(aScatter, 51U)) + RotL64(aCarry, 53U)) + 15313268829659834317U) + aNonceWordF;
            aOrbiterD = (aWandererE + RotL64(aIngress, 4U)) + 3795220914993923394U;
            aOrbiterA = (((aWandererJ + RotL64(aPrevious, 13U)) + RotL64(aCarry, 21U)) + 14044442220988813825U) + aPhaseBOrbiterAssignSaltD[((aIndex + 5U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 3804224626734584802U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 7980006306010255693U;
            aOrbiterI = RotL64((aOrbiterI * 13958505239726088561U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 13746830564584711549U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterI) ^ 11852212099729274845U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterF = RotL64((aOrbiterF * 2164880979318247855U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 9083223471018084847U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 13706723820703853346U;
            aOrbiterE = RotL64((aOrbiterE * 11361854103656219887U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 1713819986642275223U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 1382000168233902914U;
            aOrbiterH = RotL64((aOrbiterH * 3894160765130198157U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 4540474625764565485U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 1756168174375757220U;
            aOrbiterK = RotL64((aOrbiterK * 12739160208010092017U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 1409297070183609309U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 6082750101445444357U;
            aOrbiterD = RotL64((aOrbiterD * 17438740230251860935U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 1113239890859479202U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 10932192439503964363U) ^ aNonceWordJ;
            aOrbiterA = RotL64((aOrbiterA * 5915660289913324281U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 3732595033748508428U) + aNonceWordA;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 5117760372351117286U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2671510075176315761U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 7399968659654088641U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 14835608167871904147U;
            aOrbiterG = RotL64((aOrbiterG * 8312521710415756159U), 57U);
            //
            aIngress = RotL64(aOrbiterE, 13U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 47U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 24U));
            aIngress = aIngress + (RotL64(aOrbiterI, 43U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterF, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aIngress, 43U) + RotL64(aOrbiterA, 23U)) + aOrbiterK) + aNonceWordK) + aPhaseBWandererUpdateSaltB[((aIndex + 4U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterI, 14U)) + aOrbiterH);
            aWandererC = aWandererC + (((RotL64(aCross, 10U) + RotL64(aOrbiterH, 57U)) + aOrbiterF) + aNonceWordO);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 23U) + RotL64(aOrbiterE, 53U)) + aOrbiterC) + aPhaseBWandererUpdateSaltE[((aIndex + 9U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 37U) + aOrbiterA) + RotL64(aOrbiterF, 37U)) + RotL64(aCarry, 39U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 51U) + aOrbiterD) + RotL64(aOrbiterG, 48U));
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 57U) + aOrbiterA) + RotL64(aOrbiterG, 19U)) + RotL64(aCarry, 13U)) + aNonceWordN);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 14U) + aOrbiterA) + RotL64(aOrbiterI, 29U));
            aWandererE = aWandererE + (((RotL64(aCross, 3U) + RotL64(aOrbiterG, 3U)) + aOrbiterC) + aNonceWordL);
            //
            aCarry = aCarry + (RotL64(aWandererD, 19U) ^ aWandererF);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 27U));
            aCarry = aCarry + (RotL64(aWandererK, 3U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererI, 37U);
            aCarry = aCarry + RotL64(aIngress, 56U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_b loop 5
        // ingress from: aWorkLaneB, aInvestLaneD, aFireLaneD
        // ingress directions: aWorkLaneB forward forced, aInvestLaneD forward forced, aFireLaneD forward/backward random
        // cross from: aWorkLaneA, aInvestLaneC
        // cross directions: aWorkLaneA backward forced, aInvestLaneC backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 24042U)) & S_BLOCK1], 51U) ^ RotL64(aInvestLaneD[((aIndex + 26030U)) & S_BLOCK1], 26U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 27215U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordD));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 27081U)) & S_BLOCK1], 51U) ^ RotL64(aInvestLaneC[((aIndex + 22200U)) & S_BLOCK1], 26U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aIngress, 57U) + RotL64(aCarry, 36U)) ^ (RotL64(aCross, 19U) ^ RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterK = (((aWandererE + RotL64(aScatter, 43U)) + RotL64(aCarry, 43U)) + 10726035965553989335U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = ((aWandererH + RotL64(aPrevious, 29U)) + 967354339530195662U) + aPhaseBOrbiterAssignSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = (aWandererB + RotL64(aCross, 37U)) + 10834593005478605624U;
            aOrbiterI = (aWandererJ + RotL64(aIngress, 3U)) + 1012888282838656933U;
            aOrbiterJ = (aWandererK + RotL64(aCross, 20U)) + 15283530351725183253U;
            aOrbiterC = ((aWandererF + RotL64(aIngress, 13U)) + RotL64(aCarry, 53U)) + 11724495956731703750U;
            aOrbiterA = (((aWandererA + RotL64(aPrevious, 51U)) + RotL64(aCarry, 21U)) + 4288330117317505776U) + aNonceWordH;
            aOrbiterE = ((aWandererG + RotL64(aScatter, 47U)) + 10894778070022873473U) + aNonceWordJ;
            aOrbiterB = (aWandererC + RotL64(aPrevious, 58U)) + 15563886747621617467U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 11182488628562891937U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 10420140066310588580U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 13898299782819948719U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 11775138062167543111U) + aNonceWordF;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 16545391898578161683U;
            aOrbiterJ = RotL64((aOrbiterJ * 14588306527161321535U), 27U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 1550144656312299266U) + aNonceWordO;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 14903504853138279883U;
            aOrbiterK = RotL64((aOrbiterK * 8003033561266164387U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 309935535526750396U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 13991265868040011411U;
            aOrbiterH = RotL64((aOrbiterH * 2887531132228588441U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 1755976294857114222U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 2259275858478396846U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7416165760067878161U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 4838175912944552936U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 12307900457200936013U) ^ aNonceWordI;
            aOrbiterB = RotL64((aOrbiterB * 14719363144850838805U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 18025411832912225805U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 981375022769564523U;
            aOrbiterI = RotL64((aOrbiterI * 15869361544011831483U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 3174014054982742562U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 8119692378748963609U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3072354179707448489U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 14502863160788675807U) + aNonceWordB;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 1207582534593709516U;
            aOrbiterE = RotL64((aOrbiterE * 3045412087535529357U), 23U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterK, 54U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 11U));
            aIngress = aIngress + (RotL64(aOrbiterB, 21U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterJ, 41U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterE, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aScatter, 35U) + RotL64(aOrbiterB, 51U)) + aOrbiterI) + RotL64(aCarry, 51U)) + aNonceWordL);
            aWandererF = aWandererF ^ ((((RotL64(aCross, 24U) + RotL64(aOrbiterC, 29U)) + aOrbiterK) + aNonceWordM) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aIngress, 53U) + RotL64(aOrbiterD, 19U)) + aOrbiterK);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterC, 57U)) + aOrbiterE);
            aWandererH = aWandererH + (((RotL64(aCross, 39U) + RotL64(aOrbiterJ, 14U)) + aOrbiterH) + RotL64(aCarry, 37U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 43U) + aOrbiterE) + RotL64(aOrbiterA, 43U)) + aNonceWordA);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 11U) + aOrbiterC) + RotL64(aOrbiterI, 37U)) + aNonceWordE) + aPhaseBWandererUpdateSaltF[((aIndex + 29U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 18U) + RotL64(aOrbiterA, 3U)) + aOrbiterC);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 5U) + aOrbiterJ) + RotL64(aOrbiterB, 10U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 10U) ^ aWandererE);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 3U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 13U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 47U));
            aCarry = aCarry + RotL64(aWandererA, 54U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 29629U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneA[((aIndex + 31482U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 32755U)) & S_BLOCK1], 18U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 30700U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneB[((aIndex + 31431U)) & S_BLOCK1], 12U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCarry, 35U) + RotL64(aPrevious, 21U)) + (RotL64(aIngress, 47U) ^ RotL64(aCross, 60U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterF = (((aWandererA + RotL64(aCross, 22U)) + RotL64(aCarry, 41U)) + 2177539223979303669U) + aNonceWordC;
            aOrbiterA = ((aWandererJ + RotL64(aIngress, 53U)) + RotL64(aCarry, 27U)) + 3962004686551521471U;
            aOrbiterI = ((aWandererG + RotL64(aPrevious, 5U)) + 8457602312617147662U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = ((aWandererI + RotL64(aScatter, 57U)) + 18011802451816510632U) + aPhaseBOrbiterAssignSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterD = (aWandererD + RotL64(aPrevious, 18U)) + 9046101759168876832U;
            aOrbiterC = (((aWandererK + RotL64(aScatter, 43U)) + RotL64(aCarry, 13U)) + 11135620637431969597U) + aNonceWordH;
            aOrbiterK = (aWandererC + RotL64(aCross, 11U)) + 15913029940697999701U;
            aOrbiterH = (aWandererE + RotL64(aIngress, 29U)) + 16304193109948135982U;
            aOrbiterG = (aWandererH + RotL64(aScatter, 39U)) + 13208892298820080981U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 4182377898949419225U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 13970137023071326151U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 9075061559681739865U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 8402396284835248583U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 8859190834060657829U;
            aOrbiterD = RotL64((aOrbiterD * 13552418608113716117U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 9760005337757990392U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 14108277760135744897U;
            aOrbiterK = RotL64((aOrbiterK * 4474681104256093885U), 39U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 12226316121949012350U) + aNonceWordM;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 3456392186754113960U;
            aOrbiterH = RotL64((aOrbiterH * 8704729827929941215U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 5004087958637038973U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 7176881295123125567U;
            aOrbiterF = RotL64((aOrbiterF * 15272157962928021009U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 10889800478505074438U) + aNonceWordN;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 13728832441482547824U;
            aOrbiterG = RotL64((aOrbiterG * 17588477761978646139U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 17345665880706866772U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 301139993853297566U;
            aOrbiterC = RotL64((aOrbiterC * 5812445396758354505U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 2061389844760610160U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 13631862266139238355U;
            aOrbiterA = RotL64((aOrbiterA * 143613352104722701U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 10767186080827509622U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 4893486019456886013U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 5194746459545610901U), 47U);
            //
            aIngress = RotL64(aOrbiterG, 35U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterC, 14U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 47U));
            aIngress = aIngress + (RotL64(aOrbiterA, 29U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterJ, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 41U) + aOrbiterC) + RotL64(aOrbiterG, 47U));
            aWandererE = aWandererE + (((RotL64(aIngress, 60U) + RotL64(aOrbiterK, 27U)) + aOrbiterF) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterJ, 18U)) + aOrbiterF);
            aWandererA = aWandererA + ((((RotL64(aScatter, 35U) + RotL64(aOrbiterH, 57U)) + aOrbiterG) + RotL64(aCarry, 3U)) + aNonceWordG);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterG, 39U)) + aOrbiterF);
            aWandererG = aWandererG + ((((RotL64(aCross, 21U) + RotL64(aOrbiterC, 11U)) + aOrbiterH) + RotL64(aCarry, 19U)) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 12U) + aOrbiterD) + RotL64(aOrbiterH, 35U));
            aWandererH = aWandererH + (((RotL64(aIngress, 51U) + RotL64(aOrbiterA, 5U)) + aOrbiterI) + aNonceWordE);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 29U) + aOrbiterA) + RotL64(aOrbiterF, 22U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 56U) ^ aWandererI);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 39U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 35U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 27U));
            aCarry = aCarry + RotL64(aWandererC, 19U);
            aCarry = aCarry + RotL64(aIngress, 46U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xC4A1AEF11108F047ULL + 0x9894BE795E54B9DEULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x8FDBC903C8FF97D5ULL + 0x964BDE37F3ABBE0AULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xC3097024122B447FULL + 0xA0E6009114C6ED71ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x9D035D6589048485ULL + 0xE3BEB7EE38CC9E23ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xC6379D64517E3767ULL + 0xA2130A257FD6C834ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xD3428484A4CDB6F9ULL + 0x8EBB011246C85D17ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xD52BE60A2EE27D75ULL + 0x82193146E13F9BEEULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xD6053EA8B23909FBULL + 0xD1DC68BE3A6B88F3ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x8CB3AE5654777D2DULL + 0x8E49461C91A089A1ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x8E05E51908DB32C1ULL + 0x929599F2DAD8DA4AULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xC0CA38D4484175FBULL + 0xAA18E7F4C2FF4686ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x87E46FA9B06CAB23ULL + 0xF013AE0530A1F5A7ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0x93E5AC4EC6E91E39ULL + 0xE510A12A73835471ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xCF85170DB28624AFULL + 0xF57CBB032E37397FULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x8FAEF1B3456E2B41ULL + 0xD6E88BB70558C61FULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0x98D9EB027696B91DULL + 0xE2382D98FFCB3C98ULL);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 326U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneB[((aIndex + 5375U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aInvestLaneA[((aIndex + 1965U)) & S_BLOCK1], 14U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4507U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 1117U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 1555U)) & S_BLOCK1], 36U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aPrevious, 21U) ^ RotL64(aCross, 3U)) ^ (RotL64(aIngress, 37U) + RotL64(aCarry, 50U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterC = ((aWandererC + RotL64(aCross, 27U)) + RotL64(aCarry, 39U)) + 16016931609704150191U;
            aOrbiterH = ((aWandererI + RotL64(aIngress, 35U)) + 14511433515861302636U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterB = (((aWandererF + RotL64(aScatter, 19U)) + 11691237442613269593U) + aPhaseDOrbiterAssignSaltA[((aIndex + 20U)) & S_SALT1]) + aNonceWordH;
            aOrbiterF = (((aWandererD + RotL64(aPrevious, 3U)) + RotL64(aCarry, 21U)) + 16383220587320484649U) + aNonceWordI;
            aOrbiterD = (aWandererG + RotL64(aIngress, 47U)) + 14293015313458219868U;
            aOrbiterG = ((aWandererA + RotL64(aScatter, 58U)) + RotL64(aCarry, 51U)) + 4407695248205526670U;
            aOrbiterE = ((aWandererK + RotL64(aCross, 13U)) + 1158323195324398372U) + aNonceWordE;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 6577683409653864555U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = (((aOrbiterB ^ aOrbiterC) ^ 171080079472863843U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterB = RotL64((aOrbiterB * 3063978974927752653U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 5766333425872228205U) + aNonceWordL;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 16173508656917582960U;
            aOrbiterD = RotL64((aOrbiterD * 12187968015372936695U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 11781450063402219202U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 13033139686637576694U) ^ aNonceWordK;
            aOrbiterH = RotL64((aOrbiterH * 4331137994135472025U), 53U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 4006310759400926020U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 13156817947481574467U) ^ aNonceWordA;
            aOrbiterE = RotL64((aOrbiterE * 563189239835001483U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 12791290558893516411U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 989729955679243234U;
            aOrbiterF = RotL64((aOrbiterF * 8757228712495095017U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 838379839663022790U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 2830743864262313606U;
            aOrbiterC = RotL64((aOrbiterC * 10173947177104802797U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 2146646527331684652U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 4629168181742174906U;
            aOrbiterG = RotL64((aOrbiterG * 9046124907945045131U), 37U);
            //
            aIngress = RotL64(aOrbiterD, 44U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 29U));
            aIngress = aIngress + (RotL64(aOrbiterH, 11U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterE, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aScatter, 57U) + RotL64(aOrbiterD, 47U)) + aOrbiterH) + aNonceWordB);
            aWandererI = aWandererI ^ ((RotL64(aCross, 51U) + aOrbiterF) + RotL64(aOrbiterB, 19U));
            aWandererF = aWandererF + (((RotL64(aIngress, 23U) + RotL64(aOrbiterD, 35U)) + aOrbiterB) + RotL64(aCarry, 51U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 44U) + aOrbiterC) + RotL64(aOrbiterF, 29U)) + aNonceWordP);
            aWandererD = aWandererD + (((RotL64(aIngress, 11U) + aOrbiterE) + RotL64(aOrbiterC, 11U)) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterE, 57U)) + aOrbiterD) + aNonceWordM);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 37U) + RotL64(aOrbiterG, 4U)) + aOrbiterE) + RotL64(aCarry, 19U)) + aPhaseDWandererUpdateSaltF[((aIndex + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 4U) ^ aWandererK);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 43U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 13U));
            aCarry = aCarry + RotL64(aWandererG, 35U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = (RotL64(aSnowLaneA[((aIndex + 9455U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneC[((aIndex + 5959U)) & S_BLOCK1], 5U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 9409U)) & S_BLOCK1], 29U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 10490U)) & S_BLOCK1], 54U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 9174U)) & S_BLOCK1], 26U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 9502U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 6903U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCross, 6U) ^ RotL64(aPrevious, 27U)) + (RotL64(aCarry, 51U) + RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterH = (((aWandererJ + RotL64(aPrevious, 3U)) + RotL64(aCarry, 53U)) + 3238389262925516513U) + aNonceWordH;
            aOrbiterI = ((aWandererB + RotL64(aCross, 13U)) + RotL64(aCarry, 29U)) + 12381787182611386995U;
            aOrbiterE = ((aWandererA + RotL64(aIngress, 35U)) + RotL64(aCarry, 41U)) + 7883885539305181549U;
            aOrbiterA = ((aWandererI + RotL64(aScatter, 27U)) + 1185413044597727092U) + aNonceWordA;
            aOrbiterD = ((aWandererG + RotL64(aIngress, 21U)) + 15219353497204773135U) + aNonceWordE;
            aOrbiterB = (((aWandererE + RotL64(aScatter, 58U)) + 7533774715626734082U) + aPhaseDOrbiterAssignSaltE[((aIndex + 3U)) & S_SALT1]) + aNonceWordG;
            aOrbiterF = ((aWandererF + RotL64(aCross, 51U)) + 2599930450937763464U) + aPhaseDOrbiterAssignSaltC[((aIndex + 12U)) & S_SALT1];
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 16074720663961214284U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 15483613196360051221U;
            aOrbiterE = RotL64((aOrbiterE * 11717479088020532861U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 9396557867081376268U) + aNonceWordP;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 9668459976852660245U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 11748505665890567063U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 9037269914643207212U) + aNonceWordL;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 16936742640861088240U;
            aOrbiterA = RotL64((aOrbiterA * 1040172193161012227U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 16481274825758546398U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 481851372837611166U) ^ aNonceWordJ;
            aOrbiterB = RotL64((aOrbiterB * 2225030139210599207U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 13608921517203544108U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 16930740723286214636U;
            aOrbiterI = RotL64((aOrbiterI * 2605108503821980865U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 902242902582149908U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 1510861213079342977U) ^ aNonceWordO;
            aOrbiterH = RotL64((aOrbiterH * 3309753895727400707U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 7116243600304980310U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 6631412278359709602U;
            aOrbiterF = RotL64((aOrbiterF * 11452627691392637463U), 27U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterF, 27U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 21U));
            aIngress = aIngress + (RotL64(aOrbiterB, 43U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterI, 6U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aCross, 3U) + aOrbiterA) + RotL64(aOrbiterI, 47U)) + RotL64(aCarry, 5U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 26U) + aOrbiterF) + RotL64(aOrbiterH, 11U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 57U) + aOrbiterE) + RotL64(aOrbiterB, 53U)) + aPhaseDWandererUpdateSaltD[((aIndex + 7U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((((RotL64(aScatter, 47U) + aOrbiterE) + RotL64(aOrbiterA, 41U)) + aNonceWordB) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 41U) + RotL64(aOrbiterB, 28U)) + aOrbiterD) + RotL64(aCarry, 37U)) + aNonceWordM);
            aWandererF = aWandererF ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterB, 3U)) + aOrbiterA);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 13U) + aOrbiterI) + RotL64(aOrbiterF, 35U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 24U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 5U));
            aCarry = aCarry + (RotL64(aWandererB, 43U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererF, 57U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = (RotL64(aSnowLaneB[((aIndex + 12036U)) & S_BLOCK1], 24U) ^ RotL64(aExpandLaneA[((aIndex + 12759U)) & S_BLOCK1], 41U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 15725U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 11603U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneC[((aIndex + 13197U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aPrevious, 29U) + RotL64(aCross, 53U)) + (RotL64(aCarry, 12U) ^ RotL64(aIngress, 41U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterK = (aWandererH + RotL64(aIngress, 47U)) + 17936518874386450467U;
            aOrbiterC = ((aWandererD + RotL64(aPrevious, 29U)) + RotL64(aCarry, 37U)) + 13722737841589910344U;
            aOrbiterI = (aWandererA + RotL64(aScatter, 38U)) + 11774969167948715796U;
            aOrbiterD = (((aWandererB + RotL64(aCross, 23U)) + RotL64(aCarry, 19U)) + 3640101505680493777U) + aPhaseDOrbiterAssignSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = ((aWandererJ + RotL64(aScatter, 13U)) + 1369495382725650822U) + aNonceWordO;
            aOrbiterG = (((aWandererE + RotL64(aIngress, 5U)) + RotL64(aCarry, 53U)) + 11827310354654653345U) + aNonceWordP;
            aOrbiterH = (((aWandererI + RotL64(aPrevious, 57U)) + 186037671377175394U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordM;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 11428829344234627340U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 2275016369870029068U;
            aOrbiterI = RotL64((aOrbiterI * 14936799202145280833U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 15471646673734798328U) + aNonceWordD;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 12172082573115640145U;
            aOrbiterD = RotL64((aOrbiterD * 9629417882787847753U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 6626736341348283154U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 12220614992483863623U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8137086205714097487U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 13157102324253760215U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 4143587482368093601U) ^ aNonceWordK;
            aOrbiterC = RotL64((aOrbiterC * 5060677690991506895U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 11007575246013796426U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 11721585930088637162U;
            aOrbiterG = RotL64((aOrbiterG * 15009627907125738519U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 5720789204450196217U) + aNonceWordN;
            aOrbiterH = (((aOrbiterH ^ aOrbiterI) ^ 3094696226821431648U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterH = RotL64((aOrbiterH * 4412033981712165541U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 14675830108100986773U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 9444071495289719645U;
            aOrbiterF = RotL64((aOrbiterF * 10983136361953366557U), 11U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterF, 5U);
            aIngress = aIngress + (RotL64(aOrbiterC, 51U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 13U));
            aIngress = aIngress + RotL64(aOrbiterK, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((((RotL64(aScatter, 53U) + aOrbiterG) + RotL64(aOrbiterF, 53U)) + aNonceWordI) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 35U) + RotL64(aOrbiterF, 47U)) + aOrbiterH) + aNonceWordL) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 42U) + aOrbiterI) + RotL64(aOrbiterK, 24U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 5U) + aOrbiterF) + RotL64(aOrbiterK, 35U)) + RotL64(aCarry, 57U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterG, 41U)) + aOrbiterI);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 21U) + aOrbiterC) + RotL64(aOrbiterI, 13U)) + RotL64(aCarry, 43U)) + aNonceWordH);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterH, 5U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 41U));
            aCarry = aCarry + (RotL64(aWandererH, 21U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererB, 47U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererE, 30U);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 21371U)) & S_BLOCK1], 19U) ^ RotL64(aSnowLaneA[((aIndex + 16896U)) & S_BLOCK1], 50U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 18605U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 19062U)) & S_BLOCK1], 40U) ^ RotL64(aExpandLaneD[((aIndex + 18413U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCross, 51U) + RotL64(aIngress, 3U)) ^ (RotL64(aPrevious, 20U) + RotL64(aCarry, 37U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterK = ((aWandererD + RotL64(aCross, 41U)) + 3970829908171131502U) + aPhaseDOrbiterAssignSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = ((aWandererI + RotL64(aPrevious, 35U)) + 7040283759419531991U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterB = ((aWandererA + RotL64(aIngress, 57U)) + RotL64(aCarry, 47U)) + 11856292169397052901U;
            aOrbiterF = ((aWandererH + RotL64(aScatter, 11U)) + 819598588791819022U) + aNonceWordI;
            aOrbiterG = (aWandererJ + RotL64(aPrevious, 21U)) + 2176451710970866848U;
            aOrbiterJ = (((aWandererF + RotL64(aScatter, 4U)) + RotL64(aCarry, 27U)) + 6454704928613390494U) + aNonceWordM;
            aOrbiterE = ((aWandererB + RotL64(aCross, 47U)) + RotL64(aCarry, 5U)) + 11792122387218053841U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 9254780213489752211U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 16591812589999846482U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5425771603523423167U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 1471246223935074832U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 1424843083106386453U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 15020536982657410783U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 1856469958050891629U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 6331743690452052712U;
            aOrbiterF = RotL64((aOrbiterF * 15327924647897459645U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 10351075711345476487U) + aNonceWordA;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 9518585245330480185U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 3792179827396760391U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 17787514620244712033U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 14182328067398162557U) ^ aNonceWordC;
            aOrbiterG = RotL64((aOrbiterG * 18107337388659070197U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 12798088948801072444U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 9563215159275202323U;
            aOrbiterA = RotL64((aOrbiterA * 7058145016617349141U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 9904919772580498232U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 16579777394992143043U;
            aOrbiterK = RotL64((aOrbiterK * 10516761340320196661U), 35U);
            //
            aIngress = RotL64(aOrbiterK, 43U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 21U));
            aIngress = aIngress + (RotL64(aOrbiterB, 35U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterG, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterE, 11U)) + aOrbiterG);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 51U) + RotL64(aOrbiterF, 39U)) + aOrbiterJ) + RotL64(aCarry, 47U));
            aWandererH = aWandererH ^ ((((RotL64(aPrevious, 3U) + aOrbiterE) + RotL64(aOrbiterB, 19U)) + aNonceWordH) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aCross, 14U) + aOrbiterG) + RotL64(aOrbiterJ, 51U)) + RotL64(aCarry, 3U)) + aNonceWordO);
            aWandererD = aWandererD ^ ((((RotL64(aPrevious, 57U) + RotL64(aOrbiterA, 57U)) + aOrbiterJ) + aNonceWordN) + aPhaseDWandererUpdateSaltF[((aIndex + 19U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aScatter, 43U) + RotL64(aOrbiterE, 3U)) + aOrbiterK);
            aWandererF = aWandererF ^ (((RotL64(aCross, 29U) + aOrbiterG) + RotL64(aOrbiterK, 30U)) + aNonceWordD);
            //
            aCarry = aCarry + (RotL64(aWandererF, 30U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererJ, 21U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererD, 13U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererB, 41U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 25151U)) & S_BLOCK1], 27U) ^ RotL64(aSnowLaneB[((aIndex + 22483U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 26305U)) & S_BLOCK1], 36U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 26608U)) & S_BLOCK1], 53U) ^ RotL64(aSnowLaneA[((aIndex + 26133U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aIngress, 24U) + RotL64(aCarry, 37U)) ^ (RotL64(aPrevious, 53U) ^ RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterA = (aWandererI + RotL64(aIngress, 53U)) + 3448371607470865612U;
            aOrbiterH = ((aWandererD + RotL64(aPrevious, 11U)) + RotL64(aCarry, 3U)) + 3743742913651580573U;
            aOrbiterE = (((aWandererJ + RotL64(aCross, 3U)) + RotL64(aCarry, 39U)) + 13069491287948807280U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = (((aWandererE + RotL64(aScatter, 60U)) + RotL64(aCarry, 27U)) + 16872779275586545632U) + aNonceWordL;
            aOrbiterB = (((aWandererH + RotL64(aCross, 41U)) + 17945792656755062795U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterJ = ((aWandererG + RotL64(aIngress, 35U)) + 18199747196793731853U) + aNonceWordK;
            aOrbiterG = (aWandererB + RotL64(aPrevious, 29U)) + 15953311878379809513U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 941268763494588338U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 10090221530365796809U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 14035236086292997613U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 8335698093307607001U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 6147498804734306100U;
            aOrbiterB = RotL64((aOrbiterB * 6904444049941211327U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 5980246079567570090U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 4152167624425912978U) ^ aNonceWordM;
            aOrbiterA = RotL64((aOrbiterA * 10019421651535123573U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 14990418790239735916U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 3418668387496597219U;
            aOrbiterI = RotL64((aOrbiterI * 12814077238529863119U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 4206650904177199425U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 3905470780938996069U;
            aOrbiterH = RotL64((aOrbiterH * 16030122739273137005U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 9968672788233080924U) + aNonceWordF;
            aOrbiterG = (((aOrbiterG ^ aOrbiterE) ^ 602258075661864866U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterG = RotL64((aOrbiterG * 2615726693066300065U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 17751667243048041383U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 2414054413585296027U;
            aOrbiterJ = RotL64((aOrbiterJ * 1049512574773201893U), 57U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterB, 27U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 47U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 3U));
            aIngress = aIngress + RotL64(aOrbiterA, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 14U) + RotL64(aOrbiterI, 37U)) + aOrbiterB);
            aWandererB = aWandererB + (((RotL64(aIngress, 29U) + aOrbiterI) + RotL64(aOrbiterJ, 3U)) + aNonceWordC);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterE, 29U)) + aOrbiterB) + aPhaseDWandererUpdateSaltB[((aIndex + 27U)) & S_SALT1]);
            aWandererI = aWandererI + (((((RotL64(aCross, 35U) + aOrbiterA) + RotL64(aOrbiterG, 57U)) + RotL64(aCarry, 11U)) + aNonceWordH) + aPhaseDWandererUpdateSaltD[((aIndex + 4U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterH, 21U)) + aOrbiterB);
            aWandererH = aWandererH + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterB, 10U)) + aOrbiterA) + RotL64(aCarry, 53U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 41U) + RotL64(aOrbiterI, 47U)) + aOrbiterG) + aNonceWordI);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 37U));
            aCarry = aCarry + (RotL64(aWandererH, 54U) ^ aWandererB);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 5U));
            aCarry = aCarry + RotL64(aWandererG, 13U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = (RotL64(aInvestLaneC[((aIndex + 27388U)) & S_BLOCK1], 35U) ^ RotL64(aInvestLaneA[((aIndex + 31583U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 32206U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 30932U)) & S_BLOCK1], 54U) ^ RotL64(aExpandLaneB[((aIndex + 31675U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aIngress, 3U) ^ RotL64(aCarry, 23U)) ^ (RotL64(aCross, 37U) + RotL64(aPrevious, 52U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterK = ((aWandererF + RotL64(aScatter, 13U)) + RotL64(aCarry, 43U)) + 11480359716598965890U;
            aOrbiterJ = (((aWandererJ + RotL64(aCross, 47U)) + 15431182525482873419U) + aPhaseDOrbiterAssignSaltD[((aIndex + 17U)) & S_SALT1]) + aNonceWordL;
            aOrbiterC = ((aWandererI + RotL64(aPrevious, 57U)) + RotL64(aCarry, 5U)) + 11360504974812776707U;
            aOrbiterH = (((aWandererA + RotL64(aIngress, 6U)) + RotL64(aCarry, 29U)) + 9292576416573382769U) + aNonceWordF;
            aOrbiterG = (aWandererD + RotL64(aScatter, 37U)) + 1549257414531028975U;
            aOrbiterD = ((aWandererG + RotL64(aCross, 21U)) + 5347769463033129317U) + aPhaseDOrbiterAssignSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterB = (aWandererC + RotL64(aPrevious, 29U)) + 17019199177478377234U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 16558106007323125094U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 3976182233825939422U;
            aOrbiterC = RotL64((aOrbiterC * 4392162052317572289U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 2889047161195954395U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 2241831345026962605U) ^ aNonceWordK;
            aOrbiterG = RotL64((aOrbiterG * 5757458560979927857U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 12850802412140579294U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 13541744735436450160U;
            aOrbiterH = RotL64((aOrbiterH * 906089290000537439U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 2085863085516538212U) + aNonceWordD;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 2969034221711544086U;
            aOrbiterD = RotL64((aOrbiterD * 7768528124408400403U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 6482666944512391472U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 16969153556875844613U;
            aOrbiterJ = RotL64((aOrbiterJ * 9483462388353216219U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 5161314086757363678U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 7150282484670673211U;
            aOrbiterB = RotL64((aOrbiterB * 8522427002337918663U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 5465304381272305847U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 2344610773390354017U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 17010258514288089191U), 5U);
            //
            aIngress = RotL64(aOrbiterH, 51U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 19U));
            aIngress = aIngress + (RotL64(aOrbiterB, 3U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterG, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 47U) + aOrbiterH) + RotL64(aOrbiterB, 3U)) + aNonceWordA);
            aWandererD = aWandererD + (((((RotL64(aScatter, 35U) + RotL64(aOrbiterD, 47U)) + aOrbiterJ) + RotL64(aCarry, 23U)) + aNonceWordI) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterB, 37U)) + aOrbiterD) + aNonceWordN);
            aWandererC = aWandererC + ((RotL64(aIngress, 13U) + aOrbiterK) + RotL64(aOrbiterH, 29U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 29U) + aOrbiterG) + RotL64(aOrbiterJ, 11U));
            aWandererG = aWandererG + (((RotL64(aIngress, 58U) + aOrbiterH) + RotL64(aOrbiterC, 23U)) + RotL64(aCarry, 39U));
            aWandererF = aWandererF ^ ((((RotL64(aScatter, 21U) + aOrbiterG) + RotL64(aOrbiterC, 60U)) + aNonceWordE) + aPhaseDWandererUpdateSaltA[((aIndex + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 35U) ^ aWandererG);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 23U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 51U));
            aCarry = aCarry + RotL64(aWandererI, 6U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xC045E0864101F145ULL + 0xDC04E061FFF1A154ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xC467D611E2DAF769ULL + 0xBA16333F9572F9C6ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xB0AA135F051A2A67ULL + 0xCF16574D2ABFD320ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xFA96DB912ED9295DULL + 0xDA60382095EFE85CULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xA4D06B34F73DF751ULL + 0xC922AA67D07E068AULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x831CD25F366D4EB9ULL + 0xF18E8087B6EC97F2ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xF4880015B5AC1F0BULL + 0xD4022ADEE99977C8ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x89DAB56BD340C94FULL + 0x8667A3483FC9C67CULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xF306254429943F63ULL + 0xF2318AC4DECF408FULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xD51405DA733636C3ULL + 0xC49BA40A2FD53DEEULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xDA13D9F75806874DULL + 0xA535F2320D1DD92BULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xECE4E7481B7AD151ULL + 0xF0CCFAE025835F01ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xEA562A7D9CE74B1FULL + 0xC7FC13F3E2E6B39CULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xA35E92EC50E7297DULL + 0xA28906E0B3772560ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xC83BE4EBE36DF3D9ULL + 0xF3B17EBA06668366ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xD023E0162DA9B655ULL + 0xE0F6DC23B8507246ULL);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 4301U)) & S_BLOCK1], 51U) ^ RotL64(aInvestLaneB[((aIndex + 468U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 3515U)) & S_BLOCK1], 10U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 1452U)) & S_BLOCK1], 35U) ^ RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 417U)) & S_BLOCK1], 48U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 3555U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aPrevious, 35U) + RotL64(aCarry, 3U)) ^ (RotL64(aIngress, 19U) ^ RotL64(aCross, 50U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterE = (aWandererH + RotL64(aPrevious, 38U)) + 6024062041314952357U;
            aOrbiterC = (aWandererJ + RotL64(aCross, 41U)) + 18340757093658015585U;
            aOrbiterI = (aWandererG + RotL64(aIngress, 11U)) + 11911120493880346751U;
            aOrbiterB = ((aWandererK + RotL64(aScatter, 27U)) + RotL64(aCarry, 13U)) + 17428074353884654439U;
            aOrbiterH = ((aWandererI + RotL64(aCross, 23U)) + 12790849760814795936U) + aNonceWordK;
            aOrbiterF = (aWandererC + RotL64(aPrevious, 19U)) + 12633397052172117800U;
            aOrbiterD = (aWandererA + RotL64(aIngress, 3U)) + 11946150433665237945U;
            aOrbiterG = ((aWandererE + RotL64(aScatter, 14U)) + 16842157900909419285U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = ((aWandererD + RotL64(aIngress, 57U)) + 14186235783224155962U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterJ = ((aWandererB + RotL64(aCross, 21U)) + RotL64(aCarry, 5U)) + 13284904542579767591U;
            aOrbiterK = (((aWandererF + RotL64(aPrevious, 29U)) + RotL64(aCarry, 57U)) + 11609181965078844357U) + aNonceWordC;
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 9628562297095374984U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 7850281529011259759U;
            aOrbiterI = RotL64((aOrbiterI * 17611485102925470357U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 257458718073794527U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 10693404545773519306U;
            aOrbiterC = RotL64((aOrbiterC * 14821443722828498323U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 3430519236533871460U) + aNonceWordE;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 6183054506953198055U;
            aOrbiterD = RotL64((aOrbiterD * 6121082743789970911U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 2905610989884221654U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 4472163910775333862U;
            aOrbiterH = RotL64((aOrbiterH * 7770678426310856745U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 16870142883133769663U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 1403692060594816451U;
            aOrbiterK = RotL64((aOrbiterK * 9740854430251597879U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 16904169913507057108U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 4773518591580333357U;
            aOrbiterJ = RotL64((aOrbiterJ * 5306070307776061267U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 6528141733853494275U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 11254806909313951442U;
            aOrbiterE = RotL64((aOrbiterE * 6316669786405548827U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 6857506858448143407U) + aNonceWordF;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 2855763534355983644U) ^ aNonceWordB;
            aOrbiterB = RotL64((aOrbiterB * 16881334940165182415U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 12328391751024624740U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 16475072086109949522U;
            aOrbiterG = RotL64((aOrbiterG * 15218626930666825883U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 15505670341076785424U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 6972128419331939330U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12206069109180246067U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 7151546362283646210U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 6024062041314952357U;
            aOrbiterF = RotL64((aOrbiterF * 10243806128059850493U), 11U);
            //
            aIngress = RotL64(aOrbiterB, 60U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 19U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 47U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 41U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 57U));
            aIngress = aIngress + RotL64(aOrbiterF, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aScatter, 19U) + aOrbiterG) + RotL64(aOrbiterH, 43U)) + RotL64(aCarry, 3U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 34U) + RotL64(aOrbiterE, 34U)) + aOrbiterK);
            aWandererC = aWandererC + ((RotL64(aIngress, 21U) + aOrbiterI) + RotL64(aOrbiterK, 19U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 23U) + aOrbiterI) + RotL64(aOrbiterA, 39U)) + aNonceWordP);
            aWandererE = aWandererE + ((((RotL64(aIngress, 37U) + RotL64(aOrbiterJ, 11U)) + aOrbiterF) + aNonceWordN) + aPhaseEWandererUpdateSaltD[((aIndex + 29U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterC, 29U)) + aOrbiterF);
            aWandererF = aWandererF + ((RotL64(aPrevious, 44U) + aOrbiterB) + RotL64(aOrbiterJ, 47U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 3U) + RotL64(aOrbiterE, 41U)) + aOrbiterH) + aNonceWordA);
            aWandererI = aWandererI + ((RotL64(aIngress, 57U) + RotL64(aOrbiterD, 21U)) + aOrbiterE);
            aWandererA = aWandererA ^ ((((RotL64(aScatter, 47U) + RotL64(aOrbiterA, 5U)) + aOrbiterD) + aNonceWordD) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aPrevious, 29U) + aOrbiterE) + RotL64(aOrbiterJ, 26U)) + RotL64(aCarry, 23U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 39U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 52U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 11U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 29U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 19U));
            aCarry = aCarry + RotL64(aWandererE, 24U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aFireLaneA[((aIndex + 5727U)) & S_BLOCK1], 53U) ^ RotL64(aInvestLaneC[((aIndex + 9228U)) & S_BLOCK1], 37U));
            aIngress ^= (RotL64(aInvestLaneD[((aIndex + 10296U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneA[((aIndex + 8011U)) & S_BLOCK1], 12U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 6004U)) & S_BLOCK1], 13U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 5855U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 8271U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aIngress, 6U) + RotL64(aCross, 53U)) ^ (RotL64(aCarry, 19U) ^ RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterG = (aWandererB + RotL64(aPrevious, 50U)) + 9220392006207660113U;
            aOrbiterH = ((aWandererK + RotL64(aIngress, 3U)) + 11305018553489132882U) + aNonceWordF;
            aOrbiterJ = ((aWandererI + RotL64(aCross, 57U)) + RotL64(aCarry, 29U)) + 5860373868073513684U;
            aOrbiterE = (aWandererF + RotL64(aScatter, 47U)) + 12319586170883987589U;
            aOrbiterA = ((aWandererC + RotL64(aIngress, 37U)) + RotL64(aCarry, 41U)) + 14072333614354649021U;
            aOrbiterF = ((aWandererD + RotL64(aScatter, 43U)) + 9332158529453194608U) + aPhaseEOrbiterAssignSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = ((aWandererH + RotL64(aPrevious, 27U)) + RotL64(aCarry, 21U)) + 3860569321145958686U;
            aOrbiterK = ((aWandererE + RotL64(aCross, 12U)) + 8119005668901240093U) + aPhaseEOrbiterAssignSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = ((aWandererG + RotL64(aScatter, 5U)) + 13918259792880333239U) + aNonceWordB;
            aOrbiterB = (aWandererA + RotL64(aCross, 21U)) + 6938856216758228704U;
            aOrbiterD = (aWandererJ + RotL64(aPrevious, 23U)) + 3960905839118710604U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 6043879193734253929U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 15691425268831319195U;
            aOrbiterJ = RotL64((aOrbiterJ * 7189195135654636271U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 14912209933584715274U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 16180183395910618923U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3942858974766467849U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 4966642362507707776U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 6962226782462822861U;
            aOrbiterH = RotL64((aOrbiterH * 3647802407741095419U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 12409120845092026295U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 2302946450253872465U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 7099576330777297911U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 16118304388937163838U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 15968419034359049422U) ^ aNonceWordJ;
            aOrbiterB = RotL64((aOrbiterB * 11736207775827080165U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 17098982091525008231U) + aNonceWordA;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 10298979200690822062U;
            aOrbiterG = RotL64((aOrbiterG * 12620028874653521945U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 552826643694256437U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 11786560990790695378U;
            aOrbiterA = RotL64((aOrbiterA * 11190309640069208311U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 13730399230389329793U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 17614226859252305432U;
            aOrbiterE = RotL64((aOrbiterE * 2640019643570222977U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 1062738267846296283U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 13959480457644980835U;
            aOrbiterC = RotL64((aOrbiterC * 1194145909157002977U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 4635071137794189167U) + aNonceWordM;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 13374502212707796180U;
            aOrbiterD = RotL64((aOrbiterD * 129680788767298945U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 11479902881487238033U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterJ) ^ 9220392006207660113U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterI = RotL64((aOrbiterI * 1437457810224888809U), 37U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterH, 29U);
            aIngress = aIngress + (RotL64(aOrbiterD, 37U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterA, 51U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterJ, 10U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterC, 53U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterF, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aScatter, 30U) + RotL64(aOrbiterF, 30U)) + aOrbiterG) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 41U) + aOrbiterK) + RotL64(aOrbiterG, 21U)) + aNonceWordI);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 39U) + RotL64(aOrbiterE, 53U)) + aOrbiterI) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aIngress, 3U) + aOrbiterH) + RotL64(aOrbiterG, 39U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 21U) + aOrbiterA) + RotL64(aOrbiterD, 23U)) + aNonceWordH);
            aWandererE = aWandererE + (((RotL64(aIngress, 37U) + RotL64(aOrbiterD, 43U)) + aOrbiterK) + RotL64(aCarry, 43U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 53U) + aOrbiterI) + RotL64(aOrbiterD, 3U));
            aWandererG = aWandererG + ((((RotL64(aScatter, 27U) + RotL64(aOrbiterA, 41U)) + aOrbiterB) + RotL64(aCarry, 19U)) + aNonceWordO);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 6U) + aOrbiterC) + RotL64(aOrbiterF, 35U));
            aWandererC = aWandererC + ((RotL64(aCross, 47U) + aOrbiterJ) + RotL64(aOrbiterB, 47U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 11U) + aOrbiterC) + RotL64(aOrbiterJ, 6U)) + aNonceWordG);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 35U));
            aCarry = aCarry + (RotL64(aWandererG, 10U) ^ aWandererE);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 47U));
            aCarry = aCarry + (RotL64(aWandererC, 19U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererJ, 39U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererF, 41U);
            aCarry = aCarry + RotL64(aIngress, 60U);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 15720U)) & S_BLOCK1], 3U) ^ RotL64(aInvestLaneA[((aIndex + 14492U)) & S_BLOCK1], 46U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 13961U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 15723U)) & S_BLOCK1], 3U) ^ RotL64(aInvestLaneC[((aIndex + 13919U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aIngress, 52U) + RotL64(aCarry, 11U)) ^ (RotL64(aCross, 23U) ^ RotL64(aPrevious, 39U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterK = ((aWandererE + RotL64(aIngress, 43U)) + 6163290588946759209U) + aNonceWordE;
            aOrbiterJ = (aWandererH + RotL64(aScatter, 19U)) + 7342672468560105447U;
            aOrbiterF = ((aWandererJ + RotL64(aCross, 34U)) + 11574563167017282321U) + aNonceWordL;
            aOrbiterI = ((aWandererG + RotL64(aPrevious, 13U)) + 2254820206194758964U) + aPhaseEOrbiterAssignSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = (aWandererK + RotL64(aScatter, 27U)) + 1469783447473099498U;
            aOrbiterG = ((aWandererA + RotL64(aIngress, 41U)) + RotL64(aCarry, 35U)) + 14174828900676165088U;
            aOrbiterE = (aWandererF + RotL64(aCross, 46U)) + 16277954291890598132U;
            aOrbiterC = (aWandererB + RotL64(aPrevious, 57U)) + 14845750668693136766U;
            aOrbiterD = ((aWandererI + RotL64(aCross, 21U)) + RotL64(aCarry, 29U)) + 150099699692047766U;
            aOrbiterH = (((aWandererC + RotL64(aScatter, 3U)) + RotL64(aCarry, 57U)) + 1200784917165131703U) + aPhaseEOrbiterAssignSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = (aWandererD + RotL64(aIngress, 23U)) + 9469982764806754302U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 10956702761701710182U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 7915506894975487807U;
            aOrbiterF = RotL64((aOrbiterF * 8874108311712727983U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 17335794183733623213U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 557028996286989506U;
            aOrbiterK = RotL64((aOrbiterK * 3993359298602424281U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 1597385667771002414U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 4376417959915162639U;
            aOrbiterI = RotL64((aOrbiterI * 4626236858205178149U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 549770198518993876U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 756554555648070919U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 16272320259614325355U), 35U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterK) + 7298557532533152193U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 3336802611342112013U;
            aOrbiterC = RotL64((aOrbiterC * 14679103452120080499U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 2314938232094714365U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 12215066333571149153U;
            aOrbiterB = RotL64((aOrbiterB * 10747052773052630601U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 7762752719356805046U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 6519429915769040078U;
            aOrbiterJ = RotL64((aOrbiterJ * 15548676502167938513U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 7556691736109752918U) + aNonceWordA;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 13731245903412646404U;
            aOrbiterH = RotL64((aOrbiterH * 15581965016668635409U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 5910925625723735162U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 16037704866415841869U) ^ aNonceWordI;
            aOrbiterG = RotL64((aOrbiterG * 11628217027073824759U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 12605882248192797360U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 9579778913978981884U;
            aOrbiterA = RotL64((aOrbiterA * 5372577227818787957U), 43U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 6063171520266734946U) + aNonceWordP;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 6163290588946759209U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 291843698316138251U), 3U);
            //
            aIngress = RotL64(aOrbiterK, 23U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 39U));
            aIngress = aIngress + (RotL64(aOrbiterG, 37U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 30U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 19U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterB, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aCross, 5U) + aOrbiterH) + RotL64(aOrbiterF, 27U)) + aNonceWordN);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 27U) + RotL64(aOrbiterK, 57U)) + aOrbiterJ) + aNonceWordF);
            aWandererG = aWandererG + ((RotL64(aPrevious, 3U) + RotL64(aOrbiterA, 10U)) + aOrbiterJ);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterD, 5U)) + aOrbiterJ);
            aWandererD = aWandererD + ((RotL64(aCross, 10U) + aOrbiterI) + RotL64(aOrbiterJ, 23U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 57U) + aOrbiterB) + RotL64(aOrbiterJ, 19U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 13U) + aOrbiterH) + RotL64(aOrbiterE, 51U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 47U) + aOrbiterF) + RotL64(aOrbiterG, 60U));
            aWandererA = aWandererA + (((RotL64(aCross, 41U) + RotL64(aOrbiterC, 37U)) + aOrbiterI) + RotL64(aCarry, 57U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 54U) + RotL64(aOrbiterD, 35U)) + aOrbiterF);
            aWandererI = aWandererI + ((((RotL64(aScatter, 21U) + aOrbiterC) + RotL64(aOrbiterB, 47U)) + RotL64(aCarry, 11U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 42U));
            aCarry = aCarry + (RotL64(aWandererE, 47U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererH, 35U) ^ aWandererK);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 51U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 58U));
            aCarry = aCarry + RotL64(aWandererB, 39U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 19016U)) & S_BLOCK1], 58U) ^ RotL64(aFireLaneA[((aIndex + 19762U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aWorkLaneD[((aIndex + 17018U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 21825U)) & S_BLOCK1], 37U) ^ RotL64(aInvestLaneD[((aIndex + 21778U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCarry, 39U) ^ RotL64(aIngress, 5U)) + (RotL64(aCross, 56U) + RotL64(aPrevious, 21U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterE = ((aWandererC + RotL64(aScatter, 56U)) + 1557680213571812384U) + aPhaseEOrbiterAssignSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterA = (((aWandererG + RotL64(aPrevious, 3U)) + RotL64(aCarry, 43U)) + 7387349725778021121U) + aNonceWordM;
            aOrbiterC = ((aWandererI + RotL64(aCross, 19U)) + RotL64(aCarry, 53U)) + 15379264067601586976U;
            aOrbiterD = (aWandererE + RotL64(aIngress, 27U)) + 3730195724576043708U;
            aOrbiterI = ((aWandererD + RotL64(aCross, 36U)) + 9637070085323827066U) + aNonceWordF;
            aOrbiterH = (aWandererK + RotL64(aScatter, 51U)) + 1170865717363676184U;
            aOrbiterK = (aWandererH + RotL64(aPrevious, 5U)) + 2750833653175252030U;
            aOrbiterG = (aWandererA + RotL64(aIngress, 47U)) + 15118992811225568305U;
            aOrbiterJ = (((aWandererF + RotL64(aScatter, 53U)) + RotL64(aCarry, 21U)) + 4974092922102988451U) + aPhaseEOrbiterAssignSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = (aWandererJ + RotL64(aIngress, 39U)) + 10625719096296719514U;
            aOrbiterF = ((aWandererB + RotL64(aCross, 41U)) + 855167122475471865U) + aNonceWordA;
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 11322911068958340262U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 4334591909425429835U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 10059025861172038183U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 14263701737208936392U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 678723206735649084U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 10823239851733632227U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 15652053114252065230U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 1705225940224061401U;
            aOrbiterA = RotL64((aOrbiterA * 3626023093533713579U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 6826394665732900206U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 11902946775066981141U;
            aOrbiterK = RotL64((aOrbiterK * 18300629262162694137U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 9802212958998591310U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 14001358545610206524U) ^ aNonceWordC;
            aOrbiterH = RotL64((aOrbiterH * 13172645840788327099U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 4299184726135884309U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 7288757011999872416U;
            aOrbiterE = RotL64((aOrbiterE * 16806027820468277393U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 233801262480580205U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterF = (((aOrbiterF ^ aOrbiterI) ^ 14208660347238680268U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterF = RotL64((aOrbiterF * 6299693448313154603U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 9217797359740446104U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 18165073197136050838U;
            aOrbiterG = RotL64((aOrbiterG * 11677479094709512887U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 9101905235436427482U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 2884224555227870272U) ^ aNonceWordJ;
            aOrbiterD = RotL64((aOrbiterD * 12085235281782370391U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 13118509728421714433U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 1385390888603164704U;
            aOrbiterB = RotL64((aOrbiterB * 6927424835779289199U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 9621084561183039538U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 1557680213571812384U;
            aOrbiterJ = RotL64((aOrbiterJ * 3202327770291862207U), 43U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterK, 10U);
            aIngress = aIngress + (RotL64(aOrbiterC, 43U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 27U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 23U));
            aIngress = aIngress + (RotL64(aOrbiterD, 21U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterH, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aScatter, 30U) + RotL64(aOrbiterK, 19U)) + aOrbiterD) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 23U) + RotL64(aOrbiterH, 29U)) + aOrbiterK) + aNonceWordG);
            aWandererI = aWandererI ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterF, 54U)) + aOrbiterB);
            aWandererB = aWandererB + (((RotL64(aPrevious, 3U) + aOrbiterH) + RotL64(aOrbiterG, 27U)) + aNonceWordK);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 27U) + aOrbiterB) + RotL64(aOrbiterA, 37U));
            aWandererH = aWandererH + ((((RotL64(aCross, 5U) + aOrbiterD) + RotL64(aOrbiterJ, 41U)) + RotL64(aCarry, 37U)) + aPhaseEWandererUpdateSaltA[((aIndex + 17U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 47U) + aOrbiterE) + RotL64(aOrbiterC, 39U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterC, 21U)) + aOrbiterJ) + RotL64(aCarry, 11U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterD, 43U)) + aOrbiterG);
            aWandererE = aWandererE + ((RotL64(aIngress, 13U) + aOrbiterH) + RotL64(aOrbiterI, 12U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 20U) + aOrbiterF) + RotL64(aOrbiterA, 35U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 34U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererK, 19U) ^ aWandererA);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 23U));
            aCarry = aCarry + (RotL64(aWandererJ, 11U) ^ aWandererI);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 29U));
            aCarry = aCarry + RotL64(aWandererC, 36U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 25462U)) & S_BLOCK1], 36U) ^ RotL64(aFireLaneB[((aIndex + 23368U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 24282U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 24819U)) & S_BLOCK1], 19U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 24544U)) & S_BLOCK1], 58U));
            aCross ^= RotL64(aInvestLaneA[((aIndex + 22077U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCarry, 54U) + RotL64(aPrevious, 5U)) ^ (RotL64(aCross, 39U) + RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterH = (aWandererG + RotL64(aPrevious, 10U)) + 826930775230515406U;
            aOrbiterF = (aWandererD + RotL64(aCross, 13U)) + 5137814617363250861U;
            aOrbiterK = (aWandererH + RotL64(aScatter, 47U)) + 14761561947426681616U;
            aOrbiterD = (aWandererI + RotL64(aIngress, 57U)) + 12773023438753662590U;
            aOrbiterA = (aWandererC + RotL64(aPrevious, 6U)) + 7331345852207096322U;
            aOrbiterB = (((aWandererB + RotL64(aCross, 41U)) + RotL64(aCarry, 57U)) + 3899381212671247460U) + aNonceWordC;
            aOrbiterJ = (aWandererA + RotL64(aScatter, 29U)) + 10072004147620068599U;
            aOrbiterG = (aWandererF + RotL64(aIngress, 3U)) + 3424585039401897560U;
            aOrbiterC = (((aWandererK + RotL64(aScatter, 35U)) + RotL64(aCarry, 39U)) + 8246760141625966321U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = ((aWandererE + RotL64(aPrevious, 21U)) + RotL64(aCarry, 3U)) + 3655992860610853290U;
            aOrbiterI = (((aWandererJ + RotL64(aIngress, 53U)) + 11154618022505863898U) + aPhaseEOrbiterAssignSaltF[((aIndex + 3U)) & S_SALT1]) + aNonceWordI;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 15629361991059709973U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 10842068502278489664U;
            aOrbiterK = RotL64((aOrbiterK * 17223002513104960799U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 5571312349016336686U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 589313823745748879U;
            aOrbiterF = RotL64((aOrbiterF * 1356685926549786027U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 13633457935771935260U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterK) ^ 12684602052812183096U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterA = RotL64((aOrbiterA * 4689206269919806711U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 5711307583717354204U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 7181854170553728211U;
            aOrbiterH = RotL64((aOrbiterH * 9835601115561325911U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 1884620014396115821U) + aNonceWordN;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 1471516373272364262U;
            aOrbiterJ = RotL64((aOrbiterJ * 5126319375714848029U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 742739371092077733U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 8075893317715227838U;
            aOrbiterE = RotL64((aOrbiterE * 11208274111743259795U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 8179547722249281263U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 15305282712174742323U;
            aOrbiterI = RotL64((aOrbiterI * 7951986906055462929U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 1430543231751281079U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 14585341768267283387U) ^ aNonceWordO;
            aOrbiterC = RotL64((aOrbiterC * 313213844964269133U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 8123889986027932297U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 2081696191347150910U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4869653441012615053U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 10166788886199265936U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 15927074835525735601U;
            aOrbiterD = RotL64((aOrbiterD * 6747650218540675523U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 6997764816848988590U) + aNonceWordG;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 826930775230515406U;
            aOrbiterG = RotL64((aOrbiterG * 9943232461538279601U), 39U);
            //
            aIngress = RotL64(aOrbiterB, 51U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterG, 39U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterC, 54U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterD, 47U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 21U));
            aIngress = aIngress + RotL64(aOrbiterJ, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aIngress, 13U) + aOrbiterE) + RotL64(aOrbiterI, 5U));
            aWandererJ = aWandererJ + ((((RotL64(aCross, 21U) + RotL64(aOrbiterF, 11U)) + aOrbiterJ) + RotL64(aCarry, 57U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 35U) + aOrbiterH) + RotL64(aOrbiterE, 40U));
            aWandererK = aWandererK + ((RotL64(aPrevious, 41U) + RotL64(aOrbiterA, 23U)) + aOrbiterD);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 6U) + aOrbiterK) + RotL64(aOrbiterA, 47U));
            aWandererD = aWandererD + ((((RotL64(aScatter, 51U) + aOrbiterE) + RotL64(aOrbiterJ, 51U)) + RotL64(aCarry, 47U)) + aNonceWordM);
            aWandererB = aWandererB ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterG, 21U)) + aOrbiterD);
            aWandererI = aWandererI + (((RotL64(aPrevious, 3U) + aOrbiterA) + RotL64(aOrbiterC, 3U)) + aNonceWordH);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 26U) + aOrbiterF) + RotL64(aOrbiterG, 43U));
            aWandererE = aWandererE + ((((RotL64(aCross, 19U) + RotL64(aOrbiterF, 54U)) + aOrbiterB) + aNonceWordL) + aPhaseEWandererUpdateSaltF[((aIndex + 28U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 57U) + aOrbiterE) + RotL64(aOrbiterF, 57U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 6U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererB, 27U) ^ aWandererC);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 37U));
            aCarry = aCarry + (RotL64(aWandererH, 35U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererK, 24U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererF, 19U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 29934U)) & S_BLOCK1], 26U) ^ RotL64(aOperationLaneA[((aIndex + 30451U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 30135U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31261U)) & S_BLOCK1], 23U) ^ RotL64(aInvestLaneB[((aIndex + 31578U)) & S_BLOCK1], 52U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCarry, 48U) + RotL64(aIngress, 23U)) ^ (RotL64(aPrevious, 35U) + RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterK = ((aWandererK + RotL64(aPrevious, 4U)) + 7960325128608297381U) + aNonceWordJ;
            aOrbiterC = (((aWandererE + RotL64(aIngress, 41U)) + RotL64(aCarry, 37U)) + 12773836012104052042U) + aNonceWordC;
            aOrbiterE = (aWandererD + RotL64(aCross, 35U)) + 3173972621347773016U;
            aOrbiterI = (aWandererF + RotL64(aScatter, 13U)) + 3708401356314308171U;
            aOrbiterH = ((aWandererH + RotL64(aCross, 51U)) + 950774285720019449U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = ((aWandererC + RotL64(aScatter, 57U)) + 4170092315705438265U) + aNonceWordM;
            aOrbiterB = (((aWandererA + RotL64(aPrevious, 29U)) + RotL64(aCarry, 3U)) + 17000449130864980747U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterD = (aWandererI + RotL64(aIngress, 47U)) + 8793910540062893860U;
            aOrbiterF = (aWandererG + RotL64(aCross, 39U)) + 520277969543516469U;
            aOrbiterG = (aWandererB + RotL64(aIngress, 11U)) + 12762214857389827271U;
            aOrbiterJ = ((aWandererJ + RotL64(aScatter, 20U)) + RotL64(aCarry, 53U)) + 2932451184340207695U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 11062179998786293839U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 7919119215271524178U;
            aOrbiterE = RotL64((aOrbiterE * 9053677007180081359U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 1774988449597115155U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 3799792889466518953U;
            aOrbiterA = RotL64((aOrbiterA * 17512791286490623455U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 1815062051307896589U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 15260373951371654483U;
            aOrbiterD = RotL64((aOrbiterD * 2208604434669491625U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 12867546628945676853U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 7772820973895846946U;
            aOrbiterF = RotL64((aOrbiterF * 7581704643538761985U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 14213957831821966834U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 16561105721170419454U) ^ aNonceWordG;
            aOrbiterK = RotL64((aOrbiterK * 2540533987337175367U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 16556502948339949526U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 9706742922075498974U;
            aOrbiterB = RotL64((aOrbiterB * 8527361328901355457U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 13455756934917486016U) + aNonceWordE;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 9107769876332723454U;
            aOrbiterJ = RotL64((aOrbiterJ * 1722386100852683783U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 15793099079168487016U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 7968278803691283365U;
            aOrbiterC = RotL64((aOrbiterC * 11644765391940099387U), 43U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterD) + 15068302421261745111U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordA;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 11373111908765197862U;
            aOrbiterH = RotL64((aOrbiterH * 17756438368103196771U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 6362100123286229887U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterI = (((aOrbiterI ^ aOrbiterE) ^ 528778333872160609U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterI = RotL64((aOrbiterI * 17377710146983314215U), 53U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 6116442644744391285U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 7960325128608297381U;
            aOrbiterG = RotL64((aOrbiterG * 17826511435509927061U), 57U);
            //
            aIngress = RotL64(aOrbiterC, 5U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterD, 10U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 51U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 19U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 37U));
            aIngress = aIngress + RotL64(aOrbiterG, 30U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterA, 37U)) + aOrbiterE);
            aWandererA = aWandererA + ((RotL64(aPrevious, 53U) + RotL64(aOrbiterE, 5U)) + aOrbiterF);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterB, 47U)) + aOrbiterK) + aNonceWordN);
            aWandererC = aWandererC + (((RotL64(aScatter, 14U) + aOrbiterA) + RotL64(aOrbiterB, 41U)) + RotL64(aCarry, 47U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterC, 29U)) + aOrbiterA);
            aWandererK = aWandererK + (((RotL64(aCross, 37U) + aOrbiterD) + RotL64(aOrbiterK, 20U)) + RotL64(aCarry, 43U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterI, 53U)) + aOrbiterC);
            aWandererI = aWandererI + (((RotL64(aScatter, 57U) + aOrbiterJ) + RotL64(aOrbiterG, 51U)) + aNonceWordD);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 6U) + RotL64(aOrbiterB, 43U)) + aOrbiterI);
            aWandererG = aWandererG + (((RotL64(aPrevious, 35U) + aOrbiterG) + RotL64(aOrbiterH, 26U)) + aPhaseEWandererUpdateSaltC[((aIndex + 29U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 27U) + aOrbiterH) + RotL64(aOrbiterJ, 35U)) + aPhaseEWandererUpdateSaltE[((aIndex + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 23U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererA, 4U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererG, 11U) ^ aWandererH);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 47U));
            aCarry = aCarry + (RotL64(aWandererI, 37U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererK, 50U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xE0BC9CE0BC7F7E0FULL + 0xAACC96D896C0F8BAULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xC82744F5EF238819ULL + 0xD7EF164C450F1EC5ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xD343CB61CB2890B7ULL + 0xCC06AA9B854863DEULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xFE6AA46E5CBC8959ULL + 0xA55B88EFC2FAF9ABULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xB413140B960D6037ULL + 0xB82888D9E539C931ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x939EA41EC0B0A1B1ULL + 0xC3DA9A825FA8DCBBULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x859FA804A28CB1ADULL + 0xBA61906832DCF859ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x814EA0CC8F6D07C9ULL + 0x88827D6C676B6B55ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xFD9627F82BA835E3ULL + 0xA26C6C597EAFFBE1ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xD6FC64AE083C4F5DULL + 0x996916EB46CA38CEULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xBF92CA93329040C1ULL + 0xBA62E7BEE0B5037FULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xDD6EA1D6CFA72FAFULL + 0xC41F5AA4921D9399ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xA83F193B4BF3AFB7ULL + 0xEAEBC65877F01ED0ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xD53B035AEB1BB625ULL + 0xE4E6AE6915044C39ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x8CF9E991E45F6F89ULL + 0xE163459A3123F7D3ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xED01C52800BF41C1ULL + 0xBE74F12EAC7463A4ULL);
    // GSeedRunSeed_F seed_loop_f (start)
    {
        // GSeedRunSeed_F seed_loop_f lane group
        // read from: aOperationLaneA, aOperationLaneB, aInvestLaneD, aOperationLaneC, aOperationLaneD, aInvestLaneB, aSnowLaneC, aWorkLaneD, aSnowLaneA, aSnowLaneD, aInvestLaneA, aExpandLaneA, aInvestLaneC, aExpandLaneB, aWorkLaneC, aExpandLaneC, aSnowLaneB
        // write to: aSnowLaneC, aSnowLaneD, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // seed_loop_f loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aInvestLaneD
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aInvestLaneD forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aInvestLaneB
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aInvestLaneB backward/forward random
        // write to: aSnowLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 1605U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneB[((aIndex + 333U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 3731U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 4259U)) & S_BLOCK1], 56U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 1567U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 5382U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aPrevious, 52U) ^ RotL64(aCross, 13U)) ^ (RotL64(aCarry, 39U) + RotL64(aIngress, 27U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterE = ((aWandererF + RotL64(aCross, 50U)) + 9914837590440975587U) + aNonceWordO;
            aOrbiterA = (aWandererE + RotL64(aScatter, 57U)) + 6706125076401958051U;
            aOrbiterB = (aWandererA + RotL64(aIngress, 39U)) + 16570817772679258409U;
            aOrbiterH = (aWandererI + RotL64(aPrevious, 43U)) + 6843705658115186948U;
            aOrbiterJ = (((aWandererJ + RotL64(aCross, 23U)) + RotL64(aCarry, 41U)) + 16099930446791572351U) + aPhaseFOrbiterAssignSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = ((((aWandererH + RotL64(aPrevious, 18U)) + RotL64(aCarry, 53U)) + 5420550009556030459U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 22U)) & S_SALT1]) + aNonceWordN;
            aOrbiterC = (((aWandererK + RotL64(aIngress, 29U)) + RotL64(aCarry, 11U)) + 5729549069420177477U) + aNonceWordA;
            aOrbiterF = (aWandererD + RotL64(aScatter, 35U)) + 15590601126188675834U;
            aOrbiterG = (aWandererG + RotL64(aIngress, 5U)) + 13044027390998620029U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 11068338135659636772U) + aNonceWordP;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 6584988841809544332U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 1683336180438945439U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 8516813219883915404U) + aNonceWordC;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 10647314042912492785U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 15559481057047148785U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 201691689889605304U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterD) ^ 15512161798401184003U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterE = RotL64((aOrbiterE * 11473219183982564709U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 3883760518944464145U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 13861805129175491145U;
            aOrbiterF = RotL64((aOrbiterF * 17194438894492581181U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 12019138626550801486U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 13030350224959652248U;
            aOrbiterD = RotL64((aOrbiterD * 11724200983306280107U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 2643807255422544248U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 4127143302485631794U;
            aOrbiterC = RotL64((aOrbiterC * 5441038881111578487U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 14602951930809633069U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 4555737199162278494U) ^ aNonceWordB;
            aOrbiterA = RotL64((aOrbiterA * 12415825635220991865U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 6343143902997169834U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 10404783711336491985U;
            aOrbiterG = RotL64((aOrbiterG * 6235474458879439079U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 7406959231434835393U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 6684368109277850196U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8760360417572331159U), 43U);
            //
            aIngress = RotL64(aOrbiterG, 37U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterJ, 43U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 5U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 20U));
            aIngress = aIngress + RotL64(aOrbiterF, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aPrevious, 57U) + RotL64(aOrbiterH, 43U)) + aOrbiterF) + aNonceWordI) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 38U) + RotL64(aOrbiterH, 54U)) + aOrbiterE) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aCross, 51U) + RotL64(aOrbiterH, 11U)) + aOrbiterB);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterB, 27U)) + aOrbiterF);
            aWandererG = aWandererG + (((RotL64(aCross, 3U) + aOrbiterC) + RotL64(aOrbiterF, 47U)) + RotL64(aCarry, 5U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 43U) + aOrbiterJ) + RotL64(aOrbiterC, 39U));
            aWandererH = aWandererH + ((((RotL64(aIngress, 13U) + RotL64(aOrbiterH, 21U)) + aOrbiterA) + RotL64(aCarry, 57U)) + aNonceWordD);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 21U) + aOrbiterC) + RotL64(aOrbiterD, 35U)) + aNonceWordM);
            aWandererI = aWandererI + (((RotL64(aIngress, 34U) + aOrbiterG) + RotL64(aOrbiterC, 58U)) + aNonceWordH);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 5U));
            aCarry = aCarry + (RotL64(aWandererK, 50U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererE, 57U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererI, 23U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererD, 53U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aSnowLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_f loop 2
        // ingress from: aSnowLaneC, aOperationLaneC, aOperationLaneD, aWorkLaneD
        // ingress directions: aSnowLaneC forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aWorkLaneD forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aSnowLaneA
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aSnowLaneA backward/forward random
        // write to: aSnowLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneC[((aIndex + 6101U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneC[((aIndex + 6678U)) & S_BLOCK1], 37U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 5579U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 6298U)) & S_BLOCK1], 20U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 8158U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 10418U)) & S_BLOCK1], 28U));
            aCross ^= RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 9632U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCross, 21U) + RotL64(aPrevious, 4U)) + (RotL64(aIngress, 35U) ^ RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterC = (((aWandererC + RotL64(aScatter, 51U)) + RotL64(aCarry, 37U)) + 2783898056762489197U) + aNonceWordL;
            aOrbiterG = ((aWandererF + RotL64(aIngress, 24U)) + RotL64(aCarry, 11U)) + 7177192902873343053U;
            aOrbiterE = (aWandererA + RotL64(aCross, 19U)) + 12254703232691980774U;
            aOrbiterH = ((aWandererD + RotL64(aPrevious, 3U)) + RotL64(aCarry, 27U)) + 15446547245691219559U;
            aOrbiterA = (aWandererB + RotL64(aIngress, 57U)) + 888475203006174856U;
            aOrbiterJ = (((aWandererG + RotL64(aScatter, 14U)) + 3649183529366307877U) + aPhaseFOrbiterAssignSaltD[((aIndex + 9U)) & S_SALT1]) + aNonceWordF;
            aOrbiterK = (aWandererK + RotL64(aCross, 29U)) + 4642631047518805167U;
            aOrbiterF = ((aWandererE + RotL64(aPrevious, 43U)) + 6108329730724782250U) + aNonceWordK;
            aOrbiterI = (((aWandererH + RotL64(aScatter, 35U)) + 8334054653023816636U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordD;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 5891895375031474350U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 3176720746238477862U) ^ aNonceWordA;
            aOrbiterE = RotL64((aOrbiterE * 1869961473768307911U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 6111038696865301675U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 11914998302228682704U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11738924766359642853U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 17005063057791320948U) + aNonceWordP;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 18333780598768130670U;
            aOrbiterH = RotL64((aOrbiterH * 5416759844884107303U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 2056115016443263153U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 10245512728872962677U) ^ aNonceWordB;
            aOrbiterC = RotL64((aOrbiterC * 707106795383284903U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 4810366069422162351U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 3051442983125942469U;
            aOrbiterJ = RotL64((aOrbiterJ * 13558537578054436423U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 9285068547223654308U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 13067251130180968842U;
            aOrbiterI = RotL64((aOrbiterI * 7000687697769766605U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 3203670242792002165U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 1770881716916463461U;
            aOrbiterK = RotL64((aOrbiterK * 13870229847371882171U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 16286823712870537410U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 13067191141829694202U;
            aOrbiterF = RotL64((aOrbiterF * 15629974528467350445U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 3414576315085336932U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 8979691827341555245U;
            aOrbiterG = RotL64((aOrbiterG * 15971594804040295757U), 29U);
            //
            aIngress = RotL64(aOrbiterF, 23U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterE, 34U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 13U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 41U));
            aIngress = aIngress + RotL64(aOrbiterK, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aScatter, 41U) + aOrbiterE) + RotL64(aOrbiterH, 41U));
            aWandererE = aWandererE + (((RotL64(aCross, 52U) + RotL64(aOrbiterE, 57U)) + aOrbiterC) + RotL64(aCarry, 35U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 57U) + aOrbiterH) + RotL64(aOrbiterG, 19U));
            aWandererB = aWandererB + (((RotL64(aIngress, 35U) + aOrbiterJ) + RotL64(aOrbiterK, 37U)) + RotL64(aCarry, 53U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 27U) + aOrbiterI) + RotL64(aOrbiterC, 6U)) + aNonceWordO);
            aWandererD = aWandererD + (((RotL64(aPrevious, 18U) + aOrbiterE) + RotL64(aOrbiterF, 27U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((((RotL64(aCross, 23U) + aOrbiterG) + RotL64(aOrbiterA, 51U)) + aNonceWordJ) + aPhaseFWandererUpdateSaltA[((aIndex + 23U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aIngress, 13U) + aOrbiterI) + RotL64(aOrbiterJ, 23U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 47U) + aOrbiterF) + RotL64(aOrbiterK, 46U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 38U));
            aCarry = aCarry + (RotL64(aWandererA, 41U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererH, 3U) ^ aWandererF);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 23U));
            aCarry = aCarry + RotL64(aWandererB, 19U);
            aCarry = aCarry + RotL64(aIngress, 6U);
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
            aIngress = (RotL64(aSnowLaneD[((aIndex + 13022U)) & S_BLOCK1], 42U) ^ RotL64(aOperationLaneA[((aIndex + 11591U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aInvestLaneA[((aIndex + 12563U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 13819U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneC[((aIndex + 15000U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCross, 21U) + RotL64(aPrevious, 38U)) ^ (RotL64(aCarry, 53U) + RotL64(aIngress, 3U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterD = ((((aWandererI + RotL64(aCross, 29U)) + RotL64(aCarry, 11U)) + 1457104756581596530U) + aPhaseFOrbiterAssignSaltE[((aIndex + 26U)) & S_SALT1]) + aNonceWordE;
            aOrbiterJ = (aWandererG + RotL64(aIngress, 58U)) + 6127240317844622874U;
            aOrbiterF = (aWandererJ + RotL64(aScatter, 51U)) + 16492290056044189421U;
            aOrbiterA = ((aWandererA + RotL64(aPrevious, 37U)) + RotL64(aCarry, 3U)) + 10963676850938416468U;
            aOrbiterI = (((aWandererH + RotL64(aScatter, 5U)) + RotL64(aCarry, 35U)) + 4872917367399752405U) + aNonceWordD;
            aOrbiterG = ((aWandererC + RotL64(aIngress, 41U)) + 15218882377875616148U) + aNonceWordJ;
            aOrbiterE = (aWandererE + RotL64(aPrevious, 23U)) + 5934166612122118251U;
            aOrbiterB = (aWandererF + RotL64(aCross, 14U)) + 14215280930872003003U;
            aOrbiterC = ((aWandererD + RotL64(aScatter, 47U)) + 11428034799044600979U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 5453003654321728726U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 14273775120265649389U;
            aOrbiterF = RotL64((aOrbiterF * 5139018128323795309U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 328723770018440271U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 13032190719588211088U;
            aOrbiterI = RotL64((aOrbiterI * 13363368478932798315U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 2386881543033598494U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterJ) ^ 1649501123340887116U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterA = RotL64((aOrbiterA * 11148976582360499033U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 16462401546754210583U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 1510579201823042227U;
            aOrbiterB = RotL64((aOrbiterB * 16287912400104043275U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 6889066000014251983U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 11324594596597724357U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 15344987814648586023U), 43U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterI) + 12237796033168436537U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 10U)) & S_SALT1]) + aNonceWordG;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 17306069670330000343U) ^ aNonceWordH;
            aOrbiterG = RotL64((aOrbiterG * 3167451351403385259U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 14197284538008811658U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 4754134852883071927U;
            aOrbiterJ = RotL64((aOrbiterJ * 3484427259538998699U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 17201907781639753736U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 8318419319239859855U;
            aOrbiterE = RotL64((aOrbiterE * 10320390501983802091U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 16012488623961565780U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 15583721012865354925U;
            aOrbiterD = RotL64((aOrbiterD * 10656414363201743961U), 57U);
            //
            aIngress = RotL64(aOrbiterB, 43U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterG, 11U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 14U));
            aIngress = aIngress + (RotL64(aOrbiterE, 47U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterI, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aScatter, 56U) + RotL64(aOrbiterJ, 34U)) + aOrbiterF) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 47U) + aOrbiterJ) + RotL64(aOrbiterB, 47U)) + RotL64(aCarry, 5U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 51U) + RotL64(aOrbiterG, 53U)) + aOrbiterC) + aNonceWordF);
            aWandererD = aWandererD + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterI, 57U)) + aOrbiterE) + aNonceWordM);
            aWandererG = aWandererG ^ ((RotL64(aCross, 3U) + aOrbiterE) + RotL64(aOrbiterD, 21U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 18U) + aOrbiterA) + RotL64(aOrbiterC, 5U)) + RotL64(aCarry, 37U));
            aWandererA = aWandererA ^ ((((RotL64(aIngress, 13U) + aOrbiterC) + RotL64(aOrbiterB, 29U)) + aNonceWordP) + aPhaseFWandererUpdateSaltB[((aIndex + 19U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aScatter, 43U) + aOrbiterI) + RotL64(aOrbiterA, 40U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 35U) + aOrbiterD) + RotL64(aOrbiterF, 11U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 19U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 13U));
            aCarry = aCarry + (RotL64(aWandererE, 51U) ^ aWandererI);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 58U));
            aCarry = aCarry + RotL64(aWandererG, 39U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 17190U)) & S_BLOCK1], 37U) ^ RotL64(aSnowLaneC[((aIndex + 18634U)) & S_BLOCK1], 54U));
            aIngress ^= RotL64(aInvestLaneC[((aIndex + 17086U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 20002U)) & S_BLOCK1], 34U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 19755U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCross, 39U) ^ RotL64(aPrevious, 5U)) + (RotL64(aCarry, 18U) + RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterK = ((aWandererC + RotL64(aIngress, 27U)) + RotL64(aCarry, 3U)) + 2571116506511057880U;
            aOrbiterI = ((aWandererD + RotL64(aCross, 47U)) + 13112435411509707292U) + aNonceWordE;
            aOrbiterA = (((aWandererF + RotL64(aPrevious, 57U)) + 10403251762787357256U) + aPhaseFOrbiterAssignSaltB[((aIndex + 20U)) & S_SALT1]) + aNonceWordK;
            aOrbiterJ = ((aWandererH + RotL64(aScatter, 14U)) + RotL64(aCarry, 11U)) + 8461951095541400405U;
            aOrbiterC = (aWandererA + RotL64(aCross, 43U)) + 9890793478557463815U;
            aOrbiterE = ((aWandererB + RotL64(aIngress, 19U)) + 3030229465991783707U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterG = ((aWandererE + RotL64(aScatter, 5U)) + 7273848154043719247U) + aNonceWordB;
            aOrbiterF = ((aWandererG + RotL64(aPrevious, 37U)) + RotL64(aCarry, 27U)) + 10681774862516028276U;
            aOrbiterH = ((aWandererJ + RotL64(aIngress, 52U)) + 7105082755586853104U) + aNonceWordL;
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 6588579345319551129U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 14616333550242386092U;
            aOrbiterA = RotL64((aOrbiterA * 2934574715879306337U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 15439666290229654921U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 3360304356760164799U;
            aOrbiterK = RotL64((aOrbiterK * 5164191920584106237U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 14438730801970761889U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 14515616787452085729U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2041601927968559821U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 4167853822635132419U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 8950982233003320239U;
            aOrbiterH = RotL64((aOrbiterH * 887144270884244907U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 12391327853728029953U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 7100871010552394421U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 16552349374101955967U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 15381697462381887944U) + aNonceWordM;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 6801677551341079401U;
            aOrbiterC = RotL64((aOrbiterC * 13325954438427340703U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 947011315719204867U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 6356920162398333481U;
            aOrbiterI = RotL64((aOrbiterI * 5566721941682667419U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 8910262020598577378U) + aNonceWordF;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 8778455415977526457U;
            aOrbiterE = RotL64((aOrbiterE * 4092470497616637283U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 5585696961453127223U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 9670655481681494412U;
            aOrbiterJ = RotL64((aOrbiterJ * 7863197168965036383U), 35U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterI, 11U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 57U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterG, 43U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 46U));
            aIngress = aIngress + RotL64(aOrbiterE, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aCross, 27U) + RotL64(aOrbiterC, 41U)) + aOrbiterI) + RotL64(aCarry, 41U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 20U) + aOrbiterH) + RotL64(aOrbiterA, 4U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aPrevious, 57U) + RotL64(aOrbiterC, 51U)) + aOrbiterJ);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 39U) + RotL64(aOrbiterG, 23U)) + aOrbiterC) + aNonceWordG);
            aWandererA = aWandererA + ((RotL64(aScatter, 53U) + aOrbiterG) + RotL64(aOrbiterF, 35U));
            aWandererJ = aWandererJ ^ ((((RotL64(aCross, 5U) + RotL64(aOrbiterA, 11U)) + aOrbiterI) + aNonceWordN) + aPhaseFWandererUpdateSaltD[((aIndex + 5U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aIngress, 10U) + aOrbiterK) + RotL64(aOrbiterI, 46U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 47U) + RotL64(aOrbiterE, 27U)) + aOrbiterG) + aNonceWordJ);
            aWandererE = aWandererE + (((RotL64(aScatter, 43U) + RotL64(aOrbiterG, 19U)) + aOrbiterJ) + RotL64(aCarry, 3U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 3U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 13U));
            aCarry = aCarry + (RotL64(aWandererA, 51U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererE, 10U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererJ, 57U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 26752U)) & S_BLOCK1], 3U) ^ RotL64(aSnowLaneD[((aIndex + 24611U)) & S_BLOCK1], 14U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 24749U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 24520U)) & S_BLOCK1], 29U) ^ RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 26826U)) & S_BLOCK1], 4U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aPrevious, 56U) + RotL64(aCross, 29U)) + (RotL64(aIngress, 43U) ^ RotL64(aCarry, 13U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterI = (((aWandererJ + RotL64(aIngress, 54U)) + 8866844335448071821U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordN;
            aOrbiterG = ((aWandererH + RotL64(aScatter, 19U)) + RotL64(aCarry, 3U)) + 15159698739856430085U;
            aOrbiterB = (aWandererB + RotL64(aCross, 3U)) + 9582805772989594633U;
            aOrbiterE = ((aWandererC + RotL64(aPrevious, 23U)) + 1438538239931588373U) + aNonceWordM;
            aOrbiterH = (((aWandererA + RotL64(aScatter, 58U)) + 10862044156620436139U) + aPhaseFOrbiterAssignSaltD[((aIndex + 21U)) & S_SALT1]) + aNonceWordG;
            aOrbiterA = ((aWandererG + RotL64(aPrevious, 47U)) + RotL64(aCarry, 21U)) + 13682173320058164615U;
            aOrbiterJ = (aWandererK + RotL64(aCross, 35U)) + 8351013291045977592U;
            aOrbiterD = (aWandererI + RotL64(aIngress, 39U)) + 15777857431516633916U;
            aOrbiterF = ((aWandererE + RotL64(aCross, 11U)) + RotL64(aCarry, 37U)) + 16178966745333885377U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 9031889187993001617U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 6308472367425865347U;
            aOrbiterB = RotL64((aOrbiterB * 17118710301967158153U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 642109145903321046U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 9186268569255318035U;
            aOrbiterG = RotL64((aOrbiterG * 10714674348507516749U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 6091345356803675860U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 13218507921880873749U;
            aOrbiterJ = RotL64((aOrbiterJ * 15415157927185637717U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 4266652275234474616U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 4391422098164506195U;
            aOrbiterD = RotL64((aOrbiterD * 17634679403195085867U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 5160682323243635577U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 10351728852161347404U) ^ aNonceWordJ;
            aOrbiterI = RotL64((aOrbiterI * 11105410036471745951U), 11U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterI) + 3950932176454814023U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordD;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 9536466386833427441U) ^ aNonceWordA;
            aOrbiterF = RotL64((aOrbiterF * 18064984243491293435U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 9927425919978776529U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 6819384090527481081U;
            aOrbiterE = RotL64((aOrbiterE * 18032965969184368561U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 1646274931424218507U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 16166524473976135097U;
            aOrbiterH = RotL64((aOrbiterH * 11672192658072663849U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 11252501968059485262U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 16847854447987609067U;
            aOrbiterA = RotL64((aOrbiterA * 6326299154627028295U), 23U);
            //
            aIngress = RotL64(aOrbiterE, 13U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 23U));
            aIngress = aIngress + (RotL64(aOrbiterG, 29U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 19U));
            aIngress = aIngress + RotL64(aOrbiterI, 56U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aScatter, 27U) + RotL64(aOrbiterH, 37U)) + aOrbiterE);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 4U) + aOrbiterA) + RotL64(aOrbiterI, 42U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 41U) + RotL64(aOrbiterB, 57U)) + aOrbiterF) + RotL64(aCarry, 3U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 53U) + aOrbiterD) + RotL64(aOrbiterB, 51U)) + aNonceWordL);
            aWandererH = aWandererH + ((RotL64(aIngress, 11U) + aOrbiterJ) + RotL64(aOrbiterG, 29U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 60U) + aOrbiterI) + RotL64(aOrbiterG, 47U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 19U) + aOrbiterB) + RotL64(aOrbiterJ, 3U)) + RotL64(aCarry, 27U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterJ, 19U)) + aOrbiterH);
            aWandererI = aWandererI + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterI, 14U)) + aOrbiterF) + aNonceWordI);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 14U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 5U));
            aCarry = aCarry + (RotL64(aWandererE, 57U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererB, 39U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererK, 43U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 30384U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneA[((aIndex + 30693U)) & S_BLOCK1], 41U));
            aIngress ^= RotL64(aSnowLaneB[((aIndex + 27905U)) & S_BLOCK1], 60U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30380U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneB[((aIndex + 27445U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aIngress, 23U) + RotL64(aCross, 36U)) + (RotL64(aCarry, 3U) ^ RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterB = (aWandererF + RotL64(aCross, 30U)) + 2974056819475622600U;
            aOrbiterH = (aWandererD + RotL64(aIngress, 11U)) + 7345051759236356098U;
            aOrbiterK = (aWandererB + RotL64(aScatter, 43U)) + 12738468816846628882U;
            aOrbiterG = (aWandererA + RotL64(aPrevious, 47U)) + 7694520596043297922U;
            aOrbiterI = (((aWandererE + RotL64(aIngress, 26U)) + RotL64(aCarry, 27U)) + 5530753590015084774U) + aPhaseFOrbiterAssignSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterC = (aWandererJ + RotL64(aScatter, 19U)) + 3776309161718383105U;
            aOrbiterJ = ((aWandererC + RotL64(aCross, 3U)) + RotL64(aCarry, 11U)) + 784780304358106404U;
            aOrbiterA = ((((aWandererI + RotL64(aPrevious, 57U)) + RotL64(aCarry, 35U)) + 8999942326995036509U) + aPhaseFOrbiterAssignSaltF[((aIndex + 7U)) & S_SALT1]) + aNonceWordD;
            aOrbiterD = ((aWandererK + RotL64(aCross, 37U)) + 5194986506064092779U) + aNonceWordC;
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 7920040007459652762U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 11311997270710107937U) ^ aNonceWordI;
            aOrbiterK = RotL64((aOrbiterK * 6227571709361790209U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 5365231114813547251U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterG) ^ 8630110234623825263U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterB = RotL64((aOrbiterB * 2735881715888325759U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 2358235238039571072U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 18059414891616491807U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 17150786106857185467U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 14526050556461782864U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 6937282036603272474U;
            aOrbiterD = RotL64((aOrbiterD * 14954512365270028029U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 10105832250694931310U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 3884223553012098137U;
            aOrbiterJ = RotL64((aOrbiterJ * 16340956813003906195U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 10385284339549648087U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 1257633893341505930U;
            aOrbiterI = RotL64((aOrbiterI * 2669950791270500977U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 5528890519572824318U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 15664241747527713256U;
            aOrbiterC = RotL64((aOrbiterC * 16670884497088220497U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 14264122979415331887U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 17985061405540198036U;
            aOrbiterH = RotL64((aOrbiterH * 2729487440173395133U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 1663986734997903415U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 3706166884286400587U;
            aOrbiterG = RotL64((aOrbiterG * 10549736618301955745U), 29U);
            //
            aIngress = RotL64(aOrbiterK, 57U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 13U));
            aIngress = aIngress + (RotL64(aOrbiterH, 23U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 28U));
            aIngress = aIngress + RotL64(aOrbiterG, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aScatter, 19U) + aOrbiterB) + RotL64(aOrbiterK, 44U)) + aNonceWordO);
            aWandererC = aWandererC + (((RotL64(aCross, 27U) + RotL64(aOrbiterA, 51U)) + aOrbiterJ) + aPhaseFWandererUpdateSaltB[((aIndex + 15U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 44U) + aOrbiterH) + RotL64(aOrbiterA, 21U));
            aWandererK = aWandererK + ((RotL64(aIngress, 39U) + RotL64(aOrbiterH, 35U)) + aOrbiterI);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 23U) + aOrbiterD) + RotL64(aOrbiterH, 57U)) + aNonceWordH);
            aWandererD = aWandererD + ((((RotL64(aCross, 57U) + aOrbiterC) + RotL64(aOrbiterB, 5U)) + RotL64(aCarry, 5U)) + aNonceWordK);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 53U) + aOrbiterB) + RotL64(aOrbiterG, 39U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 5U) + RotL64(aOrbiterA, 11U)) + aOrbiterI) + RotL64(aCarry, 43U)) + aNonceWordF);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 34U) + aOrbiterC) + RotL64(aOrbiterK, 26U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 60U) ^ aWandererC);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 39U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 43U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 47U));
            aCarry = aCarry + RotL64(aWandererD, 3U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x8ADBC221CF4F5B0DULL + 0xEF26DD498727FAFEULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xE3CEE11E9CDCF045ULL + 0x97F97C31F4A23D55ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xA419B11AE76F007FULL + 0xFD4A9037DCE8B33EULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xB3C66DF080564241ULL + 0x8F7A6AFEB951EF26ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xC394D1AA4E35027BULL + 0xD61A9039AD218508ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x86CA52B28FDAA1BBULL + 0xF12469D7D995183EULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xEA2BEAE38E857A21ULL + 0x8EF2EA8895FAA25AULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xE45A5AF00A53EDC9ULL + 0xD9625200E41D76B9ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x8F5F6FC6B851F475ULL + 0xDE53ED084345BFB8ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xF5A7D4DAE2649909ULL + 0xA4A284EDED6203FCULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xAC96A099B3A6A07DULL + 0xDEDA06CC135299B8ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x9014DB4C68EC8965ULL + 0xFC9D8BAD88E348CAULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xC82BF037286964B9ULL + 0xECC00836EAA94B1BULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xFAA4F96B14E2BB29ULL + 0x90F5DAADA2DCFB9EULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xCA3CED72451B908DULL + 0xDE96FB18B0B00B39ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xDBFE5231B369FD2BULL + 0xCB543C1A42103BD1ULL);
    // GSeedRunSeed_G seed_loop_h (start)
    {
        // GSeedRunSeed_G seed_loop_h lane group
        // read from: aSnowLaneA, aSnowLaneB, aFireLaneD, aSnowLaneC, aSnowLaneD, aFireLaneB, aWorkLaneA, aInvestLaneC, aInvestLaneB, aWorkLaneB, aFireLaneC, aExpandLaneA, aInvestLaneD, aExpandLaneB, aInvestLaneA, aExpandLaneC, aFireLaneA
        // write to: aWorkLaneA, aWorkLaneB, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // seed_loop_h loop 1
        // ingress from: aSnowLaneA, aSnowLaneB, aFireLaneD
        // ingress directions: aSnowLaneA forward forced, aSnowLaneB forward forced, aFireLaneD forward/backward random
        // cross from: aSnowLaneC, aSnowLaneD, aFireLaneB
        // cross directions: aSnowLaneC backward forced, aSnowLaneD backward forced, aFireLaneB backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneA[((aIndex + 4138U)) & S_BLOCK1], 35U) ^ RotL64(aSnowLaneB[((aIndex + 1429U)) & S_BLOCK1], 4U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 2093U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 3712U)) & S_BLOCK1], 23U) ^ RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 3069U)) & S_BLOCK1], 56U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 2331U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCross, 37U) ^ RotL64(aIngress, 4U)) ^ (RotL64(aPrevious, 53U) + RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterI = (aWandererH + RotL64(aIngress, 41U)) + 5160910997561396461U;
            aOrbiterC = ((aWandererA + RotL64(aCross, 29U)) + 14920764751058512062U) + aPhaseHOrbiterAssignSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterH = (((aWandererJ + RotL64(aPrevious, 5U)) + RotL64(aCarry, 29U)) + 6080952401749660022U) + aNonceWordG;
            aOrbiterE = (aWandererB + RotL64(aScatter, 57U)) + 17667234330526298627U;
            aOrbiterB = (((aWandererG + RotL64(aPrevious, 35U)) + 760630072638686756U) + aPhaseHOrbiterAssignSaltB[((aIndex + 18U)) & S_SALT1]) + aNonceWordI;
            aOrbiterF = ((aWandererI + RotL64(aIngress, 12U)) + RotL64(aCarry, 5U)) + 3504157162816997476U;
            aOrbiterK = (((aWandererD + RotL64(aScatter, 51U)) + RotL64(aCarry, 41U)) + 9489022223422585882U) + aNonceWordM;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 1149898536879968964U) + aNonceWordN;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 10492284328940025310U;
            aOrbiterH = RotL64((aOrbiterH * 7893416766300156495U), 13U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterB) + 13213275606286399312U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordP;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 10557118912847180413U) ^ aNonceWordB;
            aOrbiterI = RotL64((aOrbiterI * 10077877991284587845U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 15618980209023994776U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 5268600749854045564U;
            aOrbiterB = RotL64((aOrbiterB * 3849660559223919613U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 8011552687609649990U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 3148133096349525066U;
            aOrbiterK = RotL64((aOrbiterK * 5245156554959620007U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 12032847944237867285U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 14999005703490824673U) ^ aNonceWordH;
            aOrbiterE = RotL64((aOrbiterE * 6631584955208646049U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 5426735969392906710U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 3593177531650386729U;
            aOrbiterF = RotL64((aOrbiterF * 12997284886192717043U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 1701444719333347373U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 15928731228196894960U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 1919318226904213433U), 19U);
            //
            aIngress = RotL64(aOrbiterI, 47U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 35U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 41U));
            aIngress = aIngress + RotL64(aOrbiterC, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aIngress, 12U) + aOrbiterB) + RotL64(aOrbiterH, 19U)) + aNonceWordJ);
            aWandererB = aWandererB ^ ((((RotL64(aScatter, 57U) + aOrbiterF) + RotL64(aOrbiterH, 30U)) + aNonceWordF) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 35U) + RotL64(aOrbiterC, 5U)) + aOrbiterI) + RotL64(aCarry, 57U)) + aNonceWordL);
            aWandererI = aWandererI ^ ((RotL64(aCross, 27U) + aOrbiterK) + RotL64(aOrbiterH, 39U));
            aWandererA = aWandererA + ((RotL64(aPrevious, 41U) + aOrbiterH) + RotL64(aOrbiterI, 57U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 3U) + aOrbiterI) + RotL64(aOrbiterE, 11U)) + aNonceWordO);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 47U) + aOrbiterE) + RotL64(aOrbiterK, 51U)) + RotL64(aCarry, 19U)) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 23U));
            aCarry = aCarry + (RotL64(aWandererH, 41U) ^ aWandererI);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 19U));
            aCarry = aCarry + RotL64(aWandererD, 34U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_h loop 2
        // ingress from: aWorkLaneA, aSnowLaneC, aSnowLaneD, aInvestLaneC
        // ingress directions: aWorkLaneA forward forced, aSnowLaneC forward forced, aSnowLaneD forward forced, aInvestLaneC forward/backward random
        // cross from: aSnowLaneA, aSnowLaneB, aInvestLaneB
        // cross directions: aSnowLaneA backward forced, aSnowLaneB backward forced, aInvestLaneB backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 9669U)) & S_BLOCK1], 34U) ^ RotL64(aSnowLaneC[((aIndex + 10350U)) & S_BLOCK1], 5U));
            aIngress ^= (RotL64(aSnowLaneD[((aIndex + 8018U)) & S_BLOCK1], 47U) ^ RotL64(aInvestLaneC[((aIndex + 5782U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 10243U)) & S_BLOCK1], 43U) ^ RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 6320U)) & S_BLOCK1], 14U));
            aCross ^= RotL64(aInvestLaneB[((aIndex + 6469U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aPrevious, 27U) ^ RotL64(aCarry, 54U)) + (RotL64(aIngress, 13U) ^ RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterI = ((aWandererF + RotL64(aIngress, 38U)) + 3248574644570178787U) + aNonceWordL;
            aOrbiterB = (aWandererE + RotL64(aScatter, 21U)) + 4506961512959200024U;
            aOrbiterG = ((aWandererA + RotL64(aCross, 11U)) + RotL64(aCarry, 5U)) + 8423739774540738590U;
            aOrbiterD = (aWandererK + RotL64(aPrevious, 57U)) + 6593975869641735337U;
            aOrbiterJ = (((aWandererD + RotL64(aIngress, 29U)) + RotL64(aCarry, 57U)) + 16441716090557369103U) + aPhaseHOrbiterAssignSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = (aWandererB + RotL64(aCross, 51U)) + 7936601450453207914U;
            aOrbiterF = ((((aWandererH + RotL64(aPrevious, 5U)) + RotL64(aCarry, 43U)) + 13333752583560167065U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 28U)) & S_SALT1]) + aNonceWordM;
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 8013703284795432973U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 2349852779887439236U;
            aOrbiterG = RotL64((aOrbiterG * 2422888500648100783U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 5318539364763284138U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 11450957608502944376U;
            aOrbiterJ = RotL64((aOrbiterJ * 1957880366707810635U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 9058992558327552687U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 632095686920230926U;
            aOrbiterI = RotL64((aOrbiterI * 12460364388358520799U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 14734218428913777098U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterH) ^ 16344357661370784442U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterB = RotL64((aOrbiterB * 15049472842002138369U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 2981145363531184308U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 14176472085175714494U;
            aOrbiterD = RotL64((aOrbiterD * 2584623327412130939U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 11198457590069700889U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 952584436750426828U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 1165713888651280355U), 23U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterG) + 4311591763498985972U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1]) + aNonceWordK;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 16194341833989936369U;
            aOrbiterH = RotL64((aOrbiterH * 9997934560195932575U), 53U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterJ, 41U);
            aIngress = aIngress + (RotL64(aOrbiterF, 28U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 19U));
            aIngress = aIngress + RotL64(aOrbiterG, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aCross, 3U) + RotL64(aOrbiterH, 57U)) + aOrbiterJ) + aNonceWordD);
            aWandererF = aWandererF ^ ((((RotL64(aPrevious, 41U) + RotL64(aOrbiterH, 5U)) + aOrbiterF) + aNonceWordB) + aPhaseHWandererUpdateSaltB[((aIndex + 12U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 11U) + RotL64(aOrbiterI, 27U)) + aOrbiterB) + RotL64(aCarry, 21U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 21U) + aOrbiterG) + RotL64(aOrbiterJ, 35U));
            aWandererD = aWandererD + (((RotL64(aCross, 54U) + aOrbiterG) + RotL64(aOrbiterF, 42U)) + RotL64(aCarry, 37U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 27U) + aOrbiterB) + RotL64(aOrbiterD, 51U)) + aPhaseHWandererUpdateSaltE[((aIndex + 7U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aIngress, 47U) + aOrbiterG) + RotL64(aOrbiterI, 11U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 27U));
            aCarry = aCarry + (RotL64(aWandererA, 53U) ^ aWandererH);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 42U));
            aCarry = aCarry + RotL64(aWandererE, 21U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 16357U)) & S_BLOCK1], 11U) ^ RotL64(aSnowLaneA[((aIndex + 13594U)) & S_BLOCK1], 30U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 11276U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 11590U)) & S_BLOCK1], 21U) ^ RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 15771U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aPrevious, 23U) + RotL64(aCarry, 5U)) ^ (RotL64(aCross, 54U) ^ RotL64(aIngress, 37U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterH = ((aWandererD + RotL64(aIngress, 35U)) + 16462052553719977502U) + aNonceWordG;
            aOrbiterF = ((aWandererC + RotL64(aScatter, 27U)) + 12337064059566619581U) + aNonceWordP;
            aOrbiterD = (((aWandererB + RotL64(aCross, 57U)) + RotL64(aCarry, 35U)) + 15801005007094515447U) + aNonceWordL;
            aOrbiterE = (((aWandererG + RotL64(aPrevious, 13U)) + RotL64(aCarry, 57U)) + 8228706742665081656U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterK = (aWandererE + RotL64(aScatter, 19U)) + 11006723027845190869U;
            aOrbiterG = ((aWandererF + RotL64(aCross, 46U)) + 18173765337829177450U) + aPhaseHOrbiterAssignSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterJ = ((aWandererI + RotL64(aIngress, 5U)) + RotL64(aCarry, 5U)) + 530215083653542558U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 6608611827035564511U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 2246051826221626809U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 6333352641495253539U), 21U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 5228575308895381421U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 10999213210689606857U) ^ aNonceWordO;
            aOrbiterG = RotL64((aOrbiterG * 5467601259546342925U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 3773371037240485696U) + aNonceWordJ;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 8887985779436152504U;
            aOrbiterK = RotL64((aOrbiterK * 698713082830739677U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 11150566414723818350U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 8336366151003049546U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 9033771197242493699U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 13233968794237090787U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 8172558473508478819U;
            aOrbiterE = RotL64((aOrbiterE * 17837070423649268435U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 133564480283347997U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 15104810248883567064U;
            aOrbiterH = RotL64((aOrbiterH * 706802420642303533U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 9138629520201127075U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 13993086066341664080U;
            aOrbiterJ = RotL64((aOrbiterJ * 4875046427147105077U), 5U);
            //
            aIngress = RotL64(aOrbiterJ, 19U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 35U));
            aIngress = aIngress + (RotL64(aOrbiterF, 53U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterD, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aCross, 3U) + aOrbiterG) + RotL64(aOrbiterK, 6U));
            aWandererC = aWandererC ^ ((((RotL64(aIngress, 41U) + aOrbiterJ) + RotL64(aOrbiterF, 35U)) + aNonceWordH) + aPhaseHWandererUpdateSaltD[((aIndex + 23U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 20U) + aOrbiterH) + RotL64(aOrbiterJ, 47U)) + RotL64(aCarry, 3U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 11U) + aOrbiterJ) + RotL64(aOrbiterG, 13U));
            aWandererF = aWandererF + (((RotL64(aScatter, 57U) + aOrbiterG) + RotL64(aOrbiterH, 53U)) + aPhaseHWandererUpdateSaltA[((aIndex + 26U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterD, 41U)) + aOrbiterK) + aNonceWordF);
            aWandererD = aWandererD + (((RotL64(aIngress, 29U) + RotL64(aOrbiterE, 29U)) + aOrbiterG) + RotL64(aCarry, 43U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 23U) ^ aWandererD);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 4U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 43U));
            aCarry = aCarry + RotL64(aWandererI, 27U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 19827U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneA[((aIndex + 17388U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 18582U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 17009U)) & S_BLOCK1], 11U) ^ RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 21156U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aIngress, 3U) + RotL64(aCarry, 53U)) ^ (RotL64(aPrevious, 39U) + RotL64(aCross, 20U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterK = ((((aWandererK + RotL64(aCross, 5U)) + RotL64(aCarry, 39U)) + 3684295017013759987U) + aPhaseHOrbiterAssignSaltD[((aIndex + 7U)) & S_SALT1]) + aNonceWordG;
            aOrbiterA = (((aWandererF + RotL64(aPrevious, 60U)) + RotL64(aCarry, 3U)) + 6740408842457292881U) + aNonceWordK;
            aOrbiterI = (((aWandererD + RotL64(aScatter, 29U)) + 4563975890702399441U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 4U)) & S_SALT1]) + aNonceWordH;
            aOrbiterJ = (aWandererI + RotL64(aIngress, 13U)) + 797804144825287940U;
            aOrbiterC = (aWandererG + RotL64(aScatter, 53U)) + 2763779540450101303U;
            aOrbiterH = ((aWandererB + RotL64(aIngress, 19U)) + RotL64(aCarry, 51U)) + 13211846164102089685U;
            aOrbiterD = ((aWandererA + RotL64(aCross, 37U)) + 15214578447281401982U) + aNonceWordN;
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 13745208628754232427U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 17358621225969190747U) ^ aNonceWordD;
            aOrbiterI = RotL64((aOrbiterI * 5325024317338823061U), 21U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterC) + 779739369960480023U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordC;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 4370963533701407813U;
            aOrbiterK = RotL64((aOrbiterK * 3123135216876641039U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 6061333005507739975U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 3589705340762734456U;
            aOrbiterD = RotL64((aOrbiterD * 16499293983611196967U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 10607697666369230567U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 9356757995305239271U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10945513661439954731U), 37U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 10093033335903048138U) + aNonceWordE;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 11037328061699834100U;
            aOrbiterH = RotL64((aOrbiterH * 11189760551792389605U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 558431161176115540U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 17795680919453449358U;
            aOrbiterC = RotL64((aOrbiterC * 3910117359996283803U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 6096779391116214109U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 17594243286880690775U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 12655610181937429915U), 29U);
            //
            aIngress = RotL64(aOrbiterK, 51U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterD, 30U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterC, 19U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterI, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aPrevious, 50U) + RotL64(aOrbiterK, 27U)) + aOrbiterI) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterJ, 11U)) + aOrbiterK);
            aWandererK = aWandererK + ((((RotL64(aCross, 37U) + aOrbiterD) + RotL64(aOrbiterC, 47U)) + RotL64(aCarry, 19U)) + aNonceWordI);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 19U) + aOrbiterA) + RotL64(aOrbiterC, 5U));
            aWandererB = aWandererB + ((RotL64(aPrevious, 43U) + RotL64(aOrbiterJ, 21U)) + aOrbiterD);
            aWandererA = aWandererA ^ ((((RotL64(aCross, 27U) + RotL64(aOrbiterH, 56U)) + aOrbiterD) + aNonceWordA) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aIngress, 5U) + aOrbiterJ) + RotL64(aOrbiterH, 37U)) + RotL64(aCarry, 43U)) + aNonceWordL);
            //
            aCarry = aCarry + (RotL64(aWandererF, 35U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererB, 28U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererK, 5U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererG, 41U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 24885U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((aIndex + 23472U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 26487U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 25885U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneA[((aIndex + 23448U)) & S_BLOCK1], 20U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCross, 39U) + RotL64(aIngress, 57U)) ^ (RotL64(aCarry, 27U) ^ RotL64(aPrevious, 14U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterD = ((aWandererC + RotL64(aIngress, 21U)) + RotL64(aCarry, 47U)) + 12046647397183218524U;
            aOrbiterG = ((aWandererB + RotL64(aCross, 5U)) + RotL64(aCarry, 29U)) + 2760779375026461991U;
            aOrbiterF = (((aWandererD + RotL64(aScatter, 27U)) + 13735454443176855650U) + aPhaseHOrbiterAssignSaltF[((aIndex + 24U)) & S_SALT1]) + aNonceWordK;
            aOrbiterK = (((aWandererG + RotL64(aPrevious, 34U)) + RotL64(aCarry, 3U)) + 4370377000586647724U) + aNonceWordM;
            aOrbiterA = ((aWandererH + RotL64(aScatter, 13U)) + 14566322384189969094U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = ((aWandererF + RotL64(aPrevious, 53U)) + 5056565959818422786U) + aNonceWordJ;
            aOrbiterB = ((aWandererJ + RotL64(aIngress, 41U)) + 8795403810686579209U) + aNonceWordD;
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 9625947666256011567U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterD) ^ 1703669290934254701U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterF = RotL64((aOrbiterF * 5763881345676123583U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 6664070663184147951U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 2104148316797553431U;
            aOrbiterD = RotL64((aOrbiterD * 12887842067180975983U), 5U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterD) + 1197910004222596145U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1]) + aNonceWordO;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 9922977170060903197U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 13047828062605568603U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 2048376210852567829U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 12568990647075931409U;
            aOrbiterA = RotL64((aOrbiterA * 9860242601194210927U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 15026894775772902751U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 3439447160137900629U;
            aOrbiterK = RotL64((aOrbiterK * 1813754963043785165U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 6532671388552829796U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 17261098369835997661U;
            aOrbiterG = RotL64((aOrbiterG * 568292591215203521U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 3171300991007459947U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 5935563269327662024U;
            aOrbiterJ = RotL64((aOrbiterJ * 11271790283157765003U), 53U);
            //
            aIngress = RotL64(aOrbiterB, 35U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 43U));
            aIngress = aIngress + (RotL64(aOrbiterF, 13U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterA, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 5U) + aOrbiterG) + RotL64(aOrbiterB, 13U)) + RotL64(aCarry, 11U)) + aNonceWordC);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 35U) + aOrbiterD) + RotL64(aOrbiterK, 29U)) + aNonceWordE);
            aWandererG = aWandererG + ((((RotL64(aCross, 13U) + aOrbiterJ) + RotL64(aOrbiterF, 41U)) + RotL64(aCarry, 47U)) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 47U) + aOrbiterD) + RotL64(aOrbiterF, 53U)) + aPhaseHWandererUpdateSaltE[((aIndex + 19U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 29U) + aOrbiterJ) + RotL64(aOrbiterB, 47U)) + aNonceWordN);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 23U) + aOrbiterA) + RotL64(aOrbiterJ, 19U));
            aWandererF = aWandererF + (((RotL64(aScatter, 56U) + aOrbiterG) + RotL64(aOrbiterA, 4U)) + aNonceWordL);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 14U));
            aCarry = aCarry + (RotL64(aWandererC, 29U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererH, 35U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererJ, 57U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_h loop 6
        // ingress from: aExpandLaneC, aExpandLaneA, aFireLaneA
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aFireLaneA forward/backward random
        // cross from: aExpandLaneB, aSnowLaneB
        // cross directions: aExpandLaneB backward forced, aSnowLaneB backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 27635U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneA[((aIndex + 28584U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 31135U)) & S_BLOCK1], 58U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27886U)) & S_BLOCK1], 27U) ^ RotL64(aSnowLaneB[((aIndex + 28636U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aPrevious, 11U) ^ RotL64(aCross, 24U)) ^ (RotL64(aIngress, 53U) + RotL64(aCarry, 37U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterG = (aWandererI + RotL64(aIngress, 28U)) + 6318740973868639425U;
            aOrbiterJ = (aWandererK + RotL64(aPrevious, 13U)) + 5487840061430920881U;
            aOrbiterC = (((aWandererE + RotL64(aCross, 21U)) + 10258706763248072672U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 16U)) & S_SALT1]) + aNonceWordK;
            aOrbiterA = (((aWandererJ + RotL64(aScatter, 53U)) + 18356875269730338208U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordG;
            aOrbiterB = ((aWandererB + RotL64(aCross, 3U)) + RotL64(aCarry, 21U)) + 12883160282903147010U;
            aOrbiterH = ((aWandererD + RotL64(aIngress, 47U)) + RotL64(aCarry, 51U)) + 1010140474942697730U;
            aOrbiterF = ((aWandererH + RotL64(aPrevious, 35U)) + RotL64(aCarry, 37U)) + 17733939421700898293U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 13693055887924981201U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 14574732452793385269U;
            aOrbiterC = RotL64((aOrbiterC * 9373765929885750185U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 10832873941223609012U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 8212600587135328040U;
            aOrbiterB = RotL64((aOrbiterB * 5334613996794796145U), 13U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterG) + 5312744319781971178U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1]) + aNonceWordF;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 6173741211706546923U;
            aOrbiterH = RotL64((aOrbiterH * 12854414066390848249U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 3693249147883790810U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 18365859989736602556U;
            aOrbiterG = RotL64((aOrbiterG * 3348463719324104997U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 10645056678337549771U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 1175668356822251045U;
            aOrbiterF = RotL64((aOrbiterF * 6579675292775345579U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 13556844570541823717U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 4790355739411849736U;
            aOrbiterJ = RotL64((aOrbiterJ * 4083544011788850307U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 14905575502272644116U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 17047244574558476634U) ^ aNonceWordM;
            aOrbiterA = RotL64((aOrbiterA * 2356386971503880047U), 53U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterJ, 41U);
            aIngress = aIngress + (RotL64(aOrbiterA, 6U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterF, 13U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterG, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((((RotL64(aPrevious, 57U) + RotL64(aOrbiterB, 57U)) + aOrbiterC) + RotL64(aCarry, 29U)) + aNonceWordJ) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterB, 19U)) + aOrbiterJ);
            aWandererB = aWandererB + (((RotL64(aScatter, 43U) + aOrbiterA) + RotL64(aOrbiterG, 3U)) + RotL64(aCarry, 47U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 20U) + RotL64(aOrbiterG, 35U)) + aOrbiterB) + aNonceWordO);
            aWandererI = aWandererI + ((((RotL64(aScatter, 3U) + RotL64(aOrbiterF, 11U)) + aOrbiterH) + aNonceWordP) + aPhaseHWandererUpdateSaltD[((aIndex + 22U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterH, 51U)) + aOrbiterC);
            aWandererE = aWandererE + ((RotL64(aIngress, 11U) + aOrbiterJ) + RotL64(aOrbiterA, 42U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 46U));
            aCarry = aCarry + (RotL64(aWandererD, 53U) ^ aWandererI);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 3U));
            aCarry = aCarry + RotL64(aWandererJ, 29U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA;
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
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltA;
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
            aIngress = RotL64(aKeyRowReadA[((aIndex + 2112U)) & W_KEY1], 27U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 1510U)) & W_KEY1], 58U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 1226U)) & W_KEY1], 36U) ^ RotL64(mSource[((aIndex + 1009U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 19U) + RotL64(aCarry, 35U)) ^ (RotL64(aCross, 54U) + RotL64(aPrevious, 3U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterE = ((aWandererK + RotL64(aIngress, 39U)) + RotL64(aCarry, 23U)) + 12027839670755583592U;
            aOrbiterC = ((aWandererE + RotL64(aScatter, 35U)) + RotL64(aCarry, 3U)) + 15380130703509859843U;
            aOrbiterD = ((aWandererC + RotL64(aPrevious, 26U)) + 4590907433867798074U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterF = ((aWandererH + RotL64(aCross, 57U)) + RotL64(aCarry, 35U)) + 1754574023602519724U;
            aOrbiterJ = (aWandererA + RotL64(aPrevious, 21U)) + 9832756659564903767U;
            aOrbiterK = (aWandererG + RotL64(aScatter, 51U)) + 5035088494491470403U;
            aOrbiterB = (aWandererF + RotL64(aCross, 14U)) + 14199170923323644638U;
            aOrbiterA = ((aWandererJ + RotL64(aIngress, 5U)) + 8325619421264440438U) + aPhaseAOrbiterAssignSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterG = (aWandererD + RotL64(aPrevious, 47U)) + 969534320779067977U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 270575869402913847U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 13344806516599578910U;
            aOrbiterD = RotL64((aOrbiterD * 10193544126281901579U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 15143147951139409101U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 14425582489214169238U;
            aOrbiterJ = RotL64((aOrbiterJ * 16893787086337916355U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 13951127523239064584U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 14177925225918293579U;
            aOrbiterB = RotL64((aOrbiterB * 13079514031864998485U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 8258920744278218901U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 7408161179397242453U;
            aOrbiterC = RotL64((aOrbiterC * 975737128100519169U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 8581481606764773468U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 10078416198417433133U;
            aOrbiterA = RotL64((aOrbiterA * 1102721083915858247U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 18299772198826189580U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 18304668908084397946U;
            aOrbiterE = RotL64((aOrbiterE * 10589455451200578687U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 16729632621573817223U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 13362300981585573239U;
            aOrbiterK = RotL64((aOrbiterK * 9824473895535518785U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 8629682832849915380U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 6852852009091469641U;
            aOrbiterG = RotL64((aOrbiterG * 11912646687050011915U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 7433098156961745198U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 10931806208899417308U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 14699197041038067483U), 51U);
            //
            aIngress = RotL64(aOrbiterF, 3U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 13U));
            aIngress = aIngress + (RotL64(aOrbiterE, 6U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 39U));
            aIngress = aIngress + RotL64(aOrbiterK, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aCross, 48U) + aOrbiterA) + RotL64(aOrbiterC, 34U));
            aWandererF = aWandererF + ((RotL64(aPrevious, 19U) + aOrbiterB) + RotL64(aOrbiterJ, 47U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 23U) + aOrbiterE) + RotL64(aOrbiterD, 21U)) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aIngress, 13U) + aOrbiterK) + RotL64(aOrbiterD, 43U)) + RotL64(aCarry, 5U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 35U) + aOrbiterJ) + RotL64(aOrbiterC, 51U));
            aWandererJ = aWandererJ + ((RotL64(aIngress, 57U) + aOrbiterG) + RotL64(aOrbiterE, 3U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterG, 13U)) + aOrbiterB);
            aWandererK = aWandererK + ((((RotL64(aScatter, 39U) + aOrbiterJ) + RotL64(aOrbiterE, 28U)) + RotL64(aCarry, 47U)) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 44U) + RotL64(aOrbiterF, 39U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 5U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 39U));
            aCarry = aCarry + (RotL64(aWandererC, 11U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererJ, 56U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 3134U)) & S_BLOCK1], 5U) ^ RotL64(aKeyRowReadA[((aIndex + 3628U)) & W_KEY1], 54U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 3954U)) & W_KEY1], 60U) ^ RotL64(mSource[((aIndex + 4866U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 21U) + RotL64(aPrevious, 4U)) ^ (RotL64(aCross, 37U) + RotL64(aIngress, 51U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterJ = (aWandererA + RotL64(aCross, 35U)) + 16922357079016918108U;
            aOrbiterA = (((aWandererB + RotL64(aScatter, 54U)) + RotL64(aCarry, 37U)) + 11771749797137599131U) + aPhaseAOrbiterAssignSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = ((aWandererC + RotL64(aIngress, 19U)) + 4635668433708036077U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterI = ((aWandererK + RotL64(aPrevious, 39U)) + RotL64(aCarry, 13U)) + 15827952719230577008U;
            aOrbiterD = (aWandererD + RotL64(aCross, 27U)) + 1495675306110023086U;
            aOrbiterF = (aWandererH + RotL64(aScatter, 43U)) + 7294835466949728365U;
            aOrbiterK = (aWandererG + RotL64(aPrevious, 3U)) + 179122461212041978U;
            aOrbiterH = ((aWandererE + RotL64(aIngress, 47U)) + RotL64(aCarry, 5U)) + 545981421632236251U;
            aOrbiterC = (aWandererI + RotL64(aPrevious, 12U)) + 15338259639814630535U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 12924313840290895215U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 17846785921286020610U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 18309347016029917133U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 5721472794107057875U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 16359630793856870319U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 14186771515526698907U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 10614102110239037308U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 16421992251278236531U;
            aOrbiterF = RotL64((aOrbiterF * 2561232904676068089U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 8668149834861244963U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 12699331834360948734U;
            aOrbiterK = RotL64((aOrbiterK * 2249360824172616357U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 4470693178142950471U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 526000656022724741U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 16688501462334673493U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 6880246132270094141U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 7126466778855297013U;
            aOrbiterC = RotL64((aOrbiterC * 5692237926830293205U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 6436404501390442054U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 1213633065612242699U;
            aOrbiterI = RotL64((aOrbiterI * 17604454985534439259U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 8186529105901185854U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 10607460957358250935U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 17172191011625677861U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 9743278964993305169U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 14007577681873418075U;
            aOrbiterH = RotL64((aOrbiterH * 4231122580398039133U), 47U);
            //
            aIngress = RotL64(aOrbiterD, 53U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterC, 23U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterK, 39U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterF, 30U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterA, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aCross, 13U) + aOrbiterD) + RotL64(aOrbiterC, 12U)) + aPhaseAWandererUpdateSaltA[((aIndex + 14U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterF, 51U)) + aOrbiterI);
            aWandererK = aWandererK + (((RotL64(aPrevious, 51U) + aOrbiterJ) + RotL64(aOrbiterG, 43U)) + RotL64(aCarry, 47U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 47U) + aOrbiterF) + RotL64(aOrbiterD, 39U));
            aWandererI = aWandererI + (((RotL64(aCross, 6U) + RotL64(aOrbiterH, 23U)) + aOrbiterK) + RotL64(aCarry, 37U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 57U) + aOrbiterJ) + RotL64(aOrbiterC, 57U)) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aIngress, 29U) + RotL64(aOrbiterK, 28U)) + aOrbiterJ);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 19U) + aOrbiterK) + RotL64(aOrbiterG, 47U));
            aWandererE = aWandererE + ((RotL64(aScatter, 36U) + aOrbiterA) + RotL64(aOrbiterH, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 50U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererE, 47U) ^ aWandererD);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 53U));
            aCarry = aCarry + (RotL64(aWandererG, 23U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererI, 41U);
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
            aIngress = RotL64(aWorkLaneB[((aIndex + 5866U)) & S_BLOCK1], 35U) ^ RotL64(aKeyRowReadB[((aIndex + 7768U)) & W_KEY1], 56U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 6373U)) & W_KEY1], 19U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 6739U)) & S_BLOCK1], 54U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 5895U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 48U) ^ RotL64(aCross, 35U)) + (RotL64(aIngress, 3U) ^ RotL64(aCarry, 19U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterH = ((aWandererB + RotL64(aPrevious, 48U)) + RotL64(aCarry, 51U)) + 6973892330986118220U;
            aOrbiterD = ((aWandererH + RotL64(aIngress, 43U)) + 9886813896272094864U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = ((aWandererA + RotL64(aScatter, 53U)) + RotL64(aCarry, 27U)) + 10996306582517553173U;
            aOrbiterF = ((aWandererF + RotL64(aCross, 3U)) + 8490648283899856223U) + aPhaseAOrbiterAssignSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterE = (aWandererE + RotL64(aIngress, 19U)) + 105141713530704655U;
            aOrbiterJ = (aWandererI + RotL64(aScatter, 37U)) + 3114337422810562588U;
            aOrbiterG = ((aWandererC + RotL64(aCross, 23U)) + RotL64(aCarry, 19U)) + 980857684690886131U;
            aOrbiterA = (aWandererG + RotL64(aPrevious, 28U)) + 6562042345807072665U;
            aOrbiterI = (aWandererK + RotL64(aIngress, 11U)) + 15665371138706353619U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 18113013571374375028U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 17405346422601997299U;
            aOrbiterC = RotL64((aOrbiterC * 11162604605443005253U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 5130876096426182506U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 1813821672299154629U;
            aOrbiterD = RotL64((aOrbiterD * 15478100342425611875U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 15793814882743306728U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 13925299440495476399U;
            aOrbiterH = RotL64((aOrbiterH * 12049601510660117401U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 9924458846049579438U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 7810034662781768090U;
            aOrbiterA = RotL64((aOrbiterA * 10310594595026622513U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 12812586478656872854U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 5709576448057435237U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 9101555233909853025U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 7839807649914541516U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 4717944526755429647U;
            aOrbiterE = RotL64((aOrbiterE * 8515229146471335721U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 3933911971504256022U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 4814079680865379831U;
            aOrbiterJ = RotL64((aOrbiterJ * 15100740696230557391U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 18352577312212175569U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 9670612998448920742U;
            aOrbiterG = RotL64((aOrbiterG * 5743579439303300553U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 72737302703035726U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 10032869372369626210U;
            aOrbiterF = RotL64((aOrbiterF * 7449905669249993731U), 23U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterJ, 41U);
            aIngress = aIngress + (RotL64(aOrbiterG, 48U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 53U));
            aIngress = aIngress + (RotL64(aOrbiterE, 5U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterA, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aScatter, 53U) + RotL64(aOrbiterH, 57U)) + aOrbiterC) + RotL64(aCarry, 41U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterC, 36U)) + aOrbiterD);
            aWandererC = aWandererC + ((RotL64(aCross, 60U) + RotL64(aOrbiterD, 19U)) + aOrbiterJ);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 13U) + aOrbiterH) + RotL64(aOrbiterI, 41U));
            aWandererG = aWandererG + ((((RotL64(aCross, 47U) + RotL64(aOrbiterD, 13U)) + aOrbiterE) + RotL64(aCarry, 29U)) + aPhaseAWandererUpdateSaltB[((aIndex + 10U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 23U) + RotL64(aOrbiterH, 51U)) + aOrbiterD) + aPhaseAWandererUpdateSaltE[((aIndex + 7U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aScatter, 36U) + aOrbiterG) + RotL64(aOrbiterA, 47U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 43U) + aOrbiterJ) + RotL64(aOrbiterA, 3U));
            aWandererB = aWandererB + ((RotL64(aScatter, 19U) + RotL64(aOrbiterF, 30U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererE, 3U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererH, 21U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererG, 43U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererA, 29U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererF, 51U);
            aCarry = aCarry + RotL64(aIngress, 54U);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 9455U)) & S_BLOCK1], 19U) ^ RotL64(aKeyRowReadB[((aIndex + 10320U)) & W_KEY1], 43U));
            aIngress ^= (RotL64(mSource[((aIndex + 10645U)) & S_BLOCK1], 28U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 9543U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 9606U)) & W_KEY1], 42U) ^ RotL64(aWorkLaneB[((aIndex + 9107U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 54U) + RotL64(aPrevious, 5U)) ^ (RotL64(aIngress, 39U) + RotL64(aCarry, 19U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterK = ((aWandererE + RotL64(aCross, 51U)) + RotL64(aCarry, 39U)) + 5697928251815176134U;
            aOrbiterG = (aWandererB + RotL64(aIngress, 10U)) + 337587740689259575U;
            aOrbiterC = ((aWandererC + RotL64(aScatter, 41U)) + RotL64(aCarry, 5U)) + 4927686903263973950U;
            aOrbiterB = ((aWandererA + RotL64(aPrevious, 19U)) + RotL64(aCarry, 13U)) + 3742409032569801033U;
            aOrbiterF = ((aWandererF + RotL64(aScatter, 57U)) + 1608092659172197650U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterA = (aWandererD + RotL64(aPrevious, 37U)) + 15848744267145717509U;
            aOrbiterI = (aWandererK + RotL64(aIngress, 23U)) + 15300174177963339253U;
            aOrbiterJ = (aWandererH + RotL64(aCross, 28U)) + 14162868453323648628U;
            aOrbiterH = ((aWandererJ + RotL64(aIngress, 3U)) + 12020167069983729869U) + aPhaseBOrbiterAssignSaltE[((aIndex + 17U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 16259538291658723956U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 8516686212464112245U;
            aOrbiterC = RotL64((aOrbiterC * 4731296903548893627U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 3722184575520553132U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 5663609293306386784U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 14364218128780764749U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 15265344442454471986U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 3050323350098829515U;
            aOrbiterB = RotL64((aOrbiterB * 5890624677162388135U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 1093356813820599238U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 15167726103772238440U;
            aOrbiterA = RotL64((aOrbiterA * 5719466863561311069U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 15170797965325981472U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 17826286701992981628U;
            aOrbiterI = RotL64((aOrbiterI * 11186808881726573677U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 14710892030473425181U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 397194787697553904U;
            aOrbiterJ = RotL64((aOrbiterJ * 14368930300818752833U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 1273724124862533034U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 13018397560392545616U;
            aOrbiterH = RotL64((aOrbiterH * 4644812473262395329U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 9638716186445643730U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 7255587739807843785U;
            aOrbiterK = RotL64((aOrbiterK * 6055682981584011189U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 9272350563697399628U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 1040729335295009339U;
            aOrbiterG = RotL64((aOrbiterG * 17825687660830291443U), 19U);
            //
            aIngress = RotL64(aOrbiterI, 36U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterF, 5U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 23U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 43U));
            aIngress = aIngress + RotL64(aOrbiterB, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aCross, 53U) + aOrbiterG) + RotL64(aOrbiterC, 13U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 35U) + aOrbiterG) + RotL64(aOrbiterK, 21U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 43U) + aOrbiterJ) + RotL64(aOrbiterH, 57U)) + RotL64(aCarry, 43U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 60U) + RotL64(aOrbiterF, 6U)) + aOrbiterI);
            aWandererB = aWandererB + (((RotL64(aIngress, 39U) + RotL64(aOrbiterA, 53U)) + aOrbiterI) + RotL64(aCarry, 53U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 27U) + aOrbiterI) + RotL64(aOrbiterJ, 47U));
            aWandererK = aWandererK + ((RotL64(aCross, 19U) + RotL64(aOrbiterB, 27U)) + aOrbiterK);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 6U) + aOrbiterG) + RotL64(aOrbiterB, 34U)) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 47U) + aOrbiterC) + RotL64(aOrbiterI, 43U)) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 3U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 28U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 47U));
            aCarry = aCarry + (RotL64(aWandererC, 19U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererD, 57U);
            aCarry = aCarry + RotL64(aIngress, 60U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 12021U)) & S_BLOCK1], 11U) ^ RotL64(aKeyRowReadA[((aIndex + 11590U)) & W_KEY1], 52U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 12136U)) & W_KEY1], 3U) ^ RotL64(mSource[((aIndex + 13228U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aWorkLaneB[((aIndex + 10976U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 10930U)) & S_BLOCK1], 34U) ^ RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 11965U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 39U) + RotL64(aPrevious, 52U)) ^ (RotL64(aCarry, 23U) ^ RotL64(aIngress, 3U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterD = (aWandererJ + RotL64(aCross, 57U)) + 15188686795415908074U;
            aOrbiterF = (aWandererH + RotL64(aPrevious, 4U)) + 17310049041983079779U;
            aOrbiterC = ((aWandererD + RotL64(aScatter, 27U)) + RotL64(aCarry, 57U)) + 8246925977992441471U;
            aOrbiterB = (aWandererE + RotL64(aIngress, 51U)) + 8644260919918112781U;
            aOrbiterG = (aWandererG + RotL64(aScatter, 37U)) + 13401663736874819483U;
            aOrbiterA = (((aWandererI + RotL64(aPrevious, 12U)) + RotL64(aCarry, 37U)) + 7940358935238314973U) + aPhaseBOrbiterAssignSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterE = ((aWandererB + RotL64(aIngress, 41U)) + 13278990328548007839U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterJ = ((aWandererA + RotL64(aCross, 19U)) + RotL64(aCarry, 3U)) + 11346868298353840706U;
            aOrbiterI = (aWandererF + RotL64(aScatter, 47U)) + 2374077904806833579U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 6978903378645019166U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 11951633297870965212U;
            aOrbiterC = RotL64((aOrbiterC * 12778236598654492185U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 17398460995357409673U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 1215437945597836770U;
            aOrbiterA = RotL64((aOrbiterA * 9322970054123481621U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 1878751468043972239U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 5343002808239712390U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 11878640995447558811U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 9884918450053276861U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 15894599082080422550U;
            aOrbiterD = RotL64((aOrbiterD * 8359936745539546131U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 13917339232771145459U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 18101134009493720683U;
            aOrbiterF = RotL64((aOrbiterF * 15835859435306756387U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 3830086372356903769U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 15894394599564584010U;
            aOrbiterB = RotL64((aOrbiterB * 9513921913446609263U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 5127590955274245812U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 9410946933309720054U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 14507476989423060561U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 15544384157294987085U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 998801294460434123U;
            aOrbiterG = RotL64((aOrbiterG * 5946968142746472745U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 16442095194965452163U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 14294936349037516932U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 14655345374740882581U), 51U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterJ, 23U);
            aIngress = aIngress + (RotL64(aOrbiterB, 29U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 47U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 41U));
            aIngress = aIngress + RotL64(aOrbiterA, 38U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aScatter, 47U) + aOrbiterI) + RotL64(aOrbiterC, 11U)) + RotL64(aCarry, 39U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterD, 43U)) + aOrbiterB);
            aWandererA = aWandererA + ((((RotL64(aIngress, 28U) + RotL64(aOrbiterI, 39U)) + aOrbiterG) + RotL64(aCarry, 29U)) + aPhaseBWandererUpdateSaltD[((aIndex + 18U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 41U) + aOrbiterJ) + RotL64(aOrbiterG, 24U));
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 37U) + aOrbiterE) + RotL64(aOrbiterB, 57U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 57U) + aOrbiterJ) + RotL64(aOrbiterA, 53U));
            aWandererH = aWandererH + ((RotL64(aIngress, 19U) + aOrbiterA) + RotL64(aOrbiterE, 47U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 23U) + RotL64(aOrbiterG, 35U)) + aOrbiterF) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aScatter, 6U) + aOrbiterB) + RotL64(aOrbiterA, 4U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 47U));
            aCarry = aCarry + (RotL64(aWandererB, 29U) ^ aWandererI);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 19U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 60U));
            aCarry = aCarry + RotL64(aWandererA, 53U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 16142U)) & S_BLOCK1], 21U) ^ RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 13659U)) & S_BLOCK1], 40U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 15132U)) & W_KEY1], 43U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 14054U)) & W_KEY1], 35U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 16051U)) & S_BLOCK1], 52U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 15382U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16047U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 6U) + RotL64(aIngress, 23U)) ^ (RotL64(aCross, 57U) + RotL64(aPrevious, 41U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterG = (aWandererF + RotL64(aPrevious, 39U)) + 16189787374324972735U;
            aOrbiterF = (aWandererB + RotL64(aIngress, 14U)) + 17563763730956242224U;
            aOrbiterD = (aWandererD + RotL64(aScatter, 3U)) + 10572803498593789385U;
            aOrbiterI = ((aWandererH + RotL64(aCross, 43U)) + RotL64(aCarry, 3U)) + 7713105232072974166U;
            aOrbiterA = ((aWandererA + RotL64(aIngress, 23U)) + 10760839534772718139U) + aPhaseBOrbiterAssignSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterH = (aWandererG + RotL64(aCross, 19U)) + 13397069448391230253U;
            aOrbiterK = ((aWandererC + RotL64(aPrevious, 29U)) + RotL64(aCarry, 13U)) + 4569255679998375682U;
            aOrbiterC = (((aWandererE + RotL64(aScatter, 52U)) + RotL64(aCarry, 57U)) + 9888769350817876949U) + aPhaseBOrbiterAssignSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterE = (aWandererK + RotL64(aCross, 47U)) + 11351796060878856300U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 18153775071965707204U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 1282846411145853435U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 12294455920906257823U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 16457743979262460660U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 173493260775251032U;
            aOrbiterH = RotL64((aOrbiterH * 4935807229040883505U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 3927345926316409630U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 5158769729850853623U;
            aOrbiterK = RotL64((aOrbiterK * 2446452358663812945U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 12331351600010165154U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 3940794200348684050U;
            aOrbiterA = RotL64((aOrbiterA * 13248997263062075043U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 11248514843822945425U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 1391497323278226522U;
            aOrbiterC = RotL64((aOrbiterC * 8376841806072565005U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 13265623528678787307U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 2802033745265647317U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 3437626962562016147U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 6938444301018051844U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 1086544666755559028U;
            aOrbiterE = RotL64((aOrbiterE * 16039728388882079889U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 16156443117365816536U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 3619942859562697142U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7589346043159112151U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 17681848914912743292U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 8848238631758130416U;
            aOrbiterF = RotL64((aOrbiterF * 810402256099500607U), 29U);
            //
            aIngress = RotL64(aOrbiterC, 34U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterF, 21U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterI, 51U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterD, 37U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterH, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aScatter, 35U) + aOrbiterC) + RotL64(aOrbiterK, 29U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 12U) + aOrbiterK) + RotL64(aOrbiterE, 4U)) + RotL64(aCarry, 27U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 43U) + aOrbiterF) + RotL64(aOrbiterA, 43U)) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aIngress, 39U) + aOrbiterA) + RotL64(aOrbiterC, 21U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 5U) + aOrbiterD) + RotL64(aOrbiterI, 47U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 21U) + RotL64(aOrbiterE, 35U)) + aOrbiterG);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterA, 57U)) + aOrbiterD);
            aWandererD = aWandererD + (((RotL64(aIngress, 56U) + aOrbiterC) + RotL64(aOrbiterG, 53U)) + RotL64(aCarry, 41U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 51U) + aOrbiterH) + RotL64(aOrbiterF, 12U)) + aPhaseBWandererUpdateSaltC[((aIndex + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 23U));
            aCarry = aCarry + (RotL64(aWandererE, 53U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererD, 43U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererK, 50U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererC, 5U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 18165U)) & S_BLOCK1], 21U) ^ RotL64(aKeyRowReadA[((aIndex + 18298U)) & W_KEY1], 39U));
            aIngress ^= (RotL64(mSource[((aIndex + 17976U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17902U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 18733U)) & W_KEY1], 27U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 18779U)) & S_BLOCK1], 46U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 18257U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 29U) ^ RotL64(aPrevious, 57U)) + (RotL64(aIngress, 13U) + RotL64(aCarry, 42U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterH = (aWandererG + RotL64(aScatter, 23U)) + 13499155707765393469U;
            aOrbiterD = (aWandererK + RotL64(aCross, 5U)) + 3740324981823726185U;
            aOrbiterJ = (aWandererF + RotL64(aIngress, 43U)) + 5470765363949735652U;
            aOrbiterA = ((aWandererI + RotL64(aPrevious, 18U)) + RotL64(aCarry, 57U)) + 3446436171274452326U;
            aOrbiterB = (((aWandererC + RotL64(aCross, 35U)) + RotL64(aCarry, 23U)) + 1778929412631211933U) + aPhaseCOrbiterAssignSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterG = ((aWandererH + RotL64(aScatter, 39U)) + RotL64(aCarry, 35U)) + 14666308799855220954U;
            aOrbiterK = (aWandererA + RotL64(aIngress, 11U)) + 4548410236791175055U;
            aOrbiterF = (aWandererD + RotL64(aPrevious, 48U)) + 5829739767694190372U;
            aOrbiterI = ((aWandererJ + RotL64(aIngress, 27U)) + 14319231414903675748U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 1513851750246111405U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 1685620217748986019U;
            aOrbiterJ = RotL64((aOrbiterJ * 9286548037413609445U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 16284162182006054402U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 6271539598462003309U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 13923286694131331137U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 12669312437565969473U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 11894755313393001665U) ^ aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 12556759675372354075U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 6315983824634946566U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 17106616474222892782U;
            aOrbiterH = RotL64((aOrbiterH * 167205520766791073U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 13350266700180455548U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 4608846311203767162U;
            aOrbiterI = RotL64((aOrbiterI * 2504857468837437365U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 14195866746143604365U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 7917977448256795054U) ^ aPhaseCOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 5927771378657284557U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 10707336923305131629U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 17122696159336995392U;
            aOrbiterD = RotL64((aOrbiterD * 13953518568670659191U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 5182322763573586116U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 6503754948502556246U;
            aOrbiterA = RotL64((aOrbiterA * 14749002194140663519U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 14907832047832987341U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 6258064448676621346U) ^ aPhaseCOrbiterUpdateSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4407960312705621487U), 27U);
            //
            aIngress = RotL64(aOrbiterJ, 41U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterH, 27U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 23U));
            aIngress = aIngress + (RotL64(aOrbiterF, 44U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterD, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aCross, 39U) + RotL64(aOrbiterH, 47U)) + aOrbiterI) + RotL64(aCarry, 47U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 29U) + aOrbiterB) + RotL64(aOrbiterG, 6U));
            aWandererD = aWandererD + (((RotL64(aIngress, 60U) + RotL64(aOrbiterG, 39U)) + aOrbiterD) + aPhaseCWandererUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 43U) + aOrbiterI) + RotL64(aOrbiterJ, 19U));
            aWandererI = aWandererI + (((RotL64(aIngress, 51U) + aOrbiterA) + RotL64(aOrbiterD, 35U)) + RotL64(aCarry, 21U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 13U) + aOrbiterJ) + RotL64(aOrbiterA, 12U));
            aWandererG = aWandererG + (((RotL64(aCross, 47U) + aOrbiterF) + RotL64(aOrbiterK, 57U)) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 35U) + aOrbiterA) + RotL64(aOrbiterB, 27U));
            aWandererF = aWandererF + ((RotL64(aScatter, 4U) + aOrbiterK) + RotL64(aOrbiterD, 51U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 23U) ^ aWandererJ);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 34U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 27U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 13U));
            aCarry = aCarry + RotL64(aWandererD, 19U);
            aCarry = aCarry + RotL64(aIngress, 30U);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 19579U)) & S_BLOCK1], 11U) ^ RotL64(mSource[((aIndex + 21621U)) & S_BLOCK1], 47U));
            aIngress ^= (RotL64(aFireLaneA[((aIndex + 21267U)) & S_BLOCK1], 30U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21016U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 20088U)) & W_KEY1], 37U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 19600U)) & W_KEY1], 19U));
            aCross ^= (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 20265U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 21614U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 57U) + RotL64(aIngress, 41U)) ^ (RotL64(aPrevious, 24U) ^ RotL64(aCarry, 11U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterH = ((aWandererF + RotL64(aIngress, 35U)) + RotL64(aCarry, 27U)) + 5088525177670191619U;
            aOrbiterE = (aWandererA + RotL64(aPrevious, 57U)) + 9966456257813932112U;
            aOrbiterB = (((aWandererE + RotL64(aScatter, 48U)) + RotL64(aCarry, 53U)) + 7707646574027146307U) + aPhaseCOrbiterAssignSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = (aWandererB + RotL64(aCross, 39U)) + 75480203757681173U;
            aOrbiterG = ((aWandererK + RotL64(aScatter, 23U)) + 384659134071835163U) + aPhaseCOrbiterAssignSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterA = (aWandererH + RotL64(aPrevious, 13U)) + 3158769775373307778U;
            aOrbiterC = (aWandererC + RotL64(aIngress, 43U)) + 17360830943513941272U;
            aOrbiterD = ((aWandererD + RotL64(aCross, 28U)) + RotL64(aCarry, 5U)) + 5317278822721604586U;
            aOrbiterI = (aWandererG + RotL64(aPrevious, 3U)) + 1371427105215954781U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 3162710551223553423U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 5332921933853550756U;
            aOrbiterB = RotL64((aOrbiterB * 11709546145149357887U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 10572462410297815854U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 10234389605554817892U) ^ aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2130374833440291193U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 13421365517991380605U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 10186643614984034083U;
            aOrbiterH = RotL64((aOrbiterH * 8554471709467808453U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 4742438973260817120U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 6081590345899008846U) ^ aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7069396301823124931U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 15360092808493795340U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 12186413069553132646U;
            aOrbiterE = RotL64((aOrbiterE * 3815981440611914267U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 16756221656224451552U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 12232880965861373143U;
            aOrbiterK = RotL64((aOrbiterK * 14196910735715726471U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 10090954323470840557U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 15615770271463853537U;
            aOrbiterD = RotL64((aOrbiterD * 13544181592829027283U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 556029032505658411U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 13311879111583579039U;
            aOrbiterI = RotL64((aOrbiterI * 3924744868168749003U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 8646360871497847336U) + aPhaseCOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 2064833941982069154U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 10016546852137913163U), 11U);
            //
            aIngress = RotL64(aOrbiterA, 4U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 23U));
            aIngress = aIngress + (RotL64(aOrbiterI, 57U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 47U));
            aIngress = aIngress + RotL64(aOrbiterK, 52U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aIngress, 43U) + aOrbiterI) + RotL64(aOrbiterD, 23U)) + RotL64(aCarry, 21U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 54U) + RotL64(aOrbiterH, 27U)) + aOrbiterA);
            aWandererA = aWandererA + (((RotL64(aScatter, 23U) + RotL64(aOrbiterK, 6U)) + aOrbiterC) + aPhaseCWandererUpdateSaltC[((aIndex + 4U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 19U) + aOrbiterG) + RotL64(aOrbiterH, 51U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 13U) + RotL64(aOrbiterH, 39U)) + aOrbiterE);
            aWandererK = aWandererK ^ (((RotL64(aCross, 39U) + RotL64(aOrbiterG, 43U)) + aOrbiterE) + aPhaseCWandererUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aIngress, 60U) + RotL64(aOrbiterD, 14U)) + aOrbiterB);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterA, 19U)) + aOrbiterD);
            aWandererG = aWandererG + (((RotL64(aCross, 3U) + aOrbiterK) + RotL64(aOrbiterB, 57U)) + RotL64(aCarry, 51U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 37U) ^ aWandererA);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 30U));
            aCarry = aCarry + (RotL64(aWandererE, 57U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererC, 41U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererD, 23U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 24295U)) & S_BLOCK1], 3U) ^ RotL64(aKeyRowReadA[((aIndex + 22884U)) & W_KEY1], 21U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 23148U)) & W_KEY1], 58U) ^ RotL64(aFireLaneC[((aIndex + 24573U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 23862U)) & S_BLOCK1], 21U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 23339U)) & S_BLOCK1], 29U));
            aCross ^= (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 22743U)) & S_BLOCK1], 11U) ^ RotL64(aInvestLaneB[((aIndex + 23360U)) & S_BLOCK1], 40U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 57U) ^ RotL64(aCarry, 23U)) + (RotL64(aCross, 6U) ^ RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterH = (((aWandererC + RotL64(aCross, 4U)) + RotL64(aCarry, 21U)) + 2786079456995203065U) + aPhaseCOrbiterAssignSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = ((aWandererD + RotL64(aPrevious, 23U)) + 7237256119153857253U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = (aWandererB + RotL64(aIngress, 27U)) + 9310834010563647604U;
            aOrbiterE = (aWandererA + RotL64(aScatter, 37U)) + 17361734905706517877U;
            aOrbiterI = (aWandererK + RotL64(aPrevious, 58U)) + 15837111231884647451U;
            aOrbiterD = (aWandererI + RotL64(aCross, 13U)) + 18065431964418026445U;
            aOrbiterF = ((aWandererG + RotL64(aScatter, 51U)) + RotL64(aCarry, 41U)) + 3029123922999952652U;
            aOrbiterK = ((aWandererH + RotL64(aIngress, 41U)) + RotL64(aCarry, 3U)) + 5166926595573507837U;
            aOrbiterB = (aWandererF + RotL64(aCross, 19U)) + 1918425684273807598U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 4724551751012661440U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 1818014487579644390U;
            aOrbiterA = RotL64((aOrbiterA * 14904092108647864911U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 6670090372241084216U) + aPhaseCOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 8485757110007268693U;
            aOrbiterD = RotL64((aOrbiterD * 11876760095108618363U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 4928130251509514742U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 2528788422725346792U) ^ aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 1855982047967756661U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 2860387120895147503U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 12927802338151379368U) ^ aPhaseCOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8876144125458603029U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 18029699867733207083U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 13361836994951253312U;
            aOrbiterB = RotL64((aOrbiterB * 5349767426256597073U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 11957294454794128079U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 3755417922063414648U;
            aOrbiterH = RotL64((aOrbiterH * 13896364063651241401U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 18001157153447913032U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 16214145724690286854U;
            aOrbiterE = RotL64((aOrbiterE * 5874139687703360515U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 3860958772090975562U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 12395621524459640173U;
            aOrbiterG = RotL64((aOrbiterG * 722817135977510161U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 3402035664910754484U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 2139099117325745602U;
            aOrbiterI = RotL64((aOrbiterI * 14008983756425796029U), 13U);
            //
            aIngress = RotL64(aOrbiterI, 50U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterE, 53U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 3U));
            aIngress = aIngress + (RotL64(aOrbiterK, 57U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterA, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aIngress, 18U) + aOrbiterD) + RotL64(aOrbiterF, 22U)) + aPhaseCWandererUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 5U) + RotL64(aOrbiterB, 35U)) + aOrbiterK) + aPhaseCWandererUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 23U) + aOrbiterA) + RotL64(aOrbiterF, 43U));
            aWandererG = aWandererG + ((RotL64(aCross, 53U) + RotL64(aOrbiterD, 29U)) + aOrbiterH);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterE, 11U)) + aOrbiterG);
            aWandererH = aWandererH + (((RotL64(aPrevious, 43U) + aOrbiterF) + RotL64(aOrbiterH, 47U)) + RotL64(aCarry, 3U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 27U) + aOrbiterI) + RotL64(aOrbiterD, 4U));
            aWandererD = aWandererD + (((RotL64(aIngress, 13U) + aOrbiterD) + RotL64(aOrbiterE, 51U)) + RotL64(aCarry, 39U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 60U) + aOrbiterB) + RotL64(aOrbiterE, 57U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 51U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererH, 47U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererD, 24U) ^ aWandererC);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 11U));
            aCarry = aCarry + RotL64(aWandererK, 5U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 27049U)) & S_BLOCK1], 57U) ^ RotL64(aKeyRowReadA[((aIndex + 26116U)) & W_KEY1], 3U));
            aIngress ^= (RotL64(aFireLaneD[((aIndex + 24896U)) & S_BLOCK1], 28U) ^ RotL64(aFireLaneB[((aIndex + 27073U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 25886U)) & W_KEY1], 51U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 26811U)) & S_BLOCK1], 6U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 25712U)) & S_BLOCK1], 27U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 26663U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 41U) ^ RotL64(aCarry, 23U)) ^ (RotL64(aCross, 11U) + RotL64(aIngress, 54U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterB = ((aWandererF + RotL64(aScatter, 43U)) + RotL64(aCarry, 3U)) + 3236820517816085022U;
            aOrbiterE = ((aWandererJ + RotL64(aCross, 14U)) + 741288875914097926U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = (aWandererB + RotL64(aPrevious, 39U)) + 8417246926007729580U;
            aOrbiterK = ((aWandererA + RotL64(aIngress, 19U)) + RotL64(aCarry, 27U)) + 9715717805774537170U;
            aOrbiterI = ((aWandererE + RotL64(aPrevious, 23U)) + 14360243844821619482U) + aPhaseDOrbiterAssignSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterA = (aWandererK + RotL64(aScatter, 51U)) + 10760908100206775334U;
            aOrbiterF = ((aWandererG + RotL64(aCross, 47U)) + RotL64(aCarry, 41U)) + 3434641779946167811U;
            aOrbiterD = (aWandererH + RotL64(aIngress, 34U)) + 7885568822756234567U;
            aOrbiterH = (aWandererD + RotL64(aPrevious, 29U)) + 3041563437672051294U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 15761355327564963516U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 1158633562785937421U;
            aOrbiterG = RotL64((aOrbiterG * 15511324886867188235U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 9338581575871970653U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 9172038894262857354U;
            aOrbiterA = RotL64((aOrbiterA * 3110871165285625807U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 14653924713599790081U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 3854497592598563309U;
            aOrbiterB = RotL64((aOrbiterB * 11737111068815795303U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 16286980180327600557U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 5092583772591249756U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13955105624639442903U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 4288397994175567333U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 15584236478994873104U;
            aOrbiterK = RotL64((aOrbiterK * 1860480595862755379U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 5557463939827483792U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 2659814275753280856U;
            aOrbiterI = RotL64((aOrbiterI * 17702430405693184643U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 6941807963525063449U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 2040598555191211307U;
            aOrbiterD = RotL64((aOrbiterD * 14750544987531722765U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 347572666231116258U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 779304821185302523U;
            aOrbiterH = RotL64((aOrbiterH * 14180254150318109855U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 10632524582873079742U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 9761308771280517212U;
            aOrbiterE = RotL64((aOrbiterE * 13926235411726048921U), 43U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterF, 29U);
            aIngress = aIngress + (RotL64(aOrbiterD, 22U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 41U));
            aIngress = aIngress + (RotL64(aOrbiterH, 11U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterI, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aPrevious, 52U) + aOrbiterI) + RotL64(aOrbiterK, 21U)) + RotL64(aCarry, 13U)) + aPhaseDWandererUpdateSaltA[((aIndex + 19U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 41U) + aOrbiterI) + RotL64(aOrbiterG, 39U));
            aWandererA = aWandererA + (((RotL64(aCross, 5U) + aOrbiterE) + RotL64(aOrbiterB, 35U)) + RotL64(aCarry, 53U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 27U) + aOrbiterK) + RotL64(aOrbiterF, 50U));
            aWandererK = aWandererK + (((RotL64(aScatter, 57U) + RotL64(aOrbiterA, 11U)) + aOrbiterB) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 37U) + aOrbiterH) + RotL64(aOrbiterB, 43U));
            aWandererF = aWandererF + ((RotL64(aIngress, 14U) + RotL64(aOrbiterF, 5U)) + aOrbiterA);
            aWandererH = aWandererH ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterG, 58U)) + aOrbiterD);
            aWandererB = aWandererB + ((RotL64(aIngress, 21U) + aOrbiterB) + RotL64(aOrbiterD, 27U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 54U));
            aCarry = aCarry + (RotL64(aWandererG, 37U) ^ aWandererA);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 23U));
            aCarry = aCarry + (RotL64(aWandererD, 11U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererJ, 57U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 29043U)) & S_BLOCK1], 19U) ^ RotL64(aFireLaneD[((aIndex + 28908U)) & S_BLOCK1], 60U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 29719U)) & W_KEY1], 39U) ^ RotL64(aFireLaneC[((aIndex + 29800U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 27542U)) & W_KEY1], 60U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 28806U)) & S_BLOCK1], 37U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27327U)) & S_BLOCK1], 27U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 29427U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCross, 20U)) ^ (RotL64(aIngress, 57U) + RotL64(aCarry, 37U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterH = (aWandererD + RotL64(aIngress, 3U)) + 18087125778766689269U;
            aOrbiterK = (aWandererB + RotL64(aCross, 38U)) + 13710545066503235196U;
            aOrbiterI = ((aWandererE + RotL64(aScatter, 57U)) + RotL64(aCarry, 19U)) + 1701939704736254645U;
            aOrbiterJ = ((aWandererG + RotL64(aPrevious, 51U)) + 8064093611384019909U) + aPhaseDOrbiterAssignSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = (aWandererF + RotL64(aScatter, 47U)) + 16623332751533885431U;
            aOrbiterB = ((aWandererK + RotL64(aCross, 11U)) + RotL64(aCarry, 51U)) + 15590129153794910109U;
            aOrbiterF = ((aWandererJ + RotL64(aPrevious, 43U)) + 7413312683079107383U) + aPhaseDOrbiterAssignSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = ((aWandererI + RotL64(aIngress, 23U)) + RotL64(aCarry, 27U)) + 4186064478651458810U;
            aOrbiterD = (aWandererA + RotL64(aCross, 34U)) + 5501191643940735954U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 11064645242200570835U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 13825922087298055833U;
            aOrbiterI = RotL64((aOrbiterI * 7529317892716108867U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 5944980709887369970U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 8181136916070569646U;
            aOrbiterE = RotL64((aOrbiterE * 395183021205661827U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 15442336949157292482U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 11580554435240641337U;
            aOrbiterH = RotL64((aOrbiterH * 6654637892858767739U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 11240018128174598322U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 2027565596050777471U;
            aOrbiterJ = RotL64((aOrbiterJ * 18048186560314431815U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 16425887196883725233U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 16828683527588834095U;
            aOrbiterD = RotL64((aOrbiterD * 17746289103235902485U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 9923829146479008804U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 6669171007279929454U;
            aOrbiterA = RotL64((aOrbiterA * 681823450939955099U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 3902430046523165149U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 6739998149289590041U;
            aOrbiterB = RotL64((aOrbiterB * 2675037435528416821U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 16014401255534234075U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 14741857638680634564U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8723611021403369393U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 5064807861673260054U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 968747317273200299U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 14122304002722582329U), 57U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterH, 35U);
            aIngress = aIngress + (RotL64(aOrbiterB, 3U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterA, 6U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 43U));
            aIngress = aIngress + RotL64(aOrbiterJ, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aCross, 4U) + RotL64(aOrbiterE, 47U)) + aOrbiterJ);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 11U) + aOrbiterJ) + RotL64(aOrbiterA, 52U)) + aPhaseDWandererUpdateSaltA[((aIndex + 18U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aIngress, 35U) + aOrbiterH) + RotL64(aOrbiterF, 43U)) + RotL64(aCarry, 5U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterE, 27U)) + aOrbiterD);
            aWandererJ = aWandererJ + (((RotL64(aCross, 41U) + RotL64(aOrbiterI, 35U)) + aOrbiterA) + RotL64(aCarry, 23U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 53U) + aOrbiterK) + RotL64(aOrbiterF, 18U)) + aPhaseDWandererUpdateSaltF[((aIndex + 24U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aPrevious, 24U) + RotL64(aOrbiterE, 39U)) + aOrbiterH);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 19U) + aOrbiterI) + RotL64(aOrbiterB, 3U));
            aWandererE = aWandererE + ((RotL64(aCross, 57U) + aOrbiterD) + RotL64(aOrbiterI, 11U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 5U) ^ aWandererG);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 29U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 46U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 13U));
            aCarry = aCarry + RotL64(aWandererB, 51U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 30801U)) & S_BLOCK1], 39U) ^ RotL64(aKeyRowReadA[((aIndex + 32194U)) & W_KEY1], 6U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 32153U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30723U)) & S_BLOCK1], 35U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32477U)) & S_BLOCK1], 3U) ^ RotL64(aKeyRowReadB[((aIndex + 30691U)) & W_KEY1], 48U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 6U) + RotL64(aCross, 37U)) ^ (RotL64(aIngress, 19U) + RotL64(aCarry, 51U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterJ = ((aWandererJ + RotL64(aCross, 18U)) + RotL64(aCarry, 21U)) + 8101351470141807662U;
            aOrbiterB = (aWandererG + RotL64(aPrevious, 47U)) + 6965474099521076705U;
            aOrbiterA = ((aWandererC + RotL64(aIngress, 29U)) + RotL64(aCarry, 53U)) + 6803828268885684784U;
            aOrbiterH = (aWandererE + RotL64(aScatter, 35U)) + 13454235922950972488U;
            aOrbiterI = (aWandererI + RotL64(aCross, 53U)) + 11678091885751244777U;
            aOrbiterG = (((aWandererH + RotL64(aScatter, 3U)) + RotL64(aCarry, 3U)) + 5307134544628507141U) + aPhaseDOrbiterAssignSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterD = (aWandererK + RotL64(aIngress, 39U)) + 4873703518950429353U;
            aOrbiterF = (aWandererD + RotL64(aPrevious, 22U)) + 8542156221858586039U;
            aOrbiterE = ((aWandererB + RotL64(aCross, 13U)) + 3993726182905296513U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 12113047622035464386U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 1944244448665721151U;
            aOrbiterA = RotL64((aOrbiterA * 7010050836758762003U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 12914188029425467576U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 2486762763475327024U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12319769994433811617U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 14580191602982245481U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 12093414832400135066U;
            aOrbiterD = RotL64((aOrbiterD * 12720286833215690663U), 23U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 13623906997320021065U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 9977356009806428696U;
            aOrbiterG = RotL64((aOrbiterG * 2005536391712733499U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 3694954095397810851U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 11453812627797091638U;
            aOrbiterF = RotL64((aOrbiterF * 13730420725113907161U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 542311345544726351U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 3024285045990499484U;
            aOrbiterB = RotL64((aOrbiterB * 5153745952148205645U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 15397664082460849530U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 10716856680110815056U;
            aOrbiterH = RotL64((aOrbiterH * 13947203772929252823U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 833342121331428547U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 1111339940097269219U;
            aOrbiterJ = RotL64((aOrbiterJ * 17991642769781175473U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 9312963978841402871U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 8225496710723213204U;
            aOrbiterE = RotL64((aOrbiterE * 894499195498817065U), 3U);
            //
            aIngress = RotL64(aOrbiterH, 43U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 47U));
            aIngress = aIngress + (RotL64(aOrbiterA, 51U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterF, 14U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterG, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aCross, 40U) + aOrbiterB) + RotL64(aOrbiterJ, 13U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 57U) + aOrbiterB) + RotL64(aOrbiterA, 39U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 11U) + aOrbiterF) + RotL64(aOrbiterI, 43U)) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterG, 20U)) + aOrbiterD);
            aWandererD = aWandererD + ((RotL64(aCross, 19U) + aOrbiterG) + RotL64(aOrbiterE, 57U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 35U) + aOrbiterJ) + RotL64(aOrbiterF, 5U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 23U) + aOrbiterH) + RotL64(aOrbiterF, 35U)) + RotL64(aCarry, 51U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 27U) + aOrbiterH) + RotL64(aOrbiterJ, 47U)) + aPhaseDWandererUpdateSaltB[((aIndex + 10U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aIngress, 52U) + RotL64(aOrbiterD, 30U)) + aOrbiterF) + RotL64(aCarry, 39U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 60U));
            aCarry = aCarry + (RotL64(aWandererC, 57U) ^ aWandererE);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 53U));
            aCarry = aCarry + (RotL64(aWandererK, 35U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererD, 43U);
            aCarry = aCarry + RotL64(aIngress, 30U);
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
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneD, aExpandLaneC, aExpandLaneD, aInvestLaneC, aFireLaneB, aInvestLaneD, aFireLaneA, aOperationLaneA, aFireLaneC, aOperationLaneB, aOperationLaneC
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 3506U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneB[((aIndex + 2359U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 3039U)) & S_BLOCK1], 58U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 3601U)) & S_BLOCK1], 24U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 1340U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 19U) + RotL64(aIngress, 41U)) + (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 54U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterA = ((aWandererI + RotL64(aScatter, 54U)) + RotL64(aCarry, 57U)) + 16016931609704150191U;
            aOrbiterJ = (aWandererA + RotL64(aCross, 39U)) + 14511433515861302636U;
            aOrbiterK = ((aWandererJ + RotL64(aPrevious, 21U)) + RotL64(aCarry, 37U)) + 11691237442613269593U;
            aOrbiterD = ((aWandererH + RotL64(aIngress, 5U)) + 16383220587320484649U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = (aWandererC + RotL64(aPrevious, 47U)) + 14293015313458219868U;
            aOrbiterF = ((aWandererG + RotL64(aIngress, 11U)) + RotL64(aCarry, 11U)) + 4407695248205526670U;
            aOrbiterE = ((aWandererE + RotL64(aScatter, 29U)) + 1158323195324398372U) + aPhaseEOrbiterAssignSaltE[((aIndex + 6U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 6577683409653864555U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 171080079472863843U;
            aOrbiterK = RotL64((aOrbiterK * 3063978974927752653U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 5766333425872228205U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 16173508656917582960U;
            aOrbiterA = RotL64((aOrbiterA * 12187968015372936695U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 11781450063402219202U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 13033139686637576694U;
            aOrbiterD = RotL64((aOrbiterD * 4331137994135472025U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 4006310759400926020U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 13156817947481574467U;
            aOrbiterJ = RotL64((aOrbiterJ * 563189239835001483U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 12791290558893516411U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 989729955679243234U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8757228712495095017U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 838379839663022790U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 2830743864262313606U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 10173947177104802797U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 2146646527331684652U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 4629168181742174906U;
            aOrbiterH = RotL64((aOrbiterH * 9046124907945045131U), 21U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterJ, 35U);
            aIngress = aIngress + (RotL64(aOrbiterF, 13U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 3U));
            aIngress = aIngress + RotL64(aOrbiterD, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aIngress, 13U) + aOrbiterK) + RotL64(aOrbiterA, 19U)) + RotL64(aCarry, 43U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 3U) + aOrbiterJ) + RotL64(aOrbiterH, 27U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 23U) + aOrbiterE) + RotL64(aOrbiterJ, 60U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 39U) + aOrbiterF) + RotL64(aOrbiterH, 5U));
            aWandererA = aWandererA + ((((RotL64(aPrevious, 51U) + RotL64(aOrbiterD, 51U)) + aOrbiterK) + RotL64(aCarry, 27U)) + aPhaseEWandererUpdateSaltE[((aIndex + 21U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 57U) + aOrbiterA) + RotL64(aOrbiterE, 41U));
            aWandererG = aWandererG + ((RotL64(aScatter, 30U) + RotL64(aOrbiterK, 13U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 52U));
            aCarry = aCarry + (RotL64(aWandererJ, 39U) ^ aWandererG);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 47U));
            aCarry = aCarry + RotL64(aWandererC, 57U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = (RotL64(aInvestLaneC[((aIndex + 10030U)) & S_BLOCK1], 60U) ^ RotL64(aExpandLaneC[((aIndex + 6056U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 7284U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 5882U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 10691U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 10U) ^ RotL64(aPrevious, 27U)) ^ (RotL64(aCross, 39U) + RotL64(aIngress, 51U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterI = (aWandererC + RotL64(aScatter, 37U)) + 3970829908171131502U;
            aOrbiterF = (aWandererB + RotL64(aIngress, 5U)) + 7040283759419531991U;
            aOrbiterG = ((aWandererE + RotL64(aPrevious, 43U)) + RotL64(aCarry, 3U)) + 11856292169397052901U;
            aOrbiterJ = (((aWandererD + RotL64(aCross, 29U)) + RotL64(aCarry, 41U)) + 819598588791819022U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = ((aWandererF + RotL64(aIngress, 21U)) + 2176451710970866848U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterE = (aWandererG + RotL64(aCross, 50U)) + 6454704928613390494U;
            aOrbiterC = ((aWandererJ + RotL64(aScatter, 13U)) + RotL64(aCarry, 23U)) + 11792122387218053841U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 9254780213489752211U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 16591812589999846482U;
            aOrbiterG = RotL64((aOrbiterG * 5425771603523423167U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 1471246223935074832U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 1424843083106386453U;
            aOrbiterB = RotL64((aOrbiterB * 15020536982657410783U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 1856469958050891629U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 6331743690452052712U;
            aOrbiterJ = RotL64((aOrbiterJ * 15327924647897459645U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 10351075711345476487U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 9518585245330480185U;
            aOrbiterI = RotL64((aOrbiterI * 3792179827396760391U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 17787514620244712033U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 14182328067398162557U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 18107337388659070197U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 12798088948801072444U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 9563215159275202323U;
            aOrbiterE = RotL64((aOrbiterE * 7058145016617349141U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 9904919772580498232U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 16579777394992143043U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 10516761340320196661U), 11U);
            //
            aIngress = RotL64(aOrbiterF, 43U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 5U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 12U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterB, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterC, 35U)) + aOrbiterG);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 4U) + RotL64(aOrbiterB, 27U)) + aOrbiterC) + RotL64(aCarry, 23U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterJ, 43U)) + aOrbiterF);
            aWandererG = aWandererG + ((((RotL64(aCross, 21U) + RotL64(aOrbiterB, 3U)) + aOrbiterE) + RotL64(aCarry, 43U)) + aPhaseEWandererUpdateSaltB[((aIndex + 6U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 43U) + aOrbiterE) + RotL64(aOrbiterG, 19U));
            aWandererE = aWandererE + ((RotL64(aIngress, 13U) + aOrbiterF) + RotL64(aOrbiterB, 60U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 27U) + RotL64(aOrbiterG, 53U)) + aOrbiterI) + aPhaseEWandererUpdateSaltF[((aIndex + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 14U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererG, 41U) ^ aWandererB);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 27U));
            aCarry = aCarry + RotL64(aWandererJ, 53U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = (RotL64(aInvestLaneD[((aIndex + 14102U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneD[((aIndex + 14114U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 14066U)) & S_BLOCK1], 10U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 13123U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 16244U)) & S_BLOCK1], 24U));
            aCross ^= RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 11842U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 35U) + RotL64(aIngress, 50U)) ^ (RotL64(aPrevious, 11U) ^ RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterF = (aWandererH + RotL64(aCross, 43U)) + 15920462086654025436U;
            aOrbiterE = ((aWandererC + RotL64(aScatter, 19U)) + 487844076858004017U) + aPhaseEOrbiterAssignSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterA = (aWandererF + RotL64(aIngress, 53U)) + 14502883786442630566U;
            aOrbiterC = ((aWandererE + RotL64(aPrevious, 11U)) + 3787107318658233674U) + aPhaseEOrbiterAssignSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterG = ((aWandererB + RotL64(aScatter, 3U)) + RotL64(aCarry, 35U)) + 12548777544693755491U;
            aOrbiterD = ((aWandererJ + RotL64(aCross, 29U)) + RotL64(aCarry, 21U)) + 4907309444075181683U;
            aOrbiterJ = ((aWandererD + RotL64(aPrevious, 60U)) + RotL64(aCarry, 57U)) + 18342396700266492072U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 13503051997624242670U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 17845742460521374571U;
            aOrbiterA = RotL64((aOrbiterA * 1366356786138085155U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 8640887211877858169U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 5273913123709097537U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 1661149444148461791U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 17756844173695563883U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 6713055830729302951U;
            aOrbiterJ = RotL64((aOrbiterJ * 2832836748513174311U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 5106468334224035972U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 10228769728713526172U;
            aOrbiterG = RotL64((aOrbiterG * 9760310686414358435U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 7687649520668883142U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 7757480627354711605U;
            aOrbiterE = RotL64((aOrbiterE * 7222553727737349209U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 10876291698508634557U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 8149278085586014186U;
            aOrbiterC = RotL64((aOrbiterC * 8577133863470695381U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 15592893988925610485U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 8639028256640537165U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 1880655276432963955U), 39U);
            //
            aIngress = RotL64(aOrbiterC, 41U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 3U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 29U));
            aIngress = aIngress + RotL64(aOrbiterF, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aScatter, 5U) + aOrbiterF) + RotL64(aOrbiterA, 51U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 19U) + aOrbiterC) + RotL64(aOrbiterD, 29U));
            aWandererH = aWandererH + (((RotL64(aCross, 43U) + aOrbiterC) + RotL64(aOrbiterF, 41U)) + RotL64(aCarry, 27U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterG, 19U)) + aOrbiterJ);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 37U) + RotL64(aOrbiterF, 5U)) + aOrbiterE) + RotL64(aCarry, 57U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 28U) + RotL64(aOrbiterD, 35U)) + aOrbiterE) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 13U) + aOrbiterJ) + RotL64(aOrbiterF, 60U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 5U) ^ aWandererF);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 36U));
            aCarry = aCarry + (RotL64(aWandererH, 51U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererC, 57U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_b loop 4
        // ingress from: aOperationLaneA, aInvestLaneC, aFireLaneC
        // ingress directions: aOperationLaneA forward forced, aInvestLaneC forward forced, aFireLaneC forward/backward random
        // cross from: aInvestLaneD, aExpandLaneD, aExpandLaneC
        // cross directions: aInvestLaneD backward forced, aExpandLaneD backward forced, aExpandLaneC backward/forward random
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 21461U)) & S_BLOCK1], 57U) ^ RotL64(aInvestLaneC[((aIndex + 21413U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 20094U)) & S_BLOCK1], 30U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 19697U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 19678U)) & S_BLOCK1], 42U));
            aCross ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 17975U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 57U)) ^ (RotL64(aIngress, 39U) + RotL64(aCross, 22U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterJ = ((aWandererC + RotL64(aCross, 50U)) + RotL64(aCarry, 5U)) + 6521330037475130256U;
            aOrbiterB = ((aWandererI + RotL64(aScatter, 41U)) + RotL64(aCarry, 53U)) + 12611880456055428940U;
            aOrbiterI = (aWandererB + RotL64(aIngress, 19U)) + 12061611078130934708U;
            aOrbiterG = ((aWandererH + RotL64(aPrevious, 3U)) + 1558112410801116984U) + aPhaseEOrbiterAssignSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterK = ((aWandererD + RotL64(aScatter, 27U)) + 10509115227850160786U) + aPhaseEOrbiterAssignSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = (aWandererJ + RotL64(aCross, 57U)) + 4045915960688792066U;
            aOrbiterD = ((aWandererK + RotL64(aPrevious, 35U)) + RotL64(aCarry, 23U)) + 1196541286513243082U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 15564991032722373702U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 4897765238703641798U;
            aOrbiterI = RotL64((aOrbiterI * 9693901276712946763U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 12327429514907752733U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 6189189797708711636U;
            aOrbiterG = RotL64((aOrbiterG * 9017615866338877651U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 6374267075282018852U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 1888758503831341439U;
            aOrbiterJ = RotL64((aOrbiterJ * 74387714918264257U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 14956857689299491800U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 14879361107223331957U;
            aOrbiterD = RotL64((aOrbiterD * 9166712966729591953U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 16086885494838105042U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 8069724185844303923U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8878470736758734353U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 10854345917959911439U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 7078313614360332089U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9864025732292844871U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 15083669236062255011U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 594879695916679116U;
            aOrbiterK = RotL64((aOrbiterK * 9852515479152735283U), 41U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterB, 51U);
            aIngress = aIngress + (RotL64(aOrbiterA, 57U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterD, 26U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterI, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aPrevious, 29U) + aOrbiterB) + RotL64(aOrbiterI, 37U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 47U) + aOrbiterB) + RotL64(aOrbiterJ, 5U));
            aWandererD = aWandererD + (((RotL64(aIngress, 53U) + aOrbiterA) + RotL64(aOrbiterD, 51U)) + RotL64(aCarry, 19U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterK, 21U)) + aOrbiterG) + aPhaseEWandererUpdateSaltA[((aIndex + 10U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterJ, 13U)) + aOrbiterK) + RotL64(aCarry, 35U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 38U) + RotL64(aOrbiterK, 60U)) + aOrbiterA);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 13U) + RotL64(aOrbiterD, 27U)) + aOrbiterI) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 19U));
            aCarry = aCarry + (RotL64(aWandererH, 11U) ^ aWandererK);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 29U));
            aCarry = aCarry + RotL64(aWandererC, 44U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 22555U)) & S_BLOCK1], 56U) ^ RotL64(aOperationLaneA[((aIndex + 22210U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 24322U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 23850U)) & S_BLOCK1], 37U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 25355U)) & S_BLOCK1], 54U));
            aCross ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 25825U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 12U) + RotL64(aCross, 27U)) + (RotL64(aCarry, 39U) ^ RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterK = (((aWandererD + RotL64(aScatter, 19U)) + RotL64(aCarry, 19U)) + 2558105147674438050U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = (aWandererK + RotL64(aIngress, 51U)) + 15856662514774702561U;
            aOrbiterA = (aWandererJ + RotL64(aPrevious, 13U)) + 13346869226246584582U;
            aOrbiterB = ((aWandererE + RotL64(aCross, 29U)) + 7632111846116243973U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = ((aWandererG + RotL64(aIngress, 37U)) + RotL64(aCarry, 51U)) + 2102101361626976279U;
            aOrbiterE = ((aWandererB + RotL64(aPrevious, 5U)) + RotL64(aCarry, 39U)) + 5605968705067851563U;
            aOrbiterD = (aWandererH + RotL64(aCross, 60U)) + 6842483186584326681U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 5559797213819425064U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 12422313931331576759U;
            aOrbiterA = RotL64((aOrbiterA * 7399849122565913401U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 2751024420047872601U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 11031320239359798610U;
            aOrbiterC = RotL64((aOrbiterC * 8607639453141148025U), 27U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 14366375309473793217U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 11971479429768505316U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 10063001532313098203U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 3947595951884469542U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 17882767922372770896U;
            aOrbiterB = RotL64((aOrbiterB * 3361906348965810211U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 513871456983509223U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 5951677013597794294U;
            aOrbiterK = RotL64((aOrbiterK * 8508629569649935293U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 437626309049021931U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 466674061172005705U;
            aOrbiterD = RotL64((aOrbiterD * 1310502572084891157U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 12362602809233133718U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 10525852878882195702U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 17755022180514914325U), 41U);
            //
            aIngress = RotL64(aOrbiterC, 43U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 35U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 23U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterK, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aIngress, 57U) + RotL64(aOrbiterB, 57U)) + aOrbiterE) + RotL64(aCarry, 51U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 19U) + aOrbiterD) + RotL64(aOrbiterE, 51U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 26U) + RotL64(aOrbiterJ, 35U)) + aOrbiterE) + RotL64(aCarry, 37U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 41U) + aOrbiterK) + RotL64(aOrbiterB, 27U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterC, 43U)) + aOrbiterK) + aPhaseEWandererUpdateSaltB[((aIndex + 11U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterK, 18U)) + aOrbiterD) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aScatter, 13U) + aOrbiterA) + RotL64(aOrbiterB, 3U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 37U));
            aCarry = aCarry + (RotL64(aWandererE, 53U) ^ aWandererK);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 10U));
            aCarry = aCarry + RotL64(aWandererB, 41U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 29533U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneA[((aIndex + 32755U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30544U)) & S_BLOCK1], 4U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31302U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 29759U)) & S_BLOCK1], 18U));
            aCross ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 28957U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 6U) + RotL64(aIngress, 23U)) ^ (RotL64(aCross, 39U) ^ RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterF = ((aWandererD + RotL64(aPrevious, 43U)) + RotL64(aCarry, 3U)) + 11698283336767769359U;
            aOrbiterA = (aWandererA + RotL64(aIngress, 35U)) + 13297826354831483872U;
            aOrbiterK = (aWandererJ + RotL64(aCross, 13U)) + 15254999058287530795U;
            aOrbiterI = ((aWandererK + RotL64(aScatter, 53U)) + RotL64(aCarry, 37U)) + 17474166585085346567U;
            aOrbiterD = ((aWandererG + RotL64(aCross, 23U)) + 15684783498452840289U) + aPhaseEOrbiterAssignSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterG = ((aWandererH + RotL64(aIngress, 29U)) + RotL64(aCarry, 19U)) + 5061229733465216486U;
            aOrbiterB = ((aWandererE + RotL64(aPrevious, 6U)) + 15370981279168377944U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 17966672773619554092U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 14685092893994491068U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 1627758964162892429U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 12798804186209406389U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 2848444181474221574U;
            aOrbiterF = RotL64((aOrbiterF * 13730480364920876877U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 8551142075919636146U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 8833198159158950723U;
            aOrbiterD = RotL64((aOrbiterD * 7650289040764974737U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 7351473160893666232U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 14204899612487622222U;
            aOrbiterG = RotL64((aOrbiterG * 6317485031956448029U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 7008985178526543258U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 13576796403863120356U;
            aOrbiterA = RotL64((aOrbiterA * 13745839827679114077U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 5769784656937900699U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 14075925808204936705U;
            aOrbiterB = RotL64((aOrbiterB * 5844894088757604713U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 17818667502858010896U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 16016922065572683130U;
            aOrbiterI = RotL64((aOrbiterI * 7525645833898085373U), 35U);
            //
            aIngress = RotL64(aOrbiterK, 27U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterB, 5U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 57U));
            aIngress = aIngress + RotL64(aOrbiterI, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aScatter, 11U) + RotL64(aOrbiterF, 27U)) + aOrbiterK);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 47U) + aOrbiterD) + RotL64(aOrbiterA, 51U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 36U) + RotL64(aOrbiterF, 19U)) + aOrbiterI) + RotL64(aCarry, 21U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterB, 43U)) + aOrbiterG);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 57U) + aOrbiterB) + RotL64(aOrbiterI, 57U)) + RotL64(aCarry, 57U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterB, 12U)) + aOrbiterA);
            aWandererK = aWandererK + (((RotL64(aPrevious, 21U) + aOrbiterG) + RotL64(aOrbiterF, 37U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 35U));
            aCarry = aCarry + (RotL64(aWandererA, 21U) ^ aWandererK);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 48U));
            aCarry = aCarry + RotL64(aWandererE, 53U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
        // read from: aOperationLaneA, aOperationLaneB, aExpandLaneD, aOperationLaneC, aOperationLaneD, aInvestLaneC, aSnowLaneA, aInvestLaneA, aInvestLaneD, aSnowLaneB, aInvestLaneB, aWorkLaneA, aExpandLaneA, aWorkLaneB, aExpandLaneB, aWorkLaneC, aExpandLaneC
        // write to: aSnowLaneA, aSnowLaneB, aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // twist_loop_c loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aExpandLaneD
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aExpandLaneD forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aInvestLaneC
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aInvestLaneC backward/forward random
        // write to: aSnowLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 3823U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneB[((aIndex + 4790U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 1647U)) & S_BLOCK1], 30U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 3031U)) & S_BLOCK1], 14U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 1157U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 435U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 24U) ^ RotL64(aCarry, 57U)) ^ (RotL64(aPrevious, 37U) + RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterA = (aWandererK + RotL64(aScatter, 53U)) + 8988572360732005217U;
            aOrbiterE = (aWandererF + RotL64(aCross, 19U)) + 17889613225105985335U;
            aOrbiterC = (aWandererB + RotL64(aPrevious, 29U)) + 15563478320513948626U;
            aOrbiterG = (aWandererG + RotL64(aIngress, 39U)) + 3441351228410524816U;
            aOrbiterH = ((aWandererJ + RotL64(aScatter, 46U)) + RotL64(aCarry, 39U)) + 4425592689451435346U;
            aOrbiterB = ((aWandererE + RotL64(aCross, 37U)) + RotL64(aCarry, 3U)) + 12733160231627305928U;
            aOrbiterF = ((aWandererH + RotL64(aPrevious, 41U)) + 3574152157304607854U) + aPhaseFOrbiterAssignSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterD = (aWandererA + RotL64(aIngress, 11U)) + 15167631896729808783U;
            aOrbiterI = (aWandererI + RotL64(aPrevious, 43U)) + 15822667973915417055U;
            aOrbiterJ = ((aWandererD + RotL64(aScatter, 13U)) + 17181685481076577637U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterK = ((aWandererC + RotL64(aIngress, 26U)) + RotL64(aCarry, 29U)) + 9979204751408873468U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 1334240485667164762U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 9190066751460137016U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14585141844653660363U), 21U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 15465215829109246336U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 2305208282453624419U;
            aOrbiterH = RotL64((aOrbiterH * 10257861974108363283U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 16951510027310993926U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 11117938943423526901U;
            aOrbiterF = RotL64((aOrbiterF * 7805486716716924787U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 12461379120662979432U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 11719697049048823897U;
            aOrbiterB = RotL64((aOrbiterB * 14880996802304818757U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 6843357278142933570U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 12727898578324702374U;
            aOrbiterI = RotL64((aOrbiterI * 9786435451654365097U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 18127999660067652233U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 11754709060558683082U;
            aOrbiterG = RotL64((aOrbiterG * 12798744012150745847U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 16940151146420516184U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 12924950783056761895U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 8898170377271926745U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 14829713915929878471U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 840466047621042565U;
            aOrbiterJ = RotL64((aOrbiterJ * 10748511630509529489U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 11469637840333471085U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 5561780312837795893U;
            aOrbiterK = RotL64((aOrbiterK * 11935079844970978957U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 1059834104159730610U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 10122108814456766430U;
            aOrbiterA = RotL64((aOrbiterA * 2184693583782179921U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 14857099570072635006U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 8988572360732005217U;
            aOrbiterD = RotL64((aOrbiterD * 14409836741925393077U), 27U);
            //
            aIngress = RotL64(aOrbiterD, 47U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 39U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 21U));
            aIngress = aIngress + (RotL64(aOrbiterC, 35U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterK, 3U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterF, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aPrevious, 23U) + aOrbiterF) + RotL64(aOrbiterA, 43U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 35U) + aOrbiterJ) + RotL64(aOrbiterB, 3U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aCross, 58U) + RotL64(aOrbiterG, 13U)) + aOrbiterJ) + RotL64(aCarry, 23U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 11U) + aOrbiterI) + RotL64(aOrbiterF, 10U));
            aWandererD = aWandererD + ((RotL64(aPrevious, 43U) + RotL64(aOrbiterG, 27U)) + aOrbiterI);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 3U) + aOrbiterE) + RotL64(aOrbiterD, 51U));
            aWandererI = aWandererI + ((RotL64(aCross, 53U) + aOrbiterC) + RotL64(aOrbiterD, 37U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterA, 29U)) + aOrbiterC);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 21U) + RotL64(aOrbiterE, 19U)) + aOrbiterA) + RotL64(aCarry, 37U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 39U) + aOrbiterF) + RotL64(aOrbiterK, 53U));
            aWandererA = aWandererA + ((RotL64(aScatter, 50U) + aOrbiterJ) + RotL64(aOrbiterH, 24U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 35U) ^ aWandererJ);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 60U));
            aCarry = aCarry + (RotL64(aWandererF, 13U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererD, 43U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererB, 26U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aSnowLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_c loop 2
        // ingress from: aSnowLaneA, aOperationLaneC, aOperationLaneD, aInvestLaneA
        // ingress directions: aSnowLaneA forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aInvestLaneA forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aInvestLaneD
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aInvestLaneD backward/forward random
        // write to: aSnowLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneA[((aIndex + 6974U)) & S_BLOCK1], 54U) ^ RotL64(aOperationLaneC[((aIndex + 7345U)) & S_BLOCK1], 23U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 8548U)) & S_BLOCK1], 13U) ^ RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 8825U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 7397U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 7599U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aInvestLaneD[((aIndex + 8975U)) & S_BLOCK1], 56U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 3U) ^ RotL64(aCarry, 54U)) + (RotL64(aIngress, 19U) ^ RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterF = ((aWandererA + RotL64(aIngress, 41U)) + 12980104182836602177U) + aPhaseFOrbiterAssignSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterK = (aWandererB + RotL64(aCross, 51U)) + 3172622203188863995U;
            aOrbiterJ = (aWandererD + RotL64(aPrevious, 26U)) + 1170974132219980203U;
            aOrbiterI = (aWandererK + RotL64(aScatter, 39U)) + 6035201940965047490U;
            aOrbiterE = ((aWandererG + RotL64(aPrevious, 11U)) + RotL64(aCarry, 39U)) + 18033907118424996722U;
            aOrbiterG = (aWandererF + RotL64(aIngress, 5U)) + 14604813424800580304U;
            aOrbiterA = (aWandererJ + RotL64(aScatter, 37U)) + 13720232492851066035U;
            aOrbiterC = ((aWandererI + RotL64(aCross, 3U)) + RotL64(aCarry, 57U)) + 3902659710585257448U;
            aOrbiterH = (aWandererH + RotL64(aPrevious, 35U)) + 8331560652661619868U;
            aOrbiterD = (aWandererC + RotL64(aIngress, 30U)) + 4485014147538689794U;
            aOrbiterB = (((aWandererE + RotL64(aScatter, 47U)) + RotL64(aCarry, 51U)) + 168202636924512424U) + aPhaseFOrbiterAssignSaltB[((aIndex + 5U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 16227825670092707848U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 4792781933944671365U;
            aOrbiterJ = RotL64((aOrbiterJ * 15859849676231455283U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 12636865372722601282U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 18198291399585556632U;
            aOrbiterK = RotL64((aOrbiterK * 18155803890313399795U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 3650053185419807206U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 5897288963905408776U;
            aOrbiterC = RotL64((aOrbiterC * 3706949366974086151U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 9922308113622901726U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 13352279749091561510U;
            aOrbiterG = RotL64((aOrbiterG * 4025213180483632557U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 14969461950939646117U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 10231661776135056651U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 11284575051455238501U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 10621934544068320859U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 6029116920305246887U;
            aOrbiterB = RotL64((aOrbiterB * 6087523725059376905U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 12887482425168671195U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 8351351557123783853U;
            aOrbiterI = RotL64((aOrbiterI * 3839381627914762245U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 5405938210926464973U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 385145802287899406U;
            aOrbiterE = RotL64((aOrbiterE * 8330751480464271445U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 7907749190875916461U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 5138733192253468642U;
            aOrbiterA = RotL64((aOrbiterA * 17028325976353263843U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 14382272868178763187U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 14354777100157531233U;
            aOrbiterH = RotL64((aOrbiterH * 7095764230272037767U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 4390647647193363824U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 12980104182836602177U;
            aOrbiterF = RotL64((aOrbiterF * 11124472075872147333U), 53U);
            //
            aIngress = RotL64(aOrbiterJ, 11U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 47U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 3U));
            aIngress = aIngress + (RotL64(aOrbiterD, 58U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 39U));
            aIngress = aIngress + RotL64(aOrbiterB, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 27U) + aOrbiterC) + RotL64(aOrbiterK, 3U));
            aWandererI = aWandererI + ((RotL64(aCross, 13U) + aOrbiterJ) + RotL64(aOrbiterD, 53U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterE, 37U)) + aOrbiterF);
            aWandererG = aWandererG + ((RotL64(aScatter, 34U) + aOrbiterF) + RotL64(aOrbiterK, 10U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 23U) + RotL64(aOrbiterG, 21U)) + aOrbiterI) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 29U) + aOrbiterC) + RotL64(aOrbiterH, 43U)) + RotL64(aCarry, 39U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterH, 41U)) + aOrbiterE);
            aWandererC = aWandererC + (((RotL64(aIngress, 43U) + aOrbiterH) + RotL64(aOrbiterD, 30U)) + RotL64(aCarry, 21U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 50U) + aOrbiterI) + RotL64(aOrbiterA, 23U));
            aWandererF = aWandererF + (((RotL64(aCross, 11U) + RotL64(aOrbiterJ, 35U)) + aOrbiterI) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 3U) + aOrbiterB) + RotL64(aOrbiterA, 39U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 21U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererF, 60U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererK, 27U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererH, 5U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererG, 53U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererJ, 24U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aSnowLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_c loop 3
        // ingress from: aSnowLaneB, aOperationLaneA, aInvestLaneB
        // ingress directions: aSnowLaneB forward forced, aOperationLaneA forward forced, aInvestLaneB forward/backward random
        // cross from: aSnowLaneA, aOperationLaneC
        // cross directions: aSnowLaneA backward forced, aOperationLaneC backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneB[((aIndex + 15187U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneA[((aIndex + 13152U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 16112U)) & S_BLOCK1], 22U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 12756U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneC[((aIndex + 13310U)) & S_BLOCK1], 48U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 6U) + RotL64(aCross, 51U)) ^ (RotL64(aCarry, 19U) + RotL64(aIngress, 35U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = ((aWandererI + RotL64(aScatter, 29U)) + RotL64(aCarry, 57U)) + 479672811032092393U;
            aOrbiterG = (aWandererG + RotL64(aCross, 41U)) + 18061121631394564425U;
            aOrbiterI = ((aWandererF + RotL64(aIngress, 27U)) + 14237400452740566065U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterA = (aWandererJ + RotL64(aPrevious, 3U)) + 6723123812257706134U;
            aOrbiterE = ((aWandererE + RotL64(aIngress, 6U)) + 4247997188026499248U) + aPhaseFOrbiterAssignSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = ((aWandererA + RotL64(aPrevious, 39U)) + RotL64(aCarry, 53U)) + 1939107415066134869U;
            aOrbiterC = (aWandererH + RotL64(aCross, 21U)) + 3912640123546395979U;
            aOrbiterH = (aWandererK + RotL64(aScatter, 51U)) + 8295478436553964298U;
            aOrbiterF = (aWandererB + RotL64(aCross, 23U)) + 3218960600711526885U;
            aOrbiterJ = ((aWandererC + RotL64(aIngress, 11U)) + RotL64(aCarry, 47U)) + 5874096203353388890U;
            aOrbiterK = (aWandererD + RotL64(aScatter, 18U)) + 10294536533673023358U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 11268561953904130747U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 16693201256788898423U;
            aOrbiterI = RotL64((aOrbiterI * 16291987237693567209U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 7550969634681894654U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 9501647424602245869U;
            aOrbiterE = RotL64((aOrbiterE * 11265865222096866605U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 8881869255994319423U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 16770136406906800016U;
            aOrbiterB = RotL64((aOrbiterB * 1782039587385512923U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 16185384746435761363U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 13841034186650721627U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12000155593277035447U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 15229062695864608309U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 3576122704615303733U;
            aOrbiterH = RotL64((aOrbiterH * 2433987493885779279U), 37U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 13898167174453181224U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 12878032061609524049U;
            aOrbiterF = RotL64((aOrbiterF * 18104665741338251495U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 12719156051299028649U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 8640980843376950769U;
            aOrbiterK = RotL64((aOrbiterK * 10242616778390983333U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 12133332160916004365U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 8743563985229104484U;
            aOrbiterC = RotL64((aOrbiterC * 4575129690615054691U), 21U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 7362223873479167793U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 4230720394788635807U;
            aOrbiterD = RotL64((aOrbiterD * 3658720603716856293U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 5095842824285329272U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 7483469517256234638U;
            aOrbiterA = RotL64((aOrbiterA * 9782114499878763883U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 17426017004856399653U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 479672811032092393U;
            aOrbiterJ = RotL64((aOrbiterJ * 14921028515589317919U), 11U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterH, 39U);
            aIngress = aIngress + (RotL64(aOrbiterI, 41U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterJ, 28U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 47U));
            aIngress = aIngress + (RotL64(aOrbiterC, 19U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterE, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aIngress, 54U) + aOrbiterD) + RotL64(aOrbiterH, 18U)) + aPhaseFWandererUpdateSaltC[((aIndex + 11U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aCross, 23U) + aOrbiterA) + RotL64(aOrbiterE, 35U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 13U) + aOrbiterA) + RotL64(aOrbiterJ, 11U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterF, 21U)) + aOrbiterC) + RotL64(aCarry, 13U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterC, 27U)) + aOrbiterK);
            aWandererE = aWandererE + ((RotL64(aScatter, 51U) + aOrbiterI) + RotL64(aOrbiterD, 53U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 27U) + aOrbiterG) + RotL64(aOrbiterB, 40U));
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 37U) + aOrbiterD) + RotL64(aOrbiterJ, 29U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 19U) + aOrbiterG) + RotL64(aOrbiterK, 43U));
            aWandererI = aWandererI + ((((RotL64(aIngress, 11U) + RotL64(aOrbiterE, 3U)) + aOrbiterC) + RotL64(aCarry, 57U)) + aPhaseFWandererUpdateSaltA[((aIndex + 25U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 60U) + RotL64(aOrbiterH, 51U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 39U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 51U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 27U));
            aCarry = aCarry + (RotL64(aWandererJ, 48U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererG, 21U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererH, 53U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 20152U)) & S_BLOCK1], 29U) ^ RotL64(aSnowLaneA[((aIndex + 21714U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aExpandLaneA[((aIndex + 20372U)) & S_BLOCK1], 56U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 16880U)) & S_BLOCK1], 30U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 17630U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 23U) + RotL64(aPrevious, 53U)) ^ (RotL64(aCarry, 4U) ^ RotL64(aIngress, 35U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterH = (aWandererE + RotL64(aCross, 27U)) + 3561491146322798260U;
            aOrbiterG = ((aWandererK + RotL64(aScatter, 37U)) + 7075025056181885339U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterF = (((aWandererG + RotL64(aIngress, 29U)) + RotL64(aCarry, 13U)) + 9230910887904171613U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = (aWandererH + RotL64(aPrevious, 11U)) + 4119781172609908917U;
            aOrbiterE = (aWandererD + RotL64(aScatter, 35U)) + 17155609083870983149U;
            aOrbiterA = (aWandererI + RotL64(aCross, 43U)) + 2423018561430181695U;
            aOrbiterK = (aWandererF + RotL64(aPrevious, 60U)) + 12957280305617615744U;
            aOrbiterC = (aWandererJ + RotL64(aIngress, 3U)) + 2461704174772065813U;
            aOrbiterB = ((aWandererB + RotL64(aScatter, 39U)) + RotL64(aCarry, 3U)) + 7907123257849391997U;
            aOrbiterD = ((aWandererA + RotL64(aCross, 53U)) + RotL64(aCarry, 29U)) + 7257868138318960007U;
            aOrbiterJ = (aWandererC + RotL64(aPrevious, 48U)) + 16425903703085702285U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 2990822664594079467U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 5654819006718953817U;
            aOrbiterF = RotL64((aOrbiterF * 4465096036756887801U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 12183676471235678779U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 15026286960542123922U;
            aOrbiterE = RotL64((aOrbiterE * 17199049329995315279U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 12169080607071830522U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 2906296852254787499U;
            aOrbiterC = RotL64((aOrbiterC * 6754514406846040163U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 3029858695410344584U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 14406410317495954566U;
            aOrbiterI = RotL64((aOrbiterI * 9663780721657983421U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 11048818178401163861U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 13622063920319445043U;
            aOrbiterD = RotL64((aOrbiterD * 2516025554421589857U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 2642646089141233277U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 12761571777929273548U;
            aOrbiterG = RotL64((aOrbiterG * 5518252696078700127U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 7753802695131502382U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 8510425459525030222U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 12412361423636026483U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 13522645164493316722U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 1437430302489702713U;
            aOrbiterA = RotL64((aOrbiterA * 14019316635365783545U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 14745189473423751499U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 16968328257002103715U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 17915588590593471981U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 5001838243344386314U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 13506188720092630563U;
            aOrbiterH = RotL64((aOrbiterH * 7010027510838271877U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 16902624500530747723U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 3561491146322798260U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 95761172090277669U), 41U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterB, 43U);
            aIngress = aIngress + (RotL64(aOrbiterC, 29U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 40U));
            aIngress = aIngress + (RotL64(aOrbiterI, 11U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 21U));
            aIngress = aIngress + RotL64(aOrbiterA, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aPrevious, 27U) + aOrbiterD) + RotL64(aOrbiterG, 19U)) + RotL64(aCarry, 5U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 44U) + RotL64(aOrbiterJ, 47U)) + aOrbiterD);
            aWandererH = aWandererH + ((((RotL64(aIngress, 19U) + aOrbiterF) + RotL64(aOrbiterB, 3U)) + RotL64(aCarry, 29U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aCross, 53U) + aOrbiterF) + RotL64(aOrbiterC, 36U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aIngress, 11U) + RotL64(aOrbiterH, 57U)) + aOrbiterG);
            aWandererF = aWandererF ^ ((RotL64(aCross, 47U) + aOrbiterG) + RotL64(aOrbiterI, 13U));
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 35U) + RotL64(aOrbiterG, 27U)) + aOrbiterA);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 5U) + aOrbiterD) + RotL64(aOrbiterE, 41U));
            aWandererI = aWandererI + ((RotL64(aIngress, 37U) + aOrbiterI) + RotL64(aOrbiterK, 30U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 57U) + aOrbiterK) + RotL64(aOrbiterD, 11U));
            aWandererC = aWandererC + ((RotL64(aCross, 40U) + RotL64(aOrbiterE, 5U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererG, 14U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererA, 27U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererB, 39U) ^ aWandererD);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 43U));
            aCarry = aCarry + (RotL64(aWandererC, 23U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererK, 41U);
            aCarry = aCarry + RotL64(aIngress, 34U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 25883U)) & S_BLOCK1], 44U) ^ RotL64(aSnowLaneB[((aIndex + 24809U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 22493U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 26176U)) & S_BLOCK1], 30U) ^ RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 22265U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 11U) ^ RotL64(aIngress, 38U)) + (RotL64(aPrevious, 23U) + RotL64(aCross, 51U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterC = (aWandererC + RotL64(aPrevious, 19U)) + 7790166497945719700U;
            aOrbiterJ = ((aWandererG + RotL64(aIngress, 29U)) + RotL64(aCarry, 19U)) + 7136208896846119188U;
            aOrbiterF = ((aWandererA + RotL64(aCross, 21U)) + RotL64(aCarry, 11U)) + 12123156943355100886U;
            aOrbiterE = ((aWandererH + RotL64(aScatter, 47U)) + 5095546037880875199U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = (aWandererF + RotL64(aPrevious, 24U)) + 17642705393916765992U;
            aOrbiterG = (aWandererK + RotL64(aCross, 53U)) + 9918479837334416990U;
            aOrbiterH = ((aWandererE + RotL64(aScatter, 27U)) + RotL64(aCarry, 47U)) + 4890009823843176466U;
            aOrbiterI = ((aWandererJ + RotL64(aIngress, 13U)) + 17652590786213674124U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterB = (aWandererD + RotL64(aScatter, 43U)) + 870002527644696135U;
            aOrbiterA = (aWandererB + RotL64(aIngress, 34U)) + 12545429703552643682U;
            aOrbiterK = (aWandererI + RotL64(aCross, 5U)) + 5310272867406182581U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 3264719049050179440U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 1967241238180278937U;
            aOrbiterF = RotL64((aOrbiterF * 13004319774269457957U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 773883832927040736U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 12766817190261232485U;
            aOrbiterC = RotL64((aOrbiterC * 7448864556802318431U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 260069382395598265U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 15462103891287350123U;
            aOrbiterH = RotL64((aOrbiterH * 5029268763635635753U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 4072032867513289827U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 17153061419083897076U;
            aOrbiterD = RotL64((aOrbiterD * 11934532169271718913U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 6207264270332656966U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 18048064697837314947U;
            aOrbiterI = RotL64((aOrbiterI * 13632594619404208489U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 14484617445340272026U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 16160443600497652026U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 1988599349457831597U), 21U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 5873314228291583482U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 16418290052752166515U;
            aOrbiterB = RotL64((aOrbiterB * 18270363452003213317U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 9158414409987627714U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 8205937960146492168U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 14008398661393344261U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 16386126219854809263U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 12418021156683187869U;
            aOrbiterE = RotL64((aOrbiterE * 13897930566207284517U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 5427232681451476584U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 18237670074497382745U;
            aOrbiterA = RotL64((aOrbiterA * 15528665160297906195U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 8330262458028468513U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 7790166497945719700U;
            aOrbiterJ = RotL64((aOrbiterJ * 6001280767763971107U), 51U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterC, 3U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 23U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 29U));
            aIngress = aIngress + (RotL64(aOrbiterI, 19U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterG, 47U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterJ, 14U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterC, 56U)) + aOrbiterH);
            aWandererC = aWandererC + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterE, 35U)) + aOrbiterA) + RotL64(aCarry, 53U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 56U) + RotL64(aOrbiterI, 39U)) + aOrbiterK) + aPhaseFWandererUpdateSaltE[((aIndex + 7U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aScatter, 27U) + aOrbiterE) + RotL64(aOrbiterF, 37U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterJ, 41U)) + aOrbiterG);
            aWandererG = aWandererG + ((RotL64(aScatter, 41U) + aOrbiterF) + RotL64(aOrbiterG, 53U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterB, 11U)) + aOrbiterI);
            aWandererF = aWandererF + ((RotL64(aIngress, 13U) + RotL64(aOrbiterK, 14U)) + aOrbiterF);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 21U) + aOrbiterI) + RotL64(aOrbiterH, 47U));
            aWandererA = aWandererA + ((((RotL64(aIngress, 46U) + aOrbiterD) + RotL64(aOrbiterG, 3U)) + RotL64(aCarry, 27U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterB, 51U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererG, 40U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererA, 35U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererB, 19U) ^ aWandererJ);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 11U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 54U));
            aCarry = aCarry + RotL64(aWandererE, 43U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // twist_loop_c loop 6
        // ingress from: aWorkLaneC, aWorkLaneA, aExpandLaneC
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aExpandLaneC forward/backward random
        // cross from: aWorkLaneB, aOperationLaneB
        // cross directions: aWorkLaneB backward forced, aOperationLaneB backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 29036U)) & S_BLOCK1], 52U) ^ RotL64(aWorkLaneA[((aIndex + 29181U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 29075U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 29890U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneB[((aIndex + 32655U)) & S_BLOCK1], 56U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 13U) ^ RotL64(aCarry, 27U)) + (RotL64(aCross, 41U) ^ RotL64(aIngress, 58U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterF = (((aWandererJ + RotL64(aPrevious, 43U)) + RotL64(aCarry, 27U)) + 18302975933754610273U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterI = (aWandererC + RotL64(aCross, 54U)) + 16736972646771456082U;
            aOrbiterG = (aWandererA + RotL64(aScatter, 21U)) + 17389406266488137442U;
            aOrbiterH = ((aWandererF + RotL64(aIngress, 5U)) + RotL64(aCarry, 21U)) + 5252511566486165539U;
            aOrbiterE = (aWandererG + RotL64(aScatter, 35U)) + 5730715427422747640U;
            aOrbiterB = (aWandererH + RotL64(aIngress, 41U)) + 6412695646456045825U;
            aOrbiterA = ((aWandererE + RotL64(aPrevious, 60U)) + 9539701605708994494U) + aPhaseFOrbiterAssignSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = (aWandererI + RotL64(aCross, 47U)) + 18355107116412945722U;
            aOrbiterJ = (aWandererD + RotL64(aScatter, 39U)) + 11735742491750132942U;
            aOrbiterC = ((aWandererK + RotL64(aCross, 11U)) + RotL64(aCarry, 47U)) + 12363819388562658842U;
            aOrbiterK = (aWandererB + RotL64(aIngress, 3U)) + 5861430292304371543U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 15027487084595017708U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 7012850020745791926U;
            aOrbiterG = RotL64((aOrbiterG * 15952928839355613939U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 11904871669287886120U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 11199760114477343208U;
            aOrbiterE = RotL64((aOrbiterE * 7156374911847525867U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 3856004502263742700U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 3705931243173921893U;
            aOrbiterD = RotL64((aOrbiterD * 10334871178498711485U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 12305785390539209389U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 18057980996551978823U;
            aOrbiterB = RotL64((aOrbiterB * 4850564181113470859U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 3229431819292153014U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 2994716629242460094U;
            aOrbiterI = RotL64((aOrbiterI * 1029427328395257917U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 9796307843453735512U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 2957260393651252432U;
            aOrbiterC = RotL64((aOrbiterC * 7261055869794739609U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 4060469664218866340U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 17462081697889685330U;
            aOrbiterA = RotL64((aOrbiterA * 7712009170974461225U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 13638660073917821172U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 15202349592659062565U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4514326257446024301U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 12071949111168967041U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 11930843273199806728U;
            aOrbiterK = RotL64((aOrbiterK * 16229663295689525137U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 11294220104731500296U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 440743185210586759U;
            aOrbiterF = RotL64((aOrbiterF * 14810195235168807229U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 8514240764798061804U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 18302975933754610273U;
            aOrbiterJ = RotL64((aOrbiterJ * 1972439346780950873U), 37U);
            //
            aIngress = RotL64(aOrbiterC, 38U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 5U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 51U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 29U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 19U));
            aIngress = aIngress + RotL64(aOrbiterG, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 11U) + aOrbiterF) + RotL64(aOrbiterA, 3U));
            aWandererA = aWandererA + (((RotL64(aScatter, 57U) + RotL64(aOrbiterG, 41U)) + aOrbiterE) + RotL64(aCarry, 21U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 29U) + aOrbiterC) + RotL64(aOrbiterF, 58U));
            aWandererC = aWandererC + (((RotL64(aCross, 54U) + aOrbiterA) + RotL64(aOrbiterH, 37U)) + RotL64(aCarry, 13U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterG, 43U)) + aOrbiterK);
            aWandererB = aWandererB + ((RotL64(aPrevious, 37U) + RotL64(aOrbiterJ, 51U)) + aOrbiterI);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 43U) + aOrbiterG) + RotL64(aOrbiterA, 39U));
            aWandererG = aWandererG + ((RotL64(aCross, 26U) + RotL64(aOrbiterJ, 53U)) + aOrbiterC);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterC, 47U)) + aOrbiterG);
            aWandererD = aWandererD + (((RotL64(aPrevious, 41U) + aOrbiterC) + RotL64(aOrbiterD, 22U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 23U) + aOrbiterB) + RotL64(aOrbiterC, 11U)) + aPhaseFWandererUpdateSaltC[((aIndex + 8U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 3U) ^ aWandererC);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 19U));
            aCarry = aCarry + (RotL64(aWandererH, 6U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererB, 39U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererF, 35U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererG, 53U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterI = 0;
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 1876U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneB[((aIndex + 6842U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aInvestLaneA[((aIndex + 5893U)) & S_BLOCK1], 48U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 1763U)) & S_BLOCK1], 36U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 2274U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aOperationLaneA[((aIndex + 252U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 22U) + RotL64(aIngress, 51U)) ^ (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 35U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterF = ((aWandererH + RotL64(aIngress, 3U)) + RotL64(aCarry, 51U)) + 9133751643283278896U;
            aOrbiterE = (((aWandererD + RotL64(aScatter, 47U)) + RotL64(aCarry, 27U)) + 8971581804375380408U) + aPhaseGOrbiterAssignSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterG = ((aWandererK + RotL64(aCross, 19U)) + RotL64(aCarry, 39U)) + 12559650383714566592U;
            aOrbiterD = ((aWandererA + RotL64(aPrevious, 29U)) + 15753206088872859163U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterJ = (aWandererC + RotL64(aIngress, 38U)) + 7640756270450762350U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 7340073357551376125U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 5270256573644196046U;
            aOrbiterG = RotL64((aOrbiterG * 13286406906662922841U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 3567367996479995928U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 11939634537492733738U;
            aOrbiterF = RotL64((aOrbiterF * 5640541900117183639U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 7051817732424527120U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 1730487669951837941U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 15191634337956285841U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 18009252467909454817U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 2361024272031696442U;
            aOrbiterD = RotL64((aOrbiterD * 15215151562500226027U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 15902755877642960397U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 12243517544704116184U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 2576071074148141447U), 41U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterG, 3U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 40U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterE, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterF, 43U)) + aOrbiterE) + aPhaseGWandererUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aIngress, 41U) + RotL64(aOrbiterF, 51U)) + aOrbiterD) + RotL64(aCarry, 21U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 21U) + aOrbiterE) + RotL64(aOrbiterD, 30U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterE, 19U)) + aOrbiterJ) + RotL64(aCarry, 53U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 4U) + aOrbiterG) + RotL64(aOrbiterJ, 5U)) + aPhaseGWandererUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 57U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 3U));
            aCarry = aCarry + RotL64(aWandererA, 35U);
            aCarry = aCarry + RotL64(aIngress, 48U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 15308U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneC[((aIndex + 11772U)) & S_BLOCK1], 26U));
            aIngress ^= RotL64(aInvestLaneB[((aIndex + 14949U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 9147U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 16303U)) & S_BLOCK1], 10U));
            aCross ^= RotL64(aOperationLaneB[((aIndex + 13147U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 6U) ^ RotL64(aCarry, 47U)) ^ (RotL64(aPrevious, 21U) + RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterJ = ((aWandererD + RotL64(aPrevious, 3U)) + 7948891781097675369U) + aPhaseGOrbiterAssignSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = ((aWandererH + RotL64(aScatter, 11U)) + RotL64(aCarry, 47U)) + 13928362874228230226U;
            aOrbiterK = ((aWandererI + RotL64(aCross, 43U)) + 10776180542602258926U) + aPhaseGOrbiterAssignSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = ((aWandererK + RotL64(aIngress, 54U)) + RotL64(aCarry, 23U)) + 5735115172149470447U;
            aOrbiterG = ((aWandererG + RotL64(aPrevious, 29U)) + RotL64(aCarry, 35U)) + 5353591822981766987U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 562301708107268570U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 10467810247578364868U;
            aOrbiterK = RotL64((aOrbiterK * 10449089554007059823U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 14541630141152308564U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 2350076897065139429U) ^ aPhaseGOrbiterUpdateSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 12222554362482034393U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 17519109078651162228U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 6061035173339902910U;
            aOrbiterE = RotL64((aOrbiterE * 10021905773432907835U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 15654836633731000065U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 13723521735153718904U;
            aOrbiterG = RotL64((aOrbiterG * 14459516479283070563U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 2849680038315532197U) + aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 17336102435576647923U) ^ aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 10984689101753586739U), 39U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterI, 28U);
            aIngress = aIngress + (RotL64(aOrbiterK, 13U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterG, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aCross, 35U) + RotL64(aOrbiterI, 37U)) + aOrbiterK);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 14U) + RotL64(aOrbiterE, 19U)) + aOrbiterI) + aPhaseGWandererUpdateSaltD[((aIndex + 28U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aIngress, 5U) + aOrbiterI) + RotL64(aOrbiterG, 29U)) + RotL64(aCarry, 3U)) + aPhaseGWandererUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterE, 56U)) + aOrbiterJ);
            aWandererI = aWandererI + (((RotL64(aScatter, 23U) + RotL64(aOrbiterG, 5U)) + aOrbiterJ) + RotL64(aCarry, 29U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 3U));
            aCarry = aCarry + (RotL64(aWandererG, 58U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererD, 43U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 17189U)) & S_BLOCK1], 18U) ^ RotL64(aWorkLaneD[((aIndex + 21583U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aInvestLaneC[((aIndex + 23416U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 19518U)) & S_BLOCK1], 4U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 17696U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 19019U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 27U) ^ RotL64(aIngress, 57U)) + (RotL64(aPrevious, 43U) + RotL64(aCross, 6U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterG = ((aWandererC + RotL64(aScatter, 5U)) + RotL64(aCarry, 19U)) + 12027839670755583592U;
            aOrbiterB = (((aWandererE + RotL64(aCross, 13U)) + RotL64(aCarry, 57U)) + 15380130703509859843U) + aPhaseGOrbiterAssignSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = (aWandererF + RotL64(aIngress, 35U)) + 4590907433867798074U;
            aOrbiterI = (((aWandererK + RotL64(aPrevious, 24U)) + RotL64(aCarry, 43U)) + 1754574023602519724U) + aPhaseGOrbiterAssignSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterK = (aWandererG + RotL64(aCross, 47U)) + 9832756659564903767U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 5035088494491470403U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 14199170923323644638U) ^ aPhaseGOrbiterUpdateSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4518257134117207121U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 8325619421264440438U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 969534320779067977U;
            aOrbiterB = RotL64((aOrbiterB * 17767548306355264705U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 270575869402913847U) + aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 13344806516599578910U;
            aOrbiterK = RotL64((aOrbiterK * 10193544126281901579U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 15143147951139409101U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 14425582489214169238U;
            aOrbiterG = RotL64((aOrbiterG * 16893787086337916355U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 13951127523239064584U) + aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 14177925225918293579U) ^ aPhaseGOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 13079514031864998485U), 3U);
            //
            aIngress = RotL64(aOrbiterG, 60U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 21U));
            aIngress = aIngress + RotL64(aOrbiterJ, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aCross, 51U) + aOrbiterG) + RotL64(aOrbiterB, 5U));
            aWandererG = aWandererG + (((RotL64(aScatter, 27U) + RotL64(aOrbiterK, 56U)) + aOrbiterJ) + RotL64(aCarry, 35U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 5U) + aOrbiterI) + RotL64(aOrbiterG, 47U)) + aPhaseGWandererUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aPrevious, 37U) + aOrbiterI) + RotL64(aOrbiterK, 19U)) + RotL64(aCarry, 21U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 60U) + RotL64(aOrbiterG, 35U)) + aOrbiterK) + aPhaseGWandererUpdateSaltC[((aIndex + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 13U));
            aCarry = aCarry + (RotL64(aWandererC, 35U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererK, 47U);
            aCarry = aCarry + RotL64(aIngress, 4U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 28527U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneA[((aIndex + 26224U)) & S_BLOCK1], 4U));
            aIngress ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 27776U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29758U)) & S_BLOCK1], 20U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 28864U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 25114U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 53U) ^ RotL64(aCarry, 10U)) ^ (RotL64(aIngress, 29U) + RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterA = ((aWandererB + RotL64(aPrevious, 57U)) + RotL64(aCarry, 43U)) + 2558105147674438050U;
            aOrbiterK = (((aWandererI + RotL64(aScatter, 35U)) + RotL64(aCarry, 19U)) + 15856662514774702561U) + aPhaseGOrbiterAssignSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterC = ((aWandererC + RotL64(aIngress, 23U)) + RotL64(aCarry, 57U)) + 13346869226246584582U;
            aOrbiterG = (aWandererJ + RotL64(aCross, 5U)) + 7632111846116243973U;
            aOrbiterI = ((aWandererF + RotL64(aPrevious, 46U)) + 2102101361626976279U) + aPhaseGOrbiterAssignSaltC[((aIndex + 4U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 5605968705067851563U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 6842483186584326681U) ^ aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 11344798544990575365U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 5559797213819425064U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 12422313931331576759U;
            aOrbiterG = RotL64((aOrbiterG * 7399849122565913401U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 2751024420047872601U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 11031320239359798610U;
            aOrbiterA = RotL64((aOrbiterA * 8607639453141148025U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 14366375309473793217U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 11971479429768505316U;
            aOrbiterI = RotL64((aOrbiterI * 10063001532313098203U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 3947595951884469542U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 17882767922372770896U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 3361906348965810211U), 57U);
            //
            aIngress = RotL64(aOrbiterA, 51U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterI, 30U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterG, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aPrevious, 4U) + RotL64(aOrbiterG, 3U)) + aOrbiterI);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 43U) + aOrbiterA) + RotL64(aOrbiterI, 47U));
            aWandererF = aWandererF + (((RotL64(aScatter, 13U) + aOrbiterK) + RotL64(aOrbiterC, 39U)) + RotL64(aCarry, 13U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 35U) + aOrbiterI) + RotL64(aOrbiterC, 11U)) + aPhaseGWandererUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aCross, 23U) + RotL64(aOrbiterC, 26U)) + aOrbiterG) + RotL64(aCarry, 35U)) + aPhaseGWandererUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 60U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererJ, 13U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererI, 29U);
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

    std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0; std::uint64_t aOrbiterE = 0;
    std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0;
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
        // ingress from: aExpandLaneA, aExpandLaneB, aInvestLaneA
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aInvestLaneA forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD, aOperationLaneA
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward forced, aOperationLaneA backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 3146U)) & S_BLOCK1], 34U) ^ RotL64(aExpandLaneB[((aIndex + 3066U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aInvestLaneA[((aIndex + 4238U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 1718U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 6102U)) & S_BLOCK1], 52U));
            aCross ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 3271U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 43U) + RotL64(aPrevious, 20U)) ^ (RotL64(aCross, 5U) + RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterH = ((aWandererG + RotL64(aScatter, 60U)) + 9023059520606551446U) + aPhaseHOrbiterAssignSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = (aWandererB + RotL64(aCross, 37U)) + 662441755115638133U;
            aOrbiterF = ((aWandererH + RotL64(aPrevious, 29U)) + RotL64(aCarry, 27U)) + 16957253361196144712U;
            aOrbiterK = (((aWandererJ + RotL64(aIngress, 21U)) + RotL64(aCarry, 39U)) + 7840955025765308605U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = ((aWandererI + RotL64(aCross, 47U)) + RotL64(aCarry, 57U)) + 346855809270395799U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 16099139781586668343U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 3706457327118322098U;
            aOrbiterF = RotL64((aOrbiterF * 7810030620470889591U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 12166825885547622870U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 7792658665720344200U;
            aOrbiterH = RotL64((aOrbiterH * 16305542632794270697U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 7128477606152986326U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 11116533962780290084U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 11993485572912492297U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 10443889548568288532U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 4402387036946561017U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9032964741841833277U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 13002706161178447654U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 13929727277530310708U;
            aOrbiterK = RotL64((aOrbiterK * 7005639090871200285U), 5U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterK, 30U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 19U));
            aIngress = aIngress + RotL64(aOrbiterH, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterH, 21U)) + aOrbiterF);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 30U) + RotL64(aOrbiterF, 4U)) + aOrbiterB) + RotL64(aCarry, 27U)) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 39U) + aOrbiterJ) + RotL64(aOrbiterF, 47U));
            aWandererG = aWandererG + ((((RotL64(aCross, 57U) + RotL64(aOrbiterK, 57U)) + aOrbiterB) + RotL64(aCarry, 47U)) + aPhaseHWandererUpdateSaltD[((aIndex + 7U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 11U) + aOrbiterB) + RotL64(aOrbiterJ, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 13U) ^ aWandererB);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 35U));
            aCarry = aCarry + RotL64(aWandererI, 47U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 14882U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneC[((aIndex + 11120U)) & S_BLOCK1], 40U));
            aIngress ^= RotL64(aInvestLaneB[((aIndex + 11760U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 14977U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 15644U)) & S_BLOCK1], 50U));
            aCross ^= RotL64(aOperationLaneB[((aIndex + 13750U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 39U) ^ RotL64(aPrevious, 56U)) + (RotL64(aIngress, 11U) ^ RotL64(aCross, 27U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterF = (((aWandererI + RotL64(aPrevious, 53U)) + RotL64(aCarry, 41U)) + 6163290588946759209U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = (aWandererK + RotL64(aScatter, 37U)) + 7342672468560105447U;
            aOrbiterC = ((aWandererE + RotL64(aIngress, 19U)) + RotL64(aCarry, 27U)) + 11574563167017282321U;
            aOrbiterJ = ((aWandererH + RotL64(aCross, 27U)) + RotL64(aCarry, 13U)) + 2254820206194758964U;
            aOrbiterE = ((aWandererJ + RotL64(aPrevious, 4U)) + 1469783447473099498U) + aPhaseHOrbiterAssignSaltF[((aIndex + 20U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 14174828900676165088U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 16277954291890598132U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4608888834164373691U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 14845750668693136766U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 150099699692047766U;
            aOrbiterK = RotL64((aOrbiterK * 7644895634421086357U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 1200784917165131703U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 9469982764806754302U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 17851969334511301943U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 10956702761701710182U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 7915506894975487807U;
            aOrbiterJ = RotL64((aOrbiterJ * 8874108311712727983U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 17335794183733623213U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 557028996286989506U;
            aOrbiterF = RotL64((aOrbiterF * 3993359298602424281U), 13U);
            //
            aIngress = RotL64(aOrbiterF, 35U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterE, 21U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterK, 58U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aScatter, 39U) + aOrbiterC) + RotL64(aOrbiterE, 13U)) + RotL64(aCarry, 5U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 18U) + aOrbiterF) + RotL64(aOrbiterK, 53U)) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 53U) + RotL64(aOrbiterK, 23U)) + aOrbiterJ) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterC, 3U)) + aOrbiterJ);
            aWandererI = aWandererI + (((RotL64(aCross, 27U) + RotL64(aOrbiterE, 38U)) + aOrbiterK) + RotL64(aCarry, 51U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 5U) ^ aWandererE);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 13U));
            aCarry = aCarry + RotL64(aWandererJ, 29U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 19761U)) & S_BLOCK1], 40U) ^ RotL64(aExpandLaneD[((aIndex + 19686U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aInvestLaneC[((aIndex + 20398U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24009U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 17198U)) & S_BLOCK1], 14U));
            aCross ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 23470U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 53U) ^ RotL64(aCarry, 21U)) + (RotL64(aIngress, 6U) ^ RotL64(aCross, 37U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterK = ((aWandererD + RotL64(aIngress, 39U)) + RotL64(aCarry, 3U)) + 2786079456995203065U;
            aOrbiterI = (aWandererK + RotL64(aPrevious, 13U)) + 7237256119153857253U;
            aOrbiterD = (((aWandererI + RotL64(aCross, 4U)) + RotL64(aCarry, 27U)) + 9310834010563647604U) + aPhaseHOrbiterAssignSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = (aWandererC + RotL64(aScatter, 47U)) + 17361734905706517877U;
            aOrbiterB = (((aWandererH + RotL64(aPrevious, 29U)) + RotL64(aCarry, 41U)) + 15837111231884647451U) + aPhaseHOrbiterAssignSaltE[((aIndex + 21U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 18065431964418026445U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 3029123922999952652U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 16309219658285890145U), 39U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 5166926595573507837U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 1918425684273807598U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 16616641579714896719U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 4724551751012661440U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 1818014487579644390U;
            aOrbiterB = RotL64((aOrbiterB * 14904092108647864911U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 6670090372241084216U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 8485757110007268693U;
            aOrbiterK = RotL64((aOrbiterK * 11876760095108618363U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 4928130251509514742U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 2528788422725346792U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 1855982047967756661U), 21U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterK, 5U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 53U));
            aIngress = aIngress + RotL64(aOrbiterD, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 40U) + RotL64(aOrbiterE, 53U)) + aOrbiterD);
            aWandererD = aWandererD + ((((RotL64(aScatter, 5U) + aOrbiterB) + RotL64(aOrbiterI, 21U)) + RotL64(aCarry, 53U)) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterI, 11U)) + aOrbiterD) + aPhaseHWandererUpdateSaltE[((aIndex + 15U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aIngress, 23U) + aOrbiterK) + RotL64(aOrbiterB, 42U)) + RotL64(aCarry, 37U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterK, 29U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 29U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 50U));
            aCarry = aCarry + RotL64(aWandererC, 41U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 27620U)) & S_BLOCK1], 56U) ^ RotL64(aWorkLaneA[((aIndex + 28313U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 27770U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 32506U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 27907U)) & S_BLOCK1], 44U));
            aCross ^= RotL64(aOperationLaneD[((aIndex + 31018U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCarry, 57U)) + (RotL64(aCross, 28U) + RotL64(aPrevious, 43U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterH = (((aWandererC + RotL64(aCross, 19U)) + RotL64(aCarry, 53U)) + 9630214189402543339U) + aPhaseHOrbiterAssignSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterJ = ((aWandererB + RotL64(aIngress, 57U)) + RotL64(aCarry, 23U)) + 4072576573737526819U;
            aOrbiterI = (aWandererJ + RotL64(aPrevious, 3U)) + 15994787452709618869U;
            aOrbiterF = ((aWandererH + RotL64(aScatter, 43U)) + RotL64(aCarry, 37U)) + 6403240137132259482U;
            aOrbiterK = ((aWandererA + RotL64(aCross, 28U)) + 10229266900170507720U) + aPhaseHOrbiterAssignSaltA[((aIndex + 15U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 5025294577989748989U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 16696461238217956883U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 15993828976234917577U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 9878318855341719119U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 16086635438116177346U;
            aOrbiterK = RotL64((aOrbiterK * 5585682357395705671U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 12295437783084203730U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 7681150419912842402U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7289497379725191451U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 2639104034287637448U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 12298170009332243573U;
            aOrbiterF = RotL64((aOrbiterF * 9397919591171238575U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 3485932317267669626U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 16569551670038752475U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8139802826402217631U), 27U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterI, 3U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 13U));
            aIngress = aIngress + RotL64(aOrbiterJ, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 57U) + RotL64(aOrbiterI, 13U)) + aOrbiterF) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 19U) + RotL64(aOrbiterH, 23U)) + aOrbiterJ) + RotL64(aCarry, 3U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 38U) + aOrbiterK) + RotL64(aOrbiterH, 44U));
            aWandererC = aWandererC + (((RotL64(aScatter, 5U) + aOrbiterH) + RotL64(aOrbiterI, 53U)) + RotL64(aCarry, 47U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 29U) + aOrbiterJ) + RotL64(aOrbiterI, 3U)) + aPhaseHWandererUpdateSaltB[((aIndex + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 21U) ^ aWandererJ);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 51U));
            aCarry = aCarry + RotL64(aWandererH, 37U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
